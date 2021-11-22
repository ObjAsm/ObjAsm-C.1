; ==================================================================================================
; Title:      XPropertyTreeTest_Globals.inc
; Author:     G. Friedrich
; Version:    XPropertyTreeTest.asm
; Purpose:    ObjAsm XPropertyTree Test Application.
; ==================================================================================================


include XPropertyTreeTest_Shared.inc

%CStr cAppCaption,"&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)
