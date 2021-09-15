; ==================================================================================================
; Title:      ChartFlatSetup.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartFlatSetup objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartFlatSetup implementation
; ==================================================================================================

STSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_TABSTOP or TCS_TABS or TCS_HOTTRACK; or TCS_FOCUSNEVER;

.const
SetupTabCtrl DEF_TABCONTROL {100, STSTYLE, WS_EX_CONTROLPARENT, NULL, {<4,3,268,200>}}

IDD_CHT_SETUP               equ   5000
IDC_CHT_SETUP_BTN_PREVIEW   equ   5001

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatSetup.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatSetup.CtlsGet, uses xbx xsi
  SetObject xsi
  OCall [xsi].TabGeneral::ChartFlatTabGeneral.CtlsGet
  OCall [xsi].TabScaleX::ChartFlatTabScale.CtlsGet
  OCall [xsi].TabScaleY1::ChartFlatTabScale.CtlsGet
  mov ebx, [xsi].TabSeriesColl.dCount
  .while ebx != 0
    dec ebx
    OCall [xsi].TabSeriesColl::Collection.ItemAt, ebx
    OCall xax::ChartFlatTabSeries.CtlsGet
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatSetup.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method ChartFlatSetup.CtlsSet, uses xbx xsi
  SetObject xsi
  OCall [xsi].TabGeneral::ChartFlatTabGeneral.CtlsSet
  OCall [xsi].TabScaleX::ChartFlatTabScale.CtlsSet
  OCall [xsi].TabScaleY1::ChartFlatTabScale.CtlsSet
  mov ebx, [xsi].TabSeriesColl.dCount
  .while ebx != 0
    dec ebx
    OCall [xsi].TabSeriesColl::Collection.ItemAt, ebx
    OCall xax::ChartFlatTabSeries.CtlsSet
  .endw
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatSetup.Done
; Purpose:    Finalize the ChartFlatSetup object.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatSetup.Done, uses xsi
  SetObject xsi
  OCall [xsi].IconImageList::MaskedImageList.Done
  OCall [xsi].TabGeneral::ChartFlatTabGeneral.Done
  OCall [xsi].TabScaleX::ChartFlatTabScale.Done
  OCall [xsi].TabScaleY1::ChartFlatTabScale.Done
  OCall [xsi].TabSeriesColl::Collection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatSetup.Init
; Purpose:    Initialaize a ChartFlatSetup object.
; Arguments:  Arg1: -> Owner object (ChartFlat).
;             Arg2: -> Parent window HANDLE.
;             Arg3: Tab ID to show.
; Return:     Nothing.

Method ChartFlatSetup.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, dTabID:DWORD

  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_CHT_SETUP
  m2m [xsi].dTabID, dTabID, eax

  lea xbx, [xsi].IconImageList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 4
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SETUP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCALEX")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCALEY")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SERIES")

  OCall [xsi].TabSeriesColl::Collection.Init, xsi, 5, 5, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatSetup.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartFlatSetup.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xbx, [xsi].pOwner
  .if wParam == IDOK
    ;Set current values and exit
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
    OCall xbx::ChartFlat.Refresh

  .elseif wParam == IDCANCEL
    ;Restore previous values and exit
    OCall xsi.Restore
    OCall xsi.DestroyDialog, wParam
    OCall xbx::ChartFlat.Refresh

  .elseif wParam == IDC_CHT_SETUP_BTN_PREVIEW
    ;Set current values and exit
    OCall xsi.CtlsGet
    OCall xbx::ChartFlat.Refresh
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatSetup.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method ChartFlatSetup.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatSetup.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method ChartFlatSetup.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[20]:CHR, CtrlSetup:DEF_TABCONTROL, pTabSeries:$ObjPtr(ChartFlatTabSeries)
  local hWnd:HWND, dSelTabIndex:DWORD, hSelTabWnd:HWND, dTabCount:DWORD
  local pSeries:$ObjPtr(ChartSeries)

  SetObject xsi
  lea xbx, [xsi].TabControl
  mov xdi, [xsi].pOwner
  mov dSelTabIndex, 0
  mov hSelTabWnd, 0
  mov dTabCount, 0
  invoke MemClone, addr CtrlSetup, offset SetupTabCtrl, sizeof DEF_TABCONTROL
  invoke MapDialogRect, [xsi].hWnd, addr CtrlSetup.sdPosX
  OCall xbx::TabCtrl.Init, xsi, [xsi].hWnd, addr [xsi].IconImageList, addr CtrlSetup

  .ifBitSet [xdi].$Obj(ChartFlat).dFlags, CHT_FLAG_SHOW_GENERAL_TAB
    OCall [xsi].TabGeneral::ChartFlatTabGeneral.Init, xbx, [xsi].pOwner
    OCall [xsi].TabGeneral::ChartFlatTabGeneral.Show
    invoke ShowWindow, [xsi].TabGeneral.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, 0, [xsi].TabGeneral.hWnd, $OfsCStr("General"), 0
    .if [xsi].dTabID == CHT_ID_NONE || [xsi].dTabID == CHT_ID_PLOT
      mov dSelTabIndex, eax
      m2m hSelTabWnd, [xsi].TabGeneral.hWnd, eax
    .endif
    inc dTabCount
  .endif

  .ifBitSet [xdi].$Obj(ChartFlat).ScaleX.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleX::ChartFlatTabScale.Init, xbx, addr [xdi].$Obj(ChartFlat).ScaleX
    OCall [xsi].TabScaleX::ChartFlatTabScale.Show
    invoke ShowWindow, [xsi].TabScaleX.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, 1, [xsi].TabScaleX.hWnd, $OfsCStr("Scale X"), 1
    .if [xsi].dTabID == CHT_ID_SCALEX
      mov dSelTabIndex, eax
      m2m hSelTabWnd, [xsi].TabScaleX.hWnd, eax
    .endif
    inc dTabCount
  .endif

  .ifBitSet [xdi].$Obj(ChartFlat).ScaleY1.dFlags, CHT_SCALE_SHOW_TAB
    OCall [xsi].TabScaleY1::ChartFlatTabScale.Init, xbx, addr [xdi].$Obj(ChartFlat).ScaleY1
    OCall [xsi].TabScaleY1::ChartFlatTabScale.Show
    invoke ShowWindow, [xsi].TabScaleY1.hWnd, SW_HIDE
    OCall [xsi].TabControl::TabCtrl.Insert, 2, [xsi].TabScaleY1.hWnd, $OfsCStr("Scale Y1"), 2
    .if [xsi].dTabID == CHT_ID_SCALEY1
      mov dSelTabIndex, eax
      m2m hSelTabWnd, [xsi].TabScaleY1.hWnd, eax
    .endif
    inc dTabCount
  .endif

  xor ebx, ebx
  .while ebx < [xdi].$Obj(ChartFlat).Data.dCount
    mov pSeries, $OCall([xdi].$Obj(ChartFlat).Data::Collection.ItemAt, ebx)
    .ifBitSet [xax].$Obj(ChartSeries).dFlags, CHT_SERIES_SHOW_TAB
      mov pTabSeries, $New(ChartFlatTabSeries)
      lea xdx, [xsi].TabControl
      OCall pTabSeries::ChartFlatTabSeries.Init, xdx, pSeries
      OCall pTabSeries::ChartFlatTabSeries.Show
      mov xcx, pTabSeries
      invoke ShowWindow, [xcx].$Obj(ChartFlatTabSeries).hWnd, SW_HIDE
      OCall [xsi].TabSeriesColl::Collection.Insert, pTabSeries
      mov xcx, pTabSeries
      m2m hWnd, [xcx].$Obj(ChartFlatTabSeries).hWnd, xdx
      FillWord cBuffer, <Series >
      lea edx, [ebx + 1]
      invoke dword2dec, addr cBuffer[sizeof(CHR)*7], edx
      mov edx, dTabCount
      add edx, ebx
      OCall [xsi].TabControl::TabCtrl.Insert, edx, hWnd, addr cBuffer, 3
      .if [xsi].dTabID == ebx
        mov dSelTabIndex, eax
        mov xcx, pTabSeries
        m2m hSelTabWnd, [xcx].$Obj(ChartFlatTabSeries).hWnd, eax
      .endif
      inc dTabCount
    .endif
    inc ebx
  .endw

  .if dTabCount != 0
    invoke SendMessage, [xsi].TabControl.hWnd, TCM_SETCURSEL, dSelTabIndex, 0
    invoke ShowWindow, hSelTabWnd, SW_SHOWDEFAULT
  .endif

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatSetup.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatSetup.Restore, uses xbx xsi
  SetObject xsi
  OCall [xsi].TabGeneral::ChartFlatTabGeneral.Restore
  OCall [xsi].TabScaleX::ChartFlatTabScale.Restore
  OCall [xsi].TabScaleY1::ChartFlatTabScale.Restore
  mov ebx, [xsi].TabSeriesColl.dCount
  .while ebx != 0
    dec ebx
    OCall [xsi].TabSeriesColl::Collection.ItemAt, ebx
    OCall xax::ChartFlatTabSeries.Restore
  .endw
MethodEnd

