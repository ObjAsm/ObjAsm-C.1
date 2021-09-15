; ==================================================================================================
; Title:      JsonDemo_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm JSON demonstration program.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <JSON Demo>
ABOUT_TEXT                    textequ   <JSON Demo>
COPYRIGHT                     textequ   <G. Friedrich   December 2020> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       9
BUILD_DATE_STR                textequ   <09.09.2021>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999

IDC_TEXT_ABOUT                equ       100
