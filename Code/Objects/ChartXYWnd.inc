; ==================================================================================================
; Title:      ChartXYWnd.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartXYWnd objects.
; Notes:      Version 1.0.0, August 2021
; ==================================================================================================



; ==================================================================================================
;    ChartXYWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYWnd.DrawMarkerAt
; Purpose:    Display the plot data as a line.
; Arguments:  Arg1: Output device context.
;             Arg2: -> ChartXYSeries
;             Arg3: Marker center position X.
;             Arg4: Marker center position Y.
; Return:     Nothing.

Method ChartXYWnd.DrawMarkerAt, uses xbx xdi xsi, hDC:HDC, pSeries:$ObjPtr(ChartXYSeries), \
                                               sdPosX:SDWORD, sdPosY:SDWORD
  local Pos:RECT, PolyPnts[16]:POINT

  SetObject xsi
  mov xdi, pSeries
  .if xdi != NULL && [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize != 0
    .if [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_SQUARE
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_RECT_VER
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_RECT_HOR
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_CIRCLE
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_ELLIPSE_VER
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_ELLIPSE_HOR
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_RHOMBUS
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 3*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      dec eax
      mov [xbx + 1*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 0*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      dec ecx
      mov [xbx + 2*sizeof(POINT)].POINT.y, ecx
      invoke Polygon, hDC, xbx, 4

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_RHOMBUS_HOR
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 3*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_RHOMBUS_VER
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      shr edx, 1
      sub ecx, edx
      mov [xbx + 0*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_CROSS
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 06*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 03*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 09*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 08*sizeof(POINT)].POINT.x, eax
      mov [xbx + 10*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      dec eax
      mov [xbx + 02*sizeof(POINT)].POINT.x, eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 01*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 11*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_STAR_4
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 02*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 06*sizeof(POINT)].POINT.y, ecx
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 06*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      dec eax
      mov [xbx + 02*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 00*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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

    .elseif [xdi].$Obj(ChartXYSeries).Setup.dMarkerShape == CHTXY_MARKER_STAR_8
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 08*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 04*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 12*sizeof(POINT)].POINT.y, ecx

      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 12*sizeof(POINT)].POINT.x, eax
      add eax, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      dec eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 00*sizeof(POINT)].POINT.y, ecx
      add ecx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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


      mov ecx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
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
; Method:     ChartXYWnd.DrawSeries
; Purpose:    Display the plot data as a line.
; Arguments:  Arg1: Output device context.
;             Arg2: -> ChartXYSeries.
; Return:     Nothing.

Method ChartXYWnd.DrawSeries, uses xbx xdi xsi, hDC:HDC, pSeries:$ObjPtr(ChartXYSeries)
  local hRgn:HRGN, hPrevRgn:HRGN, hPrvPen:HPEN, hPrvBrush:HBRUSH
  local fXdelta:CHT_FLOAT, fYdelta:CHT_FLOAT
  local fX0:CHT_FLOAT, fY0:CHT_FLOAT, fX1:CHT_FLOAT, fY1:CHT_FLOAT
  local Pnt0:POINT, Pnt1:POINT, PrvPnt0:POINT, PrvPnt1:POINT

  SetObject xsi
  mov xdi, pSeries
  assume xdi:$ObjPtr(ChartXYSeries)

  ;Clip drowing to the plotarea
  invoke GetClipRgn, hDC, hPrevRgn
  mov hRgn, $invoke(CreateRectRgn, [xsi].PlotRect.left,  [xsi].PlotRect.top, \
                                   [xsi].PlotRect.right, [xsi].PlotRect.bottom)
  invoke SelectClipRgn, hDC, hRgn

  ;Reset all PrvPnt
  xor eax, eax
  mov PrvPnt0.x, eax
  mov PrvPnt0.y, eax
  mov PrvPnt1.x, eax
  mov PrvPnt1.y, eax

  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_DEPICTION
    .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
      mov eax, [xdi].Setup.LineColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreatePen, [xdi].Setup.dLineStyle, [xdi].Setup.dLineWidth, eax
    mov hPrvPen, $invoke(SelectObject, hDC, xax)

    mov ebx, [xdi].dDataFrom
    add ebx, [xdi].dDataCount
    dec ebx

    .while (SDWORD ptr ebx > [xdi].dDataFrom)
      OCall xdi::ChartXYSeries.ItemAt, 0, ebx
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

      fld [xsi].ScaleY1.fScaleMin
      fld [xsi].ScaleY1.fScaleMax
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

      fld [xsi].ScaleY1.fScaleMin
      fld [xsi].ScaleY1.fScaleMax
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
      fistp Pnt0.x
      mov edx, [xsi].PlotRect.left
      add Pnt0.x, edx
      fld fY0
      fsub [xsi].ScaleY1.fScaleMin
      fmul [xsi].ScaleY1.fScaleFactor
      fistp Pnt0.y
      neg Pnt0.y
      mov edx, [xsi].PlotRect.bottom
      add Pnt0.y, edx

      fld fX1
      fsub [xsi].ScaleX.fScaleMin
      fmul [xsi].ScaleX.fScaleFactor
      fistp Pnt1.x
      mov edx, [xsi].PlotRect.left
      add Pnt1.x, edx
      fld fY1
      fsub [xsi].ScaleY1.fScaleMin
      fmul [xsi].ScaleY1.fScaleFactor
      fistp Pnt1.y
      neg Pnt1.y
      mov edx, [xsi].PlotRect.bottom
      add Pnt1.y, edx

      ;Avoid drawing the same line again.
      ;If the previous line has the same endpoints, then skip it
      mov eax, Pnt1.x
      mov ecx, Pnt1.y
      cmp eax, PrvPnt0.x
      jne @F
      cmp ecx, PrvPnt0.y
      lea xdx, PrvPnt1                          ;If we have a match with PrvPnt0 => check only PrvPnt1
      je @@CheckNextPnt
    @@:
      cmp eax, PrvPnt1.x
      jne @@DrawLine
      cmp ecx, PrvPnt1.y
      jne @@DrawLine
      lea xdx, PrvPnt0                          ;We have a match with PrvPnt1 => check only PrvPnt0

    @@CheckNextPnt:
      mov eax, Pnt0.x
      mov ecx, Pnt0.y
      cmp eax, [xdx].POINT.x
      jne @@DrawLine
      cmp ecx, [xdx].POINT.y
      jne @@DrawLine
      je @F                                     ;Line match found => skip this line

    @@DrawLine:
      invoke MoveToEx, hDC, Pnt0.x, Pnt0.y, NULL
      invoke LineTo, hDC, Pnt1.x, Pnt1.y
      s2s PrvPnt0, Pnt0, xax, xcx, xmm0
      s2s PrvPnt1, Pnt1, xax, xcx, xmm0
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
  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_MARKER
    .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
      mov eax, [xdi].Setup.MarkerBorderColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreatePen, PS_SOLID, [xdi].Setup.dMarkerBorderWidth, eax
    mov hPrvPen, $invoke(SelectObject, hDC, xax)
    .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
      mov eax, [xdi].Setup.MarkerFillColor
    .else
      mov eax, $RGB(255,255,255)
    .endif
    invoke CreateSolidBrush, eax
    mov hPrvBrush, $invoke(SelectObject, hDC, xax)

    mov ebx, [xdi].dDataFrom
    add ebx, [xdi].dDataCount
    dec ebx
    .while (SDWORD ptr ebx >= [xdi].dDataFrom)
      OCall xdi::ChartXYSeries.ItemAt, 0, ebx

      fld CHT_FLOAT ptr [xax]
      fsub [xsi].ScaleX.fScaleMin
      fmul [xsi].ScaleX.fScaleFactor
      fistp Pnt0.x
      mov edx, [xsi].PlotRect.left
      add Pnt0.x, edx
      fld CHT_FLOAT ptr [xax + sizeof(CHT_FLOAT)]
      fsub [xsi].ScaleY1.fScaleMin
      fmul [xsi].ScaleY1.fScaleFactor
      fistp Pnt0.y
      neg Pnt0.y
      mov edx, [xsi].PlotRect.bottom
      add Pnt0.y, edx

      ;Check if any part of the marker is visible
      mov ecx, Pnt0.x
      mov edx, [xdi].Setup.dMarkerSize
      shr edx, 1
      lea eax, [ecx + edx]                              ;eax = marker right border
      cmp eax, [xsi].PlotRect.left
      jl @F
      sub ecx, edx                                      ;ecx = marker left border
      cmp ecx, [xsi].PlotRect.right
      jg @F
      mov ecx, Pnt0.y
      lea eax, [ecx + edx]                              ;eax = marker bottom border
      cmp eax, [xsi].PlotRect.top
      jl @F
      sub ecx, edx                                      ;eax = marker top border
      cmp ecx, [xsi].PlotRect.bottom
      jg @F
      OCall xsi.DrawMarkerAt, hDC, xdi, Pnt0.x, Pnt0.y

      ;Create an InfoArea for each visible marker
      MemAlloc sizeof(InfoArea)
      OCall [xsi].InfoAreas::DataCollection.Insert, xax

      ;Calc bounding square RECT
      mov edx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      mov ecx, Pnt0.x
      shr edx, 1
      sub ecx, edx
      mov [xax].InfoArea.Area.left, ecx
      add ecx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      mov [xax].InfoArea.Area.right, ecx
      mov ecx, Pnt0.y
      sub ecx, edx
      mov [xax].InfoArea.Area.top, ecx
      add ecx, [xdi].$Obj(ChartXYSeries).Setup.dMarkerSize
      mov [xax].InfoArea.Area.bottom, ecx

      ;Save additional information
      mov [xax].InfoArea.dDataIndex, ebx
      mov [xax].InfoArea.pSeries, xdi

    @@:
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
; Method:     ChartXYWnd.GetDataTipText
; Purpose:    Return a string inforation about data.
; Arguments:  Arg1: -> Destination buffer. Max 1024 chars.
;             Arg2: -> Series.
;             Arg2: Data index into ChartSeries.
; Return:     Nothing.

Method ChartXYWnd.GetDataTipText, uses xsi xbx, pBuffer:PSTRING, pSeries:$ObjPtr(ChartSeries), dDataIndex:DWORD
  local cStrBufferX[20]:CHR, cStrBufferY[20]:CHR

  SetObject xsi
  mov xbx, pSeries
  OCall xbx::ChartXYSeries.ItemAt, 0, dDataIndex
  fld CHT_FLOAT ptr [xax]
  fld CHT_FLOAT ptr [xax + sizeof(CHT_FLOAT)]
  invoke St0ToStr, addr cStrBufferY, 0, 7, f_NOR or f_TRIM
  fUnload
  invoke St0ToStr, addr cStrBufferX, 0, 7, f_NOR or f_TRIM
  fUnload

  invoke wsprintf, pBuffer, $OfsCStr("Name: %s", CRLF, "Description: %s", CRLF, \
                                     "  X = %s %s", CRLF, "  Y = %s %s"), \
                   [xbx].$Obj(ChartXYSeries).pName, \
                   [xbx].$Obj(ChartXYSeries).pDescription, \
                   addr cStrBufferX, [xsi].ScaleX.pUnit, \
                   addr cStrBufferY, [xsi].ScaleY1.pUnit
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYWnd.Init
; Purpose:    Initialize the ChartXYWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent Window handle.
;             Arg3: -> Window initialization Data.
; Return:     Nothing.

Method ChartXYWnd.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_CHART
  ;DbgText "ChartXYWnd.Init"
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
; Method:     ChartXYWnd.ShowSetupDlg
; Purpose:    Displays the chart setup dialog.
; Arguments:  Arg1: Dialog popup X position on screen.
;             Arg2: Dialog popup Y position on screen.
;             Arg3: Selected tab on the dialog. 
; Return:     Nothing.

Method ChartXYWnd.ShowSetupDlg, uses xsi, sdPosX:SDWORD, sdPosY:SDWORD, dTabIndex:DWORD 
  local SetupDlg:$Obj(ChartXYSetup)

  ;DbgText "ChartWnd.ShowSetupDlg"
  SetObject xsi
  New SetupDlg::ChartXYSetup
  OCall SetupDlg::ChartXYSetup.Init, xsi, [xsi].hWnd, dTabIndex
  OCall SetupDlg::ChartXYSetup.ShowAt, sdPosX, sdPosY
  OCall SetupDlg::ChartXYSetup.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYWnd.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ChartXYWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_DBLCLKS or CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(ChartXYWnd.WndProc), xdx
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
; Method:     ChartXYWnd.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method ChartXYWnd.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "ChartXYWnd.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(ChartXYWnd)
      invoke GetParent, pSelf
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      ACall xsi::ChartXYWnd.Init, xax, pSelf             ;Window.Init
      BitSet [xsi].$Obj(ChartXYWnd).dFlags, CHT_FLAG_SELF_INST
    .else
      ;Code call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(ChartXYWnd).hWnd, pSelf, xax
      BitClr [xsi].$Obj(ChartXYWnd).dFlags, CHT_FLAG_SELF_INST
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi  ;Store the instance pointer
    OCall xsi::ChartXYWnd.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::ChartXYWnd.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(ChartXYWnd).dFlags, CHT_FLAG_SELF_INST
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd

