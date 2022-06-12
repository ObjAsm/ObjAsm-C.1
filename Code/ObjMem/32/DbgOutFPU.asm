; ==================================================================================================
; Title:      DbgOutFPU.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

DbgOutFPUColor = $RGB(50,150,50)

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutFPU 
; Purpose:    Send a command to a specific Debug window.
; Purpose:    Displays the content of the FPU
; Arguments:  Arg1: -> Destination window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutFPU proc uses edi esi pDest:POINTER
  local FPU_Buffer:FPU_CONTEXT, dLevels:DWORD
  local cBuffer[128]:CHRA, cFloat[32]:CHRA, cFPExept[30]:CHRA

  fsave FPU_Buffer
  invoke StrCopyA, addr cFPExept, $OfsCStrA("Exceptions : e s p u o z d i")  ;Exceptions
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

  invoke wsprintfA, addr cBuffer, $OfsCStrA("FPU Levels : %d "), dLevels ;Display Levels found
  invoke DbgOutTextA, addr cBuffer, DbgOutFPUColor, DBG_EFFECT_NEWLINE, pDest

  movzx eax, WORD ptr FPU_Buffer.wStatusWord
  shr eax, 6                                            ;ax  = 000000X* XXY*Y*ZZ
  shl al, 3                                             ;ax  = 000000X* *Y*ZZ---
  shl ax, 1                                             ;ax  = 00000X** Y*ZZ----
  shl al, 1                                             ;ax  = 00000X** *ZZ-----
  shr eax, 7                                            ;ax  = -------0 0000X***
  and eax, 7                                            ;ax  = 00000000 00000***
  .if ( eax == 0 )                                      ;If ST > Source
    mov ecx, $OfsCStrA("Conditional: ST !> Source")
  .elseif( eax == 1 )                                   ;If ST < Source
    mov ecx, $OfsCStrA("Conditional: ST !< Source")
  .elseif( eax == 4 )                                   ;IF ST = Source
    mov ecx, $OfsCStrA("Conditional: ST = Source")
  .else                                                 ;Anything else
    mov ecx, $OfsCStrA("Conditional: Undefined")
  .endif
  invoke DbgOutTextA, ecx, DbgOutFPUColor, DBG_EFFECT_NEWLINE, pDest

  movzx eax, WORD ptr FPU_Buffer.wStatusWord            ;eax = Status first found
  xor ecx, ecx                                          ;ecx = 0
  lea edx, cFPExept                                     ;edx = Exception String Address
  add edx, 13                                           ;edx = First Exception Bit
  .while ecx < 8                                        ;Go thru 8 exception bits
    rol al, 1                                           ;Rol the exception bits left 1
    jc @F                                               ;See if a '1' Passed out
    or BYTE ptr [edx], 20h                              ;No, then force lower case (not set)
    jmp @next                                           ;    and onto next section
@@:
    and BYTE ptr [edx], 0DFh                            ;Yes, then Force Upper case (Exception set)
@next:                                                  ;and onto next section
    add edx, 2                                          ;Since Spaces, inc 2 in string
    inc ecx                                             ;Next bit!
  .endw
  invoke DbgOutTextA, addr cFPExept, DbgOutFPUColor, DBG_EFFECT_NEWLINE, pDest

  xor esi, esi                                          ;esi = Counter = 0
  lea edi, FPU_Buffer.tST0
  .while esi < dLevels                                  ;Go thru all known stack entries
    finit
    fld TBYTE ptr [edi]
    invoke St0ToStrA, addr cFloat, 0, 4, f_SCI          ;Create Text Strings from them
    invoke wsprintfA, addr cBuffer, $OfsCStrA("  st(%d) = %s"), \  ;And display their contents
                      esi, addr cFloat
    invoke DbgOutTextA, addr cBuffer, DbgOutFPUColor, DBG_EFFECT_NEWLINE, pDest
    add edi, sizeof TBYTE                               ;Next entry
    inc esi
  .endw

  ret
DbgOutFPU endp

end
