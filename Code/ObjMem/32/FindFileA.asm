; ==================================================================================================
; Title:      FindFileA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc

TARGET_STR_TYPE = STR_TYPE_ANSI
TARGET_STR_AFFIX textequ <A>

ProcName textequ <FindFileA>
??SearchInDir textequ <??SearchInDirA>
FIND_FILE_PARAMS textequ <FIND_FILE_PARAMSA>

% include &ObjMemPath&ObjMemWin.cop

FIND_FILE_PARAMSA struct
  pFileName   POINTER    ?
  pRetBuffer  POINTER    ?
  pFilter     POINTER    ?
  cPreStr     CHRA       MAX_PATH DUP(?)
FIND_FILE_PARAMSA ends

% include &ObjMemPath&Common\FindFileTX.inc

end
