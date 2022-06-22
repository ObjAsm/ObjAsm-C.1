; ==================================================================================================
; Title:      MemFree_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemFree_UEFI
; Purpose:    Dispose a memory block.
; Arguments:  Arg1: -> Memory block.
; Return:     eax = EFI_SUCCESS or an UEFI error code.

% include &ObjMemPath&Common\MemFreeX_UEFI.inc

end
