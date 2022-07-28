; ==================================================================================================
; Title:      StrCatW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCatW
; Purpose:    Concatenate 2 WIDE strings.
; Arguments:  Arg1: Destrination WIDE string.
;             Arg2: Source WIDE string.
; Return:     Nothing.

align ALIGN_CODE
StrCatW proc pDstStrW:POINTER, pSrcStrW:POINTER
  invoke StrEndW, rcx                                   ;pDstStrW
  invoke StrCopyW, rax, pSrcStrW
  ret
StrCatW endp

end
