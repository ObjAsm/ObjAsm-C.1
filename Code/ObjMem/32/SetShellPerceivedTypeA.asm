; ==================================================================================================
; Title:      SetShellPerceivedTypeA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

TARGET_STR_TYPE = STR_TYPE_ANSI
TARGET_STR_AFFIX textequ <A>
ProcName equ <SetShellPerceivedTypeA>

% include &ObjMemPath&X\SetShellPerceivedType.asm

end
