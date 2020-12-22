; ==================================================================================================
; Title:      StrRTrimW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRTrimW
; Purpose:    Trim blank characters from the end of a WIDE string.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     eax = number of characters in destination buffer.

align ALIGN_CODE
StrRTrimW proc uses rbx rdi rsi pDstStringW:POINTER, pSrcStringW:POINTER
  mov rdi, rcx
  mov rsi, rdx
  invoke StrEndW, rsi                                   ;pSrcStringW
@@:
  sub rax, 2
  mov cx, [rax]
  cmp cx, ' '                                           ;Loop if space
  je @B
  cmp cx, 9                                             ;Loop if tab
  je @B
  sub rax, rsi                                          ;pSrcStringW
  add rax, 2
  lea rbx, [rdi + rax]
  .if rdi != rsi || eax == 0
    invoke MemShift, rdi, rsi, eax
  .endif
  m2z CHRW ptr [rbx]                                    ;Set ZTC
  shr rax, 1                                            ;Return number of chars.
  ret
StrRTrimW endp

end
