; ==================================================================================================
; Title:      MsgBoxW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, May 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\Objects\\Lib\\32W\\Objects.cop

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>
ProcName equ <MsgBoxW>

% include &ObjMemPath&Common\MsgBoxTX.inc

end
