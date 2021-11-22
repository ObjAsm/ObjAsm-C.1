; ==================================================================================================
; Title:      SplashDemo.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Splash Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

GDIPVER equ 0100h
% include &IncPath&Windows\GdiplusPixelFormats.inc
% include &IncPath&Windows\GdiplusInit.inc
% include &IncPath&Windows\GdiplusEnums.inc
% include &IncPath&Windows\GdiplusGpStubs.inc
% include &IncPath&Windows\GdiPlusFlat.inc
% includelib &LibPath&Windows\GdiPlus.lib
% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Ole32.lib

MakeObjects Primer, Stream                              ;Load or build the following objects
MakeObjects WinPrimer, Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects Splash


.code
include SplashDemo_Globals.inc
include SplashDemo_Main.inc


LoadPngFromResource proc pResName:PSTRINGW
  local GPSI:GdiplusStartupInput, xToken:XWORD
  local pBitmap:ptr GpBitmap, hBmp:HBITMAP
  local hResource:HRSRC, dResSize:DWORD, pResource:POINTER
  local hGlobal:HANDLE, pIStream:ptr IStream, pMem:POINTER

  mov hBmp, 0
  mov GPSI.GdiplusVersion, 1
  mov GPSI.DebugEventCallback, NULL
  mov GPSI.SuppressBackgroundThread, FALSE
  mov GPSI.SuppressBackgroundThread, FALSE
  invoke GdiplusStartup, addr xToken, addr GPSI, NULL
  .if eax == 0
    invoke FindResource, hInstance, pResName, $OfsCStrW("PNG")
    .if xax != 0
      mov hResource, xax
      mov dResSize, $32($invoke(SizeofResource, 0, hResource))
      mov pResource, $invoke(LoadResource, hInstance, hResource)
      invoke GlobalAlloc, GMEM_MOVEABLE, dResSize
      .if xax != 0
        mov hGlobal, xax
        mov pMem, $invoke(GlobalLock, hGlobal)
        invoke MemClone, pMem, pResource, dResSize
        invoke GlobalUnlock, hGlobal
        invoke CreateStreamOnHGlobal, hGlobal, 0, addr pIStream
        invoke GdipCreateBitmapFromStream, pIStream, addr pBitmap
        .if eax == 0
          invoke GdipCreateHBITMAPFromBitmap, pBitmap, addr hBmp, 0
          invoke GdipDisposeImage, pBitmap
        .endif
        invoke GlobalFree, hGlobal
      .endif
      invoke FreeResource, hResource
    .endif
    invoke GdiplusShutdown, xToken
  .endif
  mov xax, hBmp
  ret
LoadPngFromResource endp


start proc
  local hBmp:HBITMAP

  SysInit

  invoke LoadPngFromResource, $OfsCStrW("PNG_SPLASH")
  mov hBmp, xax
  OCall $ObjTmpl(Splash)::Splash.Init, NULL, xax, $RGB(255, 0, 255)
  OCall $ObjTmpl(Splash)::Splash.FadeIn
  invoke Sleep, 2000
  OCall $ObjTmpl(SplashDemo)::SplashDemo.Init
  invoke Sleep, 1000
  OCall $ObjTmpl(Splash)::Splash.FadeOut
  OCall $ObjTmpl(Splash)::Splash.Done
  invoke DeleteObject, hBmp
  OCall $ObjTmpl(SplashDemo)::SplashDemo.Run
  OCall $ObjTmpl(SplashDemo)::SplashDemo.Done

  SysDone
  invoke ExitProcess, 0
start endp

end
