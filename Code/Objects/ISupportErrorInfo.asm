; ==================================================================================================
; Title:   ISupportErrorInfo.asm
; Author:  Kai Liebenau
; Version: 1.0.1
; Purpose: ObjAsm32 compilation file for ISupportErrorInfo object.
; Version: Version 1.0.0, September 2006
;            - First release.
;          Version 1.0.1, August 2008
;            - SysSetup introduced.
; ==================================================================================================

% include Objects.cop

;% include &COMPath&COM.inc
;% include &COMPath&COM_Dispatch.inc
;% include &MacPath&Debug.inc
% include &MacPath&WinHelpers.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include Collection.inc
include DataCollection.inc
include XWCollection.inc
include COM_Primers.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects ISupportErrorInfo

end
