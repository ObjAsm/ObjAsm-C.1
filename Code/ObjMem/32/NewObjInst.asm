; ==================================================================================================
; Title:      NewObjInst.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  NewObjInst
; Purpose:    Creates an object instance from an Object type ID.
; Arguments:  Arg1: Object type ID.
; Return:     eax -> New object instance or NULL if failed.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
NewObjInst proc dObjectID:DWORD
  invoke GetObjectTemplate, [esp + 4]
  .if eax != NULL
    sub esp, 4                                          ;Place holder
    push ecx                                            ;ecx = Template size
    push eax                                            ;eax -> Template
    MemAlloc ecx
    .if eax != NULL
      mov [esp + 8], eax                                ;Save return value
      push eax
      call MemClone
      pop eax
    .else
      add esp, 12
    .endif
  .endif
  ret 4
NewObjInst endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
