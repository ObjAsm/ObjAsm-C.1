
;--- Generated .INC file by COMView
;--- typelib name=ShockwaveFlashObjectsc
;--- documentation=Shockwave Flash
;--- GUID={D27CDB6B-AE6D-11CF-96B8-444553540000}
;--- Version 1.0, LCID 0

;--- prototypes too complex for MASM may exist
;--- if such ones reside in a vtable they will be replaced by dummies
;--- search for occurances of ';+++' to have a closer look at these

;--- here dispatchonly interfaces are described
;--- whose methods/properties can be accessed thru IDispatch::Invoke only
;--- use macro dm() to call a method/property of such an interface.
;--- macro dm(), which is described in file objbase.inc,
;--- requires placing macro DEFINE_INVOKEHELPER somewhere in your source code

;--- _IShockwaveFlashEvents, Type=DISPATCH, GUID={D27CDB6D-AE6D-11CF-96B8-444553540000}

  DEFINE_DISPMETHOD  _IShockwaveFlashEvents , OnReadyStateChange, 0FFFFFD9Fh, METHOD, , VT_I4
  DEFINE_DISPMETHOD  _IShockwaveFlashEvents , OnProgress, 07A6h, METHOD, , VT_I4
  DEFINE_DISPMETHOD  _IShockwaveFlashEvents , FSCommand, 096h, METHOD, , VT_BSTR,VT_BSTR
  DEFINE_DISPMETHOD  _IShockwaveFlashEvents , FlashCall, 0C5h, METHOD, , VT_BSTR

;--- end of type library ---