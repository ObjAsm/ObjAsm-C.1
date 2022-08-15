; ==================================================================================================
; Title:      StrDispose.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

% include &IncPath&Windows\Windows.inc

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrDispose
; Purpose:    Free the memory allocated for the string using StrNew, StrCNew, StrLENew or
;             StrAlloc.
;             If the pointer to the string is NULL, StrDispose does nothing.
; Arguments:  Arg1: -> String.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrDispose proc pString:POINTER
  .if POINTER ptr [esp + 4] != NULL
    invoke GlobalFree, [esp + 4]
  .endif
  ret 4
StrDispose endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
