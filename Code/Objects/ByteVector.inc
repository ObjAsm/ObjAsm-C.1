; ==================================================================================================
; Title:      ByteVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ByteVector objects.
; Notes:      Version C.1.0, September 2021
;               - First release.
; ==================================================================================================


TVectorName         textequ   <ByteVector>
TVectorID           textequ   <ByteVectorID>
TVEC_DATA_TYPE      textequ   <BYTE>
PVecProc            textequ   <PVecProc08>
VEC08_MAX_CAPACITY  equ       0FFFFFFFFh/sizeof(TVEC_DATA_TYPE)

include .\TVector.inc                                   ;Template file