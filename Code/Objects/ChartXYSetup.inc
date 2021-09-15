; ==================================================================================================
; Title:      ChartXYSetup.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Tools for ObjAsm.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartTabColor
; Purpose:    Color Tab of the ChartXYSetup dialog.

Object ChartTabColor, , DialogModeless
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC
  VirtualEvent      OnCompareItem,      WM_COMPAREITEM
  VirtualEvent      OnDrawItem,         WM_DRAWITEM
  VirtualEvent      OnMeasureItem,      WM_MEASUREITEM

  DefineVariable    hComboBox,          HANDLE,     0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartTabScale
; Purpose:    Scale Tab of the ChatSetup dialog.

Object ChartTabScale, , DialogModeless
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartTabSeries
; Purpose:    Series Tab of the ChartXYSetup dialog.

Object ChartTabSeries, , DialogModeless
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartXYSetup
; Purpose:    Custom Setup dialog.

Object ChartXYSetup, , DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  VirtualMethod     GetFileName
  RedefineMethod    Init,               POINTER, HWND
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  Embed     TabControl,       TabCtrl
  Embed     TabDialog1,       ChartTabColor
  Embed     TabDialog2,       ChartTabScale
  Embed     TabDialog3,       ChartTabSeries
  Embed     IconImageList,    MaskedImageList
ObjectEnd


; ==================================================================================================


SetItemString macro iID:req, sID:req
  mov edx, edi
  %add edx, &sID
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  %invoke SetDlgItemText, [xsi].hWnd, &iID, xbx
endm

;GetTool macro ID:req
;  %.if [xdi].$Obj(OAT_App).Setup.Tool&ID.pName != NULL
;    %invoke StrDispose, [xdi].$Obj(OAT_App).Setup.Tool&ID.pName
;  .endif
;  %invoke GetDlgItemText, xbx, IDC_EDT_NAME_&ID, addr cBuffer, lengthof cBuffer
;  mov [xdi].$Obj(OAT_App).Setup.Tool&ID.pName, $invoke(StrNew, addr cBuffer)
;  .if [xdi].$Obj(OAT_App).Setup.Tool&ID.pCommand != NULL
;    %invoke StrDispose, [xdi].$Obj(OAT_App).Setup.Tool&ID.pCommand
;  .endif
;  %invoke GetDlgItemText, xbx, IDC_EDT_CMD_&ID, addr cBuffer, lengthof cBuffer
;  mov [xdi].$Obj(OAT_App).Setup.Tool&ID.pCommand, $invoke(StrNew, addr cBuffer)
;endm

.code
include OA_Tools_Setup_Tab1.inc
include OA_Tools_Setup_Tab2.inc
include OA_Tools_Setup_Tab3.inc


; ==================================================================================================
;    ChartXYSetup implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYSetup.CtlsGet, uses xsi
  SetObject xsi
  OCall [xsi].TabDialog1::ChartTabColor.CtlsGet
  OCall [xsi].TabDialog2::ChartTabScale.CtlsGet
  OCall [xsi].TabDialog3::ChartTabSeries.CtlsGet
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method ChartXYSetup.CtlsSet, uses xsi
  SetObject xsi
  OCall [xsi].TabDialog1::ChartTabColor.CtlsSet
  OCall [xsi].TabDialog2::ChartTabScale.CtlsSet
  OCall [xsi].TabDialog3::ChartTabScale.CtlsSet
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.Done
; Purpose:    Finalize the ChartXYSetup object.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYSetup.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TabDialog1::ChartTabColor.Done
  OCall [xsi].TabDialog2::ChartTabScale.Done
  OCall [xsi].TabDialog3::ChartTabSeries.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.Init
; Purpose:    Initialaize a ChartXYSetup object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window HANDLE.
; Return:     Nothing.

Method ChartXYSetup.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND

  SetObject xsi
  ACall xsi.Init, pOwner, hParent, 5000

  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 3
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APPL_SETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_CHECK")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_BRUSH")
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartXYSetup.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
  .endif
  OCall xsi.DestroyDialog, wParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method ChartXYSetup.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method ChartXYSetup.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
;  local cBuffer[MAX_PATH]:CHR, CtrlSetup:DEF_TABCONTROL
;
;  SetObject xsi
;  lea xbx, [xsi].TabControl
;  invoke MemClone, addr CtrlSetup, offset SetupTabCtrl, sizeof DEF_TABCONTROL
;  invoke MapDialogRect, [xsi].hWnd, addr CtrlSetup.sdPosX
;  OCall xbx::TabCtrl.Init, xsi, [xsi].hWnd, addr [xsi].IconImageList, addr CtrlSetup
;
;  OCall [xsi].TabDialog1::ChartTabColor.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, IDD_CHT_SETUP_TAB_GENERAL, \
;                                          addr $ObjTmpl(Application).hActiveMlsDlg
;  OCall [xsi].TabDialog1::ChartTabColor.Show
;  invoke ShowWindow, [xsi].TabDialog1.hWnd, SW_SHOWDEFAULT
;
;  OCall [xsi].TabDialog2::ChartTabScale.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, IDD_CHT_SETUP_TAB_SCALE, \
;                                          addr $ObjTmpl(Application).hActiveMlsDlg
;  OCall [xsi].TabDialog2::ChartTabScale.Show
;  invoke ShowWindow, [xsi].TabDialog2.hWnd, SW_HIDE
;
;;  OCall [xsi].TabDialog3::ChartTabSeries.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, SETUP_TAB_COLORS, \
;;                                          addr $ObjTmpl(Application).hActiveMlsDlg
;;  OCall [xsi].TabDialog3::ChartTabSeries.Show
;;  invoke ShowWindow, [xsi].TabDialog3.hWnd, SW_HIDE
;
;  mov xcx, [xsi].pOwner                                 ;xcx -> OAT_App
;  mov edi, [xcx].$Obj(OAT_App).dLanguage
;  lea xbx, cBuffer
;
;  mov edx, edi
;  add edx, IDS_SETUP
;  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
;  invoke SetWindowText, [xsi].hWnd, xbx
;
;  SetItemString IDCANCEL, IDS_CANCEL
;
;  mov edx, edi
;  add edx, IDS_TAB1_MAIN
;  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
;  OCall [xsi].TabControl::TabCtrl.Insert, 0, [xsi].TabDialog1.hWnd, xbx, 0
;
;  mov edx, edi
;  add edx, IDS_TAB2_TOOLS
;  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
;  OCall [xsi].TabControl::TabCtrl.Insert, 1, [xsi].TabDialog2.hWnd, xbx, 1
;
;  mov edx, edi
;  add edx, IDS_TAB3_COLORS
;  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
;  OCall [xsi].TabControl::TabCtrl.Insert, 2, [xsi].TabDialog3.hWnd, xbx, 2
;
;  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd
