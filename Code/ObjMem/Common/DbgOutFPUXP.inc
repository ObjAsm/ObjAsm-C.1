; ==================================================================================================
; Title:      DbgOutFPUXP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutFPU / DbgOutFPU_UEFI
; Purpose:    Displays the content of the FPU.
; Arguments:  Arg1: -> Destination Window name.
;             Arg2: Text RGB color.
; Return:     Nothing.

align ALIGN_CODE
ProcName proc uses xbx xdi xsi pDest:POINTER, dColor:DWORD
  local FPU_Buffer:FPU_CONTEXT, dLevels:DWORD
  local bBuffer[128]:CHRA, bFPExept[30]:CHRA

  fsave FPU_Buffer
  invoke StrCopyA, addr bFPExept, $OfsCStrA("Exceptions : e s p u o z d i")  ;FPU Exceptions
  mov ax, WORD ptr FPU_Buffer.wTagWord
  xor ecx, ecx
  .while ecx < 8
    rol ax, 2
    mov dx, ax
    and dx, 0000000000000011b
    .break .if dx == 0000000000000011b
    inc ecx
  .endw
  mov dLevels, ecx

  invoke StrECopyA, addr bBuffer, $OfsCStrA("FPU Levels : ")
  invoke udword2decA, xax, dLevels                    ;Display Levels found
  invoke DbgOutTextA, addr bBuffer, dColor, DBG_EFFECT_NEWLINE, pDest

  movzx eax, WORD ptr FPU_Buffer.wStatusWord
  shr eax, 6                                          ;ax  = 000000X* XXY*Y*ZZ
  shl al, 3                                           ;ax  = 000000X* *Y*ZZ---
  shl ax, 1                                           ;ax  = 00000X** Y*ZZ----
  shl al, 1                                           ;ax  = 00000X** *ZZ-----
  shr eax, 7                                          ;ax  = -------0 0000X***
  and eax, 7                                          ;ax  = 00000000 00000***
  .if eax == 0                                        ;If ST > Source
    mov xcx, $OfsCStrA("Conditional: ST !> Source")
  .elseif eax == 1                                    ;If ST < Source
    mov xcx, $OfsCStrA("Conditional: ST !< Source")
  .elseif eax == 4                                    ;IF ST = Source
    mov xcx, $OfsCStrA("Conditional: ST = Source")
  .else                                               ;Anything else
    mov xcx, $OfsCStrA("Conditional: Undefined")
  .endif
  invoke DbgOutTextA, xcx, dColor, DBG_EFFECT_NEWLINE, pDest

  movzx eax, WORD ptr FPU_Buffer.wStatusWord          ;eax = Status first found
  xor ecx, ecx                                        ;ecx = 0
  lea xdx, bFPExept                                   ;edx = Exception String Address
  add xdx, 13                                         ;edx = First Exception Bit
  .while ecx < 8                                      ;Go thru 8 exception bits
    rol al, 1                                         ;Rol the exception bits left 1
    jc @F                                             ;See if a '1' Passed out
    or BYTE ptr [xdx], 20h                            ;No, then force lower case (not set)
    jmp @next                                         ;    and onto next section
@@:
    and BYTE ptr [xdx], 0DFh                          ;Yes, then Force Upper case (Exception set)
@next:                                                ;and onto next section
    add xdx, 2                                        ;Since Spaces, inc 2 in string
    inc ecx                                           ;Next bit!
  .endw
  invoke DbgOutTextA, addr bFPExept, dColor, DBG_EFFECT_NEWLINE, pDest

  xor esi, esi                                        ;esi = Counter = 0
  lea xdi, FPU_Buffer.tST0
  .while esi < dLevels                                ;Go through all known stack entries
    finit
    fld TBYTE ptr [xdi]
    mov xbx, $invoke(StrECopyA, addr bBuffer, $OfsCStrA("  st("))
    invoke udword2decA, xax, esi                      ;Display levels
    invoke StrECopyA, addr [xbx + xax - 1], $OfsCStrA(") = ")
    invoke St0ToStrA, xax, 0, 4, f_SCI
    invoke DbgOutTextA, addr bBuffer, dColor, DBG_EFFECT_NEWLINE, pDest
    add xdi, sizeof(TBYTE)                            ;Next entry
    inc esi
  .endw

  ret
ProcName endp

end
