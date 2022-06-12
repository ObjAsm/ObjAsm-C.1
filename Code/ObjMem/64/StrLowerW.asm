; ==================================================================================================
; Title:      StrLowerW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLowerW
; Purpose:    Convert all WIDE string characters into lowercase.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     rax -> String.

OPTION PROC:NONE
align ALIGN_CODE
StrLowerW proc pStringW:POINTER
  push rcx                                              ;rcx -> StringW
  sub rcx, sizeof(CHRW)
@@:
  add rcx, sizeof(CHRW)
  mov ax, [rcx]
  or ax, ax
  jz @F                                                 ;End of string
  cmp ax, 'A'
  jb @B
  cmp ax, 'Z'
  ja @B
  add ax, 20H
  mov [rcx], ax
  jmp @B
@@:
  pop rax                                               ;Return string address
  ret
StrLowerW endp
OPTION PROC:DEFAULT

end
