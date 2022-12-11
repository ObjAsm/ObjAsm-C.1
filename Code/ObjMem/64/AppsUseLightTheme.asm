; ==================================================================================================
; Title:      AppsUseLightTheme.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, December 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

% include &IncPath&Windows\winreg.inc

.code
; ��������������������������������������������������������������������������������������������������
; Procedure:  AppsUseLightTheme
; Purpose:    Determine of Light Mode for Apps is enabled.
; Arguments:  None
; Return:     eax = TRUE or FALSE.

% include &ObjMemPath&Common\AppsUseLightTheme_TX.inc

end