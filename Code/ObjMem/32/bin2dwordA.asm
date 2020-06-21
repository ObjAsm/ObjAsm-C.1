; ==================================================================================================
; Title:      bin2dwordA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

NextCharA macro
  movzx edx, BYTE ptr [ecx]
  inc ecx
  sub edx, "0"
  cmp edx, 1
  ja @F
  rcl eax, 1
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2dwordA
; Purpose:    Load an ANSI string binary representation of a DWORD.
; Arguments:  Arg1: -> ANSI binary string.
; Return:     eax = DWORD.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
bin2dwordA proc pBuffer:POINTER
  xor eax, eax
  mov ecx, [esp + 4]
  not eax
  repeat 32
    NextCharA
  endm
@@:
  not eax
  ret 4
bin2dwordA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
