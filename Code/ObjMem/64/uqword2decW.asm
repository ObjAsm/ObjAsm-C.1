; ==================================================================================================
; Title:      uqword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>

externdef TwoDecDigitTableW:WORD
ProcName textequ <uqw2decW>

% include &ObjMemPath&ObjMem.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqword2decW
; Purpose:    Converts an unsigned QWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: QWORD value.
; Return:     eax = Number of bytes copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 42 bytes large to allocate the output string
;             (20 WIDE characters + ZTC = 42 bytes).

% include &ObjMemPath&X\uqword2decT.asm

end
