; ==================================================================================================
; Title:      NewObjInst.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  NewObjInst
; Purpose:    Creates an object instance from an object ID.
; Arguments:  Arg1: Object ID.
; Return:     rax -> new object instance or NULL if failed.

align ALIGN_CODE
NewObjInst proc uses rbx rdi rsi dObjectID:DWORD
  invoke GetObjectTemplate, ecx                         ;rax -> Template, ecx = Template size
  .if rax != NULL
    mov rsi, rax
    mov ebx, ecx
    MemAlloc ebx
    .if rax != NULL
      mov rdi, rax
      invoke MemClone, rax, rsi, ebx
      mov rax, rdi                                      ;rax -> new instance
    .endif
  .endif
  ret
NewObjInst endp

end
