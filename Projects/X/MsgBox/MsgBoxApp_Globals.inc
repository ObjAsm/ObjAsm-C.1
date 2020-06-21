; ==================================================================================================
; Title:      MsgBoxApp_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm MsgBox Application.
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


include MsgBoxApp_Shared.inc

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


if 1
CStr szMarkupText,    "{Padding 20}", \
                      "{TABC 140}{TABR 220}", \
                      "[Indent 10, H +2, Bold, Underline]", \
                        "Description{TAB}Qty{TAB}Price{P}", \
                      "[~]", \
                      "[Indent 25, Color #4F4FFF, H +2, Italic]", \
                          "{#2022} Item[SUB]1[~]{TAB}2{TAB}2.35[SUP]*[~]{B}", \
                          "{#2022} Item[SUB]2[~]{TAB}200.0{TAB}20.00[SUP]**[~]{B}", \
                          "{#2022} Item[SUB]3[~]{TAB}0.1{TAB}0.23{B}{P}", \
                      "[~]", \
                      "{TABCLR}{TABC 80}{TABL 95}", \
                      "[Indent 30, Hanging 30, Color #4F4F4F]", \
                        "Note:{TAB}*{TAB}Volume discount{B}", \
                        "{TAB}**{TAB}Regular discount", \
                      "[~]", \
                      "{COVER 1}"


else

.const
String szMarkupText,  "{Padding 20}", \
                      "[Height 11]", \
                        "{COVER 0}", \
                        "[Indent 150, Align 'LEFT']", \
                          "[Height +3, Bold]&ABOUT_TEXT{B}[~]", \
                          "[Italic]Version &VER_PRODUCTVERSION_STR{P}[~]", \
                          "[Color #3F3F3F]", \
                            "Designed with ObjAsm{B}", \
                            "© &COPYRIGHT{P}", \
                            "[Color #5F4FFF]", \
                              @CatStr(<!">, %BUILD_DATE_STR, \
                                      <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                                      %TARGET_MODE_STR, <->, %TARGET_BITNESS, <    !">), \
                              "[Info ", @CatStr(<!">, %INFO_BUILD, <!">), ", Font 'Webdings', Height +1]{#69}[~]", \
                            "[~]{B}{B}", \
                          "[~]", \
                        "[~]"
ExtendString            "[Indent 0, Align 'CENTER']", \
                          "[Font 'Webdings', Color #FF5F5F, Height +7]{#7E}[~]", \
                          "  Visit us at  ", \
                          "[App ", @CatStr(<!">, %APP_VISIT, <!">), ", Color #0000FF, U]www.objasm.x10host.com[~]{B}", \
                          "[Font 'Wingdings', Color #408090, Height +1]{#2A}[~]", \
                          "   Email us to  ", \
                          "[App ", @CatStr(<!">, %APP_EMAIL, <!">), ", Color #0000FF, U]objasm@gmx.net[~]{P}", \
                          "[App ", @CatStr(<!">, %APP_CHECK, <!">), ", Color #0000FF, U]Check for updates[~]", \
                          "[Info ", @CatStr(<!">, %INFO_UPDATE, <!">), ", Font 'Webdings', H +1, Color #5F5FFF]  {#69}[~]", \
                        "[~]", \
                      "[~]"

endif

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
