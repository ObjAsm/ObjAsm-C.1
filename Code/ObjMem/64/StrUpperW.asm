; ==================================================================================================
; Title:      StrUpperW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrUpperW
; Purpose:    Convert all WIDE string characters into uppercase.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     Nothing.

align ALIGN_CODE
StrUpperW proc pStringW:POINTER
  ;rcx -> StringW
  sub rcx, sizeof(CHRW)
@@Char:
  add rcx, sizeof(CHRW)
  mov ax, [rcx]
  or ax, ax
  je @@Exit                                             ;End of string
  cmp ax, 'a'
  jb @@Char
  cmp ax, 'z'
  ja @@Char
  sub ax, 20H
  mov [rcx], ax
  jmp @@Char
@@Exit:
  ret
StrUpperW endp

end
