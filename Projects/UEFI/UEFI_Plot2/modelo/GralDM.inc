; ==================================================================================================
; Title:   GralDM.inc                                              05/05/19
; Author:  Héctor S. Enrique  @ July 2022
; Version: 1.0.0
; Purpose: Di Marco Model code 835d adjustment- IntegAsm32 Light
; ==================================================================================================

_inicial macro
    DbgText "inicial**********************"
    fSlv8 iedad = 165.0
    fSlv8 iPb = 170.95;
    fSlv8 iPv = 38.86;
    fSlv8 iBDNA = 0.033197
    fSlv8 iVDNA = 0.026417
    fSlv8 iTsF = 10.93/0.854;
		
    fSlv8 iebw = 115.93 ;//!600 and 650 !
    fSlv8 iwater =76.9
    fSlv8 ebwm = 650.0
endm

_comunicationPre macro
	; comunications during integration every CINT   (Comunication interval
endm
_prepara macro
	; calculations before every integration step 
endm

_deriv macro
		; calculations of derivatives  subjects od integration  
	
		fSlv8 dedad =  1.0;h5;

		OCall xsi.ModeloDiMarco	

endm

_calcula macro
	; calculations after every integration step 

	fSlv8 bw = 11.3+1.04*ebw; // "Body Weight"
	fSlv8 fat_sub = -1.08 +0.26 * fat;
	fSlv8 ft = (fat_sub - 4.35) / 1.89;
	fSlv8 CarWt = bw*0.667 - 30.5;//  "Carcass weight"                      
	fSlv8 GutF = bw - ebw;// "Gut fill" 

	if HaceEstadisticas
	    	
	    fSlv8 _ebwCalcS =( -32.5 + 1.05 *edad - 3.58e-4*edad^2)/1.13
		fSlv8 _FAT = -0.61+0.037*_ebwCalcS+5.4e-4*_ebwCalcS^2;
		OCall [xsi].statLineal::StatLin.compararMultipleD,1, _FAT, @fSlv8(TsF*DMmolfat)
				
		fSlv8 WAT = 3.688+0.671*_ebwCalcS - 3.4e-4*_ebwCalcS^2;
		OCall [xsi].statLineal::StatLin.compararMultipleD,2, WAT, water

		fSlv8 PT=-2.418+0.235*_ebwCalcS-1.3e-4*_ebwCalcS^2
		OCall [xsi].statLineal::StatLin.compararMultipleD,3, PT, @fSlv8((Pb+Pv)*0.11)
    endif

endm
_comunicationPost macro
	; comunications during integration every CINT   (Comunication interval
endm

_levantaVariables macro
	troncal2 1
	nvvvar = nvaL
;	%echo %nvvvar
;	%echo %nvvaL
	
endm

_cargaVariables macro
	troncal2 2
endm

troncal2 macro tp
	troncal_variable AcTsF, tp ,<*1.0> 
	troncal_variable FaTsF, tp,<*1.0>
	troncal_variable TsFaF, tp,<*1.0>

	troncal_variable AaPbB, tp,<*1.0>
	troncal_variable PbAaB, tp,<*1.0>
	troncal_variable AaPvV, tp,<*1.0>
	troncal_variable PvAaV, tp,<*1.0>

endm
;--------------------------------------------------------------------------
;	GdmSim
;--------------------------------------------------------------------------
_AcumulaDatos macro
	
    fSlv8 [xbx].etapa = etapa
    fSlv8 [xbx].x = x1;
    fSlv8 [xbx].h = [xsi].h;
       
    fSlv8 [xbx].R8_edad = [xdx].R8_edad;
    fSlv8 [xbx].R8_bw = [xdx].R8_bw;
    fSlv8 [xbx].R8_ebw = [xdx].R8_ebw;
    fSlv8 [xbx].R8_prot = ([xdx].R8_Pb + [xdx].R8_Pv) * 0.110;
        
    fSlv8 [xbx].R8_fat = [xdx].R8_TsF*0.854;[xdx].R8_DMmolfat;0.854;
    fSlv8 [xbx].R8_fpc = [xbx].R8_fat/[xbx].R8_ebw*100.0;
    fSlv8 [xbx].R8_water = [xdx].R8_water;
    fSlv8 [xbx].R8_BDNA = [xdx].R8_BDNA*1000.0;
    fSlv8 [xbx].R8_VDNA = [xdx].R8_VDNA*1000.0;
    fSlv8 [xbx].R8_cAa = [xdx].R8_cAa*1000.0;
    fSlv8 [xbx].R8_cGl = [xdx].R8_cGl*1000.0;
    fSlv8 [xbx].R8_cAc = [xdx].R8_cAc*1000.0;
    fSlv8 [xbx].R8_cFa = [xdx].R8_cFa*1000.0;

	fSlv8 [xbx].R8_CarWt = [xdx].R8_CarWt;
	fSlv8 [xbx].R8_GutF = [xdx].R8_GutF;
		
   	fSlv8 [xbx].R8_Pb = [xdx].R8_Pb; 	//	kg
	fSlv8 [xbx].R8_Pv = [xdx].R8_Pv;	//	kg
	fSlv8 [xbx].R8_Pt = [xdx].R8_Pb+[xdx].R8_Pv;	//	kg
	
	; en mol Ts	
	fSlv8 [xbx].R8_TsFaF = [xdx].R8_TsFaF; / [xsi].h;
	fSlv8 [xbx].R8_FaTsF = [xdx].R8_FaTsF/3; / [xsi].h;
	fSlv8 [xbx].R8_AcTsF = [xdx].R8_AcTsF/25.69; / [xsi].h;

	fSlv8 [xbx].R8_dprot = [xdx].R8_dprot/[xdx].h;
	fSlv8 [xbx].R8_dwater = [xdx].R8_dwater/[xdx].h;
		
	fSlv8 [xbx].R8_dfat = [xdx].R8_dfat/[xdx].h;

	fSlv8 [xbx].R8_Chor = [xdx].R8_CHor;
	fSlv8 [xbx].R8_Ahor = [xdx].R8_AHor;
	   
	;//17/03/15
	fSlv8 [xbx].R8_AaPbB = [xdx].R8_AaPbB / [xsi].h;*110;
	fSlv8 [xbx].R8_AaPvV = [xdx].R8_AaPvV / [xsi].h;*110;
	fSlv8 [xbx].R8_PbAaB = [xdx].R8_PbAaB / [xsi].h;*110;
	fSlv8 [xbx].R8_PvAaV = [xdx].R8_PvAaV / [xsi].h;*110;
		
	;//01/04/15
	fSlv8 [xbx].R8_relwp = [xdx].R8_dprot*0.11/[xdx].R8_dwater;

    ;//	03/04/15
	fSlv8 [xbx].R8_gain = [xdx].R8_debw;
	fSlv8 [xbx].R8_sintProt =([xdx].R8_AaPbB+[xdx].R8_AaPvV)*110.0\
				/ ([xdx].R8_ebw ^ 0.75);
	
	;//	16/04/15
	fSlv8 [xbx].R8_sintAcTsporc=[xdx].R8_AcTsF/ [xdx].R8_DMAcTsTs\
			/([xdx].R8_AcTsF/ [xdx].R8_DMAcTsTs+[xdx].R8_FaTsF/3.0);
	fSlv8 [xbx].R8_sintFaTsporc=[xdx].R8_FaTsF/3.0/\
			([xdx].R8_AcTsF/ [xdx].R8_DMAcTsTs+[xdx].R8_FaTsF/3.0);
	fSlv8 [xbx].R8_debw = [xdx].R8_debw;

	fSlv8 [xbx].R8_sintAcTsFporc=[xdx].R8_AcTsF/ [xdx].R8_DMAcTsTs /[xdx].R8_dTsF
	
	; 	06/07/15	agragados a ACU  
	fSlv8 [xbx].R8_dprot_kg = [xdx].R8_dprot*0.11;
	fSlv8 [xbx].R8_dfat_kg = [xdx].R8_dfat*0.854;

	; Ruminales 17/08/2015

	fSlv8 [xbx].R8_Pt_kg = ([xbx].R8_Pb+[xbx].R8_Pv)* [xdx].R8_molprot
	fSlv8 [xbx].R8_Pb_kg = [xbx].R8_Pb*[xdx].R8_molprot
	fSlv8 [xbx].R8_Pv_kg = [xbx].R8_Pv*[xdx].R8_molprot
		
    ; 	Cell Size 01/07/2016
    fSlv8 [xbx].R8_cellsizeB=[xbx].R8_Pb*110/[xbx].R8_BDNA
    fSlv8 [xbx].R8_cellsizeV=[xbx].R8_Pv*110/[xbx].R8_VDNA

    .if [xbx].previo != NULL
        mov xcx, [xbx].previo
        assume xcx : $ObjPtr(ACUo)
			
        fSlv8 [xbx].R8_debw = ([xdx].R8_ebw - [xcx].R8_ebw)/[xbx].cint;
        fSlv8 [xbx].R8_dfat = ([xbx].R8_fat - [xcx].R8_fat)/[xbx].cint;
        fSlv8 [xbx].R8_dprot = ([xdx].R8_Pb +[xdx].R8_Pv - [xcx].R8_Pb- [xcx].R8_Pv)/[xbx].cint;
        fSlv8 [xbx].R8_dwater = ([xdx].R8_water - [xcx].R8_water)/[xbx].cint;
			
        assume xcx : nothing
	
        fSlv8 [xbx].R8_dprot_kg = [xdx].R8_dprot*0.11;
    .endif

endm

_AcuDef macro
	DefineVariable R8_edad, REAL8, 0.0
	DefineVariable R8_bw, REAL8, 0.0
	DefineVariable R8_ebw, REAL8, 0.0
	DefineVariable R8_Pb, REAL8, 0.0
	DefineVariable R8_Pv, REAL8, 0.0
	DefineVariable R8_Pt, REAL8, 0.0
	DefineVariable R8_prot, REAL8, 0.0
	DefineVariable R8_fi, REAL8, 0.0
	DefineVariable R8_gain, REAL8, 0.0
	DefineVariable R8_fpc, REAL8, 0.0
	DefineVariable R8_fat, REAL8, 0.0
	DefineVariable R8_water, REAL8, 0.0
	DefineVariable R8_BDNA, REAL8, 0.0
	DefineVariable R8_VDNA, REAL8, 0.0
	
	DefineVariable R8_cAa, REAL8, 0.0
	DefineVariable R8_cGl, REAL8, 0.0
	DefineVariable R8_cAc, REAL8, 0.0
	DefineVariable R8_cFa, REAL8, 0.0

	DefineVariable R8_Aa, REAL8, 0.0
	DefineVariable R8_Gl, REAL8, 0.0
	DefineVariable R8_Ac, REAL8, 0.0
	DefineVariable R8_Fa, REAL8, 0.0
	
	DefineVariable R8_CarWt, REAL8, 0.0
	DefineVariable R8_GutF, REAL8, 0.0

	DefineVariable R8_TsFaF, REAL8, 0.0
	DefineVariable R8_FaTsF, REAL8, 0.0
	DefineVariable R8_AcTsF, REAL8, 0.0
	
	 ;/*************
	 ;* proteína
	 ;*/
	DefineVariable R8_AaPbB, REAL8, 0.0
	DefineVariable R8_AaPvV, REAL8, 0.0
	DefineVariable R8_PbAaB, REAL8 ,0.0
	DefineVariable R8_PvAaV, REAL8, 0.0

	 ;/*******
	 ;* derivadas
	 ;*/
	DefineVariable R8_dprot, REAL8, 0.0
	DefineVariable R8_dwater, REAL8, 0.0
	DefineVariable R8_dfat, REAL8, 0.0
	DefineVariable R8_debw, REAL8, 0.0	;//	16/04/15
	 ;/******************
	 ;* Sanguineas
	 ;*/
	DefineVariable R8_Chor, REAL8, 0.0
	DefineVariable R8_Chor1, REAL8, 0.0
	DefineVariable R8_Ahor, REAL8, 0.0
	DefineVariable R8_Ahor1, REAL8, 0.0
	
	DefineVariable R8_relwp, REAL8, 0.0 ;	//	rel w+a / prot
	DefineVariable R8_sintProt, REAL8, 0.0
	DefineVariable R8_sintAcTsporc, REAL8, 0.0
	DefineVariable R8_sintFaTsporc, REAL8, 0.0

	DefineVariable R8_sintAcTsFporc, REAL8, 0.0

	;**********************************  Calculado
	DefineVariable R8_dprot_kg, REAL8, 0.0
	DefineVariable R8_dfat_kg, REAL8, 0.0
	
	DefineVariable R8_Pt_kg, REAL8, 0.0
	DefineVariable R8_Pb_kg, REAL8, 0.0
	DefineVariable R8_Pv_kg, REAL8, 0.0
	
	DefineVariable R8_cellsizeB, REAL8,0.0
	DefineVariable R8_cellsizeV, REAL8,0.0
	
	;***************************
	;	Ruminales
	;*****************
	DefineVariable R8_RDM, REAL8,0.0	
endm

;--------------------------------------------------------------------------
;	Integ01
;--------------------------------------------------------------------------
;include muestraDM.inc

_mostrarExperimento macro
;	include muestraexp18.inc
endm