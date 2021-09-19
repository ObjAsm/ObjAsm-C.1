; ==================================================================================================
; Title:      XWordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of XWordVector objects.
; Notes:      Version C.1.0, September 2021
;               - First release.
; ==================================================================================================


if TARGETBITNESS eq 64
  XWordVector textequ <QWordVector>
else
  XWordVector textequ <DWordVector>
endif
