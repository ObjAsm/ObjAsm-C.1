; ==================================================================================================
; Title:      DbgOutCmd.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

externdef DbgCritSect:CRITICAL_SECTION

.code

option stackbase:rbp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutCmd
; Purpose:    Send a command to a specific Debug window.
; Arguments:  Arg1: Command ID [BYTE].
;             Arg2: Target Debug Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutCmd proc FRAME uses rbx rdi bCommand:BYTE, pTargetWnd:POINTER
  local CDS:COPYDATASTRUCT

  mov eax, dDbgDev
  .if eax == DBG_DEV_WND
    .if $invoke(DbgWndOpen)
      mov CDS.dwData, DGB_MSG_ID                        ;Identify this message source
      .if pTargetWnd != NULL
        invoke StrSizeW, pTargetWnd                     ;Always a WIDE string
        add rax, sizeof(DBG_HEADER_INFO)
      .else
        mov rax, sizeof(DBG_HEADER_INFO)
      .endif
      mov rdi, rax
      add rax, sizeof(DBG_CMD_INFO)
      mov CDS.cbData, eax
      mov rbx, rsp                                      ;rsp restore value
      sub rsp, rax                                      ;Make room on stack to store the info
      and rsp, 0FFFFFFFFFFFFFFF0h                       ;Keep stack aligned to 16
      mov CDS.lpData, rsp
      mov [rsp].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR
      mov [rsp].DBG_HEADER_INFO.dBlockLen, edi
      .if pTargetWnd != NULL
        lea rcx, [rsp + sizeof(DBG_HEADER_INFO)]
        sub rsp, 20h                                    ;Reserve space for the homing area
        invoke StrCopyW, rcx, pTargetWnd                ;Always a WIDE string
        add rsp, 20h
      .endif
      add rdi, rsp
      mov [rdi].DBG_CMD_INFO.bBlockID, DBG_MSG_CMD
      m2m [rdi].DBG_CMD_INFO.bInfo, bCommand, al
      mov [rdi].DBG_CMD_INFO.dBlockLen, sizeof(DBG_CMD_INFO)
      sub rsp, 38h                                      ;Reserve space for homing area and 3 params
      invoke SendMessageTimeoutW, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                  SMTO_BLOCK, SMTO_TIMEOUT, NULL
      mov rsp, rbx                                      ;Restore stack
    .endif
  .endif
  ret
DbgOutCmd endp

end
