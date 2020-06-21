; ==================================================================================================
; Title:      bin2qwordA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop


NextCharA macro
  movzx rdx, BYTE ptr [rcx]
  inc rcx
  sub rdx, "0"
  cmp rdx, 1
  ja @F
  rcl rax, 1
endm

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  bin2qwordA
; Purpose:    Load an ANSI string binary representation of a QWORD.
; Arguments:  Arg1: -> ANSI binary string.
; Return:     rax = QWORD.

align ALIGN_CODE
bin2qwordA proc pBuffer:POINTER
  xor eax, eax                                          ;rcx -> Buffer
  not eax
  repeat 64
    NextCharA
  endm
@@:
  not eax
  ret
bin2qwordA endp

end
