Method IntgBase.RK4, uses xsi, x0: REAL8, xn:REAL8, h:REAL8

	local ns     : REAL8
	local nsteps : xword
	local j      : xword
	local jMb    : qword
	local i      : xword   
	local intervalominimo : REAL8
	local x : REAL8 , xc : REAL8 , xbase :REAL8
	
	local fSlvTLS()

	local xral : REAL8

	SetObject xsi

	assume xbx : $ObjPtr(modeloB)
		;// Calculate nsteps

		fld		x0
		fstp	x
		fld		xn 
		fsub	x0
		fdiv	h;
		;fRndDn
		fst	ns; = Math.rint(ns);
		fistp nsteps; = (int) ns;

		Carga_el_acumuladorI 0		

		ForLp j , 1, nsteps

			fSlv8 x  = x0 + j*h
			fSlv8 xbase = x;

			OCall xsi.Tratamiento, x

			mov	xbx , [xsi].modelo
				
			.if fLE(x, [xbx].limite)
				
				ForLp i, 0, [xsi].nequ
					fld		[xsi].integrales[xax*8]
					fstp	[xsi].yy[xax*8]		
				Next i
				OCall xbx::modeloB.zzderiv, x, 0, h
				
				IFE SoloEstados
					OCall xsi.LevantaVariables, 1
				ENDIF
			
				ForLp i, 0, [xsi].nequ
					fld		[xbx].zv[xax*8]
					fmul	h
					fst		[xsi].k_1[xax*8]
					fdiv	dos
					fadd	[xsi].yy[xax*8]
					fstp	[xsi].integrales[xcx*8]		
				Next i
				OCall xsi.CargaVector
				
				fSlv8 xc = x + h / 2.0  
				OCall xbx::modeloB.zzderiv, xc, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 2
				ENDIF
				ForLp i, 0, [xsi].nequ
					fld		[xbx].zv[xax*8]
					fmul	h
					fst		[xsi].k_2[xax*8]
					fdiv	dos
					fadd	[xsi].yy[xax*8]
					fstp	[xsi].integrales[xax*8]		
				Next i
				OCall xsi.CargaVector
		
				fSlv8 xc = x + h / 2.0  
				OCall [xsi].modelo::modeloB.zzderiv, xc, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 3
				ENDIF		
				ForLp i, 0, [xsi].nequ
					fld		[xbx].zv[xax*8]
					fmul	h
					fst		[xsi].k_3[xax*8]
					fadd	[xsi].yy[xax*8]
					fstp	[xsi].integrales[xax*8]		
				Next i
				OCall xsi.CargaVector
				fSlv8 xc = x + h  
				OCall xbx::modeloB.zzderiv, xc, 0, h
				IFE SoloEstados
					OCall xsi.LevantaVariables, 4
				ENDIF
				ForLp i, 0, [xsi].nequ
					fld		[xbx].zv[xax*8]
					fmul	h
					fst		[xsi].k_4[xax*8]
					fdiv	seis
					fld		[xsi].k_3[xax*8]
					fdiv	tres
					fadd
					fld		[xsi].k_2[xax*8]
					fdiv	tres
					fadd
					fld		[xsi].k_1[xax*8]
					fdiv	seis
					fadd
					fst		[xsi].derivadas[xax*8]
					fadd	[xsi].yy[xax*8]
					fstp	[xsi].integrales[xax*8]		
				Next i
				OCall xsi.CargaVector
	
				IFE SoloEstados
					ForLp i, 0 , nvvar
						mov		xax , 1
						mov		xcx , nvvar
						mul		xcx
						add		xax , i
						mov		xcx , xax
						fld 	[xsi]._mm_[xcx*8]
						fdiv	seis
						mov		xax , 2
						mov		xcx , nvvar
						mul		xcx
						add		xax , i
						mov		xcx , xax
						fld 	[xsi]._mm_[xcx*8]
						fdiv	tres
						fadd
						mov		xax , 3
						mov		xcx , nvvar
						mul		xcx
						add		xax , i
						mov		xcx , xax
						fld 	[xsi]._mm_[xcx*8]
						fdiv	tres
						fadd
						mov		xax , 4
						mov		xcx , nvvar
						mul		xcx
						add		xax , i
						mov		xcx , xax
						fld 	[xsi]._mm_[xcx*8]
						fdiv	seis
						fadd
						fmul	h
						mov		xcx , i
						fstp 	[xsi]._mm_[xcx*8]
					Next i
					;DbgText " a derivada"
					OCall xsi.CargaDerivada
					;DbgText " variables"
					OCall xsi.CargaVariables
				ENDIF
	
				;fSlv8 [xsi].h = h;
					OCall xbx::modeloB.zzCalcula
				.endif

			Carga_el_acumuladorI 1	
		Next j
	assume xbx : NOTHING
MethodEnd
