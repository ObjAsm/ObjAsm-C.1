; ==================================================================================================
; Title:      ChartXY.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartXY objects.
; Notes:      Version 1.0.0, August 2021
;               - First release. Code based on PlotXY object.
;                 Line clipping is implemented using the Liang-Barsky algorithm.
;                 https://www.skytopia.com/project/articles/compsci/clipping.html
;                 https://arxiv.org/pdf/1908.01350.pdf

; ==================================================================================================


CHTXY_SERIES_SHOW_LINE    equ   BIT00
CHTXY_SERIES_SHOW_MARKER  equ   BIT01

CHTXY_MARKER_NONE         equ   0
CHTXY_MARKER_SQUARE       equ   1
CHTXY_MARKER_RECT_HOR     equ   2
CHTXY_MARKER_RECT_VER     equ   3
CHTXY_MARKER_CIRCLE       equ   4
CHTXY_MARKER_ELLIPSE_HOR  equ   5
CHTXY_MARKER_ELLIPSE_VER  equ   6
CHTXY_MARKER_RHOMBUS      equ   7
CHTXY_MARKER_RHOMBUS_HOR  equ   8
CHTXY_MARKER_RHOMBUS_VER  equ   9
CHTXY_MARKER_CROSS        equ   10
CHTXY_MARKER_STAR_4       equ   11
CHTXY_MARKER_STAR_8       equ   12

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartXY
; Purpose: This object draws a XY plot on a surface. It works using the ChartSeries object, that
;          holds the information for each data line on the plot. 2 specialized dialogs,
;          DialogSetupChartScale and DialogSetupChartColors are used to customize the drawing.
;          They are called when the user doubleclicks on some plot element.
;          Simple drag mouse movements moves the plot area, while pressing the SHIFT key, the plot
;          area is resized.
; Note:    - X and Y data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.

Object ChartXY, ChartXYID, ChartFlat
  RedefineMethod    DrawSeries,         HDC, $ObjPtr(ChartSeries)   ;hDC, -> ChartSeries
  VirtualMethod     DrawMarkerAt,       HDC, $ObjPtr(ChartSeries), SDWORD, SDWORD
  RedefineMethod    Init,               POINTER, HWND, PDEF_CHART
  StaticMethod      Startup
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szChartXY, "ChartXY"


; ==================================================================================================
;    ChartXY implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXY.DrawMarkerAt
; Purpose:    Display the plot data as a line.
; Arguments:  Arg1: Output device context.
;             Arg2: -> ChartSeries
;             Arg3: Marker center position X.
;             Arg4: Marker center position Y.
; Return:     Nothing.

Method ChartXY.DrawMarkerAt, uses xbx xdi xsi, hDC:HDC, pSeries:$ObjPtr(ChartSeries), \
                                               sdPosX:SDWORD, sdPosY:SDWORD
  local Pos:RECT, PolyPnts[16]:POINT

  SetObject xsi
  mov xdi, pSeries
  .if xdi != NULL && [xdi].$Obj(ChartSeries).dMarkerSize != 0 && \
                     [xdi].$Obj(ChartSeries).dMarkerShape != CHTXY_MARKER_NONE
    .if [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_SQUARE
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      invoke Rectangle, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_RECT_VER
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      shr edx, 1
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      invoke Rectangle, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_RECT_HOR
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      shr edx, 1
      shr eax, 1
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      invoke Rectangle, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_CIRCLE
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      invoke Ellipse, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_ELLIPSE_VER
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      shr edx, 1
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      invoke Ellipse, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_ELLIPSE_HOR
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      shr edx, 1
      shr eax, 1
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      invoke Ellipse, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_RHOMBUS
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 3*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartSeries).dMarkerSize
      dec eax
      mov [xbx + 1*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 0*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartSeries).dMarkerSize
      dec ecx
      mov [xbx + 2*sizeof(POINT)].POINT.y, ecx
      invoke Polygon, hDC, xbx, 4

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_RHOMBUS_HOR
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 3*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartSeries).dMarkerSize
      dec eax
      mov [xbx + 1*sizeof(POINT)].POINT.x, eax
      mov eax, edx
      shr edx, 1
      sub ecx, edx
      mov [xbx + 0*sizeof(POINT)].POINT.y, ecx
      add ecx, eax
      dec ecx
      mov [xbx + 2*sizeof(POINT)].POINT.y, ecx
      invoke Polygon, hDC, xbx, 4

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_RHOMBUS_VER
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      shr edx, 1
      sub ecx, edx
      mov [xbx + 0*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartSeries).dMarkerSize
      dec ecx
      mov [xbx + 2*sizeof(POINT)].POINT.y, ecx
      mov ecx, edx
      shr edx, 1
      sub eax, edx
      mov [xbx + 3*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      dec eax
      mov [xbx + 1*sizeof(POINT)].POINT.x, eax

      invoke Polygon, hDC, xbx, 4

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_CROSS
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 06*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 03*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 09*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 08*sizeof(POINT)].POINT.x, eax
      mov [xbx + 10*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartSeries).dMarkerSize
      dec eax
      mov [xbx + 02*sizeof(POINT)].POINT.x, eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 01*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 11*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartSeries).dMarkerSize
      dec ecx
      mov [xbx + 05*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 07*sizeof(POINT)].POINT.y, ecx
      mov ecx, edx
      shr edx, 1
      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 07*sizeof(POINT)].POINT.x, eax
      mov [xbx + 09*sizeof(POINT)].POINT.x, eax
      mov [xbx + 11*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 01*sizeof(POINT)].POINT.x, eax
      mov [xbx + 03*sizeof(POINT)].POINT.x, eax
      mov [xbx + 05*sizeof(POINT)].POINT.x, eax
      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 00*sizeof(POINT)].POINT.y, eax
      mov [xbx + 02*sizeof(POINT)].POINT.y, eax
      mov [xbx + 10*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 04*sizeof(POINT)].POINT.y, eax
      mov [xbx + 06*sizeof(POINT)].POINT.y, eax
      mov [xbx + 08*sizeof(POINT)].POINT.y, eax

      invoke Polygon, hDC, xbx, 12

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_STAR_4
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 02*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 06*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 06*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartSeries).dMarkerSize
      dec eax
      mov [xbx + 02*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 00*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartSeries).dMarkerSize
      dec ecx
      mov [xbx + 04*sizeof(POINT)].POINT.y, ecx
      shr edx, 1
      mov ecx, edx
      shr edx, 1
      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 05*sizeof(POINT)].POINT.x, eax
      mov [xbx + 07*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 01*sizeof(POINT)].POINT.x, eax
      mov [xbx + 03*sizeof(POINT)].POINT.x, eax
      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 01*sizeof(POINT)].POINT.y, eax
      mov [xbx + 07*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 03*sizeof(POINT)].POINT.y, eax
      mov [xbx + 05*sizeof(POINT)].POINT.y, eax
      invoke Polygon, hDC, xbx, 8

    .elseif [xdi].$Obj(ChartSeries).dMarkerShape == CHTXY_MARKER_STAR_8
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 08*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 04*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 12*sizeof(POINT)].POINT.y, ecx

      mov edx, [xdi].$Obj(ChartSeries).dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 12*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartSeries).dMarkerSize
      dec eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 00*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartSeries).dMarkerSize
      dec ecx
      mov [xbx + 08*sizeof(POINT)].POINT.y, ecx


      mov ecx, edx
      shr edx, 1
      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 11*sizeof(POINT)].POINT.x, eax
      mov [xbx + 13*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 03*sizeof(POINT)].POINT.x, eax
      mov [xbx + 05*sizeof(POINT)].POINT.x, eax

      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 01*sizeof(POINT)].POINT.y, eax
      mov [xbx + 15*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 07*sizeof(POINT)].POINT.y, eax
      mov [xbx + 09*sizeof(POINT)].POINT.y, eax


      mov ecx, edx
      shr edx, 1
      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 09*sizeof(POINT)].POINT.x, eax
      mov [xbx + 15*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 01*sizeof(POINT)].POINT.x, eax
      mov [xbx + 07*sizeof(POINT)].POINT.x, eax

      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 03*sizeof(POINT)].POINT.y, eax
      mov [xbx + 13*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 05*sizeof(POINT)].POINT.y, eax
      mov [xbx + 11*sizeof(POINT)].POINT.y, eax


      mov ecx, [xdi].$Obj(ChartSeries).dMarkerSize
      lea ecx, [2*ecx + ecx]
      shr ecx, 2
      mov edx, ecx
      shr edx, 1

      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 10*sizeof(POINT)].POINT.x, eax
      mov [xbx + 14*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 02*sizeof(POINT)].POINT.x, eax
      mov [xbx + 06*sizeof(POINT)].POINT.x, eax

      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 02*sizeof(POINT)].POINT.y, eax
      mov [xbx + 14*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 06*sizeof(POINT)].POINT.y, eax
      mov [xbx + 10*sizeof(POINT)].POINT.y, eax

      invoke Polygon, hDC, xbx, 16

    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXY.DrawSeries
; Purpose:    Display the plot data as a line.
; Arguments:  Arg1: Output device context.
;             Arg2: -> ChartSeries.
; Return:     Nothing.

Method ChartXY.DrawSeries, uses xbx xdi xsi, hDC:HDC, pSeries:$ObjPtr(ChartSeries)
  local hRgn:HRGN, hPrevRgn:HRGN, hPrvPen:HPEN, hPrvBrush:HBRUSH
  local fXdelta:CHT_FLOAT, fYdelta:CHT_FLOAT
  local fX0:CHT_FLOAT, fY0:CHT_FLOAT, fX1:CHT_FLOAT, fY1:CHT_FLOAT
  local p0:POINT, p1:POINT
  local MarkerRect:RECT, MarkerIntersection:RECT

  SetObject xsi
  mov xdi, pSeries
  assume xdi:$ObjPtr(ChartSeries)
  invoke GetClipRgn, hDC, hPrevRgn
  mov hRgn, $invoke(CreateRectRgn, [xsi].PlotRect.left,  [xsi].PlotRect.top, \
                                   [xsi].PlotRect.right, [xsi].PlotRect.bottom)
  invoke SelectClipRgn, hDC, hRgn
  
  .ifBitSet [xdi].dFlags, CHTXY_SERIES_SHOW_LINE
    .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
      mov eax, [xdi].LineColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreatePen, [xdi].dLineStyle, [xdi].dLineWidth, eax
    mov hPrvPen, $invoke(SelectObject, hDC, xax)

    mov ebx, [xdi].dDataFrom
    add ebx, [xdi].dDataCount
    dec ebx

    .while (SDWORD ptr ebx > [xdi].dDataFrom)
      OCall xdi::ChartSeries.ItemAt, 0, ebx
      fld [xsi].ScaleX.fScaleMin
      fld [xsi].ScaleX.fScaleMax
      fld CHT_FLOAT ptr [xax - 2*sizeof(CHT_FLOAT)]     ;xa, xmax, xmin
      fst fX0
      fcomi st(0), st(2)
      fld CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]     ;xb, xa, xmax, xmin
      fst fX1
      jae @F
      fcomi st(0), st(3)
      jb @NextLine4                                     ;=> fUnload 4
  @@:
      fcomip st(0), st(2)                               ;xa, xmax, xmin
      jbe @F
      fcomi st(0), st(1)                                ;xa, xmax, xmin
      ja @NextLine3                                     ;=> fUnload 3
  @@:
      fUnload 3

      fld [xsi].ScaleY.fScaleMin
      fld [xsi].ScaleY.fScaleMax
      fld CHT_FLOAT ptr [xax - 1*sizeof(CHT_FLOAT)]     ;ya, ymax, ymin
      fst fY0
      fcomi st(0), st(2)
      fld CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]     ;yb, ya, ymax, ymin
      fst fY1
      jae @F
      fcomi st(0), st(3)
      jb @NextLine4                                     ;=> fUnload 4
  @@:
      fcomip st(0), st(2)                               ;ya, ymax, ymin
      jbe @F
      fcomi st(0), st(1)                                ;ya, ymax, ymin
      ja @NextLine3                                     ;=> fUnload 3
  @@:
      fUnload 1                                         ;ymax, ymin
      ;If we are here, we excluded all obvious lines outside the clipping rectangle

      fld fX1
      fsub fX0
      fstp fXdelta
      fld fY1
      fsub fY0
      fstp fYdelta

      fld fY0                                           ;fY0, ymax, ymin
      fcomi st(0), st(1)
      jbe @F
      ;Calc intersection on top edge
      fUnload
      fst fY0                                           ;ymax, ymin
      fsub CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]    ;ymax - fYb, ymin
      fmul fXdelta
      fdiv fYdelta
      fadd CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]    ;(fXdelta/fYdelta)(ymax - fYb) + fXb, ymin
      fstp fX0                                          ;ymin
      fUnload
      jmp @1C
  @@: 
      fcomi st(0), st(2)                                ;fY0, ymax, ymin
      jae @1B                                            
      ;Calc intersection on bottom edge
      fUnload 2                                         ;ymin
      fst fY0
      fsub CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]    ;ymin - fYb 
      fmul fXdelta
      fdiv fYdelta
      fadd CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]    ;(fXdelta/fYdelta)(ymin - fYb) + fXb
      fstp fX0
      jmp @1C
  @1B:
      fUnload 3
  @1C:
      fld [xsi].ScaleX.fScaleMin
      fld [xsi].ScaleX.fScaleMax
      fld fX0                                           ;fX0, xmax, xmin
      fcomi st(0), st(1)
      jbe @F
      fUnload                                           ;xmax, xmin
      ;Calc intersection on right edge
      fst fX0
      fsub CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]
      fmul fYdelta
      fdiv fXdelta
      fadd CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]
      fstp fY0
      jmp @2A                                           ;xmin
  @@: 
      fcomi st(0), st(2)                                ;fX0, xmax, xmin
      fUnload 2                                         ;xmin
      jae @2A
      ;Calc intersection on left edge
      fst fX0
      fsub CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]
      fmul fYdelta
      fdiv fXdelta
      fadd CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]
      fst fY0
  @2A:
      fUnload

      fld [xsi].ScaleY.fScaleMin
      fld [xsi].ScaleY.fScaleMax
      fld fY1                                           ;fY1, ymax, ymin
      fcomi st(0), st(1)
      jbe @F
      ;Calc intersection on top edge
      fUnload
      fst fY1                                           ;ymax, ymin
      fsub CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]    ;ymax - fYb, ymin
      fmul fXdelta
      fdiv fYdelta
      fadd CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]    ;(fXdelta/fYdelta)(ymax - fYb) + fXb, ymin
      fstp fX1                                          ;ymin
      fUnload
      jmp @2C
  @@: 
      fcomi st(0), st(2)                                ;fY1, ymax, ymin
      jae @2B                                            
      ;Calc intersection on bottom edge
      fUnload 2                                         ;ymin
      fst fY1
      fsub CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]    ;ymin - fYb 
      fmul fXdelta
      fdiv fYdelta
      fadd CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]    ;(fXdelta/fYdelta)(ymin - fYb) + fXb
      fstp fX1
      jmp @2C
  @2B:
      fUnload 3
  @2C:
      fld [xsi].ScaleX.fScaleMin
      fld [xsi].ScaleX.fScaleMax
      fld fX1                                           ;fX1, xmax, xmin
      fcomi st(0), st(1)
      jbe @F
      fUnload                                           ;xmax, xmin
      ;Calc intersection on right edge
      fst fX1
      fsub CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]
      fmul fYdelta
      fdiv fXdelta
      fadd CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]
      fstp fY1
      jmp @3                                            ;xmin
  @@: 
      fcomi st(0), st(2)
      fUnload 2                                         ;xmin
      jae @3
      ;Calc intersection on left edge
      fst fX1
      fsub CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]
      fmul fYdelta
      fdiv fXdelta
      fadd CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]
      fst fX1
  @3:
      fUnload
      ;If we are here, we will check our results

      fld [xsi].ScaleX.fScaleMin
      fld [xsi].ScaleX.fScaleMax
      fld fX0                                           ;fX0, xmax, xmin
      fcomi st(0), st(2)
      fld fX1                                           ;fX1, fX0, xmax, xmin
      jae @F
      fcomi st(0), st(3)
      jb @NextLine4                                     ;=> fUnload 4
  @@:
      fcomip st(0), st(2)                               ;fX0, xmax, xmin
      jbe @F
      fcomi st(0), st(1)                                ;xa, xmax, xmin
      ja @NextLine3                                     ;=> fUnload 3
  @@:
      fUnload 3

      ;If we are here, we will draw finally our line
      fld fX0
      fsub [xsi].ScaleX.fScaleMin
      fmul [xsi].ScaleX.fScaleFactor
      fistp p0.x
      mov edx, [xsi].PlotRect.left
      add p0.x, edx
      fld fY0
      fsub [xsi].ScaleY.fScaleMin
      fmul [xsi].ScaleY.fScaleFactor
      fistp p0.y
      neg p0.y
      mov edx, [xsi].PlotRect.bottom
      add p0.y, edx
      invoke MoveToEx, hDC, p0.x, p0.y, NULL
      
      fld fX1
      fsub [xsi].ScaleX.fScaleMin
      fmul [xsi].ScaleX.fScaleFactor
      fistp p1.x
      mov edx, [xsi].PlotRect.left
      add p1.x, edx
      fld fY1
      fsub [xsi].ScaleY.fScaleMin
      fmul [xsi].ScaleY.fScaleFactor
      fistp p1.y
      neg p1.y
      mov edx, [xsi].PlotRect.bottom
      add p1.y, edx
      invoke LineTo, hDC, p1.x, p1.y

      jmp @F
@NextLine4:
      fUnload
@NextLine3:
      fUnload 3
@@:
      dec ebx
    .endw
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvPen)
  .endif

  ;Draw the markers
  .ifBitSet [xdi].dFlags, CHTXY_SERIES_SHOW_MARKER
    .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
      mov eax, [xdi].MarkerBorderColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreatePen, PS_SOLID, [xdi].dMarkerBorderWidth, eax
    mov hPrvPen, $invoke(SelectObject, hDC, xax)
    .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
      mov eax, [xdi].MarkerFillColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreateSolidBrush, eax
    mov hPrvBrush, $invoke(SelectObject, hDC, xax)

    mov ebx, [xdi].dDataFrom
    add ebx, [xdi].dDataCount
    dec ebx
    .while (SDWORD ptr ebx >= [xdi].dDataFrom)
      OCall xdi::ChartSeries.ItemAt, 0, ebx

      fld CHT_FLOAT ptr [xax]
      fsub [xsi].ScaleX.fScaleMin
      fmul [xsi].ScaleX.fScaleFactor
      fistp p0.x
      mov edx, [xsi].PlotRect.left
      add p0.x, edx
      fld CHT_FLOAT ptr [xax + sizeof(CHT_FLOAT)]
      fsub [xsi].ScaleY.fScaleMin
      fmul [xsi].ScaleY.fScaleFactor
      fistp p0.y
      neg p0.y
      mov edx, [xsi].PlotRect.bottom
      add p0.y, edx
      
      ;Build marker rectangle
      mov ecx, p0.x
      mov edx, [xdi].dMarkerSize
      shr edx, 1
      lea eax, [ecx + edx]
      mov MarkerRect.right, eax
      sub ecx, edx
      mov MarkerRect.left, ecx
      mov ecx, p0.y
      lea eax, [ecx + edx]
      mov MarkerRect.bottom, eax
      sub ecx, edx
      mov MarkerRect.top, ecx
      
      ;Check if any part of the marker is visible
      invoke IntersectRect, addr MarkerIntersection, addr MarkerRect, addr [xsi].PlotRect
      .if eax
        OCall xsi.DrawMarkerAt, hDC, xdi, p0.x, p0.y
      .endif
      dec ebx
    .endw
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvPen)
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvBrush)
  .endif
    
  invoke SelectClipRgn, hDC, hPrevRgn
  invoke DeleteObject, hRgn
  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXY.Init
; Purpose:    Initialize the ChartXY object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent Window handle.
;             Arg3: -> Window initialization Data.
; Return:     Nothing.

Method ChartXY.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_CHART
  ;DbgText "ChartXY.Init"
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_CHART
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE

  invoke CreateWindowEx, [xbx].dExStyle, offset(szChartXY), NULL, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, xsi
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXY.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ChartXY.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(ChartXY.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szChartXY, xdx
  mov WC.hIcon, 0
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXY.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method ChartXY.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "ChartXY.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(ChartXY)
      invoke GetParent, pSelf
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      ACall xsi::ChartXY.Init, xax, pSelf             ;Window.Init
      BitSet [xsi].$Obj(ChartXY).dFlags, CHT_FLAG_SELF_INST
    .else
      ;Code call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(ChartXY).hWnd, pSelf, xax
      BitClr [xsi].$Obj(ChartXY).dFlags, CHT_FLAG_SELF_INST
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi  ;Store the instance pointer
    OCall xsi::ChartXY.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::ChartXY.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(ChartXY).dFlags, CHT_FLAG_SELF_INST
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd

endif
