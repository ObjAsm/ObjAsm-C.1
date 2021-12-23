; ==================================================================================================
; Title:      ChartBar.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm cluster to support Bar-chart objects and their setup.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



SeriesSetupBar struct
  dBarWidth          DWORD      ?
  dBarOffset         DWORD      ?
  dBorderWidth       DWORD      ?
  dBorderStyle       DWORD      ?
  BorderColor        COLORREF   ?
  FillColorFore      COLORREF   ?
  FillColorBack      COLORREF   ?
  dFillStyle         DWORD      ?
SeriesSetupBar ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartBarSeries
; Purpose: Implement a data series for plot usage.
; Note:    - Data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.
;          - The generic memory layout is [(x0, y0), (x1, y1), (x2, y2), ...]

Object ChartBarSeries, ChartBarSeriesID, ChartSeries
  RedefineMethod    Load,               $ObjPtr(Stream)             ;-> Stream
  RedefineMethod    Scan,               DWORD, DWORD                ;Scan the buffer from, count
  RedefineMethod    Store,              $ObjPtr(Stream)             ;-> Stream

  DefineVariable    dDataMaxXIndex,     DWORD,      -1              ;Biggest data element index
  DefineVariable    dDataMinXIndex,     DWORD,      -1              ;Smallest data element index
  DefineVariable    dDataMaxYIndex,     DWORD,      -1              ;Biggest data element index
  DefineVariable    dDataMinYIndex,     DWORD,      -1              ;Smallest data element index

  DefineVariable    Setup,    SeriesSetupBar,     {20, 0, 1, PS_SOLID, 0, 00FFFFFFh, 00FFFFFFh, -1}
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartBarWnd
; Purpose: This object draws a Bar diagram on a surface. It works using the ChartBarSeries object,
;          that holds the information for each data line on the plot. 2 specialized dialogs,
;          DialogChartScaleSetup and DialogChartSetup are used to customize the drawing.
;          They are called when the user doubleclicks on some plot element.
;          Simple drag mouse movements moves the plot area, while pressing the SHIFT key, the plot
;          area is resized.
; Note:    - X and Y data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.

Object ChartBarWnd, ChartBarWndID, ChartWnd
  RedefineMethod    DrawSeries,         HDC, $ObjPtr(ChartBarSeries) ;hDC, -> ChartBarSeries
  RedefineMethod    Init,               POINTER, HWND, PDEF_CHART
  RedefineMethod    GetDataTipText,     PSTRING, $ObjPtr(ChartSeries), DWORD
  RedefineMethod    ShowSetupDlg,       SDWORD, SDWORD, DWORD
  StaticMethod      Startup
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartBarTabSeries
; Purpose:    Series Tab of ChartSetup.

Object ChartBarTabSeries, , DialogModeless
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, $ObjPtr(ChartBarSeries)
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  VirtualMethod     Restore

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC

  DefineVariable    pChartSeries,       $ObjPtr(ChartBarSeries),   NULL
  DefineVariable    pLocalName,         PSTRING,    NULL            ;-> Series name
  DefineVariable    pLocalDescription,  PSTRING,    NULL            ;-> Series description
  DefineVariable    LocalSetup,         SeriesSetupBar,   {}
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartBarSetup
; Purpose:    Custom Setup dialog.

Object ChartBarSetup, , ChartSetup
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, DWORD
  RedefineMethod    InitMoreTabs                        ;Callback from ChartSetup.OnInitDialog
  RedefineMethod    Restore

  Embed     TabSeriesColl,    Collection
ObjectEnd


; ==================================================================================================


if IMPLEMENT

CStr szChartBar, "ChartBar"

% include &ObjPath&ChartBarSeries.inc
% include &ObjPath&ChartBarWnd.inc
% include &ObjPath&ChartBarTabSeries.inc
% include &ObjPath&ChartBarSetup.inc

endif
