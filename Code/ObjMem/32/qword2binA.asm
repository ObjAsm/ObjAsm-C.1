; ==================================================================================================
; Title:      qword2binA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

SetDword macro z
  mov eax, "0000"
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  inc eax                                               ;Set "1"
@@:
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 00000100h                                    ;Set "1"
@@:
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 00010000h                                    ;Set "1"
@@:
  rcl edx, 1                                            ;Set bit in carry flag
  jnc @F                                                ;Test carry flag
  add eax, 01000000h                                    ;Set "1"
@@:
  mov [ecx + z*4], eax
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: qword2binA
; Purpose:   Converts a QWORD to its binary ANSI string representation.
; Arguments: Arg1: -> Destination buffer.
;            Arg2: QWORD value.
; Return:    Nothing.
; Note:      The destination buffer must be at least 65 bytes large to allocate the output string
;            (64 character bytes + ZTC = 65 bytes).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
qword2binA proc pBuffer:POINTER, qValue:QWORD
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  mov edx, [esp + 12]                                   ;edx = (QuadWord ptr qValue).HiDWord
  SetDword 0
  SetDword 1
  SetDword 2
  SetDword 3
  SetDword 4
  SetDword 5
  SetDword 6
  SetDword 7
  mov edx, [esp + 8]                                    ;edx = (QuadWord ptr qValue).LoDWord
  SetDword 8
  SetDword 9
  SetDword 10
  SetDword 11
  SetDword 12
  SetDword 13
  SetDword 14
  SetDword 15
  m2z BYTE ptr [ecx + 64]                               ;Set terminator zero
  ret 12
qword2binA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
