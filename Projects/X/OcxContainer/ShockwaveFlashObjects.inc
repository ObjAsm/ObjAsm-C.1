
;--- Generated .INC file by COMView
;--- typelib name=ShockwaveFlashObjects
;--- documentation=Shockwave Flash
;--- GUID={D27CDB6B-AE6D-11CF-96B8-444553540000}
;--- Version 1.0, LCID 0

sTLBID_ShockwaveFlashObjects textequ <0D27CDB6B-AE6D-11CFh-96B8-444553540000>
_MajorVer_ShockwaveFlashObjects equ 1
_MinorVer_ShockwaveFlashObjects equ 0

COM_INTERFACE_BEG IShockwaveFlash, IDispatch, <D27CDB6C-AE6D-11CF-96B8-444553540000>
  COM_MTD_STD  get_ReadyState  , :ptr SDWORD
  COM_MTD_STD  get_TotalFrames  , :ptr SDWORD
  COM_MTD_STD  get_Playing  , :ptr BOOL
  COM_MTD_STD  put_Playing  , :BOOL
  COM_MTD_STD  get_Quality  , :ptr SDWORD
  COM_MTD_STD  put_Quality  , :SDWORD
  COM_MTD_STD  get_ScaleMode  , :ptr SDWORD
  COM_MTD_STD  put_ScaleMode  , :SDWORD
  COM_MTD_STD  get_AlignMode  , :ptr SDWORD
  COM_MTD_STD  put_AlignMode  , :SDWORD
  COM_MTD_STD  get_BackgroundColor  , :ptr SDWORD
  COM_MTD_STD  put_BackgroundColor  , :SDWORD
  COM_MTD_STD  get_Loop  , :ptr BOOL
  COM_MTD_STD  put_Loop  , :BOOL
  COM_MTD_STD  get_Movie  , :ptr BSTR
  COM_MTD_STD  put_Movie  , :BSTR
  COM_MTD_STD  get_FrameNum  , :ptr SDWORD
  COM_MTD_STD  put_FrameNum  , :SDWORD
  COM_MTD_STD  SetZoomRect  , :SDWORD,:SDWORD,:SDWORD,:SDWORD
  COM_MTD_STD  Zoom  , :SDWORD
  COM_MTD_STD  Pan  , :SDWORD,:SDWORD,:SDWORD
  COM_MTD_STD  Play  
  COM_MTD_STD  Stop  
  COM_MTD_STD  Back  
  COM_MTD_STD  Forward  
  COM_MTD_STD  Rewind  
  COM_MTD_STD  StopPlay  
  COM_MTD_STD  GotoFrame  , :SDWORD
  COM_MTD_STD  CurrentFrame  , :ptr SDWORD
  COM_MTD_STD  IsPlaying  , :ptr BOOL
  COM_MTD_STD  PercentLoaded  , :ptr SDWORD
  COM_MTD_STD  FrameLoaded  , :SDWORD,:ptr BOOL
  COM_MTD_STD  FlashVersion  , :ptr SDWORD
  COM_MTD_STD  get_WMode  , :ptr BSTR
  COM_MTD_STD  put_WMode  , :BSTR
  COM_MTD_STD  get_SAlign  , :ptr BSTR
  COM_MTD_STD  put_SAlign  , :BSTR
  COM_MTD_STD  get_Menu  , :ptr BOOL
  COM_MTD_STD  put_Menu  , :BOOL
  COM_MTD_STD  get_Base  , :ptr BSTR
  COM_MTD_STD  put_Base  , :BSTR
  COM_MTD_STD  get_Scale  , :ptr BSTR
  COM_MTD_STD  put_Scale  , :BSTR
  COM_MTD_STD  get_DeviceFont  , :ptr BOOL
  COM_MTD_STD  put_DeviceFont  , :BOOL
  COM_MTD_STD  get_EmbedMovie  , :ptr BOOL
  COM_MTD_STD  put_EmbedMovie  , :BOOL
  COM_MTD_STD  get_BGColor  , :ptr BSTR
  COM_MTD_STD  put_BGColor  , :BSTR
  COM_MTD_STD  get_Quality2  , :ptr BSTR
  COM_MTD_STD  put_Quality2  , :BSTR
  COM_MTD_STD  LoadMovie  , :SDWORD,:BSTR
  COM_MTD_STD  TGotoFrame  , :BSTR,:SDWORD
  COM_MTD_STD  TGotoLabel  , :BSTR,:BSTR
  COM_MTD_STD  TCurrentFrame  , :BSTR,:ptr SDWORD
  COM_MTD_STD  TCurrentLabel  , :BSTR,:ptr BSTR
  COM_MTD_STD  TPlay  , :BSTR
  COM_MTD_STD  TStopPlay  , :BSTR
  COM_MTD_STD  SetVariable  , :BSTR,:BSTR
  COM_MTD_STD  GetVariable  , :BSTR,:ptr BSTR
  COM_MTD_STD  TSetProperty  , :BSTR,:SDWORD,:BSTR
  COM_MTD_STD  TGetProperty  , :BSTR,:SDWORD,:ptr BSTR
  COM_MTD_STD  TCallFrame  , :BSTR,:SDWORD
  COM_MTD_STD  TCallLabel  , :BSTR,:BSTR
  COM_MTD_STD  TSetPropertyNum  , :BSTR,:SDWORD,:REAL8
  COM_MTD_STD  TGetPropertyNum  , :BSTR,:SDWORD,:ptr REAL8
  COM_MTD_STD  TGetPropertyAsNumber  , :BSTR,:SDWORD,:ptr REAL8
  COM_MTD_STD  get_SWRemote  , :ptr BSTR
  COM_MTD_STD  put_SWRemote  , :BSTR
  COM_MTD_STD  get_FlashVars  , :ptr BSTR
  COM_MTD_STD  put_FlashVars  , :BSTR
  COM_MTD_STD  get_AllowScriptAccess  , :ptr BSTR
  COM_MTD_STD  put_AllowScriptAccess  , :BSTR
  COM_MTD_STD  get_MovieData  , :ptr BSTR
  COM_MTD_STD  put_MovieData  , :BSTR
  COM_MTD_STD  get_InlineData  , :ptr LPUNKNOWN
  COM_MTD_STD  put_InlineData  , :LPUNKNOWN
  COM_MTD_STD  get_SeamlessTabbing  , :ptr BOOL
  COM_MTD_STD  put_SeamlessTabbing  , :BOOL
  COM_MTD_STD  EnforceLocalSecurity  
  COM_MTD_STD  get_Profile  , :ptr BOOL
  COM_MTD_STD  put_Profile  , :BOOL
  COM_MTD_STD  get_ProfileAddress  , :ptr BSTR
  COM_MTD_STD  put_ProfileAddress  , :BSTR
  COM_MTD_STD  get_ProfilePort  , :ptr SDWORD
  COM_MTD_STD  put_ProfilePort  , :SDWORD
  COM_MTD_STD  CallFunction  , :BSTR,:ptr BSTR
  COM_MTD_STD  SetReturnValue  , :BSTR
  COM_MTD_STD  DisableLocalSecurity  
  COM_MTD_STD  get_AllowNetworking  , :ptr BSTR
  COM_MTD_STD  put_AllowNetworking  , :BSTR
  COM_MTD_STD  get_AllowFullScreen  , :ptr BSTR
  COM_MTD_STD  put_AllowFullScreen  , :BSTR
COM_INTERFACE_END

COM_INTERFACE_BEG IFlashFactory, IUnknown, <D27CDB70-AE6D-11CF-96B8-444553540000>
COM_INTERFACE_END

COM_INTERFACE_BEG IDispatchEx, IDispatch, <A6EF9860-C720-11D0-9337-00A0C90DCAA9>
  COM_MTD_STD  GetDispID  , :BSTR,:DWORD,:ptr SDWORD
  COM_MTD_STD  RemoteInvokeEx  , :SDWORD,:DWORD,:DWORD,:ptr DISPPARAMS,:ptr VARIANT,:ptr EXCEPINFO,:ptr IServiceProvider,:DWORD,:ptr DWORD,:ptr VARIANT
  COM_MTD_STD  DeleteMemberByName  , :BSTR,:DWORD
  COM_MTD_STD  DeleteMemberByDispID  , :SDWORD
  COM_MTD_STD  GetMemberProperties  , :SDWORD,:DWORD,:ptr DWORD
  COM_MTD_STD  GetMemberName  , :SDWORD,:ptr BSTR
  COM_MTD_STD  GetNextDispID  , :DWORD,:SDWORD,:ptr SDWORD
  COM_MTD_STD  GetNameSpaceParent  , :ptr LPUNKNOWN
COM_INTERFACE_END

COM_INTERFACE_BEG IFlashObjectInterface, IDispatchEx, <D27CDB72-AE6D-11CF-96B8-444553540000>
COM_INTERFACE_END

;COM_INTERFACE_BEG IServiceProvider, IUnknown, <6D5140C1-7436-11CE-8034-00AA006009FA>
;  COM_MTD_STD  RemoteQueryService  , :ptr GUID,:ptr GUID,:ptr LPUNKNOWN
;COM_INTERFACE_END

COM_INTERFACE_BEG _IShockwaveFlashEvents, IDispatch, <D27CDB6D-AE6D-11CF-96B8-444553540000>
  COM_MTD_DSP  OnReadyStateChange  , :SDWORD
  COM_MTD_DSP  OnProgress  , :SDWORD
  COM_MTD_DSP  FSCommand  , :BSTR,:BSTR
  COM_MTD_DSP  FlashCall  , :BSTR
COM_INTERFACE_END


sCLSID_ShockwaveFlash       textequ <D27CDB6E-AE6D-11CF-96B8-444553540000>
sCLSID_FlashProp            textequ <1171A62F-05D2-11D1-83FC-00A0C9089C5A>
sCLSID_FlashObjectInterface textequ <D27CDB71-AE6D-11CF-96B8-444553540000>