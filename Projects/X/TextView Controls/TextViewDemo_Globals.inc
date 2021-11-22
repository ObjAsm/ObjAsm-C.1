; ==================================================================================================
; Title:      TextViewDemo_Globals.inc
; Author:     G. Friedrich
; Version:    See TextViewDemo.asm
; Purpose:    ObjAsm TextView Demo Application with Controls.
; ==================================================================================================


include TextViewDemo_Shared.inc

CStr szIcoName,     "ICON_APP"
%CStr szAppTitle,   "&APP_TITLE"
%CStr szAboutText,  "&ABOUT_TEXT", 13, 10, \
                    "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                    "Designed with ObjAsm", 13, 10, \
                    "© &COPYRIGHT", 13, 10, 13, 10, \
                    @CatStr(<!">, %BUILD_DATE_STR, \
                            <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                            %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)

APP_VISIT     equ   4
APP_CHECK     equ   5

String szMarkupText,  "{Padding 20, AutoLineBreak, Zoomable}", \
                      "[H +3]", \
                      "[H+2,Canvas#FFFFFF]", \
                        "[H+1]Settings:[~]{P}", \
                        "[FI20,HI20,C#0000F0]", \
                          "[C#0000F0,App0][TXT0,F'Lucida Sans Unicode']?[~] Option 1[~]   [TIP0,F'Webdings',H-2]{#69}[~]{B}", \
                          "[C#F00000,App1][TXT1,F'Lucida Sans Unicode']?[~] Option 2[~]{P}", \
                          "[C#007000,App2][TXT2,F'Wingdings 2']?[~] Option 3[~]{B}", \
                          "[C#000000,App3][TXT3,F'Wingdings 2']?[~] Option 4[~]{B}{B}", \
                        "[~]", \
                      "[~]"

ifdef __UASM__
  ANAME     textequ <UASM>
  AVERSION  equ __UASM__
elseifdef __JWASM__
  ANAME     textequ <JWASM>
  AVERSION  equ __JWASM__
elseifdef __ASMC__
  ANAME     textequ <ASMC>
  AVERSION  equ __ASMC__
else
  ANAME     textequ <MASM>
  AVERSION  equ  @Version
endif

if TARGET_MODE eq MODE_RLS
  DNAME     textequ <RELEASE>
else
  DNAME     textequ <DEBUG>
endif

CStr szUpdateInfo,  "Verifies the availability of a new software update."

%CStr szBuildInfo,  "Build number:", 9, @CatStr(<!">, %BUILD_NUMBER, <!">), 13, \
                    "Assembler:   ", 9, @CatStr(<!">, %ANAME, <!">), 13, \
                    "Version:     ", 9, @CatStr(<!">, %AVERSION, <!">), 13, \
                    "Distribution:", 9, @CatStr(<!">, %DNAME, <!">), 13, \
                    "Bitness:     ", 9, @CatStr(<!">, %TARGET_BITNESS, <!">)
