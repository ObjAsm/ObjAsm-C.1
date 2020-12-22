; ==================================================================================================
; Title:      Demo01B.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application 1B using console debug output.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, NUI64, ANSI_STRING, DEBUG(CON)            ;Load OOP files and OS related objects
                                                        ;Redirect Debug output to a console window.
MakeObjects Primer, Demo01                              ;Include Shape, Triangle and Rectangle

.data                                                   ;Define global variables in the Data segment
pShape_1    $ObjPtr(Triangle)   NULL
pShape_2    $ObjPtr(Rectangle)  NULL
ConInput    CHR  10 DUP(0)                              ;Get some space for the console input buffer
dBytesRead  DWORD               0

.code                                                   ;Begin Code segment
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of the OOP model
  DbgClearAll                                           ;Clear all DebugCenter windows
  New Triangle                                          ;Create an new instance of Triangle
  mov pShape_1, xax                                     ;Store instance pointer

  OCall pShape_1::Triangle.Init, 10, 15                 ;Initialize Triangle
  OCall pShape_1::Shape.GetArea                         ;Invoke GetArea method of Triangle
  DbgDec eax                                            ;Result = 75

  New Rectangle                                         ;Create an new instance of Rectangle
  mov pShape_2, xax                                     ;Store instance pointer
  OCall pShape_2::Rectangle.Init, 10, 15                ;Initialize Rectangle
  OCall pShape_2::Shape.GetArea                         ;Invoke GetArea method of Rectangle
  DbgDec eax                                            ;Result = 150
  OCall pShape_2::Rectangle.GetPerimeter                ;Invoke GetPerimeter method
  DbgDec eax                                            ;Result = 50

  OCall pShape_2::Rectangle.TestFunction                ;Invokes TestFunction method
  DbgDec xax                                            ;Result = TRUE (1)
  Override pShape_2::Rectangle.TestFunction, Rectangle.IsQuad ;Overrides TestFunction
  OCall pShape_2::Rectangle.TestFunction                ;Invoke TestFunction method
  DbgDec xax                                            ;Result of IsQuad = FALSE (0)

  Destroy pShape_2                                      ;Invoke Rectangle's Done and disposes it
  Destroy pShape_1                                      ;Invoke Triangle's Done and disposes it

  DbgText " "
  DbgText "Press \[ENTER\] to continue..."
  invoke CreateFile, $OfsCStr("CONIN$"), GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0
  invoke ReadFile, xax, addr ConInput, sizeof(ConInput), addr dBytesRead, NULL

  SysDone                                               ;Runtime finalization of the OOP model

  invoke ExitProcess, 0                                 ;Exit program returning 0 to Windows OS
start endp

end
