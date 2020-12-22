; ==================================================================================================
; Title:      MsgBoxApp_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm MsgBox Application.
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <MsgBox Application>
ABOUT_TEXT                    textequ   <MsgBox Application>
COPYRIGHT                     textequ   <G. Friedrich,  April 2020> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       29
BUILD_DATE_STR                textequ   <29.11.2020>
BUILD_BITNESS                 equ       32
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999

IDC_TEXT_ABOUT                equ       100
