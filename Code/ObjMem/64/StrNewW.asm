; ==================================================================================================
; Title:      StrNewW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrNewW
; Purpose:    Allocate a new copy of the source WIDE string.
;            If the pointer to the source string is NULL or points to an empty string, StrNewW
;            returns NULL and doesn't allocate any heap space. Otherwise, StrNewW makes a duplicate
;            of the source string.
;            The allocated space is Length(String) + 1 character.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     rax -> New WIDE string copy.

align ALIGN_CODE
StrNewW proc uses rbx rdi rsi pStringW:POINTER
  mov rax, rcx                                          ;rax -> StringW
  test rax, rax                                         ;is NULL => fail
  jz @F
  mov rsi, rcx                                          ;rsi -> StringW
  invoke StrLengthW, rax
  mov rbx, rax
  invoke StrAllocW, eax
  test rax, rax
  jz @F                                                 ;Allocation failed
  lea r8, [2*rbx + 2]                                   ;Include zero ending marker
  mov rdi, rax
  invoke MemClone, rax, rsi, r8d                        ;Copy the source string
  mov rax, rdi
@@:
  ret
StrNewW endp

end
