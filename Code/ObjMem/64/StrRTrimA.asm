; ==================================================================================================
; Title:      StrRTrimA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRTrimA
; Purpose:    Trim blank characters from the end of an ANSI string.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
; Return:     Nothing.

align ALIGN_CODE
StrRTrimA proc uses rbx rdi rsi pDstStringA:POINTER, pSrcStringA:POINTER
  mov rdi, rcx
  mov rsi, rdx
  invoke StrEndA, rsi                                   ;pSrcStringA
@@:
  dec rax
  mov cl, [rax]
  cmp cl, ' '                                           ;Loop if space
  je @B
  cmp cl, 9                                             ;Loop if tab
  je @B
  sub rax, rsi                                          ;pSrcStringA
  inc rax
  lea rbx, [rdi + rax]
  .if rdi != rsi || eax == 0
    invoke MemClone, rdi, rsi, eax
  .endif
  m2z CHRA ptr [rbx]                                    ;Set ZTC
  ret
StrRTrimA endp

end
