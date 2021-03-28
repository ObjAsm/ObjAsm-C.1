; ==================================================================================================
; Title:      qword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2decW
; Purpose:    Converts a QWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: QWORD value.
; Return:     Nothing.
; Note:       The destination string buffer must be at least 42 bytes large to allocate the output
;             (20 WIDE characters + ZTC = 42 bytes).

align ALIGN_CODE
qword2decW proc pBuffer:POINTER, qValue:QWORD
  invoke wsprintfW, rcx, $OfsCStrW("%I64u"), rdx
  ret
qword2decW endp

end
