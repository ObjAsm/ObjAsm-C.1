; ==================================================================================================
; Title:      StrNewA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrNewA
; Purpose:    Allocate a new copy of the source ANSI string.
;             If the pointer to the source string is NULL or points to an empty string, StrNewA
;             returns NULL and doesn't allocate any heap space. Otherwise, StrNewA makes a duplicate
;             of the source string.
;             The allocated space is Length(String) + 1 character.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     rax -> New ANSI string copy or NULL if failed.

align ALIGN_CODE
StrNewA proc uses rbx rdi rsi pStringA:POINTER
  mov rax, rcx                                          ;rax -> StringA
  test rax, rax                                         ;is NULL => fail
  jz @F
  mov rsi, rcx                                          ;rsi -> StringA
  invoke StrLengthA, rax
  mov rbx, rax
  invoke StrAllocA, eax
  test rax, rax
  jz @F                                                 ;Allocation failed
  inc rbx                                               ;Include zero ending marker
  mov rdi, rax
  invoke MemClone, rax, rsi, ebx                        ;Copy the source string
  mov rax, rdi
@@:
  ret
StrNewA endp

end
