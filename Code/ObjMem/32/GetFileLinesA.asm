; ==================================================================================================
; Title:      GetFileLinesA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

GFL_DATA struc
  dFileOffset   DWORD   ?     ;We are limited to 4GB files!
  dLineLength   DWORD   ?     ;Not including the CRLF sequence
GFL_DATA ends

GFL_BUFFER_SIZE     equ 4096                                  ;Should be a power of 2
GFL_LIST_SIZE_INIT  equ sizeof DWORD + 512*sizeof GFL_DATA    ;Must not be less than 12
GFL_LIST_SIZE_GROW  equ 512*sizeof GFL_DATA                   ;Must not be less than 12
GFL_CR_MASK         equ 0D0D0D0Dh


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetFileLinesA
; Purpose:    Return line information of an ANSI text file in form of GFL_DATA structures.
; Arguments:  Arg1: Opened file handle.
; Return:     eax -> Mem block. The user must dispose it using MemFree.
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
GetFileLinesA proc uses ebx edi esi hFile:HANDLE
  local pList:POINTER, pListEnd:POINTER, dListSize:DWORD
  local pBuffer:POINTER, pBufferEnd:POINTER
  local dBufferFilePos:DWORD, sdCorrOffset:SDWORD, dLineStart:DWORD
  local dBytesRead:DWORD, dPrevBytesRead:DWORD

  .const
    GFL_MASK_TABLE DWORD 0000000FFh, 00000FFFFh, 000FFFFFFh
    GFL_JUMP_TABLE POINTER @@1, @@2, @@3, @@4

  .code
  ;Ensure all requirements are met
  .if hFile != INVALID_HANDLE_VALUE
    mov dListSize, GFL_LIST_SIZE_INIT
    MemAlloc dListSize
    .if eax != NULL
      mov pList, eax
      mov edi, eax
      add eax, dListSize
      sub eax, sizeof GFL_DATA
      mov pListEnd, eax
      add edi, 4                                        ;Make room for the count DWORD

      MemAlloc GFL_BUFFER_SIZE
      .if eax != NULL
        mov pBuffer, eax
        m2z dBufferFilePos
        mov sdCorrOffset, eax
        m2z dLineStart
        m2z dPrevBytesRead

@@Loop:
        .repeat
          m2m dPrevBytesRead, dBytesRead, eax
          ;Read a data chunk
          invoke ReadFile, hFile, pBuffer, GFL_BUFFER_SIZE, addr dBytesRead, NULL
          .break .if dBytesRead == 0

          ;Compute aligned address of the last valid DWORD
          mov esi, pBuffer
          mov ecx, esi
          mov eax, dBytesRead
          add ecx, eax
          dec ecx
          and ecx, 0FFFFFFFCh
          mov pBufferEnd, ecx

          ;Cut garbage from the last DWORD
          and eax, 3
          .if !ZERO?
            ;Read mask and apply it mask to the last DWORD
            mov edx, [GFL_MASK_TABLE + 4*eax - 4]
            and [ecx], edx
          .endif

          ;Analize the data, searching for the char 13
          .while esi <= pBufferEnd
            mov ebx, [esi]
            xor ebx, GFL_CR_MASK                        ;Puts a zero where the CR was found

            test ebx, 0000000FFh
            jz @@Found
@@1:
            inc esi
            test ebx, 00000FF00h
            jz @@Found
@@2:
            inc esi
            test ebx, 000FF0000h
            jz @@Found
@@3:
            inc esi
            test ebx, 0FF000000h
            jnz @@4

@@Found:
            ;Compute line start and character file offset
            mov ecx, dLineStart
            mov eax, ecx
            stosd
            mov eax, esi
            sub eax, sdCorrOffset
            sub eax, ecx
            stosd                                       ;edi -> valid position into the list
            lea eax, [eax + ecx + 2]                    ;+2 = CRLF
            mov dLineStart, eax

            ;We check edi to ensure that it remains pointing to a valid position
            ;  to hold a complete GFL_DATA structure
            .if edi > pListEnd
              ;Extend the list by the factor GFL_LIST_SIZE_GROW
              sub edi, pList
              add dListSize, GFL_LIST_SIZE_GROW
              MemReAlloc pList, dListSize
              .if eax != NULL
                ;Operation succeeded => update internal values
                mov pList, eax
                add edi, eax                            ;Adjust new edi
                add eax, dListSize
                sub eax, sizeof GFL_DATA
                mov pListEnd, eax
              .else
                ;Operation failed => release allocated resources and exit
                MemFree pList
                MemFree pBuffer
                xor eax, eax
                ret
              .endif
            .endif
            mov ecx, esi
            and ecx, 3
            jmp [offset GFL_JUMP_TABLE + 4*ecx]
@@4:
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

        mov eax, pList
        sub edi, sizeof DWORD                           ;Subtract first DWORD
        sub edi, eax
        shr edi, 3                                      ;GFL_DATA structure size
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
