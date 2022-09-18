; ==================================================================================================
; Title:      DbgOutTextCW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutTextCW
; Purpose:    Send a counted WIDE string to the debug output device.
; Arguments:  Arg1: -> Null terminated WIDE string.
;             Arg2: Maximal character count.
;             Arg3: Color value.
;             Arg4: Effect value (DBG_EFFECT_XXX).
;             Arg5: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutTextCW proc pStringW:POINTER, dLength:DWORD, dColor:DWORD, dEffects:DWORD, pDest:POINTER
  local CDS:COPYDATASTRUCT, dCharsWritten:DWORD, wAttrib:WORD
  local dInfo1:DWORD, dInfo2:DWORD, dInfo3:DWORD, dInfo4:DWORD

  .if pStringW == NULL
    mov rax, $OfsCStrW("NULL Pointer")
    mov pStringW, rax
    mov dColor, $RGB(255, 0, 0)
  .endif
  
  invoke StrLengthW, pStringW
  .if eax < dLength
    mov dLength, eax
  .endif

  mov eax, dDbgDev
  .if eax == DBG_DEV_WIN_LOG
    .if $invoke(DbgOpenLog)
      mov eax, dLength
      add eax, eax
      invoke WriteFile, hDbgDev, pStringW, eax, NULL, NULL
    .endif
    .ifBitSet dEffects, DBG_EFFECT_NEWLINE
      invoke WriteFile, hDbgDev, offset wCRLF, 4, NULL, NULL
    .endif

  .elseif eax == DBG_DEV_WIN_CON
    .if $invoke(DbgOpenCon)
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
      lea r9, dCharsWritten
      invoke WriteConsoleW, hDbgDev, pStringW, dLength, r9, NULL
      .ifBitSet dEffects, DBG_EFFECT_NEWLINE
        invoke WriteConsoleW, hDbgDev, offset wCRLF, 2, addr dCharsWritten, NULL
      .endif
    .endif

  .else                                                 ;DBG_DEV_WIN_DC
    .if $invoke(DbgOpenWnd)
      mov CDS.dwData, DGB_MSG_ID                        ;Set DebugCenter identifier
      mov eax, dLength                                  ;String length
      add eax, eax                                      ;String size not including ZTC
      mov dInfo1, eax
      add eax, sizeof(DBG_STR_INFO) + sizeof(CHRW)      ;This includes the ZTC
      mov dInfo2, eax
      mov CDS.cbData, eax
      invoke StrSizeW, pDest
      mov dInfo3, eax                                   ;String size
      add eax, sizeof(DBG_HEADER_INFO)
      mov dInfo4, eax
      add CDS.cbData, eax
      invoke GlobalAlloc, GPTR, CDS.cbData
      .if rax != NULL                                   ;Continue only if GlobalAlloc succeeded
        mov CDS.lpData, rax
        mov [rax].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR ;Set block type = header
        m2m [rax].DBG_HEADER_INFO.dBlockLen, dInfo4, r8d
        lea rcx, [rax + sizeof(DBG_HEADER_INFO)]
        invoke MemClone, rcx, pDest, dInfo3
        mov rax, CDS.lpData
        mov ecx, [rax].DBG_HEADER_INFO.dBlockLen
        add rax, rcx
        mov [rax].DBG_STR_INFO.bBlockID, DBG_MSG_STR    ;Set block type = string
        m2m [rax].DBG_STR_INFO.dBlockLen, dInfo2, r8d
        m2m [rax].DBG_STR_INFO.dColor, dColor, r9d
        mov edx, dEffects
        BitSet edx, DBG_CHARTYPE_WIDE
        mov [rax].DBG_STR_INFO.dEffects, edx
        lea rcx, [rax + sizeof(DBG_STR_INFO)]
        mov eax, dInfo1
        m2z CHRW ptr [rcx + rax]                        ;Set ZTC 
        invoke MemClone, rcx, pStringW, eax
        
        invoke SendMessageTimeoutW, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                    SMTO_BLOCK, SMTO_TIMEOUT, NULL
        invoke GlobalFree, CDS.lpData
      .else
        invoke MessageBoxW, 0, offset szDbgComErr, offset szDbgErr, MB_OK or MB_ICONERROR
      .endif
    .endif
  .endif
  ret
DbgOutTextCW endp

end
