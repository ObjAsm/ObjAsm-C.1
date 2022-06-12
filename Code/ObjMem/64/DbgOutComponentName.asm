; ==================================================================================================
; Title:      DbgOutComponentName.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutComponentName 
; Purpose:    Identifies a COM-Component.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground color.
;             Arg2: Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutComponentName proc uses rbx pIID:ptr GUID, dColor:DWORD, pDestWnd:POINTER
  local hKey:HANDLE, SubKey[260]:CHRA, dSubKeyLength:DWORD

  lea rbx, SubKey
	FillStringA [rbx], <CLSID\{>
  invoke GUID2StrA, addr SubKey[7], pIID
  invoke DbgOutTextA, addr SubKey[7] , dColor, DBG_EFFECT_NORMAL, pDestWnd
  FillStringA [rbx + 43], <}>
  invoke RegOpenKeyA, HKEY_CLASSES_ROOT, rbx, addr hKey
  .if rax == ERROR_SUCCESS
    mov dSubKeyLength, sizeof(SubKey)
    invoke RegQueryValueA, hKey, NULL, rbx, addr dSubKeyLength
    invoke DbgOutTextA, rbx, dColor, DBG_EFFECT_NORMAL, pDestWnd
    invoke RegCloseKey, hKey
  .endif
  ret
DbgOutComponentName endp

end
