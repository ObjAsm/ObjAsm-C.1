; ==================================================================================================
; Title:      GetPrevInstanceW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetPrevInstanceW
; Purpose:    Return a handle to a previously running instance of an application.
; Arguments:  Arg1: -> WIDE application name.
;             Arg2: -> WIDE class name.
; Return:     rax = Window HANDLE of the application instance or zero if failed.

align ALIGN_CODE
GetPrevInstanceW proc uses rdi pStrIDW:POINTER, pClassNameW:POINTER
  invoke CreateSemaphoreW, 0, 0, 1, pStrIDW
  mov rdi, rax                                          ;edi = Semaphore handle
  invoke GetLastError
  cmp eax, ERROR_ALREADY_EXISTS
  je @@1
  cmp eax, ERROR_SUCCESS
  jne @@2                                               ;Find other instance
  xor eax, eax
  jmp @@Exit
@@1:
  invoke CloseHandle, rdi                               ;Close the Semaphore handle
@@2:
  invoke FindWindowW, pClassNameW, NULL                 ;Try to find another instance
  test rax, rax                                         ;already running
  jz @@Exit                                             ;return 0 to exit
  invoke GetLastActivePopup, rax                        ;eax = hWnd
@@Exit:
  ret
GetPrevInstanceW endp

end
