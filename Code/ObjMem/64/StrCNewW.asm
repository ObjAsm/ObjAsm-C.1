; ==================================================================================================
; Title:      StrCNewW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCNewW
; Purpose:    Allocate a new copy of the source WIDE string with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, StrCNewW
;             returns NULL and doesn't allocate any heap space. Otherwise, StrCNew makes a duplicate
;             of the source string. The maximal size of the new string is limited to the second
;             parameter.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Maximal character count.
; Return:     rax -> New WIDE string copy.

align ALIGN_CODE
StrCNewW proc uses rbx rdi pStringW:POINTER, dMaxChars:DWORD
  mov rax, rcx                                          ;rax -> StringW
  test rax, rax                                         ;is NULL => fail
  jz @F
  invoke StrCLengthW, rax, edx
  mov rbx, rax
  invoke StrAllocW, eax
  test rax, rax
  jz @F                                                 ;Allocation failed
  shl rbx, 1
  m2z CHRW ptr [rax + rbx]                              ;Set ZTC
  mov rdi, rax
  invoke MemClone, rax, pStringW, ebx                   ;Copy the source string
  mov rax, rdi
@@:
  ret
StrCNewW endp

end
