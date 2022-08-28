; ==================================================================================================
; Title:      Demo09.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 9.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Collection, GifDecoder, GifPlayer
MakeObjects Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout, DialogPassword
MakeObjects WinApp, SdiApp

include Demo09_Globals.inc                              ;Application globals
include Demo09_Main.inc                                 ;Application object

start proc
  local PwdDlg:$Obj(DialogPassword)                     ;Object instance on stack

  SysInit                                               ;Runtime initialization of OOP model

  New PwdDlg::DialogPassword                            ;Setup local object (no allocation)
  OCall PwdDlg::DialogPassword.Init, NULL, NULL, \      ;Initialize it
                                     $OfsCStr("Password validation (hello)"), \
                                     $OfsCStr("hello"), 3
  OCall PwdDlg::DialogPassword.Show                     ;Show modal dialog
  .if eax != FALSE
    finit
    OCall $ObjTmpl(Application)::Application.Init       ;Initialize appl. using the obj. template
    OCall $ObjTmpl(Application)::Application.Run        ;Execute it
    OCall $ObjTmpl(Application)::Application.Done       ;Finalie the application
  .endif
  OCall PwdDlg::DialogPassword.Done                     ;Finalize the password dialog

  SysDone                                               ;;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit returning 0 to the OS
start endp

end
