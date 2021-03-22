; ==================================================================================================
; Title:      DbgOutTextW.asm
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
; Purpose:    Sends a WIDE string to the debug output device
; Arguments:  Arg1: -> Null terminated WIDE string.
;             Arg2: Color value.
;             Arg3: Effect value (DBG_EFFECT_XXX)
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutTextW proc pStr:POINTER, dColor:DWORD, dEffects:DWORD, pDest:POINTER
  local dBytesWritten:DWORD, wAttrib:WORD, dResult:DWORD
  local CDS:COPYDATASTRUCT

  .if pStr == NULL
    mov pStr, $OfsCStrW("NULL Pointer")
    mov dColor, $RGB(255, 0, 0)
  .endif

  mov eax, dDbgDev
  .if eax == DBG_DEV_LOG
    invoke DbgLogOpen
    .if $invoke(DbgLogOpen)
      invoke StrSizeW, pStr
      sub eax, 2
      lea ecx, dBytesWritten
      invoke WriteFile, hDbgDev, pStr, eax, ecx, NULL
    .endif
    .ifBitSet dEffects, DBG_EFFECT_NEWLINE
      invoke WriteFile, hDbgDev, offset wCRLF, 4, addr dBytesWritten, NULL
    .endif

  .elseif eax == DBG_DEV_CON
    .if $invoke(DbgConOpen)
      m2z wAttrib
      mov eax, dColor
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
        mov eax, dColor
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
      invoke StrLengthW, pStr
      lea ecx, dBytesWritten
      invoke WriteConsoleW, hDbgDev, pStr, eax, ecx, NULL
      .ifBitSet dEffects, DBG_EFFECT_NEWLINE
        invoke WriteConsoleW, hDbgDev, offset wCRLF, 2, addr dBytesWritten, NULL
      .endif
    .endif

  .else                                                 ;DBG_DEV_WND
    .if $invoke(DbgWndOpen)
      mov CDS.dwData, DGB_MSG_ID                        ;Set DebugCenter identifier
      invoke StrSizeW, pStr                             ;String size
      push eax
      add eax, sizeof DBG_STR_INFO                      ;This includes the string ZTC
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
        m2m [eax].DBG_STR_INFO.dColor, dColor, ecx
        push pStr
        lea ecx, [eax + sizeof DBG_STR_INFO]
        push ecx
        call MemClone
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
DbgOutTextW endp

end
