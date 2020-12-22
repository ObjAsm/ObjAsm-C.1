; ==================================================================================================
; Title:      Demo01C.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration application 1C using static objects and Templates.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, NUI64, ANSI_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

MakeObjects Primer, Demo01                              ;Include Shape, Triangle and Rectangle

.data                                                   ;Define global variables in the Data segment
Shape_1   $ObjInst(Triangle)                            ;Static Instance of Triangle
pShape_1  $ObjPtr(Triangle)   NULL
pShape_2  $ObjPtr(Rectangle)  NULL

.code                                                   ;Begin Code segment
start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of the OOP model
  DbgClearAll                                           ;Clear all DebugCenter windows

  mov xax, offset Shape_1
  mov pShape_1, xax                                     ;Store instance pointer
;    DbgObject pShape_1::Triangle
  OCall pShape_1::Triangle.Init, 10, 15                 ;Initialize Triangle
  OCall pShape_1::Shape.GetArea                         ;Invoke GetArea method of Triangle
  DbgDec eax                                            ;Result = 75

  mov xax, offset $ObjTmpl(Rectangle)
  mov pShape_2, xax                                     ;Store instance pointer = Object Template
  OCall pShape_2::Rectangle.Init, 10, 15                ;Initialize Rectangle

  OCall pShape_2::Shape.GetArea                         ;Invoke GetArea method of Rectangle
  DbgDec eax                                            ;Result = 150
  OCall pShape_2::Rectangle.GetPerimeter                ;Invoke GetPerimeter method
  DbgDec eax                                            ;Result = 50

  OCall pShape_2::Rectangle.TestFunction                ;Invoke TestFunction method
  DbgDec xax                                            ;Result = TRUE (1)
  Override pShape_2::Rectangle.TestFunction, Rectangle.IsQuad ;Overrides TestFunction
  OCall pShape_2::Rectangle.TestFunction                ;Invoke TestFunction method
  DbgDec xax                                            ;Result of IsQuad = FALSE (0)

  OCall pShape_2::Rectangle.Done                        ;Invoke Rectangle's Done
  OCall pShape_1::Triangle.Done                         ;Invoke Triangle's Done

  SysDone                                               ;Runtime finalization of the OOP model

  invoke ExitProcess, 0                                 ;Exit program returning 0 to Windows OS
start endp

end
