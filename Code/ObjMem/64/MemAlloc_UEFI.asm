; ==================================================================================================
; Title:      MemAlloc_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemAlloc_UEFI
; Purpose:    Allocate a memory block.
; Arguments:  Arg1: Memory block attributes [0, MEM_INIT_ZERO].
;             Arg2: Memory block size in BYTEs.
; Return:     rax -> Memory block or NULL if failed.

% include &ObjMemPath&Common\MemAllocX_UEFI.inc

end
