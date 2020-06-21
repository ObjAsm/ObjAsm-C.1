; ==================================================================================================
; Title:      XCustomTreeView.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for XCustomTreeView object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc
% include &MacPath&SDLL.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include WinPrimer.inc
include Window.inc
include WinControl.inc
include Collection.inc
include XWCollection.inc
include DataPool.inc
include XTreeView.inc
include WinApp.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects XCustomTreeView

end
