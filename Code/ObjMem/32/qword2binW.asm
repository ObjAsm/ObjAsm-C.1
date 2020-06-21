; ==================================================================================================
; Title:      qword2binW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

SetDword macro z
  mov eax, 00300030h
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc eax                                               ;Set "1"
@@:
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 00010000h                                    ;Set "1"
@@:
  mov [ecx + z*4], eax
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2binW
; Purpose:    Converts a QWORD to its binary WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: QWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 130 bytes large to allocate the output string
;             (64 character words + ZTC = 130 bytes).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
qword2binW proc pBuffer:POINTER, qValue:QWORD
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  mov edx, [esp + 12]                                   ;edx = (QuadWord ptr qValue).HiDWord
  SetDword 00
  SetDword 01
  SetDword 02
  SetDword 03
  SetDword 04
  SetDword 05
  SetDword 06
  SetDword 07
  SetDword 08
  SetDword 09
  SetDword 10
  SetDword 11
  SetDword 12
  SetDword 13
  SetDword 14
  SetDword 15
  mov edx, [esp + 8]                                    ;edx = (QuadWord ptr qValue).LoDWord
  SetDword 16
  SetDword 17
  SetDword 18
  SetDword 19
  SetDword 20
  SetDword 21
  SetDword 22
  SetDword 23
  SetDword 24
  SetDword 25
  SetDword 26
  SetDword 27
  SetDword 28
  SetDword 29
  SetDword 30
  SetDword 31
  m2z WORD ptr [ecx + 128]                              ;Set ZTC
  ret 12
qword2binW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
