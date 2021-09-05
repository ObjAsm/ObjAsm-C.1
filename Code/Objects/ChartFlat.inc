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
      sdPosX    SDWORD  ?                               ;X position
      sdPosY    SDWORD  ?                               ;Y position
      dWidth    DWORD   ?                               ;Width
      dHeight   DWORD   ?                               ;Height
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
CHT_SCALE_SHOW_DIALOG       equ   BIT13

CHT_DEFAULT_SCALE_OPTIONS = CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX or \
                            CHT_SCALE_AUTO_MJR_DIV or CHT_SCALE_AUTO_MNR_DIV or \
                            CHT_SCALE_SHOW_MJR_GRID or CHT_SCALE_SHOW_MNR_GRID or \
                            CHT_SCALE_SHOW_MJR_DIV or CHT_SCALE_SHOW_MNR_DIV or \
                            CHT_SCALE_SHOW_LABEL or CHT_SCALE_SHOW_TITLE or \
                            CHT_SCALE_SHOW_DIALOG

CHT_FLAG_SELF_INST          equ   BIT00                 ;Object was instanced by CreateWindowEx
CHT_FLAG_PANABLE            equ   BIT01                 ;Plot is panable
CHT_FLAG_ZOOMABLE           equ   BIT02                 ;Plot is zoomable
CHT_FLAG_COLOR              equ   BIT03                 ;Color or B&W output
CHT_FLAG_SHOW_COLOR_DLG     equ   BIT04                 ;Enable the color dialog
CHT_FLAG_CTRL_DBLCLK        equ   BIT05                 ;Enable CTRL double click to center scale    

CHT_DEFAULT_FLAGS = CHT_FLAG_PANABLE or CHT_FLAG_ZOOMABLE or CHT_FLAG_COLOR or \
                    CHT_FLAG_SHOW_COLOR_DLG or CHT_FLAG_CTRL_DBLCLK

CHT_SCALE_STRINGS struc
  pDesc         PSTRING     NULL                        ;-> Description string (local allocated)
  pUnit         PSTRING     NULL                        ;-> Unit string (local allocated)
CHT_SCALE_STRINGS ends

CHT_SCALE_BASIC_DATA struc
  dOptions      DWORD       CHT_DEFAULT_SCALE_OPTIONS   ;Scale options
  fSetupMax     CHT_FLOAT   1.0                         ;Setup max value
  fSetupMin     CHT_FLOAT   0.0                         ;Setup min value
  fDataMax      CHT_FLOAT   1.0                         ;Data max value
  fDataMin      CHT_FLOAT   0.0                         ;Data min value
  dSetupMjrDiv  DWORD       2                           ;Setup major divisions
  dSetupMnrDiv  DWORD       2                           ;Setup minor divisions
  dDataMjrDiv   DWORD       2                           ;Data major divisions
  dDataMnrDiv   DWORD       2                           ;Data minor divisions
  CHT_SCALE_STRINGS         {}
CHT_SCALE_BASIC_DATA ends
PCHT_SCALE_BASIC_DATA typedef ptr CHT_SCALE_BASIC_DATA

CHT_SCALE_INTERNAL_DATA struc                           ;Do not use directly, internal data
  dDecimals     DWORD       1                           ;Nr of decimal digits used to draw labels
  fScaleMax     CHT_FLOAT   1.0                         ;Max used for drawing scale
  fScaleMin     CHT_FLOAT   0.0                         ;Min used for drawing scale
  fDivMjrFst    CHT_FLOAT   0.0                         ;Value of first major division in plot range
  fDivMjrStp    CHT_FLOAT   0.0                         ;Value major division step
  dDivMjrLen    DWORD       0                           ;Size of major division
  dDivMnrLen    DWORD       0                           ;Size of minor division
  dDivMnrCount  DWORD       0                           ;Number of minor divs between major divs
  dTitleSep     DWORD       0                           ;Title separation
  dLabelSep     DWORD       0                           ;Label separation
  pTitle        PSTRING     NULL                        ;Title string (local allocated)
  fScaleFactor  CHT_FLOAT   1.0                         ;Scale drawing factor
CHT_SCALE_INTERNAL_DATA ends
PCHT_SCALE_INTERNAL_DATA typedef ptr CHT_SCALE_INTERNAL_DATA

CHT_SCALE_DATA struc
  CHT_SCALE_BASIC_DATA      {}
  CHT_SCALE_INTERNAL_DATA   {}
CHT_SCALE_DATA ends
PCHT_SCALE_DATA typedef ptr CHT_SCALE_DATA

CHT_COLOR_CONFIG struc
  MjrGrid       COLORREF    $RGB(191,191,191)           ;Major grid color
  MnrGrid       COLORREF    $RGB(191,191,191)           ;Minor grid color
  PlotArea      COLORREF    $RGB(255,255,255)           ;Plot area color
  PlotBorder    COLORREF    $RGB(000,000,000)           ;Plot border color
  Background    COLORREF    $RGB(223,223,223)           ;Background color
  Scales        COLORREF    $RGB(000,000,000)           ;Scale divisions and labels
CHT_COLOR_CONFIG ends
PCHT_COLOR_CONFIG typedef ptr CHT_COLOR_CONFIG

CHT_AREA_NONE     equ     0
CHT_AREA_SCALEX   equ     1
CHT_AREA_SCALEY   equ     2
CHT_AREA_PLOT     equ     3


;https://docs.microsoft.com/de-de/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartFlat
; Purpose: This object is the base for all flat chart descendants.
;          It works using the ChartSeries object, that holds the information for each data
;          representation.
;          DialogSetupChartScale and DialogSetupChartColors are used to customize the drawing. They are called
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
  DefineVariable    ScaleX,             CHT_SCALE_DATA,   {}
  DefineVariable    ScaleY,             CHT_SCALE_DATA,   {}
  DefineVariable    Colors,             CHT_COLOR_CONFIG, {}
  DefineVariable    dGridLineSize,      DWORD,            1
  DefineVariable    dGridLineStyle,     DWORD,            PS_DASH

  DefineVariable    ViewRect,           RECT,             {}
  DefineVariable    Padding,            RECT,             {}
  DefineVariable    DrawRect,           RECT,             {}        ;DrawRect = ViewRect - Padding
  DefineVariable    PlotRect,           RECT,             {}
  DefineVariable    hFontHorz,          HFONT,            0         ;Horizontal font
  DefineVariable    hFontVert,          HFONT,            0         ;Vertical font
  DefineVariable    TextMetricHorz,     TEXTMETRIC,       {}
  DefineVariable    TextMetricVert,     TEXTMETRIC,       {}
  DefineVariable    bMovingOn,          BYTE,             CHT_AREA_NONE ;Selected element
  DefineVariable    MovedLastPoint,     POINT,            {}
  DefineVariable    dGestureZoomFirst,  DWORD,            0
  DefineVariable    dGestureZoomLast,   DWORD,            0

  Embed    Data,    Collection                                      ;Collection of ChartSeries
ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object DialogSetupChartScale,, DialogModal
  RedefineMethod    CtlsSet
  RedefineMethod    CtlsGet
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PCHT_SCALE_BASIC_DATA
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnClose,            WM_CLOSE

  DefineVariable    pScaleData,         PCHT_SCALE_DATA,  NULL
  DefineVariable    pPrevDesc,          PSTRING,          NULL
  DefineVariable    pPrevUnit,          PSTRING,          NULL
  DefineVariable    PrvScaleData,       CHT_SCALE_BASIC_DATA, {}
ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object DialogSetupChartColors,, DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, HWND
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnClose,            WM_CLOSE

  DefineVariable    NewColors,          CHT_COLOR_CONFIG,     {}  ;Work copy
  DefineVariable    PrvColors,          CHT_COLOR_CONFIG,     {}  ;Backup copy
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
  .if [xsi].ScaleX.pDesc != NULL
    .if $invoke(StrLength, [xsi].ScaleX.pDesc)
      invoke StrCCopy, xdi, [xsi].ScaleX.pDesc, lengthof cBuffer
    .endif
  .endif
  .if [xsi].ScaleX.pUnit != NULL
    .if $invoke(StrLength, [xsi].ScaleX.pUnit)
      .if [xsi].ScaleX.pDesc != NULL
        .if $invoke(StrLength, [xsi].ScaleX.pDesc)
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
  .if [xsi].ScaleY.pDesc != NULL
    .if $invoke(StrLength, [xsi].ScaleY.pDesc)
      invoke StrCCopy, xdi, [xsi].ScaleY.pDesc, lengthof cBuffer
    .endif
  .endif
  .if [xsi].ScaleY.pUnit != NULL
    .if $invoke(StrLength, [xsi].ScaleY.pUnit)
      .if [xsi].ScaleY.pDesc != NULL
        .if $invoke(StrLength, [xsi].ScaleY.pDesc)
          invoke StrCCatChar, xdi, " ", lengthof cBuffer
        .endif
      .endif
      invoke StrCCatChar, xdi, "[", lengthof cBuffer
      invoke StrCCat, xdi, [xsi].ScaleY.pUnit, lengthof cBuffer
      invoke StrCCatChar, xdi, "]", lengthof cBuffer
    .endif
  .endif
  invoke StrDispose, [xsi].ScaleY.pTitle
  mov [xsi].ScaleY.pTitle, $invoke(StrNew, xdi)

  ;Calculate X scale internal factors -------------------------------
  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_AUTO_MIN
    s2s [xsi].ScaleX.fScaleMin, [xsi].ScaleX.fDataMin, xcx, xdx
  .else
    s2s [xsi].ScaleX.fScaleMin, [xsi].ScaleX.fSetupMin, xcx, xdx
  .endif

  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_AUTO_MAX
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
  .ifBitSet [xsi].ScaleY.dOptions, CHT_SCALE_AUTO_MIN
    s2s [xsi].ScaleY.fScaleMin, [xsi].ScaleY.fDataMin, xcx, xdx
  .else
    s2s [xsi].ScaleY.fScaleMin, [xsi].ScaleY.fSetupMin, xcx, xdx
  .endif

  .ifBitSet [xsi].ScaleY.dOptions, CHT_SCALE_AUTO_MAX
    s2s [xsi].ScaleY.fScaleMax, [xsi].ScaleY.fDataMax, xcx, xdx
  .else
    s2s [xsi].ScaleY.fScaleMax, [xsi].ScaleY.fSetupMax, xcx, xdx
  .endif

  fld [xsi].ScaleY.fScaleMin
  fcomp [xsi].ScaleY.fScaleMax
  fGetFlags
  .if ZERO?                                             ;Min = Max
    fld [xsi].ScaleY.fScaleMax
    fld1
    faddp st(1), st(0)
    fstp [xsi].ScaleY.fScaleMax
  .elseif !CARRY?                                       ;Min > Max -> swap
    s2s [xsi].ScaleY.fScaleMin, [xsi].ScaleY.fScaleMin, xcx, xdx
    s2s [xsi].ScaleY.fScaleMax, [xsi].ScaleY.fScaleMax, xcx, xdx
  .endif

  OCall xsi.CalcScaleDivs, addr [xsi].ScaleY

  ;Calculate some plot metrics based on the font metrics ------------
  mov eax, [xsi].TextMetricHorz.tmHeight                ;height = ascent + descent
  shr eax, 1
  mov [xsi].ScaleX.dDivMjrLen, eax
  mov [xsi].ScaleY.dDivMjrLen, eax
  inc eax
  shr eax, 1
  mov [xsi].ScaleX.dDivMnrLen, eax
  mov [xsi].ScaleY.dDivMnrLen, eax
  mov [xsi].ScaleY.dLabelSep, eax                       ;Gap between divisions and label on Y scale
  mov [xsi].ScaleX.dLabelSep, eax                       ;Gap between divisions and label on X scale
  mov [xsi].ScaleX.dTitleSep, eax                       ;Gap between title and label on X scale
  mov [xsi].ScaleY.dTitleSep, eax                       ;Gap between title and label on Y scale

  ;Determine the top border -----------------------------------------
  mov eax, [xsi].TextMetricHorz.tmHeight                ;height = ascent + descent
  inc eax
  shr eax, 1
  add eax, [xsi].DrawRect.top
  mov [xsi].PlotRect.top, eax

  ;Determine the left border ----------------------------------------
  m2m [xsi].PlotRect.left, [xsi].DrawRect.left, eax

  .ifBitSet [xsi].ScaleY.dOptions, CHT_SCALE_SHOW_LABEL
    lea xdi, cBuffer
    fld [xsi].ScaleY.fScaleMin
    invoke St0ToStr, xdi, 0, [xsi].ScaleY.dDecimals, f_NOR
    fUnload
    invoke StrLength, xdi
    lea xbx, TextSize1
    invoke GetTextExtentPoint32, hDC, xdi, eax, xbx     ;TextSize1 = extent of Y scale Min label

    fld [xsi].ScaleY.fScaleMax
    invoke St0ToStr, xdi, 0, [xsi].ScaleY.dDecimals, f_NOR
    fUnload
    invoke StrLength, xdi
    lea xbx, TextSize2
    invoke GetTextExtentPoint32, hDC, xdi, eax, xbx     ;TextSize2 = extent of Y scale Max label

    uMax TextSize1.x, TextSize2.x                       ;eax = Widest Y scale label
    add eax, [xsi].ScaleY.dLabelSep                     ;add label separation
    add [xsi].PlotRect.left, eax
  .endif

  .ifBitSet [xsi].ScaleY.dOptions, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleY.pTitle != NULL
      mov eax, [xsi].TextMetricVert.tmHeight
      add eax, [xsi].ScaleY.dTitleSep
      add [xsi].PlotRect.left, eax                      ;Y scale title height + separation
    .endif
  .endif

  .ifBitSet [xsi].ScaleY.dOptions, CHT_SCALE_SHOW_MJR_DIV
    mov eax, [xsi].ScaleY.dDivMjrLen                    ;Major division lenght
    add [xsi].PlotRect.left, eax
  .elseIfBitSet [xsi].ScaleY.dOptions, CHT_SCALE_SHOW_MNR_DIV
    mov eax, [xsi].ScaleY.dDivMnrLen                    ;Minor division lenght
    add [xsi].PlotRect.left, eax
  .endif

  ;Determine the right border ---------------------------------------
  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_LABEL
    .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF or \
                                     CHT_SCALE_SHOW_AS_TIME
      m2z TextSize1.x
      m2z TextSize2.x
      .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
        .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATEDIFF
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
      .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_TIME
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
  mov [xsi].PlotRect.right, eax                         ;This edge is not included in the plot area

  ;Determine the bottom border --------------------------------------
  xor ecx, ecx
  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleX.pTitle != NULL
      mov ecx, [xsi].TextMetricHorz.tmHeight
      sub ecx, [xsi].TextMetricHorz.tmInternalLeading
      add ecx, [xsi].ScaleX.dTitleSep                   ;X scale title height + separation
    .endif
  .endif

  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_LABEL
    add ecx, [xsi].TextMetricHorz.tmHeight              ;Scale label height
    sub ecx, [xsi].TextMetricHorz.tmInternalLeading
    add ecx, [xsi].ScaleX.dLabelSep                     ;Label separation
    .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
      .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_TIME
        add ecx, [xsi].TextMetricHorz.tmHeight          ;Add an additional line
        add ecx, [xsi].TextMetricHorz.tmDescent         ;Add a bit more space
      .endif
    .endif
  .endif

  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_MJR_DIV
    add ecx, [xsi].ScaleX.dDivMjrLen                    ;Major division length
  .elseIfBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_MNR_DIV
    add ecx, [xsi].ScaleX.dDivMnrLen                    ;Minor division length
  .endif

  mov eax, [xsi].DrawRect.bottom
  sub eax, ecx
  mov [xsi].PlotRect.bottom, eax

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
  fld [xsi].ScaleY.fScaleMax
  fsub [xsi].ScaleY.fScaleMin
  fidivr dValue
  fstp [xsi].ScaleY.fScaleFactor

  invoke SelectObject, hDC, hPrevFont
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlat.CalcScaleDivs
; Purpose:    Compute major and minor scale divisions and scale decimal digits.
; Arguments:  Arg1: -> Scale data.
; Return:     Nothing.

Method ChartFlat.CalcScaleDivs, uses xbx, pScaleData:PCHT_SCALE_DATA
  local fNLL:CHT_FLOAT, fNUL:CHT_FLOAT                  ;New Lower Limit and New Upper Limit
  local dIndex:DWORD, dBuffer:DWORD

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
  fExpT                                                 ;FR = Rounded exponent of NUL-NLL

  fld [xbx].fScaleMin
  fdiv st(0), st(1)
  fRndDn
  fmul st(0), st(1)
  fstp fNLL

  fld [xbx].fScaleMax
  fdiv st(0), st(1)
  fRndUp
  fmul st(0), st(1)
  fst fNUL

  fld fNLL
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

  .ifBitSet [xbx].dOptions, CHT_SCALE_AUTO_MNR_DIV
    mov eax, dIndex                                     ;Get minor divisions from table
    lea xbx, bSclMnrDivs
    xlatb
    mov xbx, pScaleData
    mov [xbx].dDivMnrCount, eax
  .else
    mrm [xbx].dDivMnrCount, [xbx].dSetupMnrDiv, eax
  .endif
  mov [xbx].dDataMnrDiv, eax

  .ifBitSet [xbx].dOptions, CHT_SCALE_AUTO_MJR_DIV
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
  fld fNLL
@@1:
  fcomi st(0), st(1)
  .if !ZERO? && CARRY?                                  ;while x < fScaleMin
    fadd st(0), st(2)
    jmp @@1
  .endif
  fstp [xbx].fDivMjrFst
  fstp dBuffer

  fld [xbx].fScaleMax                                   ;Start repeat-until loop
  fld fNUL
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
  invoke StrDispose, [xsi].ScaleX.pDesc
  invoke StrDispose, [xsi].ScaleX.pUnit

  invoke StrDispose, [xsi].ScaleY.pTitle
  invoke StrDispose, [xsi].ScaleY.pDesc
  invoke StrDispose, [xsi].ScaleY.pUnit

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
  local dDivBeg:DWORD, dDivMjrEnd:DWORD, dDivMnrEnd:DWORD
  local dMjrCount:DWORD, dMnrCount:DWORD, sdPosition:SDWORD
  local hDivPen:HPEN, hGridPen:HPEN, PenBrush:LOGBRUSH
  local dColor:DWORD
  local r8TimeCurrent:REAL8, pTimeCurrent:POINTER
  local FpuContext:FPU_CONTEXT
  local LabelInfo[200]:CHT_LABEL_INFO, pCurLabelInfo:PCHT_LABEL_INFO

  SetObject xsi

  ;Fill output region -----------------------------------------------
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

  .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
    mov eax, [xsi].Colors.MjrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].dGridLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].dGridLineSize, addr PenBrush, 0, NULL
  mov hGridPen, xax

  mov dPrevBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))

  ;Plot X scale ---------------------------------------------------
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontHorz)
  mov dPrevAlign, $32($invoke(SetTextAlign, hDC, TA_CENTER or TA_TOP))

  mov eax, [xsi].PlotRect.bottom
  mov dDivBeg, eax
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
    invoke MoveToEx, hDC, sdPosition, dDivMjrEnd, addr LastPoint
    invoke LineTo, hDC, sdPosition, dDivBeg

    ;Draw grid lines
    .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_MJR_GRID
      mov ecx, sdPosition
      .if (SDWORD ptr ecx < [xsi].PlotRect.right) && (SDWORD ptr ecx > [xsi].PlotRect.left)
        invoke SelectObject, hDC, hGridPen
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
      invoke MoveToEx, hDC, sdPosition, dDivBeg, addr LastPoint
      invoke LineTo, hDC, sdPosition, dDivMnrEnd
      LoadFpuContext FpuContext
      inc edi
    .endw
    mov edi, dTempEDI
    fUnload 1                                           ;Unload FPU stack
    ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
    inc edi
  .until FALSE
  sub pCurLabelInfo, 2*sizeof CHT_LABEL_INFO
  fUnload 1                                             ;Unload FPU stack

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
    invoke MoveToEx, hDC, sdPosition, dDivBeg, addr LastPoint
    invoke LineTo, hDC, sdPosition,dDivMnrEnd
    LoadFpuContext FpuContext
    inc edi
  .endw

  fUnload 5                                             ;Unload FPU stack

  ;Draw X labels
  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_LABEL
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
      .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF or CHT_SCALE_SHOW_AS_TIME
        .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
          fld st(0)
          fInt
          .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATEDIFF
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

        .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_TIME
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
          .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
            add ebx, [xsi].TextMetricHorz.tmHeight
          .endif
          invoke TextOut, hDC, sdPosition, ebx, xdi, eax
          .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
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

  ;Draw X scale title
  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_TITLE
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
  mov eax, [xsi].PlotRect.left
  mov dDivBeg, eax
  sub eax, [xsi].ScaleY.dDivMjrLen
  mov dDivMjrEnd, eax

  mov ecx, dDivBeg
  sub ecx, [xsi].ScaleY.dDivMnrLen
  mov dDivMnrEnd, ecx

  fld [xsi].ScaleY.fScaleFactor
  fld [xsi].ScaleY.fDivMjrStp
  fild [xsi].ScaleY.dDivMnrCount
  fdivr st(0), st(1)                                    ;MnrStep = DivStep/MnrCount
  ;FPU Stack: MnrStep | MjrStep | ScaleFactor
  fld [xsi].ScaleY.fDivMjrFst
  fld [xsi].ScaleY.fScaleMin
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
    .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_MJR_DIV
      invoke MoveToEx, hDC, dDivMjrEnd, sdPosition, addr LastPoint
      invoke LineTo, hDC, dDivBeg, sdPosition
    .else
      .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_MNR_DIV
        invoke MoveToEx, hDC, dDivMnrEnd, sdPosition, addr LastPoint
        invoke LineTo, hDC, dDivBeg, sdPosition
      .endif
    .endif

    ;Draw grid lines
    .ifBitSet [xsi].ScaleY.dOptions, CHT_SCALE_SHOW_MJR_GRID
      mov ecx, sdPosition
      .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
        invoke SelectObject, hDC, hGridPen
        mov edx, [xsi].PlotRect.left
        inc edx
        invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
;        mov edx, [xsi].PlotRect.right
;        dec edx
        invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
        invoke SelectObject, hDC, hDivPen
      .endif
    .endif
    LoadFpuContext FpuContext

    ;Draw minor divisions
    .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_MNR_DIV
      mov dTempEDI, edi
      mov edi, 1
      .while edi < [xsi].ScaleY.dDivMnrCount
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
        invoke MoveToEx, hDC, dDivBeg, sdPosition, addr LastPoint
        invoke LineTo, hDC,dDivMnrEnd, sdPosition
        LoadFpuContext FpuContext
        inc edi
      .endw
      mov edi, dTempEDI
    .endif
    fUnload 1                                           ;Unload FPU stack
    ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
    inc edi
  .until FALSE
  sub pCurLabelInfo, 2*sizeof CHT_LABEL_INFO
  fUnload 1                                             ;Unload FPU stack

  ;Draw remaining minor divisions at the beginning of the Y scale
  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_MNR_DIV
    mov edi, 1
    .while edi < [xsi].ScaleY.dDivMnrCount
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
      invoke MoveToEx, hDC, dDivBeg, sdPosition, addr LastPoint
      invoke LineTo, hDC, dDivMnrEnd, sdPosition
      LoadFpuContext FpuContext
      inc edi
    .endw
  .endif

  fUnload 5                                             ;Unload FPU stack

  ;Draw Y labels ----------------------------------------------------
  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_LABEL
    invoke SetTextAlign, hDC, TA_TOP or TA_RIGHT
    mov eax, [xsi].ScaleY.dLabelSep
    sub dDivMjrEnd, eax
    .while TRUE
      lea xax, LabelInfo
      .break .if pCurLabelInfo < xax
      mov xdi, pCurLabelInfo
      fld [xdi].CHT_LABEL_INFO.fValue
      invoke St0ToStr, addr cBuffer, 0, [xsi].ScaleY.dDecimals, f_NOR; or f_TRIM
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

  ;Draw Y scale title -----------------------------------------------
  .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleY.pTitle != NULL
      invoke StrLength, [xsi].ScaleY.pTitle
      .if eax != 0
        mov edi, eax
        invoke SelectObject, hDC, [xsi].hFontVert
        invoke SetTextAlign, hDC, TA_CENTER or TA_TOP
        mov eax, [xsi].PlotRect.bottom
        add eax, [xsi].PlotRect.top
        shr eax, 1
        invoke TextOut, hDC, [xsi].DrawRect.left, eax, [xsi].ScaleY.pTitle, edi
      .endif
    .endif
  .endif

  ;Release resources ------------------------------------------------
  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevPen)   ;Delete hDivPen
  invoke DeleteObject, hGridPen
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
              BitClr [xsi].ScaleX.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

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
              BitClr [xsi].ScaleY.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

              mov [xsi].dGestureZoomLast, ecx             ;Remember the last value
              mov eax, ecx
              sub eax, [xsi].dGestureZoomFirst
              mov [xsi].dGestureZoomFirst, ecx
              mov sdValue, eax

              fld [xsi].ScaleY.fScaleFactor
              fidivr SDWORD ptr sdValue

              fld [xsi].ScaleY.fScaleMax
              fsub st(0), st(1)
              fstp [xsi].ScaleY.fSetupMax
              fld [xsi].ScaleY.fScaleMin
              fadd st(0), st(1)
              fstp [xsi].ScaleY.fSetupMin
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
    .if [xsi].bMovingOn == CHT_AREA_SCALEX
      BitClr [xsi].ScaleX.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

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

    .elseif [xsi].bMovingOn == CHT_AREA_SCALEY
      BitClr [xsi].ScaleY.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      shr eax, 16
      cwde
      mov ecx, [xsi].MovedLastPoint.y
      mov [xsi].MovedLastPoint.y, eax
      sub ecx, eax
      mov sdValue, ecx

      fld [xsi].ScaleY.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleY.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY.fSetupMax
      fld [xsi].ScaleY.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY.fSetupMin
      fUnload 1                                         ;Unload FPU stack
      OCall xsi.Refresh

    .elseif [xsi].bMovingOn == CHT_AREA_PLOT
      BitClr [xsi].ScaleX.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

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

      BitClr [xsi].ScaleY.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      shr eax, 16
      cwde
      mov ecx, [xsi].MovedLastPoint.y
      mov [xsi].MovedLastPoint.y, eax
      sub ecx, eax
      mov sdValue, ecx

      fld [xsi].ScaleY.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleY.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY.fSetupMax
      fld [xsi].ScaleY.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY.fSetupMin
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
  local ScaleSetupDlg:$Obj(DialogSetupChartScale), ColorSetupDlg:$Obj(DialogSetupChartColors)
  local DblClkPnt:POINT

  SetObject xsi
  PntS2Pnt DblClkPnt, lParam
  mov ebx, DblClkPnt.x
  mov edi, DblClkPnt.y

  .ifBitSet [xsi].dFlags, CHT_FLAG_CTRL_DBLCLK
    .ifBitSet wParam, MK_CONTROL
      ;Check if X scale was double clicked
      .if (SDWORD ptr ebx >= [xsi].PlotRect.left) && (SDWORD ptr ebx <= [xsi].ViewRect.right) && \
          (SDWORD ptr edi >= [xsi].PlotRect.bottom) && (SDWORD ptr edi <= [xsi].ViewRect.bottom)
        BitSet [xsi].ScaleX.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        OCall xsi.Refresh
      ;Check if Y scale was double clicked
      .elseif (SDWORD ptr ebx >= [xsi].ViewRect.left) && (SDWORD ptr ebx <= [xsi].PlotRect.left) && \
              (SDWORD ptr edi >= [xsi].ViewRect.top) && (SDWORD ptr edi <= [xsi].PlotRect.bottom)
        BitSet [xsi].ScaleY.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        OCall xsi.Refresh
      .else
        BitSet [xsi].ScaleX.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        BitSet [xsi].ScaleY.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
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
    .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_DIALOG
      New ScaleSetupDlg::DialogSetupChartScale
      OCall ScaleSetupDlg::DialogSetupChartScale.Init, xsi, [xsi].hWnd, addr [xsi].ScaleX
      OCall ScaleSetupDlg::DialogSetupChartScale.ShowAt, DblClkPnt.x, DblClkPnt.y
      OCall ScaleSetupDlg::DialogSetupChartScale.Done
    .endif
  ;Check if Y scale was double clicked
  .elseif (SDWORD ptr ebx >= [xsi].ViewRect.left) && (SDWORD ptr ebx <= [xsi].PlotRect.left) && \
          (SDWORD ptr edi >= [xsi].ViewRect.top) && (SDWORD ptr edi <= [xsi].PlotRect.bottom)
    .ifBitSet [xsi].ScaleX.dOptions, CHT_SCALE_SHOW_DIALOG
      New ScaleSetupDlg::DialogSetupChartScale
      OCall ScaleSetupDlg::DialogSetupChartScale.Init, xsi, [xsi].hWnd, addr [xsi].ScaleY
      OCall ScaleSetupDlg::DialogSetupChartScale.ShowAt, DblClkPnt.x, DblClkPnt.y
      OCall ScaleSetupDlg::DialogSetupChartScale.Done
    .endif
  .else
    .ifBitSet [xsi].dFlags, CHT_FLAG_SHOW_COLOR_DLG
      ;Launch the color setup dialog
      New ColorSetupDlg::DialogSetupChartColors
      OCall ColorSetupDlg::DialogSetupChartColors.Init, xsi, [xsi].hWnd
      OCall ColorSetupDlg::DialogSetupChartColors.ShowAt, DblClkPnt.x, DblClkPnt.y
      OCall ColorSetupDlg::DialogSetupChartColors.Done
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
    mov [xsi].bMovingOn, CHT_AREA_SCALEX
    invoke SetCapture, [xsi].hWnd
  ;Check if Y scale was clicked
  .elseif (SDWORD ptr eax >= [xsi].ViewRect.left) && (SDWORD ptr eax <= [xsi].PlotRect.left) && \
    (SDWORD ptr ecx >= [xsi].ViewRect.top) && (SDWORD ptr ecx <= [xsi].PlotRect.bottom)
    mov [xsi].bMovingOn, CHT_AREA_SCALEY
    invoke SetCapture, [xsi].hWnd
  ;Check if plot area was clicked
  .elseif (SDWORD ptr eax >= [xsi].PlotRect.left) && (SDWORD ptr eax <= [xsi].PlotRect.right) && \
    (SDWORD ptr ecx >= [xsi].PlotRect.top) && (SDWORD ptr ecx <= [xsi].PlotRect.bottom)
    mov [xsi].bMovingOn, CHT_AREA_PLOT
    invoke SetCapture, [xsi].hWnd
  ;Check if lower left area was clicked => behave like plot area
  .elseif (SDWORD ptr eax >= [xsi].ViewRect.left) && (SDWORD ptr eax <= [xsi].PlotRect.left) && \
    (SDWORD ptr ecx >= [xsi].PlotRect.bottom) && (SDWORD ptr ecx <= [xsi].ViewRect.bottom)
    mov [xsi].bMovingOn, CHT_AREA_PLOT
    invoke SetCapture, [xsi].hWnd
  .else
    ;It was clicked somewhere else
    mov [xsi].bMovingOn, CHT_AREA_NONE
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
  mov [xcx].bMovingOn, CHT_AREA_NONE
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
      BitClr [xsi].ScaleX.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
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
      BitClr [xsi].ScaleY.dOptions, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
      sar eax, 16 + 3
      mov sdValue, eax

      fld [xsi].ScaleY.fScaleFactor
      fidivr SDWORD ptr sdValue

      fld [xsi].ScaleY.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY.fSetupMax
      fld [xsi].ScaleY.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY.fSetupMin
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
  mov xdi, $invoke(CreateCompatibleDC, hDC)
  mov xbx, pRect
  invoke CreateCompatibleBitmap, hDC, [xbx].RECT.right, [xbx].RECT.bottom
  mov hPrevBmp, $invoke(SelectObject, xdi, xax)

  ;Draw frame, scales, etc.
  OCall xsi.Calc, xdi, xbx
  OCall xsi.DrawFrame, xdi

  ;Draw all series
  xor ebx, ebx
  .while ebx != [xsi].Data.dCount
    OCall [xsi].Data::Collection.ItemAt, ebx
    OCall xsi.DrawSeries, xdi, xax
    inc ebx
  .endw

  ;Copy the drawn chart on memory DC to window hDC
  mov xbx, pRect
  invoke BitBlt, hDC, [xbx].RECT.left, [xbx].RECT.top, [xbx].RECT.right, [xbx].RECT.bottom, \
                 xdi, [xbx].RECT.left, [xbx].RECT.top, SRCCOPY

  invoke DeleteObject, $invoke(SelectObject, xdi, hPrevBmp)   ;Release hMemBmp
  invoke DeleteDC, xdi                                        ;Release memory DC
MethodEnd


; ==================================================================================================
;    DialogSetupChartScale implementation
; ==================================================================================================

IDC_DSS_PREVIEW     equ     100
IDC_DSS_COLORS      equ     101

IDC_DSS_CHECKMIN    equ     104
IDC_DSS_CHECKMAX    equ     105
IDC_DSS_CHECKMJR    equ     106
IDC_DSS_CHECKMNR    equ     107

IDC_DSS_EDITMIN     equ     108
IDC_DSS_EDITMAX     equ     109
IDC_DSS_EDITMJR     equ     110
IDC_DSS_EDITMNR     equ     111

IDC_DSS_EDITDESC    equ     112
IDC_DSS_EDITUNIT    equ     113

IDC_DSS_CHECKGRID   equ     114

IDC_DSS_STATIC0     equ     115
IDC_DSS_STATIC1     equ     116
IDC_DSS_STATIC2     equ     117
IDC_DSS_STATIC3     equ     118
IDC_DSS_STATIC4     equ     119

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartScale.CtlsGet
; Purpose:    Read the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetupChartScale.CtlsGet, uses xbx xdi xsi
  local cBuffer[1024]:CHR, dFailure:DWORD

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pScaleData
  assume xdi:PCHT_SCALE_DATA
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKMAX
  .if eax != FALSE
    BitSet [xdi].dOptions, CHT_SCALE_AUTO_MAX
  .else
    BitClr [xdi].dOptions, CHT_SCALE_AUTO_MAX
  .endif
  invoke GetDlgItemText, [xsi].hWnd, IDC_DSS_EDITMAX, xbx, lengthof cBuffer
  fldStr xbx
  fstp [xdi].fSetupMax
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKMIN
  .if eax != FALSE
    BitSet [xdi].dOptions, CHT_SCALE_AUTO_MIN
  .else
    BitClr [xdi].dOptions, CHT_SCALE_AUTO_MIN
  .endif
  invoke GetDlgItemText, [xsi].hWnd, IDC_DSS_EDITMIN, xbx, lengthof cBuffer
  fldStr xbx
  fstp [xdi].fSetupMin
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKMJR
  .if eax != FALSE
    BitSet [xdi].dOptions, CHT_SCALE_AUTO_MJR_DIV
  .else
    BitClr [xdi].dOptions, CHT_SCALE_AUTO_MJR_DIV
  .endif
  invoke GetDlgItemInt, [xsi].hWnd, IDC_DSS_EDITMJR, addr dFailure, FALSE
  .if dFailure != FALSE
    .if (eax > 0) && (eax <= 20)
      mov [xdi].dSetupMjrDiv, eax
    .endif
  .endif
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKMNR
  .if eax != FALSE
    BitSet [xdi].dOptions, CHT_SCALE_AUTO_MNR_DIV
  .else
    BitClr [xdi].dOptions, CHT_SCALE_AUTO_MNR_DIV
  .endif
  invoke GetDlgItemInt, [xsi].hWnd, IDC_DSS_EDITMNR, addr dFailure, FALSE
  .if dFailure != FALSE
    .if (eax > 0) && (eax <= 10)
      mov [xdi].dSetupMnrDiv, eax
    .endif
  .endif
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKGRID
  .if eax != FALSE
    BitSet [xdi].dOptions, CHT_SCALE_SHOW_MJR_GRID
  .else
    BitClr [xdi].dOptions, CHT_SCALE_SHOW_MJR_GRID
  .endif
  ;---------------------------------------------------
  invoke StrDispose, [xdi].pDesc
  invoke GetDlgItemText, [xsi].hWnd, IDC_DSS_EDITDESC, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pDesc, xax
  ;---------------------------------------------------
  invoke StrDispose, [xdi].pUnit
  invoke GetDlgItemText, [xsi].hWnd, IDC_DSS_EDITUNIT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pUnit, xax

  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    DialogSetupChartScale.CtlsSet
; Purpose:   Set the controls in this dialog window.
; Arguments: None.
; Return:    Nothing.

Method DialogSetupChartScale.CtlsSet, uses xbx xdi xsi
  local cBuffer[256]:CHR

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pScaleData
  assume xdi:PCHT_SCALE_DATA
  ;---------------------------------------------------
  .ifBitSet [xdi].dOptions, CHT_SCALE_AUTO_MIN
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMIN), FALSE
    s2s [xdi].fSetupMin, [xdi].fDataMin, xcx, xdx
    mov eax, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMIN), TRUE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKMIN, eax

  fld [xdi].fSetupMin
  invoke St0ToStr, xbx, 0, -1, f_NOR or f_TRIM
  fUnload
  invoke SetDlgItemText, [xsi].hWnd, IDC_DSS_EDITMIN, xbx
  ;---------------------------------------------------
  .ifBitSet [xdi].dOptions, CHT_SCALE_AUTO_MAX
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMAX), FALSE
    s2s [xdi].fSetupMax, [xdi].fDataMax, xcx, xdx
    mov eax, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMAX), TRUE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKMAX, eax

  fld [xdi].fSetupMax
  invoke St0ToStr, xbx, 0, -1, f_NOR or f_TRIM
  fUnload
  invoke SetDlgItemText, [xsi].hWnd, IDC_DSS_EDITMAX, xbx
  ;---------------------------------------------------
  .ifBitSet [xdi].dOptions, CHT_SCALE_AUTO_MJR_DIV
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMJR), FALSE
    m2m [xdi].dSetupMjrDiv, [xdi].dDataMjrDiv, edx
    mov eax, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMJR), TRUE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKMJR, eax

  invoke SetDlgItemInt, [xsi].hWnd, IDC_DSS_EDITMJR, [xdi].dSetupMjrDiv, FALSE
  ;---------------------------------------------------
  .ifBitSet [xdi].dOptions, CHT_SCALE_AUTO_MNR_DIV
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMNR), FALSE
    m2m [xdi].dSetupMnrDiv, [xdi].dDataMnrDiv, edx
    mov eax, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMNR), TRUE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKMNR, eax

  invoke SetDlgItemInt, [xsi].hWnd, IDC_DSS_EDITMNR, [xdi].dSetupMnrDiv, FALSE
  ;---------------------------------------------------
  .ifBitSet [xdi].dOptions, CHT_SCALE_SHOW_MJR_GRID
    mov eax, BST_CHECKED
  .else
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKGRID, eax
  ;---------------------------------------------------
  invoke SetDlgItemText, [xsi].hWnd, IDC_DSS_EDITDESC, [xdi].pDesc
  ;---------------------------------------------------
  invoke SetDlgItemText, [xsi].hWnd, IDC_DSS_EDITUNIT, [xdi].pUnit

  ;---------------------------------------------------
  invoke GetDlgItem, [xsi].hWnd, IDC_DSS_COLORS
  mov xcx, [xsi].pOwner
  mov edx, SW_SHOW
  .ifBitClr [xcx].$Obj(ChartFlat).dFlags, CHT_FLAG_SHOW_COLOR_DLG
    mov edx, SW_HIDE
  .endif
  invoke ShowWindow, xax, edx

  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartScale.Done
; Purpose:    Finalize a dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetupChartScale.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pPrevDesc
  invoke StrDispose, [xsi].pPrevUnit
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartScale.Init
; Purpose:    Initialaize the DialogSetupChartScale dialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> CHT_SCALE_BASIC_DATA.
; Return:     Nothing.

Method DialogSetupChartScale.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pScaleData:PCHT_SCALE_BASIC_DATA
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, $OfsCStr("DialogSetupScale")
  invoke MemClone, addr [xsi].PrvScaleData, pScaleData, sizeof CHT_SCALE_BASIC_DATA
  mov xbx, pScaleData
  mov [xsi].pScaleData, xbx
  mov [xsi].pPrevDesc, $invoke(StrNew, [xbx].CHT_SCALE_BASIC_DATA.pDesc)
  mov [xsi].pPrevUnit, $invoke(StrNew, [xbx].CHT_SCALE_BASIC_DATA.pUnit)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartScale.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetupChartScale.OnClose,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, WM_COMMAND, IDCANCEL, 0
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartScale.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetupChartScale.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  xor eax, eax
  LoWord wParam

  mov ecx, eax
  .if ecx == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::ChartFlat.Refresh

  .elseif ecx == IDCANCEL
    ;Restore previous settings
    mov xbx, [xsi].pScaleData
    mov xcx, [xbx].CHT_SCALE_DATA.pDesc
    m2m [xbx].CHT_SCALE_DATA.pDesc, [xsi].pPrevDesc, xdx
    mov [xsi].pPrevDesc, xcx
    mov xcx, [xbx].CHT_SCALE_DATA.pUnit
    m2m [xbx].CHT_SCALE_DATA.pUnit, [xsi].pPrevUnit, xdx
    mov [xsi].pPrevUnit, xcx
    invoke MemClone, xbx, addr [xsi].PrvScaleData, \
                     sizeof(CHT_SCALE_BASIC_DATA) - sizeof(CHT_SCALE_STRINGS)
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::ChartFlat.Refresh

  .elseif ecx == IDC_DSS_PREVIEW
    OCall xsi.CtlsGet
    OCall [xsi].pOwner::ChartFlat.Refresh
    OCall xsi.CtlsSet

  .elseif ecx == IDC_DSS_COLORS
    mov xbx, $New(DialogSetupChartColors)
    OCall xbx::DialogSetupChartColors.Init, [xsi].pOwner, [xsi].hWnd
    OCall xbx::DialogSetupChartColors.Show
    Destroy xbx
    OCall [xsi].pOwner::ChartFlat.Refresh

  .elseif (ecx >= IDC_DSS_CHECKMIN) && (ecx <= IDC_DSS_CHECKMNR)
    HiWord wParam
    .if eax == BN_CLICKED
      mov edi, ecx
      mov edx, ecx
      add edx, IDC_DSS_EDITMIN - IDC_DSS_CHECKMIN
      mov xbx, $invoke(GetDlgItem, [xsi].hWnd, edx)
      invoke IsDlgButtonChecked, [xsi].hWnd, edi
      Choose eax, TRUE, FALSE
      invoke EnableWindow, xbx, eax
    .endif
  .endif
MethodEnd



; ==================================================================================================
;    DialogSetupChartColors implementation
; ==================================================================================================

IDC_SGC_PREVIEW     equ     100

IDC_SGC_LINE        equ     101
IDC_SGC_GRID        equ     102
IDC_SGC_PLOTAREA    equ     103
IDC_SGC_PLOTBORDER  equ     104
IDC_SGC_BACKGROUND  equ     105
IDC_SGC_SCALES      equ     106

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartColors.CtlsSet
; Purpose:    Set the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetupChartColors.CtlsSet, uses xdi xsi
  SetObject xsi
  mov xcx, [xsi].pOwner
  lea xdi, [xcx].$Obj(ChartFlat).Colors
  assume xdi:PCHT_COLOR_CONFIG

  invoke MemClone, addr [xsi].NewColors, xdi, sizeof CHT_COLOR_CONFIG   ;Make a work copy
  invoke MemClone, addr [xsi].PrvColors, xdi, sizeof CHT_COLOR_CONFIG   ;Make a backup copy

  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_GRID
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].MjrGrid
  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_PLOTAREA
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].PlotArea
  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_PLOTBORDER
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].PlotBorder
  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_BACKGROUND
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Background
  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_SCALES
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].Scales

  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartColors.CtlsGet
; Purpose:    Read the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetupChartColors.CtlsGet
  SetObject xdx
  mov xax, [xdx].pOwner
  lea xcx, [xax].$Obj(ChartFlat).Colors
  invoke MemClone, xcx, addr [xdx].NewColors, sizeof CHT_COLOR_CONFIG   ;Return colors to XGraph
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartColors.Init
; Purpose:    Initialaize the DialogSetupChartColors dialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method DialogSetupChartColors.Init,, pOwner:POINTER, hParent:HWND
  ACall Init, pOwner, hParent, $OfsCStr("DialogSetupGraph2dColors")
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartColors.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetupChartColors.OnClose,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, WM_COMMAND, IDCANCEL, 0
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupChartColors.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetupChartColors.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CC:CHOOSECOLOR, ColorRef[16]:DWORD

  SetObject xsi
  .if wParam == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::ChartFlat.Refresh
  .elseif wParam == IDCANCEL
    mov xax, [xsi].pOwner
    lea xcx, [xax].$Obj(ChartFlat).Colors
    invoke MemClone, xcx, addr [xsi].PrvColors, sizeof CHT_COLOR_CONFIG
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::ChartFlat.Refresh
  .elseif wParam == IDC_SGC_PREVIEW
    OCall xsi.CtlsGet
    OCall [xsi].pOwner::ChartFlat.Refresh
  .elseif (wParam >= IDC_SGC_GRID) && (wParam <= IDC_SGC_SCALES)
    mov CC.lStructSize, sizeof CC
    m2m CC.hwndOwner, [xsi].hWnd, xdx
    m2m CC.hInstance, hInstance, xdx
    mov CC.Flags, CC_RGBINIT; or CC_FULLOPEN
    m2z CC.lCustData
    m2z CC.lpfnHook
    m2z CC.lpTemplateName

    ;Fill 1st part with the CHT_COLOR_CONFIG colors
    lea xdi, ColorRef
    mov CC.lpCustColors, xdi
    lea xax, [xsi].NewColors
    invoke MemClone, xdi, xax, sizeof CHT_COLOR_CONFIG

    ;Fill the 2 remaining colors with white
    lea xdi, ColorRef + 6*sizeof DWORD
    mov eax, 255
    mov ecx, 3
    rep stosb                                           ;Store B = G = R = eax
    xor eax, eax
    stosb                                               ;Store alpha = 0
    mov eax, 255
    mov ecx, 3
    rep stosb                                           ;Store B = G = R = eax
    xor eax, eax
    stosb                                               ;Store alpha = 0

    ;Fill 2nd part with a gray scale
    mov edx, 255*256
    .repeat
      mov eax, edx
      shr eax, 8                                        ;/256
      mov ecx, 3
      rep stosb                                         ;Store B = G = R = eax
      xor eax, eax
      stosb                                             ;Store alpha = 0
      sub edx, 9325                                     ;int(255 * 256 / 7)
    .until SIGN?

    .if wParam == IDC_SGC_GRID
      lea xbx, [xsi].NewColors.MjrGrid
    .elseif wParam ==  IDC_SGC_PLOTAREA
      lea xbx, [xsi].NewColors.PlotArea
    .elseif wParam == IDC_SGC_PLOTBORDER
      lea xbx, [xsi].NewColors.PlotBorder
    .elseif wParam == IDC_SGC_BACKGROUND
      lea xbx, [xsi].NewColors.Background
    .elseif wParam == IDC_SGC_SCALES
      lea xbx, [xsi].NewColors.Scales
    .endif

    m2m CC.rgbResult, DWORD ptr [xbx], edx
    invoke ChooseColor, addr CC
    .if eax
      m2m [xbx], CC.rgbResult, edx
      invoke GetDlgItem, [xsi].hWnd, DWORD ptr wParam
      invoke SendMessage, xax, BM_SETCOLOR, 0, CC.rgbResult
    .endif
  .endif
MethodEnd

endif
