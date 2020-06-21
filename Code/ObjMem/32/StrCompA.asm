; ==================================================================================================
; Title:      StrCompA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCompA
; Purpose:    Compare 2 ANSI strings with case sensitivity.
; Arguments:  Arg1: -> ANSI string 1.
;             Arg2: -> ANSI string 2.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrCompA proc pString1A:POINTER, pString2A:POINTER
  mov ecx, [esp + 4]
  mov edx, [esp + 8]
  push edi
  xor edi, edi
  xor eax, eax
align ALIGN_CODE
@@Char:
  mov al, [edi + ecx]
  test al, al
  jz @@Eq?
  cmp al, [edi + edx]
  jnz @@Eq?
  inc edi
  jmp @@Char
align ALIGN_CODE
@@Eq?:
  movzx ecx, BYTE ptr [edi + edx]
  sub eax, ecx
  pop edi
  ret 8
StrCompA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
