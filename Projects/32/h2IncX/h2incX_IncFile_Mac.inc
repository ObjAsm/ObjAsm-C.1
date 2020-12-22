; ==================================================================================================
; Title:    h2incX_IncFile_Mac.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm h2incX IncFile macros.
; Notes:    See h2incX.asm
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macros:    xxx@Stacklist
; Purpose:   Local stack list.

$Create@Stacklist macro
    push 0                                              ;Stack count
    exitm <esp>                                         ;-> Stack reference (-> Count)
endm

Destroy@Stacklist macro pStackRef
    .if pStackRef != NULL
      mov esp, pStackRef
      add esp, sizeof(DWORD)                            ;Dispose Count
    .endif
endm

Reset@Stacklist macro pStackRef
    mov esp, pStackRef                                  ;Reset stack
    mov DWORD ptr [esp], 0                              ;Reset count
endm

Add@Stacklist macro pStackRef, pItem
    push pItem                                          ;Save item
    mov ecx, pStackRef
    inc DWORD ptr [ecx]                                 ;Increment count
endm

$GetCount@Stacklist macro pStackRef
    mov eax, pStackRef
    exitm <DWORD ptr [eax]>                             ;Return count
endm

$GetItem@Stacklist macro pStackRef, dIndex
    mov eax, pStackRef
    mov ecx, dIndex
    shl ecx, 2
    sub eax, ecx
    exitm <DWORD ptr [eax - sizeof(DWORD)]>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     WritePtr
; Purpose:   StmWrite multiple "ptr".

WritePtr macro
    .while dPtrCount != 0
      OCall ebx::IncFile.StmWrite, offset szPtrSpace
      dec dPtrCount
    .endw
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IsStructure?
; Purpose:   Check if token is a structure name.
; Arguments: Arg1 -> Token to test. Must be a Var or a non volatile register.
; Return:    eax = TRUE if token is a known structure name, otherwise FALSE

IsStructure? macro pToken
    OCall g_pKnownStructs::List.Search, pToken
    .if eax == FALSE
      OCall g_pStructs::List.Search, pToken
    .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IsName?
; Purpose:   Check if token is a valid name.
; Arguments: Arg1 -> Token to test.
; Return:    eax = TRUE if valid, otherwise FALSE.

IsName? macro pToken
    mov ecx, pToken
    mov eax, TRUE
    mov cl, [ecx]
    .if (cl >= "A") && (cl <= "Z")
      jmp @F
    .elseif (cl >= "a") && (cl <= "z")
      jmp @F
    .elseif (cl == "_") || (cl == "?") || (cl == "@")
      jmp @F
    .elseif (cl == "~") && ([ebx].$Obj(IncFile).bInsideClass != FALSE)  ;C++ Class destructor
      jmp @F
    .endif
    xor eax, eax                                        ;FALSE
@@:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     BasicTypeCScan
; Purpose:   Helper macro to identifiy basic C types. It sets a variable using CTS_xxx.
; Arguments: eax -> current Token.

BasicTypeCScan macro
    mov dTypeCSpec, 0                                    ;Reset dTypeCSpec
                                                        ;Step 0
    .if $DoesStringMatchA?([eax], <unsigned>)
      BitSet dTypeCSpec, CTS_unsigned
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <signed>)
      BitSet dTypeCSpec, CTS_signed
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
@@:                                                     ;Step 1
    .if $DoesStringMatchA?([eax], <long>)
      BitSet dTypeCSpec, CTS_long
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <short>)
      BitSet dTypeCSpec, CTS_short
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
@@:                                                     ;Step 2
    .if $DoesStringMatchA?([eax], <long>)
      BitSet dTypeCSpec, CTS_long2
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
@@:                                                     ;Step 3
    .if $DoesStringMatchA?([eax], <void>)
      BitSet dTypeCSpec, CTS_void
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <char>)
      BitSet dTypeCSpec, CTS_char
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <bool>)
      BitSet dTypeCSpec, CTS_bool
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <int>)
      BitSet dTypeCSpec, CTS_int
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <float>)
      BitSet dTypeCSpec, CTS_float
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <double>)
      BitSet dTypeCSpec, CTS_double
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <__int8>)
      BitSet dTypeCSpec, CTS___int8
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <__int16>)
      BitSet dTypeCSpec, CTS___int16
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <__int32>)
      BitSet dTypeCSpec, CTS___int32
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <__int64>)
      BitSet dTypeCSpec, CTS___int64
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      jmp @F
    .endif
    .if $DoesStringMatchA?([eax], <__wchar_t>)
      BitSet dTypeCSpec, CTS___wchar_t
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
;      jmp @F
    .endif
@@:                                                     ;Exit
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IsIfLevelActive?
; Purpose:   Check if a given If-Level is active.
; Arguments: Arg1: INP_STAT variable.
; Return:    ZERO set if current if level is NOT active.

IsIfLevelActive? macro InpStat
    movzx edx, InpStat.bIfLevel
    mov cl, InpStat.bIfStructure[edx - 1]
    mov ch, [ebx].$Obj(IncFile).bIfStructure[edx - 1]
    exitm <(dl != [ebx].$Obj(IncFile).bIfLevel || cl == ch)>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IsPublicPrivateProtected?
; Purpose:   Check if token is 'private', 'public' or 'protected'.
; Arguments: Arg1 -> token.
; Return:    eax = TRUE if found, otherwise FALSE.

IsPublicPrivateProtected? macro pToken
    mov ecx, pToken
    mov eax, TRUE
    .if !$DoesStringMatchA?([ecx], <public>)
      .if !$DoesStringMatchA?([ecx], <private>)
        .if !$DoesStringMatchA?([ecx], <protected>)
          xor eax, eax
        .endif
      .endif
    .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IncIfLevel
; Purpose:   Increment '#if' level.
; Arguments: None.
; Return:    Nothing.

IncIfLevel macro
    .if [ebx].$Obj(IncFile).bIfLevel == MAX_IF_LEVEL
      OCall ebx::IncFile.ShowError, offset szNesting2Deep
    .else
      inc [ebx].$Obj(IncFile).bIfLevel
      movzx eax, [ebx].$Obj(IncFile).bIfLevel
      mov [ebx].$Obj(IncFile).bIfStructure[eax - 1], 0
      mov [ebx].$Obj(IncFile).bIfResult[eax - 1], PPR_FALSE
      mov [ebx].$Obj(IncFile).bIfHistory[eax - 1], PPR_FALSE
    .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IncElseLevel
; Purpose:   Increment '#else' level.
; Arguments: None.
; Return:    Nothing.

IncElseLevel macro
    movzx eax, [ebx].$Obj(IncFile).bIfLevel
    .if eax != 0
      inc [ebx].$Obj(IncFile).bIfStructure[eax - 1]
    .else
      OCall ebx::IncFile.ShowError, offset szElseWoIf
    .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     DecIfLevel
; Purpose:   Decrement '#if' level.
; Arguments: None.
; Return:    Nothing.

DecIfLevel macro
    .if [ebx].$Obj(IncFile).bIfLevel != 0
      dec [ebx].$Obj(IncFile).bIfLevel
    .else
      OCall ebx::IncFile.ShowError, offset szEndifWoIf
    .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     SkipPPLine
; Purpose:   Skip PP tokens until EOL.
; Arguments: None.
; Return:    Nothing.

SkipPPLine macro
    .repeat
      OCall ebx::IncFile.GetNextTokenFromPPLine
    .until eax == NULL
endm

