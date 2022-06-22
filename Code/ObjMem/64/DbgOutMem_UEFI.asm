; ==================================================================================================
; Title:      DbgOutMem_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName equ <DbgOutMem_UEFI>
BYTES_PER_LINE equ 8      ;Must be a multiple of 8

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutMem_UEFI
; Purpose:    Output the content of a memory block.
; Arguments:  Arg1: -> Memory block.
;             Arg2: Memory block size.
;             Arg3: Representation format.
;             Arg4: Memory output color.
;             Arg5: Representation output color.
;             Arg6: -> Destination Window name.
; Return:     Nothing.

% include &ObjMemPath&Common\DbgOutMemXP.inc

end
