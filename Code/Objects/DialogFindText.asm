; ==================================================================================================
; Title:      DialogFindText.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm compilation file for DialogFindText object.
; Notes:      Version C.1.0, November 2017
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &IncPath&Windows\RichEdit.inc
% include &MacPath&DlgTmpl.inc

;Add here all files that build the inheritance path and referenced objects
LoadObjects Primer
LoadObjects Stream
LoadObjects WinPrimer
LoadObjects Window
LoadObjects WinApp
LoadObjects Dialog
LoadObjects DialogModeless
LoadObjects DialogModelessIndirect

;Add here the file that defines the object(s) to be included in the library
MakeObjects DialogFindText

end
