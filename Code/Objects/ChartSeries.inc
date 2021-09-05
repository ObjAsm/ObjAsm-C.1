; ==================================================================================================
; Title:      ChartSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartSeries objects.
; Notes:      Version 1.0.0, August 2021
; ==================================================================================================


CHT_FLOAT   textequ <REAL8>
PCHT_FLOAT  typedef ptr CHT_FLOAT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  ChartSeries
; Purpose: Implement a data series for plot usage.
; Note:    - Data must be floating point numbers (REAL4 or REAL8). See CHT_FLOAT.
;          - The generic memory layout is [(x0, y0, z0), (x1, y1, z1), (x2, y2, z3), ...]

Object ChartSeries, ChartSeriesID, Array
  RedefineMethod    Done                                            ;Release allocated resources
  RedefineMethod    Init,               POINTER, DWORD              ;-> Owner, Capacity
  RedefineMethod    Load,               $ObjPtr(Stream)             ;-> Stream
  DynamicMethod     Scan,               DWORD, DWORD                ;Scan the buffer from, count 
  RedefineMethod    Store,              $ObjPtr(Stream)             ;-> Stream

  DefineVariable    dDataFrom,          DWORD,      0               ;First Data index
  DefineVariable    dDataCount,         DWORD,      0               ;Number of (x,y) points
  DefineVariable    dDataMaxXIndex,     DWORD,      -1              ;Biggest data element index
  DefineVariable    dDataMinXIndex,     DWORD,      -1              ;Smallest data element index
  DefineVariable    dDataMaxYIndex,     DWORD,      -1              ;Biggest data element index
  DefineVariable    dDataMinYIndex,     DWORD,      -1              ;Smallest data element index

  DefineVariable    dFlags,             DWORD,      0
  DefineVariable    pName,              PSTRING,    NULL            ;-> Series name
  DefineVariable    pDesc,              PSTRING,    NULL            ;-> Series description

  DefineVariable    LineColor,          COLORREF,   $RGB(000,000,000)
  DefineVariable    dLineWidth,         DWORD,      1
  DefineVariable    dLineStyle,         DWORD,      PS_SOLID
  DefineVariable    LineFillColor,      COLORREF,   $RGB(255,255,255)

  DefineVariable    MarkerBorderColor,  COLORREF,   $RGB(000,000,000)
  DefineVariable    dMarkerBorderWidth, DWORD,      1
  DefineVariable    MarkerFillColor,    COLORREF,   $RGB(255,255,255)
  DefineVariable    dMarkerSize,        DWORD,      11
  DefineVariable    dMarkerShape,       DWORD,      0

  DefineVariable    dDateStamp,         DWORD,      0
  DefineVariable    dTimeStamp,         DWORD,      0
ObjectEnd



; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;    ChartSeries implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Done
; Purpose:    Finalize the ChartSeries object.
; Arguments:  None.
; Return:     Nothing.

Method ChartSeries.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pName
  invoke StrDispose, [xsi].pDesc
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Init
; Purpose:    Initialize the ChartSeries object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Capacity in bytes.
; Return:     Nothing.

Method ChartSeries.Init, uses xsi, pOwner:POINTER, dCapacity:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, sizeof(CHT_FLOAT)
  OCall xsi.DimAppend, 2, ARR_MEM_ZERO                  ;X:0, Y:1
  OCall xsi.DimAppend, dCapacity, ARR_MEM_ZERO          ;data
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Load
; Purpose:    Load buffer data from a stream object.
; Arguments:  Arg1 -> Stream object.
; Return:     Nothing.

Method ChartSeries.Load, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi

  mov [xsi].pName, $OCall(pStream::Stream.StrRead)
  mov [xsi].pDesc, $OCall(pStream::Stream.StrRead)

  mov [xsi].dDateStamp, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dTimeStamp, $32($OCall(pStream::Stream.BinRead32))

  mov [xsi].dDataMaxXIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMinXIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMaxYIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMinXIndex, $32($OCall(pStream::Stream.BinRead32))

  ACall xsi.Load, pStream
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    ChartSeries.Scan
; Purpose:   Scan the buffers X and Y data to find the min and max values => Min & Max indices are set.
; Arguments: Arg1: First element index, starting from 0 to dCapacity - 1.
;            Arg2: Element count.
; Return:    Nothing.

Method ChartSeries.Scan, uses xbx xdi xsi, dFrom:DWORD, dCount:DWORD
  local dMaxX:DWORD, dMinX:DWORD, dMaxY:DWORD, dMinY:DWORD

  SetObject xsi
  mov edi, dCount
  .if edi != 0
    mov ebx, dFrom
    mov dMaxX, edi
    mov dMinX, edi
    mov dMaxY, edi
    mov dMinY, edi
    shl ebx, 1 + $Log2(sizeof(CHT_FLOAT))
    add xbx, [xsi].pData

    fld CHT_FLOAT ptr [xbx]                               ;Load first X data
    fld st(0)                                             ;Copy it
    fld CHT_FLOAT ptr [xbx + sizeof(CHT_FLOAT)]           ;Load first Y data
    fld st(0)                                             ;Copy it
    dec edi
    .while !ZERO?                                         ; MaxY | MinY | MaxX | MinX
      add xbx, 2*sizeof(CHT_FLOAT)
      fld CHT_FLOAT ptr [xbx]                             ;  X  | MaxY | MinY | MaxX | MinX
      fcomi st(0), st(3)                                  ;Compare with maximum
      .if !CARRY?                                         ;st(0) > st(1)
        mov dMaxX, edi
        fst st(3)                                         ;Store new max
      .endif
      fcomi st(0), st(4)                                  ;Compare with minimum
      .if CARRY?                                          ;st(0) < st(1)
        mov dMinX, edi
        fst st(4)                                         ;Store new min
      .endif
      fUnload 1                                           ; MaxY | MinY | MaxX | MinX

      fld CHT_FLOAT ptr [xbx + sizeof(CHT_FLOAT)]         ;  Y  | MaxY | MinY | MaxX | MinX
      fcomi st(0), st(1)                                  ;Compare with maximum
      .if !CARRY?                                         ;st(0) > st(1)
        mov dMaxY, edi
        fst st(1)                                         ;Store new max
      .endif
      fcomi st(0), st(2)                                  ;Compare with minimum
      .if CARRY?                                          ;st(0) < st(1)
        mov dMinX, edi
        fst st(2)                                         ;Store new min
      .endif
      fUnload 1                                           ; MaxY | MinY | MaxX | MinX

      dec edi
    .endw
    fUnload 4                                             ;Unload FPU stack

    mov edx, dCount
    mov ecx, dFrom

    mov eax, edx
    sub eax, dMaxX                                        ;Calculate index of max data X
    add eax, ecx
    mov [xsi].dDataMaxXIndex, eax
    mov eax, edx
    sub eax, dMinX                                        ;Calculate index of min data X
    add eax, ecx
    mov [xsi].dDataMinXIndex, eax

    mov eax, edx
    sub eax, dMaxY                                        ;Calculate index of max data Y
    add eax, ecx
    mov [xsi].dDataMaxYIndex, eax
    sub edx, dMinY                                        ;Calculate index of min data Y
    add edx, ecx
    mov [xsi].dDataMinYIndex, edx

  .else
    mov ecx, -1
    mov [xsi].dDataMaxXIndex, ecx
    mov [xsi].dDataMinXIndex, ecx
    mov [xsi].dDataMaxXIndex, ecx
    mov [xsi].dDataMinXIndex, ecx
  .endif

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Store
; Purpose:    Store buffer data to a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartSeries.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  OCall pStream::Stream.%StrWrite, [xsi].pName
  OCall pStream::Stream.%StrWrite, [xsi].pDesc

  OCall pStream::Stream.BinWrite32, [xsi].dDateStamp
  OCall pStream::Stream.BinWrite32, [xsi].dTimeStamp

  OCall pStream::Stream.BinWrite32, [xsi].dDataMaxXIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMinXIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMaxYIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMinYIndex

  ACall xsi.Store, pStream
MethodEnd

endif
