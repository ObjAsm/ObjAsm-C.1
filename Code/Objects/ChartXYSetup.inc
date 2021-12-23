; ==================================================================================================
; Title:      ChartXYSetup.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartXYSetup objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartXYSetup implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYSetup.CtlsGet, uses xbx xsi
  SetObject xsi
  ACall xsi.CtlsGet
  mov ebx, [xsi].TabSeriesColl.dCount
  .while ebx != 0
    dec ebx
    OCall [xsi].TabSeriesColl::Collection.ItemAt, ebx
    OCall xax::ChartXYTabSeries.CtlsGet
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method ChartXYSetup.CtlsSet, uses xbx xsi
  SetObject xsi
  mov ebx, [xsi].TabSeriesColl.dCount
  .while ebx != 0
    dec ebx
    OCall [xsi].TabSeriesColl::Collection.ItemAt, ebx
    OCall xax::ChartXYTabSeries.CtlsSet
  .endw
  ACall xsi.CtlsSet
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.Done
; Purpose:    Finalize the ChartXYSetup object.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYSetup.Done, uses xsi
  SetObject xsi
  OCall [xsi].TabSeriesColl::Collection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.Init
; Purpose:    Initialaize a ChartXYSetup object.
; Arguments:  Arg1: -> Owner object (ChartWnd).
;             Arg2: -> Parent window HANDLE.
;             Arg3: Tab ID to show.
; Return:     Nothing.

Method ChartXYSetup.Init, uses xsi, pOwner:POINTER, hParent:HWND, dTabID:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, dTabID
  OCall [xsi].TabSeriesColl::Collection.Init, xsi, 2, 1, COL_MAX_CAPACITY
  OCall [xsi].IconImageList::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SERIESXY")
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.InitMoreTabs
; Purpose:    Initialize more tabs.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYSetup.InitMoreTabs, uses xbx xdi xsi
  local cBuffer[20]:CHR, pTabSeries:$ObjPtr(ChartXYTabSeries)
  local hWnd:HWND, pSeries:$ObjPtr(ChartXYSeries)

  SetObject xsi
  mov xdi, [xsi].pOwner

  xor ebx, ebx
  .while ebx < [xdi].$Obj(ChartXYWnd).Data.dCount
    mov pSeries, $OCall([xdi].$Obj(ChartXYWnd).Data::Collection.ItemAt, ebx)
    .ifBitSet [xax].$Obj(ChartXYSeries).dFlags, CHT_SERIES_SHOW_TAB
      mov pTabSeries, $New(ChartXYTabSeries)
      lea xdx, [xsi].TabControl
      OCall pTabSeries::ChartXYTabSeries.Init, xdx, pSeries
      OCall pTabSeries::ChartXYTabSeries.Show
      mov xcx, pTabSeries
      invoke ShowWindow, [xcx].$Obj(ChartXYTabSeries).hWnd, SW_HIDE
      OCall [xsi].TabSeriesColl::Collection.Insert, pTabSeries
      mov xcx, pTabSeries
      m2m hWnd, [xcx].$Obj(ChartXYTabSeries).hWnd, xdx
      FillWord cBuffer, <Series >
      lea edx, [ebx + 1]
      invoke dword2dec, addr cBuffer[sizeof(CHR)*7], edx
      OCall [xsi].TabControl::TabCtrl.Insert, [xsi].dTabCount, hWnd, addr cBuffer, 3
      .if [xsi].dTabID == ebx
        mov [xsi].dSelTabIndex, eax
        mov xcx, pTabSeries
        m2m [xsi].hSelTabWnd, [xcx].$Obj(ChartXYTabSeries).hWnd, edx
      .endif
      .if eax != -1
        inc [xsi].dTabCount
      .endif
    .endif
    inc ebx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSetup.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYSetup.Restore, uses xbx xsi
  SetObject xsi
  OCall [xsi].TabGeneral::ChartTabGeneral.Restore
  OCall [xsi].TabScaleX::ChartTabScale.Restore
  OCall [xsi].TabScaleY1::ChartTabScale.Restore
  mov ebx, [xsi].TabSeriesColl.dCount
  .while ebx != 0
    dec ebx
    OCall [xsi].TabSeriesColl::Collection.ItemAt, ebx
    OCall xax::ChartXYTabSeries.Restore
  .endw
MethodEnd