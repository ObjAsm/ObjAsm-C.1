; ==================================================================================================
; Title:      DbgOutComponentName.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutComponentName 
; Purpose:    Identifies a COM-Component.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground color.
;             Arg2: Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutComponentName proc pIID:ptr GUID, dColor:DWORD, pDestWnd:POINTER
  local SubKey[260]:BYTE

  push esi
  mov esi, offset DbgOutTextA
  invoke lstrcpyA, addr SubKey, $OfsCStrA("CLSID\{")
  invoke GUID2StrA, addr SubKey[7],pIID
  push pDestWnd
  push DBG_EFFECT_NORMAL
  push dColor
  lea eax, SubKey[7]
  push eax
  call esi
  ;invoke DbgOutTextA, addr SubKey[7] , dColor, DBG_EFFECT_NORMAL, pDestWnd
  mov SubKey[43], '}'
  mov SubKey[44], 0
  push edi
  push 0
  invoke RegOpenKeyA, HKEY_CLASSES_ROOT, addr SubKey, esp
  pop edi
  .if eax == 0
    push pDestWnd
    push DBG_EFFECT_NORMAL
    push dColor
    push $OfsCStrA(" == ")
    call esi
    ;invoke DbgOutTextA, $OfsCStrA(" == ") , dColor, DBG_EFFECT_NORMAL, pDestWnd
    push 250
    invoke RegQueryValueA, edi, NULL, addr SubKey, esp
    pop ecx
    push pDestWnd
    push DBG_EFFECT_NORMAL
    push dColor
    lea eax, SubKey
    push eax
    call esi
    ;invoke DbgOutTextA, addr SubKey, dColor, DBG_EFFECT_NORMAL, pDestWnd
    invoke RegCloseKey, edi
  .endif
  pop edi
  ret
DbgOutComponentName endp

end
