; ==================================================================================================
; Title:      StrCatW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCatW
; Purpose:    Concatenate 2 WIDE strings.
; Arguments:  Arg1: Destrination WIDE string.
;             Arg2: Source WIDE string.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrCatW proc pBuffer:POINTER, pSrcStringW:POINTER
  invoke StrEndW, [esp + 4]                             ;pBuffer
  invoke StrCopyW, eax, [esp + 8]                       ;pSrcStringW
  ret 8
StrCatW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
