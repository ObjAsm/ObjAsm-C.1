; ==================================================================================================
; Title:      SimpleCircularActivityIndicator.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Simple Circular Activity Indicator.
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &COMPath&COM.inc                              ;COM basic support
% include &MacPath&fMath.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\richedit.inc


% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Msimg32.lib
% includelib &LibPath&Windows\Ole32.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects SimpleCircularActivityIndicator
MakeObjects WinApp, SdiApp
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects TextView


include SimpleCircularActivityIndicator_Globals.inc     ;Application globals
include SimpleCircularActivityIndicator_Main.inc        ;Application object

.code
start proc                                              ;Program entry point
  local dMajorVersion:DWORD
  SysInit                                               ;Runtime initialization of OOP model

  DbgClearAll
  
  invoke GetWinVersion, addr dMajorVersion, NULL, NULL
  .if dMajorVersion < 8
    invoke MsgBox, 0, offset cWarningMsg, offset cAppWarning, MB_OK
  .else
    invoke CoInitialize, 0
    OCall $ObjTmpl(Application)::Application.Init       ;Initialize application
    OCall $ObjTmpl(Application)::Application.Run        ;Execute application
    OCall $ObjTmpl(Application)::Application.Done       ;Finalize application
    invoke CoUninitialize
  .endif

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
