; ==================================================================================================
; Title:      dword2binA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

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
  mov [rcx + 4*z], eax
endm

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dword2binA
; Purpose:    Convert a DWORD to its binary ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 33 BYTEs large to allocate the output string 
;             (32 character BYTEs + ZTC = 33 BYTEs).

OPTION PROC:NONE
align ALIGN_CODE
dword2binA proc pBuffer:POINTER, dValue:DWORD
  ;rcx -> Buffer, edx = dValue
  SetDword 0
  SetDword 1
  SetDword 2
  SetDword 3
  SetDword 4
  SetDword 5
  SetDword 6
  SetDword 7
  m2z CHRA ptr [rcx + 32]                               ;Set ZTC
  ret
dword2binA endp
OPTION PROC:DEFAULT

end
