; ==================================================================================================
; Title:   Graphic1_PROC.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: GraphicsUEFI support:
;          ObjAsm support for graphics in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Graphic1.Init
; Purpose:   Initialize the Graphic1 object.
; Arguments: Arg1: -> Owner object.
;            Arg2: Screen Buffer.
;            Arg3: horizontal buffer size
;            Arg4: vertical buffer size
;            Arg5: buffer delta parameter
; Return:    Nothing.

Method Graphic1.Init, uses xsi, pOwner:POINTER, screen1: POINTER, x1:dword, y1: dword, delta1:xword
    local dim: dword
    local rect : RECT

    DbgText "Graphic1.Init"
	SetObject xsi
   
	ACall xsi.Init, pOwner, screen1, x1, y1, delta1

	lea xcx, [xsi].ColorSeries
 	mov dword ptr [xcx+0*4], 0FF0000FFh
	mov dword ptr [xcx+1*4], 0FF00FF00h
	mov dword ptr [xcx+2*4], 0FFFFFF00h
	mov dword ptr [xcx+3*4], $RGB(255,  0,255,255)
	mov dword ptr [xcx+4*4], $RGB(255,128,128,255)
	mov dword ptr [xcx+5*4], $RGB(255,255,255,255)

MethodEnd

Method Graphic1.Paint, uses xsi
  
    SetObject xsi
    
    
        ife run_in_VirtualBox
            OCall [xsi].Pxm::PixelUEFI.FillBkGnd, $RGB(  0,  0, 68, 255)
        endif
	
	OCall xsi.CalculaMarcos
	OCall xsi.BuscaMaximos
	OCall xsi.grilla
		
	OCall xsi.HaceEjesY
	OCall xsi.HaceEjesX
	OCall xsi.PoneSeries

	OCall xsi.graficaS

MethodEnd

;======================================================================
	comparaMaximo macro
		.if inicio == TRUE
			compvalR [xbx].x, [xsi].minimox 
			.if ( ah & FP_LESSTHAN)
				fld     [xbx].x
				fstp	[xsi].minimox
			.endif 
			compvalR [xsi].maximox , [xbx].x 
			.if ( ah & FP_LESSTHAN)
				fld     [xbx].x
				fstp	[xsi].maximox
			.endif 
			
			compvalR  [xbx].y, [xsi].minimoy 
			.if ( ah & FP_LESSTHAN)
				fld	    [xbx].y
				fstp	[xsi].minimoy
			.endif 
			
			compvalR  [xsi].maximoy, [xbx].y
			.if ( ah & FP_LESSTHAN)
				fld	    [xbx].y
				fstp	[xsi].maximoy
			.endif 
		.else
			mov inicio , TRUE
		.endif
		fld	    [xsi].maximox
		fadd	[xsi].minimox
		fdiv 	dos
		fstp	[xsi].meanx
	
		fld	    [xsi].maximoy
		fadd	[xsi].minimoy
		fdiv 	dos
		fstp	[xsi].meany
	
	endm

Method Graphic1.BuscaMaximos, uses xsi xbx xdi
    local v1 : xword, v1tope : xword
    local j : xword
    local inicio : dword, inicioP : dword
    
    SetObject xsi
    
    ForLp j, 0, maxejes-1 
        fld   [xsi].minmin
        fst   [xsi].minimoy[xax*8]
        fstp  [xsi].minimox
	    
        fld   [xsi].maxmax
        fst   [xsi].maximoy[xax*8]
        fstp  [xsi].maximox
    Next j
	
	.if [xsi].moscasS > 0
		.if [xsi].arranque == 0
			mov	inicioP, TRUE
		.else
			mov inicioP, FALSE
		.endif
	 	mov	 	xax , [xsi].moscasS
	 	dec		xax
	 	mov	 	v1tope , xax
		ForLp v1, 0, v1tope
			m2m inicio, inicioP, xax
			mov xcx , v1
			mov xcx , [xsi].puntosS[xcx*sizeof(POINTER)]
			lea xax , [xcx].$Obj(SerieGraph).Puntos
			freg_push	xax
			OCall xax::LinkedList.GetFirst
			mov xcx , xax
			.if xcx == NULL
			.else	
				.repeat
					SetObject xbx, Puntito, xcx
					comparaMaximo
            		freg_pop	xax
					freg_push	xax
					OCall xax::LinkedList.GetNext
					mov	xcx , xax
			 	.until xcx == NULL
			.endif
			freg_pop xax
		Next v1
	
	.endif	

MethodEnd

Method Graphic1.Clear, uses xsi
	
    local v1 : xword

    SetObject xsi
	
    .if [xsi].moscasS > 0
        ForLp v1 , 0, [xsi].moscasS
            OCall [xsi].puntosS[xax*4]::LinkedList.Clear
        Next v1
    .endif
MethodEnd

Method Graphic1.PoneSeries, uses xsi 
	
	local v1 : xword, v1_t: xword
	local RTl : RECT
	local point1:POINT
	
	SetObject xsi
	
	ForLp_df v1, 0, [xsi].moscasT

 		fSlv4 RTl.left = [xsi].rLeyenda.left +[xsi].dCentrow/[xsi].moscasT*(v1)+2 
 		fSlv4 RTl.right = [xsi].rLeyenda.left+[xsi].dCentrow/[xsi].moscasT*(v1+1)-2  
		fSlv4 RTl.top = [xsi].rLeyenda.bottom - ([xsi].pxLeyenda)*5/6
		fSlv4 RTl.bottom = [xsi].rLeyenda.bottom - ([xsi].pxLeyenda)/6
		
		OCall [xsi].Pxm::PixelUEFI.FillRect, addr RTl, $RGB(0, 0, 0, 64)
		
		OCall [xsi].Pxm::PixelUEFI.DrawLine,RTl.left,RTl.top, RTl.right, RTl.top, $RGB(126,126,126,255)
		OCall [xsi].Pxm::PixelUEFI.DrawLine,RTl.left,RTl.bottom,RTl.right,RTl.bottom, $RGB(126,126,126,255)

		OCall [xsi].Pxm::PixelUEFI.DrawLine,RTl.left, RTl.top, RTl.left,RTl.bottom, $RGB(126,126,126,255)
		OCall [xsi].Pxm::PixelUEFI.DrawLine,RTl.right, RTl.top,RTl.right,RTl.bottom, $RGB(126,126,126,255)

 		
 		fSlv4 RTl.left = [xsi].rLeyenda.left +[xsi].dCentrow/[xsi].moscasT*(v1)+25 
 		fSlv4 RTl.right = [xsi].rLeyenda.left+[xsi].dCentrow/[xsi].moscasT*(v1)+50  
		fSlv4 RTl.top = [xsi].rLeyenda.bottom - ([xsi].pxLeyenda)*2/3
		fSlv4 RTl.bottom = [xsi].rLeyenda.bottom - ([xsi].pxLeyenda)/3
	
		OCall [xsi].Pxm::PixelUEFI.FillRect,addr RTl, $RGB(98,98,98,255)
		
		inc	RTl.left
		dec	RTl.right
		inc	RTl.top
		dec	RTl.bottom

		mov	xax , v1
		mov eax,[xsi+xax*4].ColorSeries
		OCall [xsi].Pxm::PixelUEFI.FillRect,addr RTl, eax

		fSlv4 point1.x = [xsi].rLeyenda.left +([xsi].rLeyenda.right - [xsi].rLeyenda.left)/[xsi].moscasT*(v1+0.5) 
		fSlv4 point1.y  = ([xsi].rLeyenda.bottom + [xsi].rLeyenda.top)/2
		
		mov	_ecx , v1
		OCall [xsi].Pxm::CharsUEFI.DrawStr, [xsi].tituloSerie[_ecx*@WordSize], point1,\
		                $RGB(200,200,200,255), NULL, NULL, 0
	Next v1
MethodEnd
	
