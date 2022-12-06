; ==================================================================================================
; Title:   PixelMacros.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: PixelUEFI support:
;          ObjAsm support for drawing in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================
	_swap macro a , b
		mov eax, a
		mov edx, b
		mov a, edx
		mov b, eax
	endm

	blend macro reg1 , color1
		mov edx, reg1
		and edx , 00000FFh
		mov ecx, color1
		and ecx , 00000FFh
		add ecx, eax
		shr ecx, 1
		push rcx	
	
		mov edx, reg1
		and edx , 000FF00h
		mov ecx, color1
		and ecx , 000FF00h
		add ecx, eax
		shr ecx, 1
		and ecx , 000FF00h
		push rcx	
	
		mov edx, reg1
		and edx , 0FF0000h
		mov ecx, color1
		and ecx , 0FF0000h
		add ecx, eax
		shr ecx, 1
		and ecx , 0FF0000h
		pop rax
		add ecx, eax	
		pop rax
		add ecx, eax	
	endm

    blendpixel macro x1, y1, c1
		mov xdi , [xsi].pPixels
		mov eax , y1
		mov ecx , [xsi].dDelta
		mul ecx 
		add xdi , xax
		mov eax , x1
		shl xax , 2
		add xdi , xax
		mov eax , dword ptr [xdi]
		blend eax , c1
		mov dword ptr [xdi], ecx
    endm

	takecolor macro color, cc1, cc2, cc3, cc4:=<cc4>
		mov eax , color
		and eax , 00000FFh
		mov cc3, eax
		mov eax , color
		and eax , 000FF00h
		shr eax, 8
		mov cc2, eax
		mov eax , color
		and eax , 0FF0000h
		shr eax, 16
		mov cc1, eax
		mov eax , color
		and eax , 0FF000000h
		shr eax, 24
		mov cc4, eax
	endm

   	remakecolor macro dilucion, cc1, cc2, cc3, cc4, c1f
		fSlv8 gral1px = dilucion
        fld   gral1px
		fld   st
		fld   st
		fimul cc1
		fistp c1 
		fimul cc2
		fistp c2 
		fimul cc3
		fistp c3
		mov eax, c1
		shl eax, 8
		add eax, c2
		shl eax, 8
		add eax, c3

		mov ecx, cc4
		shl ecx, 24
		add eax, ecx
		mov c1, eax     ; why is wrong
	endm

   	remakecolorbk macro dilucion, cc1, cc2, cc3, cc4, c1f
		fSlv8  gral1px = dilucion
        fld   gral1px
		fld   st
		fld   st
		fimul cc1
		fistp c1 
		fimul cc2
		fistp c2 
		fimul cc3
		fistp c3

        fld1
        fsub  gral1px
		fld   st
		fld   st
		fimul ff1
		fistp f1 
		fimul ff2
		fistp f2 
		fimul ff3
		fistp f3
		
		mov eax, c1
		add eax, f1
		and eax, 0FFh
		mov ecx, eax
		shl ecx, 8
		
		mov eax, c2
		add eax, f2
		and eax, 0FFh
		add ecx, eax
		shl ecx, 8

		mov eax, c3
		add eax, f3
		and eax, 0FFh
		add ecx, eax
		
		mov eax, cc4
		add eax, ff4
		and eax, 0FFh
		shl eax, 24
		add ecx, eax
		
		mov &c1f, ecx
	endm

    setpixel macro x1, y1, c1
        mov xdi , [xsi].pPixels
        mov eax , y1
        mov ecx , [xsi].dDelta;total.right
        mul ecx 
        add xdi , xax
        mov eax , x1
        shl eax , 2
        add xdi , xax
        mov ecx , c1
        mov dword ptr [xdi], ecx;0FF00FFh
    endm