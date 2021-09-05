; ==================================================================================================
; Title:      Demo07_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 7.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


CLSSTYLE    equ  CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW or \
                 CS_DBLCLKS

CHILDSTYLE  equ  CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_HREDRAW or CS_VREDRAW or \
                 CS_DBLCLKS

TBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

.const
ToolbarFile DEF_TOOLBAR {IDC_TOOLBARFILE, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, $OfsTStr("File operations"), 0, 0, 0, 0, 2}
  TBBUTTON {IDB_FILE_NEW,   IDM_FILE_NEW,   TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("New")}
  TBBUTTON {IDB_FILE_CLOSE, IDM_FILE_CLOSE, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Close")}

ToolbarWindow DEF_TOOLBAR {IDC_TOOLBARWINDOW, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, $OfsTStr("Window operations"), 0, 0, 0, 0, 6}
  TBBUTTON {IDB_WINDOW_CASCADE,  IDM_WINDOW_CASCADE,  TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Cascade")}
  TBBUTTON {IDB_WINDOW_TILE_HOR, IDM_WINDOW_TILE_HOR, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Tile horizontal")}
  TBBUTTON {IDB_WINDOW_TILE_VER, IDM_WINDOW_TILE_VER, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Tile vertical")}
  TBBUTTON {IDB_WINDOW_ARRANGE,  IDM_WINDOW_ARRANGE,  TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Arrange")}
  TBBUTTON {IDB_WINDOW_ARRANGE,  -1                ,  TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_WINDOW_CLOSEALL, IDM_WINDOW_CLOSEALL, TBSTATE_ENABLED, TBSTYLE_BUTTON,, 0, $OfsTStr("Close all")}

SBSTYLE     equ    WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SBSTYLE, 0, 4}
  DEF_STATUSBAR_PART {220, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL} ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}

CloseEnumProc    proto :HWND, :LPARAM

CStr szDemoApp07,   "DemoApp07"                         ;Used by Startup and Shutdown
CStr szDemoChild07, "DemoChild07"                       ;Used by Startup and Shutdown

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object DemoChild07, , MdiChildWnd                       ;MDI child window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, PSTRING  ;-> Owner, -> Title
  RedefineMethod    OnGetMinMaxInfo,    WPARAM, LPARAM
  StaticMethod      Startup

  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    pPlotXY,            $ObjPtr(PlotXY),    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object MyClientWnd, MyClientWndID, MdiClientWnd         ;MDI client window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER         ;-> Owner

  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    hBGBrush,           HBRUSH,     0   ;Background brush
  DefineVariable    dChildCount,        DWORD,      0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object DemoApp07, , MdiApp                              ;MDI application.
  RedefineMethod    Done
  VirtualMethod     EnableActions,      DWORD           ;TRUE/FALSE
  RedefineMethod    Init
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      StatusbarHelp,      POINTER         ;-> Help string
  StaticMethod      Startup

  VirtualEvent      OnClose,            WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnKeyUp,            WM_KEYUP

  DefineVariable    pRebar,             $ObjPtr(Rebar),            NULL
  DefineVariable    pStatusbar,         $ObjPtr(Statusbar),        NULL
  DefineVariable    pToolbarFile,       $ObjPtr(Toolbar),          NULL
  DefineVariable    pToolbarWindow,     $ObjPtr(Toolbar),          NULL
  DefineVariable    pIconImageList,     $ObjPtr(MaskedImageList),  NULL
  DefineVariable    pXMenu,             $ObjPtr(XMenu),            NULL

  DefineVariable    hMenuInit,          HMENU,      0
  DefineVariable    hMenuChild,         HMENU,      0
  DefineVariable    hMenuChildWnd,      HMENU,      0
  DefineVariable    dChildNumber,       DWORD,      0
  DefineVariable    dLanguage,          DWORD,      IDLANG_ENGLISH
ObjectEnd



; ==================================================================================================
;    DemoApp07 implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method DemoApp07.Done, uses xsi
  SetObject xsi
  Destroy [xsi].pRebar
  Destroy [xsi].pStatusbar
  Destroy [xsi].pToolbarFile
  Destroy [xsi].pToolbarWindow
  Destroy [xsi].pIconImageList
  Destroy [xsi].pXMenu
  Destroy [xsi].pClientWnd
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.EnableActions
; Purpose:    Enable or disable MDI child actions.
; Arguments:  Enable TRUE/FALSE.
; Return:     Nothing.

Method DemoApp07.EnableActions, uses xsi, dAction:DWORD
  SetObject xsi
  OCall [xsi].pToolbarFile::Toolbar.BtnEnable, IDM_FILE_CLOSE, dAction

  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_CASCADE,  dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_HOR, dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_TILE_VER, dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_ARRANGE,  dAction
  OCall [xsi].pToolbarWindow::Toolbar.BtnEnable, IDM_WINDOW_CLOSEALL, dAction
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    DemoApp07.Init
; Purpose:   Initialize the SDI application object.
; Arguments: None.
; Return:    Nothing.

Method DemoApp07.Init, uses xbx xdi xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init

  ;Startup
  mov [xsi].pCommandLine, $invoke(GetCommandLine)
  invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES  ;Rebar + Statusbar

  ;Load application & menu icons
  mov xbx, $New(MaskedImageList)
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  mov [xsi].pIconImageList, xbx
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP_CHILD")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_NEW")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_CLOSE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_EXIT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CASCADE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_HOR")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_VER")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ARRANGE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CLOSEALL")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_HELP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")

  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("MDIACCEL"))

  ;Obtain handles for possible menus and submenus
  mov [xsi].hMenuInit, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUINIT"))

  mov [xsi].hMenuChild, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUCHILD"))
  mov [xsi].hMenuChildWnd, $invoke(GetSubMenu, [xsi].hMenuChild, 1)

  ;Create the MDI Frame window
  mov dWndWidth, 600
  mov dWndHeight, 450
  mov dWndPosX, $32($invoke(CenterForm, dWndWidth, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWndPosY, $32($invoke(CenterForm, dWndHeight, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
         offset szDemoApp07, offset szAppTitle, WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
         dWndPosX, dWndPosY, dWndWidth, dWndHeight, NULL, [xsi].hMenuInit, hInstance, pSelf

  .if xax != 0
    ;Create Client window (subclass MDICLIENT)
    mov [xsi].pClientWnd, $New(MyClientWnd)
    OCall xax::MyClientWnd.Init, xsi

    ;Create XMenu
    mov [xsi].pXMenu, $New(XMenu)
    mov xdi, [xsi].pClientWnd
    OCall [xsi].pXMenu::XMenu.Init, xsi, [xsi].hWnd, [xdi].$Obj(MyClientWnd).hWnd, \
                                    [xsi].hMenuChildWnd, xbx, \
                                    $MethodAddr(DemoApp07.StatusbarHelp), IDLANG_ENGLISH
    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
    invoke UpdateWindow, [xsi].hWnd
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.OnClose
; Purpose:    Event procedure for WM_CLOSE and WM_QUERYENDSESSION message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoApp07.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dMsg:DWORD

  SetObject xsi
  mov dMsg, eax
  mov xbx, [xsi].pClientWnd
  .if [xbx].$Obj(MyClientWnd).dChildCount == 0    ;Ask only if a child window is open
    invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(MyClientWnd).hWnd, dMsg, wParam, lParam
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                       MB_YESNO + MB_ICONQUESTION
    .if eax == IDNO
      xor eax, eax
    .else
      invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(MyClientWnd).hWnd, dMsg, wParam, lParam
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoApp07.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hChildWnd:HWND, Dlg:$Obj(DialogAbout)
  local cBuffer[MAX_PATH]:CHR, cNumber[20]:CHR

  SetObject xsi
  mov xax, wParam
  mov xbx, [xsi].pClientWnd
  .if ax == IDM_FILE_NEW                              ;Create a child window
    inc [xsi].dChildNumber
    invoke MemClone, addr cBuffer, $OfsCStr("Child "), 7*sizeof CHR
    invoke dword2dec, addr cNumber, [xsi].dChildNumber
    invoke StrLRTrim, addr cNumber, addr cNumber
    invoke StrCCat, addr cBuffer, addr cNumber, lengthof cBuffer
    New DemoChild07
    mov xcx, xax 
    OCall xcx::DemoChild07.Init, xbx, addr cBuffer
    xor eax, eax

  .elseif ax == IDM_HELP_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .elseif ax == IDM_HELP_ABOUT
    New Dlg::DialogAbout
    invoke LoadIcon, hInstance, $OfsCStr("ICON_APP")
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, xax, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    xor eax, eax

  .elseif (ax == IDM_FILE_CLOSE) || (ax == SC_CLOSE)  ;Close the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, hChildWnd, WM_CLOSE, 0, 0

  .elseif ax == SC_RESTORE                            ;Restore the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIRESTORE, hChildWnd, 0

  .elseif ax == SC_MINIMIZE                           ;Minimize the active window
    mov hChildWnd, $invoke(SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0)
    invoke ShowWindow, xax, SW_MINIMIZE
    xor eax, eax

  .elseif ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0

  ;Messages for arranging windows
  .elseif ax == IDM_WINDOW_TILE_HOR
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDITILE, MDITILE_HORIZONTAL, 0
  .elseif ax == IDM_WINDOW_TILE_VER
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDITILE, MDITILE_VERTICAL, 0
  .elseif ax == IDM_WINDOW_CASCADE
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDICASCADE, 0, 0
  .elseif ax == IDM_WINDOW_ARRANGE
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIICONARRANGE, 0, 0
  .elseif ax == IDM_WINDOW_CLOSEALL                   ;Attempt to close all windows
    invoke EnumChildWindows, [xbx].$Obj(MyClientWnd).hWnd, addr CloseEnumProc, \
                             [xbx].$Obj(MyClientWnd).hWnd
    xor eax, eax

  ;Pass to active child
  .else
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, otherwise -1 to abort.

Method DemoApp07.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  mov [xsi].pStatusbar, $New(Statusbar)
  OCall xax::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  mov [xsi].pRebar, $New(Rebar)
  OCall xax::Rebar.Init, xsi, [xsi].hWnd

  mov [xsi].pToolbarWindow, $New(Toolbar)
  OCall [xsi].pToolbarWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
                                            [xsi].pIconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].pToolbarWindow::Toolbar.GetHeight))
  OCall [xsi].pToolbarWindow::Toolbar.GetWidth
  mov xdx, [xsi].pToolbarWindow
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, eax, ebx

  mov [xsi].pToolbarFile, $New(Toolbar)
  OCall [xsi].pToolbarFile::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
                                          [xsi].pIconImageList, NULL, NULL
  mov ebx, $32($OCall([xsi].pToolbarFile::Toolbar.GetHeight))
  OCall [xsi].pToolbarFile::Toolbar.GetWidth
  mov xdx, [xsi].pToolbarFile
  OCall [xsi].pRebar::Rebar.InsertBand, [xdx].$Obj(Toolbar).hWnd, eax, ebx

  OCall xsi.EnableActions, FALSE
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DemoApp07.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DestroyMenu, [xsi].hMenuInit
  invoke DestroyMenu, [xsi].hMenuChild
  invoke DestroyAcceleratorTable, [xsi].hAccelerators
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.OnKeyUp
; Purpose:    Event procedure for WM_KEYUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoApp07.OnKeyUp, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xbx, [xsi].pClientWnd
  .if wParam == VK_F6
    invoke SendMessage, [xbx].$Obj(MyClientWnd).hWnd ,WM_MDINEXT, NULL, 0
  .endif
  invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(MyClientWnd).hWnd, WM_KEYUP, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoApp07.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dHeight:DWORD, dWidth:DWORD, dTop:DWORD
  local SbRect:RECT, RbRect:RECT, CRect:RECT

  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke GetClientRect, [xsi].hWnd, addr CRect
    mrm dHeight, CRect.bottom, eax
    mrm dWidth, CRect.right, ecx

    mov xbx, [xsi].pRebar
    invoke GetWindowRect, [xbx].$Obj(Rebar).hWnd, addr RbRect
    mov eax, RbRect.bottom
    sub eax, RbRect.top
    mov dTop, eax
    invoke MoveWindow, [xbx].$Obj(Rebar).hWnd, 0, 0, dWidth, eax, TRUE

    mov xbx, [xsi].pStatusbar
    invoke GetWindowRect, [xbx].$Obj(Statusbar).hWnd, addr SbRect
    mov eax, SbRect.bottom
    sub eax, SbRect.top
    sub dHeight, eax
    invoke MoveWindow, [xbx].$Obj(Statusbar).hWnd, 0, dHeight, dWidth, eax, TRUE

    mov xbx, [xsi].pClientWnd
    .if xbx != NULL
      mov ecx, dTop
      sub dHeight, ecx
      invoke InvalidateRect, [xbx].$Obj(MyClientWnd).hWnd, NULL, FALSE
      invoke MoveWindow, [xbx].$Obj(MyClientWnd).hWnd, 0, dTop, dWidth, dHeight, TRUE
    .endif
  .endif

  xor eax, eax                                          ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CloseEnumProc (Callback)
; Purpose:    Close all open child windows.
; Arguments:  Arg1: Child window handle.
;             Arg2: Parameter passed to the enumeration procedure.
; Return:     eax = Exit code passed to PostQuitMessage.

CloseEnumProc proc hWnd:HWND, lParam:LPARAM
  invoke GetParent, hWnd
  .if xax == lParam
    invoke SendMessage, hWnd, WM_CLOSE, 0, 0
  .endif
  mov eax, TRUE                                         ;TRUE => next window
  ret
CloseEnumProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.StatusbarHelp
; Purpose:    Display a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method DemoApp07.StatusbarHelp,, pHelpStr:POINTER
  SetObject xax
  OCall [xax].pStatusbar::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoApp07.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method DemoApp07.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(DemoApp07.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szDemoApp07, xdx
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd



; ==================================================================================================
;    MyClientWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyClientWnd.Done
; Purpose:    Finalize the MyClientWnd object.
; Arguments:  None.
; Return:     Nothing.

Method MyClientWnd.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBGBrush
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyClientWnd.Init
; Purpose:    Initialize the MdiClientWnd object.
; Arguments:  Arg1 -> Owner object.
; Return:     Nothing.

Method MyClientWnd.Init, uses xsi, pOwner:POINTER
  local hBmp:HBITMAP
  
  SetObject xsi
  ACall xsi.Init, pOwner
  mov hBmp, $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND"))
  mov [xsi].hBGBrush, $invoke(CreatePatternBrush, hBmp)
  invoke DeleteObject, hBmp
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MyClientWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method MyClientWnd.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rct:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke FillRect, PS.hdc, addr Rct, [xsi].hBGBrush
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
  invoke CallWindowProc, [xsi].$Obj(MyClientWnd).pPrevWndProc, \
                         [xsi].$Obj(MyClientWnd).hWnd, \
                         WM_PAINT, wParam, lParam
MethodEnd



; ==================================================================================================
;    DemoChild07 implementation
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoChild07.Done
; Purpose:    Finalize the DemoChild07 object.
; Arguments:  None.
; Return:     Nothing.

Method DemoChild07.Done, uses xbx xdi xsi
  SetObject xsi
  mov xdi, [xsi].pOwner
  dec [xdi].$Obj(MyClientWnd).dChildCount

  .if ZERO?
    mov xbx, [xdi].$Obj(MyClientWnd).pOwner
    OCall xbx::DemoApp07.EnableActions, FALSE
    invoke SendMessage, [xdi].$Obj(MyClientWnd).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(DemoApp07).hMenuInit, NULL
    invoke DrawMenuBar, [xbx].$Obj(DemoApp07).hWnd      ;Redraw the new menu bar
  .endif

  Destroy [xsi].pPlotXY
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoChild07.Init
; Purpose:    Initialize the DemoChild07 object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Title string.
; Return:     Nothing.

Method DemoChild07.Init, uses xbx xdi xsi, pOwner:POINTER, pTitle:PSTRING
  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc

  mov xdi, pOwner
  inc [xdi].$Obj(MyClientWnd).dChildCount

  invoke CreateMDIWindow, offset szDemoChild07, pTitle, \
                          0 , CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(MyClientWnd).hWnd, hInstance, pSelf
  mov xbx, [xdi].$Obj(MyClientWnd).pOwner
  .if xax != NULL
    ;Manage the main Menu
    .if [xdi].$Obj(MyClientWnd).dChildCount == 1        ;First child window ?
      OCall xbx::DemoApp07.EnableActions, TRUE
      invoke SendMessage, [xdi].$Obj(MyClientWnd).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(DemoApp07).hMenuChild, \
                          [xbx].$Obj(DemoApp07).hMenuChildWnd
      invoke DrawMenuBar, [xbx].$Obj(DemoApp07).hWnd    ;Redraw the new menu bar
    .endif

    invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  .else
    invoke MessageBox, [xbx].$Obj(DemoApp07).hWnd, \
                       $OfsCStr("Window creation error"), offset szError, MB_OK or MB_ICONERROR
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoChild07.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoChild07.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local DataXY:PLOTXY_DATA, dDataBuff:DWORD
  local pCollDataX:POINTER, pCollDataY:POINTER
  local pDataBufferX:POINTER, pDataBufferY:POINTER

  SetObject xsi

  ;Create PlotXY instance
  mov [xsi].pPlotXY, $New(PlotXY)

  ;Create PlotXY data
  ;X's data
  mov pCollDataX, $New(Collection)
  OCall xax::Collection.Init, xsi, 3, 1, COL_MAX_CAPACITY
  ;X(1)
  mov pDataBufferX, $New(DataBufferXY)
  mov xbx, xax
  OCall xbx::DataBufferXY.Init, xsi, DATAPOINTS, sizeof(REAL4)
  mov [xbx].$Obj(DataBufferXY).pDesc, $invoke(StrNew, $OfsCStr("Time"))
  mov [xbx].$Obj(DataBufferXY).pUnit, $invoke(StrNew, $OfsCStr("sec."))
  xor ebx, ebx
  .while ebx < DATAPOINTS
    mov dDataBuff, ebx
    fild dDataBuff
    fstp REAL4 ptr dDataBuff
    OCall pDataBufferX::DataBufferXY.ItemAt, ebx
    .if xax != NULL
      mrm REAL4 ptr [xax], dDataBuff, edx
    .endif
    inc ebx
  .endw
  OCall pDataBufferX::DataBufferXY.Scan, 0, DATAPOINTS - 1
  OCall pCollDataX::Collection.Insert, pDataBufferX
  ;X(2)
  mov pDataBufferX, $New(DataBufferXY)
  OCall xax::DataBufferXY.Init, xsi, DATAPOINTS-200, sizeof(REAL4)
  xor ebx, ebx
  .while ebx < DATAPOINTS - 200
    mov dDataBuff, ebx
    fild dDataBuff
    fstp REAL4 ptr dDataBuff
    OCall pDataBufferX::DataBufferXY.ItemAt, ebx
    .if xax != NULL
      mrm REAL4 ptr [xax], dDataBuff, edx
    .endif
    inc ebx
  .endw
  OCall pDataBufferX::DataBufferXY.Scan, 0, DATAPOINTS - 200 - 1
  OCall pCollDataX::Collection.Insert, pDataBufferX
  ;X(3)
  mov pDataBufferX, $New(DataBufferXY)
  OCall xax::DataBufferXY.Init, xsi, DATAPOINTS - 400, sizeof(REAL4)
  xor ebx, ebx
  .while ebx < DATAPOINTS - 400
    mov dDataBuff, ebx
    add dDataBuff, 300
    fild dDataBuff
    fstp REAL4 ptr dDataBuff
    OCall pDataBufferX::DataBufferXY.ItemAt, ebx
    .if eax != NULL
      mrm REAL4 ptr [xax], dDataBuff, edx
    .endif
    inc ebx
  .endw
  OCall pDataBufferX::DataBufferXY.Scan, 0, DATAPOINTS - 400 - 1
  OCall pCollDataX::Collection.Insert, pDataBufferX

  ;Y's data
  mov pCollDataY, $New(Collection)
  OCall xax::Collection.Init, xsi, 3, 1, COL_MAX_CAPACITY
  ;Y(1)
  mov pDataBufferY, $New(DataBufferXY)
  mov xbx, xax
  OCall xbx::DataBufferXY.Init, xsi, DATAPOINTS, sizeof(REAL4)
  mov [xbx].$Obj(DataBufferXY).pDesc, $invoke(StrNew, $OfsCStr("Output"))
  mov [xbx].$Obj(DataBufferXY).pUnit, $invoke(StrNew, $OfsCStr("Volt"))
  mov [xbx].$Obj(DataBufferXY).dLineColor, $RGB(255, 000, 000)    ;Plot line color
  xor ebx, ebx
  fld $CReal4(0.12566370614359)                      ;2*Pi/50
  fldz
  fldz
  .while ebx < DATAPOINTS
    fsin
    fstp REAL4 ptr dDataBuff
    fadd st(0), st(1)
    fld st(0)
    OCall pDataBufferY::DataBufferXY.ItemAt, ebx
    .if xax != NULL
      mrm REAL4 ptr [xax], dDataBuff, edx
    .endif
    inc ebx
  .endw
  fUnload 3                                           ;Unload FPU stack
  OCall pDataBufferY::DataBufferXY.Scan, 0, DATAPOINTS - 1
  OCall pCollDataY::Collection.Insert, pDataBufferY
  ;Y(2)
  mov pDataBufferY, $New(DataBufferXY)
  mov xbx, xax
  OCall xax::DataBufferXY.Init, xsi, DATAPOINTS - 200, sizeof(REAL4)
  mov [xbx].$Obj(DataBufferXY).dLineColor, $RGB(000, 255, 000)    ;Plot line color
  mov [xbx].$Obj(DataBufferXY).dLineWidth, 3
  xor ebx, ebx
  fld $CReal4(0.00566370614359)
  fldz
  fldz
  .while ebx < DATAPOINTS - 200
    fsqrt
    fstp REAL4 ptr dDataBuff
    fadd st(0), st(1)
    fld st(0)
    OCall pDataBufferY::DataBufferXY.ItemAt, ebx
    .if xax != NULL
      mrm REAL4 ptr [xax], dDataBuff, edx
    .endif
    inc ebx
  .endw
  fUnload 3                                           ;Unload FPU stack
  OCall pDataBufferY::DataBufferXY.Scan, 0, DATAPOINTS - 200 - 1
  OCall pCollDataY::Collection.Insert, pDataBufferY
  ;Y(3)
  mov pDataBufferY, $New(DataBufferXY)
  mov xbx, xax
  OCall xbx::DataBufferXY.Init, xsi, DATAPOINTS - 400, sizeof(REAL4)
  mov [xbx].$Obj(DataBufferXY).dLineColor, $RGB(000, 000, 255)  ;Plot line color
  mov [xbx].$Obj(DataBufferXY).dLineWidth, 2
  xor ebx, ebx
  fld $CReal4(0.00566370614359)
  fldz
  fldz
  .while ebx < DATAPOINTS - 400
    fsqrt
    fstp REAL4 ptr dDataBuff
    fadd st(0), st(1)
    fld st(0)
    OCall pDataBufferY::DataBufferXY.ItemAt, ebx
    .if eax != NULL
      mrm REAL4 ptr [xax], dDataBuff, edx
    .endif
    inc ebx
  .endw
  fUnload 3                                           ;Unload FPU stack
  OCall pDataBufferY::DataBufferXY.Scan, 0, DATAPOINTS - 400 - 1
  OCall pCollDataY::Collection.Insert, pDataBufferY

  ;Main Data structure
  lea xbx, DataXY
  invoke MemZero, xbx, sizeof DataXY

  mrm [xbx].PLOTXY_DATA.pCollDataX, pCollDataX, xax
  mrm [xbx].PLOTXY_DATA.pCollDataY, pCollDataY, xax

  ;Scale X axis
  lea xbx, DataXY.ScaleX
  mov [xbx].SCALE_BASIC_DATA.bOptions, mask AutoMin or mask AutoMax or \
                                       mask AutoMjrDiv or mask AutoMnrDiv or \
                                       mask ShowGrid
  ;Scale Y axis
  lea xbx, DataXY.ScaleY
  mov [xbx].SCALE_BASIC_DATA.bOptions, mask AutoMin or mask AutoMax or \
                                       mask AutoMjrDiv or mask AutoMnrDiv or \
                                       mask ShowGrid
  ;Colors
  lea xbx, DataXY.Colors
  mov [xbx].COLOR_CONFIG.dGrid,       $RGB(128, 128, 128)    ;Grid color
  mov [xbx].COLOR_CONFIG.dPlotArea,   $RGB(255, 255, 255)    ;Plot area color
  mov [xbx].COLOR_CONFIG.dPlotBorder, $RGB(000, 000, 000)    ;Plot border color
  mov [xbx].COLOR_CONFIG.dBackground, $RGB(220, 220, 220)    ;Background color
  mov [xbx].COLOR_CONFIG.dScales,     $RGB(000, 000, 000)    ;Ticks and scale labels

  OCall [xsi].pPlotXY::PlotXY.Init, xsi, [xsi].hWnd, addr DataXY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoChild07.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DemoChild07.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, ClientRect:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr ClientRect
  OCall [xsi].pPlotXY::PlotXY.Show, PS.hdc, addr ClientRect
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoChild07.OnGetMinMaxInfo
; Purpose:    Event procedure for WM_GETMINMAXINFO message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DemoChild07.OnGetMinMaxInfo, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DefMDIChildProc, [xsi].hWnd, WM_GETMINMAXINFO, wParam, lParam
  mov xcx, lParam
  mov [xcx].MINMAXINFO.ptMinTrackSize.x, 150
  mov [xcx].MINMAXINFO.ptMinTrackSize.y, 120
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DemoChild07.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method DemoChild07.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CHILDSTYLE
  mrm WC.lpfnWndProc, $MethodAddr(DemoChild07.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  mrm WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, 0                               ;No background drawing to avoid flickering
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szDemoChild07, xdx
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP_CHILD"))
  m2z WC.hIconSm
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd
