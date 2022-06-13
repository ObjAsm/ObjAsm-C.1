; ==================================================================================================
; Title:      DbgOutTextW_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

TARGET_STR_TYPE = STR_TYPE_WIDE
ProcName textequ <DbgOutTextW_UEFI>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutTextW_UEFI
; Purpose:    Sends a WIDE string to the debug output device.
; Arguments:  Arg1: -> Zero terminated WIDE string.
;             Arg2: Color value.
;             Arg3: Effect value (DBG_EFFECT_XXX)
;             Arg4: -> Destination window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&X\DbgOutTextT_UEFI.asm

end
