; ==================================================================================================
; Title:      uqw2decA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

TARGET_STR_TYPE = STR_TYPE_ANSI
TARGET_STR_AFFIX textequ <A>

externdef TwoDecDigitTableA:BYTE
ProcName textequ <uqword2decA>

% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqword2decA
; Purpose:    Converts an unsigned QWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: QWORD value.
; Return:     eax = Number of bytes copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 21 bytes large to allocate the output string
;             (20 ANSI characters + ZTC = 21 bytes).

% include &ObjMemPath&32\uqword2decT.inc

end
