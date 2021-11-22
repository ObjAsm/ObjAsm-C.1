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
; Return:     eax -> String.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrUpperW proc pStringW:POINTER
  mov ecx, [esp + 4]                                    ;ecx -> StringW
  sub ecx, sizeof(CHRW)
@@:
  add ecx, sizeof(CHRW)
  mov ax, [ecx]
  or ax, ax
  je @F                                                 ;End of string
  cmp ax, 'a'
  jb @B
  cmp ax, 'z'
  ja @B
  sub ax, 20H
  mov [ecx], ax
  jmp @B
@@:
  mov eax, [esp + 4]                                    ;Return string address
  ret 4
StrUpperW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
