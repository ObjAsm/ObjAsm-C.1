; ==================================================================================================
; Title:      UefiUtil.inc
; Authors:    Héctor S. Enrique
; Version:    C.1.0
; Purpose:    ObjAsm support of basic UEFI handling macros and procedures.
; Notes:      Version C.1.0, Héctor S. Enrique
;               - First release.
; ==================================================================================================


PrintC macro mensaje, args:VARARG
  local pos1

  mensaje1 textequ <>
  porc = 0
  cambioactivado = 0
  forc char, <&mensaje>
    tk_1 instr 1,<%>, <&char>
    if tk_1 eq 1
      porc = 1
    else
      if porc eq 0
        mensaje1 catstr mensaje1, <&char>
      elseif porc eq 2
        if cambiacolor eq 0
          mensaje1 catstr mensaje1, <%>,lastchar, <&char>
        endif
        porc = 0
      elseif porc eq 1
        cambiacolor = 0
        lastchar textequ <&char>
        ifidn lastchar, <N>
          cambiacolor = 1
          newueficolor = EFI_LIGHTGRAY
        endif
        ifidn lastchar, <H>
          cambiacolor = 1
          newueficolor = EFI_WHITE
        endif
        ifidn lastchar, <E>
          cambiacolor = 1
          newueficolor = EFI_RED
        endif
        ifidn lastchar, <A>
          cambiacolor = 1
          newueficolor = EFI_YELLOW
        endif
        ifidn lastchar, <B>
          cambiacolor = 1
          newueficolor = EFI_BLUE
        endif
        ifidn lastchar, <V>
          cambiacolor = 1
          newueficolor = EFI_GREEN
        endif
        porc = 2
        if (cambioactivado eq 0) AND (cambiacolor eq 1)
          cambioactivado = 1
        endif
      endif
    endif
  endm
  if porc eq 2
    if cambiacolor eq 0
      mensaje1 catstr mensaje1, <%>, lastchar, <&char>
    endif
  endif
  if cambioactivado eq 1
    mov rax, pConsoleOut                                     ;Colors change
    % invoke [rax].ConOut.SetAttribute, pConsoleOut, newueficolor
  endif
% PrintLn @CatStr(mensaje1, <,> <args>)
  if cambioactivado eq 1
    mov rax, pConsoleOut                                     ;Colors change
    % invoke [rax].ConOut.SetAttribute, pConsoleOut, 07h
  endif
endm


Print macro mensaje, args:VARARG
  local pos1

  ifndef UEFI_Print_Message
    UEFI_Print_Message = 0
  else
    UEFI_Print_Message = UEFI_Print_Message + 1
  endif
  ifndef UEFI_Print_buffer1
    .data
    UEFI_Print_buffer1 CHR 1024 dup (0)
    UEFI_Print_buffer2 CHR   32 dup (0)

    CStr UEFI_Error_0, "EFI_SUCCESS"
    CStr UEFI_Error_1, "EFI_LOAD_ERROR"
    CStr UEFI_Error_2, "EFI_INVALID_PARAMETER"
    CStr UEFI_Error_3, "EFI_UNSUPPORTED"
    CStr UEFI_Error_4, "EFI_BAD_BUFFER_SIZE"
    CStr UEFI_Error_5, "EFI_BUFFER_TOO_SMALL"
    CStr UEFI_Error_6, "EFI_NOT_READY"
    CStr UEFI_Error_7, "EFI_DEVICE_ERROR"
    CStr UEFI_Error_8, "EFI_WRITE_PROTECTED"
    CStr UEFI_Error_9, "EFI_OUT_OF_RESOURCES"
    CStr UEFI_Error_10, "EFI_VOLUME_CORRUPTED"
    CStr UEFI_Error_11, "EFI_VOLUME_FULL"
    CStr UEFI_Error_12, "EFI_NO_MEDIA"
    CStr UEFI_Error_13, "EFI_MEDIA_CHANGED"
    CStr UEFI_Error_14, "EFI_NOT_FOUND"
    CStr UEFI_Error_15, "EFI_ACCESS_DENIED"
    CStr UEFI_Error_16, "EFI_NO_RESPONSE"
    CStr UEFI_Error_17, "EFI_NO_MAPPING"
    CStr UEFI_Error_18, "EFI_TIMEOUT"
    CStr UEFI_Error_19, "EFI_NOT_STARTED"
    CStr UEFI_Error_20, "EFI_ALREADY_STARTED"
    CStr UEFI_Error_21, "EFI_ABORTED"
    CStr UEFI_Error_22, "EFI_ICMP_ERROR"
    CStr UEFI_Error_23, "EFI_TFTP_ERROR"
    CStr UEFI_Error_24, "EFI_PROTOCOL_ERROR"

    cuenta = 1
    EFI_ERROR$ dq offset UEFI_Error_0
    repeat 24
      % dq offset @CatStr(<UEFI_Error_>, %cuenta)
      cuenta = cuenta + 1
    endm
  endif

  .code
  cuenta = 0
  for arg,<args>
    @CatStr(<argumento_>, %cuenta) textequ <arg>
    cuenta = cuenta + 1
  endm
  mov CHR ptr UEFI_Print_buffer1, 0

  cuenta = 0
  pos1 = 0
  parte = 0
  contenido textequ <>
  tipoarg textequ <>

  abrecomilla = 0

  forc char,<&mensaje>
    tk_1 instr 1, <">, <&char>
    if tk_1 eq 0

      tk_3 instr 1, < >, <&char>
      if (tk_3 eq 1) AND (abierto eq 0)
        ifidn tipoarg, <d>
          invoke uqword2decW, addr UEFI_Print_buffer2, @CatStr(<argumento_>, %cuenta)
          invoke StrCat, addr UEFI_Print_buffer1, addr UEFI_Print_buffer2
        endif
        ifidn tipoarg, <h>
          invoke qword2hexW, addr UEFI_Print_buffer2, @CatStr(<argumento_>, %cuenta)
          invoke StrCat, addr UEFI_Print_buffer1, addr UEFI_Print_buffer2
        endif

        ifidn tipoarg, <r>
          cuento = 1
          %mov rax, @CatStr(<argumento_>,%cuenta)
          and rax, 0FFh
          .if rax == 0
            lea rdx, @CatStr(<UEFI_Error_>, 0)
          repeat 24
         % .elseif rax == cuento
            lea rdx, @CatStr(<UEFI_Error_>, %cuento)
            cuento = cuento + 1
          endm
          .endif
          invoke StrCat, addr UEFI_Print_buffer1, rdx
        endif
        abierto = 1
        tipoarg textequ <>
        cuenta = cuenta + 1
      endif

      tk_2 instr 1,<%>,<&char>
      if tk_2 eq 0
        if abierto eq 1
          contenido catstr contenido, <&char>
        else
          tipoarg catstr tipoarg, <&char>
        endif
      else
        if abierto eq 1
          abierto = 0
          @CatStr(<CStrW UEFI_Print_Message_>, %UEFI_Print_Message, <_>, %parte, <, !">,%contenido,<!">)
          invoke StrCat, addr UEFI_Print_buffer1, addr @CatStr(<UEFI_Print_Message_>, %UEFI_Print_Message, <_>, %parte)
          contenido textequ <>
          parte = parte + 1
        endif
      endif
    else
      if abrecomilla eq 1
      else
        abrecomilla = 1
        abierto = 1
      endif
    endif
  endm
  if parte eq 0
    if abierto
      @CatStr(<CStrW UEFI_Print_Message_>, %UEFI_Print_Message, <_>, %parte, <, !">,%contenido,<!">)
      invoke StrCat, addr UEFI_Print_buffer1, addr @CatStr(<UEFI_Print_Message_>, %UEFI_Print_Message, <_>, %parte)
    endif
  endif
  mov rcx, pConsoleOut
  invoke [rcx].ConOut.OutputString, rcx, addr UEFI_Print_buffer1
endm


PrintLn macro args:VARARG
  Print args
  mov rcx, pConsoleOut
  invoke [rcx].ConOut.OutputString, rcx, offset cCRLF
endm


TimingUEFIInit macro
.data
  TimeUEFI1 EFI_TIME {}
  TimeUEFI2 EFI_TIME {}
  capabilities EFI_TIME_CAPABILITIES {}

  miliseconds REAL8   0.0
  seconds     UINT32  0
  nanoseconds SDWORD  0
  ifndef mil
    mil   REAL8   1000.0
  endif
  millon  REAL8   1000000.0
  timingbuffer CHR 32 dup(0)
  nada    dword   0
  CStr nohay, "no hay nanosegundos", 13, 10

.code
  mov r8, pRuntimeServices
  invoke [r8].EFI_RUNTIME_SERVICES.GetTime, addr TimeUEFI1, addr capabilities
endm


TimingUEFIEnding macro
  mov rax, pRuntimeServices
  invoke [rax].EFI_RUNTIME_SERVICES.GetTime, addr TimeUEFI2, NULL
  xor ecx, ecx
  xor rax, rax
  mov al, TimeUEFI2.Hour
  .if al > TimeUEFI1.Hour
    sub al, TimeUEFI1.Hour
    mov ecx, 60*60
    mul ecx
    mov ecx, eax
  .elseif al < TimeUEFI1.Hour
    add al, 24
    sub al, TimeUEFI1.Hour
    mov ecx, 60*60
    mul ecx
    mov ecx, eax
  .endif

  xor rax, rax
  mov al, TimeUEFI2.Minute
  .if al != TimeUEFI1.Minute
    sub al, TimeUEFI1.Minute
    mov edx, 60
    mul edx
    movsx edx, al
    add ecx, edx
  .endif

  xor rax, rax
  mov al, TimeUEFI2.Second
  .if al != TimeUEFI1.Second
    sub al, TimeUEFI1.Second
    movsx edx, al
    add ecx, edx
  .endif
  mov seconds, ecx

  lea rax, mut_eve
  mov r10, 4
  call qwait64
  qlock64 mut_eve, 4

  fild seconds
  invoke St0ToStr, addr timingbuffer, 8, 4, 0
  fstp miliseconds
  mov rcx, pConsoleOut
  invoke [rcx].ConOut.OutputString, rcx, addr timingbuffer

  CStr str_resol, 13, 10, "Resolution: "
  mov rcx,pConsoleOut
  invoke [rcx].ConOut.OutputString, rcx, addr str_resol
  m2z timingbuffer
  ;invoke uq2baseW, addr timingbuffer, capabilities.Resolution, 10
  invoke sqword2decW, addr timingbuffer, capabilities.Resolution
  mov rcx, pConsoleOut
  invoke [rcx].ConOut.OutputString, rcx, addr timingbuffer

  CStr str_accu, 13, 10, "Accuracy:  "
  mov rcx,pConsoleOut
  invoke [rcx].ConOut.OutputString, pConsoleOut, addr str_accu

  m2z timingbuffer
  ;invoke uq2baseW, addr timingbuffer, capabilities.Accuracy, 10
  invoke sqword2decW, addr timingbuffer, capabilities.Accuracy
  mov rcx, pConsoleOut
  invoke [rcx].ConOut.OutputString, rcx, addr timingbuffer

  qunlock64 mut_eve, 4

  @@lo4:
  ;pause
  ;jmp @@lo4
endm


.code
Wait4Key proc uses xbx xsi
  local xKeyEvent:XWORD

  mov xbx, pConsoleIn
  mov xsi, pBootServices
  .while TRUE
    mov xKeyEvent, EVT_NOTIFY_SIGNAL
    invoke [xsi].EFI_BOOT_SERVICES.WaitForEvent, 1, addr [xbx].ConIn.WaitForKey, addr xKeyEvent
    .if xax == EFI_SUCCESS
      invoke [xbx].ConIn.ReadKeyStroke, xbx, addr xKeyEvent
      .continue .if xax == EFI_NOT_READY
      .break
    .endif
  .endw
  ret
Wait4Key endp


RAWINTERFACE iEFIUtil
  STDFUNC PrintMemoryDescriptor, <voidarg>, pConsoleOut:PCONOUT, pDescriptor:ptr EFI_MEMORY_DESCRIPTOR
  STDFUNC PrintGraphicsModeInfo, <voidarg>, pConsoleOut:PCONOUT, ModeNumber:DWORD, pGfxMode:ptr EFIGraphicsMode, showHeader:BOOLEAN
  STDFUNC CompareGUID, <voidarg>, guidA:ptr, guidB:ptr
ENDRAWINTERFACE
PEFIUtil TYPEDEF ptr iEFIUtil

PrintHexNumber    PROTO :QWORD, :DWORD, :DWORD

PrintHexBYTE      PROTO :BYTE
PrintHexWORD      PROTO :WORD
PrintHexDWORD     PROTO :DWORD
PrintHexQWORD     PROTO :QWORD
PrintLnHexBYTE    PROTO :BYTE
PrintLnHexWORD    PROTO :WORD
PrintLnHexDWORD   PROTO :DWORD
PrintLnHexQWORD   PROTO :QWORD

PrintLnDecDWORD   PROTO :DWORD

.const
hexLUT  dw '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'
hexPFX  dw "0x"

.data
hexSTR dw 20 DUP (0)

_EFIUtil iEFIUtil <OFFSET EFIPrintMemDescriptor, OFFSET EFIPrintGfxInfo, OFFSET EFICompareGuid>
;pEFIUtil PEFIUtil OFFSET _EFIUtil            ; Pointer to our Util Raw Interface.

MaxEFIVideoMode     dd    0                ; Maximum Video Mode Number (0-n).
CurrentEFIMode      dd    0                ; Current EFI GOP Video Mode Number.
FrameBufferPtr      dq    0                ; Linear Frame Buffer Pointer.
GOPInfoSize         UINTN 0                ; Returned size of the video mode info buffer.
pGOPMode            dq    0                ; Pointer to GOP allocated EFI_GRAPHICS_OUTPUT_MODE_INFORMATION structure.
EFIMemBuffer        dq    0
EFIMemBufferAcc     dq    0


.code

PrintHexNumber proc uses xsi xdi xbx number:QWORD, bits:DWORD, digits:DWORD
  lea xdi, hexSTR
  lea xsi, hexLUT
  lea xdx, hexPFX

  ;Copy 0x prefix to string buffer.
  mov eax, [xdx]
  mov [xdi], eax
  add xdi, 4

  ;Transfer 16 digits.
  mov xbx, xcx
  mov ecx, bits
  sub ecx, 4            ;One nibble less.
  mov edx, digits       ;Number of digits
cpy:
  mov xax, xbx
  shr xax, cl
  and xax, 0x0f
  mov ax, [xsi + xax*2] ;ax = hexLUT[digit]
  mov [xdi], ax         ;copy to hexSTR
  add xdi, 2            ;move forward one char
  sub cl, 4
  dec edx
  jnz short cpy

  ;Null-terminate.
  mov word ptr [xdi], 0

  mov xcx, pConsoleOut
  invoke [xcx].ConOut.OutputString, pConsoleOut, addr hexSTR

  ret
PrintHexNumber endp


PrintHexBYTE proc number:BYTE
  and rcx, 0xff
  invoke PrintHexNumber, rcx, 8, 2
  ret
PrintHexBYTE endp

PrintHexWORD proc number:WORD
  and rcx, 0xffff
  invoke PrintHexNumber, rcx, 16, 4
  ret
PrintHexWORD endp

PrintHexDWORD proc number:DWORD
  and rcx, 0xffffffff
  invoke PrintHexNumber, rcx, 32, 8
  ret
PrintHexDWORD endp

PrintHexQWORD proc number:QWORD
  invoke PrintHexNumber, number, 64, 16
  ret
PrintHexQWORD endp


PrintLnHexBYTE proc number:BYTE
  and rcx, 0xff
  invoke PrintHexNumber, rcx, 8, 2
  mov xcx, pConsoleOut
  invoke [xcx].ConOut.OutputString, pConsoleOut, offset cCRLF
  ret
PrintLnHexBYTE endp

PrintLnHexWORD proc number:WORD
  and rcx, 0xffff
  invoke PrintHexNumber, rcx, 16, 4
  mov xcx, pConsoleOut
  invoke [xcx].ConOut.OutputString, pConsoleOut, offset cCRLF
  ret
PrintLnHexWORD endp

PrintLnHexDWORD proc number:DWORD
  and rcx, 0xffffffff
  invoke PrintHexNumber, rcx, 32, 8
  mov xcx, pConsoleOut
  invoke [xcx].ConOut.OutputString, pConsoleOut, offset cCRLF
  ret
PrintLnHexDWORD endp

PrintLnHexQWORD proc number:QWORD
  invoke PrintHexNumber, number, 64, 16
  mov xcx, pConsoleOut
  invoke [xcx].ConOut.OutputString, pConsoleOut, offset cCRLF
  ret
PrintLnHexQWORD endp


PrintLnDecDWORD proc dNumber:DWORD
  local cBuffer[DWORD2DEC_MAX_CHARS]:CHR

  invoke udword2dec, addr cBuffer, dNumber
  mov xcx, pConsoleOut
  invoke [xcx].ConOut.OutputString, pConsoleOut, addr cBuffer
  mov xcx, pConsoleOut
  invoke [xcx].ConOut.OutputString, pConsoleOut, offset cCRLF
  ret
PrintLnDecDWORD endp

EFICompareGuid proc uses xsi xdi xbx guidA:ptr, guidB:ptr
  mov xsi, guidA
  mov xdi, guidB

  mov rbx, [rsi]
  mov rcx, [rsi + 8]
  mov rdx, [rdi]
  mov r8, [rdi+8]

  mov eax, FALSE
  .if (rbx == rdx && rcx == r8)
    mov eax, TRUE
  .endif
  ret
EFICompareGuid endp

EFIPrintGfxInfo proc uses rsi r10 r11 pConsoleOut:PCONOUT, ModeNumber:DWORD, pGfxMode:ptr EFIGraphicsMode, showHeader:BOOLEAN
  mov rsi, r8
  if 0
    .if (showHeader == 1)
      mov rcx, pConsoleOut
      pConsoleOut->OutputString(pConsoleOut, L"Mode       | Resolution              | Stride     | Pixel Format \r\n")
      pConsoleOut->OutputString(pConsoleOut, L"-----------+-------------------------+------------+--------------------\r\n")
    .endif

    PrintHexDWORD(ModeNumber)
    pConsoleOut->OutputString(pConsoleOut, L" | ")

    PrintHexDWORD((EFI_GRAPHICS_OUTPUT_MODE_INFORMATION ptr [rsi]).HorizontalResolution)
    pConsoleOut->OutputString(pConsoleOut, L" x ")
    PrintHexDWORD((EFI_GRAPHICS_OUTPUT_MODE_INFORMATION ptr [rsi]).VerticalResolution)
    pConsoleOut->OutputString(pConsoleOut, L" | ")

    PrintHexDWORD((EFI_GRAPHICS_OUTPUT_MODE_INFORMATION ptr [rsi]).PixelsPerScanLine)
    pConsoleOut->OutputString(pConsoleOut, L" | ")

    mov r10d, (EFI_GRAPHICS_OUTPUT_MODE_INFORMATION ptr [rsi]).PixelFormat
    .switch r10
      .case EFI_PIX_FMT_PixelRedGreenBlueReserved8BitPerColor
        pConsoleOut->OutputString(pConsoleOut, L"32bit RGBx\r\n")
        .break
      .case EFI_PIX_FMT_PixelBlueGreenRedReserved8BitPerColor
        pConsoleOut->OutputString(pConsoleOut, L"32bit BGRx\r\n")
        .break
      .case EFI_PIX_FMT_PixelBitMask
        pConsoleOut->OutputString(pConsoleOut, L"32bit Pixel Mask\r\n")
        .break
      .case EFI_PIX_FMT_PixelBltOnly
        pConsoleOut->OutputString(pConsoleOut, L"BLT Only\r\n")
        .break
    .endsw
  endif
  ret
EFIPrintGfxInfo endp

EFIPrintMemDescriptor proc uses rsi r10 r11 pConsoleOut:PCONOUT, pDescriptor:ptr EFI_MEMORY_DESCRIPTOR
  mov rsi, rdx
  if 0
    PrintHexDWORD((EFI_MEMORY_DESCRIPTOR ptr [rsi])._Type)
    pConsoleOut->OutputString(pConsoleOut, L" | ")

    PrintHexQWORD((EFI_MEMORY_DESCRIPTOR ptr [rsi]).PhysicalStart)
    pConsoleOut->OutputString(pConsoleOut, L" | ")

    PrintHexQWORD((EFI_MEMORY_DESCRIPTOR ptr [rsi]).VirtualStart)
    pConsoleOut->OutputString(pConsoleOut, L" | ")

    PrintHexQWORD((EFI_MEMORY_DESCRIPTOR ptr [rsi]).NumberOfPages)
    pConsoleOut->OutputString(pConsoleOut, L" | ")

    PrintHexQWORD((EFI_MEMORY_DESCRIPTOR ptr [rsi]).Attribute)
    pConsoleOut->OutputString(pConsoleOut, &cCRLF)
  endif
  ret
EFIPrintMemDescriptor endp


;include mutex64.inc