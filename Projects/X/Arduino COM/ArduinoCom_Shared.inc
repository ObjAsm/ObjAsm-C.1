; ==================================================================================================
; Title:      ArduinoCom_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Arduino Communication demonstration program.
; Notes:      Version C.1.1, October 2020
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Arduino Communication Demo>
ABOUT_TEXT                    textequ   <Arduino Communication Demo>
COPYRIGHT                     textequ   <G. Friedrich   October 2020> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       34
BUILD_DATE_STR                textequ   <04.11.2020>
BUILD_BITNESS                 equ       32
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_SELECTION                 equ       1001
IDM_CONNECT                   equ       1002
IDM_DISCONNECT                equ       1003
IDM_TRANSMIT                  equ       1004
IDM_RECIEVE                   equ       1005
IDM_EXIT                      equ       1010
IDM_HELP                      equ       2001
IDM_ABOUT                     equ       2002

IDC_TEXT_ABOUT                equ       100
