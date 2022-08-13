; ==================================================================================================
; Title:      DbgShowObjectHeader_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <DbgShowObjectHeader_UEFI>

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgShowObjectHeader_UEFI
; Purpose:    Output heading object information.
; Arguments:  Arg1: -> Object Name.
;             Arg2: -> Instance.
;             Arg3: Text RGB color.
;             Arg3: -> Destination Window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\\DbgShowObjectHeader_XP.inc

end
