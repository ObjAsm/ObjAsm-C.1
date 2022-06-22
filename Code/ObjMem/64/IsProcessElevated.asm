; ==================================================================================================
; Title:      IsProcessElevated.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, April 2022.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsProcessElevated
; Purpose:    Check if the current process has elevated privileges.
; Arguments:  Arg: Process HANDLE.
; Return:     eax = TRUE or FALSE.
; Example:    invoke GetCurrentProcess
;             invoke IsProcessElevated, xax

% include &ObjMemPath&Common\IsProcessElevatedX.inc

end
