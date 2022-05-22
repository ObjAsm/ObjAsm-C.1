; ==================================================================================================
; Title:      udword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>

externdef TwoDecDigitTableW:WORD
ProcName textequ <udword2decW>

% include &ObjMemPath&ObjMem.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  udword2decW
; Purpose:    Converts an unsigned DWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: DWORD value.
; Return:     eax = Number of bytes copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 22 bytes large to allocate the output string
;             (10 WIDE characters + ZTC = 22 bytes).

% include &ObjMemPath&64\udword2decT.inc

end
