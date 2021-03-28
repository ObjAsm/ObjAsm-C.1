; ==================================================================================================
; Title:      StrLengthW.asm
; Author:     G. Friedrich
; Version:    3.0.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLengthW
; Purpose:    Determine the length of a WIDE string not including the ZTC.
; Arguments:  Arg1: -> WIDE string.
; Return:     rax = Length of the string in characters.

align ALIGN_CODE
StrLengthW proc uses rdi pStringW:POINTER
  mov rdi, rcx
  mov rcx, -1
  xor ax, ax
  repne scasw
  not rcx
  mov rax, rcx
  dec rax
  ret
StrLengthW endp

end
