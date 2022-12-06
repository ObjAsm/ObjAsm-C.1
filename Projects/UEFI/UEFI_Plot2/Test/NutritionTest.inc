; ==================================================================================================
; Title:   NutritionTest.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

Object Tratamiento,, Primer
	DefineVariable alimento, POINTER, 0
	DefineVariable tratamiento, dword, 0 
	DefineVariable TipoConsumo, dword, 0
	DefineVariable qa, real8, 0.0
	DefineVariable qb, real8, 0.0
	DefineVariable qc, real8, 0.0
ObjectEnd


Object Etapa,, Primer
	RedefineMethod Done
	DefineVariable isInitial, dword, 0
	DefineVariable inicio, real8, 0.0
	DefineVariable duracion, real8, 0.0 
	DefineVariable pTrat, POINTER, 0 
	
ObjectEnd

Object UnidadExperimental,, Primer

	RedefineMethod Done
	DefineVariable orden, dword, 0
	
	Embed unidad, modeloC
	Embed integ, IntgSim
	Embed etapas, LinkedList

	Embed steer, NovRef

	VirtualMethod Configuracion, DWORD
	VirtualMethod NuevaEtapa, DWORD, REAL8, REAL8, DWORD
	
	RedefineMethod Done

	DefineVariable minEdad, REAL8, 10000.0
	DefineVariable maxEdad, REAL8, -1000.0

ObjectEnd

Object NutritionTest,, LinkedList

	RedefineMethod Done
	
	VirtualAbstract Inicia
	VirtualAbstract Muestra
	VirtualAbstract Simulacion
	

	VirtualMethod SetAjustando, DWORD
	DefineVariable calculado, dword, NULL
	DefineVariable killcode, dword, NULL

	VirtualMethod SetControls
	
	DefineVariable control, CONTROL_INTG,{}
	DefineVariable controlr, CONTROL_INTG,{}

	DefineVariable unidades, dword, 0

	RedefineMethod Simulacion
	VirtualMethod Estabilizacion, DWORD
	
	DefineVariable minEdad, REAL8, 10000.0
	DefineVariable maxEdad, REAL8, -1000.0
	
ObjectEnd

if IMPLEMENT

Method Etapa.Done, uses esi
	SetObject esi
	.if [esi].pTrat != NULL
		Destroy [esi].pTrat 
	.endif
	ACall Done
MethodEnd

Method UnidadExperimental.Configuracion, uses esi, xordenmodelo:dword
	
	DbgText "UnidadExperimental.Configuracion"
	
	SetObject esi
	m2m [esi].orden, xordenmodelo
	DbgDec [esi].orden
	
	lea eax , [esi].unidad        ; Carga la ubicación de modeloC     
	mov [esi].integ.modelo, eax   
	OCall [esi].integ::IntgSim.Init
	
MethodEnd

Method UnidadExperimental.Done, uses esi
	
	DbgText "UnidadExperimental.Done"
	
	SetObject esi
	
	OCall [esi].integ::IntgSim.Done
	OCall [esi].unidad::modeloC.Done
	OCall [esi].etapas::LinkedList.Done
	
	ACall esi.Done

MethodEnd

Method UnidadExperimental.NuevaEtapa, uses esi eax, esInicial : DWORD, inicio:real8, duracion:real8, ptrat: dword
	
	local _edadM:REAL8
	local fSlvTLS()
	
	DbgText "Nueva etapa"
	SetObject esi
	
	DbgFloat inicio
	New Etapa
	m2m [eax].Etapa.isInitial, esInicial
	.if esInicial
	DbgText "       etapa es inicial"

		m2m [eax].Etapa.isInitial, 1	;	esInicial
		.if esInicial == 2
			OCall [esi].steer::NovRef.CalcBW1, inicio
			f2f inicio, [esi].steer.R8_r_edadC
			DbgFloat inicio
		.else
			f2f [esi].minEdad, inicio
			f2f [esi].unidad.R8_iedad , inicio
			f2f [esi].unidad.R8_edadInicial , inicio
		.endif

		f2f [eax].Etapa.inicio, inicio
		
		.if fLT(inicio, [esi].minEdad)
			f2f [esi].minEdad, inicio
			f2f [esi].unidad.R8_iedad , inicio
			f2f [esi].unidad.R8_edadInicial , inicio
		.endif
	
		fSlv8 _edadM = inicio+duracion
		.if fGT( _edadM, [esi].maxEdad)
			f2f	[esi].maxEdad, _edadM
		.endif
	.else
		fSlv8 _edadM = [esi].maxEdad + duracion
		.if fGT( _edadM, [esi].maxEdad)
			f2f	[esi].maxEdad, _edadM
		.endif
	.endif
	
	f2f [eax].Etapa.duracion, duracion
	
	fild [esi].integ.duracionEst
	fadd duracion
	fistp [esi].integ.duracionEst
	DbgDec [esi].integ.duracionEst
	
	m2m [eax].Etapa.pTrat, ptrat, ecx
	push eax
	OCall [esi].etapas::LinkedList.Append, eax	
	pop eax

	
;	test xtratamiento, 01b
;	jae @cambiaDieta 
	;mov [eax].Etapa.TipoConsumo, 1		;	Ayuno


;@cambiaDieta:
	;test xtratamiento, 010b
	;jae @tratamiento 
	


;@tratamiento:	
	 
		

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Method NutritionTest.SetAjustando, uses esi, valor : DWORD
	
	SetObject esi
	
	OCall esi.GetFirst
	.while eax != NULL
		m2m [eax].UnidadExperimental.integ.ajustando, valor	
		OCall esi.GetNext	
	.endw

MethodEnd

Method NutritionTest.SetControls, uses esi
	
	SetObject esi
	
	OCall esi.GetFirst
	.while eax != NULL
		m2m [eax].UnidadExperimental.integ.control.integracion, [esi].controlr.integracion
		f2f [eax].UnidadExperimental.integ.control.maxt, [esi].controlr.maxt
		f2f [eax].UnidadExperimental.integ.control.cint, [esi].controlr.cint
		OCall esi.GetNext	
	.endw

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

individuo macro tope, n_del_tratamiento
	
	if listadoI eq 0 	
	ifndef unidadesactivas
		unidadesactivas = 0
	else
		unidadesactivas = unidadesactivas +1
	endif
	n_en_el_tratamiento = n_en_el_tratamiento + 1
	New UnidadExperimental
	push eax
	OCall esi.Append, eax
	pop eax
	push eax
	OCall eax::UnidadExperimental.Configuracion, unidadesactivas
	pop eax 
	ifnb <n_del_tratamiento>
	push eax
	mov[eax].UnidadExperimental.unidad.ntrat, &n_del_tratamiento
	pop eax
	push eax
	mov[eax].UnidadExperimental.unidad.nentrat, n_en_el_tratamiento
	pop eax
	endif
	mov [esi].unidades, unidadesactivas
	endif	
endm

idato macro d1, c1, a1, a2, a3, a4, a5, a6, a7, a8
	if listadoI eq 1 	
		;first InStr 1, <c1>, <1>
		if @InStr(1, <c1>, <1>) eq 1
		OCall [esi].graf1::Resul04.CargaPuntoP, 0, itrat, FP8(d1&.0), FP8(&a1)
		endif
	endif
endm 
nuevaetapa macro esini, ini, dur, ptrat
	if listadoI eq 0 	
	DbgText "macro nuevaetapa" 	
	;OCall eax::UnidadExperimental.NuevaEtapa, &esini, <ini>, <dur>, &cons
	OCall eax::UnidadExperimental.NuevaEtapa, &esini, FP8(<ini>), FP8(<dur>), &ptrat
	endif
endm

nuevotratamiento macro htrat, xalimento, xconsumo, xa, xb, xc,xd 
	if listadoI eq 0
		pushad
		New Tratamiento
		mov &htrat, eax 
		lea ecx, &xalimento
		
		mov [eax].Tratamiento.alimento, ecx
		DbgDec [eax].Tratamiento.alimento
		mov [eax].Tratamiento.TipoConsumo, xconsumo
		fSlv8 [eax].Tratamiento.qa = &xa
  		popad
	endif
endm

finalizaIndividuo macro

	if listadoI eq 0 	
	.if fLT([eax].UnidadExperimental.minEdad,[esi].minEdad)
		f2f [esi].minEdad, [eax].UnidadExperimental.minEdad
		;DbgFloat [esi].minEdad
	.endif
	.if fGT([eax].UnidadExperimental.maxEdad,[esi].maxEdad)
		f2f [esi].maxEdad, [eax].UnidadExperimental.maxEdad
		;DbgFloat [esi].maxEdad
	.endif
	else
	
	endif
endm	

include BlaxterWainman.inc

include Perea16.inc

include DiMarco19.inc

Method NutritionTest.Simulacion, uses esi ebx edi
	local salida  : dword
	local counter : dword
	local igral_1 : dword
	
	DbgText "NutritionTest.Simulacion"
	
	SetObject esi
	
	mov counter, 0
	
	lea edi, TPL_Integ01.ProgressExp
	OCall edi::Progressbar.SetPos, 0
	
	OCall esi.GetFirst
	mov ebx, eax
	.while ebx != NULL
		;DbgText "Simula"
	
		inc counter
		fild 	counter
		fidiv	[esi].unidades
		fmul 	cien
		fistp	igral_1
		lea edi, TPL_Integ01.ProgressExp
		OCall edi::Progressbar.SetPos, igral_1
		
		mov salida, 0
		OCall [ebx].UnidadExperimental.etapas::LinkedList.GetFirst
		.repeat 
			.if eax == NULL
				
				mov salida , 1
				lea edi, TPL_Integ01.ProgressInd
				OCall edi::Progressbar.SetPos, 100
			.else
				
				.if [eax].Etapa.isInitial == 1
					push eax
					lea edi, TPL_Integ01.ProgressInd
					OCall edi::Progressbar.SetPos, 0
					mov [ebx].UnidadExperimental.integ.inicioEst, 0
					pop eax

					DbgText "Etapa es inicial" 
				
					fld [eax].Etapa.inicio
					fstp [ebx].UnidadExperimental.integ.control.inicio
					fld [eax].Etapa.duracion
					fstp [ebx].UnidadExperimental.integ.control.duracion
					if 1
					mov [ebx].UnidadExperimental.integ.control.isInitial, 1
					else
					; Estabilización inicial
					mov [ebx].UnidadExperimental.integ.control.isInitial, 2
					push eax
					pushad
					OCall [ebx].UnidadExperimental.integ::IntgSim.SimCircle, 0
					popad
					pop eax
					;ret
					endif 
				.else	
					push eax
					DbgText "Etapa no es inicial" 
				
					fld [ebx].UnidadExperimental.integ.control.final
					fist [ebx].UnidadExperimental.integ.inicioEst
					fstp [ebx].UnidadExperimental.integ.control.inicio
					fld [eax].Etapa.duracion
					fstp [ebx].UnidadExperimental.integ.control.duracion
					mov [ebx].UnidadExperimental.integ.control.isInitial, 0
					pop eax
				.endif
				
				
				mov ecx, [eax].Etapa.pTrat
				.if ecx != NULL
					.if [ecx].Tratamiento.alimento != NULL
						pushad
						push ecx
						;lea edx, dietaJenkins
						lea eax, [ebx].UnidadExperimental.unidad.Feed
						pop ecx
						push eax
						
						CopiaObjeto	$Obj(MollyDiet), <eax>, [ecx].Tratamiento.alimento;ptrat
						
						fSlv8 [ebx].UnidadExperimental.unidad.Feed.OM = 1.0-[ebx].UnidadExperimental.unidad.Feed._Ai-[ebx].UnidadExperimental.unidad.Feed.As;
;
						pop eax
				;%		DbgObject [eax]::MollyDiet
						popad
					.endif	
				.endif

				if 0
					push edx
					mov ecx , [edx].Tratamiento.TipoConsumo
					
					mov [ebx].UnidadExperimental.unidad.DD35_ayuno, 1;ecx
					;DbgBin [eax].Etapa.tratamiento 
					;int 3
					pop edx
					.if [edx].Tratamiento.alimento != NULL
					;	mov edx, [edx].Tratamiento.alimento
					;	DbgText "si Cambia la dieta"
					;	lea ecx, [ebx].UnidadExperimental.unidad.Feed
					;	CopiaObjeto	$MollyDiet, <ecx>, <edx>
					.endif
				.else
				mov [xbx].UnidadExperimental.unidad.DD35_ayuno, 1;ecx
				.endif 	
				endif
			.endif
			;DbgObject [ebx].UnidadExperimental.unidad::modeloC
			DbgFloat [xbx].UnidadExperimental.unidad.R8_ebw
			
			OCall [xbx].UnidadExperimental.integ::IntgSim.Sim
			OCall [xbx].UnidadExperimental.etapas::LinkedList.GetNext
			;mov eax, 0
			.if xax == NULL
				mov salida , 1
				lea xdi, TPL_Integ01.ProgressInd
				OCall xdi::Progressbar.SetPos, 100
			.endif
		.until salida == 1
		OCall xsi.GetNext
		mov xbx, xax
	.endw
	
MethodEnd

Method NutritionTest.Estabilizacion, uses esi ebx edi, modalidad : dword
	local salida  : dword
	local counter : dword
	local igral_1 : dword
	
	DbgText "NutritionTest.Estabilizacion"
	
	SetObject esi
	
	mov counter, 0
	
	;lea edi, TPL_Integ01.ProgressExp
	;OCall edi::Progressbar.SetPos, 0
	
	OCall esi.GetFirst
	mov ebx, eax
	.while ebx != NULL
		;DbgText "Simula"
	
		inc counter
		fild 	counter
		fidiv	[esi].unidades
		fmul 	cien
		fistp	igral_1
		lea edi, TPL_Integ01.ProgressExp
		OCall edi::Progressbar.SetPos, igral_1
		
		mov salida, 0
		OCall [ebx].UnidadExperimental.etapas::LinkedList.GetFirst
		.repeat 
			.if eax == NULL
				mov salida , 1
				lea edi, TPL_Integ01.ProgressInd
				;OCall edi::Progressbar.SetPos, 100
			.else
				.if [eax].Etapa.isInitial == 1
					push eax
					lea edi, TPL_Integ01.ProgressInd
					OCall edi::Progressbar.SetPos, 0
					mov [ebx].UnidadExperimental.integ.inicioEst, 0
					pop eax

					DbgText "Etapa es inicial" 
					fld [eax].Etapa.inicio
					fstp [ebx].UnidadExperimental.integ.control.inicio
					fld [eax].Etapa.duracion
					fstp [ebx].UnidadExperimental.integ.control.duracion
					if 1
					mov [ebx].UnidadExperimental.integ.control.isInitial, 1
					else
					; Estabilización inicial
					mov [ebx].UnidadExperimental.integ.control.isInitial, 2
					push eax
					pushad
					OCall [ebx].UnidadExperimental.integ::IntgSim.SimCircle, modalidad

					popad
					pop eax
					;ret
					endif 
				.endif
				
				mov edx, [eax].Etapa.pTrat
				.if edx != NULL
					push edx
					mov ecx , [edx].Tratamiento.TipoConsumo
					
					mov [ebx].UnidadExperimental.unidad.DD35_ayuno, ecx
					;DbgBin [eax].Etapa.tratamiento 
					;int 3
					pop edx
					.if [edx].Tratamiento.alimento != NULL
						mov edx, [edx].Tratamiento.alimento
						DbgText "si Cambia la dieta"
						lea ecx, [ebx].UnidadExperimental.unidad.Feed
						CopiaObjeto	$MollyDiet, <ecx>, <edx>
					.endif
				.endif 	
			.endif
			;DbgObject [ebx].UnidadExperimental.unidad::modeloC
			;DbgFloat [ebx].UnidadExperimental.unidad.R8_ebw
			
			;OCall [ebx].UnidadExperimental.integ::IntgSim.Sim
			OCall [ebx].UnidadExperimental.etapas::LinkedList.GetNext
			;mov eax, 0
			.if eax == NULL
				mov salida , 1
			;	lea edi, TPL_Integ01.ProgressInd
			;	OCall edi::Progressbar.SetPos, 100
			.endif
		.until salida == 1
		OCall esi.GetNext
		mov ebx, eax
	.endw
	
MethodEnd
Method NutritionTest.Done, uses esi ebx
	SetObject esi
	OCall esi.GetFirst
	mov ebx, eax
	.while ebx != NULL
		;OCall ebx::UnidadExperimental.Done
		OCall esi.GetNext
		mov ebx, eax
	.endw
	ACall esi.Done
MethodEnd

endif