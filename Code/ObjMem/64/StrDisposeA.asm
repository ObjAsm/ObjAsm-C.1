; ==================================================================================================
; Title:      StrDisposeA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrDisposeA
; Purpose:    Free the memory allocated for the string using StrNewA, StrCNewA, StrLENewA or
;             StrAllocA.
;             If the pointer to the string is NULL, StrDisposeA does nothing.
; Arguments:  Arg1: -> ANSI string.
; Return:     Nothing.

align ALIGN_CODE
StrDisposeA proc pStringA:POINTER
  .if rcx != NULL
    invoke GlobalFree, rcx
  .endif
  ret
StrDisposeA endp

end
