; ==================================================================================================
; Title:      CenterForm.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CenterForm
; Purpose:    Calculate the starting coordinate of a window based on the screen and the window size.
; Arguments:  Arg1: Window size in pixel.
;             Arg2: Screen size in pixel.
; Return:     eax = Starting point in pixel.

align ALIGN_CODE
CenterForm proc dWindowSize:DWORD, dScreenSize:DWORD
  mov eax, dScreenSize
  sub eax, dWindowSize
  shr eax, 1
  ret
CenterForm endp

end
