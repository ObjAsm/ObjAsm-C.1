; ==================================================================================================
; Title:      DbgOutCmd.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef DbgCritSect:CRITICAL_SECTION

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutCmd
; Purpose:    Send a command to a specific Debug window.
; Arguments:  Arg1: Command ID [BYTE].
;             Arg2: Target Debug Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutCmd proc bCommand:BYTE, pTargetWnd:POINTER
  local CDS:COPYDATASTRUCT, dResult:DWORD, dHeaderSize:DWORD, dESP:DWORD

  invoke EnterCriticalSection, offset DbgCritSect
  mov eax, dDbgDev
  .if eax == DBG_DEV_WIN_LOG
  .elseif eax == DBG_DEV_WIN_CON
  .else                                                 ;DBG_DEV_WIN_DC
    .if $invoke(DbgWndOpen)
      mov CDS.dwData, DGB_MSG_ID                        ;Identify this message source
      .if pTargetWnd != NULL
        invoke StrSizeW, pTargetWnd                     ;Always a WIDE string
        add eax, sizeof DBG_HEADER_INFO
      .else
        mov eax, sizeof DBG_HEADER_INFO
      .endif
      mov dHeaderSize, eax
      add eax, sizeof DBG_CMD_INFO
      mov CDS.cbData, eax
      add eax, 3                                        ;Round up to a multiply of 4
      and eax, not 3                                    ;  to keep the stack aligned
      mov dESP, esp
      sub esp, eax                                      ;Make room on stack to store the info
      mov CDS.lpData, esp
      mov [esp].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR
      m2z [esp].DBG_HEADER_INFO.bInfo
      .if pTargetWnd != NULL
        lea eax, [esp + sizeof DBG_HEADER_INFO]
        invoke StrCopyW, eax, pTargetWnd                ;Always a WIDE string
      .endif
      mrm [esp].DBG_HEADER_INFO.dBlockLen, dHeaderSize, edx
      add edx, esp
      mov [edx].DBG_CMD_INFO.bBlockID, DBG_MSG_CMD
      m2m [edx].DBG_CMD_INFO.bInfo, bCommand, al
      mov [edx].DBG_CMD_INFO.dBlockLen, sizeof DBG_CMD_INFO
      invoke SendMessageTimeoutW, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                  SMTO_BLOCK, SMTO_TIMEOUT, addr dResult
      mov esp, dESP                                     ;Restore stack
    .endif
  .endif
  invoke LeaveCriticalSection, offset DbgCritSect
  ret
DbgOutCmd endp

end
