; ==================================================================================================
; Title:   ModeloC.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================


Object modeloC , , modeloB
	
    DefineVariable ntrat, dword, 0
    DefineVariable nentrat, dword, 0

    %_variables
    %_metodos
	
    DefineVariable	estados, dword , nestados

    RedefineMethod	zzderiv, REAL8,  dword, REAL8
    RedefineMethod	zzCalcula
    RedefineMethod	vuelca

    RedefineMethod  inicia
    RedefineMethod  Muestra
ObjectEnd

if IMPLEMENT
.data
%	_modelodata;1 equ 1

.code

   
Method modeloC.zzderiv, uses xsi xbx, x: REAL8, paso:dword, h5:REAL8 

    SetObject xsi
	
    _deriv

    mov	xcx , nestados -1 ;topebucle
iniloopm1:
    if estadotriple
        imul		xax , xcx, 3 
        fSlv8 [xsi].zv[xcx*8] = [xsi].firstderivate[xax*8]
    else
        fSlv8 [xsi].zv[xcx*8] = [xsi].R8_dedad[xcx*8]
    endif
    dec xcx
    jnl iniloopm1

MethodEnd

Method modeloC.zzCalcula, uses xsi 
	
	local _ebwCalcS : REAL8
	local WAT : REAL8
	local _FAT : REAL8
	local PT : REAL8
	local _gral1 : real8, _gral2 : real8
	local fSlvTLS(,24)
	
	
	SetObject xsi

	_calcula		
		
MethodEnd

Method modeloC.vuelca, uses xsi

    SetObject xsi
	
    mov  xcx, nestados - 1
    iniloopm2:
    if estadotriple
        imul	xax, xcx, 3 
        fSlv8 [xsi].firststate[xax*8] = [xsi].yv[xcx*8] 
    else
        fSlv8 [xsi].R8_edad[xbx*8] = [xsi].yv[xbx*8] 
    endif
    dec xcx
    jnl iniloopm2

MethodEnd

Method modeloC.inicia, uses xsi xbx
	local fSlvTLS()
	local fregTLS()
	SetObject xsi

	_inicial
	
MethodEnd

_calculations

Method modeloC.Muestra, uses xsi
	local v1 : dword
	SetObject xsi
	MuestraEstados
MethodEnd

endif

