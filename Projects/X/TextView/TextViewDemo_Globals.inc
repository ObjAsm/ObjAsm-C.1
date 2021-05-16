; ==================================================================================================
; Title:      TextViewDemo_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm TextView demonstration program.
; Notes:      Version C.1.1, April 2020
;               - First release.
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
                    

APP_VISIT     equ   0
APP_EMAIL     equ   1
APP_CHECK     equ   2

INFO_BUILD    equ   0
INFO_UPDATE   equ   1


.const
String szMarkupText,  "{Padding 20}", \
                      "[Height +1]", \
                        "{COVER 0}", \
                        "[Indent 150, Align.left]", \
                          "[Height +3, Bold]&ABOUT_TEXT{B}[~]", \
                          "[Italic]Version &VER_PRODUCTVERSION_STR{P}[~]", \
                          "[Color #3F3F3F]", \
                            "Designed with ObjAsm{B}", \
                            "© &COPYRIGHT{P}", \
                            "[Color #5F4FFF]", \
                              @CatStr(<!">, %BUILD_DATE_STR, \
                                      <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                                      %TARGET_MODE_STR, <->, %TARGET_BITNESS, <    !">), \
                              "[TIP ", @CatStr(<!">, %INFO_BUILD, <!">), ", Font 'Webdings', Height +1]{#F069}[~]", \
                            "[~]{B}{B}", \
                          "[~]", \
                        "[~]"
ExtendString            "[Indent 0, Align.Center]", \
                          "[Font 'Webdings', Color #FF5F5F, Height +7]{#F07E}[~]", \
                          "  Visit us at  ", \
                          "[APP ", @CatStr(<!">, %APP_VISIT, <!">), ", Color #0000FF, U]www.objasm.x10host.com[~]{B}", \
                          "[Font 'Wingdings', Color #408090, Height +1]{#F02A}[~]", \
                          "   Email us to  ", \
                          "[APP ", @CatStr(<!">, %APP_EMAIL, <!">), ", Color #0000FF, U]objasm@gmx.net[~]{P}", \
                          "[APP ", @CatStr(<!">, %APP_CHECK, <!">), ", Color #0000FF, U]Check for updates[~]", \
                          "[TIP ", @CatStr(<!">, %INFO_UPDATE, <!">), ", Font 'Webdings', H+1, Color #5F5FFF]  {#F069}[~]", \
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
                    
%CStr szBuildInfo,  "Build number: ", 9, @CatStr(<!">, %BUILD_NUMBER, <!">), 13, \
                    "Assembler:    ", 9, @CatStr(<!">, %ANAME, <!">), 13, \
                    "Version:      ", 9, @CatStr(<!">, %AVERSION, <!">), 13, \
                    "Distribution: ", 9, @CatStr(<!">, %DNAME, <!">), 13, \
                    "Bitness:      ", 9, @CatStr(<!">, %TARGET_BITNESS, <!">)
