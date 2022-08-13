; ==================================================================================================
; Title:      StrUpperA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrUpperA
; Purpose:    Convert all ANSI string characters into uppercase.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     eax -> String.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrUpperA proc pStringA:POINTER
  mov ecx, [esp + 4]                                    ;ecx -> StringA
  dec ecx
@@:
  inc ecx
  mov al, [ecx]
  or al, al
  je @F                                                 ;End of string
  cmp al, 'a'
  jb @B
  cmp al, 'z'
  ja @B
  sub al, 20H
  mov [ecx], al
  jmp @B
@@:
  mov eax, [esp + 4]                                    ;Return string address
  ret 4
StrUpperA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
