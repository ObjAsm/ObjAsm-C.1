; ==================================================================================================
; Title:      GetFileLinesA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, December 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

GFL_DATA struc
  dFileOffset   DWORD   ?     ;We are limited to 4GB files!
  dLineLength   DWORD   ?     ;Not including the CRLF sequence
GFL_DATA ends
PGFL_DATA typedef ptr GFL_DATA

GFL_BUFFER_SIZE     equ 4096                                  ;Should be a power of 2
GFL_LIST_SIZE_INIT  equ sizeof(DWORD) + 512*sizeof GFL_DATA   ;Must not be less than 12
GFL_LIST_SIZE_GROW  equ 512*sizeof GFL_DATA                   ;Must not be less than 12
GFL_CR_MASK         equ 0D0D0D0D0D0D0D0Dh


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetFileLinesA
; Purpose:    Return line information of an ANSI text file in form of GFL_DATA structures.
; Arguments:  Arg1: Opened file handle.
; Return:     rax -> Mem block. The user must dispose it using MemFree.
;             First DWORD is the number of following GFL_DATA structures.
; Layout:
;
;      Count |  GFL_DATA #1  |  GFL_DATA #2  |  GFL_DATA #3  |     |  GFL_DATA #N  |
;            |               |               |               |     |               |
;     —————————————————————————————————————————————————————————————————————————————
;    |       |        |      |        |      |        |      |     |        |      |
;    |   N   | Offset | Size | Offset | Size | Offset | Size | ... | Offset | Size |
;    |       |        |      |        |      |        |      |     |        |      |
;     —————————————————————————————————————————————————————————————————————————————
;
; Notes:     - Lines must be terminated with the ANSI char sequence 13, 10 (CR, LF).
;            - The last line may terminate without CR, LF.

align ALIGN_CODE
GetFileLinesA proc uses rbx rdi rsi hFile:HANDLE
  local pList:POINTER, pListEnd:POINTER, dListSize:DWORD
  local pBuffer:POINTER, pBufferEnd:POINTER
  local dBufferFilePos:DWORD, sdCorrOffset:SDWORD, dLineStart:DWORD
  local dBytesRead:DWORD, dPrevBytesRead:DWORD

  .const
    GFL_MASK_TABLE \
      QWORD 000000000000000FFh
      QWORD 0000000000000FFFFh
      QWORD 00000000000FFFFFFh
      QWORD 000000000FFFFFFFFh
      QWORD 0000000FFFFFFFFFFh
      QWORD 00000FFFFFFFFFFFFh
      QWORD 000FFFFFFFFFFFFFFh
    GFL_JUMP_TABLE POINTER @@1, @@2, @@3, @@4, @@5, @@6, @@7, @@8

  .code
  ;Ensure all requirements are met
  .if hFile != INVALID_HANDLE_VALUE
    mov dListSize, GFL_LIST_SIZE_INIT
    MemAlloc dListSize
    .if rax != NULL
      mov pList, rax
      mov rdi, rax
      mov ecx, dListSize
      add rax, xcx
      sub rax, sizeof GFL_DATA
      mov pListEnd, rax
      add rdi, sizeof DWORD                             ;Make room for the count DWORD

      MemAlloc GFL_BUFFER_SIZE
      .if rax != NULL
        mov pBuffer, rax
        m2z dBufferFilePos
        mov sdCorrOffset, eax
        m2z dLineStart
        m2z dBytesRead

@@Loop:
        .repeat
          m2m dPrevBytesRead, dBytesRead, eax
          ;Read a data chunk
          invoke ReadFile, hFile, pBuffer, GFL_BUFFER_SIZE, addr dBytesRead, NULL
          .break .if dBytesRead == 0

          ;Compute aligned address of the last valid QWORD
          mov rsi, pBuffer
          mov rcx, rsi
          mov eax, dBytesRead
          add rcx, rax
          dec rcx
          and rcx, 0FFFFFFFFFFFFFFF8h                   ;Alignment 8
          mov pBufferEnd, rcx

          ;Cut garbage from the last QWORD
          and eax, 3
          .if !ZERO?
            ;Read mask and apply it mask to the last DWORD
            lea r8, GFL_MASK_TABLE
            mov rdx, [r8 + sizeof(QWORD)*xax - sizeof(QWORD)]
            and [xcx], rdx
          .endif

          ;Analize the data, searching for the char 13
          .while xsi <= pBufferEnd
            mov rbx, [xsi]
            xor rbx, GFL_CR_MASK                        ;Puts a zero where the CR was found

            test rbx, 000000000000000FFh
            jz @@Found
@@1:
            inc rsi
            test rbx, 0000000000000FF00h
            jz @@Found
@@2:
            inc rsi
            test rbx, 00000000000FF0000h
            jz @@Found
@@3:
            inc rsi
            test rbx, 000000000FF000000h
            jnz @@4
@@4:
            inc rsi
            test rbx, 0000000FF00000000h
            jz @@Found
@@5:
            inc rsi
            test rbx, 00000FF0000000000h
            jz @@Found
@@6:
            inc rsi
            test rbx, 000FF000000000000h
            jnz @@4
@@7:
            inc rsi
            test rbx, 0FF00000000000000h
            jnz @@8

@@Found:
            ;Compute line start and character file offset
            mov ecx, dLineStart
            mov eax, ecx
            stosd
            mov rax, rsi
            mov edx, sdCorrOffset
            sub rax, rdx
            sub rax, rcx
            stosd                                       ;edi -> valid position into the list
            lea eax, [eax + ecx + 2]                    ;+2 = CRLF
            mov dLineStart, eax

            ;We check edi to ensure that it remains pointing to a valid position
            ;  to hold a complete GFL_DATA structure
            .if rdi > pListEnd
              ;Extend the list by the factor GFL_LIST_SIZE_GROW
              sub rdi, pList
              add dListSize, GFL_LIST_SIZE_GROW
              MemReAlloc pList, dListSize
              .if rax != NULL
                ;Operation succeeded => update internal values
                mov pList, rax
                add rdi, rax                            ;Adjust new edi
                add rax, dListSize
                sub rax, sizeof GFL_DATA
                mov pListEnd, rax
              .else
                ;Operation failed => release allocated resources and exit
                MemFree pList
                MemFree pBuffer
                xor eax, eax
                ret
              .endif
            .endif
            mov rcx, rsi
            and ecx, 3
            mov r8, offset GFL_JUMP_TABLE 
            jmp [r8 + sizeof(POINTER)*xcx]
@@8:
            inc esi
          .endw

          mov eax, dBytesRead
          add dBufferFilePos, eax

          sub sdCorrOffset, eax

        .until FALSE

        ;Check if we have and additional line at the end that doesn't end with CRLF
        mov eax, dBufferFilePos                         ;End of data
        .if eax != dLineStart
          mov eax, dLineStart
          stosd
          sub eax, dBufferFilePos
          neg eax
          stosd
        .endif

        MemFree pBuffer

        mov rax, pList
        sub rdi, sizeof DWORD                           ;Subtract first DWORD
        sub rdi, rax
        shr edi, $Log2(sizeof(GFL_DATA))
        mov [eax], edi
      .else
        MemFree pList
        xor eax, eax
      .endif
    .endif
  .else
    xor eax, eax
  .endif
  ret
GetFileLinesA endp

end
