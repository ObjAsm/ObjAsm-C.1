; ==================================================================================================
; Title:      ClassFactory.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for ClassFactory object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &COMPath&COM.inc
% include &COMPath&COM_Dispatch.inc
% include &MacPath&Debug.inc
DEBUGGING = FALSE

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include Collection.inc
include DataCollection.inc
include COM_Primers.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects ClassFactory

end
