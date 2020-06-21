; ==================================================================================================
; Title:      StrDisposeA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop
% include &IncPath&Windows\Windows.inc

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrDisposeA
; Purpose:    Free the memory allocated for the string using StrNewA, StrCNewA, StrLENewA or
;             StrAllocA.
;             If the pointer to the string is NULL, StrDisposeA does nothing.
; Arguments:  Arg1: -> ANSI string.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrDisposeA proc pStringA:POINTER
  .if POINTER ptr [esp + 4] != NULL
    invoke GlobalFree, [esp + 4]
  .endif
  ret 4
StrDisposeA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
