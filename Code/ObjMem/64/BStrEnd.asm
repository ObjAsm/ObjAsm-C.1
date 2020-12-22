; ==================================================================================================
; Title:      BStrEnd.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrEnd
; Purpose:    Get the address of the ZTC.
; Arguments:  Arg1: -> Source BStr.
; Return:     rax -> ZTC.

align ALIGN_CODE
BStrEnd proc pBStr:POINTER
  mov eax, DWORD ptr [rcx - 4]                          ;Length of BStr
  add rax, rcx
  ret
BStrEnd endp

end
