; ==================================================================================================
; Title:      DbgClose.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgClose
; Purpose:    Closes the connection to the output device.
; Arguments:  None.
; Return:     Nothing.

align ALIGN_CODE
DbgClose proc
  .if hDbgDev != 0
    invoke CloseHandle, hDbgDev
  .endif
  ret
DbgClose endp

end
