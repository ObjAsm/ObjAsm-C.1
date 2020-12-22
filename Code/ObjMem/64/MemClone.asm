; ==================================================================================================
; Title:      MemClone.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMem.cop

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemClone
; Purpose:    Copies a memory block from a source to a destination buffer.
;             Source and destination must NOT overlap.
;             Destination buffer must be at least as large as number of bytes to copy, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source buffer.
;             Arg3: Number of bytes to be copied.
; Return:     eax = copied bytes.

align ALIGN_CODE
MemClone proc uses rdi rsi pDstMem:POINTER, pSrcMem:POINTER, dCount:DWORD
  mov rdi, rcx                                          ;rdi -> DstMem
  mov rsi, rdx                                          ;rsi -> SrcMem
  mov eax, r8d                                          ;eax = dCount
  mov rcx, rax
  shr rcx, 3 
  rep movsq
  mov rcx, rax
  and rcx, 4
  shr rcx, 2 
  rep movsd
  mov rcx, rax
  and rcx, 2
  shr rcx, 1 
  rep movsw
  mov rcx, rax
  and rcx, 1
  rep movsb
  ret
MemClone endp

end
