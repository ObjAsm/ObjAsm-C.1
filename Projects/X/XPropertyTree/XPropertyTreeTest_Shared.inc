; ==================================================================================================
; Title:      XPropertyTreeTest_Shared.inc
; Author:     G. Friedrich
; Version:    XPropertyTreeTest.asm
; Purpose:    ObjAsm XPropertyTree Test Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <XPropertyTree Demo>
ABOUT_TEXT                    textequ   <XPropertyTree>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       4
BUILD_DATE_STR                textequ   <2022-08-08>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs

IDC_TEXT_ABOUT                equ       100

IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999
IDM_CONTEXT                   equ       3000
