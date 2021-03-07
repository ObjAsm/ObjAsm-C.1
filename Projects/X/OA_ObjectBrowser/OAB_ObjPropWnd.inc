; ==================================================================================================
; Title:      OAB_ObjPropWnd.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjectBrowser.asm
; Purpose:    ObjPropWnd implementation for OA_ObjBrowser.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjPropWnd.Done
; Purpose:    Finalizes the ObjPropWnd object and disposes the MDI child window.
; Arguments:  None.
; Return:     Nothing.

Method ObjPropWnd.Done, uses xsi
  SetObject xsi

  ;Release internal data
  OCall [xsi].Variables::DataCollection.Done
  OCall [xsi].Methods::DataCollection.Done

  ;Final object cleanup
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjPropWnd.Init
; Purpose:    Initalizes the ObjPropWnd object.
; Arguments:  Arg1: -> Owner object (ClientWnd).
;             Arg2: -> Window Class name.
;             Arg2: -> POBJECTINFORMATION.
; Return:     Nothing.

Method ObjPropWnd.Init, uses xsi, pOwner:$ObjPtr(ClientWnd), pWndClassName:PSTRING, \
                                  pInfo:POBJECTINFORMATION
  SetObject xsi
  OCall [xsi].Methods::DataCollection.Init, xsi, 50, 50, COL_MAX_CAPACITY
  OCall [xsi].Variables::DataCollection.Init, xsi, 50, 50, COL_MAX_CAPACITY
  ACall xsi.Init, pOwner, pWndClassName, pInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MatchObjectImpMethod
; Purpose:    Perform a match test.
; Arguments:  Arg1: -> IMPMTDINFORMATION.
;             Arg2: -> Object name.
;             Arg2: -> Method name.
; Return:     eax = zero if a match was found.

MatchObjectImpMethod proc pImpMtdInfo:PIMPMTDINFORMATION, pObjectName:POINTER, pMethodName:POINTER
  mov xcx, pImpMtdInfo
  invoke StrCompA, [xcx].IMPMTDINFORMATION.pObjectName, pObjectName
  .if eax == 0
    mov xcx, pImpMtdInfo
    invoke StrCompA, [xcx].IMPMTDINFORMATION.pName, pMethodName
  .endif
  ret
MatchObjectImpMethod endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ShowObjMtd
; Purpose:    Emits HTML codes to render object method member information.
; Arguments:  Arg1: -> MEMBERDATA.
;             Arg2: -> ObjPropWnd.
;             Arg3: Dummy.
; Return:     Nothing.

ShowObjMtd proc uses xbx xdi xsi pMemberData:PMEMBERDATA, pSelf:$ObjPtr(ObjPropWnd), xDummy:XWORD
  local dBytesWritten:DWORD, cBuffer[20]:CHR, hHtmlFile:HANDLE, pText:POINTER
  local pImpMtdInfo:PIMPMTDINFORMATION

;  mov xsi, pMemberData
;  lea xdi, dBytesWritten
;  mov xbx, [xsi].MEMBERDATA.pMemberInfo                 ;xbx -> OBJMTDINFORMATION
;  .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_UNKNOWN
;    invoke WriteFile, hHtmlFile, offset HTML_MIS_00, HTML_MIS_00_SIZE, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    ;Attention: In this case ebx -> OBJECTINFORMATION
;    invoke StrLength, [xbx].OBJECTINFORMATION.pAncestorName
;    invoke WriteFile, hHtmlFile, [xbx].OBJECTINFORMATION.pAncestorName, eax, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_MIS_01, offset HTML_MIS_01_SIZE, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_MIS_02, offset HTML_MIS_02_SIZE, xdi, NULL
;  .else
;    ;Exit if dShowRedefMtds == FALSE
;    mov xcx, pSelf
;    .if [xcx].$Obj(ObjPropWnd).dShowRedefMtds == FALSE
;      .ifBitClr [xsi].MEMBERDATA.dFlags, MDT_FINAL
;        ret
;      .endif
;    .endif
;
;    ;Get the method implementation info
;    mov xdx, pSelf
;    mov xcx, [xdx].$Obj(ObjPropWnd).pOwner              ;xcx -> ClientWnd
;    mov xdx, [xcx].$Obj(ClientWnd).pOwner               ;xdx -> ObjectBrowser
;    mov xcx, [xdx].$Obj(ObjectBrowser).pObjDB
;    OCall [xcx].$Obj(OA_ObjDB).ImpMethodColl::Collection.FirstThatNot, offset MatchObjectImpMethod, \
;                           [xbx].OBJMTDINFORMATION.pObjectName, [xbx].OBJMTDINFORMATION.pName
;    mov pImpMtdInfo, xax
;
;    ;Setup (+)/(-) button
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_01, HTML_OMD_01_SIZE, xdi, NULL
;    lea xax, cBuffer
;    mov word ptr [xax], "x0"
;    add xax, 2
;    invoke dword2hex, xax, ebx
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_02, HTML_OMD_02_SIZE, xdi, NULL
;    invoke WriteFile, hHtmlFile, addr cBuffer, 10, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_03, HTML_OMD_03_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_SHOWDETAIL
;      invoke WriteFile, hHtmlFile, offset HTML_HIDE, sizeof HTML_HIDE, xdi, NULL
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_SHOW, sizeof HTML_SHOW, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_04, HTML_OMD_04_SIZE, xdi, NULL
;
;    ;Display object and method names
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_05, HTML_OMD_05_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke StrLength, [xbx].OBJMTDINFORMATION.pObjectName
;    invoke WriteFile, hHtmlFile, [xbx].OBJMTDINFORMATION.pObjectName, eax, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_06, HTML_OMD_06_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      invoke WriteFile, hHtmlFile, offset HTML_OPEN_BOLD, sizeof HTML_OPEN_BOLD, xdi, NULL
;    .endif
;    mov ecx, [xbx].OBJMTDINFORMATION.dFlags
;    .if ecx == METHODTYPE_VIRTUAL_ABSTRACT || ecx == METHODTYPE_DYNAMIC_ABSTRACT
;      invoke WriteFile, hHtmlFile, offset HTML_OPEN_ITALIC, sizeof HTML_OPEN_ITALIC, xdi, NULL
;    .endif
;    invoke StrLength, [xbx].OBJMTDINFORMATION.pName
;    invoke WriteFile, hHtmlFile, [xbx].OBJMTDINFORMATION.pName, eax, xdi, NULL
;    mov ecx, [xbx].OBJMTDINFORMATION.dFlags
;    .if ecx == METHODTYPE_VIRTUAL_ABSTRACT || ecx == METHODTYPE_DYNAMIC_ABSTRACT
;      invoke WriteFile, hHtmlFile, offset HTML_CLOSE_ITALIC, sizeof HTML_CLOSE_ITALIC, xdi, NULL
;    .endif
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      invoke WriteFile, hHtmlFile, offset HTML_CLOSE_BOLD, sizeof HTML_CLOSE_BOLD, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_07, HTML_OMD_07_SIZE, xdi, NULL
;
;    ;Display method type
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_08, HTML_OMD_08_SIZE, xdi, NULL
;    mov eax, [xbx].OBJMTDINFORMATION.dFlags
;    .if eax == METHODTYPE_REDEFINED && [xsi].MEMBERDATA.pDefinition == NULL
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
;    .else
;      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
;      .else
;        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
;      .endif
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    mov eax, [xbx].OBJMTDINFORMATION.dFlags
;    .if eax != METHODTYPE_REDEFINED
;      lea xcx, SOM_TEXT_TABLE
;      mov xcx, PSTRING ptr [xcx + sizeof(PSTRING)*xax]
;      mov pText, xcx
;      invoke StrLength, xcx
;      invoke WriteFile, hHtmlFile, pText, eax, xdi, NULL
;    .else
;      mov xdx, [xsi].MEMBERDATA.pDefinition
;      .if xdx != NULL
;        mov eax, [xdx].OBJMTDINFORMATION.dFlags
;        lea xcx, SOM_TEXT_TABLE
;        mov xcx, PSTRING ptr [xcx + sizeof(PSTRING)*xax]
;        mov pText, xcx
;        invoke StrLength, xcx
;        invoke WriteFile, hHtmlFile, pText, eax, xdi, NULL
;      .else
;        invoke WriteFile, hHtmlFile, offset HTML_UNKNOWN, sizeof HTML_UNKNOWN, xdi, NULL
;      .endif
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_10, HTML_OMD_10_SIZE, xdi, NULL
;
;    ;Display Definition
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_08, HTML_OMD_08_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      .if pImpMtdInfo == NULL
;        ;Draw in red also if it is abstract and final!
;        invoke WriteFile, hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
;      .else
;        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
;      .endif
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
;    .endif
;
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    mov ecx, [xbx].OBJMTDINFORMATION.dFlags
;    .if ecx ==  METHODTYPE_VIRTUAL_ABSTRACT || ecx == METHODTYPE_DYNAMIC_ABSTRACT
;      invoke WriteFile, hHtmlFile, offset HTML_ABSTRACT, sizeof HTML_ABSTRACT, xdi, NULL
;    .elseif pImpMtdInfo == NULL
;      invoke WriteFile, hHtmlFile, offset HTML_UNKNOWN, sizeof HTML_UNKNOWN, xdi, NULL
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_REGULAR, sizeof HTML_REGULAR, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_10, HTML_OMD_10_SIZE, xdi, NULL
;
;    ;Display method status
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_08, HTML_OMD_08_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    .ifBitClr [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      mov xcx, PSTRING ptr SOM_TEXT_TABLE[sizeof(PSTRING)*METHODTYPE_REDEFINED]
;      mov pText, xcx
;      invoke StrLength, xcx
;      invoke WriteFile, hHtmlFile, pText, eax, xdi, NULL
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_REGULAR, sizeof HTML_REGULAR, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_10, HTML_OMD_10_SIZE, xdi, NULL
;
;    ;Close row
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_11, HTML_OMD_11_SIZE, xdi, NULL
;
;    ;Display method comments
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_SHOWDETAIL
;      invoke WriteFile, hHtmlFile, offset HTML_OMC_00, HTML_OMC_00_SIZE, xdi, NULL
;      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
;      .else
;        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
;      .endif
;      invoke WriteFile, hHtmlFile, offset bCRLF, 2, xdi, NULL
;      mov xax, pImpMtdInfo
;      .if xax != NULL
;        mov xsi, [xax].IMPMTDINFORMATION.pHelpData
;        .while xsi != NULL
;;          lea xdx, [xsi + sizeof(POINTER)]
;;          invoke EmitHtmlText, hHtmlFile, xdx
;;          invoke WriteFile, hHtmlFile, offset HTML_BREAK, sizeof HTML_BREAK, xdi, NULL
;;          invoke WriteFile, hHtmlFile, offset bCRLF, 2, xdi, NULL
;;          mov esi, [xsi]                              ;Move to next string
;        .endw
;      .else
;;        invoke WriteFile, hHtmlFile, offset HTML_NO_INFO, HTML_NO_INFO_SIZE, xdi, NULL
;      .endif
;;      invoke WriteFile, hHtmlFile, offset HTML_OMC_01, HTML_OMC_01_SIZE, xdi, NULL
;    .endif
;  .endif
  ret
ShowObjMtd endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ShowObjVar
; Purpose:    Emits HTML codes to render variable member information.
; Arguments:  Arg1: -> MEMBERDATA.
;             Arg2: -> ObjPropWnd.
;             Arg3: Dummy.
; Return:     Nothing.

ShowObjVar proc uses xbx xdi xsi pMemberData:PMEMBERDATA, pSelf:$ObjPtr(ObjPropWnd), xDummy:XWORD
  local dBytesWritten:DWORD, hHtmlFile:HANDLE, pText:POINTER
  local dLength:DWORD, dLength1:DWORD, dLength2:DWORD
  local cBuffer1[1024]:CHR, cBuffer2[1024]:CHR, cHexBuffer[12]:CHR

  mov xsi, pMemberData
  lea xdi, dBytesWritten
  mov xbx, [xsi].MEMBERDATA.pMemberInfo                 ;xbx -> OBJVARINFORMATION
  .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_UNKNOWN
    invoke WriteFile, hHtmlFile, offset HTML_MIS_00, HTML_MIS_00_SIZE, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    ;Attention: In this case ebx -> OBJECTINFORMATION
    invoke StrLength, [xbx].OBJECTINFORMATION.pAncestorName
    invoke WriteFile, hHtmlFile, [xbx].OBJECTINFORMATION.pAncestorName, eax, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_MIS_01, offset HTML_MIS_01_SIZE, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_MIS_02, offset HTML_MIS_02_SIZE, xdi, NULL
  .else
    mov xcx, pSelf
    .if [xcx].$Obj(ObjPropWnd).dShowRedefVars == FALSE
      .ifBitClr [xsi].MEMBERDATA.dFlags, MDT_FINAL
        ret
      .endif
    .endif

    ;Display icon
    invoke WriteFile, hHtmlFile, offset HTML_VAR_01, HTML_VAR_01_SIZE, xdi, NULL
    .if [xbx].OBJVARINFORMATION.dFlags == VARIABLETYPE_OBJECT
      invoke WriteFile, hHtmlFile, offset HTML_VAROBJ, sizeof HTML_VAROBJ, xdi, NULL
    .else
      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
        invoke WriteFile, hHtmlFile, offset HTML_VARDAT, sizeof HTML_VARDAT, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_VARRDT, sizeof HTML_VARRDT, xdi, NULL
      .endif
    .endif

    ;Display Data name
    invoke WriteFile, hHtmlFile, offset HTML_VAR_02, HTML_VAR_02_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke StrLength, [xbx].OBJVARINFORMATION.pObjectName
    invoke WriteFile, hHtmlFile, [xbx].OBJVARINFORMATION.pObjectName, eax, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_VAR_03, HTML_VAR_03_SIZE, xdi, NULL
    invoke StrLength, [xbx].OBJVARINFORMATION.pName
    invoke WriteFile, hHtmlFile, [xbx].OBJVARINFORMATION.pName, eax, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_VAR_04, HTML_VAR_04_SIZE, xdi, NULL

    ;Display Variable Type
    .if [xbx].OBJMTDINFORMATION.dFlags == VARIABLETYPE_REDEFINED && \
        [xsi].MEMBERDATA.pDefinition == NULL
       invoke WriteFile, hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
    .else
      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
      .endif
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL

    ;Extract Type and Value => cBuffer 1 & 2
    m2z pText
    m2z CHR ptr cBuffer1
    m2z CHR ptr cBuffer2
    m2z dLength1
    m2z dLength2
    .if xbx != NULL && \
        [xbx].OBJVARINFORMATION.dFlags != VARIABLETYPE_OBJECT && \
        [xbx].OBJVARINFORMATION.pArgType != NULL
      invoke StrLScan, [xbx].OBJVARINFORMATION.pArgType, ","
      mov pText, xax
      .if xax != NULL
        add xax, sizeof CHR
        invoke StrLRTrim, addr cBuffer2, xax
        mov dLength2, $32($invoke(StrLength, addr cBuffer2))
      .endif

      .if [xbx].OBJVARINFORMATION.dFlags == VARIABLETYPE_REDEFINED
        invoke StrLRTrim, addr cBuffer2, [xbx].OBJVARINFORMATION.pArgType
        mov dLength2, $32($invoke(StrLength, addr cBuffer2))
        mov xbx, [xsi].MEMBERDATA.pDefinition
        .if xbx != NULL
          mov pText, $invoke(StrLScan, [xbx].OBJVARINFORMATION.pArgType, ",")
        .endif
      .endif

      .if pText != NULL && xbx != NULL && [xbx].OBJVARINFORMATION.pArgType != NULL
        mov xax, pText
        sub xax, [xbx].OBJVARINFORMATION.pArgType
        mov dLength1, eax
        invoke StrCCopy, addr cBuffer1, [xbx].OBJVARINFORMATION.pArgType, eax
      .endif
    .endif

    ;Display them
    .if xbx == NULL
      invoke WriteFile, hHtmlFile, offset HTML_UNKNOWN, sizeof HTML_UNKNOWN, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_VAR_04, HTML_VAR_04_SIZE, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_UNKNOWN, sizeof HTML_UNKNOWN, xdi, NULL

    .elseif [xbx].OBJVARINFORMATION.dFlags == VARIABLETYPE_UNKNOWN
      invoke WriteFile, hHtmlFile, addr cBuffer1, dLength1, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_UNKNOWN, sizeof HTML_UNKNOWN, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_VAR_04, HTML_VAR_04_SIZE, xdi, NULL
      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
      .endif
      invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, hHtmlFile, addr cBuffer2, dLength2, xdi, NULL

    .elseif [xbx].OBJVARINFORMATION.dFlags == VARIABLETYPE_REGULAR
      invoke WriteFile, hHtmlFile, addr cBuffer1, dLength1, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_VAR_04, HTML_VAR_04_SIZE, xdi, NULL
      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
      .endif
      invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, hHtmlFile, addr cBuffer2, dLength2, xdi, NULL

    .elseif [xbx].OBJVARINFORMATION.dFlags == VARIABLETYPE_OBJECT
      mov dLength, $32($invoke(StrLength, [xbx].OBJVARINFORMATION.pArgType))
      mov xcx, pSelf
      mov xdx, [xcx].$Obj(ObjPropWnd).pOwner            ;xdx -> ClientWnd
      OCall [xdx].$Obj(ClientWnd).pOwner::ObjectBrowser.FindObjInfo, [xbx].OBJVARINFORMATION.pArgType
      .if xax != NULL
        invoke dword2hex, addr cHexBuffer, eax
        invoke WriteFile, hHtmlFile, offset HTML_OPEN_HREF, sizeof HTML_OPEN_HREF, xdi, NULL
        invoke WriteFile, hHtmlFile, addr cHexBuffer, 8, xdi, NULL
        invoke WriteFile, hHtmlFile, offset HTML_CLOSE_TAG, sizeof HTML_CLOSE_TAG, xdi, NULL
        invoke WriteFile, hHtmlFile, [xbx].OBJVARINFORMATION.pArgType, dLength, xdi, NULL
        invoke WriteFile, hHtmlFile, offset HTML_CLOSE_HREF, sizeof HTML_CLOSE_HREF, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, [xbx].OBJVARINFORMATION.pArgType, dLength, xdi, NULL
      .endif
      invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_VAR_04, HTML_VAR_04_SIZE, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_TPL_DEFAULTS, sizeof HTML_TPL_DEFAULTS, xdi, NULL

    .else
      DbgWarning "Unknown Variable Type"
      DbgStr [xbx].OBJVARINFORMATION.pName
      DbgHex [xbx].OBJVARINFORMATION.dFlags
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_VAR_05, HTML_VAR_05_SIZE, xdi, NULL

    ;Display Variable status
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    .ifBitClr [xsi].MEMBERDATA.dFlags, MDT_FINAL
      mov xcx, PSTRING ptr SOM_TEXT_TABLE[sizeof(PSTRING)*METHODTYPE_REDEFINED]
      mov pText, xcx
      invoke StrLength, xcx
      invoke WriteFile, hHtmlFile, pText, eax, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_REGULAR, sizeof HTML_REGULAR, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_VAR_06, HTML_VAR_06_SIZE, xdi, NULL

  .endif
  ret
ShowObjVar endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjPropWnd.EmitHtml
; Purpose:    Emits the HTML render code in a file located in the user temp folder.
; Arguments:  None.
; Return:     Nothing.

;Method ObjPropWnd.EmitHtml, uses xbx xdi xsi
;  local dBytesWritten:DWORD, cBuffer[MAX_PATH]:CHR, cHexAddr[12]:CHR
;  local LastWriteTimeDef:FILETIME, LastWriteTimeAsm:FILETIME, LastWriteTimeLib:FILETIME
;  local SysTimeUTC:SYSTEMTIME, SysTimeLocal:SYSTEMTIME, dLength:DWORD
;  local dSecond:DWORD, dMinute:DWORD, dHour:DWORD, dYear:DWORD, dMonth:DWORD, dDay:DWORD
;
;  SetObject xsi
;
;  ;Reset file
;  invoke SetFilePointer, [xsi].hHtmlFile, 0, NULL, FILE_BEGIN
;  invoke SetEndOfFile, [xsi].hHtmlFile
;
;  lea xdi, dBytesWritten
;  mov xbx, [xsi].pInfo
;
;  ;Start HTML document
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_00, HTML_DOC_00_SIZE, xdi, NULL
;  mov dLength, $32($invoke(StrLength, [xbx].OBJECTINFORMATION.pName))
;  invoke WriteFile, [xsi].hHtmlFile, [xbx].OBJECTINFORMATION.pName, eax, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_01, HTML_DOC_01_SIZE, xdi, NULL
;
;  ;Show name
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_00, HTML_DSC_00_SIZE, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, [xbx].OBJECTINFORMATION.pName, dLength, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_01, HTML_DSC_01_SIZE, xdi, NULL
;
;  ;Show description (if available)
;  mov xbx, [xbx].OBJECTINFORMATION.pHelpData
;  .if xbx != NULL
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_02, HTML_DSC_02_SIZE, xdi, NULL
;    .while xbx != NULL
;      lea xdx, [xbx + sizeof(POINTER)]
;      invoke EmitHtmlText, [xsi].hHtmlFile, xdx
;      invoke WriteFile, [xsi].hHtmlFile, offset HTML_BREAK, sizeof HTML_BREAK, xdi, NULL
;      invoke WriteFile, [xsi].hHtmlFile, offset bCRLF, 2, xdi, NULL
;      mov xbx, [xbx]
;    .endw
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_03, HTML_DSC_03_SIZE, xdi, NULL
;  .endif
;
;  ;Show inheritance path
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_00, HTML_INH_00_SIZE, xdi, NULL
;  OCall xsi.ShowInheritance, [xsi].pInfo, FALSE
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_07, HTML_INH_07_SIZE, xdi, NULL
;
;  ;Show file information
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_00, HTML_FLS_00_SIZE, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_01, HTML_FLS_01_SIZE, xdi, NULL
;
;  lea xbx, cHexAddr
;  mov word ptr [xbx], "x0"
;  mov xdx, [xsi].pInfo
;  add xbx, 2
;  invoke xword2hex, xbx, [xdx].OBJECTINFORMATION.pFileInfo
;
;  ;Show definition file
;  lea xbx, cHexAddr
;  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL;**************************************************
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_02, HTML_FLS_02_SIZE, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_03, HTML_FLS_03_SIZE, xdi, NULL
;  mov xcx, [xsi].pInfo
;  mov xdx, [xcx].OBJECTINFORMATION.pFileInfo
;  mov xbx, [xdx].FILEINFORMATION.pFileName
;  OutputFileInfo LastWriteTimeDef
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_06, HTML_FLS_06_SIZE, xdi, NULL
;
;  ;Show asm file
;  lea xbx, cHexAddr
;  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_07, HTML_FLS_07_SIZE, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_08, HTML_FLS_08_SIZE, xdi, NULL
;
;  mov xcx, [xsi].pInfo
;  mov xax, [xcx].OBJECTINFORMATION.pFileInfo
;  lea xbx, cBuffer
;  invoke StrCopy, xbx, [xax].FILEINFORMATION.pFileName
;  invoke StrRScan, xbx, "."
;  .if xax == NULL
;    invoke StrEnd, xbx
;  .endif
;  FillString [xax], <.asm>
;
;  OutputFileInfo LastWriteTimeAsm
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_09, HTML_FLS_09_SIZE, xdi, NULL
;
;  ;Show lib file
;  lea xbx, cHexAddr
;  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_10, HTML_FLS_10_SIZE, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_11, HTML_FLS_11_SIZE, xdi, NULL
;
;  mov xcx, [xsi].pInfo
;  mov xax, [xcx].OBJECTINFORMATION.pFileInfo
;  lea xbx, cBuffer
;  invoke StrCopy, xbx, [xax].FILEINFORMATION.pFileName
;  invoke StrRScan, xbx, "."
;  .if xax == NULL
;    invoke StrEnd, xbx
;  .endif
;  FillString [xax], <.lib>
;  OutputFileInfo LastWriteTimeLib, 1
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_12, HTML_FLS_12_SIZE, xdi, NULL
;
;  ;Show method information
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_OMD_00, HTML_OMD_00_SIZE, xdi, NULL
;  OCall [xsi].Methods::DataCollection.ForEach, offset ShowObjMtd, xsi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_OMD_12, HTML_OMD_12_SIZE, xdi, NULL
;
;  ;Show variable information
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_VAR_00, HTML_VAR_00_SIZE, xdi, NULL
;  OCall [xsi].Variables::DataCollection.ForEach, offset ShowObjVar, xsi, NULL
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_VAR_07, HTML_VAR_07_SIZE, xdi, NULL
;
;  ;End HTML document
;  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_99, HTML_DOC_99_SIZE, xdi, NULL
;MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjPropWnd.Gather
; Purpose:    Collect all informations of this object.
; Arguments:  None.
; Return:     Nothing.

Method ObjPropWnd.Gather, uses xsi
  SetObject xsi
  OCall xsi.GatherMethods, [xsi].pInfo
  OCall xsi.GatherVariables, [xsi].pInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GatherObjMtds
; Purpose:    Recursion procedure used to collect object method information.
; Arguments:  Arg1: -> OBJECTINFORMATION.
;             Arg2: -> Object name.
;             Arg3: -> ObjPropWnd.
; Return:     Nothing.

GatherObjMtds proc uses xbx xdi xsi pObjMtdInfo:POBJMTDINFORMATION, pObjName:PSTRING, pSelf:$ObjPtr(ObjPropWnd)
  SetObject xsi, ObjPropWnd
  mov xbx, pObjMtdInfo
  .if $invoke(StrCompA, [xbx].OBJMTDINFORMATION.pObjectName, pObjName) == 0
    mov xdi, $MemAlloc(MEMBERDATA)
    mov [xdi].MEMBERDATA.pMemberInfo, xbx
    mov [xdi].MEMBERDATA.dFlags, MDT_FINAL
    m2z [xdi].MEMBERDATA.pDefinition
    .if [xbx].OBJMTDINFORMATION.dFlags == METHODTYPE_REDEFINED
      OCall [xsi].Methods::DataCollection.LastThatNot, offset FindFinalMember, xdi, NULL
    .endif
    OCall [xsi].Methods::DataCollection.Insert, xdi
  .endif
  ret
GatherObjMtds endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjPropWnd.GatherMethods
; Purpose:    Collect all method information of this object.
; Arguments:  Arg1: -> OBJECTINFORMATION.
; Return:     Nothing.

Method ObjPropWnd.GatherMethods, uses xsi, pInfo:POBJECTINFORMATION
  SetObject xsi
  OCall [xsi].Methods::DataCollection.DisposeAll

  mov xcx, pInfo
  mov xdx, [xcx].OBJECTINFORMATION.pAncestorName
  .if xdx != NULL
    mov xcx, [xsi].pOwner                               ;xcx -> ClientWnd
    OCall [xcx].$Obj(ClientWnd).pOwner::ObjectBrowser.FindObjInfo, xdx
    .if xax != NULL
      OCall xsi.GatherMethods, xax
    .else
      ;Stop recursion
      MemAlloc MEMBERDATA
      OCall [xsi].Methods::DataCollection.Insert, xax
      m2m [xax].MEMBERDATA.pMemberInfo, pInfo, xdx
      mov [xax].MEMBERDATA.dFlags, MDT_UNKNOWN
      m2z [xax].MEMBERDATA.pDefinition
    .endif
  .endif

  mov xax, pInfo
  mov xcx, [xsi].pOwner                                 ;xcx -> ClientWnd
  mov xdx, [xcx].$Obj(ClientWnd).pOwner                 ;xax -> ObjectBrowser
  mov xcx, [xdx].$Obj(ObjectBrowser).pObjDB
  OCall [xcx].$Obj(OA_ObjDB).ObjMethodColl::ObjMtdInfoCollection.ForEach, \
                                            offset GatherObjMtds, [xax].OBJECTINFORMATION.pName, xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GatherObjVars
; Purpose:    Recursion procedure used to collect variable information.
; Arguments:  Arg1: -> OBJVARINFORMATION.
;             Arg2: -> Object name.
;             Arg3: -> ObjPropWnd.
; Return:     Nothing.

GatherObjVars proc uses xbx xdi xsi pObjVarInfo:POBJVARINFORMATION, pObjName:PSTRING, pSelf:$ObjPtr(ObjPropWnd)
  SetObject xsi, ObjPropWnd
  mov xbx, pObjVarInfo
  .if $invoke(StrCompA, [xbx].OBJVARINFORMATION.pObjectName, pObjName) == 0
    mov xdi, $MemAlloc(MEMBERDATA)
    mov [xdi].MEMBERDATA.pMemberInfo, xbx
    mov [xdi].MEMBERDATA.dFlags, MDT_FINAL
    m2z [xdi].MEMBERDATA.pDefinition
    .if [xbx].OBJVARINFORMATION.dFlags == VARIABLETYPE_REDEFINED
      OCall [xsi].Variables::DataCollection.LastThatNot, offset FindFinalMember, xdi, NULL
    .endif
    OCall [xsi].Variables::DataCollection.Insert, xdi
  .endif
  ret
GatherObjVars endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjPropWnd.GatherVariables
; Purpose:    Collect all method information of this object.
; Arguments:  Arg1: -> OBJECTINFORMATION.
; Return:     Nothing.

Method ObjPropWnd.GatherVariables, uses xsi, pInfo:POBJECTINFORMATION
  SetObject xsi
  OCall [xsi].Variables::DataCollection.DeleteAll

  mov xcx, pInfo
  mov xdx, [xcx].OBJECTINFORMATION.pAncestorName
  .if xdx != NULL
    mov xcx, [xsi].pOwner                               ;xcx -> ClientWnd
    OCall [xcx].$Obj(ClientWnd).pOwner::ObjectBrowser.FindObjInfo, xdx
    .if xax != NULL
      OCall xsi.GatherVariables, xax
    .else
      ;Stop recursion
      MemAlloc MEMBERDATA
      OCall [xsi].Variables::DataCollection.Insert, xax
      m2m [xax].MEMBERDATA.pMemberInfo, pInfo, xdx
      mov [xax].MEMBERDATA.dFlags, MDT_UNKNOWN
      m2z [xax].MEMBERDATA.pDefinition
    .endif
  .endif

  mov xax, pInfo
  mov xcx, [xsi].pOwner                                 ;xcx -> ClientWnd
  mov xdx, [xcx].$Obj(ClientWnd).pOwner                 ;xax -> ObjectBrowser
  mov xcx, [xdx].$Obj(ObjectBrowser).pObjDB
  OCall [xcx].$Obj(OA_ObjDB).ObjVariableColl::ObjVarInfoCollection.ForEach, \
                offset GatherObjVars, [xax].OBJECTINFORMATION.pName, xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:   	ObjPropWnd.ShowInheritance
; Purpose:  	Method that is called recursively to output an inheritance path.
; Arguments:	Arg1: -> OBJECTINFORMATION.
;           	Arg2: Flag to signal if the current item should generate a link.
; Return:   	Nothing.

Method ObjPropWnd.ShowInheritance, uses xbx xdi xsi, pObjectInfo:POBJECTINFORMATION, dLink:DWORD
  local dBytesWritten:DWORD, cHexBuffer[12]:CHR

  SetObject xsi
  lea xdi, dBytesWritten
  mov xcx, pObjectInfo
  mov xbx, [xcx].OBJECTINFORMATION.pAncestorName
  .if xbx != NULL
    mov xcx, [xsi].pOwner                               ;xcx -> ClientWnd
    OCall [xcx].$Obj(ClientWnd).pOwner::ObjectBrowser.FindObjInfo, xbx
    .if xax != NULL
      OCall xsi::ObjPropWnd.ShowInheritance, xax, TRUE
    .else
      ;Stop recursion
;      invoke WriteFile, [xsi].hHtmlFile, offset HTML_ANF_00, HTML_ANF_00_SIZE, xdi, NULL
;      invoke StrLength, xbx
;      invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
;      invoke WriteFile, [xsi].hHtmlFile, offset HTML_ANF_01, HTML_ANF_01_SIZE, xdi, NULL
    .endif
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_04, HTML_INH_04_SIZE, xdi, NULL
  .endif

  mov xcx, pObjectInfo
  mov xbx, [xcx].OBJECTINFORMATION.pName
  .if dLink != FALSE
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_01, HTML_INH_01_SIZE, xdi, NULL
;    invoke xword2hex, addr cHexBuffer, pObjectInfo
;    invoke WriteFile, [xsi].hHtmlFile, addr cHexBuffer, 8, xdi, NULL  ;****************************************************
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_02, HTML_INH_02_SIZE, xdi, NULL
;    invoke StrLength, xbx
;    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_03, HTML_INH_03_SIZE, xdi, NULL

  .else
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_05, HTML_INH_05_SIZE, xdi, NULL
;    invoke StrLength, xbx
;    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_06, HTML_INH_06_SIZE, xdi, NULL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjPropWnd.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

TVCHAR_RB_CHECKED   equ   025C9h
TVCHAR_RB_UNCHECKED equ   025CBh
TVCHAR_CB_CHECKED   equ   00052h
TVCHAR_CB_UNCHECKEd equ   000A3h

CStrW TVRadioBtnChecked, TVCHAR_RB_CHECKED
CStrW TVRadioBtnUnChecked, TVCHAR_RB_UNCHECKED
CStrW TVCheckBoxChecked, TVCHAR_CB_CHECKED
CStrW TVCheckBoxUnChecked, TVCHAR_CB_UNCHECKEd

SetRBTextFrom proc pVariable:POINTER, ppText:POINTER 
  mov xbx, ppText
  mov xdi, pVariable
  invoke StrDispose, PSTRINGW ptr [xbx]
  .if DWORD ptr [xdi] == FALSE
    mov xcx, offset TVRadioBtnUnChecked
  .else
    mov xcx, offset TVRadioBtnChecked
  .endif
  mov PSTRINGW ptr [xbx], $invoke(StrNewW, xcx)
  ret
SetRBTextFrom endp

SetCBTextFrom proc pVariable:POINTER, ppText:POINTER 
  mov xbx, ppText
  mov xdi, pVariable
  invoke StrDispose, PSTRINGW ptr [xbx]
  .if DWORD ptr [xdi] == FALSE
    mov xcx, offset TVCheckBoxUnChecked
  .else
    mov xcx, offset TVCheckBoxChecked
  .endif
  mov PSTRINGW ptr [xbx], $invoke(StrNewW, xcx)
  ret
SetCBTextFrom endp

Method ObjPropWnd.OnNotify, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local dCheckBoxIndex:DWORD
  
  SetObject xsi
  mov xax, wParam
  .if xax == VIEW_CTRL_ID
    mov xdi, lParam
    .if [xdi].NMHDR.code == TVNMC_APP_MOUSEUP
      .if [xdi].TVNM_APP.dID == 0
        .if [xsi].dRadioBtn1 == FALSE
          mov [xsi].dRadioBtn1, TRUE
          mov [xsi].dRadioBtn2, FALSE
        .else
          mov [xsi].dRadioBtn1, FALSE
        .endif
        mov xbx, [xsi].pTextView 
        OCall xbx::TextView.Draw
        invoke RedrawWindow, [xbx].$Obj(TextView).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

      .elseif [xdi].TVNM_APP.dID == 1
        .if [xsi].dRadioBtn2 == FALSE
          mov [xsi].dRadioBtn2, TRUE
          mov [xsi].dRadioBtn1, FALSE
        .else
          mov [xsi].dRadioBtn2, FALSE
        .endif
        mov xbx, [xsi].pTextView 
        OCall xbx::TextView.Draw
        invoke RedrawWindow, [xbx].$Obj(TextView).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

      .elseif [xdi].TVNM_APP.dID == 2
        .if [xsi].dCheckBox1 == FALSE
          mov [xsi].dCheckBox1, TRUE
        .else
          mov [xsi].dCheckBox1, FALSE
        .endif
        mov xbx, [xsi].pTextView 
        OCall xbx::TextView.Draw
        invoke RedrawWindow, [xbx].$Obj(TextView).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

      .elseif [xdi].TVNM_APP.dID == 3
        .if [xsi].dCheckBox2 == FALSE
          mov [xsi].dCheckBox2, TRUE
        .else
          mov [xsi].dCheckBox2, FALSE
        .endif
        mov xbx, [xsi].pTextView 
        OCall xbx::TextView.Draw
        invoke RedrawWindow, [xbx].$Obj(TextView).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
        
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_TIP
      .if [xdi].TVNM_TIP.dID == INFO_BUILD
        c2m [xdi].TVNM_TIP.pText, $OfsCStr("BuildInfo"), xax

      .elseif [xdi].TVNM_TIP.dID == INFO_UPDATE
        c2m [xdi].TVNM_TIP.pText, $OfsCStr("UpdateInfo"), xax
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_TXT
      .if [xdi].TVNM_TXT.dID == 0
        invoke SetRBTextFrom, addr [xsi].dRadioBtn1, [xdi].TVNM_TXT.ppText 
      .elseif [xdi].TVNM_TXT.dID == 1
        invoke SetRBTextFrom, addr [xsi].dRadioBtn2, [xdi].TVNM_TXT.ppText 
      .elseif [xdi].TVNM_TXT.dID == 2
        invoke SetCBTextFrom, addr [xsi].dCheckBox1, [xdi].TVNM_TXT.ppText 
      .elseif [xdi].TVNM_TXT.dID == 3
        invoke SetCBTextFrom, addr [xsi].dCheckBox2, [xdi].TVNM_TXT.ppText 

      .endif

;    .elseif [xdi].NMHDR.code == TVNMC_DRAW
;      .if [xdi].TVNM_DRAW.dID == 0
;        New Img::Image
;        OCall Img::Image.Init, xsi
;        OCall Img::Image.%LoadFromRes, $OfsCStr("OA")
;        mov DstRect.left, 35
;        mov DstRect.top, 35
;        mov DstRect.right, 100
;        mov DstRect.bottom, 100
;        OCall Img::Image.AlphaDraw, [xdi].TVNM_DRAW.hDC, 255, addr DstRect
;        OCall Img::Image.Done
;      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjPropWnd.Startup
; Purpose:    Registers the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ObjPropWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(ObjPropWnd.WndProc), xdx
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, 0
  mov WC.lpszMenuName, NULL
  m2m WC.lpszClassName, offset cObjPropClass, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_OBJ_STD"))
  mov WC.hIconSm, 0
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

