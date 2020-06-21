; ==================================================================================================
; Title:      XTreeView.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for XTreeView object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc
% include &MacPath&SDLL.inc
% include &IncPath&Windows\CommCtrl.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include WinPrimer.inc
include Window.inc
include Collection.inc
include XWCollection.inc
include DataPool.inc
include SimpleImageList.inc
include MaskedImageList.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects XTreeView

end
