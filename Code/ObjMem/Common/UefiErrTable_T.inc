; ==================================================================================================
; Title:      UefiErrTable_T.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
;               - Character independant code.
; ==================================================================================================


DOM struc
  xCode   XWORD     ?
  pString POINTER   ?
DOM ends

.const
align ALIGN_DATA
UefiErrTable \
  DOM {EFI_SUCCESS           , $OfsTStr("SUCCESS")}
  DOM {EFI_LOAD_ERROR        , $OfsTStr("LOAD_ERROR")}
  DOM {EFI_INVALID_PARAMETER , $OfsTStr("INVALID_PARAMETER")}
  DOM {EFI_UNSUPPORTED       , $OfsTStr("UNSUPPORTED")}
  DOM {EFI_BAD_BUFFER_SIZE   , $OfsTStr("BAD_BUFFER_SIZE")}
  DOM {EFI_BUFFER_TOO_SMALL  , $OfsTStr("BUFFER_TOO_SMALL")}
  DOM {EFI_NOT_READY         , $OfsTStr("NOT_READY")}
  DOM {EFI_DEVICE_ERROR      , $OfsTStr("DEVICE_ERROR")}
  DOM {EFI_WRITE_PROTECTED   , $OfsTStr("WRITE_PROTECTED")}
  DOM {EFI_OUT_OF_RESOURCES  , $OfsTStr("OUT_OF_RESOURCES")}
  DOM {EFI_VOLUME_CORRUPTED  , $OfsTStr("VOLUME_CORRUPTED")}
  DOM {EFI_VOLUME_FULL       , $OfsTStr("VOLUME_FULL")}
  DOM {EFI_NO_MEDIA          , $OfsTStr("NO_MEDIA")}
  DOM {EFI_MEDIA_CHANGED     , $OfsTStr("MEDIA_CHANGED")}
  DOM {EFI_NOT_FOUND         , $OfsTStr("NOT_FOUND")}
  DOM {EFI_ACCESS_DENIED     , $OfsTStr("ACCESS_DENIED")}
  DOM {EFI_NO_RESPONSE       , $OfsTStr("NO_RESPONSE")}
  DOM {EFI_NO_MAPPING        , $OfsTStr("NO_MAPPING")}
  DOM {EFI_TIMEOUT           , $OfsTStr("TIMEOUT")}
  DOM {EFI_NOT_STARTED       , $OfsTStr("NOT_STARTED")}
  DOM {EFI_ALREADY_STARTED   , $OfsTStr("ALREADY_STARTED")}
  DOM {EFI_ABORTED           , $OfsTStr("ABORTED")}
  DOM {EFI_ICMP_ERROR        , $OfsTStr("ICMP_ERROR")}
  DOM {EFI_TFTP_ERROR        , $OfsTStr("TFTP_ERROR")}
  DOM {EFI_PROTOCOL_ERROR    , $OfsTStr("PROTOCOL_ERROR")}
UefiErrTableCount equ ($ - UefiErrTable)/sizeof(DOM)
