; ==================================================================================================
; Title:      StrCNewA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCNewA
; Purpose:    Allocate a new copy of the source ANSI string with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, StrCNewA
;             returns NULL and doesn't allocate any heap space. Otherwise, StrCNew makes a duplicate
;             of the source string. The maximal size of the new string is limited to the second
;             parameter.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: Maximal character count.
; Return:     rax -> New ANSI string copy.

align ALIGN_CODE
StrCNewA proc uses rbx rdi pStringA:POINTER, dMaxChars:DWORD
  mov rax, rcx                                          ;rax -> StringA
  test rax, rax                                         ;Is NULL => fail
  jz @F
  invoke StrCLengthA, rcx, edx
  mov rbx, rax
  invoke StrAllocA, eax
  test rax, rax
  jz @F                                                 ;Allocation failed
  m2z CHRA ptr [rax + rbx]                              ;Set ZTC
  mov rdi, rax
  invoke MemClone, rax, pStringA, ebx                   ;Copy the source string
  mov rax, rdi
@@:
  ret
StrCNewA endp

end
