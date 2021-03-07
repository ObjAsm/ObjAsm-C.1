; ==================================================================================================
; Title:      OA_ObjectBrowser.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Object Browser.
; Notes:      Version C.1.1, January 2021
;               - COM stuff replaced by TextView.
;             Version C.1.0, December 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, ANSI_STRING, DEBUG(WND)

% includelib &LibPath&Windows\Kernel32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\MSVCRT.lib
% includelib &LibPath&Windows\UUID.lib

% includelib &LibPath&PCRE\PCRE844S&TARGET_STR_AFFIX&.lib

% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\uxtheme.inc

% include &IncPath&PCRE\PCRE844S.inc

% include &MacPath&DlgTmpl.inc                          ;Include Dlg Template macros for XMenu
% include &MacPath&SDLL.inc
% include &MacPath&fMath.inc

.code
;Load or build the following objects
MakeObjects Primer, Stream, DiskStream, MemoryStream
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects SimpleImageList, MaskedImageList
MakeObjects StopWatch
MakeObjects WinPrimer, Window
MakeObjects Dialog, DialogModal, DialogAbout, DialogModeless
MakeObjects WinControl, Button, IconButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects Toolbar, Rebar, Statusbar
MakeObjects DataPool, IniFile, RegEx
MakeObjects FlipBox, Splitter, XTreeView
MakeObjects WinApp, MdiApp, TextView

include OAB_TextSource.inc
include OAB_ObjDB_Collections.inc
include OAB_ObjDB.inc
include OAB_InfoTree.inc
include OAB_TreeWindow.inc
include OA_ObjectBrowser_Globals.inc
include OA_ObjectBrowser_Main.inc
include OAB_PropWnd.inc
include OAB_IntPropWnd.inc
include OAB_ObjPropWnd.inc
include OAB_SetupDlg.inc
include OAB_FindInfoDlg.inc


start proc
  SysInit

  DbgClearAll

  OCall $ObjTmpl(ObjectBrowser)::ObjectBrowser.Init
  OCall $ObjTmpl(ObjectBrowser)::ObjectBrowser.Run
  OCall $ObjTmpl(ObjectBrowser)::ObjectBrowser.Done

  SysDone
  invoke ExitProcess, 0
start endp

end
