; ==================================================================================================
; Title:    h2incX_List.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm support of h2incX List objects.
; Notes:    See h2incX.asm
; ==================================================================================================


LST_OUT_OF_MEMORY   equ 124554
LST_OPEN_FILE_ERROR equ 125473

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   List
; Purpose:  Mantain a sorted list of items im the Memory pool.

Object List, 123321, SortedStrCollectionA
  RedefineMethod    Init,         POINTER, DWORD, DWORD, DWORD ;-> Owner, Count, Increment, Flags
  RedefineMethod    DestroyItem,  PSTRINGA
  StaticMethod      LoadFromFile, PSTRINGA
  StaticMethod      SaveToFile,   PSTRINGA

  DefineVariable    dFlags,       DWORD
ObjectEnd


if IMPLEMENT

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    List.DestroyItem
; Purpose:   Remove previous functionality.
; Arguments: Arg1: -> ANSI string.
; Return:    Nothing.

Method List.DestroyItem, NOFRAME, pItem:PSTRINGA
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    List.Init
; Purpose:   Initialize the List with a limit (dLimit), an increasing step (dDelta) and flags.
; Arguments: Arg1: -> Owner object.
;            Arg2: Initial capacity of the collection (#items).
;            Arg3: Growing factor of the collection (#items).
;            Arg4: Flags.
; Return:    Nothing.

Method List.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, dFlags:DWORD
    ACall Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
    SetObject ecx
    m2m [ecx].dFlags, dFlags, eax
MethodEnd
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    List.LoadFromFile
; Purpose:   Load list content from file.
; Arguments: Arg1: -> File Name.
; Return:    Nothing.

Method List.LoadFromFile, uses ebx esi, pFileName:PSTRINGA
    local hFile:HANDLE, cBuffer[1024]:CHRA, dBytesRead:DWORD, dAttr:DWORD
    local dFileSize:DWORD, dMemSize:DWORD, pMemBlock:POINTER

    SetObject edi
    invoke CreateFile, pFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
    .if eax != INVALID_HANDLE_VALUE
      mov hFile, eax
      invoke GetFileSize, eax, NULL
      add eax, 3                                        ;CR + LF + Zero
      mov dFileSize, eax
      add eax, 1000h                                    ;Roundup to 4096
      and ax, 0F000h
      mov dMemSize, eax
      invoke VirtualAlloc, NULL, eax, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
      .if eax != NULL
        mov pMemBlock, eax
        invoke ReadFile, hFile, pMemBlock, dFileSize, addr dBytesRead, NULL
        mov eax, dBytesRead
        add eax, pMemBlock
        mov WORD ptr [eax], CR + 256*LF                 ;CR + LF
        mov CHRA ptr [eax + 2], 0                       ;ZTC
      .else
        invoke printf, $OfsCStrA("Out of memory reading '%s' file", LF), pFileName
        mov [edi].dErrorCode, LST_OUT_OF_MEMORY
        xor eax, eax
        mov pMemBlock, eax
      .endif
      invoke CloseHandle, hFile

      mov ebx, pMemBlock
      .if ebx != NULL
        mov esi, ebx
        .while TRUE
          xor ecx, ecx
          .repeat
            lodsb
            inc ecx
          .until (al == CR) || (al == 0) || (al == "=")
          .break .if al == 0 || ecx == 1
          mov CHRA ptr [esi - 1], 0                     ;Set ZTC
          .if al != "="
            inc esi                                     ;Skip LF
          .endif

          .ifBitSet [edi].dFlags, CF_CASE
            push eax
            push ecx
            invoke StrLowerA, ebx
            pop ecx
            pop eax
          .endif

          .ifBitSet [edi].dFlags, CF_SNGL
            push eax
            invoke InsertStrg, edi, ebx, ecx
            pop eax
            .if al == "="                               ;Malformed input
              .repeat                                   ;Skip chars until CR or Zero
                lodsb
                inc ecx
              .until (al == CR) || (al == 0)
              .break .if al == 0
              mov CHRA ptr [esi - 1], 0                 ;Set ZTC
              inc esi                                   ;Skip LF
            .endif

          .elseIfBitSet [edi].dFlags, CF_ATTR
            push ecx
            .if al == "="
              push esi
              .repeat
                lodsb
              .until (al == CR) || (al == 0)
              .break .if al == 0
              mov CHRA ptr [esi - 1], 0                 ;Set ZTC
              inc esi                                   ;Skip LF
              pop ecx
              invoke dec2dword, ecx
            .else
              xor eax, eax                              ;Missing Attribute => assume 0
            .endif
            pop ecx
            invoke InsertAttr, edi, ebx, ecx, eax

          .elseIfBitSet [edi].dFlags, CF_EQUI
            .if al == "="
              push esi
              xor edx, edx
              .repeat
                lodsb
                inc edx
              .until (al == CR) || (al == 0)
              .break .if al == 0
              mov CHRA ptr [esi - 1], 0                 ;Set ZTC
              inc esi                                   ;Skip LF
              pop eax
            .else
              mov eax, offset szEmpty
              mov edx, 1
            .endif
            invoke InsertEqui, edi, ebx, ecx, eax, edx
          .endif

          mov ebx, esi
        .endw
      .endif
      invoke VirtualFree, pMemBlock, 0, MEM_RELEASE

    .else
      mov [edi].dErrorCode, LST_OPEN_FILE_ERROR
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    List.SaveToFile
; Purpose:   Save list content to file.
; Arguments: Arg1: -> File Name.
; Return:    Nothing.

Method List.SaveToFile, uses ebx esi, pFileName:PSTRINGA
    local hFile:HANDLE, cBuffer[1024]:CHRA, dBytesWritten:DWORD

    SetObject esi
    invoke CreateFile, pFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
    .if eax != INVALID_HANDLE_VALUE
      mov hFile, eax
      xor ebx, ebx
      .while ebx < [esi].dCount
        OCall esi.ItemAt, ebx
        mov edx, [eax - sizeof DWORD]
        .ifBitSet [esi].dFlags, CF_EQUI
          lea ecx, [eax + edx + sizeof DWORD]
          invoke sprintf, addr cBuffer, $OfsCStrA("%s=%s", CR, LF), eax, ecx
        .elseIfBitSet [esi].dFlags, CF_ATTR
          invoke sprintf, addr cBuffer, $OfsCStrA("%s=%u", CR, LF), eax, DWORD ptr [eax + edx]
        .else
          invoke sprintf, addr cBuffer, $OfsCStrA("%s", CR, LF), eax
        .endif
        lea ecx, dBytesWritten
        invoke WriteFile, hFile, addr cBuffer, eax, ecx, NULL
        inc ebx
      .endw
      invoke CloseHandle, hFile
    .endif
MethodEnd

endif
