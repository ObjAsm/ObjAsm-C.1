; ==================================================================================================
; Title:      Chart.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm cluster to support chart base objects and their setup.
; Notes:      Version 1.0.0, August 2021
;               - First release. This code is based on the legacy PlotXY object.
;                 The ChartWnd object has the ability to pan and zoom the plot area.
;                 It reacts in different ways according to the mouse position on different chart
;                 areas like the scales or plot.
;                 The flags CHT_FLAG_ZOOMABLE and CHT_FLAG_PANABLE control these features.
;                 If activated, the following rules apply:
;                   - pressing the CTRL key, a zooming action is performed
;                   - pressing the SHIFT key, actions apply on the x axis, otherwise to the y axis
;                 Touchpad or touch display gestures are also supported.
;                 A double-click on the plot area shows up, if activated, the color setting dialog.
;                 A double-click on a scale shows up, if activated, the scale setup dialog.
;                 Holding down the CTRL key and double-clicking a scale will reset it to the
;                 auto max & min values.
; ==================================================================================================



CHT_FLOAT textequ <REAL4>

DEF_CHART struc
  xCtlID        XWORD     ?                             ;Contol ID
  dStyle        DWORD     ?                             ;Style
  dExStyle      DWORD     ?                             ;Extended style
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?                             ;X position
      sdPosY    SDWORD    ?                             ;Y position
      dWidth    DWORD     ?                             ;Width
      dHeight   DWORD     ?                             ;Height
    ends
  ends
DEF_CHART ends
PDEF_CHART typedef ptr DEF_CHART

CHT_SERIES_SHOW_DEPICTION   equ   BIT00                 ;Bar, Line, etc.
CHT_SERIES_SHOW_MARKER      equ   BIT01
CHT_SERIES_SHOW_TAB         equ   BIT02                 ;Show series tab on the setup dialog

CHT_SERIES_DEFAULT_FLAGS equ CHT_SERIES_SHOW_DEPICTION or CHT_SERIES_SHOW_MARKER or CHT_SERIES_SHOW_TAB

CHT_SCALE_AUTO_MIN          equ   BIT00
CHT_SCALE_AUTO_MAX          equ   BIT01
CHT_SCALE_AUTO_MJR_DIV      equ   BIT02
CHT_SCALE_AUTO_MNR_DIV      equ   BIT03
CHT_SCALE_SHOW_MJR_GRID     equ   BIT04
CHT_SCALE_SHOW_MNR_GRID     equ   BIT05
CHT_SCALE_SHOW_MJR_DIV      equ   BIT06
CHT_SCALE_SHOW_MNR_DIV      equ   BIT07
CHT_SCALE_SHOW_LABEL        equ   BIT08
CHT_SCALE_SHOW_TITLE        equ   BIT09
CHT_SCALE_SHOW_AS_DATE      equ   BIT10                 ;Int(VARINAT time), zero @ 30.12.1899
CHT_SCALE_SHOW_AS_DATEDIFF  equ   BIT11
CHT_SCALE_SHOW_AS_TIME      equ   BIT12                 ;Frac(VARINAT time)
CHT_SCALE_SHOW_TAB          equ   BIT13                 ;Show scale tab on the setup dialog

CHT_DEFAULT_SCALE_FLAGS = CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX or \
                          CHT_SCALE_AUTO_MJR_DIV or CHT_SCALE_AUTO_MNR_DIV or \
                          CHT_SCALE_SHOW_MJR_GRID or CHT_SCALE_SHOW_MNR_GRID or \
                          CHT_SCALE_SHOW_MJR_DIV or CHT_SCALE_SHOW_MNR_DIV or \
                          CHT_SCALE_SHOW_LABEL or CHT_SCALE_SHOW_TITLE or \
                          CHT_SCALE_SHOW_TAB

CHT_FLAG_SELF_INST          equ   BIT00                 ;Object was instanced by CreateWindowEx
CHT_FLAG_PANABLE            equ   BIT01                 ;Plot is panable
CHT_FLAG_ZOOMABLE           equ   BIT02                 ;Plot is zoomable
CHT_FLAG_COLOR              equ   BIT03                 ;Color or B&W output
CHT_FLAG_SHOW_GENERAL_TAB   equ   BIT04                 ;Show the general tab on the setup dialog
CHT_FLAG_CTRL_DBLCLK        equ   BIT05                 ;Enable CTRL double click to center scale
CHT_FLAG_DATA_TOOLTIPS_SHOW equ   BIT06                 ;Enable ToolTips showing data information
CHT_FLAG_TOOLTIP_ACTIVE     equ   BIT07                 ;Helper, TooTip activation
CHT_FLAG_TOOLTIP_SHOW       equ   BIT08                 ;Helper, ToolTip visibility

CHT_DEFAULT_FLAGS = CHT_FLAG_PANABLE or CHT_FLAG_ZOOMABLE or CHT_FLAG_COLOR or \
                    CHT_FLAG_SHOW_GENERAL_TAB or CHT_FLAG_CTRL_DBLCLK or \
                    CHT_FLAG_DATA_TOOLTIPS_SHOW

CHT_SCALE_STRINGS struc
  pDescription      PSTRING     NULL                    ;-> Description string
  pUnit             PSTRING     NULL                    ;-> Unit string
CHT_SCALE_STRINGS ends

CHT_SCALE_BASIC_DATA struc
  dFlags            DWORD       CHT_DEFAULT_SCALE_FLAGS ;Scale options
  fSetupMax         CHT_FLOAT   1.0                     ;Setup max value
  fSetupMin         CHT_FLOAT   0.0                     ;Setup min value
  fDataMax          CHT_FLOAT   1.0                     ;Data max value
  fDataMin          CHT_FLOAT   0.0                     ;Data min value
  dSetupMjrDiv      DWORD       2                       ;Setup major divisions
  dSetupMnrDiv      DWORD       2                       ;Setup minor divisions
  dDataMjrDiv       DWORD       2                       ;Data major divisions
  dDataMnrDiv       DWORD       2                       ;Data minor divisions
  dGridMjrLineSize  DWORD       1
  dGridMjrLineStyle DWORD       PS_DASH
  dGridMnrLineSize  DWORD       1
  dGridMnrLineStyle DWORD       PS_DASH
  CHT_SCALE_STRINGS             {}
CHT_SCALE_BASIC_DATA ends
PCHT_SCALE_BASIC_DATA typedef ptr CHT_SCALE_BASIC_DATA

CHT_SCALE_INTERNAL_DATA struc                           ;Do not use directly, internal data
  dID               DWORD       0                       ;E.g.: CHT_ID_SCALEX
  dDecimals         DWORD       1                       ;Nr of decimal digits used to draw labels
  fScaleMax         CHT_FLOAT   1.0                     ;Max used for drawing scale
  fScaleMin         CHT_FLOAT   0.0                     ;Min used for drawing scale
  fDivMjrFst        CHT_FLOAT   0.0                     ;Value of first major division in plot range
  fDivMjrStp        CHT_FLOAT   0.0                     ;Value major division step
  dDivMjrLen        DWORD       0                       ;Size of major division
  dDivMnrLen        DWORD       0                       ;Size of minor division
  dDivMnrCount      DWORD       0                       ;Number of minor divs between major divs
  dTitleSep         DWORD       0                       ;Separation between title and labels
  dLabelSep         DWORD       0                       ;Separation between labels and divisions
  pTitle            PSTRING     NULL                    ;Title string (local allocated)
  fScaleFactor      CHT_FLOAT   1.0                     ;Scale drawing factor
CHT_SCALE_INTERNAL_DATA ends
PCHT_SCALE_INTERNAL_DATA typedef ptr CHT_SCALE_INTERNAL_DATA

CHT_SCALE_DATA struc
  CHT_SCALE_BASIC_DATA        {}
  CHT_SCALE_INTERNAL_DATA     {}
CHT_SCALE_DATA ends
PCHT_SCALE_DATA typedef ptr CHT_SCALE_DATA

CHT_COLOR_CONFIG struc
  MjrGrid         COLORREF    $RGB(191,191,191)         ;Major grid color
  MnrGrid         COLORREF    $RGB(235,235,235)         ;Minor grid color
  PlotArea        COLORREF    $RGB(255,255,255)         ;Plot area color
  PlotBorder      COLORREF    $RGB(128,128,128)         ;Plot border color
  Scales          COLORREF    $RGB(096,096,096)         ;Scale divisions, labels and titles
  Background      COLORREF    $RGB(240,240,240)         ;Background color
CHT_COLOR_CONFIG ends
PCHT_COLOR_CONFIG typedef ptr CHT_COLOR_CONFIG


;CHT_ID identify different parts of the chart.
;Positive numbers denote chart series 0..ChartWnd.Data.dCount - 1
CHT_ID_NONE       equ     -1
CHT_ID_SCALEX     equ     -2
CHT_ID_SCALEY1    equ     -3
CHT_ID_SCALEY2    equ     -4
CHT_ID_PLOT       equ     -5

externdef $ObjTmpl(Application):$Obj(WinApp)

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartSeries
; Purpose: Implement a data series for plot usage.
; Note:    - Data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.
;          - The generic memory layout is [(x0, y0, z0), (x1, y1, z1), (x2, y2, z3), ...]

Object ChartSeries, ChartSeriesID, Array
  RedefineMethod    Done                                            ;Release allocated resources
  RedefineMethod    Init,               POINTER, DWORD              ;-> Owner, Capacity
  RedefineMethod    Load,               $ObjPtr(Stream)             ;-> Stream
  DynamicAbstract   Scan,               DWORD, DWORD                ;Scan the buffer from, count
  RedefineMethod    Store,              $ObjPtr(Stream)             ;-> Stream

  DefineVariable    dDataFrom,          DWORD,      0               ;First Data index
  DefineVariable    dDataCount,         DWORD,      0               ;Number of (x,y) points

  DefineVariable    dFlags,             DWORD,      CHT_SERIES_DEFAULT_FLAGS
  DefineVariable    pName,              PSTRING,    NULL            ;-> Series name
  DefineVariable    pDescription,       PSTRING,    NULL            ;-> Series description
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartWnd
; Purpose: This object is the base for all flat chart descendants.
;          It works using the ChartSeries object, that holds the information for each data
;          representation.
;          DialogChartScaleSetup and DialogChartSetup are used to customize the drawing. They are called
;          when the user doubleclicks on some of the chart elements.
;          Mouse drag actions move the chart area. Pressing simulaneously the CONTROL key, the chart
;          area is resized.
; Note:    - X and Y data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.

Object ChartWnd, ChartWndID, Window
  VirtualMethod     Calc,               HDC, PRECT
  VirtualMethod     CalcScaleDivs,      PCHT_SCALE_DATA
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  VirtualMethod     DrawFrame,          HDC                           ;hDC
  VirtualAbstract   DrawSeries,         HDC, $ObjPtr(ChartSeries)     ;hDC, -> ChartSeries
  DynamicMethod     GetDataTipText,     PSTRING, $ObjPtr(ChartSeries), DWORD
  RedefineMethod    Load,               $ObjPtr(Stream), PDESER_INFO  ;-> Stream
  VirtualMethod     Refresh
  VirtualMethod     Show,               HDC, PRECT
  VirtualMethod     ShowSetupDlg,       SDWORD, SDWORD, DWORD
  RedefineMethod    Store,              $ObjPtr(Stream)               ;-> Stream

  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnGesture,          WM_GESTURE
  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE
  VirtualEvent      OnMouseWheel,       WM_MOUSEWHEEL
  VirtualEvent      OnLButtonDblClk,    WM_LBUTTONDBLCLK
  VirtualEvent      OnLButtonDown,      WM_LBUTTONDOWN
  VirtualEvent      OnLButtonUp,        WM_LBUTTONUP
  VirtualEvent      OnNotify,           WM_NOTIFY
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    dFlags,             DWORD,            CHT_DEFAULT_FLAGS
  DefineVariable    ScaleX,             CHT_SCALE_DATA,   {{},{CHT_ID_SCALEX}}
  DefineVariable    ScaleY1,            CHT_SCALE_DATA,   {{},{CHT_ID_SCALEY1}}
  DefineVariable    Colors,             CHT_COLOR_CONFIG, {}

  DefineVariable    ViewRect,           RECT,             {}
  DefineVariable    Padding,            RECT,             {}
  DefineVariable    DrawRect,           RECT,             {}          ;DrawRect = ViewRect - Padding
  DefineVariable    PlotRect,           RECT,             {}
  DefineVariable    hFontHorz,          HFONT,            0           ;Horizontal font
  DefineVariable    hFontVert,          HFONT,            0           ;Vertical font
  DefineVariable    TextMetricHorz,     TEXTMETRIC,       {}
  DefineVariable    TextMetricVert,     TEXTMETRIC,       {}
  DefineVariable    sbMovingOn,         SBYTE,            CHT_ID_NONE ;Selected element
  DefineVariable    LastCursorPos,      POINT,            {}
  DefineVariable    dGestureZoomFirst,  DWORD,            0
  DefineVariable    dGestureZoomLast,   DWORD,            0
  DefineVariable    hToolTip,           HWND,             0

  Embed   Data,       Collection                                      ;Collection of ChartSeries
  Embed   InfoAreas,  DataCollection                                  ;Datacollection of InfoAreaXX
ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartTabGeneral
; Purpose:    Color Tab of ChartSetup.

Object ChartTabGeneral, , DialogModeless
  RedefineMethod    Init,               POINTER, $ObjPtr(ChartWnd)
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  VirtualMethod     Restore

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC

  DefineVariable    LocalColors,        CHT_COLOR_CONFIG,   {}
  DefineVariable    pChartWnd,          $ObjPtr(ChartWnd),  NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartTabScale
; Purpose:    Scale Tab of ChartSetup.

Object ChartTabScale, , DialogModeless
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, PCHT_SCALE_DATA
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  VirtualMethod     Restore

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC

  DefineVariable    pScaleData,         PCHT_SCALE_DATA,  NULL
  DefineVariable    pLocalDescription,  PSTRING,          NULL
  DefineVariable    pLocalUnit,         PSTRING,          NULL
  DefineVariable    LocalScaleData,     CHT_SCALE_BASIC_DATA, {}    ;Only basic data!
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartSetup
; Purpose:    Custom Setup dialog.

Object ChartSetup, , DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, DWORD
  VirtualAbstract   InitMoreTabs
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  VirtualMethod     Restore

  DefineVariable    dTabID,             DWORD,  CHT_ID_NONE
  DefineVariable    dTabCount,          DWORD,  0
  DefineVariable    dSelTabIndex,       DWORD,  0
  DefineVariable    hSelTabWnd,         HWND,   0

  Embed     TabControl,       TabCtrl
  Embed     TabGeneral,       ChartTabGeneral
  Embed     TabScaleX,        ChartTabScale
  Embed     TabScaleY1,       ChartTabScale
  Embed     IconImageList,    MaskedImageList
ObjectEnd



; ==================================================================================================

if IMPLEMENT

InfoArea struct
  Area        RECT    {}
  dDataIndex  DWORD   ?
  pSeries     $ObjPtr(ChartSeries) ?
InfoArea ends

% include &ObjPath&ChartSeries.inc
% include &ObjPath&ChartWnd.inc
% include &ObjPath&ChartTabGeneral.inc
% include &ObjPath&ChartTabScale.inc
% include &ObjPath&ChartSetup.inc

endif
