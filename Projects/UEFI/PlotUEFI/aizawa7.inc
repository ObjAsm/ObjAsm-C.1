; ==================================================================================================
; Title:   Aizawa.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: Aizawa Oscilallator file for Plot UEFI Application.
; Version: Version 1.0.0, June 2022
;            - First release.
; ==================================================================================================
triplete struct
;    x   real8 0.0
;    y   real8 0.0
;    z   real8 0.0
    xg  dword 0
    yg  dword 0
    
;    order   sdword 0
    value   real8 0.0
    speed   real8 0.0
    first   dword 0
triplete ends   
 
.const

    cdXPos       dd    128
    cdYPos       dd    128
    cdXSize      dd    640
    cdYSize      dd    400
    cdColFondo   dd      0   ;     // COLOR_BTNFACE + 1
    cdVBarTipo   dd      0
    cdMainIcon   dd    100
    cdIdTimer    dd   1001
    Delta        xword      0

    xcdXSize    xword   640
    xcdYSize    xword   400

.data
    todos xword 0

    ultimo triplete <?>
    temptriple triplete <?>

    n_todos dword 0
    n_final dword 0

    dt1 real4 0.01;75  
    dt2 real4 0.01;75
 
    x real8 0.1
    y real8 0.08
    z real8 0.0
   
    mtBola dd 00000h, 09000h, 09000h, 09000h, 00000h,
              09000h, 0FF00h, 0E000h, 0B000h, 09000h,
              09000h, 0E000h, 0E000h, 0B000h, 09000h,
              09000h, 0B000h, 0B000h, 0B000h, 09000h,
              00000h, 09000h, 09000h, 09000h, 00000h

    mtBolaa dd 0000000h, 0909000h, 0909000h, 0909000h, 0000000h,
               0909000h, 0FFFF00h, 0E0E000h, 0B0b000h, 0909000h,
               0909000h, 0E0E000h, 0E0E000h, 0B0b000h, 0909000h,
               0909000h, 0B0B000h, 0B0b000h, 0B0b000h, 0909000h,
               0000000h, 0909000h, 0909000h, 0909000h, 0000000h

    iniciado dd FALSE
    oldix dd 0
    oldiy dd 0

; 3D
    cdXC real8 0.26;-0.34202;2.0 ; //-.34202
    cdXS real8 0.97;.939693;0 ; //.939693
    cdYC real8 0.97;1.0;0.70
    cdYS real8 0.26;0.0;0.70
    
    ex   real8 110.0

    speed       real8 0.0
    maxspeed    real8 0.0
    minspeed    real8 0.0
    hayspeed    dd      0

    meanspeed   real8 0.0
    totalspeed  real8 0.0
.code

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    ; ——————————————————————————————————————————————————————————————————————————————————————————————————
    ; Macro:      CopiaStruct
    ; Purpose:    Output a specified wide string on the debug device.
    ; Arguments:  Arg1: Structure.
    ;             Arg2: Destination structure.
    ;             Arg3: Source structure.
    
	CopiaStruct macro tipo_de_objeto, ObjectDest, ObjectOrig

		freg_push xsi

		cld
		mov xdi, &ObjectDest;[Dest]
    	mov xsi, &ObjectOrig
    	mov xcx , sizeof &tipo_de_objeto;[ln]
    	rep movsb
	
		freg_pop xsi
	endm


PintaBola proc uses xbx px :dword, py:dword
  local x1, y1, pos, oldpos : dword

    .if (px < 0) 
        ret
    .endif 
    .if (py < 0)
        ret
    .endif
    mov eax, cdXSize
    sub eax , 5
    .if px >=eax
        ret
    .endif
    mov eax, cdYSize
    sub eax , 5
    .if py >= eax
        ret
    .endif

        mov edx, 0
	    mov eax , py
	    mov ecx , cdXSize
	    shl ecx , 2
	    mul ecx 
        mov edx , eax		
	    mov eax , px
	    shl eax , 2
        add eax, edx

    mov pos , eax
    mov oldpos , eax
    
    ForLp y1, 0, 4, eax
        ForLp x1, 0, 4, eax
            mov edx, 0
            mov eax, y1
            mov ecx, 5 
            mul ecx
            mov edx, x1
            add edx , eax
            .if edx !=0 && edx !=4 && edx!=20 && edx!=24
                mov ecx, pos
                add xcx, ScreenBuffer
                mov xax, offset mtBolaa
                mov eax, [xax+xdx*4]
           		bswap eax
        		ror eax, 8
                mov dword ptr [xcx] , eax 
            .endif
            add pos, 4
        Next x1
        
        mov eax, cdXSize
        shl eax, 2
        add eax, oldpos
        mov pos , eax  
        mov oldpos, eax
        
    Next y1
    ret
PintaBola endp

BorraBola proc px :dword, py:dword, vel:real8  
  local x1, y1, pos, oldpos : dword
  local velcol : dword
  local velrel : real8
  local fSlvTLS()

    .if (px < 0) 
        ret
    .endif 
    .if (py < 0)
        ret
    .endif
    mov eax, cdXSize
    sub eax , 5
    .if px >=eax
        ret
    .endif
    mov eax, cdYSize
    sub eax , 5
    .if py >= eax
        ret
    .endif

        mov edx, 0
	    mov eax , py
	    mov ecx , cdXSize
	    shl ecx , 2
	    mul ecx 
        mov edx , eax		
	    mov eax , px
	    shl eax , 2
        add eax, edx
    
    mov pos , eax
    mov oldpos , eax

            ;PrintDec vel
            ;PrintDoublemaxspeed-meanspeed

    .if fEQ(vel, 0.0)
        fSlv8 velrel = 1
    .else    
        fSlv8 velrel =vel/meanspeed
    .endif  
   ;PrintDouble velrel
    
    ForLp y1, 0, 4, eax
        ForLp x1, 0, 4, eax
            mov edx, 0
            mov eax, y1
            mov ecx, 5 
            mul ecx
            mov edx, x1
            add edx , eax
            .if edx !=0 && edx !=4 && edx!=20 && edx!=24
                mov ecx, pos
                add xcx, ScreenBuffer
                .if fGT(velrel, 1.75)
                    ;fSlv velcol = trunc(velrel*95)
                    ;mov eax, velcol
                    if 0
                    ; ??
                    shl eax, 16
                    endif
                    mov xax, offset mtBola
                    mov dword ptr eax, [xax+xdx*4]
                    shr eax, 8
                    
                .else
                    .if fLT(velrel, 0.25)
                    if 0
                        ;??
                        fSlv velcol = 95-trunc(velrel*95)
                        mov eax, velcol
                        xor eax, mtBola[edx*4]
                        mov xax, offset mtBola
                        mov dword ptr eax, [xax+xdx*4]
                    endif
                        mov xax, offset mtBola
                        mov dword ptr eax, [xax+xdx*4]
                        shl eax, 8
                    .else
                        mov xax, offset mtBola
                        mov dword ptr eax, [xax+xdx*4]
                    
                    .endif
                .endif
                mov dword ptr [xcx] , eax
    
            .endif
            add pos, 4
        Next x1
        
        mov eax, cdXSize
        shl eax, 2
        add eax, oldpos
        mov pos , eax  
        mov oldpos, eax
        
    Next y1
    ret
BorraBola endp


BorraBola2 proc uses xbx px :dword, py:dword, pz : real8 
    local x1, y1, pos, oldpos : dword
    local mascara : xword

    ;fSlv mascara = 128*(pz+0.34)/2.2; z
    fSlv mascara = 144+110*(pz+0.34)/2.2; z
    ;PrintHex mascara
   ; fSlv mascara = 40+200*(pz+8.857)/12.16; zr

    mov xbx , mascara
    shl xbx, 8
    
    .if (px <= 5) 
        ret
    .endif 
    .if (py <= 5)
        ret
    .endif
    mov eax, cdXSize
    sub eax , 5
    .if px >= eax
        ret
    .endif
    mov eax, cdYSize
    sub eax , 5
    .if py >= eax
        ret
    .endif

        mov edx, 0
	    mov eax , py
	    mov ecx , cdXSize
	    shl ecx , 2
	    mul ecx 
        mov edx , eax		
	    mov eax , px
	    shl eax , 2
        add eax, edx
    
    mov pos , eax
    mov oldpos , eax
    
    ForLp y1, 0, 4, eax
        ForLp x1, 0, 4, eax
            mov edx, 0
            mov eax, y1
            mov ecx, 5 
            mul ecx
            mov edx, x1
            add edx , eax
            .if edx !=0 && edx !=4 && edx!=20 && edx!=24
                mov ecx, pos
                add xcx, ScreenBuffer
                mov xax, offset mtBola
                mov xax , [xax+xdx*4];
                mov eax, [xax+xdx*4]
           		bswap eax
        		ror eax, 8
                ;freg_push eax   ??
                .if eax > 9000h
                    ;freg_pop eax
                    or  eax, ebx
                ;.else
                ;    freg_pop eax
             ;   or  eax, ebx
                 .endif
                mov dword ptr [xcx], eax
            .endif
            add pos, 4
        Next x1
        
        mov eax, cdXSize
        shl eax, 2
        add eax, oldpos
        mov pos , eax  
        mov oldpos, eax
        
    Next y1
    ret
BorraBola2 endp

; ««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

if 1
tmgl equ <12>

   	remakecolor macro dilucion, cc1, cc2, cc3, c1
	        
	    fSlv8 = dilucion;0.85
		fld   st
		fld   st
		fimul cc1
		fistp c1 
		fimul cc2
		fistp c2 
		fimul cc3
		fistp c3
		mov eax, c1
		shl	eax, 8
		add eax, c2
		shl eax, 8
		add eax, c3
		mov c1 , eax
	endm

BorraBola3 proc uses xbx px :dword, py:dword, luz : dword
    local x1, y1, pos, oldpos : dword
    local i, j: dword
    local mascara : dword
    local r : real8
    local fSlvTLS()
    local c1:dword, c2:dword, c3:dword
    local cc1:dword, cc2:dword,cc3: dword
    local fregTLS()
    
    .if (px < 0) 
        ret
    .endif 
    .if (py < 0)
        ret
    .endif
    mov eax, cdXSize
    sub eax , 5
    .if px >= eax
        ret
    .endif
    mov eax, cdYSize
    sub eax , 5
    .if py >= eax
        ret
    .endif

        mov edx, 0
	    mov eax , py
        sub eax , tmgl
	    mov ecx , cdXSize
	    shl ecx , 2
	    mul ecx 
        mov edx , eax		
	    mov eax , px
        sub eax , tmgl
	    shl eax , 2
        add eax, edx
    
    mov pos , eax
    mov oldpos , eax
    mov eax, luz
    mov cc1, eax
    mov cc2, eax
    mov cc3, eax
    
	ForLp i, -tmgl-1, tmgl+1, eax
		ForLp j, -tmgl-1, tmgl+1, eax
		    fSlv8 r = (i*i+j*j)^0.5/(tmgl+1)
            mov ecx, pos
            add xcx, ScreenBuffer
            freg_push xcx
			.if fLT(r, 1.0)
               	remakecolor <(1-r)^2>, cc1, cc2, cc3, c1

                mov eax, dword ptr [xcx]
                or eax , c1
                freg_pop xcx
                mov dword ptr [xcx], eax
            .else
                freg_correction +1
                freg_pop xcx
			.endif
            add pos, 4
		Next j
        mov eax, cdXSize
        shl eax, 2
        add eax, oldpos
        mov pos , eax  
        mov oldpos, eax
    Next i
  ret
BorraBola3 endp

endif


MuestraTodo proc
    local i : dword, tope : dword
    local punterox: xword, punteroy : xword
    local fregTLS()

    ;                      Erase buffer
        mov eax , cdXSize
        mov ecx , cdYSize
        mul ecx
        mov xcx, xax
        mov xdx, ScreenBuffer
    @loop1:
        mov eax, n_final
    	mov dword ptr [xdx], eax
        add xdx, 4
        loop @loop1
    
    mov eax, n_todos
    sub eax, 1
    mov tope , eax 

    ForLp i, 0, tope, eax
        imul xdx, xax, sizeof triplete
        ;lea eax, todos
        mov xax, todos
        add xdx, xax
        .if [xdx].triplete.first == 1
            mov [xdx].triplete.first, 0
            freg_push xdx
            invoke PintaBola, [xdx].triplete.xg, [xdx].triplete.yg
            freg_pop xdx
            if 1
	            freg_push xdx
	            invoke BorraBola3, [xdx].triplete.xg, [xdx].triplete.yg, 0DDh  
	            m2m punterox, [xdx].triplete.xg, xax
	            m2m punteroy, [xdx].triplete.yg, xax
	            freg_pop xdx
            endif
        .else
            mov r8, [xdx].triplete.speed
            invoke BorraBola, [xdx].triplete.xg, [xdx].triplete.yg, r8  
        .endif
    Next i
    ret
MuestraTodo endp

CalculaObjeto proc
    ;local ix, iy : dword
    ;local xr, yr, zr ; real8
    local xr:real8 , yr:real8, zr : real8
    local x2:real8 , y2:real8, z2 : real8
    local fregTLS()

    local i : dword, menor :xword, tope : dword
    local fSlvTLS()
    

    fSlvRegConst _a , 0.95
    fSlvRegConst _b , 0.7
    fSlvRegConst _c , 0.6
    fSlvRegConst _d , 3.5
    fSlvRegConst _e , 0.25
    fSlvRegConst _f , 0.1
    .if n_todos > 499980
        .if n_final > 0FFFFFFh
            mov n_final, 0
        .endif
        jmp @muestrat
    .endif

    fSlv8 x2 = x
    fSlv8 y2 = y
    fSlv8 z2 = z
    fSlv8 x = x2 + ((z2 - _b) * x2 - _d * y2) * dt1
    fSlv8 y = y2 + (_d * x2 + (z2 -_b) * y2)* dt1
    fSlv8 z = z2 + (_c + _a*z2 - z2^3 /3 - (x2^2 +y2^2) *(1+_e*z2) + _f * z2 * x2^3) * dt1
    
    fSlv8 speed = abs(x-x2)*abs(y-y2)*abs(z-z2)

    .if hayspeed
        fSlv8 totalspeed = totalspeed + speed
        fSlv8 meanspeed = totalspeed/(n_todos+1)
        
    .else
        mov hayspeed, 1
        fSlv8 totalspeed = speed
        fSlv8 meanspeed = speed
    .endif

    fSlv xr = x*cdYC*ex + z*cdYS*ex;
    fSlv yr = y*cdXC*ex - z*cdYC*cdXS*ex + x*cdYS*cdXS*ex;
    fSlv zr = z*cdXS*ex - y*cdYC*cdXS*ex + x*cdYS*cdXS*ex;

    fSlv ultimo.triplete.xg = trunc(xr+cdXSize/2)
    fSlv ultimo.triplete.yg = trunc(yr+cdYSize/1.7);
    fSlv ultimo.triplete.speed = speed
  
    mov ultimo.triplete.first, 1  
    fSlv ultimo.triplete.value = zr

    .if n_todos > 0
        mov menor, 0

            mov eax, n_todos
            sub eax, 1
            mov tope , eax 

        ForLp i, 0, tope, eax
            imul xdx, xax, sizeof triplete
            mov xax, todos
            add xdx, xax
            mov [xdx].triplete.first, 0
            
            .if fLT(ultimo.triplete.value, [xdx].triplete.value) && !menor
                mov menor, 1
                CopiaStruct triplete, offset temptriple, xdx
                CopiaStruct triplete, xdx, offset ultimo
            .else
                .if menor; == 1
                    CopiaStruct triplete, offset ultimo, xdx 
                    CopiaStruct triplete, xdx, offset temptriple
                    CopiaStruct triplete, offset temptriple, offset ultimo
                .endif
            .endif
        Next i
        .if menor
           CopiaStruct triplete, xdx, offset temptriple
        .else
            CopiaStruct triplete, xdx, offset ultimo
        .endif
    .else
        ;lea edx, todos
        mov xdx, todos
        CopiaStruct triplete, xdx, offset ultimo
    .endif
    inc n_todos
@muestrat:  
    invoke MuestraTodo
        
    ret
CalculaObjeto endp


IniciaObjeto proc
    local xr, yr, zr ; real8
    local fregTLS()
  
    fSlv xr = x*cdYC*ex + z*cdYS*ex;
    fSlv yr = y*cdXC*ex - z*cdYC*cdXS*ex + x*cdYS*cdXS*ex;
   
    fSlv zr = z*cdXS*ex - y*cdYC*cdXS*ex + x*cdYS*cdXS*ex;

    fSlv ultimo.triplete.xg = trunc(xr+cdXSize/2)
    fSlv ultimo.triplete.yg = trunc(yr+cdYSize/1.7);
  
    mov ultimo.triplete.first, 1  
    fSlv ultimo.triplete.value = zr

    mov xdx, todos
    CopiaStruct triplete, xdx, offset ultimo
       
    ret
IniciaObjeto endp

