; ==================================================================================================
; Title:      dword2binW.asm
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
; Procedure:  dword2binW
; Purpose:    Converts a DWORD to its binary WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 66 bytes large to allocate the output string
;             (32 character words + ZTC = 66 bytes).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
dword2binW proc pBuffer:POINTER, dValue:DWORD
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  mov edx, [esp + 8]                                    ;edx = dValue
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
  m2z WORD ptr [ecx + 64]                               ;Set ZTC
  ret 8
dword2binW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
