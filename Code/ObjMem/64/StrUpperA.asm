; ==================================================================================================
; Title:      StrUpperA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrUpperA
; Purpose:    Convert all ANSI string characters into uppercase.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     rax -> String.

OPTION PROC:NONE
align ALIGN_CODE
StrUpperA proc pStringA:POINTER
  push rcx                                              ;rcx -> StringA
  dec rcx
@@:
  inc rcx
  mov al, [rcx]
  or al, al
  je @F                                                 ;End of string
  cmp al, 'a'
  jb @B
  cmp al, 'z'
  ja @B
  sub al, 20H
  mov [rcx], al
  jmp @B
@@:
  pop rax                                               ;Return string address
  ret
StrUpperA endp
OPTION PROC:DEFAULT

end
