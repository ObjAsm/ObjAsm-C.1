; ==================================================================================================
; Title:      sdword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

externdef TwoDecDigitTableW:CHRW

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sdword2decW
; Purpose:    Converts a signed DWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: SDWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 24 bytes large to allocate the output string
;             (Sign + 10 WIDE characters + ZTC = 24 bytes).

align ALIGN_CODE
sdword2decW proc uses rdi rsi pBuffer:POINTER, sdValue:SDWORD
  ;rcx -> Buffer, edx = SDWORD
  mov r10, offset TwoDecDigitTableW
  mov eax, edx                          ;eax = sdValue
  mov edx, 0D1B71759h                   ;= 2^45\10000    13 bit extra shift
  test eax, eax
  jge @F
  mov CHRW ptr [rcx], '-'
  add rcx, 2
  neg eax
@@:
  mov edi, eax                          ;save a copy of the number
  mul edx                               ;gives 6 high digits in edx
  shr edx, 13                           ;correct for multiplier offset used to give better accuracy
  mov eax, 68DB9h                       ;=2^32\10000+1
  je @@10                               ;if zero then don’t need to process the top 6 digits
  imul esi, edx, 10000
  sub edi, esi
  mul edx
  mov esi, 100
  jnb @@09
  cmp edx, 9
  jbe @@08
  mov edx, DCHRW ptr [r10 + 4*rdx]
  mov [rcx], edx
  add rcx, 16

@@00:
  mul esi

@@01:
  mov edx, DCHRW ptr [r10 + 4*rdx]
  mov [rcx - 12], edx

@@02:
  mul esi

@@03:
  mov edx, DCHRW ptr [r10 + 4*rdx]
  mov [rcx - 8], edx

@@04:
  mov eax, 28F5C29h
  mul edi

@@05:
  mov edx, DCHRW ptr [r10 + 4*rdx]
  mov [rcx - 4], edx

@@06:
  mul esi

@@07:
  mov eax, DCHRW ptr [r10 + 4*rdx]
  mov [rcx], eax
  m2z CHRW ptr [rcx + 4]
  ret

@@08:
  add edx, 30h
  mov [rcx], edx
  add rcx, 14
  jnz @@00

@@09:
  mul esi
  jnb @F
  add rcx, 12
  cmp edx, 9
  ja @@01
  add edx, 30h
  sub rcx, 2
  mov [rcx - 10], edx
  jnz @@02

@@:
  mul esi
  jnb @@10
  add rcx, 8
  cmp edx, 9
  ja @@03
  add edx, 30h
  sub rcx, 2
  mov [rcx - 6], edx
  jnz @@04

@@10:
  mov eax, 28F5C29h
  mul edi
  mov esi, 100
  jnb @F
  add rcx, 4
  cmp edx, 9
  ja @@05
  add edx, 30h
  sub rcx, 2
  mov [rcx - 2], dx
  jnz @@06

@@:
  mul esi
  cmp edx, 9
  ja @@07
  lea rax, [rdx + 30h]
  mov [rcx], eax
  m2z CHRW ptr [rcx + 4]
  ret
sdword2decW endp

end
