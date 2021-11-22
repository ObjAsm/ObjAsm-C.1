; ==================================================================================================
; Title:      Api3DEng_Globals.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm API 3D Engine program.
; ==================================================================================================


include Api3DEng_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

CStr szScene, "Scene.svd"
