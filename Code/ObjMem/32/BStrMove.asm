; ==================================================================================================
; Title:      BStrMove.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrMove
; Purpose:    Move part of a BStr. The ZTC is not appended automatically.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source BStr.
;             Arg3: Character count.
; Return:     Nothing.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
BStrMove proc pDstBStr:POINTER, pSrcBStr:POINTER, dCharCount:DWORD
  mov eax, [esp + 4]                                    ;eax -> DstBStr
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov edx, [esp + 12]                                   ;edx = dCharCount
  sub eax, 4
  sub ecx, 4
  lea edx, [2*edx + 6]
  invoke MemShift, eax, ecx, edx
  ret 12
BStrMove endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
