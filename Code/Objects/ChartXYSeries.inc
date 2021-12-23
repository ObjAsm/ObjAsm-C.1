; ==================================================================================================
; Title:      ChartXYSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartXYSeries objects.
; Notes:      Version 1.0.0, August 2021
; ==================================================================================================



; ==================================================================================================
;    ChartXYSeries implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSeries.Load
; Purpose:    Load buffer data from a stream object.
; Arguments:  Arg1 -> Stream object.
; Return:     Nothing.

Method ChartXYSeries.Load, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Load, pStream
  mov [xsi].dDataMaxXIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMinXIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMaxYIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMinXIndex, $32($OCall(pStream::Stream.BinRead32))
  OCall pStream::Stream.BinRead, addr [xsi].Setup, sizeof(SeriesSetupXY)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    ChartXYSeries.Scan
; Purpose:   Scan the buffers X and Y data to find the min and max values => Min & Max indices are set.
; Arguments: Arg1: First element index, starting from 0 to dCapacity - 1.
;            Arg2: Element count.
; Return:    Nothing.

Method ChartXYSeries.Scan, uses xbx xdi xsi, dFrom:DWORD, dCount:DWORD
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
; Method:     ChartXYSeries.Store
; Purpose:    Store buffer data to a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartXYSeries.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWrite32, [xsi].dDataMaxXIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMinXIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMaxYIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMinYIndex
  OCall pStream::Stream.BinWrite, addr [xsi].Setup, sizeof(SeriesSetupXY)
  
MethodEnd
