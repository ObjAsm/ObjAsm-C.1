; ==================================================================================================
; Title:      DbgOutBitmap.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutBitmap
; Purpose:    Sends a bitmap to the Debug Center Window.
; Arguments:  Arg1: Bitamp HANDLE.
;             Arg2: -> Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutBitmap proc uses rbx rdi rsi r12 hBmp:HANDLE, pDest:POINTER
  local CDS:COPYDATASTRUCT, hDC:HDC, BMI:BITMAPINFO, dResult:DWORD

  .if dDbgDev == DBG_DEV_WND
    .if $invoke(DbgWndOpen)
      mov CDS.dwData, DGB_MSG_ID                        ;Set DebugCenter identifier
      mov hDC, $invoke(GetDC, 0)
      ;Get the Bitmap attributes
      mov BMI.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)
      m2z BMI.bmiHeader.biBitCount
      invoke GetDIBits, hDC, hBmp, 0, 1, NULL, addr BMI, DIB_RGB_COLORS ;Fill only BITMAPINFO
      ;Get memory to transfer the header info & bitmap bits and set DIB properties we want
      mov eax, BMI.bmiHeader.biWidth
      mul BMI.bmiHeader.biHeight
      shl eax, $Log2(sizeof(RGBQUAD))
      mov BMI.bmiHeader.biSizeImage, eax
      add eax, sizeof(DBG_BMP_INFO)
      mov rdi, rax                                      ;edi = BMP data size + sizeof(DBG_BMP_INFO)
      mov CDS.cbData, eax
      invoke StrSizeW, pDest
      mov esi, eax                                      ;esi = sizeof(pDest)
      add eax, sizeof(DBG_HEADER_INFO)
      mov r12d, eax                                     ;r12d = sizeof(DBG_HEADER_INFO) + sizeof(pDest)
      add CDS.cbData, eax
      invoke GlobalAlloc, GPTR, CDS.cbData
      .if rax != NULL
        mov CDS.lpData, rax
        mov [rax].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR ;Set block type = header
        mov [rax].DBG_HEADER_INFO.dBlockLen, r12d
        lea rcx, [rax + sizeof(DBG_HEADER_INFO)]
        invoke MemClone, rcx, pDest, esi                ;Copy string "Destrination"
        mov rcx, CDS.lpData
        mov r8d, [rcx].DBG_HEADER_INFO.dBlockLen
        add rcx, r8
        mov [rcx].DBG_BMP_INFO.bBlockID, DBG_MSG_BMP    ;Set block type = bitmap
        mov [rcx].DBG_BMP_INFO.dBlockLen, edi
        mov BMI.bmiHeader.biBitCount, 32
        mov BMI.bmiHeader.biCompression, BI_RGB
        lea rbx, [rcx + sizeof(DBG_BMP_INFO)]
        invoke MemClone, addr [rcx].DBG_BMP_INFO.BmpHeader, addr BMI, sizeof(DBG_BMP_INFO.BmpHeader)
        invoke GetDIBits, hDC, hBmp, 0, BMI.bmiHeader.biHeight, rbx, addr BMI, DIB_RGB_COLORS
        ;Send the DIB info
        invoke SendMessageTimeoutW, hDbgDev, WM_COPYDATA, -1, addr CDS, \
                                    SMTO_BLOCK, SMTO_TIMEOUT, addr dResult
        invoke GlobalFree, CDS.lpData
      .else
        invoke MessageBoxW, 0, offset szDbgComErr, offset szDbgErr, MB_OK or MB_ICONERROR
      .endif
      invoke ReleaseDC, 0, hDC
    .endif
  .endif
  ret
DbgOutBitmap endp

end
