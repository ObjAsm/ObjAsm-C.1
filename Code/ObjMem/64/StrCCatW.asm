; ==================================================================================================
; Title:      StrCCatW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCCatW
; Purpose:    Concatenate 2 WIDE strings with length limitation.
;             The destination string buffer should have at least enough room for the maximum number
;             of characters + 1.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Maximal number of charachters that the destination string can hold including the
;                   ZTC.
; Return:     Nothing.

align ALIGN_CODE
StrCCatW proc pDstStringW:POINTER, pSrcStringW:POINTER, dMaxChars:DWORD
  invoke StrEndW, rcx
  mov r8d, dMaxChars
  shl r8, 1
  add r8, pDstStringW
  sub r8, rax
  jbe @F                                                ;Destination is too small!
  shr r8, 1
  invoke StrCCopyW, rax, pSrcStringW, r8d
@@:
  ret
StrCCatW endp

end
