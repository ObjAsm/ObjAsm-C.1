; ==================================================================================================
; Title:      StrFillChrW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>
ProcName equ <StrFillChrW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrFillChrW
; Purpose:    Fill a preallocated String with a character.
; Arguments:  Arg1: -> String.
;             Arg2: Character.
;             Arg3: Character Count.
; Return:     Nothing.

% include &ObjMemPath&Common\StrFillChrTXP.inc

end
