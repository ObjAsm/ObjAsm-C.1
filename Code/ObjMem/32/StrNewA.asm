; ==================================================================================================
; Title:      StrNewA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrNewA
; Purpose:    Allocate a new copy of the source ANSI string.
;             If the pointer to the source string is NULL or points to an empty string, StrNewA
;             returns NULL and doesn't allocate any heap space. Otherwise, StrNewA makes a duplicate
;             of the source string.
;             The allocated space is Length(String) + 1 character.
; Arguments:  Arg1: -> Source ANSI string.
; Return:     eax -> New ANSI string copy.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrNewA proc pStringA:POINTER
  mov eax, [esp + 4]                                    ;eax -> StringA
  test eax, eax                                         ;is NULL => fail
  jz @F
  invoke StrLengthA, eax
  push eax
  invoke StrAllocA, eax
  pop ecx
  test eax, eax
  jz @F                                                 ;Allocation failed
  inc ecx                                               ;Include zero ending marker
  push eax
  invoke MemClone, eax, [esp + 12], ecx                 ;Copy the source string
  pop eax
@@:
  ret 4
StrNewA endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
