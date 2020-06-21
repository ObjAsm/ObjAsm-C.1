; ==================================================================================================
; Title:    h2incX_IniFileReader.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm support of h2incX IniFiles.
; Notes:    See h2incX.asm
; ==================================================================================================


IFR_OUT_OF_MEMORY       equ   180001
IFR_OUT_OF_SYM_SPACE    equ   180002
IFR_FILE_NOT_FOUND      equ   180003
IFR_SECTION_NOT_FOUND   equ   180004

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   IniFileReader
; Purpose:  Ini file reader.

Object IniFileReader, 0, Primer
  RedefineMethod  Done
  RedefineMethod  Init,         POINTER
  StaticMethod    LoadList,     PCONV_TAB_ENTRY

  DefineVariable  pMemBlock,    POINTER,  NULL
  DefineVariable  dMemSize,     DWORD,    0
ObjectEnd


if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IniFileReader.Done
; Purpose:   Finalizes the object.
; Arguments: None.
; Return:    Nothing.

Method IniFileReader.Done, uses esi
    SetObject esi
    .if [esi].pMemBlock != NULL
      invoke VirtualFree, [esi].pMemBlock, 0, MEM_RELEASE
    .endif
    ACall esi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IniFileReader.Init
; Purpose:   Initializes the object.
; Arguments: Arg1 -> Owner.
;            Arg2 -> File name string.
; Return:    eax = bytes read.

Method IniFileReader.Init, uses edi esi, pOwner:POINTER
    local hFile:HANDLE, dBytesRead:DWORD, szName[MAX_PATH]:CHRA, dFileSize:DWORD

    SetObject esi
    ACall esi.Init, pOwner
    invoke GetModuleFileNameA, NULL, addr szName, sizeof szName  ;eax = string char count, not including ZTC
    lea ecx, szName
    lea eax, [ecx + eax - 1]
    .while eax >= ecx
      .break .if (CHRA ptr [eax] == "\") || (CHRA ptr [eax] == "/") || (CHRA ptr [eax] == ":")
      dec eax
    .endw
    inc eax
    invoke StrCopyA, eax, $OfsCStrA("h2incX.ini")
    invoke CreateFile, addr szName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
    .if eax != INVALID_HANDLE_VALUE
      mov hFile, eax
      invoke GetFileSize, eax, NULL
      mov dFileSize, eax
      add eax, 1000h        ;Roundup to 4096
      and ax, 0F000h
      mov [esi].dMemSize, eax
      invoke VirtualAlloc, NULL, eax, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
      .if eax != NULL
        mov [esi].pMemBlock, eax
        invoke ReadFile, hFile, [esi].pMemBlock, dFileSize, addr dBytesRead, NULL
        mov eax, dBytesRead
        add eax, [esi].pMemBlock
        mov CHRA ptr [eax], 0           ;ZTC
      .else
        invoke printf, $OfsCStrA("Out of memory reading h2incX.ini file", LF)
        mov [esi].dErrorCode, IFR_OUT_OF_MEMORY
        xor eax, eax
      .endif
      invoke CloseHandle, hFile
    .else
      invoke printf, $OfsCStrA("File '%s' not found, using defaults!", LF), addr szName
      mov [esi].dErrorCode, IFR_FILE_NOT_FOUND
      xor eax, eax
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IniFileReader.LoadList
; Purpose:   Scans h2incX.ini for a given section.
; Arguments: Arg1 -> List.
;            Arg2 -> Section name.
;            Arg3: Flags.
; Return:    eax = TRUE if succeeded, otherwise FALSE.

Method IniFileReader.LoadList, uses ebx edi esi, pConTabEntry:PCONV_TAB_ENTRY
    local pSectionName: PSTRINGA, dStrLen:DWORD, dAttribute:DWORD

    SetObject ebx

    ;Find section
    mov ecx, pConTabEntry
    mov edx, [ecx].CONV_TAB_ENTRY.pSectionName
    mov pSectionName, edx
    mov eax, DWORD ptr [edx - sizeof DWORD]             ;Get string size
    dec eax                                             ;Calculate the length
    mov dStrLen, eax
    mov esi, [ebx].pMemBlock
    mov ebx, [ebx].dMemSize
    ReleaseObject ebx
    mov al, LF
    test ebx, ebx
    .while !ZERO?
      mov ah, al
      lodsb
      .if ax == 0A00h + "["
        mov edi, pSectionName
        mov ecx, dStrLen
        mov edx, esi
        repz cmpsb
        .if ZERO?
          lodsb
          .if al == "]"
            .repeat
              lodsb
            .until (al == LF) || (al == 0)
            .if al == LF
              jmp @SectionFound
            .endif
          .endif
        .endif
        mov esi, edx
      .endif
      dec ebx
    .endw

;Section not found
    SetObject ecx
    mov [ecx].dErrorCode, IFR_SECTION_NOT_FOUND
    ReleaseObject
    mov edi, pConTabEntry
    DbgPrintF $RGB(0,0,0), <"IniFileReader - section '%s' not found, using defaults">, [edi].CONV_TAB_ENTRY.pSectionName, eax
    mov esi, [edi].CONV_TAB_ENTRY.pDefault
    .while POINTER ptr [esi] != NULL
      mov ecx, [esi]
      OCall g_pMemPool::MemPool.AddBStrA, POINTER ptr [esi], DWORD ptr [ecx - sizeof DWORD]
      .ifBitSet [edi].CONV_TAB_ENTRY.dFlags, CF_CASE
        invoke StrLowerA, eax
      .endif
      OCall [edi].CONV_TAB_ENTRY.pList::List.Insert, eax
      add esi, sizeof POINTER
      .ifBitSet [edi].CONV_TAB_ENTRY.dFlags, CF_ATTR
        OCall g_pMemPool::MemPool.AddDword, DWORD ptr [esi]
        add esi, sizeof DWORD
      .elseIfBitSet [edi].CONV_TAB_ENTRY.dFlags, CF_EQUI
        mov ecx, [esi]
        OCall g_pMemPool::MemPool.AddBStrA, POINTER ptr [esi], DWORD ptr [ecx - sizeof DWORD]
        add esi, sizeof POINTER
      .endif
    .endw
    mov eax, TRUE
    jmp @@EOM

@SectionFound:
    ;Load strings into List
    mov edi, pConTabEntry
    DbgPrintF $RGB(0,0,0), <"IniFileReader - section '%s' found at %u">, [edi].CONV_TAB_ENTRY.pSectionName, esi
    invoke StrCompA, [edi].CONV_TAB_ENTRY.pSectionName, $OfsCStrA("Type Conversion 1")
    xor ecx, ecx
    .while TRUE
      mov al, [esi]
      .break .if (al == 0) || (al == "[")
      .if (al <= " ") || (al == ";")
        .repeat
          lodsb
        .until (al == 0) || (al == CR)
        .break .if al == 0
      .else
        mov ebx, esi
        xor ecx, ecx
        .repeat
          lodsb
          inc ecx
        .until (al == 0) || (al == CR) || (al == "=")
        mov byte ptr [esi - 1], 0
        mov edx, ebx
        push ebx
        push ecx
        mov ebx, eax                                    ;Remember last character
        OCall [edi].CONV_TAB_ENTRY.pList::List.Search, edx
        pop ecx
        pop edx
        .if eax != FALSE                                ;Duplicate found =>
          .if bl == "="                               ; if "=" found => skip second string
            .repeat
              lodsb
            .until (al == 0) || (al == CR)              ;Stop on CR! esi -> LF
          .endif
          inc esi                                       ;In any case move from LF to the next char
          .continue
        .endif
        
        OCall g_pMemPool::MemPool.AddBStrA, edx, ecx
        .if eax != NULL
          .ifBitSet [edi].CONV_TAB_ENTRY.dFlags, CF_CASE
            invoke StrLowerA, eax
          .endif
          OCall [edi].CONV_TAB_ENTRY.pList::List.Insert, eax
          .if eax != NULL
            .if bl == "="
              mov ebx, esi
              xor ecx, ecx
              .repeat
                lodsb
                inc ecx
              .until (al == 0) || (al == CR)
              mov byte ptr [esi - 1], 0
              .ifBitSet [edi].CONV_TAB_ENTRY.dFlags, CF_ATTR
                invoke dec2dwordA, ebx
                OCall g_pMemPool::MemPool.AddDword, eax
              .elseIfBitSet [edi].CONV_TAB_ENTRY.dFlags, CF_EQUI
                OCall g_pMemPool::MemPool.AddBStrA, ebx, ecx
              .endif
            .endif
            inc esi
            .continue
          .endif
        .endif
        SetObject ecx
        mov [ecx].dErrorCode, IFR_OUT_OF_SYM_SPACE
        ReleaseObject
        xor eax, eax                                    ;Return FALSE
        jmp @@EOM
      .endif
    .endw
@ExitOK:
    mov eax, TRUE
MethodEnd

endif
