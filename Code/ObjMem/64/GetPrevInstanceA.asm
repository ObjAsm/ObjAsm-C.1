; ==================================================================================================
; Title:      GetPrevInstanceA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetPrevInstanceA
; Purpose:    Return a HANDLE to a previously running instance of an application.
; Arguments:  Arg1: -> ANSI application name.
;             Arg2: -> ANSI class name.
; Return:     eax = Window HANDLE of the application instance or zero if failed.

align ALIGN_CODE
GetPrevInstanceA proc uses rdi pStrIDA:POINTER, pClassNameA:POINTER
  invoke CreateSemaphore, 0, 0, 1, pStrIDA
  mov rdi, rax                                          ;edi = Semaphore HANDLE
  invoke GetLastError
  cmp eax, ERROR_ALREADY_EXISTS
  je @@1
  cmp eax, ERROR_SUCCESS
  jne @@2                                               ;Find other instance
  xor eax, eax
  jmp @@Exit
@@1:
  invoke CloseHandle, rdi                               ;Close the Semaphore HANDLE
@@2:
  invoke FindWindow, pClassNameA, NULL                  ;Try to find another instance
  test rax, rax                                         ;already running
  jz @@Exit                                             ;return 0 to exit
  invoke GetLastActivePopup, rax                        ;eax = hWnd
@@Exit:
  ret
GetPrevInstanceA endp

end
