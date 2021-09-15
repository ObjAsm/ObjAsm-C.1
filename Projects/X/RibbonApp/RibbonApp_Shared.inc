; ==================================================================================================
; Title:      RibbonApp_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Ribbon application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Ribbon Application>
ABOUT_TEXT                    textequ   <Ribbon Demo Application>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       107
BUILD_DATE_STR                textequ   <09.09.2021>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1100
IDM_HELP                      equ       6000
IDM_ABOUT                     equ       6001
