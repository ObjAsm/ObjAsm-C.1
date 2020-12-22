; ==================================================================================================
; Title:      StrW2StrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrW2StrA
; Purpose:    Convert a WIDE string into an ANSI string. WIDE characters are converted to bytes by
;            decimation of the high byte.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source WIDE string.
; Return:     rax = number of characters.

align ALIGN_CODE
StrW2StrA proc uses rdi rsi pBuffer:POINTER, pSrcStringW:POINTER
  mov rdi, rcx                                          ;rdi -> Buffer
  mov rsi, rdx                                          ;rsi -> SrcStringW

@@1:
  lodsw
  or ah, ah                                             ;check high order byte if it is zero
  jz @@2
  xor eax, eax                                          ;No convertion is possible!
  jmp @@Exit
@@2:
  stosb
  or ax, ax                                             ;Check for ZTC
  jne @@1
  sub rdi, rcx                                          ;pBuffer
  mov rax, rdi                                          ;Return number of chars
@@Exit:
  ret
StrW2StrA endp

end
