; ==================================================================================================
; Title:      OcxContainer_Shared.inc
; Author:     G. Friedrich
; Version:    See OcxContainer.asm
; Purpose:    ObjAsm OCX Control Container.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <OcxContainer>
ABOUT_TEXT                    textequ   <Active X Control Container>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       9
BUILD_DATE_STR                textequ   <2022-08-28>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Dialog About Control IDs
IDC_DAB_ICON                  equ       100
IDC_DAB_TEXT                  equ       101
IDC_DAB_MAIL                  equ       102
IDC_DAB_LINK                  equ       103

;Menu IDs
IDM_OPEN                      equ       1001
IDM_EXIT                      equ       1002
IDM_HELP                      equ       2001
IDM_ABOUT                     equ       2002
