; ==================================================================================================
; Title:    h2incX_IncFile_Parse.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm h2incX IncFile parser procs.
; Notes:    See h2incX.asm
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseEqu
; Purpose:   For EQU invocation called by PPCH_Define.
; Arguments: Arg1 -> Name.
; Return:    Nothing.

ParseEqu proc uses edi esi pName:PSTRINGA
    local pToken:PTOKEN, pStmOutPos:PSTRINGA, pItems:POINTER
    local bExpression:DWORD, bAddSpace:DWORD, InpStat:INP_STAT
    local dTypeCSpec:DWORD, pType:PSTRINGA

    invoke SkipCasts
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax == NULL
      OCall ebx::IncFile.StmWrite, $OfsCStrA("<>")       ;Terminate the equ line
    .else
      ;Find out if the line is an expression ----------------------------------
      mov pToken, eax
      OCall ebx::IncFile.SaveInputStatus, addr InpStat
      mov bExpression, FALSE
      mov eax, pToken

      .while eax != NULL
        mov edi, eax
        invoke IsString?, eax
        .if eax != FALSE
          mov bExpression, FALSE
          .break
        .endif
        mov al, [edi]
        .if al >= "0" && al <= "9"
          mov bExpression, TRUE
        .elseif al != "(" && al != ")"
          ;Is Alpha?
          .if al != "?" && al != "@" && al != "_"
            .if al < "A" || al > "Z"
              .if al < "a" || al > "z"
                ;False
                invoke IsNumOperator?, DWORD ptr [edi]
                .if eax != FALSE
                  mov bExpression, TRUE
                  .break
                .endif
                invoke IsLogOperator?, DWORD ptr [edi]
                .if eax != FALSE
                  mov bExpression, TRUE
                  .break
                .endif
              .endif
            .endif
          .endif
        .endif
        OCall ebx::IncFile.GetNextTokenFromPPLine
      .endw
      OCall ebx::IncFile.LoadInputStatus, addr InpStat

      ;Write items from PP-Line to the output stream --------------------------
      .if bExpression == FALSE
        OCall ebx::IncFile.StmWriteChar, 3Ch            ;"<"
      .endif
      m2m pStmOutPos, [ebx].$Obj(IncFile).pStmOutPos, eax
      mov pItems, $Create@Stacklist()
      mov eax, pToken
      mov bAddSpace, FALSE
      .while eax != NULL
        DbgPrintF $RGB(0,0,0), <"%u: ParseEqu - item '%s' found">, [ebx].$Obj(IncFile).dLineNbr, edi

        DoesStringMatchA? [eax], <LongToHandle>
        jz @NextTokenPP                                 ;Hack => ignore this macro

        ;pToken may be a basic C type
        mov edi, eax
        .if pType == NULL
          BasicTypeCScan
          .if dTypeCSpec != 0
            invoke ConvBasicTypeC, dTypeCSpec
            .if eax == NULL                             ;If conversion failed
              mov pType, offset szUnkType
            .else
              mov pType, eax
            .endif
            Add@Stacklist pItems, pType                 ;Save item for later evaluation
            OCall ebx::IncFile.StmWrite, pType
            OCall ebx::IncFile.StmWriteChar, " "
          .endif
        .endif

        mov eax, $GetCount@Stacklist(pItems)
        .if eax != 0 && CHRA ptr [edi] != ")" && CHRA ptr [edi] != "," && bAddSpace != FALSE
          OCall ebx::IncFile.StmWriteChar, " "
        .endif
        invoke IsMacro?, edi                            ;If it is a macro, check if it has params
        .if eax != 0
          .if eax == 1
            OCall g_pMacros::List.ItemAt, ecx
          .else
            OCall g_pKnownMacros::List.ItemAt, ecx
          .endif
          mov edx, [eax - sizeof DWORD]
          mov ecx, DWORD ptr [eax + edx]
          xor eax, eax
          .ifBitSet ecx, MCF_HAS_PARAMS
            mov eax, TRUE
          .endif
        .endif
        .if CHRA ptr [edi] == "(" || eax != FALSE
          mov bAddSpace, FALSE
        .else
          mov eax, $GetCount@Stacklist(pItems)
          .if eax == 0 && (CHRA ptr [edi] == "-" || CHRA ptr [edi] == "+")
            mov bAddSpace, FALSE
          .else
            mov bAddSpace, TRUE
          .endif
        .endif
        Add@Stacklist pItems, edi                       ;Save item for later evaluation
        invoke TranslateNumOperator, edi
        .if edx == FALSE
          invoke TranslateLogOperator, eax
        .endif
        OCall ebx::IncFile.StmWrite, eax

@NextTokenPP:
        OCall ebx::IncFile.GetNextTokenFromPPLine
      .endw

      OCall ebx::IncFile.StmDeleteLastSpace
      .if bExpression == FALSE
        OCall ebx::IncFile.StmWriteChar, 3Eh            ;">"
      .endif

      ;If equate is a simple text item, then check if the value is a proto qualifier.
      ;If yes, add new equate to qualifier list.
      mov eax, pStmOutPos                                     ;1st char in 2nd member of equate
      .if g_bUse@DefProto != FALSE && CHRA ptr [eax] > "9"
        mov esi, $GetCount@Stacklist(pItems)
        xor edi, edi
        .while esi != 0
          dec esi
          mov eax, $GetItem@Stacklist(pItems, esi)
          invoke IsQualifier?, eax                      ;ecx = index into list
          .if eax != 0
            .if eax == 1
              mov edx, g_pQualifiers
            .else                                       ;eax = 2
              mov edx, g_pKnownQualifiers
            .endif
            OCall edx::List.ItemAt, ecx
            mov edx, [eax - sizeof DWORD]
            BitSet edi, [eax + edx]                     ;Get ATTR = PTQ_IMPORT...
          .endif
        .endw

        .if edi != 0
          invoke IsQualifier?, pName                    ;ecx = index into list
          .if eax == 0                                  ;g_pKnownQualifiers (eax = 2) are immutable
            invoke StrSizeA, pName
            invoke InsertAttr, g_pQualifiers, pName, eax, edi
          .elseif eax == 1
            OCall g_pQualifiers::List.ItemAt, ecx
            mov edx, [eax - sizeof DWORD]
            BitSet [eax + edx], edi                     ;Combine with prev qualifiers
          .endif
        .endif
      .endif
    .endif
    OCall ebx::IncFile.StmWriteComment
    OCall ebx::IncFile.StmWriteEOL

    Destroy@Stacklist pItems                            ;Restore stack
    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseEqu - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    Destroy@Stacklist pItems                            ;Restore stack
    ret
ParseEqu endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseExternItem
; Purpose:   Get an extern declaration.
; Arguments: Arg1 -> First Token.
; Return:    eax -> Next Token.

ParseExternItem proc uses edi pToken:PTOKEN
    local dTypeCSpec:DWORD, bFunction:DWORD, bStatic:DWORD, bConst:DWORD
    local pType:PSTRINGA, pName:PSTRINGA

    mov pType, NULL
    mov pName, NULL
    mov bStatic, FALSE
    mov bFunction, FALSE

    mov eax, pToken                                     ;Use token passed in to this proc
    .while TRUE
      .break .if eax == NULL
      invoke SkipAnnotations, pToken
      .break .if eax == NULL

      .if $DoesStringMatchA?([eax], <static>)
        mov bStatic, TRUE
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([eax], <const>)
        mov bConst, TRUE
        jmp @GetNextToken
      .endif

      invoke TranslateTypeQualifier, eax
      cmp CHRA ptr [eax], 0
      jz @GetNextToken

      .break .if CHRA ptr [eax] == "}" || CHRA ptr [eax] == ";"   ;Statement terminator

      mov pToken, eax
      invoke IsMacro?, eax
      .if eax != 0
        .if eax == 1
          OCall g_pMacros::List.ItemAt, ecx
        .else
          OCall g_pKnownMacros::List.ItemAt, ecx
        .endif
        mov edx, [eax - sizeof DWORD]
        invoke ParseMacroInvocation, pToken, DWORD ptr [eax + edx], TRUE
        .if eax != FALSE
          jmp @GetNextToken
        .endif
      .endif

      mov eax, pToken
      .if CHRA ptr [eax] == "("
        mov eax, pName
        .if eax != NULL
          DbgPrintF $RGB(0,0,0), <"%u: ParseExternItem, function %s found">, [ebx].$Obj(IncFile).dLineNbr, eax
        .else
          jmp @Error
        .endif
        mov bFunction, TRUE
        jmp @GetNextToken
      .endif

      ;pToken may be a basic C type
      mov eax, pToken
      .if pType == NULL
        BasicTypeCScan
        mov pToken, eax
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if eax == 0
            mov pType, offset szUnkType
          .else
            mov pType, eax
          .endif
          mov eax, pToken                               ;Process last gattered Token
          .continue
        .endif
      .endif

      mov eax, pToken
      .if $DoesStringMatchA?([eax], <"C">)
        jmp @GetNextToken                               ;Ignore it
      .endif

      mov eax, pToken
      .if $DoesStringMatchA?([eax], <"C++">)
        jmp @GetNextToken                               ;Ignore it
      .endif

      mov eax, pToken
      mov cl, CHRA ptr [eax]
      .if cl == "[" && pName != NULL                   ;"[]" should only come after a valid name
        .repeat                                         ;Ignore it
          OCall ebx::IncFile.GetNextToken
        .until eax == NULL || CHRA ptr [eax] == ";"
        .break
      .endif

      .if cl == "="
        .repeat
          OCall ebx::IncFile.GetNextToken
        .until eax == NULL || CHRA ptr [eax] == ";"
        .break
      .endif

      IsName? pToken
      .if eax != FALSE
        mov eax, pToken
        .if pType == NULL
          mov pType, eax
        .elseif pName == NULL
          mov pName, eax
        .else
          DbgErrorF $RGB(255,0,0), <"%s(%u): ParseExternItem - unknown Token 1 '%s'">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr, pToken
          jmp @Error
        .endif
      .else
        DbgErrorF $RGB(255,0,0), <"%s(%u): ParseExternItem - unknown Token 2 '%s'">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr, pToken
        jmp @Error
      .endif

@GetNextToken:
      OCall ebx::IncFile.GetNextToken
      mov pToken, eax
    .endw

    .if pName != NULL
      invoke TranslateReservedWord, pName, NULL
      .if bFunction != FALSE
        mov ecx, $OfsCStrA("near")
      .else
        mov ecx, pType
      .endif
      OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s:%s"), eax, ecx
      OCall ebx::IncFile.StmWriteEOL
      mov eax, pToken
    .else
      xor eax, eax
      jmp @Error
    .endif

@Exit:
    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseExternItem - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    ret
ParseExternItem endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseFurtherTypes
; Purpose:   Check out if there come some pointer definitions behind.
; Arguments: Arg1 -> Type.
;            Arg2 -> Tag.
;            Arg3 -> Token
; Return:    eax -> Next Token.

ParseFurtherTypes proc uses edi pType:PSTRINGA, pTag:PSTRINGA, pToken:PTOKEN
    local dPtrCount:DWORD, pName:PSTRINGA, cBuffer[1024]:CHRA

    mov dPtrCount, 0
    mov pName, NULL
    .while TRUE
      mov eax, pToken
      .if CHRA ptr [eax] == "," || CHRA ptr [eax] == ";"    ;Statement terminator
        .if pName != NULL
          push eax
          mov edi, pType
          .if edi == NULL
            mov edi, pTag
          .endif
          DbgPrintF $RGB(0,0,0), <"%u: ParseFurtherTypes - '%s %s'">, [ebx].$Obj(IncFile).dLineNbr, pName, edi
          ;Comment out forward declarations
          .if dPtrCount == 0
            invoke StrCompA, pName, edi
            .if eax == 0
              OCall ebx::IncFile.StmWriteChar, ";"
            .endif
          .endif
          invoke TranslateReservedWord, pName, NULL
          mov pName, eax
          .if dPtrCount == 0
            IsStructure? edi                              ;If the type is a structure, 
            .if eax != FALSE                              ;  then the new type is it too
              IsStructure? pName                          ;Check if it already exist
              .if eax == FALSE
                invoke StrSizeA, pName
                invoke InsertStrg, g_pStructs, pName, eax
              .endif
            .endif
          .endif

          OCall ebx::IncFile.StmWrite, pName
          OCall ebx::IncFile.StmWrite, $OfsCStrA(" typedef ")
          WritePtr
          OCall ebx::IncFile.StmWrite, edi
          OCall ebx::IncFile.StmWriteEOL
          pop eax
        .endif
        .break .if CHRA ptr [eax] == ";"                ;Statement terminator
        mov pName, NULL
        mov dPtrCount, 0
      .elseif CHRA ptr [eax] == "*"
        inc dPtrCount
      .else
        invoke TranslateTypeQualifier, pToken
        .if CHRA ptr [eax] != 0
          mov pName, eax
        .endif
      .endif
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      mov pToken, eax
    .endw
    .if pName != NULL
      OCall ebx::IncFile.StmWriteEOL
    .endif

    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseFurtherTypes - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    ret
ParseFurtherTypes endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedefFunction
; Purpose:   typedef function occured.
; Arguments: Arg1 -> Name.
;            Arg2: Accept Body flag.
;            Arg3 -> Parent
; Return:    Nothing.
; Syntax:    typedef <qualifiers> returntype name(<parameters>)<{...}>;
;            or in a class definition:
;            <qualifiers> returntype name(<parameters>)<{...}>;

ParseTypedefFunction proc pName:PSTRINGA, bAcceptBody:DWORD, pParent:PSTRINGA
    local pToken:PTOKEN
    local dNum:DWORD, dCallConv:DWORD, dPtrCount:DWORD, bFirstParam:DWORD
    local dTypeCSpec:DWORD, pType:PSTRINGA
    local szFuncName[32]:CHRA, szType[512]:CHRA, szDecoName[1024]:CHRA

    ;Parse function header ----------------------------------------------------
    mov bFirstParam, FALSE
    invoke TranslateReservedWord, pName, NULL
    mov pName, eax
    .if [ebx].$Obj(IncFile).bInsideClass != FALSE
      mov dNum, 0
      mov eax, pName
      .if CHRA ptr [eax] == "~"
        inc eax
        inc dNum
      .endif
      invoke StrCompA, eax, pParent
      .if eax == 0
        invoke sprintf, addr szFuncName, $OfsCStrA("?%u"), dNum
        lea eax, szFuncName
        mov pName, eax
      .endif
      mov dCallConv, "A"          ;A = cdecl, G = stdcall
      invoke sprintf, addr szDecoName, $OfsCStrA("?%s@%s@@Q%c___Z"), pName, pParent, dCallConv
      OCall ebx::IncFile.StmWriteF, $OfsCStrA(";externdef syscall %s:near"), addr szDecoName
      OCall ebx::IncFile.StmWriteEOL
      OCall ebx::IncFile.StmWriteF, $OfsCStrA(";%s proto :ptr %s "), addr szDecoName, pParent
      mov bFirstParam, TRUE
    .else
      OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s typedef proto "), pName
    .endif

    ;Parse function parameters ------------------------------------------------
    mov pType, NULL
    mov dPtrCount, 0
    .while TRUE
      OCall ebx::IncFile.GetNextToken
@ProcessToken:
      test eax, eax
      jz @Error

      invoke SkipAnnotations, eax
      test eax, eax
      jz @Error

      .if CHRA ptr [eax] == "*"
        inc dPtrCount
        .continue
      .endif

      .continue .if $DoesStringMatchA?([eax], <struct>) ;Ignore 'struct'
      .continue .if $DoesStringMatchA?([eax], <union>)  ;Ignore 'union'
      .continue .if $DoesStringMatchA?([eax], <enum>)   ;Ignore 'enum'

      ;pToken may be a basic C type
      mov pToken, eax
      .if pType == NULL
        BasicTypeCScan
        mov pToken, eax
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if eax == NULL                               ;If conversion failed
            mov pType, offset szUnkType
          .else
            mov pType, eax
            mov eax, pToken
            jmp @ProcessToken
            .continue
          .endif
        .endif
      .endif
      mov pToken, eax
      .if CHRA ptr [eax] == "," || CHRA ptr [eax] == ")"  ;End of function parameter list
        push eax
        .if dPtrCount != 0 || pType != NULL
          .if pType != NULL
            invoke TranslateReservedWord, pType, NULL   ;Maybe it is a reserved word!
            mov pType, eax
          .endif
          mov eax, pType

          .if dPtrCount != 0 || CHRA ptr [eax] != 0
            .if bFirstParam != FALSE
              OCall ebx::IncFile.StmWrite, $OfsCStrA(", ")
              mov bFirstParam, FALSE
            .endif
            OCall ebx::IncFile.StmWriteChar, ":"
          .endif
          WritePtr
          .if pType != NULL
            OCall ebx::IncFile.StmWrite, pType
          .endif
          OCall ebx::IncFile.StmDeleteLastSpace
        .endif
        pop eax
        .break .if CHRA ptr [eax] == ")"
        OCall ebx::IncFile.StmWrite, $OfsCStrA(", ")
        mov pType, NULL
        mov dPtrCount, 0
        .continue
      .endif

      mov pToken, eax
      invoke TranslateTypeQualifier, eax
      .continue .if CHRA ptr [eax] == 0
      .if pType == NULL
        m2m pType, pToken, eax
      .endif
    .endw
    OCall ebx::IncFile.StmWriteEOL

    .if bAcceptBody != FALSE
      OCall ebx::IncFile.PeekNextToken
      .if eax != NULL && CHRA ptr [eax] == "{"
        invoke SkipBraces, "{", "}"
      .endif
    .endif

    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseTypedefFunction - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    ret
ParseTypedefFunction endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedefFunctionPtr
; Purpose:   typedef function pointer occured.
; Arguments: Arg1 -> Parent.
; Return:    eax -> Last Token, usually ';' or NULL if failed.
;            edx -> Name.
; Syntax:    typedef function pointer
;            typedef <annotations><qualifiers><returntype> ( <qualifiers> * <name> )(<parameters>)
; Notes:     The first "(" has been read already!
;            This procedure has to be reentrant, since a function parameter may have "function ptr"
;            types. That means, that we have to write to an intermediate buffer (szPrototype) until
;            we returned from the last recursive call.

ParseTypedefFunctionPtr proc uses edi pParent:PSTRINGA
    local pToken:PTOKEN, pName:PSTRINGA, pType:PSTRINGA
    local dQualifier:DWORD, dPtrCount:DWORD, bFirstParam:DWORD
    local dTypeCSpec:DWORD, dScanStep:DWORD
    local szPrototype[1024*3]:CHRA, szType[128]:CHRA

    mov dPtrCount, 0
    mov dQualifier, 0
    mov szPrototype, 0
    mov pName, NULL

    ;Get Qualifiers & Name ----------------------------------------------------
    .while TRUE
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error
      invoke SkipAnnotations, eax
      test eax, eax
      jz @Error
      mov pToken, eax

      cmp CHRA ptr [eax], ";"                           ;Statement terminator
      jz @Error

      cmp CHRA ptr [eax], "}"                           ;block terminator
      jz @Exit

      .break .if CHRA ptr [eax] == ")"
      .if CHRA ptr [eax] == "*"
        inc dPtrCount
      .else
        invoke GetProtoQualifier, eax
        .if eax != NULL
          mov edx, [eax - sizeof DWORD]
          mov eax, [eax + edx]
          or dQualifier, eax
        .else
          m2m pName, pToken, eax                        ;Ignore any qualifiers
        .endif
      .endif
    .endw

    DbgPrintF $RGB(0,0,0), <"%u: ParseTypedefFunctionPtr - %s">, [ebx].$Obj(IncFile).dLineNbr, pName

    ;Parse function header ----------------------------------------------------
    OCall ebx::IncFile.GetNextToken
    test eax, eax
    jz @Error
    invoke SkipAnnotations, eax
    test eax, eax
    jz @Error
    cmp CHRA ptr [eax], "("
    jnz @Error

    lea edi, szPrototype                                ;edi -> Buffer
    xor eax, eax
    .if pName != NULL
      .if ([ebx].$Obj(IncFile).bInsideInterface != FALSE); && (dQualifier & PTQ_STDCALL || dQualifier & PTQ_FASTCALL)
        invoke TranslateReservedWord, pName, NULL
        invoke sprintf, edi, $OfsCStrA("STD_METHOD %s, "), eax ;Use asm adhoc macro
      .else
        invoke GetCallConvString, dQualifier
        .if pParent != NULL
          invoke sprintf, edi, $OfsCStrA("TYPE_%s_%s typedef proto %s "), pParent, pName, eax
        .else
          invoke sprintf, edi, $OfsCStrA("TYPE_%s typedef proto %s "), pName, eax
        .endif
      .endif
      add edi, eax                                      ;Move pointer to the end
    .endif

    ;Parse function parameters ------------------------------------------------
    mov dPtrCount, 0
    mov pType, NULL
    mov bFirstParam, TRUE
    .while TRUE
      OCall ebx::IncFile.GetNextToken
@ProcessToken:
      test eax, eax
      jz @Error
      invoke SkipAnnotations, eax
      test eax, eax
      jz @Error
      .break .if CHRA ptr [eax] == ";"                  ;Statement terminator

      .if CHRA ptr [eax] == "*"
        inc dPtrCount
        .continue
      .endif

      .continue .if $DoesStringMatchA?([eax], <struct>) ;Ignore 'struct'
      .continue .if $DoesStringMatchA?([eax], <union>)  ;Ignore 'union'
      .continue .if $DoesStringMatchA?([eax], <enum>)   ;Ignore 'enum'

      .if CHRA ptr [eax] == "["
        inc dPtrCount
        .repeat
          OCall ebx::IncFile.GetNextToken
        .until eax == NULL || CHRA ptr [eax] == "]" || CHRA ptr [eax] == ";"
        .continue
      .endif

      .if CHRA ptr [eax] == "("
        ;Function ptr as function parameter?
        invoke IsFunctionPtr?
        .if eax != FALSE
          movzx eax, [ebx].$Obj(IncFile).bInsideInterface     ;If we are inside an interface declaration
          push eax                                      ;Then we want to declare a typedef
          mov [ebx].$Obj(IncFile).bInsideInterface, FALSE
          invoke ParseTypedefFunctionPtr, pName         ;Possible recursion here!!!
          mov pToken, eax
          pop eax
          mov [ebx].$Obj(IncFile).bInsideInterface, al
          invoke sprintf, addr szType, $OfsCStrA("P%s_%s"), pName, edx
          lea eax, szType
          mov pType, eax
          mov eax, pToken
          .break .if CHRA ptr [eax] == ";"
        .endif
      .endif

      invoke TranslateTypeQualifier, eax
      .continue .if CHRA ptr [eax] == 0

      ;pToken may be a basic C type -------------------------------------------
      mov pToken, eax
      .if pType == NULL
        BasicTypeCScan
        mov pToken, eax
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if eax == NULL
            mov pType, offset szUnkType
          .else
            mov pType, eax
          .endif
          mov eax, pToken
          jmp @ProcessToken
        .else
          mov pType, eax
        .endif
      .endif

      mov eax, pToken                                   ;Needed
      .if CHRA ptr [eax] == "," || CHRA ptr [eax] == ")"
        .if bFirstParam != FALSE
          mov ecx, pType
          .break .if CHRA ptr [ecx] == 0 && dPtrCount == 0
          .break .if CHRA ptr [ecx] == ")"              ;We have no argument => name()
          FillStringA [edi], <:>
          add edi, 1
          mov bFirstParam, FALSE
        .else
          FillStringA [edi], <, :>
          add edi, 3
        .endif

        .while dPtrCount != 0
          FillStringA [edi], <ptr >
          add edi, 4
          dec dPtrCount
        .endw

        mov eax, pType
        .if eax != NULL && CHRA ptr [eax] != 0
          invoke TranslateReservedWord, pType, NULL
          invoke StrECopy, edi, eax
          mov edi, eax
        .else
          mov CHRA ptr [edi], 0
        .endif

        mov eax, pToken
        .break .if CHRA ptr [eax] == ")"                ;Exit here with ')'

        .if CHRA ptr [edi - 1] == " "
          dec edi
          mov CHRA ptr [edi], 0
        .endif

        mov pType, NULL
        mov dPtrCount, 0
        .continue
      .endif

      .if pType == NULL && dPtrCount == 0               ;After an '*' can't come a type
        mov pType, eax
      .endif

    .endw

    .while CHRA ptr [eax] != ";" && CHRA ptr [eax] != ","     ;Consume the rest up to ';' or ','
      OCall ebx::IncFile.GetNextToken
    .endw
    mov pToken, eax

    .if pName != NULL
      OCall ebx::IncFile.StmWrite, addr szPrototype
      OCall ebx::IncFile.StmDeleteLastSpace
      OCall ebx::IncFile.StmWriteEOL

      .if [ebx].$Obj(IncFile).bInsideInterface == FALSE
        .if pParent != NULL
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("P%s_%s"), pParent, pName
        .else
          invoke TranslateReservedWord, pName, NULL
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s"), eax
        .endif
        OCall ebx::IncFile.StmWrite, $OfsCStrA(" typedef ptr TYPE")
        .if pParent != NULL
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s_%s"), pParent, pName
        .else
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("_%s"), pName
        .endif
        OCall ebx::IncFile.StmWriteEOL
      .endif
    .endif
@Exit:
    mov edx, pName
    mov eax, pToken
    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseTypedefFunctionPtr - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    mov edx, pName
    mov eax, pToken
    ret
ParseTypedefFunctionPtr endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseMemLayoutItem
; Purpose:   Get a struct or union declaration item.
; Arguments: Arg1 -> First Token after 'union' or 'struct' Token.
;            Arg2 -> Struct or union Name.
; Return:    eax -> Last Token, usually ';' or NULL if failed.
; Link:      https://en.cppreference.com/w/c/language/bit_field
; Idea:      Replace _??xx with the name of the parent struct.

ParseMemLayoutItem proc uses edi pToken:PTOKEN, pMemLayoutName:PSTRINGA
    local dTypeCSpec:DWORD, bBits:DWORD, bStruct:DWORD, bFirst:DWORD, pPrvName:PSTRINGA
    local dFieldCount:DWORD, dRes:DWORD, dPtrCount:DWORD, dBits:DWORD, dNameFlags:DWORD
    local pType:PSTRINGA, pName:PSTRINGA, pDupList:POINTER, pBits:PSTRINGA, pEndToken:PSTRINGA
    local dReturn:DWORD, InpStat:INP_STAT
    local szMacroBuffer[MAX_BLOCK_NAME]:CHRA, szRecord[64]:CHRA, szBuffer[128]:CHRA, szBits[128]:CHRA

    m2m pPrvName, [ebx].$Obj(IncFile).pStructName, eax
    m2m [ebx].$Obj(IncFile).pStructName, pMemLayoutName, ecx

    mov bBits, FALSE
    mov bStruct, FALSE
    mov dBits, 0
    mov dRes, 0
    mov dFieldCount, 0
    mov pEndToken, NULL

@NextMember:
    mov pBits, NULL
    mov pName, NULL
    mov pType, NULL
    mov pDupList, NULL
    mov dPtrCount, 0

    mov eax, pToken                                     ;Use token passed to this proc
    .while TRUE
      .break .if eax == NULL
      invoke SkipAnnotations, eax
      .break .if eax == NULL
      mov cl, [eax]
      .break .if cl == ";" || cl == "}" || cl == ","
      mov pToken, eax

      ;union ------------------------------------------------------------------
      .if $DoesStringMatchA?([eax], <union>)
        DbgPrintF $RGB(0,0,0), <"%u: ParseMemLayoutItem - %s.union found">, [ebx].$Obj(IncFile).dLineNbr, pMemLayoutName
        OCall ebx::IncFile.StmWrite, offset szUnion
        inc [ebx].$Obj(IncFile).dIndentation
        OCall ebx::IncFile.GetNextToken
        test eax, eax
        jz @Error
        mov pToken, eax
        IsName? eax
        .if eax != FALSE
          OCall ebx::IncFile.GetNextToken
          test eax, eax
          jz @Error
        .else
          mov eax, pToken
        .endif
        .if CHRA ptr [eax] == "{"
          invoke GetBlockName, addr szMacroBuffer
          .if eax != NULL
            mov pName, eax
          .endif
          mov dNameFlags, edx

          .if eax != NULL
            .if !$DoesStringMatchA?([eax], <DUMMYUNIONNAME>)  ;Don't write in case of an
              OCall ebx::IncFile.StmWriteChar, " "            ; embedded union & DUMMY name
              invoke TranslateReservedWord, pName, NULL
              OCall ebx::IncFile.StmWrite, eax
            .endif
          .endif
          OCall ebx::IncFile.StmWriteEOL

          invoke ParseBlock, pName, PBT_MEM_LAYOUT
          test eax, eax
          jz @Exit
          invoke SkipName, pName, dNameFlags
        .else
          OCall ebx::IncFile.ShowError, $OfsCStrA("union without block")
          OCall ebx::IncFile.StmWriteEOL
        .endif
        mov pType, NULL
        mov pName, NULL
        dec [ebx].$Obj(IncFile).dIndentation
        OCall ebx::IncFile.StmWrite, $OfsCStrA("ends")
        OCall ebx::IncFile.StmWriteEOL

        DbgPrintF $RGB(0,0,0), <"%u: ParseMemLayoutItem - end of union">, [ebx].$Obj(IncFile).dLineNbr
        jmp @GetNextToken
      .endif

      ;struct -----------------------------------------------------------------
      .if $DoesStringMatchA?([eax], <struct>)
        DbgPrintF $RGB(0,0,0), <"%u: ParseMemLayoutItem - %s.struct found">, [ebx].$Obj(IncFile).dLineNbr, pMemLayoutName
        OCall ebx::IncFile.GetNextToken
        .if eax == NULL || CHRA ptr [eax] == ";"        ;Statement terminator
          jmp @Error
        .endif
        DbgPrintF $RGB(0,0,0), <"%u: ParseMemLayoutItem - %s.struct, next token %s">, [ebx].$Obj(IncFile).dLineNbr, pMemLayoutName, eax
        .if CHRA ptr [eax] != "{"
          mov pName, eax
          OCall ebx::IncFile.PeekNextToken
          .if eax != NULL && CHRA ptr [eax] == "{"
            OCall ebx::IncFile.GetNextToken
          .else
            mov eax, pName
            mov pName, NULL
          .endif
        .endif
        .if CHRA ptr [eax] == "{"
          OCall ebx::IncFile.StmWrite, offset szStruct
          inc [ebx].$Obj(IncFile).dIndentation
          invoke GetBlockName, addr szMacroBuffer       ;eax -> Name, edx = flags (if name is a macro)
          .if eax != NULL
            mov pName, eax
          .endif
          mov dNameFlags, edx

          .if eax != NULL
            .if !$DoesStringMatchA?([eax], <DUMMYSTRUCTNAME>) ;Don't write in case of an
              OCall ebx::IncFile.StmWriteChar, " "            ; embedded structure & DUMMY name
              invoke TranslateReservedWord, pName, NULL
              OCall ebx::IncFile.StmWrite, eax
            .endif
          .endif
          OCall ebx::IncFile.StmWriteEOL

          invoke ParseBlock, pName, PBT_MEM_LAYOUT
          test eax, eax
          jz @Exit

          invoke SkipName, pName, dNameFlags

          ;In case that the structure is repeated [...], we ignore it ---------
          OCall ebx::IncFile.PeekNextToken
          .if eax != NULL && CHRA ptr [eax] == "["
            OCall ebx::IncFile.GetNextToken
            invoke SkipBraces, "[", "]"
          .endif

          dec [ebx].$Obj(IncFile).dIndentation
          OCall ebx::IncFile.StmWrite, $OfsCStrA("ends")
          OCall ebx::IncFile.StmWriteEOL
          DbgPrintF $RGB(0,0,0), <"%u: ParseMemLayoutItem - end of struct">, [ebx].$Obj(IncFile).dLineNbr

        .elseif CHRA ptr [eax] == "*"
          inc dPtrCount

        .else
          ;Found struct tag ---------------------------------------------------
          mov pType, eax                                ;Name of structure
          mov pName, NULL
          mov dPtrCount, 0
          IsName? eax
          .if eax != FALSE
            .while TRUE
              OCall ebx::IncFile.GetNextToken
              test eax, eax
              jz @Error
              mov cl, [eax]
              .if cl == "["                             ;It is an array of structures!
                jmp @DUP
              .endif
              .break .if cl == ";" || cl == ","
              .if CHRA ptr [eax] == "*"
                inc dPtrCount
              .else
                invoke TranslateTypeQualifier, eax
                .continue .if CHRA ptr [eax] == 0
                push eax
                IsName? eax
                pop ecx
                .if eax != FALSE
                  mov pName, ecx
                .endif
              .endif
            .endw
            .if pName != NULL
              .if pType != NULL && dPtrCount == 0
                OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s %s <>"), pName, pType
                OCall ebx::IncFile.StmWriteEOL
              .else
                OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s POINTER ?"), pName
                OCall ebx::IncFile.StmWriteEOL
              .endif
            .else
              mov bStruct, TRUE
              jmp @GetNextToken
            .endif
          .else
            OCall ebx::IncFile.ShowError, $OfsCStrA("unexpected MemLayoutItem '%s' after 'struct'"), pType
          .endif
        .endif
        mov pType, NULL
        mov pName, NULL
        mov dPtrCount, 0
        jmp @GetNextToken
      .endif

      ;Skip the following keywords --------------------------------------------
      .if $DoesStringMatchA?([eax], <static>)
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([eax], <enum>)
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([eax], <const>)
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([eax], <friend>)
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([eax], <virtual>)
        jmp @GetNextToken
      .endif

      ;private or protected ---------------------------------------------------
      IsPublicPrivateProtected? eax
      .if eax != FALSE
        OCall ebx::IncFile.PeekNextToken
        .if eax != NULL && CHRA ptr [eax] == ":"
          OCall ebx::IncFile.GetNextToken
          jmp @GetNextToken
        .endif
      .endif

      ;macro ------------------------------------------------------------------
      invoke IsMacro?, pToken
      .if eax != 0
        .if eax == 1
          OCall g_pMacros::List.ItemAt, ecx
        .else
          OCall g_pKnownMacros::List.ItemAt, ecx
        .endif
        mov edx, [eax - sizeof DWORD]
        invoke ParseMacroInvocation, pToken, DWORD ptr [eax + edx], TRUE
        .if eax != FALSE
          jmp @GetNextToken
        .endif
      .endif

      ;equate containing items ------------------------------------------------
      invoke IsEquate?, pToken
      .if eax != 0
        .if eax == 1
          OCall g_pEquates::List.ItemAt, ecx
        .else
          OCall g_pKnownEquates::List.ItemAt, ecx
        .endif
        mov edx, [eax - sizeof DWORD]

        .ifBitSet DWORD ptr [eax + edx], EQF_HAS_EOL 
          OCall ebx::IncFile.StmWrite, pToken
          OCall ebx::IncFile.StmWriteEOL
          jmp @GetNextToken
        .endif
      .endif

      ;Record -----------------------------------------------------------------
      mov eax, pToken
      .if CHRA ptr [eax] == ":"                         ;Record field
        lea edi, szBits
        mov pBits, edi
        mov bFirst, TRUE
        .while TRUE
          OCall ebx::IncFile.GetNextToken
          mov pToken, eax
          .break .if eax == NULL
          mov cl, [eax]
          .break .if cl == ";" || cl == "}" || cl == ","
          .if bFirst != FALSE
            mov bFirst, FALSE
          .else
            mov DCHRA ptr [edi], " "
            inc edi
          .endif
          invoke TranslateNumOperator, pToken
          .if edx == FALSE
            invoke TranslateLogOperator, eax
          .endif
          invoke StrECopy, edi, eax
          mov edi, eax
        .endw
        .continue
      .endif

      ;Function or FunctionPtr ------------------------------------------------
      mov eax, pToken
      .if CHRA ptr [eax] == "("
        invoke IsFunctionPtr?
        .if eax != FALSE
          invoke ParseTypedefFunctionPtr, NULL
          .continue
        .else
          invoke IsFunction?
          .if eax != FALSE
            mov eax, pName
            test eax, eax
            cmovz eax, pType
            invoke ParseTypedefFunction, eax, FALSE, NULL
            .continue
          .endif
        .endif
      .endif

      ;Array ------------------------------------------------------------------
      mov eax, pToken
      .if CHRA ptr [eax] == "["                         ;Array => DUP
@DUP:
        .if pType != NULL || pName != NULL              ;Only of we have a Type & a Name
          mov pDupList, $Create@Stacklist()
          .while TRUE
            OCall ebx::IncFile.GetNextToken
            .if eax == NULL || CHRA ptr [eax] == ";"    ;Statement terminator
              jmp @Error
            .endif
            .break .if CHRA ptr [eax] == "]"
            Add@Stacklist pDupList, eax                 ;Add Tokens to the DUP-List
          .endw
          jmp @GetNextToken
        .endif
      .endif

      ;Pointer ----------------------------------------------------------------
      mov eax, pToken
      mov cl, [eax]
      .if cl == "*" || cl == "&"
        inc dPtrCount
        jmp @GetNextToken
      .endif

      invoke TranslateTypeQualifier, pToken
      cmp CHRA ptr [eax], 0
      jz @GetNextToken
      mov pToken, eax

      ;pToken may be a basic C type -------------------------------------------
      .if pType == NULL
        BasicTypeCScan
        mov pToken, eax                                 ;Last gattered Token
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if eax == NULL                               ;If conversion failed
            mov pType, offset szUnkType
          .else
            mov pType, eax
          .endif
          mov eax, pToken
          .continue                                     ;Process the last gattered Token
        .endif
      .endif
      
      IsName? pToken
      .if eax != FALSE
        mov ecx, pToken
        .if pType == NULL
          mov pType, ecx
        .elseif pName == NULL
          mov pName, ecx
        .else
          jmp @Error
        .endif
      .else
        jmp @Error
      .endif

@GetNextToken:
      OCall ebx::IncFile.GetNextToken
    .endw
    mov pEndToken, eax

    ;Write member to stream ---------------------------------------------------
    .if pBits != NULL                                   ;Check for bit field => record
      .if pName == NULL                                 ;It is possible that NO name is supplied!
        lea eax, szBuffer                               ;=> create one
        mov pName, eax
        invoke sprintf, eax, $OfsCStrA("Bitfield%u"), dFieldCount
      .endif

      ;Write record declaration -----------------------------------------------
      .if bBits == FALSE
        mov bBits, TRUE
        DbgPrintF $RGB(0,0,0), <"%u: ParseMemLayoutItem - new Bitfield: %s">, [ebx].$Obj(IncFile).dLineNbr, pType
        mov ecx, $OfsCStrA("DUMMYRECORDNAME")
        mov eax, pMemLayoutName
        .if eax != NULL                                 ;Unnamed struct or union
          .if !$DoesStringMatchA?([eax], <DUMMYSTRUCTNAME>)
            .if !$DoesStringMatchA?([eax], <DUMMYUNIONNAME>)
              mov ecx, eax
            .endif
          .endif
        .endif
        invoke sprintf, addr szRecord, $OfsCStrA("%s_??%u"), ecx, g_dRecordNameSufix
        .if g_bNoRecords == FALSE
          OCall ebx::IncFile.StmWrite, addr szRecord
          OCall ebx::IncFile.StmWrite, $OfsCStrA(" record ")
        .endif
      .endif

      .if g_bNoRecords == FALSE
        DbgPrintF $RGB(0,0,0), <"%u: ParseMemLayoutItem - new bits: %s">, [ebx].$Obj(IncFile).dLineNbr, pName
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s_??%u:%s"), pName, g_dRecordNameSufix, pBits
      .else
        invoke dec2dwordA, pBits
        mov ecx, dBits
        xor edx, edx
        .while eax != 0
          bts edx, ecx
          inc ecx
          dec eax
        .endw
        mov dBits, ecx
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s_%s equ 0%xh"), addr szRecord, pName, edx
        OCall ebx::IncFile.StmWriteEOL
      .endif

      ;Determine if we are at the end of a record declaration -----------------
      OCall ebx::IncFile.SaveInputStatus, addr InpStat
      inc [ebx].$Obj(IncFile).bSkipScanPP
      mov dReturn, TRUE
      .while TRUE
        OCall ebx::IncFile.GetNextToken
        .break .if eax == NULL
        .continue .if !IsIfLevelActive?(InpStat)
        mov cl, [eax]
        .break .if cl == "," || cl == ";"                 ;Statement terminator
        .if cl == ":"
          mov dReturn, FALSE
          .break
        .endif
      .endw
      dec [ebx].$Obj(IncFile).bSkipScanPP
      OCall ebx::IncFile.LoadInputStatus, addr InpStat

      .if dReturn != FALSE
        inc g_dRecordNameSufix
        .if g_bNoRecords == FALSE
          OCall ebx::IncFile.StmWriteEOL
        .endif
        .if g_bRecordsInUnions != FALSE
          OCall ebx::IncFile.StmWrite, offset szUnion
          OCall ebx::IncFile.StmWriteEOL
          ;Tab here
          OCall ebx::IncFile.StmWrite, pType
          OCall ebx::IncFile.StmWrite, $OfsCStrA(" ?")
          OCall ebx::IncFile.StmWriteEOL
        .elseif g_bNoRecords != FALSE
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s %s "), addr szRecord
          IsStructure? pType
          .if eax != FALSE
            OCall ebx::IncFile.StmWrite, $OfsCStrA("<>")
          .else
            OCall ebx::IncFile.StmWriteChar, "?"
          .endif
          OCall ebx::IncFile.StmWriteEOL
        .endif

        .if g_bNoRecords == FALSE
          OCall ebx::IncFile.StmWrite, addr szRecord
          OCall ebx::IncFile.StmWrite, $OfsCStrA(" <>")
          OCall ebx::IncFile.StmWriteEOL
        .endif
        .if g_bRecordsInUnions != FALSE
          OCall ebx::IncFile.StmWrite, $OfsCStrA("ends")
          OCall ebx::IncFile.StmWriteEOL
        .endif

      .else
        .if g_bNoRecords == FALSE
          OCall ebx::IncFile.StmWrite, $OfsCStrA(", ")
        .endif
        inc dFieldCount
        OCall ebx::IncFile.GetNextToken
        mov pToken, eax
        jmp @NextMember
      .endif

    .elseif pName != NULL
      ;Write regular struct/union member --------------------------------------
      .if dPtrCount != 0
        mov pType, $OfsCStrA("POINTER")
      .else
        .if pType == NULL
          IsStructure? pName
          .if eax != FALSE
            xor eax, eax
            xchg eax, pName
            mov pType, eax
          .endif
        .endif
      .endif

      .if pName != NULL
        invoke TranslateReservedWord, pName, NULL
        OCall ebx::IncFile.StmWrite, eax
      .endif
      .if pType != NULL
        OCall ebx::IncFile.StmWriteChar, " "
        invoke TranslateReservedWord, pType, NULL
        OCall ebx::IncFile.StmWrite, eax
        .if pDupList != NULL
          OCall ebx::IncFile.StmWriteChar, " "
          invoke WriteStackList, pDupList
          OCall ebx::IncFile.StmWrite, $OfsCStrA($Esc(" dup \{"))
        .else
          OCall ebx::IncFile.StmWriteChar, " "
        .endif
        IsStructure? pType
        .if eax != FALSE
          OCall ebx::IncFile.StmWrite, $OfsCStrA("<>")
        .else
          OCall ebx::IncFile.StmWriteChar, "?"
        .endif
        .if pDupList != NULL
          OCall ebx::IncFile.StmWriteChar, 29h          ;")"
        .endif
      .endif
      OCall ebx::IncFile.StmWriteComment
      OCall ebx::IncFile.StmWriteEOL
      ;------------------------------------------------------------------------

      mov eax, pToken
      .if eax != NULL && CHRA ptr [eax] == ","
        OCall ebx::IncFile.GetNextToken
        mov pToken, eax
        jmp @NextMember
      .endif
    .endif

@Exit:
    Destroy@Stacklist pDupList
    mov eax, pEndToken
    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseMemLayoutItem - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    m2m [ebx].$Obj(IncFile).pStructName, pPrvName, eax
    OCall ebx::IncFile.ShowError, $OfsCStrA("unexpected '%s' MemLayoutItem = '%s'"), pMemLayoutName, pToken
    mov eax, pEndToken
    ret
ParseMemLayoutItem endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseEnumItem
; Purpose:   Get an enum item declaration.
; Arguments: Arg1 -> Token.
; Return:    eax -> Last Token, usually ';' or NULL if failed.
; Idea:      linear code, not looping.

ParseEnumItem proc uses edi pToken:PTOKEN
    GED_MacroInvocation macro
        invoke IsMacro?, pToken
        .if eax != 0
          .if eax == 1
            OCall g_pMacros::List.ItemAt, ecx
          .else
            OCall g_pKnownMacros::List.ItemAt, ecx
          .endif
          mov edx, [eax - sizeof DWORD]
          invoke ParseMacroInvocation, pToken, DWORD ptr [eax + edx], FALSE
          mov bFirstToken, FALSE
          jmp @GetNextToken
        .endif
    endm

    local sdValue:SDWORD, dStep:DWORD, bFirstToken:DWORD, bNegative:DWORD

    mov eax, pToken                                     ;Use token passed to this proc
    mov sdValue, 0
    .while TRUE
      mov dStep, 0
      mov bFirstToken, TRUE
      .while TRUE
        .if eax == NULL || CHRA ptr [eax] == ";"        ;Statement terminator
          jmp @Error
        .endif

        .if dStep == 0
          .if CHRA ptr [eax] == "," || CHRA ptr [eax] == "}"  ;Item terminator or end of declaration
            .break
          .endif

          GED_MacroInvocation

          mov eax, pToken
          invoke TranslateReservedWord, eax, NULL
          OCall ebx::IncFile.StmWrite, eax
          mov dStep, 1
          jmp @GetNextToken
        .endif

        .if dStep == 1
          mov eax, pToken
          .if CHRA ptr [eax] == "," || CHRA ptr [eax] == "}"  ;Item terminator or end of declaration
            OCall ebx::IncFile.StmWriteF, $OfsCStrA(" equ %d"), sdValue
            inc sdValue
            OCall ebx::IncFile.StmWriteEOL
            .break
          .endif

          .if CHRA ptr [eax] == "="
            OCall ebx::IncFile.StmWrite, $OfsCStrA(" equ ") ;Use equ (unchangeable)
            mov bFirstToken, TRUE
            mov bNegative, FALSE
            mov dStep, 2
            jmp @GetNextToken
          .endif
        .endif

        .if dStep == 2
          .if bFirstToken != FALSE
            .if CHRA ptr [eax] == "," || CHRA ptr [eax] == "}"
              OCall ebx::IncFile.StmWriteF, $OfsCStrA("%d"), sdValue
              inc sdValue
              OCall ebx::IncFile.StmWriteEOL
              .break
            .endif
          .else
            .if CHRA ptr [eax] == "," || CHRA ptr [eax] == "}"
              OCall ebx::IncFile.StmDeleteLastSpace
              OCall ebx::IncFile.StmWriteEOL
              .break
            .endif
          .endif

          GED_MacroInvocation

          mov eax, pToken
          .if CHRA ptr [eax] == "("                     ;On enumerations, we will skip ... = (int) xxxx
            mov bFirstToken, FALSE
            invoke SkipBraces, "(", ")"
            test eax, eax
            jz @Error
            jmp @GetNextToken
          .endif

          .if (CHRA ptr [eax] == "-" || CHRA ptr [eax] == "+") && bFirstToken != FALSE
            .if CHRA ptr [eax] == "-"
              mov bNegative, TRUE
            .endif
            OCall ebx::IncFile.StmWrite, eax
            mov bFirstToken, FALSE
            jmp @GetNextToken
          .endif

          invoke TranslateNumOperator, eax
          OCall ebx::IncFile.StmWrite, eax
          OCall ebx::IncFile.StmWriteChar, " "
          mov bFirstToken, FALSE

          mov eax, pToken
          .if CHRA ptr [eax] >= "0"
            invoke dec2dwordA, pToken
            inc eax                                     ;Increment for next enum item
            .if bNegative != FALSE
              neg eax
              inc eax
            .endif
            mov sdValue, eax
          .endif
        .endif

@GetNextToken:
        OCall ebx::IncFile.GetNextToken
        mov pToken, eax
      .endw
      mov eax, pToken
      .break .if CHRA ptr [eax] == "}"                  ;Statment terminator
      OCall ebx::IncFile.GetNextToken
      mov pToken, eax
    .endw

    mov eax, pToken
    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseEnumItem - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    OCall ebx::IncFile.ShowError, $OfsCStrA("unexpected enum item = '%s'"), pToken
    mov eax, pToken
    ret
ParseEnumItem endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseBlock
; Purpose:   Get members of a block (structure, union, enum).
; Arguments: Arg1 -> Name.
;            Arg2: Mode.
;              PBT_MEM_LAYOUT: variable declaration in (struct|union)
;              PBT_EXTERN: extern declaration.
;              PBT_ENUM: enum declaration.
; Return:    eax -> Last Token or NULL if failed.

ParseBlock proc uses esi pName:PSTRINGA, dMode:DWORD
    local wIf:WORD

    movzx eax, [ebx].$Obj(IncFile).bIfLevel
    mov ah, [ebx].$Obj(IncFile).bIfStructure[eax - 1]
    mov wIf, ax

    mov esi, 1
    .repeat
      OCall ebx::IncFile.GetNextToken
      .break .if eax == NULL
      invoke SkipAnnotations, eax
      .break .if eax == NULL

      movzx ecx, [ebx].$Obj(IncFile).bIfLevel
      mov ch, [ebx].$Obj(IncFile).bIfStructure[ecx - 1]
      .if (cl == BYTE ptr wIf) && (ch != BYTE ptr wIf + 1)
        mov [ebx].$Obj(IncFile).pPrevToken, eax
        mov [ebx].$Obj(IncFile).bUsePrevToken, TRUE
        xor eax, eax
        jmp @Exit
      .endif

      .if CHRA ptr [eax] == "{"
        inc esi
        .continue

      .elseif CHRA ptr [eax] == "}"
        dec esi

      .else
        .if dMode == PBT_ENUM
          invoke ParseEnumItem, eax

        .elseif dMode == PBT_MEM_LAYOUT
          invoke ParseMemLayoutItem, eax, pName

        .else
          invoke ParseExternItem, eax
        .endif

        .break .if eax == NULL
        .if CHRA ptr [eax] == "}"
          dec esi
        .endif
      .endif
    .until esi == 0

@Exit:
    DbgPrintF $RGB(0,0,0), <"%u: ParseBlock - %s, end of struct found [%u]">, [ebx].$Obj(IncFile).dLineNbr, pName, eax
    ret
ParseBlock endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseInterfaceBlock
; Purpose:   Get members of a block (structure, union, enum).
; Arguments: Arg1 -> Name.
;            eax -> '{'
; Return:    eax -> Last Token or NULL if failed.

ParseInterfaceBlock proc pName:PSTRINGA
    mov [ebx].$Obj(IncFile).bInsideInterface, TRUE
    .repeat
      invoke ParseTypedefFunctionPtr, NULL
;      invoke ParseMemLayoutItem, eax, pName
      .break .if eax == NULL
      .if CHRA ptr [eax] == ";"
        OCall ebx::IncFile.PeekNextToken
        .break .if eax == NULL
        .if CHRA ptr [eax] == "}"
          OCall ebx::IncFile.GetNextToken               ;Consume it
          .break
        .endif
      .else
        jmp @Error
      .endif
    .until FALSE
    mov [ebx].$Obj(IncFile).bInsideInterface, FALSE
    ret

@Error:
    DbgPrintF $RGB(0,0,0), <"%u: ParseInterfaceBlock - %s, end of struct found [%u]">, [ebx].$Obj(IncFile).dLineNbr, pName, eax
    mov [ebx].$Obj(IncFile).bInsideInterface, FALSE
    xor eax, eax
    ret
ParseInterfaceBlock endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedefEnum
; Purpose:   Parse 'typedef enum'.
; Arguments: Arg1: Typedef flag.
; Return:    TRUE if succeeded, otherwise FALSE
; Syntax:    <typedef> <qualifiers> enum <tname> {x<=a>,y<=b>,...} name<,*name>;
;            <typedef> <qualifiers> enum <tname> <:type> {x<=a>,y<=b>,...} name<,*name>;
;            <typedef> <qualifiers> enum <class> <tname> <: type> {x<=a>,y<=b>,...} name<,*name>;
;            simplest form is "enum {x = a, y = b};"

ParseTypedefEnum proc uses edi bIsTypedef:BOOL
    local pTag:PTOKEN, pName:PTOKEN, pType:PSTRINGA, pToken:PTOKEN
    local szBlockName[MAX_BLOCK_NAME]:CHRA, szType[100]:CHRA
    local dTypeCSpec:DWORD, dScanStep:DWORD

    mov pTag, NULL
    mov pName, NULL
    mov pType, NULL

    OCall ebx::IncFile.GetNextToken
    invoke SkipAnnotations, eax
    test eax, eax
    jz @Error
    invoke SkipMacros, eax
    test eax, eax
    jz @Error

    .if CHRA ptr [eax] != "{" && CHRA ptr [eax] != ":"
      mov pTag, eax
      OCall ebx::IncFile.GetNextToken
    .endif
    mov pToken, eax

    .if eax != NULL && CHRA ptr [eax] == ":"            ;Type specified?
      OCall ebx::IncFile.GetNextToken
      test eax, eax
      jz @Error

      ;pToken may be a basic C type
      BasicTypeCScan
      .if dTypeCSpec != 0
        mov pToken, eax                                 ;Last gattered Token
        invoke ConvBasicTypeC, dTypeCSpec
        .if eax == NULL                                 ;If conversion failed
          mov pType, offset szUnkType
        .else
          mov pType, eax
        .endif
      .else
        mov pType, eax
        OCall ebx::IncFile.GetNextToken
        test eax, eax
        jz @Error
        mov pToken, eax
      .endif
    .else
      mov pType, $OfsCStrA("SDWORD")                    ;Default enum type
    .endif

    mov eax, pToken
    .if eax != NULL && CHRA ptr [eax] == "{"
      .if bIsTypedef != FALSE
        invoke GetBlockName, addr szBlockName
      .else
        xor eax, eax
      .endif
      mov pName, eax
      test eax, eax
      cmovz eax, pTag                                   ;if no name found, use the tag
      .if eax != NULL
        mov pName, eax
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s typedef %s"), pName, pType
        OCall ebx::IncFile.StmWriteEOL
      .endif
      mov [ebx].$Obj(IncFile).dEnumValue, 0
      invoke ParseBlock, pName, PBT_ENUM

      ;Write a typedaf with the tagName
      mov eax, pName
      .if eax != NULL && pTag != NULL
        invoke StrCompA, pName, pTag
        .if eax != 0
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s typedef %s"), pTag, pName
          OCall ebx::IncFile.StmWriteEOL
        .endif
      .endif

      .if bIsTypedef != FALSE
        OCall ebx::IncFile.GetNextToken                 ;Skip enum name
      .endif
      OCall ebx::IncFile.GetNextToken
      .if eax != NULL && pName != NULL && CHRA ptr [eax] != ";"
        invoke ParseFurtherTypes, pName, NULL, eax
      .else
        OCall ebx::IncFile.StmWriteEOL                  ;Separator line
      .endif

      mov eax, TRUE

    .else
      ;Syntax "typedef <Annotation> enum OldTypeName <*> NewTypeName;
      push eax
      IsName? eax
      pop ecx
      .if eax != FALSE
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s typedef %s"), ecx, pType
        OCall ebx::IncFile.StmWriteEOL
        mov eax, TRUE
      .elseif CHRA ptr [ecx] == "*"
        OCall ebx::IncFile.GetNextToken
        .if eax != NULL
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s typedef ptr %s"), eax, pType
          OCall ebx::IncFile.StmWriteEOL
        .endif
        mov eax, TRUE
      .else
        xor eax, eax
      .endif
    .endif

    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseTypedefEnum - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    ret
ParseTypedefEnum endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedefUnionStruct
; Purpose:   Parse Typedef of a structure or union.
; Arguments: Arg1 -> MemLayoutType (structure or union).
;            Arg2: Inside class flag.
; Return:    Nothing
; Syntax:    class tname {};
;            typedef struct/union <macro> tname name;
;            typedef struct/union <macro> <tname> {} name;
;            typedef struct/union <macro> <tname> * name;

ParseTypedefUnionStruct proc pMemLayoutType:PSTRINGA, bInsideClass:BOOL
    local pName:PSTRINGA, pTag:PSTRINGA, pToken:PTOKEN
    local pInherit:POINTER, pSuffix:PSTRINGA
    local bSkipName:DWORD, bHasVTable:DWORD, dPtrCount:DWORD
    local szName[256]:CHRA, szStructName[MAX_BLOCK_NAME]:CHRA, szNoName[64]:CHRA

    mov szStructName, 0
    mov szName, 0
    mov szNoName, 0
    mov pTag, NULL
    mov pName, NULL
    mov pInherit, NULL
    mov dPtrCount, 0
    .if bInsideClass != FALSE
      mov pMemLayoutType, offset szStruct
      mov [ebx].$Obj(IncFile).bInsideClass, TRUE
    .endif
    DbgPrintF $RGB(0,0,0), <"%u: ParseTypedefUnionStruct - '%s'">, [ebx].$Obj(IncFile).dLineNbr, pMemLayoutType
    OCall ebx::IncFile.GetNextToken
    invoke SkipAnnotations, eax
    test eax, eax
    jz @Error
    invoke SkipMacros, eax
    test eax, eax
    jz @Error

    .if CHRA ptr [eax] != "{"
      DbgPrintF $RGB(0,0,0), <"%u: ParseTypedefUnionStruct - token '%s' assumed tag">, [ebx].$Obj(IncFile).dLineNbr, eax
      lea ecx, szName
      invoke TranslateReservedWord, eax, ecx
      mov pTag, eax
      mov pName, eax
      OCall ebx::IncFile.GetNextToken
    .endif
    test eax, eax
    jz @Error

    .if CHRA ptr [eax] == ":"
      .if 0; (!bInsideClass)
        invoke printf, $OfsCStrA("%s(%u): C++ syntax found", LF), [ebx].$Obj(IncFile).pFileName,
                       [ebx].$Obj(IncFile).dLineNbr
      .endif
      .while TRUE
        OCall ebx::IncFile.GetNextToken
        .if eax == NULL || CHRA ptr [eax] == ";"        ;Statement terminator
          jmp @Error
        .endif
        .break .if CHRA ptr [eax] == "{"
        .continue .if CHRA ptr [eax] == ","
        mov pToken, eax
        .if pInherit == NULL
          mov pInherit, $Create@Stacklist()
        .endif
        Add@Stacklist pInherit, pToken
      .endw
    .endif

    DbgPrintF $RGB(0,0,0), <"%u: ParseTypedefUnionStruct - token '%s' found">, [ebx].$Obj(IncFile).dLineNbr, eax

    .if CHRA ptr [eax] == "{"
      mov bHasVTable, FALSE
      .if bInsideClass != FALSE
        invoke HasVTable?
        mov bHasVTable, eax
      .endif
      invoke GetBlockName, addr szStructName
      mov bSkipName, TRUE
      .if eax == NULL
        mov eax, pTag
        mov bSkipName, FALSE
      .endif

      ;No name at all?
      .if eax == NULL
        invoke sprintf, addr szNoName, $OfsCStrA("STRUCT_%u"), g_dStructSuffix
        inc g_dStructSuffix
        lea eax, szNoName
      .endif
      lea ecx, szName
      invoke TranslateReservedWord, eax, ecx
      mov pName, eax
      IsStructure? pName
      .if eax == FALSE
        invoke StrSizeA, pName
        invoke InsertStrg, g_pStructs, pName, eax
      .endif
      mov pSuffix, offset szEmpty
;      .if pInherit != NULL
;        invoke HasVirtualBase?, pInherit
;        .if eax != FALSE
;          mov pSuffix, $OfsCStrA("$")
;        .endif
;      .endif

      OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s%s %s"), pName, pSuffix, pMemLayoutType

      ;Get known structure alignment
      OCall g_pAlignments::List.Search, pName
      .if eax != FALSE
        OCall g_pAlignments::List.ItemAt, ecx
        mov edx, [eax - sizeof DWORD]
        mov eax, [eax + edx]
      .endif
      .if eax != 0
        OCall ebx::IncFile.StmWriteF, $OfsCStrA(" %u"), eax
      .elseif g_bAddAlign != FALSE
        OCall ebx::IncFile.StmWrite, $OfsCStrA(" @Align")
      .endif
      OCall ebx::IncFile.StmWriteEOL

      inc [ebx].$Obj(IncFile).dIndentation
      .if bHasVTable != FALSE
        OCall ebx::IncFile.StmWrite, $OfsCStrA("  POINTER  ?   ; 'virtual method table'")
        OCall ebx::IncFile.StmWriteEOL
      .endif
      .if pInherit != NULL
        invoke WriteInherit, pInherit, TRUE
      .endif
      .if bInsideClass != FALSE
        invoke SkipBraces, "{", "}"
        test eax, eax
        jz @Exit
      .else
        invoke ParseBlock, pName, PBT_MEM_LAYOUT
        test eax, eax
        jz @Exit
        mov pToken, eax
      .endif
      .if pInherit != NULL
        invoke HasVirtualBase?, pInherit
        .if eax != NULL
;          OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s %s %s"), pName, pMemLayoutType, pAlignment
;          OCall ebx::IncFile.StmWriteEOL
;          OCall ebx::IncFile.StmWriteF, $OfsCStrA("  %s%s <>"), pName, pSuffix
;          OCall ebx::IncFile.StmWriteEOL
          invoke WriteInherit, pInherit, FALSE
;          OCall ebx::IncFile.StmWriteF,$OfsCStrA("%s ends"), pName
;          OCall ebx::IncFile.StmWriteEOL
        .endif
      .endif
      dec [ebx].$Obj(IncFile).dIndentation
      OCall ebx::IncFile.StmWriteF,$OfsCStrA("%s%s ends", LF), pName, pSuffix
      OCall ebx::IncFile.StmWriteEOL

      .if pTag != NULL && pName != NULL
        invoke StrCompA, pTag, pName
        .if eax != 0
          OCall ebx::IncFile.StmWriteF,$OfsCStrA("%s typedef %s"), pTag, pName
          OCall ebx::IncFile.StmWriteEOL
        .endif
      .endif

      .if bSkipName != FALSE
        OCall ebx::IncFile.GetNextToken  ;skip structure name
      .endif
      OCall ebx::IncFile.GetNextToken
      ;typedef struct/union tagname typename
    .endif

    .if eax != NULL
      invoke ParseFurtherTypes, pName, pTag, eax
    .endif

@Exit:
    mov [ebx].$Obj(IncFile).bInsideClass, FALSE
    Destroy@Stacklist pInherit
    xor eax, eax
    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseTypedefUnionStruct - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    mov [ebx].$Obj(IncFile).bInsideClass, FALSE
    Destroy@Stacklist pInherit
    ret
ParseTypedefUnionStruct endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedef
; Purpose:   typedef occured.
; Arguments: esi -> tokens behind "typedef"
; Return:    Nothing.
; Syntax:    typedef <annotations><qualifiers> type <<far|near> *> newname<[]>;
;            typedef struct/union <macro> <tname> {} name;
;            typedef struct/union <macro> <tname> * name;
;            typedef <annotations><qualifiers> enum <tname> {<annotations>x<=a>,<annotations>y<=b>,...} name;
;            typedef <annotations><qualifiers> returntype (<qualifiers> *name)(<parameters>);
;            typedef <annotations><qualifiers> returntype name(<parameters>);

ParseTypedef proc
    local pToken:PTOKEN, pName:PSTRINGA, pType:PSTRINGA, pDup:PSTRINGA
    local dSquareBracketCount:DWORD, dPtrCount:DWORD, bValid:DWORD, dTypeCSpec:DWORD
    local szTmpType[256]:CHRA, szBuffer[256]:CHRA
    local InpStat:INP_STAT

    DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - begin">, [ebx].$Obj(IncFile).dLineNbr
    mov pType, NULL

@GetNextToken:
    OCall ebx::IncFile.GetNextToken
@ProcessToken:
    .if eax != NULL
      invoke SkipAnnotations, eax
      .if eax != NULL
        invoke TranslateToken, eax
        .if edx == FALSE
          invoke TranslateTypeQualifier, eax
          cmp CHRA ptr [eax], 0
          jz @GetNextToken
        .endif
      .endif
    .endif
    mov pToken, eax
    test eax, eax
    jz @Error

    cmp CHRA ptr [eax], ";"                             ;Statement terminator?
    jz @Error                                           ; Yes => error

    .if CHRA ptr [eax] == "["
      DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - '[' found">, [ebx].$Obj(IncFile).dLineNbr
      OCall ebx::IncFile.SaveInputStatus, addr InpStat
      OCall ebx::IncFile.GetNextToken
      .if eax != NULL
        .if $DoesStringMatchA?([eax], <public>)
          OCall ebx::IncFile.GetNextToken
          .if eax != NULL && CHRA ptr [eax] == "]"
            DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - ']' found">, [ebx].$Obj(IncFile).dLineNbr
            jmp @GetNextToken                                ;Sure????
          .endif
        .endif
      .endif
      OCall ebx::IncFile.LoadInputStatus, addr InpStat
    .endif

    ;syntax: "typedef <macro()> xxx"
    invoke IsMacro?, pToken                             ;Check if it is an already known macro
    .if eax != 0                                        ;0, 1, ...
      DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - macro invocation %s">, [ebx].$Obj(IncFile).dLineNbr, pToken
      .if eax == 1
        OCall g_pMacros::List.ItemAt, ecx
      .else
        OCall g_pKnownMacros::List.ItemAt, ecx
      .endif
      mov edx, [eax - sizeof DWORD]                       ;Get offset to Macro-Attr
      invoke ParseMacroInvocation, pToken, DWORD ptr [eax + edx], TRUE
      test eax, eax                                       ;FALSE if it was not a macro
      jnz @GetNextToken
    .endif

    ;Syntax: "typedef union|struct"?
    invoke IsUnionStructClass?, pToken
    .if eax != 0
      DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - '%s' found">, [ebx].$Obj(IncFile).dLineNbr, pToken
      invoke ParseTypedefUnionStruct, pToken, edx
      xor eax, eax
      jmp @Exit
    .endif

    ;Syntax: "typedef enum"?
    mov eax, pToken
    .if $DoesStringMatchA?([eax], <enum>)
      DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - 'enum' found">, [ebx].$Obj(IncFile).dLineNbr
      invoke ParseTypedefEnum, TRUE
      xor eax, eax
      jmp @Exit
    .endif

    .if pType == NULL
      ;pToken may be a basic C type
      mov eax, pToken
      BasicTypeCScan
      mov pToken, eax                                   ;Last gattered Token
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec
        .if eax == NULL                                 ;If conversion failed
          mov pType, offset szUnkType
        .else
          mov pType, eax
        .endif
        mov eax, pToken
        jmp @ProcessToken                               ;Process the last gattered Token in eax
      .else
        lea ecx, szBuffer
        invoke TranslateReservedWord, eax, ecx
        mov pType, eax
        jmp @GetNextToken
      .endif
    .endif

    ;Get the new Name and write all to the output stream
    mov eax, pToken
    mov dSquareBracketCount, 0
    mov dPtrCount, 0
    mov pName, NULL
    mov pDup, NULL
    .while TRUE
      .if CHRA ptr [eax] == "," || CHRA ptr [eax] == ";"
        .if pName != NULL
          mov bValid, TRUE
          ;Don't add "<newname> typedef <oldname>" entries if <newname> == <oldname>
          .if dPtrCount == 0
            invoke StrCompA, pName, pType
            .if eax == 0
              mov bValid, FALSE
            .endif
          .endif
          .if bValid != FALSE
            invoke TranslateReservedWord, pName, addr szBuffer
            push eax
            .if edx != 0 && g_bWarningLevel > 0
              OCall ebx::IncFile.ShowWarning, $OfsCStrA("reserved word '%s' used as typedef"), pName
            .endif
            pop pName                                   ;Assign translated name
          .endif
          DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - new typedef %s = %s">, [ebx].$Obj(IncFile).dLineNbr, pName, pType

          .if bValid != FALSE
            .if dPtrCount == 0
              IsStructure? pType                        ;If the type is a structure, 
              .if eax != FALSE                          ;  then the new type is it too
                IsStructure? pName                      ;Check if it already exist
                .if eax == FALSE
                  invoke StrSizeA, pName
                  invoke InsertStrg, g_pStructs, pName, eax
                .endif
              .endif
            .endif

            ;If there is an array index, create a 'struct' instead of a 'typedef'!
            .if pDup != NULL && dPtrCount == 0
              OCall ebx::IncFile.StmWrite, pName
              OCall ebx::IncFile.StmWrite, $OfsCStrA(" struct")
              OCall ebx::IncFile.StmWriteEOL
              inc [ebx].$Obj(IncFile).dIndentation
              OCall ebx::IncFile.StmWrite, pType
              OCall ebx::IncFile.StmWriteChar, " "
              OCall ebx::IncFile.StmWrite, pDup
              IsStructure? pType                        ;Check if pType is already a known struct
              .if eax == FALSE
                OCall ebx::IncFile.StmWrite, $OfsCStrA(" dup (?)")
              .else
                OCall ebx::IncFile.StmWrite, $OfsCStrA(" dup (<>)")
              .endif
              OCall ebx::IncFile.StmWriteEOL
              dec [ebx].$Obj(IncFile).dIndentation
              OCall ebx::IncFile.StmWrite, pName
              OCall ebx::IncFile.StmWrite, $OfsCStrA(" ends")
              OCall ebx::IncFile.StmWriteEOL

            .else
              OCall ebx::IncFile.StmWrite, pName
              OCall ebx::IncFile.StmWrite, $OfsCStrA(" typedef ")
              WritePtr
              mov eax, pType
              .if CHRA ptr [eax] == 0
                OCall ebx::IncFile.StmDeleteLastSpace
              .else
                OCall ebx::IncFile.StmWrite, pType
              .endif
              OCall ebx::IncFile.StmWriteEOL

              invoke StrSizeA, pName
              invoke InsertStrg, g_pTypedefs, pName, eax
            .endif
          .endif
        .endif

        mov dPtrCount, 0
        mov pName, NULL
        mov eax, pToken
        .break .if CHRA ptr [eax] == ";"                ;Statement terminator? => exit
      .endif

      .if CHRA ptr [eax] == "("
        invoke IsFunctionPtr?
        .if eax != FALSE
          invoke ParseTypedefFunctionPtr, NULL
        .else
          invoke IsFunction?
          .if eax != FALSE
            mov eax, pName
            test eax, eax
            cmovz eax, pType
            invoke ParseTypedefFunction, eax, FALSE, NULL
          .endif
        .endif
        mov pName, NULL
        test eax, eax
        jnz @Exit

      .elseif CHRA ptr [eax] == "*" && dSquareBracketCount == 0
        inc dPtrCount

      .elseif CHRA ptr [eax] == "["
        DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - '[' found">, [ebx].$Obj(IncFile).dLineNbr
        inc dSquareBracketCount

      .elseif CHRA ptr [eax] == "]"
        DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - ']' found">, [ebx].$Obj(IncFile).dLineNbr
        dec dSquareBracketCount

      .else
        .if dSquareBracketCount != 0
          .if pDup != 0
            push eax
            invoke StrSizeA, eax
            push eax
            invoke StrSizeA, pDup
            pop ecx
            add eax, ecx                                ;length1 + length2 + 2
            MemAlloc eax
            push ebx
            mov ebx, eax
            invoke StrECopyA, ebx, pDup
            push eax
            MemFree pDup
            mov pDup, ebx
            pop ecx
            mov CHRA ptr [ecx], "*"
            inc ecx
            invoke StrCopyA, ecx, [esp + 4]
            pop ebx
            pop eax
          .else
            invoke StrNewA, eax
            mov pDup, eax
          .endif
          DbgPrintF $RGB(0,0,0), <"%u: ParseTypedef - array size '%s' found">, [ebx].$Obj(IncFile).dLineNbr, eax
        .else
          mov pToken, eax
          IsName? eax
          .if eax != FALSE
            mov eax, pToken
            mov pName, eax
          .endif
        .endif
      .endif

      OCall ebx::IncFile.GetNextToken
      test eax, eax                                     ;No more tokens? => error
      jz @Error
      invoke SkipAnnotations, eax
      test eax, eax
      jz @Error                                         ;No more tokens? => error
      mov pToken, eax
    .endw

@Exit:
    ret

@Error:
    .if eax != NULL
      OCall ebx::IncFile.ShowError, $OfsCStrA("unexpected item '%s' in typedef [%u]"), pToken, eax
    .endif
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseTypedef - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    ret
ParseTypedef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseExtern
; Purpose:   Parse extern.
; Arguments: None.
; Return:    Nothing.

ParseExtern proc
    local pToken:PTOKEN

    .while TRUE
      OCall ebx::IncFile.GetNextToken
      .break .if eax == NULL
      .break .if CHRA ptr [eax] == ";"                  ;Statement terminator
      mov pToken, eax
      .if DWORD ptr [eax] == ',"C"' && DCHRA ptr [eax + sizeof DWORD] == "0"
        OCall ebx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C", 22h)      ;"   C linkage
        OCall ebx::IncFile.StmWriteEOL
        mov [ebx].$Obj(IncFile).bExternC, TRUE
        .break
      .elseif DWORD ptr [eax] == '++C"' && DWORD ptr [eax + 4] == '0,"'
        OCall ebx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C++", 22h)    ;"   C++ linkage
        OCall ebx::IncFile.StmWriteEOL
        .break
      .endif
      OCall ebx::IncFile.StmWrite, $OfsCStrA("externdef ")
      .if [ebx].$Obj(IncFile).bExternC != FALSE
        OCall ebx::IncFile.StmWrite, $OfsCStrA("c ")
      .endif
      invoke ParseExternItem, pToken
      .break
    .endw

    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseExtern - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    ret
ParseExtern endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParsePrototype
; Purpose:   Parse a function prototype.
; Arguments: Arg1 -> Function name.
;            Arg2 -> Import specification (for example WINOLEAPI). Can be NULL.
;            Arg3 -> Call convention (for example WINAPI). Can be NULL.
; Return:    Nothing.
; Link:      https://msdn.microsoft.com/en-us/library/zw3za17w.aspx
; Format:    [Annotation] [Import-Spec] return-type [Call-Conv] Function-Name[(Argument-List)]

ParsePrototype proc pProcName:PSTRINGA, pImportSpec:PSTRINGA, pCallConv:PSTRINGA
    local pName:PSTRINGA, pToken:PTOKEN, pPrefix:PSTRINGA, pCallConvStr:PSTRINGA
    local bFunctionPtr:DWORD, dPtrCount:DWORD, dParenthesisCount:DWORD, dParamBytes:DWORD
    local InpStat:INP_STAT, szSuffix[8]:CHRA, szBuffer[512]:CHRA
    local dTypeCSpec:DWORD, pType:PSTRINGA

    ;Parse function header ----------------------------------------------------
    invoke GetCallConvString, [ebx].$Obj(IncFile).dQualifiers
    mov pCallConvStr, eax

    DbgPrintF $RGB(0,0,0), <"%u: ParsePrototype - name = '%s', pImportSpec = %s">, [ebx].$Obj(IncFile).dLineNbr, pProcName, pImportSpec
    .if g_bUse@DefProto != FALSE && pImportSpec != NULL
    .else
      .if g_bAssumeDllImport != FALSE
        or [ebx].$Obj(IncFile).dQualifiers, PTQ_IMPORT
      .elseif g_bIgnoreDllImport != FALSE
        and [ebx].$Obj(IncFile).dQualifiers, not PTQ_IMPORT
      .endif
    .endif

    .if g_bUse@DefProto != FALSE && pImportSpec != NULL
      invoke IsReservedWord?, pProcName
      .if eax != FALSE
        OCall ebx::IncFile.ShowWarning, $OfsCStrA("reserved word '%s' used as prototype"), pProcName
        mov eax, offset szResWordSuffix
      .else
        mov eax, NULL
      .endif
      push eax
      OCall ebx::IncFile.StmWriteF, $OfsCStrA("@DefProto %s, %s, %s,"), pImportSpec, pProcName, pCallConvStr
      pop eax
      .if eax != NULL
        OCall ebx::IncFile.StmWriteF, $OfsCStrA(" %s"), eax    ;ProcName suffix
      .endif
      OCall ebx::IncFile.StmWrite, $OfsCStrA(", ", 3Ch)  ;", <"
    .else
      .if ([ebx].$Obj(IncFile).dQualifiers & PTQ_IMPORT)
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("TYPE_%s typedef proto %s"), pProcName, eax
      .else
        invoke TranslateReservedWord, pProcName, NULL
        .if ecx != offset szEmpty
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s proto %s"), eax, pCallConvStr
        .else
          OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s proto"), eax
        .endif
      .endif
    .endif

    ;Parse function parameters ------------------------------------------------
    mov [ebx].$Obj(IncFile).pPrevToken, NULL
    mov pType, NULL
    mov pName, NULL
    mov bFunctionPtr, FALSE
    mov dPtrCount, 0
    mov dParamBytes, 0
    mov dParenthesisCount, 1
    .while dParenthesisCount != 0
      OCall ebx::IncFile.GetNextToken
@ProcessToken:
      .break .if eax == NULL || CHRA ptr [eax] == ";"   ;Statement terminator
      invoke SkipAnnotations, eax
      .break .if eax == NULL

      .if CHRA ptr [eax] == "," || CHRA ptr [eax] == ")"
        mov pToken, eax
        .if pType != NULL || dPtrCount != 0
          mov eax, pType
          .if eax == NULL && dPtrCount != 0
            mov eax, offset szEmpty                     ;Make sure it is a valid PSTRINGA
          .else
            .if dPtrCount == 0 && pName == NULL
              .break .if $DoesStringMatchA?([eax], <void>)
              .break .if $DoesStringMatchA?([eax], <VOID>)
            .endif
          .endif
                                                        ;Don't interpret xxx(void) as parameter
          .if dPtrCount != 0 || CHRA ptr [eax] != 0
            .if dParamBytes != 0 || g_bUse@DefProto == FALSE || pImportSpec == NULL
              OCall ebx::IncFile.StmWrite, offset szSpace
            .endif
            OCall ebx::IncFile.StmWrite, offset szColon
            .if dPtrCount != 0
              mov eax, sizeof DWORD                     ;Size of a 32 bit POINTER
            .else
              ;Get type sizes (for structures used as parameters). Only relevant for 32 bit!
              OCall g_pTypeSize::List.Search, pType
              .if eax != FALSE
                OCall g_pTypeSize::List.ItemAt, ecx
                mov edx, [eax - sizeof DWORD]
                mov eax, [eax + edx]
              .else
                mov eax, sizeof DWORD                   ;Default for 32 bit!
              .endif
            .endif
            add dParamBytes, eax
          .endif
          WritePtr                                      ;on exit, dPtrCount = 0
          mov eax, pType
          .if eax != NULL && CHRA ptr [eax] != 0
            OCall ebx::IncFile.StmWrite, pType
          .else
            OCall ebx::IncFile.StmDeleteLastSpace
          .endif
          mov pType, NULL
          mov pName, NULL
          mov bFunctionPtr, FALSE
        .endif

        mov eax, pToken
        .if CHRA ptr [eax] == ")"
          dec dParenthesisCount
        .else
          OCall ebx::IncFile.StmWrite, eax
        .endif

      .elseif CHRA ptr [eax] == "*" || CHRA ptr [eax] == "&"
        inc dPtrCount

      .elseif CHRA ptr [eax] == "["
        inc dPtrCount
        .repeat
          OCall ebx::IncFile.GetNextToken
        .until eax == NULL || CHRA ptr [eax] == "]" || CHRA ptr [eax] == ";"

      .elseif CHRA ptr [eax] == "("
        ;Function ptr as function parameter?
        invoke IsFunctionPtr?
        .if eax != FALSE
;          push [ebx].$Obj(IncFile).pStmOutPos
;          push [ebx].$Obj(IncFile).bStmOutEOL
;          invoke ParseTypedefFunctionPtr, NULL
;          pop [ebx].$Obj(IncFile).bStmOutEOL
;          pop [ebx].$Obj(IncFile).pStmOutPos
          ;Alternative code without explicit declaration of the Function pointer
          invoke SkipBraces, "(", ")"
          OCall ebx::IncFile.GetNextToken
          invoke SkipBraces, "(", ")"
          mov dPtrCount, TRUE
          mov pName, NULL
          mov pType, NULL
        .else
          inc dParenthesisCount
        .endif

      .else
        invoke TranslateTypeQualifier, eax
        .continue .if CHRA ptr [eax] == 0
        .continue .if $DoesStringMatchA?([eax], <struct>) ;Ignore 'struct'
        .continue .if $DoesStringMatchA?([eax], <union>)  ;Ignore 'union'
        .continue .if $DoesStringMatchA?([eax], <enum>)   ;Ignore 'enum'

        .if $DoesStringMatchA?([eax], <...>)
          mov pType, $OfsCStrA("vararg")
          mov pName, offset szEmpty
          .continue
        .endif

        ;pToken may be a basic C type
        mov pToken, eax
        .if pType == NULL
          BasicTypeCScan
          mov pToken, eax
          .if dTypeCSpec != 0
            invoke ConvBasicTypeC, dTypeCSpec
            .if eax == NULL                             ;If conversion failed
              mov pType, offset szUnkType
            .else
              mov pType, eax
              mov eax, pToken
              jmp @ProcessToken
            .endif
            mov eax, pToken
          .endif
        .endif

        lea ecx, szBuffer
        invoke TranslateReservedWord, eax, ecx
        .if pType == NULL
          mov pType, eax
        .elseif pName == NULL
          mov pName, eax
        .endif
      .endif
    .endw

    .if g_bUse@DefProto != FALSE && pImportSpec != NULL
      OCall ebx::IncFile.StmWriteChar, 3Eh              ;">"
      mov eax, pCallConvStr
      .if CHRA ptr [eax] != "c"                         ;cdecl doesn't need decoration suffix
        OCall ebx::IncFile.StmWriteF, $OfsCStrA(", %u"), dParamBytes
      .endif
    .endif
    OCall ebx::IncFile.StmWriteEOL

    .if !(g_bUse@DefProto != FALSE && pImportSpec != NULL)
      .ifBitSet [ebx].$Obj(IncFile).dQualifiers, PTQ_IMPORT
        .if ([ebx].$Obj(IncFile).dQualifiers & PTQ_STDCALL)
          mov pPrefix, offset szUnderscore
          invoke sprintf, addr szSuffix, $OfsCStrA("@%u"), dParamBytes
        .elseif ([ebx].$Obj(IncFile).dQualifiers & PTQ_CDECL)
          mov pPrefix, offset szUnderscore
          mov szSuffix, 0
        .else
          mov pPrefix, offset szEmpty
          mov szSuffix, 0
        .endif

        OCall ebx::IncFile.StmWriteF, $OfsCStrA("externdef stdcall _imp_%s%s%s: ptr proto_%s"), \
                                      pPrefix, pProcName, addr szSuffix, pProcName
        OCall ebx::IncFile.StmWriteEOL
        invoke TranslateReservedWord, pProcName, NULL
        mov ecx, eax
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s equ ", 3Ch, "_imp_%s%s%s", 3Eh), \     ;"<" ">"
                                      ecx, pPrefix, pProcName, addr szSuffix
        OCall ebx::IncFile.StmWriteEOL
      .endif
    .endif
    invoke StrSizeA, pProcName
    invoke InsertStrg, g_pPrototypes, pProcName, eax

    .if g_bCreateDefs != FALSE
      invoke InsertDefItem, pProcName, dParamBytes
    .endif
    .ifBitSet [ebx].$Obj(IncFile).dQualifiers, PTQ_INLINE
      ;Skip inline C-code block
      OCall ebx::IncFile.SaveInputStatus, addr InpStat
      OCall ebx::IncFile.GetNextToken
      .if eax != NULL && CHRA ptr [eax] == "{"
        invoke SkipBraces, "{", "}"
      .else
        OCall ebx::IncFile.LoadInputStatus, addr InpStat
      .endif
    .endif

@Exit:
    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParsePrototype - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    ret
ParsePrototype endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseMacroInvocation
; Purpose:   A known macro has been found.
; Arguments: Arg1 -> Macro Name
;            Arg2: Macro Flags (MCF_xxx).
;            Arg3: Flag to write LF after macro invocation.
; Return:    eax = returns TRUE if macro was invoked, otherwise FALSE (turned out to be
;            NO macro invocation).

ParseMacroInvocation proc pMacroName:PSTRINGA, dMacroFlags:DWORD, bWriteLF:DWORD
    local pToken:PTOKEN, pType:PSTRINGA, pName:PSTRINGA, pStmOutPos:PSTRINGA, bAddSpace:DWORD
    local dPtrCount:DWORD, dParenthesesCount:DWORD, bSkipTheRest:DWORd
    local dTypeCSpec:DWORD, dScanStep:DWORD, pArgStack:POINTER

    m2m pStmOutPos, [ebx].$Obj(IncFile).pStmOutPos, eax

    DbgPrintF $RGB(0,0,0), <"%u: ParseMacroInvocation - found: %s">, \
              [ebx].$Obj(IncFile).dLineNbr, pMacroName

    .ifBitSet dMacroFlags, MCF_SKIP_INVOKATION
      OCall ebx::IncFile.PeekNextToken
      .if eax != NULL
        .if CHRA ptr [eax] == "("
          OCall ebx::IncFile.GetNextToken                 ;Consume it
          invoke SkipBraces, "(", ")"
        .endif
      .endif
      mov eax, TRUE
      ret
    .endif

    mov pArgStack, $Create@Stacklist()

    .ifBitSet dMacroFlags, MCF_INTERFACE_END
      OCall ebx::IncFile.StmWriteF, $OfsCStrA("??Interface equ <>")  ;Reset ??Interface symbol
      OCall ebx::IncFile.StmWriteEOL
      mov [ebx].$Obj(IncFile).bInsideInterface, FALSE
    .endif

    OCall ebx::IncFile.PeekNextToken
    .if eax != NULL && CHRA ptr [eax] == "("
      OCall ebx::IncFile.StmWrite, pMacroName
      OCall ebx::IncFile.GetNextToken                   ;Can NOT fail, we peeked a token previously
      .ifBitClr dMacroFlags, MCF_SKIP_BRACES
        OCall ebx::IncFile.StmWrite, eax
      .else
        OCall ebx::IncFile.StmWriteChar, " "
      .endif
      mov dParenthesesCount, 1
      mov bAddSpace, FALSE
      .while TRUE
        OCall ebx::IncFile.GetNextToken
        .break .if eax == NULL
        Add@Stacklist pArgStack, eax
        .if CHRA ptr [eax] == "("
          inc dParenthesesCount
          mov bAddSpace, FALSE
        .elseif CHRA ptr [eax] == ")"
          dec dParenthesesCount
          mov bAddSpace, TRUE
          .break .if dParenthesesCount == 0
        .else
          .if CHRA ptr [eax] != ","
            push eax
            .if bAddSpace != FALSE
              OCall ebx::IncFile.StmWriteChar, " "
            .endif
            pop eax
            .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
              invoke TranslateReservedWord, eax, NULL   ;Arguments can not be reserved words
            .endif
            invoke TranslateNumOperator, eax
            DbgPrintF $RGB(0,0,0), <"%u: ParseMacroInvocation - Parameter = %s">, [ebx].$Obj(IncFile).dLineNbr, eax
            mov bAddSpace, TRUE
          .endif
        .endif
        OCall ebx::IncFile.StmWrite, eax
      .endw

      .ifBitClr dMacroFlags, MCF_SKIP_BRACES
        OCall ebx::IncFile.StmWriteChar, 29h            ;")"
      .endif

      ;Up to now we processed MacroName(...). Now comes the rest of the line.
      .ifBitSet dMacroFlags, MCF_COPY_LINE              ;Rest of line belongs to macro invocation
        mov pType, NULL
        mov pName, NULL
        mov dPtrCount, 0
        mov dTypeCSpec, 0
        mov dScanStep, 0
        mov bSkipTheRest, FALSE
        .while TRUE
          .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
            OCall ebx::IncFile.GetNextToken
            .break .if eax == NULL || CHRA ptr [eax] == ";"     ;Statement terminator
          .else
            OCall ebx::IncFile.GetNextTokenFromPPLine
            .break .if eax == NULL
          .endif
          .continue .if bSkipTheRest != FALSE

@ProcessToken:
          .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
            invoke SkipAnnotations, eax
            .if CHRA ptr [eax] == ")" || CHRA ptr [eax] == ","
              push eax
              mov eax, pType
              test eax, eax
              cmovz eax, pName
              .if eax != NULL
                DbgPrintF $RGB(0,0,0), <"%u: ParseMacroInvocation - Param = %s">, [ebx].$Obj(IncFile).dLineNbr, eax
                push eax
                OCall ebx::IncFile.StmWrite, $OfsCStrA(", :")
                WritePtr
                pop eax
                movzx ecx, g_bUntypedParams
                invoke TranslateType, eax, ecx
                OCall ebx::IncFile.StmWrite, eax
              .endif
              mov pType, NULL
              mov pName, NULL
              mov dPtrCount, 0
              mov dTypeCSpec, 0
              mov dScanStep, 0
              pop eax
              .continue .if CHRA ptr [eax] == ","
            .endif
            .if CHRA ptr [eax] == "("
              inc dParenthesesCount
              .continue
            .endif
            .if CHRA ptr [eax] == ")"
              dec dParenthesesCount
              .continue
            .endif
            .if CHRA ptr [eax] == "*"
              inc dPtrCount
              .continue
            .endif
            .if CHRA ptr [eax] == "["
              inc dPtrCount
              invoke SkipBraces, "[", "]"
              test eax, eax
              jz @Exit
              .continue
            .endif
            .if CHRA ptr [eax] == "="
              mov bSkipTheRest, TRUE
              .continue
            .endif
            
            mov ecx, [eax]
            or ecx, 20202020h                           ;Convert to lowercase
            .if ecx == "siht"
              mov cx, [eax + 4]
              .continue .if cx == "_" || cl == 0        ;Skip THIS and THIS_
            .endif

            invoke TranslateTypeQualifier, eax
            .continue .if CHRA ptr [eax] == 0
            mov pToken, eax

            .if pType == NULL
              BasicTypeCScan
              mov pToken, eax
              .if dTypeCSpec != 0
                invoke ConvBasicTypeC, dTypeCSpec
                .if eax == NULL
                  mov pType, offset szUnkType
                .else
                  mov pType, eax
                .endif
                mov eax, pToken
                jmp @ProcessToken
              .endif
            .endif

            mov eax, pToken
            .if pType == NULL
              mov pType, eax
              .continue
            .endif
            .if pName == NULL
              mov pName, eax
              .continue
            .endif
            jmp @Error
          .endif
          OCall ebx::IncFile.StmWrite, eax
        .endw
      .endif
    .else
      .ifBitClr dMacroFlags, MCF_HAS_PARAMS
        OCall ebx::IncFile.StmWrite, pMacroName
      .else
        xor eax, eax                                    ;It wasn't a macro or some error happend
        jmp @Exit
      .endif
    .endif
    .ifBitSet dMacroFlags, MCF_END_MACRO
      mov eax, pMacroName
      mov [ebx].$Obj(IncFile).pEndMacro, eax
      mov eax, [ebx].$Obj(IncFile).dBraces
      mov [ebx].$Obj(IncFile).dBlockLevel, eax
    .endif

@Done:
    .if bWriteLF != FALSE
      OCall ebx::IncFile.StmWriteEOL
    .endif
    .ifBitSet dMacroFlags, MCF_INTERFACE_BEG
      .if [ebx].$Obj(IncFile).pStructName != NULL
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("??Interface equ <%s>"), [ebx].$Obj(IncFile).pStructName
        OCall ebx::IncFile.StmWriteEOL
        mov [ebx].$Obj(IncFile).bInsideInterface, TRUE
      .endif
    .endif
    .if g_bConstants == FALSE
      mrm [ebx].$Obj(IncFile).pStmOutPos, pStmOutPos, ecx
      mov CHRA ptr [ecx], 0
    .endif

    .ifBitSet dMacroFlags, MCF_STRUCT_BEG
      inc [ebx].$Obj(IncFile).dIndentation
      OCall ebx::IncFile.GetNextToken
      .if CHRA ptr [eax] == "{"
        mov ecx, $GetItem@Stacklist(pArgStack, 0)
;        invoke ParseBlock, ecx, PBT_MEM_LAYOUT
        invoke ParseInterfaceBlock, ecx
        dec [ebx].$Obj(IncFile).dIndentation
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("END_%s"), pMacroName
        OCall ebx::IncFile.StmWriteEOL
      .else
        jmp @Error
      .endif
    .endif
    mov eax, TRUE

@Exit:
    Destroy@Stacklist pArgStack
    ret

@Error:
    DbgErrorF $RGB(255,0,0), <"%s(%u): ParseMacroInvocation - error">, \
              [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    Destroy@Stacklist pArgStack
    xor eax, eax
    ret
ParseMacroInvocation endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseC
; Purpose:   The following types of declarations are known:
;              1. typedef (struct, enum)
;              2. extern
;              3. prototypes
; Arguments: None.
; Return:    eax = TRUE if succeeded, otherwise FALSE.
; Links:     http://www.inf.fu-berlin.de/lehre/WS11/OS/slides/OS_Declarations_in_C_.pdf
;            https://en.wikipedia.org/wiki/C_syntax
;            https://msdn.microsoft.com/en-us/library/bz4heb45.aspx

ParseC proc
    local pToken:PTOKEN, bNextParm:DWORD, bInsideClass:DWORD, bAddSpace:DWORD

    OCall ebx::IncFile.GetNextToken
    .if eax == NULL
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - EOF reached">, [ebx].$Obj(IncFile).dLineNbr
      ret
    .endif
    mov pToken, eax

    OCall ebx::IncFile.StmWriteComment
    .if eax != FALSE
      OCall ebx::IncFile.StmWriteEOL
    .endif

    mov eax, pToken
    .if CHRA ptr [eax] == ";"                           ;Statement terminator => reset all
      mov [ebx].$Obj(IncFile).pPrevToken, NULL
      mov [ebx].$Obj(IncFile).pImportSpec, NULL
      mov [ebx].$Obj(IncFile).pCallConv, NULL
      mov [ebx].$Obj(IncFile).dQualifiers, 0
      jmp @Exit
    .endif

    ;Check annotation ---------------------------------------------------------
    invoke SkipAnnotations, pToken
    test eax, eax
    jz @Exit

    invoke TranslateToken, eax
    mov pToken, eax

    ;'typedef' test -----------------------------------------------------------
    .if $DoesStringMatchA?([eax], <typedef>)
      push [ebx].$Obj(IncFile).pStmOutPos
      push [ebx].$Obj(IncFile).bStmOutEOL
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - 'typedef' found">, [ebx].$Obj(IncFile).dLineNbr
      invoke ParseTypedef
      pop edx
      pop ecx
      .if g_bTypedefs == FALSE
        mov [ebx].$Obj(IncFile).pStmOutPos, ecx
        mov [ebx].$Obj(IncFile).bStmOutEOL, edx
        mov CHRA ptr [ecx], 0
      .endif
      jmp @Exit
    .endif

    ;'union', 'struct', 'class' test ------------------------------------------
    ;'struct' may be a struct declaration, but may be a function returning a struct as well
    invoke IsUnionStructClass?, pToken                  ;edx = TRUE if class detected
    .if eax != FALSE
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - 'union/struct/class' found">, [ebx].$Obj(IncFile).dLineNbr
      push edx
      invoke IsFunction?
      pop edx
      .if eax == FALSE
        push [ebx].$Obj(IncFile).pStmOutPos
        push [ebx].$Obj(IncFile).bStmOutEOL
        invoke ParseTypedefUnionStruct, pToken, edx
        pop edx
        pop ecx
        .if g_bTypedefs == FALSE
          mov [ebx].$Obj(IncFile).pStmOutPos, ecx
          mov [ebx].$Obj(IncFile).bStmOutEOL, edx
          mov CHRA ptr [ecx], 0
        .endif
        jmp @Exit
      .endif
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - 'union/struct' ignored (function return type)">, \
                [ebx].$Obj(IncFile).dLineNbr
    .endif

    ;'extern' test ------------------------------------------------------------
    mov eax, pToken
    .if $DoesStringMatchA?([eax], <extern>)
      invoke IsFunction?                                ;In case of an extern function, ignore
      .if eax == FALSE                                  ;'extern' and continue parsing as a proto
        push [ebx].$Obj(IncFile).pStmOutPos
        push [ebx].$Obj(IncFile).bStmOutEOL
        DbgPrintF $RGB(0,0,0), <"%u: ParseC - 'extern' found">, [ebx].$Obj(IncFile).dLineNbr
        invoke ParseExtern
        pop edx
        pop ecx
        .if g_bExternals == FALSE
          mov [ebx].$Obj(IncFile).pStmOutPos, ecx
          mov [ebx].$Obj(IncFile).bStmOutEOL, edx
          mov CHRA ptr [ecx], 0
        .endif
      .endif
      jmp @Exit
    .endif

    ;'enum' test --------------------------------------------------------------
    invoke StrICompA, offset szEnum, pToken             ;Upper- and lowercase!
    .if eax == 0
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - 'enum' found">, [ebx].$Obj(IncFile).dLineNbr
      invoke ParseTypedefEnum, FALSE
      jmp @Exit
    .endif

    ;Check qualifier ----------------------------------------------------------

    ;First check if name is a known prototype qualifier.
    ;This may also be a macro. In that case, no macro invocation should be generated.

    invoke GetProtoQualifier, pToken
    .if eax != NULL
      mov edx, [eax - sizeof DWORD]
      mov ecx, [eax + edx]
      push ecx
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - prototype qualifier '%s' found, value = %X">, \
                [ebx].$Obj(IncFile).dLineNbr, pToken, ecx
      invoke IsMacro?, pToken
      .if eax != 0
        ;OK, it is a macro, check for args in parenthesis
        OCall ebx::IncFile.PeekNextToken
        .if CHRA ptr [eax] == "("
          push esi
          push edi
          mov bAddSpace, FALSE
          invoke StrECopy, offset g_szMacroBuffer, pToken   ;macro name
          mov edi, eax
          OCall ebx::IncFile.GetNextToken               ;"("
          invoke StrECopy, edi, eax
          mov edi, eax
          mov esi, 1
          .repeat
            OCall ebx::IncFile.GetNextToken
            invoke SkipAnnotations, eax
            .break .if eax == NULL
            push eax
            .if CHRA ptr [eax] == "("
              inc esi
              mov bAddSpace, FALSE
            .elseif CHRA ptr [eax] == ")"
              dec esi
              mov bAddSpace, TRUE
            .else
              .if bAddSpace != FALSE
                invoke StrECopy, edi, offset szSpace
                mov edi, eax
              .endif
              mov bAddSpace, TRUE
            .endif
            pop ecx
            invoke StrECopy, edi, ecx
            mov edi, eax
          .until esi == 0
          pop edi
          pop esi
          lea eax, g_szMacroBuffer
        .else
          mov eax, pToken
        .endif
      .else
        mov eax, pToken
      .endif
      pop ecx

      .ifBitSet ecx, PTQ_IMPORT
        mov [ebx].$Obj(IncFile).pImportSpec, offset szDllImport
      .endif
      .ifBitSet ecx, (PTQ_STDCALL or PTQ_CDECL or PTQ_SYSCALL or PTQ_PASCAL or \
                      PTQ_FASTCALL or PTQ_VECTORCALL)
        mov [ebx].$Obj(IncFile).pCallConv, eax
      .endif
      or [ebx].$Obj(IncFile).dQualifiers, ecx
      jmp @Exit
    .endif

    ;Check for macro invocation -----------------------------------------------
    .if [ebx].$Obj(IncFile).dQualifiers == 0                  ;No previous qualifiers => it is a macro invocation
      invoke IsMacro?, pToken
      .if eax != 0
        .if eax == 1
          OCall g_pMacros::List.ItemAt, ecx
        .else
          OCall g_pKnownMacros::List.ItemAt, ecx
        .endif
        mov edx, [eax - sizeof DWORD]
        invoke ParseMacroInvocation, pToken, DWORD ptr [eax + edx], TRUE
        .if eax != FALSE
          jmp @Exit
        .endif
      .endif
    .endif

    ;Check known types --------------------------------------------------------
    .if [ebx].$Obj(IncFile).dQualifiers == 0                  ;No previous qualifiers!
      OCall g_pTypedefs::List.Search, pToken
      .if eax != 0
        jmp @Exit
      .endif
    .endif

    ;Check for prototypes -----------------------------------------------------
    mov eax, pToken
    .if CHRA ptr [eax] == "("
      .if [ebx].$Obj(IncFile).pPrevToken != NULL
        DbgPrintF $RGB(0,0,0), <"%u: ParseC - prototype found">, [ebx].$Obj(IncFile).dLineNbr
        push [ebx].$Obj(IncFile).pStmOutPos
        push [ebx].$Obj(IncFile).bStmOutEOL
        invoke ParsePrototype, [ebx].$Obj(IncFile).pPrevToken, [ebx].$Obj(IncFile).pImportSpec, [ebx].$Obj(IncFile).pCallConv
        pop edx
        pop ecx
        .if g_bPrototypes == FALSE
          mov [ebx].$Obj(IncFile).pStmOutPos, ecx
          mov [ebx].$Obj(IncFile).bStmOutEOL, edx
          mov CHRA ptr [ecx], 0
        .endif
        mov [ebx].$Obj(IncFile).dQualifiers, 0
        jmp @Exit
      .endif
    .endif

    ;Check for names ----------------------------------------------------------
    IsName? pToken
    .if eax != FALSE
      mov eax, pToken
      mov [ebx].$Obj(IncFile).pPrevToken, eax
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - token '%s' found">, [ebx].$Obj(IncFile).dLineNbr, eax
      jmp @Exit
    .endif

    ;Check block  -------------------------------------------------------------
    mov eax, pToken
    .if CHRA ptr [eax] == "{"
      inc [ebx].$Obj(IncFile).dBraces
;      mov eax, [ebx].$Obj(IncFile).pStmOutPos
;      .if CHRA ptr [eax - 1] == LF
;        OCall ebx::IncFile.StmWrite, $OfsCStrA(";{")
;        OCall ebx::IncFile.StmWriteEOL
;      .endif
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - begin block, new level = %u">, \
                [ebx].$Obj(IncFile).dLineNbr, [ebx].$Obj(IncFile).dBraces
    .elseif CHRA ptr [eax] == "}"
      dec [ebx].$Obj(IncFile).dBraces
;      mov eax, [ebx].$Obj(IncFile).pStmOutPos
;      .if CHRA ptr [eax - 1] == LF
;        OCall ebx::IncFile.StmWrite, $OfsCStrA(";}")
;        OCall ebx::IncFile.StmWriteEOL
;      .endif
      DbgPrintF $RGB(0,0,0), <"%u: ParseC - end block, new level = %u">, \
                [ebx].$Obj(IncFile).dLineNbr, [ebx].$Obj(IncFile).dBraces
      mov eax, [ebx].$Obj(IncFile).dBraces
      .if [ebx].$Obj(IncFile).pEndMacro != NULL && eax == [ebx].$Obj(IncFile).dBlockLevel
        OCall ebx::IncFile.StmWriteF, $OfsCStrA("%s_END", LF), [ebx].$Obj(IncFile).pEndMacro
        OCall ebx::IncFile.StmWriteEOL
        mov [ebx].$Obj(IncFile).dBlockLevel, 0
        mov [ebx].$Obj(IncFile).pEndMacro, NULL
      .endif
    .endif

@Exit:
    OCall ebx::IncFile.StmWriteComment
    .if eax != FALSE
      OCall ebx::IncFile.StmWriteEOL
    .endif
    mov eax, TRUE
    ret
ParseC endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParsePP
; Purpose:   Parse PreProcessor lines.
; Arguments: None.
; Return:    Nothing.

ParsePP proc uses esi edi
    local pToken:PTOKEN

    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax != NULL
      mov pToken, eax
      DbgPrintF $RGB(0,0,0), <"%u: ParsePP - PP-Command '%s' found">, [ebx].$Obj(IncFile).dLineNbr, pToken

      .if [ebx].$Obj(IncFile).bSkipScanPP == 0
        ;Find and execute the matching handler for the input Token ------------
        mov eax, pToken
        .if [ebx].$Obj(IncFile).bSkipLogiPP == FALSE
          mov edi, offset PreProcCmdHandlerTab
          .if [ebx].$Obj(IncFile).bStmOutEOL == FALSE
            OCall ebx::IncFile.StmWriteEOL
          .endif
        .else
          mov edi, offset PreProcCmdNPHandlerTab
        .endif

        .while [edi].PP_CMD_HANDLER_ENTRY.pCmd != NULL
          invoke BStrCompA, [edi].PP_CMD_HANDLER_ENTRY.pCmd, pToken
          .if eax == 0
            call [edi].PP_CMD_HANDLER_ENTRY.pHandler
            jmp @F
          .endif
          add edi, sizeof PP_CMD_HANDLER_ENTRY
        .endw

        ;If no handler found
        .if [ebx].$Obj(IncFile).bSkipScanPP != 0 || [ebx].$Obj(IncFile).bSkipLogiPP == TRUE
          SkipPPLine
        .else
          OCall ebx::IncFile.StmWriteF, $OfsCStrA(";#%s "), pToken
          OCall ebx::IncFile.StmCopyRestOfPPLine
        .endif
      .else
        SkipPPLine
      .endif
@@:
      ;Consume C-Tokens until the next PP-Line is found -----------------------
      .if [ebx].$Obj(IncFile).bSkipC != FALSE
        mov edi, [ebx].$Obj(IncFile).pStmInpPos
@@:
        .while CHRA ptr [edi] != '#'                        ;Always a single character
          .if DCHRA ptr [edi] == PCT_EOL || DCHRA ptr [edi] == PCT_WEAKEOL
            inc [ebx].$Obj(IncFile).dLineNbr
          .endif
          mov ecx, -1
          mov al, 0
          repnz scasb
          not ecx
          dec ecx                                           ;ecx = character count
          jz @Exit
        .endw
        .if [ebx].$Obj(IncFile).bSkipUselessCode == FALSE
          OCall ebx::IncFile.StmWrite, $OfsCStrA(";[...]")  ;Visualize that we skipped some lines
          OCall ebx::IncFile.StmWriteEOL
          mov [ebx].$Obj(IncFile).bSkipUselessCode, TRUE
        .endif
        mov [ebx].$Obj(IncFile).pStmInpPos, edi
      .endif
    .endif
@Exit:
    ret
ParsePP endp
