; ==================================================================================================
; Title:      ViewDemo.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm TextView demonstration program.
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, ANSI_STRING;, DEBUG(WND)

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\Msimg32.lib
% includelib &LibPath&Windows\Comctl32.lib

% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\IImgCtx.inc

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects Window, Dialog, DialogModal, DialogAbout, Image
MakeObjects WinApp, SdiApp
MakeObjects TextView

include TextViewDemo_Globals.inc
include TextViewDemo_Main.inc

.code
start proc
  SysInit
  DbgClearAll
  DbgText "Hello"
  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done
  SysDone
  invoke ExitProcess, 0
start endp

end
