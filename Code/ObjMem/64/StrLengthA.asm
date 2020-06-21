; ==================================================================================================
; Title:      StrLengthA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLengthA
; Purpose:    Determine the length of an ANSI string not including the zero terminating character.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     eax = Length of the string in characters.

align ALIGN_CODE
StrLengthA proc uses rdi pString:POINTER
  mov rdi, rcx
  mov rcx, -1
  xor al, al
  repne scasb
  not rcx
  mov eax, ecx
  dec eax
  ret
StrLengthA endp

end
