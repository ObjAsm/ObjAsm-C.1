; ==================================================================================================
; Title:      GUID2StrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GUID2StrW
; Purpose:    Convert a GUID to a WIDE string.
; Arguments:  Arg1: -> Destination WIDE string Buffer.
;                   It must hold at least 36 characters plus a terminating zero (74 bytes).
;             Arg2: -> GUID.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
GUID2StrW proc pBuffer:POINTER, pGUID:POINTER
  push edi
  push esi
  mov edi, [esp + 12]                                   ;edi -> Buffer
  mov esi, [esp + 16]                                   ;esi -> GUID
  invoke dword2hexW, edi, [esi]                         ;Convert DWORD to hex
  mov WORD ptr [edi + 16], "-"                          ;Append "-"
  add edi, 18
  invoke dword2hexW, edi, [esi + 4]                     ;Convert next DWORD to hex
  push DWORD ptr [edi + 00]                             ;Rearrange words
  push DWORD ptr [edi + 04]
  push DWORD ptr [edi + 08]
  push DWORD ptr [edi + 12]
  pop DWORD ptr [edi + 04]
  pop DWORD ptr [edi + 00]
  pop DWORD ptr [edi + 14]
  pop DWORD ptr [edi + 10]
  mov WORD ptr [edi + 08], "-"                          ;Insert "-"
  mov WORD ptr [edi + 18], "-"                          ;Append "-"
  add edi, 20
  invoke dword2hexW, edi, [esi + 8]                     ;Convert next DWORD to hex
  push DWORD ptr [edi + 00]                             ;Rearrange bytes
  push DWORD ptr [edi + 04]
  push DWORD ptr [edi + 08]
  push DWORD ptr [edi + 12]
  pop DWORD ptr [edi + 00]
  pop DWORD ptr [edi + 04]
  pop DWORD ptr [edi + 10]
  pop DWORD ptr [edi + 14]
  mov WORD ptr [edi + 08], "-"                          ;Insert "-"
  add edi, 18
  invoke dword2hexW, edi, [esi + 12]                    ;Convert next DWORD to hex
  push DWORD ptr [edi + 00]                             ;Rearrange bytes
  push DWORD ptr [edi + 04]
  push DWORD ptr [edi + 08]
  push DWORD ptr [edi + 12]
  pop DWORD ptr [edi + 00]
  pop DWORD ptr [edi + 04]
  pop DWORD ptr [edi + 08]
  pop DWORD ptr [edi + 12]
  pop esi
  pop edi
  ret 8
GUID2StrW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
