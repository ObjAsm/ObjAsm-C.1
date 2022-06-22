; ==================================================================================================
; Title:      StrAllocA_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName equ <StrAllocA_UEFI>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrAllocA_UEFI
; Purpose:    Allocate space for a string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     rax -> New allocated string or NULL if failed.

% include &ObjMemPath&Common\StrAllocTX_UEFI.inc

end
