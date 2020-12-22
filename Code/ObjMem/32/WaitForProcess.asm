; ==================================================================================================
; Title:      WaitForProcess.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based on Donkey's code (http://donkey.visualassembler.com/).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  WaitForProcess
; Purpose:    Synchronisation procedure that waits until a process has finished.
; Arguments:  Arg1: Process ID
;             Arg2: Timeout value in ms.
; Return:     eax = Wait result (WAIT_ABANDONED, WAIT_OBJECT_0 or WAIT_TIMEOUT).

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
WaitForProcess proc dProcessID:DWORD, dTimeOut:DWORD
  invoke OpenProcess, SYNCHRONIZE, FALSE, [esp + 4]     ;dProcessID
  or eax, eax
  jnz @F
  dec eax                                               ;-1 = failure
  ret 8
@@:
  push eax                                              ;Save process handle
  invoke WaitForSingleObject, eax, [esp + 12]           ;hProcess, dTimeOut
  pop ecx
  push eax
  invoke CloseHandle, ecx                               ;hProcess
  pop eax                                               ;eax = Wait result
  ret 8
WaitForProcess endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
