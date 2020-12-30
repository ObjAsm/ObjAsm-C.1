; ==================================================================================================
; Title:      OA_ObjDB.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Object Database and associated collections.
; Notes:      Version C.1.0, December 2020
;               - First release.
; ==================================================================================================


DATABASE_VERSION            equ   1

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

FIF_STANDARD                equ   BIT00           ;It's a file from the standard folders
FIF_SCANNED                 equ   BIT01           ;File has been scanned in the current session

INF_INTERFACE               equ   BIT31           ;This Info is about a COM interface

CStr  cInfoFileName,        "%OBJASM_PATH%\Code\OA_Info.stm"
CStr  cScanInclude,         "Scan Include"
CStr  cScanExclude,         "Scan Exclude"
CStr  cSetup,               "Setup"
CStr  cScanOn,              "ScanOn"
CStr  cSave,                "Save"
CStr  cStart,               "Start"
CStr  cYes,                 "Yes"

CStr  cREXP_ListItem,       "^[ \t,]*([\.\w]*)[ \t,]*"

CStrA bComment,             "COMMENT"
CStrA bMethod,              "Method"
CStrA bMacro,               "macro"
CStrA bObject,              "Object"
CStrA bObjectEnd,           "ObjectEnd"
CStrA bVirtualMethod,       "VirtualMethod"
CStrA bStaticMethod,        "StaticMethod"
CStrA bDynamicMethod,       "DynamicMethod"
CStrA bInterfaceMethod,     "InterfaceMethod"
CStrA bInlineMethod,        "InlineMethod"
CStrA bVirtualAbstract,     "VirtualAbstract"
CStrA bDynamicAbstract,     "DynamicAbstract"
CStrA bInterfaceAbstract,   "InterfaceAbstract"
CStrA bObsoleteMethod,      "ObsoleteMethod"
CStrA bRedefineMethod,      "RedefineMethod"
CStrA bEvent,               "Event"
CStrA bDynamicEvent,        "DynamicEvent"
CStrA bVirtualEvent,        "VirtualEvent"
CStrA bDefineVariable,      "DefineVariable"
CStrA bRedefineVariable,    "RedefineVariable"
CStrA bEmbed,               "Embed"
CStrA bSetObject,           "SetObject"
CStrA bBeginInterface,      "BEGIN_INTERFACE"
CStrA bEndInterface,        "END_INTERFACE"
CStrA bStdMethod,           "STDMETHOD"
CStrA bDispMethod,          "DISPMETHOD"

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


;Collections managed by the OA_ObjDB

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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    TextSource
; Purpose:   Text reading managment.

Object TextSource,, Primer
  RedefineMethod    Done
  StaticMethod      GetPrevLine
  StaticMethod      GetNextArgument
  StaticMethod      GetNextLine
  StaticMethod      GetNextWord
  RedefineMethod    Init,           POINTER, POINTER  ;-> Owner, -> FileName
  StaticMethod      Reset

  DefineVariable    pSource,        $ObjPtr(DiskStream), NULL  ;-> Disk Stream
  DefineVariable    dTotalSize,     DWORD,      0     ;Total character count in text source
  DefineVariable    dSrcPos,        DWORD,      0     ;Current position in text source
  DefineVariable    bCommentChar,   CHRA,       0     ;Used internally by GetNextWord
  DefineVariable    pFileLinesBuff, POINTER,    0     ;Buffer retunred by GetFileLinesA

  Embed   MemStream,  MemoryStream                    ;Local line buffer
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:    OA_ObjDB
; Purpose:   Object database engine.

Object OA_ObjDB, OA_ObjDBID, Primer
  StaticMethod      RemoveFileInfo,     PSTRING
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, $ObjPtr(IniFile)
  StaticMethod      Open,               PSTRING
  StaticMethod      Save,               PSTRING
  StaticMethod      ScanFile,           POINTER, FILETIME, DWORD
  StaticMethod      ScanDBFiles
  StaticMethod      ScanDirFiles,       POINTER

  DefineVariable    ObjLock,            OBJECT_LOCK,  {}
  DefineVariable    cStmFileName,       CHR,          MAX_PATH dup (0)
  DefineVariable    dScanOn,            DWORD,        SCAN_OFF
  DefineVariable    dDoSave,            DWORD,        FALSE

  Embed             FilesColl,          FilesCollection
  Embed             InterfaceColl,      IntInfoCollection
  Embed             IntMethodColl,      IntMtdInfoCollection

  Embed             ObjectColl,         ObjInfoCollection
  Embed             ObjMethodColl,      ObjMtdInfoCollection
  Embed             ObjVariableColl,    ObjVarInfoCollection

  Embed             ImpMethodColl,      ImpMtdInfoCollection

% Embed             REX_Parse_ListItem, RegEx

  Embed             ScanInclude,        DataCollection
  Embed             ScanExclude,        DataCollection
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;  OA_ObjDB
; ==================================================================================================

;##\

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.RemoveFileInfo
; Purpose:    Removes all entries in the info collections related to a specified FileName.
; Arguments:  Arg1: -> Filename.
; Return:     Nothing.

align ALIGN_CODE
DelMatchingObjVariable proc pItem:POINTER, pFileInfo:POINTER, pColl:POINTER
  mov xax, pItem
  mov xcx, [xax].OBJVARINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::ObjVarInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingObjVariable endp

align ALIGN_CODE
DelMatchingObjMethod proc pItem:POINTER, pFileInfo:POINTER, pColl:POINTER
  mov xax, pItem
  mov xcx, [xax].OBJMTDINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::ObjMtdInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingObjMethod endp

align ALIGN_CODE
DelMatchingObject proc pItem:POINTER, pFileInfo:POINTER, pColl:POINTER
  mov xax, pItem
  mov xcx, [xax].OBJECTINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::ObjInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingObject endp

align ALIGN_CODE
DelMatchingIntMethod proc pItem:POINTER, pFileInfo:POINTER, pColl:POINTER
  mov xax, pItem
  mov xcx, [xax].INTMTDINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::IntMtdInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingIntMethod endp

align ALIGN_CODE
DelMatchingInterface proc pItem:POINTER, pFileInfo:POINTER, pColl:POINTER
  mov xax, pItem
  mov xcx, [xax].INTERFACEINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::IntInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingInterface endp

align ALIGN_CODE
DelMatchingImpMethod proc pItem:POINTER, pFileInfo:POINTER, pColl:POINTER
  mov xax, pItem
  mov xcx, [xax].IMPMTDINFORMATION.pFileInfo
  .if xcx == pFileInfo
    OCall pColl::ImpMtdInfoCollection.Dispose, pItem
  .endif
  ret
DelMatchingImpMethod endp

Method OA_ObjDB.RemoveFileInfo, uses xbx xdi xsi, pFileName:PSTRING
  SetObject xsi
  OCall [xsi].FilesColl::FilesCollection.Search, pFileName
  .if eax != FALSE
    mov edi, ecx
    mov xbx, $OCall([xsi].FilesColl::FilesCollection.ItemAt, ecx)
    lea xax, [xsi].ObjVariableColl
    OCall xax::ObjVarInfoCollection.ForEachRev, offset DelMatchingObjVariable, xbx, xax
    lea xax, [xsi].ObjMethodColl
    OCall xax::ObjMtdInfoCollection.ForEachRev, offset DelMatchingObjMethod, xbx, xax
    lea xax, [xsi].ObjectColl
    OCall xax::ObjInfoCollection.ForEachRev, offset DelMatchingObject, xbx, xax
    lea xax, [xsi].IntMethodColl
    OCall xax::IntMtdInfoCollection.ForEachRev, offset DelMatchingIntMethod, xbx, xax
    lea xax, [xsi].InterfaceColl
    OCall xax::IntInfoCollection.ForEachRev, offset DelMatchingInterface, xbx, xax
    lea xax, [xsi].ImpMethodColl
    OCall xax::ImpMtdInfoCollection.ForEachRev, offset DelMatchingImpMethod, xbx, xax
    OCall [xsi].FilesColl::FilesCollection.DisposeAt, edi
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.Done
; Purpose:    Finalizes the object, freeing all allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method OA_ObjDB.Done, uses xsi
  SetObject xsi
  OCall [xsi].FilesColl::FilesCollection.Done
  OCall [xsi].ObjectColl::ObjInfoCollection.Done
  OCall [xsi].ObjMethodColl::ObjMtdInfoCollection.Done
  OCall [xsi].ObjVariableColl::ObjVarInfoCollection.Done
  OCall [xsi].InterfaceColl::IntInfoCollection.Done
  OCall [xsi].IntMethodColl::IntMtdInfoCollection.Done
  OCall [xsi].ImpMethodColl::ImpMtdInfoCollection.Done

  OCall [xsi].ScanInclude::DataCollection.Done
  OCall [xsi].ScanExclude::DataCollection.Done

  %OCall [xsi].REX_Parse_ListItem::RegEx.Done

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RemoveUnusedInfo
; Purpose:    Remove unused structures from the Object database.
; Arguments:  Arg1: -> FILEINFORMATION
;             Arg2: -> Self.
; Return:     Nothing.

RemoveUnusedInfo proc pFileInfo:POINTER, Self:POINTER
  ;Remove untagged files and related info from collections
  mov xax, pFileInfo
  .if [xax].FILEINFORMATION.dFlags == 0
    OCall Self::OA_ObjDB.RemoveFileInfo, [xax].FILEINFORMATION.pFileName
  .endif
  ret
RemoveUnusedInfo endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.Init
; Purpose:    Initializes a OA_ObjDB object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Full path Ini file name.
; Return:     Nothing.

Method OA_ObjDB.Init, uses xbx xdi xsi, pOwner:POINTER, pIniFile:$ObjPtr(IniFile)
  local dHasChanged:DWORD
  local cBuffer[1024]:CHR

  SetObject xsi

  lea xbx, [xsi].FilesColl
  OCall xbx::FilesCollection.Init, xsi, 50, 25, COL_MAX_CAPACITY

  OCall [xsi].ObjectColl::ObjInfoCollection.Init, xsi, 50, 50, xbx
  OCall [xsi].ObjMethodColl::ObjMtdInfoCollection.Init, xsi, 100, 100, xbx
  OCall [xsi].ObjVariableColl::ObjVarInfoCollection.Init, xsi, 100, 100, xbx

  OCall [xsi].InterfaceColl::IntInfoCollection.Init, xsi, 50, 50, xbx
  OCall [xsi].IntMethodColl::IntMtdInfoCollection.Init, xsi, 100, 100, xbx
  OCall [xsi].ImpMethodColl::ImpMtdInfoCollection.Init, xsi, 100, 100, xbx

  mov xbx, $OCall(pIniFile::IniFile.GetString, offset cSetup, offset cScanOn, offset cStart)
  invoke StrComp, xbx, offset cStart
  .if eax == 0
    mov [xsi].dScanOn, SCAN_ON_START
  .endif
  invoke StrDispose, xbx

  mov xbx, $OCall(pIniFile::IniFile.GetString, offset cSetup, offset cSave, offset cYes)
  invoke StrComp, xbx, offset cYes
  .if eax == 0
    mov [xsi].dDoSave, TRUE
  .endif
  invoke StrDispose, xbx

  OCall [xsi].ScanInclude::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  xor edi, edi
  .repeat
    invoke dword2dec, addr cBuffer, edi
    mov xbx, $OCall(pIniFile::IniFile.GetString, offset cScanInclude, addr cBuffer, offset szNULL)
    .if edi > 0 && CHR ptr [xax] == 0
      invoke StrDispose, xbx
      .break
    .endif
    invoke ExpandEnvironmentStrings, xbx, addr cBuffer, lengthof(cBuffer) - 1
    invoke StrDispose, xbx
    invoke StrNew, addr cBuffer
    OCall [xsi].ScanInclude::DataCollection.Insert, xax
    inc edi
  .until FALSE

  OCall [xsi].ScanExclude::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  xor edi, edi
  .repeat
    invoke dword2dec, addr cBuffer, edi
    mov xbx, $OCall(pIniFile::IniFile.GetString, offset cScanExclude, addr cBuffer, offset szNULL)
    .if edi > 0 && CHR ptr [xax] == 0
      invoke StrDispose, xbx
      .break
    .endif
    invoke ExpandEnvironmentStrings, xbx, addr cBuffer, lengthof(cBuffer) - 1
    invoke StrNew, addr cBuffer
    OCall [xsi].ScanExclude::DataCollection.Insert, xax
    inc edi
  .until FALSE

  lea xbx, [xsi].REX_Parse_ListItem
  %OCall xbx::RegEx.Init, xsi, offset cREXP_ListItem, 0
  %OCall xbx::RegEx.SetOutCount, -1
  %OCall xbx::RegEx.Study, 0

  ;Load data from .stm file
  lea xdi, [xsi].cStmFileName
  invoke ExpandEnvironmentStrings, offset cInfoFileName, xdi, MAX_PATH
  .if $invoke(FileExist, xdi) != FALSE
    OCall xsi.Open, xdi
  .endif

  ;Check if something has changed in the following folders and rebuild if necessary
  mov dHasChanged, FALSE
  .ifBitSet [xsi].dScanOn, SCAN_ON_START
    mov ebx, 1
    .while ebx < [xsi].ScanInclude.dCount
      OCall [xsi].ScanInclude::DataCollection.ItemAt, ebx
      OCall xsi.ScanDirFiles, xax
      or dHasChanged, eax                               ;Update flag
      inc ebx
    .endw

    .if dHasChanged != FALSE
      ;Remove unused entries
      OCall [xsi].FilesColl::FilesCollection.ForEachRev, offset RemoveUnusedInfo, xsi, NULL
      ;Save to .stm file
      .if [xsi].dDoSave != FALSE
        OCall xsi.Save, xdi
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.Open
; Purpose:    Reads the DB content from a binary file.
; Arguments:  Arg1: -> File name.
; Return:     Nothing.

Method OA_ObjDB.Open, uses xbx xsi, pFileName:PSTRING
  local DskStm:$Obj(DiskStream)

  SetObject xsi
  mov xbx, $New(DskStm::DiskStream)
  OCall xbx::DiskStream.Init, xsi, pFileName, 0, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
  OCall xbx::DiskStream.BinRead32                     ;Read file version
  .if eax == DATABASE_VERSION
    DbgText "Reading Database..."
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].FilesColl::FilesCollection.Load, xbx, xsi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].ObjectColl::ObjInfoCollection.Load, xbx, xsi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].ObjMethodColl::ObjMtdInfoCollection.Load, xbx, xsi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].ObjVariableColl::ObjVarInfoCollection.Load, xbx, xsi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].InterfaceColl::IntInfoCollection.Load, xbx, xsi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].IntMethodColl::IntMtdInfoCollection.Load, xbx, xsi
    OCall xbx::DiskStream.BinRead32                   ;eax = Object Class ID
    OCall [xsi].ImpMethodColl::ImpMtdInfoCollection.Load, xbx, xsi
  .endif
  OCall xbx::DiskStream.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.Save
; Purpose:    Saves the DB content to a binary file.
; Arguments:  Arg1: -> file name.
; Return:     Nothing.

Method OA_ObjDB.Save, uses xbx xsi, pFileName:PSTRING
  local DskStm:$Obj(DiskStream)

  SetObject xsi
  DbgText "Saving Database..."
  mov xbx, $New(DskStm::DiskStream)
  OCall xbx::DiskStream.Init, xsi, pFileName, 0, 0, 0, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0
  OCall xbx::DiskStream.BinWrite32, DATABASE_VERSION
  OCall xbx::DiskStream.Put, addr [xsi].FilesColl
  OCall xbx::DiskStream.Put, addr [xsi].ObjectColl
  OCall xbx::DiskStream.Put, addr [xsi].ObjMethodColl
  OCall xbx::DiskStream.Put, addr [xsi].ObjVariableColl
  OCall xbx::DiskStream.Put, addr [xsi].InterfaceColl
  OCall xbx::DiskStream.Put, addr [xsi].IntMethodColl
  OCall xbx::DiskStream.Put, addr [xsi].ImpMethodColl
  OCall xbx::DiskStream.Truncate
  OCall xbx::DiskStream.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.ScanFile
; Purpose:    Scans a file in the ObjAsm\Code\Objects directory for object information.
; Arguments:  Arg1: -> File name.
;             Arg2: Last Write Time (FILETIME).
;             Arg3: Info Flags: OIF_xxx (INF_PRJ, etc.).
; Return:     xax -> FILEINFORMATION or NULL if the file was excluded of the scan.

FindHelpLines proc uses xbx xdi xsi pTextSrc:$ObjPtr(TextSource), pInfo:PINFORMATION
  local dHelpLineCount:DWORD, dSrcPos:DWORD

  mov xbx, pTextSrc
  xor edi, edi
  mov dHelpLineCount, edi

  m2m dSrcPos, [xbx].$Obj(TextSource).dSrcPos, eax      ;Save current line position

  .repeat
    OCall xbx::TextSource.GetPrevLine
    ;eax = TRUE if succeeded, otherwise FALSE
    ;ecx = Character offset.
    ;edx = Character count.
    .break .if eax == FALSE
    mov xsi, [xbx].$Obj(TextSource).MemStream.pBuffer
    ;Skip all initial spaces
    .repeat
      mov al, [xsi]
      .break .if al != VK_SPACE && al != VK_TAB
      inc esi
    .until FALSE                                        ;xsi -> 1st non blank character

    .continue .if dHelpLineCount == 0 && al == 0
    .break .if al != ";"
    add xdx, [xbx].$Obj(TextSource).MemStream.pBuffer
    sub xdx, xsi
    inc xsi
    add edx, sizeof(DWORD)
    mov eax, edx
    MemAlloc eax
    mov [xax], edi
    mov edi, eax
    add eax, 4
    invoke StrCopy, xax, xsi
    inc dHelpLineCount
  .until FALSE

;    DbgDec dHelpLineCount
  mov xax, pInfo
  .if dHelpLineCount == 0
    ;Save information
    m2z [xax].INFORMATION.pHelpData
    m2z [xax].INFORMATION.dHelpLineCount
  .else
    mov [xax].INFORMATION.pHelpData, xdi
    m2m [xax].INFORMATION.dHelpLineCount, dHelpLineCount, edx
  .endif

  m2m [xbx].$Obj(TextSource).dSrcPos, dSrcPos, eax      ;Restore line position

  ret
FindHelpLines endp

CheckMthWord macro ThisWord, ThisFlag
  cmp dWordSize, sizeof ThisWord
  jnz @F
  invoke StrCCompA, pWord, offset ThisWord, dWordSize
  jnz @F
  mov dFlags, ThisFlag
  jmp @@AddNewMethod
@@:
endm

CheckVarWord macro ThisWord, ThisFlag
  cmp dWordSize, sizeof ThisWord
  jnz @F
  invoke StrCCompA, pWord, offset ThisWord, dWordSize
  jnz @F
  mov dFlags, ThisFlag
  jmp @@AddNewVariable
@@:
endm

Method OA_ObjDB.ScanFile, uses xbx xdi xsi, pFileName:POINTER, LastWriteTime:FILETIME, dInfoFlags:DWORD
  local cBuffer[MAX_PATH]:CHR, pWord:PSTRINGA, dWordSize:DWORD
  local pName:POINTER, pFileInfo:PFILEINFORMATION, dFlags:DWORD
  local dNameLength:DWORD, dIncludeLength:DWORD
  local TextSrc:$Obj(TextSource), pTextSrc:$ObjPtr(TextSource)

  DbgText "OA_ObjDB.ScanFile"
  DbgStr pFileName
  SetObject xsi
  m2z pFileInfo

  ;Check for included file types
  mov xdi, [xsi].REX_Parse_ListItem.pOutVector
  mov dNameLength, $32($invoke(StrLength, pFileName))
  OCall [xsi].ScanInclude::DataCollection.ItemAt, 0   ;Get file extension of allowed files
  .if xax != NULL
    mov xbx, xax
    mov dIncludeLength, $32($invoke(StrLength, xbx))
    .repeat
      .if CHR ptr [xbx] != 0
        %OCall [xsi].REX_Parse_ListItem::RegEx.Exec, xbx, dIncludeLength, 0, 0
        .if eax == 2
          mov ecx, dNameLength
          mov eax, [xdi + 1*sizeof PCRE_OUTDATA].PCRE_OUTDATA.dEndIndex
          sub eax, [xdi + 1*sizeof PCRE_OUTDATA].PCRE_OUTDATA.dBegIndex
          .continue .if ecx < eax
          sub ecx, eax
          add xcx, pFileName
          mov edx, [xdi + 1*sizeof PCRE_OUTDATA].PCRE_OUTDATA.dBegIndex
          add edx, ebx
          invoke StrCIComp, xcx, xdx, eax
          .if eax == 0
            inc eax
            .break
          .endif
          mov eax, [xdi + 0*sizeof PCRE_OUTDATA].PCRE_OUTDATA.dEndIndex
          add ebx, eax
          sub dIncludeLength, eax
        .else
          xor eax, eax
          .break
        .endif
      .else
        xor eax, eax
        .break
      .endif
    .until FALSE
  .endif

  .if eax != FALSE
    mov ebx, 1
    .while ebx < [xsi].ScanExclude.dCount
      OCall [xsi].ScanExclude::DataCollection.ItemAt, ebx
      invoke StrIComp, xax, pFileName
      .break .if eax == 0
      inc ebx
    .endw

    .if eax != FALSE
      ;We create a file entry for EACH file in the directory!
      .if $OCall([xsi].FilesColl::FilesCollection.Search, pFileName) == FALSE
        mov xdi, $MemAlloc(sizeof FILEINFORMATION)
        mov [xdi].FILEINFORMATION.pFileName, $invoke(StrNew, pFileName)
        m2m [xdi].FILEINFORMATION.LastWrite.dwLowDateTime, LastWriteTime.dwLowDateTime, edx
        m2m [xdi].FILEINFORMATION.LastWrite.dwHighDateTime, LastWriteTime.dwHighDateTime, edx
        mov [xdi].FILEINFORMATION.dFlags, FIF_SCANNED
        OCall [xsi].FilesColl::FilesCollection.Insert, xdi   ;eax -> FILEINFORMATION
      .else
        OCall [xsi].FilesColl::FilesCollection.ItemAt, ecx   ;ecx = index, eax -> FILEINFORMATION
      .endif
      mov pFileInfo, xax

      lea xdi, cBuffer

      mov pTextSrc, $New(TextSource)
      OCall pTextSrc::TextSource.Init, xsi, pFileName
      OCall pTextSrc::TextSource.Reset

      .repeat
        .repeat
          .if $OCall(pTextSrc::TextSource.GetNextLine) == FALSE
            jmp @@Exit
          .endif
          OCall pTextSrc::TextSource.GetNextWord
          .if ecx != 0
            mov pWord, xax
            mov dWordSize, ecx

            .if ecx == lengthof bObject
              invoke StrCCompA, pWord, offset bObject, dWordSize
              .if eax == 0
                OCall pTextSrc::TextSource.GetNextWord          ;Get object name
                .if ecx != 0
                  mov pWord, xax
                  mov dWordSize, ecx
                  .if ecx == sizeof bMacro
                    invoke StrCICompA, offset bMacro, pWord, dWordSize
                    .if eax == 0
                      ;Object name OK => create a new entry in the object collection
                      mov pName, $invoke(StrCNewA, pWord, dWordSize)
                      mov xbx, $MemAlloc(sizeof OBJECTINFORMATION)
                      m2m [xbx].OBJECTINFORMATION.pName, pName, edx
                      m2m [xbx].OBJECTINFORMATION.dFlags, dInfoFlags, edx
                      m2m [xbx].OBJECTINFORMATION.pFileInfo, pFileInfo, xdx
                      m2z [xbx].OBJECTINFORMATION.pHelpData
                      OCall [xsi].ObjectColl::ObjInfoCollection.Insert, xbx
    
                      OCall pTextSrc::TextSource.GetNextWord   ;Get object ID
                      OCall pTextSrc::TextSource.GetNextWord   ;Get object ancestor
                      .if ecx != 0
                        mov edx, ecx
                        invoke StrCNewA, xax, edx
                      .else
                        xor eax, eax
                      .endif
                      mov [xbx].OBJECTINFORMATION.pAncestorName, xax
    
                      invoke FindHelpLines, pTextSrc, xbx
    
                      ;Scan now for object members
                      .repeat
                        .if $OCall(pTextSrc::TextSource.GetNextLine) == FALSE
                          jmp @@Exit
                        .endif
                        OCall pTextSrc::TextSource.GetNextWord
                        .if ecx != 0
                          mov pWord, xax
                          mov dWordSize, ecx
                          .if ecx == sizeof bObjectEnd
                            invoke StrCCompA, pWord, offset bObjectEnd, dWordSize
                            .break .if eax == 0
                          .endif
    
                          CheckMthWord bVirtualMethod,    METHODTYPE_VIRTUAL
                          CheckMthWord bStaticMethod,     METHODTYPE_STATIC
                          CheckMthWord bDynamicMethod,    METHODTYPE_DYNAMIC
                          CheckMthWord bInterfaceMethod,  METHODTYPE_INTERFACE
                          CheckMthWord bInlineMethod,     METHODTYPE_INLINE
    
                          CheckMthWord bVirtualEvent,     METHODTYPE_VIRTUAL_EVENT
                          CheckMthWord bDynamicEvent,     METHODTYPE_DYNAMIC_EVENT
    
                          CheckMthWord bVirtualAbstract,  METHODTYPE_VIRTUAL_ABSTRACT
                          CheckMthWord bDynamicAbstract,  METHODTYPE_DYNAMIC_ABSTRACT
    
                          CheckMthWord bRedefineMethod,   METHODTYPE_REDEFINED
    
                          CheckVarWord bDefineVariable,   VARIABLETYPE_REGULAR
                          CheckVarWord bRedefineVariable, VARIABLETYPE_REDEFINED
                          CheckVarWord bEmbed,            VARIABLETYPE_OBJECT
    
                          .continue
                        .endif
    
                    @@AddNewMethod:
                        OCall pTextSrc::TextSource.GetNextWord         ;Get method name
                        .if ecx != 0
                          mov edx, ecx
                          mov xbx, $invoke(StrCNewA, xax, edx)
                          MemAlloc sizeof OBJMTDINFORMATION
                          mov [xax].OBJMTDINFORMATION.pName, xbx
                          mov xbx, xax
                          mov [xbx].OBJMTDINFORMATION.pObjectName, $invoke(StrNewA, pName)
                          m2m [xbx].OBJMTDINFORMATION.pFileInfo, pFileInfo, xdx  ;From FilesCollection
                          m2m [xbx].OBJMTDINFORMATION.dFlags, dFlags, edx
                          m2z [xbx].OBJMTDINFORMATION.pHelpData
                          m2z [xbx].OBJMTDINFORMATION.dHelpLineCount
    
                          mov pWord, $OCall(pTextSrc::TextSource.GetNextWord)     ;xax -> parameters
                          .if xax != NULL
                            invoke StrRScanA, xax, ';'
                            .if eax != NULL
                              m2z BYTE ptr [xax]
                              invoke StrRTrimA, pWord, pWord
                            .endif
                          .endif
                          .if dFlags == METHODTYPE_VIRTUAL_EVENT || dFlags == METHODTYPE_DYNAMIC_EVENT
                            mov [xbx].OBJMTDINFORMATION.pArguments, $invoke(StrNewA, $OfsCStr("wParam, lParam"))
                          .else
                            mov [xbx].OBJMTDINFORMATION.pArguments, $invoke(StrNewA, pWord)
                          .endif
                          OCall [xsi].ObjMethodColl::ObjMtdInfoCollection.Insert, xbx
                        .endif
                        .continue
    
                    @@AddNewVariable:
                        OCall pTextSrc::TextSource.GetNextWord         ;Get variable name
                        .if ecx != 0
                          mov edx, ecx
                          mov xbx, $invoke(StrCNewA, xax, edx)
                          MemAlloc sizeof OBJVARINFORMATION
                          mov [xax].OBJVARINFORMATION.pName, xbx
                          mov xbx, xax
                          mov [xbx].OBJVARINFORMATION.pObjectName, $invoke(StrNewA, pName)
                          m2m [xbx].OBJVARINFORMATION.pFileInfo, pFileInfo, xdx  ;From FilesCollection
                          m2m [xbx].OBJVARINFORMATION.dFlags, dFlags, edx
                          m2z [xbx].OBJVARINFORMATION.pHelpData
                          m2z [xbx].OBJVARINFORMATION.dHelpLineCount
                          mov pWord, $OCall(pTextSrc::TextSource.GetNextWord)
                          .if xax != NULL
                            invoke StrRScanA, xax, ';'
                            .if xax != NULL
                              m2z BYTE ptr [xax]
                              invoke StrRTrimA, [xsp + 4], [xsp]
                            .endif
                          .endif
                          mov [xbx].OBJVARINFORMATION.pArgType, $invoke(StrNewA, pWord)
                          OCall [xsi].ObjVariableColl::ObjVarInfoCollection.Insert, xbx
                        .endif
    
                        invoke FindHelpLines, pTextSrc, xbx
    
                    @@NextLine1:
                      .until FALSE
                    .endif
                  .endif
                .endif
              .endif

              ;-- Interface definition --------------------------------------------------

            .elseif dWordSize == sizeof bBeginInterface
              invoke StrCCompA, pWord, offset bBeginInterface, dWordSize
              .if eax == 0
                OCall pTextSrc::TextSource.GetNextWord     ;Get interface name
                mov pWord, xax
                mov dWordSize, ecx
                .if ecx != 0
                  .if ecx == sizeof bMacro
                    invoke StrCICompA, offset bMacro, pWord, dWordSize
                    .if eax == 0
                      ;Interface name OK => create a new entry in the interface collection
                      invoke StrCNewA, pWord, dWordSize
                      mov pName, xax
                      mov xbx, $MemAlloc(sizeof INTERFACEINFORMATION)
                      m2m [xbx].INTERFACEINFORMATION.pName, pName, xdx
                      mov edx, dInfoFlags
                      or edx, INF_INTERFACE
                      mov [xbx].INTERFACEINFORMATION.dFlags, edx
                      m2m [xbx].INTERFACEINFORMATION.pFileInfo, pFileInfo, xax
                      m2z [xbx].INTERFACEINFORMATION.pHelpData
                      m2z [xbx].INTERFACEINFORMATION.dHelpLineCount
  
                      OCall pTextSrc::TextSource.GetNextWord   ;Get interface ancestor
                      mov pWord, xax
                      mov dWordSize, ecx
                      .if ecx != 0
                        invoke StrCNewA, pWord, dWordSize
                      .else
                        xor eax, eax
                      .endif
                      mov [xbx].INTERFACEINFORMATION.pAncestorName, xax
  
                      OCall [xsi].InterfaceColl::IntInfoCollection.Insert, xbx
  
                      invoke FindHelpLines, pTextSrc, xbx
  
                      ;Scan now for standart/dispatch interface methods
                      .repeat
                        .if $OCall(pTextSrc::TextSource.GetNextLine) == FALSE
                          jmp @@Exit
                        .endif
                        OCall pTextSrc::TextSource.GetNextWord
                        .if ecx != 0
                          mov pWord, xax
                          mov dWordSize, ecx
                          .if dWordSize == sizeof bEndInterface
                            invoke StrCCompA, pWord, offset bEndInterface, dWordSize
                            .break .if eax == 0
                          .endif
  
                          .if dWordSize == sizeof bStdMethod
                            invoke StrCCompA, pWord, offset bStdMethod, dWordSize
                            mov dFlags, METHODTYPE_STANDARD
                          .elseif dWordSize == sizeof bDispMethod
                            invoke StrCCompA, pWord, offset bDispMethod, dWordSize
                            mov dFlags, METHODTYPE_DISPATCH
                          .endif
  
                          .if eax == 0
                            OCall pTextSrc::TextSource.GetNextWord    ;Get method name
                            .if ecx != 0
                              mov edx, ecx
                              mov xbx, $invoke(StrCNewA, xax, edx)
                              MemAlloc sizeof INTMTDINFORMATION
                              mov [xax].INTMTDINFORMATION.pName, xbx
                              mov xbx, xax
                              mov [xbx].INTMTDINFORMATION.pInterfaceName, $invoke(StrNewA, pName)
                              m2m [xbx].INTMTDINFORMATION.dFlags, dFlags, edx
                              m2m [xbx].INTMTDINFORMATION.pFileInfo, pFileInfo, xdx  ;From FilesCollection
                              m2z [xbx].INTMTDINFORMATION.pHelpData
                              m2z [xbx].INTMTDINFORMATION.dHelpLineCount
  
                              OCall pTextSrc::TextSource.GetNextWord
                              mov pWord, xax
                              mov dWordSize, ecx
                              .if xax != NULL
                                invoke StrRScanA, xax, ';'
                                .if xax != NULL
                                  m2z CHRA ptr [xax]
                                  invoke StrRTrimA, pWord, pWord
                                .endif
                              .endif
                              mov [xbx].INTMTDINFORMATION.pArguments, $invoke(StrNewA, xax)
                              OCall [xsi].IntMethodColl::IntMtdInfoCollection.Insert, xbx
                            .endif
                          .endif
                        .endif
                      .until FALSE
                    .endif
                  .endif
                .endif

              ;-- Method implementation --------------------------------------------------
              .elseif dWordSize == sizeof bMethod
                invoke StrCCompA, pWord, offset bMethod, dWordSize
                .if eax == 0
                  OCall pTextSrc::TextSource.GetNextWord       ;Get object/interface name
                  mov pWord, xax
                  mov dWordSize, ecx
                  .if ecx != 0
                    .if ecx == sizeof bMacro
                      invoke StrCICompA, offset bMacro, pWord, dWordSize
                      .if eax == 0
                        ;Get the interface/object name
                        mov xbx, $MemAlloc(sizeof IMPMTDINFORMATION)
                        invoke StrCNew, pWord, dWordSize
                        mov [xbx].IMPMTDINFORMATION.pObjectName, xax
                        m2m [xbx].IMPMTDINFORMATION.pFileInfo, pFileInfo, xdx ;From FilesCollection
                        m2z [xbx].IMPMTDINFORMATION.dFlags
                        m2z [xbx].IMPMTDINFORMATION.pArguments
                        m2z [xbx].IMPMTDINFORMATION.pHelpData
                        m2z [xbx].IMPMTDINFORMATION.dHelpLineCount
  
                        ;Get the method name
                        OCall pTextSrc::TextSource.GetNextWord   ;xax -> parameters
                        mov pWord, xax
                        mov dWordSize, ecx
                        add pWord, xcx
                        mov [xbx].IMPMTDINFORMATION.pName, $invoke(StrCNewA, xax, dWordSize)
                        invoke StrLScanA, pWord, ","
                        .if xax != NULL
                          invoke StrLScanA, xax, ","
                          .if xax != NULL
                            inc xax
                            mov [xbx].IMPMTDINFORMATION.pArguments, $invoke(StrNewA, xax)
                          .endif
                        .endif
  
                        OCall [xsi].ImpMethodColl::ImpMtdInfoCollection.Insert, xbx
  
                        invoke FindHelpLines, pTextSrc, xbx
  
                      .endif
                    .endif
                  .endif
                .endif
              .endif
            .endif
          .endif
        .until FALSE
      .until FALSE

@@Exit:
      OCall pTextSrc::TextSource.Done
    .endif
  .endif
@@Abort:

  mov xax, pFileInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.ScanDBFiles
; Purpose:    Checks all files in the FilesCollection.
; Arguments:  None.
; Return:     eax = TRUE if something has changed in the database, otherwise FALSE.

Method OA_ObjDB.ScanDBFiles, uses xbx xdi xsi
  local FD:WIN32_FIND_DATA, dHasChanged:DWORD
  local cBuffer[MAX_PATH]:CHR, pFileInfo:PFILEINFORMATION

  SetObject xsi
  m2z dHasChanged
  xor ebx, ebx
  .while ebx < [xsi].FilesColl.dCount
    mov pFileInfo, $OCall([xsi].FilesColl::FilesCollection.ItemAt, ebx)
    mov xdi, [xax].FILEINFORMATION.pFileName
    lea xdx, FD
    invoke FindFirstFile, xdi, xdx
    .if eax == INVALID_HANDLE_VALUE
      DbgWarning "File deleted = "
      mov xax, pFileInfo
      DbgStr [xax].FILEINFORMATION.pFileName
      OCall xsi.RemoveFileInfo, xdi
    .else
      invoke FindClose, xax
      mov xax, pFileInfo
      mov ecx, [xax].FILEINFORMATION.LastWrite.dwHighDateTime
      .if ecx == FD.ftLastWriteTime.dwHighDateTime
        mov ecx, [xax].FILEINFORMATION.LastWrite.dwLowDateTime
        .if ecx == FD.ftLastWriteTime.dwLowDateTime
          jmp @@NextFile
        .endif
      .endif
      ;Save FileName on cBuffer
      invoke StrCCopy, addr cBuffer, xdi, lengthof(cBuffer) - 1
      OCall xsi.RemoveFileInfo, xdi
      OCall xsi.ScanFile, addr cBuffer, QWORD ptr FD.ftLastWriteTime, 0

      .if eax != NULL
        or dHasChanged, TRUE
      .endif
    .endif
@@NextFile:
    inc ebx
  .endw
  mov eax, dHasChanged
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OA_ObjDB.ScanDirFiles
; Purpose:    Checks all files of a specified folder.
; Arguments:  Arg1: -> Path.
; Return:     eax = TRUE if something has changed in the specified folder, else FALSE.

Method OA_ObjDB.ScanDirFiles, uses xbx xdi xsi, pPath:POINTER
  local FD:WIN32_FIND_DATA, dRemaining:DWORD, dHasChanged:DWORD
  local cBuffer[MAX_PATH]:CHR, pBuffer:POINTER

  SetObject xsi
  m2z dHasChanged
  lea xbx, cBuffer
  mov pBuffer, xbx
  mov dRemaining, ebx
  mov xdi, $invoke(StrECopy, xbx, pPath)
  sub dRemaining, eax
  add dRemaining, lengthof(cBuffer) - 1
  invoke StrCCopy, xdi, $OfsCStr("*.*"), dRemaining
  mov xbx, $invoke(FindFirstFile, xbx, addr FD)
  .if xbx != INVALID_HANDLE_VALUE
    .repeat
      .if FD.nFileSizeLow != 0 || FD.nFileSizeHigh != 0
        invoke StrCCopy, xdi, addr FD.cFileName, dRemaining
        .if $OCall([xsi].FilesColl::FilesCollection.Search, pBuffer) != FALSE
          OCall [xsi].FilesColl::FilesCollection.ItemAt, ecx
          mov ecx, [xax].FILEINFORMATION.LastWrite.dwHighDateTime
          .if ecx == FD.ftLastWriteTime.dwHighDateTime
            mov ecx, [xax].FILEINFORMATION.LastWrite.dwLowDateTime
            .if ecx == FD.ftLastWriteTime.dwLowDateTime
              mov [xax].FILEINFORMATION.dFlags, FIF_STANDARD
              jmp @F
            .endif
          .endif
          OCall xsi.RemoveFileInfo, pBuffer
        .endif
        OCall xsi.ScanFile, pBuffer, QWORD ptr FD.ftLastWriteTime, 0
        .if eax != NULL
          mov [xax].FILEINFORMATION.dFlags, FIF_STANDARD
          or dHasChanged, TRUE
        .endif
      .endif
    @@:
      invoke FindNextFile, xbx, addr FD
    .until eax == FALSE
    invoke FindClose, xbx
  .endif
  mov eax, dHasChanged
MethodEnd

;##/

; ==================================================================================================
;  TextSource implementation
; ==================================================================================================

;##\

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextSource.Done
; Purpose:    Finalizes TextSource object.
; Arguments:  None.
; Return:     Nothing.

Method TextSource.Done, uses xsi
  SetObject xsi
  OCall [xsi].MemStream::MemoryStream.Done
  invoke CloseHandle, [xsi].pSource
  .if [xsi].pFileLinesBuff != NULL
    MemFree [xsi].pFileLinesBuff
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; ——————————————————————————————————————————————————————————————————————————————————————————————————

GFL_BUFFER_SIZE     equ 4096                                  ;Should be a power of 2
GFL_LIST_SIZE_INIT  equ sizeof(DWORD) + 512*sizeof GFL_DATA   ;Must not be less than 12
GFL_LIST_SIZE_GROW  equ 512*sizeof GFL_DATA                   ;Must not be less than 12

if TARGET_BITNESS eq 32

GFL_CR_MASK         equ 0D0D0D0Dh

align ALIGN_CODE
GetFileLinesA proc uses ebx edi esi hFile:HANDLE
  local pList:POINTER, pListEnd:POINTER, dListSize:DWORD
  local pBuffer:POINTER, pBufferEnd:POINTER
  local dBufferFilePos:DWORD, sdCorrOffset:SDWORD, dLineStart:DWORD
  local dBytesRead:DWORD, dPrevBytesRead:DWORD

  .const
    GFL_MASK_TABLE \
      DWORD 0000000FFh
      DWORD 00000FFFFh
      DWORD 000FFFFFFh
    GFL_JUMP_TABLE POINTER @@1, @@2, @@3, @@4

  .code
  ;Ensure all requirements are met
  .if hFile != INVALID_HANDLE_VALUE
    mov dListSize, GFL_LIST_SIZE_INIT
    MemAlloc dListSize
    .if eax != NULL
      mov pList, eax
      mov edi, eax
      add eax, dListSize
      sub eax, sizeof GFL_DATA
      mov pListEnd, eax
      add edi, sizeof DWORD                             ;Make room for the count DWORD

      MemAlloc GFL_BUFFER_SIZE
      .if eax != NULL
        mov pBuffer, eax
        m2z dBufferFilePos
        mov sdCorrOffset, eax
        m2z dLineStart
        m2z dBytesRead

@@Loop:
        .repeat
          m2m dPrevBytesRead, dBytesRead, eax
          ;Read a data chunk
          invoke ReadFile, hFile, pBuffer, GFL_BUFFER_SIZE, addr dBytesRead, NULL
          .break .if dBytesRead == 0

          ;Compute aligned address of the last valid DWORD
          mov esi, pBuffer
          mov ecx, esi
          mov eax, dBytesRead
          add ecx, eax
          dec ecx
          and ecx, 0FFFFFFFCh                           ;Alignment 4 
          mov pBufferEnd, ecx

          ;Cut garbage from the last DWORD
          and eax, 2
          .if !ZERO?
            ;Read mask and apply it mask to the last DWORD
            mov edx, [GFL_MASK_TABLE + sizeof(DWORD)*eax - sizeof(DWORD)]
            and [ecx], edx
          .endif

          ;Analize the data, searching for the char 13
          .while esi <= pBufferEnd
            mov ebx, [esi]
            xor ebx, GFL_CR_MASK                        ;Puts a zero where the CR was found

            test ebx, 0000000FFh
            jz @@Found
@@1:
            inc esi
            test ebx, 00000FF00h
            jz @@Found
@@2:
            inc esi
            test ebx, 000FF0000h
            jz @@Found
@@3:
            inc esi
            test ebx, 0FF000000h
            jnz @@4

@@Found:
            ;Compute line start and character file offset
            mov ecx, dLineStart
            mov eax, ecx
            stosd
            mov eax, esi
            sub eax, sdCorrOffset
            sub eax, ecx
            stosd                                       ;edi -> valid position into the list
            lea eax, [eax + ecx + 2]                    ;+2 = CRLF
            mov dLineStart, eax

            ;We check edi to ensure that it remains pointing to a valid position
            ;  to hold a complete GFL_DATA structure
            .if edi > pListEnd
              ;Extend the list by the factor GFL_LIST_SIZE_GROW
              sub edi, pList
              add dListSize, GFL_LIST_SIZE_GROW
              MemReAlloc pList, dListSize
              .if eax != NULL
                ;Operation succeeded => update internal values
                mov pList, eax
                add edi, eax                            ;Adjust new edi
                add eax, dListSize
                sub eax, sizeof GFL_DATA
                mov pListEnd, eax
              .else
                ;Operation failed => release allocated resources and exit
                MemFree pList
                MemFree pBuffer
                xor eax, eax
                ret
              .endif
            .endif
            mov ecx, esi
            and ecx, 2
            jmp [offset GFL_JUMP_TABLE + sizeof(POINTER)*ecx]
@@4:
            inc esi
          .endw

          mov eax, dBytesRead
          add dBufferFilePos, eax

          sub sdCorrOffset, eax

        .until FALSE

        ;Check if we have and additional line at the end that doesn't end with CRLF
        mov eax, dBufferFilePos                         ;End of data
        .if eax != dLineStart
          mov eax, dLineStart
          stosd
          sub eax, dBufferFilePos
          neg eax
          stosd
        .endif

        MemFree pBuffer

        mov eax, pList
        sub edi, sizeof DWORD                           ;Subtract first DWORD
        sub edi, eax
        shr edi, $Log2(sizeof(GFL_DATA))
        mov [eax], edi
      .else
        MemFree pList
        xor eax, eax
      .endif
    .endif
  .else
    xor eax, eax
  .endif
  ret
GetFileLinesA endp

else

GFL_CR_MASK         equ 0D0D0D0D0D0D0D0Dh

align ALIGN_CODE
GetFileLinesA proc uses rbx rdi rsi hFile:HANDLE
  local pList:POINTER, pListEnd:POINTER, dListSize:DWORD
  local pBuffer:POINTER, pBufferEnd:POINTER
  local dBufferFilePos:DWORD, sdCorrOffset:SDWORD, dLineStart:DWORD
  local dBytesRead:DWORD, dPrevBytesRead:DWORD

  .const
    GFL_MASK_TABLE \
      QWORD 000000000000000FFh
      QWORD 0000000000000FFFFh
      QWORD 00000000000FFFFFFh
      QWORD 000000000FFFFFFFFh
      QWORD 0000000FFFFFFFFFFh
      QWORD 00000FFFFFFFFFFFFh
      QWORD 000FFFFFFFFFFFFFFh
    GFL_JUMP_TABLE POINTER @@1, @@2, @@3, @@4, @@5, @@6, @@7, @@8

  .code
  ;Ensure all requirements are met
  .if hFile != INVALID_HANDLE_VALUE
    mov dListSize, GFL_LIST_SIZE_INIT
    MemAlloc dListSize
    .if rax != NULL
      mov pList, rax
      mov rdi, rax
      mov ecx, dListSize
      add rax, xcx
      sub rax, sizeof GFL_DATA
      mov pListEnd, rax
      add rdi, sizeof DWORD                             ;Make room for the count DWORD

      MemAlloc GFL_BUFFER_SIZE
      .if rax != NULL
        mov pBuffer, rax
        m2z dBufferFilePos
        mov sdCorrOffset, eax
        m2z dLineStart
        m2z dBytesRead

@@Loop:
        .repeat
          m2m dPrevBytesRead, dBytesRead, eax
          ;Read a data chunk
          invoke ReadFile, hFile, pBuffer, GFL_BUFFER_SIZE, addr dBytesRead, NULL
          .break .if dBytesRead == 0

          ;Compute aligned address of the last valid QWORD
          mov rsi, pBuffer
          mov rcx, rsi
          mov eax, dBytesRead
          add rcx, rax
          dec rcx
          and rcx, 0FFFFFFFFFFFFFFF8h                   ;Alignment 8
          mov pBufferEnd, rcx

          ;Cut garbage from the last QWORD
          and eax, 3
          .if !ZERO?
            ;Read mask and apply it mask to the last DWORD
            lea r8, GFL_MASK_TABLE
            mov rdx, [r8 + sizeof(QWORD)*xax - sizeof(QWORD)]
            and [xcx], rdx
          .endif

          ;Analize the data, searching for the char 13
          .while xsi <= pBufferEnd
            mov rbx, [xsi]
            mov rdx, GFL_CR_MASK
            xor rbx, rdx                         ;Puts a zero where the CR was found

            test rbx, 000000000000000FFh
            jz @@Found
@@1:
            inc rsi
            test rbx, 0000000000000FF00h
            jz @@Found
@@2:
            inc rsi
            test rbx, 00000000000FF0000h
            jz @@Found
@@3:
            inc rsi
            test rbx, 000000000FF000000h
            jnz @@4
@@4:
            mov ecx, 0FFh
            shl rcx, 32
            inc rsi
            test rbx, rcx
            jz @@Found
@@5:
            mov ecx, 0FFh
            shl rcx, 40
            inc rsi
            test rbx, rcx
            jz @@Found
@@6:
            mov ecx, 0FFh
            shl rcx, 48
            inc rsi
            test rbx, rcx
            jnz @@4
@@7:
            mov ecx, 0FFh
            shl rcx, 56
            inc rsi
            test rbx, rcx
            jnz @@8

@@Found:
            ;Compute line start and character file offset
            mov ecx, dLineStart
            mov eax, ecx
            stosd
            mov rax, rsi
            mov edx, sdCorrOffset
            sub rax, rdx
            sub rax, rcx
            stosd                                       ;edi -> valid position into the list
            lea eax, [eax + ecx + 2]                    ;+2 = CRLF
            mov dLineStart, eax

            ;We check edi to ensure that it remains pointing to a valid position
            ;  to hold a complete GFL_DATA structure
            .if rdi > pListEnd
              ;Extend the list by the factor GFL_LIST_SIZE_GROW
              sub rdi, pList
              add dListSize, GFL_LIST_SIZE_GROW
              MemReAlloc pList, dListSize
              .if rax != NULL
                ;Operation succeeded => update internal values
                mov pList, rax
                add rdi, rax                            ;Adjust new rdi
                mov ecx, dListSize
                add rax, rcx
                sub rax, sizeof GFL_DATA
                mov pListEnd, rax
              .else
                ;Operation failed => release allocated resources and exit
                MemFree pList
                MemFree pBuffer
                xor eax, eax
                ret
              .endif
            .endif
            mov rcx, rsi
            and ecx, 3
            mov r8, offset GFL_JUMP_TABLE 
            jmp POINTER ptr [r8 + sizeof(POINTER)*xcx]
@@8:
            inc esi
          .endw

          mov eax, dBytesRead
          add dBufferFilePos, eax

          sub sdCorrOffset, eax

        .until FALSE

        ;Check if we have and additional line at the end that doesn't end with CRLF
        mov eax, dBufferFilePos                         ;End of data
        .if eax != dLineStart
          mov eax, dLineStart
          stosd
          sub eax, dBufferFilePos
          neg eax
          stosd
        .endif

        MemFree pBuffer

        mov rax, pList
        sub rdi, sizeof DWORD                           ;Subtract first DWORD
        sub rdi, rax
        shr edi, $Log2(sizeof(GFL_DATA))
        mov [eax], edi
      .else
        MemFree pList
        xor eax, eax
      .endif
    .endif
  .else
    xor eax, eax
  .endif
  ret
GetFileLinesA endp
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextSource.Init
; Purpose:    (Constructor) Initializes TextSource object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> File Name string.
; Return:     Nothing.

Method TextSource.Init, uses xsi, pOwner:POINTER, pFileName:POINTER
  SetObject xsi
;  DbgText "TextSource.Init"
;  DbgStr pFileName
  ACall xsi.Init, pOwner
  OCall [xsi].MemStream::MemoryStream.Init, xsi, 50*1024, 50*1024, -1
  invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, NULL, \
                                OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
  mov [xsi].pSource, xax
  mov [xsi].pFileLinesBuff, $invoke(GetFileLinesA, xax)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextSource.GetPrevLine
; Purpose:    Retrieves a new line from the text source into the object line buffer.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
;             ecx = Character offset.
;             edx = Character count.

Method TextSource.GetPrevLine, uses xbx xsi
  local dBytesRead:DWORD

  SetObject xsi
  xor eax, eax
  mov [xsi].MemStream.dPosition, eax                    ;Position = 0
  mov [xsi].MemStream.dCurrSize, eax                    ;Fill level = 0

  ;The source is a file
  mov xcx, [xsi].pFileLinesBuff
  .if [xsi].dSrcPos <= 1
    xor eax, eax                                        ;Returns FALSE
  .else
    dec [xsi].dSrcPos
    mov eax, [xsi].dSrcPos

    lea xbx, [xcx + sizeof(GFL_DATA)*xax + sizeof(DWORD)]  ;xbx -> 1st GFL_DATA
    mov xdx, xbx
    mov ecx, [xdx].GFL_DATA.dLineLength
    inc ecx                                             ;Add space for zero terminator char
    .if ecx > [xsi].MemStream.dLimit
      OCall [xsi].MemStream::MemoryStream.SetCapacity, ecx
    .endif
    invoke SetFilePointer, [xsi].pSource, [xbx].GFL_DATA.dFileOffset, NULL, FILE_BEGIN
    invoke ReadFile, [xsi].pSource, [xsi].MemStream.pBuffer, [xbx].GFL_DATA.dLineLength, addr dBytesRead, NULL

    mov xax, [xsi].MemStream.pBuffer
    mov ecx, [xbx].GFL_DATA.dLineLength
    m2z CHRA ptr [xax + xcx]

    inc ecx
    mov [xsi].MemStream.dCurrSize, ecx

    mov eax, TRUE
    mov xdx, xbx
    mov ecx, [xdx].GFL_DATA.dFileOffset                 ;ecx = Char offset
    mov edx, [xdx].GFL_DATA.dLineLength                 ;edx = Char count in this line
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextSource.GetNextArgument
; Purpose:    Retrieves the next word from the object line buffer after a comma.
; Arguments:  None.
; Return:     eax -> Word or NULL if no more words exist.
;             ecx = Word length.
;             edx = Flags. 1 = line break

Method TextSource.GetNextArgument, uses xsi
  SetObject xsi
  OCall xsi.GetNextWord
  .while xax != NULL && dl != ','
    OCall xsi.GetNextWord
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextSource.GetNextLine
; Purpose:    Retrieves a new line from the text source into the object line buffer.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
;             ecx = Character offset.
;             edx = Character count.

Method TextSource.GetNextLine, uses xbx xsi
  local dBytesRead:DWORD

  SetObject xsi
  xor eax, eax
  mov [xsi].MemStream.dPosition, eax                    ;Position = 0
  mov [xsi].MemStream.dCurrSize, eax                    ;Fill level = 0

  ;The source is a file
  mov xcx, [xsi].pFileLinesBuff
  mov eax, [xsi].dSrcPos
  .if eax >= DWORD ptr [xcx]
    xor eax, eax                                        ;Returns FALSE
  .else
    lea xbx, [xcx + sizeof(GFL_DATA)*xax + sizeof(DWORD)]   ;xbx -> 1st GFL_DATA
    mov ecx, [xbx].GFL_DATA.dLineLength
    inc ecx                                             ;Room for zero terminator
    .if ecx > [xsi].MemStream.dLimit
      OCall [xsi].MemStream::MemoryStream.SetCapacity, ecx
    .endif
    invoke SetFilePointer, [xsi].pSource, [xbx].GFL_DATA.dFileOffset, NULL, FILE_BEGIN
    invoke ReadFile, [xsi].pSource, [xsi].MemStream.pBuffer, [xbx].GFL_DATA.dLineLength, addr dBytesRead, NULL

    mov xax, [xsi].MemStream.pBuffer
    mov ecx, [xbx].GFL_DATA.dLineLength
    m2z CHRA ptr [xax + xcx]

    inc ecx
    mov [xsi].MemStream.dCurrSize, ecx

    inc [xsi].dSrcPos

    mov eax, TRUE
    mov ecx, [xbx].GFL_DATA.dFileOffset                 ;ecx = Char offset
    mov edx, [xbx].GFL_DATA.dLineLength                 ;edx = Char count in this line
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextSource.GetNextWord
; Purpose:    Retrieves the next word from the object line buffer.
; Arguments:  None.
; Return:     eax -> Word or NULL if no more words are available.
;             ecx = Word length
;             edx = Flags. Bit00 = line break, Bit01 = Comment
; Notes:      dInWord: 0 = at the beginning, 1 = in Word, 2 = at the end

Method TextSource.GetNextWord, uses xbx xdi xsi
  local dInWord:DWORD, dInString:DWORD, bStrDelimiter:BYTE, dFlags:DWORD

  SetObject xsi
  xor ecx, ecx                                          ;Reset ecx
  mov dInWord, ecx                                      ;  and use it to initialize
  mov dInString, ecx                                    ;  local variables
  mov ebx, [xsi].MemStream.dPosition
  add xbx, [xsi].MemStream.pBuffer                      ;xbx -> current CHRA

  .if [xsi].bCommentChar != 0
    invoke StrLScan, xbx, [xsi].bCommentChar
    .if eax == 0
      xor ecx, ecx
      xor edx, edx
      ExitMethod
    .else
      xor eax, eax
      xor ecx, ecx
      xor edx, edx
      mov [xsi].bCommentChar, al                        ;Reset CommentChar 
    .endif
  .endif
  mov xdi, xbx                                          ;Word beginning pointer

  xor edx, edx
  .if xdi > [xsi].MemStream.pBuffer
    mov dl, CHRA ptr [xdi - sizeof CHRA]
    mov dFlags, edx
  .endif

  .if [xsi].MemStream.dPosition == 0
    BitSet dFlags, BIT17                                ;First word
  .endif

  .repeat
    mov al, [xbx]
    .if dInString == 1
      .if al == 0                                       ;Unexpected end of string
        xor eax, eax
        xor ecx, ecx
        jmp @@Exit
      .else
        inc xbx
        .if al == bStrDelimiter
          and dInString, 0
          mov xdi, xbx
        .endif
      .endif
    .else
      .if (al == "'") || (al == '"')
        mov dInString, 1
        mov bStrDelimiter, al
        inc xbx
      .else
        .if al == 0 || al == ";"
          .if dInWord == 0
            xor eax, eax
            xor ecx, ecx
          .else
            mov xax, xdi
          .endif
          jmp @@Exit
        .else
          .if al == " " || al ==  9
            .if dInWord == 0
              inc xdi
            .elseif dInWord == 1
              mov dInWord, 2
            .endif
            inc ebx
          .elseif al == ":" || al == "," || al == "." || \
              al == "+" || al == "-" || al == "*" || al == "/" || \
              al == "=" || al == "!" || al == "<" || al == ">" || \
              al == "[" || al == "]" || \
              al == "(" || al == ")" || \
              al == "{" || al == "}"
            mov xax, xdi
            inc xbx
            jmp @@Exit
          .elseif al == "\"                             ;Line break
            mov xax, xdi
            inc xbx
            BitSet dFlags, BIT16
            jmp @@Exit
          .else
            .if dInWord == 0
              mov dInWord, 1
              inc xbx
              inc ecx
            .elseif dInWord == 1
              inc xbx
              inc ecx
            .else
              mov xax, xdi
              jmp @@Exit
            .endif
          .endif
        .endif
      .endif
    .endif
  .until FALSE

@@Exit:
  sub xbx, [xsi].MemStream.pBuffer
  mov [xsi].MemStream.dPosition, ebx

  .if xax != NULL && ecx != 0
    .ifBitSet dFlags, BIT17
      .if ecx == sizeof bComment
        mov xbx, xax
        mov edi, ecx
        invoke StrCIComp, offset bComment, xbx, edi
        .if ZERO?
          add xdi, xbx
          inc xdi
          .repeat                                       ;find the comment marker
            mov al, CHRA ptr [xdi]
            .if al == VK_SPACE || al == VK_TAB
              inc xdi
            .else
              .break
            .endif
          .until FALSE
          mov [xsi].bCommentChar, al
          xor eax, eax
          xor ecx, ecx
        .else
          mov ecx, edi
          mov xax, xbx
        .endif
      .endif
    .endif
  .endif
  mov edx, dFlags
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextSource.Reset
; Purpose:    Resets the stream position to zero.
; Arguments:  None.
; Return:     Nothing.

Method TextSource.Reset, uses xsi
  local qZero:QWORD

  SetObject xsi
  xor eax, eax
  mov [xsi].MemStream.dPosition, eax                    ;Position = 0
  mov [xsi].MemStream.dCurrSize, eax                    ;Fill level = 0
  mov [xsi].dSrcPos, eax

  mov (QUADWORD ptr qZero).LoDWord, eax
  mov (QUADWORD ptr qZero).HiDWord, eax
  int 3
  OCall [xsi].pSource::Stream.Seek, QWORD ptr 0, STM_BEGIN
MethodEnd

;##/

; ==================================================================================================
;  Collections implementation
; ==================================================================================================

;##\

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

;##/

endif