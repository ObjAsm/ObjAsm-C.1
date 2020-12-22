; ==================================================================================================
; Title:      Json.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of JSON (JavaScript Object Notation) objects.
; Links:      https://www.json.org/json-en.html
;             https://www.ietf.org/rfc/rfc4627.txt
;             https://tools.ietf.org/html/rfc8259
;             https://www.w3schools.com/js/js_json.asp
;             https://jsonformatter.curiousconcept.com/#
; References: RFC8259, RFC7159, RFC4627, EMCA-404
; Notes:      Version C.1.2, December 2020.
;               - First release.
; ==================================================================================================


JSON_TYPE_NULL      equ 0
JSON_TYPE_STRING    equ 1
JSON_TYPE_NUMBER    equ 2
JSON_TYPE_BOOLEAN   equ 3
JSON_TYPE_ARRAY     equ 4
JSON_TYPE_OBJECT    equ 5
JSON_TYPE_ERROR     equ -1

INDENTATION_STEP    equ 2

CStrW JSON_TRUE,  "true"
CStrW JSON_FALSE, "false"
CStrW JSON_NULL,  "null"


PJSON_PROPERTY typedef ptr JSON_PROPERTY
JSON_PROPERTY struc
  pParent       PJSON_PROPERTY  ?
  Siblings      LDLL_MEMBER     <>
  dType         DWORD           ?         ;JSON_TYPE_NULL .. JSON_TYPE_ERROR
  pName         PSTRING         ?
  union
    pValue      PSTRING         ?         ;String representation of the value
    Children    LDLL_CONTROL    <>        ;Reuse this space if no value is assigned to the property
  ends
JSON_PROPERTY ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Json
; Purpose:    This object provides the functionality read and write information in JSON format.
; Note:       Numeric and Boolean values are recognized when reading, but not translated into
;             a value. It is up to the host to interpret the string value and convert it to the
;             desired format, e.g. BYTE, WORD, DWORD, QWORD, REAL4, REAL8 etc.

Object Json, 0, Streamable
  VirtualMethod     AddArray,         PJSON_PROPERTY, PSTRING
  VirtualMethod     AddData,          PJSON_PROPERTY, PSTRING, DWORD, PSTRING
  VirtualMethod     AddObject,        PJSON_PROPERTY, PSTRING
  VirtualMethod     DelProperty,      PJSON_PROPERTY
  RedefineMethod    Done
  VirtualMethod     GetArrayItem,     PJSON_PROPERTY, DWORD
  VirtualMethod     GetPrevProperty,  PJSON_PROPERTY
  VirtualMethod     GetNextProperty,  PJSON_PROPERTY
  VirtualMethod     GetProperty,      PJSON_PROPERTY, PSTRING
  VirtualMethod     Read,             $ObjPtr(Stream)
  VirtualMethod     Write,            $ObjPtr(Stream)
  VirtualMethod     WriteProperty,    $ObjPtr(Stream), PJSON_PROPERTY, POINTER

  DefineVariable    RootProperty,     JSON_PROPERTY,  {, {}, JSON_TYPE_OBJECT, NULL}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.AddArray
; Purpose:    Create a new JSON array.
; Arguments:  Arg1: -> Parent JSON_PROPERTY.
;             Arg2: -> Array name.
; Return:     xax -> JSON_PROPERTY or NULL if failed.

Method Json.AddArray, uses xbx xdi, pParent:PJSON_PROPERTY, pName:PSTRING
  MemAlloc sizeof(JSON_PROPERTY), MEM_INIT_ZERO
  .if xax != NULL
    mov xbx, xax
    mrm [xbx].JSON_PROPERTY.pParent, pParent, xdi
    lea xax, [xdi].JSON_PROPERTY.Children
    lea xcx, [xbx].JSON_PROPERTY.Siblings
    LDLL_Append xax, xcx, xdx
    .if [xdi].JSON_PROPERTY.dType != JSON_TYPE_ARRAY    ;Array items have no name
      mov [xbx].JSON_PROPERTY.pName, $invoke(StrNew, pName)
    .endif
    mov [xbx].JSON_PROPERTY.dType, JSON_TYPE_ARRAY
    mov xax, xbx
  .endif
;  DbgHex xax, "AddArray"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.AddData
; Purpose:    Create a new JSON value.
; Arguments:  Arg1: -> Owner JSON_PROPERTY.
;             Arg2: Property type [JSON_TYPE_STRING, JSON_TYPE_NUMBER, JSON_TYPE_BOOLEAN].
;             Arg3: -> String representation of the value.
; Return:     xax -> JSON_PROPERTY or NULL if failed.

Method Json.AddData, uses xbx xdi,pParent:PJSON_PROPERTY, pName:PSTRING, dType:DWORD, pValue:PSTRING
  MemAlloc sizeof(JSON_PROPERTY), MEM_INIT_ZERO
  .if xax != NULL
    mov xbx, xax
    mrm [xbx].JSON_PROPERTY.pParent, pParent, xdi
    lea xax, [xdi].JSON_PROPERTY.Children
    lea xcx, [xbx].JSON_PROPERTY.Siblings
    LDLL_Append xax, xcx, xdx
    .if [xdi].JSON_PROPERTY.dType != JSON_TYPE_ARRAY    ;Array items have no name
      mov [xbx].JSON_PROPERTY.pName, $invoke(StrNew, pName)
    .endif
    mov eax, dType
    .if eax == JSON_TYPE_STRING || eax == JSON_TYPE_NUMBER || eax == JSON_TYPE_BOOLEAN
      mov [xbx].JSON_PROPERTY.dType, eax
      mov [xbx].JSON_PROPERTY.pValue, $invoke(StrNew, pValue)
    .else
      mov [xbx].JSON_PROPERTY.dType, JSON_TYPE_ERROR
    .endif
    mov xax, xbx
  .endif
;  DbgHex xax, "AddData"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.AddObject
; Purpose:    Create a new JSON object.
; Arguments:  Arg1: -> Owner JSON_PROPERTY.
;             Arg2: -> Object name.
; Return:     xax -> JSON_PROPERTY or NULL if failed.

Method Json.AddObject, uses xbx xdi, pParent:PJSON_PROPERTY, pName:PSTRING
  MemAlloc sizeof(JSON_PROPERTY), MEM_INIT_ZERO
  .if xax != NULL
    mov xbx, xax
    mrm [xbx].JSON_PROPERTY.pParent, pParent, xdi
    lea xax, [xdi].JSON_PROPERTY.Children
    lea xcx, [xbx].JSON_PROPERTY.Siblings
    LDLL_Append xax, xcx, xdx
    .if [xdi].JSON_PROPERTY.dType != JSON_TYPE_ARRAY    ;Array items have no name
      mov [xbx].JSON_PROPERTY.pName, $invoke(StrNew, pName)
    .endif
    mov [xbx].JSON_PROPERTY.dType, JSON_TYPE_OBJECT
    mov xax, xbx
  .endif
;  DbgHex xax, "AddObject"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.Done
; Purpose:    Finalize the Json object.
; Arguments:  None.
; Return:     Nothing.

Method Json.Done, uses xbx xsi
  SetObject xsi
  lea xbx, [xsi].RootProperty
  ;Delete all children recursively
  .while TRUE
    mov xax, [xbx].JSON_PROPERTY.Children.pLastMember
    .break .if xax == NULL
    lea xdx, [xax - offset JSON_PROPERTY.Siblings]
    OCall xsi.DelProperty, xdx
  .endw
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.DelProperty
; Purpose:    Deletes a Json Property.
; Arguments:  Arg1: -> JSON_PROPERTY.
; Return:     Nothing.

Method Json.DelProperty, uses xbx xsi, pProperty:PJSON_PROPERTY
  SetObject xsi
;  DbgHex pProperty, "DelProperty"
  mov xbx, pProperty
  .if xbx != NULL
    mov eax, [xbx].JSON_PROPERTY.dType
    .if eax == JSON_TYPE_STRING || eax == JSON_TYPE_NUMBER || eax == JSON_TYPE_BOOLEAN
      invoke StrDispose, [xbx].JSON_PROPERTY.pValue
    .elseif eax == JSON_TYPE_ARRAY || eax == JSON_TYPE_OBJECT
      ;Delete all children recursively
      .while TRUE
        mov xax, [xbx].JSON_PROPERTY.Children.pLastMember
        .break .if xax == NULL
        lea xdx, [xax - offset JSON_PROPERTY.Siblings]  ;xdx -> JSON_PROPERTY
        OCall xsi.DelProperty, xdx
      .endw
    .endif
    invoke StrDispose, [xbx].JSON_PROPERTY.pName
    mov xdx, [xbx].JSON_PROPERTY.pParent
    lea xax, [xdx].JSON_PROPERTY.Children
    lea xcx, [xbx].JSON_PROPERTY.Siblings
    LDLL_Remove xax, xcx, xdx, xsi
    MemFree xbx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.GetArrayItem
; Purpose:    Get an JSON_PROPERTY from an array at a specific index position.
; Arguments:  Arg1: -> Owner JSON_PROPERTY.
;             Arg2: Index [0..n-1].
; Return:     xax -> JSON_PROPERTY or NULL if not found.

Method Json.GetArrayItem,, pParent:PJSON_PROPERTY, dIndex:DWORD
  mov xax, pParent
  .if xax != NULL
    mov xax, [xax].JSON_PROPERTY.Children.pFirstMember
    mov edx, dIndex
    .while xax != NULL
      lea xcx, [xax - offset JSON_PROPERTY.Siblings]      ;xcx -> JSON_PROPERTY
      .if edx == 0
        mov xax, xcx
        .break
      .endif
      mov xax, [xcx].JSON_PROPERTY.Siblings.pLinkFwrd
      dec edx
    .endw
  .endif
;  DbgHex xax, "GetArrayItem"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.GetPrevProperty
; Purpose:    Get the previous JSON_PROPERTY from a specific JSON_PROPERTY.
; Arguments:  Arg1: -> Starting JSON_PROPERTY.
; Return:     xax -> JSON_PROPERTY or NULL if not found.

Method Json.GetPrevProperty,, pProperty:PJSON_PROPERTY
  mov xax, pProperty
  .if xax != NULL
    mov xax, [xax].JSON_PROPERTY.Siblings.pLinkBack
    .if xax != NULL
      lea xax, [xax - offset JSON_PROPERTY.Siblings]      ;xax -> JSON_PROPERTY
    .endif
  .endif
;  DbgHex xax, "GetNextProperty"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.GetNextProperty
; Purpose:    Get the next JSON_PROPERTY from a specific JSON_PROPERTY.
; Arguments:  Arg1: -> Starting JSON_PROPERTY.
; Return:     xax -> JSON_PROPERTY or NULL if not found.

Method Json.GetNextProperty,, pProperty:PJSON_PROPERTY
  mov xax, pProperty
  .if xax != NULL
    mov xax, [xax].JSON_PROPERTY.Siblings.pLinkFwrd
    .if xax != NULL
      lea xax, [xax - offset JSON_PROPERTY.Siblings]      ;xax -> JSON_PROPERTY
    .endif
  .endif
;  DbgHex xax, "GetNextProperty"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.GetProperty
; Purpose:    Find the JSON_PROPERTY with a specific name.
; Arguments:  Arg1: -> Owner JSON_PROPERTY.
;             Arg2: Property type [JSON_TYPE_STRING, JSON_TYPE_NUMBER, JSON_TYPE_BOOLEAN].
;             Arg3: -> String representation of the value.
; Return:     xax -> JSON_PROPERTY or NULL if not found.

Method Json.GetProperty, uses xbx, pParent:PJSON_PROPERTY, pName:PSTRING
  mov xax, pParent
  .if xax != NULL
    mov xax, [xax].JSON_PROPERTY.Children.pFirstMember
    .while xax != NULL
      lea xbx, [xax - offset JSON_PROPERTY.Siblings]      ;xbx -> JSON_PROPERTY
      invoke StrComp, [xbx].JSON_PROPERTY.pName, pName
      .if eax == 0                                        ;Found if eax = 0
        mov xax, xbx
        .break
      .endif
      mov xax, [xbx].JSON_PROPERTY.Siblings.pLinkFwrd
    .endw
  .endif
;  DbgHex xax, "GetProperty"
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.Read
; Purpose:    Read a JSON object from stream (also known as Parse).
; Arguments:  Arg1: -> Stream.
; Return:     TRUE if succeeded, otherwise FALSE.

;Note: the following helper procedures does not preserve xbx, xdi & xsi, since these registers
;      are used to pass the following values:
;        xbx -> last char + 2.
;        xsi -> current char.
;        xdi -> Json instance when called from Json.Read, otherwise used as volatile register.

JsonSkipBlanks    proto
JsonGetObject     proto :PJSON_PROPERTY
JsonGetStringEnd  proto
JsonGetNumberEnd  proto
JsonGetObject     proto :PJSON_PROPERTY
JsonGetArray      proto :PJSON_PROPERTY
JsonGetValue      proto :PJSON_PROPERTY, :PSTRING

JsonSkipBlanks proc
  ANNOTATION prv:xbx xsi

  mov eax, TRUE                                         ;Always return success = TRUE
  .while TRUE
    .break .if xsi == xbx
    mov cx, [xsi]
    .break .if (cx != " " && cx != 9 && cx != 10 && cx != 13)
    add xsi, sizeof(CHRW)
  .endw
  ret
JsonSkipBlanks endp

JsonGetObject proc pParent:PJSON_PROPERTY
  ANNOTATION prv:xbx xdi xsi
  local pBegin:POINTER, dSize:DWORD

  .while TRUE
    .if xsi == xbx
      xor eax, eax
      ret
    .endif

    invoke JsonSkipBlanks

    mov ax, [xsi]
    .if ax == "}"
      add xsi, sizeof(CHRW)
      mov eax, TRUE                                     ;Return success = TRUE
      ret
    .endif

    .if ax == '"'
      add xsi, sizeof(CHRW)
      mov pBegin, xsi
      invoke JsonGetStringEnd
      .break .if eax == FALSE
      mov xax, xsi
      sub xax, pBegin
      shr eax, $Log2(CHRW)
      dec eax
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        mov dSize, eax
        mov xdi, $invoke(StrAllocA, eax)
        invoke WideCharToMultiByte, CP_ACP, 0, pBegin, dSize, xdi, dSize, NULL, NULL
        mov CHRA ptr [xdi + xax], 0                     ;Set the ZTC
      else
        mov xdi, $invoke(StrCNewW, pBegin, eax)         ;xdi -> Name
      endif
      ;DbgStr xdi

      invoke JsonSkipBlanks
      .if xsi == xbx || CHRW ptr [xsi] != ":"
        xor eax, eax
        .break
      .endif
      add xsi, sizeof(CHRW)
      invoke JsonGetValue, pParent, xdi                 ;Pass xbx & xsi implicitly
      .break .if eax == FALSE

      .if CHRW ptr [xsi] == ","
        add xsi, sizeof(CHRW)
        .continue
      .endif

      .if CHRW ptr [xsi] == "}"
        add xsi, sizeof(CHRW)
        mov eax, TRUE                                   ;Return success = TRUE
        ret
      .endif

    .endif
    xor eax, eax                                        ;Error
    .break
  .endw
  ret
JsonGetObject endp

JsonGetArray proc pParent:PJSON_PROPERTY
  ANNOTATION prv:xbx xsi
  .while TRUE
    .if xsi == xbx
      xor eax, eax
      ret
    .endif

    invoke JsonSkipBlanks

    .if CHRW ptr [xsi] == "]"
      add xsi, sizeof(CHRW)
      mov eax, TRUE                                     ;Return success = TRUE
      .break
    .endif

    invoke JsonGetValue, pParent, NULL                  ;Pass xbx & xsi implicitly
    .break .if eax == FALSE

    .if CHRW ptr [xsi] == ","
      add xsi, sizeof(CHRW)
      .continue
    .endif

    .if CHRW ptr [xsi] == "]"
      add xsi, sizeof(CHRW)
      mov eax, TRUE                                     ;Return success = TRUE
      .break
    .endif

    xor eax, eax                                        ;Error
    .break
  .endw
  ret
JsonGetArray endp

JsonGetStringEnd proc                                   ;On entry, xsi -> first char after "
  ANNOTATION prv:xbx xsi
  xor eax, eax
  .while TRUE
    .break .if xsi == xbx
    mov cx, [xsi]
    add xsi, sizeof(CHRW)
    .if cx == '"'
      inc eax                                           ;Return success = TRUE
      .break
    .endif
  .endw
  ret
JsonGetStringEnd endp

JsonGetNumberEnd proc                                   ;On entry, xsi -> first char in number
  ANNOTATION prv:xbx xsi
  xor eax, eax                                          ;Only allow numbers in the right format
  test xsi, xbx                                         ;[-]([0.(0..9)]|(0..9))([e|E[+|-](0..9)])
  jz @@Exit                                             ;See https://www.json.org/json-en.html
  mov cx, [xsi]
  .if cx == "-"
    add xsi, sizeof(CHRW)
    test xsi, xbx
    jz @@Exit
    mov cx, [xsi]
  .endif
  .if cx == "0"
    add xsi, sizeof(CHRW)
    test xsi, xbx
    jz @@Exit
    mov cx, [xsi]
  .else
    .if cx >= "1" && cx <= "9"
      add xsi, sizeof(CHRW)
      .while TRUE
        test xsi, xbx
        jz @@Exit
        mov cx, [xsi]
        .break .if cx < "0" || cx > "9"
        add xsi, sizeof(CHRW)
      .endw
    .endif
  .endif

  .if cx == "."
    add xsi, sizeof(CHRW)
    xor edx, edx
    .while TRUE
      test xsi, xbx
      jz @@Exit
      mov cx, [xsi]
      .break .if cx < "0" || cx > "9"
      add xsi, sizeof(CHRW)
      .if cx >= "1" && cx <= "9"
        inc edx
      .endif
    .endw
    test edx, edx
    jz @@Exit
  .endif

  .if cx == "E" || cx == "e"
    add xsi, sizeof(CHRW)
    test xsi, xbx
    jz @@Exit
    mov cx, [xsi]
    .if cx == "+" || cx == "-"
      add xsi, sizeof(CHRW)
    .endif
    xor edx, edx
    .while TRUE
      test xsi, xbx
      jz @@Exit
      mov cx, [xsi]
      .break .if cx < "0" || cx > "9"
      add xsi, sizeof(CHRW)
      inc edx
    .endw
    test edx, edx
    jz @@Exit
  .endif

  inc eax                                               ;Return success = TRUE
@@Exit:
  ret
JsonGetNumberEnd endp

JsonGetValue proc pParent:PJSON_PROPERTY, pName:PSTRING
  ANNOTATION prv:xbx xdi xsi
  local pBegin:POINTER, pValue:POINTER, dSize:DWORD

  invoke JsonSkipBlanks
  .if xsi == xbx
    invoke StrDispose, pName                            ;In case of failure, dispose the string
    xor eax, eax
    ret
  .endif

  .if pParent != NULL
    mov xdi, $MemAlloc(sizeof(JSON_PROPERTY), MEM_INIT_ZERO)  ;Create a property
    mrm [xdi].JSON_PROPERTY.pParent, pParent, xdx
    lea xax, [xdx].JSON_PROPERTY.Children               ;xax -> PLDLL_CONTROL
    lea xcx, [xdi].JSON_PROPERTY.Siblings
    LDLL_Append xax, xcx, xdx
  .else
    lea xdi, [xdi].$Obj(Json).RootProperty              ;Only valid when called from Json.read
  .endif
  m2m [xdi].JSON_PROPERTY.pName, pName, xdx

  mov ax, [xsi]
  .if ax == '"'
    add xsi, sizeof(CHRW)
    mov [xdi].JSON_PROPERTY.dType, JSON_TYPE_STRING
    mov pBegin, xsi
    invoke JsonGetStringEnd                             ;Pass xbx & xsi implicitly
    test eax, eax
    jz @@Exit
    mov xax, xsi
    sub xax, pBegin
    shr eax, $Log2(CHRW)
    dec eax
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      mov dSize, eax
      mov pValue, $invoke(StrAllocA, eax)
      invoke WideCharToMultiByte, CP_ACP, 0, pBegin, dSize, pValue, dSize, NULL, NULL
      mov xdx, pValue
      mov CHRA ptr [xdx + xax], 0                       ;Set the ZTC
      mov [xdi].JSON_PROPERTY.pValue, xdx
    else
      mov [xdi].JSON_PROPERTY.pValue, $invoke(StrCNewW, pBegin, eax)
    endif
    ;DbgStr [xdi].JSON_PROPERTY.pValue
    invoke JsonSkipBlanks
    jmp @@Exit
  .endif

  .if ax == "-" || (ax >= "0" && ax <= "9")
    mov [xdi].JSON_PROPERTY.dType, JSON_TYPE_NUMBER
    mov pBegin, xsi
    invoke JsonGetNumberEnd                             ;Pass xbx & xsi implicitly
    test eax, eax
    jz @@Exit
    mov xax, xsi
    sub xax, pBegin
    shr eax, $Log2(CHRW)
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      mov dSize, eax
      mov pValue, $invoke(StrAllocA, eax)
      invoke WideCharToMultiByte, CP_ACP, 0, pBegin, dSize, pValue, dSize, NULL, NULL
      mov xdx, pValue
      mov CHRA ptr [xdx + xax], 0                       ;Set the ZTC
      mov [xdi].JSON_PROPERTY.pValue, xdx
    else
      mov [xdi].JSON_PROPERTY.pValue, $invoke(StrCNewW, pBegin, eax)
    endif
    ;DbgStr [xdi].JSON_PROPERTY.pValue
    invoke JsonSkipBlanks
    jmp @@Exit
  .endif

  .if ax == "{"
    add xsi, sizeof(CHRW)
    mov [xdi].JSON_PROPERTY.dType, JSON_TYPE_OBJECT
    invoke JsonGetObject, addr [xdi].JSON_PROPERTY
    .if eax != FALSE
      invoke JsonSkipBlanks
    .endif
    jmp @@Exit
  .endif

  .if ax == "["
    add xsi, sizeof(CHRW)
    mov [xdi].JSON_PROPERTY.dType, JSON_TYPE_ARRAY
    invoke JsonGetArray, addr [xdi].JSON_PROPERTY
    .if eax != FALSE
      invoke JsonSkipBlanks
    .endif
    jmp @@Exit
  .endif

  DoesWordMatch? [xsi], <true>
  .if ZERO?
    mov [xdi].JSON_PROPERTY.dType, JSON_TYPE_BOOLEAN
    mov [xdi].JSON_PROPERTY.pValue, $invoke(StrNew, offset JSON_TRUE)
    ;DbgStr [xdi].JSON_PROPERTY.pValue
    add xsi, 4*sizeof(CHR)
    mov eax, TRUE
    jmp @@Exit
  .endif

  DoesWordMatch? [xsi], <false>
  .if ZERO?
    mov [xdi].JSON_PROPERTY.dType, JSON_TYPE_BOOLEAN
    mov [xdi].JSON_PROPERTY.pValue, $invoke(StrNew, offset JSON_FALSE)
    ;DbgStr [xdi].JSON_PROPERTY.pValue
    add xsi, 5*sizeof(CHR)
    mov eax, TRUE
    jmp @@Exit
  .endif

  DoesWordMatch? [xsi], <null>
  .if ZERO?
    mov [xdi].JSON_PROPERTY.dType, JSON_TYPE_NULL
    mov [xdi].JSON_PROPERTY.pValue, $invoke(StrNew, offset JSON_NULL)
    ;DbgStr [xdi].JSON_PROPERTY.pValue
    add xsi, 4*sizeof(CHR)
    mov eax, TRUE
    jmp @@Exit
  .endif

  mov [xdi].JSON_PROPERTY.dType, JSON_TYPE_ERROR
  xor eax, eax

@@Exit:
  ret
JsonGetValue endp


Method Json.Read, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local pMemBlockUTF8:POINTER, pMemBlockWide:POINTER

  SetObject xdi
  mov xbx, $OCall(pStream::Stream.GetSize)
  .if eax != -1
    MemAlloc ebx
    .if xax != NULL
      mov pMemBlockUTF8, xax
      OCall pStream::Stream.BinRead, pMemBlockUTF8, ebx
      .if eax != 0
        shl ebx, 1                                      ;Conservative guess
        MemAlloc ebx
        .if xax != NULL
          mov pMemBlockWide, xax
          invoke UTF8ToWide, pMemBlockWide, pMemBlockUTF8, ebx
          mov xsi, pMemBlockWide
          add xbx, xsi

          mov [xdi].RootProperty.JSON_PROPERTY.Siblings.pLinkFwrd, NULL
          mov [xdi].RootProperty.JSON_PROPERTY.Siblings.pLinkBack, NULL
          mov [xdi].RootProperty.JSON_PROPERTY.dType, 0
          mov [xdi].RootProperty.JSON_PROPERTY.Children.pFirstMember, NULL
          mov [xdi].RootProperty.JSON_PROPERTY.Children.pLastMember, NULL

          invoke JsonGetValue, NULL, NULL               ;Pass xbx, xdi & xsi implicitly
          MemFree pMemBlockWide
        .endif
      .endif
      MemFree pMemBlockUTF8
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.Write
; Purpose:    Write a JSON object to stream (also known as Stringify).
; Arguments:  Arg1: -> Stream.
; Return:     TRUE if succeeded, otherwise FALSE.

Method Json.Write,, pStream:$ObjPtr(Stream)
  local dIndentation:DWORD

  SetObject xcx
  mov dIndentation, 0
  OCall xcx::Json.WriteProperty, pStream, addr [xcx].RootProperty, addr dIndentation
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.WriteProperty
; Purpose:    Write a JSON object to stream (also known as Stringify).
; Arguments:  Arg1: -> Stream.
;             Arg2: -> JSON_PROPERTY.
; Return:     TRUE if succeeded, otherwise FALSE.

IndentNow macro
  mov esi, [xdi]
  test esi, esi
  .while !ZERO?
    OCall pStream::Stream.BinWrite8, " "
    dec esi
  .endw
endm

Method Json.WriteProperty, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pProperty:PJSON_PROPERTY, \
                                             pIndentation:POINTER
  mov xbx, pProperty
  mov xdi, pIndentation
  IndentNow

  .if [xbx].JSON_PROPERTY.pName != NULL
    OCall pStream::Stream.BinWrite8, '"'
    invoke StrSize, [xbx].JSON_PROPERTY.pName
    if TARGET_STR_TYPE eq STR_TYPE_WIDE
      shl eax, 1                                        ;Each UTF8 char can have at max 4 bytes
      mov xsi, $MemAlloc(eax)
      invoke WideToUTF8, xsi, [xbx].JSON_PROPERTY.pName, -1
      dec eax                                           ;Discard ZTC
      OCall pStream::Stream.BinWrite, xsi, eax
      MemFree xsi
    else
      dec eax                                           ;Discard ZTC
      OCall pStream::Stream.BinWrite, [xbx].JSON_PROPERTY.pName, eax
    endif
    OCall pStream::Stream.BinWrite, $OfsCStrA('":'), 2
  .endif

  .if [xbx].JSON_PROPERTY.dType == JSON_TYPE_OBJECT
    OCall pStream::Stream.BinWrite, $OfsCStrA("{", 13, 10), 3
    ;Write all children recursively
    mov xsi, [xbx].JSON_PROPERTY.Children.pFirstMember
    add DWORD ptr [xdi], INDENTATION_STEP               ;Increment indentation
    .while xsi != NULL
      lea xax, [xsi - offset JSON_PROPERTY.Siblings]    ;xax -> JSON_PROPERTY
      OCall pSelf::Json.WriteProperty, pStream, xax, xdi
      mov xsi, [xsi].LDLL_MEMBER.pLinkFwrd
      .if xsi != 0
        OCall pStream::Stream.BinWrite, $OfsCStrA(",", 13, 10), 3
      .endif
    .endw
    sub DWORD ptr [xdi], INDENTATION_STEP               ;Decrement indentation
    OCall pStream::Stream.BinWrite, $OfsCStrA(13, 10), 2
    IndentNow
    OCall pStream::Stream.BinWrite8, "}"

  .elseif [xbx].JSON_PROPERTY.dType == JSON_TYPE_ARRAY
    OCall pStream::Stream.BinWrite, $OfsCStrA("[", 13, 10), 3
    mov xsi, [xbx].JSON_PROPERTY.Children.pFirstMember
    add DWORD ptr [xdi], INDENTATION_STEP               ;Increment indentation
    .while xsi != NULL
      lea xax, [xsi - offset JSON_PROPERTY.Siblings]    ;xax -> JSON_PROPERTY
      OCall pSelf::Json.WriteProperty, pStream, xax, xdi
      mov xsi, [xsi].LDLL_MEMBER.pLinkFwrd
      .if xsi != 0
        OCall pStream::Stream.BinWrite, $OfsCStrA(",", 13, 10), 3
      .endif
    .endw
    sub DWORD ptr [xdi], INDENTATION_STEP               ;Decrement indentation
    OCall pStream::Stream.BinWrite, $OfsCStrA(13, 10), 2
    IndentNow
    OCall pStream::Stream.BinWrite8, "]"

  .elseif [xbx].JSON_PROPERTY.dType == JSON_TYPE_STRING
    OCall pStream::Stream.BinWrite8, '"'
    invoke StrSize, [xbx].JSON_PROPERTY.pValue
    if TARGET_STR_TYPE eq STR_TYPE_WIDE
      shl eax, 1                                        ;Each UTF8 char can have at max 4 bytes
      mov xsi, $MemAlloc(eax)
      invoke WideToUTF8, xsi, [xbx].JSON_PROPERTY.pValue, -1
      dec eax                                           ;Discard ZTC
      OCall pStream::Stream.BinWrite, xsi, eax
      MemFree xsi
    else
      dec eax                                           ;Discard ZTC
      OCall pStream::Stream.BinWrite, [xbx].JSON_PROPERTY.pValue, eax
    endif
    OCall pStream::Stream.BinWrite8, '"'

  .elseif [xbx].JSON_PROPERTY.dType == JSON_TYPE_NUMBER || [xbx].JSON_PROPERTY.dType == JSON_TYPE_BOOLEAN
    invoke StrSize, [xbx].JSON_PROPERTY.pValue
    if TARGET_STR_TYPE eq STR_TYPE_WIDE
      shl eax, 1                                        ;Each UTF8 char can have at max 4 bytes
      mov xsi, $MemAlloc(eax)
      invoke WideToUTF8, xsi, [xbx].JSON_PROPERTY.pValue, -1
      dec eax                                           ;Discard ZTC
      OCall pStream::Stream.BinWrite, xsi, eax
      MemFree xsi
    else
      dec eax                                           ;Discard ZTC
      OCall pStream::Stream.BinWrite, [xbx].JSON_PROPERTY.pValue, eax
    endif

  .elseif [xbx].JSON_PROPERTY.dType == JSON_TYPE_NULL
    OCall pStream::Stream.BinWrite, offset JSON_NULL, 4
  .endif
MethodEnd

endif
