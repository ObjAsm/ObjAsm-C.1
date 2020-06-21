; ==================================================================================================
; Title:      MSChart.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for MSChart object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc
% include &MacPath&fMath.inc
% include &MacPath&Strings.inc
% include &MacPath&BStrings.inc
% include &IncPath&Windows\sGUID.inc
% include &IncPath&Windows\ocidl.inc
% include &IncPath&Windows\OleCtl.inc

% include &COMPath&COM.inc
% include &COMPath&COM_Dispatch.inc
% include &COMPath&COM_Dispatch.inc
% include &COMPath&COM_Dispatch.asm

% include &OA_PATH&\Projects\32\MSChart\MSChart20Lib.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include Collection.inc
include DataCollection.inc
include WinPrimer.inc
include Window.inc
include Dialog.inc
include DialogModal.inc
include DialogAbout.inc
include WinApp.inc
include SdiApp.inc
include COM_Primers.inc
include IDispatch.inc
include ConnectionPoint.inc
include IConnectionPointContainer.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects MSChart

end
