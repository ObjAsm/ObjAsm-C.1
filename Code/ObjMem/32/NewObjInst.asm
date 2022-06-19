; ==================================================================================================
; Title:      NewObjInst.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName equ <NewObjInst>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  NewObjInst 
; Purpose:    Creates an object instance from an object ID.
; Arguments:  Arg1: Object ID.
; Return:     eax -> New object instance or NULL if failed.

% include &ObjMemPath&X\NewObjInst.asm

end
