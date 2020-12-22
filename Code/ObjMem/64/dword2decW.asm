; ==================================================================================================
; Title:      dword2decW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dword2decW
; Purpose:    Converts a DWORD to its decimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 22 bytes large to allocate the output string
;             (10 WIDE characters + ZTC = 22 bytes).

align ALIGN_CODE
dword2decW proc pBuffer:POINTER, dValue:DWORD
  invoke wsprintfW, rcx, $OfsCStrW("%I32u"), rdx
  ret
dword2decW endp


end
