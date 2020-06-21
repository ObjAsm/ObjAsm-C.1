; ==================================================================================================
; Title:      DbgOutComponent.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutComponent 
; Purpose:    Identifies a COM-Component.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground color.
;             Arg2: Destination Window name.

align ALIGN_CODE
DbgOutComponent proc pIID:ptr GUID, dColor:DWORD, pDestWnd:POINTER
  invoke DbgOutTextA, $OfsCStrA("Component: "), dColor, DBG_EFFECT_NORMAL, pDestWnd
  invoke DbgOutComponentName, pIID, dColor, pDestWnd
  ret
DbgOutComponent endp

end
