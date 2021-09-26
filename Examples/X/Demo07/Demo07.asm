; ==================================================================================================
; Title:      Demo07.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 7.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN32, WIDE_STRING;, DEBUG(WND)

% include &MacPath&fMath.inc

% include &MacPath&Strings.inc                          ;Include wide string support for DlgTmpl
% include &MacPath&DlgTmpl.inc                          ;Include Dlg Template macros for XMenu
% include &MacPath&ConstDiv.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\UxTheme.inc
% include &IncPath&Windows\vsstyle.inc

% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\OleAut32.lib

;Load or build the following objects
MakeObjects Primer, Stream
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects WinPrimer, Window, GifDecoder, GifPlayer
MakeObjects Dialog, DialogModal, DialogModeless, DialogAbout, DialogPassword
MakeObjects SimpleImageList, MaskedImageList
MakeObjects Button, IconButton, ColorButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects WinControl, Toolbar, Rebar, Statusbar, TabCtrl, TextView
MakeObjects WinApp, MdiApp
MakeObjects Array, ChartSeries, ChartFlat, ChartXY

include Demo07_Globals.inc
include Demo07_Main.inc

start proc
  SysInit

  finit
  OCall $ObjTmpl(Application)::Application.Init
  OCall $ObjTmpl(Application)::Application.Run
  OCall $ObjTmpl(Application)::Application.Done

  SysDone
  invoke ExitProcess, 0
start endp

end
