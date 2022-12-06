; ==================================================================================================
; Title:   PixelLines.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: PixelUEFI support:
;          ObjAsm support for drawing in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================

horizontal	proc X1:dword,Y1:dword,X2:dword, ScreenWidth:dword, color:dword
		
		mov	eax, X1
		cmp	eax, X2
		jbe	@f

		_swap X1, X2	
		
@@:		
		xor edx , edx
		mov eax , Y1
		mov ecx , ScreenWidth
		mul	ecx 
		mov edx , X1
		shl edx , 2
		add	eax , edx
		mov	edx , eax ; edx = Y1 * ScreenWidth + X1
		xor	ecx , ecx
@@:		
		mov	eax, X2
		sub	eax, X1
		cmp	ecx, eax
		ja	@f
		mov eax , color
		mov xsi, xdi
		push xcx
		shl xcx , 2
		add xsi, xcx
		pop xcx
		add xsi , xdx
		mov	[xsi], eax
		inc	ecx
		jmp	@b
@@:		ret
horizontal	endp

vertical proc X1:dword,Y1:dword,Y2:dword, ScreenWidth:dword, color:dword

		mov	eax, Y1
		cmp	eax, Y2
		jbe	@f

		_swap Y1, Y2
@@:		
		xor edx, edx
		mov eax, Y1
		mov ecx, ScreenWidth
		mul ecx
		mov ecx, X1
		shl ecx, 2
		add	eax, ecx
		mov	edx, eax ;edx = Y1 * ScreenWidth + X1
		xor	ecx, ecx
@@:		
		mov	eax, Y2
		sub	eax, Y1
		cmp	ecx, eax
		ja	@f
		mov eax , color
		mov xsi, xdi
		add xsi , xdx
		mov	[xsi], eax

		add	edx, ScreenWidth
		inc	ecx
		jmp	@b
@@:		ret
vertical endp


Method PixelUEFI.BresLine, uses xsi xdi, X1:sdword,Y1:sdword,X2:sdword,Y2:sdword, color:dword
	 
	local var_4:dword
	local var_8:dword
	local var_C:dword
	local var_10:dword
	local var_14:dword
	local var_18:dword
	;-----------------
	local ScreenWidth : dword
	local buffer1 : dword

	SetObject xsi

    	; Convert RGB to BGR format (Siemanski)

		mov eax, color
		bswap eax
		ror eax, 8
		mov color,  eax
		
		mov ecx, [xsi].dWidth
		shl xcx, 2
		mov ScreenWidth , ecx	; now is width in bytes 
		mov xdi , [xsi].pPixels	; Buffer containing data bits
	
		mov	eax, Y1
		cmp	eax, Y2
		jnz	@f
	
		invoke horizontal, X1, Y1, X2, ScreenWidth, color
		jmp	fin

@@:		mov	eax, X1
		cmp	eax, X2
		jnz	@f
		invoke vertical, X1, Y1, Y2, ScreenWidth, color
		jmp	fin

@@:		mov	eax, X2
		sub	eax, X1
		mov	var_4, eax
		cmp	eax, 0
		jge	@f
		neg	var_4

@@:		mov	eax, Y2
		sub	eax, Y1
		mov	var_8, eax
		cmp	eax, 0
		jge	@f
		neg	var_8

@@:		mov	eax, X1
		cmp	eax, X2
		jge	@f
		mov	var_C, 1
		jmp	loc_401601

@@:		or	var_C, -1

loc_401601:	
		mov	eax, Y1
		cmp	eax, Y2
		jge	@f
		mov	var_10, 1
		jmp	loc_401624

@@:		or	var_10, -1

loc_401624:	
		mov	eax, var_4
		sub	eax, var_8
		mov	var_14, eax

loc_40162F:	
		mov eax, Y1
		xor edx, edx
		mov ecx , ScreenWidth
		mul ecx
		mov ecx , X1
		shl ecx, 2
		add	eax, ecx      ; eax = Y1 * ScreenWidth + X1

		mov xsi, xdi
		add xsi, xax
		m2m	[xsi], color, eax
		mov	eax, X1
		cmp	eax, X2
		jnz	@f
		mov	eax, Y1
		cmp	eax, Y2
		jz	fin

@@:		mov	eax, var_14
		shl	eax, 1
		mov	var_18, eax
		mov	eax, 0
		sub	eax, var_8
		cmp	var_18, eax
		jle	@f
		mov	eax, var_14
		sub	eax, var_8
		mov	var_14, eax
		mov	eax, X1
		add	eax, var_C
		mov	X1, eax

@@:		mov	eax, X1
		cmp	eax, X2
		jnz	@f
		mov	eax, Y1
		cmp	eax, Y2
		jnz	@f
		xor    edx, edx
		mov    eax, Y1
		mov    ecx , ScreenWidth
		mul	ecx
		mov    ecx , X1
		shl   ecx , 2
		add   eax, ecx		; eax = Y1 * ScreenWidth + X1

		mov   xsi , xdi
		add   xsi , xax
		m2m   [xsi], color, eax;color=5
		jmp   fin

@@:		mov	eax, var_18
		cmp	eax, var_4
		jge	loc_40162F
		mov	eax, var_14
		add	eax, var_4
		mov	var_14, eax
		mov	eax, Y1
		add	eax, var_10
		mov	Y1, eax
		jmp	loc_40162F
fin:	
MethodEnd;BresLine	endp

;---------------------------------------------------------------------------------

horizontal2	proc X1:dword, Y1:dword, X2:dword, ScreenWidth:dword, color:dword
		
		mov	eax, X1
		cmp	eax, X2
		jbe	@f

		_swap X1, X2	
		
@@:		
		xor   edx , edx
		mov   eax , Y1
		mov   ecx , ScreenWidth
		mul   ecx 
		mov   edx , X1
		shl   edx , 2
		add   eax , edx
		mov   edx , eax ; edx = Y1 * ScreenWidth + X1
		xor   ecx , ecx
@@:		
		mov   eax, X2
		sub   eax, X1
		cmp   ecx, eax
		ja    @f
		mov   eax , color
		mov   xsi, xdi
		push  xcx
		shl   xcx , 2
		add   xsi, xcx
		pop   xcx
		add   xsi , xdx
		mov   [xsi], xax
		inc   xcx
		jmp   @b
@@:		ret
horizontal2	endp

vertical2 proc X1:dword, Y1:dword, Y2:dword, ScreenWidth:dword, color:dword

		mov	eax, Y1
		cmp	eax, Y2
		jbe	@f

		_swap Y1, Y2
@@:		
		xor   edx, edx
		mov   eax, Y1
		mov   ecx, ScreenWidth
		mul   ecx
		mov   ecx, X1
		shl   ecx, 2
		add   eax, ecx
		mov   edx, eax ;edx = Y1 * ScreenWidth + X1
		xor   ecx, ecx
@@:		
		mov   eax, Y2
		sub   eax, Y1
		cmp   ecx, eax
		ja    @f
		mov   eax , color
		mov   xsi, xdi
		add   xsi , xdx
		mov   [xsi], xax

		add   edx, ScreenWidth
		inc   ecx
		jmp   @b
@@:		ret
vertical2 endp

Method PixelUEFI.BresLine2, uses xsi xdi, X1:sdword,Y1:sdword,X2:sdword,Y2:sdword, color:dword
	local var_4:dword
	local var_8:dword
	local var_C:dword
	local var_10:dword
	local var_14:dword
	local var_18:dword
	;-----------------
	local ScreenWidth : dword
	local buffer1 : dword

	SetObject xsi

		; Convert RGB to BGR format (Siemanski)
		mov eax, color
		bswap eax
		ror eax, 8
		mov color,  eax
		
		; Screen Width in pixels
	
		mov ecx, [xsi].dWidth
		shl xcx, 2
		mov ScreenWidth , ecx	; now is width in bytes 
		mov xdi , [xsi].pPixels	; Buffer containing data bits
	
		mov	eax, Y1
		cmp	eax, Y2
		jnz	@f
		invoke horizontal2, X1, Y1, X2, ScreenWidth, color 
		jmp	fin

@@:		mov	eax, X1
		cmp	eax, X2
		jnz	@f
		invoke vertical2, X1, Y1, Y2, ScreenWidth, color
		jmp	fin

@@:		mov	eax, X2
		sub	eax, X1
		mov	var_4, eax
		cmp	eax, 0
		jge	@f
		neg	var_4

@@:		mov	eax, Y2
		sub	eax, Y1
		mov	var_8, eax
		cmp	eax, 0
		jge	@f
		neg	var_8

@@:		mov	eax, X1
		cmp	eax, X2
		jge	@f
		mov	var_C, 1
		jmp	loc_401601

@@:		or	var_C, -1

loc_401601:	
		mov	eax, Y1
		cmp	eax, Y2
		jge	@f
		mov	var_10, 1
		jmp	loc_401624

@@:		or	var_10, -1

loc_401624:	
		mov	eax, var_4
		sub	eax, var_8
		mov	var_14, eax

loc_40162F:	
		mov   eax, Y1
		xor   edx, edx
		mov   ecx , ScreenWidth
		mul   ecx
		mov   ecx , X1
		shl   ecx, 2
		add   eax, ecx      ; eax = Y1 * ScreenWidth + X1

		mov   xsi, xdi
		add   xsi, xax
		m2m   [xsi], color, eax
		mov   eax, X1
		cmp   eax, X2
		jnz   @f
		mov   eax, Y1
		cmp   eax, Y2
		jz    fin

@@:		mov	eax, var_14
		shl	eax, 1
		mov	var_18, eax
		mov	eax, 0
		sub	eax, var_8
		cmp	var_18, eax
		jle	@f
		mov	eax, var_14
		sub	eax, var_8
		mov	var_14, eax
		mov	eax, X1
		add	eax, var_C
		mov	X1, eax

@@:		mov	eax, X1
		cmp	eax, X2
		jnz	@f
		mov	eax, Y1
		cmp	eax, Y2
		jnz	@f
		xor   edx, edx
		mov   eax, Y1
		mov   ecx, ScreenWidth
		mul   ecx
		mov   ecx, X1
		shl   ecx, 2
		add   eax, ecx		; eax = Y1 * ScreenWidth + X1

		mov   xsi, xdi
		add   xsi, xax
		m2m   [xsi], color, eax;color=5
		jmp   fin

@@:		mov	eax, var_18
		cmp	eax, var_4
		jge	loc_40162F
		mov	eax, var_14
		add	eax, var_4
		mov	var_14, eax
		mov	eax, Y1
		add	eax, var_10
		mov	Y1, eax
		jmp	loc_40162F
fin:	
MethodEnd

;Title: Bresenham's Line Algorithm (DOTTED LINE)
;Description: An algorithm to draw a Dotted Line using Bresenham's Line Drawing Algorithm
;Author: Saideep Dicholkar   widh serious errors!!! 

Method PixelUEFI.DottedLine, uses xsi, x1:sdword,y1:sdword,x2:sdword,y2:sdword, espaciado:dword, dColor:dword
	
    local x:sdword,y:sdword,dxx:sdword,dyy:sdword,i:sdword,e:sdword

	local xinc:sdword,yinc:sdword
 
	SetObject xsi

    mov eax, x2
    sub eax, x1
    mov dxx, eax
    
    mov eax, y2
    sub eax, y1
    mov dyy, eax

    mov eax, x1
    .if (eax < x2)
        mov xinc, 1
    .else
        mov xinc, -1
    .endif
    
    mov eax, y1    
    .if (eax < y2)
        mov yinc, 1 
    .else
        mov yinc, -1
    .endif

  	; Macros ------------------------------------------

		 salta macro var
	            mov eax , &var&inc
	            mov ecx , espaciado
	            imul xcx
	            add eax , &var
	            mov &var , eax
	        endm
	        AbsI macro
			cdq
			xor xax , xdx
			sub xax , xdx
		endm
	proceso_dot macro v1, v2
    	mov	 eax, d&v2&&v2
    	mov	 ecx, espaciado
    	imul ecx
    	sub  eax, d&v1&&v1
    	mov e, eax
        .while (eax > espaciado)
            .if ( e < 0)
	    	    mov  eax, d&v2&&v2
	    	    mov  ecx, espaciado
	    	    imul ecx
                add  eax, e
                mov  e, eax
	        .else
	      	    mov  eax, d&v2&&v2
	      	    sub  eax, d&v1&&v1
	    	    mov  ecx, espaciado
	    	    imul ecx
                add  eax, e
                mov  e, eax
                salta &v2
            .endif
            salta &v1
            blendpixel x, y, dColor
            ; -----------------
            mov  eax , &v1
            sub  eax , &v1&2
            AbsI 
	   .endw
	endm

    ; Algorithm ------------------------------------------
  	
    m2m x, x1, eax
    m2m y, y1, eax
    mov eax, dxx
    .if eax >= dyy
        proceso_dot x, y
    .else
        proceso_dot y, x
    .endif
MethodEnd

;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Method PixelUEFI.horizontal3, uses xbx, X1:dword, Y1:dword, X2:dword, ScreenWidth:dword, color:dword, dot :dword

    SetObject xbx
    		
		mov	eax, X1
		cmp	eax, X2
		jbe	@f

		_swap X1, X2	
		
@@:		
		xor edx , edx
		mov eax , Y1
		mov ecx , ScreenWidth
		mul	ecx 
		mov edx , X1
		shl edx , 2
		add	eax , edx
		mov	edx , eax ; edx = Y1 * ScreenWidth + X1
		xor	ecx , ecx
@@:		
		mov	eax, X2
		sub	eax, X1
		cmp	ecx, eax
		ja	@f
		mov eax , color
		mov esi, edi
		push xcx
		shl ecx , 2
		add esi, ecx
		pop xcx
		add esi , edx

		push xax
		push xcx
		mov eax, 1
		mov ecx, [xbx].dotp
		shl eax, cl
		test dot, eax
		jz salto1
		pop xcx		
		pop xax 
		mov [esi], eax
		jmp salto2
salto1:
		pop xcx		
		pop xax 
salto2:
		inc	ecx
		mov eax, [xbx].dotp
		add eax, 1
		mov [xbx].dotp, eax
		.if [xbx].dotp > 31
			mov [xbx].dotp, 0
		.endif
		jmp	@b
@@:		
MethodEnd

Method PixelUEFI.vertical3, uses xbx, X1:dword, Y1:dword, Y2:dword, ScreenWidth:dword, color:dword, dot :dword

    SetObject xbx

		mov	eax, Y1
		cmp	eax, Y2
		jbe	@f

		_swap Y1, Y2
@@:		
		xor edx, edx
		mov eax, Y1
		mov ecx, ScreenWidth
		mul ecx
		mov ecx, X1
		shl ecx, 2
		add	eax, ecx
		mov	edx, eax ;edx = Y1 * ScreenWidth + X1
		xor	ecx, ecx
@@:		
		mov	eax, Y2
		sub	eax, Y1
		cmp	ecx, eax
		ja	@f
		mov eax , color
		mov xsi, xdi
		add xsi , xdx

		push xax
		push xcx
		mov eax, 1
		mov ecx, [xbx].dotp
		shl eax, cl
		test dot, eax
		jz salto1
		pop xcx		
		pop xax 
		mov	[xsi], eax
		jmp salto2
salto1:
		pop xcx		
		pop xax 
salto2:

		mov eax, [xbx].dotp
		add eax, 1
		mov [xbx].dotp, eax
		.if [xbx].dotp > 31
			mov [xbx].dotp, 0
		.endif
		add	edx, ScreenWidth
		inc	ecx
		jmp	@b
@@:
MethodEnd

Method PixelUEFI.BresLine3, uses xsi xdi xbx, X1:dword,Y1:dword,X2:dword,Y2:dword, color:dword, dot :dword
	local  difX :dword
	local  difY :dword
	local  var_C :dword
	local var_10 :dword
	local difXY :dword
	local difXY2 :dword

	;-----------------
	local ScreenWidth : dword
	local buffer1 : dword

	local doto : byte
	local pdotp : dword
	    
    SetObject xbx

		; Convert RGB to BGR format (Siemanski)
		;mov eax, color
		;bswap eax
		;ror eax, 8
		;mov color,  eax

		mov ecx , [xbx].dWidth	; Screen Width in pixels
		shl ecx, 2
		mov ScreenWidth , ecx	; now is width in bytes 
		mov xdi , [xbx].pPixels; Buffer containing data bits
	
		mov	eax, Y1
		cmp	eax, Y2
		jnz	@f
		
		OCall xbx.horizontal3, X1, Y1, X2, ScreenWidth, color, dot
		jmp	fin

@@:		mov	eax, X1
		cmp	eax, X2
		jnz	@f
		
		OCall xbx.vertical3, X1, Y1, X2, ScreenWidth, color, dot
		jmp	fin

@@:		mov	eax, X2
		sub	eax, X1
		mov	difX, eax
		cmp	eax, 0
		jge	@f
		neg	difX

@@:		mov	eax, Y2
		sub	eax, Y1
		mov	difY, eax
		cmp	eax, 0
		jge	@f
		neg	difY

@@:		mov	eax, X1
		cmp	eax, X2
		jge	@f
		mov	var_C, 1
		jmp	compY;loc_401601

@@:		or	var_C, -1

compY:	
		mov	eax, Y1
		cmp	eax, Y2
		jge	@f
		mov	var_10, 1
		jmp	loc_401624

@@:		or	var_10, -1

loc_401624:	
		mov	eax, difX
		sub	eax, difY
		mov	difXY, eax

loc_40162F:	
		mov eax , Y1
		xor edx , edx
		mov ecx , ScreenWidth
		mul ecx
		mov ecx , X1
		shl ecx, 2
		add	eax, ecx      ; eax = Y1 * ScreenWidth + X1
		push xax
		mov eax, [xbx].dotp
		add eax, 1
		mov [xbx].dotp, eax
		
		.if [xbx].dotp > 31
			mov [xbx].dotp, 0
		.endif 
        pop xax
		mov xsi, xdi
		add xsi, xax

		push xax
		push xcx
		mov  eax, 1
		mov ecx, [xbx].dotp
		shl eax, cl

		test dot, eax
		jz salto1
		pop xcx		
		pop xax 
		m2m	[xsi], color, eax
		jmp salto2
salto1:
		pop xcx		
		pop xax 
salto2:
		mov	eax , X1
		cmp	eax , X2
		jnz	@f
		mov	eax , Y1
		cmp	eax , Y2
		jz	fin

@@:		mov	eax , difXY
		shl	eax , 1
		mov	difXY2, eax
		mov	eax , 0
		sub	eax , difY
		cmp	difXY2, eax
		jle	@f
		mov	eax , difXY
		sub	eax , difY
		mov	difXY , eax
		mov	eax , X1
		add	eax , var_C
		mov	X1 , eax


@@:		mov	eax, X1
		cmp	eax, X2
		jnz	@f
		mov	eax, Y1
		cmp	eax, Y2
		jnz	@f
		xor edx , edx
		mov eax , Y1
		mov ecx , ScreenWidth
		mul	ecx
		mov ecx , X1
		shl ecx , 2
		add	eax , ecx		; eax = Y1 * ScreenWidth + X1

		mov xsi , xdi
		add xsi , xax
		push xax
		push xcx
		mov eax, 1
		mov ecx, [xbx].dotp
		shl eax, cl
		;DbgDec eax
		test dot, eax
		jz salto1b
		pop xcx		
		pop xax 
		m2m	[xsi], color, xax
		jmp salto2b
salto1b:
		pop xcx		
		pop xax 
salto2b:
		mov eax, [xbx].dotp
		add eax, 1
		mov [xbx].dotp, eax
		.if [xbx].dotp > 31
			mov [xbx].dotp, 0
		.endif
		jmp	fin

@@:		mov	eax , difXY2
		cmp	eax , difX
		jge	loc_40162F
		mov	eax , difXY
		add	eax , difX
		mov	difXY, eax
		mov	eax , Y1
		add	eax , var_10
		mov	Y1, eax
		jmp	loc_40162F
fin:	
		ret
MethodEnd

Method PixelUEFI.Pipeline, uses xsi xdi, x1:sdword, y1:sdword, x2:sdword, y2:sdword, color:dword
	
	local i:dword, j:dword
	local r:real8
	local c1:dword, c2:dword, c3:dword
	local cc1:dword, cc2:dword,cc3: dword, cc4: dword
	local fSlvTLS()
	;// (1-r)^2
	
	local ang : real8, cang : real8, sang : real8
	local dx1 : sdword, dy1 : sdword, temp : sdword
	local quad4 : dword, oct2: dword, offset1:sdword
	
	local pty1:dword, pty2:dword
	local ptx1:dword, ptx2:dword
	
	local x1a:dword, x1p:dword
	local y1a:dword, y1p:dword

    SetObject xsi
	
    fSlv dx1 = abs(x2 - x1); /* delta x */
    fSlv dy1 = abs(y2 - y1); /* delta y */

    OCall xsi.BresLine, x1, y1, x2, y2, color

    takecolor color, cc1, cc2, cc3

    remakecolor <(1-1/4)^0.5>, cc1, cc2, cc3, cc4, c1
    mov eax, dx1
    .if eax > dy1
        add y1, 1
        add y2, 1
    .else
        add x1, 1
        add x2, 1
    .endif
    OCall xsi.BresLine2, x1, y1, x2, y2, c1
	
    mov eax, dx1
    .if eax > dy1
        sub y1, 2
        sub y2, 2
    .else
        sub x1, 2
        sub x2, 2
    .endif
    OCall xsi.BresLine2, x1, y1, x2, y2, c1

    remakecolor <(1-2/4)^0.5>, cc1, cc2, cc3, cc4, c1
    mov eax, dx1
    .if eax > dy1
        add y1, 3
        add y2, 3
    .else
        add x1, 3
        add x2, 3
    .endif
    OCall xsi.BresLine2, x1, y1, x2, y2, c1
    mov eax, dx1
    .if eax > dy1
        sub y1, 4
        sub y2, 4
    .else
        sub x1, 4
        sub x2, 4
    .endif
    OCall xsi.BresLine2, x1, y1, x2, y2, c1

    remakecolor <(1-3/4)^0.5>, cc1, cc2, cc3, cc4, c1
    mov eax, dx1
    .if eax > dy1
        add y1, 5
        add y2, 5
    .else
        add x1, 5
        add x2, 5
    .endif
	OCall xsi.BresLine2, x1, y1, x2, y2, c1
	
	mov eax, dx1
    .if eax > dy1
        sub y1, 6
        sub y2, 6
    .else
        sub x1, 6
        sub x2, 6
    .endif
    OCall xsi.BresLine2, x1, y1, x2, y2, c1
			
MethodEnd; Pipeline endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
    tmgl equ <1>

   	remakecolor macro dilucion, cc1, cc2, cc3, c1
	    ifidn abb_backend_entity,<FSLV_X86_FPU_ENTITY>
		    fSlv8 = dilucion;0.85
	    else;	FSLV_X86_SSE2_FPU_ENTITY
		    fSlv8 tempR8 = dilucion;0.85
		    fld tempR8
	    endif
		fld   st
		fld   st
		fild  cc1
		fmul
		fistp c1 
		fimul cc2
		fistp c2 
		fimul cc3
		fistp c3
		mov  eax, c1;c3
		shl  eax, 8
		add  eax, c2
		shl  eax, 8
		add  eax, c3;c1
		mov  c1, eax
	endm

	lens44vert macro
		fSlv a1 = (y1-yi)
		fSlv c1a = (x1-xi)
        fSlv ang1 = cos(atan2(a1,c1a))
		fSlv c2a = (x0-xi)
		fSlv a2 = c2a / c1a* a1
		ForLp i, -tmgl-2, tmgl+2, eax
		    ;fSlv8 r = (i*i+j*j)^0.5/(tmgl+1)
			;.if fLT(r, 1.0)
				mov 	eax , y0
				add 	eax, i 
				mov 	y1l, eax

				fSlv a3 = (y1l-yi) - a2				
				
		        fSlv8 r = abs(ang1*a3)/(tmgl+3)

				remakecolor <(1-r)^0.5>, cc1, cc2, cc3, c1
				;DbgHex c1
				setpixel x0, y1l, c1
				;OCall xsi.SetPixel, x0, y1l, c1
		Next i
		
		if 0
			mov 	eax , y0
			add 	eax, 4 
			mov 	y1l, eax

			fSlv a3 = (y1l-yi) - a2				
			
	        fSlv8 r = abs(ang1*a3)/(tmgl+3)

			remakecolor <(1-r)^0.5>, cc1, cc2, cc3, c1
			setpixel x0, y1l, c1

			mov 	eax , y0
			sub 	eax, 4 
			mov 	y1l, eax

			fSlv a3 = (y1l-yi) - a2				
			
	        fSlv8 r = abs(ang1*a3)/(tmgl+3)

			remakecolor <(1-r)^0.5>, cc1, cc2, cc3, c1
			blendpixel x0, y1l, c1
		endif
	endm

	lens44horiz macro
		fSlv a1 = (y1-yi)
		fSlv c1a = (x1-xi)
        fSlv ang1 = cos(atan2(a1,c1a))
		ForLp i, -tmgl-2, tmgl+2, eax
            mov 	eax , x0
            add 	eax, i 
            mov 	x1l, eax

            fSlv c2a = (x1l-xi)
				
            fSlv a2 = c2a / c1a* a1
            fSlv a3 = (y0-yi) - a2				

            fSlv8 r = abs(ang1*a3)/(tmgl+3)
	
            remakecolor <(1-r)^0.5>, cc1, cc2, cc3, c1
            setpixel x1l, y0, c1
		Next i
		if 0
            mov  eax , x0
            add  eax, 4 
            mov  x1l, eax

            fSlv c2a = (x1l-xi)
				
            fSlv a2 = c2a / c1a* a1
            fSlv a3 = (y0-yi) - a2				

            fSlv8 r = abs(ang1*a3)/(tmgl+3)
	
            remakecolor <(1-r)^0.5>, cc1, cc2, cc3, c1
            blendpixel x1l, y0, c1
				
            mov  eax , x0
            sub  eax, 4 
            mov  x1l, eax

            fSlv c2a = (x1l-xi)
				
            fSlv a2 = c2a / c1a* a1
            fSlv a3 = (y0-yi) - a2				

            fSlv8 r = abs(ang1*a3)/(tmgl+3)
	
            remakecolor <(1-r)^0.5>, cc1, cc2, cc3, c1
            blendpixel x1l, y0, c1
		endif
	endm
	vert44 macro
		ForLp i, -tmgl-4, tmgl+4, eax
			mov 	eax , x0
			add 	eax, i 
			mov 	x1l, eax

	        fSlv8 r = abs(i)/(tmgl+3)
	
			remakecolor <(1-r)^0.5>, cc1, cc2, cc3, c1
	
			;DbgDec x1l
			;DbgDec y0

			setpixel x1l, y0, c1
		Next i
	endm

Method PixelUEFI.line44, uses xsi xdi, x0:dword, y0:dword, x1:dword, y1:dword, wdh:dword, xcolor:dword
	
  	local dx1   :sdword, sx :sdword
  	local dy1   :sdword, sy :sdword
  	local err   :sdword, e2 :sdword 
  	local color :dword
	local orientation :dword
	local angle :dword

	;	for lens
	local i   :sdword
	local x1l :sdword, y1l :sdword
	local r   :real8
	
	;	for colors
	local c1   :dword, c2  :dword,  c3 :dword
	local cc1  :dword, cc2 :dword, cc3 :dword, cc4 :dword

	local xi   :sdword, yi  :sdword
	local coef :real8, ang1 :real8, xlong1 :real8, ylong1 :real8

	local xx :dword, yy :dword
	local xt :dword, yt :dword
	
	local fSlvTLS()
	
	; para color
	local a1  :real8, a2  :real8, a3 :real8
	local c1a :real8, c2a :real8, d1 :real8
	
	;local rx0:real8, ry0:real8, rx1:real8, ry1:real8
	;local rdx1:real8, rdy1:real8
	
	;DbgText "  line44  "
	
	SetObject xsi 
	m2m xi, x0, @if64bits(r8d)
	m2m yi, y0, @if64bits(r8d)
	
	;fSlv rx0 = x0
	;fSlv ry0 = y0
	;fSlv rx1 = x1
	;fSlv ry1 = y1
	
	mov eax, xcolor;[xsi].activeColor
	bswap eax
	ror eax, 8
	mov xcolor,  eax

	takecolor xcolor, cc1, cc2, cc3

	;remakecolor 1, cc1, cc2, cc3, c1
	
  	fSlv dx1 = abs(x1-x0)
	mov eax , x0
	.if eax < x1 
	  	fSlv sx = 1
	.else
		fSlv sx = -1
	.endif
	fSlv dy1 = abs(y1-y0)
	mov eax , y0
	.if eax < y1 
	  	fSlv sy = 1
	.else
		fSlv sy = -1
	.endif
  
  	mov eax, dx1
  	.if sdword ptr eax == 0
  		mov angle, 1
  	.else	
  		mov angle, 0
	  	.if (sdword ptr eax > dy1)
	  		fSlv err = dx1/2
	  		mov orientation, 1
	  	.else
	  		fSlv err = -dy1/2
	  		mov orientation, 0
	  	.endif
  	.endif

@bucle44:
	.if angle
		vert44
	.else	
	    .if orientation
	    ;setpixel x0, y0, color
			lens44vert;  x0, y0, color
		.else
			lens44horiz;, x0, y0, color
		.endif
	.endif
	;DbgText "a pix" 
	
    mov eax, x0
    mov edx, y0
    .if eax == x1 && edx == y1
    	jmp @sale44
    .endif
    mov eax , err
    mov e2, eax
    mov edx, dx1
    neg edx
    .if (sdword ptr eax > edx) 
     	;fSlv err = err - dy1
      	mov edx , eax
      	sub sdword ptr edx , dy1
      	mov err , edx
      	;fSlv x0  = x0  + sx;
      	mov edx , x0
      	add sdword ptr edx , sx
      	mov x0 , edx 
    .endif
    .if (sdword ptr eax < dy1) 
    	fSlv err = err + dx1 
		;mov edx, eax
		;add sdword ptr edx , dx1
      	;mov err , edx
      	;int 3
	 	fSlv y0 = y0 + sy  
      	;mov edx , y0
      	;add sdword ptr edx , sy
      	;mov y0 , edx
    .endif
    jmp @bucle44
  
    @sale44:
MethodEnd