; ==================================================================================================
; Title:      PixelmapApp.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Pixelmap application using ObjAsm.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &COMPath&COM.inc
% include &COMPath&COM_Dispatch.inc
% include &MacPath&fMath.inc
% include &IncPath&Windows\sGUID.inc
% include &IncPath&Windows\olectl.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\OleAut32.lib

;Load or build the following objects
MakeObjects Primer, Stream, DiskStream
MakeObjects WinPrimer, Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects Pixelmap

include PixelmapApp_Globals.inc                         ;Include application globals
include PixelmapApp_Main.inc                            ;Include PixelmapApp object

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(PixelmapApp)::PixelmapApp.Init         ;Initialize the object data
  OCall $ObjTmpl(PixelmapApp)::PixelmapApp.Run          ;Execute the application
  OCall $ObjTmpl(PixelmapApp)::PixelmapApp.Done         ;Finalize it

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
