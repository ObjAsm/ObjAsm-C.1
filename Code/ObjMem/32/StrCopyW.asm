; ==================================================================================================
; Title:      StrCopyW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCopyW
; Purpose:    Copy a WIDE string to a destination buffer.
; Arguments:  Arg1: Destrination WIDE string buffer.
;             Arg2: Source WIDE string.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrCopyW proc pBuffer:POINTER, pSrcStringW:POINTER
  invoke StrLengthW, [esp + 8]                          ;pSrcStringW
  lea ecx, [2*eax + 2]                                  ;Calc # of bytes including zero terminator 
  invoke MemShift, [esp + 12], [esp + 12], ecx          ;pBuffer, pSrcStringW
  ret 8
StrCopyW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
