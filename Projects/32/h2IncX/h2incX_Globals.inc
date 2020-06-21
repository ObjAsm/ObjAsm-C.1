; ==================================================================================================
; Title:    h2incX_Globals.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  Creates MASM .inc files from C .h files.
; Notes:    See h2incX.asm
; ==================================================================================================


;General equates
VERSION           equ   "C.01.00"
COPYRIGHT         equ   "(C) 2018-today by Biterider, 2005-2009 by Japheth"
MAX_WARNING_LEVEL equ   3       ;max value for -Wn switch

;Prototypes
InsertStrg proto :POINTER, :PSTRINGA, :DWORD
InsertAttr proto :POINTER, :PSTRINGA, :DWORD, :DWORD
InsertEqui proto :POINTER, :PSTRINGA, :DWORD, :PSTRINGA, :DWORD

;ASCII codes
TAB       equ 09
LF        equ 10
CR        equ 13

;ASCII strings
szBell    equ <"07">
szBackSp  equ <"08">
szHTab    equ <"09">
szLF      equ <"0A">
szVTab    equ <"0B">
szFF      equ <"0C">
szCR      equ <"0D">

;Prototype qualifiers
PTQ_CDECL           equ   0001h   ;cdecl
PTQ_STDCALL         equ   0002h   ;stdcall
PTQ_INLINE          equ   0004h   ;inline
PTQ_IMPORT          equ   0008h   ;declspec(dllimport)
PTQ_SYSCALL         equ   0010h   ;syscall
PTQ_PASCAL          equ   0020h   ;pascal
PTQ_FASTCALL        equ   0040h   ;fastcall
PTQ_VECTORCALL      equ   0080h   ;vectorcall
PTQ_STATIC          equ   1000h   ;static

;C Basic Type Specifier
CTS_signed          equ   BIT04
CTS_unsigned        equ   CTS_signed shl 1
CTS_short           equ   CTS_unsigned shl 1
CTS_long            equ   CTS_short shl 1
CTS_long2           equ   CTS_long shl 1
CTS_void            equ   01
CTS_char            equ   02
CTS_bool            equ   03
CTS_int             equ   04
CTS_float           equ   05
CTS_double          equ   06
CTS___int8          equ   07
CTS___int16         equ   08
CTS___int32         equ   09
CTS___int64         equ   10
CTS___wchar_t       equ   11

;Types for ParseBlock()
PBT_MEM_LAYOUT      equ   0       ;struct/union
PBT_EXTERN          equ   1       ;extern
PBT_ENUM            equ   2       ;enum

;Parser output ctrl codes
PCT_EOL             equ   0E0h    ;(à) End of Line
PCT_WEAKEOL         equ   0E1h    ;(á) "\" at the end of preprocessor lines
PCT_COMMENT         equ   0E2h    ;(â) Comment token
PCT_IGNORE          equ   0E3h    ;(ã) Ignore token
PCT_MACRO           equ   0E4h    ;(ä) Is a macro

;Flag values in [Known Macros]
MCF_KNOWN           equ   001h    ;Known macro comming from Ini-File or default values
MCF_HAS_PARAMS      equ   002h    ;Macro has parameters
MCF_SKIP_BRACES     equ   004h    ;Skip first and last parenthesis in macro invocation
MCF_COPY_LINE       equ   008h    ;Assume rest of line belongs to macro invocation
MCF_PARAMS_FOLLOW   equ   010h    ;Assume method parameters coming after macro invocation
MCF_END_MACRO       equ   020h    ;End next block with a ???_END macro invocation
MCF_STRUCT_BEG      equ   040h    ;Macro begins a struct/union definition
MCF_INTERFACE_BEG   equ   080h    ;Add an "??Interface equ <xxx>" line
MCF_INTERFACE_END   equ   100h    ;Add an "??Interface equ <>" line
MCF_ARG_EXPRESSION  equ   200h    ;Force argument handling as an expression
MCF_SKIP_INVOKATION equ   400h    ;Skip macro invocation

;Flag values in [Known Equates]
EQF_KNOWN           equ   001h    ;Known equate comming from Ini-File or default values
EQF_HAS_EOL         equ   002h

;PP conditional types
PCT_IF              equ   000h    ;"#if"
PCT_ELIF            equ   001h    ;"#elif"
PCT_IFDEF           equ   002h    ;"#ifdef"
PCT_IFNDEF          equ   003h    ;"#ifndef"

;PP conditional result
PPR_FALSE           equ   0
PPR_TRUE            equ   1
PPR_UNKNOWN         equ   2

PTOKEN  typedef     ptr CHRA

;Prototypes & externdefs
ParseMacroInvocation    proto :PTOKEN, :DWORD, :DWORD
ParseBlock              proto :PTOKEN, :DWORD
ProcessFile             proto :PTOKEN, :ptr IncFile

.const
szEmpty BYTE          0
CBStrA szUnsigned,    "unsigned"
CBStrA szSigned,      "signed"
CBStrA szStruct,      "struct"
CBStrA szUnion,       "union"
CBStrA szClass,       "class"
CBStrA szEnum,        "enum"
CBStrA szVoid,        "void"
CStrA szSpace,        " "
CStrA szComma,        ","
CStrA szColon,        ":"
CStrA szSemiColon,    ";"
CStrA szUnderscore,   "_"
CStrA szResWordSuffix,"_"
CStrA szDllImport,    "DllImport"
CStrA szPtrSpace,     "ptr "
CStrA szUnkType,      "??TYPE"
CStrA szOutOfSpace,   "out of symbol space"

CStrA szBYTE,         "BYTE"
CStrA szSBYTE,        "SBYTE"
CStrA szWORD,         "WORD"
CStrA szSWORD,        "SWORD"
CStrA szDWORD,        "DWORD"
CStrA szSDWORD,       "SDWORD"
CStrA szQWORD,        "QWORD"
CStrA szSQWORD,       "SQWORD"
CStrA szOWORD,        "OWORD"
CStrA szSOWORD,       "SOWORD"
CStrA szREAL4,        "REAL4"
CStrA szREAL8,        "REAL8"
CStrA szREAL10,       "REAL10"

CStrA szNesting2Deep, "'if' nesting level too deep"
CStrA szElseWoIf,     "'else'/'elif' without 'if'"
CStrA szEndifWoIf,    "'endif' without 'if'"


.data?
g_szCreation    CHRA   32 dup (?)       ;Creation Time for all converted .h files
g_szComment     CHRA 4096 dup (?)       ;Temp Buffer for comments
g_szTemp        CHRA  128 dup (?)       ;Temp Buffer for TranslateReservedWord()
g_szMacroBuffer CHRA 1024 dup (?)       ;Temp Buffer for macro operations

DebugMessage    CHRA  512 dup (?)

DebugCaption PSTRINGA ?

DbgOutputF macro Color:req, Message:req, Args:vararg
  if DEBUGGING
    DbgSaveContext
    DbgSetDestWnd "Output"
    ifnb <Args>
      invoke wsprintf, offset DebugMessage, $OfsCStrA($Esc(Message)), Args
      invoke DbgOutTextA, offset DebugMessage, Color, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    else
      invoke DbgOutTextA, $OfsCStrA($Esc(Message)), Color, DBG_EFFECT_NEWLINE, ??DbgDstWnd
    endif
    DbgLoadContext
  endif
endm

DbgPrintF macro Color:req, Message:req, Args:vararg
    if 0
      DbgOutputF Color, Message, Args
    endif
endm

DbgErrorF macro Color:req, Message:req, Args:vararg
  if 1
    DbgOutputF Color, Message, Args
  endif
endm


.data

;--- global variables

g_pMemPool          POINTER   NULL          ;-> Memory Pool (like a heap)
g_pIF_Reader        POINTER   NULL          ;-> Ini-File Reader
g_dRecordNameSufix  DWORD     0             ;Added at the end of record and field names
g_dStructNameSufix  DWORD     0             ;Added at the end of DUMMYSTRUCTNAME
g_dUnionNameSufix   DWORD     0             ;Added at the end of DUMMYUNIONNAME
g_dStructSuffix     DWORD     0             ;Used for nameless structures => STRUCT_xxxx
if DEBUGGING
g_dIncLevel         DWORD     0
endif
g_dResult           DWORD     0             ;Process exit value
g_dDefCallConv      DWORD     PTQ_FASTCALL  ;Default calling convention
g_bTerminate        BYTE      FALSE         ;TRUE = terminate application as soon as possible

g_pFilespec         PSTRINGA  NULL          ;-> filespec Command line param
g_pOutDir           PSTRINGA  $OfsCStrA(".") ;-o -> Command line output directory
g_pIncDir           PSTRINGA  NULL          ;-I -> Command line include directory

g_bShowUsage        BYTE      FALSE         ;-h | -? command line switch
g_bAddAlign         BYTE      FALSE         ;-a command line switch
g_bBatchmode        BYTE      FALSE         ;-b command line switch
g_bIncludeComments  BYTE      FALSE         ;-c command line switch
g_bAssumeDllImport  BYTE      FALSE         ;-d command line switch
g_bUse@DefProto     BYTE      FALSE         ;-D command line switch
g_bCreateDefs       BYTE      FALSE         ;-e command line switch
g_bIgnoreDllImport  BYTE      FALSE         ;-g command line switch
g_bProcessInclude   BYTE      FALSE         ;-i command line switch
g_bUntypedMembers   BYTE      FALSE         ;-m command line switch
g_bNoRecords        BYTE      FALSE         ;-q command line switch
g_bRecordsInUnions  BYTE      FALSE         ;-r command line switch
g_bSummary          BYTE      FALSE         ;-S command line switch
g_bUntypedParams    BYTE      FALSE         ;-u command line switch; STRUCTS = TRUE, TYPES = FALSE
g_bVerbose          BYTE      FALSE         ;-v command line switch
g_bWarningLevel     BYTE      0             ;-W command line switch
g_bOverwrite        BYTE      FALSE         ;-y command line switch

g_bOutDirExpected   BYTE      FALSE         ;GetOption temp var for -o command line switch
g_bSelExpected      BYTE      FALSE         ;GetOption temp var for -s command line switch
g_bCallConvExpected BYTE      FALSE         ;GetOption temp var for -k command line switch
g_bIncDirExpected   BYTE      FALSE         ;GetOption temp var for -I command line switch

g_bPrototypes       BYTE      TRUE          ;modified by -s command line switch
g_bTypedefs         BYTE      TRUE          ;modified by -s command line switch
g_bConstants        BYTE      TRUE          ;modified by -s command line switch
g_bExternals        BYTE      TRUE          ;modified by -s command line switch


;--- table for sections to read from h2incX.ini

CONV_TAB_ENTRY struct
  pSectionName  PSTRINGA  ?   ;-> ini section name
  pList         POINTER   ?   ;-> List
  dAlloc        DWORD     ?   ;List memory allocation count
  dIncr         DWORD     ?   ;List memory increment count
  dFlags        DWORD     ?   ;List flags
  pFileName     PSTRINGA  ?   ;Load/Save Filename
  pDefault      POINTER   ?   ;-> default table
CONV_TAB_ENTRY ends
PCONV_TAB_ENTRY typedef ptr CONV_TAB_ENTRY

CF_SNGL   equ 0001h           ;Single string
CF_CASE   equ 0002h           ;Single lowercase string
CF_EQUI   equ 0004h           ;string -> string conversion
CF_ATTR   equ 0008h           ;string -> DWORD conversion
CF_INIF   equ 0010h           ;Load from Ini-File

CONV_ATTR_ENTRY struc
  pName   PSTRINGA ?
  dValue  DWORD    ?
CONV_ATTR_ENTRY ends

CONV_EQUI_ENTRY struc
  pName   PSTRINGA ?
  pEqui   PSTRINGA ?
CONV_EQUI_ENTRY ends

CONV_BASIC_TYPE_ENTRY struc
  dSpec   DWORD    ?
  pName   PSTRINGA ?
CONV_BASIC_TYPE_ENTRY ends


DefineConvTabEntry macro EName:req, Alloc:req, Incr:req, Flags:=<>, FName:= <>, SName:=<>
  ifb <FName>
    FN equ <NULL>
  else
    FN equ <$OfsCStrA("H2I_&FName&.lst")>               ;;Filename
  endif

  if Flags and CF_INIF
%   EName CONV_TAB_ENTRY <$OfsCBStrA("&SName"), NULL, Alloc, Incr, Flags, FN, offset g_Default&EName&Tab>
  else
%   EName CONV_TAB_ENTRY <offset szEmpty, NULL, Alloc, Incr, Flags, FN, NULL>
  endif
  g_p&EName textequ <&EName.pList>
endm

g_PersistConvTable label POINTER
DefineConvTabEntry  SimpleTypes,     1000, 100, CF_SNGL or CF_INIF, <TypeNames>, <Simple Type Names>
DefineConvTabEntry  KnownMacros,     1000, 100, CF_ATTR or CF_INIF, <KnwMacros>, <Macro Names>
DefineConvTabEntry  KnownEquates,    1000, 100, CF_ATTR or CF_INIF, <KnwEquate>, <Equate Names>
DefineConvTabEntry  KnownStructs,    1000, 100, CF_SNGL or CF_INIF, <KnwStruct>, <Structure Names>
DefineConvTabEntry  KnownQualifiers, 1000, 100, CF_ATTR or CF_INIF, <KnwQualif>, <Prototype Qualifiers>
DefineConvTabEntry  ReservedWords,   1000, 100, CF_CASE or CF_INIF, <ResvWords>, <Reserved Words>
DefineConvTabEntry  ConvertTypeQual, 1000, 100, CF_EQUI or CF_INIF, <QualifCnv>, <Type Qualifier Conversion>
DefineConvTabEntry  ConvertTypes1,   1000, 100, CF_EQUI or CF_INIF, <TypeConv1>, <Type Conversion 1>
DefineConvTabEntry  ConvertTypes2,   1000, 100, CF_EQUI or CF_INIF, <TypeConv2>, <Type Conversion 2>
DefineConvTabEntry  ConvertTypes3,   1000, 100, CF_EQUI or CF_INIF, <TypeConv3>, <Type Conversion 3>
DefineConvTabEntry  ConvertTokens,   1000, 100, CF_EQUI or CF_INIF, <TokenConv>, <Token Conversion>
DefineConvTabEntry  Alignments,      1000, 100, CF_ATTR or CF_INIF, <Alignment>, <Alignment>
DefineConvTabEntry  TypeSize,        1000, 100, CF_ATTR or CF_INIF, <TypeSizes>, <Type Size>
DefineConvTabEntry  Annotations,     1000, 100, CF_SNGL or CF_INIF, <KnwAnnots>, <Annotations>
g_VolatilConvTable label POINTER
DefineConvTabEntry  InpFiles,         100,  10, CF_SNGL, <ConvFiles>
DefineConvTabEntry  Macros,          1000, 100, CF_ATTR, <NewMacros>
DefineConvTabEntry  Equates,         1000, 100, CF_ATTR, <NewEquate>
DefineConvTabEntry  Structs,         1000, 100, CF_SNGL, <NewStruct>
DefineConvTabEntry  Qualifiers,      1000, 100, CF_ATTR, <NewQualif>
DefineConvTabEntry  Prototypes,      1000, 100, CF_SNGL, <NewProtos>
DefineConvTabEntry  Typedefs,        1000, 100, CF_SNGL, <NewTypdef>
POINTER NULL


.const

externdef pepe:DWORD
pepe DWORD 15



;Token conversion, use with care!

g_DefaultConvertTokensTab label POINTER
  CONV_EQUI_ENTRY <$OfsCBStrA("interface"), offset szStruct>
  POINTER NULL

;Known type attribute names, usually not used, since defined in h2incX.ini.
g_DefaultConvertTypeQualTab label POINTER
  CONV_EQUI_ENTRY <$OfsCBStrA("const"),     offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("volatile"),  offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("restrict"),  offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("_Atomic"),   offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("far"),       offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("near"),      offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("IN"),        offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("OUT"),       offset szEmpty>
  POINTER NULL

;Known macro names, usually not used, since defined in h2incX.ini.
;Meaning of ATTR value:
;  MCF_KNOWN            001h => Skip braces in macro call
;  MCF_HAS_PARAMS       002h => Macro has parameters
;  MCF_SKIP_BRACES      004h => Skip braces in macro call
;  MCF_COPY_LINE        008h => Assume rest of line belongs to macro call
;  MCF_PARAMS_FOLLOW    010h => Assume method parameters coming after macro
;  MCF_END_MACRO        020h => End next block with a ???_END macro call
;  MCF_STRUCT_BEG       040h => Macro begins a struct/union
;  MCF_INTERFACE_BEG    080h => Add an "??Interface equ <xxx>" line
;  MCF_INTERFACE_END    100h => Add an "??Interface equ <>" line
;  MCF_ARG_EXPRESSION   200h => Force argument handling as expression
;  MCF_SKIP_INVOKATION  400h => skip macro invokation
;
;  31: STDMETHOD handling: skip braces, copy rest of line assuming that they are function params.
;  35: terminate block with a <macroname>_END macro invocation
;
;Support for MIDL generated header files:
;  67: assume MIDL_INTERFACE: start a struct declaration
; 129: assume BEGIN_INTERFACE: add "??Interface equ <xxx>" line
; 257: assume END_INTERFACE: add "??Interface equ <>" line

g_DefaultKnownMacrosTab label POINTER
  CONV_ATTR_ENTRY <$OfsCBStrA("BEGIN_INTERFACE"),           MCF_KNOWN or MCF_INTERFACE_BEG>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_HANDLE"),            MCF_KNOWN or MCF_HAS_PARAMS>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_INTERFACE"),         MCF_KNOWN or MCF_HAS_PARAMS or MCF_END_MACRO>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_INTERFACE_"),        MCF_KNOWN or MCF_HAS_PARAMS or MCF_END_MACRO>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_INTERFACE_IID"),     MCF_KNOWN or MCF_HAS_PARAMS or MCF_END_MACRO>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_INTERFACE_IID_"),    MCF_KNOWN or MCF_HAS_PARAMS or MCF_END_MACRO>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLSPEC_UUID"),             MCF_KNOWN or MCF_HAS_PARAMS>
  CONV_ATTR_ENTRY <$OfsCBStrA("DEFINE_GUID"),               MCF_KNOWN or MCF_HAS_PARAMS or MCF_SKIP_BRACES>
  CONV_ATTR_ENTRY <$OfsCBStrA("END_INTERFACE"),             MCF_KNOWN or MCF_INTERFACE_END>
  CONV_ATTR_ENTRY <$OfsCBStrA("SHSTDAPI_"),                 MCF_KNOWN or MCF_HAS_PARAMS>
  CONV_ATTR_ENTRY <$OfsCBStrA("STDMETHOD"),                 MCF_KNOWN or MCF_HAS_PARAMS or MCF_SKIP_BRACES or MCF_COPY_LINE or MCF_PARAMS_FOLLOW>
  CONV_ATTR_ENTRY <$OfsCBStrA("STDMETHOD_"),                MCF_KNOWN or MCF_HAS_PARAMS or MCF_SKIP_BRACES or MCF_COPY_LINE or MCF_PARAMS_FOLLOW>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINOLEAPI_"),                MCF_KNOWN or MCF_HAS_PARAMS>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_FAMILY_PARTITION"),   MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_DESKTOP"),  MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_APP"),      MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_PHONE_APP"),MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_SYSTEM"),   MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_PHONE"),    MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  POINTER NULL

;Known equate names, usually not used, since defined in h2incX.ini.
;Meaning of ATTR value:
;  EQF_KNOWN            001h

g_DefaultKnownEquatesTab label POINTER
;  CONV_ATTR_ENTRY <$OfsCBStrA(""),           EQF_KNOWN>
  POINTER NULL

;Known structure names, usually not used, since defined in h2incX.ini.
g_DefaultKnownStructsTab label POINTER
  POINTER $OfsCBStrA("POINT")
  POINTER NULL

;Known prototype qualifier names, usually not used, since defined in h2incX.ini.
g_DefaultKnownQualifiersTab label POINTER
  CONV_ATTR_ENTRY <$OfsCBStrA("__cdecl"),    PTQ_CDECL>
  CONV_ATTR_ENTRY <$OfsCBStrA("_cdecl"),     PTQ_CDECL>
  CONV_ATTR_ENTRY <$OfsCBStrA("__stdcall"),  PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("_stdcall"),   PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("stdcall"),    PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI"),     PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPIV"),    PTQ_CDECL>
  CONV_ATTR_ENTRY <$OfsCBStrA("APIENTRY"),   PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("__inline"),   PTQ_INLINE>
  POINTER NULL

;Structure sizes. required if a structure is a parameter with size > 4.
g_DefaultTypeSizeTab label POINTER
  CONV_ATTR_ENTRY <$OfsCBStrA("CY"),         08>
  CONV_ATTR_ENTRY <$OfsCBStrA("DATE"),       08>
  CONV_ATTR_ENTRY <$OfsCBStrA("DOUBLE"),     08>
  CONV_ATTR_ENTRY <$OfsCBStrA("POINT"),      08>
  CONV_ATTR_ENTRY <$OfsCBStrA("VARIANT"),    16>
  POINTER NULL

;Simple types default, usually not used, since defined in h2incX.ini.
g_DefaultSimpleTypesTab label POINTER
  POINTER $OfsCBStrA("BYTE")
  POINTER $OfsCBStrA("SBYTE")
  POINTER $OfsCBStrA("WORD")
  POINTER $OfsCBStrA("SWORD")
  POINTER $OfsCBStrA("DWORD")
  POINTER $OfsCBStrA("SDWORD")
  POINTER $OfsCBStrA("QWORD")
  POINTER $OfsCBStrA("LONG")
  POINTER $OfsCBStrA("ULONG")
  POINTER $OfsCBStrA("REAL4")
  POINTER $OfsCBStrA("REAL8")
  POINTER $OfsCBStrA("BOOL")
  POINTER $OfsCBStrA("CHAR")
  POINTER $OfsCBStrA("ptr")
  POINTER $OfsCBStrA("PVOID")
  POINTER $OfsCBStrA("WCHAR")
  POINTER $OfsCBStrA("WPARAM")
  POINTER $OfsCBStrA("LPARAM")
  POINTER $OfsCBStrA("LRESULT")
  POINTER $OfsCBStrA("HANDLE")
  POINTER $OfsCBStrA("HINSTANCE")
  POINTER $OfsCBStrA("HGLOBAL")
  POINTER $OfsCBStrA("HLOCAL")
  POINTER $OfsCBStrA("HWND")
  POINTER $OfsCBStrA("HMENU")
  POINTER $OfsCBStrA("HDC")
  POINTER NULL

;Type conversion 1 default, usually not used since defined in h2incX.ini.
g_DefaultConvertTypes1Tab label POINTER
  CONV_EQUI_ENTRY <$OfsCBStrA("DWORDLONG"),      $OfsCBStrA("QWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("ULONGLONG"),      $OfsCBStrA("QWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("LONGLONG"),       $OfsCBStrA("SQWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("double"),         $OfsCBStrA("REAL8")>
  CONV_EQUI_ENTRY <$OfsCBStrA("float"),          $OfsCBStrA("REAL4")>
  POINTER NULL

;Type conversion 2 default, usually not used since defined in h2incX.ini.
g_DefaultConvertTypes2Tab label POINTER
  CONV_EQUI_ENTRY <$OfsCBStrA("int"),            $OfsCBStrA("SDWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("unsigned int"),   $OfsCBStrA("DWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("short"),          $OfsCBStrA("SWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("unsigned short"), $OfsCBStrA("WORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("long"),           $OfsCBStrA("SDWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("unsigned long"),  $OfsCBStrA("DWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("char"),           $OfsCBStrA("SBYTE")>
  CONV_EQUI_ENTRY <$OfsCBStrA("unsigned char"),  $OfsCBStrA("BYTE")>
  CONV_EQUI_ENTRY <$OfsCBStrA("wchar_t"),        $OfsCBStrA("WORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("LPCSTR"),         $OfsCBStrA("LPSTR")>
  CONV_EQUI_ENTRY <$OfsCBStrA("LPCWSTR"),        $OfsCBStrA("LPWSTR")>
  CONV_EQUI_ENTRY <$OfsCBStrA("UINT"),           $OfsCBStrA("DWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("ULONG"),          $OfsCBStrA("DWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("LONG"),           $OfsCBStrA("SDWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("float"),          $OfsCBStrA("REAL4")>
  CONV_EQUI_ENTRY <$OfsCBStrA("double"),         $OfsCBStrA("REAL8")>
  POINTER NULL

;Type conversion 3 default, usually not used since defined in h2incX.ini.
g_DefaultConvertTypes3Tab label POINTER
  CONV_EQUI_ENTRY < $OfsCBStrA("POINT"),         $OfsCBStrA("QWORD")>
  POINTER NULL

;Structure alignments default, usually not used since defined in h2incX.ini.
g_DefaultAlignmentsTab label POINTER
  POINTER NULL

;Reserved words default, usually not used since defined in h2incX.ini.
g_DefaultReservedWordsTab label POINTER
  POINTER $OfsCBStrA("cx")
  POINTER $OfsCBStrA("dx")
  POINTER NULL

g_DefaultAnnotationsTab label POINTER
  POINTER NULL

g_ConvertBasicType label DWORD
CONV_BASIC_TYPE_ENTRY <CTS_char,                                          offset szSBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_char,                            offset szSBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_char,                          offset szBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_bool,                                          offset szBYTE>
CONV_BASIC_TYPE_ENTRY <CTS___int8,                                        offset szSBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS___int8,                          offset szSBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS___int8,                        offset szBYTE>
CONV_BASIC_TYPE_ENTRY <CTS___int16,                                       offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS___int16,                         offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS___int16,                       offset szWORD>
CONV_BASIC_TYPE_ENTRY <CTS_short,                                         offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_short or CTS_int,                              offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_short,                           offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_short or CTS_int,                offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_short,                         offset szWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_short or CTS_int,              offset szWORD>
CONV_BASIC_TYPE_ENTRY <CTS___wchar_t,                                     offset szWORD>
CONV_BASIC_TYPE_ENTRY <CTS___int32,                                       offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS___int32,                         offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS___int32,                       offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed,                                        offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned,                                      offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_int,                                           offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_int,                             offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_int,                           offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_long,                                          offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_long,                            offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_long,                          offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS___int64,                                       offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS___int64,                         offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS___int64,                       offset szQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_long or CTS_int,                               offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_long or CTS_int,                 offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_long or CTS_int,               offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_long or CTS_long2,                             offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_long or CTS_long2,             offset szQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_long or CTS_long2,               offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_long or CTS_long2 or CTS_int,                  offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_long or CTS_long2 or CTS_int,    offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_long or CTS_long2 or CTS_int,  offset szQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_float,                                         offset szREAL4>
CONV_BASIC_TYPE_ENTRY <CTS_double,                                        offset szREAL8>
CONV_BASIC_TYPE_ENTRY <CTS_long or CTS_double,                            offset szREAL10>
CONV_BASIC_TYPE_ENTRY <CTS_void,                                          offset szEmpty>
DWORD 0

;Command line switch table
CMDLINE_SWITCH_ENTRY struct
  bSwitch   BYTE     ?
  bType     BYTE     ?
  pVariable POINTER  ?
CMDLINE_SWITCH_ENTRY ends

CLS_IS_BOOL  equ 1
CLS_IS_PROC  equ 2     ;not used yet

CmdLineSwitchTab label BYTE
  CMDLINE_SWITCH_ENTRY <"?", CLS_IS_BOOL, offset g_bShowUsage>
  CMDLINE_SWITCH_ENTRY <"a", CLS_IS_BOOL, offset g_bAddAlign>
  CMDLINE_SWITCH_ENTRY <"b", CLS_IS_BOOL, offset g_bBatchmode>
  CMDLINE_SWITCH_ENTRY <"c", CLS_IS_BOOL, offset g_bIncludeComments>
  CMDLINE_SWITCH_ENTRY <"e", CLS_IS_BOOL, offset g_bCreateDefs>
  CMDLINE_SWITCH_ENTRY <"h", CLS_IS_BOOL, offset g_bShowUsage>
  CMDLINE_SWITCH_ENTRY <"i", CLS_IS_BOOL, offset g_bProcessInclude>
  CMDLINE_SWITCH_ENTRY <"I", CLS_IS_BOOL, offset g_bIncDirExpected>
  CMDLINE_SWITCH_ENTRY <"k", CLS_IS_BOOL, offset g_bCallConvExpected>
  CMDLINE_SWITCH_ENTRY <"o", CLS_IS_BOOL, offset g_bOutDirExpected>
  CMDLINE_SWITCH_ENTRY <"q", CLS_IS_BOOL, offset g_bNoRecords>
  CMDLINE_SWITCH_ENTRY <"r", CLS_IS_BOOL, offset g_bRecordsInUnions>
  CMDLINE_SWITCH_ENTRY <"s", CLS_IS_BOOL, offset g_bSelExpected>
  CMDLINE_SWITCH_ENTRY <"S", CLS_IS_BOOL, offset g_bSummary>
  CMDLINE_SWITCH_ENTRY <"u", CLS_IS_BOOL, offset g_bUntypedParams>
  CMDLINE_SWITCH_ENTRY <"v", CLS_IS_BOOL, offset g_bVerbose>
  CMDLINE_SWITCH_ENTRY <"y", CLS_IS_BOOL, offset g_bOverwrite>
  BYTE 0

szUsage label CHRA
  CHRA "h2incX, Version ", VERSION, ", ", COPYRIGHT, LF
  CHRA "Usage: h2incX <options> filespec", LF
  CHRA "  -a: add @Align to STRUCT declarations", LF
  CHRA "  -b: batch mode, no user interaction", LF
  CHRA "  -c: include comments in output", LF
  CHRA "  -d0|1|2|3: define __declspec(dllimport) handling:", LF
  CHRA "      - 0: [default] decide depending on values in h2incX.ini", LF
  CHRA "      - 1: always assume __declspec(dllimport) is set", LF
  CHRA "      - 2: always assume __declspec(dllimport) is not set", LF
  CHRA "      - 3: if possible use @DefProto macro to define prototypes", LF
  CHRA "  -e: write full decorated names of function prototypes to a .DEF file", LF
  CHRA "  -h | -?: show usage help", LF
  CHRA "  -i: process #include lines", LF
  CHRA "  -I directory: specify an additional directory to search for header files", LF
  CHRA "  -k c|s|p|y|f|v: set default calling convention for prototypes", LF
  CHRA "      - c: CDECL", LF
  CHRA "      - s: STDCALL", LF
  CHRA "      - p: PASCAL", LF
  CHRA "      - y: SYSCALL", LF
  CHRA "      - f: FASTCALL", LF
  CHRA "      - v: VECTORCALL", LF
  CHRA "  -o directory: set output directory (default is current dir)", LF
  CHRA "  -q: avoid RECORD definitions", LF
  CHRA "  -r: create size-safe RECORD definitions", LF
  CHRA "  -s c|p|t|e: selective output", LF
  CHRA "      - c: constants", LF
  CHRA "      - p: prototypes", LF
  CHRA "      - t: typedefs", LF
  CHRA "      - e: externals", LF
  CHRA "  -S: print summary (structures, macros, prototypes, typedefs)", LF
  CHRA "  -u: generate untyped parameters (DWORDs) in prototypes", LF
  CHRA "  -v: verbose mode", LF
  CHRA "  -W0|1|2|3: set warning level (default is 0)", LF
  CHRA "  -y: overwrite existing .inc files without confirmation", LF
  CHRA 0