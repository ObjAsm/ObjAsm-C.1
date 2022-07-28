; ==================================================================================================
; Title:      DbgOutComponent.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutComponent 
; Purpose:    Identify a COM-Component.
; Arguments:  Arg1: -> CSLID.
;             Arg2: Foreground color.
;             Arg2: -> Destination Window WIDE name.

align ALIGN_CODE
DbgOutComponent proc pIID:ptr GUID, dColor:DWORD, pDestWnd:POINTER
  invoke DbgOutTextA, $OfsCStrA("Component: "), dColor, DBG_EFFECT_NORMAL, pDestWnd
  invoke DbgOutComponentName, pIID, dColor, pDestWnd
  ret
DbgOutComponent endp

end
