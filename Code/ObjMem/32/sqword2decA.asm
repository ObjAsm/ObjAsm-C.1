; ==================================================================================================
; Title:      sqword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqword2decA
; Purpose:    Converts a signed QWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: sqword value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 21 bytes large to allocate the output string
;             (Sign + 19 ANSI characters + ZTC = 21 bytes).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
sqword2decA proc pBuffer:POINTER, sqValue:SQWORD
  push DWORD ptr [esp + 12]
  push DWORD ptr [esp + 12]
  push $OfsCStrA("%I64i")
  push POINTER ptr [esp + 16]
  call wsprintfA
  add esp, 16
  ret 12
sqword2decA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
