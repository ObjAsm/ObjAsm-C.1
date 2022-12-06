; ==================================================================================================
; Title:   Lor835.inc                                              05/05/19
; Author:  Héctor S. Enrique  @ July 2022
; Version: 1.0.0
; Purpose: Di Marco Model code 835d adjustment- IntegAsm32 Light
; ==================================================================================================

	titulo_del_modelo textequ < " Di Marco NewDNA 835 Lorentz">

;--------------------------------------------------------------------------
;	Compilation Controls
;--------------------------------------------------------------------------
	; Only state variables are storied and showed	
	SoloEstados equ TRUE
	;SoloEstados equ  FALSE

	;HayExperimentos equ TRUE
	HayExperimentos equ FALSE
	
	InterfaceDefault equ FALSE
	;MuestraElemental equ TRUE ;	solo muestra estados y derivadas
	MuestraElemental equ FALSE

	HayRuminales equ FALSE
	
	estadotriple equ TRUE 	; en esta forma se encuentran iname, dname u name intercalados

	Mecanistico equ TRUE
	;Mecanistico equ FALSE

	Instancias_del_modelo equ 0 ; número-1 usados : número es para cálculos accesorios
			
	;HaceEstadisticas equ TRUE
	HaceEstadisticas equ FALSE
	;HaceEstadisticas equ FALSE
	statVariables equ 3
	
	SeleccionGenetica equ FALSE
	
	AnalisisSensibilidad equ FALSE

	ModAccesorio	equ 0
;--------------------------------------------------------------------------
;	GdmRK
;--------------------------------------------------------------------------

	_Control_Model macro
		v_inicio	textequ <165.0>
		v_duracion	textequ <835.0>
		v_maxt		textequ <  1.0>
		v_cint		textequ <  1.0>

		;v_maxt_cod	equ 0	; 0.0001
		;v_maxt_cod	equ 1	; 0.002
		;v_maxt_cod	equ 2	; 0.05
		;v_maxt_cod	equ 3	; 0.1
		v_maxt_cod	equ 4	; 1.0

		;meth_integ  textequ 0	; TimeStep
		meth_integ  equ 1	; Runge-Kutta
		;meth_integ  textequ 2	; Fehlberg
		;meth_integ  textequ 3	; Cash-Karp

	endm

;nestados equ 8

_variables macro
	
	estado edad
	estado Pb
	estado Pv
	estado BDNA
	estado VDNA
	estado TsF
	estado water
    estado TIME
	estado ebw

	DefineR8   bDNAmx,  0.0
	DefineR8   vDNAmx , 0.0
	DefineR8   ebwm,    0.0
	DefineR8   ebwR,  650.0

	;  intermedias
	DefineR8   AaPbB,  0.0
	DefineR8   AaPvV,  0.0
	DefineR8   PbAaB,  0.0
	DefineR8   PvAaV,  0.0

	DefineR8   FaTsF,  0.0
	DefineR8   AcTsF,  0.0
	DefineR8   TsFaF,  0.0
	
	DefineR8   CHor,   0.0
	DefineR8   AHor,   0.0
	DefineR8   cAc,    0.0
	DefineR8   cGl,    0.0
	DefineR8   cAa,    0.0
	DefineR8   cFa,    0.0
	
	DefineR8   KTsFa   ,  1.0e-4
	DefineR8   KAcTsF  ,  0.0005
	DefineR8   k_1AcTs ,  0.0015
	DefineR8   KFaTsF  ,  1.5e-4
	DefineR8   k_1FaTs ,  1.5e-3
	
	DefineR8   bw ,        0.0
	DefineR8   fat ,       0.0
	DefineR8   fat_sub ,   0.0
	DefineR8   ft ,        0.0
	DefineR8   CarWt ,     0.0
	DefineR8   GutF ,      0.0

	DefineR8   dfat ,      0.0
	DefineR8   dprot ,     0.0

	DefineR8   molprot,    0.110
	DefineR8   DMmolfat,   0.854
	DefineR8   DMAcTsTs,  25.690

	DefineR8   edadInicial, 165.0
	;nestados = cestados
	
endm

_modelodata macro
	
endm

_metodos macro
	VirtualMethod		ModeloDiMarco
	VirtualMethod		Ini_DM
	VirtualMethod		DNA_DM
	VirtualMethod		Prot_DM
	VirtualMethod		Fat_DM
	VirtualMethod		Water_DM
endm

;--------------------------------------------------------------------------
;	GdmSim
;--------------------------------------------------------------------------

topebucle equ nestados - 1

_calculations macro
	
Method modeloC.Ini_DM, uses xsi
    SetObject xsi
		
    fSlv8	CHor = 1.0
    fSlv8	AHor = 1.0
    fSlv8	cFa  = 3.0e-4
    fSlv8	cAc  = 1.0e-3; // concentración de acetato = mol/litro de plama;;
    fSlv8	cGl  = 3.0e-3; // concentración de glucosa = mol/litro de plama;
    fSlv8	cAa  = 2.0e-3
MethodEnd
Method modeloC.DNA_DM, uses xsi
		
	SetObject xsi	
	
	fSlvRegConst bdnaa ,  1.712248 
    fSlvRegConst bdnab ,  -41509.46 
    fSlvRegConst bdnac ,  -2106598 
    fSlvRegConst bdnad ,  -13530.84 

    fSlvRegConst vdnaa ,  1.413132 
    fSlvRegConst vdnab ,  -856.3709 
    fSlvRegConst vdnac ,  -467573.7 
    fSlvRegConst vdnad ,  -19010.55 

	fSlv8 bDNAmx = 0.09745670418668801 * ebwR/650.0 * ebwm/650.0 ;
	fSlv8 vDNAmx = 0.07898211123597083 * ebwR/650.0 * ebwm/650.0;

    fSlv8 dBDNA =  ebwR/650.0 * (bdnaa +bdnab/(1+ (( Pb - bdnac)/ bdnad)^2)) * (1.0 -  BDNA /  bDNAmx)
    fSlv8 dVDNA =  ebwR/650.0 * (vdnaa +vdnab/(1+ (( Pv - vdnac) / vdnad)^2)) * (1.0 -  VDNA /  vDNAmx)
MethodEnd	
	

Method modeloC.Prot_DM, uses xsi
		
    local ExpPbAaB :REAL8
    local ExpPvAaV :REAL8

    local VAaPbB   :REAL8
    local VAaPvV   :REAL8
    local ExpAaPbB :REAL8
    local ExpAaPvV :REAL8 

    local KPbAaB   :REAL8
    local KPvAaV   :REAL8

    SetObject xsi
		
    fSlvRegConst KAaPbB , 2.0e-3
    fSlvRegConst KAaPvV , 2.0e-3

    fSlvRegConst spba ,  0.004746554 
    fSlvRegConst spbb ,  5764.693 
    fSlvRegConst spbc ,  777.9607 
    fSlvRegConst spbd ,  0.2920463 
    fSlvRegConst spva ,  0.01774839 
    fSlvRegConst spvb ,  21446.52 
    fSlvRegConst spvc ,  172.9763 
    fSlvRegConst spvd ,  -0.06591476 
        
    fSlvRegConst dgba ,  17688.43 
    fSlvRegConst dgbb ,  -273167 
    fSlvRegConst dgbc ,  -3012370 
    fSlvRegConst dgbd ,  -792595.6 
    fSlvRegConst dgva ,  5.769692 
    fSlvRegConst dgvb ,  3.706978 
    fSlvRegConst dgvc ,  144.8412 
    fSlvRegConst dgvd ,  -28.72189 

    fSlv8 AaPbB = ebwR/650.0 * (spba +spbb/(1+ (( Pb - spbc)/ spbd)^2)) \ 
    			* (710.2740349 *  ebwR/650.0 /  bDNAmx - ( Pb /  BDNA))\
    			/ (1.0 +  ( KAaPbB /  cAa))

    fSlv8 AaPvV = ebwR/650.0 *  (spva +spvb/(1+ (( Pv - spvc)/ spvd)^2))\
    			* (( 156.9713 * ebwR/650.0/ vDNAmx) - (Pv / VDNA))\		
    			/ (1.0 + ( KAaPvV / cAa))
		
    fSlv8 PbAaB = ebwR/650.0 *  (dgba +dgbb/(1+ ((Pb - dgbc)/ dgbd)^2))

    fSlv8 PvAaV = ebwR/650.0 *  (dgva +dgvb/(1+ ((Pv - dgvc)/ dgvd)^2))
		
    fSlv8 dPb 	= AaPbB - PbAaB
    fSlv8 dPv 	= AaPvV - PvAaV
    fSlv8 dprot	= dPb + dPv
MethodEnd

Method modeloC.Fat_DM, uses xsi
	
	local WtTs   :REAL8
	local VTsFa  :REAL8
	local VAcTs  :REAL8
	local VFaTs  :REAL8
	local WtCytF :REAL8
		
	local ac1 :REAL8 , ac2 :REAL8
	local ts1 :REAL8 , ts2 :REAL8
	local fa1 :REAL8 , fa2 :REAL8 , fa3 :REAL8 
	
	SetObject xsi	 

		;   Variables Lípidos

		fSlv8 ac1 = -121.3 , ac2 = -1.9276;
		fSlv8 ts1 = 16.01922405 , ts2 = 1.901897;
   		fSlv8 fa1 = 1128.84, fa2 = 9406.91, fa3 =  3.083845

		;   Calculos Lípidos

		fSlv8 WtCytF = 0.04 * ( Pb + Pv)*0.11;
			
		fSlv8 WtTs =  TsF * DMmolfat;
			
		fSlv8 VAcTs = ( ac2 +  ac1*ln( ebw/ ebwm))*( WtTs+ WtCytF)/1000.0;

		fSlv8 VTsFa = ( ts1*exp( ts2* ebw/ ebwm)/1000.0)*(WtTs+ WtCytF);
			
		fSlv8 VFaTs =  WtCytF * ( fa1 +  fa2* (( ebw/ ebwm) ^ fa3))/1000.0;
		
		fSlv8 TsFaF =  VTsFa / ((1.0 + ( cFa/ KTsFa)) * CHor);
		;(ebw/ebwm < 1.0)|
		fld		ebw
		fdiv 	ebwm
		fstp	tempR8
		compvalR tempR8, uno 
		.if ( ah & FP_LESSTHAN )
			fSlv8 AcTsF = VAcTs/ (1.0 + ( KAcTsF / cAc) + ( k_1AcTs / ( AHor *  cGl)));
		.else
			fSlv8 AcTsF = 0.0;
		.endif
		fSlv8 FaTsF =  VFaTs / (1.0 + ( KFaTsF / cFa) + ( k_1FaTs / ( AHor *  cGl)));

		; Lipid accretion
		fSlv8 dTsF = FaTsF/3.0 + AcTsF/ DMAcTsTs - TsFaF;
		fSlv8 dfat = (FaTsF/3.0 - TsFaF + AcTsF/DMAcTsTs) * DMmolfat ;
	
MethodEnd	

Method modeloC.Water_DM, uses xsi
	local pw2:REAL8, pw3:REAL8, pw4:REAL8
	SetObject xsi
						
	fSlvRegConst pw2 , 0.3186401 
	fSlvRegConst pw3 , 0.05549023 
	fSlvRegConst pw4 , 2.509056 
     
	fSlv8 dwater = dprot* ( pw3*((ebw/ebwm) ^ pw4) + pw2);

MethodEnd

Method modeloC.ModeloDiMarco, uses xsi

	SetObject xsi	

	OCall xsi.Ini_DM
	OCall xsi.DNA_DM
	OCall xsi.Prot_DM
	OCall xsi.Fat_DM
	OCall xsi.Water_DM
	
	fSlv8 debw = dprot * molprot +  dTsF *  DMmolfat +  dwater;

MethodEnd	

endm

include GralDM.inc
