; ==================================================================================================
; Title:      DbgOutInterfaceName.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutInterfaceName 
; Purpose:    Identifies a COM-Interface.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground color.
;             Arg2: Destination window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutInterfaceName proc uses rbx pIID:ptr GUID, dColor:DWORD, pDestWnd:POINTER
  local hKey:HANDLE, SubKey[260]:CHRA, dSubKeyLenght:DWORD

  lea rbx, SubKey
	FillStringA [rbx], <Interface\{>
	invoke GUID2StrA, addr SubKey[11], pIID
  invoke DbgOutTextA, addr SubKey[11] , dColor, DBG_EFFECT_NORMAL, pDestWnd
  mov CHRA ptr [rbx + 47], "}"
  m2z hKey
  invoke RegOpenKeyA, HKEY_CLASSES_ROOT, rbx, addr hKey
  .if rax == ERROR_SUCCESS
    mov DCHRA ptr [rbx], "( "
    mov dSubKeyLenght, sizeof(SubKey) - 2*sizeof(CHRA)
    invoke RegQueryValueA, hKey, NULL, addr SubKey[2], addr dSubKeyLenght
    mov eax, dSubKeyLenght
    mov CHRA ptr [rax + rbx + 1], ")"
    invoke DbgOutTextA, rbx, dColor, DBG_EFFECT_NORMAL, pDestWnd
    invoke RegCloseKey, hKey
  .endif
  ret
DbgOutInterfaceName endp

end
