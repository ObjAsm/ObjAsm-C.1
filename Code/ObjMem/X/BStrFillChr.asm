; ==================================================================================================
; Title:      BStrFillChr.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.2, December 2020.
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrFillChr
; Purpose:    Fill a preallocated BSTR with a character.
; Arguments:  Arg1: -> String.
;             Arg2: Character.
;             Arg3: Character Count.
; Return:     Nothing

align ALIGN_CODE
BStrFillChr proc pString:POINTER, dCount:DWORD, wChar:CHRW
  invoke MemFillW, pString, dCount, wChar
  mov xax, pString
  mov ecx, dCount
  shl ecx, 1
  mov CHRW ptr [xax + xcx], 0                           ;Set ZTC
  mov [xax - 4], ecx                                    ;Set String length in bytes
  ret
BStrFillChr endp
