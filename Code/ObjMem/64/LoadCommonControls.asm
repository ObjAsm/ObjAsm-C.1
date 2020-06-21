; ==================================================================================================
; Title:      LoadCommonControls.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

% include &IncPath&Windows\CommCtrl.inc

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  LoadCommonControls
; Purpose:    Invokes InitCommonControls with a correctly filled input structure.
; Arguments:  Arg1: ICC_COOL_CLASSES, ICC_BAR_CLASSES, ICC_LISTVIEW_CLASSES, ICC_TAB_CLASSES,
;                   ICC_USEREX_CLASSES, etc.
; Return:     Nothing.

align ALIGN_CODE
LoadCommonControls proc dFlags:DWORD
  local icce:INITCOMMONCONTROLSEX

  invoke InitCommonControls
  mov icce.dwSize, sizeof(INITCOMMONCONTROLSEX)
  m2m icce.dwICC, dFlags, edx
  invoke InitCommonControlsEx, addr icce
  ret
LoadCommonControls endp

end
