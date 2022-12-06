; ==================================================================================================
; Title:   CKbase.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

.data
	
	SAFETY1 REAL8 0.90
	KC_y2	REAL8 5.0
	KC_y3a	REAL8 3.0
	KC_y3b	REAL8 9.0
	KC_y3c	REAL8 40.0
	KC_y4a	REAL8 12.0
	KC_y4b	REAL8 10.0
			
	KC_y5a REAL8 -11.0
	KC_y5b REAL8  54.0
	KC_y5c REAL8   5.0
	KC_y5d REAL8   2.0
	KC_y5e REAL8 -70.0
	KC_y5f REAL8  27.0
	KC_y5g REAL8  35.0

	KC_y61a	REAL8 1631.0
	KC_y61b	REAL8 55296.0 
	KC_y62a	REAL8 175.0
	KC_y62b	REAL8 512.0 
	KC_y63a	REAL8 575.0
	KC_y63b	REAL8 13824.0 
	KC_y64a	REAL8 44275.0
	KC_y64b	REAL8 110592.0
	KC_y65a	REAL8 253.0
	KC_y65b	REAL8 4096.0

	KC5_1a REAL8	2825.0
	KC5_1b REAL8	27648.0 
	KC5_3a REAL8	18575.0
	KC5_3b REAL8	48384.0 
	KC5_4a REAL8	13525.0
	KC5_4b REAL8	55296.0 
	KC5_5a REAL8	277.0
	KC5_5b REAL8	14336.0 
	KC5_6b REAL8	4.0

	KC6_1a REAL8	 37.0
	KC6_1b REAL8	 378.0 
	KC6_3a REAL8	 250.0
	KC6_3b REAL8	 621.0 
	KC6_4a REAL8	 125.0
	KC6_4b REAL8	 594.0
	KC6_6a REAL8	 512.0
	KC6_6b REAL8	 1771.0
	

.code
;	private static double SAFETY = 0.9D; // safety scaling factor for Runge Kutta Fehlberg tolerance check
	;/*******************************************************
	; * 
	; *		Cash-Karp 
	; */

Method IntgBase.CashKarpI, uses xsi xbx, tanda: xword, x0: REAL8,  xn:REAL8, h:REAL8, maxiter: xword,reltol:REAL8, abstol:REAL8

	local ns : REAL8
	local nsteps:xword
	local j: xword
	local jMb: qword
	local i : xword , terminado : xword  
	local intervalominimo : REAL8
	local x : REAL8 , xc : REAL8

	local salta1 : xword , termina : xword

	local pasov : REAL8
	
	local ii : xword
	local maxerr : REAL8 , delta : REAL8

	local fSlvTLS()	
	local xral : REAL8

;		DbgLine
;		DbgText " Cash - Karp"
;		DbgLine

	SetObject xsi
	assume xbx : ptr $Obj(modeloB)

		f2f x , x0;
		
		Carga_el_acumuladorI 0		
		
		mov		salta1 , FALSE
		mov		ii , 0
		mov		terminado , FALSE;
		.while !terminado ;((x <= xn)&&(terminado==false)){

			;.if(x>=xn) 
			inc 	ii;	ii++;
			mov xax, ii
			.if xax > maxiter 
				mov	terminado , FALSE
				;;throw new ArithmeticException("Maximum number of iterations exceeded");
			.endif
			fldz
			fstp	maxerr

			OCall xsi.Tratamiento, x

			mov	xbx , [xsi].modelo
					
				;  Paso 1 ---------------------------------------------
				
				ForLp i, 0, [xsi].nequ, xcx
					fld		[xsi].integrales[xcx*8]
					fstp	[xsi].yy[xcx*8]		
				Next i
				
				OCall xbx::modeloB.zzderiv, x, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 0
				ENDIF
				;  Paso 2 ---------------------------------------------
				ForLp i, 0, [xsi].nequ, xcx
				
					fld		[xbx].zv[xcx*8]
					fmul	h
					fst		[xsi].k_1[xcx*8]
					fdiv	KC_y2
					fadd	[xsi].yy[xcx*8]
					fstp	[xsi].integrales[xcx*8]		
				Next i
				OCall xsi.CargaVector
				fSlv8 xc = x + h / 5.0  
				OCall xbx::modeloB.zzderiv, xc, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 1
				ENDIF
				; Paso 3 -------------------------------------------------------------
				ForLp i, 0, [xsi].nequ, xcx
					fld	[xbx].zv[xcx*8]
					fmul	h
					fst	[xsi].k_2[xcx*8]
					fmul	KC_y3b
					fld	[xsi].k_1[xcx*8]
					fmul	KC_y3a
					fadd
					fdiv	KC_y3c
					fadd	[xsi].yy[xcx*8]
					fstp	[xsi].integrales[xcx*8]		
				Next i
				OCall xsi.CargaVector
	
				fSlv8 xc = x +3.0* h / 10.0
				OCall xbx::modeloB.zzderiv, xc, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 2
				ENDIF
				; Paso 4 --------------------------------------------------------------------
			
					;yd[i] = y[vk][i] + (3.0*k1[i] - 9.0*k2[i] + 12.0*k3[i])/10.0;
    			ForLp i, 0, [xsi].nequ, xcx
					fld		[xbx].zv[xcx*8]
					fmul	h
					fst		[xsi].k_3[xcx*8]
					fmul	KC_y4a
					fld		[xsi].k_1[xcx*8]
					fmul	KC_y3a
					fadd
					fld		[xsi].k_2[xcx*8]
					fmul	KC_y3b
					fsub
					fdiv	KC_y4b
					fadd	[xsi].yy[xcx*8]
					fstp	[xsi].integrales[xcx*8]		
				Next i
	
				OCall xsi.CargaVector
				fSlv8 xc = x +3.0* h / 5.0
				OCall xbx::modeloB.zzderiv, xc, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 3
				ENDIF
				; PASO 5 --------------------------------------------------
					;for(int i=0; i<nequ; i++)yd[i] = y[vk][i] -11.0*k1[i]/54.0 + 5.0*k2[i]/2.0 
					;                                               - 70.0*k3[i]/27.0 + 35.0*k4[i]/27.0;
				ForLp i, 0, [xsi].nequ, xcx

					fld		[xbx].zv[xcx*8]
					fmul	h
					fst		[xsi].k_4[xcx*8]
					fmul	KC_y5g
					fdiv	KC_y5f
					fld		[xsi].k_1[xcx*8]
					fmul	KC_y5a
					fdiv	KC_y5b
					fadd
					fld		[xsi].k_2[xcx*8]
					fmul	KC_y5c
					fdiv	KC_y5d
					fadd
					fld		[xsi].k_3[xcx*8]
					fmul	KC_y5e
					fdiv	KC_y5f
					fadd
					fadd	[xsi].yy[xcx*8]
					fstp	[xsi].integrales[xcx*8]		
				Next i
				OCall xsi.CargaVector
		
				fSlv8 xc = x + h   
				OCall xbx::modeloB.zzderiv, xc, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 4
				ENDIF
				; Paso 6 ------------------------------------------------------------------------------------------------------------------- 
					;for(int i=0; i<nequ; i++)yd[i] = y[vk][i] 
					;	+ 1631.0*k1[i]/55296.0 + 175.0*k2[i]/512.0 + 575.0*k3[i]/13824.0 
					; + 44275.0*k4[i]/110592.0 + 253.0*k5[i]/4096.0;
				ForLp i, 0, [xsi].nequ, xcx

					fld		[xbx].zv[xcx*8]
					fmul	h
					fst		[xsi].k_5[xcx*8]
					fmul	KC_y65a
					fdiv	KC_y65b
					fld		[xsi].k_1[xcx*8]
					fmul	KC_y61a
					fdiv	KC_y61b
					fadd
					fld		[xsi].k_2[xcx*8]
					fmul	KC_y62a
					fdiv	KC_y62b
					fadd
					fld		[xsi].k_3[xcx*8]
					fmul	KC_y63a
					fdiv	KC_y63b
					fadd
					fld		[xsi].k_4[xcx*8]
					fmul	KC_y64a
					fdiv	KC_y64b
					fadd
					fadd	[xsi].yy[xcx*8]
					fstp	[xsi].integrales[xcx*8]		
				Next i
				
				OCall xsi.CargaVector
				fSlv8 xc = x +(7.0*h / 8.0)   
				
				OCall xbx::modeloB.zzderiv, xc, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 5
				ENDIF
				
    			ForLp i, 0, [xsi].nequ, xcx
					fld		[xbx].zv[xcx*8]
					fmul	h
					fstp	[xsi].k_6[xcx*8]
				Next i

				; Resolución -----------------------------------------------------------------------------------------------------------------
				ForLp i, 0, [xsi].nequ, xcx
					;	y5[i] = y[vk][i] + 2825.0*k1[i]/27648.0 + 18575.0*k3[i]/48384.0 + 13525.0*k4[i]/55296.0 + 277.0*k5[i]/14336.0 + k6[i]/4.0;
					;	y6[i] = y[vk][i] + 37*k1[i]/378.0 + 250.0*k3[i]/621.0 + 125.0*k4[i]/594.0  + 512.0*k6[i]/1771.0;

					fld		[xsi].yy[xcx*8]		
					fld		[xsi].k_1[xcx*8]
					fmul	KC6_1a
					fdiv	KC6_1b
					fadd
					fld		[xsi].k_3[xcx*8]
					fmul	KC6_3a
					fdiv	KC6_3b
					fadd
					fld		[xsi].k_4[xcx*8]
					fmul	KC6_4a
					fdiv	KC6_4b
					fadd
					fld		[xsi].k_6[xcx*8]
					fmul	KC6_6a
					fdiv	KC6_6b
					fadd
					fstp	[xsi].y_6[xcx*8]
		
					fld		[xsi].k_1[xcx*8]
					fmul	KC5_1a
					fdiv	KC5_1b
					fld		[xsi].k_3[xcx*8]
					fmul	KC5_3a
					fdiv	KC5_3b
					fadd
					fld		[xsi].k_4[xcx*8]
					fmul	KC5_4a
					fdiv	KC5_4b
					fadd
					fld		[xsi].k_5[xcx*8]
					fmul	KC5_5a
					fdiv	KC5_5b
					fadd
					fld		[xsi].k_6[xcx*8]
					fdiv	KC5_6b
					fadd
					fst		[xsi].derivadas[xcx*8]
					fadd	[xsi].yy[xcx*8]		
					fst		[xsi].y_5[xcx*8]
					fabs
					fmul	reltol
					fadd	abstol
					fstp	[xsi].tol[xcx*8];tol 	= Math.abs(y5[i])*reltol +  abstol;
					
					fld		[xsi].y_6[xcx*8]
					fsub	[xsi].y_5[xcx*8]
					fabs
					fstp	[xsi].err[xcx*8];err 	= Math.abs(y6[i] - y5[i]);
					
					fSlv8 tempR8 = [xsi].err[xcx*8]/[xsi].tol[xcx*8]
					compvalR maxerr , tempR8
					.if ( ah & FP_LESSTHAN )
						fSlv8  maxerr = tempR8
					.endif					;maxerr = Math.max(maxerr,err/tol);
		
				Next i
				comment ¨
					for(int i = 0; i < nequ; i++){
						;yy[vk][i]   = y5[i];   in asm at last
						dd[vk][i]  = 1/h*(2825.0*k1[i]/27648.0 + 18575.0*k3[i]/48384.0 + 13525.0*k4[i]/55296.0 + 277.0*k5[i]/14336.0 + k6[i]/4.0);
					}
					for(int i = 0; i < nvar; i++){
						mm[vk][i]  = (2825.0*m1[i]/27648.0 + 18575.0*m3[i]/48384.0 + 13525.0*m4[i]/55296.0 + 277.0*m5[i]/14336.0 + m6[i]/4.0);
					}
				;}¨
					
				compvalR maxerr , uno
				.if((ah & FP_LESSTHAN)||(ah &FP_EQUALTO));((maxerr <= 1.0D)|| ( salta1== TRUE))
					mov salta1 , FALSE;
					fSlv8 x = x+ h;
					fSlv8 delta = SAFETY1 * (maxerr ^ -0.2)
					compvalR cuatro , delta
					.if (ah & FP_LESSTHAN);				.if(delta > 4.0)
						fSlv8 h= h*4.0;
					.else
						compvalR uno , delta
						.if (ah & FP_LESSTHAN);delta > 1.0)
							fSlv8 h= h* delta
						.endif
					.endif
					fSlv8 tempR8 = x+h
					compvalR xn , tempR8
					.if(ah & FP_LESSTHAN);(x+h > xn) 
						fSlv8 h = xn - x;
					.endif
	
					ForLp i , 0, [xsi].nequ, xcx
						fld		[xsi].y_5[xcx*8]
						fstp	[xsi].integrales[xcx*8]
					Next i
					OCall xsi.CargaVector
					IFE SoloEstados
						OCall xsi.CargaDerivada
						OCall xsi.CargaVariables
					ENDIF
					fSlv8 [xsi].h = h;
	
					OCall xbx::modeloB.zzCalcula
				
					Carga_el_acumuladorI 1	

				.else
					fSlv8 delta = SAFETY1*(maxerr ^ -0.25);
					compvalR delta , cero1
					.if(ah & FP_LESSTHAN) 
						fSlv8 h = h*0.1;
					.else 
						fSlv8 h = h* delta;
					.endif
					ForLp i , 0, [xsi].nequ, xcx
						fld		[xsi].yy[xcx*8]
						fstp	[xsi].integrales[xcx*8]
					Next i

					OCall xsi.CargaVector
				.endif        	
				
				compvalR x, xn	
				.if !( ah & FP_LESSTHAN ); || (ah & FP_EQUALTO))	
					mov 	terminado , TRUE;
				.endif
			.endw
assume xbx:NOTHING
MethodEnd
