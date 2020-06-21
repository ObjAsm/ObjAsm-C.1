; ==================================================================================================
; Title:      DialogAboutIndirect.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for DialogAboutIndirect object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc
% include &MacPath&DlgTmpl.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include WinPrimer.inc
include Window.inc
include Dialog.inc
include DialogModal.inc
include DialogModalIndirect.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects DialogAboutIndirect

end
