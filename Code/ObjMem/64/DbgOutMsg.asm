; ==================================================================================================
; Title:      DbgOutMsg.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  DbgOutMsg
; Purpose:    Identify a windows message with a string.
; Arguments:  Arg1: Windows message ID.
;             Arg2: Foreground color.
;             Arg3: -> Destination window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\DbgOutMsg_X.inc

end
