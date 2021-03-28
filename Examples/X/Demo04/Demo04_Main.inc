; ==================================================================================================
; Title:      Demo04_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 4.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

CStr szDemoApp04, "DemoApp04"


Object DemoApp04, MySdiAppID, SdiApp                    ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init
  StaticMethod      Startup

  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT
  
if TARGET_BITNESS eq 64
  Embed   QCont,  QContainer
endif
  Embed   DCont,  DContainer
  Embed   WCont,  WContainer
  Embed   BCont,  BContainer
  Embed   XCont,  XContainer

ObjectEnd


.code
; ==================================================================================================
;    DemoApp04 implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp04.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method DemoApp04.Done, uses xsi
  SetObject xsi
if TARGET_BITNESS eq 64
  OCall [xsi].QCont::QContainer.Done
endif
  OCall [xsi].DCont::DContainer.Done
  OCall [xsi].WCont::WContainer.Done
  OCall [xsi].BCont::BContainer.Done
  OCall [xsi].XCont::XContainer.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp04.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method DemoApp04.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 500                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height
  
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szDemoApp04, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary

if TARGET_BITNESS eq 64
  OCall [xsi].QCont::QContainer.Init, xsi
  DbgHex xax
endif
  OCall [xsi].DCont::DContainer.Init, xsi
  DbgHex xax
  OCall [xsi].WCont::WContainer.Init, xsi
  DbgHex xax
  OCall [xsi].BCont::BContainer.Init, xsi
  DbgHex xax
  OCall [xsi].XCont::XContainer.Init, xsi
  DbgHex xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp04.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoApp04.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout)

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    invoke LoadIcon, hInstance, offset szIcoName
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, xax, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp04.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoApp04.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION
  .if eax == IDNO
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp04.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoApp04.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp04.Startup
; Purpose:    Register the DemoApp04 window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method DemoApp04.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(SdiApp.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), r8
  c2m WC.lpszClassName, offset szDemoApp04, r8
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
