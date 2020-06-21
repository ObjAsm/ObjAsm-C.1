; ==================================================================================================
; Title:      StrAllocW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrAllocW
; Purpose:    Allocate space for a WIDE string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     rax -> New allocated WIDE string or NULL if failed.

align ALIGN_CODE
StrAllocW proc dChars:DWORD
  lea edx, [2*ecx + 2]                                  ;Make room for the ZTC & convert
  invoke GlobalAlloc, 0, edx                            ;GMEM_FIXED
  m2z CHRW ptr [rax]                                    ;Set the ZTC
  ret
StrAllocW endp

end
