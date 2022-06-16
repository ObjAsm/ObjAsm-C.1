; ==================================================================================================
; Title:      StrAllocW_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName equ <StrAllocW_UEFI>

% include &ObjMemPath&X\StrAllocT_UEFI.asm

end
