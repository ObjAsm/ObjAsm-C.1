; ==================================================================================================
; Title:      StrNewW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrNewW
; Purpose:    Allocate a new copy of the source WIDE string.
;             If the pointer to the source string is NULL or points to an empty string, StrNewW
;             returns NULL and doesn't allocate any heap space. Otherwise, StrNewW makes a duplicate
;             of the source string.
;             The allocated space is Length(String) + 1 character.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     eax -> New WIDE string copy.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrNewW proc pStringW:POINTER
  mov eax, [esp + 4]                                    ;eax -> StringW
  or eax, eax                                           ;is NULL => fail
  jz @F
  invoke StrLengthW, eax
  push eax
  invoke StrAllocW, eax
  pop ecx
  or eax, eax
  jz @F                                                 ;Allocation failed
  lea ecx, [2 * ecx + 2]                                ;Include zero ending marker
  push eax
  invoke MemClone, eax, [esp + 12], ecx                 ;Copy the source string
  pop eax
@@:
  ret 4
StrNewW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
