; ==================================================================================================
; Title:      Err2StrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Err2StrA
; Purpose:    Translate a system error code to an ANSI string.
; Arguments:  Arg1: Error code.
;             Arg2: -> ANSI string buffer.
;             Arg3: Buffer size in characters, inclusive ZTC.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
Err2StrA proc dError:DWORD, pBuffer:POINTER, dMaxChars:DWORD
  mov eax, POINTER ptr [esp + 8]                        ;pBuffer
  m2z BYTE ptr [eax]
  invoke FormatMessageA, FORMAT_MESSAGE_FROM_SYSTEM, 0, \
                         DWORD ptr [esp + 20], \        ;dError
                         0, \
                         POINTER ptr [esp + 16], \      ;pBuffer
                         DWORD ptr [esp + 16], \        ;dMaxChars
                         0
  ret 12
Err2StrA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
