; ==================================================================================================
; Title:      StrCCopyW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCCopyW
; Purpose:    Copy the the source WIDE string with length limitation.
;             The destination buffer should be big enough to hold the maximum number of
;             characters + 1.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Maximal number of charachters to be copied.
; Return:     eax = Number of copied characters, not including the ZTC.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrCCopyW proc pBuffer:POINTER, pSrcStringW:POINTER, dMaxChars:DWORD
  invoke StrCLengthW, [esp + 12], [esp + 12]            ;pSrcStr, dMaxChars
  shl eax, 1
  push eax
  add eax, [esp + 8]
  m2z WORD ptr [eax]                                    ;Set ZTC
  push [esp + 12]
  push [esp + 12]
  call MemShift
  ret 12
StrCCopyW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
