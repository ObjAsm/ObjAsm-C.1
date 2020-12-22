; ==================================================================================================
; Title:      NetComClient.asm
; Author:     G. Friedrich
; Purpose:    Demonstration program.
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


WIN32_LEAN_AND_MEAN         equ 1                       ;Necessary to exlude WinSock.inc  
INCL_WINSOCK_API_PROTOTYPES equ 1
INTERNET_PROTOCOL_VERSION   equ 4
APP_NAME                    textequ <NetComClient>
PROTOCOL_WND_NAME           textequ <Client Protocol>

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, ANSI_STRING;, DEBUG(WND)           ;Load OOP files and OS related objects

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
MakeObjects Primer, Stream, Collection, StopWatch
MakeObjects DataCollection, XWCollection, SortedCollection, SortedDataCollection
MakeObjects WinPrimer, Window, Dialog, DialogModal, DialogAbout
MakeObjects DataPool
MakeObjects WinApp, SdiApp
MakeObjects NetCom

.code
include NetComClient_Globals.inc                        ;Includes application globals
include NetComClient_Main.inc

start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  DbgClearTxt "NETCOMCLIENT"                            ;Clear this DbgCenter text window
  DbgClearTxt "&PROTOCOL_WND_NAME"                      ;Clear this DbgCenter text window
  OCall $ObjTmpl(NetComClient)::NetComClient.Init       ;Initializes the object data
  OCall $ObjTmpl(NetComClient)::NetComClient.Run        ;Executes the application
  OCall $ObjTmpl(NetComClient)::NetComClient.Done       ;Finalizes it

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exits program returning 0 to the OS
start endp                                              ;Code end and defines prg entry point

end
