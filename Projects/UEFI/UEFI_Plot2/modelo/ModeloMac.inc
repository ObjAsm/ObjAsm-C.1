; ==================================================================================================
; Title:   ModeloMac.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
;               1           hse October 2017
;               _muestraT & _muestraP
; Purpose:  General Model code - IntegAsm32 Light
; Aknowledgments: to qWord, for his suggestions leading to DefineR8 first macro
; ==================================================================================================

DefineTS macro nombre , valor, tipo
	DefineVariable	@CatStr(  < >,TS_ , &nombre ) , &tipo , &valor
	&nombre textequ <[xsi].TS_&nombre>
endm

DefineFd macro nombre, tipo, valor 
	DefineVariable  &nombre , &tipo, &valor
endm

DefineDD macro nombre , valor
	DefineVariable	@CatStr(  < >,DD35_ , &nombre ) , dword , &valor
	&nombre textequ <[xsi].DD35_&nombre>
endm

DefineR8 macro nombre , valor
	DefineVariable	@CatStr(  < >,R8_ , &nombre ) , REAL8 , &valor
	&nombre textequ <[xsi].R8_&nombre>
	
endm

DefineER8 macro nombre , valor
	ifndef ertados
		ertados = 0
	else
		ertados = ertados+1
	endif
	ifdef Application
    	CStr @CatStr(estado,%ertados) , "&nombre"
	endif 
	%echo @CatStr(estado,%ertados) , "&nombre" 
	ifdef Application
    	if MuestraElemental
    		CStr @CatStr(destado,%ertados), "d&nombre" 
    	endif
    	;endif
    	CStr @CatStr(str_,&nombre) , "&nombre" 
	endif
	DefineVariable	@CatStr(  < >,R8_ , &nombre ) , REAL8 , &valor
	&nombre textequ <[xsi].R8_&nombre>
	
	IFNDEF firstinitial
		firstinitial textequ <R8_i&nombre>
		firstderivate textequ <R8_d&nombre>
		firststate textequ <R8_&nombre>
	ENDIF
endm

DefineVR8 macro nombre , valor, denominacion
	ifndef vetados
		vetados = 0
	endif
	
	ifnb <denominacion>
		%echo @CatStr(< con denominccion >, variable,%vetados) , @CatStr(!",&denominacion,!")
		CStr @CatStr(variable,%vetados) , @CatStr(!",&denominacion,!") 
	else
		%echo @CatStr(variable,%vetados) , "&nombre" 
		CStr @CatStr(variable,%vetados) , "&nombre" 
	endif

	DefineVariable	@CatStr(  < >,R8_ , &nombre ) , REAL8 , &valor
	&nombre textequ <[xsi].R8_&nombre>
	%echo &nombre
	@CatStr(varElemental,%vetados,< >) textequ <R8_&nombre> 
	vetados = vetados+1
	 	
endm
estado macro nombre:REQ, iniValue
   	ifidn <iniValue>,<0>
		DefineR8  i&nombre&  ,  0.0
	else
 		DefineR8  i&nombre&  ,  &iniValue
	endif

	ifidn <nombre>, <Aa>
	
		DefineR8  d_&nombre& ,  0.0
	else
		DefineR8  d&nombre& ,  0.0
	endif
	DefineER8  &nombre&   ,  0.0
	
	ifndef cestados
		cestados = 0
	else
		cestados = cestados+1
	endif
	orden_d&nombre& equ cestados

	IFNDEF firstinitial
		firstinitial textequ <R8_i&nombre>
		firstderivate textequ <R8_d&nombre>
		firststate textequ <R8_&nombre>
	ENDIF

	nestados = cestados+1
endm

AcumR8 macro nombre
	DefineVariable	@CatStr(< >,acum_ , &nombre ) , REAL8 , 555.0
	DefineVariable	@CatStr(< >,ordenac_ , &nombre ) , dword , @CatStr(orden_ , &nombre )
	ifndef acumuladores
		acumuladores = 1
		firstacumulator textequ <acum_&nombre>
		firstordenacum textequ <ordenac_&nombre>
	else
		acumuladores = acumuladores +1	
	endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

MuestraEstados macro
	DbgLine
	nccest = 0	
	REPEAT nestados
		nccest = nccest+1
	endm
	DbgLine
endm
DbgEstados macro estados :VARARG
	for item, <estados>
		DbgFloat <item> 
	endm
endm
DbgVarios macro estados :VARARG
	for item, <estados>
		DbgFloat <item> 
	endm
endm

_serieP macro args:VARARG
	local cntt
	
	cntt = 0
	;repeat Instancias_del_modelo+1
	FOR item, <args>
		OCallO grafico::Graphic1.InitSerie, 1, SG_Modo_Linea , $RGB(0,248,0)
		mov grafico.Graphic1.serieS[cntt*4], xax
		cntt = cntt + 1
	ENDM

endm
;*****************************************************
_muestraT macro tipo, cnt, xtit, xunit, args:VARARG
   	if tipo lt 2
	    if cnt eq 0
			mtif tipo, graf1, tmp$, cnt, <xtit>, <xunit>,<args>
		else
			mtelseif tipo, graf1, tmp$, cnt, <xtit>, <xunit>,<args>
		endif
   	endif
endm
_muestraP macro tipo, cnt,xstring, base, args:VARARG
	local ccnntt
	
   	if tipo eq 0
   		ccnntt = 0
   		For item, <args>
   			ccnntt = ccnntt+1
   		endm
	elseif tipo eq 2
	    txt SUBSTR tmp$, 8;@SizeStr( %tmp$ )
	    invoke SendMessage, @CatStr(<[xsi].chMostrar>, %txt,<.hWnd>), CB_ADDSTRING, 0, $OfsCStr("&xstring")
   	elseif tipo eq 3
   		if cnt eq 0
			mif  graf1, hRes$, tmp$, cnt, base, <args>
		else
			melseif graf1, hRes$, tmp$, cnt, base, <args>
		endif
   	elseif tipo eq 4
   		;_serieP <args>
   	endif
	cnt = cnt+1
endm

;***************************************************************

	levantaV macro variable
		ifndef nvaL
			nvaL = 0
		endif 
		f2f	[xsi]._mm_[xcx*8+%nvaL*8], [xbx].R8_&variable
		nvaL = nvaL + 1
	endm
	cargaV macro variable
		ifndef nvaC
			nvaC = 0
		endif 
		f2f	 [xbx].R8_&variable , [xsi]._mm_[%nvaC*8]
		nvaC = nvaC + 1
	endm
	
	muestraLaVariablei macro variable, calculo
		@CatStr (<fSlv8 [xbx].>, &variable, < = [xdx].>, &variable, &calculo)
	endm

	muestraLaVariable macro variable, calculo, variabl2
		ifndef variabl2
			@CatStr (<fSlv8 [xbx].>, &variable, < = [xdx].>, &variable, <calculo>)
		else
			@CatStr (<fSlv8 [xbx].>, &variable, < = [xdx].R8_>, &variabl2, &calculo)
		endif
	endm

troncal_variable macro variable, tipo, accesorio, accesori2
	if tipo eq 0
	    DefineVariable R8_&variable, REAL8, 0.0
	elseif tipo eq 1
	    levantaV &variable
	elseif tipo eq 2
	    cargaV &variable
	elseif tipo eq 3			; Carga en AcumulaDatos
	    ifndef accesori2
    	    muestraLaVariable R8_&variable, accesorio
	    else
		    muestraLaVariable R8_&variable, accesorio, accesori2
	    endif
	else
	endif
endm
troncal_estado macro variable, tipo, accesorio
	if tipo eq 0
		DefineVariable R8_&variable, REAL8, 0.0
	elseif tipo eq 1
		muestraLaVariable R8_&variable, accesorio
	else
	endif
endm

muestraxtitle macro atitle:VARARG
    count = 0
    FOR titlex, <atitle> 
    %	invoke SendMessage, [xsi].chMostrarEje.hWnd, CB_ADDSTRING, count, @CatStr(<$OfsCStr("> <titlex> <")>)
        count = count +1
    ENDM
endm
muestraxu macro tipo, atitle:VARARG
    count = 0
    FOR titlex, <atitle>
%    	CStr @CatStr( <eje>, %count,<$,>) @CatStr(<!">,<titlex>,<!",0>)
        count = count +1
    ENDM
endm

estadom macro args:VARARG
	FOR item, <args>
		estado <item>
	ENDM
endm

defineR8m macro args:VARARG
	FOR item, <args>
		defineR8 <item>, 0.0
	ENDM
endm
