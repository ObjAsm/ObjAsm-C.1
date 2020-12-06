; ==================================================================================================
; Title:      Json.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of JSON objects.
; Links:      https://www.w3schools.com/js/js_json.asp
;             https://jsonformatter.curiousconcept.com/#
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

CStrA JSON_NULL,  "null"
CStrA JSON_TRUE,  "true"
CStrA JSON_FALSE, "false"


JSON_PROPERTY struc
  pOwner        PLDLL_CONTROL ?
  Siblings      LDLL_MEMBER   <>
  dType         DWORD         ?         ;JSON_TYPE_NULL .. JSON_TYPE_ERROR
  pName         PSTRING       ?
  union
    Children    LDLL_CONTROL  <>
    pValue      PSTRING       ?         ;String representation of the value
  ends
JSON_PROPERTY ends
PJSON_PROPERTY typedef ptr JSON_PROPERTY

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Json
; Purpose:    This object provides the functionality read and write information in JSON format.

Object Json, 0, Streamable
  VirtualMethod     AddArray,       PJSON_PROPERTY, PSTRING
  VirtualMethod     AddData,        PJSON_PROPERTY, PSTRING, DWORD, PSTRING
  VirtualMethod     AddObject,      PJSON_PROPERTY, PSTRING

  VirtualMethod     DelProperty,    PJSON_PROPERTY
  RedefineMethod    Done
  VirtualMethod     GetArrayItem,   PJSON_PROPERTY, DWORD
  VirtualMethod     GetPrevProperty,PJSON_PROPERTY
  VirtualMethod     GetNextProperty,PJSON_PROPERTY
  VirtualMethod     GetProperty,    PJSON_PROPERTY, PSTRING
;  VirtualMethod     ReadProperty,   $ObjPtr(Stream)
  VirtualMethod     Write,          $ObjPtr(Stream)
  VirtualMethod     WriteProperty,  $ObjPtr(Stream), PJSON_PROPERTY, POINTER

  DefineVariable    RootProperty,   JSON_PROPERTY,  {, {}, JSON_TYPE_OBJECT, NULL}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Json.AddArray
; Purpose:    Create a new JSON array.
; Arguments:  Arg1: -> Owner JSON_PROPERTY.
;             Arg2: -> Array name.
; Return:     xax -> JSON_PROPERTY or NULL if failed.

Method Json.AddArray, uses xbx xdi, pOwner:PJSON_PROPERTY, pName:PSTRING
  MemAlloc sizeof(JSON_PROPERTY), MEM_INIT_ZERO
  .if xax != NULL
    mov xbx, xax
    mrm [xbx].JSON_PROPERTY.pOwner, pOwner, xdi
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

Method Json.AddData, uses xbx xdi, pOwner:PJSON_PROPERTY, pName:PSTRING, dType:DWORD, pValue:PSTRING
  MemAlloc sizeof(JSON_PROPERTY), MEM_INIT_ZERO
  .if xax != NULL
    mov xbx, xax
    mrm [xbx].JSON_PROPERTY.pOwner, pOwner, xdi
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

Method Json.AddObject, uses xbx xdi, pOwner:PJSON_PROPERTY, pName:PSTRING
  MemAlloc sizeof(JSON_PROPERTY), MEM_INIT_ZERO
  .if xax != NULL
    mov xbx, xax
    mrm [xbx].JSON_PROPERTY.pOwner, pOwner, xdi
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
    mov xdx, [xbx].JSON_PROPERTY.pOwner
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

Method Json.GetArrayItem,, pOwner:PJSON_PROPERTY, dIndex:DWORD
  mov xax, pOwner
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

Method Json.GetProperty, uses xbx, pOwner:PJSON_PROPERTY, pName:PSTRING
  mov xax, pOwner
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

Method Json.Read,, pStream:$ObjPtr(Stream)
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
