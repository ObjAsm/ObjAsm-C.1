; ==================================================================================================
; Title:      OA_ObjExplorer_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Object Browser globals.
; Notes:      Version C.1.0, December 2020
;               - First release.
; ==================================================================================================


include OA_ObjExplorer_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)

INF_PRJ               equ   BIT00             ;This Info belongs to the current project
INF_INVALID           equ   BIT01             ;This is an info about an invalid object or interface
INF_INTREE            equ   BIT02             ;This Info is loaded into the tree
INF_INTERFACE         equ   BIT31             ;This Info is about a COM interface

INFO_TYPE_OBJECT      equ   0                 ;Link type encoded in the char color
INFO_TYPE_INTERFACE   equ   1

APP_VISIT     equ   0
APP_EMAIL     equ   1
APP_CHECK     equ   2

INFO_BUILD    equ   0
INFO_UPDATE   equ   1

CStr  cIconName,      "ICON_APP"

;Setup strings
CStr  cViewer,        "Viewer"
CStr  cDefViewer,     '"%ProgramFiles%\Notepad++\Notepad++.exe" "%s" -n%lu'     ;Default string
CStr  cLanguage,      "Language"
CStr  cShowRedefMtds, "ShowRedefinedMethods"
CStr  cShowRedefVars, "ShowRedefinedVariables"

CStr  cShow,          "show"
CStr  cViewerError,   "Can't start the specified viewer.", CRLF, "Please check the application setup.", CRLF
CStr  cOpen,          "open"

;Markup Texts
MTXT_NAME           CHR "{PA 20,ALB,Z}", \
                        "[H+2,HI 20,N#FFFFFF]", \
                          "[H+3][B][U]Object Name[~]:[~]     "
MTXT_END            CHR   "[~]{P}{P}", \
                        "[~]", 0
MTXT_FILES          CHR "{P}[H+1,B][U]Files[~]:[~]{TABCLR}{TL 30}{TL 200}{TC 800}{TC 950}{P}", \
                        "[B]{T}{T}File Name{T}Last Write{T}Status[~]{P}"
MTXT_FILE_INC       CHR "{T}[B]Definition:[~]{T}"
MTXT_FILE_ASM       CHR "{T}[B]Assembly:[~]{T}"
MTXT_FILE_LIB32A    CHR "{T}[B]Library 32 bit ANSI:[~]{T}"
MTXT_FILE_LIB32W    CHR "{T}[B]Library 32 bit WIDE:[~]{T}"
MTXT_FILE_LIB64A    CHR "{T}[B]Library 64 bit ANSI:[~]{T}"
MTXT_FILE_LIB64W    CHR "{T}[B]Library 64 bit WIDE:[~]{T}"
MTXT_INHER          CHR "{P}[H+1,B][U]Inheritance Path[~]:[~]     "
MTXT_ARROW          CHR " [F'Wingdings']{#00E8}[~] "
MTXT_LINK_BEG       CHR "[APP "
MTXT_LINK_END       CHR ",C#0066D5]"
MTXT_ICON_BEG       CHR "{C "
MTXT_ICON_END       CHR "}"
MTXT_ICON_VAR_UNK   CHR "{C ", "0" + VARIABLETYPE_UNKNOWN, "}"
MTXT_ICON_VAR_REG   CHR "{C ", "0" + VARIABLETYPE_REGULAR, "}"
MTXT_ICON_VAR_RED   CHR "{C ", "0" + VARIABLETYPE_REDEFINED, "}"
MTXT_ICON_VAR_OBJ   CHR "{C ", "0" + VARIABLETYPE_OBJECT, "}"
MTXT_OK             CHR "OK"
MTXT_DOT            CHR "."
MTXT_UNKNOWN        CHR "[C#FF0000,I]Not found[~]"
MTXT_ABSTRACT       CHR "Abstract"
MTXT_REGULAR        CHR "Regular"
MTXT_CHECK          CHR "[F'Wingdings 2',C#007F00,B]{#50}[~]"
MTXT_CROSS          CHR "[F'Wingdings 2',C#FF0000,B]{#4F}[~]"
MTXT_LASTUPDATE     CHR "Last update: [%02hu/%02hu/%02hu %02hu:%02hu:%02hu]{T}"
MTXT_MTDS           CHR "[H+1,B][U]Member Methods[~]:[~]{P}{TABCLR}{TL 30}{TC 450}{TC 650}{TC 800}[B]{T}Name{T}Type{T}Implementation{T}Status[~]{P}"
MTXT_VARS           CHR "[H+1,B][U]Member Variables[~]:[~]{P}{TABCLR}{TL 30}{TC 450}{TC 650}{TC 800}[B]{T}Name{T}Type{T}Value{T}Status[~]{P}"
MTXT_NO_INFO        CHR "[I]No information available[~]"
MTXT_TPL_DEFAULTS   CHR "[I]Template Defaults[~]"
MTXT_COLOR_BLACK    CHR "[C#000000]"
MTXT_COLOR_GRAY     CHR "[C#7F7F7F]"
MTXT_COLOR_RED      CHR "[C#FF0000]"
MTXT_STYLE_ITALIC   CHR "[I]"
MTXT_STYLE_BOLD     CHR "[B]"
MTXT_STYLE_NONE     CHR "[H+0]"
MTXT_STYLE_CLOSE    CHR "[~]"
MTXT_PARA           CHR "{P}"
MTXT_BREAK          CHR "{B}"
MTXT_TAB            CHR "{T}"
MTXT_FILE_NOT_FOUND CHR "[C#FF0000,I]File Not Found[~]"
MTXT_OUTDATED       CHR "[C#FF0000,I]Outdated[~]"

.const
;Lookup tables

SOM_TEXT_TABLE \
  PSTRING $OfsTStr("Unknown type")
  PSTRING $OfsTStr("Static")
  PSTRING $OfsTStr("Virtual")
  PSTRING $OfsTStr("Virtual")             ;Abstract
  PSTRING $OfsTStr("Virtual Event")       ;Event
  PSTRING $OfsTStr("Dynamic")
  PSTRING $OfsTStr("Dynamic")             ;Abstract
  PSTRING $OfsTStr("Dynamic Event")       ;Event
  PSTRING $OfsTStr("Interface")
  PSTRING $OfsTStr("Inline")
  PSTRING $OfsTStr("Redefined")
  PSTRING $OfsTStr("Standard")
  PSTRING $OfsTStr("Dispatch")
