; ==================================================================================================
; Title:      bin2dwordA.asm
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
; Procedure:  bin2dwordA
; Purpose:    Load an ANSI string binary representation of a DWORD.
; Arguments:  Arg1: -> ANSI binary string.
; Return:     eax = DWORD.

OPTION PROC:NONE
align ALIGN_CODE
bin2dwordA proc pBuffer:POINTER
  xor eax, eax                                          ;rcx -> Buffer
  not rax
  repeat 32
    NextCharA
  endm
@@:
  not rax
  ret
bin2dwordA endp
OPTION PROC:DEFAULT

end
