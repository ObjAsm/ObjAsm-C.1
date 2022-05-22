; ==================================================================================================
; Title:      sdword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, May 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>

externdef TwoDecDigitTableW:WORD
ProcName textequ <sdword2decW>

% include &ObjMemPath&ObjMem.cop

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  sdword2decW
; Purpose:    Converts a signed DWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: SDWORD value.
; Return:     eax = Number of bytes copied to the destination buffer, including the ZTC.
; Note:       The destination buffer must be at least 24 bytes large to allocate the output string
;             (Sign + 10 WIDE characters + ZTC = 24 bytes).

% include &ObjMemPath&64\sdword2decT.inc

end
