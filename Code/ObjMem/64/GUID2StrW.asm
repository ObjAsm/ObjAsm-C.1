; ==================================================================================================
; Title:      GUID2StrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GUID2StrW
; Purpose:    Convert a GUID to a WIDE string.
; Arguments:  Arg1: -> Destination WIDE string Buffer.
;                   It must hold at least 36 characters plus a ZTC (= 74 bytes).
;             Arg2: -> GUID.
; Return:     Nothing.

align ALIGN_CODE
GUID2StrW proc uses rdi rsi pBuffer:POINTER, pGUID:POINTER
  mov rdi, rcx                                          ;rdi -> Buffer
  mov rsi, rdx                                          ;rsi -> GUID
  invoke dword2hexW, rdi, DWORD ptr [rsi]               ;Convert DWORD to hex
  mov CHRW ptr [rdi + 16], "-"                          ;Append "-"
  add edi, 18
  invoke dword2hexW, rdi, DWORD ptr [rsi + 4]           ;Convert next DWORD to hex
  mov eax, DCHRW ptr [rdi + 00]                         ;Rearrange words
  mov ecx, DCHRW ptr [rdi + 04]
  mov edx, DCHRW ptr [rdi + 08]
  mov r8d, DCHRW ptr [rdi + 12]
  mov DCHRW ptr [rdi + 00], edx
  mov DCHRW ptr [rdi + 04], r8d
  mov CHRW ptr [rdi + 08], "-"                          ;Insert "-"
  mov DCHRW ptr [rdi + 10], eax
  mov DCHRW ptr [rdi + 14], ecx
  mov CHRW ptr [rdi + 18], "-"                          ;Append "-"
  add rdi, 20
  invoke dword2hexW, rdi, DWORD ptr [rsi + 8]           ;Convert next DWORD to hex
  mov eax, DCHRW ptr [rdi + 00]                         ;Rearrange bytes
  mov ecx, DCHRW ptr [rdi + 04]
  mov edx, DCHRW ptr [rdi + 08]
  mov r8d, DCHRW ptr [rdi + 12]
  mov DCHRW ptr [rdi + 00], r8d
  mov DCHRW ptr [rdi + 04], edx
  mov CHRW ptr [rdi + 08], "-"                          ;Insert "-"
  mov DCHRW ptr [rdi + 10], ecx
  mov DCHRW ptr [rdi + 14], eax
  add rdi, 18
  invoke dword2hexW, rdi, DWORD ptr [rsi + 12]          ;Convert next DWORD to hex
  mov eax, DCHRW ptr [rdi + 00]                         ;Rearrange bytes
  mov ecx, DCHRW ptr [rdi + 04]
  mov edx, DCHRW ptr [rdi + 08]
  mov r8d, DCHRW ptr [rdi + 12]
  mov DCHRW ptr [rdi + 00], r8d
  mov DCHRW ptr [rdi + 04], edx
  mov DCHRW ptr [rdi + 08], ecx
  mov DCHRW ptr [rdi + 12], eax
  ret
GUID2StrW endp

end
