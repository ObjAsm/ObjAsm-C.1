; ==================================================================================================
; Title:   UnidadExperimental.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

isThread equ 1
isConsole equ 1

Object Etapa,, Primer
	RedefineMethod Done
	DefineVariable isInitial, xword, 0
	DefineVariable inicio, real8, 0.0
	DefineVariable duracion, real8, 0.0 
ObjectEnd

Object UnidadExperimental,, Primer
	VirtualMethod  Run
	RedefineMethod Done
	DefineVariable orden, xword, 0
	
	DefineVariable unidad, $ObjPtr(modeloB), NULL
	Embed integ, IntgSim
	Embed etapas, LinkedList

	VirtualMethod Configuracion, xword
	VirtualMethod NuevaEtapa, xword, REAL8, REAL8;, xword Acá no hay tratamiento

	DefineVariable xmin, REAL8, 10000.0
	DefineVariable xmax, REAL8, -1000.0
	
	DefineVariable running, xword, 0
	if isConsole
	    DefineVariable hConsole
	endif
ObjectEnd

if IMPLEMENT

individuo macro elmodelo
    if @WordSize eq 8
    ;lea xcx, nombreM
    ;call StdOut
    endif
	%echo individuo elmodelo
	ifndef unidadesactivas
		unidadesactivas = 0
	else
	    unidadesactivas = unidadesactivas + 1
	endif

	New UnidadExperimental
	mov last_unidad, xax
	;DbgHex xax, " es la unidad"
	
	New &elmodelo
	;DbgHex xax, " es el modelo"
	mov xdx, last_unidad
    ;DbgHex xcx, " es la unidad ap"
	mov [xdx].$Obj(UnidadExperimental).unidad, xax
    ;DbgHex xcx, " es la unidad ap"
	OCall xsi.Append, xdx

	mov _ecx, last_unidad
	OCall _ecx::UnidadExperimental.Configuracion, unidadesactivas
	mov [xsi].unidades, unidadesactivas
	;DbgText "hasta acá"
endm


nuevaetapa macro esini, ini, dur, ptrat

    ;%echo nuevaetapa  esini, ini, dur, ptrat
    ;DbgText " nuevaetapa"
    
    mov _ecx, last_unidad
    ;OCall xax::UnidadExperimental.NuevaEtapa, &esini, <ini>, <dur>, &cons
    OCall _ecx::UnidadExperimental.NuevaEtapa, &esini, FP8(<ini>), FP8(<dur>)
endm

finalizaIndividuo macro

	.if fLT([xax].UnidadExperimental.minEdad,[xsi].minEdad)
		f2f [xsi].minEdad, [xax].UnidadExperimental.minEdad
		;DbgFloat [xsi].minEdad
	.endif
	
	.if fGT([xax].UnidadExperimental.maxEdad,[xsi].maxEdad)
		f2f [xsi].maxEdad, [xax].UnidadExperimental.maxEdad
		;DbgFloat [xsi].maxEdad
	.endif
endm	

if IMPLEMENT

Method Etapa.Done, uses xsi
	SetObject xsi
	;.if [xsi].pTrat != NULL
	;	Destroy [xsi].pTrat 
	;.endif
	ACall Done
MethodEnd

Method UnidadExperimental.Configuracion, uses xsi, xordenmodelo:xword
	
	DbgText "+UnidadExperimental.Configuracion"
	
	SetObject xsi
    
	m2m [xsi].orden, xordenmodelo, @if64bits(r13)
	;DbgDec [xsi].orden
	
	mov xax , [xsi].unidad        ; Carga la ubicación de modeloB  
	;DbgHex [xsi].unidad
	
	
	mov [xsi].integ.modelo, xax   
	
	OCall [xsi].integ::IntgSim.Init
    ;DbgObject [xsi].integ::IntgSim 	
	DbgText "-UnidadExperimental.Configuracion"
MethodEnd

Method UnidadExperimental.Run, uses xsi
    local salida:xword
    local fregTLS()
    if @WordSize eq 8
        local dgral1:dword
    endif     
        
    DbgText "UnidadExperimental.Run" 
       
    SetObject xsi;, UnidadExperimental, xbx

	CStr UE_run$,"+UnidadExperimental.Run",13,10
    ;mov rcx,pConsole
    ;invoke [rcx].ConOut.OutputString, rcx, ADDR UE_run$


    mov salida, 0
	OCall [xsi].etapas::LinkedList.GetFirst
	.repeat 
			.if xax != NULL
				
				.if [xax].$Obj(Etapa).isInitial == 1
					freg_push xax
					mov [xsi].integ.initial, TRUE
					mov [xsi].integ.inicioEst, 0
					freg_pop xax
					DbgText "Etapa es inicial" 
		            
					fld [xax].$Obj(Etapa).inicio
					;fst x
					fstp [xsi].integ.control.inicio
					fld [xax].$Obj(Etapa).duracion
					fstp [xsi].integ.control.duracion
					if 1
    					mov [xsi].integ.control.isInitial, 1
					else
						; Estabilización inicial
						mov [xsi].integ.control.isInitial, 2
						freg_push xax
						pushad
						OCall [xsi].integ::IntgSim.SimCircle, 0
						popad
						freg_pop xax
						;ret
					endif
 
				.else	
					freg_push xax
					DbgText "Etapa no es inicial" 
					mov [xsi].integ.initial, FALSE
				
					fld [xsi].integ.control.final
					if @WordSize eq 4
					    fist [xsi].integ.inicioEst
					else
					    freg_push xax
					    fist dgral1
					    xor rax,rax
					    mov eax, dgral1
					    mov [xsi].integ.inicioEst, rax
					    freg_pop xax 
					endif    
					fstp [xsi].integ.control.inicio
					fld [xax].$Obj(Etapa).duracion
					fstp [xsi].integ.control.duracion
					mov [xsi].integ.control.isInitial, 0
					freg_pop xax
				.endif
				
			.endif
			;DbgObject [xsi].UnidadExperimental.unidad::modeloC
			;lea xax, [xsi].integ
			;OCall xax::IntgSim.Sim
			OCall [xsi].integ::IntgSim.Sim
			OCall [xsi].etapas::LinkedList.GetNext
			.if !xax
			    mov salida, 1
			.endif
		.until salida == 1

	mov [xsi].running, 0
	
	;if isThread
	;    invoke ExitThread, 0
	;endif

MethodEnd
Method UnidadExperimental.Done, uses xsi
	
	SetObject xsi
	
	OCall [xsi].integ::IntgSim.Done
	Destroy [xsi].unidad
	OCall [xsi].etapas::LinkedList.Done
	
	ACall xsi.Done

MethodEnd

Method UnidadExperimental.NuevaEtapa, uses xsi xax, esInicial : xword, inicio:real8, duracion:real8
	
	local _edadM:REAL8
	local fSlvTLS()
	;local fregTLS()

   
	DbgText "+UnidadExperimental.NuevaEtapa"
	SetObject xsi
	
	DbgFloat inicio
	New Etapa
	;DbgHex xax, " nueva etapa"
	m2m [xax].$Obj(Etapa).isInitial, esInicial, @if64bits(r13)
	.if esInicial
    	DbgText "       etapa es inicial"
		mov [xax].$Obj(Etapa).isInitial, 1	;	esInicial
		f2f [xsi].xmin, inicio
		f2f [xax].$Obj(Etapa).inicio, inicio
		mov [xsi].integ.duracionEst, 0
	.endif
	
	f2f [xax].$Obj(Etapa).duracion, duracion
	
	fild [xsi].integ.duracionEst
	fadd duracion
	fistp [xsi].integ.duracionEst
	;DbgDec [xsi].integ.duracionEst
	
	;DbgHex xax, " nueva etapa"
	OCall [xsi].etapas::LinkedList.Append, xax	
	;freg_pop xax
	
;	test xtratamiento, 01b
;	jae @cambiaDieta 
	;mov [xax].Etapa.TipoConsumo, 1		;	Ayuno


;@cambiaDieta:
	;test xtratamiento, 010b
	;jae @tratamiento 
	


;@tratamiento:	
	 
		
	DbgText "-UnidadExperimental.NuevaEtapa"

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

endif