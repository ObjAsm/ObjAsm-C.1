; ==================================================================================================
; Title:      GUID2BStr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GUID2BStr
; Purpose:    Convert a GUID to a BStr.
; Arguments:  Arg1: -> Destination BStr Buffer. It must hold at least
;                   36 characters plus a terminating zero.
;             Arg2: -> GUID.
; Return:     Nothing.

align ALIGN_CODE
GUID2BStr proc pStr:POINTER, pGUID:POINTER
  mov DWORD ptr [rcx - 4], 72                           ;Byte size of the string
  invoke dword2hexW, rcx, DWORD ptr [rdx]               ;Convert DWORD to hex
  mov CHRW ptr [rcx + 16], "-"                          ;Append "-"
  add rcx, 18
  invoke dword2hexW, rcx, [rdx + 4]                     ;Convert next DWORD to hex
  mov eax, DWORD ptr [rcx + 00]                         ;Rearrange words
  mov r8d, DWORD ptr [rcx + 04]
  mov r9d, DWORD ptr [rcx + 08]
  mov r10d, DWORD ptr [rcx + 12]
  mov DWORD ptr [rcx + 00], r9d
  mov DWORD ptr [rcx + 04], r10d
  mov DWORD ptr [rcx + 14], r8d
  mov DWORD ptr [rcx + 10], eax
  mov CHRW ptr [rcx + 08], "-"                          ;Insert "-"
  mov CHRW ptr [rcx + 18], "-"                          ;Append "-"
  add rcx, 20
  invoke dword2hexW, rcx, [rdx + 8]                     ;Convert next DWORD to hex
  mov eax, DWORD ptr [rcx + 00]                         ;Rearrange bytes
  mov r8d, DWORD ptr [rcx + 04]
  mov r9d, DWORD ptr [rcx + 08]
  mov r10d, DWORD ptr [rcx + 12]
  mov DWORD ptr [rcx + 00], r10d
  mov DWORD ptr [rcx + 04], r9d
  mov DWORD ptr [rcx + 10], r8d
  mov DWORD ptr [rcx + 14], eax
  mov CHRW ptr [rcx + 08], "-"                          ;Insert "-"
  add rcx, 18
  invoke dword2hexW, rcx, [rdx + 12]                    ;Convert next DWORD to hex
  mov eax, DWORD ptr [rcx + 00]                         ;Rearrange bytes
  mov r8d, DWORD ptr [rcx + 04]
  mov r9d, DWORD ptr [rcx + 08]
  mov r10d, DWORD ptr [rcx + 12]
  mov DWORD ptr [rcx + 00], r10d
  mov DWORD ptr [rcx + 04], r9d
  mov DWORD ptr [rcx + 08], r8d
  mov DWORD ptr [rcx + 12], eax
  ret
GUID2BStr endp

end

