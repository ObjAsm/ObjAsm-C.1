; ==================================================================================================
; Title:   IntgControl.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose:  Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

CONTROL_INTG struc
	submodelo	xword	6
	integracion	xword 	meth_integ
	%inicio		real8	v_inicio;216.0;
	%duracion	REAL8	v_duracion;244.0;
	final		REAL8	525.0
	%maxt		REAL8	v_maxt;0.002
	%cint		REAL8	v_cint;0.002
	%maxt_cod	xword	v_maxt_cod;1	
	modalidad	xword	0
	isInitial	xword	0
	proceso		xword	0
	;VirtualMethod CargaPuntoP, xword,xword,qword,qword
CONTROL_INTG ends
PCONTROL_INTG  typedef ptr CONTROL_INTG  
