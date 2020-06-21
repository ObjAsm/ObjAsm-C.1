; ==================================================================================================
; Title:      dword2decA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dword2decA
; Purpose:    Converts a DWORD to its decimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 11 bytes large to allocate the output string
;             (10 ANSI characters + ZTC = 11 bytes).

align ALIGN_CODE
dword2decA proc pBuffer:POINTER, dValue:DWORD
  invoke wsprintfA, rcx, $OfsCStrA("%I32u"), rdx
  ret
dword2decA endp

end
