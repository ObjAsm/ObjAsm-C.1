; ==================================================================================================
; Title:   ConsoleUEFI.inc
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: GraphicsUEFI support:
;          ObjAsm support for graphic console Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================

	DefineDD macro a1, a2
		DefineVariable &a1, dword, &a2
	endm
	DefinePT macro a1, a2
		DefineVariable &a1, POINTER, &a2
	endm

	xconf equ 640
	yconf equ 480

Object ConsoleUEFI, , CharsUEFI
    VirtualMethod   InitBoot, POINTER
    VirtualMethod   Blt
    VirtualMethod   ClearScreen

    VirtualMethod   DrawStrCon, POINTER
    VirtualMethod   Tab  
    VirtualMethod   Cr   
    VirtualMethod   Lf
    VirtualMethod   Scroll
    
    VirtualMethod   SetPos, DWORD, DWORD      
    VirtualMethod   SetForeground, DWORD      
    
    DefineDD    dBackground, 0880000h
    DefineDD    dForeground, 0FFFFFFh
    
    DefineDD curX, 0
    DefineDD curY, 0
    DefineDD maxCurX; = pixelsPerScanLine/fontSize;
    DefineDD maxCurY; = screenHeight/(fontSize*2);


    DefinePT    BufferBase, 0
    DefinePT    GraphicsOutput, 0    
ObjectEnd

if IMPLEMENT

.data
    cdXPos       dd    128
    cdYPos       dd    128
    cdColFondo   dd      0   ;     // COLOR_BTNFACE + 1
    cdVBarTipo   dd      0
    
.code

    addPSFwidthCon proc uses xbx c_x:POINTER;dword
        ; cast the address to PSF header struct 
        lea xbx, psf2i
        mov rdx, c_x
        mov eax, [xdx] 
        mov ecx, [xbx].PSF_font._width
        inc ecx
        add eax, ecx 
        mov [xdx], eax 
        ret
    addPSFwidthCon endp

Method ConsoleUEFI.InitBoot, uses xsi xdi xbx, pBoot: POINTER
    local cdXSize : dword, cdYSize : dword
    local ivar : dword
    local qvar : qword
    
    ;DbgText "ConsoleUEFI.InitBoot"
    
    SetObject xsi

    mov xdi, pBoot
        
    invoke [xdi].EFI_BOOT_SERVICES.LocateProtocol, addr EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, NULL, addr [xsi].GraphicsOutput
    .if xax
        mov [xsi].GraphicsOutput, NULL
        PrintLn "Loading Graphics_Output_Protocol error!"
        return EFI_SUCCESS
    .endif
    
    mov xax, [xsi].GraphicsOutput
    mov xbx, [xax].EFI_GRAPHICS_OUTPUT_PROTOCOL.Mode
       
    if 0
        m2m qvar,[xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.MaxMode,xax
        PrintLn "Max mode     =[ %d  ] ", qvar
    
        m2m qvar, [xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.Mode, xax
        PrintLn "Current mode =[ %d  ] ", qvar
    
    
        m2m ScreenBufferM, [xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.FrameBufferBase, xax
        DbgHex ScreenBufferM
    
        mov xbx, [xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.Info      
        m2m ivar,[xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.Version, eax
        PrintLn "Version      =[ %i  ] ", ivar
    endif
    
    mov xbx, [xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.Info      
    mov eax, [xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.HorizontalResolution
    mov cdXSize, eax
    mov xcdXSize, xax
    ;mov ivar, eax
    ;PrintLn "Screen Width =[ %i  ] ", ivar

    mov eax, [xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.VerticalResolution
    mov cdYSize, eax
    mov xcdYSize, xax
    ;mov ivar, eax
    ;PrintLn "Screen height=[ %i  ] ", ivar

    ;m2m ivar, [xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelFormat, eax
    ;PrintLn "Format       =[ %i  ] ", ivar

    mov eax, [xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelsPerScanLine
    shl xax, 2
    mov [xsi].xDelta, xax
    ;mov ivar, eax
    ;PrintLn "Screen Delta =[ %i  ] ", ivar
    ;------------------------------------

    ;PrintLn "waiting for a key..."
    ;call Wait4Key

    ;mov xcx, pConsoleOut
    ;invoke [xcx].ConOut.ClearScreen, xcx
 
    mov eax , cdXSize
    mov ecx , cdYSize
    mul ecx
    shl eax, 2
    invoke MemAlloc_UEFI, 0, eax, EFI_MEMORY_TYPE_EfiLoaderData 
    mov [xsi].pPixels, xax

    ACall xsi.Init, [xsi].pPixels, cdXSize, cdYSize, [xsi].xDelta

    mov xax, [xsi].GraphicsOutput
    mov xbx, [xax].EFI_GRAPHICS_OUTPUT_PROTOCOL.Mode   
    mov xcx, [xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.FrameBufferBase
    mov [xsi].BufferBase, xcx

    
    ; = pixelsPerScanLine/fontSize;

    lea xbx, psf2i
    xor edx,edx
    mov ecx, [xbx].PSF_font._width
    add ecx, 1
    mov xax , [xsi].xDelta
    div ecx
    mov [xsi].maxCurX, eax

    xor edx,edx
    mov ecx, [xbx].PSF_font.height
    add ecx, 1
    mov eax , cdYSize
    div ecx
    sub eax, 1
    mov [xsi].maxCurY, eax

MethodEnd

Method ConsoleUEFI.ClearScreen, uses xsi
  
    SetObject xsi
    
    OCall xsi.FillBkGnd, [xsi].dBackground;$RGB(  0,  0, 68, 255)
    OCall xsi.Blt

MethodEnd

Method ConsoleUEFI.Blt, uses xdi xbx
    local i:dword
    local j:dword
    
    SetObject xbx
  
    .if [xbx].pPixels != 0
        ForLpD i, 0, [xbx].dHeight, eax
            ForLpD j, 0, [xbx].dWidth, eax
                mov eax, i
                mov ecx , [xbx].dDelta
                mul ecx
                mov ecx, j
                shl ecx, 2
                add eax, ecx
                mov ecx, eax
                add xax, [xbx].pPixels
                add xcx, [xbx].BufferBase
                mov edi, dword ptr [xax]         
                mov dword ptr [xcx], edi
            Next j
        Next i    
    .endif
MethodEnd

Method ConsoleUEFI.Scroll, uses xdi xbx
    local i : dword
    local j : dword
    local deltascroll : dword
    
    SetObject xbx

    lea xcx, psf2i
    mov ecx,  [xcx].PSF_font.height
    add ecx, 1
    mov eax, [xbx].dDelta
    mul ecx
    mov deltascroll, eax
  
    .if [xbx].pPixels != 0
        ForLpD i, ecx, [xbx].dHeight, eax
            ForLpD j, 0, [xbx].dWidth, eax
                mov eax, i
                mov ecx , [xbx].dDelta
                mul ecx
                mov ecx, j
                shl ecx, 2
                add eax, ecx
                add xax, [xbx].pPixels
                mov ecx, eax
                sub ecx, deltascroll
                
                mov edi, dword ptr [xax]         
                mov dword ptr [xcx], edi
            Next j
        Next i    

        mov edi, [xbx].dBackground         
        RGB2BGR edi
 
        lea xcx, psf2i
        mov edx, [xcx].PSF_font.height
        add edx, 1
        mov ecx, [xbx].dHeight
        sub ecx, edx
        ForLpD i, ecx, [xbx].dHeight, eax
            ForLpD j, 0, [xbx].dWidth, eax
                mov eax, i
                mov ecx , [xbx].dDelta
                mul ecx
                mov ecx, j
                shl ecx, 2
                add eax, ecx
                add xax, [xbx].pPixels
                mov dword ptr [xax], edi
            Next j
        Next i    
    .endif
MethodEnd

Method ConsoleUEFI.DrawStrCon, uses xsi xbx, s1:POINTER
    local i : dword
    local len : dword
    local x1: dword, y1: dword
    
    SetObject xsi
    
    invoke StrLength, s1
    dec eax
    mov len, eax

    lea xbx, psf2i

    mov eax, [xsi].curX
    mov ecx, [xbx].PSF_font._width
    inc ecx
    mul ecx
    mov x1, eax
    
    mov eax, [xsi].curY
    mov ecx, [xbx].PSF_font.height
    inc ecx
    mul ecx
    mov y1, eax  
    
    ForLp i, 0, len, eax
        add xax, s1
        mov r10w, word ptr [xax]
        OCall xsi.putchar, r10w, x1, y1, [xsi].dForeground, 0
        invoke addPSFwidthCon, addr x1
        add [xsi].curX, 1
        add s1, 1
    Next i
    OCall xsi.Blt
MethodEnd

Method ConsoleUEFI.Tab, uses xsi
    SetObject xsi
    mov eax, [xsi].curX
    add eax, 4
    mov [xsi].curX, eax
MethodEnd
Method ConsoleUEFI.Cr, uses xsi
    SetObject xsi
    mov [xsi].curX, 0
MethodEnd
Method ConsoleUEFI.Lf, uses xsi
    SetObject xsi
    
    mov eax , [xsi].maxCurY
    
    ;DbgDec  [xsi].maxCurY
    ;       call Wait4Key  

    .if eax > [xsi].curY
        inc [xsi].curY
    .else
        OCall xsi.Scroll
    .endif
MethodEnd

Method ConsoleUEFI.SetPos, uses xsi, x1:DWORD, y1:DWORD
    SetObject xsi
    m2m [xsi].curX, x1, eax
    m2m [xsi].curY, y1, eax
MethodEnd

Method ConsoleUEFI.SetForeground, uses xsi, c1:DWORD
    SetObject xsi
    m2m [xsi].dForeground, c1, eax
MethodEnd

Method ConsoleUEFI.SetBackground, uses xsi, c1:DWORD
    SetObject xsi
    m2m [xsi].dBackground, c1, eax
MethodEnd
endif