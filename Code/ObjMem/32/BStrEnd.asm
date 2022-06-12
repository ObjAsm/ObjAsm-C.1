; ==================================================================================================
; Title:      BStrEnd.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: BStrEnd
; Purpose:   Get the address of the ZTC that terminates the string.
; Arguments: Arg1: -> Source BStr.
; Return:    eax -> ZTC.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
BStrEnd proc pBStr:POINTER
  mov eax, [esp + 4]                                    ;eax -> BStr
  add eax, DWORD ptr [eax - 4]                          ;Length of BStr
  ret 4
BStrEnd endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
