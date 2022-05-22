; ==================================================================================================
; Title:      sqword2decT.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; Links       https://publik.tuwien.ac.at/files/publik_287602.pdf
;             https://calc.penjee.com/  128 hex calculator
;             https://de.wikipedia.org/wiki/Integer_(Datentyp)
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqword2decT
; Purpose:    Converts a signed QWORD to its decimal string representation.
; Arguments:  Arg1: -> Destination string buffer.
;             Arg2: SQWORD value.
; Return:     eax = Number of bytes copied to the destination buffer, including the ZTC.

align ALIGN_CODE
ProcName proc uses ebx edi esi pBuffer:POINTER, sqValue:SQWORD
  local cBuffer[2*24*sizeof(CHR)]:CHR                     ;21 chars + 3 filler for alignment
                                                          ;All 2x to get safe for final copy
  mov CHR ptr cBuffer[24*sizeof(CHR)], 0
  lea edi, cBuffer[22*sizeof(CHR)]
  mov edx, DWORD ptr [sqValue + 4]
  mov eax, DWORD ptr [sqValue]
  .ifBitSet edx, BIT31                                    ;Check for negative input
    not edx                                               ;Negate edx::eax
    neg eax
    sbb edx, -1                                           ;Increment high word if low word was 0.
  .endif
  mov ebx, 100                                            ;Divisor

  .repeat                                                 ;Main loop
    ;Divide by 100
    .if edx == 0                                          ;Only one division needed?
      mov edx, 51EB851Fh
      mul edx
      shrd eax, edx, 5
      mov ecx, edx                                        ;Save edx
      inc eax
      mul ebx
      mov eax, ecx
      %mov ecx, [offset TwoDecDigitTable&TARGET_STR_AFFIX + sizeof(DCHR)*edx]
      shr eax, 5
      xor edx, edx                                        ;edx = quot.-hi(quotient in edx::eax)
    .else
      ;qddiv
      mov ecx, eax                                        ;Save dividend-lo in ecx
      mov eax, edx                                        ;Get dividend-hi
      xor edx, edx                                        ;Zero extend it into edx::eax
      div ebx                                             ;Quotient-hi in eax
      mov esi, eax                                        ;ecx = quotient-hi, eax =dividend-lo
      mov eax, ecx
      div ebx                                             ;eax = quotient-lo
      %mov ecx, [offset TwoDecDigitTable&TARGET_STR_AFFIX + sizeof(DCHR)*edx]
      mov edx, esi                                        ;edx = quot.-hi(quotient in edx::eax)
    .endif

    ;Store character
    mov [edi], $SubReg(ecx, sizeof(DCHR))
    sub edi, sizeof(DCHR)

    ;Check for last decimal digit 
    mov esi, eax
    or esi, edx
  .until ZERO?
  add edi, sizeof(CHR)

  .if cl == '0'
    add edi, sizeof(CHR)                                  ;Discard leading '0' character
  .endif

  .ifBitSet DWORD ptr [sqValue + 4], BIT31                ;Check for negative input
    mov CHR ptr [edi], '-'                                ;Write a minus sign
    sub edi, sizeof(CHR)
  .endif

  ;Copy 21 Chars
  mov ebx, pBuffer
  lea eax, cBuffer[24*sizeof(CHR)]
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    movups xmm0, [edi + 1]                                ;16 bytes
    mov edx, [edi + 17]                                   ;4 bytes
    mov cl, [edi + 33]                                    ;1 byte
    movups [ebx], xmm0
    mov [ebx + 16], edx
    mov [ebx + 32], cl
  else
    movups xmm0, [edi + 2]                                ;16 bytes
    movups xmm1, [edi + 18]                               ;16 bytes
    movq xmm2, [edi + 34]                                 ;8 bytes
    mov cx, [edi + 42]                                    ;2 bytes
    movups [ebx], xmm0
    movups [ebx + 16], xmm1
    movq [ebx + 32], xmm2
    mov [ebx + 40], cx
  endif
  sub eax, edi                                            ;Get BYTE count incl. ZTC

  ret
ProcName endp
