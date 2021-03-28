; ==================================================================================================
; Title:      BStrDispose.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrDispose
; Purpose:    Free the memory allocated for the string using BStrNew, BStrCNew, BStrLENew or
;             BStrAlloc.
;             If the pointer to the string is NULL, BStrDispose does nothing.
; Arguments:  Arg1: -> BStr.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
BStrDispose proc pBStr:POINTER
  mov ecx, [esp + 4]                                    ;ecx -> BStr
  .if ecx != NULL                   
    sub ecx, 4
    invoke GlobalFree, ecx
  .endif
  ret 4
BStrDispose endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
