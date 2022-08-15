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

return macro valor1
    mov rax, &valor1
    ret
endm

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIDE_STRING, UEFI64;, DEBUG(CON)             ;Load OOP files and basic OS support

.data
    Handle           EFI_HANDLE 0
    SystemTablePtr   dq 0
    MpProto          dq 0

    ;pConsole         PCONOUT 0
    ;pConsoleIn       PCONIN  0
    ;pBootServices    P_BOOT_SERVICES 0
    ;pRuntimeServices P_RUNTIME_SERVICES 0

    GraphicsOutput PGOP NULL

    mapSize     UINTN  512*SIZEOF(EFI_MEMORY_DESCRIPTOR)
    descriptors EFI_MEMORY_DESCRIPTOR 512 DUP (<?>)
    mapKey      UINTN  0
    descSize    UINTN  0
    descVer     UINT32 0
    align @WordSize
    buffer      CHR 32 dup (0)
    CStr crlf$,13,10

    NaN REAL8  7FF8000000000000r

    Red_Pixel db 0,-1,0,0 ; EFI_GRAPHICS_OUTPUT_BLT_PIXEL array of one item
    Red_Black db 0,0,0,0 ; EFI_GRAPHICS_OUTPUT_BLT_PIXEL array of one item
    ScreenBuffer  POINTER 0
    ScreenBufferM POINTER 0
.code

include \masm32\macros\SmplMath\math.inc
fSlvSelectBackEnd FPU

include aizawa7.inc

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

    m2m ivar, [xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelFormat, eax
    PrintLn "Format       =[ %i  ] ", ivar

    m2m ivar,[xbx].EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelsPerScanLine, eax
    shl xax, 2
    mov Delta, xax
    ;PrintLn "Num of pixel =[ %i  ] ", ivar

    ;------------------------------------

    PrintLn "waiting for a key..."
    call Wait4Key

    mov rcx, pConsoleOut
    invoke [rcx].ConOut.ClearScreen, rcx

    invoke IniciaObjeto

    invoke MemAlloc_UEFI, 0, sizeof triplete *500000
    mov todos, xax

        mov eax , cdXSize
        mov ecx , cdYSize
        mul ecx
        shl eax, 2
    invoke MemAlloc_UEFI, 0, eax
    mov ScreenBuffer, xax

@as1:
    invoke CalculaObjeto
    mov rcx, GraphicsOutput ; EFI_GRAPHICS_OUTPUT_PROTOCOL
    invoke [rcx].EFI_GRAPHICS_OUTPUT_PROTOCOL.Blt, rcx, ScreenBuffer, BLT_OP_EfiBltBufferToVideo,0,0,0,0,xcdXSize,xcdYSize, Delta
    jmp @as1

    ;------------------------------------

    PrintLn "waiting for a key..."
    call Wait4Key
    mov rax, pConsoleOut                                     ;Colors change
    invoke [rax].ConOut.SetAttribute, pConsoleOut, 0Fh

    invoke MemFree_UEFI, ScreenBuffer
    invoke MemFree_UEFI, todos

    CStr msg_bye, 13, 10,"bye bye...", 13, 10
    mov rcx, pConsoleOut
    invoke [rcx].ConOut.OutputString, rcx, ADDR msg_bye

    SysDone

    mov rax, pBootServices
    invoke [rax].EFI_BOOT_SERVICES.Exit, Handle, EFI_SUCCESS, 0, NULL

start endp

end start