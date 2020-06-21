; ==================================================================================================
; Title:      Splitter.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for Splitter object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc

;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include WinPrimer.inc
include WinControl.inc
include Window.inc
include FlipBox.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects Splitter

end
