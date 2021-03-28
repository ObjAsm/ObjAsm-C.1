; ==================================================================================================
; Title:      CAStr_CRLF.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.const

align ALIGN_DATA
bCRLF  BYTE  13, 10, 0

end
