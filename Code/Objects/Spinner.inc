; ==================================================================================================
; Title:      Spinner.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of Spinner objects.
; Notes:      Version C.1.1, April 2022
;               - First release.
; ==================================================================================================


SPINNER_STEP_DATA struct
  hBmp  HBITMAP   ?
SPINNER_STEP_DATA ends
PSPINNER_STEP_DATA typedef ptr SPINNER_STEP_DATA

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  Spinner
; Purpose: Implement an animated control, known as a spinner.

Object Spinner, SpinnerID, WinPrimer
  VirtualMethod     AddBmpFromRes,      PSTRING
  VirtualMethod     AddBmpStripFromRes, PSTRING, DWORD
  VirtualMethod     AddImageFromRes,    PSTRING
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  VirtualMethod     Start,              DWORD
  StaticMethod      Startup
  VirtualMethod     Stop
  VirtualMethod     WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnPaint,      WM_PAINT
  VirtualEvent      OnTimer,      WM_TIMER

  DefineVariable    dFlags,       DWORD,    0
  DefineVariable    hTimer,       HANDLE,   0
  DefineVariable    dSpeed,       DWORD,    0
  DefineVariable    dAllocSteps,  DWORD,    0
  DefineVariable    dAllocIncr,   DWORD,    16      ;Allocation increment
  DefineVariable    dTotalSteps,  DWORD,    0
  DefineVariable    dCurrentStep, DWORD,    0
  DefineVariable    pStepData,    PSPINNER_STEP_DATA, NULL
  
ObjectEnd


CStr szSpinnerClass, "OA_SpinnerClass"

; ==================================================================================================

if IMPLEMENT


SPN_WND_SELF_INST equ BIT00

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.AddBmpFromRes
; Purpose:    Load a bitmap from the resource section and add it to the spinner resources.
; Arguments   Arg1: -> Bitmap resource name.
; Return:     Nothing.

Method Spinner.AddBmpFromRes, uses xbx xsi, pBmpName:PSTRING
  SetObject xsi
  mov xbx, $invoke(LoadImage, hInstance, pBmpName, IMAGE_BITMAP, 0, 0, 0)
  mov edx, [xsi].dTotalSteps
  .if edx == 0
    mov eax, [xsi].dAllocIncr
    mov ecx, sizeof(SPINNER_STEP_DATA)
    mul ecx
    MemAlloc eax
    .if xax != NULL
      mov [xsi].pStepData, xax
      m2m [xsi].dAllocSteps, [xsi].dAllocIncr, ecx
      mov [xax].SPINNER_STEP_DATA.hBmp, xbx
      inc [xsi].dTotalSteps
    .endif
  .else
    mov eax, [xsi].dAllocSteps
    .if eax == edx
      add eax, [xsi].dAllocIncr
      mov ecx, sizeof(SPINNER_STEP_DATA)
      mul ecx
      MemReAlloc [xsi].pStepData, eax
      .if xax != NULL
        mov [xsi].pStepData, xax
        mov eax, [xsi].dTotalSteps
        mov ecx, sizeof(SPINNER_STEP_DATA)
        mul ecx
        add xax, [xsi].pStepData
        mov [xax].SPINNER_STEP_DATA.hBmp, xbx
        inc [xsi].dTotalSteps
        mov edx, [xsi].dAllocIncr
        add [xsi].dAllocSteps, edx
      .endif
    .else
      mov eax, [xsi].dTotalSteps
      mov ecx, sizeof(SPINNER_STEP_DATA)
      mul ecx
      add xax, [xsi].pStepData
      mov [xax].SPINNER_STEP_DATA.hBmp, xbx
      inc [xsi].dTotalSteps
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.AddImageFromRes
; Purpose:    Load a Image from the resource section and add it to the spinner resources.
; Arguments   Arg1: -> Image resource name. Must be of type IMAGE = 2110.
; Return:     Nothing.

Method Spinner.AddImageFromRes, uses xbx xsi, pImageName:PSTRING
  local hDC:HDC, Img:$Obj(Image)

  SetObject xsi
;  mov xbx, $invoke(LoadImage, hInstance, pImageName, IMAGE_BITMAP, 0, 0, 0)
  New Img::Image
  OCall Img::Image.Init, xsi
  OCall Img::Image.LoadFromResW, pImageName
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  OCall Img::Image.GetCompatibleBmp, hDC
  invoke CopyImage, xax, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE
  mov xbx, xax
  OCall Img::Image.Done
  DbgBmp xbx
  invoke ReleaseDC, [xsi].hWnd, hDC
  mov edx, [xsi].dTotalSteps
  .if edx == 0
    mov eax, [xsi].dAllocIncr
    mov ecx, sizeof(SPINNER_STEP_DATA)
    mul ecx
    MemAlloc eax
    .if xax != NULL
      mov [xsi].pStepData, xax
      m2m [xsi].dAllocSteps, [xsi].dAllocIncr, ecx
      mov [xax].SPINNER_STEP_DATA.hBmp, xbx
      inc [xsi].dTotalSteps
    .endif
  .else
    mov eax, [xsi].dAllocSteps
    .if eax == edx
      add eax, [xsi].dAllocIncr
      mov ecx, sizeof(SPINNER_STEP_DATA)
      mul ecx
      MemReAlloc [xsi].pStepData, eax
      .if xax != NULL
        mov [xsi].pStepData, xax
        mov eax, [xsi].dTotalSteps
        mov ecx, sizeof(SPINNER_STEP_DATA)
        mul ecx
        add xax, [xsi].pStepData
        mov [xax].SPINNER_STEP_DATA.hBmp, xbx
        inc [xsi].dTotalSteps
        mov edx, [xsi].dAllocIncr
        add [xsi].dAllocSteps, edx
      .endif
    .else
      mov eax, [xsi].dTotalSteps
      mov ecx, sizeof(SPINNER_STEP_DATA)
      mul ecx
      add xax, [xsi].pStepData
      mov [xax].SPINNER_STEP_DATA.hBmp, xbx
      inc [xsi].dTotalSteps
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.AddBmpStripFromRes
; Purpose:    Load a bitmap strip from the resource section, split it into individual bitmaps and
;             add them to the spinner resources.
; Arguments   Arg1: -> Bitmap strip resource name.
;             Arg2: Bitmap count in the strip.
; Return:     Nothing.

Method Spinner.AddBmpStripFromRes, uses xbx xsi, pBmpName:PSTRING, dCount:DWORD
  SetObject xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method Spinner.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.Done
; Purpose:    None.
; Return:     Nothing.

Method Spinner.Done, uses xbx xdi xsi
  DbgText "Spinner.Done"
  SetObject xsi
  OCall xsi.Stop
  mov ebx, [xsi].dTotalSteps
  mov xdi, [xsi].pStepData
  test ebx, ebx
  .while !ZERO?
    invoke DeleteObject, HBITMAP ptr [xdi]
    add xdi, sizeof(SPINNER_STEP_DATA)
    dec ebx
  .endw
  MemFree [xsi].pStepData
  m2z [xsi].pStepData
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.OnTimer
; Purpose:    Event procedure for WM_TIMER message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Spinner.OnTimer, uses xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "Spinner.OnTimer"
  SetObject xsi
  inc [xsi].dCurrentStep
  mov eax, [xsi].dCurrentStep
  .if eax == [xsi].dTotalSteps
    mov [xsi].dCurrentStep, 0
  .endif
  invoke InvalidateRect, [xsi].hWnd, NULL, FALSE
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_UPDATENOW
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Spinner.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, hTmpDC:HDC, hPrvBmp:HBITMAP, bfn:BLENDFUNCTION

;  DbgText "Spinner.OnPaint"
  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)
  mov hTmpDC, $invoke(CreateCompatibleDC, hDC)
  mov eax, [xsi].dCurrentStep
  mov ecx, sizeof(SPINNER_STEP_DATA)
  mul ecx
  add xax, [xsi].pStepData
  mov hPrvBmp, $invoke(SelectObject, hTmpDC, [xax].SPINNER_STEP_DATA.hBmp)
  invoke BitBlt, hDC, 0,0,100,100, hTmpDC,0,0, SRCCOPY
;  invoke TransparentBlt, hDC, 0,0,100,100, hTmpDC,0,0,100,100, $RGB(255,255,255,255) 

;  mov bfn.BlendOp, AC_SRC_OVER
;  mov bfn.BlendFlags, 0
;  mov bfn.SourceConstantAlpha, 255
;  mov bfn.AlphaFormat, AC_SRC_ALPHA
;  invoke AlphaBlend, hDC, 0, 0, \
;                     100, 100, \
;                     hTmpDC, 0, 0, 100, 100, bfn
;  DbgHex eax
  invoke SelectObject, hTmpDC, hPrvBmp
  invoke DeleteObject, hTmpDC

;  mov eax, [xsi].dCurrentStep
;  mov ecx, sizeof(SPINNER_STEP_DATA)
;  mul ecx
;  add xax, [xsi].pStepData
;  invoke DrawTransparentBitmap, hDC, [xax].SPINNER_STEP_DATA.hBmp, 0,0, 80000000h
  invoke EndPaint, [xsi].hWnd, addr PS
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.Start
; Purpose:    Start spinning.
; Arguments:  Arg1: Interval between steps.
; Return:     Nothing.

Method Spinner.Start, uses xsi, dInterval:DWORD
  SetObject xsi
  .if [xsi].hTimer != 0
    invoke KillTimer, [xsi].hWnd, 0 
  .endif
  invoke SetTimer, [xsi].hWnd, 0, dInterval, NULL
  mov [xsi].hTimer, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Spinner.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(Spinner.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szSpinnerClass, xdx
  mov WC.hIcon, 0
  mov WC.hCursor, 0
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.Stop
; Purpose:    Stop spinning.
; Arguments:  None.
; Return:     Nothing.

Method Spinner.Stop, uses xsi
  SetObject xsi
  .if [xsi].hTimer != 0
    invoke KillTimer, [xsi].hWnd, 0
    m2z [xsi].hTimer
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Spinner.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Spinner HANDLE is passed in pSelf (hidden parameter).

Method Spinner.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "Spinner.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(Spinner)
      invoke GetParent, pSelf
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      ACall xsi::Spinner.Init, xax, pSelf              ;Window.Init
      BitSet [xsi].$Obj(Spinner).dFlags, SPN_WND_SELF_INST
    .else
      ;Code call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(Spinner).hWnd, pSelf, xax
      BitClr [xsi].$Obj(Spinner).dFlags, SPN_WND_SELF_INST
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi  ;Store the instance pointer
    OCall xsi::Spinner.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::Spinner.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(Spinner).dFlags, SPN_WND_SELF_INST
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd

endif
