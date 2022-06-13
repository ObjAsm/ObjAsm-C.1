; ==================================================================================================
; Title:      DbgOutTextT_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include &ObjMemPath&ObjMemUEFI.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutTextA_UEFI / DbgOutTextW_UEFI
; Purpose:    Sends a string to the debug output device.
; Arguments:  Arg1: -> Zero terminated string.
;             Arg2: Color value.
;             Arg3: Effect value (DBG_EFFECT_XXX)
;             Arg4: -> Destination window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
ProcName proc uses xbx pString:POINTER, dColor:DWORD, dEffects:DWORD, pDest:POINTER
  .if pString == NULL
    mov xax, $OfsCStr("NULL Pointer")
    mov pString, xax
    mov dColor, $RGB(255, 0, 0)
  .endif

  mov eax, dDbgDev
  .if eax == DBG_DEV_UEFI_CON
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      invoke StrLengthA, pString
      invoke StrAllocW, eax
      mov xbx, xax
      invoke StrA2StrW, xax, pString
      mov pString, xbx
    endif
    invoke RGB24To16ColorIndex, dColor
    mov xbx, pConsoleOut
    invoke [xbx].ConOut.SetAttribute, xbx, xax
    invoke [xbx].ConOut.OutputString, xbx, pString
    .ifBitSet dEffects, DBG_EFFECT_NEWLINE
      invoke [xbx].ConOut.OutputString, xbx, offset wCRLF
    .endif
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      invoke StrDispose, pString
    endif
  .endif
  ret
ProcName endp
