; ==================================================================================================
; Title:      DbgOutTextA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutTextA
; Purpose:    Sends an ANSI string to the debug output device.
; Arguments:  Arg1: -> Null terminated ANSI string.
;             Arg2: Color value.
;             Arg3: Effect value (DBG_EFFECT_XXX)
;             Arg4: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutTextA proc pStringA:POINTER, dColor:DWORD, dEffects:DWORD, pDest:POINTER
  local CDS:COPYDATASTRUCT, dBytesWritten:DWORD, wAttrib:WORD
  local dInfo1:DWORD, dInfo2:DWORD, dInfo3:DWORD, dInfo4:DWORD

  .if pStringA == NULL
    mov rax, $OfsCStrA("NULL Pointer")
    mov pStringA, rax
    mov dColor, $RGB(255, 0, 0)
  .endif

  mov eax, dDbgDev
  .if eax == DBG_DEV_LOG
    invoke DbgLogOpen
    .if $invoke(DbgLogOpen)
      invoke StrLengthA, pStringA
      invoke WriteFile, hDbgDev, pStringA, eax, NULL, NULL
    .endif
    .ifBitSet dEffects, DBG_EFFECT_NEWLINE
      invoke WriteFile, hDbgDev, offset bCRLF, 2, NULL, NULL
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
      invoke StrLengthA, pStringA
      lea r9, dBytesWritten
      invoke WriteConsoleA, hDbgDev, pStringA, eax, r9, NULL
      .ifBitSet dEffects, DBG_EFFECT_NEWLINE
        invoke WriteConsoleA, hDbgDev, offset bCRLF, 2, addr dBytesWritten, NULL
      .endif
    .endif

  .elseif eax == DBG_DEV_WND
    .if $invoke(DbgWndOpen)
      mov CDS.dwData, DGB_MSG_ID                        ;Set DebugCenter identifier
      invoke StrSizeA, pStringA                         ;String size
      mov dInfo1, eax
      add eax, sizeof(DBG_STR_INFO)                     ;This includes the ZTC
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
        BitClr edx, DBG_CHARTYPE_WIDE                   ;Reset this bit (to be sure)
        mov [rax].DBG_STR_INFO.dEffects, edx
        invoke MemClone, addr [rax + sizeof(DBG_STR_INFO)], pStringA, dInfo1
        invoke SendMessageTimeoutW, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                    SMTO_BLOCK, SMTO_TIMEOUT, NULL
        invoke GlobalFree, CDS.lpData
      .else
        invoke MessageBoxW, 0, offset szDbgComErr, offset szDbgErr, MB_OK or MB_ICONERROR
      .endif
    .endif
  .endif
  ret
DbgOutTextA endp

end
