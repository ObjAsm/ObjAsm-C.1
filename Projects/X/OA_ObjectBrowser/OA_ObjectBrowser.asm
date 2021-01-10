; ==================================================================================================
; Title:      OA_ObjectBrowser.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Object Browser.
; Notes:      Version C.1.0, December 2020
;               - First release.
; Link:       http://www.codeproject.com/KB/COM/cwebpage.aspx
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, ANSI_STRING, DEBUG(WND)

% includelib &LibPath&Windows\Kernel32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Shlwapi.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\OleAut32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\Comdlg32.lib
% includelib &LibPath&Windows\MSVCRT.lib
% includelib &LibPath&Windows\UUID.lib

% includelib &LibPath&PCRE\PCRE844S&TARGET_STR_AFFIX&.lib


% include &COMPath&COM.inc                              ;COM basic support
% include &COMPath&COM_Errors.inc
% include &COMPath&COM_Dispatch.inc                     ;Dispatch definitions and macros
% include &COMPath&COM_Dispatch.asm                     ;Dispatch procedures
% include &COMPath&OAIDL.inc
% include &COMPath&COM_Interfaces.inc                   ;COM common interfaces

% include &IncPath&Windows\sGUID.inc
% include &IncPath&Windows\oaidl.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\shlobj_core.inc
% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\uxtheme.inc
% include &IncPath&Windows\OleCtl.inc

% include &IncPath&PCRE\PCRE844S.inc

% include &MacPath&DlgTmpl.inc                          ;Include Dlg Template macros for XMenu
% include &MacPath&SDLL.inc
% include &MacPath&fMath.inc
% include &MacPath&Strings.inc                          ;Wide string support
% include &MacPath&BStrings.inc                         ;BSTR support

.const                                                  ;Global GUIDs
DefGUID IID_NULL, %sGUID_NULL
DefGUID IID_IUnknown, %sIID_IUnknown
DefGUID IID_IConnectionPointContainer, %sIID_IConnectionPointContainer
DefGUID IID_IConnectionPoint, %sIID_IConnectionPoint
DefGUID IID_IEnumConnections, %sIID_IEnumConnections
DefGUID IID_IEnumConnectionPoints, %sIID_IEnumConnectionPoints
DefGUID IID_IDispatch, %sIID_IDispatch
DefGUID IID_IOleObject, %sIID_IOleObject
DefGUID IID_IPersistStorage, %sIID_IPersistStorage
DefGUID IID_IAdviseSink, %sIID_IAdviseSink
DefGUID IID_IOleInPlaceObject, %sIID_IOleInPlaceObject
DefGUID IID_IOleWindow, %sIID_IOleWindow
DefGUID IID_IOleClientSite, %sIID_IOleClientSite
DefGUID IID_IOleInPlaceSite, %sIID_IOleInPlaceSite
DefGUID IID_IOleInPlaceSiteEx, %sIID_IOleInPlaceSiteEx
DefGUID IID_IOleInPlaceActiveObject, %sIID_IOleInPlaceActiveObject
DefGUID IID_IOleControlSite, %sIID_IOleControlSite
DefGUID IID_IOleControl, %sIID_IOleControl
DefGUID IID_IDataObject, %sIID_IDataObject
DefGUID IID_IViewObject2, %sIID_IViewObject2
DefGUID IID_IProvideClassInfo, %sIID_IProvideClassInfo
DefGUID IID_ISpecifyPropertyPages, %sIID_ISpecifyPropertyPages
DefGUID IID_IOleInPlaceFrame, %sIID_IOleInPlaceFrame
DefGUID IID_IOleContainer, %sIID_IOleContainer
DefGUID IID_ISimpleFrameSite, %sIID_ISimpleFrameSite
DefGUID IID_IPropertyNotifySink, %sIID_IPropertyNotifySink
DefGUID IID_IErrorInfo, %sIID_IErrorInfo
DefGUID IID_IClassFactory2, %sIID_IClassFactory2
DefGUID IID_IFontDisp, %sIID_IFontDisp
DefGUID IID_IServiceProvider, %sIID_IServiceProvider
DefGUID IID_IOleInPlaceSiteWindowless, %sIID_IOleInPlaceSiteWindowless
DefGUID IID_IOleCommandTarget, %sIID_IOleCommandTarget
DefGUID IID_IOleDocumentSite, %sIID_IOleDocumentSite

sCLSID_WebBrowser textequ <8856F961-340A-11D0-A96B-00C04FD705A2>
DefGUID CLSID_WebBrowser, %sCLSID_WebBrowser
DefGUID IID_IWebBrowser2, %sIID_IWebBrowser2
DefGUID IID_DWebBrowserEvents2, %sIID_DWebBrowserEvents2

DefGUID IID_IDocHostUIHandler, %sIID_IDocHostUIHandler

.code
;Load or build the following objects
MakeObjects Primer, Stream, DiskStream, MemoryStream
MakeObjects Collection, DataCollection, SortedCollection, XWCollection
MakeObjects SimpleImageList, MaskedImageList
MakeObjects WinPrimer, Window
MakeObjects Dialog, DialogModal, DialogAbout, DialogModeless
MakeObjects WinControl, Button, IconButton, Hyperlink
MakeObjects MsgInterceptor, DialogModalIndirect, XMenu
MakeObjects Toolbar, Rebar, Statusbar
MakeObjects DataPool, IniFile, RegEx, IDL
MakeObjects FlipBox, Splitter, XTreeView
MakeObjects WinApp, MdiApp
MakeObjects COM_Primers, IDispatch
MakeObjects OcxContainer, IDocHostUIHandler

include OA_TextSource.inc
include OA_ObjDB_Collections.inc
include OA_ObjDB.inc
include OA_InfoTree.inc
include OA_TreeWindow.inc
include OA_ObjectBrowser_Globals.inc
include OA_ObjectBrowser_Main.inc


start proc
  SysInit

  DbgClearAll

  invoke OleInitialize, 0                               ;Internally invokes CoInitialize
  invoke InitCommonControls

  OCall $ObjTmpl(ObjectBrowser)::ObjectBrowser.Init
  OCall $ObjTmpl(ObjectBrowser)::ObjectBrowser.Run
  OCall $ObjTmpl(ObjectBrowser)::ObjectBrowser.Done
  invoke OleUninitialize

  SysDone
  invoke ExitProcess, 0
start endp

end
