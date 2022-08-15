; ==================================================================================================
; Title:      bin2dwordW.asm
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
; Procedure:  bin2dwordW
; Purpose:    Load an WIDE string binary representation of a DWORD.
; Arguments:  Arg1: -> WIDE binary string.
; Return:     eax = DWORD.

OPTION PROC:NONE
align ALIGN_CODE
bin2dwordW proc pBuffer:POINTER
  xor eax, eax                                          ;rcx -> Buffer
  not rax
  repeat 32
    NextCharW
  endm
@@:
  not rax
  ret
bin2dwordW endp
OPTION PROC:DEFAULT

end
