; ==================================================================================================
; Title:   lineal.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: lineal regression for Benchmark UEFI Application.
; Version: Version 1.0.0, May 2022
;            - First release.
; ==================================================================================================

lineal proc  inputsy: POINTER, n:qword
    
    local i: qword, i_t : qword
    local X:REAL8, X2:REAL8,Y:REAl8,Y2:REAL8,XY:REAL8
    local a:REAL8,b:REAL8
    local sXX:REAL8, sXY:REAL8

    fldz
    fst X
    fst Y
    fst X2
    fst Y2
    fstp XY
    
    ForLp_df i, 0, n
        mov rcx, inputsy
        shl rax, 3
        add rcx, rax
        fild SQWORD ptr [rcx]
        fld st
        fld st
        fmul
        fadd Y2
        fstp Y2
        fld st
        fild i
        fld st
        fadd X
        fstp X
        fld st
        fld st
        fmul
        fadd X2
        fstp X2
        fmul
        fadd XY
        fstp XY
        fadd Y
        fstp Y
    Next i
    fSlv8 sXY = XY-X*Y/n
    fSlv8 sXX = X2-X^2/n

    fSlv8 b = sXY/sXX

    fSlv8  = (Y-b*X)/n
    fld b
    
    ret
lineal endp
