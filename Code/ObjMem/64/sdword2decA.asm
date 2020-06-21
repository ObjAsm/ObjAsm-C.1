; ==================================================================================================
; Title:      sdword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

externdef TwoDecDigitTableA:CHRA

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sdword2decA
; Purpose:    Converts a signed DWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: SDWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 12 bytes large to allocate the output string
;             (Sign + 10 ANSI characters + ZTC = 12 bytes).

align ALIGN_CODE
sdword2decA proc uses rdi rsi pBuffer:POINTER, sdValue:SDWORD
  ;rcx -> Buffer, edx = SDWORD
  mov r10, offset TwoDecDigitTableA
  mov eax, edx                        ;eax = sdValue
  mov edx, 0D1B71759h                 ;= 2^45\10000    13 bit extra shift
  test eax, eax                       
  jge @F                              
  mov CHRA ptr [rcx], '-'             
  add rcx, 1                          
  neg eax                             
@@:                                   
  mov edi, eax                        ;save a copy of the number
  mul edx                             ;gives 6 high digits in edx
  shr edx, 13                         ;correct for multiplier offset used to give better accuracy
  mov eax, 68DB9h                     ;=2^32\10000+1
  je Label_10                         ;if zero then don’t need to process the top 6 digits
  imul esi, edx, 10000
  sub edi, esi
  mul edx
  mov esi, 100
  jnb Label_09
  cmp edx, 9
  jbe Label_08
  mov dx, DCHRA ptr [r10 + 2*rdx]
  mov [rcx], dx
  add rcx, 8

Label_00:
  mul esi

Label_01:
  mov dx, DCHRA ptr [r10 + 2*rdx]
  mov [rcx - 6], dx

Label_02:
  mul esi

Label_03:
  mov dx, DCHRA ptr [r10 + 2*rdx]
  mov [rcx - 4], dx

Label_04:
  mov eax, 28F5C29h
  mul edi

Label_05:
  mov dx, DCHRA ptr [r10 + 2*rdx]
  mov [rcx - 2], dx

Label_06:
  mul esi

Label_07:
  mov ax, DCHRA ptr [r10 + 2*rdx]
  mov [rcx], ax
  m2z CHRA ptr [rcx + 2]
  ret

Label_08:
  add edx, 30h
  mov [rcx], dx
  add rcx, 7
  jnz Label_00

Label_09:
  mul esi
  jnb @F
  add rcx, 6
  cmp edx, 9
  ja Label_01
  add edx, 30h
  sub rcx, 1
  mov [rcx - 5], dx
  jnz Label_02

@@:
  mul esi
  jnb Label_10
  add rcx, 4
  cmp edx, 9
  ja Label_03
  add edx, 30h
  sub rcx, 1
  mov [rcx - 3], dx
  jnz Label_04

Label_10:
  mov eax, 28F5C29h
  mul edi
  mov esi, 100
  jnb @F
  add rcx, 2
  cmp edx, 9
  ja Label_05
  add edx, 30h
  sub rcx, 1
  mov [rcx - 1], dx
  jnz Label_06

@@:
  mul esi
  cmp edx, 9
  ja Label_07
  lea rax, [rdx + 30h]
  mov [rcx], ax
  m2z CHRA ptr [rcx + 2]
  ret
sdword2decA endp

end
