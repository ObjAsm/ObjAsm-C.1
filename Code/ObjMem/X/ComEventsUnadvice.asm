; ==================================================================================================
; Title:      ComEventsUnadvice.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Bitness neutral version.
; ==================================================================================================


% include &ObjMemPath&ObjMem.cop
% include &MacPath&Objects.inc
% include &COMPath&COM.inc
% include &IncPath&Windows\ocidl.inc

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ComEventsUnadvice
; Purpose:    Notificates the Event source that pISource will NOT recieve Events any more.
; Arguments:  Arg1: -> Previous ConnectionPoint interface.
;             Arg2: DWORD Cookie received from previous ComEventsAdvice call.
; Return:     eax = HRESULT.

align ALIGN_CODE
ComEventsUnadvice proc pICP:POINTER, dPrvCookie:DWORD
  ICall pICP::IConnectionPoint.Unadvise, dPrvCookie
  .if SUCCEEDED(eax)
    ICall pICP::IConnectionPoint.Release
  .endif
  ret
ComEventsUnadvice endp
