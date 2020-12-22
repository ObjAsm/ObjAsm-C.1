; ==================================================================================================
; Title:      XPropertyTreeTest.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm XPropertyTree Demo Application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&fMath.inc
% include &MacPath&SDLL.inc

% include &IncPath&Windows\mmsystem.inc
% include &IncPath&Windows\shlobj_core.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Ole32.lib


;Load or build the following objects
MakeObjects Primer, Stream, Collection, XWCollection
MakeObjects WinPrimer, Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects DataPool
MakeObjects WinControl, XTreeView
MakeObjects XPropertyTree


include XPropertyTreeTest_Globals.inc
include XPropertyTreeTest_Main.inc

start proc
  SysInit

  OCall $ObjTmpl(DemoApp02)::DemoApp02.Init
  OCall $ObjTmpl(DemoApp02)::DemoApp02.Run
  OCall $ObjTmpl(DemoApp02)::DemoApp02.Done

  SysDone
  invoke ExitProcess, 0
start endp

end
