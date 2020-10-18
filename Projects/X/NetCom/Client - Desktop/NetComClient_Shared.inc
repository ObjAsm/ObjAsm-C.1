; ==================================================================================================
; Title:      NetComClient_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm NetComClient program.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <NetCom Client>
ABOUT_TEXT                    textequ   <NetComClient>
COPYRIGHT                     textequ   <G. Friedrich   October 2017>
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       138
BUILD_DATE_STR                textequ   <18.10.2020>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

IDC_TEXT_ABOUT                equ       100

IDM_SEND                      equ       1000
IDM_EXIT                      equ       1001
IDM_HELP                      equ       1100
IDM_ABOUT                     equ       1101


IDD_DLG_SEND                  equ       1000
IDC_BTN_CONNECT               equ       1001
IDC_BTN_DISCONNECT            equ       1002
IDC_EDT_ADDRESS               equ       1005
IDC_EDT_PORT                  equ       1007
