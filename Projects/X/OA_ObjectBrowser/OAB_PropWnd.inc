; ==================================================================================================
; Title:      OAB_PropWnd.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjectBrowser.asm
; Purpose:    PropWnd implementation for OA_ObjBrowser. 
; ==================================================================================================


VIEW_CTRL_ID equ 546983

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FindFinalMember
; Purpose:    Used with Collection.LastThatNot to reset the MDT_FINAL flag.
; Arguments:  Arg1: -> Iterated MEMBERDATA.
;             Arg2: -> Source MEMBERDATA.
;             Arg3: Dummy.
; Return:     eax = Zero stops the iteration.

FindFinalMember proc pMemberData:PMEMBERDATA, pSrcData:PMEMBERDATA, xDummy:XWORD
  mov xax, pMemberData
  mov xdx, [xax].MEMBERDATA.pMemberInfo
  mov xcx, pSrcData
  mov xax, [xcx].MEMBERDATA.pMemberInfo
  invoke StrCompA, [xax].INFORMATION.pName, [xdx].INFORMATION.pName
  .if eax == 0                                          ;Method/Variable found
    mov xcx, pMemberData
    BitClr [xcx].MEMBERDATA.dFlags, MDT_FINAL           ;Reset the flag
    mov xdx, [xcx].MEMBERDATA.pDefinition
    .if xdx == NULL
      mov xdx, [xcx].MEMBERDATA.pMemberInfo
    .endif
    mov xcx, pSrcData
    mov [xcx].MEMBERDATA.pDefinition, xdx               ;Copy pDefinition from MemberData in SrcData
  .endif                                                ;eax == 0 => stop search
  ret
FindFinalMember endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.Done
; Purpose:    Finalizes the PropWnd object and disposes the MDI child window.
; Arguments:  None.
; Return:     Nothing.

Method PropWnd.Done, uses xbx xdi xsi
  SetObject xsi

  ;TextView cleanup

  ;Main menu update
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(ClientWnd).pOwner
  mov xbx, [xdi].$Obj(ObjectBrowser).pClientWnd
  dec [xbx].$Obj(ClientWnd).dChildCount
  OCall xdi::ObjectBrowser.EnableActions
  .if [xbx].$Obj(ClientWnd).dChildCount == 0            ;No more child windows ?
    invoke SendMessage, [xdi].$Obj(ObjectBrowser).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(ObjectBrowser).hMenuInit, NULL
    invoke DrawMenuBar, [xdi].$Obj(ObjectBrowser).hWnd  ;Redraw the new menu bar
  .endif

  ;Final object cleanup
  invoke StrDispose, [xsi].pName
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.Init
; Purpose:    Initalizes the PropWnd object.
; Arguments:  Arg1: -> Owner object (ClientWnd).
;             Arg2: -> Window Class name.
;             Arg2: -> INFORMATION.
; Return:     Nothing.

Method PropWnd.Init, uses xbx xdi xsi, pOwner:$ObjPtr(ClientWnd), pWndClassName:PSTRING, \
                                       pInfo:PINFORMATION
  local Rect:RECT, cTempPath[MAX_PATH]:CHR, dIsMaximized:DWORD, CRect:RECT

  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  m2m [xsi].pInfo, pInfo, xax

  ;Create a local copy of the name (used to refresh the window content)
  mov [xsi].pName, $invoke(StrNew, [xax].INFORMATION.pName)

  ;Apply application setup
  mov xdi, [xsi].pOwner                                 ;xdi -> ClientWnd
  mov xdx, [xdi].$Obj(ClientWnd).pOwner                 ;xdx -> ObjectBrowser
  m2m [xsi].dShowRedefMtds, [xdx].$Obj(ObjectBrowser).dShowRedefMtds, eax
  m2m [xsi].dShowRedefVars, [xdx].$Obj(ObjectBrowser).dShowRedefVars, eax

  ;Polymorphic calls
  OCall xsi.Gather
;  OCall xsi.EmitHtml

  inc [xdi].$Obj(ClientWnd).dChildCount
  invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, addr dIsMaximized
  .if xax != 0 && dIsMaximized == FALSE                 ;xax = MDI Child HWND
    xor ebx, ebx
  .else
    mov ebx, WS_MAXIMIZE
  .endif
  mov xax, pInfo
  invoke CreateMDIWindow, pWndClassName, [xax].INFORMATION.pName, \
                          ebx, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(ClientWnd).hWnd, hInstance, xsi

  invoke GetClientRect, [xsi].hWnd, addr CRect

  %invoke CreateWindowEx, 0, offset cTextViewClass&TARGET_STR_AFFIX, offset szMarkupText, \
                          WS_CHILD or WS_VISIBLE, \
                          CRect.left, CRect.top, CRect.right, CRect.bottom, \
                          [xsi].hWnd, VIEW_CTRL_ID, hInstance, 0
  ;At this point, Window.Init, TextView.OnCreate & TextView.OnSize were called.
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    mov [xsi].pTextView, xax
  .endif

  mov xbx, [xdi].$Obj(ClientWnd).pOwner
  OCall xbx::ObjectBrowser.EnableActions
  .if eax != 0
    .if [xdi].$Obj(ClientWnd).dChildCount == 1          ;First child window ?
      mov xax, [xbx].$Obj(ObjectBrowser).pClientWnd
      invoke SendMessage, [xax].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(ObjectBrowser).hMenuChild, [xbx].$Obj(ObjectBrowser).hMenuChildWnd
      invoke DrawMenuBar, [xbx].$Obj(ObjectBrowser).hWnd  ;Redraw the new menu bar
    .endif
  .else
    invoke GetLastError
    invoke ErrorMessageBox, [xbx].$Obj(ObjectBrowser).hWnd, $OfsCStr("Window creation error"), \
                            LOCALE_USER_DEFAULT, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PropWnd.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  invoke GetActiveWindow
  SetObject xsi
  mov xcx, [xsi].pOwner                                 ;xcx -> ClientWnd
  mov xdx, [xcx].$Obj(ClientWnd).pOwner                 ;xdx -> ObjectBrowser
  .if xax == [xdx].$Obj(ObjectBrowser).hWnd
    invoke DefMDIChildProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method PropWnd.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

  SetObject xsi
  .if wParam != SIZE_MINIMIZED
    invoke GetClientRect, [xsi].hWnd, addr CRect
    mov xax, [xsi].pTextView
    .if xax != NULL
      invoke SetWindowPos, [xax].$Obj(TextView).hWnd, HWND_BOTTOM, \
                           CRect.left, CRect.top, CRect.right, CRect.bottom, SWP_NOZORDER
    .endif  
  .endif
  invoke DefMDIChildProc, [xsi].hWnd, WM_SIZE, wParam, lParam

MethodEnd