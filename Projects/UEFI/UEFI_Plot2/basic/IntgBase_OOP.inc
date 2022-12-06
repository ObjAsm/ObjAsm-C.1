; ==================================================================================================
; Title:   IntgBase_OOP.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.1
; Purpose:  Object declaration - IntegAsm32 Light
;          Version 1.0.1, July 2016
;            - multiple instance of the model running at same interval

; ==================================================================================================
ife estadotriple
	neqqu 	equ 65	; es el número máximo de variables de estado  
endif

ifndef nvvar
    nvvar	equ 47	; es el número máximo de variables intermedias que se están "integrando"
endif                ; ahora lo puede decir el modelo
iibu	equ 6+1	; numero máximo de pasos de la integración	6=Cash-Karp

;GdmRkID equ 2000

Object IntgBase, , Primer
	DefineVariable	corrida, xword, 0;
	
	DefineVariable 	integrales, REAL8, neqqu dup (0.0) 
	DefineVariable 	derivadas, REAL8, neqqu dup (0.0) 

	DefineVariable		k_1 , REAL8 , neqqu dup (0.0); 	**       
	DefineVariable		k_2 , REAL8 , neqqu dup (0.0);	  *      Runge - Kutta
	DefineVariable		k_3 , REAL8 , neqqu dup (0.0);	  *
	DefineVariable		k_4 , REAL8 , neqqu dup (0.0); 	**
	DefineVariable		k_5 , REAL8 , neqqu dup (0.0);		**	
	DefineVariable		k_6 , REAL8 , neqqu dup (0.0);		   *
	DefineVariable		y_5 , REAL8 , neqqu dup (0.0);		   *   Cash - Karp
	DefineVariable		y_6 , REAL8 , neqqu dup (0.0);		   *
	DefineVariable		err , REAL8 , neqqu dup (0.0);		   *   
	DefineVariable		tol , REAL8 , neqqu dup (0.0);		**
	DefineVariable		yy  , REAL8 , neqqu dup (0.0);	
	DefineVariable		y   , REAL8 , neqqu dup (0.0);
	DefineVariable		d   , REAL8 , neqqu dup (0.0)
	;DefineVariable		dydx, REAL8, neqqu dup (0.0);
	
	DefineVariable		_mm_, REAL8 , iibu*nvvar dup (0.0)     ; Solamente para un animal !!
	
	DefineVariable		x , REAL8, 0.0;   //new double[anim];
	DefineVariable		h , REAL8, 0.0;   //new double[anim];
	DefineVariable		nequ , xword, 11; //new double[anim];
	DefineVariable		anim , xword,  6; //new double[anim];
	
	DefineVariable		paso, xword, 0
	DefineVariable		counter, xword, 0
	
	DefineVariable		cint, REAL8, 1.0

	DefineVariable		acum, POINTER, 0 
	DefineVariable		acumInt, POINTER, 0 
		
	VirtualAbstract CargaVector
	;%echo @CatStr(<    >, <SoloEstados = >,%SoloEstados)  
	IFE SoloEstados
		;echo "Activado Carga Derivada"
		VirtualAbstract CargaDerivada
		VirtualAbstract CargaVariables
		VirtualAbstract LevantaVariables, xword
	ENDIF

	VirtualAbstract CargaAcu, xword, REAL8  
	VirtualAbstract Tratamiento, REAL8
	VirtualAbstract Resultado, REAL8
	
	VirtualMethod   timestep, REAL8, REAL8, REAL8
	VirtualMethod   RK4, REAL8, REAL8, REAL8
	; tanda: xword, x0: REAL8,  xn:REAL8, h:REAL8, maxiter: xword,reltol:REAL8, abstol:REAL8
	VirtualMethod   CashKarpI, xword, REAL8, REAL8, REAL8, xword, REAL8, REAL8
	VirtualMethod   Fehlberg,  REAL8, REAL8, REAL8, xword, REAL8, REAL8

	; 08/07/2016
	DefineVariable  modelo  , $ObjPtr(modeloB), NULL
	DefineVariable  auxiliar, $ObjPtr(modeloB), NULL
	
	DefineVariable  ajustando, xword, FALSE
       ; 01/10/2017
	DefineVariable  CINTactivado, xword, 0	
	; 04/12/2017
	VirtualMethod   circletime, xword, xword, REAL8, REAL8, xword
	VirtualAbstract CargaCircle
	if 0
	VirtualMethod Acumulacion_vacia, xword
	VirtualMethod Acumulacion_carga, xword
	endif
    DefineVariable initial, xword, FALSE
ObjectEnd

.data

ifndef start1
	start1	REAL8 180.0
	end1	REAL8  30.0
	step1	REAL8 1.0
	
	cero1	REAL8 0.1
	cuatro	REAL8 4.0
	seis	REAL8 6.0
	tres	REAL8 3.0
	tempR8 	REAL8 0.0
endif

	Carga_el_acumuladorI macro orden:REQ
	    if orden eq 0
			mov		[xsi].paso , 0
		else
			inc 	[xsi].paso
		endif
		;DbgText	"Carga_el_acumuladorI"	
		.if [xsi].CINTactivado == FALSE
		if orden eq 0
		 .if [xsi].initial == TRUE 
		endif    
			.if [xsi].ajustando == FALSE
			    
				f2f [xsi].h , h
				mov	xbx , [xsi].modelo
				.if fLE(x, [xbx].$Obj(modeloB).limite)
					OCall xsi.CargaAcu, [xsi].paso, x
				.endif
			.endif
			OCall xsi.Resultado, x
		if orden eq 0
		 .endif
		endif
		.endif
	endm

