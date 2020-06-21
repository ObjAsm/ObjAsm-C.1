; ==================================================================================================
; Title:      GridView.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for GridView object.
; Notes:      Version C.1.1, May 2020
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc
% include &IncPath&Windows\CommCtrl.inc 
% include &MacPath&ConstDiv.inc 

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include Collection.inc
include DataCollection.inc
include SortedCollection.inc
include SortedDataCollection.inc
include XWCollection.inc
include WinPrimer.inc
include Window.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects GridView

end
