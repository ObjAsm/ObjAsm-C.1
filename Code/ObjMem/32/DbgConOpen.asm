; ==================================================================================================
; Title:      DbgConOpen.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgConOpen 
; Purpose:    Open a new console for the calling process.
; Arguments:  None.
; Return:     eax = TRUE if it was opened, otherwise FALSE.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
DbgConOpen proc
  .if hDbgDev == 0
    .if $invoke(AllocConsole)
      invoke SetConsoleTitleW, offset szDbgSrc
      mov hDbgDev, $invoke(GetStdHandle, STD_OUTPUT_HANDLE)
    .else
      mov hDbgDev, -1
      xor eax, eax
    .endif
  .else
    xor eax, eax
    inc eax
  .endif
  ret 0
DbgConOpen endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
