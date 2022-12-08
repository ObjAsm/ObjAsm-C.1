; ==================================================================================================
; Title:    h2incX_IncFile_Proc.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm h2incX IncFile procs.
; Notes:    See h2incX.asm
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: BStrCompA
; Purpose:   Comparison routine for BStrA strings.
; Arguments: Arg1 -> String 1.
;            Arg2 -> String 2.
; Return:    eax: comparison result. Zero if strings are identical.

BStrCompA proc uses edi esi pBStrA:PSTRINGA, pStrA:PSTRINGA
    mov esi, pBStrA
    mov edi, pStrA
    mov ecx, [esi - sizeof DWORD]                       ;Load string size
    repz cmpsb
    mov eax, 0
    .if SIGN?
      dec eax
    .elseif !ZERO?
      inc eax
    .endif
    ret
BStrCompA endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: InsertStrg, InsertAttr, InsertEqui
; Purpose:   Add an Item to a List.
; Arguments: Arg1 -> List.
;            Arg2 -> Identifier string.
;            Arg3: additional Paramters.
; Return:    eax -> Identifier string.

InsertStrg proc pList:POINTER, pStr:PSTRINGA, dSize:DWORD
    local dInsIndex:DWORD

    OCall pList::List.Search, pStr
    .if eax == FALSE
      mov dInsIndex, ecx
      OCall g_pMemPool::MemPool.AddBStrA, pStr, dSize
      .if eax != NULL
        OCall pList::List.InsertAt, dInsIndex, eax
        ret
      .endif
      OCall ebx::IncFile.ShowError, offset szOutOfSpace
      mov g_bTerminate, TRUE
      xor eax, eax
    .else
      mov edx, ecx
      OCall pList::List.ItemAt, edx
    .endif
    ret
InsertStrg endp

InsertAttr proc pList:POINTER, pStr:PSTRINGA, dSize:DWORD, dAttr:DWORD
    local dInsIndex:DWORD

    OCall pList::List.Search, pStr
    .if eax == FALSE
      mov dInsIndex, ecx
      OCall g_pMemPool::MemPool.AddBStrA, pStr, dSize
      .if eax != NULL
        OCall pList::List.InsertAt, dInsIndex, eax
        OCall g_pMemPool::MemPool.AddDword, dAttr
        .if eax != NULL
          ret
        .endif
      .endif
      OCall ebx::IncFile.ShowError, offset szOutOfSpace
      mov g_bTerminate, TRUE
      xor eax, eax
    .else
      mov edx, ecx
      OCall pList::List.ItemAt, edx
    .endif
    ret
InsertAttr endp

InsertEqui proc pList:POINTER, pStr:PSTRINGA, dStrSize:DWORD, pStrEqui:PSTRINGA, dEquSize:DWORD
    local dInsIndex:DWORD

    OCall pList::List.Search, pStr
    .if eax == FALSE
      mov dInsIndex, ecx
      OCall g_pMemPool::MemPool.AddBStrA, pStr, dStrSize
      .if eax != NULL
        OCall pList::List.InsertAt, dInsIndex, eax
        OCall g_pMemPool::MemPool.AddBStrA, pStrEqui, dEquSize
        .if eax != NULL
          ret
        .endif
      .endif
      OCall ebx::IncFile.ShowError, offset szOutOfSpace
      mov g_bTerminate, TRUE
      xor eax, eax
    .else
      OCall pList::List.ItemAt, ecx
    .endif
    ret
InsertEqui endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: InsertDefItem
; Purpose:   Add a prototype to a list.
; Arguments: Arg1 -> Function Name.
;            Arg2: Parameter bytes.
; Return:    Nothing.

InsertDefItem proc pFuncName:PSTRINGA, dParamBytes:DWORD
    local szProto[MAX_PATH]:CHRA

    mov szProto, 0
    .ifBitSet [ebx].$Obj(IncFile).dQualifiers, PTQ_STDCALL
      invoke printf, addr szProto, $OfsCStrA("_%s@%u"), pFuncName, dParamBytes
    .elseIfBitSet [ebx].$Obj(IncFile).dQualifiers, PTQ_CDECL
      invoke printf, addr szProto, $OfsCStrA("_%s"), pFuncName
    .else
      invoke printf, addr szProto, $OfsCStrA("%s"), pFuncName
    .endif
    inc eax
    OCall g_pMemPool::MemPool.AddBStrA, addr szProto, eax
    .if eax != NULL
      OCall [ebx].$Obj(IncFile).pDefs::List.Insert, eax
      .if eax == NULL
        OCall ebx::IncFile.ShowError, offset szOutOfSpace
        mov g_bTerminate, TRUE
        xor eax, eax
      .endif
    .endif
    ret
InsertDefItem endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsLogOperator?
; Purpose:   Check if character in al/ax/eax is a logical operator (comparison & logical)
; Arguments: al/ax/eax = character(s) to test.
; Return:    eax = TRUE or FALSE.
; Note:      No other register is changed.

IsLogOperator? proc dChars:DWORD
    mov eax, dChars

    and eax, 0FFFFh
    cmp eax, "=="
    jz @IsTrue
    cmp eax, "!="
    jz @IsTrue
    cmp eax, "<="
    jz @IsTrue
    cmp eax, ">="
    jz @IsTrue
    cmp eax, "&&"
    jz @IsTrue
    cmp eax, "||"
    jz @IsTrue

    and eax, 0FFh
    cmp eax, "<"
    jz @IsTrue
    cmp eax, ">"
    jz @IsTrue
    cmp eax, "!"
    jz @IsTrue

    xor eax, eax
    ret
@IsTrue:
    mov eax, TRUE
    ret
IsLogOperator? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsNumOperator?
; Purpose:   Check if character in al/ax/eax is a numeric operator (assignment & arithmetic).
; Arguments: al/ax/eax = character(s) to test.
; Return:    eax = TRUE or FALSE.
; Note:      No other register is changed.

IsNumOperator? proc dChars:DWORD
    mov eax, dChars

    and eax, 0FFFFFFh
    cmp eax, "<<="
    jz @IsTrue
    xor eax, eax
    cmp eax, ">>="
    jz @IsTrue

    and eax, 0FFFFh
    cmp eax, ">>"
    jz @IsTrue
    cmp eax, "<<"
    jz @IsTrue
    cmp eax, "--"
    jz @IsTrue
    cmp eax, "++"
    jz @IsTrue
    cmp eax, "-="
    jz @IsTrue
    cmp eax, "+="
    jz @IsTrue
    cmp eax, "*="
    jz @IsTrue
    cmp eax, "/="
    jz @IsTrue
    cmp eax, "&="
    jz @IsTrue
    cmp eax, "%="
    jz @IsTrue
    cmp eax, "|="
    jz @IsTrue
    cmp eax, "^="
    jz @IsTrue

    and eax, 0FFh
    cmp eax, "="
    jz @IsTrue
    cmp eax, "-"
    jz @IsTrue
    cmp eax, "+"
    jz @IsTrue
    cmp eax, "*"
    jz @IsTrue
    cmp eax, "/"
    jz @IsTrue
    cmp eax, "|"
    jz @IsTrue
    cmp eax, "&"
    jz @IsTrue
    cmp eax, "%"
    jz @IsTrue
    cmp eax, "^"
    jz @IsTrue

    xor eax, eax
    ret
@IsTrue:
    mov eax, TRUE
    ret
IsNumOperator? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsReservedWord?
; Purpose:   Check if token is a reserved word.
; Arguments: Arg1 -> token to check.
; Return:    eax = FALSE if token is not reserved.

IsReservedWord? proc pToken:PTOKEN
    local szWord[128]:CHRA

    invoke StrCCopyA, addr szWord, pToken, sizeof szWord - 1
    invoke StrLowerA, addr szWord
    OCall g_pReservedWords::List.Search, eax
    ret
IsReservedWord? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsMacro?
; Purpose:   Check if token is a macro.
; Arguments: Arg1 -> token to check.
; Return:    eax = 0 if FALSE, 1 if macros was previously defined, 2 if it is a known macro.
;            ecx = Index in the range [0..Count].

IsMacro? proc pToken:PTOKEN
    OCall g_pKnownMacros::List.Search, pToken
    .if eax == FALSE
      OCall g_pMacros::List.Search, pToken
    .else
      inc eax
    .endif
    ret
IsMacro? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsEquate
; Purpose:   Check if token is an equate.
; Arguments: Arg1 -> token to check.
; Return:    eax = 0 if FALSE, 1 if macros was previously defined, 2 if it is a known equate.
;            ecx = Index in the range [0..Count].

IsEquate? proc pToken:PTOKEN
    OCall g_pKnownEquates::List.Search, pToken
    .if eax == FALSE
      OCall g_pEquates::List.Search, pToken
    .else
      inc eax
    .endif
    ret
IsEquate? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsQualifier?
; Purpose:   Check if token is a qualifier.
; Arguments: Arg1 -> token to check.
; Return:    eax = 0 if FALSE, 1 if qualifier was previously defined, 2 if it is a known qualifier.
;            ecx = Index in the range [0..Count-1].

IsQualifier? proc uses esi pToken:PTOKEN
    OCall g_pKnownQualifiers::List.Search, pToken
    .if eax == FALSE
      OCall g_pQualifiers::List.Search, pToken
    .else
      inc eax
    .endif
    ret
IsQualifier? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsString?
; Purpose:   Check if token is a string.
; Arguments: Arg1 -> token to check.
; Return:    eax = TRUE if token is a string, otherwise FALSE.

IsString? proc pToken:PTOKEN
    mov ecx, pToken
    mov al, [ecx]
    .if al == '"'
      jmp @IsTrue
    .elseif al >= "0" && al <= "9"
      inc ecx
      .while CHRA ptr [ecx] != 0
        .if CHRA ptr [ecx] == ","
          jmp @IsTrue
        .endif
        inc ecx
      .endw
    .endif
    xor eax, eax
    ret
@IsTrue:
    mov eax, TRUE
    ret
IsString? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsCObjMacro?
; Purpose:   Check the presence of "CObjMacro".
; Arguments: None.
; Return:    If present, eax -> Name of THIS, edx -> method name.
; Syntax:    (THIS)->lpVtbl-><method>(THIS,...)

IsCObjMacro? proc uses esi edi
    local InpStat:INP_STAT

    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax == NULL || CHRA ptr [eax] != "("
      jmp @Exit
    .endif
    OCall ebx::IncFile.GetNextTokenFromPPLine           ;get name of THIS
    test eax, eax
    jz @Exit
    mov esi, eax
    IsName? eax
    test eax, eax
    jz @Exit
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax == NULL || CHRA ptr [eax] != ")"
      jmp @Exit
    .endif
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax == NULL || DCHRA ptr [eax] != ">-"
      jmp @Exit
    .endif
    OCall ebx::IncFile.GetNextTokenFromPPLine
    test eax, eax
    jz @Exit
    DoesStringMatchA? [eax], <lpVtbl>
    jz @Exit
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax == NULL || DCHRA ptr [eax] != ">-"
      jmp @Exit
    .endif
    OCall ebx::IncFile.GetNextTokenFromPPLine           ;get method name
    test eax, eax
    jz @Exit
    mov edi, eax
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax == NULL || CHRA ptr [eax] != "("
      jmp @Exit
    .endif
    OCall ebx::IncFile.GetNextTokenFromPPLine
    test eax, eax
    jz @Exit
    invoke StrCompA, eax, esi  ;is THIS?
    test eax, eax
    jz @Exit
    mov eax, esi
    mov edx, edi
    ret
@Exit:
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    xor eax, eax
    ret
IsCObjMacro? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsFunction?
; Purpose:   Determine if current item is a "function" declaration.
;            Required if keyword "struct" has been found in input stream.
;            May be a struct declaration or a function returning a struct (ptr).
;            Workaround:
;              + if "*" is found before next ";" or ",", then it is a function.
;              + if "(" is found before next ";" or ",", then it is a function.
;              + if "{" is found before next ";" or ",", then it is a structure.
; Arguments: None.
; Return:    eax = TRUE if it is a function, otherwise FALSE.

IsFunction? proc
    local dReturn:DWORD
    local InpStat:INP_STAT

    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    inc [ebx].$Obj(IncFile).bSkipScanPP
    mov dReturn, FALSE
    .while TRUE
      OCall ebx::IncFile.GetNextToken
      .break .if eax == NULL
      .continue .if !IsIfLevelActive?(InpStat)
      mov cl, [eax]
      .break .if cl == ";" || cl == ")" || cl == "{"
      .if cl == "," || cl == "*" || cl == "("
        mov dReturn, TRUE
        .break
      .endif
    .endw

@Exit:
    dec [ebx].$Obj(IncFile).bSkipScanPP
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    mov eax, dReturn
    ret
IsFunction? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsFunctionPtr?
; Purpose:   Determine if it is a "function" or "function ptr" declaration.
; Arguments: None.
; Return:    eax = TRUE if present, otherwise FALSE.
; Syntax:    ...(...)(...)

IsFunctionPtr? proc
    local dParenthesesCount:DWORD, dReturn:DWORD, InpStat:INP_STAT

    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    inc [ebx].$Obj(IncFile).bSkipScanPP
    mov dParenthesesCount, 1
    mov dReturn, FALSE
    .while dParenthesesCount != 0
      OCall ebx::IncFile.GetNextToken
      .break .if eax == NULL
      .continue .if !IsIfLevelActive?(InpStat)
      .if CHRA ptr [eax] == "("
        inc dParenthesesCount
      .elseif CHRA ptr [eax] == ")"
        dec dParenthesesCount
      .endif
    .endw
    .if eax != NULL                                     ;Last Token != NULL
      OCall ebx::IncFile.GetNextToken
      .if eax != NULL && CHRA ptr [eax] == "("
        mov dReturn, TRUE
      .endif
    .else
      DbgPrintF $RGB(0,0,0), <"%u: IsFunctionPtr? - unexpected EOF">, [ebx].$Obj(IncFile).dLineNbr
    .endif

@Exit:
    dec [ebx].$Obj(IncFile).bSkipScanPP
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    mov eax, dReturn
    ret
IsFunctionPtr? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: IsUnionStructClass?
; Purpose:   Check if token is "union", "struct" or "class".
; Arguments: Arg1 -> token.
; Return:    eax = TRUE if found, otherwise FALSE.
;            edx = TRUE if token = "class".

IsUnionStructClass? proc uses esi pToken:PTOKEN
    xor edx, edx
    mov eax, TRUE
    mov ecx, pToken
    .if !$DoesStringMatchA?([ecx], <struct>)
      .if !$DoesStringMatchA?([ecx], <union>)
        .if !$DoesStringMatchA?([ecx], <class>)
          xor eax, eax
        .else
          inc edx
        .endif
      .endif
    .endif
    ret
IsUnionStructClass? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: HasVTable?
; Purpose:   Check presence of VTable.
; Arguments: None.
; Return:    eax = TRUE if present, otherwise FALSE.

HasVTable? proc
    local dReturn:DWORD, dBraceCount:DWORD
    local InpStat:INP_STAT

    DbgPrintF $RGB(0,0,0), <"%u: HasVTable? - enter">, [ebx].$Obj(IncFile).dLineNbr
    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    inc [ebx].$Obj(IncFile).bSkipScanPP
    mov dBraceCount, 1
    mov dReturn, FALSE
    .while dBraceCount != 0
      OCall ebx::IncFile.GetNextToken
      .break .if eax == NULL
      .continue .if !IsIfLevelActive?(InpStat)
      .if CHRA ptr [eax] == "{"
        inc dBraceCount
      .elseif CHRA ptr [eax] == "}"
        dec dBraceCount
      .elseif dBraceCount == 1
        .if $DoesStringMatchA?([eax], <virtual>)
          mov dReturn, TRUE
          .break
        .endif
      .endif
    .endw
    dec [ebx].$Obj(IncFile).bSkipScanPP
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    mov eax, dReturn
    ret
HasVTable? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: HasVirtualBase?
; Purpose:   Check presence of "virtual" token.
; Arguments: Arg1 -> Inherit.
; Return:    eax = TRUE if it is a function ptr, otherwise FALSE.

HasVirtualBase? proc uses esi pInherit:ptr
    mov edx, $GetCount@Stacklist(pInherit)
    xor esi, esi
    test edx, edx
    .while !ZERO?
      mov eax, $GetItem@Stacklist(pInherit, esi)
      .if $DoesStringMatchA?([eax], <virtual>)
        mov eax, TRUE
        ret
      .endif
      inc esi
      dec edx
    .endw
    xor eax, eax
    ret
HasVirtualBase? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: TranslateToken
; Purpose:   Translate tokens like "__export" or "__stdcall".
; Arguments: Arg1 -> Token.
; Return:    eax -> translated Token.
;            edx = FASLE if no translation occured.

TranslateToken proc pToken:PTOKEN
    OCall g_pConvertTokens::List.Search, pToken
    .if eax != FALSE
      OCall g_pConvertTokens::List.ItemAt, ecx
      mov edx, [eax - sizeof DWORD]
      lea eax, [eax + edx + sizeof DWORD]
    .else
      xor edx, edx
      mov eax, pToken
    .endif
    ret
TranslateToken endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: TranslateReservedWord
; Purpose:   Check if token is a reserved name, if yes, add a "_" suffix
; Arguments: Arg1: -> Token.
;            Arg2: -> Output stream. If NULL, global buffer is used.
; Return:    eax -> translated token.
;            edx: TRUE if translation occured, otherwise FALSE.

TranslateReservedWord proc uses esi pToken:PTOKEN, pOut:PTOKEN
    invoke IsReservedWord?, pToken
    .if eax != FALSE
      mov esi, pOut
      .if esi == NULL
        mov esi, offset g_szTemp
      .endif
      invoke StrECopyA, esi, pToken
      invoke StrCopyA, eax, offset szResWordSuffix
      mov eax, esi
      mov edx, TRUE
      ret
    .endif
    xor edx, edx
    mov eax, pToken
    ret
TranslateReservedWord endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: TranslateType
; Purpose:   Translate known type.
; Arguments: Arg1 -> Token.
;            Arg2: Mode: 0 for TYPES, 1 for STRUCTS.
; Return:    eax -> translated type.
;            edx = FALSE if no macht found.

TranslateType proc uses edi pToken:PTOKEN, bMode:DWORD
    OCall g_pConvertTypes1::List.Search, pToken         ;Common for TYPES & STRUCTS
    .if eax != FALSE
      OCall g_pConvertTypes1::List.ItemAt, ecx
      mov edx, [eax - sizeof DWORD]
      lea eax, [eax + edx + sizeof DWORD]
    .else
      .if bMode == 0
        mov edi, g_pConvertTypes2                       ;TYPE
      .else
        mov edi, g_pConvertTypes3                       ;STRUCT
      .endif

      OCall edi::List.Search, pToken
      .if eax != FALSE
        OCall edi::List.ItemAt, ecx
        mov edx, [eax - sizeof DWORD]
        lea eax, [eax + edx + sizeof DWORD]
      .else
        xor edx, edx
        .if bMode == 0                                  ;TYPE
          mov eax, pToken
        .else                                           ;STRUCT
          mov eax, offset szUnkType
        .endif
      .endif
    .endif
    ret
TranslateType endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: TranslateTypeQualifier
; Purpose:   Convert type qualifiers.
; Arguments: Arg1 -> Type qualifier.
; Return:    eax -> Converted type qualifier.
;            edx = FASLE if no translation occured.

TranslateTypeQualifier proc pTypeQual:PTOKEN
    OCall g_pConvertTypeQual::List.Search, pTypeQual
    .if eax != FALSE
      OCall g_pConvertTypeQual::List.ItemAt, ecx
      mov edx, [eax - sizeof DWORD]
      lea eax, [eax + edx + sizeof DWORD]               ;eax -> converted string
    .else
      xor edx, edx
      mov eax, pTypeQual
    .endif
    ret
TranslateTypeQualifier endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: TranslateNumOperator
; Purpose:   Translate operator in #define lines.
; Arguments: Arg1 -> Token.
; Return:    eax -> translated or original Token.
;            edx: TRUE if translated, otherwise FALSE.

TranslateNumOperator proc pToken:PTOKEN
    mov eax, pToken
    mov eax, [eax]

    mov edx, TRUE
    and eax, 0FFFFh
    .if eax == ">>"
      mov eax, $OfsCStrA("shr")
    .elseif (eax == "<<")
      mov eax, $OfsCStrA("shl")
    .else
      and eax, 0FFh
      .if eax == "-"
        mov eax, $OfsCStrA("-")
      .elseif eax == "+"
        mov eax, $OfsCStrA("+")
      .elseif eax == "*"
        mov eax, $OfsCStrA("*")
      .elseif eax == "/"
        mov eax, $OfsCStrA("/")
      .elseif eax == "|"
        mov eax, $OfsCStrA("or")
      .elseif eax == "&"
        mov eax, $OfsCStrA("and")
      .elseif (ax == "~")
        mov eax, $OfsCStrA("not")
      .else
        mov eax, pToken
        xor edx, edx
      .endif
    .endif
    ret
TranslateNumOperator endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: TranslateLogOperator
; Purpose:   Translate operator in #define lines.
; Arguments: Arg1 -> Token.
; Return:    eax -> translated or original Token.
;            edx: TRUE if translated, otherwise FALSE.

TranslateLogOperator proc pToken:PTOKEN
    mov eax, pToken
    mov eax, [eax]
    mov edx, TRUE

    and eax, 0FFFFh
    .if eax == "=="
      mov eax, $OfsCStrA("eq")
    .elseif (eax == "!=")
      mov eax, $OfsCStrA("ne")
    .elseif (eax == "<=")
      mov eax, $OfsCStrA("le")
    .elseif (eax == ">=")
      mov eax, $OfsCStrA("ge")
    .elseif (eax == "&&")
      mov eax, $OfsCStrA("and")
    .elseif (eax == "||")
      mov eax, $OfsCStrA("or")
    .else
      and eax, 0FFFFh
      .if eax == "<"
        mov eax, $OfsCStrA("lt")
      .elseif eax == ">"
        mov eax, $OfsCStrA("gt")
      .elseif eax == "!"
        mov eax, $OfsCStrA("not")
      .else
        mov eax, pToken
        xor edx, eax
      .endif
    .endif
    ret
TranslateLogOperator endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ConvBasicTypeC
; Purpose:   Convert a basic "C" type to an "asm" type.
; Arguments: Arg1: C type specifier (see CTS_xxx equates)
; Return:    eax -> asm type string or NULL if not found.

ConvBasicTypeC proc dTypeSpecC:DWORD
    mov ecx, offset g_ConvertBasicType
    xor eax, eax
    .while TRUE
      mov edx, [ecx].CONV_BASIC_TYPE_ENTRY.dSpec
      .break .if edx == NULL
      .if edx == dTypeSpecC
        mov eax, [ecx].CONV_BASIC_TYPE_ENTRY.pName
        ret
      .endif
      add ecx, sizeof CONV_BASIC_TYPE_ENTRY
    .endw
    ret
ConvBasicTypeC endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: DeleteSimpleBraces
; Purpose:   Delete surrounding braces.
; Arguments: None.
; Return:    Nothing.

DeleteSimpleBraces proc uses esi
    local InpStat:INP_STAT

    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax != NULL && CHRA ptr [eax] == "("
      mov esi, eax
      OCall ebx::IncFile.GetNextTokenFromPPLine
      .if eax != NULL
        .if CHRA ptr [eax] == "-"
          OCall ebx::IncFile.GetNextTokenFromPPLine
          test eax, eax
          jz @Exit
        .endif
        mov cl, [eax]
        .if cl >= "0" && cl <= "9"
          OCall ebx::IncFile.GetNextTokenFromPPLine
          .if eax != NULL && CHRA ptr [eax] == ")"
            mov BYTE ptr [esi], PCT_IGNORE
            mov BYTE ptr [eax], PCT_IGNORE
          .endif
        .endif
      .endif
    .endif
@Exit:
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    ret
DeleteSimpleBraces endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: SkipCasts
; Purpose:   Skip typecasts in preprocessor lines.
; Arguments: None.
; Return:    Nothing.

SkipCasts proc uses edi
    local pToken: PTOKEN, pCastStack:POINTER, bIsName:DWORD, InpStat:INP_STAT

    mov pCastStack, NULL
    mov bIsName, FALSE
    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    .while TRUE
      OCall ebx::IncFile.GetNextTokenFromPPLine
      .break .if eax == NULL
      mov pToken, eax

      ;Skip MACRO(type) patterns ----------------------------------------------
      .if bIsName == FALSE
        IsName? pToken
        .if eax != FALSE
          mov bIsName, TRUE
        .endif
      .endif

      mov eax, pToken
      .if CHRA ptr [eax] == "(" && bIsName != FALSE
        mov bIsName, FALSE
        .continue
      .endif

      ;Check for "(" ... <*> ")" pattern --------------------------------------
      mov eax, pToken
      .if CHRA ptr [eax] == "("
        .if pCastStack == NULL
          mov pCastStack, $Create@Stacklist()
        .else
          Reset@Stacklist pCastStack
        .endif
        Add@Stacklist pCastStack, eax                   ;Save "("
        .continue
      .endif

      .if pCastStack != NULL
        .if CHRA ptr [eax] == ")"
          mov BYTE ptr [eax], PCT_IGNORE                ;Mark ")"
          mov edi, $GetCount@Stacklist(pCastStack)
          .while edi != 0
            dec edi
            mov eax, $GetItem@Stacklist(pCastStack, edi)
            mov BYTE ptr [eax], PCT_IGNORE              ;Mark all tokens in the stack
          .endw
          Destroy@Stacklist pCastStack
          mov pCastStack, NULL
          mov bIsName, FALSE
          .continue
        .endif

        OCall g_pSimpleTypes::List.Search, pToken
        .if eax == FALSE                                ;Only Simple Types allowed betw. parenthesis
          Destroy@Stacklist pCastStack
          mov pCastStack, NULL
        .else
          Add@Stacklist pCastStack, pToken
        .endif
      .else
        IsName? pToken
        mov bIsName, eax
      .endif
    .endw
@Error:
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    Destroy@Stacklist pCastStack
    ret
SkipCasts endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: SkipSimpleBraces
; Purpose:   Skip braces of "(" <number> ")" pattern.
; Arguments: None.
; Return:    Nothing.

SkipSimpleBraces proc
    local InpStat:INP_STAT

    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    .repeat
      IsName? [ebx].$Obj(IncFile).pStmInpPos
      .if eax != FALSE
        OCall ebx::IncFile.GetNextTokenFromPPLine
        .break .if eax == NULL
      .else
        invoke DeleteSimpleBraces
      .endif
      OCall ebx::IncFile.GetNextTokenFromPPLine
    .until eax == NULL
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    ret
SkipSimpleBraces endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: SkipBraces
; Purpose:   Skip all Tokens between braces.
; Arguments: Arg1: opening brace.
;            Arg2: closing brace.
; Return:    eax -> last Token or NULL.

SkipBraces proc uses esi cOpenBrace:CHRA, cCloseBrace:CHRA
    mov esi, 1
    .repeat
      OCall ebx::IncFile.GetNextToken
      .break .if eax == NULL
      mov cl, [eax]
      .if cl == cOpenBrace
        inc esi
      .elseif cl == cCloseBrace
        dec esi
      .endif
    .until ZERO?
    ret
SkipBraces endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: GetInterfaceName
; Purpose:   Get the name of an interface.
; Arguments: Arg1: -> Source Name.
;            Arg2: -> Destination Interface.
; Return:    Nothing.

GetInterfaceName proc uses edi esi pName:PSTRINGA, pInterface:PSTRINGA
    mov esi, pName
    mov edi, pInterface
    mov cl, 0
    .repeat
      lodsb
      .if al != "_"
        inc cl
      .elseif cl != 0
        mov al, 0
      .endif
      stosb
    .until al == 0
    ret
GetInterfaceName endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: SkipName
; Purpose:   Skip name of a struct/union.
; Arguments: Arg1 -> Name.
;            Arg2: Name flags. if != 0 => skip parentheses.
; Return:    Nothing.

SkipName proc pName:PSTRINGA, dFlags:DWORD
    .if pName != NULL
      OCall ebx::IncFile.GetNextToken                   ;skip name
      mov eax, dFlags
      .if eax != 0
        OCall ebx::IncFile.PeekNextToken
        .if eax != NULL && CHRA ptr [eax] == "("
          .while TRUE
            OCall ebx::IncFile.GetNextToken
            .break .if eax == NULL
            .break .if CHRA ptr [eax] == ")"
          .endw
        .endif
      .endif
    .endif
    ret
SkipName endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: SkipAnnotations
; Purpose:   Skip all comming annotations.
; Arguments: Arg1 -> Token.
; Return:    eax -> next Token or NULL.

SkipAnnotations proc pToken:PTOKEN
    OCall g_pAnnotations::List.Search, pToken
    .if eax != FALSE
      OCall ebx::IncFile.GetNextToken
      .if eax != NULL
        .if CHRA ptr [eax] == "("
          invoke SkipBraces, "(", ")"
          OCall ebx::IncFile.GetNextToken
        .endif
        .if eax != NULL
          invoke SkipAnnotations, eax                   ;Check next Token recursively
        .endif
      .endif
    .else
      mov eax, pToken                                   ;If no annotation found, return old Token
    .endif
    ret
SkipAnnotations endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: SkipMacros
; Purpose:   Skip all comming macros.
; Arguments: Arg1 -> Token.
; Return:    eax -> next Token or NULL.

SkipMacros proc uses esi pToken:PTOKEN
    invoke IsMacro?, pToken
    .if eax != 0
      OCall ebx::IncFile.GetNextToken
      .if eax != NULL
        .if CHRA ptr [eax] == "("
          invoke SkipBraces, "(", ")"
          OCall ebx::IncFile.GetNextToken
        .endif
        .if eax != NULL
          invoke SkipMacros, eax                        ;Check next Token
        .endif
      .endif
    .else
      mov eax, pToken
    .endif
    ret
SkipMacros endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: If_ElIf
; Purpose:   Process "#if"/"#elif" lines.
; Arguments: Arg1: PP conditional type: "#if" or "#elif".
; Return:    Nothing.

If_ElIf proc uses esi bCondType:DWORD
    local Evtor:$Obj(Evaluator)
    local InpStat:INP_STAT, bIfResult:BYTE

    movzx esi, [ebx].$Obj(IncFile).bIfLevel
    mrm bIfResult, [ebx].$Obj(IncFile).bIfResult[esi - 1], al       ;Get current result
    .if bCondType == PCT_IF || (bCondType == PCT_ELIF && al != PPR_TRUE)
      OCall ebx::IncFile.SaveInputStatus, addr InpStat
      New Evtor::Evaluator
      OCall Evtor::Evaluator.Init, ebx
      OCall Evtor::Evaluator.Evaluate                               ;Evaluate conditional expression
      mov bIfResult, al
      OCall Evtor::Evaluator.Done
      OCall ebx::IncFile.LoadInputStatus, addr InpStat

      mrm [ebx].$Obj(IncFile).bIfResult[esi - 1], bIfResult, al     ;Store result
      .if bCondType == PCT_IF
        mov [ebx].$Obj(IncFile).bIfHistory[esi - 1], al             ;Store result in history stack
      .else
        mov cl, [ebx].$Obj(IncFile).bIfHistory[esi - 1]
        .if al > cl
          mov [ebx].$Obj(IncFile).bIfHistory[esi - 1], al           ;Store result in history stack
        .endif
      .endif
    .endif

    ;Write conditional sentence
    .if bCondType == PCT_IF
      OCall ebx::IncFile.StmWrite, $OfsCStrA("if ")
    .else
      OCall ebx::IncFile.StmWrite, $OfsCStrA("elseif ")
    .endif
    mov [ebx].$Obj(IncFile).bSkipUselessCode, FALSE

    .while TRUE
      OCall ebx::IncFile.GetNextTokenFromPPLine
      .break .if eax == NULL
      mov esi, eax
      .if $DoesStringMatchA?([esi], <defined>)
        OCall ebx::IncFile.StmWrite, $OfsCBStrA("Defined")
        OCall ebx::IncFile.GetNextTokenFromPPLine       ;Read "("
        .break .if eax == NULL
        mov esi, eax
        .if CHRA ptr [esi] == "("                       ;It is written defined or defiend(...)
          OCall ebx::IncFile.StmWrite, esi
          OCall ebx::IncFile.GetNextTokenFromPPLine
          .break .if eax == NULL
          OCall ebx::IncFile.StmWrite, eax
          OCall ebx::IncFile.GetNextTokenFromPPLine
          .break .if eax == NULL
          OCall ebx::IncFile.StmWrite, eax
        .else
          OCall ebx::IncFile.StmWriteChar, 28h          ;"("
          OCall ebx::IncFile.StmWrite, esi
          OCall ebx::IncFile.StmWriteChar, 29h          ;")"
        .endif
      .else
        mov dl, [esi]
        .if dl >= "0" && dl <= "9"                      ;Check if number (begins with 0..9)
          OCall ebx::IncFile.StmWrite, esi
        .else
          ;Translate operators in an "#if" expression.
          mov ecx, OpConvTabEntries
          mov eax, offset g_OpConvTab
          test ecx, ecx
          .while !ZERO?
            mov dx, DCHRA ptr [eax].OP_CONV_ENTRY.wOp
            .if [esi] == dx
              mov esi, [eax].OP_CONV_ENTRY.pSubst
              .break
            .endif
            add eax, sizeof OP_CONV_ENTRY
            dec ecx
          .endw

          OCall ebx::IncFile.StmWrite, esi
        .endif
      .endif
    .endw
    OCall ebx::IncFile.StmWriteEOL

    .if bIfResult == PPR_FALSE
      mov [ebx].$Obj(IncFile).bSkipLogiPP, TRUE                   ;Swap the PP-command dispatcher tables
      mov [ebx].$Obj(IncFile).bSkipC, TRUE
    .else
      mov [ebx].$Obj(IncFile).bSkipLogiPP, FALSE
      mov [ebx].$Obj(IncFile).bSkipC, FALSE
    .endif

    ret
If_ElIf endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: Ifdef_Ifndef
; Purpose:   Process "#ifdef"/"#ifndef" lines.
; Arguments: Arg1: PP conditional type: "#ifdef" or "#ifndef".
; Return:    Nothing.

Ifdef_Ifndef proc uses edi esi bCondType:DWORD
    local pToken:PTOKEN, bIfResult:BYTE

    movzx esi, [ebx].$Obj(IncFile).bIfLevel
    mrm bIfResult, [ebx].$Obj(IncFile).bIfResult[esi - 1], al       ;Get current result
    .if al != PPR_TRUE
      OCall ebx::IncFile.GetNextTokenFromPPLine
      test eax, eax
      jz @Error
      mov pToken, eax

      ;Check if it is a known symbol
      mov edi, offset g_EvalKnownSymbol
      .while [edi].EVAL_KNOWN_SYMBOL.pToken != NULL
        invoke StrCompA, pToken, [edi].EVAL_KNOWN_SYMBOL.pToken
        .if eax == 0
          .if bCondType == PCT_IFDEF
            .if [edi].EVAL_KNOWN_SYMBOL.wGenus == EGN_UNDEF
              mov bIfResult, PPR_FALSE
            .elseif [edi].EVAL_KNOWN_SYMBOL.wGenus == EGN_UNKNOWN
              mov bIfResult, PPR_UNKNOWN
            .else
              mov bIfResult, PPR_TRUE
            .endif
          .elseif bCondType == PCT_IFNDEF
            .if [edi].EVAL_KNOWN_SYMBOL.wGenus == EGN_UNDEF
              mov bIfResult, PPR_TRUE
            .elseif [edi].EVAL_KNOWN_SYMBOL.wGenus == EGN_UNKNOWN
              mov bIfResult, PPR_UNKNOWN
            .else
              mov bIfResult, PPR_FALSE
            .endif
          .else
            mov bIfResult, PPR_UNKNOWN
          .endif
          jmp @Found
        .endif
        add edi, sizeof EVAL_KNOWN_SYMBOL
      .endw
      mov bIfResult, PPR_UNKNOWN

@Found:
      mrm [ebx].$Obj(IncFile).bIfResult[esi - 1], bIfResult, al     ;Store result
      mov [ebx].$Obj(IncFile).bIfHistory[esi - 1], al               ;Store result in history stack

      .if bCondType == PCT_IFDEF
        OCall ebx::IncFile.StmWrite, $OfsCStrA("ifdef ")
      .else
        OCall ebx::IncFile.StmWrite, $OfsCStrA("ifndef ")
      .endif
      invoke TranslateReservedWord, pToken, NULL
      OCall ebx::IncFile.StmWrite, eax
      OCall ebx::IncFile.StmCopyRestOfPPLine
      mov [ebx].$Obj(IncFile).bSkipUselessCode, FALSE
    .else
      SkipPPLine
    .endif

    .if bIfResult == PPR_FALSE
      mov [ebx].$Obj(IncFile).bSkipLogiPP, TRUE                   ;Swap the PP-command dispatcher tables
      mov [ebx].$Obj(IncFile).bSkipC, TRUE
    .else
      mov [ebx].$Obj(IncFile).bSkipLogiPP, FALSE
      mov [ebx].$Obj(IncFile).bSkipC, FALSE
    .endif
    ret

@Error:
    OCall ebx::IncFile.ShowError, $OfsCStrA("unexpected EOL")
    OCall ebx::IncFile.StmWrite, $OfsCStrA("if 0; unexpected EOL")
    SkipPPLine
    ret
Ifdef_Ifndef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: WriteInherit
; Purpose:
; Arguments: Arg1 -> Inherit StackList.
;            Arg2 -> previous class.
; Return:    Nothing.

WriteInherit proc uses edi esi pInherit:ptr, bPreClass:BOOL
    local bVirtual:DWORD, bVbtable:DWORD, pToken:PTOKEN

    mov edi, $GetCount@Stacklist(pInherit)
    xor esi, esi
    mov bVirtual, FALSE
    mov bVbtable, FALSE
    test edi, edi
    .while !ZERO?
      mov eax, $GetItem@Stacklist(pInherit, esi)
      mov pToken, eax
      .if $DoesStringMatchA?([eax], <virtual>)
        .if bPreClass != FALSE && bVbtable == FALSE
          OCall ebx::IncFile.StmWrite, $OfsCStrA(" POINTER ?  ;'vbtable'")
          OCall ebx::IncFile.StmWriteEOL
          mov bVbtable, TRUE
        .endif
        mov bVirtual, TRUE
      .else
        IsPublicPrivateProtected? pToken
        .if eax != FALSE
          .if bPreClass != FALSE
            OCall ebx::IncFile.StmWriteF, $OfsCStrA(";%s:"), pToken
            OCall ebx::IncFile.StmWriteEOL
          .endif
        .else
          .if bVirtual != FALSE
            .if bPreClass == FALSE
              OCall ebx::IncFile.StmWriteF, $OfsCStrA(" %s <>"), pToken
              OCall ebx::IncFile.StmWriteEOL
            .endif
          .elseif (bPreClass)
            OCall ebx::IncFile.StmWriteF, $OfsCStrA(" %s <>"), pToken
            OCall ebx::IncFile.StmWriteEOL
          .endif
          mov bVirtual, FALSE
        .endif
      .endif
      inc esi
      dec edi
    .endw
    ret
WriteInherit endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: WriteStackList
; Purpose:   Writes tokens contained in a StackList to the output stream.
; Arguments: Arg1 -> StackList.
; Return:    Nothing.

WriteStackList proc uses edi esi pStackList:POINTER
    local bAddSpace:DWORD

    mov edi, $GetCount@Stacklist(pStackList)
    .if edi != 0
      xor esi, esi
      mov bAddSpace, FALSE
      .while edi != 0
        mov eax, $GetItem@Stacklist(pStackList, esi)
        inc esi
        .if CHRA ptr [eax] == "("
          mov bAddSpace, FALSE
        .else
          push eax
          mov eax, $GetCount@Stacklist(pStackList)
          .if esi >= eax
            mov bAddSpace, FALSE
          .else
            mov eax, $GetItem@Stacklist(pStackList, esi)
            .if CHRA ptr [eax] == ")" || CHRA ptr [eax] == "."
              mov bAddSpace, FALSE
            .else
              mov bAddSpace, TRUE
            .endif
          .endif
          pop eax
          invoke TranslateNumOperator, eax
        .endif
        OCall ebx::IncFile.StmWrite, eax
        .if bAddSpace != FALSE
          OCall ebx::IncFile.StmWriteChar, " "
        .endif
        dec edi
      .endw
    .else
      OCall ebx::IncFile.StmWriteChar, "0"
    .endif
    ret
WriteStackList endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: GetCallConvString
; Purpose:   Return the correct calling convention.
; Arguments: Arg1 -> CallConv qualifier (PTQ_xxx).
; Return:    eax -> CallConv string. Can not be NULL.

GetCallConvString proc dQualifiers:DWORD
    mov ecx, dQualifiers
    .ifBitSet ecx, PTQ_CDECL
      mov eax, $OfsCStrA("c")
    .elseIfBitSet ecx, PTQ_SYSCALL
      mov eax, $OfsCStrA("syscall")
    .elseIfBitSet ecx, PTQ_FASTCALL
      mov eax, $OfsCStrA("fastcall")
    .elseIfBitSet ecx, PTQ_VECTORCALL
      mov eax, $OfsCStrA("vectorcall")
    .elseIfBitSet ecx, PTQ_PASCAL
      mov eax, $OfsCStrA("pascal")
    .else
      mov eax, $OfsCStrA("WIN_STD_CALL_CONV")
    .endif
    ret
GetCallConvString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: GetProtoQualifier
; Purpose:   Check proto qualifier.
; Arguments: Arg1 -> Token.
; Return:    eax -> List item or NULL if not found.

GetProtoQualifier proc uses esi pToken:PTOKEN
    local InpStat:INP_STAT

    invoke BStrCompA, $OfsCBStrA("__declspec"), pToken
    .if eax == 0
      OCall ebx::IncFile.SaveInputStatus, addr InpStat
      OCall ebx::IncFile.GetNextToken
      .if eax != NULL && CHRA ptr [eax] == "("
        OCall ebx::IncFile.GetNextToken
        .if eax != NULL
          mov pToken, eax
          OCall ebx::IncFile.GetNextToken               ;")"
        .endif
      .else
        OCall ebx::IncFile.LoadInputStatus, addr InpStat
      .endif
    .endif

    OCall g_pKnownQualifiers::List.Search, pToken
    .if eax != FALSE
      OCall g_pKnownQualifiers::List.ItemAt, ecx
    .else
      OCall g_pQualifiers::List.Search, pToken
      .if eax != FALSE
        OCall g_pQualifiers::List.ItemAt, ecx
      .endif
    .endif

    ret
GetProtoQualifier endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: GetBlockName
; Purpose:   Find name of a struct/union, if any.
; Arguments: Arg1 -> Buffer used when the name is a macro invocation.
; Return:    eax -> Block Name or NULL.
;            edx = flags (if name is a macro).

GetBlockName proc pMacroNameBuffer:PSTRINGA
    local dBraceCount:DWORD, dFlags:DWORD
    local pName:PSTRINGA, cBuffer[1024]:CHRA
    local InpStat:INP_STAT

    DbgPrintF $RGB(0,0,0), <"%u: GetBlockName - enter">, [ebx].$Obj(IncFile).dLineNbr

    mov pName, NULL
    mov dFlags, FALSE
    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    inc [ebx].$Obj(IncFile).bSkipScanPP

    ;Skip declaration ---------------------------------------------------------
    mov dBraceCount, 1
    .while dBraceCount != 0
      OCall ebx::IncFile.GetNextToken
      .break .if eax == NULL
      .continue .if !IsIfLevelActive?(InpStat)
      .if CHRA ptr [eax] == "{"
        inc dBraceCount
      .elseif CHRA ptr [eax] == "}"
        dec dBraceCount
      .endif
    .endw

    .if eax != NULL
      OCall ebx::IncFile.GetNextToken
      .if eax != NULL && CHRA ptr [eax] != ";"          ;Statement terminator
        .if CHRA ptr [eax] == "*"
          jmp @Exit
        .endif
        mov pName, eax

        ;There may come a type qualifier or a "*" in which case there is no name
        invoke TranslateTypeQualifier, eax
        .if CHRA ptr [eax] == 0
          mov pName, NULL
          jmp @Exit
        .endif

        invoke IsMacro?, pName
        .if eax != 0
          mov dFlags, TRUE
          .if eax == 2
            OCall g_pKnownMacros::List.ItemAt, ecx
            mov edx, [eax - sizeof DWORD]
            mov ecx, [eax + edx]
            BitSet ecx, MCF_KNOWN                       ;Just in case
          .else
            xor ecx, ecx
          .endif
          push [ebx].$Obj(IncFile).pStmOutPos
          push [ebx].$Obj(IncFile).bStmOutEOL
          m2m [ebx].$Obj(IncFile).pStmOutPos, pMacroNameBuffer, eax
          invoke ParseMacroInvocation, pName, ecx, FALSE
          pop [ebx].$Obj(IncFile).bStmOutEOL
          pop [ebx].$Obj(IncFile).pStmOutPos
          m2m pName, pMacroNameBuffer, eax
        .endif

        DbgPrintF $RGB(0,0,0), <"%u: GetBlockName - end of struct '%s' found">, [ebx].$Obj(IncFile).dLineNbr, pName
      .endif
    .endif
    .if pName == NULL
      DbgPrintF $RGB(0,0,0), <"%u: GetBlockName - no name found">, [ebx].$Obj(IncFile).dLineNbr
    .endif

@Exit:
    DbgPrintF $RGB(0,0,0), <"%u: GetBlockName - exit">, [ebx].$Obj(IncFile).dLineNbr
    dec [ebx].$Obj(IncFile).bSkipScanPP
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    mov eax, pName
    mov edx, dFlags
    ret
GetBlockName endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ConvertNumber
; Purpose:   Converts number from C syntax to MASM syntax.
; Arguments: esi -> input stream.
;            edi -> output stream.
; Return:    Nothing.
; Note:      Must preserve ecx edx.

ConvertNumber proc uses ecx edx
    xor eax, eax
    mov cx, [esi]
    .if cx == "x0" || cx == "X0"
      add esi, 2
      .if CHRA ptr [esi] > "9"
        mov al, "0"
        stosb
      .endif
      mov dl, 1
    .else
      mov dl, 0
    .endif
    xor ecx, ecx
    .while TRUE
      mov al, [esi]
      ;Is alphanumeric?
      .if al != "?" && al != "@" && al != "_"
        .if al < "A" || al > "Z"
          .if al < "a" || al > "z"
            .if al < "0" || al > "9"
              ;FALSE
              .if al == "."
                or dl, 2
              .else
                .break
              .endif
            .endif
          .endif
        .endif
      .endif
      movsb
      inc ecx
    .endw
    mov dh, 0
    .if ecx > 3
      mov ax, [edi - 3]
      or ax, 2020h
      .if al == "i"
        mov ax, [edi - 2]
        .if ax == "46" || ax == "23" || eax == "61"
          lea edi, [edi - 3]
          inc dh
        .endif
      .elseif ah == "i" && CHRA ptr [edi - 1] == "8"
        lea edi, [edi - 2]
        inc dh
      .elseif ecx > 4
        mov eax, [edi - 4]
        or al, 20h
        .if eax == "821i"
          lea edi, [edi - 4]
          inc dh
        .endif
      .endif
      .if dh != 0
        mov al, [edi - 1]
        or al, 20h
        .if al == "u"
          dec edi
        .endif
        jmp @Skip
      .endif
    .endif
    .if ecx > 1
      mov al, [edi - 1]
      or al, 20h
      .if al == "l" || al == "u"
        dec edi
        .if ecx > 2
          mov ah, [edi - 1]
          or ah, 20h
          .if ah != al && ah == "u"
            dec edi
          .endif
        .endif
      .elseif al == "e"
        test dl, 2
        .if !ZERO?
          mov CHRA ptr [edi - 1], "E"
          mov al, [esi]
          .if al == "-" || al == "+"
            movsb
            .while TRUE
              mov al, [esi]
              .if al >= "A"
                or al, 20h
              .endif
              .if (((al >= "0") && (al <= "9")) || (al == "f") || (al == "l"))
                movsb
              .else
                .break
              .endif
            .endw
          .endif
        .endif
      .endif
      test dl, 2
      .if !ZERO?
        mov al, [edi - 1]
        or al,20h
        .if (al == "f") || (al == "l")
          dec edi
        .endif
      .endif
    .endif
@Skip:
    test dl, 1
    .if !ZERO?
      mov al, "h"
      stosb
    .endif
    ret
ConvertNumber endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: AddEscStr
; Purpose:   Add some chars to the output stream.
; Arguments: esi -> input stream.
;            edi -> output stream.
; Return:    Nothing.
; Note:      Must preserve ecx edx.
;            ch: bit 0 = 1: previous item is enclosed in '"'
;                bit 1 = 1: no previous char

AddEscStr proc
    push eax
    .if ch == 0
      mov al, '"'
      stosb
    .endif
    .if !(ch & 2)
      mov al, ","
      stosb
    .endif
    pop eax
    xchg al, ah
    stosw
    mov al, "h"
    stosb
    ret
AddEscStr endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: GetStringLiteral
; Purpose:   String processing.
; Arguments: esi -> input stream.
;            edi -> output stream.
; Return:    Nothing.
; Note:      Must preserve ecx edx.
;            ch: bit 0 = 1: previous item is enclosed in '"'
;                bit 1 = 1: no previous char

GetStringLiteral proc uses ecx
    mov ch, 2
    .repeat
      lodsb
      .if al == "\"
        lodsb
        .if al >= "0" && al <= "7"
          .if ch == 0
            mov al, '"'
            stosb
          .endif
          mov al, ","
          stosb
          dec esi
          mov cl, 3
          .while cl != 0
            mov al, [esi]
            .if al >= "0" && al <= "7"
              stosb
            .else
              .break
            .endif
            inc esi
            dec cl
          .endw
          .if cl != 3
            mov al, "o"
            stosb
          .endif
        .elseif al == "a"
          mov ax, szBell
          invoke AddEscStr
        .elseif al == "b"
          mov ax, szBackSp
          invoke AddEscStr
        .elseif al == "f"
          mov ax, szFF
          invoke AddEscStr
        .elseif al == "n"
          mov ax, szLF
          invoke AddEscStr
        .elseif al == "r"
          mov ax, szCR
          invoke AddEscStr
        .elseif al == "t"
          mov ax, szHTab
          invoke AddEscStr
        .elseif al == "v"
          mov ax, szVTab
          invoke AddEscStr
        .elseif al == "x"
          .if ch == 0
            mov al, '"'
            stosb
          .endif
          mov al, ","
          stosb
          mov cl, 3
          .while cl != 0
            mov al, [esi]
            or al, 20h
            .if al >= "0" && al <= "9"
              stosb
            .elseif al >= "a" && al <= "f"
              .if cl == 3
                mov CHRA ptr [edi], "0"
                inc edi
              .endif
              stosb
            .else
              .break
            .endif
            inc esi
            dec cl
          .endw
          .if cl != 3
            mov al, "h"
            stosb
          .endif
        .elseif al == '"'
          .if ch != 0
            mov al, ","
            stosb
            mov al, '"'
            stosb
          .endif
          stosb
          stosb
          mov ch, 0
          .continue
        .else
          jmp @NormalChar
        .endif
        mov ch, 1
        .continue
      .endif
@NormalChar:
      .if ch != 0
        .if al == '"'
          .break
        .else
          mov ah, al
          .if ch & 1
            mov al, ","
            stosb
          .endif
          mov al, '"'
          stosb
          mov al, ah
        .endif
      .endif
      .if al == 0
        dec esi
        mov al, '"'
      .endif
      stosb
      mov ch, 0
    .until al == '"'
    ret
GetStringLiteral endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PrintTable
; Purpose:   Output Table content.
; Arguments: Arg1 -> Table
;            Arg2 -> Format string.
; Return:    eax = Item count.

PrintTable proc uses edi esi pTable:$ObjPtr(List), pFormat:PSTRINGA
    mov esi, pTable
    .if esi != NULL
      xor edi, edi
      .while edi < [esi].$Obj(List).dCount
        OCall esi::List.ItemAt, edi
        mov edx, [eax - sizeof DWORD]
        lea ecx, [eax + edx + sizeof DWORD]
        invoke printf, pFormat, eax, ecx
        inc edi
      .endw
    .endif
    mov eax, [esi].$Obj(List).dCount
    ret
PrintTable endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PrintSummary
; Purpose:   Output summary to console.
; Arguments: Arg1: -> Current File Name.
; Return:    Nothing.

PrintSummary proc uses esi pFileName:PSTRINGA
  local dCntStruct:DWORD, dCntMacro:DWORD, dCntProto:DWORD, dCntTypedef:DWORD

  .if g_bSummary != FALSE
    invoke printf, $OfsCStr(LF,"Summary %s:", LF), pFileName

    invoke PrintTable, g_pStructs, $OfsCStrA("structure: %s", LF)
    mov dCntStruct, eax
    .if eax != 0
      invoke printf, $OfsCStr(LF)
    .endif

    invoke PrintTable, g_pMacros, $OfsCStrA("macro: %s", LF)
    mov dCntMacro, eax
    .if eax != 0
      invoke printf, $OfsCStr(LF)
    .endif

    invoke PrintTable, g_pPrototypes, $OfsCStrA("prototype: %s", LF)
    mov dCntProto, eax
    .if eax != 0
      invoke printf, $OfsCStr(LF)
    .endif

    invoke PrintTable, g_pTypedefs, $OfsCStrA("typedef: %s", LF)
    mov dCntTypedef, eax
    .if eax != 0
      invoke printf, $OfsCStr(LF)
    .endif

    .if g_bUse@DefProto != FALSE
      invoke PrintTable, g_pQualifiers, $OfsCStrA("prototype qualifier: %s [%X]", LF)
      .if eax != 0
        invoke printf, $OfsCStr(LF)
      .endif
    .endif
    invoke printf, $OfsCStr(LF)
    invoke printf, $OfsCStrA("%u structures", LF), dCntStruct
    invoke printf, $OfsCStrA("%u macros", LF), dCntMacro
    invoke printf, $OfsCStrA("%u prototypes", LF), dCntProto
    invoke printf, $OfsCStrA("%u typedefs", LF), dCntTypedef

  .endif
  ret
PrintSummary endp
