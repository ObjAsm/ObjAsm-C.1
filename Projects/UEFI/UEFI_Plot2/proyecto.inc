; ==================================================================================================
; Title:   proyecto.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: Plot UEFI Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================
echo -------------------------
echo esta leyendo proyecto.inc
echo -------------------------

if 1

include .\modelo\Lor835.inc

else

HaceEstadisticas equ TRUE
   statVariables equ 7;3;8

neqqu 	equ 65	; es el número máximo de variables de estado  

nvvar	equ 47	; es el número máximo de variables intermedias que se están "integrando"

estadotriple equ TRUE 	; en esta forma se encuentran iname, dname u name intercalados

SoloEstados equ FALSE

MuestraElemental equ FALSE

	_Control_Model macro
		v_inicio	textequ <0.0>
		v_duracion	textequ <835.0>
		v_maxt		textequ <  0.002>
		v_cint		textequ <  1.0>

		;v_maxt_cod	equ 0	; 0.0001
		v_maxt_cod	equ 1	; 0.002
		;v_maxt_cod	equ 2	; 0.05
		;v_maxt_cod	equ 3	; 0.1
		;v_maxt_cod	equ 4	; 1.0

		;meth_integ  equ 0	; TimeStep
		meth_integ  equ 1	; Runge-Kutta
		;meth_integ  equ 2	; Fehlberg
		;meth_integ  equ 3	; Cash-Karp
	endm

_variables macro
 	estado edad
	estado ebw
    estado TIME
    
endm

_metodos macro
   	VirtualMethod Crecimiento
endm

_inicial macro
	fSlv8 iedad = 165.0
	fSlv8 iebw = 115.93
	fSlv8 iTIME = 0.0
endm

_deriv macro
	; calculations of derivatives  subjects od integration  

	fSlv8 dedad =  1.0
	fSlv8 dTIME =  1.0
	OCall xsi.Crecimiento	

endm

_calcula macro
    
endm

_modelodata macro
    
endm

_calculations macro
	Method modeloC.Crecimiento, uses xsi
		SetObject xsi
		
	    fSlv8 debw =  1.05/1.13 - 2*3.58e-4*edad/1.13
			
	MethodEnd    
endm


; Para recuperar estados calculados por el modelo (se pueden escalar)
tr_estado macro tp
	;troncal_estado Aa ,tp ,</[edx].R8_AaCOR>   ; example
	
if 1	
	troncal_estado edad, tp
	troncal_estado ebw, tp
	;DbgFloat [ebx].R8_ebw
endif
endm

; Para recuperar variables calculadas por el modelo (se pueden escalar)
troncal2 macro tp
    ; troncal_variable AcTsF, tp ,<*1.0> ; example

endm

; Para nuevas variables calculadas con variables ya recuperadas
troncalsimple macro tp 
    ; troncal_variable TsFaF_Ts, tp, <*1>, TsFaF ; example
	
endm

;-------------------------------------------------	
;   System macros
;-------------------------------------------------	
_AcuDef macro
    ; DefineVariable R8_ebw, REAL8, 0.0  ; example

   	tr_estado 0     ; not modify this
	troncal2 0      ; not modify this
	troncalsimple 0 ; not modify this
endm
_levantaVariables macro
	troncal2 1      ; not modify this
endm
_cargaVariables macro
	troncal2 2      ; not modify this
endm
_AcumulaDatos macro

    ; fSlv8 [ebx].R8_ebw = [edx].R8_ebw   ; example
    
	tr_estado 1     ; not modify this
	troncal2 3      ; not modify this
	troncalsimple 3 ; not modify this
endm
_Actualiza macro tipo
	actualTP = &tipo
    ; cargacircle	RLV     ; example 

endm

endif
ModAccesorio equ 0

MuestraContador equ FALSE
MuestraProgress equ FALSE
 