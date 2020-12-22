
;--- Generated .INC file by COMView
;--- typelib name=Wordc
;--- documentation=Microsoft Word 9.0 Object Library
;--- GUID={00020905-0000-0000-C000-000000000046}
;--- Version 8.1, LCID 0

;--- prototypes too complex for MASM may exist
;--- if such ones reside in a vtable they will be replaced by dummies
;--- search for occurances of ';+++' to have a closer look at these

;--- here dispatchonly interfaces are described
;--- whose methods/properties can be accessed thru IDispatch::Invoke only
;--- use macro dm() to call a method/property of such an interface.
;--- macro dm(), which is described in file objbase.inc,
;--- requires placing macro DEFINE_INVOKEHELPER somewhere in your source code

;--- ApplicationEvents, Type=DISPATCH, GUID={000209F7-0000-0000-C000-000000000046}


;--- DocumentEvents, Type=DISPATCH, GUID={000209F6-0000-0000-C000-000000000046}

  DEFINE_COM_MTD_DSP  DocumentEvents , New, 04h, METHOD, 
  DEFINE_COM_MTD_DSP  DocumentEvents , Open, 05h, METHOD, 
  DEFINE_COM_MTD_DSP  DocumentEvents , Close, 06h, METHOD, 

;--- ApplicationEvents2, Type=DISPATCH, GUID={000209FE-0000-0000-C000-000000000046}

  DEFINE_COM_MTD_DSP  ApplicationEvents2 , Startup, 01h, METHOD, 
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , Quit, 02h, METHOD, 
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , DocumentChange, 03h, METHOD, 
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , DocumentOpen, 04h, METHOD, , VT_BYREF OR VT_USERDEFINED
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , DocumentBeforeClose, 06h, METHOD, , VT_BYREF OR VT_USERDEFINED,VT_BYREF OR VT_BOOL
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , DocumentBeforePrint, 07h, METHOD, , VT_BYREF OR VT_USERDEFINED,VT_BYREF OR VT_BOOL
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , DocumentBeforeSave, 08h, METHOD, , VT_BYREF OR VT_USERDEFINED,VT_BYREF OR VT_BOOL,VT_BYREF OR VT_BOOL
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , NewDocument, 09h, METHOD, , VT_BYREF OR VT_USERDEFINED
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , WindowActivate, 0Ah, METHOD, , VT_BYREF OR VT_USERDEFINED,VT_BYREF OR VT_USERDEFINED
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , WindowDeactivate, 0Bh, METHOD, , VT_BYREF OR VT_USERDEFINED,VT_BYREF OR VT_USERDEFINED
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , WindowSelectionChange, 0Ch, METHOD, , VT_BYREF OR VT_USERDEFINED
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , WindowBeforeRightClick, 0Dh, METHOD, , VT_BYREF OR VT_USERDEFINED,VT_BYREF OR VT_BOOL
  DEFINE_COM_MTD_DSP  ApplicationEvents2 , WindowBeforeDoubleClick, 0Eh, METHOD, , VT_BYREF OR VT_USERDEFINED,VT_BYREF OR VT_BOOL

;--- OCXEvents, Type=DISPATCH, GUID={000209F3-0000-0000-C000-000000000046}

  DEFINE_COM_MTD_DSP  OCXEvents , GotFocus, 0800100E0h, METHOD, 
  DEFINE_COM_MTD_DSP  OCXEvents , LostFocus, 0800100E1h, METHOD, 

;--- end of type library ---