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

% include &ObjMemPath&X\StrAllocT_UEFI.asm

end
