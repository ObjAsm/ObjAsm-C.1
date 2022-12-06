; ==================================================================================================
; Title:   PixelUEFI.inc
; Author:  H. S. Enrique / G. Friedrich / Homer 
; Version: 1.0.0
; Purpose: ObjAsm support for drawing in non-OS Application.
; Version: Version 1.0.0, June 2022
;            - First release.
;
; ==================================================================================================

Object PixelUEFI,, Primer
    RedefineMethod Init, POINTER, DWORD, DWORD, XWORD
    RedefineMethod Done
    
    VirtualMethod  FillBkGnd, DWORD
  
    DefineVariable pPixels   , POINTER, 0
    
    DefineVariable dWidth    , DWORD, 0
    DefineVariable dHeight   , DWORD, 0
    DefineVariable dDelta    , DWORD, 0
    DefineVariable dSizeImage, DWORD, 0
    
    VirtualMethod    BresLine, SDWORD, SDWORD, SDWORD, SDWORD, DWORD
    VirtualMethod    BresLine2, SDWORD, SDWORD, SDWORD, SDWORD, DWORD
    VirtualMethod    DottedLine, SDWORD, SDWORD, SDWORD, SDWORD, DWORD, DWORD
    VirtualMethod    Pipeline, SDWORD, SDWORD, SDWORD, SDWORD, DWORD

    VirtualMethod    drawPixel, SDWORD, SDWORD, DWORD, REAL4

    ; Original ObjAsm PixelMap, 
    VirtualMethod   DrawLine,             SDWORD, SDWORD, SDWORD, SDWORD, DWORD
    StaticMethod    FillRect,             PRECT, DWORD
    VirtualMethod   SetPixel,             DWORD, DWORD, DWORD
    
    ;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    VirtualMethod  BresLine3,dword,dword,dword,dword,dword,dword
    VirtualMethod  vertical3,dword,dword,dword,dword,dword,dword
    VirtualMethod  horizontal3,dword,dword,dword,dword,dword,dword

    DefineVariable Dot, dword, 01010101010101010b	
    DefineVariable dotp, dword, 0	; guarda puntero a Resul03
 
ObjectEnd

PXM_CHANNEL_RED     equ   1
PXM_CHANNEL_BLUE    equ   2
PXM_CHANNEL_GREEN   equ   4
PXM_CHANNEL_ALPHA   equ   8

PXM_FORMAT_PXM      equ   0

PXM_ADDR_LIN        equ   0
PXM_ADDR_WRAP       equ   1
PXM_ADDR_MIRROR     equ   2
PXM_ADDR_CLAMP      equ   3


; ==================================================================================================

if IMPLEMENT

    .data
    	gral1px real8 0.0

; ——————————————————————————————————————————————————————————————————————————————————————————————————

;Some used constants
PXM_MASK_0001             equ   0000000FFh
PXM_MASK_0010             equ   00000FF00h
PXM_MASK_0100             equ   000FF0000h
PXM_MASK_0101             equ   000FF00FFh
PXM_MASK_1010             equ   0FF00FF00h
PXM_MASK_REG_RGB          equ   000FFFFFFh
PXM_MASK_REG_ARGB         equ   0FFFFFFFFh
PXM_MASK_REG_ALPHA        equ   0FF000000h
PXM_MASK_REG_RED          equ   000FF0000h
PXM_MASK_REG_GREEN        equ   00000FF00h
PXM_MASK_REG_BLUE         equ   0000000FFh
PXM_MASK_MEM_RGB          equ   0FFFFFF00h
PXM_MASK_MEM_ARGB         equ   0FFFFFFFFh
PXM_MASK_MEM_ALPHA        equ   0000000FFh
PXM_MASK_MEM_RED          equ   00000FF00h
PXM_MASK_MEM_GREEN        equ   000FF0000h
PXM_MASK_MEM_BLUE         equ   0FF000000h
PXM_CHANNEL_OFFSET_BLUE   equ   0
PXM_CHANNEL_OFFSET_GREEN  equ   1
PXM_CHANNEL_OFFSET_RED    equ   2
PXM_CHANNEL_OFFSET_ALPHA  equ   3

REAL4_SIZE                equ   sizeof REAL4

RGBQUAD_SIZE              equ   sizeof RGBQUAD
LOG2_RGBQUAD_SIZE         equ   $Log2(RGBQUAD_SIZE)

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Perform a component intensity multiplication using ARGB pixel nibbles.

Pxm_Blend_ARGB macro Reg1:req, Reg2:req, Density:req
  mov Reg2, Reg1
  and Reg1, PXM_MASK_1010                               ;Get pixel nibbles
  and Reg2, PXM_MASK_0101
  shr Reg1, 8
  imul Reg2, Density                                    ;Compute new component intensity
  imul Reg1, Density
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Perform the merging of partial ARGB blending operations.

Pxm_BlendMerge_ARGB macro Reg1:req, Reg2:req, Reg3:req, Reg4:req
  add Reg2, Reg4
  add Reg1, Reg3                                        ;Merge the 2 pixel nibbles
  shr Reg2, 8
  and Reg1, PXM_MASK_1010
  and Reg2, PXM_MASK_0101
  or Reg1, Reg2
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Perform a component intensity multiplication using RGB pixel nibbles.
;             Alpha value is set to zero.

Pxm_PixelBlend_RGB macro Reg1:req, Reg2:req, Density:req
  mov Reg2, Reg1
  and Reg1, PXM_MASK_0010                               ;Get pixel nibbles
  and Reg2, PXM_MASK_0101
  imul Reg1, Density                                    ;Compute new component intensity
  imul Reg2, Density
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Perform the merging of partial RGB blending operations.
;             Alpha value is set to zero.

Pxm_PixelMerge_RGB macro Reg1:req, Reg2:req, Reg3:req, Reg4:req
  add Reg1, Reg3                                        ;Merge the 2 pixel nibbles
  add Reg2, Reg4
  and Reg1, PXM_MASK_0100
  and Reg2, PXM_MASK_1010
  or Reg1, Reg2
  shr Reg1, 8
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Order the RECT arguments so that RECT.left <= RECT.right and RECT.top <= RECT.bottom.
; Uses:       eax, ecx

Pxm_FlipInvertedRect macro Rct:req
  mov eax, Rct.right
  .if SDWORD ptr eax < Rct.left
    mov ecx, Rct.left
    mov Rct.left, eax
    mov Rct.right, ecx
  .endif
  mov eax, Rct.bottom
  .if SDWORD ptr eax < Rct.top
    mov ecx, Rct.top
    mov Rct.top, eax
    mov Rct.bottom, ecx
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Calculate the intersection of 2 RECTs (my replacement of the IntersectRect API).
; Uses:       eax, ecx

Pxm_ClipRect macro DstRct:req, SrcRct1:req, SrcRct2:req
  mov ecx, SrcRct1.left
  cmp ecx, SrcRct2.left
  if @Cpu and CPU_686
    cmovl ecx, SrcRct2.left
  else
    .if SDWORD ptr ecx < SrcRct2.left
      mov ecx, SrcRct2.left
    .endif
  endif
  mov eax, SrcRct1.right
  cmp eax, SrcRct2.right
  if @Cpu and CPU_686
    cmovg eax, SrcRct2.right
  else
    .if SDWORD ptr eax > SrcRct2.right
      mov eax, SrcRct2.right
    .endif
  endif
  cmp eax, ecx
  jle @@EOM                                              ;Early method exit
  mov DstRct.left, ecx
  mov DstRct.right, eax
  mov ecx, SrcRct1.top
  cmp ecx, SrcRct2.top
  if @Cpu and CPU_686
    cmovl ecx, SrcRct2.top
  else
    .if SDWORD ptr ecx < SrcRct2.top
      mov ecx, SrcRct2.top
    .endif
  endif
  mov eax, SrcRct1.bottom
  cmp eax, SrcRct2.bottom
  if @Cpu and CPU_686
    cmovg eax, SrcRct2.bottom
  else
    .if SDWORD ptr eax > SrcRct2.bottom
      mov eax, SrcRct2.bottom
    .endif
  endif
  cmp eax, ecx
  jle @@EOM                                             ;Early method exit
  mov DstRct.top, ecx
  mov DstRct.bottom, eax
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Get address of a pixel in the Pixelmap.
; Uses:       xax

Pxm_PixelAddr macro XPos:req, YPos:req, ObjReg:=<xsi>
  mov eax, YPos
  mul [ObjReg].dWidth
  add eax, XPos
  shl xax, LOG2_RGBQUAD_SIZE
  add xax, [ObjReg].pPixels
endm

$Pxm_PixelAddr macro XPos:req, YPos:req, ObjReg:=<xsi>
  Pxm_PixelAddr XPos, YPos, ObjReg
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Get the bytes to reach the next line
; Uses:       eax

$Pxm_Bytes2Skip macro DimX:req, ObjReg:=<xsi>
  mov eax, [ObjReg].dWidth
  sub eax, DimX
  shl eax, LOG2_RGBQUAD_SIZE
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Transformation from destination to source space => DstRct/SrcPnt to SrcRct/DstPnt
; Uses:       eax, ecx, edx

Dst2SrcSpace macro Rct:req, Pnt:req
  mov ecx, Pnt.x
  mov edx, Rct.left
  mov eax, Rct.right
  sub eax, edx
  add eax, ecx
  mov Rct.left, ecx
  mov Rct.right, eax
  mov Pnt.x, edx

  mov ecx, Pnt.y
  mov edx, Rct.top
  mov eax, Rct.bottom
  sub eax, edx
  add eax, ecx
  mov Rct.top, ecx
  mov Rct.bottom, eax
  mov Pnt.y, edx
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————


;      WinHelpers


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CloneRect
; Purpose:    Copy the coordinates from the source to the destination RECT.
; Arguments:  Arg1: Destination RECT structure.
;             Arg2: Source RECT structure.
;             Arg3: optional registers to be used to copy the RECT content.
; Return:     Nothing.

CloneRect macro DstRct:req, SrcRct:req, AuxRegs:vararg
  ifb <AuxRegs>
    s2s DstRct, SrcRct, xax
  else
    s2s DstRct, SrcRct, AuxRegs
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      GrowRect
; Purpose:    Change the size of a RECT by a specified value.
; Arguments:  Arg1: RECT structure.
;             Arg2: X size to grow.
;             Arg2: (optional) Y size to grow.
; Return:     Nothing.

GrowRect macro Rect:req, dSX:=<0>, dSY:=<>
  ifdifi <dSX>, <0>
    sub Rect.left, dSX
    add Rect.right, dSX
  endif

  ifb <dSY>
    ??SY textequ <dSX>
  else
    ??SY textequ <dSY>
  endif

  %ifdifi <??SY>, <0>
    %sub Rect.top, ??SY
    %add Rect.bottom, ??SY
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      MoveRect
; Purpose:    Move a RECT by a specified X/Y value.
; Arguments:  Arg1: -> RECT structure.
;             Arg2: X size to move.
;             Arg3: (optional) Y size to move.
; Return:     Nothing.

MoveRect macro Rect:req, dSX:req, dSY:=<>
  ifdifi <dSX>, <0>
    add Rect.left, dSX
    add Rect.right, dSX
  endif

  ifb <dSY>
    ??SY textequ <dSX>
  else
    ??SY textequ <dSY>
  endif

  %ifdifi <??SY>, <0>
    %add Rect.top, ??SY
    %add Rect.bottom, ??SY
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $MakePointS
; Purpose:    Return a POINTS structure (DWORD) containing the coordinates indicated in args.
; Arguments:  Arg1: X position.
;             Arg2: Y position.
; Return:     POINT structure.

$MakePointS macro XPos:req, YPos:req
  exitm <YPos*0FFFFh + XPos>
endm


Method PixelUEFI.Init, uses xsi, screen1: POINTER, x1:dword, y1: dword, delta1:xword
    SetObject xsi
    
    m2m [xsi].pPixels, screen1, rax
    m2m [xsi].dWidth, x1, eax
    m2m [xsi].dHeight, y1, ecx
    mov xax, delta1
    mov [xsi].dDelta, eax
    mul xcx
    mov [xsi].dSizeImage, eax
    
MethodEnd
Method PixelUEFI.Done, uses xsi
    SetObject xsi
    
MethodEnd

Method PixelUEFI.FillBkGnd, uses xdi xbx, dARGB:DWORD
    local i:dword, i_t:dword
    local j:dword, j_t:dword
    
    DbgText "PixelUEFI.FillBkGnd"
    SetObject xbx
  
    .if [xbx].pPixels != 0
        mov ecx , [xbx].dDelta
        .if ecx == [xbx].dHeight 
            cld
            mov ecx, [xbx].dSizeImage
            mov xdi, [xbx].pPixels
            mov eax, dARGB
            RGB2BGR eax
            rep stosd
        .else   
            mov edi, dARGB
            RGB2BGR edi
            ForLp_df i, 0, [xbx].dHeight, eax
                ForLp_df j, 0, [xbx].dWidth, eax
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
    .endif
MethodEnd
;-----------------------------------------------------------------------------------------------
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.FillRect
; Purpose:    Fill a rectangular area of the Pixelmap with an ARGB value.
; Arguments:  Arg1: -> RECT to fill.
;             Arg2: ARGB value.
; Return:     Nothing.

Method PixelUEFI.FillRect, uses xbx xdi xsi, pDstRct:PRECT, dARGB:DWORD
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT
  local dDens1:DWORD, dDens2:DWORD

  SetObject xsi
  .if [xsi].pPixels != 0
    ;Flip SrcRct if necessary
    mov xcx, pDstRct
    CloneRect DstRct, RECT ptr [xcx], xax, xdx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    mov ecx, dARGB
    RGB2BGR ecx
    mov eax, dARGB
    shr eax, 32 - 8

    .if al == 255
      mov ebx, dHeight
      test ebx, ebx
      .while !ZERO?
        mov edi, dWidth
        test edi, edi
        .while !ZERO?
          mov [xsi], ecx
          add xsi, RGBQUAD_SIZE
          dec edi
        .endw
        add xsi, xSkipY
        dec ebx
      .endw

    .elseif al != 0
      mov dDens1, eax
      neg ax
      add ax, 0FFh
      mov dDens2, eax                                   ;Dens2 = Complement to dDens1

      Pxm_Blend_ARGB ecx, edx, dDens1
      mov eax, dHeight
      test eax, eax
      .while !ZERO?
        mov edi, dWidth
        test edi, edi
        .while !ZERO?
          mov eax, [xsi]                                ;Get original pixel
          Pxm_Blend_ARGB eax, ebx, dDens2
          Pxm_BlendMerge_ARGB eax, ebx, ecx, edx
          mov [xsi], eax                                ;Store new color
          add xsi, RGBQUAD_SIZE
          dec edi
        .endw
        add xsi, xSkipY
        dec dHeight
      .endw
    .endif
  .endif
MethodEnd
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.SetPixel
; Purpose:    Set the ARGB value of a given pixel.
; Arguments:  Arg1: X location.
;             Arg2: Y location.
;             Arg3: New ARGB value.
; Return:     Nothing.

Method PixelUEFI.SetPixel,, dCoorX:DWORD, dCoorY:DWORD, dARGB:DWORD
  SetObject xdx
  .if [xdx].pPixels != 0
    mov eax, dCoorY
    .if SDWORD ptr eax >= 0 && SDWORD ptr eax < [xdx].dHeight
      mov ecx, dCoorX
      .if SDWORD ptr ecx >= 0 && SDWORD ptr ecx < [xdx].dWidth
        shl xcx, LOG2_RGBQUAD_SIZE
        add xcx, [xdx].pPixels
        mul [xdx].dWidth
        mov edx, dARGB
        RGB2BGR edx
        mov [RGBQUAD_SIZE*xax + xcx], edx
      .else
;        DbgWarning "X coordinate out of range in SetPixel"
      .endif
    .else
;      DbgWarning "Y coordinate out of range in SetPixel"
    .endif
  .endif
MethodEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.DrawLine
; Purpose:    Draw a line on the Pixelmap.
; Arguments:  Arg1: Start x coordinate.
;             Arg2: start y coordinate.
;             Arg3: End x coordinate.
;             Arg4: End y coordinate.
;             Arg5: Color to use.
; Return:     Nothing.

Method PixelUEFI.DrawLine, uses xsi, x0:SDWORD, y0:SDWORD, x1:SDWORD, y1:SDWORD, dColor:DWORD
  local sdDeltaY:SDWORD, sdDeltaX:SDWORD, sdStepX:SDWORD, sdStepY:SDWORD, sdFraction:SDWORD

    DbgText "PixelUEFI.DrawLine"
  SetObject xsi

  mov eax, y1
  sub eax, y0
  mov sdDeltaY, eax

  mov eax, x1
  sub eax, x0
  mov sdDeltaX, eax

  .if sdDeltaY < 0
    xor eax, eax
    sub eax, sdDeltaY
    mov sdDeltaY, eax
    mov sdStepY, -1
  .else
    mov sdStepY, 1
  .endif
  .if sdDeltaX < 0
    xor eax, eax
    sub eax, sdDeltaX
    mov sdDeltaX, eax
    mov sdStepX, -1
  .else
    mov sdStepX, 1
  .endif

  shl sdDeltaY, 1
  shl sdDeltaX, 1

  OCall xsi.SetPixel, x0, y0, dColor

  mov eax, sdDeltaX
  .if eax > sdDeltaY
    shr eax, 1
    mov edx, sdDeltaY
    sub edx, eax
    mov sdFraction, edx

    mov eax, x0
    .while eax != x1
      .if sdFraction >= 0
        mov eax, sdStepY
        add y0, eax
        mov eax, sdDeltaX
        sub sdFraction, eax
      .endif
      mov eax, sdStepX
      add x0, eax
      mov eax, sdDeltaY
      add sdFraction, eax
      OCall xsi.SetPixel, x0, y0, dColor
      mov eax, x0
    .endw
  .else
    mov edx,sdDeltaY
    shr edx,1
    sub eax,edx
    mov sdFraction,eax

    mov eax,y0
    .while eax != y1
      .if sdFraction >= 0
        mov eax, sdStepX
        add x0, eax
        mov eax, sdDeltaY
        sub sdFraction, eax
      .endif
      mov eax, sdStepY
      add y0, eax
      mov eax, sdDeltaX
      add sdFraction, eax
      OCall xsi.SetPixel, x0, y0, dColor
      mov eax, y0
    .endw
  .endif
MethodEnd


include PixelMacros.inc
include PixelLines.inc


Method PixelUEFI.drawPixel, uses xsi, x:sdword , y:sdword , color:dword, brightness:real4

	local c1:dword, c2:dword,c3: dword
	local cc1:dword, cc2:dword,cc3: dword, cc4: dword
     
	takecolor color, cc1, cc2, cc3    
	remakecolor brightness, cc1, cc2, cc3, cc4, color

	SetObject xsi

	OCall xsi.SetPixel, x, y, color
MethodEnd 

endif 