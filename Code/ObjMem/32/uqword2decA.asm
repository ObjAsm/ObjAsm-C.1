; ==================================================================================================
; Title:      uqword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqword2decA
; Purpose:    Converts a unsigned QWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: QWORD value.
; Return:     eax = Number of bytes copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 21 bytes large to allocate the output string
;             (20 character bytes + ZTC = 21 bytes).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
qword2decA proc pBuffer:POINTER, qValue:QWORD
  push DWORD ptr [esp + 12]
  push DWORD ptr [esp + 12]
  push $OfsCStrA("%I64u")
  push POINTER ptr [esp + 16]
  call wsprintfA
  inc eax
  add esp, 16
  ret 12
qword2decA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
