; ==================================================================================================
; Title:   ConsoleUEFI.asm
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: ObjAsm compilation file for Console UEFI Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================
    xword textequ <XWORD> 
    

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIDE_STRING, UEFI64, DEBUG(CON)             ;Load OOP files and basic OS support

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

;    GraphicsOutput PGOP NULL

    mapSize     UINTN  512*SIZEOF(EFI_MEMORY_DESCRIPTOR)
    descriptors EFI_MEMORY_DESCRIPTOR 512 DUP (<?>)
    mapKey      UINTN  0
    descSize    UINTN  0
    descVer     UINT32 0
    align @WordSize
    buffer      CHR 32 dup (0)
    CStr crlf$,13,10

    ScreenBufferM   POINTER 0
    
    pGraphicConsole POINTER 0

    xcdXSize    xword   640
    xcdYSize    xword   400
    
    IntegRun POINTER 0
    
    include .\App\App_globals.inc
.code

% include @Environ(OBJASM_PATH)\\Code\\Macros\\fMath.inc

% include @Environ(OBJASM_PATH)\\AddedSoftware\SmplMath-main\SmplMath\math.inc
fSlvSelectBackEnd FPU

% include @Environ(OBJASM_PATH)\\AddedSoftware\mreal-macros-main\real_math.inc

@reg32_64 ecx, r10
@reg32_64 edx, r11

MakeObjects Primer, LinkedList
MakeObjects .\GraphicsUEFI\PixelUEFI, .\GraphicsUEFI\CharsUEFI
MakeObjects .\GraphicsUEFI\ConsoleUEFI

start proc uses xbx xdi xsi ImageHandle:EFI_HANDLE, pSysTable:PTR_EFI_SYSTEM_TABLE
    local cBuffer[100]:CHR

    local Status : EFI_STATUS
    local Delta: XWORD
    local ScreenBuffer:POINTER
    local i: xword


                                                 ;Runtime model initialization
    ;Runtime model initialization
    SysInit ImageHandle, pSysTable

    mov r10, pBootServices
    invoke [r10].EFI_BOOT_SERVICES.SetWatchdogTimer, 0, 0, 0, NULL

    ;call Wait4Key  
    ;------------------------------------
    PLATFORM_UEFI_MEMORY = EFI_MEMORY_TYPE_EfiLoaderData
    New ConsoleUEFI
    mov pGraphicConsole, xax
    PLATFORM_UEFI_MEMORY = EFI_MEMORY_TYPE_EfiBootServicesData       

    OCall pGraphicConsole::ConsoleUEFI.InitBoot, pBootServices

    OCall pGraphicConsole::ConsoleUEFI.ClearScreen 
   
    OCall pGraphicConsole::ConsoleUEFI.SetPos, 35, 10
    OCall pGraphicConsole::ConsoleUEFI.DrawStrCon, $OfsCStr("Console UEFI")
    ;------------------------------------

    ;PrintLn "waiting for a key..."
;    call Wait4Key


    OCall pGraphicConsole::ConsoleUEFI.SetPos, 1, 17
    OCall pGraphicConsole::ConsoleUEFI.SetForeground, 0FFFF00h
    OCall pGraphicConsole::ConsoleUEFI.DrawStrCon, $OfsCStr("Press any key to continue ...")

    call Wait4Key  
    
    mov xax, pBootServices
    invoke [xax].EFI_BOOT_SERVICES.ExitBootServices, 0, NULL
    ;invoke [xax].EFI_BOOT_SERVICES.Exit, Handle, EFI_SUCCESS, 0, NULL

    OCall pGraphicConsole::ConsoleUEFI.Cr
    OCall pGraphicConsole::ConsoleUEFI.Lf
    OCall pGraphicConsole::ConsoleUEFI.Lf


    OCall pGraphicConsole::ConsoleUEFI.SetForeground, 0AAAAAAh

    ForLp i, 0, 80
        OCall pGraphicConsole::ConsoleUEFI.Tab
        invoke sqword2decW, addr cBuffer, i
        OCall pGraphicConsole::ConsoleUEFI.DrawStrCon,  addr cBuffer
        OCall pGraphicConsole::ConsoleUEFI.Cr
        OCall pGraphicConsole::ConsoleUEFI.Lf
    Next i 
    
    OCall pGraphicConsole::ConsoleUEFI.Cr
    OCall pGraphicConsole::ConsoleUEFI.Lf
    OCall pGraphicConsole::ConsoleUEFI.Lf
    
    OCall pGraphicConsole::ConsoleUEFI.SetForeground, 0FFFF00h
    OCall pGraphicConsole::ConsoleUEFI.DrawStrCon, $OfsCStr("bye bye")
    
    OCall pGraphicConsole::ConsoleUEFI.Done 
    Destroy pGraphicConsole

    SysDone
    
    
start endp

end start