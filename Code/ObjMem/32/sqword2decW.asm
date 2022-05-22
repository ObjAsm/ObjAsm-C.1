; ==================================================================================================
; Title:      sqword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>

externdef TwoDecDigitTableW:WORD
ProcName textequ <sqword2decW>

% include &ObjMemPath&ObjMem.cop

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  sqword2decW
; Purpose:    Converts a signed SQWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: SQWORD value.
; Return:     eax = Number of bytes copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 42 bytes large to allocate the output string
;             (Sign + 19 WIDE characters + ZTC = 42 bytes).

% include &ObjMemPath&32\sqword2decT.inc

end
