; ==================================================================================================
; Title:      dword2hexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

externdef HexCharTableW:BYTE

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dword2hexW
; Purpose:    Converts a DWORD to its hexadecimal WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 18 bytes large to allocate the output string
;             (8 character words + ZTC = 18 bytes).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
dword2hexW proc pBuffer:POINTER, dValue:DWORD
  mov edx, [esp + 4]                                    ;edx -> Buffer
  lea ecx, [esp + 8]                                    ;ecx -> dValue
  movzx eax, BYTE ptr [ecx]
  mov eax, DWORD ptr HexCharTableW[4*eax]
  m2z WORD ptr [edx + 16]                               ;Set zero marker
  mov [edx + 12], eax
  movzx eax, BYTE ptr [ecx + 1]
  mov eax, DWORD ptr HexCharTableW[4*eax]
  mov [edx + 8], eax
  movzx eax, BYTE ptr [ecx + 2]
  movzx ecx, BYTE ptr [ecx + 3]
  mov eax, DWORD ptr HexCharTableW[4*eax]
  mov ecx, DWORD ptr HexCharTableW[4*ecx]
  mov [edx + 4], eax
  mov [edx], ecx
  ret 8
dword2hexW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
