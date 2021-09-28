; ==================================================================================================
; Title:      ChartFlat.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartFlat objects.
; Notes:      Version 1.0.0, August 2021
;               - First release. This code is based on the legacy PlotXY object.
;                 This object has the ability to pan and zoom the plot area. It reacts in different
;                 ways according to the mouse position on different chart areas loke scales or plot.
;                 The flags CHT_FLAG_ZOOMABLE and CHT_FLAG_PANABLE control these features.
;                 If activated, the following rules apply:
;                   - pressing the CTRL key, a zooming action is performed
;                   - pressing the SHIFT key, actions apply on the x axis, otherwise to the y axis
;                 Touchpad or touch display gestures are also supported.
;                 A double-click on the plot area shows up, if activated, the color setting dialog.
;                 A double-click on a scale shows up, if activated, the scale setup dialog.
;                 Holding down the CTRL key and double-clicking a scale will reset it to the
;                 auto max & min values.
;                 To seedup the line rendering, line clipping is implemented using an algorithm
;                 described here https://arxiv.org/pdf/1908.01350.pdf
; ==================================================================================================



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

CHT_DEFAULT_FLAGS = CHT_FLAG_PANABLE or CHT_FLAG_ZOOMABLE or CHT_FLAG_COLOR or \
                    CHT_FLAG_SHOW_GENERAL_TAB or CHT_FLAG_CTRL_DBLCLK

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
;Positive numbers denote chart series 0..ChartFlat.Data.dCount - 1
CHT_ID_NONE       equ     -1
CHT_ID_SCALEX     equ     -2
CHT_ID_SCALEY1    equ     -3
CHT_ID_SCALEY2    equ     -4
CHT_ID_PLOT       equ     -5

externdef $ObjTmpl(Application):$Obj(WinApp)

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartFlat
; Purpose: This object is the base for all flat chart descendants.
;          It works using the ChartSeries object, that holds the information for each data
;          representation.
;          DialogChartScaleSetup and DialogChartSetup are used to customize the drawing. They are called
;          when the user doubleclicks on some of the chart elements.
;          Mouse drag actions move the chart area. Pressing simulaneously the CONTROL key, the chart
;          area is resized.
; Note:    - X and Y data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.

Object ChartFlat, ChartFlatID, Window
  VirtualMethod     Calc,               HDC, PRECT
  VirtualMethod     CalcScaleDivs,      PCHT_SCALE_DATA
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  VirtualMethod     DrawFrame,          HDC                         ;hDC
  VirtualAbstract   DrawSeries,         HDC, $ObjPtr(ChartSeries)   ;hDC, -> ChartSeries
  VirtualMethod     Refresh
  VirtualMethod     Show,               HDC, PRECT

  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnGesture,          WM_GESTURE
  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE
  VirtualEvent      OnMouseWheel,       WM_MOUSEWHEEL
  VirtualEvent      OnLButtonDblClk,    WM_LBUTTONDBLCLK
  VirtualEvent      OnLButtonDown,      WM_LBUTTONDOWN
  VirtualEvent      OnLButtonUp,        WM_LBUTTONUP
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    dFlags,             DWORD,            CHT_DEFAULT_FLAGS
  DefineVariable    ScaleX,             CHT_SCALE_DATA,   {{},{CHT_ID_SCALEX}}
  DefineVariable    ScaleY1,            CHT_SCALE_DATA,   {{},{CHT_ID_SCALEY1}}
  DefineVariable    Colors,             CHT_COLOR_CONFIG, {}

  DefineVariable    ViewRect,           RECT,             {}
  DefineVariable    Padding,            RECT,             {}
  DefineVariable    DrawRect,           RECT,             {}        ;DrawRect = ViewRect - Padding
  DefineVariable    PlotRect,           RECT,             {}
  DefineVariable    hFontHorz,          HFONT,            0         ;Horizontal font
  DefineVariable    hFontVert,          HFONT,            0         ;Vertical font
  DefineVariable    TextMetricHorz,     TEXTMETRIC,       {}
  DefineVariable    TextMetricVert,     TEXTMETRIC,       {}
  DefineVariable    bMovingOn,          BYTE,             CHT_ID_NONE ;Selected element
  DefineVariable    MovedLastPoint,     POINT,            {}
  DefineVariable    dGestureZoomFirst,  DWORD,            0
  DefineVariable    dGestureZoomLast,   DWORD,            0

  Embed    Data,    Collection                                      ;Collection of ChartSeries
ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartFlatTabGeneral
; Purpose:    Color Tab of ChartFlatSetup.

Object ChartFlatTabGeneral, , DialogModeless
  RedefineMethod    Init,               POINTER, $ObjPtr(ChartFlat)
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  VirtualMethod     Restore

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC

  DefineVariable    LocalColors,        CHT_COLOR_CONFIG,     {}
  DefineVariable    pChartFlat,         $ObjPtr(ChartFlat),   NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartFlatTabScale
; Purpose:    Scale Tab of ChartFlatSetup.

Object ChartFlatTabScale, , DialogModeless
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, PCHT_SCALE_DATA
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
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
; Object:     ChartFlatTabSeries
; Purpose:    Series Tab of ChartFlatSetup.

Object ChartFlatTabSeries, , DialogModeless
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, $ObjPtr(ChartSeries)
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  VirtualMethod     Restore

  VirtualEvent      OnCtlColorDlg,      WM_CTLCOLORDLG, WM_CTLCOLORSTATIC

  DefineVariable    pLocalName,         PSTRING,    NULL            ;-> Series name
  DefineVariable    pLocalDescription,  PSTRING,    NULL            ;-> Series description

  DefineVariable    LocalLineColor,     COLORREF,   $RGB(000,000,000)
  DefineVariable    dLocalLineWidth,    DWORD,      1
  DefineVariable    dLocalLineStyle,    DWORD,      PS_SOLID

  DefineVariable    LocalMarkerBorderColor,   COLORREF,   $RGB(000,000,000)
  DefineVariable    dLocalMarkerBorderWidth,  DWORD,      1
  DefineVariable    LocalMarkerFillColor,     COLORREF,   $RGB(255,255,255)
  DefineVariable    dLocalMarkerSize,   DWORD,      11
  DefineVariable    dLocalMarkerShape,  DWORD,      0

  DefineVariable    pChartSeries,       $ObjPtr(ChartSeries),   NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     ChartFlatSetup
; Purpose:    Custom Setup dialog.

Object ChartFlatSetup, , DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, DWORD
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  VirtualMethod     Restore

  DefineVariable    dTabID,             DWORD,  CHT_ID_NONE

  Embed     TabControl,       TabCtrl
  Embed     TabGeneral,       ChartFlatTabGeneral
  Embed     TabScaleX,        ChartFlatTabScale
  Embed     TabScaleY1,       ChartFlatTabScale
  Embed     TabSeriesColl,    Collection
  Embed     IconImageList,    MaskedImageList
ObjectEnd



; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    ChartFlat implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.Calc
; Purpose:    Compute internal values of the plot.
; Arguments:  Arg1: Output device context.
;             Arg2: -> Output rect.
; Return:     Nothing.

Method ChartFlat.Calc, uses xbx xdi xsi, hDC:HWND, pOutRect:PRECT
  local TextSize1:POINT, TextSize2:POINT, hPrevFont:HFONT
  local cBuffer[1024]:CHR, dValue:DWORD

  ;DbgText "ChartFlat.Calc"
  SetObject xsi
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontHorz)

  ;Set ViewRect = OutRect and DrawRect = ViewRect - Padding
  mov xbx, pOutRect
  mrm [xsi].ViewRect.left, [xbx].RECT.left, eax
  add eax, [xsi].Padding.left
  mov [xsi].DrawRect.left, eax
  mrm [xsi].ViewRect.top, [xbx].RECT.top, eax
  add eax, [xsi].Padding.top
  mov [xsi].DrawRect.top, eax
  mrm [xsi].ViewRect.right, [xbx].RECT.right, eax
  sub eax, [xsi].Padding.right
  mov [xsi].DrawRect.right, eax
  mrm [xsi].ViewRect.bottom, [xbx].RECT.bottom, eax
  sub eax, [xsi].Padding.bottom
  mov [xsi].DrawRect.bottom, eax

  ;Set scale titles -------------------------------------------------
  lea xdi, cBuffer

  m2z CHR ptr [xdi]                                     ;Set first CHR to zero
  .if [xsi].ScaleX.pDescription != NULL
    .if $invoke(StrLength, [xsi].ScaleX.pDescription)
      invoke StrCCopy, xdi, [xsi].ScaleX.pDescription, lengthof cBuffer
    .endif
  .endif
  .if [xsi].ScaleX.pUnit != NULL
    .if $invoke(StrLength, [xsi].ScaleX.pUnit)
      .if [xsi].ScaleX.pDescription != NULL
        .if $invoke(StrLength, [xsi].ScaleX.pDescription)
          invoke StrCCatChar, xdi, " ", lengthof cBuffer
        .endif
      .endif
      invoke StrCCatChar, xdi, "[", lengthof cBuffer
      invoke StrCCat, xdi, [xsi].ScaleX.pUnit, lengthof cBuffer
      invoke StrCCatChar, xdi, "]", lengthof cBuffer
    .endif
  .endif
  invoke StrDispose, [xsi].ScaleX.pTitle
  mov [xsi].ScaleX.pTitle, $invoke(StrNew, xdi)

  m2z CHR ptr [xdi]                                     ;Set first CHR to zero
  .if [xsi].ScaleY1.pDescription != NULL
    .if $invoke(StrLength, [xsi].ScaleY1.pDescription)
      invoke StrCCopy, xdi, [xsi].ScaleY1.pDescription, lengthof cBuffer
    .endif
  .endif
  .if [xsi].ScaleY1.pUnit != NULL
    .if $invoke(StrLength, [xsi].ScaleY1.pUnit)
      .if [xsi].ScaleY1.pDescription != NULL
        .if $invoke(StrLength, [xsi].ScaleY1.pDescription)
          invoke StrCCatChar, xdi, " ", lengthof cBuffer
        .endif
      .endif
      invoke StrCCatChar, xdi, "[", lengthof cBuffer
      invoke StrCCat, xdi, [xsi].ScaleY1.pUnit, lengthof cBuffer
      invoke StrCCatChar, xdi, "]", lengthof cBuffer
    .endif
  .endif
  invoke StrDispose, [xsi].ScaleY1.pTitle
  mov [xsi].ScaleY1.pTitle, $invoke(StrNew, xdi)

  ;Calculate X scale internal factors -------------------------------
  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_AUTO_MIN
    s2s [xsi].ScaleX.fScaleMin, [xsi].ScaleX.fDataMin, xcx, xdx
  .else
    s2s [xsi].ScaleX.fScaleMin, [xsi].ScaleX.fSetupMin, xcx, xdx
  .endif

  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_AUTO_MAX
    s2s [xsi].ScaleX.fScaleMax, [xsi].ScaleX.fDataMax, xcx, xdx
  .else
    s2s [xsi].ScaleX.fScaleMax, [xsi].ScaleX.fSetupMax, xcx, xdx
  .endif

  fld [xsi].ScaleX.fScaleMin
  fcomp [xsi].ScaleX.fScaleMax
  fGetFlags
  .if ZERO?                                             ;Min = Max
    fld [xsi].ScaleX.fScaleMax
    fld1
    faddp st(1), st(0)
    fstp [xsi].ScaleX.fScaleMax
  .elseif !CARRY?                                       ;Min > Max -> swap
    s2s [xsi].ScaleX.fScaleMin, [xsi].ScaleX.fScaleMin, xcx, xdx
    s2s [xsi].ScaleX.fScaleMax, [xsi].ScaleX.fScaleMax, xcx, xdx
  .endif

  OCall xsi.CalcScaleDivs, addr [xsi].ScaleX

  ;Calculate Y scale internal factors -------------------------------
  .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_AUTO_MIN
    s2s [xsi].ScaleY1.fScaleMin, [xsi].ScaleY1.fDataMin, xcx, xdx
  .else
    s2s [xsi].ScaleY1.fScaleMin, [xsi].ScaleY1.fSetupMin, xcx, xdx
  .endif

  .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_AUTO_MAX
    s2s [xsi].ScaleY1.fScaleMax, [xsi].ScaleY1.fDataMax, xcx, xdx
  .else
    s2s [xsi].ScaleY1.fScaleMax, [xsi].ScaleY1.fSetupMax, xcx, xdx
  .endif

  fld [xsi].ScaleY1.fScaleMin
  fcomp [xsi].ScaleY1.fScaleMax
  fGetFlags
  .if ZERO?                                             ;Min = Max
    fld [xsi].ScaleY1.fScaleMax
    fld1
    faddp st(1), st(0)
    fstp [xsi].ScaleY1.fScaleMax
  .elseif !CARRY?                                       ;Min > Max -> swap
    s2s [xsi].ScaleY1.fScaleMin, [xsi].ScaleY1.fScaleMin, xcx, xdx
    s2s [xsi].ScaleY1.fScaleMax, [xsi].ScaleY1.fScaleMax, xcx, xdx
  .endif

  OCall xsi.CalcScaleDivs, addr [xsi].ScaleY1

  ;Calculate some plot metrics based on the font metrics ------------
  mov eax, [xsi].TextMetricHorz.tmHeight                ;height = ascent + descent
  shr eax, 1
  mov [xsi].ScaleX.dDivMjrLen, eax
  mov [xsi].ScaleY1.dDivMjrLen, eax
  inc eax
  shr eax, 1
  mov [xsi].ScaleX.dDivMnrLen, eax
  mov [xsi].ScaleY1.dDivMnrLen, eax
  mov [xsi].ScaleY1.dLabelSep, eax                       ;Gap between divisions and label on Y scale
  mov [xsi].ScaleX.dLabelSep, eax                       ;Gap between divisions and label on X scale
  mov [xsi].ScaleX.dTitleSep, eax                       ;Gap between title and label on X scale
  mov [xsi].ScaleY1.dTitleSep, eax                       ;Gap between title and label on Y scale

  ;Determine the top plot border ------------------------------------
  mov eax, [xsi].TextMetricHorz.tmHeight                ;height = ascent + descent
  inc eax
  shr eax, 1
  add eax, [xsi].DrawRect.top                           ;Let a small distance
  mov [xsi].PlotRect.top, eax

  ;Determine the left plot border -----------------------------------
  m2m [xsi].PlotRect.left, [xsi].DrawRect.left, eax

  .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_LABEL
    lea xdi, cBuffer
    fld [xsi].ScaleY1.fScaleMin
    invoke St0ToStr, xdi, 0, [xsi].ScaleY1.dDecimals, f_NOR
    fUnload
    invoke StrLength, xdi
    lea xbx, TextSize1
    invoke GetTextExtentPoint32, hDC, xdi, eax, xbx     ;TextSize1 = extent of Y scale Min label

    fld [xsi].ScaleY1.fScaleMax
    invoke St0ToStr, xdi, 0, [xsi].ScaleY1.dDecimals, f_NOR
    fUnload
    invoke StrLength, xdi
    lea xbx, TextSize2
    invoke GetTextExtentPoint32, hDC, xdi, eax, xbx     ;TextSize2 = extent of Y scale Max label

    uMax TextSize1.x, TextSize2.x                       ;eax = Widest Y scale label
    add eax, [xsi].ScaleY1.dLabelSep                     ;add label separation
    add [xsi].PlotRect.left, eax
  .endif

  .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleY1.pTitle != NULL
      mov eax, [xsi].TextMetricVert.tmHeight
      add eax, [xsi].ScaleY1.dTitleSep
      add [xsi].PlotRect.left, eax                      ;Y scale title height + separation
    .endif
  .endif

  .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MJR_DIV
    mov eax, [xsi].ScaleY1.dDivMjrLen                    ;Major division lenght
    add [xsi].PlotRect.left, eax
  .elseIfBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_DIV
    mov eax, [xsi].ScaleY1.dDivMnrLen                    ;Minor division lenght
    add [xsi].PlotRect.left, eax
  .endif

  ;Determine the right plot border ----------------------------------
  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_LABEL
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF or \
                                     CHT_SCALE_SHOW_AS_TIME
      m2z TextSize1.x
      m2z TextSize2.x
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
          fld [xsi].ScaleX.fScaleMax
          invoke St0ToStr, xdi, 0, 0, f_NOR
          fUnload
          invoke StrLength, xdi
          lea xbx, TextSize1
          invoke GetTextExtentPoint32, hDC, xdi, eax, xbx
        .else
          FillString CHR ptr [xdi], <DD.MM.YYYY>
          lea xbx, TextSize1
          invoke GetTextExtentPoint32, hDC, xdi, 10, xbx
        .endif
      .endif
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_TIME
        FillString CHR ptr [xdi], <00:00:00>
        lea xbx, TextSize2
        invoke GetTextExtentPoint32, hDC, xdi, 8, xbx
      .endif
    .else
      fld [xsi].ScaleX.fScaleMax
      invoke St0ToStr, xdi, 0, [xsi].ScaleX.dDecimals, f_NOR
      fUnload
      invoke StrLength, xdi
      lea xbx, TextSize1
      invoke GetTextExtentPoint32, hDC, xdi, eax, xbx
    .endif

    mov ecx, TextSize1.x
    .if ecx < TextSize2.x
      mov ecx, TextSize2.x
    .endif
    inc ecx
    shr ecx, 1
    mov eax, [xsi].DrawRect.right
    sub eax, ecx
  .else
    mov eax, [xsi].DrawRect.right
  .endif
  .if SDWORD ptr eax < [xsi].PlotRect.left
    mov eax, [xsi].PlotRect.left
  .endif
  mov [xsi].PlotRect.right, eax                         ;This edge is not included in the plot area

  ;Determine the bottom plot border ---------------------------------
  xor ecx, ecx
  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleX.pTitle != NULL
      mov ecx, [xsi].TextMetricHorz.tmHeight
      sub ecx, [xsi].TextMetricHorz.tmInternalLeading
      add ecx, [xsi].ScaleX.dTitleSep                   ;X scale title height + separation
    .endif
  .endif

  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_LABEL
    add ecx, [xsi].TextMetricHorz.tmHeight              ;Scale label height
    sub ecx, [xsi].TextMetricHorz.tmInternalLeading
    add ecx, [xsi].ScaleX.dLabelSep                     ;Label separation
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_TIME
        add ecx, [xsi].TextMetricHorz.tmHeight          ;Add an additional line
        add ecx, [xsi].TextMetricHorz.tmDescent         ;Add a bit more space
      .endif
    .endif
  .endif

  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MJR_DIV
    add ecx, [xsi].ScaleX.dDivMjrLen                    ;Major division length
  .elseIfBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_DIV
    add ecx, [xsi].ScaleX.dDivMnrLen                    ;Minor division length
  .endif

  mov eax, [xsi].DrawRect.bottom
  sub eax, ecx

  .if SDWORD ptr eax < [xsi].PlotRect.top
    mov eax, [xsi].PlotRect.top
    add ecx, eax
    mov [xsi].DrawRect.bottom, ecx
  .endif
  mov [xsi].PlotRect.bottom, eax                         ;This edge is not included in the plot area

  ;Calculate Scaling factors ----------------------------------------
  mov eax, [xsi].PlotRect.right
  sub eax, [xsi].PlotRect.left
  mov dValue, eax
  fld [xsi].ScaleX.fScaleMax
  fsub [xsi].ScaleX.fScaleMin
  fidivr dValue
  fstp [xsi].ScaleX.fScaleFactor

  mov eax, [xsi].PlotRect.bottom
  sub eax, [xsi].PlotRect.top
  mov dValue, eax
  fld [xsi].ScaleY1.fScaleMax
  fsub [xsi].ScaleY1.fScaleMin
  fidivr dValue
  fstp [xsi].ScaleY1.fScaleFactor

  invoke SelectObject, hDC, hPrevFont
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.CalcScaleDivs
; Purpose:    Compute major and minor scale divisions and scale decimal digits.
; Arguments:  Arg1: -> Scale data.
; Return:     Nothing.

Method ChartFlat.CalcScaleDivs, uses xbx, pScaleData:PCHT_SCALE_DATA
  local fNewLoLim:CHT_FLOAT, fNewUpLim:CHT_FLOAT        ;New Lower Limit (NLL)
  local dIndex:DWORD, dBuffer:DWORD                     ;  and New Upper Limit (NUL)

  .const
    bSclMjrDivs  db  05, 04, 06, 04, 05, 06, 07, 08, 09, 10, 11, 06
    bSclMnrDivs  db  04, 05, 05, 05, 05, 05, 02, 02, 05, 02, 02, 05
  .code

  mov xbx, pScaleData
  assume xbx:PCHT_SCALE_DATA
  fld [xbx].fScaleMax
  fsub [xbx].fScaleMin
  fabs                                                  ;Be sure UL-LL > 0
  fLogT
  fRndDn                                                ;E
  fExpT                                                 ;FR = Rounded exponent of |NUL-NLL|

  fld [xbx].fScaleMin
  fdiv st(0), st(1)
  fRndDn
  fmul st(0), st(1)
  fstp fNewLoLim

  fld [xbx].fScaleMax
  fdiv st(0), st(1)
  fRndUp
  fmul st(0), st(1)
  fst fNewUpLim

  fld fNewLoLim
  fsubp st(1), st(0)
  fabs                                                  ;Be sure NUL-NLL > 0
  fld st(0)
  fLogT
  fRndDn                                                ;F = RndDn(Log(Abs((NUL-NLL)))

  fld1
  fcomi st(0), st(1)
  .if !CARRY? && !ZERO?                                 ;st(1) < 1
    fsubrp st(1), st(0)
  .else
    fUnload 2                                           ;Unload FPU stack
    fldz
  .endif
  fistp [xbx].dDecimals

  fxch
  fdivr st(0), st(1)
  fRnd
  fistp dIndex                                          ;Index = Rnd(NUL-NLL) / FR
  dec dIndex                                            ;Make zero based index
  .if dIndex >= 12
    mov dIndex, 11                                      ;Clamp the dIndex value
  .endif

  .ifBitSet [xbx].dFlags, CHT_SCALE_AUTO_MNR_DIV
    mov eax, dIndex                                     ;Get minor divisions from table
    lea xbx, bSclMnrDivs                                ;xbx = table base address
    xlatb
    mov xbx, pScaleData
    mov [xbx].dDivMnrCount, eax
  .else
    mrm [xbx].dDivMnrCount, [xbx].dSetupMnrDiv, eax
  .endif
  mov [xbx].dDataMnrDiv, eax

  .ifBitSet [xbx].dFlags, CHT_SCALE_AUTO_MJR_DIV
    mov eax, dIndex                                     ;Get major divisions from table
    lea xbx, bSclMjrDivs
    xlatb
    mov xbx, pScaleData
    mov dBuffer, eax
    fild dBuffer
  .else
    fild [xbx].dSetupMjrDiv
    mov eax, [xbx].dSetupMjrDiv
  .endif
  mov [xbx].dDataMjrDiv, eax

  fdivp st(1), st(0)
  fst [xbx].fDivMjrStp

  fld [xbx].fScaleMin                                   ;Start repeat-until loop
  fld fNewLoLim
@@1:
  fcomi st(0), st(1)
  .if !ZERO? && CARRY?                                  ;while x < fScaleMin
    fadd st(0), st(2)
    jmp @@1
  .endif
  fstp [xbx].fDivMjrFst
  fstp dBuffer

  fld [xbx].fScaleMax                                   ;Start repeat-until loop
  fld fNewUpLim
@@2:
  fcomi st(0),  st(1)
  .if !ZERO? && !CARRY?                                 ;while x > fScaleMax
    fsub st(0), st(2)
    jmp @@2
  .endif

  fUnload 3                                             ;Unload FPU stack

  assume xbx:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method ChartFlat.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.Done
; Purpose:    Finalize the ChartFlat object.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlat.Done, uses xsi
  SetObject xsi

  invoke StrDispose, [xsi].ScaleX.pTitle
  invoke StrDispose, [xsi].ScaleX.pDescription
  invoke StrDispose, [xsi].ScaleX.pUnit

  invoke StrDispose, [xsi].ScaleY1.pTitle
  invoke StrDispose, [xsi].ScaleY1.pDescription
  invoke StrDispose, [xsi].ScaleY1.pUnit

  OCall [xsi].Data::Collection.Done

  invoke DeleteObject, [xsi].hFontHorz
  invoke DeleteObject, [xsi].hFontVert

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.DrawFrame
; Purpose:    Draw the plot frame.
; Arguments:  Arg1: Output device context.
; Return:     Nothing.

CHT_LABEL_INFO struc
  dPosition   DWORD       ?
  fValue      CHT_FLOAT   ?
CHT_LABEL_INFO ends
PCHT_LABEL_INFO typedef ptr CHT_LABEL_INFO

Method ChartFlat.DrawFrame, uses xbx xdi xsi, hDC:HDC
  local hPrevPen:HPEN, hPrevBrush:HBRUSH, dPrevColor:DWORD, hPrevFont:HFONT
  local dPrevBkMode:DWORD, dPrevAlign:DWORD, dTempEDI:DWORD
  local LastPoint:POINT, cBuffer[256]:CHR
  local dDivMjrEnd:DWORD, dDivMnrEnd:DWORD
  local dMjrCount:DWORD, dMnrCount:DWORD, sdPosition:SDWORD
  local hDivPen:HPEN, hMjrGridPen:HPEN, hMnrGridPen:HPEN, PenBrush:LOGBRUSH
  local dColor:DWORD
  local r8TimeCurrent:REAL8, pTimeCurrent:POINTER
  local FpuContext:FPU_CONTEXT
  local LabelInfo[200]:CHT_LABEL_INFO, pCurLabelInfo:PCHT_LABEL_INFO

  SetObject xsi

  mov dPrevBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))

  ;Fill output area -------------------------------------------------
  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.Background
  .else
    mov eax, $RGB(255,255,255)
  .endif
  mov xdi, $invoke(CreateSolidBrush, eax)
  invoke FillRect, hDC, addr [xsi].ViewRect, xdi
  invoke DeleteObject, xdi

  ;Plot a line around the plot area and fill the interior  ----------
  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.PlotBorder
  .else
    mov eax, $RGB(000,000,000)
  .endif
  invoke CreatePen, PS_SOLID, 1, eax
  mov hPrevPen, $invoke(SelectObject, hDC, xax)

  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.PlotArea
  .else
    mov eax, $RGB(255,255,255)
  .endif
  invoke CreateSolidBrush, eax
  mov hPrevBrush, $invoke(SelectObject, hDC, xax)

  mov eax, [xsi].PlotRect.right
  mov edi, [xsi].PlotRect.bottom
  inc eax
  inc edi
  invoke Rectangle, hDC, [xsi].PlotRect.left, [xsi].PlotRect.top, eax, edi

  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevBrush)

  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.Scales
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov dColor, eax
  mov dPrevColor, $32($invoke(SetTextColor, hDC, eax))

  mov hDivPen, $invoke(CreatePen, PS_SOLID, 1, dColor)
  invoke DeleteObject, $invoke(SelectObject, hDC, xax)  ;Delete PlotBorder pen

  ;Plot X scale ---------------------------------------------------
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontHorz)
  mov dPrevAlign, $32($invoke(SetTextAlign, hDC, TA_CENTER or TA_TOP))

  ;Create the grid pens
  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.MjrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleX.dGridMjrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleX.dGridMjrLineSize, addr PenBrush, 0, NULL
  mov hMjrGridPen, xax

  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.MnrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleX.dGridMnrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleX.dGridMnrLineSize, addr PenBrush, 0, NULL
  mov hMnrGridPen, xax

  mov edx, [xsi].PlotRect.left
  .if SDWORD ptr edx < [xsi].PlotRect.right
    mov eax, [xsi].PlotRect.bottom
    mov ecx, eax
    add eax, [xsi].ScaleX.dDivMjrLen
    add ecx, [xsi].ScaleX.dDivMnrLen
    mov dDivMjrEnd, eax
    mov dDivMnrEnd, ecx

    fld [xsi].ScaleX.fScaleFactor
    fld [xsi].ScaleX.fDivMjrStp
    fild [xsi].ScaleX.dDivMnrCount
    fdivr st(0), st(1)                                    ;MnrStep = DivStep/MnrCount
    ;FPU Stack: MnrStep | MjrStep | ScaleFactor
    fld [xsi].ScaleX.fDivMjrFst
    fld [xsi].ScaleX.fScaleMin
    ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
    lea xax, LabelInfo
    mov pCurLabelInfo, xax
    xor edi, edi
    .repeat
      mov dMjrCount, edi
      fild dMjrCount
      ;FPU Stack: dMjrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(4)
      fadd st(0), st(2)
      mov xcx, pCurLabelInfo
      fst [xcx].CHT_LABEL_INFO.fValue
      fsub st(0), st(1)
      fmul st(0), st(5)
      ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fist sdPosition
      mov eax, [xsi].PlotRect.left
      add eax, sdPosition
      mov [xcx].CHT_LABEL_INFO.dPosition, eax             ;Store position onto stack
      add pCurLabelInfo, sizeof CHT_LABEL_INFO
      .break .if SDWORD ptr eax > [xsi].PlotRect.right
      mov sdPosition, eax

      ;Draw major division
      SaveFpuContext FpuContext
      invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
      invoke LineTo, hDC, sdPosition, dDivMjrEnd

      ;Draw major grid lines
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MJR_GRID
        mov ecx, sdPosition
        .if (SDWORD ptr ecx < [xsi].PlotRect.right) && (SDWORD ptr ecx > [xsi].PlotRect.left)
          invoke SelectObject, hDC, hMjrGridPen
          invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
          mov eax, [xsi].PlotRect.top
          inc eax
          invoke LineTo, hDC, sdPosition, eax
          invoke SelectObject, hDC, hDivPen
        .endif
      .endif
      LoadFpuContext FpuContext

      ;Draw minor divisions
      mov dTempEDI, edi
      mov edi, 1
      .while edi < [xsi].ScaleX.dDivMnrCount
        mov dMnrCount, edi
        fild dMnrCount
        ;FPU Stack: dMnrCount | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        fmul st(0), st(4)
        fmul st(0), st(6)
        fadd st(0), st(1)
        ;FPU Stack: MnrDivPos | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        fistp sdPosition
        ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        mov eax, sdPosition
        add eax, [xsi].PlotRect.left
        .break .if SDWORD ptr eax > [xsi].PlotRect.right
        mov sdPosition, eax
        SaveFpuContext FpuContext
        invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
        invoke LineTo, hDC, sdPosition, dDivMnrEnd
        ;Draw minor grid lines
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_GRID
          mov ecx, sdPosition
          .if (SDWORD ptr ecx < [xsi].PlotRect.right) && (SDWORD ptr ecx > [xsi].PlotRect.left)
            mov ecx, sdPosition
            invoke SelectObject, hDC, hMnrGridPen
            invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
            mov eax, [xsi].PlotRect.top
            inc eax
            invoke LineTo, hDC, sdPosition, eax
            invoke SelectObject, hDC, hDivPen
          .endif
        .endif
        LoadFpuContext FpuContext
        inc edi
      .endw
      mov edi, dTempEDI
      fUnload 1                                         ;Unload FPU stack
      ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      inc edi
    .until FALSE
    sub pCurLabelInfo, 2*sizeof CHT_LABEL_INFO
    fUnload 1                                           ;Unload FPU stack

    ;Draw remaining minor divisions at the beginning of the X scale
    mov edi, 1
    .while edi < [xsi].ScaleX.dDivMnrCount
      mov dMnrCount, edi
      fild dMnrCount
      ;FPU Stack: dMnrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(3)
      fsubr st(0), st(2)
      fsub st(0), st(1)
      fmul st(0), st(5)
      fistp sdPosition
      mov eax, [xsi].PlotRect.left
      add eax, sdPosition
      .break .if SDWORD ptr eax < [xsi].PlotRect.left
      mov sdPosition, eax
      SaveFpuContext FpuContext
      invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
      invoke LineTo, hDC, sdPosition,dDivMnrEnd
      ;Draw remaining minor grid lines
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_GRID
        mov ecx, sdPosition
        .if (SDWORD ptr ecx < [xsi].PlotRect.right) && (SDWORD ptr ecx > [xsi].PlotRect.left)
          mov ecx, sdPosition
          invoke SelectObject, hDC, hMnrGridPen
          invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
          mov eax, [xsi].PlotRect.top
          inc eax
          invoke LineTo, hDC, sdPosition, eax
          invoke SelectObject, hDC, hDivPen
        .endif
      .endif
      LoadFpuContext FpuContext
      inc edi
    .endw

    fUnload 5                                           ;Unload FPU stack

    ;Draw X labels
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_LABEL
      mov ebx, dDivMjrEnd
      sub ebx, [xsi].TextMetricHorz.tmInternalLeading
      add ebx, [xsi].ScaleX.dLabelSep
      .while TRUE
        lea xax, LabelInfo
        .break .if pCurLabelInfo < xax
        mov xdi, pCurLabelInfo
        m2m sdPosition, [xdi].CHT_LABEL_INFO.dPosition, edx

        SaveFpuContext FpuContext
        fld [xdi].CHT_LABEL_INFO.fValue
        lea xdi, cBuffer
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF or CHT_SCALE_SHOW_AS_TIME
          .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
            fld st(0)
            fInt
            .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
              invoke St0ToStr, xdi, 0, 0, f_NOR
              invoke StrLength, xdi
              invoke TextOut, hDC, sdPosition, ebx, xdi, eax
            .else
              fst r8TimeCurrent
              invoke VarBstrFromDate, r8TimeCurrent, 0, \
                                      LOCALE_NOUSEROVERRIDE or VAR_DATEVALUEONLY or VAR_FOURDIGITYEARS, \
                                      addr pTimeCurrent
              .if eax == S_OK
                mov xax, pTimeCurrent
                .if CHRW ptr [xax] == 0
                  FillString [xdi], <30.12.1899>
                .else
                  if TARGET_STR_TYPE eq STR_TYPE_ANSI
                    invoke WideCharToMultiByte, CP_ACP, 0, pTimeCurrent, -1, \
                                                xdi, lengthof cBuffer, NULL, NULL
                  else
                    invoke StrCopyW, xdi, pTimeCurrent
                  endif
                .endif
                invoke SysFreeString, pTimeCurrent
              .else
                m2z CHR ptr [xdi]
              .endif

              invoke StrLength, xdi
              invoke TextOut, hDC, sdPosition, ebx, xdi, eax
            .endif
            fUnload
          .endif

          .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_TIME
            fld st(0)
            fFrac
            fstp r8TimeCurrent
            invoke VarBstrFromDate, r8TimeCurrent, 0, \
                                    LOCALE_NOUSEROVERRIDE or VAR_TIMEVALUEONLY, \
                                    addr pTimeCurrent
            .if eax == S_OK
              if TARGET_STR_TYPE eq STR_TYPE_ANSI
                invoke WideCharToMultiByte, CP_ACP, 0, pTimeCurrent, -1, \
                                            xdi, lengthof cBuffer, NULL, NULL
              else
                invoke StrCopyW, xdi, pTimeCurrent
              endif
              invoke SysFreeString, pTimeCurrent
            .else
              m2z CHR ptr [xdi]
            .endif

            invoke StrLength, xdi
            .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
              add ebx, [xsi].TextMetricHorz.tmHeight
            .endif
            invoke TextOut, hDC, sdPosition, ebx, xdi, eax
            .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
              sub ebx, [xsi].TextMetricHorz.tmHeight
            .endif
          .endif
        .else
          invoke St0ToStr, xdi, 0, [xsi].ScaleX.dDecimals, f_NOR
          invoke StrLength, xdi
          invoke TextOut, hDC, sdPosition, ebx, xdi, eax
        .endif
        fUnload
        LoadFpuContext FpuContext

        sub pCurLabelInfo, sizeof CHT_LABEL_INFO
      .endw
    .endif
  .endif
  invoke DeleteObject, hMjrGridPen
  invoke DeleteObject, hMnrGridPen

  ;Draw X scale title
  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TITLE
    SaveFpuContext FpuContext
    lea xbx, [xsi]
    invoke StrLength, [xsi].ScaleX.pTitle
    .if eax != 0
      mov edi, eax
      invoke SetTextAlign, hDC, TA_CENTER or TA_BOTTOM
      mov edx, [xsi].PlotRect.right
      add edx, [xsi].PlotRect.left
      shr edx, 1
      invoke TextOut, hDC, edx, [xsi].DrawRect.bottom, [xsi].ScaleX.pTitle, edi
    .endif
    LoadFpuContext FpuContext
  .endif


  ;Plot Y scale ---------------------------------------------------
  ;Create the grid pens
  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.MjrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleY1.dGridMjrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleY1.dGridMjrLineSize, addr PenBrush, 0, NULL
  mov hMjrGridPen, xax

  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.MnrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleY1.dGridMnrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleY1.dGridMnrLineSize, addr PenBrush, 0, NULL
  mov hMnrGridPen, xax

  mov edx, [xsi].PlotRect.top
  .if SDWORD ptr edx < [xsi].PlotRect.bottom
    mov eax, [xsi].PlotRect.left
    mov ecx, eax
    sub eax, [xsi].ScaleY1.dDivMjrLen
    sub ecx, [xsi].ScaleY1.dDivMnrLen
    mov dDivMjrEnd, eax
    mov dDivMnrEnd, ecx

    fld [xsi].ScaleY1.fScaleFactor
    fld [xsi].ScaleY1.fDivMjrStp
    fild [xsi].ScaleY1.dDivMnrCount
    fdivr st(0), st(1)                                    ;MnrStep = DivStep/MnrCount
    ;FPU Stack: MnrStep | MjrStep | ScaleFactor
    fld [xsi].ScaleY1.fDivMjrFst
    fld [xsi].ScaleY1.fScaleMin
    ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
    lea xax, LabelInfo
    mov pCurLabelInfo, xax
    xor edi, edi
    .repeat
      mov dMjrCount, edi
      fild dMjrCount
      ;FPU Stack: dMjrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(4)
      fadd st(0), st(2)
      mov xcx, pCurLabelInfo
      fst [xcx].CHT_LABEL_INFO.fValue
      fsub st(0), st(1)
      fmul st(0), st(5)
      ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fist sdPosition
      mov eax, [xsi].PlotRect.bottom
      sub eax, sdPosition
      mov [xcx].CHT_LABEL_INFO.dPosition, eax             ;Store position onto stack
      add pCurLabelInfo, sizeof CHT_LABEL_INFO
      .break .if SDWORD ptr eax < [xsi].PlotRect.top
      mov sdPosition, eax

      ;Draw major division
      SaveFpuContext FpuContext
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MJR_DIV
        invoke MoveToEx, hDC, [xsi].PlotRect.left, sdPosition, addr LastPoint
        invoke LineTo, hDC, dDivMjrEnd, sdPosition
      .else
        .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_DIV
          invoke MoveToEx, hDC, [xsi].PlotRect.left, sdPosition, addr LastPoint
          invoke LineTo, hDC, dDivMnrEnd, sdPosition
        .endif
      .endif

      ;Draw major grid lines
      .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MJR_GRID
        mov ecx, sdPosition
        .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
          invoke SelectObject, hDC, hMjrGridPen
          mov edx, [xsi].PlotRect.left
          inc edx
          invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
          invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
          invoke SelectObject, hDC, hDivPen
        .endif
      .endif
      LoadFpuContext FpuContext

      ;Draw minor divisions
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_DIV
        mov dTempEDI, edi
        mov edi, 1
        .while edi < [xsi].ScaleY1.dDivMnrCount
          mov dMnrCount, edi
          fild dMnrCount
          ;FPU Stack: dMnrCount | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          fmul st(0), st(4)
          fmul st(0), st(6)
          fadd st(0), st(1)
          ;FPU Stack: MnrDivPos | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          fistp sdPosition
          ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          mov eax, [xsi].PlotRect.bottom
          sub eax, sdPosition
          .break .if SDWORD ptr eax < [xsi].PlotRect.top
          mov sdPosition, eax
          SaveFpuContext FpuContext
          invoke MoveToEx, hDC, [xsi].PlotRect.left, sdPosition, addr LastPoint
          invoke LineTo, hDC, dDivMnrEnd, sdPosition
          ;Draw minor grid lines
          .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_GRID
            mov ecx, sdPosition
            .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
              invoke SelectObject, hDC, hMnrGridPen
              mov edx, [xsi].PlotRect.left
              inc edx
              invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
              invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
              invoke SelectObject, hDC, hDivPen
            .endif
          .endif
          LoadFpuContext FpuContext
          inc edi
        .endw
        mov edi, dTempEDI
      .endif
      fUnload 1                                         ;Unload FPU stack
      ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      inc edi
    .until FALSE
    sub pCurLabelInfo, 2*sizeof CHT_LABEL_INFO
    fUnload 1                                           ;Unload FPU stack

    ;Draw remaining minor divisions at the beginning of the Y scale
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_DIV
      mov edi, 1
      .while edi < [xsi].ScaleY1.dDivMnrCount
        mov dMnrCount, edi
        fild dMnrCount
        ;FPU Stack: dMnrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        fmul st(0), st(3)
        fsubr st(0), st(2)
        fsub st(0), st(1)
        fmul st(0), st(5)
        fistp sdPosition
        mov eax, [xsi].PlotRect.bottom
        sub eax, sdPosition
        mov sdPosition, eax
        dec eax
        .break .if SDWORD ptr eax >= [xsi].PlotRect.bottom
        SaveFpuContext FpuContext
        invoke MoveToEx, hDC, [xsi].PlotRect.left, sdPosition, addr LastPoint
        invoke LineTo, hDC, dDivMnrEnd, sdPosition
        ;Draw remaining minor grid lines
        .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_GRID
          mov ecx, sdPosition
          .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
            invoke SelectObject, hDC, hMnrGridPen
            mov edx, [xsi].PlotRect.left
            inc edx
            invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
            invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
            invoke SelectObject, hDC, hDivPen
          .endif
        .endif
        LoadFpuContext FpuContext
        inc edi
      .endw
    .endif

    fUnload 5                                             ;Unload FPU stack

    ;Draw Y labels ----------------------------------------------------
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_LABEL
      invoke SetTextAlign, hDC, TA_TOP or TA_RIGHT
      mov eax, [xsi].ScaleY1.dLabelSep
      sub dDivMjrEnd, eax
      .while TRUE
        lea xax, LabelInfo
        .break .if pCurLabelInfo < xax
        mov xdi, pCurLabelInfo
        fld [xdi].CHT_LABEL_INFO.fValue
        invoke St0ToStr, addr cBuffer, 0, [xsi].ScaleY1.dDecimals, f_NOR; or f_TRIM
        fUnload
        invoke StrLength, addr cBuffer
        mov ecx, [xsi].TextMetricHorz.tmAscent
        add ecx, [xsi].TextMetricHorz.tmInternalLeading
        shr ecx, 1
        mov ebx, [xdi].CHT_LABEL_INFO.dPosition
        sub ebx, ecx
        invoke TextOut, hDC, dDivMjrEnd, ebx, addr cBuffer, eax
        sub pCurLabelInfo, sizeof CHT_LABEL_INFO
      .endw
    .endif
  .endif

  ;Draw Y scale title -----------------------------------------------
  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleY1.pTitle != NULL
      invoke StrLength, [xsi].ScaleY1.pTitle
      .if eax != 0
        mov edi, eax
        invoke SelectObject, hDC, [xsi].hFontVert
        invoke SetTextAlign, hDC, TA_CENTER or TA_TOP
        mov eax, [xsi].PlotRect.bottom
        add eax, [xsi].PlotRect.top
        shr eax, 1
        invoke TextOut, hDC, [xsi].DrawRect.left, eax, [xsi].ScaleY1.pTitle, edi
      .endif
    .endif
  .endif

  ;Release resources ------------------------------------------------
  invoke SelectObject, hDC, hPrevPen
  invoke DeleteObject, hMjrGridPen
  invoke DeleteObject, hMnrGridPen
  invoke DeleteObject, hDivPen
  invoke SetTextColor, hDC, dPrevColor
  invoke SetTextAlign, hDC, dPrevAlign
  invoke SetBkMode, hDC, dPrevBkMode
  invoke SelectObject, hDC, hPrevFont                   ;hFonts are deleted by the Done method

  assume xbx:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method ChartFlat.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local LogFnt:LOGFONT, hDC:HDC, hPrevFont:HFONT

;  DbgText "ChartFlat.OnCreate"
  SetObject xsi

  OCall [xsi].Data::Collection.Init, xsi, 1, 1, COL_MAX_CAPACITY    ;Make Space for 1 series

  FillString LogFnt.lfFaceName, <Segoe UI>
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 9, eax, -72
  mov LogFnt.lfHeight, eax
  m2z LogFnt.lfWidth
  m2z LogFnt.lfEscapement
  m2z LogFnt.lfOrientation
  mov LogFnt.lfWeight, FW_DONTCARE
  m2z LogFnt.lfItalic
  m2z LogFnt.lfUnderline
  m2z LogFnt.lfStrikeOut
  mov LogFnt.lfCharSet, DEFAULT_CHARSET
  mov LogFnt.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov LogFnt.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov LogFnt.lfQuality, DEFAULT_QUALITY
  mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov [xsi].hFontHorz, $invoke(CreateFontIndirect, addr LogFnt)
  mov hPrevFont, $invoke(SelectObject, hDC, xax)
  invoke GetTextMetrics, hDC, addr [xsi].TextMetricHorz

  mov LogFnt.lfEscapement, 900
  mov [xsi].hFontVert, $invoke(CreateFontIndirect, addr LogFnt)
  invoke SelectObject, hDC, xax
  invoke GetTextMetrics, hDC, addr [xsi].TextMetricVert

  invoke SelectObject, hDC, hPrevFont
  invoke ReleaseDC, [xsi].hWnd, hDC
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.OnGesture
; Purpose:    Event procedure for WM_GESTURE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter. lParam = info HANDLE identifying the gesture command
; Return:     eax = Zero if handled.
; Link:       https://docs.microsoft.com/en-us/windows/win32/wintouch/improving-the-single-finger-panning-experience

Method ChartFlat.OnGesture, uses xsi, wParam:WPARAM, lParam:LPARAM
  local GestInfo:GESTUREINFO, bResult:BOOL, bHandled:BOOL, sdValue:SDWORD
;  local Pnt1:POINT, bHasChanged:BOOL, dError:DWORD

  ;DbgText "ChartFlat.OnGesture"
  SetObject xsi

  ;Populate and retrieve the extra message info.
  invoke MemZero, addr GestInfo, sizeof GestInfo
  mov GestInfo.cbSize, sizeof GestInfo
  mov bResult, $32($invoke(GetGestureInfo, lParam, addr GestInfo))
  mov bHandled, FALSE

  .if bResult != FALSE
    ;Now interpret the gesture
    .if GestInfo.dwID == GID_ZOOM

      .ifBitSet [xsi].dFlags, CHT_FLAG_ZOOMABLE
        .ifBitSet GestInfo.dwFlags, GF_BEGIN
          mov eax, DWORD ptr GestInfo.ullArguments
          mov [xsi].dGestureZoomFirst, eax
          mov [xsi].dGestureZoomLast, eax
        .else
          invoke GetKeyState, VK_SHIFT
          mov ecx, DWORD ptr GestInfo.ullArguments
          .ifBitSet eax, BIT15
            .if ecx != [xsi].dGestureZoomLast             ;Take an action if the value has changed
              BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

              mov [xsi].dGestureZoomLast, ecx             ;Remember the last value
              mov eax, ecx
              sub eax, [xsi].dGestureZoomFirst
              mov [xsi].dGestureZoomFirst, ecx
              mov sdValue, eax

              fld [xsi].ScaleX.fScaleFactor
              fidivr SDWORD ptr sdValue

              fld [xsi].ScaleX.fScaleMax
              fsub st(0), st(1)
              fstp [xsi].ScaleX.fSetupMax
              fld [xsi].ScaleX.fScaleMin
              fadd st(0), st(1)
              fstp [xsi].ScaleX.fSetupMin
              fUnload 1                                   ;Unload FPU stack
            .endif
          .else
            .if ecx != [xsi].dGestureZoomLast             ;Take an action if the value has changed
              BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

              mov [xsi].dGestureZoomLast, ecx             ;Remember the last value
              mov eax, ecx
              sub eax, [xsi].dGestureZoomFirst
              mov [xsi].dGestureZoomFirst, ecx
              mov sdValue, eax

              fld [xsi].ScaleY1.fScaleFactor
              fidivr SDWORD ptr sdValue

              fld [xsi].ScaleY1.fScaleMax
              fsub st(0), st(1)
              fstp [xsi].ScaleY1.fSetupMax
              fld [xsi].ScaleY1.fScaleMin
              fadd st(0), st(1)
              fstp [xsi].ScaleY1.fSetupMin
              fUnload 1                                   ;Unload FPU stack
            .endif
          .endif
          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
        .endif
      .endif
      mov bHandled, TRUE

      ;Handle the pan gesture the compatibility way

;    .elseif GestInfo.dwID == GID_PAN
;      ;Code for panning goes here
;      .ifBitSet GestInfo.dwFlags, GF_BEGIN
;        movsx eax, GestInfo.ptsLocation.x
;        movsx ecx, GestInfo.ptsLocation.y
;        mov [xsi].GesturePanPos.x, eax
;        mov [xsi].GesturePanPos.y, ecx
;
;      .else
;        movsx ecx, GestInfo.ptsLocation.x
;        mov eax, ecx
;        sub eax, [xsi].GesturePanPos.x
;        mov [xsi].GesturePanPos.x, ecx
;        mov bHasChanged, FALSE
;
;        .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_HORZ
;          mov bHasChanged, TRUE
;          .if SDWORD ptr eax > [xsi].Origin.x
;            mov [xsi].Origin.x, 0
;          .else
;            mov edx, [xsi].ClientRect.right
;            sub edx, [xsi].Padding.left
;            sub edx, [xsi].Padding.right                ;edx = drawable width on the client window
;
;            mov ecx, [xsi].DrawExtent.x
;            sub ecx, [xsi].Origin.x
;            add ecx, eax                                ;ecx = new visible height
;
;            .if SDWORD ptr ecx < edx
;              mov eax, [xsi].DrawExtent.x
;              sub eax, edx
;              mov [xsi].Origin.x, eax
;            .else
;              sub [xsi].Origin.x, eax
;            .endif
;          .endif
;          invoke SetScrollPos, [xsi].hWnd, SB_HORZ, [xsi].Origin.x, TRUE
;        .endif
;
;        movsx ecx, GestInfo.ptsLocation.y
;        mov eax, ecx
;        sub eax, [xsi].GesturePanPos.y                  ;eax = delta pos y
;        mov [xsi].GesturePanPos.y, ecx
;
;        .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_VERT
;          .if SDWORD ptr eax > [xsi].Origin.y
;          mov bHasChanged, TRUE
;            mov [xsi].Origin.y, 0
;          .else
;            mov edx, [xsi].ClientRect.bottom
;            sub edx, [xsi].Padding.top
;            sub edx, [xsi].Padding.bottom               ;edx = drawable height on the client window
;
;            mov ecx, [xsi].DrawExtent.y
;            sub ecx, [xsi].Origin.y
;            add ecx, eax                                ;ecx = new visible height
;
;            .if SDWORD ptr ecx < edx
;              mov eax, [xsi].DrawExtent.y
;              sub eax, edx
;              mov [xsi].Origin.y, eax
;            .else
;              sub [xsi].Origin.y, eax
;            .endif
;          .endif
;          invoke SetScrollPos, [xsi].hWnd, SB_VERT, [xsi].Origin.y, TRUE
;        .endif
;
;        .if bHasChanged
;          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
;        .endif
;      .endif
;      invoke DefWindowProc, [xsi].hWnd, WM_GESTURE, wParam, lParam
;      ret
;
;      mov bHandled, TRUE

      invoke CloseGestureInfoHandle, lParam             ;Close the gesture handle
    .endif
  .endif

  .if bHandled
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_GESTURE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartFlat.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local sdValue:SDWORD, dDoZoom:DWORD, dDoPan:DWORD

  SetObject xsi
  mov dDoPan, FALSE
  mov dDoZoom, FALSE
  .ifBitClr wParam, MK_CONTROL
    .ifBitSet [xsi].dFlags, CHT_FLAG_PANABLE
      mov dDoPan, TRUE
    .endif
  .else
    .ifBitSet [xsi].dFlags, CHT_FLAG_ZOOMABLE
      mov dDoZoom, TRUE
    .endif
  .endif

  .if dDoPan != FALSE || dDoZoom != FALSE
    .if [xsi].bMovingOn == CHT_ID_SCALEX
      BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      cwde
      mov ecx, [xsi].MovedLastPoint.x
      mov [xsi].MovedLastPoint.x, eax
      sub eax, ecx
      mov sdValue, eax

      fld [xsi].ScaleX.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleX.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleX.fSetupMax
      fld [xsi].ScaleX.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleX.fSetupMin
      fUnload 1                                           ;Unload FPU stack
      OCall xsi.Refresh

    .elseif [xsi].bMovingOn == CHT_ID_SCALEY1
      BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      shr eax, 16
      cwde
      mov ecx, [xsi].MovedLastPoint.y
      mov [xsi].MovedLastPoint.y, eax
      sub ecx, eax
      mov sdValue, ecx

      fld [xsi].ScaleY1.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleY1.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY1.fSetupMax
      fld [xsi].ScaleY1.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY1.fSetupMin
      fUnload 1                                         ;Unload FPU stack
      OCall xsi.Refresh

    .elseif [xsi].bMovingOn == CHT_ID_PLOT
      BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      cwde
      mov ecx, [xsi].MovedLastPoint.x
      mov [xsi].MovedLastPoint.x, eax
      sub eax, ecx
      mov sdValue, eax

      fld [xsi].ScaleX.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleX.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleX.fSetupMax
      fld [xsi].ScaleX.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleX.fSetupMin
      fUnload 1                                         ;Unload FPU stack

      BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      shr eax, 16
      cwde
      mov ecx, [xsi].MovedLastPoint.y
      mov [xsi].MovedLastPoint.y, eax
      sub ecx, eax
      mov sdValue, ecx

      fld [xsi].ScaleY1.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleY1.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY1.fSetupMax
      fld [xsi].ScaleY1.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY1.fSetupMin
      fUnload 1                                         ;Unload FPU stack
      OCall xsi.Refresh
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.OnLButtonDblClk
; Purpose:    Event procedure for WM_LBUTTONDBLCLK message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartFlat.OnLButtonDblClk, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local SetupDlg:$Obj(ChartFlatSetup), DblClkPnt:POINT

  SetObject xsi
  PntS2Pnt DblClkPnt, lParam
  mov ebx, DblClkPnt.x
  mov edi, DblClkPnt.y
  mov eax, -1

  .ifBitSet [xsi].dFlags, CHT_FLAG_CTRL_DBLCLK
    .ifBitSet wParam, MK_CONTROL
      ;Check if X scale was double clicked
      .if (SDWORD ptr ebx >= [xsi].PlotRect.left) && (SDWORD ptr ebx <= [xsi].ViewRect.right) && \
          (SDWORD ptr edi >= [xsi].PlotRect.bottom) && (SDWORD ptr edi <= [xsi].ViewRect.bottom)
        BitSet [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        OCall xsi.Refresh
      ;Check if Y scale was double clicked
      .elseif (SDWORD ptr ebx >= [xsi].ViewRect.left) && (SDWORD ptr ebx <= [xsi].PlotRect.left) && \
              (SDWORD ptr edi >= [xsi].ViewRect.top) && (SDWORD ptr edi <= [xsi].PlotRect.bottom)
        BitSet [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        OCall xsi.Refresh
      .else
        BitSet [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        BitSet [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        OCall xsi.Refresh
      .endif
      xor eax, eax
      ExitMethod
    .endif
  .endif

  ;Get doubleclick client coordinates
  add DblClkPnt.x, 10                                   ;Place the Dialog 10 px at the right
  add DblClkPnt.y, 20                                   ;Place the Dialog 20 px below
  
  invoke ClientToScreen, [xsi].hWnd, addr DblClkPnt     ;Transform to screen coordiantes
  ;Check if X scale was double clicked
  .if (SDWORD ptr ebx >= [xsi].PlotRect.left) && (SDWORD ptr ebx <= [xsi].ViewRect.right) && \
      (SDWORD ptr edi >= [xsi].PlotRect.bottom) && (SDWORD ptr edi <= [xsi].ViewRect.bottom)
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TAB
      New SetupDlg::ChartFlatSetup
      OCall SetupDlg::ChartFlatSetup.Init, xsi, [xsi].hWnd, CHT_ID_SCALEX
      OCall SetupDlg::ChartFlatSetup.ShowAt, DblClkPnt.x, DblClkPnt.y
      OCall SetupDlg::ChartFlatSetup.Done
    .endif
  ;Check if Y1 scale was double clicked
  .elseif (SDWORD ptr ebx >= [xsi].ViewRect.left) && (SDWORD ptr ebx <= [xsi].PlotRect.left) && \
          (SDWORD ptr edi >= [xsi].ViewRect.top) && (SDWORD ptr edi <= [xsi].PlotRect.bottom)
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TAB
      New SetupDlg::ChartFlatSetup
      OCall SetupDlg::ChartFlatSetup.Init, xsi, [xsi].hWnd, CHT_ID_SCALEY1
      OCall SetupDlg::ChartFlatSetup.ShowAt, DblClkPnt.x, DblClkPnt.y
      OCall SetupDlg::ChartFlatSetup.Done
    .endif
  .else
    .ifBitSet [xsi].dFlags, CHT_FLAG_SHOW_GENERAL_TAB
      ;Launch the color setup dialog
      New SetupDlg::ChartFlatSetup
      OCall SetupDlg::ChartFlatSetup.Init, xsi, [xsi].hWnd, CHT_ID_PLOT
      OCall SetupDlg::ChartFlatSetup.ShowAt, DblClkPnt.x, DblClkPnt.y
      OCall SetupDlg::ChartFlatSetup.Done
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartFlat.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  PntS2Regs lParam
  mov [xsi].MovedLastPoint.x, eax
  mov [xsi].MovedLastPoint.y, ecx

  ;Check if X scale was clicked
  .if (SDWORD ptr eax >= [xsi].PlotRect.left) && (SDWORD ptr eax <= [xsi].ViewRect.right) && \
    (SDWORD ptr ecx >= [xsi].PlotRect.bottom) && (SDWORD ptr ecx <= [xsi].ViewRect.bottom)
    mov [xsi].bMovingOn, CHT_ID_SCALEX
    invoke SetCapture, [xsi].hWnd
  ;Check if Y scale was clicked
  .elseif (SDWORD ptr eax >= [xsi].ViewRect.left) && (SDWORD ptr eax <= [xsi].PlotRect.left) && \
    (SDWORD ptr ecx >= [xsi].ViewRect.top) && (SDWORD ptr ecx <= [xsi].PlotRect.bottom)
    mov [xsi].bMovingOn, CHT_ID_SCALEY1
    invoke SetCapture, [xsi].hWnd
  ;Check if plot area was clicked
  .elseif (SDWORD ptr eax >= [xsi].PlotRect.left) && (SDWORD ptr eax <= [xsi].PlotRect.right) && \
    (SDWORD ptr ecx >= [xsi].PlotRect.top) && (SDWORD ptr ecx <= [xsi].PlotRect.bottom)
    mov [xsi].bMovingOn, CHT_ID_PLOT
    invoke SetCapture, [xsi].hWnd
  ;Check if lower left area was clicked => behave like plot area
  .elseif (SDWORD ptr eax >= [xsi].ViewRect.left) && (SDWORD ptr eax <= [xsi].PlotRect.left) && \
    (SDWORD ptr ecx >= [xsi].PlotRect.bottom) && (SDWORD ptr ecx <= [xsi].ViewRect.bottom)
    mov [xsi].bMovingOn, CHT_ID_PLOT
    invoke SetCapture, [xsi].hWnd
  .else
    ;It was clicked somewhere else
    mov [xsi].bMovingOn, CHT_ID_NONE
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartFlat.OnLButtonUp,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov [xcx].bMovingOn, CHT_ID_NONE
  invoke ReleaseCapture
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ChartFlat.OnMouseWheel, uses xsi, wParam:WPARAM, lParam:LPARAM
  local sdValue:SDWORD, dDoZoom:DWORD, dDoPan:DWORD

  ;DbgText "ChartFlat.OnMouseWheel"
  SetObject xsi
  mov dDoPan, FALSE
  mov dDoZoom, FALSE
  .ifBitClr wParam, MK_CONTROL
    .ifBitSet [xsi].dFlags, CHT_FLAG_PANABLE
      mov dDoPan, TRUE
    .endif
  .else
    .ifBitSet [xsi].dFlags, CHT_FLAG_ZOOMABLE
      mov dDoZoom, TRUE
    .endif
  .endif

  SetObject xsi
  .if dDoPan != FALSE || dDoZoom != FALSE
    mov xax, wParam
    .ifBitSet ax, MK_SHIFT                                ;If SHIFT is pressed then act on the horz SB
      BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
      sar eax, 16 + 3
      mov sdValue, eax

      fld [xsi].ScaleX.fScaleFactor
      fidivr SDWORD ptr sdValue

      fld [xsi].ScaleX.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleX.fSetupMax
      fld [xsi].ScaleX.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleX.fSetupMin
      fUnload 1                                           ;Unload FPU stack
    .else
      BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
      sar eax, 16 + 3
      mov sdValue, eax

      fld [xsi].ScaleY1.fScaleFactor
      fidivr SDWORD ptr sdValue

      fld [xsi].ScaleY1.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY1.fSetupMax
      fld [xsi].ScaleY1.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY1.fSetupMin
      fUnload 1                                           ;Unload FPU stack
    .endif
    OCall xsi.Refresh
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ChartFlat.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, ClientRect:RECT

  ;DbgText "ChartFlat.OnPaint"
  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr ClientRect
  OCall xsi.Show, PS.hdc, addr ClientRect
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.Refresh
; Purpose:    Refresh the plot object.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlat.Refresh, uses xsi
  local hDC:HDC

  ;DbgText "ChartFlat.Refresh"
  SetObject xsi
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  OCall xsi.Show, hDC, addr [xsi].ViewRect
  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.Show
; Purpose:    Draw the ChartFlat object.
; Arguments:  Arg1: DC handle.
;             Arg2: -> RECT structure that indicates where to draw.
; Return:     Nothing.

Method ChartFlat.Show, uses xbx xdi xsi, hDC:HDC, pRect:PRECT
  local hPrevBmp:HBITMAP

  ;DbgText "ChartFlat.Show"
  SetObject xsi
  ;Draw on a memory DC to avoid flicker
  mov xdi, $invoke(CreateCompatibleDC, hDC)             ;Create Mem DC
  mov xbx, pRect
  invoke CreateCompatibleBitmap, hDC, [xbx].RECT.right, [xbx].RECT.bottom
  mov hPrevBmp, $invoke(SelectObject, xdi, xax)

  ;Draw frame, scales, etc.
  OCall xsi.Calc, xdi, xbx
  OCall xsi.DrawFrame, xdi

  ;Draw all series
  mov eax, [xsi].PlotRect.right
  mov ecx, [xsi].PlotRect.bottom
  .if (SDWORD ptr eax > [xsi].PlotRect.left) && (SDWORD ptr ecx > [xsi].PlotRect.top)
    xor ebx, ebx
    .while ebx != [xsi].Data.dCount
      OCall [xsi].Data::Collection.ItemAt, ebx
      OCall xsi.DrawSeries, xdi, xax
      inc ebx
    .endw
  .endif

  ;Copy the drawn chart on memory DC to window DC
  mov xbx, pRect
  invoke BitBlt, hDC, [xbx].RECT.left, [xbx].RECT.top, [xbx].RECT.right, [xbx].RECT.bottom, \
                 xdi, [xbx].RECT.left, [xbx].RECT.top, SRCCOPY

  invoke DeleteObject, $invoke(SelectObject, xdi, hPrevBmp)   ;Release hMemBmp
  invoke DeleteDC, xdi                                        ;Release memory DC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

% include &ObjPath&ChartFlatTabGeneral.inc
% include &ObjPath&ChartFlatTabScale.inc
% include &ObjPath&ChartFlatTabSeries.inc
% include &ObjPath&ChartFlatSetup.inc

endif
