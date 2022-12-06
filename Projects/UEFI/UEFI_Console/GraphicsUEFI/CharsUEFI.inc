; ==================================================================================================
; Title:   CharsUEFI.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: ObjAsm crude support for PSF2 fonts in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================
Object CharsUEFI,,PixelUEFI
    
    DefineVariable pGlyphs, POINTER, 0
     
    VirtualMethod DrawStr , POINTER, POINT, dword, POINTER, dword, dword
    VirtualMethod putchar, word, dword, dword, dword, dword
    
ObjectEnd

    PSF_font struct
        magic         dword 0;   magic bytes to identify PSF
        version       dword 0;   zero
        headersize    dword 0;   offset of bitmaps in file, 32
        flags         dword 0;   0 if there's no unicode table
        numglyph      dword 0;   number of glyphs
        bytesperglyph dword 0;   size of each glyph
        height        dword 0;   height in pixels
        _width        dword 0;   width in pixels
    PSF_font ends

    P_PSF_font typedef ptr PSF_font

if IMPLEMENT
   
    .data

        ; only one of this
        ;include Tamsyn8x15b.inc
        include Tamsyn8x16r.inc
        ;include Tamsyn8x16b.inc
           
        unicode qword 0

        ; number of bytes in each line, it's possible it's not screen width * bytesperpixel! 
        scanline dword 0
        
; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
    .code
    
    addPSFwidth proc uses xbx c_x:POINTER;dword
        ; cast the address to PSF header struct 
        lea xbx, psf2i
        mov rdx, c_x
        mov eax, [xdx] 
        mov ecx, [xbx].PSF_font._width
        inc ecx
        add eax, ecx 
        mov [xdx], eax 
        ret
    addPSFwidth endp

    subPSFwidth proc uses xbx c_x:POINTER;dword
        ; cast the address to PSF header struct 
        lea xbx, psf2i
        mov rdx, c_x
        mov eax, [xdx] 
        mov ecx, [xbx].PSF_font._width
        inc ecx
        sub eax, ecx 
        mov [xdx], eax 
        ret
    subPSFwidth endp

    drawPSFhor macro
        ForLp_df y1, 0, [xbx].PSF_font.height, eax
            ; save the starting position of the line
            mov eax, offs 
            mov line1, eax
            mov eax, 1
            mov ecx, [xbx].PSF_font._width
            dec ecx
            shl eax, cl
            mov mask1, eax
            
            ; display a row 
            ForLp_df x1, 0, [xbx].PSF_font._width, eax
                mov rcx, pglyph
                mov rax, [xcx]
                and eax, mask1
                .if rax > 0
                    mov eax, fg
                    mov xcx, [xsi].pPixels
                    mov edx, line1
                    add xcx, xdx
                    mov [xcx], eax
                .endif
    
                ; adjust to the next pixel
                mov eax, mask1 ;  mask1 >>= 1
                shr eax, 1
                mov mask1, eax
                fSlvW line1 += 4
            Next x1
            
            ; adjust to the next line 
            mov xax, pglyph
            mov xcx, 1;bytesperline
            add xax, xcx
            mov pglyph, xax 
            fSlvW offs  += [xsi].xDelta ;scanline
        Next y1
    endm
    drawPSFver macro
        ForLp_df y1, 0, [xbx].PSF_font.height, eax
            ; save the starting position of the line
            mov eax, offs 
            mov line1, eax
            mov eax, 1
            mov ecx, [xbx].PSF_font._width
            dec ecx
            shl eax, cl
            mov mask1, eax
            
            ; display a row 
            ForLp_df x1, 0, [xbx].PSF_font._width, eax
                mov rcx, pglyph
                mov rax, [xcx]
                and eax, mask1
                .if rax > 0
                    mov eax, c_y
                    sub eax, x1
                    mov xcx, [xsi].xDelta
                    mul xcx
                    mov ecx, c_x
                    add ecx, y1
                    shl ecx, 2
                    add ecx, eax
                    add xcx, [xsi].pPixels
                    ;fSlv xdx = (c_x + y1)*4+(c_y-x1)*Delta
                    mov eax, fg
                    mov [xcx], eax
                .endif
    
                ; adjust to the next pixel
                mov eax, mask1 ;  mask1 >>= 1
                shr eax, 1
                mov mask1, eax
                fSlvW line1 += 4
            Next x1
            
            ; adjust to the next line 
            mov xax, pglyph
            mov xcx, 1;bytesperline
            add xax, xcx
            mov pglyph, xax 
            fSlvW offs  += [xsi].xDelta ;scanline
        Next y1
    endm


drawPSF macro

    ; get the glyph for the character. If there's no
    ;  glyph for a given character, we'll display the first glyph.
        mov eax, [xbx].PSF_font.numglyph
        @if ch1 gt 0 && ch1 lt ax
            xor eax, eax 
            mov ax, ch1
            mov ecx, [xbx].PSF_font.bytesperglyph
            mul ecx
        @else
            mov eax, 0
        @endif
        add eax, [xbx].PSF_font.headersize
        add xax, xbx
        mov pglyph, xax

        .if rot == 0
            drawPSFhor
        .else
            drawPSFver
        .endif

endm

Method CharsUEFI.putchar, uses xsi xbx, ch1:word, c_x:dword, c_y:dword, fg:dword, rot:dword

    local x1:dword, x1_t:dword, y1:dword, y1_t: dword
    LOCAL offs:dword,line1:dword, mask1:dword
    local bytesperline:dword
    local pglyph:qword

    SetObject xsi
    
    ; cast the address to PSF header struct 
    lea xbx, psf2i

    ; calculate the upper left corner on screen where we want to display.
    ;  we only do this once, and adjust the offset later. This is faster. 

    mov eax, c_y
    mov xcx, [xsi].xDelta;scanline 
    mul ecx 
    mov edx, eax
    mov eax, c_x
    shl eax, 2    ;sizeof(PIXEL)
    add edx, eax
    mov offs, edx
        
    drawPSF
    
MethodEnd

Method CharsUEFI.Init, uses xsi, screen1: POINTER, x1:dword, y1: dword, delta1:xword
    SetObject xsi
    
    ACall xsi.Init, screen1, x1, y1, delta1
    
    lea xdx, psf2i
    mov eax, [xdx].PSF_font.headersize
    
MethodEnd


Method CharsUEFI.DrawStr, uses xsi xbx, s1:POINTER, point1:POINT, fb1:dword, fuente:POINTER,flags:dword,rot:dword
    local i : dword
    local len : dword
    local x1: dword, y1: dword
    
    SetObject xsi
    
    invoke StrLength, s1
    dec eax
    mov len, eax

    ; centered 
    lea xbx, psf2i
    .if rot == 0
        inc eax
        mov ecx, [xbx].PSF_font._width
        inc ecx
        mul ecx
        shr eax, 1
        mov edx, point1.POINT.x
        sub edx, eax
        mov x1, edx  
        mov eax, [xbx].PSF_font.height
        shr eax, 1
        mov edx, point1.POINT.y
        sub edx, eax
        mov y1, edx
    .else 
        inc eax
        mov ecx, [xbx].PSF_font._width
        inc ecx
        mul ecx
        shr eax, 1
        mov edx, point1.POINT.y
        add edx, eax
        mov y1, edx  
        mov eax, [xbx].PSF_font.height
        shr eax, 1
        mov edx, point1.POINT.x
        sub edx, eax
        mov x1, edx
    .endif 
    
    ForLp i, 0, len, eax
        add xax, s1
        mov r10w, word ptr [xax]
        OCall xsi.putchar, r10w, x1, y1, fb1, rot
        .if rot == 0
            invoke addPSFwidth, addr x1
        .else
            invoke subPSFwidth, addr y1
        .endif
        add s1, 1
    Next i
MethodEnd

endif