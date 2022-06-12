; ==================================================================================================
; Title:      DbgClose.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgClose
; Purpose:    Closes the connection to the output device.
; Arguments:  None.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
DbgClose proc
  .if hDbgDev != 0
    invoke CloseHandle, hDbgDev
  .endif
  ret 0
DbgClose endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
