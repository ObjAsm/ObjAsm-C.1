; ==================================================================================================
; Title:      DbgConstants.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

CStrW szDbgInvalidDevPtr, "Invalid device pointer"
%CStrW szDbgRegKey,       DEBUG_CENTER_REGKEY

end
