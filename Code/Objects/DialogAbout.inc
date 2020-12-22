; ==================================================================================================
; Title:      DialogAbout.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of about dialog objects.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     DialogAbout
; Purpose:    Generic modal about dialog. It shows a single text on a static control.
;             This dialog uses the DIALOGABOUT resurce which must be located in application resource
;             file (*.rc). DialogAbout.rc may be included for this purpose.

Object DialogAbout, DialogAboutID, DialogModal
  RedefineMethod    CtlsSet
  RedefineMethod    Init,       POINTER, HWND, HICON, PSTRING

  DefineVariable    hIcon,      HICON,      0
  DefineVariable    pText,      PSTRING,    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

IDC_DAB_ICON    equ     100
IDC_DAB_TEXT    equ     101

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:       DialogAbout.CtlsSet
; Purpose:      Setup the controls of the About dialog.
; Arguments:    None.
; Return:       Nothing.

Method DialogAbout.CtlsSet, uses xsi
  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_DAB_ICON                   ;Get static icon window HANDLE
  invoke SendMessage, xax, STM_SETICON, [xsi].hIcon, NULL       ;Set icon
  invoke SetDlgItemText, [xsi].hWnd, IDC_DAB_TEXT, [xsi].pText  ;Set static about text
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:       DialogAbout.Init
; Purpose:      Initialize the about dialog using the "DIALOGABOUT" dialog resource.
; Arguments:    Arg1: -> Owner object.
;               Arg2: Parent window HANDLE.
;               Arg3: Icon HANDLE.
;               Arg4: -> About text.
; Return:       Nothing.

Method DialogAbout.Init,, pOwner:POINTER, hParent:HWND, hIcon:HICON, pText:PSTRING
  SetObject xcx
  m2m [xcx].hIcon, hIcon, xax
  m2m [xcx].pText, pText, xdx
  ACall xcx::DialogAbout.Init, pOwner, hParent, $OfsCStr("DIALOGABOUT")
MethodEnd

endif
