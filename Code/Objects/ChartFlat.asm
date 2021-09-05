; ==================================================================================================
; Title:      ChartFlat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for ChartFlat object.
; Notes:      Version C.1.0, August 2021
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&fMath.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects Dialog
LoadObjects DialogModal
LoadObjects Array
LoadObjects Collection

;Add here the file that defines the object(s) to be included in the library
MakeObjects ChartFlat

end
