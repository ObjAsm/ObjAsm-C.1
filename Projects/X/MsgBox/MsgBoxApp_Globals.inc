; ==================================================================================================
; Title:      MsgBoxApp_Globals.inc
; Author:     G. Friedrich
; Version:    See ViewDemo.asm
; Purpose:    ObjAsm MsgBox Application.
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



CStr szMarkupText,  "{Padding 20}{SIZE.X 330}{SIZE.Y 290}", \
                    "{TABC 140}{TABR 220}", \
                    "[H +2, Indent 10, Bold, Underline]", \
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
                      "{TAB}**{TAB}Regular discount{B}", \
                    "[~]", \
                    "{COVER 1}"
