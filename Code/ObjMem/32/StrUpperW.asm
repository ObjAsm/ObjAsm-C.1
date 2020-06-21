; ==================================================================================================
; Title:      StrUpperW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrUpperW
; Purpose:    Convert all WIDE string characters into uppercase.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrUpperW proc pStringW:POINTER
  mov ecx, [esp + 4]                                    ;ecx -> StringW
  sub ecx, 2
@@Char:
  add ecx, 2
  mov ax, [ecx]
  or ax, ax
  je @@Exit                                             ;End of string
  cmp ax, 'a'
  jb @@Char
  cmp ax, 'z'
  ja @@Char
  sub ax, 20H
  mov [ecx], ax
  jmp @@Char
align ALIGN_CODE
@@Exit:
  mov eax, [esp + 4]                                    ;Return string address
  ret 4
StrUpperW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
