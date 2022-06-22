; ==================================================================================================
; Title:      GUID2StrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GUID2StrA
; Purpose:    Convert a GUID to an ANSI string.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;                   It must hold at least 36 characters plus a ZTC (= 37 bytes).
;             Arg2: -> GUID.
; Return:     Nothing.

% include &ObjMemPath&Common\GUID2StrAXP.inc

end
