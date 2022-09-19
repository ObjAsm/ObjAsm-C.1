; ==================================================================================================
; Title:      DbgOutTextCW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef DbgColorError:DWORD

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutTextCW
; Purpose:    Send a counted WIDE string to the debug output device
; Arguments:  Arg1: -> Null terminated WIDE string.
;             Arg2: Maximal character count.
;             Arg3: Foreground RGB color value.
;             Arg4: Background RGB color value.
;             Arg5: Effect value (DBG_EFFECT_XXX).
;             Arg6: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutTextCW proc pStringW:POINTER, dLength:DWORD, dForeColor:DWORD, dBackColor:DWORD, dEffects:DWORD, pDest:POINTER
  local dCharsWritten:DWORD, wAttrib:WORD, dResult:DWORD
  local CDS:COPYDATASTRUCT

  .if pStringW == NULL
    mov pStringW, $OfsCStrW("NULL Pointer")
    m2m dForeColor, DbgColorError, edx
  .endif

  mov eax, dDbgDev
  .if eax == DBG_DEV_WIN_LOG
    .if $invoke(DbgOpenLog)
      mov eax, dLength
      lea ecx, dCharsWritten
      add eax, eax
      invoke WriteFile, hDbgDev, pStringW, eax, ecx, NULL
    .endif
    .ifBitSet dEffects, DBG_EFFECT_NEWLINE
      invoke WriteFile, hDbgDev, offset wCRLF, 4, addr dCharsWritten, NULL
    .endif

  .elseif eax == DBG_DEV_WIN_CON
    .if $invoke(DbgOpenCon)
      m2z wAttrib
      mov eax, dForeColor
      .ifBitSet al, BIT07 
        or wAttrib, FOREGROUND_INTENSITY or FOREGROUND_RED
      .endif
      .ifBitSet ah, BIT07 
        or wAttrib, FOREGROUND_INTENSITY or FOREGROUND_GREEN
      .endif
      shr eax, 16
      .ifBitSet al, BIT07  
        or wAttrib, FOREGROUND_INTENSITY or FOREGROUND_BLUE
      .endif
      
      .ifBitClr wAttrib, FOREGROUND_INTENSITY
        mov eax, dForeColor
        .if al != 0h 
          or wAttrib, FOREGROUND_RED
        .endif
        .if ah != 0h 
          or wAttrib, FOREGROUND_GREEN
        .endif
        shr eax, 16
        .if al != 0h 
          or wAttrib, FOREGROUND_BLUE
        .endif
      .endif
      invoke SetConsoleTextAttribute, hDbgDev, wAttrib
      lea ecx, dCharsWritten
      invoke WriteConsoleW, hDbgDev, pStringW, dLength, ecx, NULL
      .ifBitSet dEffects, DBG_EFFECT_NEWLINE
        invoke WriteConsoleW, hDbgDev, offset wCRLF, 2, addr dCharsWritten, NULL
      .endif
    .endif

  .else                                                 ;DBG_DEV_WIN_DC
    .if $invoke(DbgOpenWnd)
      mov CDS.dwData, DGB_MSG_ID                        ;Set DebugCenter identifier
      mov eax, dLength                                  ;String length
      add eax, eax                                      ;String size without the ZTC
      push eax
      add eax, sizeof DBG_STR_INFO + 2                  ;This includes the string ZTC
      push eax
      mov CDS.cbData, eax
      invoke StrSizeW, pDest
      push eax                                          ;String size
      add eax, sizeof DBG_HEADER_INFO
      push eax
      add CDS.cbData, eax
      invoke GlobalAlloc, GPTR, CDS.cbData
      .if eax != NULL                                   ;Continue only if GlobalAlloc succeeded
        mov CDS.lpData, eax
        mov [eax].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR ;Set block type = header
        pop [eax].DBG_HEADER_INFO.dBlockLen
        lea ecx, [eax + sizeof DBG_HEADER_INFO]
        push pDest
        push ecx
        call MemClone
        mov eax, CDS.lpData
        add eax, [eax].DBG_HEADER_INFO.dBlockLen
        mov [eax].DBG_STR_INFO.bBlockID, DBG_MSG_STR    ;Set block type = string
        pop [eax].DBG_STR_INFO.dBlockLen
        mov edx, dEffects
        BitSet edx, DBG_CHARTYPE_WIDE                   ;Set this bit
        mov [eax].DBG_STR_INFO.dEffects, edx
        m2m [eax].DBG_STR_INFO.dForeColor, dForeColor, ecx
        m2m [eax].DBG_STR_INFO.dBackColor, dBackColor, edx
        push pStringW
        lea ecx, [eax + sizeof DBG_STR_INFO]
        push ecx
        call MemClone
        mov ecx, CDS.lpData
        add ecx, CDS.cbData
        m2z CHRW ptr [ecx - 2]                          ;Set string ZTC

        invoke SendMessageTimeoutW, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                    SMTO_BLOCK, SMTO_TIMEOUT, addr dResult
        invoke GlobalFree, CDS.lpData
      .else
        add esp, 16                                     ;Restore stack
        invoke MessageBoxW, 0, offset szDbgComErr, offset szDbgErr, MB_OK or MB_ICONERROR
      .endif
    .endif
  .endif
  ret
DbgOutTextCW endp

end
