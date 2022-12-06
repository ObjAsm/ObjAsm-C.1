; ==================================================================================================
; Title:   IntgSim_macs.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose:  Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

AbreEstadisticas macro statVariables
	local statn
	if HaceEstadisticas
		mov	xbx , [xsi].modelo
		assume xbx : ptr $Obj(modeloB)
		OCall [xbx].statLineal::StatLin.Initialization, &statVariables;,4
		statn = 0
		repeat statVariables
			statn = statn+1
			OCall [xbx].statLineal::StatLin.compararMultipleI, &statn, NULL;$OfsCStr(" FAT ")
		endm
		.if [xsi].ajustando == FALSE
;			OCall [ebx].statLineal::StatLin.residual_Ini, 3
		.endif
		assume xbx : nothing 
	endif
endm

CierraEstadisticas macro nVariables
	local statn
	if HaceEstadisticas
		assume xbx : ptr $Obj(modeloB)
		mov	xbx , [xsi].modelo
    	;OCall [ebx].statLineal::StatLin.Finalization
    	statn = 0
    	repeat nVariables
    		statn = statn +1
	    	OCall [xbx].statLineal::StatLin.compararMultipleF, statn
    	endm
		OCall [xbx].statLineal::StatLin.compararMultipleT, &nVariables;3
   		.if [xsi].ajustando == FALSE
   		;	OCall [ebx].statLineal::StatLin.cuadroGeneral, [esi].hEvaluaciones, v1
	   		;OCall [ebx].statLineal::StatLin.residualF, 3, [esi].hEvaluaciones
			;OCall [ebx].statLineal::StatLin.determinanteT, 3, [esi].hEvaluaciones
		.endif
		assume xbx : nothing
   		if 0
   		.if [xsi].ajustando == FALSE && [xsi].instancias > 0
			OCall xsi.Summary, [xsi].hEvaluaciones
		.endif
		endif
	endif
endm