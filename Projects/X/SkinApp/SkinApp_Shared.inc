; ==================================================================================================
; Title:      SkinApp_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Skin application.
; Notes:      Version C.1.0, November 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Skin Application>
ABOUT_TEXT                    textequ   <Elastic Skin Engine Demo>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       84
BUILD_DATE_STR                textequ   <29.11.2020>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_EXIT                      equ       1000
IDM_ABOUT                     equ       1999

