; ==================================================================================================
; Title:      CircularActivityIndicator_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Simple Circular Activity Indicator.
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


CLSSTYLE equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW; or CS_DROPSHADOW

CStr szApplication, "Application"                       ;Creates szApplication string in .const


Object Application, MySdiAppID, SdiApp                  ;Single Document Interface App.
  RedefineMethod    Done
  RedefineMethod    Init                                ;Init method redefinition
  StaticMethod      Startup

  VirtualEvent      OnCreate,   WM_CREATE
  VirtualEvent      OnCommand,  WM_COMMAND
  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnPaint,    WM_PAINT

  DefineVariable    pSCAI1,   $ObjPtr(SimpleCircularActivityIndicator),   NULL
  DefineVariable    pSCAI2,   $ObjPtr(SimpleCircularActivityIndicator),   NULL

ObjectEnd                                               ;Ends object definition


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi

;  DbgText "Application.Done"
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init
  mov dWndWidth, 400                                    ;Default creation width
  mov dWndHeight, 350                                   ;Default creation height

  mov dWndPosX, $32($invoke(CenterForm, dWndWidth,  $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset szApplication, offset szAppTitle, WS_OVERLAPPEDWINDOW, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, NULL, hInstance, xsi

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL          ;Show the window
  invoke UpdateWindow, [xsi].hWnd                       ;Update if necessary
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke CreateWindowEx, WS_EX_LAYERED, \
                         offset szCircularActivityIndicatorClass, NULL, WS_VISIBLE or WS_CHILD, \
                         150, 100, 100, 100, [xsi].hWnd, 0, hInstance, NULL
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
    mov [xsi].pSCAI1, xax
    OCall [xsi].pSCAI1::SimpleCircularActivityIndicator.AddPngFromRes, $OfsCStr("SPINNER1")
    OCall [xsi].pSCAI1::SimpleCircularActivityIndicator.Start
  .endif

  invoke CreateWindowEx, WS_EX_LAYERED, \
                         offset szCircularActivityIndicatorClass, NULL, WS_VISIBLE or WS_CHILD, \
                         170, 120, 100, 100, [xsi].hWnd, 0, hInstance, NULL
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
    mov [xsi].pSCAI2, xax
    OCall [xsi].pSCAI2::SimpleCircularActivityIndicator.AddPngFromRes, $OfsCStr("SPINNER2")
    OCall [xsi].pSCAI2::SimpleCircularActivityIndicator.Start
  .endif

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout)

  SetObject xsi
  mov xax, wParam
  .if ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    xor eax, eax

  .elseif ax == IDM_START_1
    .if [xsi].pSCAI1 != NULL
      OCall [xsi].pSCAI1::SimpleCircularActivityIndicator.Start
    .endif

  .elseif ax == IDM_START_2
    .if [xsi].pSCAI2 != NULL
      OCall [xsi].pSCAI2::SimpleCircularActivityIndicator.Start
    .endif

  .elseif ax == IDM_STOP_1
    .if [xsi].pSCAI1 != NULL
      OCall [xsi].pSCAI1::SimpleCircularActivityIndicator.Stop
    .endif

  .elseif ax == IDM_STOP_2
    .if [xsi].pSCAI2 != NULL
      OCall [xsi].pSCAI2::SimpleCircularActivityIndicator.Stop
    .endif

  .elseif ax == IDM_ABOUT
    New Dlg::DialogAbout
    invoke LoadIcon, hInstance, offset szIcoName
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, xax, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    xor eax, eax

  .elseif ax == IDM_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"),\
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
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
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the Application window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(SdiApp.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), rax
  c2m WC.lpszClassName, offset szApplication, rax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd
