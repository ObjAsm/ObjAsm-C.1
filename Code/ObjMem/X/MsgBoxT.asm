; ==================================================================================================
; Title:      MsgBoxT.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of MsgBox dialogs.
;             It displays a modified Messagebox using TextView formatted text.
; Notes:      Version C.1.2, May 2020
;               - First release.
;               - The arguments passed to the function are almost the same es the original API.
;               - If an icon is specified, e.g MB_ICONERROR, a text indentation of 65px is 
;                 recommended.
;               - Don't use GWLP_USERDATA. It is used internally by the API.
; ==================================================================================================


% include &MacPath&WinHelpers.inc
% include &IncPath&Windows\CommCtrl.inc
% include &MacPath&ConstDiv.inc

% include &ObjPath&\Primer.inc
% include &ObjPath&\Stream.inc
% include &ObjPath&\Collection.inc
% include &ObjPath&\DataCollection.inc
% include &ObjPath&\SortedCollection.inc
% include &ObjPath&\SortedDataCollection.inc
% include &ObjPath&\XWCollection.inc
% include &ObjPath&\WinPrimer.inc
% include &ObjPath&\Window.inc
% include &ObjPath&\TextView.inc


MB_BTN_MAX_COUNT  equ 4       ;Max number of buttons shown on the dialog

MB_ButtonInfo struc           ;Collected information of each button
  hWnd        HWND  ?
  Rect        RECT  {}
MB_ButtonInfo ends

MsgBoxInfo struc
  hHook       HANDLE    ?     ;System hook
  hDlg        HWND      ?     ;hDlg
  pCaption    PSTRING   ?     ;Dialog caption string
  pText       PSTRING   ?     ;Main text markup string
  dBandHeight DWORD     ?     ;Drawing help, height of grey band at the bottom of the dialog
  dBtnCount   DWORD     ?     ;Index into MsgBoxBtns
  dFlags      DWORD     ?
  Buttons     MB_ButtonInfo MB_BTN_MAX_COUNT DUP({?})       ;Button information
MsgBoxInfo ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MsgBoxA / MsgBoxW
; Purpose:    Customized MessageBox.
; Arguments:  Arg1: Parent HANDLE.
;             Arg2: -> Markup text.
;             Arg3: -> Caption text.
;             Arg4: Flags.
; Return:     eax = Zero if failed, otherwise pressed button ID.

ProcName proc uses xbx hParent:HANDLE, pText:POINTER, pCaption:POINTER, dFlags:DWORD
  local cTransfer[(2*sizeof(POINTER) + 1)]:CHR

  ;Set system hook
  mov xbx, $MemAlloc(sizeof(MsgBoxInfo))
  invoke SetWindowsHookEx, WH_CALLWNDPROC, offset MB_HookProc, 0, $32($invoke(GetCurrentThreadId))
  mov [xbx].MsgBoxInfo.hHook, xax

  ;Prepare information to pass to the MessageBox dialog.
  m2m [xbx].MsgBoxInfo.pText, pText, xcx
  m2m [xbx].MsgBoxInfo.pCaption, pCaption, xdx
  invoke xword2hex, addr cTransfer, xbx

  ;Use the caption to pass the pointer to MsgBoxInfo in form of a string.
  ;MessageBoxIndirect can be used for more options.
  invoke MessageBox, hParent, NULL, addr cTransfer, dFlags
  ret
ProcName endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MB_TextView.GetExtent
; Purpose:    Return the Extent after evaluation of SIZE commands.
;             This method only allows growing sizes.
; Arguments:  None.
; Return:     eax = TRUE if the extent has changed, otherwise FALSE.

OA_MB_TextView_GetExtent proc private uses xbx xdi xsi, pSelf:POINTER
  local NewExtent:POINT, dHasChanged:DWORD

  SetObject xsi, TextView
  mov dHasChanged, FALSE
  s2s NewExtent, [xsi].Extent, xax, xcx, xmm0, xmm1, xmm2 
  .for (ebx = 0 : ebx != [xsi].Entries.dCount: ebx++)
    mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, ebx)
    mov xax, [xdi].TVENTRY.pHandler
    mov xcx, offset(TVCH_SIZE_X)
    .if xax == xcx
      m2m NewExtent.x, [xdi].TVENTRY.dValue, ecx
      mov dHasChanged, TRUE
    .else
      mov xcx, offset(TVCH_SIZE_Y)
      .if xax == xcx
        m2m NewExtent.y, [xdi].TVENTRY.dValue, ecx
        mov dHasChanged, TRUE
      .endif
    .endif
  .endfor

  xor eax, eax
  .if dHasChanged != FALSE
    mov ecx, NewExtent.x
    mov edx, NewExtent.y
    .if ecx > [xsi].Extent.x
      mov [xsi].Extent.x, ecx
      mov eax, TRUE
    .endif
    .if edx > [xsi].Extent.y
      mov [xsi].Extent.y, edx
      mov eax, TRUE
    .endif
  .endif
  ReleaseObject
  ret
OA_MB_TextView_GetExtent endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MB_WndProc
; Purpose:    WndProc for the customized Messagebox.
; Arguments:  Arg1: Dialog HANDLE.
;             Arg2: Message ID.
;             Arg3: wParam.
;             Arg4: lParam.
; Return:     eax = Depends on the message ID.

%CStr cMsgBoxProp&TARGET_SUFFIX, "MsgBoxInfo&TARGET_SUFFIX"


MB_TEXTVIEW_CTLID   equ   0FFFFh                        ;Reuse the ID of the static text control

MBF_JUST_DRAWN  equ   BIT00

MB_EnumDlgItems proc private uses xbx xdi hItem:HWND, lParam:LPARAM
  mov xbx, lParam
  .if [xbx].MsgBoxInfo.dBtnCount < MB_BTN_MAX_COUNT
    invoke GetMenu, hItem                               ;Get the control ID stored as hMenu
    .if eax <= IDCONTINUE                               ;Last known button ID
      imul eax, [xbx].MsgBoxInfo.dBtnCount, sizeof(MB_ButtonInfo)
      lea xdi, [xbx + xax].MsgBoxInfo.Buttons
      mrm [xdi].MB_ButtonInfo.hWnd, hItem, xcx
      invoke GetWindowRect, xcx, addr [xdi].MB_ButtonInfo.Rect
      ;Calculate with, height and client position
      mov ecx, [xdi].MB_ButtonInfo.Rect.bottom
      sub ecx, [xdi].MB_ButtonInfo.Rect.top
      mov [xdi].MB_ButtonInfo.Rect.bottom, ecx
      mov edx, [xdi].MB_ButtonInfo.Rect.right
      sub edx, [xdi].MB_ButtonInfo.Rect.left
      mov [xdi].MB_ButtonInfo.Rect.right, edx
      invoke ScreenToClient, [xbx].MsgBoxInfo.hDlg, addr [xdi].MB_ButtonInfo.Rect.left

      add [xbx].MsgBoxInfo.dBtnCount, 1                 ;Move index to next MB_ButtonInfo
    .endif
    mov eax, TRUE                                       ;Continue enumeration
  .else
    xor eax, eax                                        ;Stop enumeration
  .endif
  ret
MB_EnumDlgItems endp


MB_WndProc proc private uses xbx xdi xsi hDlg:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  local TVDef:DEF_TEXTVIEW
  local CRect:RECT, WRect:RECT, WndSize:POINT, CtlOfs:POINT

;  DbgMessage uMsg, "MsgBoxBlgProc.WndProc"
  .if uMsg == WM_INITDIALOG

    %mov xdx, offset cMsgBoxProp&TARGET_SUFFIX
    mov xdi, $invoke(GetProp, hDlg, xdx)
    mov [xdi].MsgBoxInfo.dFlags, 0

    ;Destroy the original static control, we don't need it anymore
    invoke GetDlgItem, hDlg, 0FFFFh
    invoke DestroyWindow, xax

    ;Get button information
    m2m [xdi].MsgBoxInfo.hDlg, hDlg, xax
    mov [xdi].MsgBoxInfo.dBtnCount, 0                   ;Start with the first button
    invoke EnumChildWindows, hDlg, offset MB_EnumDlgItems, xdi

    ;Calculate the height of the grey band at the bottom
    invoke GetClientRect, hDlg, addr CRect              ;Get the original client rect
    mov ecx, CRect.bottom
    sub ecx, [xdi].MsgBoxInfo.Buttons.Rect.top
    shl ecx, 1
    sub ecx, [xdi].MsgBoxInfo.Buttons.Rect.bottom
    mov [xdi].MsgBoxInfo.dBandHeight, ecx

    ;Setup TextView
    mov TVDef.xCtlID, MB_TEXTVIEW_CTLID
    mov TVDef.dStyle, 0
    mov TVDef.dExStyle, 0
    mov TVDef.sdPosX, 0
    mov TVDef.sdPosY, 0
    mov TVDef.dWidth, 200
    mov TVDef.dHeight, 100
    m2m TVDef.pText, [xdi].MsgBoxInfo.pText, xax

    ;Adjust dialog size according to the TextView size
    mov TVDef.dWidth, $uMax(TVDef.dWidth, CRect.right)
    mov eax, CRect.bottom
    sub eax, [xdi].MsgBoxInfo.dBandHeight
    mov TVDef.dHeight, $uMax(eax, TVDef.dHeight)

    mov xbx, $New(TextView)
    Override xbx::TextView.GetExtent, MB_TextView.GetExtent
    OCall xbx::TextView.Init, NULL, hDlg, addr TVDef
    OCall xbx::TextView.Show

    ;Set TextView as parent of the static control that holds the icon.
    ;This way it is placed on top of TextView.
    invoke GetDlgItem, hDlg, 14h
    .if xax != 0
      invoke SetParent, xax, [xbx].$Obj(TextView).hWnd
    .endif

    ;Update the dialog size and position
    invoke GetWindowRect, hDlg, addr WRect
    mov ecx, WRect.right
    sub ecx, WRect.left
    mov eax, [xbx].$Obj(TextView).Extent.x
    mov edx, CRect.right
    sub eax, edx
    add ecx, eax
    mov WndSize.x, ecx
    mov CtlOfs.x, eax
    sar eax, 1
    sub WRect.left, eax

    mov ecx, WRect.bottom
    sub ecx, WRect.top
    mov eax, [xbx].$Obj(TextView).Extent.y
    sub eax, CRect.bottom
    add ecx, eax
    mov WndSize.y, ecx
    mov CtlOfs.y, eax
    sar eax, 1
    sub WRect.top, eax

    invoke MoveWindow, hDlg, WRect.left, WRect.top, WndSize.x, WndSize.y, FALSE

    ;Update TextView size
    invoke GetClientRect, hDlg, addr CRect              ;Get the updated client rect
    mov ecx, [xdi].MsgBoxInfo.dBandHeight
    sub CRect.bottom, ecx
    invoke MoveWindow, [xbx].$Obj(TextView).hWnd, 0, 0, CRect.right, CRect.bottom, FALSE

    ;Modify button positions
    xor ebx, ebx
    .while ebx < [xdi].MsgBoxInfo.dBtnCount
      imul eax, ebx, sizeof(MB_ButtonInfo)
      lea xsi, [[xdi].MsgBoxInfo.Buttons + xax]
      mov eax, CtlOfs.x
      mov ecx, CtlOfs.y
      add [xsi].MB_ButtonInfo.Rect.left, eax
      add [xsi].MB_ButtonInfo.Rect.top,  ecx
      invoke MoveWindow, [xsi].MB_ButtonInfo.hWnd, \
                         [xsi].MB_ButtonInfo.Rect.left, [xsi].MB_ButtonInfo.Rect.top, \
                         [xsi].MB_ButtonInfo.Rect.right, [xsi].MB_ButtonInfo.Rect.bottom, \
                         FALSE
      add ebx, 1
    .endw

  .elseif uMsg == WM_NOTIFY                             ;Forward the message to the parent window
    .if wParam == MB_TEXTVIEW_CTLID
      invoke GetParent, hDlg
      invoke SendMessage, xax, WM_NOTIFY, wParam, lParam
    .endif

  .elseif uMsg == WM_HELP                               ;Forward the message to the parent window
    invoke GetParent, hDlg
    invoke SendMessage, xax, WM_HELP, wParam, lParam
    invoke DefDlgProc, hDlg, uMsg, wParam, lParam

  .elseif uMsg == WM_PAINT
    ;Draw a grey band at the bottom like is is done in the latest OS versions
    %mov xdx, offset cMsgBoxProp&TARGET_SUFFIX
    mov xdi, $invoke(GetProp, hDlg, xdx)
    .ifBitClr [xdi].MsgBoxInfo.dFlags, MBF_JUST_DRAWN
      BitSet [xdi].MsgBoxInfo.dFlags, MBF_JUST_DRAWN
      invoke GetClientRect, hDlg, addr CRect
      mov ecx, CRect.bottom
      sub ecx, [xdi].MsgBoxInfo.dBandHeight
      mov CRect.top, ecx
      invoke GetSysColor, COLOR_BTNFACE
      mov xsi, $invoke(CreateSolidBrush, eax)
      mov xbx, $invoke(GetDC, hDlg)
      invoke FillRect, xbx, addr CRect, xsi
      invoke DeleteObject, xsi
      invoke ReleaseDC, hDlg, xbx
    .endif

  .elseif uMsg == WM_ERASEBKGND
    ret

  .elseif uMsg == WM_NCDESTROY                          ;Last message recieved
    %mov xdi, offset cMsgBoxProp&TARGET_SUFFIX
    invoke GetProp, hDlg, xdi
    MemFree xax                                         ;Free MsgBoxInfo memory block
    invoke RemoveProp, hDlg, xdi

  .endif
  invoke DefDlgProc, hDlg, uMsg, wParam, lParam

  ret
MB_WndProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MB_HookProc
; Purpose:    Procedure used by the hook set by MsgBox.
; Arguments:  Arg1: Hook code.
;             Arg2: Nonzero if the msg was sent by the current thread, otherwise zero.
;             Arg3: -> CWPSTRUCT.
; Return:     eax = Zero if handled.

MB_HookProc proc private uses xbx xdi dCode:DWORD, wParam:WPARAM, lParam:LPARAM
  local cTransfer[(2*sizeof(POINTER) + 1)]:CHR

  .if dCode == HC_ACTION                                ;Ignore the rest
    mov xbx, lParam
    ;The first recieved WM_NCCALCSIZE corresponds to the dialog window.
    ;It is the first dialog message that has the caption set
    .if [xbx].CWPSTRUCT.message == WM_NCCALCSIZE
      invoke GetWindowText, [xbx].CWPSTRUCT.hwnd, addr cTransfer, lengthof(cTransfer)
      mov xdi, $invoke(hex2xword, addr cTransfer)
      ;Save a pointer to MsgBoxInfo as a window property
      %mov xdx, offset cMsgBoxProp&TARGET_SUFFIX
      invoke SetProp, [xbx].CWPSTRUCT.hwnd, xdx, xdi
      ;Release the hook
      invoke UnhookWindowsHookEx, [xdi].MsgBoxInfo.hHook
      ;Set correct caption
      invoke SetWindowText, [xbx].CWPSTRUCT.hwnd, [xdi].MsgBoxInfo.pCaption
      ;Set the new WndProc
      invoke SetWindowLongPtr, [xbx].CWPSTRUCT.hwnd, GWLP_WNDPROC, offset MB_WndProc
    .endif
  .endif
  mov eax, 1
  ret
MB_HookProc endp
