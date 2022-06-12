; ==================================================================================================
; Title:      StrRTrimW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRTrimW
; Purpose:    Trim blank characters from the end of a WIDE string.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrRTrimW proc pBuffer:POINTER, pSrcStringW:POINTER
  invoke StrEndW, [esp + 8]                             ;pSrcStringW
@@:
  sub eax, 2
  mov cx, [eax]
  cmp cx, ' '                                           ;Loop if space
  je @B
  cmp cx, 9                                             ;Loop if tab
  je @B
  sub eax, [esp + 8]                                    ;pSrcStringW
  add eax, 2
  push eax
  invoke MemShift, [esp + 16], [esp + 16], eax
  pop eax
  add eax, [esp + 4]
  m2z CHRW ptr [eax]                                    ;Set ZTC
  ret 8
StrRTrimW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
