; ==================================================================================================
; Title:      FindFileW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ??SearchDirW
; Purpose:    Search in a directory.
; Arguments:  Arg1: -> Pre-String.
;             Arg2: -> Pos-String.

align ALIGN_CODE
??SearchDirW proc uses ebx edi esi pPreStrW:POINTER, pPosStrW:POINTER
  local cPosStr[MAX_PATH]:CHRW
  local FFD:WIN32_FIND_DATAW
  local pNextPosStr:POINTER
  local hFindFile:HANDLE
  local pFilePart:POINTER

  .if pPosStrW != NULL
    mov esi, $invoke(StrEndW, pPreStrW)
    lea ebx, FFD
    invoke StrLScanW, pPosStrW, "*"
    mov edi, eax
    invoke StrLScanW, pPosStrW, "?"
    mov ecx, eax
    or ecx, edi
    .if !ZERO?
      .if eax == 0
        mov eax, edi
      .elseif edi != 0
        uMin eax, edi, ecx
      .endif
      ;There is a wildcard... we have to recurse again
      invoke StrLScanW, eax, "\"
      .if eax == NULL
        mov pNextPosStr, eax
        invoke StrCatW, esi, pPosStrW
      .else
        mov pNextPosStr, eax
        sub eax, pPosStrW
        invoke StrCCatW, esi, pPosStrW, eax
      .endif
      invoke StrRScanW, pPreStrW, "\"
      .if eax == NULL
        mov esi, pPreStrW
      .else
        mov esi, eax
        add esi, sizeof CHRW
      .endif
      invoke FindFirstFileW, pPreStrW, ebx
      .if eax != INVALID_HANDLE_VALUE
        mov hFindFile, eax

        ;Main loop
@@1:
        .ifBitSet [ebx].WIN32_FIND_DATAW.dwFileAttributes, FILE_ATTRIBUTE_DIRECTORY
          ;Skip "." and ".."
          .if CHRW ptr [ebx].WIN32_FIND_DATAW.cFileName != "."
            invoke StrECopyW, esi, addr [ebx].WIN32_FIND_DATAW.cFileName
            push eax

            ;Search localy
            invoke ??SearchDirW, pPreStrW, pNextPosStr
            pop ecx
            or eax, eax
            jnz @@2
            mov CHRW ptr [ecx], ax                    ;Restore PreStr, eax == 0

            ;Search into subfolders, we create a new PosStr localy starting with "\*"
            lea ecx, cPosStr
            FillStringW [ecx], <\\*>
            .if eax != pNextPosStr
              add ecx, 4
              invoke StrCopyW, ecx, pNextPosStr
            .endif
            invoke ??SearchDirW, pPreStrW, addr cPosStr
            or eax, eax
            jnz @@2

          .endif
        .endif
        invoke FindNextFileW, hFindFile, ebx
        or eax, eax
        jnz @@1
@@2:
        push eax
        invoke FindClose, hFindFile
        pop eax
      .else
        xor eax, eax
      .endif
    .else
      invoke StrCopyW, esi, pPosStrW
      invoke ??SearchDirW, pPreStrW, NULL
    .endif

  .else
    ;Check if the path matches with the filter and if the file exists
    mov edi, pPreStrW
    add edi, 2*MAX_PATH                               ;Get arguments using pPreStrW
    invoke StrIFilterW, pPreStrW, POINTER ptr [edi]   ;pFilter
    .if eax != FALSE
      add edi, 12
      lea ebx, FFD
      mov esi, $invoke(StrEndW, pPreStrW)
      mov CHRW ptr [esi], "\"
      add esi, sizeof CHRW
      invoke StrCopyW, esi, POINTER ptr [edi]         ;pFileNameW
      invoke FindFirstFileW, pPreStrW, ebx
      .if eax == INVALID_HANDLE_VALUE
        xor eax, eax
        mov [esi - 2], ax                             ;Restore pPreStrW
      .else
        invoke FindClose, eax
        invoke StrRScanW, pPreStrW, "\"
        add eax, 2
        lea ecx, [ebx].WIN32_FIND_DATAW.cFileName
        invoke StrCopyW, eax, ecx
        invoke GetFullPathNameW, pPreStrW, MAX_PATH, POINTER ptr [edi + 8], addr pFilePart
      .endif
    .endif
  .endif
  ret
??SearchDirW endp

align ALIGN_CODE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: FindFileW
; Purpose:   Search for a file in a list of paths.
; Arguments: Arg1: -> Wide file name.
;            Arg2: -> Wide list of paths.
;            Arg3: -> Buffer that will contain the full path where the file was found.
; Return:    eax = TRUE if found, otherwise FALSE.
; Example:   invoke FindFile, $OfsCStr("free.c"), $OfsCStr("\ObjAsm\*.*",0), addr cBuffer

FindFileW proc uses ebx, pFileNameW:POINTER, pPathsW:POINTER, pReturnBufferW:POINTER
  local pFilter:POINTER, cPreStr[MAX_PATH]:CHRW         ;Don't change this line!!!

  ;Sanity check: all ptrs must be != NULL
  mov ebx, pPathsW
  mov eax, pFileNameW
  and eax, ebx
  and eax, pReturnBufferW
  jnz @@2
  cmp eax, pReturnBufferW
  jz @@4
  jmp @@3
  align ALIGN_CODE
  ;Loop through the path strings
@@1:
  lea eax, cPreStr
  m2z CHRW ptr [eax]                                    ;Reset PreStr
  mov pFilter, ebx
  invoke ??SearchDirW, eax, ebx
  test eax, eax
  jnz @@4
  invoke StrSizeW, ebx
  add ebx, eax
@@2:
  cmp CHRW ptr [ebx], NULL
  jnz @@1
  xor eax, eax
@@3:
  ;Here eax is zero
  mov ecx, pReturnBufferW
  m2z CHRW ptr [ecx]
@@4:
  ret
FindFileW endp

end
