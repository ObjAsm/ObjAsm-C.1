; ==================================================================================================
; Title:      qword2binA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop


SetQword macro z
  mov rax, "00000000"
  mov r8, 1

  rcl rdx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc rax                                               ;Set "1"
@@:
  repeat 7
    shl r8, 8                                           ;Set increment for next char
    rcl rdx, 1                                          ;Set bit in carry flag
    jnc @F                                              ;Test carry flag
    add rax, r8                                         ;Set "1"
@@:
  endm
  mov [rcx + z*sizeof(QWORD)], rax
endm

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2binA
; Purpose:    Convert a QWORD to its binary ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: QWORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 65 BYTEs large to allocate the output string
;             (64 character BYTEs + ZTC = 65 BYTEs).

OPTION PROC:NONE
align ALIGN_CODE
qword2binA proc pBuffer:POINTER, qValue:QWORD
  ;rcx -> Buffer, rdx = qValue
  SetQword 0
  SetQword 1
  SetQword 2
  SetQword 3
  SetQword 4
  SetQword 5
  SetQword 6
  SetQword 7
  m2z CHRA ptr [rcx + 8*sizeof(QWORD)]                  ;Set ZTC
  ret
qword2binA endp
OPTION PROC:DEFAULT

end
