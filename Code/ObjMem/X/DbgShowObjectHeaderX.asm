; ==================================================================================================
; Title:      DbgShowObjectHeaderX.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgShowObjectHeader / DbgShowObjectHeader_UEFI
; Purpose:    Outputs heading object information.
; Arguments:  Arg1: -> Object Name.
;             Arg2: -> Instance.
;             Arg3: Text RGB color.
;             Arg3: -> Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
ProcName proc pObjectName:POINTER, pInstance:POINTER, dColor:DWORD, pDest:POINTER
  local bNum[20]:CHRA

  invoke DbgOutTextA, $OfsCStrA("Object "), dColor, DBG_EFFECT_BOLD, pDest
  invoke xword2hexA, addr bNum, pInstance
  invoke DbgOutTextA, addr bNum, dColor, DBG_EFFECT_BOLD, pDest
  invoke DbgOutTextA, $OfsCStrA("h::"), dColor, DBG_EFFECT_BOLD, pDest
  invoke DbgOutTextA, pObjectName, dColor, DBG_EFFECT_BOLD, pDest
  ret
ProcName endp

end
