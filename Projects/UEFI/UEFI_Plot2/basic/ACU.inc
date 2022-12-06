; ==================================================================================================
; Title:   ACU.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Object declaration - IntegAsm32 Light
; ==================================================================================================
include \masm32\objasm32\code\macros\SDLL.inc

acuElemental macro
	nccest = 0	
	REPEAT nestados
		 %DefineVariable @CatStr(R8_estado,%nccest), REAL8, 0.0

		;%DbgStrWFloat @CatStr(estado,%nccest),edad[nccest*8]
		;mov	eax , v1
;		DbgFloat edad[nccest*8]
		nccest = nccest+1
	endm
	ife SoloEstados
		nccest = 0	
		REPEAT nestados
			 %DefineVariable @CatStr(R8_destado,%nccest), REAL8, 0.0
			nccest = nccest+1
		endm

		nccest = 0	
		REPEAT vetados
			 %DefineVariable @CatStr(R8_variable,%nccest), REAL8, 0.0
			nccest = nccest+1
		endm
	endif
endm

Object ACUo,  ,Primer
  	
  	SDLL_ITEM { }
	DefineVariable etapa, xword, 0.0
	DefineVariable previo, xword, 0.0

       DefineVariable ntrat, xword, 0
       DefineVariable nentrat, xword, 0
	 
	DefineVariable x, REAL8, 0.0
	DefineVariable h, REAL8, 0.0
	DefineVariable cint, REAL8, 0.0

	if MuestraElemental
		echo Acumulador MuestraElemental
		acuElemental
	else
		_AcuDef
	endif	 

ObjectEnd

;pACU typedef ptr ACU
