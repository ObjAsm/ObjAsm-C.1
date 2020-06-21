; ==================================================================================================
; Title:      FindFileW.asm
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
??SearchDirW proc uses rbx rdi rsi r12 pPreStrW:POINTER, pPosStrW:POINTER
  local cPosStr[MAX_PATH]:CHRW
  local FFD:WIN32_FIND_DATAW
  local pNextPosStr:POINTER
  local hFindFile:HANDLE
  local pFilePart:POINTER

  .if pPosStrW != NULL
    mov rsi, $invoke(StrEndW, pPreStrW)
    lea rbx, FFD
    invoke StrLScanW, pPosStrW, "*"
    mov rdi, rax
    invoke StrLScanW, pPosStrW, "?"
    mov rcx, rax
    or rcx, rdi
    .if !ZERO?
      .if rax == 0
        mov rax, rdi
      .elseif rdi != 0
        uMin rax, rdi, rcx
      .endif
      ;There is a wildcard... we have to recurse again
      invoke StrLScanW, rax, "\"
      .if rax == NULL
        mov pNextPosStr, rax
        invoke StrCatW, rsi, pPosStrW
      .else
        mov pNextPosStr, rax
        sub rax, pPosStrW
        invoke StrCCatW, rsi, pPosStrW, eax
      .endif
      invoke StrRScanW, pPreStrW, "\"
      .if rax == NULL
        mov rsi, pPreStrW
      .else
        mov rsi, rax
        add rsi, sizeof(CHRW)
      .endif
      invoke FindFirstFileW, pPreStrW, rbx
      .if rax != INVALID_HANDLE_VALUE
        mov hFindFile, rax

        ;Main loop
@@1:
        .ifBitSet [rbx].WIN32_FIND_DATAW.dwFileAttributes, FILE_ATTRIBUTE_DIRECTORY
          ;Skip "." and ".."
          .if CHRW ptr [rbx].WIN32_FIND_DATAW.cFileName != "."
            invoke StrECopyW, rsi, addr [rbx].WIN32_FIND_DATAW.cFileName
            mov r12, rax

            ;Search localy
            invoke ??SearchDirW, pPreStrW, pNextPosStr
            mov rcx, r12
            test rax, rax
            jnz @@2
            mov CHRW ptr [rcx], ax                      ;Restore PreStr, eax == 0

            ;Search into subfolders, we create a new PosStr localy starting with "\*"
            lea rcx, cPosStr
            FillStringW [rcx], <\\*>
            .if rax != pNextPosStr
              add rcx, 4
              invoke StrCopyW, rcx, pNextPosStr
            .endif
            invoke ??SearchDirW, pPreStrW, addr cPosStr
            test rax, rax
            jnz @@2

          .endif
        .endif
        invoke FindNextFileW, hFindFile, rbx
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
      invoke StrCopyW, rsi, pPosStrW
      invoke ??SearchDirW, pPreStrW, NULL
    .endif

  .else
    ;Check if the path matches with the filter and if the file exists
    mov rdi, pPreStrW
    add rdi, 2*MAX_PATH                                 ;Get arguments using pPreStrW
    invoke StrIFilterW, pPreStrW, POINTER ptr [rdi]     ;pFilter
    .if rax != FALSE
      add rdi, 12
      lea rbx, FFD
      mov rsi, $invoke(StrEndW, pPreStrW)
      mov CHRW ptr [rsi], "\"
      add rsi, sizeof(CHRW)
      invoke StrCopyW, rsi, POINTER ptr [rdi]           ;pFileNameW
      invoke FindFirstFileW, pPreStrW, rbx
      .if rax == INVALID_HANDLE_VALUE
        xor eax, eax
        mov [rsi - 2], ax                               ;Restore pPreStrW
      .else
        invoke FindClose, rax
        invoke StrRScanW, pPreStrW, "\"
        add rax, 2
        lea rdx, [rbx].WIN32_FIND_DATAW.cFileName
        invoke StrCopyW, rax, rdx
        invoke GetFullPathNameW, pPreStrW, MAX_PATH, POINTER ptr [rdi + 8], addr pFilePart
      .endif
    .endif
  .endif
  ret
??SearchDirW endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FindFileW
; Purpose:    Search for a file in a list of paths.
; Arguments:  Arg1: -> WIDE file name.
;             Arg2: -> WIDE list of paths.
;             Arg3: -> Buffer that will contain the full path where the file was found.
; Return:     eax = TRUE if found, otherwise FALSE.
; Example:    invoke FindFile, $OfsCStr("free.c"), $OfsCStr("C:\masm32\ObjAsm\*.*",0), addr cBuff

align ALIGN_CODE
FindFileW proc uses rbx, pFileNameW:POINTER, pPathsW:POINTER, pReturnBufferW:POINTER
  local pFilter:POINTER, cPreStr[MAX_PATH]:CHRW      ;Don't change this line!!!

  ;Sanity check: all ptrs must be != NULL
  mov rbx, pPathsW
  mov rax, pFileNameW
  and rax, rbx
  and rax, pReturnBufferW
  jnz @@2
  cmp rax, pReturnBufferW
  jz @@4
  jmp @@3
  ;Loop through the path strings
@@1:
  lea rax, cPreStr
  m2z CHRW ptr [rax]                                    ;Reset PreStr
  mov pFilter, rbx
  invoke ??SearchDirW, rax, rbx
  test rax, rax
  jnz @@4
  invoke StrSizeW, rbx
  add rbx, rax
@@2:
  cmp CHRW ptr [rbx], NULL
  jnz @@1
  xor eax, eax
@@3:
  ;Here eax is zero
  mov rcx, pReturnBufferW
  m2z CHRW ptr [rcx]
@@4:
  ret
FindFileW endp

end
