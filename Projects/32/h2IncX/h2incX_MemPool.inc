; ==================================================================================================
; Title:    h2incX_MemPool.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm support of h2incX MemPool objects.
; Notes:    See h2incX.asm
; ==================================================================================================


MPL_OUT_OF_MEMORY     equ   1
MPL_INVALID_ARGUMENT  equ   2

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   MemPool
; Purpose:  Global memory for non-organized storage, in most cases for ANSI strings or BStrA.

Object MemPool, 0, Primer
  StaticMethod    AddBStrA,     PSTRINGA, DWORD
  StaticMethod    AddDword,     DWORD
  StaticMethod    AddStr,       PSTRINGA
  StaticMethod    Alloc,        DWORD
  RedefineMethod  Done
  RedefineMethod  Init,         POINTER, DWORD, DWORD
  StaticMethod    Reset
  StaticMethod    SetMemMax,    DWORD

  DefineVariable  pMemBlock,    POINTER,  NULL
  DefineVariable  pMemFree,     POINTER,  NULL
  DefineVariable  pMemMax,      POINTER,  NULL
  DefineVariable  dIncrement,   DWORD,    0
  DefineVariable  dMemSize,     DWORD,    0
ObjectEnd

if IMPLEMENT

dShowMemPoolStatus macro
    if DEBUGGING
      DbgSaveContext
      DbgSetDestWnd "MemPool"
;      DbgClear "MemPool"
      mov ecx, [esi].pMemBlock
      mov edx, [esi].pMemFree
      sub edx, ecx
      mov eax, [esi].pMemMax
      sub eax, ecx
      invoke wsprintf, offset DebugMessage, $OfsCStrA("%u of %u"), edx, eax
      invoke DbgOutTextA, offset DebugMessage, $RGB(0,0,0), DBG_EFFECT_NEWLINE, ??DbgDstWnd
;      DbgLoadContext
    endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemPool.AddBStrA
; Purpose:   Add a BStrA into the MemPool.
; Arguments: Arg1 -> original string.
;            Arg2: String size, inclusive ZTC.
; Return:    eax -> new string in MemPool.

Method MemPool.AddBStrA, uses edi esi, pStrA:PSTRINGA, dSize:DWORD
    SetObject esi
@Retry:
    mov edi, [esi].pMemFree
    mov eax, dSize
    lea ecx, [edi + eax + sizeof DWORD]
    .if ecx > [esi].pMemMax
      mov eax, [esi].dMemSize
      add eax, [esi].dIncrement
      OCall esi.SetMemMax, eax
      test eax, eax
      jz @Retry                       ;ZERO => OK
      xor eax, eax                    ;Return NULL
      ret
    .endif
    stosd                             ;Save string length
    invoke StrECopy, edi, pStrA       ;Copy string
    inc eax
    mov [esi].pMemFree, eax
    mov eax, edi                      ;Return -> string
;    dShowMemPoolStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemPool.AddDword
; Purpose:   Add a DWORD value into the MemPool.
; Arguments: Arg1: DWORD value.
; Return:    eax -> Value in MemPool buffer.

Method MemPool.AddDword, uses edi esi, dValue:DWORD
    SetObject esi
@Retry:
    mov edi, [esi].pMemFree
    lea ecx, [edi + sizeof DWORD]
    .if ecx > [esi].pMemMax
      mov eax, [esi].dMemSize
      add eax, [esi].dIncrement
      OCall esi.SetMemMax, eax
      test eax, eax
      jz @Retry                       ;ZERO => OK
      xor eax, eax                    ;Return NULL
      ret
    .endif
    mov eax, dValue
    stosd                             ;Save string length
    mov [esi].pMemFree, edi
    mov eax, edi                      ;Return -> dValue
;    dShowMemPoolStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemPool.AddStr
; Purpose:   Add an ANSI string into the MemPool.
; Arguments: Arg1: -> String.
; Return:    eax -> Value in MemPool buffer.

Method MemPool.AddStr, uses edi esi, pStrA:PSTRINGA
    local dSize:DWORD

    SetObject esi
    invoke StrSize, pStrA
    mov dSize, eax
@Retry:
    mov edi, [esi].pMemFree
    mov eax, dSize
    lea ecx, [edi + eax]
    .if ecx > [esi].pMemMax
      mov eax, [esi].dMemSize
      add eax, [esi].dIncrement
      OCall esi.SetMemMax, eax
      test eax, eax
      jz @Retry                       ;ZERO => OK
      xor eax, eax                    ;Return NULL
      ret
    .endif

    invoke StrECopy, edi, pStrA       ;Copy string
    inc eax
    mov [esi].pMemFree, eax
    mov eax, edi                      ;Return -> string
;    dShowMemPoolStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemPool.Alloc
; Purpose:   Allocate memory block in MemPool
; Arguments: Arg1: memory block size.
; Return:    eax -> Allocated memory block or NULL if failed.

Method MemPool.Alloc, uses ebx esi, dMemSize:DWORD
    SetObject esi
    mov eax, [esi].pMemFree
    mov ebx, dMemSize
    add ebx, eax
    mov edx, [esi].pMemMax
    .if ebx > edx
      mov eax, edx
      .repeat
        add eax, [esi].dIncrement
      .until eax >= ebx
      OCall esi.SetMemMax, eax
    .endif
    mov [esi].pMemFree, ebx
;    dShowMemPoolStatus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemPool.Done
; Purpose:   Allocate memory block
; Arguments: None.
; Return:    Nothing.

Method MemPool.Done, uses esi
    SetObject esi
    OCall esi.SetMemMax, 0
    ACall esi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemPool.Init
; Purpose:   Allocate memory block.
; Arguments: Arg1: -> Owner
;            Arg2: Initial block size in bytes.
;            Arg3: Increment size in bytes.
; Return:    eax = Error code.

Method MemPool.Init, uses esi, pOwner:POINTER, dMemSize:DWORD, dIncrement:DWORD
    SetObject esi
    ACall esi.Init, pOwner
    m2m [esi].dIncrement, dIncrement, eax
    OCall esi.SetMemMax, dMemSize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemPool.Reset
; Purpose:   Resets the content of the MemPool.
; Arguments: None.
; Return:    Nothing.

Method MemPool.Reset
    SetObject ecx
    m2m [ecx].pMemFree, [ecx].pMemBlock, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    MemPool.SetMemMax
; Purpose:   Set the MemPool limit, allocating the necessary memory on the process heap.
; Arguments: Arg1: New memory size.
; Return:    eax = Error code.

Method MemPool.SetMemMax, uses esi, dNewMemMax:DWORD
    SetObject esi
    mov ecx, dNewMemMax
    .if [esi].pMemBlock == NULL
      MemAlloc ecx
      mov [esi].pMemBlock, eax
      mov [esi].pMemFree, eax
      mrm [esi].dMemSize, dNewMemMax, ecx
      add ecx, eax
      mov [esi].pMemMax, ecx
      xor eax, eax
    .else
      .if ecx == 0
        MemFree [esi].pMemBlock, MEM_SAFE_FREE
        xor eax, eax                                    ;eax = OBJ_OK
        mov [esi].pMemBlock, eax                        ;NULL
        mov [esi].pMemFree, eax                         ;NULL
        mov [esi].pMemMax, eax                          ;NULL
        mov [esi].dMemSize, eax
      .else
        mov eax, [esi].dMemSize
        .if eax < ecx
          MemReAlloc [esi].pMemBlock, ecx, HEAP_NO_SERIALIZE or HEAP_REALLOC_IN_PLACE_ONLY
          .if eax != NULL
            mov [esi].pMemBlock, eax
            mov [esi].pMemFree, eax
            mrm [esi].dMemSize, dNewMemMax, ecx
            add ecx, eax
            mov [esi].pMemMax, ecx
            xor eax, eax
          .else
            DbgWarning "MemPool.SetMemMax failed"
            mov eax, MPL_OUT_OF_MEMORY                  ;Return value
          .endif
        .else
          mov eax, MPL_INVALID_ARGUMENT                 ;Return value
        .endif
      .endif
    .endif
MethodEnd

endif
