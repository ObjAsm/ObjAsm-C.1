; ==================================================================================================
; Title:      CudaApp.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm CUDA demo application.
;             Original idea and implementation by LiaoMi @ MASM32 Forum.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN32, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&fMath.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

CUDA_FORCE_API_VERSION EQU 3010
CUdeviceptr typedef POINTER

% include &IncPath&CUDA\cuda.inc
% includelib &LibPath&CUDA\cuda.lib


;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Window
MakeObjects Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, DlgApp


include CudaApp_Globals.inc                             ;Application globals
include CudaApp_Main.inc                                ;CudaApp object

.code
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

;  DbgClearAll
  OCall $ObjTmpl(CudaApp)::CudaApp.Init                 ;Initialize application
  OCall $ObjTmpl(CudaApp)::CudaApp.Run                  ;Execute application
  OCall $ObjTmpl(CudaApp)::CudaApp.Done                 ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
