; ==================================================================================================
; Title:      ChartBarWnd.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartBarWnd objects.
; Notes:      Version 1.0.0, August 2021
; ==================================================================================================



; ==================================================================================================
;    ChartBarWnd implementation
; ==================================================================================================

BAR_FILL_STYLE_SOLID  equ   HS_DIAGCROSS + 1            ;HS_DIAGCROSS is the last item in the enum.

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartBarWnd.DrawSeries
; Purpose:    Display the plot data as a line.
; Arguments:  Arg1: Output device context.
;             Arg2: -> ChartBarSeries.
; Return:     Nothing.

Method ChartBarWnd.DrawSeries, uses xbx xdi xsi, hDC:HDC, pSeries:$ObjPtr(ChartBarSeries)
  local hRgn:HRGN, hPrevRgn:HRGN, hPrvPen:HPEN, hPrvBrush:HBRUSH
  local Pnt:POINT, Bounds:RECT, Intersection:RECT

  SetObject xsi
  mov xdi, pSeries
  assume xdi:$ObjPtr(ChartBarSeries)

  ;Clip drowing to the plotarea
  invoke GetClipRgn, hDC, hPrevRgn
  mov hRgn, $invoke(CreateRectRgn, [xsi].PlotRect.left,  [xsi].PlotRect.top, \
                                   [xsi].PlotRect.right, [xsi].PlotRect.bottom)
  invoke SelectClipRgn, hDC, hRgn

  .ifBitSet [xdi].dFlags, CHT_SERIES_SHOW_DEPICTION
    .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
      mov eax, [xdi].Setup.BorderColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreatePen, [xdi].Setup.dBorderStyle, [xdi].Setup.dBorderWidth, eax
    mov hPrvPen, $invoke(SelectObject, hDC, xax)

    .if [xdi].Setup.dFillStyle == BAR_FILL_STYLE_SOLID
      .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
        mov eax, [xdi].Setup.FillColorBack
      .else
        mov eax, $RGB(255,255,255)
      .endif
      invoke CreateSolidBrush, eax
    .else
      .ifBitSet [xsi].dFlags, CHT_FLAG_COLOR
        invoke SetBkMode, hDC, OPAQUE
        invoke SetBkColor, hDC, [xdi].Setup.FillColorBack
        invoke CreateHatchBrush, [xdi].Setup.dFillStyle, [xdi].Setup.FillColorFore
      .else
        invoke SetBkMode, hDC, OPAQUE
        invoke SetBkColor, hDC, $RGB(255,255,255) 
        invoke CreateHatchBrush, [xdi].Setup.dFillStyle, $RGB(000,000,000)
      .endif
    .endif
    mov hPrvBrush, $invoke(SelectObject, hDC, xax)

    mov ebx, [xdi].dDataFrom
    add ebx, [xdi].dDataCount
    dec ebx

    fld [xsi].ScaleX.fScaleMin
    fld [xsi].ScaleX.fScaleFactor
    fld [xsi].ScaleY1.fScaleMin
    fld [xsi].ScaleY1.fScaleFactor         ;ScaleY1.fScaleFactor|ScaleY1.fScaleMin|ScaleX.fScaleFactor|ScaleX.fScaleMin|

    .while (SDWORD ptr ebx >= [xdi].dDataFrom)
      OCall xdi::ChartBarSeries.ItemAt, 0, ebx
      fld CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]     ;Y
      fsub st(0), st(2)
      fmul st(0), st(1)
      fistp Bounds.top
      neg Bounds.top
      mov edx, [xsi].PlotRect.bottom
      add Bounds.top, edx

      fldz
      fsub st(0), st(2)
      fmul st(0), st(1)
      fistp Bounds.bottom
      neg Bounds.bottom
      mov edx, [xsi].PlotRect.bottom
      add Bounds.bottom, edx

      fld CHT_FLOAT ptr [xax]                           ;X
      fsub st(0), st(4)
      fmul st(0), st(3)
      fistp Pnt.x
      mov edx, [xsi].PlotRect.left
      add edx, [xdi].Setup.dBarOffset
      add Pnt.x, edx

      mov ecx, [xdi].Setup.dBarWidth
      mov eax, ecx
      shr ecx, 1
      mov edx, Pnt.x
      sub edx, ecx
      mov Bounds.left, edx
      add edx, eax
      mov Bounds.right, edx

      invoke Rectangle, hDC, Bounds.left, Bounds.top, Bounds.right, Bounds.bottom

      ;Check if any part of the bar is visible taking the border into account
      mov xax, pSeries
      mov ecx, [xax].$Obj(ChartBarSeries).Setup.dBorderWidth
      shr ecx, 1
      sub Bounds.left, ecx
      mov edx, Bounds.left
      add edx, [xax].$Obj(ChartBarSeries).Setup.dBarWidth
      add edx, [xax].$Obj(ChartBarSeries).Setup.dBorderWidth
      mov Bounds.right, edx

      mov edx, Bounds.bottom
      sub edx, Bounds.top
      sub Bounds.top, ecx
      mov ecx, Bounds.top
      add ecx, edx
      add ecx, [xax].$Obj(ChartBarSeries).Setup.dBorderWidth
      mov Bounds.bottom, ecx

      invoke IntersectRect, addr Intersection, addr [xsi].PlotRect, addr Bounds
      .if eax != 0
        ;Create an InfoArea for each visible marker
        MemAlloc sizeof(InfoArea)
        OCall [xsi].InfoAreas::DataCollection.Insert, xax
        s2s [xax].InfoArea.Area, Bounds, xcx, xdx, xmm0, xmm1

        ;Save additional information
        mov [xax].InfoArea.dDataIndex, ebx
        mov [xax].InfoArea.pSeries, xdi
      .endif
      dec ebx
    .endw
    fUnload 4
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvPen)
  .endif

  invoke SelectClipRgn, hDC, hPrevRgn
  invoke DeleteObject, hRgn
  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartBarWnd.GetDataTipText
; Purpose:    Return a string inforation about data.
; Arguments:  Arg1: -> Destination buffer. Max 1024 chars.
;             Arg2: -> Series.
;             Arg2: Data index into ChartSeries.
; Return:     Nothing.

Method ChartBarWnd.GetDataTipText, uses xsi xbx, pBuffer:PSTRING, pSeries:$ObjPtr(ChartSeries), dDataIndex:DWORD
  local cStrBufferX[20]:CHR, cStrBufferY[20]:CHR

  SetObject xsi
  mov xbx, pSeries
  OCall xbx::ChartBarSeries.ItemAt, 0, dDataIndex
  fld CHT_FLOAT ptr [xax]
  fld CHT_FLOAT ptr [xax + sizeof(CHT_FLOAT)]
  invoke St0ToStr, addr cStrBufferY, 0, 7, f_NOR or f_TRIM
  fUnload
  invoke St0ToStr, addr cStrBufferX, 0, 7, f_NOR or f_TRIM
  fUnload

  invoke wsprintf, pBuffer, $OfsCStr("Name: %s", CRLF, "Description: %s", CRLF, \
                                     "  X = %s %s", CRLF, "  Y = %s %s"), \
                   [xbx].$Obj(ChartBarSeries).pName, \
                   [xbx].$Obj(ChartBarSeries).pDescription, \
                   addr cStrBufferX, [xsi].ScaleX.pUnit, \
                   addr cStrBufferY, [xsi].ScaleY1.pUnit
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartBarWnd.Init
; Purpose:    Initialize the ChartBarWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent Window handle.
;             Arg3: -> Window initialization Data.
; Return:     Nothing.

Method ChartBarWnd.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_CHART
  ;DbgText "ChartBarWnd.Init"
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_CHART
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE

  invoke CreateWindowEx, [xbx].dExStyle, offset(szChartBar), NULL, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, xsi
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartBarWnd.ShowSetupDlg
; Purpose:    Displays the chart setup dialog.
; Arguments:  Arg1: Dialog popup X position on screen.
;             Arg2: Dialog popup Y position on screen.
;             Arg3: Selected tab on the dialog. 
; Return:     Nothing.

Method ChartBarWnd.ShowSetupDlg, uses xsi, sdPosX:SDWORD, sdPosY:SDWORD, dTabIndex:DWORD 
  local SetupDlg:$Obj(ChartBarSetup)

  ;DbgText "ChartWnd.ShowSetupDlg"
  SetObject xsi
  New SetupDlg::ChartBarSetup
  OCall SetupDlg::ChartBarSetup.Init, xsi, [xsi].hWnd, dTabIndex
  OCall SetupDlg::ChartBarSetup.ShowAt, sdPosX, sdPosY
  OCall SetupDlg::ChartBarSetup.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartBarWnd.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ChartBarWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_DBLCLKS or CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(ChartBarWnd.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szChartBar, xdx
  mov WC.hIcon, 0
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartBarWnd.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method ChartBarWnd.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "ChartBarWnd.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(ChartBarWnd)
      invoke GetParent, pSelf
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      ACall xsi::ChartBarWnd.Init, xax, pSelf             ;Window.Init
      BitSet [xsi].$Obj(ChartBarWnd).dFlags, CHT_FLAG_SELF_INST
    .else
      ;Code call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(ChartBarWnd).hWnd, pSelf, xax
      BitClr [xsi].$Obj(ChartBarWnd).dFlags, CHT_FLAG_SELF_INST
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi  ;Store the instance pointer
    OCall xsi::ChartBarWnd.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::ChartBarWnd.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(ChartBarWnd).dFlags, CHT_FLAG_SELF_INST
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd

