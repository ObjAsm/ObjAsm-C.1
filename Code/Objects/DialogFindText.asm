; ==================================================================================================
; Title:      DialogFindText.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for DialogFindText object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc
% include &IncPath&Windows\RichEdit.inc
% include &MacPath&DlgTmpl.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include WinPrimer.inc
include Window.inc
include WinApp.inc
include Dialog.inc
include DialogModeless.inc
include DialogModelessIndirect.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects DialogFindText

end
