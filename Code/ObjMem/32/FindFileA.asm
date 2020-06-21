; ==================================================================================================
; Title:      FindFileA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ??SearchDirA
; Purpose:    Search in a directory.
; Arguments:  Arg1: -> Pre-String.
;             Arg2: -> Pos-String.

align ALIGN_CODE
??SearchDirA proc uses ebx edi esi pPreStrA:POINTER, pPosStrA:POINTER
  local cPosStr[MAX_PATH]:CHRA
  local FFD:WIN32_FIND_DATA
  local pNextPosStr:POINTER
  local hFindFile:HANDLE
  local pFilePart:POINTER

  .if pPosStrA != NULL
    mov esi, $invoke(StrEndA, pPreStrA)
    lea ebx, FFD
    invoke StrLScanA, pPosStrA, "*"
    mov edi, eax
    invoke StrLScanA, pPosStrA, "?"
    mov ecx, eax
    or ecx, edi
    .if !ZERO?
      .if eax == 0
        mov eax, edi
      .elseif edi != 0
        uMin eax, edi, ecx
      .endif
      ;There is a wildcard... we have to recurse again
      invoke StrLScanA, eax, "\"
      .if eax == NULL
        mov pNextPosStr, eax
        invoke StrCatA, esi, pPosStrA
      .else
        mov pNextPosStr, eax
        sub eax, pPosStrA
        invoke StrCCatA, esi, pPosStrA, eax
      .endif
      invoke StrRScanA, pPreStrA, "\"
      .if eax == NULL
        mov esi, pPreStrA
      .else
        mov esi, eax
        inc esi
      .endif
      invoke FindFirstFileA, pPreStrA, ebx
      .if eax != INVALID_HANDLE_VALUE
        mov hFindFile, eax

        ;Main loop
@@1:
        .ifBitSet [ebx].WIN32_FIND_DATA.dwFileAttributes, FILE_ATTRIBUTE_DIRECTORY
          ;Skip "." and ".."
          .if CHRA ptr [ebx].WIN32_FIND_DATA.cFileName != "."
            invoke StrECopyA, esi, addr [ebx].WIN32_FIND_DATA.cFileName
            push eax

            ;Search localy
            invoke ??SearchDirA, pPreStrA, pNextPosStr
            pop ecx
            or eax, eax
            jnz @@2
            mov CHRA ptr [ecx], al                    ;Restore PreStr, eax == 0

            ;Search into subfolders, we create a new PosStr localy starting with "\*"
            lea ecx, cPosStr
            mov DWORD ptr [ecx], "*\"
            .if eax != pNextPosStr
              add ecx, 2
              invoke StrCopyA, ecx, pNextPosStr
            .endif
            invoke ??SearchDirA, pPreStrA, addr cPosStr
            or eax, eax
            jnz @@2

          .endif
        .endif
        invoke FindNextFileA, hFindFile, ebx
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
      invoke StrCopyA, esi, pPosStrA
      invoke ??SearchDirA, pPreStrA, NULL
    .endif

  .else
    ;Check if the path does match with the filter and if the file does exist
    mov edi, pPreStrA
    add edi, MAX_PATH                                 ;Get arguments using pPreStrA
    invoke StrIFilterA, pPreStrA, POINTER ptr [edi]   ;pFilter
    .if eax != FALSE
      add edi, 12
      lea ebx, FFD
      mov esi, $invoke(StrEndA, pPreStrA)
      mov CHRA ptr [esi], "\"
      inc esi
      invoke StrCopyA, esi, POINTER ptr [edi]         ;pFileNameA
      invoke FindFirstFileA, pPreStrA, ebx
      .if eax == INVALID_HANDLE_VALUE
        xor eax, eax
        mov [esi - 1], al                             ;Restore pPreStrA
      .else
        invoke FindClose, eax
        invoke StrRScanA, pPreStrA, "\"
        inc eax
        lea ecx, [ebx].WIN32_FIND_DATA.cFileName
        invoke StrCopyA, eax, ecx
        invoke GetFullPathNameA, pPreStrA, MAX_PATH, POINTER ptr [edi + 8], addr pFilePart
      .endif
    .endif
  .endif
  ret
??SearchDirA endp

align ALIGN_CODE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FindFileA
; Purpose:    Search for a file in a list of paths.
; Arguments:  Arg1: -> ANSI file name.
;             Arg2: -> ANSI list of paths.
;             Arg3: -> Buffer that will contain the full path where the file was found.
;                      Buffer size = MAX_PATH.
; Return:     eax = TRUE if found, otherwise FALSE.
; Example:    invoke FindFile, $OfsCStr("free.c"), $OfsCStr("\ObjAsm\*.*",0), addr cBuffer

FindFileA proc uses ebx, pFileNameA:POINTER, pPathsA:POINTER, pReturnBufferA:POINTER
  local pFilter:POINTER, cPreStr[MAX_PATH]:CHRA         ;Don't change this line!!!

  ;Sanity check: all ptrs must be != NULL
  mov ebx, pPathsA
  mov eax, pFileNameA
  and eax, ebx
  and eax, pReturnBufferA
  jnz @@2
  cmp eax, pReturnBufferA
  jz @@4
  jmp @@3
  align ALIGN_CODE
  ;Loop through the path strings
@@1:
  lea eax, cPreStr
  m2z CHRA ptr [eax]                                    ;Reset PreStr
  mov pFilter, ebx
  invoke ??SearchDirA, eax, ebx
  test eax, eax
  jnz @@4
  invoke StrSizeA, ebx
  add ebx, eax
@@2:
  cmp CHRA ptr [ebx], NULL
  jnz @@1
  xor eax, eax
@@3:
  ;Here eax is zero
  mov ecx, pReturnBufferA
  m2z CHRA ptr [ecx]
@@4:
  ret
FindFileA endp

end
