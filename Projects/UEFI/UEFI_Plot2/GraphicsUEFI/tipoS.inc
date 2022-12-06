; ==================================================================================================
; Title:   tipoS_PROC.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: GraphicsUEFI support:
;          ObjAsm support for graphics in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================

Method Graphic1.InitSerieS, uses xsi xcx, xeje:dword, xcolor:dword, xmod:dword, xprior:dword
    local fregTLS()
    SetObject xsi
    .if [xsi].moscasS < 6
    	New SerieGraph
    	freg_push xax
    	mov xcx, xax
    	OCall xcx::SerieGraph.Init, xeje, xcolor, xmod, xprior      			;Initialize Puntito instance values
    	freg_pop xcx
    	mov xax,[xsi].moscasS
    	lea xdx, [xsi].puntosS
    	mov [xdx+xax*@WordSize], xcx
    	inc xax
    	mov [xsi].moscasS, xax
    .endif
MethodEnd

Method Graphic1.CargaPuntoS, uses xsi, p: dword, x:REAL8, y: REAL8
	SetObject xsi
	mov ecx , p
   	lea xdx, [xsi].puntosS
   	mov xax, [xdx+xcx*@WordSize]
	OCall xax::SerieGraph.CargaPunto, x, y 
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
	
Method Graphic1.graficaS, uses xsi
 	local inicio0 : dword
	local estebrush:dword
	local estepen:dword
	local estedot:dword
	local esteeje:dword
	local estecolor:dword

    local v1: xword, v1_t:xword
    SetObject xsi

    ForLp_df v1, 0, [xsi].moscasS

        mov xcx, [xsi].puntosS[xax*@WordSize]
buscase1a:	
    	.if xcx != NULL
    		mov [xsi].dotp, 0
    
    		m2m [xsi].Dot , [xcx].OA_SerieGraph.Dot, xax
    		m2m [xsi].modo, [xcx].OA_SerieGraph.Modo, xax
    		m2m [xsi].color, [xcx].$Obj(SerieGraph).Color, xax
    		mov esteeje, 0 	
    		mov [xsi].yadibujo, FALSE
    	
    		.if [xsi].arranque == 0
    			mov inicio0 , TRUE
    		.else
    			mov inicio0 , FALSE
    		.endif
    		SetObject xax, $Obj(LinkedList), [xcx].$Obj(SerieGraph).Puntos
    		mov xcx, xax
    		freg_push xax
    
    		OCall xax::LinkedList.GetFirst
    		mov _ecx, xax
    buscase2a:	
    		.if _ecx != NULL
                .if inicio0 == TRUE
                    OCall xsi.dibujaS, esteeje, _ecx  ; en ecx va el puntero
                .else
                    	mov inicio0 , TRUE
                .endif
    		
    		  freg_pop xax
    		  freg_push xax	
    	 	  OCall xax::LinkedList.GetNext
    		  mov _ecx, xax
    		  jmp buscase2a
    		.endif
    		freg_pop xax
        .endif		
	Next v1

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Method Graphic1.dibujaS, uses xsi xbx, eje:dword, punto:XWORD
   
    local RT:RECT
    LOCAL A1:DWORD, A2:DWORD
	LOCAL a1:sdword, a3:sdword, a4:dword, v2:dword    
	local a1c:dword, a3c:dword
	local a1b:dword, a3b:dword
	
	local q34:POINTER
	local fSlvTLS()
	
	local vt1:POINT
	local vt2:POINT
	local vt3:POINT
	local vt4:POINT

	local ScreenWidth: dword
	local a3R:real4
	
	SetObject xsi
		
	CalculaPuntito 0

	;case SG_Modo_PipeLine
		
        	mov	eax , a3
		add	eax, 7
		mov	a3c , eax;= a3-1;
		mov	eax , a1
		add 	eax, 17
		mov	a1c, eax;=a1-1;
		
		m2m	RT.left , a3, eax
		m2m	RT.bottom , a1c, eax
		m2m	RT.right, a3c, eax
		m2m	RT.top , a1, eax
	
		.if [xsi].yadibujo == FALSE
		
			.if fEQ( [xbx].y, -1 )
				mov [xsi].yadibujo, FALSE
			.else				
				mov [xsi].yadibujo, TRUE
				m2m [xsi].lastx, a3, eax
				m2m [xsi].lasty, a1, eax
			.endif
		.else
			.if fEQ( [xbx].y,-1.0)
				mov [xsi].yadibujo, FALSE
			.else				
				OCall [xsi].Pxm::PixelUEFI.Pipeline,[xsi].lastx,[xsi].lasty, a3, a1, [xsi].color
				m2m [xsi].lastx, a3, eax
				m2m [xsi].lasty, a1, eax
			.endif
		.endif	
				
MethodEnd
