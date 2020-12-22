; ==================================================================================================
; Title:      dword2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

externdef HexCharTableA:CHRA

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dword2hexA
; Purpose:    Converts a DWORD to its hexadecimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 9 bytes large to allocate the output string
;             (8 character bytes + ZTC = 9 bytes).

align ALIGN_CODE
dword2hexA proc pBuffer:POINTER, dValue:DWORD
  ;rcx -> Buffer, edx = dValue
  lea r10, HexCharTableA
  movzx rax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr edx, 8
  shl r8, 16
  movzx rax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr edx, 8
  shl r8, 16
  movzx rax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr edx, 8
  shl r8, 16
  movzx rax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  mov [rcx], r8
  m2z CHRA ptr [rcx + 8*sizeof(CHRA)]                   ;Set ZTC
  ret
dword2hexA endp

end
