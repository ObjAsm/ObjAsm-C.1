; ==================================================================================================
; Title:    h2incX_Handler.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm h2incX Handler routines.
; Notes:    See h2incX.asm
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Define
; Purpose:   PP Command Handler for "#define".
; Arguments: esi -> input token stream.
; Return:    Nothing.
; Note:      If a macro is defined and an argument name is a reseved word, it is converted. In the
;            following exitm, only reserved words are converted that were converted previously.

PPCH_Define proc uses edi esi
    local pName:PSTRINGA, pParm:PSTRINGA, pToken:PTOKEN, pThis:PTOKEN, pCObject:POINTER
    local dParams:DWORD, bMacro:DWORD, bAddSpace:DWORD, pArgStack:POINTER, bFirstParam:DWORD
    local szInterface[128]:CHRA, szMethod[128]:CHRA, pStmOutPos:POINTER

    m2m pStmOutPos, [ebx].$Obj(IncFile).pStmOutPos, eax
    mov pCObject, NULL

    OCall ebx::IncFile.GetNextTokenFromPPLine           ;get the name of constant/macro
    .if eax != NULL
      mov pName, eax
      invoke TranslateReservedWord, pName, NULL
      OCall ebx::IncFile.StmWrite, eax
      mov eax, [ebx].$Obj(IncFile).pStmInpPos
      .if WORD ptr [eax] == PCT_MACRO
        mov bMacro, TRUE
      .else
        mov bMacro, FALSE
      .endif
      .if bMacro != FALSE
        OCall ebx::IncFile.GetNextTokenFromPPLine       ;skip PCT_MACRO
        OCall ebx::IncFile.GetNextTokenFromPPLine       ;skip "("
        OCall ebx::IncFile.StmWrite, $OfsCStrA(" macro ")

        ;Write the macro params
        invoke SkipSimpleBraces

        mov pArgStack, $Create@Stacklist()
        mov dParams, 0
        .while TRUE
          OCall ebx::IncFile.GetNextTokenFromPPLine
          .break .if eax == NULL
          .break .if CHRA ptr [eax] == ")"
          mov pToken, eax
          .if CHRA ptr [eax] == ","
            mov eax, $OfsCStrA(", ")
          .else
            inc dParams
            invoke TranslateReservedWord, eax, NULL
            .if edx != 0
              ;Translation occurred
              Add@Stacklist pArgStack, pToken           ;Does NOT change eax
            .endif
          .endif
          OCall ebx::IncFile.StmWrite, eax
        .endw
        OCall ebx::IncFile.StmWriteEOL

        ;Save macro name in symbol table
        invoke IsMacro?, pName                          ;Check if we know this macro
        .if eax == 0
          invoke StrSizeA, pName
          .if dParams > 0
            mov ecx, MCF_HAS_PARAMS
          .else
            xor ecx, ecx
          .endif
          invoke InsertAttr, g_pMacros, pName, eax, ecx
        .endif

        OCall ebx::IncFile.StmWrite, $OfsCStrA("  exitm ", 3Ch)   ;"  exitm <", incl. 2 spc 4 indent.
        invoke SkipCasts

        mov bAddSpace, TRUE
        mov bFirstParam, TRUE
        .while TRUE
          OCall ebx::IncFile.GetNextTokenFromPPLine
          .break .if eax == NULL
          mov esi, eax
          .continue .if pCObject != NULL && CHRA ptr [esi] == ")"
          .if bFirstParam == FALSE && CHRA ptr [esi] != ")" && CHRA ptr [esi] != "," && bAddSpace != FALSE && CHRA ptr [eax] != "."
            OCall ebx::IncFile.StmWriteChar, " "
          .endif
          invoke IsMacro?, esi
          .if eax != 0
            OCall ebx::IncFile.PeekNextToken
            test eax, eax
            .if !ZERO? && CHRA ptr [eax] == "("
              mov bAddSpace, FALSE
            .else
              mov bAddSpace, TRUE
            .endif
          .elseif CHRA ptr [esi] == "("
            mov bAddSpace, FALSE
          .else
            mov bAddSpace, TRUE
          .endif

          ;Check if the reserved word is an argument
          mov edi, $GetCount@Stacklist(pArgStack)
          .while edi != 0
            dec edi
            mov eax, $GetItem@Stacklist(pArgStack, edi)
            invoke StrCompA, eax, esi
            .if eax == 0
              invoke TranslateReservedWord, esi, NULL   ;Yes => translate it
              mov esi, eax
              .break
            .endif
          .endw
          .if edx == FALSE || edi == 0                  ;No translation
            invoke TranslateNumOperator, esi            ;  => try to handle it as an numeric operator
          .endif
          OCall ebx::IncFile.StmWrite, eax
          mov bFirstParam, FALSE
        .endw
        Destroy@Stacklist pArgStack

        OCall ebx::IncFile.StmWriteChar, 3Eh            ;>
        OCall ebx::IncFile.StmWriteEOL
        OCall ebx::IncFile.StmWrite, $OfsCStrA("endm")
        OCall ebx::IncFile.StmWriteEOL
      .else
        invoke IsEquate?, pName                         ;Check if it already exist
        .if eax == FALSE
          invoke StrSizeA, pName
          invoke InsertAttr, g_pEquates, pName, eax, 0
        .endif
        OCall ebx::IncFile.StmWrite, $OfsCStrA(" equ ")
        invoke SkipSimpleBraces
        invoke ParseEqu, pName
      .endif
    .endif

    .if g_bConstants == FALSE
      mrm pStmOutPos, [ebx].$Obj(IncFile).pStmOutPos, ecx
      mov CHRA ptr [ecx], 0
    .endif
    ret
PPCH_Define endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Undef
; Purpose:   PP Command Handler for "#undef".
; Arguments: esi -> input token stream.
; Return:    Nothing.

PPCH_Undef proc
    ;Consume tokens until EOL
    SkipPPLine
    ret
PPCH_Undef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Include
; Purpose:   PP Command Handler for "#include".
; Arguments: esi -> input token stream.
; Return:    Nothing

PPCH_Include proc uses esi edi
    local pPath:PSTRINGA

    OCall ebx::IncFile.StmWrite, $OfsCStrA("include ")
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if eax != NULL && CHRA ptr [eax] == "<"
      OCall ebx::IncFile.GetNextTokenFromPPLine
    .endif
    mov pPath, eax
    mov edi, [ebx].$Obj(IncFile).pStmOutPos
    mov esi, pPath
    .if esi != NULL
      mov dh, 0
      .if CHRA ptr [esi] == '"'
        inc esi
        mov dh, '"'
      .endif
      .while CHRA ptr [esi] != 0
        lodsb
        .break .if al == dh
        .break .if al == 0
        stosb
      .endw
      mov ax, [edi - 2]
      or ah, 20h
      .if ax == "h."
        .if g_bProcessInclude != FALSE
          pushad
          mov al, 0
          stosb
          invoke ProcessFile, [ebx].$Obj(IncFile).pStmOutPos, ebx     ;ignore result and continue
          popad
        .endif
        dec edi
        dec edi
        mov eax, "cni."
        stosd
      .endif
      mov ax, 0A0Dh
      stosw
      mov [ebx].$Obj(IncFile).bStmOutEOL, TRUE
    .endif
    mov [ebx].$Obj(IncFile).pStmOutPos, edi
    mov al, 0
    stosb
    ret
PPCH_Include endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Error
; Purpose:   PP Command Handler for "#error".
; Arguments: None.
; Return:    Nothing.

PPCH_Error proc uses esi
    OCall ebx::IncFile.StmWrite, $OfsCStrA(".err ", 3Ch)  ;"<"
    xor esi, esi
    .while TRUE
      OCall ebx::IncFile.GetNextTokenFromPPLine
      .break .if eax == NULL
      .if esi != 0
        push eax
        OCall ebx::IncFile.StmWriteChar, " "
        pop eax
      .endif
      OCall ebx::IncFile.StmWrite, eax
      inc esi
    .endw
    OCall ebx::IncFile.StmWriteChar, 3Eh                ;">"
    OCall ebx::IncFile.StmWriteEOL
    ret
PPCH_Error endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Pragma
; Purpose:   PP Command Handler for "#pragma".
; Arguments: None.
; Return:    Nothing.

PPCH_Pragma proc uses esi
    local InpStat:INP_STAT, dParenthesesCount:DWORD

    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    OCall ebx::IncFile.GetNextTokenFromPPLine
    .if !$DoesStringMatchA?([eax], <message>)
      OCall ebx::IncFile.LoadInputStatus, addr InpStat
      jmp @NotMessage
    .endif

    ;Handle "#pragma message(...)"
    OCall ebx::IncFile.GetNextTokenFromPPLine           ;skip "("
    .if eax != NULL
      OCall ebx::IncFile.StmWrite, $OfsCStrA("echo ")
      mov dParenthesesCount, 1
      xor esi, esi
      .while TRUE
        OCall ebx::IncFile.GetNextTokenFromPPLine
        .if CHRA ptr [eax] == "("
          inc dParenthesesCount
        .elseif CHRA ptr [eax] == ")"
          dec dParenthesesCount
        .endif
        .break .if ZERO? || eax == NULL
        .if esi == 0
          push eax
          OCall ebx::IncFile.StmWriteChar, " "
          pop eax
        .endif
        .if CHRA ptr [eax] == '"'
          inc eax
          push eax
          invoke StrLengthA, eax
          pop ecx
          mov CHRA ptr [ecx + eax - 1], 0
          mov eax, ecx
        .endif
        OCall ebx::IncFile.StmWrite, eax
        inc esi
      .endw
      .if eax != NULL
        SkipPPLine
      .endif
      mov ecx, [ebx].$Obj(IncFile).pStmOutPos
      ;Check if last character is a ",". This causes %echo to continue with next line!
      mov al, CHRA ptr [ecx - 1]
      .if al == ","
        OCall ebx::IncFile.StmWriteChar, "'"
      .endif
      OCall ebx::IncFile.StmWriteEOL
    .endif
    ret

@NotMessage:
;    OCall ebx::IncFile.StmWrite, $OfsCStrA(";#pragma")
;    OCall ebx::IncFile.StmCopyRestOfPPLine
    .while TRUE
      OCall ebx::IncFile.GetNextTokenFromPPLine
      .break .if eax == NULL
    .endw
    ret
PPCH_Pragma endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

PPCH_Beg macro
;    int 3
;    DbgHex [ebx].$Obj(IncFile).bSkipScanPP
;    DbgHex [ebx].$Obj(IncFile).bSkipLogiPP
;    DbgHex [ebx].$Obj(IncFile).dIndentation
;    DbgHex [ebx].$Obj(IncFile).bIfLevel
endm

PPCH_End macro
;    int 3
;    DbgHex [ebx].$Obj(IncFile).bSkipScanPP
;    DbgHex [ebx].$Obj(IncFile).bSkipLogiPP
;    DbgHex [ebx].$Obj(IncFile).dIndentation
;    DbgHex [ebx].$Obj(IncFile).bIfLevel
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_If
; Purpose:   PP Command Handler for "#if".
; Arguments: None.
; Return:    Nothing.

PPCH_If proc
;    DbgText "if"
    PPCH_Beg
    movzx ecx, [ebx].$Obj(IncFile).bIfLevel
    .if ecx == 0 || (ecx != 0 && [ebx].$Obj(IncFile).bIfResult[ecx - 1] != PPR_FALSE)
      IncIfLevel
      invoke If_ElIf, PCT_IF
    .else
      SkipPPLine
    .endif
    inc [ebx].$Obj(IncFile).dIndentation
    PPCH_End
    ret
PPCH_If endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_ElIf
; Purpose:   PP Command Handler for "#elif".
; Arguments: None.
; Return:    Nothing.

PPCH_ElIf proc uses esi
;    DbgText "elif"
    PPCH_Beg
    dec [ebx].$Obj(IncFile).dIndentation

    movzx esi, [ebx].$Obj(IncFile).bIfLevel
    .if (esi == 1) || (esi > 1 && [ebx].$Obj(IncFile).bIfResult[esi - 2] != PPR_FALSE)
      IncElseLevel
      invoke If_ElIf, PCT_ELIF
      inc [ebx].$Obj(IncFile).dIndentation
    .else
      SkipPPLine
      mov [ebx].$Obj(IncFile).bSkipLogiPP, TRUE
      mov [ebx].$Obj(IncFile).bSkipC, TRUE
    .endif
    PPCH_End
    ret
PPCH_ElIf endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Else
; Purpose:   PP Command Handler for "#else".
; Arguments: None.
; Return:    Nothing.

PPCH_Else proc uses esi
;    DbgText "else"
    PPCH_Beg
    movzx esi, [ebx].$Obj(IncFile).bIfLevel
    .if (esi == 1) || (esi > 1 && [ebx].$Obj(IncFile).bIfResult[esi - 2] != PPR_FALSE)
      dec [ebx].$Obj(IncFile).dIndentation
      IncElseLevel
      OCall ebx::IncFile.StmWrite, $OfsCStrA("else")
      mov [ebx].$Obj(IncFile).bSkipUselessCode, FALSE
      OCall ebx::IncFile.StmSkipRestOfPPLine
      inc [ebx].$Obj(IncFile).dIndentation
      .if [ebx].$Obj(IncFile).bIfHistory[esi - 1] == PPR_TRUE
        mov [ebx].$Obj(IncFile).bIfResult[esi - 1], PPR_FALSE
        mov [ebx].$Obj(IncFile).bSkipLogiPP, TRUE
        mov [ebx].$Obj(IncFile).bSkipC, TRUE
      .else
        .if [ebx].$Obj(IncFile).bIfHistory[esi - 1] == PPR_FALSE
          mov [ebx].$Obj(IncFile).bIfResult[esi - 1], PPR_TRUE
          mov [ebx].$Obj(IncFile).bSkipLogiPP, FALSE
          mov [ebx].$Obj(IncFile).bSkipC, FALSE
          mov [ebx].$Obj(IncFile).bIfHistory[esi - 1], PPR_TRUE
        .else
          mov [ebx].$Obj(IncFile).bIfResult[esi - 1], PPR_UNKNOWN
          mov [ebx].$Obj(IncFile).bSkipLogiPP, FALSE
          mov [ebx].$Obj(IncFile).bSkipC, FALSE
          mov [ebx].$Obj(IncFile).bIfHistory[esi - 1], PPR_UNKNOWN
        .endif
      .endif
    .else
      SkipPPLine
      mov [ebx].$Obj(IncFile).bSkipLogiPP, TRUE
      mov [ebx].$Obj(IncFile).bSkipC, TRUE
    .endif
    PPCH_End
    ret
PPCH_Else endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Endif
; Purpose:   PP Command Handler for "#endif".
; Arguments: None.
; Return:    Nothing.

PPCH_Endif proc uses esi
;    DbgText "endif"
    PPCH_Beg
    dec [ebx].$Obj(IncFile).dIndentation
    DecIfLevel

    movzx esi, [ebx].$Obj(IncFile).bIfLevel
    .if (esi == 0) || (esi > 0) && ([ebx].$Obj(IncFile).bIfResult[esi - 1] != PPR_FALSE)
      OCall ebx::IncFile.StmWrite, $OfsCStrA("endif")
      mov [ebx].$Obj(IncFile).bSkipUselessCode, FALSE
      OCall ebx::IncFile.StmSkipRestOfPPLine
      mov [ebx].$Obj(IncFile).bSkipLogiPP, FALSE
      mov [ebx].$Obj(IncFile).bSkipC, FALSE
    .else
      SkipPPLine
      mov [ebx].$Obj(IncFile).bSkipLogiPP, TRUE
      mov [ebx].$Obj(IncFile).bSkipC, TRUE
    .endif
    PPCH_End
    ret
PPCH_Endif endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Ifdef
; Purpose:   PP Command Handler for "#ifdef".
; Arguments: None.
; Return:    Nothing.

PPCH_Ifdef proc
;    DbgText "ifdef"
    PPCH_Beg
    movzx ecx, [ebx].$Obj(IncFile).bIfLevel
    .if ecx == 0 || (ecx != 0 && [ebx].$Obj(IncFile).bIfResult[ecx - 1] != PPR_FALSE)
      IncIfLevel
      invoke Ifdef_Ifndef, PCT_IFDEF
    .else
      SkipPPLine
    .endif
    mov [ebx].$Obj(IncFile).bSkipUselessCode, FALSE
    inc [ebx].$Obj(IncFile).dIndentation
    PPCH_End
    ret
PPCH_Ifdef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_Ifndef
; Purpose:   PP Command Handler for "#ifndef".
; Arguments: None.
; Return:    Nothing.

PPCH_Ifndef proc
;    DbgText "ifndef"
    PPCH_Beg
    movzx ecx, [ebx].$Obj(IncFile).bIfLevel
    .if ecx == 0 || (ecx != 0 && [ebx].$Obj(IncFile).bIfResult[ecx - 1] != PPR_FALSE)
      IncIfLevel
      invoke Ifdef_Ifndef, PCT_IFNDEF
    .else
      SkipPPLine
    .endif
    inc [ebx].$Obj(IncFile).dIndentation
    PPCH_End
    ret
PPCH_Ifndef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: PPCH_IfNP
; Purpose:   PP Command Handler for "#if" only when IncFile.bSkipLogiPP == TRUE.
; Arguments: None.
; Return:    Nothing.

PPCH_IfNP proc uses esi
;    DbgText "ifNP"
    PPCH_Beg
    IncIfLevel
    movzx esi, [ebx].$Obj(IncFile).bIfLevel
    mov [ebx].$Obj(IncFile).bIfResult[esi - 1], PPR_FALSE
    mov [ebx].$Obj(IncFile).bIfHistory[esi - 1], PPR_FALSE
    mov [ebx].$Obj(IncFile).bSkipLogiPP, TRUE
    mov [ebx].$Obj(IncFile).bSkipC, TRUE

    SkipPPLine
    inc [ebx].$Obj(IncFile).dIndentation
    PPCH_End
    ret
PPCH_IfNP endp
