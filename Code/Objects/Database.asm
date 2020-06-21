; ==================================================================================================
; Title:      Database.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm compilation file for Database cluster objects.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&ConstDiv.inc
% include &MacPath&QuadWord.inc
% include &IncPath&Windows\Shlwapi.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include DiskStream.inc
include Collection.inc
include SortedCollection.inc
include DataCollection.inc
include WinPrimer.inc
include Window.inc
include Dialog.inc
include DialogModal.inc
include DialogProgress.inc


;Add here the file that defines the object(s) to be included in the library
MakeObjects Database

end
