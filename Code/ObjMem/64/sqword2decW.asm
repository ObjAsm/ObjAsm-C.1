; ==================================================================================================
; Title:      sqword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  sqword2decW
; Purpose:    Converts a signed QWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: sqword value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 42 bytes large to allocate the output string
;             (Sign + 19 WIDE characters + ZTC = 42 bytes).

align ALIGN_CODE
sqword2decW proc pBuffer:POINTER, sqValue:SQWORD
  invoke wsprintfW, rcx, $OfsCStrW("%I64i"), sqValue  
  ret
sqword2decW endp

end
