; ==================================================================================================
; Title:      Button.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Button objects.
; Notes:      Version C.1.0, November 2017
;               - First release.
; ==================================================================================================


BM_GETCOLOR     equ     WM_USER + 100   ;Used to get the color of the ColorButton object
BM_SETCOLOR     equ     WM_USER + 101   ;Used to set the color of the ColorButton object

ButtonState     record  BS_Unused:2 = 0, \
                        BS_Resource:1 = FALSE, BS_ShowShortCut:1 = FALSE, BS_Disabled:1 = FALSE, \
                        BS_Hovered:1 = FALSE, BS_Focused:1 = FALSE, BS_Pressed:1 = FALSE

DEF_BUTTON struc
  xCtlID    XWORD     ?   ;Contol ID
  dStyle    DWORD     ?   ;Style
  dExStyle  DWORD     ?   ;Extended style
  pTitle    PSTRING   ?   ;-> Window title
  sdPosX    SDWORD    ?   ;X position
  sdPosY    SDWORD    ?   ;Y position
  dWidth    DWORD     ?   ;Width
  dHeight   DWORD     ?   ;Height
DEF_BUTTON ends
PDEF_BUTTON typedef ptr DEF_BUTTON

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   Button
; Purpose:  Implementation of a base object used as ancestor for objects like ColorButton, Hyperlink
;           or IconButton.

Object Button, ButtonID, WinPrimer
  VirtualMethod     Dispatch,       HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  VirtualMethod     InitRes,        HWND
  VirtualAbstract   OnCreate,       WPARAM, LPARAM
  VirtualAbstract   OnDestroy,      WPARAM, LPARAM
  VirtualAbstract   OnPaint,        WPARAM, LPARAM
  VirtualAbstract   WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnEnable,       WM_ENABLE
  VirtualEvent      OnGetDlgCode,   WM_GETDLGCODE
  VirtualEvent      OnKeyDown,      WM_KEYDOWN
  VirtualEvent      OnLButtonDown,  WM_LBUTTONDOWN
  VirtualEvent      OnLButtonUp,    WM_LBUTTONUP
  VirtualEvent      OnMouseMove,    WM_MOUSEMOVE
  VirtualEvent      OnUpdateUIState,WM_UPDATEUISTATE        ;Show underscores (XP)
  VirtualEvent      OnNcDestroy,    WM_NCDESTROY
  VirtualEvent      OnSetFont,      WM_SETFONT
  VirtualEvent      OnGetFont,      WM_GETFONT
  VirtualEvent      OnSetText,      WM_SETTEXT
  VirtualEvent      OnGetText,      WM_GETTEXT
  VirtualEvent      OnSetFocus,     WM_SETFOCUS
  VirtualEvent      OnKillFocus,    WM_KILLFOCUS

  Event             OnCreate,       WM_CREATE
  Event             OnDestroy,      WM_DESTROY
  Event             OnPaint,        WM_PAINT

;  DefineVariable    hBgBrush,       HBRUSH,     0           ;Background brush HANDLE
  DefineVariable    hMemDC,         HDC,        0           ;Memory DC
  DefineVariable    hMemBmp,        HBITMAP,    0           ;Memory DC bitmap
  DefineVariable    hPrevBmp,       HBITMAP,    0           ;Previous hMemDC bitmap
  DefineVariable    dState,         DWORD,      0           ;ButtonState
  DefineVariable    FaceRect,       RECT,       {}          ;Face RECT
  DefineVariable    IconRect,       RECT,       {}          ;Button RECT
  DefineVariable    TextRect,       RECT,       {}          ;Text RECT
  DefineVariable    pTextBuffer,    PSTRING,    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method Button.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.Done
; Purpose:    Finalize the Button object.
; Arguments:  None.
; Return:     Nothing.

Method Button.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pTextBuffer
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.InitRes
; Purpose:    Initialize the Button object from a resource.
; Arguments:  Arg1: Button window handle.
; Return:     Nothing.
; Note:       WM_GETOBJECTINSTANCE may fail if the dialog has not processed WM_INITDIALOG yet.

Method Button.InitRes, uses xsi, hWnd:HWND
  SetObject xsi
  BitSet [xsi].dState, mask BS_Resource
  invoke GetParent, hWnd
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
  .endif
  ACall xsi.Init, xax, hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnEnable
; Purpose:    Event procedure for WM_ENABLE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnEnable, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if wParam == FALSE
    BitSet [xsi].dState, mask BS_Disabled
  .else
    BitClr [xsi].dState, mask BS_Disabled
  .endif
  BitClr [xsi].dState, (mask BS_Hovered or mask BS_Focused or mask BS_Pressed)
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnGetDlgCode
; Purpose:    Event procedure for WM_GETDLGCODE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Value indicating type of control and input type the application processes.

Method Button.OnGetDlgCode, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
  .ifBitSet eax, BS_DEFPUSHBUTTON
     mov eax, DLGC_BUTTON or DLGC_DEFPUSHBUTTON
  .else
     mov eax, DLGC_BUTTON or DLGC_UNDEFPUSHBUTTON
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnGetFont
; Purpose:    Event procedure for WM_GETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Requested font handle.

Method Button.OnGetFont, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke GetStockObject, SYSTEM_FONT                    ;Use a dummy font
  invoke SelectObject, [xsi].hMemDC, xax                ;Select it, returns the searched value
  mov xbx, xax                                          ;Save it on the stack
  invoke SelectObject, [xsi].hMemDC, xax                ;Select it again
  mov xax, xbx                                          ;Return in eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnGetText
; Purpose:    Event procedure for WM_GETTEXT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = The return value is the number of characters copied including zero termnator.

Method Button.OnGetText,, wParam:WPARAM, lParam:LPARAM
  SetObject xdx
  .if (lParam != NULL) && (wParam > 0)
    mov xax, wParam
    dec xax                                             ;Leave place for the ZTC
    invoke StrCCopy, lParam, [xdx].pTextBuffer, eax
    inc edx
    mov eax, edx
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnKeyDown
; Purpose:    Event procedure for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Button.OnKeyDown, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if al == " "                                         ;Space was pressed!
    invoke GetParent, [xsi].hWnd
    mov xbx, xax
    invoke GetWindowLongPtr, [xsi].hWnd, GWL_ID
    invoke SendMessage, xbx, WM_COMMAND, eax, [xsi].hWnd
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnKillFocus
; Purpose:    Event procedure for WM_KILLFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnKillFocus, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  BitClr [xsi].dState, (mask BS_Focused or mask BS_Hovered)
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xsi
  .ifBitClr [xsi].dState, mask BS_Disabled
    PntS2Pnt Pnt, lParam
    .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
      invoke SetFocus, [xsi].hWnd
      BitSet [xsi].dState, (mask BS_Pressed or BS_Focused)
      BitClr [xsi].dState, mask BS_Hovered
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnLButtonUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xsi
  .ifBitClr [xsi].dState, mask BS_Disabled
    invoke ReleaseCapture
    .ifBitSet [xsi].dState, mask BS_Pressed
      BitClr [xsi].dState, (mask BS_Pressed or mask BS_Hovered)
      PntS2Pnt Pnt, lParam
      .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
        invoke GetParent, [xsi].hWnd
        mov xbx, xax
        invoke GetWindowLongPtr, [xsi].hWnd, GWL_ID
        invoke SendMessage, xbx, WM_COMMAND, eax, [xsi].hWnd
      .endif
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xsi
  .ifBitClr [xsi].dState, mask BS_Disabled
    PntS2Pnt Pnt, lParam
    .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
      .ifBitClr [xsi].dState, (mask BS_Pressed or mask BS_Hovered)
        invoke SetCapture, [xsi].hWnd
        BitSet [xsi].dState, mask BS_Hovered
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      .endif
    .else
      .ifBitClr [xsi].dState, mask BS_Pressed
        BitClr [xsi].dState, mask BS_Hovered
        invoke ReleaseCapture
        invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnUpdateUIState
; Purpose:    Event procedure for WM_UPDATEUISTATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnUpdateUIState, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .ifBitSet wParam, BIT01
    BitSet [xsi].dState, mask BS_ShowShortCut
  .else
    BitClr [xsi].dState, mask BS_ShowShortCut
  .endif
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnNcDestroy
; Purpose:    Event procedure for WM_NCDESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnNcDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, GWLP_USERDATA, NULL
  .ifBitSet [xsi].dState, mask BS_Resource
    Destroy xsi
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnSetFont
; Purpose:    Event procedure for WM_SETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnSetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, wParam)
  .if lParam != FALSE
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnSetText
; Purpose:    Event procedure for WM_SETTEXT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE.

Method Button.OnSetText, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov [xsi].pTextBuffer, $invoke(StrNew, lParam)
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Button.OnSetFocus
; Purpose:    Event procedure for WM_SETFOCUS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Button.OnSetFocus, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  BitSet [xsi].dState, mask BS_Focused
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

endif
