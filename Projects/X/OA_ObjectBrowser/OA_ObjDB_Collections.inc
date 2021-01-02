; ==================================================================================================
; Title:      OA_ObjDB_Collections.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Collections managed by the OA_ObjDB.
; Notes:      Version C.1.0, December 2020
;               - First release.
; ==================================================================================================


METHODTYPE_UNKNOWN          equ   0
METHODTYPE_STATIC           equ   1
METHODTYPE_VIRTUAL          equ   2
METHODTYPE_VIRTUAL_ABSTRACT equ   3
METHODTYPE_VIRTUAL_EVENT    equ   4
METHODTYPE_DYNAMIC          equ   5
METHODTYPE_DYNAMIC_ABSTRACT equ   6
METHODTYPE_DYNAMIC_EVENT    equ   7
METHODTYPE_INTERFACE        equ   8
METHODTYPE_INLINE           equ   9
METHODTYPE_REDEFINED        equ   10

METHODTYPE_STANDARD         equ   11
METHODTYPE_DISPATCH         equ   12


VARIABLETYPE_UNKNOWN        equ   0
VARIABLETYPE_REGULAR        equ   1
VARIABLETYPE_REDEFINED      equ   2
VARIABLETYPE_OBJECT         equ   3


FILEINFORMATION struct
  pFileName       PSTRING   ?           ;-> File Name
  LastWrite       FILETIME  <>          ;Date of last write to this file
  dFlags          DWORD     ?           ;Internal maintenance flags
FILEINFORMATION ends
PFILEINFORMATION typedef ptr FILEINFORMATION

INFORMATION struct
  dFlags          DWORD     ?           ;METHODTYPE_XXX, VARIABLETYPE_XXX,
  pName           PSTRING   ?           ;-> Name.
  pFileInfo       PFILEINFORMATION   ?  ;-> FILEINFORMATION structure
  dHelpLineCount  DWORD     ?           ;Number of lines contained in HelpLines
  pHelpData       PSTRING   ?           ;help strings, each string is a consecutive line
INFORMATION ends
PINFORMATION typedef ptr INFORMATION

OBJECTINFORMATION struct
                  INFORMATION {}
  pAncestorName   PSTRING   ?           ;-> Object Ancestor Name
OBJECTINFORMATION ends
POBJECTINFORMATION typedef ptr OBJECTINFORMATION

OBJMTDINFORMATION struct
                  INFORMATION {}
  pObjectName     PSTRING   ?           ;-> Object Name
  pArguments      PSTRING   ?           ;-> "DWORD, DWORD, POINTER"
OBJMTDINFORMATION ends
POBJMTDINFORMATION typedef ptr OBJMTDINFORMATION

OBJVARINFORMATION struct
                  INFORMATION {}
  pObjectName     PSTRING   ?           ;-> Object Name
  pArgType        PSTRING   ?           ;-> "DWORD"
OBJVARINFORMATION ends
POBJVARINFORMATION typedef ptr OBJVARINFORMATION

INTERFACEINFORMATION struct
                  INFORMATION {}
  pAncestorName   PSTRING   ?           ;-> Interface Ancestor Name
INTERFACEINFORMATION ends
PINTERFACEINFORMATION typedef ptr INTERFACEINFORMATION

INTMTDINFORMATION struct
                  INFORMATION {}
  pInterfaceName  PSTRING   ?           ;-> Interface Name
  pArguments      PSTRING   ?           ;-> "DWORD, DWORD, POINTER"
INTMTDINFORMATION ends
PINTMTDINFORMATION typedef ptr INTMTDINFORMATION

IMPMTDINFORMATION struct
                  INFORMATION {}
  pObjectName     PSTRING   ?           ;-> Object Name
  pArguments      PSTRING   ?           ;-> "DWORD, DWORD, POINTER"
IMPMTDINFORMATION ends
PIMPMTDINFORMATION typedef ptr IMPMTDINFORMATION

SCAN_OFF          equ     0
SCAN_ON_START     equ     BIT00
SCAN_ON_REQUEST   equ     BIT01


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    FileCollection
; Purpose:   This collection holds all file references of the object database.

Object FilesCollection, FilesCollectionID, SortedCollection
  RedefineMethod    Compare,        POINTER, POINTER
  RedefineMethod    DestroyItem,    POINTER
  RedefineMethod    GetItem,        $ObjPtr(Stream)
  RedefineMethod    KeyOf,          POINTER
  RedefineMethod    PutItem,        POINTER, POINTER
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    ObjInfoCollection
; Purpose:   This collection holds all object definitions found in the scanned files.

Object ObjInfoCollection, ObjInfoCollectionID, SortedCollection
  RedefineMethod    Compare,        POINTER, POINTER
  RedefineMethod    DestroyItem,    POINTER
  RedefineMethod    GetItem,        $ObjPtr(Stream)
  RedefineMethod    Init,           POINTER, DWORD, DWORD, POINTER
  RedefineMethod    KeyOf,          POINTER
  RedefineMethod    PutItem,        POINTER, POINTER

  DefineVariable    pFilesColl,     POINTER,    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    ObjMtdInfoCollection
; Purpose:   This collection holds all method definitions found in the scanned files.

Object ObjMtdInfoCollection, ObjMtdInfoCollectionID, Collection
  RedefineMethod    DestroyItem,    POINTER
  RedefineMethod    GetItem,        $ObjPtr(Stream)
  RedefineMethod    Init,           POINTER, DWORD, DWORD, POINTER
  RedefineMethod    PutItem,        POINTER, POINTER

  DefineVariable    pFilesColl,     POINTER,    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    ObjVarInfoCollection
; Purpose:   This collection holds all variable definitions found in the scanned files.

Object ObjVarInfoCollection, ObjVarInfoCollectionID, Collection
  RedefineMethod    DestroyItem,    POINTER
  RedefineMethod    GetItem,        $ObjPtr(Stream)
  RedefineMethod    Init,           POINTER, DWORD, DWORD, POINTER
  RedefineMethod    PutItem,        POINTER, POINTER

  DefineVariable    pFilesColl,     POINTER,    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    IntInfoCollection
; Purpose:   This collection holds all interface definitions found in the scanned files.

Object IntInfoCollection, IntInfoCollectionID, SortedCollection
  RedefineMethod    Compare,        POINTER, POINTER
  RedefineMethod    DestroyItem,    POINTER
  RedefineMethod    GetItem,        $ObjPtr(Stream)
  RedefineMethod    KeyOf,          POINTER
  RedefineMethod    Init,           POINTER, DWORD, DWORD, POINTER
  RedefineMethod    PutItem,        POINTER, POINTER

  DefineVariable    pFilesColl,     POINTER,    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    IntMtdInfoCollection
; Purpose:   This collection holds all interface method definitions found in the scanned files.

Object IntMtdInfoCollection, IntMtdInfoCollectionID, Collection
  RedefineMethod    DestroyItem,    POINTER
  RedefineMethod    GetItem,        $ObjPtr(Stream)
  RedefineMethod    Init,           POINTER, DWORD, DWORD, POINTER
  RedefineMethod    PutItem,        POINTER, POINTER

  DefineVariable    pFilesColl,     POINTER,    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    ImpMtdInfoCollection
; Purpose:   This collection holds all implemented methods found in the scanned files.

Object ImpMtdInfoCollection, ImpMtdInfoCollectionID, Collection
  RedefineMethod    DestroyItem,    POINTER
  RedefineMethod    GetItem,        $ObjPtr(Stream)
  RedefineMethod    Init,           POINTER, DWORD, DWORD, POINTER
  RedefineMethod    PutItem,        POINTER, POINTER

  DefineVariable    pFilesColl,     POINTER,    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;  FilesCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FilesCollection.Compare
; Purpose:    Compares the strings Key1 and Key2.
; Arguments:  Arg1: -> First key string.
;             Arg2: -> Second key string.
; Return:     eax = (-)  if Key1 < Key2
;                    0   if Key1 = Key2
;                   (+)  if Key1 > Key2

Method FilesCollection.Compare,, pKeyStr1:POINTER, pKeyStr2:POINTER
  invoke StrIComp, pKeyStr1, pKeyStr2                   ;Without case!
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FilesCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method FilesCollection.DestroyItem,, pItem:POINTER
  mov xax, pItem
  invoke StrDispose, [xax].FILEINFORMATION.pFileName
  MemFree pItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FilesCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream.
; Return:     xax -> New loaded structure.

Method FilesCollection.GetItem, uses xbx, pStream:$ObjPtr(Stream)
  mov xbx, $MemAlloc(FILEINFORMATION)
  mov [xbx].FILEINFORMATION.pFileName, $OCall(pStream::Stream.StrRead)
  OCall pStream::Stream.BinRead, addr [xbx].FILEINFORMATION.LastWrite, sizeof FILETIME
  m2z [xbx].FILEINFORMATION.dFlags                    ;Reset flags
  mov xax, xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FilesCollection.KeyOf
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     xax -> Sorting key of the item.

Method FilesCollection.KeyOf,, pItem:POINTER
  mov xcx, pItem
  mov xax, [xcx].FILEINFORMATION.pFileName
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FilesCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item.
; Return:     Nothing.

Method FilesCollection.PutItem, uses xbx, pStream:POINTER, pItem:POINTER
  mov xbx, pItem
  OCall pStream::Stream.StrWriteA, [xbx].FILEINFORMATION.pFileName
  OCall pStream::Stream.BinWrite, addr [xbx].FILEINFORMATION.LastWrite, sizeof FILETIME
MethodEnd


; ==================================================================================================
;  ObjInfoCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjInfoCollection.Compare
; Purpose:    Compares the strings Key1 and Key2.
; Arguments:  Arg1: -> First key string.
;             Arg2: -> Second key string.
; Return:     eax = (-)  if Key1 < Key2
;                    0   if Key1 = Key2
;                   (+)  if Key1 > Key2

Method ObjInfoCollection.Compare,, pKeyStr1:POINTER, pKeyStr2:POINTER
  invoke StrComp, pKeyStr1, pKeyStr2
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method ObjInfoCollection.DestroyItem, uses xbx xdi, pItem:POINTER
  mov xbx, pItem                                 ;pItem
  invoke StrDispose, [xbx].OBJECTINFORMATION.pName
  invoke StrDispose, [xbx].OBJECTINFORMATION.pAncestorName
  mov xdi, [xbx].OBJECTINFORMATION.pHelpData
  .while xdi != NULL
    mov xax, xdi
    mov xdi, [xdi]
    MemFree xax
  .endw
  MemFree xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream.
; Return:     xax -> New loaded structure.

Method ObjInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local dSize:DWORD

  mov xbx, $MemAlloc(OBJECTINFORMATION)
  mov [xbx].OBJECTINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].OBJECTINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJECTINFORMATION.pAncestorName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJECTINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
;  DbgDec eax
  mov edi, eax
  lea esi, [xbx].OBJECTINFORMATION.pHelpData
  .while edi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke GlobalAlloc, 0, eax
    mov [xsi], xax
    mov esi, eax
    add eax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
;    DbgStr BYTE ptr [xsi + sizeof(POINTER)]
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                     ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].OBJECTINFORMATION.pFileInfo, xax
  mov eax, ebx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjInfoCollection.KeyOf
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     xax -> Sorting key of the item.

Method ObjInfoCollection.KeyOf,, pItem:POINTER
  mov xcx, pItem
  mov xax, [xcx].OBJECTINFORMATION.pName
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method ObjInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, pFilesColl:POINTER
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  mov [xcx].dDuplicates, TRUE
  ACall xcx.Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item.
; Return:     Nothing.

Method ObjInfoCollection.PutItem, uses xbx xdi, pStream:POINTER, pItem:POINTER
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].OBJECTINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].OBJECTINFORMATION.pName
  OCall pStream::Stream.StrWriteA, [xbx].OBJECTINFORMATION.pAncestorName
  OCall pStream::Stream.BinWrite32, [xbx].OBJECTINFORMATION.dHelpLineCount
;  DbgDec [xbx].OBJECTINFORMATION.dHelpLineCount
  mov xdi, [xbx].OBJECTINFORMATION.pHelpData
  .while xdi != NULL
    lea xcx, [xdi + 4]
;    DbgStr ecx
    OCall pStream::Stream.StrWriteA, xcx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].OBJECTINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
MethodEnd


; ==================================================================================================
;  ObjMtdInfoCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjMtdInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method ObjMtdInfoCollection.DestroyItem, uses xbx xdi, pItem:POINTER
  mov xbx, pItem
  invoke StrDispose, [xbx].OBJMTDINFORMATION.pObjectName
  invoke StrDispose, [xbx].OBJMTDINFORMATION.pName
  invoke StrDispose, [xbx].OBJMTDINFORMATION.pArguments
  mov xdi, [xbx].OBJMTDINFORMATION.pHelpData
  .while xdi != NULL
    mov xax, xdi
    mov xdi, [xdi]
    MemFree xax
  .endw
  MemFree xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjMtdInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream.
; Return:     xax -> New loaded structure.

Method ObjMtdInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local dSize:DWORD

  mov xbx, $MemAlloc(OBJMTDINFORMATION)
  mov [xbx].OBJMTDINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].OBJMTDINFORMATION.pObjectName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJMTDINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJMTDINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
;  DbgDec xax
  mov xdi, xax
  lea xsi, [xbx].OBJMTDINFORMATION.pHelpData
  .while xdi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke GlobalAlloc, 0, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
;    DbgStr BYTE ptr [xsi + sizeof(POINTER)]
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                     ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].OBJMTDINFORMATION.pFileInfo, xax
  mov [xbx].OBJMTDINFORMATION.pArguments, $OCall(pStream::Stream.StrRead)
  mov xax, xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjMtdInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method ObjMtdInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, pFilesColl:POINTER
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  ACall xcx.Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjMtdInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item.
; Return:     Nothing.

Method ObjMtdInfoCollection.PutItem, uses xbx xdi, pStream:POINTER, pItem:POINTER
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].OBJMTDINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].OBJMTDINFORMATION.pObjectName
  OCall pStream::Stream.StrWriteA, [xbx].OBJMTDINFORMATION.pName
  OCall pStream::Stream.BinWrite32, [xbx].OBJMTDINFORMATION.dHelpLineCount
;  DbgDec [xbx].OBJMTDINFORMATION.dHelpLineCount
  mov xdi, [xbx].OBJMTDINFORMATION.pHelpData
  .while xdi != NULL
    lea xcx, [xdi + 4]
;    DbgStr ecx
    OCall pStream::Stream.StrWriteA, xcx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].OBJMTDINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
  OCall pStream::Stream.StrWriteA, [xbx].OBJMTDINFORMATION.pArguments
MethodEnd


; ==================================================================================================
;  ObjVarInfoCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjVarInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method ObjVarInfoCollection.DestroyItem, uses xbx xdi, pItem:POINTER
  mov xbx, pItem
  invoke StrDispose, [xbx].OBJVARINFORMATION.pObjectName
  invoke StrDispose, [xbx].OBJVARINFORMATION.pName
  invoke StrDispose, [xbx].OBJVARINFORMATION.pArgType
  mov xdi, [xbx].OBJVARINFORMATION.pHelpData
  .while xdi != NULL
    mov xax, xdi
    mov xdi, [xdi]
    MemFree xax
  .endw
  MemFree xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjVarInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream.
; Return:     xax -> New loaded structure.

Method ObjVarInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local dSize:DWORD

  mov xbx, $MemAlloc(OBJVARINFORMATION)
  mov [xbx].OBJVARINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].OBJVARINFORMATION.pObjectName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJVARINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJVARINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
;  DbgDec eax
  mov xdi, xax
  lea xsi, [xbx].OBJVARINFORMATION.pHelpData
  .while xdi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke GlobalAlloc, 0, eax
    mov [xsi], xax
    mov esi, eax
    add eax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
;    DbgStr BYTE ptr [xsi + sizeof(POINTER)]
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                     ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].OBJVARINFORMATION.pFileInfo, xax
  mov [xbx].OBJVARINFORMATION.pArgType, $OCall(pStream::Stream.StrRead)
  mov xax, xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjVarInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method ObjVarInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, pFilesColl:POINTER
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  ACall xcx.Init, pOwner, dLimit, dLimit, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjVarInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item.
; Return:     Nothing.

Method ObjVarInfoCollection.PutItem, uses xbx xdi, pStream:POINTER, pItem:POINTER
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].OBJVARINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].OBJVARINFORMATION.pObjectName
  OCall pStream::Stream.StrWriteA, [xbx].OBJVARINFORMATION.pName
  OCall pStream::Stream.BinWrite32, [xbx].OBJVARINFORMATION.dHelpLineCount
  mov xdi, [xbx].OBJVARINFORMATION.pHelpData
  .while xdi != NULL
    lea xcx, [xdi + 4]
;    DbgStr xcx
    OCall pStream::Stream.StrWriteA, xcx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].OBJVARINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
  OCall pStream::Stream.StrWriteA, [xbx].OBJVARINFORMATION.pArgType
MethodEnd


; ==================================================================================================
;  IntInfoCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntInfoCollection.Compare
; Purpose:    Compares the strings Key1 and Key2.
; Arguments:  Arg1: -> First key string.
;             Arg2: -> Second key string.
; Return:     eax = (-)  if Key1 < Key2
;                    0   if Key1 = Key2
;                   (+)  if Key1 > Key2

Method IntInfoCollection.Compare,, pKeyStr1:POINTER, pKeyStr2:POINTER
  invoke StrComp, pKeyStr1, pKeyStr2
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method IntInfoCollection.DestroyItem, uses xbx xdi, pItem:POINTER
  mov xbx, pItem
  invoke StrDispose, [xbx].INTERFACEINFORMATION.pName
  invoke StrDispose, [xbx].INTERFACEINFORMATION.pAncestorName
  mov xdi, [xbx].INTERFACEINFORMATION.pHelpData
  .while xdi != NULL
    mov xax, xdi
    mov xdi, [xdi]
    MemFree xax
  .endw
  MemFree xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream object containing an object.
; Return:     xax -> New loaded structure.

Method IntInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local dSize:DWORD

  mov xbx, $MemAlloc(INTERFACEINFORMATION)
  mov [xbx].INTERFACEINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].INTERFACEINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].INTERFACEINFORMATION.pAncestorName, $OCall(pStream::Stream.StrRead)
  mov [xbx].INTERFACEINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
;  DbgDec eax
  mov edi, eax
  lea xsi, [xbx].INTERFACEINFORMATION.pHelpData
  .while edi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke GlobalAlloc, 0, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
;    DbgStr BYTE ptr [xsi + sizeof(POINTER)]
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].INTERFACEINFORMATION.pFileInfo, xax
  mov xax, xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntInfoCollection.KeyOf
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     xax -> Sorting key of the item.

Method IntInfoCollection.KeyOf,, pItem:POINTER
  mov xcx, pItem
  mov xax, [xcx].INTERFACEINFORMATION.pName
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method IntInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, pFilesColl:POINTER
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  mov [xcx].dDuplicates, TRUE
  ACall xcx.Init, pOwner, dLimit, dLimit, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item.
; Return:     Nothing.

Method IntInfoCollection.PutItem, uses xbx xdi, pStream:POINTER, pItem:POINTER
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].INTERFACEINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].INTERFACEINFORMATION.pName
  OCall pStream::Stream.StrWriteA, [xbx].INTERFACEINFORMATION.pAncestorName
  OCall pStream::Stream.BinWrite32, [xbx].INTERFACEINFORMATION.dHelpLineCount
  mov xdi, [xbx].INTERFACEINFORMATION.pHelpData
  .while xdi != NULL
    lea xcx, [xdi + 4]
;    DbgStr xcx
    OCall pStream::Stream.StrWriteA, xcx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].INTERFACEINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
MethodEnd


; ==================================================================================================
;  IntMtdInfoCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntMtdInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method IntMtdInfoCollection.DestroyItem, uses xbx xdi, pItem:POINTER
  mov xbx, pItem
  invoke StrDispose, [xbx].INTMTDINFORMATION.pInterfaceName
  invoke StrDispose, [xbx].INTMTDINFORMATION.pName
  invoke StrDispose, [xbx].INTMTDINFORMATION.pArguments
  mov xdi, [xbx].INTMTDINFORMATION.pHelpData
  .while xdi != NULL
    mov xax, xdi
    mov xdi, [xdi]
    MemFree xax
  .endw
  MemFree xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntMtdInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream object containing an object.
; Return:     xax -> New loaded structure.

Method IntMtdInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local dSize:DWORD

  mov xbx, $MemAlloc(INTMTDINFORMATION)
  mov [xbx].INTMTDINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].INTMTDINFORMATION.pInterfaceName, $OCall(pStream::Stream.StrRead)
  mov [xbx].INTMTDINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].INTMTDINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
;  DbgDec xax
  mov xdi, xax
  lea xsi, [xbx].INTMTDINFORMATION.pHelpData
  .while xdi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke GlobalAlloc, 0, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
;    DbgStr BYTE ptr [xsi + sizeof(POINTER)]
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                     ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].INTMTDINFORMATION.pFileInfo, xax
  mov [xbx].INTMTDINFORMATION.pArguments, $OCall(pStream::Stream.StrRead)
  mov xax, xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntMtdInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method IntMtdInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, pFilesColl:POINTER
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  ACall xcx.Init, pOwner, dLimit, dLimit, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntMtdInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item.
; Return:     Nothing.

Method IntMtdInfoCollection.PutItem, uses xbx xdi, pStream:POINTER, pItem:POINTER
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].INTMTDINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].INTMTDINFORMATION.pInterfaceName
  OCall pStream::Stream.StrWriteA, [xbx].INTMTDINFORMATION.pName
  OCall pStream::Stream.BinWrite32, [xbx].INTMTDINFORMATION.dHelpLineCount
  mov xdi, [xbx].INTMTDINFORMATION.pHelpData
  .while xdi != NULL
    lea xcx, [xdi + 4]
;    DbgStr ecx
    OCall pStream::Stream.StrWriteA, xcx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].INTERFACEINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
  OCall pStream::Stream.StrWriteA, [xbx].INTMTDINFORMATION.pArguments
MethodEnd


; ==================================================================================================
;  ImpMtdInfoCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ImpMtdInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     Nothing.

Method ImpMtdInfoCollection.DestroyItem, uses xbx xdi, pItem:POINTER
  mov xbx, pItem
  invoke StrDispose, [xbx].IMPMTDINFORMATION.pObjectName
  invoke StrDispose, [xbx].IMPMTDINFORMATION.pName
  invoke StrDispose, [xbx].IMPMTDINFORMATION.pArguments
  mov xdi, [xbx].IMPMTDINFORMATION.pHelpData
  .while xdi != NULL
    mov xax, xdi
    mov xdi, [xdi]
    MemFree xax
  .endw
  MemFree xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ImpMtdInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream object containing an object.
; Return:     xax -> New loaded structure.

Method ImpMtdInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream)
  local dSize:DWORD

  mov xbx, $MemAlloc(IMPMTDINFORMATION)
  mov [xbx].IMPMTDINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].IMPMTDINFORMATION.pObjectName, $OCall(pStream::Stream.StrRead)
  mov [xbx].IMPMTDINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].IMPMTDINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
;  DbgDec eax
  mov edi, eax
  lea xsi, [xbx].IMPMTDINFORMATION.pHelpData
  .while edi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke GlobalAlloc, 0, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
;    DbgStr BYTE ptr [xsi + sizeof(POINTER)]
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                     ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].IMPMTDINFORMATION.pFileInfo, xax
  mov [xbx].IMPMTDINFORMATION.pArguments, $OCall(pStream::Stream.StrRead)
  mov xax, xbx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ImpMtdInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method ImpMtdInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, pFilesColl:POINTER
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  ACall xcx.Init, pOwner, dLimit, dLimit, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ImpMtdInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item.
; Return:     Nothing.

Method ImpMtdInfoCollection.PutItem, uses xbx xdi, pStream:POINTER, pItem:POINTER
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].IMPMTDINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].IMPMTDINFORMATION.pObjectName
  OCall pStream::Stream.StrWriteA, [xbx].IMPMTDINFORMATION.pName
  OCall pStream::Stream.BinWrite32, [xbx].IMPMTDINFORMATION.dHelpLineCount
  mov xdi, [xbx].IMPMTDINFORMATION.pHelpData
  .while xdi != NULL
    lea xcx, [xdi + 4]
;    DbgStr xcx
    OCall pStream::Stream.StrWriteA, xcx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].IMPMTDINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
  OCall pStream::Stream.StrWriteA, [xbx].IMPMTDINFORMATION.pArguments
MethodEnd

endif