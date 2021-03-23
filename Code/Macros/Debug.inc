; ==================================================================================================
; Title:      Debug.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm debug macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, October 2019
;               - Added more color and font customization by HSE.
;             Version C.1.2, October 2020
;               - DbgSaveContext modified to better handle references.
;               - DbgLoadContext simplified.
;               - DbgStr bug corrected.
;               - DbgTextF added.
; ==================================================================================================

;Supported debugging macros:
;———————————————————————————
;  - DbgCloseAll, DbgCloseTxt, DbgCloseBmp
;  - DbgClearAll, DbgClearTxt, DbgClearBmp
;  - DbgLine, DbgLine2, DbgText, DbgTextF, DbgWarning
;  - DbgARGB
;  - DbgStr, DbgStrA, DbgStrW, DbgStrCA, DbgStrCW
;  - DbgBin, DbgDec, DbgHex, DbgFloat, DbgGUID
;  - DbgMem, DbgGlobalMemUsage, DbgFPU
;  - DbgBmp, DbgBmpFromDC
;  - DbgApiError, DbgComError, DbgMessage
;  - DbgObject, DbgTraceObject, DbgTraceShow
;  - ResGuard_Show, ResGuard_Start, ResGuard_Stop
;  - DbgIMT, DbgSMT
;  - DbgAttach, DbgBreak

;DEBUGGING  = TRUE / FALSE   ;Turns debugging output ON or OFF.
;TRACING    = TRUE / FALSE   ;Turns trace output ON or OFF.

; ==================================================================================================

;Debug coloring setup

ifndef DBG_DEVICE
  DBG_DEVICE textequ <WND>
endif

ifidn DBG_DEVICE, <WND>
  if FALSE                                                ;Use high contrast colors
    DBG_COLOR_TEXT        equ   $RGB(230,230,230)
    DBG_COLOR_BACKGROUND  equ   $RGB(000,000,048)
  else
    DBG_COLOR_TEXT        equ   $RGB(000,000,000)
    DBG_COLOR_BACKGROUND  equ   $RGB(255,255,255)
  endif
  DBG_COLOR_COMMENT       equ   $RGB(128,128,128)
  DBG_COLOR_WARNING       equ   $RGB(192,064,064)
  DBG_COLOR_ERROR         equ   $RGB(255,000,000)
  DBG_COLOR_STRING        equ   $RGB(000,000,255)
  DBG_COLOR_MESSAGE       equ   $RGB(064,064,160)
  DBG_COLOR_OBJECT        equ   $RGB(128,128,128)
  DBG_COLOR_INTERFACE     equ   $RGB(090,090,255)
  DBG_COLOR_VMT           equ   $RGB(063,063,255)
  DBG_COLOR_FPU           equ   $RGB(050,150,050)
  DBG_COLOR_MEMORY        equ   $RGB(100,100,200)
  DBG_COLOR_RGB_RED       equ   $RGB(255,000,000)
  DBG_COLOR_RGB_GREEN     equ   $RGB(000,160,000)
  DBG_COLOR_RGB_BLUE      equ   $RGB(000,000,255)
  DBG_COLOR_DEFAULT_PRE   equ   $RGB(090,090,090)
  DBG_COLOR_DEFAULT_VAR   equ   $RGB(130,130,255)
  DBG_COLOR_LINE          equ   $RGB(150,150,255)
else
  DBG_COLOR_TEXT          equ   $RGB(255,255,255)
  DBG_COLOR_BACKGROUND    equ   $RGB(000,000,000)
  DBG_COLOR_COMMENT       equ   $RGB(127,127,127)
  DBG_COLOR_WARNING       equ   $RGB(127,000,000)
  DBG_COLOR_ERROR         equ   $RGB(255,000,000)
  DBG_COLOR_STRING        equ   $RGB(000,000,255)
  DBG_COLOR_MESSAGE       equ   $RGB(127,127,255)
  DBG_COLOR_OBJECT        equ   $RGB(127,127,127)
  DBG_COLOR_INTERFACE     equ   $RGB(000,000,255)
  DBG_COLOR_VMT           equ   $RGB(000,000,255)
  DBG_COLOR_FPU           equ   $RGB(127,255,127)
  DBG_COLOR_MEMORY        equ   $RGB(127,127,255)
  DBG_COLOR_RGB_RED       equ   $RGB(255,000,000)
  DBG_COLOR_RGB_GREEN     equ   $RGB(000,255,000)
  DBG_COLOR_RGB_BLUE      equ   $RGB(000,000,255)
  DBG_COLOR_DEFAULT_PRE   equ   $RGB(127,127,127)
  DBG_COLOR_DEFAULT_VAR   equ   $RGB(255,255,255)
  DBG_COLOR_LINE          equ   $RGB(127,127,127)
endif

;Debug font
DBG_FONT_TEXT             textequ <Courier New>
;DBG_FONT_TEXT             textequ <Fixedsys>

;Debug device
DBG_DEV_NUL               equ   00h
DBG_DEV_LOG               equ   01h
DBG_DEV_CON               equ   02h
DBG_DEV_WND               equ   03h

;Debug options
DBG_OPT_NONE              equ   00h
DBG_OPT_SHOWINFO          equ   01h

;Debug memory formats
DBG_MEM_STRA              equ   100       ;ANSI String
DBG_MEM_STRW              equ   101       ;WIDE String
DBG_MEM_UI8               equ   102       ;Unsigned BYTE Integer in decimal format
DBG_MEM_UI16              equ   103       ;Unsigned WORD Integer in decimal format
DBG_MEM_UI32              equ   104       ;Unsigned DWORD Integer in decimal format
DBG_MEM_UI64              equ   105       ;Unsigned QWORD Integer in decimal format
DBG_MEM_I8                equ   106       ;Signed BYTE Integer in decimal format
DBG_MEM_I16               equ   107       ;Signed WORD Integer in decimal format
DBG_MEM_I32               equ   108       ;Signed DWORD Integer in decimal format
DBG_MEM_I64               equ   109       ;Signed QWORD Integer in decimal format
DBG_MEM_R4                equ   110       ;REAL4 in decimal format
DBG_MEM_R8                equ   111       ;REAL8 in decimal format
DBG_MEM_H8                equ   112       ;BYTE Integer in hexadecimal format
DBG_MEM_H16               equ   113       ;WORD Integer in hexadecimal format
DBG_MEM_H32               equ   114       ;DWORD Integer in hexadecimal format
DBG_MEM_H64               equ   115       ;QWORD Integer in hexadecimal format

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DBG_MEM_STR equ DBG_MEM_STRA
else
  DBG_MEM_STR equ DBG_MEM_STRW
endif


DBG_FLOAT_RESOLUTION      equ   12
DBG_FLOAT_BUFFERSIZE      equ   24        ;(DBG_FLOAT_RESOLUTION + 9) roundup to the next 4 boundary

if DEBUGGING
  CStrW szDbgErr,         "Debug Error"
  CStrW szDbgObjErr,      "Object Error"
  CStrW szDbgComErr,      "DebugCenter communication failed due to low system resources"
  CStrW szLeakReport,     "Resource Leakage Report"

  CStrA szDbgInvalid,     "????"

  CStrW szDbgCtrCls,      &DEBUG_CENTER_CLASS

  externdef dDbgDev:DWORD       ;Exports dDbgDev symbol, defined in SetupSys.inc
  externdef hDbgDev:HANDLE

  .data?
    hDbgDev               HANDLE    ?
    pObjIDTableStart      POINTER   ?
    dObjIDTableCount      DWORD     ?
    pObjErrTableStart     POINTER   ?
    dObjErrTableCount     DWORD     ?
endif


; ==================================================================================================
;    Helper macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgSaveContext
; Purpose:    Save CPU & FPU registers & flags onto stack and aligns it. This way, all subsequent
;             invocations have an aligned stack and a cleared direction flag. Additionally, a
;             Critacal Section is passed to avoid racing conditions.
; Arguments:  Arg1: Handle the passed argument as a Value (FALSE) or a reference (TRUE).
;             Arg2: Var to be saved in rbx/ebx/bx/bl or the address of Var in xbx.
; Returns:    Nothing.
; Note:       On entry, the stack doesn't need to be aligned!

DbgSaveContext macro VarIsRef:=<FALSE>, Var
  pushcontext assumes
  pushfx                                                ;;Save CPU flags
  pushax
  ifnb <Var>
    ??Attributes = opattr(Var)
    if VarIsRef ne FALSE
      if ??Attributes and OAT_REGISTER                  ;;Is Var a register?
        %ifdifi <Var>, <xbx>                            ;;Skip if Var is xbx
          if type(Var) eq @WordSize                     ;;  Use xbx, because it is the only non
            mov xbx, Var                                ;;  volatile register that can be loaded
          else
            .err <DbgSaveContext - Reference error>
            exitm
          endif
        endif
      else
        lea xbx, Var
      endif
      ??VarRBX textequ <xbx>
    else
      if @InStr(1, RBX_SUBREGS, $Upper(Var)) eq 0
        if type(Var) eq 8
          mov rbx, Var
          ??VarRBX textequ <rbx>
        elseif type(Var) eq 4
          mov ebx, Var
          ??VarRBX textequ <ebx>
        elseif type(Var) eq 2
          mov bx, Var
          ??VarRBX textequ <bx>
        elseif type(Var) eq 1
          mov bl, Var
          ??VarRBX textequ <bl>
        else
          if (opattr Var) and OAT_IMMEDIATE
            mov xbx, Var
            ??VarRBX textequ <xbx>
          else
            .err <DbgSaveContext - Value error>
            exitm
          endif
        endif
      else
        ??VarRBX textequ Var
      endif
    endif
  endif

  cld                                                   ;;Reset direction flag for API calling!
  mov xdi, xsp                                          ;;Save current esp value in edi
  if TARGET_BITNESS eq 32
    and esp, 0FFFFFFF0h                                 ;;Align stack on a 16 byte boundary
    invoke EnterCriticalSection, offset(DbgCritSect)    ;;This call don't change GetLastError
    sub esp, XMM_CONTEXT_SIZE
    fxsave [esp]                                        ;;This instruction reinitializes the XMM
    push esp                                            ;;Save FPU storage pointer
    push edi                                            ;;Save address to restore CPU registers
    ifb <Var>                                           ;;If not Var is supplied, restore regs
      mov eax, [edi +  7*4]                             ;;Restore volatile registers
      mov ecx, [edi +  6*4]
      mov edx, [edi +  5*4]
      mov edi, [edi]                                    ;;Restore edi from pushed register values
    endif
  else
    and rsp, 0FFFFFFFFFFFFFFF0h                         ;;Align stack on a 16 byte boundary
    sub rsp, 20h
    invoke EnterCriticalSection, offset(DbgCritSect)    ;;This call don't change GetLastError
    sub rsp, XMM_CONTEXT_SIZE - 20h
    fxsave [rsp]                                        ;;This instruction reinitializes the XMM
    push rsp                                            ;;Save FPU storage pointer
    push rdi                                            ;;Save address to restore CPU registers
    ifb <Var>                                           ;;If not Var is supplied, restore regs
      mov rax, [rdi + 11*8]                             ;;Restore volatile registers
      mov rcx, [rdi + 10*8]
      mov rdx, [rdi +  9*8]
      mov r8,  [rdi +  7*8]
      mov r9,  [rdi +  6*8]
      mov r10, [rdi +  5*8]
      mov r11, [rdi +  4*8]
      mov rdi, [rdi +  8*8]                             ;;Restore rdi from pushed register values
    endif

    sub rsp, 40h                                        ;;Add an homing area and argument space
  endif                                                 ;; for the comming calls
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgLoadContext
; Purpose:    Load CPU & FPU registers & flags from stack and restores the original stack alignment.
; Arguments:  None.
; Returns:    Nothing.

DbgLoadContext macro
  if TARGET_BITNESS eq 32
    pop ebp
    pop ebx
    fxrstor [ebx]                                       ;;Read XMM content back
  else
    add rsp, 40h                                        ;;Remove homing area and argument space
    pop rbp
    pop rbx
    fxrstor [rbx]                                       ;;Read XMM content back
    sub rsp, 20h
  endif
  invoke LeaveCriticalSection, offset(DbgCritSect)
  mov xsp, xbp                                          ;;Restore rsp
  popax                                                 ;;Restore CPU registers
  popfx                                                 ;;Direction flag is restored here too
  popcontext assumes
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgSetDestWnd
; Purpose:    Set the global symbol ??DbgDstWnd.
; Arguments:  Arg1: Debug Center MDI destination child window name on which will be directed
;                   the information.
; Returns:    Nothing.

DbgSetDestWnd macro DestWnd
  local ??DestWnd                                       ;;Must be local

  ifb <DestWnd>
    ??DbgDstWnd textequ <offset(szDbgSrc)>
  else
    ifidni @SubStr(DestWnd, 1, 1), <">
      CStrW ??DestWnd, DestWnd                          ;;Create only 1 instance of the window name.
      ??DbgDstWnd textequ <offset(??DestWnd)>
    else
      ??DbgDstWnd textequ <DestWnd>
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgShowSrcInfo
; Purpose:    Output source line info on the debug device.
; Arguments:  Arg1: Optional destination Window name.
; Returns:    Nothing.

DbgShowSrcInfo macro Dest:req
  ??DbgIndex = 0
  ??DbgPos = 0
  %forc ??DbgChar, @FileCur                             ;;Search last "\" and return string position
    ??DbgIndex = ??DbgIndex + 1
    ifidni <&??DbgChar>, <\>
      ??DbgPos = ??DbgIndex
    endif
  endm

  .ifBitSet dDbgOpt, DBG_OPT_SHOWINFO
    invoke DbgOutTextA, \
              $OfsCStrA(@CatStr(<!" [>, @SubStr(%@FileCur, ??DbgPos + 1), <, >, %@Line, <]!">)), \
              DBG_COLOR_COMMENT, DBG_EFFECT_NEWLINE, Dest
  .else
    invoke DbgOutTextA, offset(bNULL), DBG_COLOR_TEXT, DBG_EFFECT_NEWLINE, Dest
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgShowTxtInfo
; Purpose:    Output additional text info on the debug device.
; Arguments:  Arg1: Text.
;             Arg2: Optional destination Window name.
; Returns:    Nothing.

DbgShowTxtInfo macro Text, Dest
  ifnb <&Text>
    invoke DbgOutTextA, $OfsCStrA(<", ", &Text>), DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, Dest
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgOutHex
; Purpose:    Output a number in hexadecimal on the debug output device.
; Arguments:  Arg1: Text displayed befor the value.
;             Arg2: Output color of PreText (defaut is black).
;             Arg3: Symbol. Value or address must be stored in rbx/ebx/bx/bl.
;             Arg4: Output color (default = black).
;             Arg5: Optional destination Window name.
; Note:       If register addressing is used, a size prefix is required.
;             i.e.:  DbgHexHex DWORD ptr [rcx]
;             THIS MACRO TRASHES XDI & XSI!

OutHexAux macro
  if ??DbgDataSize ge 16
    invoke qword2hexA, xdi, [xbx + 8]
    add xdi, 16
    invoke qword2hexA, xdi, [xbx]
    H_Offset = 16
    if ??DbgDataSize ne 16
      add xdi, 16
      mov QCHRA ptr [xdi], "..."
      H_Offset = 3
    endif
  elseif ??DbgDataSize ge 8
    invoke qword2hexA, xdi, [xbx]
    H_Offset = 16
    if ??DbgDataSize ne 8
      add xdi, 16
      mov QCHRA ptr [xdi], "..."
      H_Offset = 3
    endif
  elseif ??DbgDataSize ge 4
    invoke dword2hexA, xdi, [xbx]
    H_Offset = 8
    if ??DbgDataSize ne 4
      add xdi, 8
      mov QCHRA ptr [xdi], "..."
      H_Offset = 3
    endif
  elseif ??DbgDataSize ge 2
    movzx edx, WORD ptr [xbx]
    invoke dword2hexA, xdi, edx
    add xsi, 4
    H_Offset = 8
    if ??DbgDataSize ne 2
      add xdi, 8
      mov QCHRA ptr [xdi], "..."
      H_Offset = 3
    endif
  else
    movzx edx, BYTE ptr [xbx]
    invoke dword2hexA, xdi, edx
    add xsi, 6
    H_Offset = 8
  endif
  mov DCHRA ptr [xdi + H_Offset], "h"
endm

DbgOutHex macro PreText:=<>, PreColor:=<DBG_COLOR_DEFAULT_PRE>, Var:req, \
                VarColor:=<DBG_COLOR_DEFAULT_VAR>, Dest:req
  ??DbgDataSize = type(Var)
  if TARGET_BITNESS eq 32
    ;;Reserve stack = 4*8 chars + "h" + ZTC = 22h => 28h
    sub esp, 28h
    ifnb <PreText>
      invoke DbgOutTextA, $OfsCStrA($Esc("&PreText&")), PreColor, DBG_EFFECT_NORMAL, Dest
    endif
    if (opattr Var) and OAT_REGISTER                      ;;Is Var a register?
      mov esi, esp                                        ;;+ 2 padding bytes = 0Ch
      invoke dword2hexA, esi, ebx
      mov DCHRA ptr [esi + 8], "h"                        ;;Set "h" + ZTC
      if ??DbgDataSize lt 4
        add esi, 8 - 2*??DbgDataSize                      ;;Skip unnecessary zeros
      endif
    else
      invoke IsBadReadPtr, ebx, DWORD ptr ??DbgDataSize
      .if eax != 0
        mov esi, offset(szDbgInvalid)
      .else
        mov edi, esp
        mov esi, edi
        OutHexAux
      .endif
    endif
    invoke DbgOutTextA, esi, VarColor, DBG_EFFECT_NORMAL, Dest
    add esp, 28h                                          ;;Restore stack
  else
    ;;Reserve stack = 2*16 chars + "h" + ZTC + 14 padding bytes + homing space = 50h
    sub rsp, 50h
    ifnb <PreText>
      invoke DbgOutTextA, $OfsCStrA($Esc("&PreText&")), PreColor, DBG_EFFECT_NORMAL, Dest
    endif
    if (opattr Var) and OAT_REGISTER                      ;;Is Var a register?
      lea rsi, [rsp + 20h]
      invoke qword2hexA, rsi, rbx
      mov DCHRA ptr [rsi + 16], "h"                       ;;Set "h" + ZTC
      if ??DbgDataSize lt 8
        add rsi, 16 - 2*??DbgDataSize                     ;;Skip unnecessary zeros
      endif
    else
      invoke IsBadReadPtr, rbx, DWORD ptr ??DbgDataSize
      .if rax != 0
        mov rsi, offset(szDbgInvalid)
      .else
        lea rdi, [rsp + 20h]
        mov rsi, rdi
        OutHexAux
      .endif
    endif
    invoke DbgOutTextA, rsi, VarColor, DBG_EFFECT_NORMAL, Dest
    add rsp, 50h                                          ;;Restore stack
  endif
endm

; ==================================================================================================
;   String debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgLine
; Purpose:    Draw a single line on the debug device.
; Arguments:  Arg1: Optional destination Window name.

DbgLine macro Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifidn DBG_DEVICE, <WND>
      invoke DbgOutCmd, DBG_CMD_SINGLE_LINE, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA("-------------------------------------------------------"), \
                          DBG_COLOR_LINE, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    endif
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgLine2
; Purpose:    Draw a double line on the debug device.
; Arguments:  Arg1: Optional destination Window name.

DbgLine2 macro Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifidn DBG_DEVICE, <WND>
      invoke DbgOutCmd, DBG_CMD_DOUBLE_LINE, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA("======================================================="), \
                          DBG_COLOR_LINE, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    endif
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgText
; Purpose:    Output a text on the debug device.
; Arguments:  Arg1: Text.
;             Arg2: Optional destination Window name.

DbgText macro Var, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifb <&Var>
      invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">,<%@FileCur>,<!">)), \
                          DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA($Esc(<&Var>)), \
                          DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
    endif
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgTextF
; Purpose:    Output formated a text on the debug device.
; Arguments:  Arg1: Optional destination Window name.
;             Arg2: Optional text color.
;             Arg3: Format text.
;             Arg4: Text paramters.
; Example:    DbgTextF "Output", $RGB(0,0,0), "Data = '%s'", xax

DbgTextF macro Dest, Color:=<DBG_COLOR_TEXT>, Message:req, Args:vararg
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifnb <Args>
      ifndef DebugTextF
        S_DATA segment
         DebugTextF CHRA 1024 dup (?)
        S_DATA ends
      endif

      invoke wsprintf, offset DebugTextF, $OfsCStrA($Esc(Message)), Args
      invoke DbgOutText, offset DebugTextF, Color, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    else
      invoke DbgOutText, $OfsCStrA($Esc(Message)), Color, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    endif
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgWarning
; Purpose:    Output a text on the debug device on red color.
; Arguments:  Arg1: Text.
;             Arg2: Optional destination Window name.

DbgWarning macro DispText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    ifb <&Var>
      invoke DbgOutTextA, $OfsCStrA($Esc("WARNING\:")), \
                          DBG_COLOR_WARNING, DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA($Esc(<DispText>)), \
                          DBG_COLOR_WARNING, DBG_EFFECT_NORMAL, ??DbgDstWnd
    endif
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DbgStr textequ <DbgStrA>
else
  DbgStr textequ <DbgStrW>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgStrA
; Purpose:    Output a specified string on the debug device.
; Arguments:  Arg1: ANSI String.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgStrA macro Var:req, InfoText, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
      DbgSetDestWnd Dest
      invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), DBG_COLOR_DEFAULT_PRE, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgStrA - <Var> register error>
        exitm
      else
        DbgSaveContext TRUE, Var                        ;;Pass Var as a reference
        DbgSetDestWnd Dest
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), DBG_COLOR_DEFAULT_PRE, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
    endif
    invoke DbgOutTextA, ??VarRBX, DBG_COLOR_STRING, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgStrW
; Purpose:    Output a specified WIDE string on the debug device.
; Arguments:  Arg1: WIDE string.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgStrW macro Var:req, InfoText, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
      DbgSetDestWnd Dest
      invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), DBG_COLOR_DEFAULT_PRE, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgStrW - <Var> register error>
        exitm
      else
        DbgSaveContext TRUE, Var                        ;;Pass Var as a reference
        DbgSetDestWnd Dest
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), DBG_COLOR_DEFAULT_PRE, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
    endif
    invoke DbgOutTextW, ??VarRBX, DBG_COLOR_STRING, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgStrCA
; Purpose:    Output a limited ANSI string on the debug device.
; Arguments:  Arg1: ANSI string.
;             Arg2: Character count (fix number, like 8).
;             Arg3: Additional information.
;             Arg4: Optional destination Window name.

DbgStrCA macro Var:req, StrLen:req, InfoText, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
      DbgSetDestWnd Dest
      invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), DBG_COLOR_DEFAULT_PRE, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgStrCA - <Var> register error>
        exitm
      else
        DbgSaveContext TRUE, Var                        ;;Pass Var as a reference
        DbgSetDestWnd Dest
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), DBG_COLOR_DEFAULT_PRE, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
    endif
    invoke DbgOutTextCA, ??VarRBX, StrLen, DBG_COLOR_STRING, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgStrCW
; Purpose:    Output a limited WIDE string on the debug device.
; Arguments:  Arg1: WIDE string.
;             Arg2: Character count.
;             Arg3: Additional information.
;             Arg4: Optional destination Window name.

DbgStrCW macro Var:req, StrLen:req, InfoText, Dest
  if DEBUGGING
    if type(Var) eq @WordSize                           ;;Check if Var is a POINTER or characters
      DbgSaveContext FALSE, Var                         ;;Pass Var as a value
      DbgSetDestWnd Dest
      invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), DBG_COLOR_DEFAULT_PRE, \
                          DBG_EFFECT_NORMAL, ??DbgDstWnd
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgStrCW - <Var> register error>
        exitm
      else
        DbgSaveContext TRUE, Var                        ;;Pass Var as a reference
        DbgSetDestWnd Dest
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), DBG_COLOR_DEFAULT_PRE, \
                            DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
    endif
    invoke DbgOutTextCW, ??VarRBX, StrLen, DBG_COLOR_STRING, DBG_EFFECT_NORMAL, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DbgStrC textequ <DbgStrCA>
else
  DbgStrC textequ <DbgStrCW>
endif


; ==================================================================================================
;   Number debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgHex
; Purpose:    Display a number in hexadecimal format on the debug device.
; Arguments:  Arg1: Number (register or symbol).
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Note:       If register addressing is used, a size prefix is required.
;             i.e.:  DbgHex DWORD ptr [rcx]

DbgHex macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    DbgOutHex <Var = >,, ??VarRBX,, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBin
; Purpose:    Output a number in binary format on the debug device.
; Arguments:  Arg1: Number (register or symbol). Max 32 bits.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Note:       If register addressing is used, a size prefix is required.
;             i.e.:  DbgBin DWORD ptr [rcx]

DbgBin macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA("&Var = "), DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
    if TARGET_BITNESS eq 32
      $$Buffersize = 24h                                ;;32 + "y" + ZTC + Padding(2) = 24h
      sub esp, $$Buffersize                             ;;Reserve a buffer on the stack.
      mov edi, esp                                      ;;Get a pointer to the buffer
    else
      $$Buffersize = 68h                                ;;64 + "y" + ZTC + Padding(6) + Homing = 68h
      sub rsp, $$Buffersize                             ;;Reserve a buffer on the stack.
      lea rdi, [rsp + 20h]                              ;;Get a POINTER to the output buffer
    endif
    mov xsi, xdi                                        ;;Save it
    mov xcx, 8*type(Var)
    if @WordSize ne type(Var)
      rcl xbx, 8*(@WordSize - type(Var))                ;;Skip unused bits in rbx
    endif
  @@:
    rcl xbx, 1                                          ;;Set bit in carry flag
    setc al
    add al, "0"
    stosb
    loop @B
    mov DCHRA ptr [xdi], "y"                            ;;Set "y" specifier and ZTC
    invoke DbgOutTextA, xsi, DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
    add xsp, $$Buffersize                               ;;Restore stack
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgDec
; Purpose:    Output a number in decimal format on the debug device.
; Arguments:  Arg1: Number (register or symbol). Max 32 bits
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Note:       If register addressing is used, a size prefix is required.
;             i.e.:  DbgDec DWORD ptr [rcx]

DbgDec macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA("&Var = "), DBG_COLOR_DEFAULT_PRE, DBG_EFFECT_NORMAL, ??DbgDstWnd
    if TARGET_BITNESS eq 32
      $$Buffersize = 0Ch                                ;;10 + "t" + ZTC + Padding(0) = 0Ch
      sub esp, $$Buffersize                             ;;Reserve a buffer on the stack.
      mov edi, esp                                      ;;Get a pointer to the buffer
    else
      $$Buffersize = 38h                                ;;20 + "y" + ZTC + Padding(2) + Homing = 38h
      sub rsp, $$Buffersize                             ;;Reserve a buffer on the stack.
      lea rdi, [rsp + 20h]                              ;;Get a POINTER to the output buffer
    endif
    invoke wsprintfA, xdi, $OfsCStrA("%lit"), ??VarRBX
    invoke DbgOutTextA, xdi, DBG_COLOR_DEFAULT_VAR, DBG_EFFECT_NORMAL, ??DbgDstWnd
    add xsp, $$Buffersize                               ;;Restore stack
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFloat
; Purpose:    Display a floating point number in decimal format on the debug device.
; Arguments:  Arg1: Floating point number (REAL4 or REAL8)
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgFloat macro Var:req, InfoText, Dest
  if DEBUGGING
    ??DbgDataSize = type(Var)
    if (??DbgDataSize ne 4) and (??DbgDataSize ne 8) and (??DbgDataSize ne 10)
      .err <DbgFloat - wrong argument type>
    else
      if (opattr Var) and OAT_REGISTER                  ;;Is Var a register?
        .err <DbgFloat - invalid parameter>
      else
        DbgSaveContext TRUE, Var
        DbgSetDestWnd Dest
        if ??DbgDataSize eq 4
          fld REAL4 ptr [xbx]
        elseif ??DbgDataSize eq 8
          fld REAL8 ptr [xbx]
        else
          fld REAL10 ptr [xbx]
        endif
        mov xdi, xsp
        sub xsp, DBG_FLOAT_BUFFERSIZE + 20h             ;;Reserve a buffer for the number
        lea xsi, [xsp + 20h]                            ;; Keep stack aligned!
        invoke DbgOutTextA, $OfsCStrA("&Var = "), DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
        invoke St0ToStrA, xsi, 0, DBG_FLOAT_RESOLUTION, 1
        invoke DbgOutTextA, xsi, DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
        add xsp, DBG_FLOAT_BUFFERSIZE + 20h             ;;Restore stack
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgGUID
; Purpose:    Output the a GUID on the debug device.
; Arguments:  Arg1: GUID.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgGUID macro Var:req, InfoText, Dest
  if DEBUGGING
    ??DbgDataSize = type(Var)
    if (??DbgDataSize ne @WordSize) and (??DbgDataSize ne type(GUID))
      .err <DbgGUID - wrong argument type>
    else
      DbgSaveContext TRUE, Var
      DbgSetDestWnd Dest
      if TARGET_BITNESS eq 32
        $$Buffersize = 28h                              ;;36 + ZTC + Padding(3) = 28Ch
        sub esp, $$Buffersize                           ;;Reserve a buffer on the stack.
        mov edi, esp                                    ;;Get a pointer to the buffer
      else
        $$Buffersize = 48h                              ;;36 + ZTC + Padding(3) + Homing = 48h
        sub rsp, $$Buffersize                           ;;Reserve a buffer on the stack.
        lea rdi, [rsp + 20h]                            ;;Get a POINTER to the output buffer
      endif
      invoke GUID2StrA, xdi, ??VarRBX
      if ??DbgDataSize eq @WordSize
        invoke DbgOutTextA, $OfsCStrA($Esc("&Var& -\] ")), \
                            DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
      else
        invoke DbgOutTextA, $OfsCStrA("&Var& = "), \
                            DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
      endif
      invoke DbgOutTextA, xdi, DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
      add xsp, $$Buffersize                             ;;Restore stack
      DbgShowTxtInfo InfoText, ??DbgDstWnd
      DbgShowSrcInfo ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgARGB
; Purpose:    Output the an ARGB color on the debug device.
; Arguments:  Arg1: ARGB DWORD color value.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgARGB macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    if type(Var) ne type(DWORD)
      .err <DbgARGB - invalid argument.>
    endif
    mov edi, ebx
    shr ebx, 24
    DbgOutHex <Var = [A:>, DBG_COLOR_TEXT, al, DBG_COLOR_TEXT, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA(", "),DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
    mov ebx, edi
    DbgOutHex <R:>, DBG_COLOR_RGB_RED, al, DBG_COLOR_RGB_RED, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA(", "),DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
    mov ebx, edi
    shr ebx, 8
    DbgOutHex <G:>, DBG_COLOR_RGB_GREEN, al, DBG_COLOR_RGB_GREEN, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA(", "),DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
    mov ebx, edi
    shr ebx, 16
    DbgOutHex <B:>, DBG_COLOR_RGB_BLUE, al, DBG_COLOR_RGB_BLUE, ??DbgDstWnd
    invoke DbgOutTextA, $OfsCStrA("]"),DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd

    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm


; ==================================================================================================
;   Bitmap debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBmp
; Purpose:    Output a specified bitmap on the debug device.
; Arguments:  Arg1: Bitmap HANDLE.
;             Arg2: Optional destination Window name.

DbgBmp macro hBmp:req, Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext FALSE, hBmp
      DbgSetDestWnd Dest
      invoke DbgOutBitmap, ??VarRBX, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBmpFromDC
; Purpose:    Output a specified bitmap on the debug device.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Optional destination Window name.

DbgBmpFromDC macro hDC:req, Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext FALSE, hDC
      DbgSetDestWnd Dest
      invoke GetCurrentObject, hDC, OBJ_BITMAP
      invoke DbgOutBitmap, xax, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm


; ==================================================================================================
;   Memory debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgMem
; Purpose:    Output a memory block on the debug device.
; Arguments:  Arg1: -> memory block.
;             Arg2: Size of memory block.
;             Arg3: Output format (DBG_MEM_STR, DBG_MEM_[U]I??, DBG_MEM_R?, DBG_MEM_H??).
;             Arg4: Additional information.
;             Arg5: Optional destination Window name.

DbgMem macro pData:req, DataSize:req, OutputFormat:=<DBG_MEM_STR>, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, pData                          ;;Pass pData as a value
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA("MEMORY DUMP of &pData"), DBG_COLOR_MEMORY, DBG_EFFECT_BOLD, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    invoke DbgOutMem, ??VarRBX, DataSize, OutputFormat, ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgGlobalMemUsage
; Purpose:    Display global memory usage on the debug window.
; Arguments:  Arg1: Additional information.
;             Arg2: Optional destination Window name.

DbgGlobalMemUsage macro InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    mov xbx, xsp                                        ;;Save stack pointer
    sub xsp, 96                                         ;;Keep stack aligned!
    mov xsi, xsp
    sub xsp, sizeof(MEMORYSTATUS)                       ;;Keep stack aligned!
    mov xdi, xsp
    assume xdi:ptr MEMORYSTATUS
    if TARGET_BITNESS eq 64
      sub xsp, 20h                                      ;;Homing area
    endif
    invoke GlobalMemoryStatus, xdi                      ;;No need to set MEMORYSTATUS.dwLength

    invoke wsprintfA, xsi, $OfsCStrA("Memory load: %lu%%"), [xdi].MEMORYSTATUS.dwMemoryLoad
    invoke DbgOutTextA, xsi, DBG_COLOR_MEMORY, DBG_EFFECT_BOLD, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd

    invoke wsprintfA, xsi, $OfsCStrA(" - Physical: %lu of %lu bytes."), \
                      [xdi].dwAvailPhys, [xdi].dwTotalPhys
    invoke DbgOutTextA, xsi, DBG_COLOR_MEMORY, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    invoke wsprintfA, xsi, $OfsCStrA(" - PageFile: %lu of %lu bytes."), \
                      [xdi].dwAvailPageFile, [xdi].dwTotalPageFile
    invoke DbgOutTextA, xsi, DBG_COLOR_MEMORY, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    invoke wsprintfA, xsi, $OfsCStrA(" - Virtual : %lu of %lu bytes."), \
                      [xdi].dwAvailVirtual, [xdi].dwTotalVirtual
    invoke DbgOutTextA, xsi, DBG_COLOR_MEMORY, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    mov xsp, xbx
    DbgLoadContext
  endif
endm




; ==================================================================================================
;   Hardware debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgFPU
; Purpose:    Output the content of the FPU registers on the debug device.
; Arguments:  Arg1: Additional information.
;             Arg2: Optional destination Window name.

DbgFPU macro InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    invoke DbgOutTextA, $OfsCStrA("FPU DUMP"), DBG_COLOR_FPU, DBG_EFFECT_BOLD, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    invoke DbgOutFPU, ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ==================================================================================================
;   OS debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgMessage
; Purpose:    Identify a windows message with a string.
; Arguments:  Arg1: Windows message.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgMessage macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    invoke DbgOutMsg, ebx, DBG_COLOR_MESSAGE, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgApiError
; Purpose:    Identify an API error with a string.
; Arguments:  Arg1: Additional information.
;             Arg2: Optional destination Window name.

DbgApiError macro InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    invoke GetLastError
    invoke DbgOutApiErr, eax, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgComError
; Purpose:    Identify a COM error with a string
; Arguments:  Arg1: COM error code.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgComError macro Var:req, InfoText, Dest
  if DEBUGGING
    DbgSaveContext FALSE, Var
    DbgSetDestWnd Dest
    invoke DbgOutComErr, ebx, ??DbgDstWnd
    DbgShowTxtInfo InfoText, ??DbgDstWnd
    DbgShowSrcInfo ??DbgDstWnd
    DbgLoadContext
  endif
endm


; ==================================================================================================
;   Object debugging macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgObject
; Purpose:    Output internal object variables to the debug device.
; Arguments:  Arg1: InstanceHANDLE::ClassName.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Return:     Nothing.
; Note:       ebp is assumed to nothing!

DbgObject macro Expression, InfoText, Dest
  if DEBUGGING
    PreParseExpr Expression
    if $ParseInstExpr(Expression) eq FALSE or ??Pos3 ne 0
      .err <DbgObject - invalid syntax: Expression>
    else
      %ifndef ??ObjExpr
        %.err <DbgObject - unknown object: ??ObjExpr>
      else
        DbgSaveContext TRUE, ??InsExpr
        DbgSetDestWnd Dest
        invoke DbgShowObjectHeader, $OfsCStrA(<!"%??ObjExpr!">), xbx, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        mov xdi, xbx

        %for ??TestObject, @CatStr(<!<>, %??ObjExpr, <_InherFrwPath!>>)
          $$ACount = 0
          %repeat @CatStr(<??TestObject>, <_VCount>)
            $$ACount = $$ACount + 1
            $$sz1 textequ @CatStr(<??TestObject>, <_VarName_>, %$$ACount)
            $$sz2 textequ @CatStr(<??TestObject>, <_VarType_>, %$$ACount)
            if @InStr(1, <%$$sz2>, <??>) eq 1
              $$Pos2 InStr 3, $$sz2, <_Init>
              if $$Pos2 gt 3
                $$sz2 CatStr @SubStr(<%$$sz2>, 3, $$Pos2 - 3)
              endif
            endif
            lea xbx, @CatStr(<[xdi].>, <??TestObject>, <.>, %$$sz1)
            push xdi
            %DbgOutHex < - &$$sz1 = >, DBG_COLOR_OBJECT, \
                       @CatStr(<[xdi].>, <??TestObject>, <.>, %$$sz1),, ??DbgDstWnd
            pop xdi
            %ifidn <??TestObject>, <??ObjExpr>
              invoke DbgOutTextA, $OfsCStrA(<!" (%$$sz2)!">), \
                                   DBG_COLOR_OBJECT, DBG_EFFECT_NEWLINE, ??DbgDstWnd
            else
              invoke DbgOutTextA, $OfsCStrA(<!" (%$$sz2 from &??TestObject)!">), \
                                   DBG_COLOR_OBJECT, DBG_EFFECT_NEWLINE, ??DbgDstWnd
            endif
          endm
        endm
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgVMT
; Purpose:    Output offsets contained in a VMT.
; Arguments:  Arg1: InstanceHANDLE::ClassName.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Return:     Nothing.
; Note:       ebp is assumed to nothing!

DbgVMT macro Expression, InfoText, Dest
  if DEBUGGING
    PreParseExpr Expression
    if $ParseInstExpr(Expression) eq FALSE or ??Pos3 ne 0
      .err <DbgVMT - invalid syntax: Expression>
    else
      %ifndef ??ObjExpr
        %.err <DbgVMT - unknown object: ??ObjExpr>
      else
        DbgSaveContext TRUE, ??InsExpr
        DbgSetDestWnd Dest
        invoke DbgShowObjectHeader, $OfsCStrA(<!"%??ObjExpr!">), xbx, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        mov xdi, [xbx]                                  ;;xbx -> VMT
        DbgOutHex < Virtual Method Table @ >, DBG_COLOR_VMT, xbx, DBG_COLOR_TEXT, ??DbgDstWnd
        invoke DbgOutTextA, offset(bCRLF), DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
        %for ??TestObject, @CatStr(<!<>, %??ObjExpr, <_InherFrwPath!>>)
          $$ACount = 0
          %repeat @CatStr(<??TestObject>, <_VtlMtdCount>)
            $$ACount = $$ACount + 1
            $$sz1 CatStr <??TestObject>, <_VtlMethodName_>, %$$ACount
            %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!" - >, @SubStr(%$$sz1, ??MtdPfxOfs), \
                                 < method @ !">)), DBG_COLOR_VMT, DBG_EFFECT_NORMAL, ??DbgDstWnd
            DbgOutHex,, @CatStr(<[xdi - sizeof(??>, ??TestObject, <_VMT) - @WordSize].??>, \
                                ??TestObject, <_VMT.>, %$$sz1), 0, ??DbgDstWnd
            invoke DbgOutTextA, offset(bCRLF), \
                                DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
          endm
        endm
        DbgLoadContext
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgIMT
; Purpose:    Output offsets contained in a IMT.
; Arguments:  Arg1: InstanceHANDLE::ClassName.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Return:     Nothing.
; Note:       ebp is assumed to nothing!

DbgIMT macro Expression, InfoText, Dest
  if DEBUGGING
    PreParseExpr Expression
    if $ParseInstExpr(Expression) eq FALSE or ??Pos3 ne 0
     .err <DbgIMT - invalid syntax: Expression>
    else
      %ifndef ??ObjExpr
        %.err <DbgIMT - unknown object: ??ObjExpr>
      else
        DbgSaveContext TRUE, ??InsExpr
        DbgSetDestWnd Dest
        invoke DbgShowObjectHeader, $OfsCStrA(<!"%??ObjExpr!">), xbx, ??DbgDstWnd
        DbgShowTxtInfo InfoText, ??DbgDstWnd
        DbgShowSrcInfo ??DbgDstWnd
        mov xdi, [xbx]                                  ;;xbx -> VMT
        DbgOutHex < Interface Method Table @ >, DBG_COLOR_VMT, xbx, DBG_COLOR_TEXT, ??DbgDstWnd
        invoke DbgOutTextA, offset(bCRLF), DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
        %for ??TestObject, @CatStr(<!<>, %??ObjExpr, <_InherFrwPath!>>)
          $$ACount = 0
          %repeat @CatStr(<??TestObject>, <_IfcMtdCount>)
            $$ACount = $$ACount + 1
            $$sz1 CatStr <??TestObject>, <_IfcMethodName_>, %$$ACount
            %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!" - >, @SubStr(%$$sz1, ??MtdPfxOfs, \
                                 < method @ !">)), DBG_COLOR_VMT, DBG_EFFECT_NORMAL, ??DbgDstWnd
            DbgOutHex,, @CatStr(<[xdi - sizeof(??>, ??TestObject, <_IMT) - @WordSize].??>, \
                                 ??TestObject, <_VMT.>, %$$sz1), 0, ??DbgDstWnd
            invoke DbgOutTextA, offset(bCRLF), \
                                DBG_COLOR_TEXT, DBG_EFFECT_NORMAL, ??DbgDstWnd
          endm
        endm
        DbgLoadContext
      endif
    endif
  endif
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      DbgTraceObject
;; Purpose:    Start tracing of an object instance.
;; Arguments:  Arg1: Instance POINTER.
;
;DbgTraceObject macro IName:req
;  if DEBUGGING
;    if TRACING
;      DbgSaveContext TRUE, IName
;      if type(IName) eq @WordSize             ;;If true, then it's not an Object instance!
;        if (opattr IName) and OAT_REGISTER    ;;Is ??DbgIName a register?
;          mov ??pDbgTraceInstance, IName
;        else
;          mrm ??pDbgTraceInstance, IName, xax
;        endif
;      else
;        ??Attributes = opattr(IName)
;        if ??Attributes eq 00100010y or ??Attributes eq 01100010y
;          lea xcx, IName
;          mov ??pDbgTraceInstance, xcx
;        else
;          mov ??pDbgTraceInstance, offset(IName)
;        endif
;      endif
;      DbgLoadContext
;    else
;      %echo @CatStr(<WARNING: TRACE debug option is not active (>, %@FileCur, <, >, %@Line, <).>)
;    endif
;  endif
;endm
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      DbgTraceShow
;; Purpose:    Display gattered trace information.
;; Arguments:  Arg1: Object name.
;;             Arg2: Additional information.
;;             Arg2: Optional destination Window name.
;
;DbgTraceShow macro OName:req, InfoText, Dest
;  if DEBUGGING
;    if TRACING
;      DbgSaveContext
;      DbgSetDestWnd Dest
;      invoke DbgShowObjectHeader, $OfsCStrA("&OName"), ??pDbgTraceInstance, ??DbgDstWnd
;      DbgShowTxtInfo InfoText, ??DbgDstWnd
;      DbgShowSrcInfo ??DbgDstWnd
;      %DbgShowTraceResult OName, ??DbgDstWnd          ;;Begin recursive display of results
;      DbgLoadContext
;    else
;      %echo @CatStr(<WARNING: TRACE debug option is not active (>, %@FileCur, <, >, %@Line, <).>)
;    endif
;  endif
;endm
;
;DbgShowTraceResult macro OName:req, Dest
;% for ??TestObject, <&OName&_InherFrwPath>
;
;    ;; --------- Virtual methods ---------
;    $$ACount = 0
;    repeat @CatStr(<??TestObject>, <_VtlMtdCount>)
;      $$ACount = $$ACount + 1
;      $$sz1 CatStr <??TestObject>, <_VtlMethod_Name_>, %$$ACount
;
;      ??DbgTraceMtdCount CatStr <MtdCnt_>, <??TestObject>, <_>, $$sz1
;      ??DbgTraceMtdTicks CatStr <MtdTck_>, <??TestObject>, <_>, $$sz1
;
;      %ifdef ??DbgTraceMtdCount
;        %ifidn <$$sz1>, <WndProc>
;          ;;WndProc can't be traced due to pSelf is set after the prologue!
;          %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                               DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;          %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                               DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;          invoke DbgOutTextA, $OfsCStrA("unable to trace this method."), \
;                              DBG_COLOR_WARNING, DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;        else
;          %DbgShowTraceVar @CatStr(<??TestObject>, <.>, %$$sz1), \
;                           ??DbgTraceMtdCount, ??DbgTraceMtdTicks, Dest
;        endif
;      else                                                ;;It is an abstract method!
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                             DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                            DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;;        %echo @CatStr(OName, <_VtlMethod_Proc_>, %$$ACount)
;        invoke DbgOutTextA, $OfsCStrA("Unable to trace this method (abstract, precompiled, etc.)."), \
;                            DBG_COLOR_WARNING, DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;      endif
;    endm
;
;    ;; --------- Interface methods ---------
;    $$ACount = 0
;    repeat @CatStr(<??TestObject>, <_IfcMtdCount>)
;      $$ACount = $$ACount + 1
;      $$sz1 CatStr <??TestObject>, <_IfcMethod_Name_>, %$$ACount
;
;      ??DbgTraceMtdCount CatStr <MtdCnt_>, <??TestObject>, <_>, $$sz1
;      ??DbgTraceMtdTicks CatStr <MtdTck_>, <??TestObject>, <_>, $$sz1
;
;      %ifdef ??DbgTraceMtdCount
;        %DbgShowTraceVar @CatStr(<??TestObject>, <.>, %$$sz1), \
;                         ??DbgTraceMtdCount, ??DbgTraceMtdTicks, Dest
;      else                                                ;;It is an abstract method!
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                            DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                            DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;;        %echo @CatStr(OName, <_VtlMethod_Proc_>, %$$ACount)
;        invoke DbgOutTextA, $OfsCStrA("unable to trace this method."), \
;                            DBG_COLOR_WARNING, DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;      endif
;    endm
;
;    ;; --------- Static methods ---------
;    $$ACount = 0
;    repeat @CatStr(<??TestObject>, <_StcMtdCount>)
;      $$ACount = $$ACount + 1
;      $$sz1 CatStr <??TestObject>, <_StcMethod_Name_>, %$$ACount
;
;      ??DbgTraceMtdCount CatStr <MtdCnt_>, <??TestObject>, <_>, $$sz1
;      ??DbgTraceMtdTicks CatStr <MtdTck_>, <??TestObject>, <_>, $$sz1
;
;      %ifdef ??DbgTraceMtdCount
;        %ifidn <$$sz1>, <WndProc>
;          ;;WndProc can't be traced due to pSelf is set after the prologue!
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                             DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                             DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;          invoke DbgOutTextA, $OfsCStrA("unable to trace this method."), \
;                              DBG_COLOR_WARNING, DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;        else
;          %DbgShowTraceVar @CatStr(<??TestObject>, <.>, %$$sz1), \
;                           ??DbgTraceMtdCount, ??DbgTraceMtdTicks, Dest
;        endif
;      else                                                ;;It is an abstract method!
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                            DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;        %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                            DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;;        %echo @CatStr(OName, <_VtlMethod_Proc_>, %$$ACount)
;        invoke DbgOutTextA, $OfsCStrA("Unable to trace this method (abstract, precompiled, etc.)."), \
;                            DBG_COLOR_WARNING, DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;      endif
;    endm
;
;    ;; --------- Overwritten methods ---------
;    $$ACount = 0
;    repeat @CatStr(<??TestObject>, <_OMCount>)
;      $$ACount = $$ACount + 1
;      $$sz1 CatStr <??TestObject>, <_OvrMtd_Name_>, %$$ACount
;
;      ??DbgTraceMtdCount CatStr <MtdCnt_>, <??TestObject>, <_>, $$sz1
;      ??DbgTraceMtdTicks CatStr <MtdTck_>, <??TestObject>, <_>, $$sz1
;
;      %ifdef ??DbgTraceMtdCount
;        %ifidn <$$sz1>, <WndProc>
;          ;;WndProc can't be traced due to pSelf is stablished after the prologue!
;          %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!"  >, ??TestObject, <.>, <!">)), \
;                              DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;          %invoke DbgOutTextA, $OfsCStrA(@CatStr(<!">, %$$sz1, <: !">)), \
;                              DBG_COLOR_OBJECT, DBG_EFFECT_NORMAL, Dest
;          invoke DbgOutTextA, $OfsCStrA("unable to trace this method."), \
;                              DBG_COLOR_WARNING, DBG_EFFECT_ITALIC or DBG_EFFECT_NEWLINE, Dest
;        else
;          %DbgShowTraceVar @CatStr(<??TestObject>, <.>, %$$sz1), \
;                           ??DbgTraceMtdCount, ??DbgTraceMtdTicks, Dest
;        endif
;      endif
;    endm
;  endm
;endm
;
;DbgShowTraceVar macro MName:req, Count:req, Ticks:req, Dest
;  mov xax, @SizeStr(MName) + 1                          ;;Include ZTC
;  MemAlloc xax
;  push xax
;  push xax
;  FillStringA [xax], &MName
;  pop xcx
;  invoke DbgShowTraceMethod, xcx, Count, offset(Ticks), Dest
;  pop xax
;  MemFree xax
;endm
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgAttach
; Purpose:    Break execution and attaches the system debugger. If already loaded, nothing is done.
; Arguments:  None.

DbgAttach macro
  if DEBUGGING
    DbgSaveContext
    .if $invoke(IsDebuggerPresent) == FALSE
      @CatStr(<int >, <3>)
    .endif
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgBreak
; Purpose:    Break execution.
; Arguments:  None.

DbgBreak macro
  if DEBUGGING
    @CatStr(<int >, <3>)                                ;;Written this way to disable int3 search
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgCloseAll
; Purpose:    Close all child windows of the Debug window.
; Arguments:  None.

DbgCloseAll macro
  if DEBUGGING
    DbgSaveContext
    invoke DbgOutCmd, DBG_CMD_CLOSE_ALL, NULL
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgCloseTxt
; Purpose:    Close specific text child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgCloseTxt macro Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    invoke DbgOutCmd, DBG_CMD_CLOSE_TXT, ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgCloseBmp
; Purpose:    Close specific bitmap child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgCloseBmp macro Dest
  if DEBUGGING
    ifidn DBG_DEVICE, <WND>
      DbgSaveContext
      DbgSetDestWnd Dest
      invoke DbgOutCmd, DBG_CMD_CLOSE_BMP, ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgClearAll
; Purpose:    Clear the content of all child windows of the Debug window.
; Arguments:  None.

DbgClearAll macro
  if DEBUGGING
    DbgSaveContext
    invoke DbgOutCmd, DBG_CMD_CLEAR_ALL, NULL
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgClearTxt
; Purpose:    Clear the content of a specific text child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgClearTxt macro Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    invoke DbgOutCmd, DBG_CMD_CLEAR_TXT, ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DbgClearBmp
; Purpose:    Clear the content of a specific bitmap child window of the Debug window.
; Arguments:  Arg1: Target Debug Window name.

DbgClearBmp macro Dest
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd Dest
    invoke DbgOutCmd, DBG_CMD_CLEAR_BMP, ??DbgDstWnd
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Fix
; Purpose:    Reminder text echoed at compile time.
; Arguments:  Arg1: (optional) Text.

Fix macro Txt:=<Fix this later>
% echo @CatStr(<Fix: >, %@FileCur, < (>, %@Line, <) - >, <&Txt>)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ASSERT
; Purpose:    Display a message if an argument value is FALSE.
; Arguments:  Arg1: Value.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.
; Note:       ! acts as escape character, use !!= as unequality comparison.

ASSERT macro Expression:req, InfoText, Dest
  if DEBUGGING
    pushcontext assumes
    pushfx                                              ;;Save CPU flags
    pushax
    .if Expression                                      ;Evaluate expression
      mov ebx, TRUE
    .else
      xor ebx, ebx
    .endif
    DbgSetDestWnd Dest
    cld                                                 ;;Reset direction flag for API calling!
    mov xdi, xsp                                        ;;Save current esp value in xdi
    and xsp, 0FFFFFFFFFFFFFFF0h                         ;;Align stack on a 16 byte boundary
    sub xsp, 20h
    invoke EnterCriticalSection, offset(DbgCritSect)    ;;This call don't change GetLastError
    .if ebx == FALSE
      invoke DbgOutTextA, $OfsCStrA("Assertion failed"), \
                          DBG_COLOR_WARNING, DBG_EFFECT_BOLD, ??DbgDstWnd
      DbgShowTxtInfo InfoText, ??DbgDstWnd
      DbgShowSrcInfo ??DbgDstWnd
    .endif
    invoke LeaveCriticalSection, offset(DbgCritSect)
    mov xsp, xdi                                        ;;Restore rsp
    popax                                               ;;Restore CPU registers
    popfx                                               ;;Direction flag is restored here too
    popcontext assumes
  endif
endm


; ==================================================================================================
;   ResGuard macros
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ResGuard_Show
; Purpose:    Show the result of ResGuard system activity.
; Arguments:  None.

ResGuard_Show macro
  if DEBUGGING and RESGUARD_LOADED
    DbgSaveContext
    invoke DbgOutTextA, $OfsCStrA("Report  "), \
                        DBG_COLOR_TEXT, DBG_EFFECT_BOLD, offset(szLeakReport)
    DbgShowSrcInfo offset(szLeakReport)
    invoke ResGuardShow
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ResGuard_Start
; Purpose:    Start activity of the ResGuard system.
; Arguments:  None.

ResGuard_Start macro
  if DEBUGGING and RESGUARD_LOADED
    DbgSaveContext
    invoke DbgOutTextA, $OfsCStrA("Started "), \
                        DBG_COLOR_TEXT, DBG_EFFECT_BOLD, offset(szLeakReport)
    DbgShowSrcInfo offset(szLeakReport)
    invoke ResGuardStart
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ResGuard_Stop
; Purpose:    Stop activity of the ResGuard system.
; Arguments:  None.

ResGuard_Stop macro
  if DEBUGGING and RESGUARD_LOADED
    DbgSaveContext
    invoke DbgOutTextA, $OfsCStrA("Stopped "), \
                        DBG_COLOR_TEXT, DBG_EFFECT_BOLD, offset(szLeakReport)
    DbgShowSrcInfo offset(szLeakReport)
    invoke ResGuardStop
    DbgLoadContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgComponent
; Purpose:    Output Componet information on the debug device.
; Arguments:  Arg1: GUID.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgComponent macro Var:req, InfoText, Dest
  if DEBUGGING
    ??DbgDataSize = type(Var)
    if (??DbgDataSize ne @WordSize) and (??DbgDataSize ne sizeof(GUID))  ;??!!
      .err <DbgComponent - wrong argument.>
    else
      DbgSaveContext TRUE, Var
      DbgSetDestWnd Dest
      invoke DbgOutComponent, ??VarRBX, DBG_COLOR_OBJECT, ??DbgDstWnd
      DbgShowTxtInfo InfoText, ??DbgDstWnd
      DbgShowSrcInfo ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgInterface
; Purpose:    Output Interface information on the debug device.
; Arguments:  Arg1: IID.
;             Arg2: Additional information.
;             Arg3: Optional destination Window name.

DbgInterface macro Var:req, InfoText, Dest
  if DEBUGGING
    ??DbgDataSize = type(Var)
    if (??DbgDataSize ne @WordSize) and (??DbgDataSize ne sizeof(GUID))
      .err <DbgInterface - wrong argument.>
    else
      DbgSaveContext TRUE, Var
      DbgSetDestWnd Dest
      invoke DbgOutInterface, ??VarRBX, DBG_COLOR_INTERFACE, ??DbgDstWnd
      DbgShowTxtInfo InfoText, ??DbgDstWnd
      DbgShowSrcInfo ??DbgDstWnd
      DbgLoadContext
    endif
  endif
endm
