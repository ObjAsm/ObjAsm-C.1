; ==================================================================================================
; Title:   Grilla_PROC.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: GraphicsUEFI support:
;          ObjAsm support for graphics in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================


Method Grilla.CalculaMarcos, uses xsi

	local pxSup:dword, pxInf:dword
	
	SetObject xsi
	
	mov eax, [xsi].pxTitulo
	add eax, [xsi].pxEjeX2
	mov pxSup, eax
	mov [xsi].rEjeY1.top, eax
	mov [xsi].rEjeY2.top, eax
	mov [xsi].rEjeX2.bottom, eax 
	
	mov [xsi].rArcTL.bottom, eax
	mov [xsi].rArcTR.bottom, eax
	mov [xsi].rDibujo.top, eax
		
	mov eax, [xsi].pxLeyenda
	add eax, [xsi].pxEjeX1
	mov pxInf, eax
		
	mov [xsi].rArcTL.top, 0
	mov [xsi].rArcTR.top, 0
	mov [xsi].rTitulo.top, 0
	mov eax, [xsi].pxTitulo
	mov [xsi].rTitulo.bottom, eax
	mov [xsi].rEjeX2.top, eax 

	mov [xsi].rArcTL.left, 0
	mov [xsi].rArcBL.left, 0
	mov [xsi].rEjeY1.left, 0
	mov eax, [xsi].pxEjeY1
	mov [xsi].rArcTL.right, eax
	mov [xsi].rArcBL.right, eax
	mov [xsi].rDibujo.left, eax
	mov [xsi].rTitulo.left, eax
	mov [xsi].rLeyenda.left, eax
	mov [xsi].rEjeY1.left, eax
	mov [xsi].rEjeX1.left, eax
	mov [xsi].rEjeX2.left, eax

	mov eax, [xsi].Pxm.dWidth
	mov [xsi].rArcTR.right, eax
	mov [xsi].rArcBR.right, eax
	mov [xsi].rEjeY2.right, eax
	sub eax, [xsi].pxEjeY2
	mov [xsi].rArcTR.left, eax
	mov [xsi].rArcBR.left, eax
	mov [xsi].rDibujo.right, eax
	mov [xsi].rTitulo.right, eax
	mov [xsi].rLeyenda.right, eax
	mov [xsi].rEjeY2.left, eax
	mov [xsi].rEjeX1.right, eax
	mov [xsi].rEjeX2.right, eax

	mov eax, [xsi].Pxm.dHeight
	mov [xsi].rArcBR.bottom, eax
	mov [xsi].rArcBL.bottom, eax
	mov [xsi].rLeyenda.bottom, eax
	sub eax, pxInf
	mov [xsi].rArcBR.top, eax
	mov [xsi].rArcBL.top, eax
	mov [xsi].rDibujo.bottom, eax
	mov [xsi].rEjeX1.top, eax
	mov [xsi].rEjeY1.bottom, eax
	mov [xsi].rEjeY2.bottom, eax

	mov eax, [xsi].Pxm.dHeight
	sub eax, [xsi].pxLeyenda
	mov [xsi].rLeyenda.top, eax
	mov [xsi].rEjeX1.bottom, eax
	
	mov eax, [xsi].pxEjeY1
	.if eax > pxSup
		mov eax, pxSup
	.endif	
	.if eax > pxInf
		mov eax, pxInf
	.endif
	.if eax > [xsi].pxEjeY2
		mov eax, [xsi].pxEjeY2
	.endif
	mov [xsi].pxx1Arc, eax
	mov [xsi].pxy1Arc, eax
	mov [xsi].pxArc, eax
	sub eax, [xsi].pxArcMargin
	mov [xsi].pxcArc, eax

	mov eax, [xsi].Pxm.dWidth
	sub eax, [xsi].pxArc
	mov [xsi].pxx2Arc, eax

	mov eax, [xsi].Pxm.dHeight
	sub eax, [xsi].pxArc
	mov [xsi].pxy2Arc, eax
	
	mov eax, [xsi].rDibujo.right
	sub eax, [xsi].rDibujo.left
	mov [xsi].dCentrow, eax
	shr eax,2
	mov ecx, [xsi].rDibujo.left
	add ecx, eax
	mov [xsi].pxx1Line, ecx
	mov ecx, [xsi].rDibujo.right
	sub ecx, eax
	mov [xsi].pxx2Line, ecx

	
	mov eax, [xsi].rDibujo.bottom
	sub eax, [xsi].rDibujo.top
	mov [xsi].dCentroh, eax
	shr eax,2
	mov ecx, [xsi].rDibujo.top
	add ecx, eax
	mov [xsi].pxy1Line, ecx
	mov ecx, [xsi].rDibujo.bottom
	sub ecx, eax
	mov [xsi].pxy2Line, ecx

MethodEnd

