; ==================================================================================================
; Title:      StrRTrimA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRTrimA
; Purpose:    Trim blank characters from the end of an ANSI string.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrRTrimA proc pBuffer:POINTER, pSrcStringA:POINTER
  invoke StrEndA, [esp + 8]                             ;pSrcStringA
@@:
  dec eax
  mov cl, [eax]
  cmp cl, ' '                                           ;Loop if space
  je @B
  cmp cl, 9                                             ;Loop if tab
  je @B
  sub eax, [esp + 8]                                    ;pSrcStringA
  inc eax
  push eax
  invoke MemShift, [esp + 16], [esp + 16], eax
  pop eax
  add eax, [esp + 4]
  m2z CHRA ptr [eax]                                    ;Set ZTC
  ret 8
StrRTrimA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
