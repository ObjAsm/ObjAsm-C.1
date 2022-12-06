; ==================================================================================================
; Title:   Graphic_PROC.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: GraphicsUEFI support:
;          ObjAsm support for graphics in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Graphic0.Init
; Purpose:   Initialize Graphic0 object.
; Arguments: Arg1: -> Owner object.
;            Arg2: Screen Buffer.
;            Arg3: horizontal buffer size
;            Arg4: vertical buffer size
;            Arg5: buffer delta parameter
; Return:    Nothing.

Method Graphic0.Init, uses xsi, pOwner:POINTER, screen1: POINTER, x1:dword, y1: dword, delta1:xword
 
	SetObject xsi
   
	ACall xsi.Init, pOwner

	New Eje_gr1
	mov [xsi].BaseEjesY[0*sizeof(POINTER)], xax
	assume xax : ptr $Obj(Eje_gr1)
		lea xcx, tituloy1
		mov [xax].titulo, xcx
	assume xax : nothing
	
	OCall [xsi].Pxm::PixelUEFI.Init, screen1, x1, y1, delta1
	
MethodEnd

Method Graphic0.Done, uses xsi
	
    SetObject xsi

    OCall [xsi].Pxm::PixelUEFI.Done
    
    ACall xsi.Done

MethodEnd

Method Graphic0.grilla, uses xsi

	local v2:dword, a3:dword, a3f:real8
	local A1:dword, c3 : dword, A2:dword
	
	local paso:dword
		
	SetObject xsi
	
	OCall [xsi].Pxm::PixelUEFI.FillRect, addr [xsi].rDibujo, $RGB(0, 0, 0, 64)

	mov a3, 10
	fSlv8 a3f = 10.0
	
	mov c3 , $RGB(100,100,100,255)
	 
	mov paso, 1 
	ForLp v2, 0, a3, eax

			; grilla Horizontal
			finit
			;fp_roundnearest
			fild	[xsi].dCentroh
			;fisub	[xsi].pxcabecera
			fdiv	a3f
			fimul	v2
			fiadd	[xsi].rDibujo.top
			;fiadd	[xsi].pxpie
			;fadd
			fistp	A1
			mov eax, A1
			;add eax, 20
			mov A2, eax

		OCall [xsi].Pxm::PixelUEFI.BresLine2, [xsi].rDibujo.left, A1,[xsi].rDibujo.right, A2, c3  
  
	Next v2	

MethodEnd

Method Graphic0.HaceEjesX, uses xsi
	
	local lbuffer[32]:CHR
	local A1 : dword
	local point1:POINT
	local v2R:real8
	local c3:dword

	LOCAL tramo:XWORD, saltos:xword
	local fSlvTLS()
	
	DbgText "Graphic0.HaceEjesX"
	SetObject xsi
		
	fSlv8 [xsi].escalax = [xsi].dCentrow/([xsi].maximox-[xsi].minimox)
	fSlv tramo = trunc([xsi].intervalox * [xsi].escalax)
	
	mov xax, 24
	.if tramo > xax
		mov saltos, 0
	.else
		fSlv saltos = trunc(tramo/xax)+1	 
	.endif
	mov tramo , 0	

	mov c3 , $RGB(90,90,90,255)
	
	mov eax, [xsi].pxEjeX2
	shr eax, 2
	mov ecx, 3
	mul ecx
	add eax, [xsi].rEjeX2.top
	sub eax, 5
	mov point1.y, eax
  	
  	ForLpR v2R, [xsi].minimox, [xsi].maximox, [xsi].intervalox;a5R, afR, 1.00

		finit
		fld	v2R
		fsub	[xsi].minimox
		fld 	st
		fmul	[xsi].escalax
		fiadd	[xsi].rDibujo.left
		fist	point1.x
		Fistp	A1;	(int) Math.floor(posix + (v2 - inicio + 1)* escalax), 
		
		OCall [xsi].Pxm::PixelUEFI.BresLine2, A1, [xsi].rDibujo.top, A1, [xsi].rDibujo.bottom, c3  

		.if tramo == 0	
			fld	v2R
			fRnd
			fst	[xsi].escala0
			invoke St0ToStr, addr lbuffer, 4, 0, f_NOR
			fstp st(0)

			OCall [xsi].Pxm::CharsUEFI.DrawStr, addr lbuffer, point1,\
		                $RGB(200,200,200,255), NULL,NULL, 0
						
		.endif
		inc tramo
		mov xax, saltos
		.if tramo > xax
			mov tramo, 0
		.endif

	NextR v2R

	OCall [xsi].Pxm::PixelUEFI.BresLine2, [xsi].rDibujo.right, [xsi].rDibujo.top, [xsi].rDibujo.right, [xsi].rDibujo.bottom, c3  

MethodEnd

	haceY macro
		
		mov point.x, 10
		mov point.y, 20
		mov xcx, [xsi].BaseEjesY[xax*sizeof(POINTER)]
		OCall [xsi].Pxm::CharsUEFI.DrawStr, [xcx].Eje_gr1.titulo, point, RGB$(200,200,200,255), NULL, NULL, 1
	endm
	
Method Graphic0.HaceEjesY, uses xsi
	
	local i:dword, j:dword
	local point1:POINT
	local rect1:RECT
	
	local lbuffer[32]:CHR
	local A1 : dword
	local a3f:real8
	local fSlvTLS()
	
	DbgText "Graphic0.HaceEjesY" 

	SetObject xsi
	
	mov eax, [xsi].pxEjeY1
	shr eax, 2
	mov point1.x, eax
	shr eax, 1
	mov rect1.left, eax
	shl eax, 1
	mov ecx, eax
    shr ecx, 1
	add eax, ecx
	;sub eax, 2
	mov rect1.right, eax
		
	mov eax, [xsi].dCentroh
	shr eax, 1
	add eax, [xsi].rDibujo.top
	mov point1.y, eax

	mov eax, [xsi].rDibujo.top
	mov rect1.top, eax

	mov eax, [xsi].rDibujo.bottom
	mov rect1.bottom, eax
		
	OCall [xsi].Pxm::PixelUEFI.FillRect, addr rect1, $RGB(0, 0, 0, 64)
	
	OCall [xsi].Pxm::PixelUEFI.DrawLine,rect1.left,rect1.top, rect1.right, rect1.top, $RGB(126,126,126,255)
	OCall [xsi].Pxm::PixelUEFI.DrawLine,rect1.left,rect1.bottom,rect1.right,rect1.bottom, $RGB(126,126,126,255)

	OCall [xsi].Pxm::PixelUEFI.DrawLine,rect1.left, rect1.top, rect1.left,rect1.bottom, $RGB(126,126,126,255)
	OCall [xsi].Pxm::PixelUEFI.DrawLine,rect1.right, rect1.top,rect1.right,rect1.bottom, $RGB(126,126,126,255)





	mov xax, 0
	mov _ecx, [xsi].BaseEjesY[xax*sizeof(POINTER)]
		
    .if [_ecx].OA_Eje_gr1.titulo
		OCall [xsi].Pxm::CharsUEFI.DrawStr, [_ecx].OA_Eje_gr1.titulo, point1,\
		                $RGB(200,200,200), NULL, NULL, 1
	.endif

	fSlv8 [xsi].escalay = [xsi].dCentroh/([xsi].maximoy-[xsi].minimoy)
		
	fSlv8 a3f = 10.0

	mov eax, [xsi].pxEjeY1
	sub eax, 40
	mov point1.x, eax

	ForLp j, 0, 10, eax
		fild	[xsi].dCentroh
		fdiv	a3f
		fimul	j
		fiadd	[xsi].rDibujo.top
		fistp	point1.y
				
		fld    [xsi].maximoy[0*8] 
		fld    st
		fsub	[xsi].minimoy[0*8]
		fdiv	diez
		fimul	j
		fsub 	
		invoke St0ToStr, addr lbuffer, 5, 2, f_NOR
		fstp st(0)
			
		OCall [xsi].Pxm::CharsUEFI.DrawStr, addr lbuffer, point1,\
	                $RGB(200,200,200,255), NULL, NULL, 0
			
	Next j
	
MethodEnd
