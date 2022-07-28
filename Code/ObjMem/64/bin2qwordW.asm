; ==================================================================================================
; Title:      bin2qwordW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

NextCharW macro
  movzx rdx, WORD ptr [rcx]
  add rcx, 2
  sub rdx, WORD ptr "0"
  cmp rdx, 1
  ja @F
  rcl rax, 1
endm

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2qwordW
; Purpose:    Load an WIDE string binary representation of a QWORD.
; Arguments:  Arg1: -> Wide binary string.
; Return:     rax = QWORD.

OPTION PROC:NONE
align ALIGN_CODE
bin2qwordW proc pBuffer:POINTER
  xor eax, eax                                          ;rcx -> Buffer
  not rax
  repeat 64
    NextCharW
  endm
@@:
  not rax
  ret
bin2qwordW endp
OPTION PROC:DEFAULT

end
