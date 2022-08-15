; ==================================================================================================
; Title:      GUID2BStr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GUID2BStr
; Purpose:    Convert a GUID to a BStr.
; Arguments:  Arg1: -> Destination BStr Buffer. It must hold at least
;                   36 characters plus a ZTC.
;             Arg2: -> GUID.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE

GUID2BStr proc pStr:POINTER, pGUID:POINTER
  push edi
  push esi
  mov edi, [esp + 12]                                   ;pStr
  mov DWORD ptr [edi - 4], 72                           ;Byte size of the string
  mov esi, [esp + 16]                                   ;pGUID
  invoke dword2hexW, edi, [esi]                         ;Convert DWORD to hex
  mov WORD ptr [edi + 16], "-"                          ;Append "-"
  add edi, 18
  invoke dword2hexW, edi, [esi + 4]                     ;Convert next DWORD to hex
  push DWORD ptr [edi + 00]                             ;Rearrange WORDs
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
  push DWORD ptr [edi + 00]                             ;Rearrange BYTEs
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
  push DWORD ptr [edi + 00]                             ;Rearrange BYTEs
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
GUID2BStr endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
