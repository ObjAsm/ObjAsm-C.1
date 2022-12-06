; ==================================================================================================
; Title:   SimpleTest.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

Object SimpleTest,, LinkedList

	RedefineMethod Done
	
	VirtualAbstract Inicia
	VirtualAbstract Muestra
	VirtualAbstract Simulacion

	VirtualMethod SetAjustando, xword
	DefineVariable calculado, xword, NULL
	DefineVariable killcode, xword, NULL

	VirtualMethod SetControls
	DefineVariable control, CONTROL_INTG,{}
	DefineVariable controlr, CONTROL_INTG,{}

	DefineVariable unidades, xword, 0

	RedefineMethod Simulacion
	VirtualMethod Estabilizacion, xword
	
ObjectEnd


Method SimpleTest.SetAjustando, uses xsi, valor : xword
	SetObject xsi
	OCall xsi.GetFirst
	.while xax != NULL
    	m2m [xax].$Obj(UnidadExperimental).integ.ajustando, valor, @if64bits(r13)
		OCall xsi.GetNext	
	.endw
MethodEnd

Method SimpleTest.SetControls, uses xsi

   CStr M0SetControls$,"+SimpleTest.SetControls",13,10
;    mov rcx,pConsole
;    invoke [rcx].ConOut.OutputString, pConsole, ADDR M0SetControls$
    
	SetObject xsi
	OCall xsi.GetFirst
	.while xax != NULL
	    ;DbgHex xax, " debería ser la unidad"
	    ;DbgObject xax::UnidadExperimental
		m2m [xax].$Obj(UnidadExperimental).integ.control.integracion, [xsi].controlr.integracion, @if64bits(r10)
		f2f [xax].$Obj(UnidadExperimental).integ.control.maxt, [xsi].controlr.maxt
		f2f [xax].$Obj(UnidadExperimental).integ.control.cint, [xsi].controlr.cint
		OCall xsi.GetNext	
	.endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Method SimpleTest.Simulacion, uses xsi xbx
	local counter : xword
	local igral_1 : xword
	local knot: xword
	;local fregTLS()
    LOCAL hProcess :XWORD

    ;invoke GetCurrentProcess
    ;mov hProcess, xax
	
    
	SetObject xsi
	
	CStr M0Simulacion$,"+SimpleTest.Simulacion",13,10
    ;mov rcx,pConsole
    ;invoke [rcx].ConOut.OutputString, rcx, ADDR M0Simulacion$

	mov counter, 0
	
	OCall xsi.GetFirst
	mov xbx, xax
	.while xbx != NULL
		;DbgText "Simula"
        if 0;isThread
            ;invoke SetPriorityClass,hProcess,REALTIME_PRIORITY_CLASS
            ;invoke SetPriorityClass,hProcess, HIGH_PRIORITY_CLASS
            mov [xbx].$Obj(UnidadExperimental).running, 1
    		invoke CreateThread, NULL, 0, $MethodAddr(UnidadExperimental.Run), xbx, 0, NULL;addr knot
            invoke CloseHandle, xax
            mov xax, 0
        else
            OCall xbx::UnidadExperimental.Run
	    endif
	    
		OCall xsi.GetNext
		mov xbx, xax
	.endw

    if 0;isThread
    @@1:	
    	mov xbx, 0
	    OCall xsi.GetFirst
    	.while xax != NULL
    	    add xbx, [xax].$Obj(UnidadExperimental).running 
			OCall xsi.GetNext
		.endw
		cmp xbx, 0
		jg @@1
    endif

sale:    
	
MethodEnd
Method SimpleTest.Estabilizacion, uses xsi xbx xdi, modalidad : xword
	local salida  : xword
	local counter : xword
	local igral_1 : xword
	
	SetObject xsi
	
	if 0
	mov counter, 0
	
	;lea xdi, TPL_Integ01.ProgressExp
	;OCall xdi::Progressbar.SetPos, 0
	
	OCall xsi.GetFirst
	mov xbx, xax
	.while xbx != NULL
		;DbgText "Simula"
	
		inc counter
		fild 	counter
		fidiv	[xsi].unidades
		fmul 	cien
		fistp	igral_1
		lea xdi, TPL_Integ01.ProgressExp
		OCall xdi::Progressbar.SetPos, igral_1
		
		mov salida, 0
		OCall [xbx].UnidadExperimental.etapas::LinkedList.GetFirst
		.repeat 
			.if xax == NULL
				mov salida , 1
				lea xdi, TPL_Integ01.ProgressInd
				;OCall xdi::Progressbar.SetPos, 100
			.else
				.if [xax].Etapa.isInitial == 1
					freg_push xax
					lea xdi, TPL_Integ01.ProgressInd
					OCall xdi::Progressbar.SetPos, 0
					mov [xbx].UnidadExperimental.integ.inicioEst, 0
					freg_pop xax

					DbgText "Etapa es inicial" 
					fld [xax].Etapa.inicio
					fstp [xbx].UnidadExperimental.integ.control.inicio
					fld [xax].Etapa.duracion
					fstp [xbx].UnidadExperimental.integ.control.duracion
					if 1
					mov [xbx].UnidadExperimental.integ.control.isInitial, 1
					else
					; Estabilización inicial
					mov [xbx].UnidadExperimental.integ.control.isInitial, 2
					freg_push xax

					pushad
					OCall [xbx].UnidadExperimental.integ::IntgSim.SimCircle, modalidad
					popad

					freg_pop xax
					;ret
					endif 
				.endif
				
				mov xdx, [xax].Etapa.pTrat
				.if xdx != NULL
					freg_push xdx
					mov xcx , [xdx].Tratamiento.TipoConsumo
					
					mov [xbx].UnidadExperimental.unidad.DD35_ayuno, xcx
					;DbgBin [xax].Etapa.tratamiento 
					;int 3
					freg_pop xdx
					.if [xdx].Tratamiento.alimento != NULL
						mov xdx, [xdx].Tratamiento.alimento
						DbgText "si Cambia la dieta"
						lea xcx, [xbx].UnidadExperimental.unidad.Feed
						CopiaObjeto	$Obj(MollyDiet), <xcx>, <xdx>
					.endif
				.endif 	
			.endif
			;DbgObject [xbx].UnidadExperimental.unidad::modeloC
			;DbgFloat [xbx].UnidadExperimental.unidad.R8_ebw
			
			;OCall [xbx].UnidadExperimental.integ::IntgSim.Sim
			OCall [xbx].UnidadExperimental.etapas::LinkedList.GetNext
			;mov xax, 0
			.if xax == NULL
				mov salida , 1
			;	lea xdi, TPL_Integ01.ProgressInd
			;	OCall xdi::Progressbar.SetPos, 100
			.endif
		.until salida == 1
		OCall xsi.GetNext
		mov xbx, xax
	.endw
	endif
MethodEnd

Method SimpleTest.Done, uses xsi xbx
    DbgText "SimpleTest.Done"
	SetObject xsi
	OCall xsi.GetFirst
	mov xbx, xax
	.while xbx != NULL
		;OCall xbx::UnidadExperimental.Done
		OCall xsi.GetNext
		mov xbx, xax
	.endw
	ACall xsi.Done
MethodEnd
endif
