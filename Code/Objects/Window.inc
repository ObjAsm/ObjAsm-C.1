; ==================================================================================================
; Title:      Window.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of Window objects.
; Notes:      Version C.1.2, October 2020
;               - dResizeRequest added to MoveChildWndInfo structure to hide the gripper when the
;                 parent window is maximized.
;               - if the window is minimized, MoveChildWnd is skipped.
;             Version C.1.1, January 2020
;               - Dynamic Layout support added.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;Dynamic Layout:
; Links:
; - https://docs.microsoft.com/en-us/cpp/mfc/dynamic-layout?view=vs-2019
;
; Notes:
; - Make sure that the window has the following window styles set:
;     WS_CAPTION, WS_SIZEBOX, WS_POPUP, WS_THICKFRAME.
; - Avoid control superposition. It leads to ugly glitches and deteriorates the usability
; - To setup a Dynamic Layout, create in writable memory a sequence this structures:
;     DL_HEADER + n * DL_CHILD_INFO
;   where n is the number of controls in the window.
;   The initialization is done calling OnCreateWindow. This method is called by Dialogs
;   automatically.
;   The DL_CHILD_INFO order corresponds to the window tab sequence.
; - Depending on the flags set in the DL_HEADER.dFlags field, additional information must be set.
;     DLF_USE_INISIZE => IniSize.cx_ & IniSize.cy
;     DLF_USE_MINSIZE_X or DLF_USE_MINSIZE_Y => MinSize.cx_ & MinSize.cy
;     DLF_USE_MAXSIZE_X or DLF_USE_MAXSIZE_Y => MaxSize.cx_ & MaxSize.cy
; - If the gripper is added using the DLF_ADD_GRIPPER flag, no additional DL_CHILD_INFO is needed.
;   The gripper is not controlled by the resizing rules. Check always that it doesn't overlap
;   other controls.
; - Layout information is not serialized. It can be reconstructed during initialization.
; - Set CS_HREDRAW and CS_VREDRAW flags in the WNDCLASSEX to redraw the complete client area.
;   this avoids flicker when resized from the left edge (WM_MOVE!! + WM_SIZE).


;Dynamic Layout flags
DLF_USE_INISIZE         equ   BIT00   ;Use the initial size rather than the template size
DLF_LOAD_MIN_INISIZE    equ   BIT01   ;Use the initial size / template size as minimal size
DLF_LOAD_MAX_INISIZE    equ   BIT02   ;Use the initial size / template size as maximal size
DLF_USE_MINSIZE_X       equ   BIT03   ;Limit the minimal width
DLF_USE_MINSIZE_Y       equ   BIT04   ;Limit the minimal height
DLF_USE_MAXSIZE_X       equ   BIT05   ;Limit the maximal width
DLF_USE_MAXSIZE_Y       equ   BIT06   ;Limit the maximal height
DLF_ADD_GRIPPER         equ   BIT07   ;If this flag is used, add an additional DL_CHILD_INFO struc

;Convenience flags
DLF_USE_MAXSIZE         equ   DLF_USE_MAXSIZE_X or DLF_USE_MAXSIZE_Y
DLF_USE_MINSIZE         equ   DLF_USE_MINSIZE_X or DLF_USE_MINSIZE_Y
DLF_USE_MINMAXSIZE      equ   DLF_USE_MINSIZE or DLF_USE_MAXSIZE
DLF_USE_MINMAXSIZE_X    equ   DLF_USE_MINSIZE_X or DLF_USE_MAXSIZE_X
DLF_USE_MINMAXSIZE_Y    equ   DLF_USE_MINSIZE_Y or DLF_USE_MAXSIZE_Y
DLF_LOAD_MINMAX_INISIZE equ   DLF_LOAD_MIN_INISIZE or DLF_LOAD_MAX_INISIZE

IDC__GRIPPER_         equ   -1


DL_CHILD_INFO struct
  ChangeInfo      RECT    {}          ;Input: 0 = no change, 100 = full change
  PositionInfo    RECT    {}          ;Used internally, x & y parent relative coords, width & height
DL_CHILD_INFO ends
PChildWndInfo typedef ptr DL_CHILD_INFO

DL_HEADER struct
  dFlags          DWORD   ?           ;DLF_xxx
  IniSize         POINT   {}          ;Input: Initial client size
  MinSize         POINT   {}          ;Input: Min client width & height
  MaxSize         POINT   {}          ;Input: Max client width & height
  dChildCount     DWORD   ?           ;Used internally, don't fill it
  ChildInfo       DL_CHILD_INFO 0 dup (?)  ;-> As many structures as Window children are present
DL_HEADER ends
PDL_HEADER typedef ptr DL_HEADER


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  Window
; Purpose: Implement a base object for windows user interface descendant objects.
;          Object pointer is stored in the window GWL_USERDATA slot.

Object Window, WindowID, WinPrimer
  VirtualMethod     OnInitWindow
  VirtualMethod     WndProc,          DWORD, WPARAM, LPARAM

  ;Dynamic Layout messages
  VirtualEvent      OnGetMinMaxInfo,  WM_GETMINMAXINFO
  VirtualEvent      OnSize,           WM_SIZE

  DefineVariable    pDynamicLayout,   PDL_HEADER, NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

GetChildWndInfo struct
  hParent         HWND    ?
  pInfo           PChildWndInfo ?
  dChildCount     DWORD   ?
GetChildWndInfo ends
PGetChildWndInfo typedef ptr GetChildWndInfo

MoveChildWndInfo struct
  hParent         HWND    ?
  pInfo           PChildWndInfo ?
  hDWP            HANDLE  ?               ;DeferWindowPos HANDLE
  dDeltaX         DWORD   ?               ;Only positive values allowed
  dDeltaY         DWORD   ?               ;Only positive values allowed
  dResizeRequest  DWORD   ?               ;SIZE_RESTORED, SIZE_MINIMIZED, SIZE_MAXIMIZED, ...
MoveChildWndInfo ends
PMoveChildWndInfo typedef ptr MoveChildWndInfo


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Window.OnGetMinMaxInfo
; Purpose:   Event procedure for WM_GETMINMAXINFO message.
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    eax = Zero.

Method Window.OnGetMinMaxInfo, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT, WRect:RECT

  SetObject xsi
  mov xbx, [xsi].pDynamicLayout
  .if xbx != NULL
    invoke GetWindowRect, [xsi].hWnd, addr WRect
    invoke GetClientRect, [xsi].hWnd, addr CRect
    mov xdx, lParam                                     ;xdx -> MINMAXINFO
    .ifBitSet [xbx].DL_HEADER.dFlags, DLF_USE_MINSIZE_X
      mov eax, [xbx].DL_HEADER.MinSize.x
      add eax, WRect.right
      sub eax, WRect.left
      sub eax, CRect.right
      mov [xdx].MINMAXINFO.ptMinTrackSize.x, eax
    .endif
    .ifBitSet [xbx].DL_HEADER.dFlags, DLF_USE_MINSIZE_Y
      mov eax, [xbx].DL_HEADER.MinSize.y
      add eax, WRect.bottom
      sub eax, WRect.top
      sub eax, CRect.bottom
      mov [xdx].MINMAXINFO.ptMinTrackSize.y, eax
    .endif
    .ifBitSet [xbx].DL_HEADER.dFlags, DLF_USE_MAXSIZE_X
      mov eax, [xbx].DL_HEADER.MaxSize.x
      add eax, WRect.right
      sub eax, WRect.left
      sub eax, CRect.right
      mov [xdx].MINMAXINFO.ptMaxTrackSize.x, eax
    .endif
    .ifBitSet [xbx].DL_HEADER.dFlags, DLF_USE_MAXSIZE_Y
      mov eax, [xbx].DL_HEADER.MaxSize.y
      add eax, WRect.bottom
      sub eax, WRect.top
      sub eax, CRect.bottom
      mov [xdx].MINMAXINFO.ptMaxTrackSize.y, eax
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Window.OnInitWindow
; Purpose:    Event procedure for WM_CREATE or WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Child count.

GetChildInfo proc uses xbx xsi hWnd:HWND, pGetChildWndInfo:PGetChildWndInfo
  mov xbx, pGetChildWndInfo
  invoke GetMenu, hWnd                                  ;eax = Control ID
  .if eax == IDC__GRIPPER_
    inc [xbx].GetChildWndInfo.dChildCount               ;Include the Gripper in the count
  .else
    mov xsi, [xbx].GetChildWndInfo.pInfo
    invoke GetParent, hWnd
    .if xax == [xbx].GetChildWndInfo.hParent
      invoke GetWindowRect, hWnd, addr [xsi].DL_CHILD_INFO.PositionInfo
      ;Convert to x/y coordinates relative to the parent.
      invoke ScreenToClient, [xbx].GetChildWndInfo.hParent, addr [xsi].DL_CHILD_INFO.PositionInfo.left
      ;Convert to width and height values.
      invoke ScreenToClient, hWnd, addr [xsi].DL_CHILD_INFO.PositionInfo.right
      ;Move to the next DL_CHILD_INFO.
      mov xcx, sizeof(DL_CHILD_INFO)
      add [xbx].GetChildWndInfo.pInfo, xcx
      inc [xbx].GetChildWndInfo.dChildCount             ;Include the Gripper in the count
    .endif
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
GetChildInfo endp

Method Window.OnInitWindow, uses xbx xsi
  local CRect:RECT, GCWI:GetChildWndInfo, IniSize:SIZE_, Gripper:RECT

;  DbgText "Window.OnInitWindow"

  SetObject xsi
  mov xbx, [xsi].pDynamicLayout
  .if xbx != NULL

    ;Get the initial dialog size to use it as a reference to calculate the size changes.
    s2s IniSize, [xbx].DL_HEADER.IniSize, xax, xcx
    invoke GetClientRect, [xsi].hWnd, addr CRect
    s2s [xbx].DL_HEADER.IniSize, POINT ptr CRect.right, xax, xcx

    .ifBitSet [xbx].DL_HEADER.dFlags, DLF_ADD_GRIPPER
      ;Calculate Gripper position and size
      invoke GetSystemMetrics, SM_CXVSCROLL
      mov ecx, CRect.right
      sub ecx, eax
      inc ecx
      mov edx, CRect.bottom
      sub edx, eax
      mov Gripper.left, ecx
      mov Gripper.top, edx
      mov Gripper.right, eax
      mov Gripper.bottom, eax
      ;Create the gripper
      invoke CreateWindowEx, 0, $OfsCStr("ScrollBar"), NULL, \
                             WS_CHILD or WS_VISIBLE or SBS_HORZ or SBS_SIZEGRIP, \
                             Gripper.left, Gripper.top, Gripper.right, Gripper.bottom, \
                             [xsi].hWnd, IDC__GRIPPER_, hInstance, 0
    .endif
    .ifBitSet [xbx].DL_HEADER.dFlags, DLF_LOAD_MIN_INISIZE
      s2s [xbx].DL_HEADER.MinSize, [xbx].DL_HEADER.IniSize, xax, xcx
    .endif
    .ifBitSet [xbx].DL_HEADER.dFlags, DLF_LOAD_MAX_INISIZE
      s2s [xbx].DL_HEADER.MaxSize, [xbx].DL_HEADER.IniSize, xax, xcx
    .endif
    m2m GCWI.hParent, [xsi].hWnd, xcx
    lea xax, [xbx + sizeof(DL_HEADER)]                    ;xax -> first DL_CHILD_INFO structure
    mov GCWI.pInfo, xax
    m2z GCWI.dChildCount

    invoke EnumChildWindows, [xsi].hWnd, offset(GetChildInfo), addr GCWI

    m2m [xbx].DL_HEADER.dChildCount, GCWI.dChildCount, eax
  .else
    xor eax, eax
  .endif
;  DbgDec eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Window.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

MoveChildWnd proc uses xbx xsi hWnd:HWND, pMoveChildWndInfo:PMoveChildWndInfo
  local WRect:RECT, CRect:RECT

  mov xbx, pMoveChildWndInfo
  mov xsi, [xbx].MoveChildWndInfo.pInfo
  invoke GetMenu, hWnd
  .if eax == IDC__GRIPPER_
    .if [xbx].MoveChildWndInfo.dResizeRequest == SIZE_MAXIMIZED
      invoke ShowWindow, hWnd, SW_HIDE
    .else
      invoke ShowWindow, hWnd, SW_SHOW
      invoke GetClientRect, [xbx].MoveChildWndInfo.hParent, addr WRect
      invoke GetClientRect, hWnd, addr CRect
      mov eax, CRect.right
      dec eax
      sub WRect.right, eax
      mov eax, CRect.bottom
      sub WRect.bottom, eax
      invoke DeferWindowPos, [xbx].MoveChildWndInfo.hDWP, hWnd, 0, \
                             WRect.right, WRect.bottom, 0, 0, \
                             SWP_NOOWNERZORDER or SWP_NOZORDER or SWP_NOSIZE
      ;In case Windows had to allocate a new memory block, update the DeferWindowPos HANDLE.
      mov [xbx].MoveChildWndInfo.hDWP, xax
    .endif
  .else
    invoke GetParent, hWnd
    .if xax == [xbx].MoveChildWndInfo.hParent
      ;Calculate the new child window position according to the passed parameters.
      mov eax, [xbx].MoveChildWndInfo.dDeltaX
      mul [xsi].DL_CHILD_INFO.ChangeInfo.left
      cdiv 100
      add edx, [xsi].DL_CHILD_INFO.PositionInfo.left
      mov WRect.left, edx
      mov eax, [xbx].MoveChildWndInfo.dDeltaY
      mul [xsi].DL_CHILD_INFO.ChangeInfo.top
      cdiv 100
      add edx, [xsi].DL_CHILD_INFO.PositionInfo.top
      mov WRect.top, edx
      mov eax, [xbx].MoveChildWndInfo.dDeltaX
      mul [xsi].DL_CHILD_INFO.ChangeInfo.right
      cdiv 100
      add edx, [xsi].DL_CHILD_INFO.PositionInfo.right
      mov WRect.right, edx
      mov eax, [xbx].MoveChildWndInfo.dDeltaY
      mul [xsi].DL_CHILD_INFO.ChangeInfo.bottom
      cdiv 100
      add edx, [xsi].DL_CHILD_INFO.PositionInfo.bottom
      mov WRect.bottom, edx

      invoke DeferWindowPos, [xbx].MoveChildWndInfo.hDWP, hWnd, 0, \
                             WRect.left, WRect.top, WRect.right, WRect.bottom, \
                             SWP_NOOWNERZORDER or SWP_NOZORDER
      ;In case Windows had to allocate a new memory block, update the DeferWindowPos HANDLE.
      mov [xbx].MoveChildWndInfo.hDWP, xax
      ;Move to next DL_CHILD_INFO.
      mov xcx, sizeof(DL_CHILD_INFO)
      add [xbx].MoveChildWndInfo.pInfo, xcx
    .endif
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
MoveChildWnd endp

Method Window.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local MCWI:MoveChildWndInfo

;  DbgText "Window.OnSize"
  SetObject xsi
  .if wParam != SIZE_MINIMIZED
    mov xdx, [xsi].pDynamicLayout
    .if xdx != NULL
      mov xcx, lParam
      movsx eax, cx                                       ;eax = new client x size
      sub eax, [xdx].DL_HEADER.IniSize.x
      .if SIGN?
        xor eax, eax
      .endif
      mov MCWI.dDeltaX, eax
      shr ecx, 16
      movsx eax, cx                                       ;eax = new client y size
      sub eax, [xdx].DL_HEADER.IniSize.y
      .if SIGN?
        xor eax, eax
      .endif
      mov MCWI.dDeltaY, eax

      lea xax, [xdx + sizeof(DL_HEADER)]                  ;xax -> first DL_CHILD_INFO structure
      mov MCWI.pInfo, xax

      mov MCWI.hDWP, $invoke(BeginDeferWindowPos, [xdx].DL_HEADER.dChildCount)
      mrm MCWI.hParent, [xsi].hWnd, xcx
      m2m MCWI.dResizeRequest, DWORD ptr wParam, eax
      invoke EnumChildWindows, xcx, offset(MoveChildWnd), addr MCWI
      invoke EndDeferWindowPos, MCWI.hDWP
    .endif
  .endif

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Window.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method Window.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg, "Window.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    mov xsi, [xax].CREATESTRUCT.lpCreateParams
    test xsi, xsi
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mrm [xsi].$Obj(Window).hWnd, pSelf, xcx             ;pSelf = hWnd
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWLP_USERDATA wasn't set,
    test xax, xax                                       ;  it returns NULL
    jz @@DefProc                                        ;Goto handler defined in DispatchEvent
    mov xsi, xax
  .endif
  DispatchEvent <DefWindowProc, pSelf>                  ;xsi -> Object Instance
MethodEnd

endif
