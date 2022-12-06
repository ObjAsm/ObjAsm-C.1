; ==================================================================================================
; Title:   TSbase.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================


Method IntgBase.timestep, uses xsi xbx , x0:REAL8, xn:REAL8, h:REAL8

	local ns : REAL8
	local nsteps:xword
	
	local j: xword
	local jMb: qword
	local i : xword   
	local intervalominimo : REAL8
	local x : REAL8
	
	local tempr15:REAL8
	local xb :REAL8
	
	local fSlvTLS()
	
	local temp1 : REAL8, temp2 : REAL8, temp3 : REAL8

	local xral : REAL8
	;DbgText "TimeStep"
	
	assume xbx : $ObjPtr(modeloB)
	;base equ [ebx].modeloC
	SetObject xsi

		fld		x0
		fst		xb
		fstp 	x
		
		fld		xn 
		fsub	x0
		fdiv	h;
		fst		ns; = Math.rint(ns);
		fistp 	nsteps; = (int) ns;

		;fSlv8 intervalominimo = 0.2;

		fSlv8 h = ( xn - x0)/ns;
		;DbgFloat h
		
		Carga_el_acumuladorI 0		
		; ——————————————————————————————————————————————————————————————————————————————————————————————————
		
		ForLp j, 1, nsteps

			fSlv8 x  = x0 + j*h
			;fSlv8 xbase = x;

			OCall xsi.Tratamiento, x

				mov	xbx , [xsi].modelo
				
				.if fLE(x, [xbx].limite)
				
				
				OCall [xsi].modelo::modeloB.zzderiv, x, 0, h
					
				mov	xbx , [xsi].modelo
				
				ForLp i, 0, [xsi].nequ
					fld		[xbx].zv[xax*8]
					fmul	h
					fst		[xsi].derivadas[xax*8]
					fadd	[xsi].integrales[xax*8]
					fstp	[xsi].integrales[xax*8]		
				Next i
				
				OCall xsi.CargaVector

				IFE SoloEstados
					OCall xsi.LevantaVariables, 0
					OCall xsi.CargaDerivada
					OCall xsi.CargaVariables
					if 0
					OCall xsi.Acumulacion_carga, vk
					endif
				ENDIF
			
				OCall [xsi].modelo::modeloB.zzCalcula
				;mov eax , vk
				;OCall [esi].modelo[eax*4]::modeloC.muestra
				.endif
				Carga_el_acumuladorI 1	

			fld		x
			fadd	h
			fstp	x
	
		Next j
	assume xbx : NOTHING
MethodEnd

