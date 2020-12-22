; ==================================================================================================
; Title:      NetComServer.asm
; Author:     G. Friedrich
; Purpose:    Demonstration program.
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


WIN32_LEAN_AND_MEAN         equ 1                       ;Necessary to exlude WinSock.inc  
INCL_WINSOCK_API_PROTOTYPES equ 1
PROTOCOL_WND_NAME           textequ <Server Protocol>
INTERNET_PROTOCOL_VERSION   equ 4

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, ANSI_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&fMath.inc
% include &MacPath&SDLL.inc

% include &IncPath&Windows\WinSock2.inc
% include &IncPath&Windows\ws2ipdef.inc
% include &IncPath&Windows\ws2tcpip.inc

% include &IncPath&Windows\CommCtrl.inc 

% includelib &LibPath&Windows\Ws2_32.lib
% includelib &LibPath&Windows\Mswsock.lib
% includelib &LibPath&Windows\Kernel32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib

if INTERNET_PROTOCOL_VERSION eq 4
  AF_INETX  equ   AF_INET
elseif INTERNET_PROTOCOL_VERSION eq 6
  AF_INETX  equ   AF_INET6
else
  %.err <NetComEngine.Init - wrong IP version: $ToStr(%INTERNET_PROTOCOL_VERSION)>
endif


;Load or build the following objects
MakeObjects Primer, Stream, DiskStream, Collection, DataPool, StopWatch
MakeObjects DataCollection, XWCollection, SortedCollection, SortedDataCollection
MakeObjects WinPrimer, Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects NetCom


.code
include NetComServer_Globals.inc                        ;Includes application globals
include NetComServer_Main.inc                           ;Includes NetComServer object

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  DbgClearTxt "NETCOMSERVER"                            ;Clear this DbgCenter text window
  DbgClearTxt "&PROTOCOL_WND_NAME"                      ;Clear this DbgCenter text window
  OCall $ObjTmpl(NetComServer)::NetComServer.Init       ;Initializes the object data
  OCall $ObjTmpl(NetComServer)::NetComServer.Run        ;Executes the application
  OCall $ObjTmpl(NetComServer)::NetComServer.Done       ;Finalizes it

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exits program returning 0 to the OS
start endp

end
