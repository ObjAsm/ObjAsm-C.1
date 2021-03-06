; ==================================================================================================
; Title:      IDocHostUIHandler.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm compilation file for IDocHostUIHandler object.
; Notes:      Version C.1.2, December 2020
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &COMPath&COM.inc
% include &COMPath&OAIDL.inc
% include &COMPath&COM_Dispatch.inc
% include &COMPath&COM_Interfaces.inc
% include &IncPath&Ole32.inc
% include &IncPath&OleAut32.inc
% include &MacPath&Debug.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Streamable.inc
include Stream.inc
include Collection.inc
include DataCollection.inc
include COMPrimers.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects IDocHostUIHandler

end
