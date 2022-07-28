; ==================================================================================================
; Title:      StrLScanA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLScanA
; Purpose:    Scan for a character from the beginning of an ANSI string. 
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: Character to search.
; Return:     eax -> Character address or NULL if not found.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrLScanA proc pStringA:POINTER, cChar:CHRA
  invoke StrLengthA, [esp + 4]                          ;pStringA
  test eax, eax                                         ;Lenght = 0 ?
  jz @@Exit                                             ;Return NULL
  mov ecx, eax                                          ;ecx (counter) = length
  mov al, [esp + 8]                                     ;Load Char
  push edi                                              ;Save edi onto stack
  mov edi, [esp + 8]                                    ;edi -> StringA
  repne scasb
  mov eax, 0                                            ;Dont't change flags!
  jne @F
  lea eax, [edi - sizeof(CHRA)]
@@:
  pop edi                                               ;Recover edi
@@Exit:
  ret 8
StrLScanA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
