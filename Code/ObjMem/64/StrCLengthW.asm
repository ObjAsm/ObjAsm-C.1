; ==================================================================================================
; Title:      StrCLengthW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCLengthW
; Purpose:    Get the character count of the source WIDE string with length limitation.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg3: Maximal character count.
; Return:     eax = limited character count.

align ALIGN_CODE
StrCLengthW proc uses rdi pStringW:POINTER, dMaxChars:DWORD
  ;rcx = pStringW, edx = dMaxChars
  inc edx
  mov rdi, rcx                                          ;rdi -> StringW
  mov ecx, edx                                          ;ecx = dMaxChars + 1
  xor eax, eax
  repne scasw
  not rcx
  lea eax, [ecx + edx]
  ret
StrCLengthW endp

end
