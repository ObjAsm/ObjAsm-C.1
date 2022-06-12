; ==================================================================================================
; Title:      IsWinNT.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsWinNT
; Purpose:    Detects if the OS is Windows NT based.
; Arguments:  None.
; Return:     eax = TRUE if OS is Windows NT based, otherwise FALSE.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
IsWinNT proc
  sub esp, sizeof OSVERSIONINFO
  mov [esp].OSVERSIONINFO.dwOSVersionInfoSize, sizeof OSVERSIONINFO
  invoke GetVersionEx, esp                              ;TRUE/FALSE
  cmp [esp].OSVERSIONINFO.dwPlatformId, VER_PLATFORM_WIN32_NT
  sete al
  add esp, sizeof OSVERSIONINFO
  ret
IsWinNT endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
