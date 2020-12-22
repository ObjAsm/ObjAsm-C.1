; ==================================================================================================
; Title:      IsWinNT.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsWinNT
; Purpose:    Detects if the OS is Windows NT based.
; Arguments:  None.
; Return:     rax = TRUE if OS is Windows NT based, otherwise FALSE.

align ALIGN_CODE
IsWinNT proc
  local OSVI:OSVERSIONINFO
  
  mov OSVI.dwOSVersionInfoSize, sizeof(OSVERSIONINFO)
  invoke GetVersionEx, addr OSVI                        ;TRUE/FALSE
  xor eax, eax
  cmp OSVI.dwPlatformId, VER_PLATFORM_WIN32_NT
  sete al
  ret
IsWinNT endp

end
