; ==================================================================================================
; Title:      StrAllocA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrAllocA
; Purpose:    Allocate space for an ANSI string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     rax -> New allocated ANSI string or NULL if failed.

align ALIGN_CODE
StrAllocA proc dChars:DWORD
  lea edx, [ecx + 1]                                    ;Make room for the ZTC
  invoke GlobalAlloc, 0, edx                            ;GMEM_FIXED
  m2z CHRA ptr [rax]                                    ;Set the ZTC
  ret
StrAllocA endp

end
