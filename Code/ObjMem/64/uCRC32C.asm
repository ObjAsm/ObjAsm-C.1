; ==================================================================================================
; Title:      uCRC32C.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, March 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uCRC32C
; Purpose:    Computes the CRC-32C (Castagnoli), using the polynomial 11EDC6F41h from an unaligned
;             memory block.
; Arguments:  Arg1: -> Unaligned memory block.
;             Arg2: Memory block size in BYTEs.
; Return:     eax = CRC32C.

% include &ObjMemPath&Common\uCRC32CXP.inc

end
