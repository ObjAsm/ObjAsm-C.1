; ==================================================================================================
; Title:      IFileDialogApp_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm IFileDialog demo.
; Notes:      Version C.1.0, November 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <IFileDialogApp>
ABOUT_TEXT                    textequ   <IFileDialog demo>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       131
BUILD_DATE_STR                textequ   <2021-10-17>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDC_TEXT_ABOUT                equ       100

IDM_OPEN                      equ       1001
IDM_EXIT                      equ       1002
IDM_HELP                      equ       2001
IDM_ABOUT                     equ       2002
