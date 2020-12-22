; ==================================================================================================
; Title:      Demo04.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 4.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Window
MakeObjects Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

; The following code demonstartes how an object can be type customized from an object definition
; In this case Demo04_Templet.inc is used.
include Demo04_Templet.inc

; Now we create 5 objects from the template to hold variables of different sizes.
; They will be initialized and the content displayed by the DemoApp04. 

if TARGET_BITNESS eq 64
  TContainer QContainer, -1, QWORD
endif
TContainer DContainer, -2, DWORD
TContainer WContainer, -3, WORD
TContainer BContainer, -4, BYTE
TContainer XContainer, -5, XWORD


include Demo04_Globals.inc                              ;Application globals
include Demo04_Main.inc                                 ;DemoApp04 object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(DemoApp04)::DemoApp04.Init             ;Initialize application
  OCall $ObjTmpl(DemoApp04)::DemoApp04.Run              ;Execute application
  OCall $ObjTmpl(DemoApp04)::DemoApp04.Done             ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
