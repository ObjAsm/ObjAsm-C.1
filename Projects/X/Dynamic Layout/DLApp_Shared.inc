; ==================================================================================================
; Title:      DLApp_Shared.inc
; Author:     G. Friedrich
; Version:    See DLApp.asm
; Purpose:    ObjAsm Dynamic Window Layout Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Dynamic Layout Application>
ABOUT_TEXT                    textequ   <Dynamic Layout Application>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       17
BUILD_DATE_STR                textequ   <2022-09-19>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_DIALOG                    equ       1001
IDM_HELP                      equ       2000
IDM_ABOUT                     equ       2001

;Dialog About Control IDs
IDC_DAB_ICON                  equ       100
IDC_DAB_TEXT                  equ       101
IDC_DAB_MAIL                  equ       102
IDC_DAB_LINK                  equ       103
