; ==================================================================================================
; Title:      DLApp_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Dynamic Window Layout Application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Dynamic Layout Application>
ABOUT_TEXT                    textequ   <Dynamic Layout Application>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       93
BUILD_DATE_STR                textequ   <18.10.2020>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_DIALOG                    equ       1001
IDM_HELP                      equ       2000
IDM_ABOUT                     equ       2001

IDC_TEXT_ABOUT                equ       100
