; ==================================================================================================
; Title:      SimpleCircularActivityIndicator.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm implementation of SimpleCircularActivityIndicator objects.
; Notes:      Version C.1.0, August 2022
;               - First release.
; Links:      https://stackoverflow.com/questions/3970066/creating-a-transparent-window-in-c-win32
;             https://stackoverflow.com/questions/42569348/how-to-use-ws-ex-layered-on-child-controls
;             https://www.codeguru.com/multimedia/rotate-a-bitmap-image/
;             https://api.flutter.dev/flutter/material/CircularProgressIndicator-class.html
; ==================================================================================================


SCAI_STATUS_STOPPED   equ 0
SCAI_STATUS_STARTING  equ 1
SCAI_STATUS_RUNNING   equ 2
SCAI_STATUS_STOPPING  equ 3

DEF_SCAI struc
  xCtlID        XWORD     ?         ;Contol ID
  dStyle        DWORD     ?         ;Style
  dExStyle      DWORD     ?         ;Extended style
  pTitle        PSTRING   ?         ;-> Window text
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?         ;X position
      sdPosY    SDWORD    ?         ;Y position
      dWidth    DWORD     ?         ;Width
      dHeight   DWORD     ?         ;Height
    ends
  ends
  dInterval     DWORD     ?
DEF_SCAI ends
PDEF_SCAI typedef ptr DEF_SCAI


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  SimpleCircularActivityIndicator
; Purpose: Implement an animated control that rotates a loaded image to show activity.
; Notes:   Require an addition to the manifest to enable WS_EX_LAYERED style on child windows
;          <application>
;            <!--The ID below indicates app support for Windows 8 -->
;            <supportedOS Id="{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}"/>
;          </application>


Object SimpleCircularActivityIndicator, CircularActivityIndicatorID, WinPrimer
  VirtualMethod     AddBmpFromRes,      PSTRING
  VirtualMethod     AddPngFromRes,      PSTRING
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PDEF_SCAI
  VirtualMethod     InitRes,            POINTER, HWND, DWORD
  VirtualMethod     Start
  StaticMethod      Startup
  VirtualMethod     Stop
  VirtualMethod     WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnTimer,        WM_TIMER

  DefineVariable    dFlags,         DWORD,    0
  DefineVariable    dStatus,        DWORD,    SCAI_STATUS_STOPPED
  DefineVariable    hTimer,         HANDLE,   0
  DefineVariable    hThread,        HANDLE,   0
  DefineVariable    hBitmap,        HBITMAP,  0
  DefineVariable    ControlSize,    POINT,    {}
  DefineVariable    ImageSize,      POINT,    {}

  DefineVariable    r4Rotation,     REAL4,    0.0     ;Rad/Frame
  DefineVariable    r4Scaling,      REAL4,    0.0     ;Factor <= 1.0
  DefineVariable    r4ScaleChange,  REAL4,    0.08    ;Factor/Frame
  DefineVariable    dAlpha,         DWORD,    0       ;Factor 0..255

ObjectEnd


CStr szCircularActivityIndicatorClass, "OA_CircularActivityIndicatorClass"

; ==================================================================================================

if IMPLEMENT

.const
r4RotIncr     REAL4   0.3
dAlphaChange  DWORD   20


SCAI_SELF_INST        equ BIT00

SCAI_STATUS_STOPPED   equ 0
SCAI_STATUS_STARTING  equ 1
SCAI_STATUS_RUNNING   equ 2
SCAI_STATUS_STOPPING  equ 3

SCAI_SCALE_START_END  equ 1.0
SCAI_SCALE_STOP_END   equ 0.0



; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.AddBmpFromRes
; Purpose:    Load a bitmap from the resource section and add it to the spinner resources.
; Arguments   Arg1: -> Bitmap resource name.
; Return:     Nothing.

Method SimpleCircularActivityIndicator.AddBmpFromRes, uses xsi, pBmpName:PSTRING
  local BMP:BITMAP

  SetObject xsi
  .if [xsi].hBitmap != 0
    invoke DeleteObject,  [xsi].hBitmap
  .endif

  mov [xsi].hBitmap, $invoke(LoadImage, hInstance, pBmpName, IMAGE_BITMAP, 0, 0, 0)
  invoke GetObject, [xsi].hBitmap, sizeof BMP, addr BMP
  m2m [xsi].ImageSize.x, BMP.bmWidth, eax
  m2m [xsi].ImageSize.y, BMP.bmHeight, ecx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.AddPngFromRes
; Purpose:    Load a PNG from the resource section and add it to the spinner resources.
; Arguments   Arg1: -> Image resource name. Must be of type IMAGE = 2110.
; Return:     Nothing.

Method SimpleCircularActivityIndicator.AddPngFromRes, uses xsi, pPngName:PSTRING
  local BMP:BITMAP

  SetObject xsi
  .if [xsi].hBitmap != 0
    invoke DeleteObject,  [xsi].hBitmap
  .endif

  mov [xsi].hBitmap, $invoke(LoadPngFromResource, pPngName)
  invoke GetObject, [xsi].hBitmap, sizeof BMP, addr BMP
  m2m [xsi].ImageSize.x, BMP.bmWidth, eax
  m2m [xsi].ImageSize.y, BMP.bmHeight, ecx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method SimpleCircularActivityIndicator.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.Done
; Purpose:    None.
; Return:     Nothing.

Method SimpleCircularActivityIndicator.Done, uses xbx xdi xsi
;  DbgText "SimpleCircularActivityIndicator.Done"
  SetObject xsi
  OCall xsi.Stop
  .if [xsi].hTimer != 0
    invoke KillTimer, [xsi].hWnd, 0
    m2z [xsi].hTimer
  .endif
  invoke DeleteObject, [xsi].hBitmap
  m2z [xsi].hBitmap
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.Init
; Purpose:    Initialize the SimpleCircularActivityIndicator object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent Window HANDLE.
;             Arg3: -> Definition structure.
; Return:     Nothing.

Method SimpleCircularActivityIndicator.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_SCAI
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_SCAI
  mov ecx, [xbx].dExStyle
  or ecx, WS_EX_LAYERED
  invoke CreateWindowEx, ecx, offset(szCircularActivityIndicatorClass), [xbx].pTitle, \
                         [xbx].dStyle, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  ACall xsi.Init, pOwner, xax
  mov [xsi].hTimer, $invoke(SetTimer, [xsi].hWnd, 0, [xbx].dInterval, NULL)
  assume xbx:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.InitRes
; Purpose:    Initialize the SimpleCircularActivityIndicator object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Window HANDLE.
;             Arg3: Frame presentation interval.
; Return:     Nothing.

Method SimpleCircularActivityIndicator.InitRes, uses xsi, pOwner:POINTER, hWnd:HWND, dInterval:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, hWnd
  mov [xsi].hTimer, $invoke(SetTimer, [xsi].hWnd, 0, dInterval, NULL)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.OnTimer
; Purpose:    Event procedure for WM_TIMER message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method SimpleCircularActivityIndicator.OnTimer, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hSrcDC:HDC, hPrvSrcBmp:HBITMAP, hModDC:HDC, hPrvModBmp:HBITMAP, hDstDC:HDC, hPrvModBrush:HBRUSH
  local xform:XFORM, bfn:BLENDFUNCTION, WRect:RECT
  local PtSize:POINT, PtZero:POINT

;  DbgText "SimpleCircularActivityIndicator.OnTimer"
  SetObject xsi

  invoke GetWindowRect, [xsi].hWnd, addr WRect
  mov eax, WRect.right
  mov ecx, WRect.bottom
  sub eax, WRect.left
  sub ecx, WRect.top
  mov [xsi].ControlSize.x, eax
  mov [xsi].ControlSize.y, ecx

  mov hDstDC, $invoke(GetDC, [xsi].hWnd)
  mov hSrcDC, $invoke(CreateCompatibleDC, hDstDC)
  mov hModDC, $invoke(CreateCompatibleDC, hDstDC)

  mov hPrvSrcBmp, $invoke(SelectObject, hSrcDC, [xsi].hBitmap)
  invoke CreateCompatibleBitmap, hDstDC, [xsi].ControlSize.x, [xsi].ControlSize.y
  mov hPrvModBmp, $invoke(SelectObject, hModDC, xax)

  .if [xsi].dStatus != SCAI_STATUS_STOPPED
    fld [xsi].r4Rotation
    fadd r4RotIncr
    fst [xsi].r4Rotation
    fSinCos                           ;  sin   ;  cos

    mov eax, [xsi].dAlpha
    .if [xsi].dStatus == SCAI_STATUS_STARTING
      add eax, dAlphaChange
      .if eax > 255
        mov eax, 255                  ;Saturate
      .endif
      mov [xsi].dAlpha, eax

      fld [xsi].r4Scaling
      fadd [xsi].r4ScaleChange

      fld1
      fcom
      fGetFlags
      .if CARRY?
        mov [xsi].dStatus, SCAI_STATUS_RUNNING
        fstp [xsi].r4Scaling          ;1.0
        fUnload
      .else
        fUnload
        fmul st(1), st(0)
        fmul st(2), st(0)
        fstp [xsi].r4Scaling
      .endif

    .elseif [xsi].dStatus == SCAI_STATUS_STOPPING
      sub eax, dAlphaChange
      .if SDWORD ptr eax < 0
        xor eax, eax
      .endif
      mov [xsi].dAlpha, eax

      fld [xsi].r4Scaling
      fsub [xsi].r4ScaleChange

      fldz
      fcom
      fGetFlags
      .if !CARRY?
        mov [xsi].dStatus, SCAI_STATUS_STOPPED
        fst st(1)
      .endif
      fUnload
      fmul st(1), st(0)
      fmul st(2), st(0)
      fstp [xsi].r4Scaling
    .endif

    fst xform.eM21
    fchs                              ; -sin   ;  cos
    fstp xform.eM12                   ;  cos
    fst xform.eM11
    fstp xform.eM22
    fld1                              ;   1
    fld1                              ;   1    ;    1
    faddp st(1), st(0)                ;   2
    fild [xsi].ImageSize.x            ;   W    ;    2
    fdiv st(0), st(1)                 ;  W/2   ;    2
    fstp xform.eDx_                   ;   2
    fild [xsi].ImageSize.y            ;   H    ;    2
    fdivrp st(1), st(0)               ;  H/2
    fstp xform.eDy

    invoke SetGraphicsMode, hModDC, GM_ADVANCED
    invoke SetWorldTransform, hModDC, addr xform

    invoke CreateSolidBrush, $RGB(128,128,255,128)
    mov hPrvModBrush, $invoke(SelectObject, hModDC, xax)

    mov edx, [xsi].ImageSize.x
    mov eax, [xsi].ImageSize.y
    shr edx, 1
    neg edx
    shr eax, 1
    neg eax
    invoke BitBlt, hModDC, edx, eax, [xsi].ImageSize.x, [xsi].ImageSize.y, hSrcDC, 0, 0, SRCCOPY
    invoke DeleteObject, $invoke(SelectObject, hModDC, hPrvModBrush)
  .endif

  mov bfn.BlendOp, AC_SRC_OVER
  mov bfn.BlendFlags, 0
  mov eax, [xsi].dAlpha
  mov bfn.SourceConstantAlpha, al
  mov bfn.AlphaFormat, AC_SRC_ALPHA
  s2s PtSize, [xsi].ImageSize, xax, xcx, xmm0
  mov PtZero.x, 0
  mov PtZero.y, 0
  invoke UpdateLayeredWindow, [xsi].hWnd, hDstDC, NULL, addr PtSize, \
                              hModDC, addr PtZero, $RGB(0,0,0), addr bfn, ULW_ALPHA
  invoke SelectObject, hSrcDC, hPrvSrcBmp
  invoke DeleteDC, hSrcDC
  invoke SelectObject, hModDC, hPrvModBmp
  invoke DeleteObject, xax
  invoke DeleteDC, hModDC
  invoke ReleaseDC, [xsi].hWnd, hDstDC

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.Start
; Purpose:    Start spinning.
; Arguments:  Arg1: Interval between steps.
; Return:     Nothing.

Method SimpleCircularActivityIndicator.Start, uses xsi
  SetObject xsi
  mov [xsi].dStatus, SCAI_STATUS_STARTING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method SimpleCircularActivityIndicator.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(SimpleCircularActivityIndicator.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szCircularActivityIndicatorClass, xdx
  mov WC.hIcon, 0
  mov WC.hCursor, 0
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.Stop
; Purpose:    Stop spinning.
; Arguments:  None.
; Return:     Nothing.

Method SimpleCircularActivityIndicator.Stop, uses xsi
  SetObject xsi
  mov [xsi].dStatus, SCAI_STATUS_STOPPING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SimpleCircularActivityIndicator.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             SimpleCircularActivityIndicator HANDLE is passed in pSelf (hidden parameter).

Method SimpleCircularActivityIndicator.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "SimpleCircularActivityIndicator.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(SimpleCircularActivityIndicator)
      invoke GetParent, pSelf
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      OCall xsi::SimpleCircularActivityIndicator.InitRes, xax, pSelf, 50
      BitSet [xsi].$Obj(SimpleCircularActivityIndicator).dFlags, SCAI_SELF_INST
    .else
      ;Code call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(SimpleCircularActivityIndicator).hWnd, pSelf, xax
      BitClr [xsi].$Obj(SimpleCircularActivityIndicator).dFlags, SCAI_SELF_INST
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi  ;Store the instance pointer
    OCall xsi::SimpleCircularActivityIndicator.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::SimpleCircularActivityIndicator.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(SimpleCircularActivityIndicator).dFlags, SCAI_SELF_INST
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd

endif
