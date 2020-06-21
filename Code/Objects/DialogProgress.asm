; ==================================================================================================
; Title:      DialogProgress.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm compilation file for DialogProgress object.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


% include Objects.cop

% include &MacPath&WinHelpers.inc
% include &IncPath&Windows\CommCtrl.inc 
% include &IncPath&Windows\Richedit.inc 


;Add here all files that build the inheritance path and referenced objects
include Primer.inc
include Stream.inc
include WinPrimer.inc
include Window.inc
include Dialog.inc
include DialogModal.inc

;Add here the file that defines the object(s) to be included in the library
MakeObjects DialogProgress

end
