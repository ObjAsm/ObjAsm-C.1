; ==================================================================================================
; Title:      DbgOutBitmap.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutBitmap
; Purpose:    Send a bitmap to the Debug Center Window.
; Arguments:  Arg1: Bitamp HANDLE.
;             Arg2: -> Destination window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutBitmap proc hBmp:HANDLE, pDest:POINTER
  local CDS:COPYDATASTRUCT, hDC:HDC, BMI:BITMAPINFO, pBuffer:POINTER, dResult:DWORD

  .if dDbgDev == DBG_DEV_WIN_DC
    .if $invoke(DbgWndOpen)
      mov CDS.dwData, DGB_MSG_ID                        ;Set DebugCenter identifier
      mov hDC, $invoke(GetDC, 0)
      ;Get the Bitmap attributes
      mov BMI.bmiHeader.biSize, sizeof BITMAPINFOHEADER
      m2z BMI.bmiHeader.biBitCount
      invoke GetDIBits, hDC, hBmp, 0, 1, NULL, addr BMI, DIB_RGB_COLORS
      ;Get memory to transfer the header info & bitmap bits and set DIB properties we want
      mov eax, BMI.bmiHeader.biWidth
      mul BMI.bmiHeader.biHeight
      shl eax, 2
      mov BMI.bmiHeader.biSizeImage, eax
      add eax, sizeof DBG_BMP_INFO
      push eax
      mov CDS.cbData, eax
      invoke StrSizeW, pDest
      push eax
      add eax, sizeof DBG_HEADER_INFO
      push eax
      add CDS.cbData, eax
      invoke GlobalAlloc, GPTR, CDS.cbData
      .if eax != NULL
        mov CDS.lpData, eax
        mov [eax].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR ;Set block type = header
        pop [eax].DBG_HEADER_INFO.dBlockLen
        push pDest
        lea ecx, [eax + sizeof DBG_HEADER_INFO]
        push ecx
        call MemClone
        mov ecx, CDS.lpData
        add ecx, [ecx].DBG_HEADER_INFO.dBlockLen
        mov [ecx].DBG_BMP_INFO.bBlockID, DBG_MSG_BMP    ;Set block type = bitmap
        pop [ecx].DBG_BMP_INFO.dBlockLen
        mov BMI.bmiHeader.biBitCount, 32
        mov BMI.bmiHeader.biCompression, BI_RGB
        PushArgsFor GetDIBits, hDC, hBmp, 0, BMI.bmiHeader.biHeight, \
                               addr [ecx + sizeof(DBG_BMP_INFO)], \
                               addr BMI, DIB_RGB_COLORS
        invoke MemClone, addr [ecx].DBG_BMP_INFO.BmpHeader, addr BMI, sizeof BMI
        call GetDIBits
        ;Send the DIB info
        invoke SendMessageTimeoutW, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                    SMTO_BLOCK, SMTO_TIMEOUT, addr dResult

        invoke GlobalFree, CDS.lpData
      .else
        add esp, 12                                     ;Restore stack
        invoke MessageBoxW, 0, offset szDbgComErr, offset szDbgErr, MB_OK or MB_ICONERROR
      .endif
      invoke ReleaseDC, 0, hDC
    .endif
  .endif
  ret
DbgOutBitmap endp

end
