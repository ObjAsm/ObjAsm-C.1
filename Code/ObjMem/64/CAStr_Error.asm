; ==================================================================================================
; Title:      CAStr_Error.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.const

align ALIGN_DATA
bError  BYTE  "E", "r", "r", "o", "r", 0

end
