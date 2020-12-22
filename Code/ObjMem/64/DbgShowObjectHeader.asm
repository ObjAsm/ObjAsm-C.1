; ==================================================================================================
; Title:      DbgShowObjectHeader.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
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

  invoke DbgOutTextA, $OfsCStrA("Object "), $RGB(64,64,255), DBG_EFFECT_BOLD, pDest
  invoke qword2hexA, addr cNum, pInstance
  invoke DbgOutTextA, addr cNum, $RGB(64,64,255), DBG_EFFECT_BOLD, pDest
  invoke DbgOutTextA, $OfsCStrA("h::"), $RGB(64,64,255), DBG_EFFECT_BOLD, pDest
  invoke DbgOutTextA, pObjectName, $RGB(64,64,255), DBG_EFFECT_BOLD, pDest
  ret
DbgShowObjectHeader endp

end
