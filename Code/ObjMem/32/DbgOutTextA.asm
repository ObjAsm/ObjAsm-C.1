; ==================================================================================================
; Title:      DbgOutTextA.asm
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
; Purpose:    Sends an ANSI string to the debug output device
; Arguments:  Arg1: -> Null terminated ANSI string.
;             Arg2: Color value.
;             Arg3: Effect value (DBG_EFFECT_XXX)
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutTextA proc pStr:POINTER, dColor:DWORD, dEffects:DWORD, pDest:POINTER
  local dBytesWritten:DWORD, wAttrib:WORD, dResult:DWORD
  local CDS:COPYDATASTRUCT

  .if pStr == NULL
    mov pStr, $OfsCStrA("NULL Pointer")
    mov dColor, $RGB(255, 0, 0)
  .endif

  mov eax, dDbgDev
  .if eax == DBG_DEV_LOG
    invoke DbgLogOpen
    .if $invoke(DbgLogOpen)
      invoke StrLengthA, pStr
      lea ecx, dBytesWritten
      invoke WriteFile, hDbgDev, pStr, eax, ecx, NULL
    .endif
    .ifBitSet dEffects, DBG_EFFECT_NEWLINE
      invoke WriteFile, hDbgDev, offset bCRLF, 2, addr dBytesWritten, NULL
    .endif

  .elseif eax == DBG_DEV_CON
    .if $invoke(DbgConOpen)
      mov eax, dColor
      mov wAttrib, FOREGROUND_INTENSITY
      test eax, 000000F0h
      .if !ZERO?
        or wAttrib, FOREGROUND_RED
      .endif
      test eax, 0000F000h
      .if !ZERO?
        or wAttrib, FOREGROUND_GREEN
      .endif
      test eax, 00F00000h
      .if !ZERO?
        or wAttrib, FOREGROUND_BLUE
      .endif
      invoke SetConsoleTextAttribute, hDbgDev, wAttrib
      invoke StrLengthA, pStr
      lea ecx, dBytesWritten
      invoke WriteConsoleA, hDbgDev, pStr, eax, ecx, NULL
      .ifBitSet dEffects, DBG_EFFECT_NEWLINE
        invoke WriteConsoleA, hDbgDev, offset bCRLF, 2, addr dBytesWritten, NULL
      .endif
    .endif

  .else                                                       ;DBG_DEV_WND
    .if $invoke(DbgWndOpen)
      mov CDS.dwData, DGB_MSG_ID                              ;Set DebugCenter identifier
      invoke StrSizeA, pStr                                   ;String size
      push eax
      add eax, sizeof DBG_STR_INFO                            ;This includes the string ZTC
      push eax
      mov CDS.cbData, eax
      invoke StrSizeW, pDest
      push eax                                                ;String size
      add eax, sizeof DBG_HEADER_INFO
      push eax
      add CDS.cbData, eax
      invoke GlobalAlloc, GPTR, CDS.cbData
      .if eax != NULL                                         ;Continue only if GlobalAlloc succeeded
        mov CDS.lpData, eax
        mov [eax].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR       ;Set block type = header
        pop [eax].DBG_HEADER_INFO.dBlockLen
        lea ecx, [eax + sizeof DBG_HEADER_INFO]
        push pDest
        push ecx
        call MemClone
        mov eax, CDS.lpData
        add eax, [eax].DBG_HEADER_INFO.dBlockLen
        mov [eax].DBG_STR_INFO.bBlockID, DBG_MSG_STR          ;Set block type = string
        pop [eax].DBG_STR_INFO.dBlockLen
        mov edx, dEffects
        BitClr edx, DBG_CHARTYPE_WIDE                         ;Reset this bit
        mov [eax].DBG_STR_INFO.dEffects, edx
        m2m [eax].DBG_STR_INFO.dColor, dColor, ecx
        push pStr
        lea ecx, [eax + sizeof DBG_STR_INFO]
        push ecx
        call MemClone
        invoke SendMessageTimeoutW, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                    SMTO_BLOCK, SMTO_TIMEOUT, addr dResult
        invoke GlobalFree, CDS.lpData
      .else
        add esp, 16                                           ;Restore stack
        invoke MessageBoxW, 0, offset szDbgComErr, offset szDbgErr, MB_OK or MB_ICONERROR
      .endif
    .endif
  .endif
  ret
DbgOutTextA endp

end
