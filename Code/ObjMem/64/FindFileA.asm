; ==================================================================================================
; Title:      FindFileA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

% include &MacPath&Memory.inc

.code

align ALIGN_CODE
??SearchDirA proc uses rbx rdi rsi r12 pPreStrA:POINTER, pPosStrA:POINTER
  local cPosStr[MAX_PATH]:CHRA
  local FFD:WIN32_FIND_DATA
  local pNextPosStr:POINTER
  local hFindFile:HANDLE
  local pFilePart:POINTER

  .if pPosStrA != NULL
    mov rsi, $invoke(StrEndA, pPreStrA)
    lea rbx, FFD
    invoke StrLScanA, pPosStrA, "*"
    mov rdi, rax
    invoke StrLScanA, pPosStrA, "?"
    mov rcx, rax
    or rcx, rdi
    .if !ZERO?
      .if rax == 0
        mov rax, rdi
      .elseif rdi != 0
        uMin rax, rdi
      .endif
      ;There is a wildcard... we have to recurse again
      invoke StrLScanA, rax, "\"
      .if eax == NULL
        mov pNextPosStr, rax
        invoke StrCatA, rsi, pPosStrA
      .else
        mov pNextPosStr, rax
        sub rax, pPosStrA
        invoke StrCCatA, rsi, pPosStrA, eax
      .endif
      invoke StrRScanA, pPreStrA, "\"
      .if rax == NULL
        mov rsi, pPreStrA
      .else
        mov rsi, rax
        inc rsi
      .endif
      invoke FindFirstFileA, pPreStrA, rbx
      .if rax != INVALID_HANDLE_VALUE
        mov hFindFile, rax

        ;Main loop
@@1:
        .ifBitSet [rbx].WIN32_FIND_DATA.dwFileAttributes, FILE_ATTRIBUTE_DIRECTORY
          ;Skip "." and ".."
          .if CHRA ptr [rbx].WIN32_FIND_DATA.cFileName != "."
            invoke StrECopyA, rsi, addr [rbx].WIN32_FIND_DATA.cFileName
            mov r12, rax

            ;Search localy
            invoke ??SearchDirA, pPreStrA, pNextPosStr
            mov rcx, r12
            test rax, rax
            jnz @@2
            mov CHRA ptr [rcx], al                    ;Restore PreStr, eax == 0

            ;Search into subfolders, we create a new PosStr localy starting with "\*"
            lea rcx, cPosStr
            mov DWORD ptr [rcx], "*\"
            .if rax != pNextPosStr
              add rcx, 2
              invoke StrCopyA, rcx, pNextPosStr
            .endif
            invoke ??SearchDirA, pPreStrA, addr cPosStr
            test rax, rax
            jnz @@2

          .endif
        .endif
        invoke FindNextFileA, hFindFile, rbx
        test rax, rax
        jnz @@1
@@2:
        mov r12, rax
        invoke FindClose, hFindFile
        mov rax, r12
      .else
        xor eax, eax
      .endif
    .else
      invoke StrCopyA, rsi, pPosStrA
      invoke ??SearchDirA, pPreStrA, NULL
    .endif

  .else
    ;Check if the path does match with the filter and if the file does exist
    mov rdi, pPreStrA
    add rdi, MAX_PATH                                 ;Get arguments using pPreStrA
    invoke StrIFilterA, pPreStrA, POINTER ptr [rdi]   ;pFilter
    .if rax != FALSE
      add rdi, 12
      lea rbx, FFD
      mov rsi, $invoke(StrEndA, pPreStrA)
      mov CHRA ptr [rsi], "\"
      inc rsi
      invoke StrCopyA, rsi, POINTER ptr [rdi]         ;pFileNameA
      invoke FindFirstFileA, pPreStrA, rbx
      .if rax == INVALID_HANDLE_VALUE
        xor eax, eax
        mov [rsi - 1], al                             ;Restore pPreStrA
      .else
        invoke FindClose, rax
        invoke StrRScanA, pPreStrA, "\"
        inc rax
        lea rdx, [rbx].WIN32_FIND_DATA.cFileName
        invoke StrCopyA, rax, rdx
        invoke GetFullPathNameA, pPreStrA, MAX_PATH, POINTER ptr [rdi + 8], addr pFilePart
      .endif
    .endif
  .endif
  ret
??SearchDirA endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FindFileA
; Purpose:    Search for a file in a list of paths.
; Arguments:  Arg1: -> ANSI file name.
;             Arg2: -> ANSI list of paths.
;             Arg3: -> Buffer that will contain the full path where the file was found.
; Return:     eax = TRUE if found, otherwise FALSE.
; Example:    invoke FindFile, $OfsCStr("free.c"), $OfsCStr("C:\masm32\ObjAsm\*.*",0), addr cBuff

align ALIGN_CODE
FindFileA proc uses rbx, pFileNameA:POINTER, pPathsA:POINTER, pReturnBufferA:POINTER
  local pFilter:POINTER, cPreStr[MAX_PATH]:CHRA         ;Don't change this line!!!

  ;Sanity check: all ptrs must be != NULL
  mov rbx, pPathsA
  mov rax, pFileNameA
  and rax, rbx
  and rax, pReturnBufferA
  jnz @@2
  cmp rax, pReturnBufferA
  jz @@4
  jmp @@3
  ;Loop through the path strings
@@1:
  lea rax, cPreStr
  m2z CHRA ptr [rax]                                    ;Reset PreStr
  mov pFilter, rbx
  invoke ??SearchDirA, rax, rbx
  test rax, rax
  jnz @@4
  invoke StrSizeA, rbx
  add rbx, rax
@@2:
  cmp CHRA ptr [rbx], NULL
  jnz @@1
  xor eax, eax
@@3:
  ;Here eax is zero
  mov rcx, pReturnBufferA
  m2z CHRA ptr [rcx]
@@4:
  ret
FindFileA endp

end
