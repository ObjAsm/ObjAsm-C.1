; ==================================================================================================
; Title:      StrCNewA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

TARGET_STR_TYPE = STR_TYPE_ANSI
ProcName textequ <StrCNewA>

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  StrCNewW
; Purpose:    Allocate a new copy of the source ANSI string with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, StrCNewA
;             returns NULL and doesn't allocate any heap space. Otherwise, StrCNewA makes a
;             duplicate of the source string. The maximal size of the new string is limited to the
;             second parameter.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: Maximal character count.
; Return:     rax -> New ANSI string copy.

% include &ObjMemPath&64\StrCNewT.inc

end