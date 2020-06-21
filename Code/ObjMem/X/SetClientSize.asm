; ==================================================================================================
; Title:      SetClientSize.asm
; Author:     MichelW / G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release
; ==================================================================================================


% include &ObjMemPath&ObjMem.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SetClientSize
; Purpose:    Set the client window size.
; Arguments:  Arg1: Target window handle.
;             Arg2: Client area width in pixel.
;             Arg3: Client area height in pixel.
; Return:     Nothing.

align ALIGN_CODE
SetClientSize proc hWnd:HWND, dPixelWidth:DWORD, dPixelHeight:DWORD
  local CRect:RECT, WRect:RECT, WndSize:POINT

  invoke GetClientRect, hWnd, addr CRect
  invoke GetWindowRect, hWnd, addr WRect

  mov ecx, WRect.right
  sub ecx, WRect.left
  add ecx, dPixelWidth
  sub ecx, CRect.right
  mov WndSize.x, ecx

  mov edx, WRect.bottom
  sub edx, WRect.top
  add edx, dPixelHeight
  sub edx, CRect.bottom
  mov WndSize.y, edx

  invoke MoveWindow, hWnd, WRect.left, WRect.top, WndSize.x, WndSize.y, TRUE

  ret
SetClientSize endp
