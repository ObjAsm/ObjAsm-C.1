; ==================================================================================================
; Title:      ChartSetup.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartSetup objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartSetup implementation
; ==================================================================================================

STSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_TABSTOP or TCS_TABS or TCS_HOTTRACK

.const
SetupTabCtrl DEF_TABCONTROL {100, STSTYLE, WS_EX_CONTROLPARENT, NULL, {<4,3,268,200>}}

IDD_CHT_SETUP               equ   5000
IDC_CHT_SETUP_BTN_PREVIEW   equ   5001

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartSetup.CtlsGet, uses xsi
  SetObject xsi
  OCall [xsi].TabGeneral::ChartTabGeneral.CtlsGet
  OCall [xsi].TabScaleX::ChartTabScale.CtlsGet
  OCall [xsi].TabScaleY1::ChartTabScale.CtlsGet
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method ChartSetup.CtlsSet, uses xsi
  SetObject xsi
  OCall [xsi].TabGeneral::ChartTabGeneral.CtlsSet
  OCall [xsi].TabScaleX::ChartTabScale.CtlsSet
  OCall [xsi].TabScaleY1::ChartTabScale.CtlsSet
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.Done
; Purpose:    Finalize the ChartSetup object.
; Arguments:  None.
; Return:     Nothing.

Method ChartSetup.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TabGeneral::ChartTabGeneral.Done
  OCall [xsi].TabScaleX::ChartTabScale.Done
  OCall [xsi].TabScaleY1::ChartTabScale.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.Init
; Purpose:    Initialaize a ChartSetup object.
; Arguments:  Arg1: -> Owner object (ChartWnd).
;             Arg2: -> Parent window HANDLE.
;             Arg3: Tab ID to show.
; Return:     Nothing.

Method ChartSetup.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, dTabID:DWORD

  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_CHT_SETUP
  m2m [xsi].dTabID, dTabID, eax

  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 10
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCALEX")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCALEY")
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartSetup.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xbx, [xsi].pOwner
  .if wParam == IDOK
    ;Set current values and exit
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
    OCall xbx::ChartWnd.Refresh

  .elseif wParam == IDCANCEL
    ;Restore previous values and exit
    OCall xsi.Restore
    OCall xsi.DestroyDialog, wParam
    OCall xbx::ChartWnd.Refresh

  .elseif wParam == IDC_CHT_SETUP_BTN_PREVIEW
    ;Set current values and exit
    OCall xsi.CtlsGet
    OCall xbx::ChartWnd.Refresh
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method ChartSetup.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method ChartSetup.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CtrlSetup:DEF_TABCONTROL, hWnd:HWND

  SetObject xsi
  lea xbx, [xsi].TabControl
  mov xdi, [xsi].pOwner
  mov [xsi].dSelTabIndex, 0
  mov [xsi].hSelTabWnd, 0
  mov [xsi].dTabCount, 0
  invoke MemClone, addr CtrlSetup, offset SetupTabCtrl, sizeof DEF_TABCONTROL
  invoke MapDialogRect, [xsi].hWnd, addr CtrlSetup.sdPosX
  OCall xbx::TabCtrl.Init, xsi, [xsi].hWnd, addr [xsi].IconImageList, addr CtrlSetup

  .ifBitSet [xdi].$Obj(ChartWnd).dFlags, CHT_FLAG_SHOW_GENERAL_TAB
    OCall [xsi].TabGeneral::ChartTabGeneral.Init, xbx, [xsi].pOwner
    OCall [xsi].TabGeneral::ChartTabGeneral.Show
    invoke ShowWindow, [xsi].TabGeneral.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, [xsi].TabGeneral.hWnd, \
                                            $OfsCStr("General"), 0
    .if [xsi].dTabID == CHT_ID_NONE || [xsi].dTabID == CHT_ID_PLOT
      mov [xsi].dSelTabIndex, eax
      m2m [xsi].hSelTabWnd, [xsi].TabGeneral.hWnd, ecx
    .endif
    .if eax != -1
      inc [xsi].dTabCount
    .endif
  .endif

  .ifBitSet [xdi].$Obj(ChartWnd).ScaleX.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleX::ChartTabScale.Init, xbx, addr [xdi].$Obj(ChartWnd).ScaleX
    OCall [xsi].TabScaleX::ChartTabScale.Show
    invoke ShowWindow, [xsi].TabScaleX.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, [xsi].TabScaleX.hWnd, \
                                            $OfsCStr("Scale X"), 1
    .if [xsi].dTabID == CHT_ID_SCALEX
      mov [xsi].dSelTabIndex, eax
      m2m [xsi].hSelTabWnd, [xsi].TabScaleX.hWnd, ecx
    .endif
    .if eax != -1
      inc [xsi].dTabCount
    .endif
  .endif

  .ifBitSet [xdi].$Obj(ChartWnd).ScaleY1.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY1::ChartTabScale.Init, xbx, addr [xdi].$Obj(ChartWnd).ScaleY1
    OCall [xsi].TabScaleY1::ChartTabScale.Show
    invoke ShowWindow, [xsi].TabScaleY1.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, [xsi].TabScaleY1.hWnd, \
                                            $OfsCStr("Scale Y1"), 2
    .if [xsi].dTabID == CHT_ID_SCALEY1
      mov [xsi].dSelTabIndex, eax
      m2m [xsi].hSelTabWnd, [xsi].TabScaleY1.hWnd, ecx
    .endif
    .if eax != -1
      inc [xsi].dTabCount
    .endif
  .endif

  .if $MethodAddr(xsi::ChartSetup.InitMoreTabs) != ??ABSTRACT_ERROR_PROC
    OCall xsi.InitMoreTabs
  .endif

  .if [xsi].dTabCount != 0
    invoke SendMessage, [xsi].TabControl.hWnd, TCM_SETCURSEL, [xsi].dSelTabIndex, 0
    invoke ShowWindow, [xsi].hSelTabWnd, SW_SHOWDEFAULT
  .endif

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSetup.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartSetup.Restore, uses xsi
  SetObject xsi
  OCall [xsi].TabGeneral::ChartTabGeneral.Restore
  OCall [xsi].TabScaleX::ChartTabScale.Restore
  OCall [xsi].TabScaleY1::ChartTabScale.Restore
MethodEnd

