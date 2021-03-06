; ==================================================================================================
; Title:      OA_ObjectBrowser_Main.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjectBrowser.asm
; Purpose:    Window definitions for OA_ObjBrowser.
; ==================================================================================================


CLSSTYLE      equ   CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

TBSTYLE       equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                    CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

SBSTYLE       equ   WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

NODE_HEIGHT   equ  20
NODE_WIDTH    equ  146

.const
ToolbarFile DEF_TOOLBAR {IDC_TOOLBARFILE, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("File commands"), 0, 0, 0, 0, 1}
  TBBUTTON {IDB_FILE_SETUP,     IDM_FILE_SETUP,    TBSTATE_ENABLED, TBSTYLE_BUTTON}

ToolbarWindow DEF_TOOLBAR {IDC_TOOLBARWINDOW, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                           $OfsTStr("Window commands"), 0, 0, 0, 0, 9}
  TBBUTTON {IDB_WIND_CASCADE,   IDM_WIND_CASCADE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WIND_TILE_HORZ, IDM_WIND_TILE_HOR, TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WIND_TILE_VERT, IDM_WIND_TILE_VER, TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WIND_ARRANGE,   IDM_WIND_ARRANGE,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WIND_PREV,      IDM_WIND_PREV,     TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WIND_NEXT,      IDM_WIND_NEXT,     TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                  -1,                TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_WIND_CLOSE,     IDM_WIND_CLOSE,    TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WIND_CLOSEALL,  IDM_WIND_CLOSEALL, TBSTATE_ENABLED, TBSTYLE_BUTTON}

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SBSTYLE, 0, 4}
  DEF_STATUSBAR_PART {220, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL} ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}


; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object ClientWnd, ObjBwrClientWndID, MdiClientWnd       ;MDI client window.
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER         ;-> Owner

  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnPaint,            WM_PAINT

  DefineVariable    hBGBrush,           HBRUSH,     0   ;Background brush
  DefineVariable    dChildCount,        DWORD,      0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object PropWnd, PropWndID, MdiChildWnd                  ;MDI base child window.
  RedefineMethod    Done
  RedefineMethod    Init,               $ObjPtr(ClientWnd), PSTRING, PINFORMATION
  StaticMethod      InitContainer,      PSTRING
  VirtualAbstract   EmitHtml
  VirtualAbstract   Gather

  VirtualEvent      OnClose,            WM_CLOSE
  VirtualEvent      OnSize,             WM_SIZE

  DefineVariable    pInfo,              PINFORMATION, NULL
  DefineVariable    pName,              PSTRING,    NULL

  DefineVariable    pTextView,          $ObjPtr(TextView), NULL
  DefineVariable    dInitialized,       DWORD,      FALSE
  DefineVariable    dShowRedefMtds,     DWORD,      TRUE
  DefineVariable    dShowRedefVars,     DWORD,      TRUE
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CStr cIntPropClass, "IntPropWndClass"

Object IntPropWnd, IntPropWndID, PropWnd
  RedefineMethod    Done
  RedefineMethod    Init,               $ObjPtr(ClientWnd), PSTRING, PINTERFACEINFORMATION
  RedefineMethod    Gather
  StaticMethod      GatherMethods,      PINTERFACEINFORMATION
  StaticMethod      ShowInheritance,    PINTERFACEINFORMATION, DWORD
  StaticMethod      Startup

  Embed     Methods,     DataCollection       ;Collection of MEMBERDATA structures
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CStr cObjPropClass, "ObjPropWndClass"

Object ObjPropWnd, ObjPropWndID, PropWnd
  RedefineMethod    Done
  RedefineMethod    Init,               $ObjPtr(ClientWnd), PSTRING, POBJECTINFORMATION
  RedefineMethod    Gather
  StaticMethod      GatherMethods,      POBJECTINFORMATION
  StaticMethod      GatherVariables,    POBJECTINFORMATION
  StaticMethod      ShowInheritance,    POBJECTINFORMATION, DWORD
  StaticMethod      Startup
  VirtualEvent      OnNotify,           WM_NOTIFY

  Embed     Methods,     DataCollection       ;Collection of MEMBERDATA structures
  Embed     Variables,   DataCollection       ;Collection of MEMBERDATA structures

  DefineVariable    dRadioBtn1,         DWORD,    TRUE  
  DefineVariable    dRadioBtn2,         DWORD,    FALSE  
  DefineVariable    dCheckBox1,         DWORD,    FALSE 
  DefineVariable    dCheckBox2,         DWORD,    FALSE  
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object FindInfoDlg,, Dialog
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, HANDLE
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnActivate,         WM_ACTIVATE

  DefineVariable    hSearch,            HANDLE,   0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object SetupDlg,, DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, HANDLE
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CloseEnumProc    proto :HANDLE, :LPARAM

CStr cObjectBrowserClass, "ObjectBrowserClass"

Object ObjectBrowser, ObjectBrowserID, MdiApp           ;MDI application.
  VirtualMethod     ChangeBtnLanguage,  DWORD           ;IDLANG_XXX
  VirtualMethod     ChangeLanguage,     DWORD           ;IDLANG_XXX
  RedefineMethod    Done
  StaticMethod      EnableActions
  StaticMethod      ExtractResFile,     HANDLE, POINTER, PSTRING, PSTRING
  StaticMethod      FindObjInfo,        PSTRING
  VirtualMethod     FindIntInfo,        PSTRING
  RedefineMethod    Init
  VirtualMethod     Navigate,           PSTRING, DWORD
  VirtualMethod     Refresh,            DWORD
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      TreeDecimate,       $ObjPtr(InfoNode)

  StaticMethod      Startup
  VirtualMethod     StatusbarHelp,      PSTRING         ;-> Help string

  VirtualEvent      OnClose,            WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnNotify,           WM_NOTIFY

  DefineVariable    dLanguage,          DWORD,      IDLANG_ENGLISH
  DefineVariable    hMenuChild,         HANDLE,     0
  DefineVariable    hMenuChildWnd,      HANDLE,     0
  DefineVariable    hMenuInit,          HANDLE,     0
  DefineVariable    hMenuContext,       HANDLE,     0

  Embed     IconList,         MaskedImageList
  Embed     RBar,             Rebar
  Embed     TbFile,           Toolbar
  Embed     TbWindow,         Toolbar
  Embed     Menu,             XMenu
  Embed     SBar,             Statusbar
  Embed     TreeWnd,          TreeWindow
  Embed     SplitterVer,      Splitter
  Embed     SetupFile,        IniFile
  Embed     FindInfDlg,       FindInfoDlg

  DefineVariable    pViewerApp,         POINTER,    NULL    ;-> String
  DefineVariable    dShowAll,           DWORD,      TRUE    ;Project and non project
  DefineVariable    dShowBrokenOnly,    DWORD,      FALSE   ;Invalid INFORMATION only
  DefineVariable    dShowObjects,       DWORD,      TRUE
  DefineVariable    dShowInterfaces,    DWORD,      TRUE

  DefineVariable    pObjDB,             $ObjPtr(OA_ObjDB),  NULL
  DefineVariable    dShowRedefMtds,     DWORD,      TRUE
  DefineVariable    dShowRedefVars,     DWORD,      TRUE
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

.code

if IMPLEMENT

MEMBERDATA struc
  pMemberInfo   PINFORMATION  ?
  dFlags        DWORD         ?
  pDefinition   POINTER       ?                         ;POBJMTDINFORMATION
MEMBERDATA ends
PMEMBERDATA typedef ptr MEMBERDATA

MDT_UNKNOWN         equ   BIT00
MDT_FINAL           equ   BIT01
MDT_SHOWDETAIL      equ   BIT02

REFRESH_TREE        equ   BIT00
REFRESH_CHILDREN    equ   BIT01
REFRESH_ALL         equ   REFRESH_TREE or REFRESH_CHILDREN

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

.code

; ==================================================================================================
;    ICustomDocHostUIHandler implementation
; ==================================================================================================

;##\


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      EnableContextMenuItem
; Purpose:    used to enable menu items.
; Arguments:  Arg1: menu command ID.
;             Arg2: Index into lookup structure.
; Return:     Nothing.

EnableContextMenuItem macro CMD:req, Index:req
  .ifBitClr QueryCmds[Index*sizeof(OLECMD)].OLECMD.cmdf, OLECMDF_ENABLED or OLECMDF_LATCHED
    mov eax, MF_BYCOMMAND or MF_DISABLED or MF_GRAYED
  .else
    mov eax, MF_BYCOMMAND or MF_ENABLED
  .endif
  DbgHex eax
  invoke EnableMenuItem, xdi, CMD, eax
endm


; ==================================================================================================
;    ObjectBrowser implementation
; ==================================================================================================

;##\

PROPERTIES_INFO struct
  pCaption    PSTRING   ?
  dType       DWORD     ?
  pChild      $ObjPtr(ObjPropWnd) ?
PROPERTIES_INFO ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.ChangeBtnLanguage
; Purpose:    Switch the toolbar button application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method ObjectBrowser.ChangeBtnLanguage, uses xbx xdi xsi, dLangID:DWORD

  SetButtonText macro ButtonCommand:req, TextIndex:req
    mov eax, dLangID
    add eax, TextIndex
    invoke LoadString, hInstance, eax, xdi, lengthof(cButtonText) - 1
    .if eax != 0
      invoke SendMessage, [xbx].$Obj(Toolbar).hWnd, TB_SETBUTTONINFO, ButtonCommand, addr tbbi
    .endif
  endm

  local tbbi:TBBUTTONINFO, cButtonText[256]:CHR

  SetObject xsi

  ;Set Toolbar button texts
  mov tbbi.TBBUTTONINFO.cbSize, sizeof TBBUTTONINFO
  mov tbbi.TBBUTTONINFO.dwMask, TBIF_TEXT
  lea xdi, cButtonText
  mov tbbi.TBBUTTONINFO.pszText, xdi
  mov tbbi.TBBUTTONINFO.cchText, sizeof cButtonText - 1

  lea xbx, [xsi].TbFile
  SetButtonText IDM_FILE_SETUP,    82

  lea xbx, [xsi].TbWindow
  SetButtonText IDM_WIND_CASCADE,  83
  SetButtonText IDM_WIND_TILE_HOR, 84
  SetButtonText IDM_WIND_TILE_VER, 85
  SetButtonText IDM_WIND_ARRANGE,  86
  SetButtonText IDM_WIND_PREV,     87
  SetButtonText IDM_WIND_NEXT,     88
  SetButtonText IDM_WIND_CLOSE,    89
  SetButtonText IDM_WIND_CLOSEALL, 90
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.ChangeLanguage
; Purpose:    Switches the application language.
; Arguments:  Arg1: Language ID.
; Return:     Nothing.

Method ObjectBrowser.ChangeLanguage, uses xbx xdi xsi, dLangID:DWORD
  local MenuInfo:MENUITEMINFO

  SetObject xsi
  m2m [xsi].dLanguage, dLangID, ecx                   ;Save setting

  ;Keep updated both menus!
  mov eax, dLangID
  cdiv LANGUAGE_STEP
  lea edi, [edx + IDM_LANGUAGE_ENGLISH]

  ;The IDM_LANGUAGE popup menu has to be found in the ChildMenu using GetMenuItemInfo since
  ;  it can have position 1 or 2 depending if a MDI child is maximized or not.
  mov MenuInfo.cbSize, sizeof MenuInfo
  mov MenuInfo.fMask, MIIM_SUBMENU
  invoke GetMenuItemInfo, [xsi].hMenuChild, IDM_LANGUAGE, FALSE, addr MenuInfo
  invoke CheckMenuRadioItem, MenuInfo.hSubMenu, IDM_LANGUAGE_ENGLISH, IDM_LANGUAGE_SPANISH, \
                             edi, MF_BYCOMMAND

  ;IDM_LANGUAGE popup menu has only positon 1 in the InitMenu.
  invoke GetSubMenu, [xsi].hMenuInit, 1
  invoke CheckMenuRadioItem, xax, IDM_LANGUAGE_ENGLISH, IDM_LANGUAGE_SPANISH, edi, MF_BYCOMMAND

  ;Language switch
  mov xbx, $invoke(GetMenu, [xsi].hWnd)                     ;Get the current menu
  OCall [xsi].Menu::XMenu.ChangeLanguage, xbx, dLangID      ;Active menu is converted

  ;Convert remaining main menu
  .if xbx == [xsi].hMenuInit
    OCall [xsi].Menu::XMenu.Convert, [xsi].hMenuChild, TRUE
  .else
    OCall [xsi].Menu::XMenu.Convert, [xsi].hMenuInit, TRUE
  .endif

  OCall xsi.ChangeBtnLanguage, dLangID
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.Done
; Purpose:    Finalizes the MDI application object. Objects associated with window controls are
;             destroyed by Windows automatically when WM_DESTROY is send.
; Arguments:  None.
; Return:     Nothing.

Method ObjectBrowser.Done, uses xsi
  ;DbgText "ObjectBrowser.Done"
  SetObject xsi
  OCall [xsi].pObjDB::OA_ObjDB.Done

  OCall [xsi].IconList::MaskedImageList.Done
  OCall [xsi].RBar::Rebar.Done
  OCall [xsi].SBar::Statusbar.Done
  OCall [xsi].TbFile::Toolbar.Done
  OCall [xsi].TbWindow::Toolbar.Done
  OCall [xsi].TreeWnd::TreeWindow.Done
  OCall [xsi].SplitterVer::Splitter.Done
  OCall [xsi].Menu::XMenu.Done
  TCall [xsi].FindInfDlg::DialogModeless.DestroyDialog, 0
  OCall [xsi].FindInfDlg::FindInfoDlg.Done
  OCall [xsi].pClientWnd::ClientWnd.Done

  OCall [xsi].SetupFile::IniFile.SetString, offset cSetup, offset cViewer, [xsi].pViewerApp
  OCall [xsi].SetupFile::IniFile.SetDWord,  offset cSetup, offset cLanguage, [xsi].dLanguage
  OCall [xsi].SetupFile::IniFile.SetDWord,  offset cSetup, offset cShowRedefMtds, [xsi].dShowRedefMtds
  OCall [xsi].SetupFile::IniFile.SetDWord,  offset cSetup, offset cShowRedefVars, [xsi].dShowRedefVars

  invoke StrDispose, [xsi].pViewerApp

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.EnableActions
; Purpose:    Enables or disables MDI child actions.
; Arguments:  None.
; Return:     Nothing.

Method ObjectBrowser.EnableActions, uses xbx xdi xsi
  SetObject xsi
  xor edi, edi
  mov xbx, [xsi].pClientWnd
  .if [xbx].$Obj(ClientWnd).dChildCount != 0                ;No more child windows ?
    inc edi
  .endif
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WIND_CASCADE,  edi
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WIND_TILE_HOR, edi
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WIND_TILE_VER, edi
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WIND_ARRANGE,  edi
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WIND_CLOSE,    edi
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WIND_CLOSEALL, edi

  xor edi, edi
  .if [xbx].$Obj(ClientWnd).dChildCount > 1                ;More child windows than 1?
    inc edi
  .endif
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WIND_PREV,     edi
  OCall [xsi].TbWindow::Toolbar.BtnEnable, IDM_WIND_NEXT,     edi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.ExtractResFile
; Purpose:    Extracts a resource file and saves it to the user temp folder.
; Arguments:  Arg1: Module instance handle where the resource is placed.
;             Arg2: -> Resource type.
;             Arg3: -> Resource name.
;             Arg4: -> Path and file name.
; Return:     eax = OBJ_OK on success, otherwise an error code.

Method ObjectBrowser.ExtractResFile, uses xsi, hInst:HANDLE, pResType:POINTER, \
                                               pResName:PSTRING, pFileName:PSTRING
  local hFindRes:HANDLE, hResData:HANDLE, hFile:HANDLE
  local pResData:POINTER, dResSize:DWORD, dBytesWritten:DWORD

  SetObject xsi
  invoke FindResource, hInst, pResName, pResType
  .if eax == 0
    invoke GetLastError
    OCall xsi.ErrorReport, NULL, eax
  .else
    mov hFindRes, xax
    invoke LoadResource, hInst, xax
    .if eax == 0
      invoke GetLastError
      OCall xsi.ErrorReport, NULL, eax
    .else
      mov hResData, xax
      invoke LockResource, xax
      .if eax == NULL
        invoke GetLastError
        OCall xsi.ErrorReport, NULL, eax
      .else
        mov pResData, xax
        invoke SizeofResource, hInst, hFindRes
        .if eax == 0
          invoke GetLastError
          OCall xsi.ErrorReport, NULL, eax
        .else
          mov dResSize, eax
          invoke CreateFile, pFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, \
                             CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
          .if xax == 0
            invoke GetLastError
            OCall xsi.ErrorReport, NULL, eax
          .else
            mov hFile, xax
            invoke WriteFile, hFile, pResData, dResSize, addr dBytesWritten, NULL
            .if eax == 0
              invoke GetLastError
              OCall xsi.ErrorReport, NULL, eax
            .endif
            invoke CloseHandle, hFile
          .endif
        .endif
      .endif
      invoke FreeResource, hResData
    .endif
  .endif
  mov eax, [xsi].dErrorCode
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.FindObjInfo
; Purpose:    Searches for an OBJECTINFORMATION with a matching object name.
; Arguments:  Arg1: -> Object name.
; Return:     xax -> OBJECTINFORMATION or NULL of not found.

Method ObjectBrowser.FindObjInfo, uses xsi, pName:PSTRING
  SetObject xsi
  mov xcx, [xsi].pObjDB
  .if $OCall([xcx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.Search, pName) != FALSE
    mov eax, ecx
    mov xcx, [xsi].pObjDB
    OCall [xcx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.ItemAt, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.FindIntInfo
; Purpose:    Searches for an INTERFACEINFORMATION with a matching interface name.
; Arguments:  Arg1: -> Interface name.
; Return:     xax -> INTERFACEINFORMATION or NULL of not found.

Method ObjectBrowser.FindIntInfo, uses xsi, pName:PSTRING
  SetObject xsi
  mov xcx, [xsi].pObjDB
  .if $OCall([xcx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.Search, pName) != FALSE
    mov eax, ecx
    mov xcx, [xsi].pObjDB
    OCall [xcx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.ItemAt, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.Init
; Purpose:    Initalizes the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method ObjectBrowser.Init, uses xbx xdi xsi
  local dWwd:DWORD, dWht:DWORD, dWtx:DWORD, dWty:DWORD
  local cBuffer[1024]:CHR, pSBHelp:POINTER

  SetObject xsi
  ACall xsi.Init

  ;Rebar + Statusbar + ListView + TabControl + ComboBoxEx
  invoke LoadCommonControls, ICC_COOL_CLASSES or ICC_BAR_CLASSES or \
                             ICC_LISTVIEW_CLASSES or ICC_TAB_CLASSES or ICC_USEREX_CLASSES

  ;Load settings from ini file
  lea xbx, cBuffer
  invoke GetCurrentDirectory, lengthof cBuffer, xbx
  lea xax, [xbx + sizeof(CHR)*xax]
  FillString [xax], <\OA_ObjectBrowser.ini>

  OCall [xsi].SetupFile::IniFile.Init, xsi, xbx

  OCall [xsi].SetupFile::IniFile.GetString, offset cSetup, offset cViewer, offset cDefViewer
  mov [xsi].pViewerApp, xax
  OCall [xsi].SetupFile::IniFile.GetDWord, offset cSetup, offset cLanguage, IDLANG_ENGLISH
  mov [xsi].dLanguage, eax
  OCall [xsi].SetupFile::IniFile.GetDWord, offset cSetup, offset cShowRedefMtds, BST_CHECKED
  mov [xsi].dShowRedefMtds, eax
  OCall [xsi].SetupFile::IniFile.GetDWord, offset cSetup, offset cShowRedefVars, BST_CHECKED
  mov [xsi].dShowRedefVars, eax

  ;Extract some files from the resource section to the user temp folder
  lea xdi, cBuffer
  invoke GetTempPath, lengthof cBuffer, xdi
  lea xbx, [xdi + xax]
  FillString [xbx], <Compile.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngCompile"), xdi
  FillString [xbx], <Edit.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngEdit"), xdi
  FillString [xbx], <Open.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngOpen"), xdi
  FillString [xbx], <Show.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngShow"), xdi
  FillString [xbx], <Hide.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngHide"), xdi
  FillString [xbx], <VarDat.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngVarDat"), xdi
  FillString [xbx], <VarObj.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngVarObj"), xdi
  FillString [xbx], <VarRDt.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngVarRDt"), xdi
  FillString [xbx], <IntMtd.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngIntMtd"), xdi
  FillString [xbx], <IntDsp.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngIntDsp"), xdi
  FillString [xbx], <Plus.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngPlus"), xdi
  FillString [xbx], <Minus.png>
  OCall xsi.ExtractResFile, hInstance, offset cPNG, $OfsCStr("PngMinus"), xdi

  ;Load application & menu icons from the resource section
  lea xbx, [xsi].IconList
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  OCall xbx::MaskedImageList.IconLoadResource, offset szIcoName                 ;00
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_REFRESH")    ;01
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SEARCH")     ;02
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SETUP")      ;03
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_EXIT")       ;04
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CASCADE")  ;05
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_HOR") ;06
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_TILE_VER") ;07
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_ARRANGE")  ;08
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_NEXT")     ;09
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_PREV")     ;10
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CLOSE")    ;11
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_WINDOW_CLOSEALL") ;12
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_HELP")       ;13
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")      ;14
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_COPY")            ;15
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_PRINT_PREVIEW")   ;16
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_PRINT")           ;17

  ;Load application accelerators from the resource section
  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("MDIACCEL"))

  ;Obtain handles for possible menus and submenus
  mov [xsi].hMenuInit, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUINIT"))

  mov [xsi].hMenuChild, $invoke(LoadMenu, hInstance, $OfsCStr("MDIMENUCHILD"))
  mov [xsi].hMenuChildWnd, $invoke(GetSubMenu, [xsi].hMenuChild, 2)

  mov [xsi].hMenuContext, $invoke(LoadMenu, hInstance, $OfsCStr("PROPCONTEXT"))

  ;Create the MDI Frame window
  mov dWwd, 2100
  mov dWht, 1000
  mov dWtx, $32($invoke(CenterForm, dWwd, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWty, $32($invoke(CenterForm, dWht, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
                         offset cObjectBrowserClass, offset szAppTitle, \
                         WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
                         dWtx, dWty, dWwd, dWht, 0, [xsi].hMenuInit, hInstance, xsi

  ;Initialize Client window
  mrm [xsi].pClientWnd, offset $ObjTmpl(ClientWnd), xdi ;Use the template
  OCall xdi::ClientWnd.Init, xsi
  mov xdi, [xdi].$Obj(ClientWnd).hWnd

  ;Initialize XMenu, xbx -> [xsi].IconList
  m2m pSBHelp, $MethodAddr(xsi::ObjectBrowser.StatusbarHelp), xax
  OCall [xsi].Menu::XMenu.Init, xsi, [xsi].hWnd, xdi, [xsi].hMenuChildWnd, xbx, \
                                pSBHelp, IDLANG_ENGLISH
  OCall [xsi].Menu::XMenu.Convert, [xsi].hMenuContext, FALSE
  OCall xsi.ChangeLanguage, [xsi].dLanguage

  OCall [xsi].FindInfDlg::FindInfoDlg.Init, xsi, [xsi].hWnd

  OCall xsi.EnableActions                               ;Disable toolbar buttons

  invoke ShowWindow, [xsi].hWnd, SW_SHOW
  invoke UpdateWindow, [xsi].hWnd

  m2m [xsi].pObjDB, offset $ObjTmpl(OA_ObjDB), xax
  OCall [xsi].pObjDB::OA_ObjDB.Init, xsi, addr [xsi].SetupFile

  OCall xsi.Refresh, REFRESH_ALL                        ;Load Object information from .stm file --> other thread
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.Navigate
; Purpose:    Navigates the InfoTree to the desired object.
; Arguments:  Arg1: -> Name.
;             Arg2: Type (INFO_TYPE_OBJECT or INFO_TYPE_INTERFACE).
; Return:     Nothing.

Method ObjectBrowser.Navigate, uses xbx xsi, pName:PSTRING, dType:DWORD
  SetObject xsi
  OCall [xsi].TreeWnd.Tree::InfoTree.FindNode, pName, dType
  .if xax != NULL
    mov xbx, xax
    OCall [xsi].TreeWnd.Tree::InfoTree.MoveInViewBottom, xbx
    OCall [xsi].TreeWnd.Tree::InfoTree.Select, xbx
    OCall [xsi].TreeWnd.Tree::InfoTree.Draw
    .if dType == INFO_TYPE_OBJECT
      mov eax, IDM_OPEN_OBJ_PROP_WND
    .else
      mov eax, IDM_OPEN_INT_PROP_WND
    .endif
    invoke SendMessage, [xsi].hWnd, WM_COMMAND, xax, [xbx].$Obj(InfoNode).pInfo
  .else
    .if dType == INFO_TYPE_OBJECT
      .if $OCall(xsi.FindObjInfo, pName) != NULL
        invoke SendMessage, [xsi].hWnd, WM_COMMAND, IDM_OPEN_OBJ_PROP_WND, xax
      .endif
    .else
      .if $OCall(xsi.FindIntInfo, pName) != NULL
        invoke SendMessage, [xsi].hWnd, WM_COMMAND, IDM_OPEN_INT_PROP_WND, xax
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.OnClose
; Purpose:    Event procedure for WM_CLOSE or WM_QUERYENDSESSION messages.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ObjectBrowser.OnClose, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local dMsg:DWORD

  ;DbgText "ObjectBrowser.OnClose"
  SetObject xsi
  mov dMsg, eax
  mov xbx, [xsi].pClientWnd
  .if [xbx].$Obj(ClientWnd).dChildCount == 0          ;Ask only if a child window is open
    invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(ClientWnd).hWnd, dMsg, wParam, lParam
  .else
    invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                       MB_YESNO + MB_ICONQUESTION
    .if eax == IDNO
      xor eax, eax
      ExitMethod
    .else
      invoke DefFrameProc, [xsi].hWnd, [xbx].$Obj(ClientWnd).hWnd, dMsg, wParam, lParam
    .endif
  .endif

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ChildSearch
; Purpose:    Used to locate a MDI child window using EnumChildWindows API.
; Arguments:  Arg1: Window handle.
;             Arg2: -> PROPERTIES_INFO.
; Return:     eax = TRUE to continue the enumeration, otherwise FALSE.

ChildSearch proc uses xbx hWnd:HANDLE, lParam:LPARAM
  local cBuffer[1024]:CHR

  mov xbx, lParam
  invoke SendMessage, hWnd, WM_GETTEXT, lengthof cBuffer, addr cBuffer
  .if $invoke(StrComp, addr cBuffer, [xbx].PROPERTIES_INFO.pCaption) == 0
    mov xdx, $invoke(SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0)
    mov xcx, [xdx].$Obj(ObjPropWnd).pInfo
    mov eax, TRUE
    .ifBitSet [xcx].INFORMATION.dFlags, INF_INTERFACE
      .if [xbx].PROPERTIES_INFO.dType == INFO_TYPE_INTERFACE
        mov [xbx].PROPERTIES_INFO.pChild, xdx
        xor eax, eax
      .endif
    .else
      .if [xbx].PROPERTIES_INFO.dType == INFO_TYPE_OBJECT
        mov [xbx].PROPERTIES_INFO.pChild, xdx
        xor eax, eax
      .endif
    .endif
  .else
    mov eax, TRUE                                       ;Continue enumeration
  .endif
  ret
ChildSearch endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ObjectBrowser.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local SetupDialog:$Obj(SetupDlg), AboutDialog:$Obj(DialogAbout)
  local cBuffer[MAX_PATH]:CHR, PTI:PROPERTIES_INFO

  SetObject xsi
  mov xax, wParam
  mov xbx, [xsi].pClientWnd

  .if ax == IDM_OPEN_INT_PROP_WND                       ;Create a child window
    mov xcx, lParam
    m2m PTI.pCaption, [xcx].INFORMATION.pName, xax
    mov PTI.pChild, NULL
    mov PTI.dType, INFO_TYPE_INTERFACE

    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset ChildSearch, addr PTI
    .if PTI.pChild == NULL
      New IntPropWnd
      OCall xax::IntPropWnd.Init, [xsi].pClientWnd, offset cIntPropClass, lParam
    .else
      mov xax, PTI.pChild
      invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIACTIVATE, [xax].$Obj(IntPropWnd).hWnd, 0
    .endif
    xor eax, eax

  .elseif ax == IDM_OPEN_OBJ_PROP_WND                   ;Create a child window
    mov xcx, lParam
    m2m PTI.pCaption, [xcx].INFORMATION.pName, xax
    mov PTI.pChild, NULL
    mov PTI.dType, INFO_TYPE_OBJECT

    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset ChildSearch, addr PTI
    .if PTI.pChild == NULL
      New ObjPropWnd
      OCall xax::ObjPropWnd.Init, [xsi].pClientWnd, offset cObjPropClass, lParam
    .else
      mov xax, PTI.pChild
      invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIACTIVATE, [xax].$Obj(ObjPropWnd).hWnd, 0
    .endif
    xor eax, eax

  .elseif ax == IDM_FILE_REFRESH
    OCall xsi.Refresh, REFRESH_ALL
    xor eax, eax

  .elseif ax == IDM_FILE_SEARCH
    invoke ShowWindow, [xsi].FindInfDlg.hWnd, SW_SHOW
    invoke BringWindowToTop, [xsi].FindInfDlg.hWnd
    xor eax, eax

  .elseif ax == IDM_FILE_SETUP
    New SetupDialog::SetupDlg
    OCall SetupDialog::SetupDlg.Init, xsi, [xsi].hWnd
    OCall SetupDialog::SetupDlg.Show
    OCall SetupDialog::SetupDlg.Done
    xor eax, eax

  .elseif ax == IDM_TREE_SHOW_OBJ
    xor [xsi].dShowObjects, TRUE
    OCall xsi.Refresh, REFRESH_TREE
    xor eax, eax

  .elseif ax == IDM_TREE_SHOW_INT
    xor [xsi].dShowInterfaces, TRUE
    OCall xsi.Refresh, REFRESH_TREE
    xor eax, eax

  .elseif ax == IDM_TREE_SHOW_PRJ
    xor [xsi].dShowAll, TRUE
    OCall xsi.Refresh, REFRESH_TREE
    xor eax, eax

  .elseif ax == IDM_TREE_SHOW_ERR
    xor [xsi].dShowBrokenOnly, TRUE
    OCall xsi.Refresh, REFRESH_TREE
    xor eax, eax

  .elseif ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0
    xor eax, eax

  .elseif ax == IDM_HELP_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm.pdf"), \
                                     addr cBuffer, lengthof cBuffer
    invoke PdfView, [xsi].hWnd, addr cBuffer, $OfsCStr("Introduction")
    xor eax, eax

  .elseif ax == IDM_HELP_ABOUT
    New AboutDialog::DialogAbout
    invoke LoadIcon, hInstance, offset szIcoName
    OCall AboutDialog::DialogAbout.Init, xsi, [xsi].hWnd, xax, offset szAboutText
    OCall AboutDialog::DialogAbout.Show
    OCall AboutDialog::DialogAbout.Done
    xor eax, eax

  .elseif (ax == IDM_WIND_CLOSE) || (ax == SC_CLOSE)    ;Close the active window
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_CLOSE, 0, 0
    xor eax, eax

  .elseif ax == SC_RESTORE                              ;Restore the active window
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIRESTORE, eax, 0
    xor eax, eax

  .elseif ax == SC_MINIMIZE                             ;Minimize the active window
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke ShowWindow, xax, SW_MINIMIZE
    xor eax, eax

  ;Messages for language selection
  .elseif (ax >= IDM_LANGUAGE_ENGLISH) && (ax <= IDM_LANGUAGE_SPANISH)
    ;Calculate IDLANG_XXX
    sub eax, IDM_LANGUAGE_ENGLISH
    mov ecx, LANGUAGE_STEP
    mul ecx
    OCall xsi.ChangeLanguage, eax
    xor eax, eax

  ;Messages for windows arrangement
  .elseif ax == IDM_WIND_TILE_HOR
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDITILE, MDITILE_HORIZONTAL, 0
    xor eax, eax
  .elseif ax == IDM_WIND_TILE_VER
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDITILE, MDITILE_VERTICAL, 0
    xor eax, eax
  .elseif ax == IDM_WIND_CASCADE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDICASCADE, 0, 0
    xor eax, eax
  .elseif ax == IDM_WIND_ARRANGE
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIICONARRANGE, 0, 0
    xor eax, eax
  .elseif ax == IDM_WIND_NEXT
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDINEXT, 0, 0
    xor eax, eax
  .elseif ax == IDM_WIND_PREV
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDINEXT, 0, -1
    xor eax, eax


  .elseif ax == IDM_WIND_CLOSEALL                   ;Attempt to close all windows
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset CloseEnumProc, [xbx].$Obj(ClientWnd).hWnd
    xor eax, eax

  .elseif ax == IDM_SELECTALL

  .elseif ax == IDM_COPY

  .elseif ax == IDM_PRINTPREVIEW

  .elseif ax == IDM_PRINT

  ;Pass to active child
  .else
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_COMMAND, wParam, lParam
  .endif

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ObjectBrowser.OnCreate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  ;Initialize tree window
  OCall [xsi].TreeWnd::TreeWindow.Init, xsi, [xsi].hWnd, addr [xsi].dLanguage

  ;Initialize vertical splitter
  OCall [xsi].SplitterVer::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_VERTICAL, 350, 50, 50

  ;Initialize statusbar
  OCall [xsi].SBar::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar

  ;Intialize rebar and toolbars
  OCall [xsi].RBar::Rebar.Init, xsi, [xsi].hWnd

  OCall [xsi].TbWindow::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarWindow, \
                                      addr [xsi].IconList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbWindow::Toolbar.GetHeight))
  OCall [xsi].TbWindow::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbWindow.hWnd, eax, ebx

  OCall [xsi].TbFile::Toolbar.Init, xsi, [xsi].hWnd, offset ToolbarFile, \
                                    addr [xsi].IconList, NULL, NULL
  mov ebx, $32($OCall([xsi].TbFile::Toolbar.GetHeight))
  OCall [xsi].TbFile::Toolbar.GetWidth
  OCall [xsi].RBar::Rebar.InsertBand, [xsi].TbFile.hWnd, eax, ebx

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ObjectBrowser.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if [xsi].hMenuInit
    invoke DestroyMenu, [xsi].hMenuInit
  .endif
  .if [xsi].hMenuChild
    invoke DestroyMenu, [xsi].hMenuChild
  .endif
  .if [xsi].hAccelerators
    invoke DestroyAcceleratorTable, [xsi].hAccelerators
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method ObjectBrowser.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, -1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ObjectBrowser.OnNotify, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cToolTipText[256]:CHR

  SetObject xsi
  mov xdi, lParam
  assume xdi: ptr TOOLTIPTEXT
  .if [xdi].hdr.code == TTN_NEEDTEXT
    mov edx, [xsi].dLanguage
    lea xbx, cToolTipText
    .if [xdi].hdr.idFrom == IDM_FILE_SETUP
      add edx, IDS_SETUP
    .elseif [xdi].hdr.idFrom == IDM_WIND_CASCADE
      add edx, IDS_WIND_CASCADE
    .elseif [xdi].hdr.idFrom == IDM_WIND_TILE_HOR
      add edx, IDS_WIND_TILE_HORZ
    .elseif [xdi].hdr.idFrom == IDM_WIND_TILE_VER
      add edx, IDS_WIND_TILE_VERT
    .elseif [xdi].hdr.idFrom == IDM_WIND_ARRANGE
      add edx, IDS_WIND_ARRANGE
    .elseif [xdi].hdr.idFrom == IDM_WIND_PREV
      add edx, IDS_WIND_PREV
    .elseif [xdi].hdr.idFrom == IDM_WIND_NEXT
      add edx, IDS_WIND_NEXT
    .elseif [xdi].hdr.idFrom == IDM_WIND_CLOSE
      add edx, IDS_WIND_CLOSE
    .elseif [xdi].hdr.idFrom == IDM_WIND_CLOSEALL
      add edx, IDS_WIND_CLOSE_ALL
    .endif
    invoke LoadString, hInstance, edx, xbx, lengthof cToolTipText
    mov [xdi].lpszText, xbx
  .endif
  assume xdi:nothing
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ObjectBrowser.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local dHeight:DWORD, dWidth:DWORD, dTop:DWORD
  local CtRect:RECT, SbRect:RECT, RbRect:RECT
  local TreeWndRect:RECT, SpVerRect:RECT

  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    ACall xsi.OnSize, wParam, lParam

    invoke GetClientRect, [xsi].hWnd, addr CtRect
    m2m dHeight, CtRect.bottom, eax
    m2m dWidth, CtRect.right, eax

    ;Place rebar
    invoke GetWindowRect, [xsi].RBar.hWnd, addr RbRect
    mov eax, RbRect.bottom
    sub eax, RbRect.top
    mov dTop, eax
    invoke MoveWindow, [xsi].RBar.hWnd, 0, 0, dWidth, eax, FALSE

    ;Place statusbar
    invoke GetWindowRect, [xsi].SBar.hWnd, addr SbRect
    mov eax, SbRect.bottom
    sub eax, SbRect.top
    sub dHeight, eax
    invoke MoveWindow, [xsi].SBar.hWnd, 0, dHeight, dWidth, eax, FALSE
    mov ecx, dTop
    sub dHeight, ecx

    ;Place vertical splitter
    invoke GetWindowRect, [xsi].SplitterVer.hWnd, addr SpVerRect
    invoke ScreenToClient, [xsi].hWnd, addr SpVerRect.left
    invoke ScreenToClient, [xsi].hWnd, addr SpVerRect.right
    mov eax, SpVerRect.right
    sub eax, SpVerRect.left
    invoke MoveWindow, [xsi].SplitterVer.hWnd, SpVerRect.left, dTop, eax, dHeight, FALSE

    ;Place project window
    invoke GetWindowRect, [xsi].TreeWnd.hWnd, addr TreeWndRect
    invoke ScreenToClient, [xsi].hWnd, addr TreeWndRect.left
    invoke ScreenToClient, [xsi].hWnd, addr TreeWndRect.right
    invoke MoveWindow, [xsi].TreeWnd.hWnd, 0, dTop, SpVerRect.left, dHeight, FALSE

    ;Place client window
    mov xcx, [xsi].pClientWnd
    .if xcx != NULL
      mov eax, CtRect.right
      sub eax, SpVerRect.right
      invoke MoveWindow, [xcx].$Obj(ClientWnd).hWnd, SpVerRect.right, dTop, eax, dHeight, FALSE
    .endif

    ;Redraw all child windows
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                         RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN

    xor eax, eax                                        ;Return zero
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CloseEnumProc (Callback)
; Purpose:    Close all open child windows using the EnumChildWindows API.
; Arguments:  Arg1: Child window handle.
;             Arg2: Parameter passed to the enumeration procedure.
; Return:     eax = Exit code passed to PostQuitMessage.

CloseEnumProc proc hWnd:HANDLE, lParam:LPARAM
  invoke GetParent, hWnd
  .if xax == lParam
    invoke SendMessage, hWnd, WM_CLOSE, 0, 0
  .endif
  mov eax, TRUE                                         ;TRUE => next window
  ret
CloseEnumProc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ResetInfoFlags
; Purpose:    Resets the info flags INF_INVALID + INF_INTREE in a INFORMATION structure.
; Arguments:  Arg1: -> INFORMATION.
;             Arg2: Dummy.
;             Arg3: Dummy.
; Return:     Nothing.

ResetInfoFlags proc pInfo:PINFORMATION, xDummy1:XWORD, xDummy2:XWORD
  mov xcx, pInfo
  BitClr [xcx].INFORMATION.dFlags, (INF_INVALID or INF_INTREE)
  ret
ResetInfoFlags endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  AddObjectBranch
; Purpose:    Auxiliary procedure used by ObjectBrowser.Refresh.
; Arguments:  Arg1: -> OBJECTINFORMATION.
;             Arg2: -> Ancestor InfoNode.
;             Arg3: -> ObjectBrowser.
; Return:     Nothing.

AddObjectBranch proc uses xbx xdi xsi, pInfo:POBJECTINFORMATION, pAncestorNode:$ObjPtr(InfoNode), pSelf:$ObjPtr(ObjectBrowser)
  SetObject xsi, ObjectBrowser, pSelf
  mov xax, pInfo
  .ifBitClr [xax].OBJECTINFORMATION.dFlags, INF_INTREE
    mov xcx, pAncestorNode
    .if xcx == NULL
      .if [xax].OBJECTINFORMATION.pAncestorName != NULL
        ret
      .endif
    .else
      mov xax, [xax].OBJECTINFORMATION.pAncestorName
      .if xax == NULL
        ret
      .endif
      mov xdx, [xcx].$Obj(InfoNode).pInfo
      invoke StrCompA, xax, [xdx].OBJECTINFORMATION.pName
      .if eax != 0
        ret
      .endif
    .endif

    lea xbx, [xsi].TreeWnd.Tree
    mov xdi, $New(InfoNode)
    OCall xdi::InfoNode.Init, xbx, NODE_WIDTH, NODE_HEIGHT, XTVNS_EXPANDED
    mrm [xdi].$Obj(InfoNode).pInfo, pInfo, xcx
    BitSet [xcx].OBJECTINFORMATION.dFlags, INF_INTREE
    OCall xbx::InfoTree.Insert, xdi, pAncestorNode, XTVN_INSERT_AS_LAST_CHILD
    mov xcx, [xsi].pObjDB
    OCall [xcx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.ForEach, addr AddObjectBranch, xdi, xsi
  .endif
  ret
AddObjectBranch endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  AddBrokenObjects
; Purpose:    Auxiliary procedure used by ObjectBrowser.Refresh.
; Arguments:  Arg1: -> OBJECTINFORMATION.
;             Arg2: -> ObjectBrowser.
;             Arg3: Dummy.
; Return:     Nothing.

AddBrokenObjects proc uses xbx xdi xsi pInfo:POBJECTINFORMATION, pSelf:$ObjPtr(ObjectBrowser), xDummy:XWORD
  SetObject xsi, ObjectBrowser, pSelf
  mov xax, pInfo
  .ifBitClr [xax].OBJECTINFORMATION.dFlags, INF_INTREE
    mov xdx, [xax].OBJECTINFORMATION.pAncestorName
    .if xdx != NULL
      OCall xsi.FindObjInfo, xdx
      .if xax == NULL
        lea xbx, [xsi].TreeWnd.Tree
        mov xdi, $New(InfoNode)
        OCall xdi::InfoNode.Init, xbx, NODE_WIDTH, NODE_HEIGHT, XTVNS_EXPANDED
        mrm [xdi].$Obj(InfoNode).pInfo, pInfo, xcx
        BitSet [xcx].OBJECTINFORMATION.dFlags, INF_INVALID
        OCall xbx::InfoTree.Insert, xdi, NULL, XTVN_INSERT_AS_LAST_CHILD
        mov xcx, [xsi].pObjDB
        OCall [xcx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.ForEach, addr AddObjectBranch, xdi, xsi
      .endif
    .endif
  .endif
  ret
AddBrokenObjects endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  AddInterfaceBranch
; Purpose:    Auxiliary procedure used by ObjectBrowser.Refresh.
; Arguments:  Arg1: -> INTERFACEINFORMATION.
;             Arg2: -> Ancestor InfoNode.
;             Arg3: -> ObjectBrowser.
; Return:     Nothing.

AddInterfaceBranch proc uses xbx xdi xsi, pInfo:PINTERFACEINFORMATION, pAncestorNode:$ObjPtr(InfoNode), pSelf:$ObjPtr(ObjectBrowser)
  SetObject xsi, ObjectBrowser, pSelf
  mov xax, pInfo
  .ifBitClr [xax].INTERFACEINFORMATION.dFlags, INF_INTREE
    mov xcx, pAncestorNode
    .if xcx == NULL
      .if [xax].INTERFACEINFORMATION.pAncestorName != NULL
        ret
      .endif
    .else
      mov xax, [xax].INTERFACEINFORMATION.pAncestorName
      .if xax == NULL
        ret
      .endif
      mov xdx, [xcx].$Obj(InfoNode).pInfo
      invoke StrCompA, xax, [xdx].INTERFACEINFORMATION.pName
      .if eax != 0
        ret
      .endif
    .endif

    lea xbx, [xsi].TreeWnd.Tree
    mov xdi, $New(InfoNode)
    OCall xdi::InfoNode.Init, xbx, NODE_WIDTH, NODE_HEIGHT, XTVNS_EXPANDED
    mrm [xdi].$Obj(InfoNode).pInfo, pInfo, xcx
    BitSet [xcx].INTERFACEINFORMATION.dFlags, INF_INTREE
    OCall xbx::InfoTree.Insert, xdi, pAncestorNode, XTVN_INSERT_AS_LAST_CHILD
    mov xcx, [xsi].pObjDB
    OCall [xcx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.ForEach, addr AddInterfaceBranch, xdi, xsi
  .endif
  ret
AddInterfaceBranch endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  AddInterfaceBranch
; Purpose:    Auxiliary procedure used by ObjectBrowser.Refresh.
; Arguments:  Arg1: -> INTERFACEINFORMATION.
;             Arg2: -> ObjectBrowser.
;             Arg3: Dummy.
; Return:     Nothing.

AddBrokenInterfaces proc uses xbx xdi xsi pInfo:PINTERFACEINFORMATION, pSelf:$ObjPtr(ObjectBrowser), xDummy:XWORD
  SetObject xsi, ObjectBrowser, pSelf
  mov xax, pInfo
  .ifBitClr [xax].INTERFACEINFORMATION.dFlags, INF_INTREE
    mov xdx, [xax].INTERFACEINFORMATION.pAncestorName
    .if xdx != NULL
      OCall xsi.FindIntInfo, xdx
      .if xax == NULL
        lea xbx, [xsi].TreeWnd.Tree
        mov xdi, $New(InfoNode)
        OCall xdi::InfoNode.Init, xbx, NODE_WIDTH, NODE_HEIGHT, XTVNS_EXPANDED
        mrm [xdi].$Obj(InfoNode).pInfo, pInfo, xcx
        BitSet [xcx].INTERFACEINFORMATION.dFlags, INF_INVALID
        OCall xbx::InfoTree.Insert, xdi, NULL, XTVN_INSERT_AS_LAST_CHILD
        mov xcx, [xsi].pObjDB
        OCall [xcx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.ForEach, addr AddInterfaceBranch, xdi, xsi
      .endif
    .endif
  .endif
  ret
AddBrokenInterfaces endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RefreshMdiChild
; Purpose:    Used to refresh a MDI child window using EnumChildWindows API.
; Arguments:  Arg1: Window handle.
;             Arg2: (lParam) ClientWnd.hWnd
; Return:     eax = TRUE to continue the enumeration, otherwise FALSE.

RefreshMdiChild proc uses xbx hWnd:HANDLE, lParam:LPARAM
  invoke GetParent, hWnd
  .if xax == lParam
    invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke GetObjectID, xbx
      mov xcx, [xbx].$Obj(PropWnd).pOwner                     ;xcx -> ClientWnd
      .if eax == ObjPropWndID
        OCall [xcx].$Obj(ClientWnd).pOwner::ObjectBrowser.FindObjInfo, [xbx].$Obj(PropWnd).pName
      .elseif eax == IntPropWndID
        OCall [xcx].$Obj(ClientWnd).pOwner::ObjectBrowser.FindIntInfo, [xbx].$Obj(PropWnd).pName
      .else
        mov eax, TRUE                                   ;TRUE => next window
        ret
      .endif
      .if xax == NULL
        ;We can not find a match => close the window
        invoke SendMessage, hWnd, WM_CLOSE, 0, 0
      .else
        mov [xbx].$Obj(PropWnd).pInfo, xax
        OCall xbx::PropWnd.Gather
;        OCall xbx::PropWnd.EmitHtml
;        ICall [xbx].$Obj(PropWnd).pIWebBrowser2::IWebBrowser2.Refresh
      .endif
    .endif
  .endif
  mov eax, TRUE                                       ;Continue enumeration
  ret
RefreshMdiChild endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.Refresh
; Purpose:    Reloads the object information stream.
; Arguments:  Arg1: Refresh flags [REFRESH_TREE, REFRESH_CHILDREN, REFRESH_ALL]
; Return:     Nothing.

Method ObjectBrowser.Refresh, uses xbx xsi, dFlags:DWORD
  SetObject xsi

  .ifBitSet dFlags, REFRESH_TREE
    ;Remove all information from tree
    OCall [xsi].TreeWnd.Tree::InfoTree.Reset

    mov xbx, [xsi].pObjDB
    ;Load data from .stm file
    OCall [xbx].$Obj(OA_ObjDB)::OA_ObjDB.ScanDBFiles

    ;Build the tree
    ;Reset flags
    OCall [xbx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.ForEach, addr ResetInfoFlags, NULL, NULL
    OCall [xbx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.ForEach, addr ResetInfoFlags, NULL, NULL

    ;Add Objects
    .if [xsi].dShowObjects != FALSE
      .if [xsi].dShowBrokenOnly == FALSE
        OCall [xbx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.ForEach, addr AddObjectBranch, NULL, xsi
      .endif
      OCall [xbx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.ForEach, addr AddBrokenObjects, xsi, NULL
    .endif

    ;Add Interfaces
    .if [xsi].dShowInterfaces != FALSE
      .if [xsi].dShowBrokenOnly == FALSE
        OCall [xbx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.ForEach, addr AddInterfaceBranch, NULL, xsi
      .endif
      OCall [xbx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.ForEach, addr AddBrokenInterfaces, xsi, NULL
    .endif

    ;Tree decimation for non project objects
    .if [xsi].dShowAll == FALSE
      .repeat
        lea xdx, [xsi].TreeWnd.Tree
        OCall xsi.TreeDecimate, [xdx].$Obj(InfoTree).pFirstChild
      .until eax == FALSE
    .endif

    ;Draw the tree
    OCall [xsi].TreeWnd.Tree::InfoTree.Draw
  .endif

  .ifBitSet dFlags, REFRESH_CHILDREN
    ;Now refresh the MDI Childs
    mov xdx, [xsi].pClientWnd
    mov xcx, [xdx].$Obj(ClientWnd).hWnd
    invoke EnumChildWindows, xcx, offset RefreshMdiChild, xcx
  .endif

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.TreeDecimate
; Purpose:    Walk the tree leaves and remove them if they dont belong to the project.
; Arguments:  Arg1: -> InfoNode.
; Return:     eax = TRUE if something was removed, otherwise FALSE.

Method ObjectBrowser.TreeDecimate, uses xbx xdi xsi, pNode:$ObjPtr(InfoNode)
  SetObject xsi
  xor edi, edi                                        ;edi = HasChanged flag
  mov xbx, pNode
  .if xbx != NULL
    .if [xbx].$Obj(InfoNode).pNextSibling != NULL
      OCall xsi.TreeDecimate, [xbx].$Obj(InfoNode).pNextSibling
      or edi, eax
    .endif
    .if [xbx].$Obj(InfoNode).pFirstChild != NULL
      OCall xsi.TreeDecimate, [xbx].$Obj(InfoNode).pFirstChild
      or edi, eax
    .else
      mov xcx, [xbx].$Obj(InfoNode).pInfo
      .ifBitClr [xcx].INFORMATION.dFlags, INF_PRJ
        ;Remove the node
        OCall [xsi].TreeWnd.Tree::InfoTree.Dispose, xbx
        mov edi, TRUE
      .endif
    .endif
  .endif
  mov eax, edi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.Startup
; Purpose:    Registers the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ObjectBrowser.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(ObjectBrowser.WndProc), xdx
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, NULL
  mov WC.lpszMenuName, NULL
  m2m WC.lpszClassName, offset cObjectBrowserClass, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, offset szIcoName)
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)
  mov WC.hIconSm, 0

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ObjectBrowser.StatusbarHelp
; Purpose:    Displays a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> Help string.
; Return:     Nothing.

Method ObjectBrowser.StatusbarHelp,, pHelpStr:PSTRING
  SetObject xcx
  OCall [xcx].SBar::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd

;##/

; ==================================================================================================
;    ClientWnd implementation
; ==================================================================================================

;##\

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ClientWnd.Done
; Purpose:    Finalizes the ClientWnd object.
; Arguments:  None.
; Return:     Nothing.

Method ClientWnd.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBGBrush
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ClientWnd.Init
; Purpose:    Initalizes the MdiClientWnd object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method ClientWnd.Init, uses xsi, pOwner:POINTER
  local hBmp:HBITMAP

  SetObject xsi
  ACall xsi.Init, pOwner
  mov hBmp, $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND"))
  mov [xsi].hBGBrush, $invoke(CreatePatternBrush, hBmp)
  invoke DeleteObject, hBmp
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ClientWnd.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method ClientWnd.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, -1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ClientWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ClientWnd.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rct:RECT

  ;DbgText "ClientWnd.OnPaint"
  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke FillRect, PS.hdc, addr Rct, [xsi].hBGBrush
  invoke EndPaint, [xsi].hWnd, addr PS
  invoke CallWindowProc, [xsi].$Obj(ClientWnd).pPrevWndProc, \
                         [xsi].$Obj(ClientWnd).hWnd, WM_PAINT, wParam, lParam
MethodEnd

;##/

endif