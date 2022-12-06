; ==================================================================================================
; Title:   Fehlbase.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

.data
	FB_y2	REAL8	4.0
	FB_y3 	REAL8 	32.0	
	FB_y4a	REAL8	1932.0
	FB_y4b	REAL8	-7200.0
	FB_y4c	REAL8	7296.0
	FB_y4d	REAL8	2197.0
	FB_y5am	REAL8	439.0
	FB_y5ad	REAL8	216.0
	FB_y5b	REAL8	-8.0
	
	MR_FROM_STR rFB_y5cm, 3680.0
	MR_FROM_STR rFB_y5cd, 513.0
	MR_DIV rFB_y5c, rFB_y5cd, rFB_y5cm
	FB_y5c	REAL8	MR_TO_IEEE(<REAl8>,rFB_y5c) 	
	
	MR_FROM_STR rFB_y5dm, -845.0
	MR_FROM_STR rFB_y5dd, 4104.0
	MR_DIV rFB_y5d, rFB_y5dd, rFB_y5dm
	FB_y5d	REAL8	MR_TO_IEEE(<REAl8>,rFB_y5d) 	
	
;            	k5 = stepUsed*g.deriv(x + stepUsed, y + 439.0*k1/216.0 - 8.0*k2 + 3680.0*k3/513.0 - 845*k4/4104.0);
 

	FB_y6ad	REAL8	27.0
	FB_y6cm	REAL8	-3544.0
	FB_y6cd	REAL8	2565.0
	FB_y6dm	REAL8	1859.0
	FB_y6dd	REAL8	4104.0
	FB_y6em	REAL8	-11.0	
	FB_y6ed	REAL8	40.0

 ;           	k6 = stepUsed*g.deriv(x + 0.5*stepUsed, y - 8.0*k1/27.0 + 2.0*k2 - 3544.0*k3/2565.0 + 1859.0*k4/4104.0 - 11.0*k5/40.0);

	FB_5am	REAL8	25.0	
	FB_5ad	REAL8	216.0
	FB_5cm	REAL8	1408.0
	FB_5cd	REAL8	2565.0
	FB_5dm	REAL8	2197.0
	FB_5dd	REAL8	4104.0
	FB_5ed	REAL8	5.0
	FB_6am	REAL8	16.0
	FB_6ad	REAL8	135.0
	FB_6cm	REAL8	6656.0
	FB_6cd	REAL8	12825.0
	FB_6dm	REAL8	28561.0
	FB_6dd	REAL8	56430.0
	FB_6em	REAL8	-9.0
	FB_6ed	REAL8	50.0
	FB_6fd	REAL8	55.0

;	        	y5 = y + 25.0*k1/216.0 + 1408.0*k3/2565.0 + 2197.0*k4/4104.0 - k5/5.0;
;            		y6 = y + 16.0*k1/135.0 + 6656.0*k3/12825.0 + 28561.0*k4/56430.0 - 9.0*k5/50.0 + 2.0*k6/55.0;

.code
;	private static double SAFETY = 0.9D; // safety scaling factor for Runge Kutta Fehlberg tolerance check
	;/*******************************************************
	; * 
	; *		Cash-Karp 
	; */
Method IntgBase.Fehlberg, uses xsi xbx, x0: REAL8,  xn:REAL8, h:REAL8, maxiter: xword,reltol:REAL8, abstol:REAL8

	local ns : REAL8
	local nsteps:xword
	local j: xword
	local jMb: qword
	local i : xword ,  vk : xword , terminado : xword  
	local intervalominimo : REAL8
	local x : REAL8 , xc : REAL8

	local salta2 : xword , termina : xword

	local pasov : REAL8
	
	local ii : xword
	local maxerr : REAL8 , delta : REAL8
	local fSlvTLS()

	SetObject xsi

	assume xbx : $ObjPtr(modeloB)

		f2f x , x0;
		
		Carga_el_acumuladorI 0		

		mov		salta2 , FALSE
		mov		ii , 0
		mov		terminado , FALSE;
		.while !terminado ;((x <= xn)&&(terminado==false)){

			inc 	ii;	ii++;
			mov xax, ii
			.if xax > maxiter 
				mov	terminado , FALSE
			.endif
			;.if(h < h1)
			;	mov salta2 , true;
			;.endif
			fldz
			fstp	maxerr

			OCall xsi.Tratamiento, x

			mov	xbx , [xsi].modelo

			;  Paso 1 ---------------------------------------------

			ForLp i, 0, [xsi].nequ, xcx
				fld		[xsi].integrales[xcx*8]
				fstp	[xsi].yy[xcx*8]		
			Next i
			
			OCall [xsi].modelo::modeloB.zzderiv, x, 0, h
			IFE SoloEstados
				OCall xsi.LevantaVariables, 0
			ENDIF
			;  Paso 2 ---------------------------------------------
			ForLp i, 0, [xsi].nequ, xcx
				fld		[xbx].zv[xcx*8]
				fmul	h
				fst		[xsi].k_1[xcx*8]
				fdiv	FB_y2
				fadd	[xsi].yy[xcx*8]
				fstp	[xsi].integrales[xcx*8]		
			Next i
			OCall xsi.CargaVector
			fSlv8 xc = x + h / 4.0  
			OCall [xsi].modelo::modeloB.zzderiv, xc, 0, h
			IFE SoloEstados
				OCall xsi.LevantaVariables, 1
			ENDIF
			;k2 = stepUsed*g.deriv(x + stepUsed/4.0, y + k1/4.0);
       
			; Paso 3 -------------------------------------------------------------
			ForLp i, 0, [xsi].nequ, xcx
				fld		[xbx].zv[xcx*8]
				fmul	h
				fst		[xsi].k_2[xcx*8]
				fmul	KC_y3b
				fld		[xsi].k_1[xcx*8]
				fmul	KC_y3a
				fadd
				fdiv	FB_y3
				fadd	[xsi].yy[xcx*8]
				fstp	[xsi].integrales[xcx*8]		
			Next i
			OCall xsi.CargaVector

			fSlv8 xc = x +3.0* h / 8.0  
			OCall [xsi].modelo::modeloB.zzderiv, xc, 0, h
			IFE SoloEstados
				OCall xsi.LevantaVariables, 2
			ENDIF
	     	;k3 = stepUsed*g.deriv(x + 3.0*stepUsed/8.0, y + (3.0*k1 + 9.0*k2)/32.0);
           	
           		; Paso 4 --------------------------------------------------------------------
		
			ForLp i, 0, [xsi].nequ, xcx
				fld		[xbx].zv[xcx*8]
				fmul	h
				fst		[xsi].k_3[xcx*8]
				fmul	FB_y4c
				fld		[xsi].k_1[xcx*8]
				fmul	FB_y4a
				fadd
				fld		[xsi].k_2[xcx*8]
				fmul	FB_y4b
				fadd
				fdiv	FB_y4d
				fadd	[xsi].yy[xcx*8]
				fstp	[xsi].integrales[xcx*8]		
			Next i

			OCall xsi.CargaVector
			fSlv8 xc = x +12.0* h / 13.0  
			OCall [xsi].modelo::modeloB.zzderiv, xc, 0, h
			IFE SoloEstados
				OCall xsi.LevantaVariables, 3
			ENDIF
	
	 	;k4 = stepUsed*g.deriv(x + 12.0*stepUsed/13.0, y + (1932.0*k1 - 7200.0*k2 + 7296.0*k3)/2197.0);
        	
        		; PASO 5 --------------------------------------------------
				;for(int i=0; i<nequ; i++)yd[i] = y[vk][i] -11.0*k1[i]/54.0 + 5.0*k2[i]/2.0 
				;                                               - 70.0*k3[i]/27.0 + 35.0*k4[i]/27.0;
			ForLp i, 0, [xsi].nequ, xcx
				fld		[xbx].zv[xcx*8]
				fmul	h
				fst		[xsi].k_4[xcx*8]
				fmul	FB_y5d
				fld		[xsi].k_1[xcx*8]
				fmul	FB_y5am
				fdiv	FB_y5ad
				fadd
				fld		[xsi].k_2[xcx*8]
				fmul	FB_y5b
				fadd
				fld		[xsi].k_3[xcx*8]
				fmul	FB_y5c
				fadd
				fadd	[xsi].yy[xcx*8]
				fstp	[xsi].integrales[xcx*8]		
			Next i
			OCall xsi.CargaVector
	
			fSlv8 xc = x + h   
			OCall [xsi].modelo::modeloB.zzderiv, xc, 0, h
			IFE SoloEstados
				OCall xsi.LevantaVariables, 4
			ENDIF
	    	;k5 = stepUsed*g.deriv(x + stepUsed, y + 439.0*k1/216.0 - 8.0*k2 
	    	 ;          + 3680.0*k3/513.0 - 845*k4/4104.0);
        		; Paso 6 ------------------------------------------------------------------------------------------------------------------- 
				;	+ 1631.0*k1[i]/55296.0 + 175.0*k2[i]/512.0 + 575.0*k3[i]/13824.0 
				; + 44275.0*k4[i]/110592.0 + 253.0*k5[i]/4096.0;
			ForLp i, 0, [xsi].nequ, xcx
				fld		[xbx].zv[xcx*8]
				fmul	h
				fst		[xsi].k_5[xcx*8]
				fmul	FB_y6em
				fdiv	FB_y6ed
				fld		[xsi].k_1[xcx*8]
				fmul	FB_y5b
				fdiv	FB_y6ad
				fadd
				fld		[xsi].k_2[xcx*8]
				fmul	dos
				fadd
				fld		[xsi].k_3[xcx*8]
				fmul	FB_y6cm
				fdiv	FB_y6cd
				fadd
				fld		[xsi].k_4[xcx*8]
				fmul	FB_y6dm
				fdiv	FB_y6dd
				fadd
				fadd	[xsi].yy[xcx*8]
				fstp	[xsi].integrales[xcx*8]		
			Next i
			OCall xsi.CargaVector
			fSlv8 xc = x +(0.5*h)   
			
			OCall [xsi].modelo::modeloB.zzderiv, xc, 0, h
			IFE SoloEstados
				OCall xsi.LevantaVariables, 5
			ENDIF
 	;k6 = stepUsed*g.deriv(x + 0.5*stepUsed, y - 8.0*k1/27.0 + 2.0*k2 - 3544.0*k3/2565.0 
    	;+ 1859.0*k4/4104.0 - 11.0*k5/40.0);

			ForLp i, 0, [xsi].nequ, xcx
				fld		[xbx].zv[xcx*8]
				fmul	h
				fstp	[xsi].k_6[xcx*8]
			Next i

				;for(int i=0; i<nequ; i++)k6[i] = h*dydx[i];
				;//tol = 0;
			; Resolución -----------------------------------------------------------------------------------------------------------------
			ForLp i, 0, [xsi].nequ, xcx
				;	y5[i] = y[vk][i] + 2825.0*k1[i]/27648.0 + 18575.0*k3[i]/48384.0 + 13525.0*k4[i]/55296.0 + 277.0*k5[i]/14336.0 + k6[i]/4.0;
				;	y6[i] = y[vk][i] + 37*k1[i]/378.0 + 250.0*k3[i]/621.0 + 125.0*k4[i]/594.0  + 512.0*k6[i]/1771.0;

				fld		[xsi].yy[xcx*8]		
				fld		[xsi].k_1[xcx*8]
				fmul	FB_6am
				fdiv	FB_6ad
				fadd
				fld		[xsi].k_3[xcx*8]
				fmul	FB_6cm
				fdiv	FB_6cd
				fadd
				fld		[xsi].k_4[xcx*8]
				fmul	FB_6dm
				fdiv	FB_6dd
				fadd
				fld		[xsi].k_5[xcx*8]
				fmul	FB_6em
				fdiv	FB_6ed
				fadd
				fld		[xsi].k_6[xcx*8]
				fmul	dos
				fdiv	FB_6fd
				fadd
				fstp	[xsi].y_6[xcx*8]
		
;		y6 = y + 16.0*k1/135.0 + 6656.0*k3/12825.0 + 28561.0*k4/56430.0 - 9.0*k5/50.0 + 2.0*k6/55.0;
        
				fld		[xsi].k_1[xcx*8]
				fmul	FB_5am
				fdiv	FB_5ad
				fld		[xsi].k_3[xcx*8]
				fmul	FB_5cm
				fdiv	FB_5cd
				fadd
				fld		[xsi].k_4[xcx*8]
				fmul	FB_5dm
				fdiv	FB_5dd
				fadd
				fld		[xsi].k_5[xcx*8]
				fdiv	FB_5ed
				fsub
			;y5 = y + 25.0*k1/216.0 + 1408.0*k3/2565.0 + 2197.0*k4/4104.0 - k5/5.0;
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
	
	        	;y5 = y + 25.0*k1/216.0 + 1408.0*k3/2565.0 + 2197.0*k4/4104.0 - k5/5.0;
            	;	y6 = y + 16.0*k1/135.0 + 6656.0*k3/12825.0 + 28561.0*k4/56430.0 - 9.0*k5/50.0 + 2.0*k6/55.0;
        
			comment ¨
				for(int i = 0; i < nequ; i++){
					;yy[vk][i]   = y5[i];   in asm at last
					dd[vk][i]  = 1/h*(2825.0*k1[i]/27648.0 + 18575.0*k3[i]/48384.0 + 13525.0*k4[i]/55296.0 + 277.0*k5[i]/14336.0 + k6[i]/4.0);
				}
				for(int i = 0; i < nvar; i++){
					mm[vk][i]  = (2825.0*m1[i]/27648.0 + 18575.0*m3[i]/48384.0 + 13525.0*m4[i]/55296.0 + 277.0*m5[i]/14336.0 + m6[i]/4.0);
				}
			;}
						
			¨	
			compvalR maxerr , uno
			.if((ah & FP_LESSTHAN)||(ah &FP_EQUALTO));((maxerr <= 1.0D)|| ( salta2== TRUE))
				mov salta2 , FALSE;
				;fSlv8 xv1=x;
				fSlv8 x = x+ h;
				;fSlv8 h1= h;
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

				OCall [xsi].modelo::modeloB.zzCalcula

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
			.if !( ah & FP_LESSTHAN );||(ah& FP_EQUALTO))	
				mov 	terminado , TRUE;
			.endif
		.endw
	
		comment ¨
		.if(ultimo)
			;System.out.println("hay último");
			;CargaAcu(tanda, paso, x+h );
			inc paso
		.endif
		z.Area2.etapasg[tanda] = paso - 1;

		z.CargaMuestra(tanda);
		z.Area2.inicio =0;// 		z.Area2.finalv -1;

		return y0;
¨
assume xbx:NOTHING
MethodEnd
