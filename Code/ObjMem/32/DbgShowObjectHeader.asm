; ==================================================================================================
; Title:      DbgShowObjectHeader.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgClose
; Purpose:    Outputs heading object information.
; Arguments:  Arg1: -> Object Name.
;             Arg2: -> Instance.
;             Arg3: -> Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgShowObjectHeader proc pObjectName:POINTER, pInstance:POINTER, pDest:POINTER
  local cNum[20]:CHRA

  invoke DbgOutTextA, $OfsCStrA("Object "), \
                      $RGB(64,64,255), DBG_EFFECT_BOLD or DBG_EFFECT_UNDERLINE, pDest
  invoke dword2hexA, addr cNum, pInstance
  invoke DbgOutTextA, addr cNum, $RGB(64,64,255), DBG_EFFECT_BOLD or DBG_EFFECT_UNDERLINE, pDest
  invoke DbgOutTextA, $OfsCStrA("h::"), \
                      $RGB(64,64,255), DBG_EFFECT_BOLD or DBG_EFFECT_UNDERLINE, pDest
  invoke DbgOutTextA, pObjectName, $RGB(64,64,255), DBG_EFFECT_BOLD or DBG_EFFECT_UNDERLINE, pDest
  ret
DbgShowObjectHeader endp

end
