; ==================================================================================================
; Title:      bin2dwordW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

NextCharW macro
  movzx edx, WORD ptr [ecx]
  add ecx, 2
  sub edx, WORD ptr "0"
  cmp edx, 1
  ja @F
  rcl eax, 1
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2dwordW
; Purpose:    Load an WIDE string binary representation of a DWORD.
; Arguments:  Arg1: -> Wide binary string.
; Return:     eax = DWORD.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
bin2dwordW proc pBuffer:POINTER
  xor eax, eax
  mov ecx, [esp + 4]
  not eax
  repeat 32
    NextCharW
  endm
@@:
  not eax
  ret 4
bin2dwordW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
