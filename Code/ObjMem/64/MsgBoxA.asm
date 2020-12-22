; ==================================================================================================
; Title:      MsgBoxA.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, May 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\Objects\\Lib\\64A\\Objects.cop

TARGET_STR_TYPE = STR_TYPE_ANSI
TARGET_STR_AFFIX textequ <A>
ProcName equ <MsgBoxA>

% include &ObjMemPath&X\MsgBoxT.asm

end
