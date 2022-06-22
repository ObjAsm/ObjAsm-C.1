; ==================================================================================================
; Title:      DbgOutApiErrX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness independent code.
; ==================================================================================================


% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutApiErr
; Purpose:    Identifies a API error with a string.
; Arguments:  Arg1: Api error code obtained with GetLastError.
;             Arg2: -> Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutApiErr proc dErrorCode:DWORD, pDest:POINTER
  local pBuffer:POINTER, cHexBuffer[16]:CHRA

  invoke FormatMessageA, FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM, \
                         0, dErrorCode, 0, addr pBuffer, 0, 0
  .if eax != 0
    add xax, pBuffer
    m2z CHRA ptr [xax - 2*sizeof(CHRA)]                 ;Remove the CRLF ending characters.
    invoke DbgOutTextA, pBuffer, $RGB(255,0,0), DBG_EFFECT_NORMAL, pDest
    invoke LocalFree, pBuffer
    mov DCHRA ptr [cHexBuffer], 5B20h  ;< [>
    invoke dword2hexA, addr [cHexBuffer + 2*sizeof(CHRA)], dErrorCode
    FillStringA [cHexBuffer + 10*sizeof(CHRA)], <h]>
    invoke DbgOutTextA, addr cHexBuffer, $RGB(255,0,0), DBG_EFFECT_NORMAL, pDest
  .else
    invoke DbgOutTextA, $OfsCStrA("DbgOutApiErr failed"), $RGB(255,0,0), DBG_EFFECT_NORMAL, pDest
  .endif
  ret
DbgOutApiErr endp
