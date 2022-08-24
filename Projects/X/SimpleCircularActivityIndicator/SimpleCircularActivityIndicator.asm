; ==================================================================================================
; Title:      SimpleCircularActivityIndicator.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Simple Circular Activity Indicator.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &COMPath&COM.inc                              ;COM basic support
% include &MacPath&fMath.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Msimg32.lib
% includelib &LibPath&Windows\Ole32.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects SimpleCircularActivityIndicator
MakeObjects WinApp, SdiApp

include SimpleCircularActivityIndicator_Globals.inc     ;Application globals
include SimpleCircularActivityIndicator_Main.inc        ;Application object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  DbgClearAll
  invoke CoInitialize, 0
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application
  invoke CoUninitialize

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
