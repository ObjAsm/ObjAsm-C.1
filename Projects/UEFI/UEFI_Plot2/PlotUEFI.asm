run_in_VirtualBox equ 0
; ==================================================================================================
; Title:   PlotUEFI.asm
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: ObjAsm compilation file for Plot UEFI Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================
    xword textequ <XWORD> 
    

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIDE_STRING, UEFI64;, DEBUG(CON)             ;Load OOP files and basic OS support

    return macro valor1
        mov rax, &valor1
        ret
    endm 

    @reg32_64 macro reg_32, reg_64
        if @WordSize eq 4
          @CatStr(<_>,&reg_32) textequ <reg_32>
          @CatStr(<__>,&reg_32) textequ <reg_32>
        else
          @CatStr(<_>,&reg_32) textequ <reg_64>
          @CatStr(<__>,&reg_32) textequ <@CatStr(&reg_64,<d>)>
        endif 
    endm

    @if64bits macro RegAux
        if @WordSize eq 4
            exitm <>
        else
            exitm <&RegAux>
        endif    
    endm

      FP8 MACRO value
        LOCAL vname
        .data
        if @WordSize eq 4 
            align 4
        else
            align 16
        endif
          vname REAL8 value
        .code
        EXITM <vname>
      ENDM

    POINT struct
        x dword ?
        y dword ?
    POINT ends
    RECT struct
        left dword ?
        top dword ?
        right dword ?
        bottom dword ?
    RECT ends
    PRECT typedef ptr RECT

    RGBQUAD textequ <DWORD>    

.const
    cero real8   0.0
    uno  real8   1.0
    dos  real8   2.0
    diez real8  10.0
    cien real8 100.0
    NaN  REAL8  7FF8000000000000r
    
.data
    Handle           EFI_HANDLE 0
    SystemTablePtr   dq 0
    MpProto          dq 0

    GraphicsOutput PGOP NULL

    mapSize     UINTN  512*SIZEOF(EFI_MEMORY_DESCRIPTOR)
    descriptors EFI_MEMORY_DESCRIPTOR 512 DUP (<?>)
    mapKey      UINTN  0
    descSize    UINTN  0
    descVer     UINT32 0
    align @WordSize
    buffer      CHR 32 dup (0)
    CStr crlf$,13,10

    ScreenBuffer  POINTER 0
    ScreenBufferM POINTER 0
    
    pGraphic    POINTER 0

    cdXPos       dd    128
    cdYPos       dd    128
    cdXSize      dd    640
    cdYSize      dd    400
    cdColFondo   dd      0   ;     // COLOR_BTNFACE + 1
    cdVBarTipo   dd      0
    Delta        xword      0

    xcdXSize    xword   640
    xcdYSize    xword   400
    
    IntegRun POINTER 0
    
    include .\App\App_globals.inc
.code

%include @Environ(OBJASM_PATH)\\Code\\Macros\\fMath.inc

include \masm32\macros\SmplMath\math.inc
fSlvSelectBackEnd FPU

include /masm32/macros/real_math.inc

@reg32_64 ecx, r10
@reg32_64 edx, r11

MakeObjects Primer, LinkedList
MakeObjects .\GraphicsUEFI\PixelUEFI, .\GraphicsUEFI\CharsUEFI
MakeObjects .\GraphicsUEFI\GraphicUEFI

include proyecto.inc
include .\modelo\modelomac.inc
MakeObjects .\modelo\modeloB
MakeObjects .\basic\IntgBase
MakeObjects .\basic\Acu
MakeObjects .\modelo\modeloC
MakeObjects .\basic\IntgSim
MakeObjects .\test\UnidadExperimental
MakeObjects .\test\SimpleTest
MakeObjects .\test\LinealTest

include .\App\M0_Calculator.inc

start PROC FRAME imageHandle:EFI_HANDLE, SystemTable:PTR_EFI_SYSTEM_TABLE

    local Status : EFI_STATUS
    local ivar : dword
    local qvar : qword
 
                                             ;Runtime model initialization
    mov Handle, rcx
    mov SystemTablePtr, rdx

    SysInit

    mov rax, SystemTablePtr
    mov rsi, [rax].EFI_SYSTEM_TABLE.RuntimeServices
    mov pRuntimeServices, rsi
    mov rsi, [rax].EFI_SYSTEM_TABLE.BootServices
    mov pBootServices, rsi

    mov rcx,SystemTablePtr
    mov rax,[rcx].EFI_SYSTEM_TABLE.ConIn
    mov pConsoleIn,rax
    mov rax,[rcx].EFI_SYSTEM_TABLE.ConOut
    mov pConsoleOut,rax

    invoke [rax].ConOut.ClearScreen, pConsoleOut

    mov rax, pConsoleOut                                     ;Colors change
    invoke [rax].ConOut.SetAttribute, pConsoleOut, 0Eh
    
    CStr HelloMsg,"Plot with UEFI",13,10,13,10
    mov rcx, pConsoleOut                                     
    invoke [rcx].ConOut.OutputString, rcx, ADDR HelloMsg 

    mov rcx, pConsoleOut                                     ;Colors change
    invoke [rcx].ConOut.SetAttribute, pConsoleOut, 07h

    mov r10, pBootServices
    invoke [r10].EFI_BOOT_SERVICES.SetWatchdogTimer, 0, 0, 0, NULL

    ;------------------------------------

    mov xdi, pBootServices
    invoke [xdi].EFI_BOOT_SERVICES.LocateProtocol, addr EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, NULL, addr GraphicsOutput
    mov Status, rax
    .if xax
        mov GraphicsOutput, NULL
        PrintLn "Loading Graphics_Output_Protocol error!"
        return EFI_SUCCESS
    .endif
    mov xax, GraphicsOutput
    mov xbx, [xax].EFI_GRAPHICS_OUTPUT_PROTOCOL.Mode   

    m2m qvar,[xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.MaxMode,xax
    ;PrintLn "Max mode     =[ %d  ] ", qvar

    m2m qvar, [xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.Mode, xax
    ;PrintLn "Current mode =[ %d  ] ", qvar

    ;m2m ScreenBufferM, [xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.FrameBufferBase, xax
    ;DbgHex ScreenBufferM

    mov xbx, [xbx].EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.Info      
    m2m ivar,[xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.Version, eax
    ;PrintLn "Version      =[ %i  ] ", ivar
    
    m2m ivar,[xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.HorizontalResolution, eax
    mov cdXSize, eax
    mov xcdXSize, xax
    ;PrintLn "Screen Width =[ %i  ] ", ivar

    m2m ivar, [xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.VerticalResolution, eax
    mov cdYSize, eax
    mov xcdYSize, xax
    ;PrintLn "Screen height=[ %i  ] ", ivar

    ;m2m ivar, [xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelFormat, eax
    ;PrintLn "Format       =[ %i  ] ", ivar

    m2m ivar,[xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelsPerScanLine, eax
    shl xax, 2
    mov Delta, xax
    ;PrintLn "Num of pixel =[ %i  ] ", ivar
     
    ;------------------------------------

    ;PrintLn "waiting for a key..."
    ;call Wait4Key

    mov rcx, pConsoleOut
    invoke [rcx].ConOut.ClearScreen, rcx
 
    if 0
    invoke IniciaObjeto

    invoke MemAlloc_UEFI, 0, sizeof triplete *500000
    mov todos, xax   
    endif
    
    mov eax , cdXSize
    mov ecx , cdYSize
    mul ecx
    shl eax, 2
    DbgDec eax
    invoke MemAlloc_UEFI, 0, eax
    mov ScreenBuffer, xax
    DbgHex xax   
    
    ;invoke psf_init
@as1:
    ;invoke CalculaObjeto
    ;invoke putchar, 58, 10, 10, 0FFFFFFh, 0FF0000h
    
    ;invoke draw_string, ScreenBuffer, $OfsCStr("Ñadá es 1234567890"), 10, 10, 0FFFFFFh, 0FF0000h
   ;invoke ShowAllPSF
    ;call Wait4Key
    
    New Graphic1
    mov pGraphic, rax
    
    OCall pGraphic::Graphic1.Init, NULL, ScreenBuffer, cdXSize, cdYSize, Delta
    if 0
    OCall pGraphic::Graphic1.InitSerieS, 0, 0FF0000FFh, SG_Modo_PipeLine, 0
    if 0
    mov r10,pGraphic
    mov xax, 1
    mov xcx, [r10].OA_Graphic1.BaseEjesY[xax*sizeof(POINTER)]
    mov xax, $OfsCStr("A N I M A L   C O M P O S I T I O N")
    mov [xcx].OA_Eje_gr1.titulo, xax
    endif
    
    OCall pGraphic::Graphic1.CargaPuntoS, 0, 195.0, 15.0
    OCall pGraphic::Graphic1.CargaPuntoS, 0, 450.0, 40.0
    OCall pGraphic::Graphic1.CargaPuntoS, 0, 600.0, 60.0
    endif

    OCall  $ObjTmpl(M0_Calculator)::M0_Calculator.Init 
    OCall  $ObjTmpl(M0_Calculator)::M0_Calculator.Calculo 
    OCall  $ObjTmpl(M0_Calculator)::M0_Calculator.MuestraG 

    OCall  $ObjTmpl(M0_Calculator)::M0_Calculator.Done 

    OCall pGraphic::Graphic1.Paint 
    ;call Wait4Key

           

    mov rcx, GraphicsOutput ; EFI_GRAPHICS_OUTPUT_PROTOCOL
    invoke [rcx].EFI_GRAPHICS_OUTPUT_PROTOCOL.Blt, rcx, ScreenBuffer, BLT_OP_EfiBltBufferToVideo,0,0,0,0,xcdXSize,xcdYSize, Delta 
    ;jmp @as1

    ;------------------------------------

    ;rintLn "waiting for a key..."
    call Wait4Key
    ;Kill pGraphic
    ;call Wait4Key
    
    mov rax, pConsoleOut                                     ;Colors change
    invoke [rax].ConOut.SetAttribute, pConsoleOut, 0Fh

    invoke MemFree_UEFI, ScreenBuffer
    if 0
    invoke MemFree_UEFI, todos
    endif

    CStr msg_bye, 13, 10,"bye bye...", 13, 10 
    mov rcx, pConsoleOut                                     
    invoke [rcx].ConOut.OutputString, rcx, ADDR msg_bye
    
    SysDone
    
    mov rax, pBootServices
    invoke [rax].EFI_BOOT_SERVICES.Exit, Handle, EFI_SUCCESS, 0, NULL
    
start endp

end start