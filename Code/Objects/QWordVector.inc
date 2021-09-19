; ==================================================================================================
; Title:      QWordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of QWordVector objects.
; Notes:      Version C.1.0, September 2021
;               - First release.
; ==================================================================================================


TVectorName         textequ   <QWordVector>
TVectorID           textequ   <QWordVectorID>
TVEC_DATA_TYPE      textequ   <QWORD>
PVecProc            textequ   <PVecProc64>
VEC64_MAX_CAPACITY  equ       0FFFFFFFFh/sizeof(TVEC_DATA_TYPE)

include .\TVector.inc                                   ;Template file
