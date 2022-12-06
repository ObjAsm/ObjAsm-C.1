; ==================================================================================================
; Title:   ModeloB.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

Ifndef neqqu
   neqqu    equ   65 
endif

Object modeloB, , Primer

    DefineVariable    tipo, dword, 0
    DefineVariable    ID, dword, 0
    DefineVariable    pName, dword, NULL

    DefineVariable    iniciado, dword, 0
	
    DefineVariable 	  zv, REAL8, neqqu dup  (0.0)
    DefineVariable 	  yv, REAL8, neqqu dup  (0.0)
 
    VirtualAbstract	  zzderiv, REAL8,  dword, REAL8
    VirtualAbstract	  zzCalcula
    VirtualAbstract	  vuelca

    VirtualAbstract    inicia
    VirtualAbstract    Muestra

    if HaceEstadisticas
        Embed	statLineal , StatLin
    endif
    DefineVariable     x , REAL8 , 0.0
    DefineVariable     limite, dword , 10000	
    DefineVariable     norden, dword , 0	 

    DefineVariable     h,   REAL8, 0.0

    DefineDD           estabilizando, 0
  
ObjectEnd
