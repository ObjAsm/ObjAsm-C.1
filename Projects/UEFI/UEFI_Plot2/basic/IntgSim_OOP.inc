; ==================================================================================================
; Title:   IntgSIM_OOP.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose:  Object declaration - IntegAsm32 Light
; ==================================================================================================
    Integ_Directo       equ	0 
    Integ_RungeKutta    equ	1 
    Integ_CashKarp      equ	2 
    Integ_Fehlberg      equ	3
		
	_Control_Model

  include IntgControl.inc

	CARGAACUS struct
	    etapa xword 0
	    x1    real8 0.0
	CARGAACUS ends
	PCARGAACUS typedef ptr CARGAACUS
  
;include ACU.asm

Object IntgSim, , IntgBase
    DefineVariable control, CONTROL_INTG, {}
    ;DefineVariable controlr, CONTROL_INTG,{}
	
    DefineVariable calculado, xword, FALSE
    DefineVariable counterT, xword, 0

    RedefineMethod CargaVector
    IFE SoloEstados 
        RedefineMethod CargaDerivada
        RedefineMethod LevantaVariables, xword
        RedefineMethod CargaVariables
    ENDIF 
    RedefineMethod CargaAcu 
    RedefineMethod Tratamiento, REAL8 
    RedefineMethod Resultado, REAL8 
	
    VirtualMethod Asignamodelo
    VirtualMethod Iniciamodelo
    RedefineMethod Init
    RedefineMethod Done
	
    VirtualMethod Sim
    ;VirtualMethod SimIndividual, xword

    DefineVariable hEvaluaciones, POINTER, 0
	
    DefineVariable diar, xword, 0
       ; 04/12/17
    if 0
        	RedefineMethod CargaCircle
         	VirtualMethod SimCircle, xword
    endif
    ;19/08/18
    ;VirtualMethod Summary, POINTER
    if HaceEstadisticas 
        DefineVariable msep, REAL8, varis+1 dup (0.0)
        DefineVariable ect, REAL8, varis+1 dup (0.0)
        DefineVariable er, REAL8, varis+1 dup (0.0)
        DefineVariable _ed, REAL8, varis+1 dup (0.0)
    endif        
    DefineVariable duracionEst, xword, 0
    DefineVariable inicioEst, xword, 0
    DefineVariable cargaacus, CARGAACUS, {}

ObjectEnd

; 04/12/17
ccM macro n1, n2,n3
	OCall [xsi].statLineal::StatLin.compararMultipleD,&n1, &n2,n3
endm 

