; ==================================================================================================
; Title:   CTbase.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

Method IntgBase.circletime, uses xsi xbx , tanda:xword, nsteps:xword, x0:REAL8, h:REAL8, modalidad: xword

	local ns : REAL8
		
	local j: xword
	local jMb: qword
	local i : xword ,  vk : xword  
	local intervalominimo : REAL8
	local x : REAL8
	
	local tempr15:REAL8
	local xb :REAL8
	
	local fSlvTLS()
	
	local temp1 : REAL8, temp2 : REAL8, temp3 : REAL8
	local laststep:xword
	local igral1:xword, igral2:xword

	DbgText "CircleTime"
	
	assume xbx : ptr modeloB
	;base equ [xbx].modeloC
	SetObject xsi

	;fSlv8 x = 165.0
	OCall xsi.Tratamiento, x
	;DbgText "pasa Tratmiento"
	mov 	laststep, 0
	mov		[xsi].paso , 0
	
	ForLp j, 1, nsteps

		OCall [xsi].modelo::modeloB.zzderiv, x, 0, h

		mov	xbx , [xsi].modelo
		
		if 0
		ForLp i, 0, [xsi].nequ
			fld		[xbx].zv[xax*8]
			fmul	h
			fst		[xsi].derivadas[xax*8]
			fadd	[xsi].integrales[xax*8]
			fstp	[xsi].integrales[xax*8]		
		Next i
		endif	
		OCall xsi.CargaCircle
		
		;DbgDec [xsi].paso
		
		;OCall xsi.Resultado, x
		;.endif 
			
	;	MuestraContadorCircle
		inc [xsi].paso

	Next j
	
	
	.if modalidad ==1
		OCall xsi.CargaAcu, [xsi].paso, x
	.endif
	
	assume xbx : NOTHING
MethodEnd
