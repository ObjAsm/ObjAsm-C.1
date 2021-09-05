; ==================================================================================================
; Title:      RedBlackTreeDemo_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Pixelmap application using ObjAsm.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <RedBlackTree Demo Application>
ABOUT_TEXT                    textequ   <RedBlackTree Demo Application>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       23
BUILD_DATE_STR                textequ   <2021-09-05>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDC_TEXT_ABOUT                equ       100

IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999
