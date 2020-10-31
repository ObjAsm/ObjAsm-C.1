; ==================================================================================================
; Title:      DC_Test.asm
; Authors:    G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm DebugCenter test application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND, INFO, TRACE, STKGUARD, "DC_Test Project")

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

CStr szMyStr, "Here is my string"
CReal4 r4MyFloat1, 12.3456789
CReal8 r8MyFloat2, 89.2398756225

;Note: use MakeObjects to build the following objects to allow to trace them.
.code
;Build the following objects
MakeObjects Primer, Stream
MakeObjects WinPrimer, Window, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

.code
include DC_Test_Globals.inc
include DC_Test_Main.inc

pApp equ offset $ObjTmpl(DC_Test)

start proc
  SysInit
  DbgClearAll
  xor eax, eax
  DbgStr xax ;offset szMyStr
  mov xax, offset szMyStr
  DbgStr xax
  DbgStr szMyStr
  
  DbgText "aaa", "bbb"
;  DbgComError 08007000Eh, "COM error"
;  DbgComError 000000000h, "COM error"
;  DbgComError 0FFFFFFFFh, "COM error"
  DbgLine
  DbgText "Hello friends"
  DbgText
  DbgWarning "Here is something wrong"
  DbgWarning
  DbgHex eax, "My text"

  invoke LoadBitmap, hInstance, $OfsCStr("BMP_TEST1")
  DbgBmp xax, "BMP1"
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_TEST2")
  DbgBmp xax, "BMP2"

;  DbgTraceObject $ObjTmpl(DC_Test)
  OCall $ObjTmpl(DC_Test)::DC_Test.Init                                ;Initialize the object data
  OCall $ObjTmpl(DC_Test)::DC_Test.ErrorSet, STM_OPEN_ERROR
  DbgObject $ObjTmpl(DC_Test)::DC_Test
  OCall $ObjTmpl(DC_Test)::DC_Test.Run                                 ;Execute the application
  OCall $ObjTmpl(DC_Test)::DC_Test.Done                                ;Finalize it

  DbgHex pApp, "Here in Code"
;  DbgTraceShow DC_Test,, "Performance data"
  DbgLine
  DbgText "Hip hop..."
  DbgHex hInstance
  lea xax, szMyStr
  DbgHex eax
  DbgHex ax
  DbgHex al
  DbgHex BYTE ptr [xax], "Here in Code"
  DbgStr szMyStr, "This is my string"
  DbgLine2
  lea xcx, szMyStr
  DbgMem xcx, 29, DBG_MEM_STR, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_UI8, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_UI16, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_UI32, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_I8, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_I16, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_I32, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_R8, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_R4, "Dump Here"
  DbgLine
  DbgMem xcx, 29,, "Default is String"
  DbgLine
  fld r4MyFloat1
  fld r8MyFloat2
  DbgFPU "FPU here"
  DbgLine
  mov ecx, -1
  DbgHex ecx
  DbgBin ecx
  DbgDec ecx
  DbgFloat r4MyFloat1, "REAL4"
  DbgFloat r8MyFloat2, "REAL8"
  DbgBin ecx
  DbgApiError
  DbgLine
  DbgGlobalMemUsage "Memory usage here"
  DbgLine
  xor ecx, ecx
  ASSERT ecx, "ecx should not be zero here"
;  DbgComError 0
;  DbgComError 08000FFFFh
  DbgText "Bye..."
;  DbgClearTxt "Performance data"
;  DbgClearBmp "BMP1"

  SysDone
  invoke ExitProcess, 0
start endp

end
