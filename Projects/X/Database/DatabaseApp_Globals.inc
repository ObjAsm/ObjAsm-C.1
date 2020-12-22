; ==================================================================================================
; Title:      DatabaseApp_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database demonstration Application.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


include DatabaseApp_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

CStr szQueryFile, "DBase.qry"


CLS_STYLE         equ   CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW
SBR_STYLE         equ   WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

;Dialog Design Elements (Units in DLU)
CTL_MARGIN_HORZ       = 4
CTL_MARGIN_VERT       = 0
CTL_SEPARATION_HORZ   = 3
CTL_HEIGHT_EDIT       = 14
CTL_SEPARATION_VERT   = CTL_HEIGHT_EDIT + 2        ;Distance from baseline to baseline
CTL_HEIGHT_STATIC     = CTL_HEIGHT_EDIT
CTL_BUTTON_WIDTH      = 50
CTL_BUTTON_HEIGHT     = 14

CTRL_POSITIONS struc
  LineOrigin  POINT   {}
  sdPosX1     SDWORD  ?
  sdPosX2     SDWORD  ?
  sdPosX3     SDWORD  ?
  sdPosX4     SDWORD  ?
  sdPosX5     SDWORD  ?
  sdPosX6     SDWORD  ?
CTRL_POSITIONS ends
PCTRL_POSITIONS typedef ptr CTRL_POSITIONS
