; ==================================================================================================
; Title:      sdword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

TARGET_STR_TYPE = STR_TYPE_ANSI
TARGET_STR_AFFIX textequ <A>

externdef TwoDecDigitTableA:BYTE
ProcName textequ <sdw2decA>

% include &ObjMemPath&ObjMem.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sdword2decA
; Purpose:    Converts a signed DWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: SDWORD value.
; Return:     eax = Number of bytes copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 12 bytes large to allocate the output string
;             (Sign + 10 ANSI characters + ZTC = 12 bytes).

% include &ObjMemPath&X\sdword2decT.asm

end
