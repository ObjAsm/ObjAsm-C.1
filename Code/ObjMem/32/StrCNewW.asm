; ==================================================================================================
; Title:      StrCNewW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCNewW
; Purpose:    Allocate a new copy of the source WIDE string with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, StrCNewW
;             returns NULL and doesn't allocate any heap space. Otherwise, StrCNew makes a duplicate
;             of the source string. The maximal size of the new string is limited to the second
;             parameter.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Maximal character count.
; Return:     eax -> New WIDE string copy.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrCNewW proc pStringW:POINTER, dMaxChars:DWORD
  mov eax, [esp + 4]                                    ;eax -> StringW
  or eax, eax                                           ;is NULL => fail
  jz @F
  invoke StrCLengthW, eax, [esp + 8]
  push eax
  invoke StrAllocW, eax
  pop ecx
  or eax, eax
  jz @F                                                 ;Allocation failed
  shl ecx, 1
  m2z WORD ptr [eax + ecx]                              ;Set termination zero
  push eax
  invoke MemClone, eax, [esp + 12], ecx                 ;Copy the source string
  pop eax
@@:
  ret 8
StrCNewW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
