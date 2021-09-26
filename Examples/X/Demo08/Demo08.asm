; ==================================================================================================
; Title:      Demo08.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm DlgApp demo application.
; Notes:      Version C.1.0, September 2021
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&fMath.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Window
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, DlgApp


include Demo08_Globals.inc                              ;Application globals
include Demo08_Main.inc                                 ;Application object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  DbgClearAll
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
