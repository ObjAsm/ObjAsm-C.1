; ==================================================================================================
; Title:      ChartXY.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm cluster to support XY-chart objects and their setup.
; Notes:      Version C.1.0, August 2021
;               - First release.
;                 Line clipping is implemented using the Liang-Barsky algorithm.
;                 https://www.skytopia.com/project/articles/compsci/clipping.html
;                 https://arxiv.org/pdf/1908.01350.pdf
;                 To speedup the line rendering, line clipping is implemented using an algorithm
;                 described here https://arxiv.org/pdf/1908.01350.pdf
; ==================================================================================================



;Marker type enumeration
CHTXY_MARKER_SQUARE       equ   0
CHTXY_MARKER_RECT_HOR     equ   1
CHTXY_MARKER_RECT_VER     equ   2
CHTXY_MARKER_CIRCLE       equ   3
CHTXY_MARKER_ELLIPSE_HOR  equ   4
CHTXY_MARKER_ELLIPSE_VER  equ   5
CHTXY_MARKER_RHOMBUS      equ   6
CHTXY_MARKER_RHOMBUS_HOR  equ   7
CHTXY_MARKER_RHOMBUS_VER  equ   8
CHTXY_MARKER_CROSS        equ   9
CHTXY_MARKER_STAR_4       equ   10
CHTXY_MARKER_STAR_8       equ   11

SeriesSetupXY struct
  dLineWidth          DWORD       ?
  dLineStyle          DWORD       ?
  LineColor           COLORREF    ?
  dMarkerSize         DWORD       ?
  dMarkerShape        DWORD       ?
  MarkerFillColor     COLORREF    ?
  MarkerBorderColor   COLORREF    ?
  dMarkerBorderWidth  DWORD       ?
SeriesSetupXY ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartXYSeries
; Purpose: Implement a data series for plot usage.
; Note:    - Data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.
;          - The generic memory layout is [(x0, y0), (x1, y1), (x2, y2), ...]

Object ChartXYSeries, ChartXYSeriesID, ChartSeries
  RedefineMethod    Load,               $ObjPtr(Stream)             ;-> Stream
  RedefineMethod    Scan,               DWORD, DWORD                ;Scan the buffer from, count
  RedefineMethod    Store,              $ObjPtr(Stream)             ;-> Stream

  DefineVariable    dDataMaxXIndex,     DWORD,      -1              ;Biggest data element index
  DefineVariable    dDataMinXIndex,     DWORD,      -1              ;Smallest data element index
  DefineVariable    dDataMaxYIndex,     DWORD,      -1              ;Biggest data element index
  DefineVariable    dDataMinYIndex,     DWORD,      -1              ;Smallest data element index

  DefineVariable    Setup,              SeriesSetupXY,    {1, PS_SOLID, 0, 11, 0, 00FFFFFFh, 0, 1}
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartXYWnd
; Purpose: This object draws a XY plot on a surface. It works using the ChartXYSeries object, that
;          holds the information for each data line on the plot. 2 specialized dialogs,
;          DialogChartScaleSetup and DialogChartSetup are used to customize the drawing.
;          They are called when the user doubleclicks on some plot element.
;          Simple drag mouse movements moves the plot area, while pressing the SHIFT key, the plot
;          area is resized.
; Note:    - X and Y data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.

Object ChartXYWnd, ChartXYWndID, ChartWnd
  RedefineMethod    DrawSeries,         HDC, $ObjPtr(ChartXYSeries) ;hDC, -> ChartXYSeries
  VirtualMethod     DrawMarkerAt,       HDC, $ObjPtr(ChartXYSeries), SDWORD, SDWORD
  RedefineMethod    GetDataTipText,     PSTRING, $ObjPtr(ChartSeries), DWORD
  RedefineMethod    Init,               POINTER, HWND, PDEF_CHART
  RedefineMethod    ShowSetupDlg,       SDWORD, SDWORD, DWORD
  StaticMethod      Startup
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartXYTabSeries
; Purpose:    Series Tab of ChartSetup.

Object ChartXYTabSeries, , DialogModeless
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, $ObjPtr(ChartXYSeries)
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  VirtualMethod     Restore

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC

  DefineVariable    pChartSeries,       $ObjPtr(ChartXYSeries),   NULL
  DefineVariable    pLocalName,         PSTRING,    NULL            ;-> Series name
  DefineVariable    pLocalDescription,  PSTRING,    NULL            ;-> Series description
  DefineVariable    LocalSetup,         SeriesSetupXY,    {}
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartXYSetup
; Purpose:    Custom Setup dialog.

Object ChartXYSetup, , ChartSetup
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

CStr szChartXY, "ChartXY"

% include &ObjPath&ChartXYSeries.inc
% include &ObjPath&ChartXYWnd.inc
% include &ObjPath&ChartXYTabSeries.inc
% include &ObjPath&ChartXYSetup.inc

endif
