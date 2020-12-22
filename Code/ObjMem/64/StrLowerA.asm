; ==================================================================================================
; Title:      StrLowerA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLowerA
; Purpose:    Convert all ANSI string characters into lowercase.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     rax -> String.

align ALIGN_CODE
StrLowerA proc pStrA:POINTER
  push rcx
  dec rcx
@@:
  inc rcx
  mov al, [rcx]
  or al, al
  je @F                                                 ;End of string
  cmp al, 'A'
  jb @F
  cmp al, 'Z'
  ja @F
  add al, 20H
  mov [rcx], al
  jmp @B
@@:
  pop rax
  ret
StrLowerA endp

end
