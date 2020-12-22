; ==================================================================================================
; Title:   SplashDemo.inc
; Author:  G. Friedrich  @ July 2003
; Version: 1.0.0
; Purpose: Demonstration program 2 of ObjAsm32.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szSplashDemo, "SplashDemo"                         ;Creates szSplashDemo string in .const

Object SplashDemo, MySdiAppID, SdiApp                   ;Single Document Interface App.
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT
ObjectEnd                                               ;Ends object definition


.code
; ==================================================================================================
;    SplashDemo implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    SplashDemo.Init
; Purpose:   Initalizes the SDI application object.
; Arguments: None.
; Return:    Nothing.

Method SplashDemo.Init, uses esi
    local dWwd:dword, dWht:dword
    local dWtx:dword, dWty:dword

    SetObject esi
    ACall esi.Init

    mov dWwd, 500                                       ;Default creation width
    mov dWht, 350                                       ;Default creation height
    mov dWtx, $invoke(CenterForm, dWwd, $invoke(GetSystemMetrics, SM_CXSCREEN)) ;Center the form
    mov dWty, $invoke(CenterForm, dWht, $invoke(GetSystemMetrics, SM_CYSCREEN)) ;Center the form

    invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
           offset szSplashDemo, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
           dWtx, dWty, dWwd, dWht, NULL, NULL, hInstance, esi ;Pass the instance pointer

    invoke ShowWindow, [esi].hWnd, SW_SHOWNORMAL        ;Show the window
    invoke UpdateWindow, [esi].hWnd                     ;Update if necessary
    
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    SplashDemo.OnCommand
; Purpose:   Event procedure for WM_COMMAND message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method SplashDemo.OnCommand, uses esi, wParam:dword, lParam:dword
    local cBuffer[MAX_PATH]:CHR, Dlg:DialogAbout

    SetObject esi
    mov eax, wParam
    .if ax == IDM_EXIT
      invoke SendMessage, [esi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
      xor eax, eax

    .elseif ax == IDM_ABOUT
      invoke LoadIcon, hInstance, $OfsCStr("ICON_APP_32")
      New Dlg::DialogAbout.Init, esi, [esi].hWnd, eax, offset szAboutText
      OCall Dlg::DialogAbout.Show
      OCall Dlg::DialogAbout.Done
      xor eax, eax

    .elseif ax == IDM_HELP
      invoke GetEnvironmentVariable, $OfsCStr("OA32_PATH"), addr cBuffer, lengthof cBuffer
      invoke StrLCat, addr cBuffer, $OfsCStr("\Help\ObjAsm32.chm"), lengthof cBuffer
      invoke HtmlHelp, [esi].hWnd, addr cBuffer, HH_DISPLAY_TOPIC, 0
      xor eax, eax

    .else
      invoke DefWindowProc, [esi].hWnd, WM_COMMAND, wParam, lParam

    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    SplashDemo.OnClose
; Purpose:   Event procedure for WM_CLOSE message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method SplashDemo.OnClose, uses esi, wParam:dword, lParam:dword
    SetObject esi
    invoke MessageBox, [esi].hWnd, $OfsCStr("Are you sure ?"), \
                       $OfsCStr("Application exit"), MB_YESNO or MB_ICONQUESTION
    .if eax == IDNO
      xor eax, eax
    .else
      invoke DefWindowProc, [esi].hWnd, WM_CLOSE, wParam, lParam
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    SplashDemo.OnPaint
; Purpose:   Event procedure for WM_PAINT message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    Zero if handled.

Method SplashDemo.OnPaint, uses esi, wParam:dword, lParam:dword
    local PS:PAINTSTRUCT, hDC:Handle, Rct:RECT

    SetObject esi
    mov hDC, $invoke(BeginPaint, [esi].hWnd, addr PS)

    invoke GetClientRect, [esi].hWnd, addr Rct
    invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

    invoke EndPaint, [esi].hWnd, addr PS
    mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    SplashDemo.Startup
; Purpose:   Registers the object class with the OS.
; Arguments: None.
; Return:    Nothing.

Method SplashDemo.Startup
    local WC:WNDCLASSEX

    mov WC.cbSize, sizeof WNDCLASSEX
    mov WC.style, CLSSTYLE
    m2m WC.lpfnWndProc, $MethodAddr(SplashDemo.WndProc), edx
    and WC.cbClsExtra, 0
    and WC.cbWndExtra, 0
    m2m WC.hInstance, hInstance, edx
    invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
    mov WC.hbrBackground, $invoke(CreatePatternBrush, eax)
    mov WC.lpszMenuName, $OfsCStr("MENU_APP")
    mov WC.lpszClassName, offset szSplashDemo
    mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_32"))
    mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
    and WC.hIconSm, 0

    invoke RegisterClassEx, addr WC
MethodEnd
MethodEnd
