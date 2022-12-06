; ==================================================================================================
; Title:   IntgSim_PROC.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose:  Object procedures - IntegAsm32 Light
; ==================================================================================================

topebucle equ nestados - 1
Method IntgSim.Init , uses xsi
		
	SetObject xsi
	
	mov [xsi].acum, $New(LinkedList) ; Datos de cada paso
	if ModAccesorio GT 0
	;	mov [xsi].auxiliar, $New(modeloC)
	endif

MethodEnd

Method IntgSim.Done , uses xsi
	local v1:xword, v2:xword
	
	;DbgText "desarma IntgSim"
	SetObject xsi
	
	OCall [xsi].acum::LinkedList.Done
	Destroy [xsi].acum
	;DbgText "va a destriui" 
	if ModAccesorio GT 0
		;Destroy [xsi].modelo[(Instancias_del_modelo+ModAccesorio)*4]
	;	Destroy [xsi].auxiliar
	endif
	ACall Done
MethodEnd


.data
;	topemaxt	qword 500.0
	contador 	xword 0
	mil			qword 1000.0
.code

Method IntgSim.Sim, uses xsi xbx
	local MaxtV : qword
	local reltol : REAL8 , abstol : REAL8
	local v1 : xword
	local x : REAL8
	local limite : xword
	
	local comunicado : xword
	local vk : xword
	local parar : xword

	local fSlvTLS()
	
    SetObject xsi

    mov IntegRun, xsi

    fld		[xsi].control.maxt
    fstp	MaxtV
		fld		[xsi].control.cint
		fstp	[xsi].cint

		mov [xsi].nequ , nestados
		;DbgDec [xsi].nequ
		
		.if [xsi].control.isInitial
			OCall [xsi].acum::LinkedList.Clear
			mov [xsi].acumInt, 0
			.if [xsi].control.isInitial == 1
				OCall xsi.Iniciamodelo
			.endif
		.endif
		
		;DbgText "modelo iniciado"
			
		;DbgFloat [xsi].integrales[xax*8+0*8] 
		;z.Area2.etapasg[tanda] = 0;

	;DbgDec [xsi].modelo.fd.sizeO

		fld		[xsi].control.inicio
		fadd	[xsi].control.duracion
		fstp	[xsi].control.final
;		DbgFloat [xsi].control.final
		
 		;mov 	[xsi].paso , 1;
	
	
		;mov xax, [xsi].modelo
		;assume xax: ptr modeloC 
		;DbgFloat  [xax].R8_TIME
		;DbgFloat [xsi].control.inicio
		;DbgFloat [xsi].control.duracion
		;DbgFloat [xsi].control.final
		;assume xax:nothing
	
		AbreEstadisticas statVariables
		
		.if [xsi].ajustando == FALSE
			if MuestraContador
				invoke SendMessage, hCbar, WM_COMMAND, PBM_RESET, 0 ; step up the progress in the progress bar
			endif  
;			counter_begin 1, HIGH_PRIORITY_CLASS
		.endif
		DbgFloat [xsi].control.CONTROL_INTG.cint
		DbgFloat [xsi].control.CONTROL_INTG.maxt
		lea xcx, [xsi].control
		.if faEQ([xcx].CONTROL_INTG.cint,[xcx].CONTROL_INTG.maxt, 0.00001) 
			DbgText "cint=maxt"
			jmp cint0
		.endif

		.if fGT([xcx].CONTROL_INTG.cint,[xcx].CONTROL_INTG.maxt) 

			mov [xsi].CINTactivado, TRUE
			;DbgDec [xsi].CINTactivado
		
			.if [xsi].ajustando == FALSE
				mov comunicado , 0
				mov xbx , [xsi].modelo
				.if [xcx].CONTROL_INTG.isInitial
				    m2m [xsi].cargaacus.etapa, comunicado, xax
				    f2f [xsi].cargaacus.x1, cero
    				OCall xsi.CargaAcu
				.endif 
			.endif
			mov parar, 0
			mov xax , [xsi].modelo
			fldz
			assume xax : $ObjPtr(modeloC)
			fst REAL8 ptr [xax].R8_TIME
			assume xax : nothing
			fstp x
			
			.repeat
                ;UseConsole "Sin step wait"


                ;UseConsole "Sin step run"

				.if [xsi].control.integracion == 0
		
					OCall xsi.timestep, cero, [xsi].control.CONTROL_INTG.cint , MaxtV
				
				.elseif [xsi].control.integracion == 1
					
					OCall xsi.RK4, cero, [xsi].control.CONTROL_INTG.cint , MaxtV
				
				.elseif [xsi].control.integracion == 2
					
					fSlv8 reltol = 0.0001
					fSlv8 abstol = 0.001
					OCall xsi.Fehlberg, cero, [xsi].control.CONTROL_INTG.cint , MaxtV, 2, reltol, abstol 
		
				.elseif [xsi].control.integracion == 3
					
					fSlv8 reltol = 0.0001
					fSlv8 abstol = 0.001
					OCall xsi.CashKarpI, 0, cero, [xsi].control.CONTROL_INTG.cint , MaxtV, 2, reltol, abstol 
				.endif
				inc comunicado
				fld		x
				fadd 	[xsi].control.CONTROL_INTG.cint
				fstp	x
				;fcomp [xsi].control.CONTROL_INTG.duracion
				;.if ax == FP_LESSTHAN
				;DbgFloat x
				.if fGT(x, [xsi].control.duracion)
				;.else	
					f2f x, [xsi].control.duracion
					mov parar, 1
				.endif
				;DbgFloat x
				;DbgDec parar
				.if [xsi].ajustando == FALSE
					mov	xbx , [xsi].modelo
					
					assume xbx: ptr $Obj(modeloB)
					.if fLE(x,[xbx].limite )
					assume xbx: nothing
					    m2m [xsi].cargaacus.etapa, [xsi].paso, xax
    				    f2f [xsi].cargaacus.x1, x
					.endif
				.endif
				OCall xsi.Resultado, x
			.until parar == 1
	
		.else
cint0:
			mov [xsi].CINTactivado, FALSE
		;	DbgDec [xsi].CINTactivado
			.if [xsi].control.integracion == 0
		
				OCall xsi.timestep, cero, [xsi].control.CONTROL_INTG.duracion , MaxtV
			
			.elseif [xsi].control.integracion == 1
				
				OCall xsi.RK4, cero, [xsi].control.CONTROL_INTG.duracion , MaxtV
			
			.elseif [xsi].control.integracion == 2
				
				fSlv8 reltol = 0.0001
				fSlv8 abstol = 0.001
				OCall xsi.Fehlberg, cero, [xsi].control.CONTROL_INTG.duracion , MaxtV, 2, reltol, abstol 
	
			.elseif [xsi].control.integracion == 3
				
				fSlv8 reltol = 0.0001
				fSlv8 abstol = 0.001
				OCall xsi.CashKarpI, 0, cero, [xsi].control.CONTROL_INTG.duracion , MaxtV, 2, reltol, abstol 
			.endif
		.endif

		if 1
			.if [xsi].ajustando == FALSE 
				;timer_end
;				counter_end
				mov	[xsi].counter , xax
		
				.if xax > 10000000
					mov	[xsi].counterT, 2
					fild [xsi].counter
					fdiv mil
					fdiv mil
					fistp [xsi].counter
				.elseif xax > 10000
					mov	[xsi].counterT, 1
					fild [xsi].counter
					fdiv mil
					fistp [xsi].counter
				.else	
					mov	[xsi].counterT, 0
				.endif
			.endif
		endif
		mov	[xsi].calculado, TRUE
	
		CierraEstadisticas statVariables		

MethodEnd

; Pasa el reultado de la integración a las variables de estado

Method IntgSim.CargaVector, uses xsi xdx xbx
    local fregTLS()
    
	assume xbx : ptr $Obj(modeloC)
	SetObject xsi

;	DbgText "CaragaVector"
	
	mov	xbx , [xsi].modelo
	;DbgDec xbx	
	mov	xcx , topebucle
iniloop1:
	if estadotriple
	;	DbgDec xcx
		imul	xax , xcx, 3 
		freg_push 	xcx
	
		f2f [xbx].firststate[xax*8] , [xsi].integrales[xcx*8]
		freg_pop xcx
	else
		mov		xax , xcx
		freg_push 	xcx
	
		f2f [xbx].R8_edad[xax*8] , [xsi].integrales[xcx*8]
		freg_pop	xcx
	endif
	dec xcx
	jnl iniloop1

        assume xbx : NOTHING
MethodEnd
;04/12/17
if 0; RealizaEstabilizacion
cargacircle macro var1
	
;%	DbgDec orden_d&var1
	;%echo ar es var1
	mov	xcx, orden_d&var1
	xor xdx, xdx

    fld		[xbx].zv[xcx*8]			; del modelo
    fmul	[xsi].control.maxt
    fst		[xsi].derivadas[xcx*8]	; del integrador
    fadd	[xsi].integrales[xcx*8]
    fstp	[xsi].integrales[xcx*8]		

	if estadotriple
		imul	xax , xcx, 3 
		
		f2f [xbx].firststate[xax*8] , [xsi].integrales[xcx*8]
	else
		mov		xax , xcx
		f2f [xbx].R8_edad[xax*8] , [xsi].integrales[xcx*8]
	endif

endm
cargacircla macro var1
	
	;%echo ar es var1
	mov	xcx, &var1
	xor xdx, xdx
	if estadotriple
		imul	xax , xcx, 3 
		freg_push 	xbx
		mov 	xbx, vk
		imul	xbx, neqqu
		add		xcx , xbx
		freg_pop		xbx	
		f2f [xbx].firststate[xax*8] , [xsi].integrales[xcx*8]
	else
		mov		xax , xcx
		freg_push 	xbx
		mov 	xbx, vk
		imul	xbx, neqqu
		add		xcx , xbx
		freg_pop xbx	
		f2f [xbx].R8_edad[xax*8] , [xsi].integrales[xcx*8]
	endif

endm

Method IntgSim.CargaCircle, uses xsi xdx xbx
	
	assume xbx : ptr $Obj(modeloC)
	
	;DbgText "IntgSim.CargaCircle"
	
	SetObject xsi

	;ifdef _Actualiza
		mov	xbx , [xsi].modelo	
		_Actualiza 0
	;endif

    assume xbx : NOTHING
MethodEnd
endif		
cargaElemental macro
	if estadotriple
		multipl equ	3
	else
		multipl equ 1
	endif
	;int 3	
	;fld [xdx].R8_edad
	nccest = 0
	REPEAT nestados
		% f2f @CatStr([xbx].R8_estado,%nccest),[xdx].R8_edad[nccest*multipl*8]
		nccest = nccest+1
	endm
	ife SoloEstados
		nccest = 0	
		REPEAT nestados
			% f2f @CatStr([xbx].R8_destado,%nccest),[xdx].R8_dedad[nccest*multipl*8]
			nccest = nccest+1
		endm
		nccest = 0	
		REPEAT vetados
			%echo f2f @CatStr([xbx].R8_variable,%nccest),@CatStr([xdx].%@CatStr(varElemental,%nccest))
			% f2f @CatStr([xbx].R8_variable,%nccest), @CatStr([xdx].%@CatStr(varElemental,%nccest))
			nccest = nccest+1
		endm
	endif

endm		

; Crea un nuevo acumulador de reusltados y le carga 
; valores de variables  de estado y variables pseudointegradas

Method IntgSim.CargaAcu, uses xsi xbx 
    local etapa:xword, x1:REAL8	
    local i : xword
    local fSlvTLS(,24)
    local vuelto : real8
    local igral_1: xword
    local fregTLS(,8*8)
    if @WordSize eq 8
        local dgral1:dword
    endif	
	
    assume xdx : ptr $Obj(modeloC)
    SetObject xsi

    fSlv etapa = [xsi].cargaacus.etapa
    fSlv x1    = [xsi].cargaacus.x1;

    New ACUo
    SetObject xbx, ACUo, xax
			
    mov xdx , [xsi].modelo
	
    mov xcx , [xsi].acumInt 	
    .if xcx == NULL
        mov		[xbx].previo, NULL
    .else
        mov		[xbx].previo, xcx
    .endif
		
    f2f [xbx].h, [xsi].h
    f2f [xbx].cint, [xsi].control.CONTROL_INTG.cint
    ;	básico
    fSlv [xbx].etapa = [xsi].cargaacus.etapa
    fSlv [xbx].x 	 = [xsi].cargaacus.x1;

	
    if MuestraElemental
        cargaElemental			
    else
        _AcumulaDatos
    endif

    OCall [xsi].acum::LinkedList.Append, xbx
	
    mov [xsi].acumInt, xbx
    ;.endif
    
    ;DbgFloat x1
    fld 	x1
    if @WordSize eq 4
        fisub   [xsi].inicioEst
    else
        mov     rax,[xsi].inicioEst
        mov     dgral1, eax
        fisub	dgral1
    endif
    fdiv    [xsi].control.duracion;Est
    fmul    cien
    fistp   igral_1
	
    freg_pushad
	
    if MuestraProgress
		% lea xdi, $ObjTmpl(Integ01).ProgressInd
		OCall xdi::Progressbar.SetPos, igral_1
	endif
	;mov xcx, [xsi].parent

	if MuestraContador
		if ControlFearless
		    invoke SendMessage, hCbar, CBM_SET_PROGRESSVALUE, igral1, 0
		else
			invoke SendMessage, hCbar, WM_COMMAND, CBM_SETPOS, igral1 ; step up the progress in the progress bar  
	    endif
	    ;invoke UpdateWindow, hCbar
    	invoke GetParent, hCbar
    	invoke SetFocus, xax
	endif
	freg_popad
 
	assume xdx : NOTHING
MethodEnd

;*=======================================================================
IFE SoloEstados 

	Method IntgSim.CargaDerivada, uses xsi xbx
		local v1 : xword
		local fregTLS()
			
		assume xbx : ptr $Obj(modeloC)
		SetObject xsi
	
	;	DbgText "CargaDerivada"
		; Este paso es ineficiente
		; Solamente se realiza para mantener la claridad si se quieren mostrar derivadas
		;mov
		mov xbx , [xsi].modelo
		mov xcx , topebucle
	iniloop3:

	if estadotriple
		imul	xax , xcx, 3 
		freg_push 	xcx
	
;		f2f [xbx].firststate[xax*8] , [xsi].integrales[xcx*8]
		f2f [xbx].firstderivate[xax*8] , [xsi].derivadas[xcx*8]
		freg_pop xcx
	else
		mov		xax , xcx
		freg_push 	xcx
		freg_push 	xbx

		mov 	xbx, v1
		imul	xbx, neqqu
		add		xcx , xbx
			
		freg_pop 		xbx 
	
		;f2f [xbx].R8_edad[xax*8] , [xsi].integrales[xcx*8]
		f2f [xbx].R8_dedad[xax*8] , [xsi].derivadas[xcx*8]
		freg_pop	xcx
	endif
		dec xcx
		jnl iniloop3
		assume xbx : NOTHING  
	MethodEnd
	
	Method IntgSim.LevantaVariables , uses xsi xbx, num:xword
		local v1 : xword
			
		SetObject xsi

		assume xbx : ptr $Obj(modeloC)
		mov xbx , [xsi].modelo
		if MuestraElemental
			neccst = 0
			repeat vetados
				f2f	  [xsi]._mm_[%neccst*8], @CatStr(<[xbx].>,varElemental,%neccst) 
				neccst= neccst + 1
			endm
		else
			mov	xax , num
			mov	xcx , nvvar
			mul	xcx
			mov	xcx,  xax
			_levantaVariables
		endif  
		assume xbx : NOTHING
	MethodEnd
	
	Method IntgSim.CargaVariables , uses xsi xbx
		local v1 : xword
		
		SetObject xsi

		assume xbx : ptr $Obj(modeloC)
		mov xbx , [xsi].modelo
		if MuestraElemental
			neccst = 0
			repeat vetados
				f2f	 @CatStr(<[xbx].>,varElemental,%neccst) , [xsi]._mm_[%neccst*8]
				neccst= neccst + 1
			endm
		else	
			_cargaVariables
		endif  
		assume xbx : NOTHING
	MethodEnd

ENDIF
;=============================================================================

Method IntgSim.Asignamodelo
	
	SetObject xsi
	
	;DbgText "Asignamodeloes"
		
		;SetObject xbx, modeloModelo2, [xsi].modelo
		
    	;mov		[xbx].pOwner, xsi

		;f2f [xbx].edadInicial ,[xsi].controlr.inicio
					
		
MethodEnd


Method IntgSim.Iniciamodelo , uses xsi xbx
	local inif:REAL8
	local	v1 : xword
	local fregTLS()

	SetObject xsi
		
		;OCall xsi.Asignamodelo
		
		assume xbx : ptr $Obj(modeloC)
		mov xbx, [xsi].modelo
		mov [xbx].iniciado, FALSE


	ifdef _preinitial 
	;	_preinitial
	endif
	
	OCall [xsi].modelo::modeloC.inicia
	
	DbgText "Inicia el modelo"
	
		mov xcx, topebucle
		mov xbx , [xsi].modelo
				
	iniloop2:
		if estadotriple
			imul xax, xcx, 3
			freg_push xcx

			;DbgFloat [xbx].firstinitial[xax*8]
			fld	 [xbx].firstinitial[xax*8]
			fst  [xsi].integrales[xcx*8]
			fstp [xbx].firststate[xax*8]; , [xbx].firstinitial[xax*8]

			freg_pop	xcx 

		else
			mov		xax , xcx
			freg_push 	xcx
			freg_push 	xbx

			mov 	xbx, v1
			imul	xbx, neqqu
			add		xcx , xbx
			
			freg_pop xbx 
			f2f [xsi].integrales[xcx*8], [xbx].R8_iedad[xax*8]
			;%echo f2f	[xsi].%firststate[xcx*8] , [xbx].R8_iedad[xax*8]

			f2f	[xbx].firststate[xcx*8] , [xbx].R8_iedad[xax*8]
			DbgFloat [xbx].R8_iedad[xax*8]
			freg_pop	xcx
		endif 
;		DbgFloat [xsi].integrales[xcx*8]
		dec	xcx
		
		jnl iniloop2
	
		OCall xbx::modeloC.zzCalcula
	
	;OCall xsi.Tratamiento, [xsi].controlr.inicio

	;ifdef pretraitment_exist 
	ifdef _pretraitment 
	mov	xbx , xmodelo
	_pretraitment
	endif
;	DbgText  "Iniciado"
	assume xbx : NOTHING

MethodEnd

Method IntgSim.Tratamiento, uses xsi, time : REAL8

	local v1 : xword
	local v2 : xword
	
	local bucle_max : REAL8
	local bucle_min : REAL8
	local bucle_val : REAL8
	local varia1: REAL8
	
	local fSlvTLS()
	
	local cuenta : xword 
	
	SetObject xsi
	
	assume xbx : ptr $Obj(modeloC)
	fSlv v2 = rndint(time) {i4}

	if 0	
	cvttss2si    xbx,    guar1
	mov          xax,    guar1
	shr          xax,    31
	sub          xbx ,   xax
	cvtsi2ss     xmm0,   xbx
	mov v2, xbx
	endif
	;echo _haytratamiento
	ifdef _traitment;_haytratamiento
		;echo Si hay tratamiento
		_traitment
	endif
	;ç
	assume xbx: nothing 
MethodEnd
 

Method IntgSim.Resultado, uses xsi, time : REAL8

	local v1 : xword
	local v2 : xword
	
	local varia1: REAL8
	
	local fSlvTLS(,2048)
	
	SetObject xsi
	
	assume xbx : ptr modeloC
	
	fSlv v2 = rndint(time) {i4}
	
	if HaceEstadisticas
	;	if MODELO EQ SAINZ
	;		_EstadisticaSainz
	;	endif
	endif
	assume xbx : nothing
MethodEnd
; 04/12/17
Method IntgSim.SimCircle, uses xsi xbx, modalidad :xword
	local MaxtV : qword
	local reltol : REAL8 , abstol : REAL8
	local v1 : xword
	local fSlvTLS()	

	SetObject xsi
if 0

	;fSlvSetPrecision <@fSlv8>, REAL8,
	DbgText "Entra en Sim Circle"
	    
		;mov [xsi].CINTactivado, TRUE

		;if IntegUsual
			mov [xsi].ajustando, TRUE
		;else
		;	OCall [xsi].TestBW::NutritionTest.SetAjustando, FALSE
		;endif	
		OCall [xsi].acum::LinkedList.Clear
        echo ---------------------
    %    echo @CatStr(nestados)
        echo ---------------------
         
		mov [xsi].nequ , nestados-1
		
		OCall xsi.Iniciamodelo
		
		.if [xsi].ajustando == FALSE
;			counter_begin 1, HIGH_PRIORITY_CLASS
		.endif

		mov xax, [xsi].modelo
	%	mov [xax].$Obj(modeloB).DD35_estabilizando, 1
		OCall xsi.circletime, 0, 10000*90, [xsi].control.inicio, @fSlv8(0.0001), modalidad
		mov xax, [xsi].modelo
	%	mov [xax].$Obj(modeloB).DD35_estabilizando, 0
		
		;mov xax, [xsi].modelo
		;assume xax: ptr modeloC 
		;DbgFloat  [xax].R8_TIME
		;DbgFloat [xsi].control.inicio
		;DbgFloat [xsi].control.duracion
		;DbgFloat [xsi].control.final
		;assume xax:nothing
		
		.if [xsi].ajustando == FALSE 
			;timer_end
		;	comment Ç
;			counter_end
			mov	[xsi].counter , xax
	
			.if xax > 10000000
				mov	[xsi].counterT, 2
				fild [xsi].counter
				fdiv mil
				fdiv mil
				fistp [xsi].counter
			.elseif xax > 10000
				mov	[xsi].counterT, 1
				fild [xsi].counter
				fdiv mil
				fistp [xsi].counter
			.else	
				mov	[xsi].counterT, 0
			.endif
		.endif
endif
			mov [xsi].ajustando, FALSE

MethodEnd

if 0
Method IntgSim.Summary, uses xsi xbx, tela : xword
	local vk : xword
	local v1 : xword
	local buffer[32] : CHR
	
	SetObject xsi
	
	;------------------------------------
	;	Calcula
	;-------------------------------------
	ForLp v1, 0, statVariables
		fldz	
		fst [xsi].msep[xax*8]
		fst [xsi].ect[xax*8]
		fst [xsi].er[xax*8]
		fstp [xsi]._ed[xax*8]
	Next v1
		
	ForLp vk, 0 , [xsi].instancias
		;assume xbx: ptr ModeloC
		mov xcx, xax
		ForLp v1, 0, statVariables
		mov xbx, [xsi].modelo[xcx*4]
		;DbgDec v1	
			fld		[xsi].msep[xax*8]
			lea 	xdx , [xbx].modeloB.statLineal
			fadd	[xdx].StatLin.msep1[xax*8]
			fstp	[xsi].msep[xax*8]
				
			fld		[xsi].ect[xax*8]
			lea 	xdx , [xbx].modeloB.statLineal
			fld		[xdx].StatLin.ect[xax*8]
			fidiv	[xsi].instancias
			fadd   
			fstp	[xsi].ect[xax*8]
				
			fld		[xsi].er[xax*8]
			lea 	xdx , [xbx].modeloB.statLineal
			fld		[xdx].StatLin.er[xax*8]
			fidiv	[xsi].instancias
			fadd   
			fstp	[xsi].er[xax*8]
				
			fld		[xsi]._ed[xax*8]
			lea 	xdx , [xbx].modeloB.statLineal
			fld		[xdx].StatLin._ed[xax*8]
			fidiv	[xsi].instancias
			fadd   
			fstp	[xsi]._ed[xax*8]
		Next v1		
		;assume xbx: nothing
	Next vk
	;----------------------------------------------
	;	Textos
	;----------------------------------------------
	ForLp v1, 1, statVariables
		f4real8$ [xsi].msep[xax*8];, f:%8.2f
		Text_crm tela, space$, buffer;real8$(gral1)
	Next v1
	f4real8$ [xsi].msep[0];, f:%8.2f
	Text_crm tela, space$, buffer, cr$;real8$(gral1), cr$

	ForLp v1, 1, statVariables
		f4real8$ [xsi].ect[xax*8];, f:%8.2f
		Text_crm tela, space$, buffer;real8$(gral1)
	Next v1
	f4real8$ [xsi].ect[0];, f:%8.2f
	Text_crm tela, space$, buffer, cr$;real8$(gral1), cr$

	ForLp v1, 1, statVariables
		f4real8$ [xsi].er[xax*8];, f:%8.2f
		Text_crm tela, space$, buffer;real8$(gral1)
	Next v1
	f4real8$ [xsi].er[0];, f:%8.2f
	Text_crm tela, space$, buffer, cr$;real8$(gral1), cr$
	
	ForLp v1, 1, statVariables
		f4real8$ [xsi]._ed[xax*8];, f:%8.2f
		Text_crm tela, space$, buffer;real8$(gral1)
	Next v1
	f4real8$ [xsi]._ed[0];, f:%8.2f
	Text_crm tela, space$, buffer, cr$;real8$(gral1), cr$

	
MethodEnd

Method IntgSim.SimIndividual, uses xsi, individuo: xword

	SetObject xsi
	.if [xsi].controlr.integracion == 0
		OCall xsi.timestepindiv, individuo, cero, [xsi].controlr.cint, [xsi].controlr.maxt
	.elseif [xsi].controlr.integracion == 1
		OCall xsi.RK4Individual, individuo, cero, [xsi].controlr.cint, [xsi].controlr.maxt
	.endif
MethodEnd

endif