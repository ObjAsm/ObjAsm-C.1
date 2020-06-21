; ==================================================================================================
; Title:      D3Engine.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for D3Engine object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include DiskStream.inc
include Collection.inc
include SortedCollection.inc
include SortedDataCollection.inc
include DataCollection.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects D3Engine

end
