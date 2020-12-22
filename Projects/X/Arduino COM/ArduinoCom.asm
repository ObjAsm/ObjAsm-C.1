; ==================================================================================================
; Title:      ArduinoCom.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Arduino Communication demonstration program.
; Notes:      Version C.1.1, October 2020
;               - First release.
;               - https://www.xanthium.in/Serial-Port-Programming-using-Win32-API
;               - https://docs.microsoft.com/en-us/previous-versions/ff802693(v=msdn.10)?redirectedfrom=MSDN
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN32, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &IncPath&Windows\winioctl.inc

;Required switches to use SetupApi
USE_SP_ALTPLATFORM_INFO_V1    equ FALSE
USE_SP_ALTPLATFORM_INFO_V3    equ TRUE
USE_SP_DRVINFO_DATA_V1        equ TRUE
USE_SP_BACKUP_QUEUE_PARAMS_V1 equ TRUE
% include &IncPath&Windows\setupapi.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\setupapi.lib
% includelib &LibPath&Windows\OneCore.lib

% include &IncPath&ObjAsm\ComPortNames.inc

.const
GUID_DEVINTERFACE_COMPORT GUID sGUID_DEVINTERFACE_COMPORT

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects .\DialogComPortSelection

include ArduinoCom_Globals.inc                          ;Application globals
include ArduinoCom_Main.inc                             ;ArduinoApp object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model
  DbgClearAll

  OCall $ObjTmpl(ArduinoApp)::ArduinoApp.Init           ;Initialize application
  OCall $ObjTmpl(ArduinoApp)::ArduinoApp.Run            ;Execute application
  OCall $ObjTmpl(ArduinoApp)::ArduinoApp.Done           ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
