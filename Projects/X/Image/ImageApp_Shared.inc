; ==================================================================================================
; Title:      ImageApp_Shared.inc
; Author:     G. Friedrich
; Version:    See ImageApp.asm
; Purpose:    ObjAsm Image Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Image Demo           -- Strecht the Window -->
ABOUT_TEXT                    textequ   <Image Demo>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       2
BUILD_DATE_STR                textequ   <2021-11-21>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999

IDC_TEXT_ABOUT                equ       100
