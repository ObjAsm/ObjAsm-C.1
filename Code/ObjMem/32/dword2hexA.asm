; ==================================================================================================
; Title:      dword2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

externdef HexCharTableA:BYTE

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dword2hexA
; Purpose:    Converts a DWORD to its hexadecimal ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 9 bytes large to allocate the output string
;             (8 character bytes + ZTC = 9 bytes).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
dword2hexA proc pBuffer:POINTER, dValue:DWORD
  mov edx, [esp + 4]                                    ;edx -> Buffer
  lea ecx, [esp + 8]                                    ;ecx -> dValue
  movzx eax, BYTE ptr [ecx]
  mov ax, WORD ptr HexCharTableA[2*eax]
  m2z BYTE ptr [edx + 8]                                ;Set zero marker
  mov [edx + 6], ax
  movzx eax, BYTE ptr [ecx + 1]
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov [edx + 4], ax
  movzx eax, BYTE ptr [ecx + 2]
  movzx ecx, BYTE ptr [ecx + 3]
  mov ax, WORD ptr HexCharTableA[2*eax]
  mov cx, WORD ptr HexCharTableA[2*ecx]
  mov [edx + 2], ax
  mov [edx], cx
  ret 8
dword2hexA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
