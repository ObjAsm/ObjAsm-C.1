; ==================================================================================================
; Title:      qword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2decA
; Purpose:    Converts a QWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: QWORD value.
; Return:     Nothing.
; Note:       The destination String buffer must be at least 21 bytes large to allocate the output
;             (20 ANSI characters + ZTC = 21 bytes).

align ALIGN_CODE
qword2decA proc pBuffer:POINTER, qValue:QWORD
  invoke wsprintfA, rcx, $OfsCStrA("%I64u"), rdx
  ret
qword2decA endp

end
