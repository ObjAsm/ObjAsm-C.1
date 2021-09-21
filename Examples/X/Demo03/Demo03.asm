; ==================================================================================================
; Title:      Demo03.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 3.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&DlgTmpl.inc                          ;Include Dlg Template macros for XMenu
% include &IncPath&Windows\CommCtrl.inc
% includelib &LibPath&Windows\Comctl32.lib

;Load or build the following objects
MakeObjects Primer, Stream, Collection
MakeObjects WinPrimer, Window, Dialog, DialogModal, DialogAbout
MakeObjects DialogModeless, DialogModalIndirect
MakeObjects SimpleImageList, MaskedImageList
MakeObjects MsgInterceptor, WinControl
MakeObjects XMenu, Toolbar, Rebar, Statusbar, Tooltip
MakeObjects WinApp, SdiApp

.code
include Demo03_Globals.inc                              ;Include application globals
include Demo03_Main.inc                                 ;Include Application object

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(Application)::Application.Init             ;Initialize the object data
  OCall $ObjTmpl(Application)::Application.Run              ;Execute the application
  OCall $ObjTmpl(Application)::Application.Done             ;Finalize it

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
