; ==================================================================================================
; Title:      DWordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of DWordVector objects.
; Notes:      Version C.1.0, September 2021
;               - First release.
; ==================================================================================================


TVectorName         textequ   <DWordVector>
TVectorID           textequ   <DWordVectorID>
TVEC_DATA_TYPE      textequ   <DWORD>
PVecProc            textequ   <PVecProc32>
VEC32_MAX_CAPACITY  equ       0FFFFFFFFh/sizeof(TVEC_DATA_TYPE)

include .\TVector.inc                                   ;Template file