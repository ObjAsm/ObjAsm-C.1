; ==================================================================================================
; Title:      ChartSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartSeries objects.
; Notes:      Version 1.0.0, August 2021
;               - First release.
;               - OCall ChartSeries.ItemAt, Element(X, Y, Z), Index(0..DATACOUNT-1)
; ==================================================================================================



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
  invoke StrDispose, [xsi].pDescription
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
  ACall xsi.Load, pStream
  mov [xsi].pName, $OCall(pStream::Stream.StrRead)
  mov [xsi].pDescription, $OCall(pStream::Stream.StrRead)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Store
; Purpose:    Store buffer data to a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartSeries.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.%StrWrite, [xsi].pName
  OCall pStream::Stream.%StrWrite, [xsi].pDescription
MethodEnd
