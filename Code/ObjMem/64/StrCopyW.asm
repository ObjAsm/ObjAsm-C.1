; ==================================================================================================
; Title:      StrCopyW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCopyW
; Purpose:    Copy a WIDE string to a destination buffer.
; Arguments:  Arg1: Destrination WIDE string buffer.
;             Arg2: Source WIDE string.
; Return:     Nothing.

align ALIGN_CODE
StrCopyW proc pDstStringW:POINTER, pSrcStringW:POINTER
  invoke StrSizeW, rdx
  invoke MemShift, pDstStringW, pSrcStringW, eax
  ret
StrCopyW endp

end
