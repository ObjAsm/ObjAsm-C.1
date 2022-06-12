; ==================================================================================================
; Title:      qword2binW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code

SetQword macro z
  mov rax, 0030003000300030h
  mov r8, 1

  rcl rdx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc rax                                               ;Set "1"
@@:
  repeat 3
    shl r8, 16                                          ;Set increment for next char
    rcl rdx, 1                                          ;Set bit in carry flag
    jnc @F                                              ;Test carry flag
    add rax, r8                                         ;Set "1"
@@:
  endm
  mov [rcx + z*sizeof(QWORD)], rax
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2binW
; Purpose:    Converts a QWORD to its binary WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: QWORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 130 bytes large to allocate the output string
;             (64 character words + ZTC = 130 bytes).

OPTION PROC:NONE
align ALIGN_CODE
qword2binW proc pBuffer:POINTER, qValue:QWORD
  ;rcx -> Buffer, rdx = qValue
  SetQword 00
  SetQword 01
  SetQword 02
  SetQword 03
  SetQword 04
  SetQword 05
  SetQword 06
  SetQword 07
  SetQword 08
  SetQword 09
  SetQword 10
  SetQword 11
  SetQword 12
  SetQword 13
  SetQword 14
  SetQword 15
  m2z CHRW ptr [rcx + 16*sizeof(QWORD)]                 ;Set ZTC
  ret
qword2binW endp
OPTION PROC:DEFAULT

end
