; ==================================================================================================
; Title:      UefiGetErrStr_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


% include &ObjMemPath&Common\\UefiErrTable_T.inc

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  UefiGetErrStrA / UefiGetErrStrW 
; Purpose:    Return description string from a COM error code.
; Arguments:  Arg1: COM error code.
; Return:     xax -> Error string.

align ALIGN_CODE
ProcName proc xErrCode:XWORD
  ?mov ecx, xErrCode
  mov eax, UefiErrTableCount
  mov xdx, offset UefiErrTable
  test eax, eax
  .while !ZERO?                                         ;This search can be smarter!
    .break .if xcx == [xdx].DOM.xCode
    add xdx, sizeof(DOM)
    dec eax
  .endw
  .if eax == 0
    mov xax, $OfsCStr("Unknown error")
  .else
    mov xax, [xdx].DOM.pString
  .endif
  ret
ProcName endp
