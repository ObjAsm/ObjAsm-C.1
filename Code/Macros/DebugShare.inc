; ==================================================================================================
; Title:      DebugShare.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm debug shared definitions.
;             This file provides definitions used by the "application debug system" and DebugCenter.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;Exported symbols defined in Model.inc
externdef dDbgDev:DWORD
externdef dDbgOpt:DWORD
externdef hDbgDev:HANDLE

;Exported symbols defined in Debug.inc
externdef szDbgCtrCmd:CHRA
externdef szDbgSrc:CHRW
externdef szDbgErr:CHRW
externdef szDbgComErr:CHRW

;Exported symbols defined in Debug.inc
externdef szDbgElipsis:CHRA
externdef szDbgInvalid:CHRA
externdef szDbgPoint2:CHRA
externdef szDbgArrow:CHRA
externdef szDbgBracketLeft:CHRA
externdef szDbgBracketRight:CHRA
externdef szDbgColon:CHRA
externdef szDbgComma:CHRA

;Exported symbols defined in DebugShare.inc
externdef szDbgCtrCls:CHRW

;Exported symbols defined in DbgConstants.asm
externdef szDbgInvalidDevPtr:CHRW
externdef szDbgRegKey:CHRW

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DGB_MSG_ID            equ   58ADF9ACh       ;Random number that identifies these debug messages
DBG_MSG_HDR           equ   00
DBG_MSG_CMD           equ   01
DBG_MSG_STR           equ   02
DBG_MSG_BMP           equ   03

DBG_EFFECT_NORMAL     equ   00000000h       ;Regular text
DBG_EFFECT_BOLD       equ   00000001h       ;CFE_BOLD
DBG_EFFECT_ITALIC     equ   00000002h       ;CFE_ITALIC
DBG_EFFECT_UNDERLINE  equ   00000004h       ;CFE_UNDERLINE
DBG_EFFECT_STRIKEOUT  equ   00000008h       ;CFE_STRIKEOUT
DBG_EFFECT_NEWLINE    equ   00000100h

DBG_CHARTYPE_WIDE     equ   80000000h       ;if not set => ANSI (BIT31)

DBG_CMD_CLEAR_TXT     equ   0
DBG_CMD_CLEAR_BMP     equ   1
DBG_CMD_CLEAR_ALL     equ   2
DBG_CMD_CLOSE_TXT     equ   3               ;Currently not implemented!
DBG_CMD_CLOSE_BMP     equ   4               ;Currently not implemented!
DBG_CMD_CLOSE_ALL     equ   5               ;Currently not implemented!
DBG_CMD_SINGLE_LINE   equ   6               ;char 2500 or 2014
DBG_CMD_DOUBLE_LINE   equ   7               ;Char 2550


SMTO_TIMEOUT          equ   5000            ;Timeout of a WM_COPYDATA message


IDM_DEBUG_CENTER_RESTORE  equ   0f6cah      ;Random number


; ——————————————————————————————————————————————————————————————————————————————————————————————————

DBG_HEADER_INFO struc 1
  bBlockID    BYTE    DBG_MSG_HDR
  bInfo       BYTE    ?                     ;Not used
  dBlockLen   DWORD   ?                     ;Size of this structure + size of the source WIDE string
DBG_HEADER_INFO ends
;Source WIDE string & ZTC follow this structure

DBG_CMD_INFO struc 1
  bBlockID    BYTE    DBG_MSG_CMD
  bInfo       BYTE    ?                     ;Used for single byte commands
  dBlockLen   DWORD   ?                     ;Size of this structure + size of the data (may be zero)
DBG_CMD_INFO ends
;Data bytes may follow this structure

DBG_STR_INFO struc 1
  bBlockID    BYTE    DBG_MSG_STR
  bInfo       BYTE    ?                     ;Not used
  dBlockLen   DWORD   ?                     ;Size of this structure + size of the WIDE string
  dColor      DWORD   ?
  dEffects    DWORD   ?                     ;Text effects & flags
DBG_STR_INFO ends
;WIDE characters & ZTC (WIDE string) follow this structure

DBG_BMP_INFO struc 1
  bBlockID    BYTE    DBG_MSG_BMP
  bInfo       BYTE    ?                     ;Not used
  dBlockLen   DWORD   ?                     ;Size of this structure + size of bitmap data (RGBQUADs)
  BmpHeader   BITMAPINFOHEADER  {}
DBG_BMP_INFO ends
;Bitmap data follow this structure

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DEBUG_CENTER_CLASS  textequ  <"DebugCenter">
DEBUG_CENTER_REGKEY textequ  <"Software\DebugCenter">
