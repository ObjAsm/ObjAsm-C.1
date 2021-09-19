; ==================================================================================================
; Title:      WordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of WordVector objects.
; Notes:      Version C.1.0, September 2021
;               - First release.
; ==================================================================================================


TVectorName         textequ   <WordVector>
TVectorID           textequ   <WordVectorID>
TVEC_DATA_TYPE      textequ   <WORD>
PVecProc            textequ   <PVecProc16>
VEC16_MAX_CAPACITY  equ       0FFFFFFFFh/sizeof(TVEC_DATA_TYPE)

include .\TVector.inc                                   ;Template file