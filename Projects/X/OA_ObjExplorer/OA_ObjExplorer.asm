; ==================================================================================================
; Title:      OA_ObjExplorer.asm
; Author:     G. Friedrich
; Version:    2.0.1
; Purpose:    ObjAsm Object Explorer Application.
; Notes:      Version 1.0.0, December 2017
;               - First release.
;             Version 1.1.0, August 2020
;               - WebBrowser rendering replaced by TextView.
;             Version 2.0.0, October 2021
;               - General overhaul.
;             Version 2.0.1, November 2022
;               - OA_Info.stm: name and path moved to ini file.
;
; Todos:      - Namespaces need better handling
;             - Interfaces are not recognized --> API convention change! See h2incX project
;             - HelpLines are not collected nor displayed
;             - Set some information on the StatusBar from resources
;             - Context menu is not used. Code remains for future use
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, ANSI_STRING;, DEBUG(WND)           ;MUST be ANSI!!!

% includelib &LibPath&Windows\Kernel32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\MSVCRT.lib
% includelib &LibPath&Windows\UUID.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\Msimg32.lib

% includelib &LibPath&PCRE\PCRE844S&TARGET_STR_AFFIX&.lib

% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\IImgCtx.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\uxtheme.inc
% include &IncPath&Windows\richedit.inc

% include &IncPath&PCRE\PCRE844S.inc

% include &MacPath&DlgTmpl.inc                          ;Include Dlg Template macros for XMenu
% include &MacPath&SDLL.inc
% include &MacPath&fMath.inc

.code
;Load or build the following objects
MakeObjects Primer, Stream, DiskStream, MemoryStream
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects SimpleImageList, MaskedImageList
MakeObjects StopWatch
MakeObjects WinPrimer, Window
MakeObjects Dialog, DialogModal, DialogModeless
MakeObjects WinControl, Button, IconButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects Toolbar, Rebar, Statusbar
MakeObjects DataPool, IniFile, RegEx
MakeObjects FlipBox, Splitter, XTreeView
MakeObjects Image
MakeObjects WinApp, MdiApp, TextView





MB_BTN_MAX_COUNT  equ 4       ;Max number of buttons shown on the dialog

MB_ButtonInfo struc           ;Collected information of each button
  hWnd        HWND  ?
  Rect        RECT  {}
MB_ButtonInfo ends

MsgBoxInfo struc
  hHook       HANDLE    ?     ;System hook
  hDlg        HWND      ?     ;Dialog HANDLE
  pCaption    PSTRING   ?     ;Dialog caption string
  pText       PSTRING   ?     ;Main text markup string
  dBandHeight DWORD     ?     ;Drawing help, height of grey band at the bottom of the dialog
  dBtnCount   DWORD     ?     ;Index into MsgBoxBtns
  dFlags      DWORD     ?
  Buttons     MB_ButtonInfo MB_BTN_MAX_COUNT DUP({?})       ;Button information
MsgBoxInfo ends

MsgBoxCaptionHeader     equ <MsgBoxData@>
MsgBoxCaptionHeaderSize equ 11

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MsgBoxA / MsgBoxW
; Purpose:    Show a customized MessageBox.
; Arguments:  Arg1: Parent HANDLE.
;             Arg2: -> Markup text.
;             Arg3: -> Caption text.
;             Arg4: Flags.
; Return:     eax = Zero if failed, otherwise pressed button ID.
; Note:       Caption, text etc. are transferred via a caption string which contains a header and
;             the address of a MsgBoxInfo structure in text form.

MBX proc uses xbx hParent:HANDLE, pText:POINTER, pCaption:POINTER, dFlags:DWORD
  local cTransferInfo[MsgBoxCaptionHeaderSize + 2*sizeof(POINTER) + 1]:CHR, MBInfo:MsgBoxInfo

  ;Set system hook
  invoke SetWindowsHookEx, WH_CALLWNDPROC, offset MB_HookProc, 0, $32($invoke(GetCurrentThreadId))

  ;Prepare information to pass to the MessageBox dialog.
  mov MBInfo.hHook, xax
  m2m MBInfo.pText, pText, xcx
  m2m MBInfo.pCaption, pCaption, xdx
  FillWord cTransferInfo, MsgBoxCaptionHeader
  invoke xword2hex, addr [cTransferInfo + MsgBoxCaptionHeaderSize*sizeof(CHR)], addr MBInfo

  ;Use the caption to pass the pointer to MsgBoxInfo in form of a string.
  ;MessageBoxIndirect can be used for more options.
  invoke MessageBox, hParent, NULL, addr cTransferInfo, dFlags
  mov eax, MB_OK
  ret
MBX endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MB_WndProc
; Purpose:    WndProc for the customized Messagebox.
; Arguments:  Arg1: Dialog HANDLE.
;             Arg2: Message ID.
;             Arg3: wParam.
;             Arg4: lParam.
; Return:     eax = Depends on the message ID.

%CStr cMsgBoxProp_&TARGET_SUFFIX, "MsgBoxInfo&TARGET_SUFFIX"


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

      ;Calculate with, height and client position of each button
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

    %mov xdx, offset cMsgBoxProp_&TARGET_SUFFIX
    mov xdi, $invoke(GetProp, hDlg, xdx)
    mov [xdi].MsgBoxInfo.dFlags, 0

    ;Destroy the original static control were the messagebox text is usually displayed,
    ;we don't need it anymore
    invoke GetDlgItem, hDlg, 0FFFFh                     ;0FFFFh = static control ID
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
    mov TVDef.dWidth, 200                               ;Min TextView width
    mov TVDef.dHeight, 100                              ;Min TextView height
    m2m TVDef.pText, [xdi].MsgBoxInfo.pText, xax

    ;Adjust dialog size according to the TextView size
    mov TVDef.dWidth, $uMax(TVDef.dWidth, CRect.right)
    mov eax, CRect.bottom
    sub eax, [xdi].MsgBoxInfo.dBandHeight
    mov TVDef.dHeight, $uMax(eax, TVDef.dHeight)

    mov xbx, $New(TextView)
    OCall xbx::TextView.Init, NULL, hDlg, addr TVDef

    ;Set TextView as parent of the static control that holds the icon.
    ;This way it is placed on top of TextView control.
    invoke GetDlgItem, hDlg, 14h                        ;14h = icon control ID
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
    add eax, [xdi].MsgBoxInfo.dBandHeight
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
    %mov xdx, offset cMsgBoxProp_&TARGET_SUFFIX
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

  .elseif uMsg == WM_DESTROY
    %mov xdi, offset cMsgBoxProp_&TARGET_SUFFIX
    invoke GetDlgItem, hDlg, MB_TEXTVIEW_CTLID
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      Destroy xax
    .endif

  .elseif uMsg == WM_NCDESTROY                          ;Last message recieved
    %invoke RemoveProp, hDlg, offset cMsgBoxProp_&TARGET_SUFFIX

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
  local cTransferInfo[2*sizeof(POINTER) + MsgBoxCaptionHeaderSize + 1]:CHR

  .if dCode == HC_ACTION                               ;Ignore the rest
    mov xbx, lParam
    ;The first recieved WM_NCCALCSIZE corresponds to the dialog window.
    ;It is the first dialog message where the caption is set
    .if [xbx].CWPSTRUCT.message == WM_NCCALCSIZE
      invoke GetWindowText, [xbx].CWPSTRUCT.hwnd, addr cTransferInfo, lengthof(cTransferInfo)
      .if $DoesWordMatch?(cTransferInfo, MsgBoxCaptionHeader)
        mov xdi, $invoke(hex2xword, addr [cTransferInfo + MsgBoxCaptionHeaderSize*sizeof(CHR)])
        ;Save a pointer to MsgBoxInfo as a window property
        %invoke SetProp, [xbx].CWPSTRUCT.hwnd, offset cMsgBoxProp_&TARGET_SUFFIX, xdi
        ;Release the hook
        invoke UnhookWindowsHookEx, [xdi].MsgBoxInfo.hHook
        ;Set correct caption
        invoke SetWindowText, [xbx].CWPSTRUCT.hwnd, [xdi].MsgBoxInfo.pCaption
        ;Set the new WndProc
        invoke SetWindowLongPtr, [xbx].CWPSTRUCT.hwnd, GWLP_WNDPROC, offset MB_WndProc
      .endif
    .endif
  .endif
  mov eax, 1
  ret
MB_HookProc endp


include OAE_TextSource.inc
include OAE_ObjDB_Collections.inc
include OAE_ObjDB.inc
include OAE_InfoTree.inc
include OAE_TreeWindow.inc
include OA_ObjExplorer_Globals.inc
include OAE_AboutDlg.inc
include OA_ObjExplorer_Main.inc
include OAE_PropWnd.inc
include OAE_IntPropWnd.inc
include OAE_ObjPropWnd.inc
include OAE_SetupDlg.inc
include OAE_FindInfoDlg.inc


start proc
  SysInit

  DbgClearAll
  invoke CoInitialize, 0                                ;Required for Image object
  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done
  invoke CoUninitialize
  SysDone
  invoke ExitProcess, 0
start endp

end
