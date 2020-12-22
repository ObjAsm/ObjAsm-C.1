; ==================================================================================================
; Title:      DbgShowTraceMethod.asm
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
; Purpose:    Outputs trace information about a method.
; Arguments:  Arg1: -> Method Name.
;             Arg2: Method count.
;             Arg3: Method ticks.
;             Arg4: -> Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgShowTraceMethod proc uses ebx pMName:POINTER, dCount:DWORD, pTicks:POINTER, pDest:POINTER
  local cBuffer[100]:CHRW

  lea ebx, cBuffer
  invoke DbgOutTextA, $OfsCStrA("  "), $RGB(64,64,255), DBG_EFFECT_NORMAL, pDest
  invoke DbgOutTextA, pMName, $RGB(64,64,255), DBG_EFFECT_NORMAL, pDest
  invoke DbgOutTextA, $OfsCStrA(": Calls = "), $RGB(64,64,255), DBG_EFFECT_NORMAL, pDest
  invoke wsprintfA, ebx, $OfsCStrA("%li"), dCount
  invoke DbgOutTextA, ebx, $RGB(0,0,0), DBG_EFFECT_NORMAL, pDest
  .if dCount != 0
    invoke DbgOutTextA, $OfsCStrA(", Ticks = "), $RGB(64,64,255), DBG_EFFECT_NORMAL, pDest
    mov ecx, pTicks
    invoke qword2hexA, ebx, QWORD ptr [ecx]
    mov WORD ptr [ebx + 16], "h"
    invoke DbgOutTextA, ebx, $RGB(0,0,0), DBG_EFFECT_NORMAL, pDest
  .endif
  invoke DbgOutTextA, offset bCRLF, $RGB(0,0,0), DBG_EFFECT_NORMAL, pDest
  ret
DbgShowTraceMethod endp

end
