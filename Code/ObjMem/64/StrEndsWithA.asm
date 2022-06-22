; ==================================================================================================
; Title:      StrEndsWithA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

TARGET_STR_TYPE = STR_TYPE_ANSI
TARGET_STR_AFFIX textequ <A>
ProcName equ <StrEndsWithA>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrEndsWithA
; Purpose:    Compares the ending of a string.
; Arguments:  Arg1: -> Analized string.
;             Arg2: -> Suffix string.
; Return:     eax = TRUE of the ending matches, otherwise FALSE.

% include &ObjMemPath&Common\StrEndsWithTXP.inc

end
