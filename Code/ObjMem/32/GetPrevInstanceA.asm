; ==================================================================================================
; Title:      GetPrevInstanceA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetPrevInstanceA
; Purpose:    Return a HANDLE to a previously running instance of an application.
; Arguments:  Arg1: -> ANSI application name.
;             Arg2: -> ANSI class name.
; Return:     eax = Window HANDLE of the application instance or zero if failed.

align ALIGN_CODE
GetPrevInstanceA proc uses edi pStrIDA:POINTER, pClassNameA:POINTER
  invoke CreateSemaphoreA, 0, 0, 1, pStrIDA
  mov edi, eax                                          ;edi = Semaphore handle
  invoke GetLastError
  cmp eax, ERROR_ALREADY_EXISTS
  je @@1
  cmp eax, ERROR_SUCCESS
  jne @@2                                               ;Find other instance
  xor eax, eax
  jmp @@Exit
@@1:
  invoke CloseHandle, edi                               ;Close the Semaphore handle
@@2:
  invoke FindWindowA, pClassNameA, NULL                 ;Try to find another instance
  test eax, eax                                         ;already running
  jz @@Exit                                             ;return 0 to exit
  invoke GetLastActivePopup, eax                        ;eax = hWnd
@@Exit:
  ret
GetPrevInstanceA endp

end
