; ==================================================================================================
; Title:      Demo07.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 7.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)

% include &MacPath&fMath.inc
% include &MacPath&DlgTmpl.inc

% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\Shlwapi.inc

% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\Shlwapi.lib
% includelib &LibPath&Windows\strsafe.lib


;Load or build the following objects
MakeObjects Primer, Stream, Collection, DataCollection
MakeObjects WinPrimer, Window, GifDecoder, GifPlayer
MakeObjects Dialog, DialogModal, DialogAbout, DialogPassword
MakeObjects SimpleImageList, MaskedImageList
MakeObjects Button, ColorButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects WinControl, Toolbar, Rebar, Statusbar
MakeObjects Array, PlotXY
MakeObjects WinApp, MdiApp

include Demo07_Globals.inc
include Demo07_Main.inc

start proc
  SysInit

  New DialogPassword
  mov xbx, xax
  OCall xbx::DialogPassword.Init, NULL, NULL, \
                                  $OfsCStr("Password validation (hello)"), \
                                  $OfsCStr("hello"), 3
  OCall xbx::DialogPassword.Show
  .if eax != FALSE
    OCall $ObjTmpl(DemoApp07)::DemoApp07.Init
    OCall $ObjTmpl(DemoApp07)::DemoApp07.Run
    OCall $ObjTmpl(DemoApp07)::DemoApp07.Done
  .endif
  Destroy xbx

  SysDone
  invoke ExitProcess, 0
start endp

end
