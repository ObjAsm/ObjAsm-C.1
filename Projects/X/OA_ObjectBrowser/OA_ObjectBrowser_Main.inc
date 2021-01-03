; ==================================================================================================
; Title:      OA_ObjectBrowser_Main.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Object Browser.
; Notes:      Version C.1.0, December 2020
;               - First release.
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

WM_BROWSERTITLECHANGE       equ   WM_APP
WM_BROWSERDOCUMENTCOMPLETE  equ   WM_APP + 1
WM_BROWSERSTATUSTEXTCHANGE  equ   WM_APP + 2

;Window Events - Only valid in body and frameset elements.
DISPID_ONLOAD               equ   06A3185BCh             ;Runs when a document loads (random number)
DISPID_ONUNLOAD             equ   DISPID_ONLOAD + 1      ;Runs when a document unloads

;Form Element Events - Only valid in form elements.
DISPID_ONCHANGE             equ   DISPID_ONUNLOAD + 1    ;Runs when the element changes
DISPID_ONSUBMIT             equ   DISPID_ONCHANGE + 1    ;Runs when the form is submitted
DISPID_ONRESET              equ   DISPID_ONSUBMIT + 1    ;Runs when the form is reset
DISPID_ONSELECT             equ   DISPID_ONRESET + 1     ;Runs when the element is selected
DISPID_ONBLUR               equ   DISPID_ONSELECT + 1    ;Runs when the element loses focus
DISPID_ONFOCUS              equ   DISPID_ONBLUR + 1      ;Runs when the element gets focus

;Keyboard Events - Not valid in base, bdo, br, frame, frameset, head, html, iframe, meta, param,
;                  script, style, and title elements.
DISPID_ONKEYDOWN            equ   DISPID_ONFOCUS + 1     ;Runs when key is pressed
DISPID_ONKEYPRESS           equ   DISPID_ONKEYDOWN + 1   ;Runs when key is pressed and released
DISPID_ONKEYUP              equ   DISPID_ONKEYPRESS + 1  ;Runs when key is released


;Mouse Events - Not valid in base, bdo, br, frame, frameset, head, html, iframe, meta, param,
;               script, style, title elements.
DISPID_ONCLICK              equ   DISPID_ONKEYUP + 1     ;Runs on a mouse click
DISPID_ONDBLCLICK           equ   DISPID_ONCLICK + 1     ;Runs on a mouse double-click
DISPID_ONMOUSEDOWN          equ   DISPID_ONDBLCLICK + 1  ;Runs when mouse button is pressed
DISPID_ONMOUSEMOVE          equ   DISPID_ONMOUSEDOWN + 1 ;Runs when mouse pointer moves
DISPID_ONMOUSEOUT           equ   DISPID_ONMOUSEMOVE + 1 ;Runs when mouse moves out of an element
DISPID_ONMOUSEOVER          equ   DISPID_ONMOUSEOUT + 1  ;Runs when mouse moves over an element
DISPID_ONMOUSEUP            equ   DISPID_ONMOUSEOVER + 1 ;Runs when mouse button is released

DISPID_STATUSTEXTCHANGE           equ  0066h
DISPID_PROGRESSCHANGE             equ  006Ch
DISPID_COMMANDSTATECHANGE         equ  0069h
DISPID_DOWNLOADBEGIN              equ  006Ah
DISPID_DOWNLOADCOMPLETE           equ  0068h
DISPID_TITLECHANGE                equ  0071h
DISPID_PROPERTYCHANGE             equ  0070h
DISPID_BEFORENAVIGATE2            equ  00FAh
DISPID_NEWWINDOW2                 equ  00FBh
DISPID_NAVIGATECOMPLETE2          equ  00FCh
DISPID_DOCUMENTCOMPLETE           equ  0103h
DISPID_ONQUIT                     equ  00FDh
DISPID_ONVISIBLE                  equ  00FEh
DISPID_ONTOOLBAR                  equ  00FFh
DISPID_ONMENUBAR                  equ  0100h
DISPID_ONSTATUSBAR                equ  0101h
DISPID_ONFULLSCREEN               equ  0102h
DISPID_ONTHEATERMODE              equ  0104h
DISPID_WINDOWSETRESIZABLE         equ  0106h
DISPID_WINDOWSETLEFT              equ  0108h
DISPID_WINDOWSETTOP               equ  0109h
DISPID_WINDOWSETWIDTH             equ  010Ah
DISPID_WINDOWSETHEIGHT            equ  010Bh
DISPID_WINDOWCLOSING              equ  0107h
DISPID_CLIENTTOHOSTWINDOW         equ  010Ch
DISPID_SETSECURELOCKICON          equ  010Dh
DISPID_FILEDOWNLOAD               equ  010Eh
DISPID_NAVIGATEERROR              equ  010Fh
DISPID_PRINTTEMPLATEINSTANTIATION equ  00E1h
DISPID_PRINTTEMPLATETEARDOWN      equ  00E2h
DISPID_UPDATEPAGESTATUS           equ  00E3h
DISPID_PRIVACYIMPACTEDSTATECHANGE equ  0110h
DISPID_NEWWINDOW3                 equ  0111h
DISPID_SETPHISHINGFILTERSTATUS    equ  011Ah
DISPID_WINDOWSTATECHANGED         equ  011Bh


Object ICustomDocHostUIHandler,, IDocHostUIHandler
  RedefineMethod    ShowContextMenu,      DWORD, POINTER, POINTER, POINTER
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object IWebBrowserEvents2,, IDispatch
  RedefineMethod    Invoke,             DWORD, REFIID, DWORD, word, LPDISPPARAMS, LPVARIANT, \
                                        POINTER, POINTER
  IDispEvent        BeforeNavigate2,    DISPID_BEFORENAVIGATE2, DISPATCH_METHOD

  InterfaceMethod   BeforeNavigate2,    LPDISPPARAMS, LPVARIANT

  RedefineVariable  pIID,               offset IID_DWebBrowserEvents2
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object ICustomSiteDispatch,, I_OcxCont_SiteDispatch
  RedefineMethod    Init,               POINTER
  RedefineMethod    GetIDsOfNames,      POINTER, POINTER, DWORD, DWORD, POINTER

  IDispEvent        OnClick,            DISPID_ONCLICK, DISPATCH_METHOD or DISPATCH_PROPERTYGET

  InterfaceMethod   OnClick,            LPDISPPARAMS, LPVARIANT

  DefineVariable    cExplorerApp,       CHR,        MAX_PATH dup(0)
ObjectEnd

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
  StaticMethod      SetOcxPosition,     PRECT

  VirtualEvent      OnClose,            WM_CLOSE
  VirtualEvent      OnSize,             WM_SIZE

  DefineVariable    pInfo,              PINFORMATION, NULL
  DefineVariable    pName,              PSTRING,    NULL
  DefineVariable    pFileName,          PSTRING,    NULL
  DefineVariable    hHtmlFile,          HANDLE,     0

  DefineVariable    pOcxContainer,      $ObjPtr(OcxContainer),  NULL
  DefineVariable    pOcxClientSite,     $ObjPtr(OcxClientSite), NULL
  DefineVariable    pIWebBrowser2,      POINTER,    NULL
  DefineVariable    pICP_WB,            POINTER,    NULL
  DefineVariable    dCookie_WB,         DWORD,      0
  DefineVariable    pIWebBrowserEvents2,POINTER,    NULL
  DefineVariable    dInitialized,       DWORD,      FALSE
  DefineVariable    dShowRedefMtds,     DWORD,      TRUE
  DefineVariable    dShowRedefVars,     DWORD,      TRUE
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CStr cIntPropClass, "IntPropWndClass"

Object IntPropWnd, IntPropWndID, PropWnd
  RedefineMethod    Init,               $ObjPtr(ClientWnd), PSTRING, PINTERFACEINFORMATION
  RedefineMethod    EmitHtml
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
  RedefineMethod    EmitHtml
  RedefineMethod    Gather
  StaticMethod      GatherMethods,      POBJECTINFORMATION
  StaticMethod      GatherVariables,    POBJECTINFORMATION
  StaticMethod      ShowInheritance,    POBJECTINFORMATION, DWORD
  StaticMethod      Startup

  Embed     Methods,     DataCollection       ;Collection of MEMBERDATA structures
  Embed     Variables,   DataCollection       ;Collection of MEMBERDATA structures

ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object FindInfoDlg,, Dialog
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, HANDLE
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnActivate,         WM_ACTIVATE

  DefineVariable    hSearch,            HANDLE,     0
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
  VirtualMethod     StatusbarHelp,      PSTRING           ;-> Help string

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
  DefineVariable    pIOleCommandTarget, POINTER,    NULL    ;-> IOleCommandTarget

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
  pDefinition   POINTER       ?
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

ICustomSiteDispatchTable \
  POINTER $OfsTStrW("OnLoad"),      DISPID_ONLOAD
  POINTER $OfsTStrW("OnUnload"),    DISPID_ONUNLOAD
  POINTER $OfsTStrW("OnChange"),    DISPID_ONCHANGE
  POINTER $OfsTStrW("OnSubmit"),    DISPID_ONSUBMIT
  POINTER $OfsTStrW("OnReset"),     DISPID_ONRESET
  POINTER $OfsTStrW("OnSelect"),    DISPID_ONSELECT
  POINTER $OfsTStrW("OnBlur"),      DISPID_ONBLUR
  POINTER $OfsTStrW("OnFocus"),     DISPID_ONFOCUS
  POINTER $OfsTStrW("OnKeydown"),   DISPID_ONKEYDOWN
  POINTER $OfsTStrW("OnKeypress"),  DISPID_ONKEYPRESS
  POINTER $OfsTStrW("OnKeyup"),     DISPID_ONKEYUP
  POINTER $OfsTStrW("OnClick"),     DISPID_ONCLICK
  POINTER $OfsTStrW("OnDblclick"),  DISPID_ONDBLCLICK
  POINTER $OfsTStrW("OnMousedown"), DISPID_ONMOUSEDOWN
  POINTER $OfsTStrW("OnMousemove"), DISPID_ONMOUSEMOVE
  POINTER $OfsTStrW("OnMouseout"),  DISPID_ONMOUSEOUT
  POINTER $OfsTStrW("OnMouseover"), DISPID_ONMOUSEOVER
  POINTER $OfsTStrW("OnMouseup"),   DISPID_ONMOUSEUP
ICustomSiteDispatchTableCount equ ($ - ICustomSiteDispatchTable)/(2*sizeof(POINTER))

SOM_TEXT_TABLE \
  POINTER $OfsTStr("Unknown type")
  POINTER $OfsTStr("Static")
  POINTER $OfsTStr("Virtual")
  POINTER $OfsTStr("Virtual")             ;Abstract
  POINTER $OfsTStr("Virtual Event")       ;Event
  POINTER $OfsTStr("Dynamic")
  POINTER $OfsTStr("Dynamic")             ;Abstract
  POINTER $OfsTStr("Dynamic Event")       ;Event
  POINTER $OfsTStr("Interface")
  POINTER $OfsTStr("Inline")
  POINTER $OfsTStr("Redefined")
  POINTER $OfsTStr("Standard")
  POINTER $OfsTStr("Dispatch")


.code

; ==================================================================================================
;    ICustomDocHostUIHandler implementation
; ==================================================================================================

;##\

OLECMD struc
  cmdID   DWORD   ?
  cmdf    DWORD   ?
OLECMD ends

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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    ICustomDocHostUIHandler.ShowContextMenu
; Purpose:   Enables MSHTML to display a shortcut menu.
; Arguments: Arg1: [in] A DWORD that specifies the identifier of the shortcut menu to be displayed.
;            Arg2: [in] -> POINT structure containing the screen coordinates for the menu.
;            Arg3: [in] -> IUnknown of an IOleCommandTarget interface used to query command status
;                  and execute commands on this object.
;            Arg4: [in] -> IDispatch interface of the object at the screen coordinates specified in
;                  ppt. This enables a host to pass particular objects, such as anchor tags and
;                  images, to provide more specific context.
; Return:    eax = HRESULT.
;            S_OK: Host displays its UI. MSHTML will not attempt to display its UI.
;            S_FALSE: Host did not display its UI. MSHTML will display its UI.
;            DOCHOST_E_UNKNOWN: Menu identifier is unknown. MSHTML might attempt an alternative
;                               identifier from a previous version
;
;http://msdn.microsoft.com/en-us/library/aa770042(v=vs.85).aspx
;http://msdn.microsoft.com/en-us/library/aa752041(v=VS.85).aspx
;
;Hint:       CommandStateChange

Method ICustomDocHostUIHandler.ShowContextMenu, uses xbx xdi, dwID:DWORD, pPoint:POINTER, \
                                              pcmdtReserved:POINTER, pdispReserved:POINTER
  local QueryCmds[4]:OLECMD

  DbgText "ICustomDocHostUIHandler.ShowContextMenu", "ICustomDocHostUIHandler"
  DbgDec dwID,, "ICustomDocHostUIHandler"
  .if dwID == CONTEXT_MENU_TEXTSELECT || dwID == CONTEXT_MENU_DEFAULT || \
      dwID == CONTEXT_MENU_CONTROL || dwID == CONTEXT_MENU_ANCHOR || \
      dwID == CONTEXT_MENU_IMAGE
    mov xcx, pSelf
    mov xdx, [xcx].$Obj(ICustomDocHostUIHandler).pOwner       ;xdx -> OcxClientSite
    mov xcx, [xdx].$Obj(OcxClientSite).pOwner                 ;xcx -> OcxContainer
    mov xdx, [xcx].$Obj(OcxContainer).pOwner                  ;xdx -> PropWnd
    mov xcx, [xdx].$Obj(PropWnd).pOwner                       ;xcx -> ClientWnd
    mov xbx, [xcx].$Obj(ClientWnd).pOwner                     ;xbx -> ObjectBrowser
    assume xbx:$ObjPtr(ObjectBrowser)
    mov xdi, $invoke(GetSubMenu, [xbx].hMenuContext, 0)

    mov QueryCmds[0*sizeof(OLECMD)].OLECMD.cmdID, OLECMDID_SELECTALL
    m2z QueryCmds[0*sizeof(OLECMD)].OLECMD.cmdf
    mov QueryCmds[1*sizeof(OLECMD)].OLECMD.cmdID, OLECMDID_COPY
    m2z QueryCmds[1*sizeof(OLECMD)].OLECMD.cmdf
    mov QueryCmds[2*sizeof(OLECMD)].OLECMD.cmdID, OLECMDID_PRINT
    m2z QueryCmds[2*sizeof(OLECMD)].OLECMD.cmdf
    mov QueryCmds[3*sizeof(OLECMD)].OLECMD.cmdID, OLECMDID_PRINTPREVIEW
    m2z QueryCmds[3*sizeof(OLECMD)].OLECMD.cmdf
    ICall pcmdtReserved::IUnknown.QueryInterface, offset IID_IOleCommandTarget, \
                                                  addr [xbx].pIOleCommandTarget
    ICall [xbx].pIOleCommandTarget::IOleCommandTarget.QueryStatus, NULL, lengthof QueryCmds, \
                                                                   addr QueryCmds, NULL
    EnableContextMenuItem IDM_SELECTALL, 0
    EnableContextMenuItem IDM_COPY, 1
    EnableContextMenuItem IDM_PRINT, 2
    EnableContextMenuItem IDM_PRINTPREVIEW, 3

    mov xax, pPoint
    invoke TrackPopupMenu, xdi, 0, [xax].POINT.x, [xax].POINT.y, 0, [xbx].hWnd, NULL
    mov eax, S_OK
    assume xbx:nothing

  .elseif dwID == CONTEXT_MENU_HSCROLL || dwID == CONTEXT_MENU_VSCROLL
    mov eax, S_FALSE
  .else
    mov eax, S_OK
  .endif
MethodEnd

;##/

; ==================================================================================================
;    IWebBrowserEvents2 implementation
; ==================================================================================================

;##\

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IWebBrowserEvents2.Invoke
; Purpose:    Provide access to properties and methods exposed by an object.
; Arguments:  Arg1: Method Member ID.
;             Arg2: -> IID_NULL
;             Arg3: Locale context in which to interpret the names.
;             Arg4: Flags.
;               DISPATCH_METHOD: The member is invoked as a method. If a property has the same name,
;                                both this and the DISPATCH_PROPERTYGET flag may be set.
;               DISPATCH_PROPERTYGET: The member is retrieved as a property or data member.
;               DISPATCH_PROPERTYPUT: The member is changed as a property or data member.
;               DISPATCH_PROPERTYPUTREF: The member is changed by a reference assignment, rather than
;                                a value assignment. This flag is valid only when the
;                                property accepts a reference to an object.
;             Arg5: -> Array of arguments DispParams.
;             Arg6: -> Result VARIANT.
;             Arg7: -> Exception Info.
;             Arg8: -> Index of the argument that produces the error.
; Return:     eax = HRESULT.
; Note:       Static methods can NOT be redirected to another interface!

Method IWebBrowserEvents2.Invoke, uses xbx xsi, dMethodID:DWORD, pIID:REFIID, dLCID:DWORD, \
                                         wFlags:word, pParams:LPDISPPARAMS, pResult:LPVARIANT, \
                                         pExcepInfo:POINTER, pArgErrIdx:POINTER
;    DbgText "IWebBrowserEvents2.Invoke", "IWebBrowserEvents2_SiteDispatch"

.const
@@IWebBrowserEvents2_SiteDispatch_JumpTable \
  POINTER offset @@IWebBrowserEvents2_SiteDispatch_Static
  POINTER offset @@IWebBrowserEvents2_SiteDispatch_VirtualInterface
  POINTER offset @@IWebBrowserEvents2_SiteDispatch_VirtualInterface
  POINTER offset @@IWebBrowserEvents2_SiteDispatch_Dynamic

.code
  SetObject xsi
  .if [xsi].pITypeInfo == NULL
    ;Since we have no ITypeInfo, we'll try to dispatch this call using the IDispEvents table
    mov xdx, POINTER ptr [xsi]                          ;edx -> Dual Method Table
    mov xbx, [xdx - 4]                                  ;ebx -> Event Translation Table
    mov ecx, [xbx]                                      ;Number of ??EVENT_ENTRY structures
    add xbx, sizeof DWORD                               ;ebx -> first ??EVENT_ENTRY
    or ecx, ecx
    .while !Zero?
      mov eax, [xbx].??EVENT_ENTRY.dID                  ;Recover DispID
      .if eax == dMethodID
        mov dx, word ptr [xbx].??EVENT_ENTRY.wFlags     ;DispID found!
        cmp dx, wFlags                                  ;Now check the flags
        je @@Found                                      ;Flags OK
      .endif
      add ebx, sizeof ??EVENT_ENTRY                     ;Goto next ??EVENT_ENTRY
      dec ecx
    .endw
;      DbgWarning "Failed to get this DISPID:", "IWebBrowserEvents2_SiteDispatch"
;      DbgHex dMethodID,, "IWebBrowserEvents2_SiteDispatch"
;      DbgHex wFlags,, "IWebBrowserEvents2_SiteDispatch"
    mov eax, DISP_E_MEMBERNOTFOUND
    ExitMethod

@@Found:
    ;Push arguments
    push pResult                                        ;-> Return VARIANT
    push pParams                                        ;-> DISPPARAMS
    push xsi                                            ;pSelf

    ;Call the method according to its type
    movzx ecx, [xbx].??EVENT_ENTRY.wType                ;ecx = Method type
    lea xdx, @@IWebBrowserEvents2_SiteDispatch_JumpTable
    jmp POINTER ptr [xdx + sizeof(POINTER)*xcx]

@@IWebBrowserEvents2_SiteDispatch_Static:
    call [xbx].??EVENT_ENTRY.pHandler                   ;Invoke event handler; eax = uMsg
    ExitMethod
@@IWebBrowserEvents2_SiteDispatch_VirtualInterface:
    mov xcx, [xbx].??EVENT_ENTRY.pHandler               ;Offset into DMT -> Method address
    add xcx, [xsi].pDispInterface                       ;Correct the offset to redirect to
    sub xcx, xsi                                        ;  another interface
    call POINTER ptr [xcx]                              ;Invoke event handler; eax = uMsg
    ExitMethod
@@IWebBrowserEvents2_SiteDispatch_Dynamic:
    mov xcx, [xbx].??EVENT_ENTRY.pHandler               ;Method offset
    add xcx, [xsi].pDispInterface
    call POINTER ptr [xcx]                              ;Invoke event handler; eax = uMsg

  .else
    invoke SetErrorInfo, 0, 0
    ICall [xsi].pITypeInfo::ITypeInfo.Invoke, [xsi].pDispInterface, dMethodID, \
                wFlags, pParams, pResult, pExcepInfo, pArgErrIdx
    if DEBUGGING eq TRUE
      .if FAILED(eax)
        DbgComError eax
      .endif
    endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IWebBrowserEvents2.BeforeNavigate2
; Purpose:    Notification event before Navigation is started.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT. In this case it is NULL.
; Return:     eax = HRESULT.
;
; Parameters:
;   pDisp:    Object that evaluates to the top-level or frame WebBrowser2 object corresponding to
;             the navigation.
;   Url:      String expression that evaluates to the URL to which the browser is navigating.
;   Flags:    Integer expression that contains the following flag, or zero.
;               &H0001 : Windows Internet Explorer 7 or later. This navigation is the result of
;                         an external window or tab that targets this browser.
;   TargetFrameName: String expression that evaluates to the name of the frame in which the resource
;             will be displayed, or Null if no named frame is targeted for the resource.
;   PostData: Data to send to the server if the HTTP POST transaction is being used.
;   Headers:  Value that specifies the additional HTTP headers to send to the server
;             (HTTP URLs only). The headers can specify such things as the action required of
;             the server, the type of data being passed to the server, or a status code.
;   Cancel:   Boolean value that the container can set to True to cancel the navigation operation,
;             or to False to allow it to proceed.

Method IWebBrowserEvents2.BeforeNavigate2, uses xbx xsi, pParams:LPDISPPARAMS, pRetVal:LPVARIANT
  ;DbgText "IWebBrowserEvents2.BeforeNavigate2"

  mov xcx, pSelf
  mov xdx, [xcx].$Obj(IWebBrowserEvents2).pOwner        ;OcxClientSite
  mov xcx, [xdx].$Obj(OcxClientSite).pOwner             ;OcxContainer
  mov xsi, [xcx].$Obj(OcxContainer).pOwner              ;PropWnd
  .if [xsi].$Obj(PropWnd).dInitialized != FALSE
    mov xdx, pParams
    mov xcx, [xdx].DISPPARAMS.rgvarg
    ;Reverse order!!! Last argument is the first in the array
    ;lea ecx, [xcx + 0*sizeof(VARIANT)]
    mov xdx, [xcx].VARIANT.pboolVal                     ;VT_BYREF|VT_BOOL
    mov [xdx].VARIANT.vt, VT_BOOL
    mov [xdx].VARIANT.boolVal, VARIANT_FALSE

    mov xdx, pParams
    mov xcx, [xdx].DISPPARAMS.rgvarg
    lea xcx, [xcx + 5*sizeof(VARIANT)]
    mov xdx, [xcx].VARIANT.byref                        ;VT_BYREF|VT_VARIANT

    ;Path strings comming from a link uses "\" while path strings comming from another
    ;action uses "/" ... cool eh?
    invoke StrRScanW, [xdx].VARIANT.bstrVal, "\"
    .if xax != NULL
      lea xbx, [xax + 2]
      invoke StrLScanW, xbx, "?"
      .if xax == NULL
        invoke hex2dwordW, xbx                          ;xax -> OBJECT / INTERFACE  INFORMATION
        mov xdx, xax
        mov xcx, [xsi].$Obj(PropWnd).pOwner             ;xdx -> ClientWnd
        .ifBitSet [xdx].INFORMATION.dFlags, INF_INTERFACE
          mov eax, INFO_TYPE_INTERFACE
        .else
          mov eax, INFO_TYPE_OBJECT
        .endif
        DbgStrA [xdx].INFORMATION.pName
        OCall [xcx].$Obj(ClientWnd).pOwner::ObjectBrowser.Navigate, [xdx].INFORMATION.pName, eax
      .endif
    .endif
  .endif

  mov eax, S_OK
MethodEnd

;##/

; ==================================================================================================
;    ICustomSiteDispatch implementation
; ==================================================================================================

;##\

BUTTON_TYPE_EXPLORE_DEF   equ  1
BUTTON_TYPE_EDIT_DEF      equ  2
BUTTON_TYPE_EXPLORE_ASM   equ  3
BUTTON_TYPE_EDIT_ASM      equ  4
BUTTON_TYPE_EXPLORE_LIB   equ  5
BUTTON_TYPE_COMPILE_LIB   equ  6
BUTTON_TYPE_EDIT_METHOD   equ  7
BUTTON_TYPE_SHOW_DETAIL   equ  8
BUTTON_TYPE_HIDE_ARGS     equ  9
BUTTON_TYPE_NAVIGATE      equ  10
BUTTON_TYPE_REDEFMTD      equ  20
BUTTON_TYPE_REDEFVAR      equ  21



; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ICustomSiteDispatch.GetIDsOfNames
; Purpose:    Map a single member name and an optional set of parameter names to a corresponding set
;             of integer dispatch identifiers (DISPIDs), which can then be used on subsequent calls
;             to Invoke.
; Arguments:  Arg1: -> IID_NULL
;             Arg2: -> Passed in array of names to be mapped.
;             Arg3: Count of names to be mapped.
;             Arg4: Locale context in which to interpret the names.
;             Arg5: -> Return ID array corresponding to the Arg2.
; Return:     eax = HRESULT.
;             S_OK: success.
;             E_OUTOFMEMORY: out of memory.
;             DISP_E_UNKNOWNNAME: one or more of the names were not known. The returned array of
;               DISPIDs contains DISPID_UNKNOWN for each entry that corresponds to an unknown name.
;             DISP_E_UNKNOWNLCID: the locale identifier (LCID) was not recognized.

Method ICustomSiteDispatch.GetIDsOfNames, uses xbx xdi xsi, pIID:POINTER, pNames:POINTER, \
                                  dNameCnt:DWORD, dLCID:DWORD, pNameIDs:POINTER
  local hResult:DWORD

  ;DbgText "ICustomSiteDispatch.GetIDsOfNames";, "ICustomSiteDispatch"
  mov hResult, S_OK
  mov xsi, pNames
  mov xdi, pNameIDs
  .while dNameCnt > 0
    xor ebx, ebx
    .while ebx < ICustomSiteDispatchTableCount
      lea xax, ICustomSiteDispatchTable
      shl xbx, $Log2(sizeof(POINTER)) + 1
      invoke StrICompW, POINTER ptr [xsi], POINTER ptr [xax + xbx]
      .if eax == 0
        lea xax, ICustomSiteDispatchTable
        m2m POINTER ptr [xdi], POINTER ptr [xax + xbx + sizeof(POINTER)], xdx
        jmp @F
      .endif
      shr xbx, $Log2(sizeof(POINTER)) + 1
      inc ebx
    .endw
    mov hResult, DISP_E_UNKNOWNNAME
    mov POINTER ptr [xdi], DISPID_UNKNOWN
@@:
    add xdi, sizeof(POINTER)
    add xsi, sizeof(POINTER)
    dec dNameCnt
  .endw
  mov eax, hResult
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ICustomSiteDispatch.Init
; Purpose:    Initialize the ICustomSiteDispatch interface object and replaces the original
;             ClientSiteDispatch interface of its owner.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Interface object whose methods will be dispatched.
;             Arg3: -> TypeLib GUID associated to the interface.
; Return:     Nothing.

Method ICustomSiteDispatch.Init, uses xbx xsi, pOwner:POINTER
  local IDList:$Obj(IDL)

  DbgText "ICustomSiteDispatch.Init", "ICustomSiteDispatch"
  SetObject xsi
  ACall xsi.Init, pOwner, NULL, NULL

  ;Replace the original OcxClientSite.IClientSiteDispatch with this instance
  SetOwner xbx, OcxClientSite
  OCall [xbx].Interfaces::Collection.IndexOf, [xbx].pISiteDispatch
  OCall [xbx].Interfaces::Collection.PutAt, eax, xsi
  mov [xbx].pISiteDispatch, xsi
  Destroy xax                                         ;xax -> old pISiteDispatch

  ;Get the Windows directory
  lea xbx, [xsi].cExplorerApp
  New IDList::IDL
  OCall IDList::IDL.Init, xsi
  OCall IDList::IDL.SetSpecialFolder, CSIDL_WINDOWS
  OCall IDList::IDL.GetPath, xbx
  OCall IDList::IDL.Done
  ;Add "\Explorer.exe"
  invoke StrCCat, xbx, $OfsCStr("\Explorer.exe"), lengthof($Obj(ICustomSiteDispatch).cExplorerApp) - 1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MatchMtdInfo
; Purpose:    Performs a match test.
; Arguments:  Arg1: -> MEMBERDATA.
;             Arg2: -> OBJMTDINFORMATION.
;             Arg3: Dummy.
; Return:     eax = Zero if matches.

MatchMtdInfo proc pMemberData:PMEMBERDATA, pObjMtdInfo:POBJMTDINFORMATION, xDummy:XWORD
  mov xax, pObjMtdInfo
  mov xcx, pMemberData
  sub xax, [xcx].MEMBERDATA.pMemberInfo                 ;Check if both POINTERs are equal
  if TARGET_BITNESS eq 64                               ;  by subtracting them
    mov ecx, eax
    shr rax, 32
    or eax, ecx                                         ;Merge high 32 bit with low 32 bit
  endif
  ret
MatchMtdInfo endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ICustomSiteDispatch.OnClick
; Purpose:    React on a click event.
; Arguments:  Arg1: -> DISPPARAMS structure.
;             Arg2: -> Return value VARIANT.
; Return:     eax = HRESULT. See IDispatch.DispatchInvoke return values.

Method ICustomSiteDispatch.OnClick, uses xbx xdi xsi, pParams:LPDISPPARAMS, pRetVal:LPVARIANT
  local dType:DWORD, xID:XWORD, hWnd:HANDLE, pName:PSTRING
  local StartupInfo:STARTUPINFO, ProcessInfo:PROCESS_INFORMATION
  local cFileName[MAX_PATH]:CHR, cParam[2*MAX_PATH]:CHR, cCommand[2*MAX_PATH]:CHR

  DbgText "ICustomSiteDispatch.OnClick";, "ICustomSiteDispatch"
  SetObject xsi
  .if pParams != NULL && pRetVal != NULL
    mov xcx, pParams
    mov xdx, [xcx]
    .if [xdx].VARIANT.vt == VT_I4
      ;Inspect second parameter = ID
      m2m xID, [xdx].VARIANT.lVal, xax
      ;Move to first argument
      add xdx, sizeof VARIANT
      .if [xdx].VARIANT.vt == VT_I4
        ;Inspect second parameter = Type
        m2m dType, [xdx].VARIANT.lVal, eax
        .if dType == BUTTON_TYPE_EXPLORE_DEF
          lea xbx, cParam
          FillString [xbx], < /e, /select,>           ;Write this into cParam
          lea xcx, [xbx + 13*sizeof(CHR)]
          mov xdx, xID
          invoke StrCopy, xcx, [xdx].FILEINFORMATION.pFileName                      ;****************************************
          invoke ShellExecute, 0, offset cOpen, addr [xsi].cExplorerApp, xbx, NULL, SW_SHOW
        .elseif dType == BUTTON_TYPE_EXPLORE_ASM
          lea xbx, cParam
          FillString [xbx], < /e, /select,>           ;Write this into cParam
          lea xcx, [xbx + 13*sizeof(CHR)]
          mov xdx, xID
          invoke StrECopy, xcx, [xdx].FILEINFORMATION.pFileName
          FillString CHR ptr [xax - 3*sizeof(CHR)], <asm>
          invoke ShellExecute, 0, offset cOpen, addr [xsi].cExplorerApp, xbx, NULL, SW_SHOW
        .elseif dType == BUTTON_TYPE_EXPLORE_LIB
          lea xbx, cParam
          FillString [xbx], < /e, /select,>           ;Write this into cParam
          lea xcx, [xbx + 13*sizeof(CHR)]
          mov xdx, xID
          invoke StrECopy, xcx, [xdx].FILEINFORMATION.pFileName
          FillString CHR ptr [xax - 3*sizeof(CHR)], <lib>
          invoke ShellExecute, 0, offset cOpen, addr [xsi].cExplorerApp, xbx, NULL, SW_SHOW

        .elseif dType == BUTTON_TYPE_EDIT_DEF
          mov xcx, [xsi].pOwner
          mov xdx, [xcx].$Obj(OcxClientSite).pOwner
          mov xcx, [xdx].$Obj(OcxContainer).pOwner
          mov xdx, [xcx].$Obj(PropWnd).pOwner
          mov xbx, [xdx].$Obj(ClientWnd).pOwner

          mov xcx, [xbx].$Obj(ObjectBrowser).pViewerApp
          .if xcx == NULL || CHR ptr [xcx] == 0
            mov xax, xID
            invoke ShellExecute, 0, offset cOpen, [xax].FILEINFORMATION.pFileName, NULL, NULL, SW_SHOW
          .else
            mov StartupInfo.cb, sizeof STARTUPINFO
            invoke GetStartupInfo, addr StartupInfo
            mov StartupInfo.dwFlags, STARTF_USESHOWWINDOW
            mov StartupInfo.wShowWindow, SW_SHOW
            invoke StrECopy, addr cParam, [xbx].$Obj(ObjectBrowser).pViewerApp
            FillString CHR ptr [xax], < >
            add eax, sizeof(CHR)
            mov xdx, xID
            invoke StrCopy, xax, [xdx].FILEINFORMATION.pFileName
            invoke ExpandEnvironmentStrings, addr cParam, addr cCommand, lengthof cCommand
            invoke CreateProcess, NULL, addr cCommand, NULL, NULL, TRUE, NULL, NULL, NULL, \
                                  addr StartupInfo, addr ProcessInfo
          .endif

        .elseif dType == BUTTON_TYPE_EDIT_ASM
          lea xbx, cFileName
          mov xdx, xID
          invoke StrECopy, xbx, [xdx].FILEINFORMATION.pFileName
          FillString CHR ptr [xax - 3*sizeof(CHR)], <asm>

          mov xcx, [xsi].pOwner
          mov xdx, [xcx].$Obj(OcxClientSite).pOwner
          mov xcx, [xdx].$Obj(OcxContainer).pOwner
          mov xdx, [xcx].$Obj(PropWnd).pOwner
          mov xbx, [xdx].$Obj(ClientWnd).pOwner

          mov xcx, [xbx].$Obj(ObjectBrowser).pViewerApp
          .if xcx == NULL || CHR ptr [xcx] == 0
            invoke ShellExecute, 0, offset cOpen, addr cFileName, NULL, NULL, SW_SHOW
          .else
            mov StartupInfo.cb, sizeof STARTUPINFO
            invoke GetStartupInfo, addr StartupInfo
            mov StartupInfo.dwFlags, STARTF_USESHOWWINDOW
            mov StartupInfo.wShowWindow, SW_SHOW
            invoke StrECopy, addr cParam, [xbx].$Obj(ObjectBrowser).pViewerApp
            FillString CHR ptr [xax], < >
            add xax, sizeof(CHR)
            lea xdx, cFileName
            invoke StrCopy, xax, xdx
            invoke ExpandEnvironmentStrings, addr cParam, addr cCommand, lengthof cCommand
            invoke CreateProcess, NULL, addr cCommand, NULL, NULL, TRUE, NULL, NULL, NULL, \
                                  addr StartupInfo, addr ProcessInfo
          .endif

        .elseif dType == BUTTON_TYPE_COMPILE_LIB
          mov xcx, [xsi].pOwner
          mov xdx, [xcx].$Obj(OcxClientSite).pOwner
          mov xcx, [xdx].$Obj(OcxContainer).pOwner
          mov xdx, [xcx].$Obj(PropWnd).pOwner
          mov xbx, [xdx].$Obj(ClientWnd).pOwner
          m2m hWnd, [xbx].$Obj(ObjectBrowser).hWnd, xax

          lea xbx, cFileName
          mov xax, xID
          invoke StrECopy, xbx, [xax].FILEINFORMATION.pFileName
          m2z CHR ptr [xax - 3*sizeof(CHR)]
          invoke StrRScan, xbx, "\"
          .if xax == NULL
            invoke StrRScan, addr cFileName, ":"
          .endif
          add xax, sizeof(CHR)
          mov pName, xax

          ;Assembling
          lea xdi, cParam
          lea xbx, cCommand
          invoke ExpandEnvironmentStrings, $OfsCStr("%MASM32_PATH%\Bin\ML.EXE /nologo /c /coff "),\
                                           xbx, lengthof cCommand
          invoke StrECat, xbx, addr cFileName
          FillString CHR ptr [xax], <asm>
          mov StartupInfo.cb, sizeof STARTUPINFO
          invoke GetStartupInfo, addr StartupInfo
          mov StartupInfo.dwFlags, STARTF_USESHOWWINDOW
          mov StartupInfo.wShowWindow, SW_SHOW
          invoke CreateProcess, NULL, xbx, NULL, NULL, TRUE, NULL, NULL, NULL, \
                                addr StartupInfo, addr ProcessInfo
          .if xax == NULL
            invoke GetLastError
            invoke ErrorMessageBox, hWnd, $OfsCStr("Compilation Error"), LOCALE_USER_DEFAULT, eax
          .else
            invoke WaitForProcess, ProcessInfo.dwProcessId, 60000
            .if eax == WAIT_OBJECT_0
              ;Linking
              invoke StrECopy, xdi, $OfsCStr("%MASM32_PATH%\Bin\LINK.EXE -lib ")
              invoke StrECopy, xax, pName
              invoke StrECopy, xax, $OfsCStr("obj /nologo /out:%OA_PATH%\Code\Objects\")
              invoke StrECopy, xax, pName
              FillString CHR ptr [xax], <lib>
              invoke ExpandEnvironmentStrings, xdi, xbx, lengthof cCommand
              invoke CreateProcess, NULL, xbx, NULL, NULL, TRUE, NULL, NULL, NULL, \
                                    addr StartupInfo, addr ProcessInfo
              .if xax == NULL
                invoke GetLastError
                invoke ErrorMessageBox, hWnd, $OfsCStr("Link Error"), LOCALE_USER_DEFAULT, eax
              .else
                invoke WaitForProcess, ProcessInfo.dwProcessId, 60000
              .endif
            .else
              invoke ErrorMessageBox, hWnd, $OfsCStr("Compilation Error"), LOCALE_USER_DEFAULT, eax
            .endif
          .endif

          ;Cleanup: remove the .obj file from the current directory
          invoke StrEnd, pName
          FillString CHR ptr [xax], <obj>
          invoke DeleteFile, pName

          mov xcx, [xsi].pOwner
          mov xdx, [xcx].$Obj(OcxClientSite).pOwner
          mov xbx, [xdx].$Obj(OcxContainer).pOwner      ;xbx -> PropWindow
          OCall xbx::PropWnd.EmitHtml
          ICall [xbx].$Obj(PropWnd).pIWebBrowser2::IWebBrowser2.Refresh

        .elseif dType == BUTTON_TYPE_SHOW_DETAIL
          mov xcx, [xsi].pOwner
          mov xdx, [xcx].$Obj(OcxClientSite).pOwner
          mov xbx, [xdx].$Obj(OcxContainer).pOwner      ;xbx -> PropWindow
          OCall [xbx].$Obj(ObjPropWnd).Methods::DataCollection.FirstThatNot, \
                                                                  offset MatchMtdInfo, xID, NULL
          BitToggle [xax].MEMBERDATA.dFlags, MDT_SHOWDETAIL
          OCall xbx::PropWnd.EmitHtml
          ICall [xbx].$Obj(PropWnd).pIWebBrowser2::IWebBrowser2.Refresh

        .elseif dType == BUTTON_TYPE_REDEFMTD
          mov xcx, [xsi].pOwner
          mov xdx, [xcx].$Obj(OcxClientSite).pOwner
          mov xbx, [xdx].$Obj(OcxContainer).pOwner      ;xbx -> PropWindow
          m2m [xbx].$Obj(PropWnd).dShowRedefMtds, DWORD ptr xID, xcx
          OCall xbx::PropWnd.EmitHtml
          ICall [xbx].$Obj(PropWnd).pIWebBrowser2::IWebBrowser2.Refresh

        .elseif dType == BUTTON_TYPE_REDEFVAR
          mov xcx, [xsi].pOwner
          mov xdx, [xcx].$Obj(OcxClientSite).pOwner
          mov xbx, [xdx].$Obj(OcxContainer).pOwner      ;xbx -> PropWindow
          m2m [xbx].$Obj(PropWnd).dShowRedefVars, DWORD ptr xID, xcx
          OCall xbx::PropWnd.EmitHtml
          ICall [xbx].$Obj(PropWnd).pIWebBrowser2::IWebBrowser2.Refresh

        .endif
        mov eax, S_OK

      .else
        mov eax, DISP_E_TYPEMISMATCH
      .endif
    .else
      mov eax, DISP_E_TYPEMISMATCH
    .endif
  .else
    mov eax, E_FAIL
  .endif
MethodEnd

;##/

; ==================================================================================================
;    ObjectBrowser implementation
; ==================================================================================================

;##\

PROPERTIES_INFO struct
  pCaption    PSTRING   ?
  dType       DWORD     ?
  pChild      $ObjPtr(ObjPropWnd) ?         ;Return value
PROPERTIES_INFO ends

OLECMDEXECOPT_DODEFAULT equ 0

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
  mov dWwd, 600
  mov dWht, 450
  mov dWtx, $32($invoke(CenterForm, dWwd, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov dWty, $32($invoke(CenterForm, dWht, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
                         offset cObjectBrowserClass, offset szAppTitle, \
                         WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
                         dWtx, dWty, dWwd, dWht, 0, [xsi].hMenuInit, hInstance, xsi

  ;Initialize Client window
  mrm [xsi].pClientWnd, offset $ObjTmpl(ClientWnd), xdi
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
    ICall [xsi].pIOleCommandTarget::IOleCommandTarget.Exec, NULL, OLECMDID_SELECTALL, \
                                                            OLECMDEXECOPT_DONTPROMPTUSER, NULL, NULL
    RELEASE_AND_NULLIFY [xsi].pIOleCommandTarget

  .elseif ax == IDM_COPY
    ICall [xsi].pIOleCommandTarget::IOleCommandTarget.Exec, NULL, OLECMDID_COPY, \
                                                            OLECMDEXECOPT_DONTPROMPTUSER, NULL, NULL
    RELEASE_AND_NULLIFY [xsi].pIOleCommandTarget

  .elseif ax == IDM_PRINTPREVIEW
    ICall [xsi].pIOleCommandTarget::IOleCommandTarget.Exec, NULL, OLECMDID_PRINTPREVIEW, \
                                                            OLECMDEXECOPT_DODEFAULT, NULL, NULL
    RELEASE_AND_NULLIFY [xsi].pIOleCommandTarget

  .elseif ax == IDM_PRINT
    ICall [xsi].pIOleCommandTarget::IOleCommandTarget.Exec, NULL, OLECMDID_PRINT, \
                                                            OLECMDEXECOPT_DODEFAULT, NULL, NULL
    RELEASE_AND_NULLIFY [xsi].pIOleCommandTarget

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
        OCall xbx::PropWnd.EmitHtml
        ICall [xbx].$Obj(PropWnd).pIWebBrowser2::IWebBrowser2.Refresh
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

; ==================================================================================================
;    PropWnd implementation
; ==================================================================================================

;##\

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  EmitHtmlText
; Purpose:    Auxiliary procedure that emits special HTML codes as &#xxxx; text.
; Arguments:  Arg1: HTML file handle.
;             Arg2: -> Source text.
; Return:     Nothing.

EmitHtmlText proc uses xbx xdi xsi hHtmlFile:HANDLE, pText:PSTRING
  local bBuffer[20]:BYTE, dBytesWritten:DWORD, dLength:DWORD

  invoke StrLength, pText
  mov xsi, pText
  mov ebx, eax
  lea xdi, dBytesWritten
  .while ebx != 0
    movzx edx, BYTE ptr [xsi]
    .if edx >= 128
      invoke dword2dec, addr bBuffer, edx
      invoke WriteFile, hHtmlFile, $OfsCStr("&#"), 2, xdi, NULL
      mov dLength, $32($invoke(StrLength, addr bBuffer))
      invoke WriteFile, hHtmlFile, addr bBuffer, dLength, addr dBytesWritten, NULL
      invoke WriteFile, hHtmlFile, $OfsCStr(";"), 1, xdi, NULL
    .elseif edx == 32
      invoke WriteFile, hHtmlFile, offset HTML_SPACE, sizeof HTML_SPACE, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, xsi, 1, xdi, NULL
    .endif
    inc esi
    dec ebx
  .endw
  ret
EmitHtmlText endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FindFinalMember
; Purpose:    Used with Collection.LastThatNot to reset the MDT_FINAL flag.
; Arguments:  Arg1: -> Iterated MEMBERDATA.
;             Arg2: -> Source MEMBERDATA.
;             Arg3: Dummy.
; Return:     eax = Zero stops the iteration.

FindFinalMember proc pMemberData:PMEMBERDATA, pSrcData:PMEMBERDATA, xDummy:XWORD
  mov xax, pMemberData
  mov xdx, [xax].MEMBERDATA.pMemberInfo
  mov xcx, pSrcData
  mov xax, [xcx].MEMBERDATA.pMemberInfo
  invoke StrCompA, [xax].INFORMATION.pName, [xdx].INFORMATION.pName
  .if eax == 0                                          ;Method/Variable found
    mov xcx, pMemberData
    BitClr [xcx].MEMBERDATA.dFlags, MDT_FINAL           ;Reset the flag
    mov xdx, [xcx].MEMBERDATA.pDefinition
    .if xdx == NULL
      mov xdx, [xcx].MEMBERDATA.pMemberInfo
    .endif
    mov xcx, pSrcData
    mov [xcx].MEMBERDATA.pDefinition, xdx               ;Copy pDefinition from MemberData in SrcData
  .endif                                                ;eax == 0 => stop search
  ret
FindFinalMember endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.Done
; Purpose:    Finalizes the PropWnd object and disposes the MDI child window.
; Arguments:  None.
; Return:     Nothing.

Method PropWnd.Done, uses xbx xdi xsi
  SetObject xsi

  ;WebBrowser2 cleanup
  .if [xsi].pICP_WB != NULL
    invoke ComEventsUnadvice, [xsi].pICP_WB, [xsi].dCookie_WB
  .endif
  SAFE_RELEASE_AND_NULLIFY [xsi].pIWebBrowser2
  OCall [xsi].pOcxContainer::OcxContainer.Done

  ;Close and delete HTML auxiliary file
  .if [xsi].hHtmlFile != 0
    invoke CloseHandle, [xsi].hHtmlFile
    invoke DeleteFile, [xsi].pFileName
    invoke StrDispose, [xsi].pFileName
  .endif

  ;Main menu update
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(ClientWnd).pOwner
  mov xbx, [xdi].$Obj(ObjectBrowser).pClientWnd
  dec [xbx].$Obj(ClientWnd).dChildCount
  OCall xdi::ObjectBrowser.EnableActions
  .if [xbx].$Obj(ClientWnd).dChildCount == 0            ;No more child windows ?
    invoke SendMessage, [xdi].$Obj(ObjectBrowser).hWnd, WM_MDISETMENU, \
                        [xbx].$Obj(ObjectBrowser).hMenuInit, NULL
    invoke DrawMenuBar, [xdi].$Obj(ObjectBrowser).hWnd  ;Redraw the new menu bar
  .endif

  ;Final object cleanup
  .if [xsi].pName != NULL
    invoke StrDispose, [xsi].pName
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.Init
; Purpose:    Initalizes the PropWnd object.
; Arguments:  Arg1: -> Owner object (ClientWnd).
;             Arg2: -> Window Class name.
;             Arg2: -> INFORMATION.
; Return:     Nothing.

Method PropWnd.Init, uses xbx xdi xsi, pOwner:$ObjPtr(ClientWnd), pWndClassName:PSTRING, \
                                       pInfo:PINFORMATION
  local Rect:RECT, cTempPath[MAX_PATH]:CHR, dIsMaximized:DWORD

  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  m2m [xsi].pInfo, pInfo, xax

  ;Create a local copy of the name (used to refresh the window content)
  mov [xsi].pName, $invoke(StrNew, [xax].INFORMATION.pName)

  ;Apply application setup
  mov xcx, [xsi].pOwner                                 ;xcx -> ClientWnd
  mov xdx, [xcx].$Obj(ClientWnd).pOwner                 ;xdx -> ObjectBrowser
  m2m [xsi].dShowRedefMtds, [xdx].$Obj(ObjectBrowser).dShowRedefMtds, eax
  m2m [xsi].dShowRedefVars, [xdx].$Obj(ObjectBrowser).dShowRedefVars, eax

  ;Create an auxiliar HTML File in the user temp folder
  lea xdi, cTempPath
  invoke GetTempPath, lengthOf cTempPath, xdi
  mov xbx, $invoke(StrECat, xdi, $OfsCStr("OBR_"))
  invoke dword2hex, xax, esi
  FillString CHR ptr [xbx + 8*sizeof(CHR)], <.html>
  mov [xsi].pFileName, $invoke(StrNew, xdi)
  DbgStr [xsi].pFileName
  invoke CreateFile, xdi, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, \
                     FILE_ATTRIBUTE_TEMPORARY, 0
  mov [xsi].hHtmlFile, xax

  ;Polymorphic calls
  OCall xsi.Gather
  OCall xsi.EmitHtml

  mov xdi, pOwner
  inc [xdi].$Obj(ClientWnd).dChildCount
  invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, addr dIsMaximized
  .if xax != 0 && dIsMaximized == FALSE                 ;xax = MDI Child HWND
    xor ebx, ebx
  .else
    mov ebx, WS_MAXIMIZE
  .endif
  mov xax, pInfo
  invoke CreateMDIWindow, pWndClassName, [xax].INFORMATION.pName, \
                          ebx, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(ClientWnd).hWnd, hInstance, xsi
  mov xbx, [xdi].$Obj(ClientWnd).pOwner
  OCall xbx::ObjectBrowser.EnableActions
  .if eax != 0
    .if [xdi].$Obj(ClientWnd).dChildCount == 1          ;First child window ?
      mov xax, [xbx].$Obj(ObjectBrowser).pClientWnd
      invoke SendMessage, [xax].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                          [xbx].$Obj(ObjectBrowser).hMenuChild, [xbx].$Obj(ObjectBrowser).hMenuChildWnd
      invoke DrawMenuBar, [xbx].$Obj(ObjectBrowser).hWnd      ;Redraw the new menu bar
    .endif
    OCall xsi.InitContainer, [xsi].pFileName
    lea xbx, Rect
    invoke GetClientRect, [xsi].hWnd, xbx
    OCall xsi.SetOcxPosition, xbx
    mov [xsi].dInitialized, TRUE
  .else
    invoke GetLastError
    invoke ErrorMessageBox, [xbx].$Obj(ObjectBrowser).hWnd, $OfsCStr("Window creation error"), \
                            LOCALE_USER_DEFAULT, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.InitContainer
; Purpose:    Initalize Container object.
; Arguments:  Arg1: -> FileName (ANSI).
; Return:     Nothing.

Method PropWnd.InitContainer, uses xsi, pFileName:PSTRING
  local URL[1024]:word, pICustomSiteDispatch:POINTER

  SetObject xsi
  New OcxContainer
  .if xax != NULL
    mov [xsi].pOcxContainer, xax
    OCall [xsi].pOcxContainer::OcxContainer.Init, xsi, [xsi].hWnd
    .if eax == OBJ_OK
      OCall [xsi].pOcxContainer::OcxContainer.CreateClientSite
      .if xax != NULL
        mov [xsi].pOcxClientSite, xax
        New ICustomSiteDispatch
        .if xax != NULL
          mov pICustomSiteDispatch, xax
          OCall pICustomSiteDispatch::ICustomSiteDispatch.Init, [xsi].pOcxClientSite
          New ICustomDocHostUIHandler
          .if xax != NULL
            ;Initialize and customize the interface
            mov xcx, [xsi].pOcxClientSite
            OCall [xcx].$Obj(OcxClientSite).Interfaces::Collection.Insert, xax
            m2m [xax].$Obj(ICustomDocHostUIHandler).pHostDispatch, pICustomSiteDispatch, xdx
            mov [xax].$Obj(ICustomDocHostUIHandler).dShowUI, S_OK
            OCall xax::ICustomDocHostUIHandler.Init, [xsi].pOcxClientSite

            ;Create an event sink
            mov [xsi].pIWebBrowserEvents2, $New(IWebBrowserEvents2)
            OCall xax::IWebBrowserEvents2.Init, [xsi].pOcxClientSite, NULL, NULL
            mov xcx, [xsi].pOcxClientSite
            OCall [xcx].$Obj(OcxClientSite).Interfaces::Collection.Insert, xax

            ;Create the WebBrowser2 control with the customized ClientSite
            OCall [xsi].pOcxContainer::OcxContainer.CreateControl, offset CLSID_WebBrowser, \
                                                                   CLSCTX_INPROC_SERVER, \
                                                                   [xsi].pOcxClientSite
            .if eax == OBJ_OK
              invoke StrA2StrW, addr URL, pFileName
              mov xcx, [xsi].pOcxClientSite
              ICall [xcx].$Obj(OcxClientSite).pIUnknown::IUnknown.QueryInterface, \
                                                   offset IID_IWebBrowser2, addr [xsi].pIWebBrowser2
              .if SUCCEEDED(eax)
                invoke ComEventsAdvice, [xsi].pIWebBrowser2, [xsi].pIWebBrowserEvents2, \
                                        offset IID_DWebBrowserEvents2, \
                                        addr [xsi].pICP_WB, addr [xsi].dCookie_WB
                ;Deactivate file dropping
                ICall [xsi].pIWebBrowser2::IWebBrowser2.put_RegisterAsDropTarget, FALSE
                ;Navigate to our file in the temp folder
                ICall [xsi].pIWebBrowser2::IWebBrowser2.Navigate, addr URL, NULL, NULL, NULL, NULL
                .if FAILED(eax)
                  mov eax, -1
                .endif
              .else
                mov eax, -2
              .endif
            .else
              mov eax, -3
            .endif
          .else
            mov eax, -4
          .endif
        .else
          mov eax, -5
        .endif
      .else
        mov eax, -6
      .endif
    .else
      mov eax, -7
    .endif
  .else
    DbgText "Failed to allocate OcxContainer"
    mov eax, -8
  .endif

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PropWnd.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  invoke GetActiveWindow
  SetObject xsi
  mov xcx, [xsi].pOwner                               ;xcx -> ClientWnd
  mov xdx, [xcx].$Obj(ClientWnd).pOwner         ;xdx -> ObjectBrowser
  .if xax == [xdx].$Obj(ObjectBrowser).hWnd
    invoke DefMDIChildProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method PropWnd.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Rect:RECT

;  DbgText "OnSize"
  .if (wParam == SIZE_RESTORED || wParam == SIZE_MAXIMIZED)
    SetObject xsi
    ;Put the client size in Rect
    m2z Rect.left
    m2z Rect.top
    PntS2Pnt (POINT ptr Rect.right), lParam
    OCall xsi.SetOcxPosition, addr Rect
  .endif
  invoke DefMDIChildProc, [xsi].hWnd, WM_SIZE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PropWnd.SetOcxPosition
; Purpose:    Sets the size of the OCX control.
; Arguments:  Arg1: -> RECT.
; Return:     eax = Zero.

Method PropWnd.SetOcxPosition, uses xsi, pRect:PRECT
  local Rect:RECT

;  DbgText "PropWnd.SetOcxPosition"
  SetObject xsi
  .if [xsi].pOcxClientSite != NULL
    mov xcx, [xsi].pOcxClientSite
    .if [xcx].$Obj(OcxClientSite).pIOleInPlaceSite != NULL
      ;Put the client size in Rect
      mov xax, pRect
      m2z Rect.left
      m2z Rect.top
      mov edx, [xax].RECT.right
      sub edx, [xax].RECT.left
      mov Rect.right, edx
      mov edx, [xax].RECT.bottom
      sub edx, [xax].RECT.top
      mov Rect.bottom, edx
      ;Set rect as clip area for this control
      CloneRect [xcx].$Obj(OcxClientSite).ClipRect, Rect, xax
      ICall [xcx].$Obj(OcxClientSite).pIOleInPlaceSite::IOleInPlaceSite.OnPosRectChange, addr Rect
    .endif
  .endif
MethodEnd

;##/

; ==================================================================================================
;    IntPropWnd implementation
; ==================================================================================================

;##\

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntPropWnd.Done
; Purpose:    Finalizes the IntPropWnd object and disposes the MDI child window.
; Arguments:  None.
; Return:     Nothing.

Method IntPropWnd.Done, uses xsi
  SetObject xsi

  ;Release internal data
  OCall [xsi].Methods::DataCollection.Done

  ;Final object cleanup
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntPropWnd.Init
; Purpose:    Initalizes the IntPropWnd object.
; Arguments:  Arg1: -> Owner object (ClientWnd).
;             Arg2: -> Window Class name.
;             Arg2: -> PINTERFACEINFORMATION.
; Return:     Nothing.

Method IntPropWnd.Init, uses xsi, pOwner:$ObjPtr(ClientWnd), pWndClassName:PSTRING, \
                                  pInfo:PINTERFACEINFORMATION
  SetObject xsi
  OCall [xsi].Methods::DataCollection.Init, xsi, 50, 50, COL_MAX_CAPACITY
  ACall xsi.Init, pOwner, pWndClassName, pInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ShowIntMtd
; Purpose:    Emits HTML codes to render interface method member information.
; Arguments:  Arg1: -> MEMBERDATA.
;             Arg2: -> IntPropWnd.
;             Arg3: Dummy.
; Return:     Nothing.

ShowIntMtd proc uses xbx xdi xsi pMemberData:PMEMBERDATA, pSelf:$ObjPtr(IntPropWnd), xDummy:XWORD
  local dBytesWritten:DWORD, hHtmlFile:HANDLE

  SetObject xsi, IntPropWnd
  m2m hHtmlFile, [xsi].hHtmlFile, xax
  ReleaseObject
  mov xsi, pMemberData
  lea xdi, dBytesWritten
  mov xbx, [xsi].MEMBERDATA.pMemberInfo               ;ebx -> INTMTDINFORMATION
  .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_UNKNOWN
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_MIS_00, HTML_MIS_00_SIZE, xdi, NULL
    ;Attention: In this case ebx -> INTERFACEINFORMATION
    invoke StrLength, [xbx].INTERFACEINFORMATION.pAncestorName
    invoke WriteFile, hHtmlFile, [xbx].INTERFACEINFORMATION.pAncestorName, eax, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_MIS_01, offset HTML_MIS_01_SIZE, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_MIS_02, offset HTML_MIS_02_SIZE, xdi, NULL
  .else
    mov xcx, pSelf
    .if [xcx].$Obj(IntPropWnd).dShowRedefMtds == FALSE
      .ifBitClr [xsi].MEMBERDATA.dFlags, MDT_FINAL
        ret
      .endif
    .endif

    invoke WriteFile, hHtmlFile, offset HTML_IMD_01, HTML_IMD_01_SIZE, xdi, NULL
    .if [xbx].INTMTDINFORMATION.dFlags == METHODTYPE_STANDARD
      invoke WriteFile, hHtmlFile, offset HTML_INTMTD, sizeof HTML_INTMTD, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_INTDSP, sizeof HTML_INTDSP, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_IMD_02, HTML_IMD_02_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
    .endif
    invoke StrLength, [xbx].INTMTDINFORMATION.pInterfaceName
    invoke WriteFile, hHtmlFile, [xbx].INTMTDINFORMATION.pInterfaceName, eax, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_06, HTML_OMD_06_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_OPEN_BOLD, sizeof HTML_OPEN_BOLD, xdi, NULL
    .endif
    mov ecx, [xbx].INTMTDINFORMATION.dFlags
    invoke StrLength, [xbx].INTMTDINFORMATION.pName
    invoke WriteFile, hHtmlFile, [xbx].INTMTDINFORMATION.pName, eax, xdi, NULL
    mov ecx, [xbx].INTMTDINFORMATION.dFlags
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_CLOSE_BOLD, sizeof HTML_CLOSE_BOLD, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_OMD_07, HTML_OMD_07_SIZE, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_08, HTML_OMD_08_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    mov eax, [xbx].INTMTDINFORMATION.dFlags
    lea xcx, SOM_TEXT_TABLE
    mov xbx, POINTER ptr [xcx + sizeof(POINTER)*xax]
    invoke StrLength, xbx
    invoke WriteFile, hHtmlFile, xbx, eax, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_10, HTML_OMD_10_SIZE, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_11, HTML_OMD_11_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_SHOWDETAIL
      invoke WriteFile, hHtmlFile, offset HTML_OMC_00, HTML_OMC_00_SIZE, xdi, NULL
      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
      .endif
      invoke WriteFile, hHtmlFile, offset bCRLF, 2, xdi, NULL
      invoke WriteFile, hHtmlFile, offset HTML_OMC_01, HTML_OMC_01_SIZE, xdi, NULL
    .endif
  .endif
  ret
ShowIntMtd endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      OutputFileInfo
; Purpose:    Compares the current and the stored FileTime data and emits HTML codes to display it.
; Arguments:  Arg1: FileTimeVar.
;             Arg2: Evaluate flag.
; Return:     Nothing.

OutputFileInfo macro FileTimeVar:req, Evaluate:=<0>           ;xbx must -> filename
  invoke StrLength, xbx
  invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_04, HTML_FLS_04_SIZE, xdi, NULL
  .if $invoke(FileExist, xbx) != FALSE
    invoke CreateFile, xbx, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
    mov xbx, xax
    lea xax, FileTimeVar
    invoke GetFileTime, xbx, NULL, NULL, xax                  ;Get LastWriteTime
    invoke CloseHandle, xbx
    invoke FileTimeToSystemTime, addr FileTimeVar, addr SysTimeUTC
    invoke SystemTimeToTzSpecificLocalTime, NULL, addr SysTimeUTC, addr SysTimeLocal
    movzx eax, SysTimeLocal.wSecond
    mov dSecond, eax
    movzx eax, SysTimeLocal.wMinute
    mov dMinute, eax
    movzx eax, SysTimeLocal.wHour
    mov dHour, eax
    movzx eax, SysTimeLocal.wYear
    mov dYear, eax
    movzx eax, SysTimeLocal.wMonth
    mov dMonth, eax
    movzx eax, SysTimeLocal.wDay
    mov dDay, eax
    lea xbx, cBuffer
    invoke wsprintf, xbx, $OfsCStr("%02d/%02d/%02d %02d:%02d:%02d"), dDay, dMonth, dYear, dHour, dMinute, dSecond
    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_05, HTML_FLS_05_SIZE, xdi, NULL
    if Evaluate eq 0
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_OK, sizeof HTML_OK, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    else
      invoke CompareFileTime, addr LastWriteTimeLib, addr LastWriteTimeDef
      mov ebx, eax
      invoke CompareFileTime, addr LastWriteTimeLib, addr LastWriteTimeAsm
      or eax, ebx
      .ifBitSet eax, BIT31
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_OUTDATED, sizeof HTML_OUTDATED, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      .else
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_OK, sizeof HTML_OK, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
  .endif
    endif
  .else
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_FNF_01, HTML_FNF_01_SIZE, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_05, HTML_FLS_05_SIZE, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_FNF_00, HTML_FNF_00_SIZE, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntPropWnd.EmitHtml
; Purpose:    Emits the HTML render code in a file located in the user temp folder.
; Arguments:  None.
; Return:     Nothing.

Method IntPropWnd.EmitHtml, uses xbx xdi xsi
  local dBytesWritten:DWORD, cBuffer[MAX_PATH]:CHR, cHexAddr[12]:CHR
  local LastWriteTimeDef:FILETIME, LastWriteTimeAsm:FILETIME, LastWriteTimeLib:FILETIME
  local SysTimeUTC:SYSTEMTIME, SysTimeLocal:SYSTEMTIME, dLength:DWORD
  local dSecond:DWORD, dMinute:DWORD, dHour:DWORD, dYear:DWORD, dMonth:DWORD, dDay:DWORD

  SetObject xsi

  ;Reset file
  invoke SetFilePointer, [xsi].hHtmlFile, 0, NULL, FILE_BEGIN
  invoke SetEndOfFile, [xsi].hHtmlFile

  lea xdi, dBytesWritten
  mov xbx, [xsi].pInfo

  ;Start HTML document
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_00, HTML_DOC_00_SIZE, xdi, NULL
  mov dLength, $32($invoke(StrLength, [xbx].INTERFACEINFORMATION.pName))
  invoke WriteFile, [xsi].hHtmlFile, [xbx].INTERFACEINFORMATION.pName, dLength, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_01, HTML_DOC_01_SIZE, xdi, NULL

  ;Show name
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_00, HTML_DSC_00_SIZE, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, [xbx].INTERFACEINFORMATION.pName, dLength, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_01, HTML_DSC_01_SIZE, xdi, NULL

  ;Show description (if available)
  mov xbx, [xbx].INTERFACEINFORMATION.pHelpData
  .if xbx != NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_02, HTML_DSC_02_SIZE, xdi, NULL
    .while xbx != NULL
      lea xdx, [xbx + sizeof(POINTER)]
      invoke EmitHtmlText, [xsi].hHtmlFile, xdx
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_BREAK, sizeof HTML_BREAK, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset bCRLF, 2, xdi, NULL
      mov xbx, [xbx]
    .endw
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_03, HTML_DSC_03_SIZE, xdi, NULL
  .endif

  ;Show inheritance path
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_00, HTML_INH_00_SIZE, xdi, NULL
  OCall xsi.ShowInheritance, [xsi].pInfo, FALSE
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_07, HTML_INH_07_SIZE, xdi, NULL

  ;Show file information
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_00, HTML_FLS_00_SIZE, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_01, HTML_FLS_01_SIZE, xdi, NULL

  lea xbx, cHexAddr
  mov word ptr [xbx], "x0"
  mov xdx, [xsi].pInfo
  add xbx, 2
  invoke xword2hex, xbx, [xdx].INTERFACEINFORMATION.pFileInfo

  ;Show definition file
  lea xbx, cHexAddr
  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_02, HTML_FLS_02_SIZE, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_03, HTML_FLS_03_SIZE, xdi, NULL
  mov xcx, [xsi].pInfo
  mov xdx, [xcx].INTERFACEINFORMATION.pFileInfo
  mov xbx, [xdx].FILEINFORMATION.pFileName
  OutputFileInfo LastWriteTimeDef
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_12, HTML_FLS_12_SIZE, xdi, NULL

  ;Show method information
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_IMD_00, HTML_IMD_00_SIZE, xdi, NULL
  OCall [xsi].Methods::DataCollection.ForEach, offset ShowIntMtd, xsi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_OMD_12, HTML_OMD_12_SIZE, xdi, NULL

  ;End HTML document
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_99, HTML_DOC_99_SIZE, xdi, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntPropWnd.Gather
; Purpose:    Collect all informations of this object.
; Arguments:  None.
; Return:     Nothing.

Method IntPropWnd.Gather, uses xsi
  SetObject xsi
  OCall xsi.GatherMethods, [xsi].pInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GatherIntMtds
; Purpose:    Recursion procedure used to collect interface method information.
; Arguments:  Arg1: -> INTMTDINFORMATION.
;             Arg2: -> Interface name.
;             Arg3: -> IntPropWnd.
; Return:     Nothing.

GatherIntMtds proc uses xbx xdi xsi pIntMtdInfo:PINTMTDINFORMATION, pInterfaceName:PSTRING, pSelf:$ObjPtr(IntPropWnd)
  SetObject xsi, IntPropWnd
  mov xbx, pIntMtdInfo
  .if $invoke(StrCompA, [xbx].INTMTDINFORMATION.pInterfaceName, pInterfaceName) == 0
    mov xdi, $MemAlloc(MEMBERDATA)
    mov [xdi].MEMBERDATA.pMemberInfo, xbx
    mov [xdi].MEMBERDATA.dFlags, MDT_FINAL
    m2z [xdi].MEMBERDATA.pDefinition
    .if [xbx].INTMTDINFORMATION.dFlags == METHODTYPE_REDEFINED
      OCall [xsi].Methods::DataCollection.LastThatNot, offset FindFinalMember, xdi, NULL
    .endif
    OCall [xsi].Methods::DataCollection.Insert, xdi
  .endif
  ret
GatherIntMtds endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntPropWnd.GatherMethods
; Purpose:    Collect all method information of this object.
; Arguments:  Arg1: -> OBJECTINFORMATION.
; Return:     Nothing.

Method IntPropWnd.GatherMethods, uses xbx xsi, pInfo:PINTERFACEINFORMATION
  SetObject xsi
  OCall [xsi].Methods::DataCollection.DisposeAll

  mov xcx, pInfo
  mov xdx, [xcx].INTERFACEINFORMATION.pAncestorName
  .if xdx != NULL
    mov xcx, [xsi].pOwner                             ;ecx -> ClientWnd
    OCall [xcx].$Obj(ClientWnd).pOwner::ObjectBrowser.FindIntInfo, xdx
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

  mov xbx, pInfo
  mov xcx, [xsi].pOwner                               ;xcx -> ClientWnd
  mov xax, [xcx].$Obj(ClientWnd).pOwner         ;xax -> ObjectBrowser
  mov xcx, [xax].$Obj(ObjectBrowser).pObjDB
  OCall [xcx].$Obj(OA_ObjDB).IntMethodColl::IntMtdInfoCollection.ForEach, \
                                         offset GatherIntMtds, [xbx].INTERFACEINFORMATION.pName, xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntPropWnd.ShowInheritance
; Purpose:    Method that is called recursively to output an inheritance path.
; Arguments:  Arg1: -> INTERFACENFORMATION.
;             Arg2: Flag to signal if the current item should generate a link.
; Return:     Nothing.

Method IntPropWnd.ShowInheritance, uses xbx xdi xsi, pInterfaceInfo:PINTERFACEINFORMATION, dLink:DWORD
  local dBytesWritten:DWORD, cHexBuffer[12]:CHR

  SetObject xsi
  lea xdi, dBytesWritten
  mov xcx, pInterfaceInfo
  mov xbx, [xcx].INTERFACEINFORMATION.pAncestorName
  .if xbx != NULL
    mov xcx, [xsi].pOwner                             ;ecx -> ClientWnd
    OCall [xcx].$Obj(ClientWnd).pOwner::ObjectBrowser.FindIntInfo, xbx
    .if xax != NULL
      OCall xsi::IntPropWnd.ShowInheritance, xax, TRUE
    .else
      ;Stop recursion
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_ANF_00, HTML_ANF_00_SIZE, xdi, NULL
      invoke StrLength, xbx
      invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_ANF_01, HTML_ANF_01_SIZE, xdi, NULL
    .endif
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_04, HTML_INH_04_SIZE, xdi, NULL
  .endif

  mov xcx, pInterfaceInfo
  mov xbx, [xcx].INTERFACEINFORMATION.pName
  .if dLink != FALSE
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_01, HTML_INH_01_SIZE, xdi, NULL
    invoke xword2hex, addr cHexBuffer, pInterfaceInfo
    invoke WriteFile, [xsi].hHtmlFile, addr cHexBuffer, TARGET_BITNESS/4, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_02, HTML_INH_02_SIZE, xdi, NULL
    invoke StrLength, xbx
    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_03, HTML_INH_03_SIZE, xdi, NULL
  .else
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_05, HTML_INH_05_SIZE, xdi, NULL
    invoke StrLength, xbx
    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_06, HTML_INH_06_SIZE, xdi, NULL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IntPropWnd.Startup
; Purpose:    Registers the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method IntPropWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(IntPropWnd.WndProc), xdx
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, 0
  mov WC.lpszMenuName, NULL
  m2m WC.lpszClassName, offset cIntPropClass, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_INT_STD"))
  mov WC.hIconSm, 0
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

;##/

; ==================================================================================================
;    ObjPropWnd implementation
; ==================================================================================================

;##\

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

  SetObject xsi, ObjPropWnd
  m2m hHtmlFile, [xsi].hHtmlFile, xax
  ReleaseObject
  mov xsi, pMemberData
  lea xdi, dBytesWritten
  mov xbx, [xsi].MEMBERDATA.pMemberInfo               ;ebx -> OBJMTDINFORMATION
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
    ;Exit if dShowRedefMtds == FALSE
    mov xcx, pSelf
    .if [xcx].$Obj(ObjPropWnd).dShowRedefMtds == FALSE
      .ifBitClr [xsi].MEMBERDATA.dFlags, MDT_FINAL
        ret
      .endif
    .endif

    ;Get the method implementation info
    mov xdx, pSelf
    mov xcx, [xdx].$Obj(ObjPropWnd).pOwner           ;xcx -> ClientWnd
    mov xdx, [xcx].$Obj(ClientWnd).pOwner      ;xdx -> ObjectBrowser
    mov xcx, [xdx].$Obj(ObjectBrowser).pObjDB
    OCall [xcx].$Obj(OA_ObjDB).ImpMethodColl::Collection.FirstThatNot, offset MatchObjectImpMethod, \
                           [xbx].OBJMTDINFORMATION.pObjectName, [xbx].OBJMTDINFORMATION.pName
    mov pImpMtdInfo, xax

    ;Setup (+)/(-) button
    invoke WriteFile, hHtmlFile, offset HTML_OMD_01, HTML_OMD_01_SIZE, xdi, NULL
    lea xax, cBuffer
    mov word ptr [xax], "x0"
    add xax, 2
    invoke dword2hex, xax, ebx
    invoke WriteFile, hHtmlFile, offset HTML_OMD_02, HTML_OMD_02_SIZE, xdi, NULL
    invoke WriteFile, hHtmlFile, addr cBuffer, 10, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_03, HTML_OMD_03_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_SHOWDETAIL
      invoke WriteFile, hHtmlFile, offset HTML_HIDE, sizeof HTML_HIDE, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_SHOW, sizeof HTML_SHOW, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_OMD_04, HTML_OMD_04_SIZE, xdi, NULL

    ;Display object and method names
    invoke WriteFile, hHtmlFile, offset HTML_OMD_05, HTML_OMD_05_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke StrLength, [xbx].OBJMTDINFORMATION.pObjectName
    invoke WriteFile, hHtmlFile, [xbx].OBJMTDINFORMATION.pObjectName, eax, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_06, HTML_OMD_06_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_OPEN_BOLD, sizeof HTML_OPEN_BOLD, xdi, NULL
    .endif
    mov ecx, [xbx].OBJMTDINFORMATION.dFlags
    .if ecx == METHODTYPE_VIRTUAL_ABSTRACT || ecx == METHODTYPE_DYNAMIC_ABSTRACT
      invoke WriteFile, hHtmlFile, offset HTML_OPEN_ITALIC, sizeof HTML_OPEN_ITALIC, xdi, NULL
    .endif
    invoke StrLength, [xbx].OBJMTDINFORMATION.pName
    invoke WriteFile, hHtmlFile, [xbx].OBJMTDINFORMATION.pName, eax, xdi, NULL
    mov ecx, [xbx].OBJMTDINFORMATION.dFlags
    .if ecx == METHODTYPE_VIRTUAL_ABSTRACT || ecx == METHODTYPE_DYNAMIC_ABSTRACT
      invoke WriteFile, hHtmlFile, offset HTML_CLOSE_ITALIC, sizeof HTML_CLOSE_ITALIC, xdi, NULL
    .endif
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_CLOSE_BOLD, sizeof HTML_CLOSE_BOLD, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_07, HTML_OMD_07_SIZE, xdi, NULL

    ;Display method type
    invoke WriteFile, hHtmlFile, offset HTML_OMD_08, HTML_OMD_08_SIZE, xdi, NULL
    mov eax, [xbx].OBJMTDINFORMATION.dFlags
    .if eax == METHODTYPE_REDEFINED && [xsi].MEMBERDATA.pDefinition == NULL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
    .else
      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
      .endif
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    mov eax, [xbx].OBJMTDINFORMATION.dFlags
    .if eax != METHODTYPE_REDEFINED
      lea xcx, SOM_TEXT_TABLE
      mov xcx, POINTER ptr [xcx + sizeof(POINTER)*xax]
      mov pText, xcx
      invoke StrLength, xcx
      invoke WriteFile, hHtmlFile, pText, eax, xdi, NULL
    .else
      mov xdx, [xsi].MEMBERDATA.pDefinition
      .if xdx != NULL
        mov eax, [xdx].OBJMTDINFORMATION.dFlags
        lea xcx, SOM_TEXT_TABLE
        mov xcx, POINTER ptr [xcx + sizeof(POINTER)*xax]
        mov pText, xcx
        invoke StrLength, xcx
        invoke WriteFile, hHtmlFile, pText, eax, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_UNKNOWN, sizeof HTML_UNKNOWN, xdi, NULL
      .endif
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_10, HTML_OMD_10_SIZE, xdi, NULL

    ;Display Definition
    invoke WriteFile, hHtmlFile, offset HTML_OMD_08, HTML_OMD_08_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      .if pImpMtdInfo == NULL
        ;Draw in red also if it is abstract and final!
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      .endif
    .else
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
    .endif

    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    mov ecx, [xbx].OBJMTDINFORMATION.dFlags
    .if ecx ==  METHODTYPE_VIRTUAL_ABSTRACT || ecx == METHODTYPE_DYNAMIC_ABSTRACT
      invoke WriteFile, hHtmlFile, offset HTML_ABSTRACT, sizeof HTML_ABSTRACT, xdi, NULL
    .elseif pImpMtdInfo == NULL
      invoke WriteFile, hHtmlFile, offset HTML_UNKNOWN, sizeof HTML_UNKNOWN, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_REGULAR, sizeof HTML_REGULAR, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_10, HTML_OMD_10_SIZE, xdi, NULL

    ;Display method status
    invoke WriteFile, hHtmlFile, offset HTML_OMD_08, HTML_OMD_08_SIZE, xdi, NULL
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    .ifBitClr [xsi].MEMBERDATA.dFlags, MDT_FINAL
      mov ecx, DWORD ptr SOM_TEXT_TABLE[4*METHODTYPE_REDEFINED]
      mov pText, xcx
      invoke StrLength, xcx
      invoke WriteFile, hHtmlFile, pText, eax, xdi, NULL
    .else
      invoke WriteFile, hHtmlFile, offset HTML_REGULAR, sizeof HTML_REGULAR, xdi, NULL
    .endif
    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, hHtmlFile, offset HTML_OMD_10, HTML_OMD_10_SIZE, xdi, NULL

    ;Close row
    invoke WriteFile, hHtmlFile, offset HTML_OMD_11, HTML_OMD_11_SIZE, xdi, NULL

    ;Display method comments
    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_SHOWDETAIL
      invoke WriteFile, hHtmlFile, offset HTML_OMC_00, HTML_OMC_00_SIZE, xdi, NULL
      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      .else
        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
      .endif
      invoke WriteFile, hHtmlFile, offset bCRLF, 2, xdi, NULL
      mov xax, pImpMtdInfo
      .if xax != NULL
        mov xsi, [xax].IMPMTDINFORMATION.pHelpData
        .while xsi != NULL
          lea xdx, [xsi + sizeof(POINTER)]
          invoke EmitHtmlText, hHtmlFile, xdx
          invoke WriteFile, hHtmlFile, offset HTML_BREAK, sizeof HTML_BREAK, xdi, NULL
          invoke WriteFile, hHtmlFile, offset bCRLF, 2, xdi, NULL
          mov esi, [xsi]                              ;Move to next string
        .endw
      .else
        invoke WriteFile, hHtmlFile, offset HTML_NO_INFO, HTML_NO_INFO_SIZE, xdi, NULL
      .endif
      invoke WriteFile, hHtmlFile, offset HTML_OMC_01, HTML_OMC_01_SIZE, xdi, NULL
    .endif
  .endif
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

  SetObject xsi, ObjPropWnd
  m2m hHtmlFile, [xsi].hHtmlFile, xax
  ReleaseObject
  mov xsi, pMemberData
  lea xdi, dBytesWritten
  mov xbx, [xsi].MEMBERDATA.pMemberInfo               ;ebx -> OBJVARINFORMATION
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
      mov xcx, POINTER ptr SOM_TEXT_TABLE[sizeof(POINTER)*METHODTYPE_REDEFINED]
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

Method ObjPropWnd.EmitHtml, uses xbx xdi xsi
  local dBytesWritten:DWORD, cBuffer[MAX_PATH]:CHR, cHexAddr[12]:CHR
  local LastWriteTimeDef:FILETIME, LastWriteTimeAsm:FILETIME, LastWriteTimeLib:FILETIME
  local SysTimeUTC:SYSTEMTIME, SysTimeLocal:SYSTEMTIME, dLength:DWORD
  local dSecond:DWORD, dMinute:DWORD, dHour:DWORD, dYear:DWORD, dMonth:DWORD, dDay:DWORD

  SetObject xsi

  ;Reset file
  invoke SetFilePointer, [xsi].hHtmlFile, 0, NULL, FILE_BEGIN
  invoke SetEndOfFile, [xsi].hHtmlFile

  lea xdi, dBytesWritten
  mov xbx, [xsi].pInfo

  ;Start HTML document
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_00, HTML_DOC_00_SIZE, xdi, NULL
  mov dLength, $32($invoke(StrLength, [xbx].OBJECTINFORMATION.pName))
  invoke WriteFile, [xsi].hHtmlFile, [xbx].OBJECTINFORMATION.pName, eax, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_01, HTML_DOC_01_SIZE, xdi, NULL

  ;Show name
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_00, HTML_DSC_00_SIZE, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, [xbx].OBJECTINFORMATION.pName, dLength, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_01, HTML_DSC_01_SIZE, xdi, NULL

  ;Show description (if available)
  mov xbx, [xbx].OBJECTINFORMATION.pHelpData
  .if xbx != NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_02, HTML_DSC_02_SIZE, xdi, NULL
    .while xbx != NULL
      lea xdx, [xbx + sizeof(POINTER)]
      invoke EmitHtmlText, [xsi].hHtmlFile, xdx
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_BREAK, sizeof HTML_BREAK, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset bCRLF, 2, xdi, NULL
      mov xbx, [xbx]
    .endw
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_DSC_03, HTML_DSC_03_SIZE, xdi, NULL
  .endif

  ;Show inheritance path
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_00, HTML_INH_00_SIZE, xdi, NULL
  OCall xsi.ShowInheritance, [xsi].pInfo, FALSE
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_07, HTML_INH_07_SIZE, xdi, NULL

  ;Show file information
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_00, HTML_FLS_00_SIZE, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_01, HTML_FLS_01_SIZE, xdi, NULL

  lea xbx, cHexAddr
  mov word ptr [xbx], "x0"
  mov xdx, [xsi].pInfo
  add xbx, 2
  invoke xword2hex, xbx, [xdx].OBJECTINFORMATION.pFileInfo

  ;Show definition file
  lea xbx, cHexAddr
  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL;**************************************************
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_02, HTML_FLS_02_SIZE, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_03, HTML_FLS_03_SIZE, xdi, NULL
  mov xcx, [xsi].pInfo
  mov xdx, [xcx].OBJECTINFORMATION.pFileInfo
  mov xbx, [xdx].FILEINFORMATION.pFileName
  OutputFileInfo LastWriteTimeDef
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_06, HTML_FLS_06_SIZE, xdi, NULL

  ;Show asm file
  lea xbx, cHexAddr
  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_07, HTML_FLS_07_SIZE, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_08, HTML_FLS_08_SIZE, xdi, NULL

  mov xcx, [xsi].pInfo
  mov xax, [xcx].OBJECTINFORMATION.pFileInfo
  lea xbx, cBuffer
  invoke StrCopy, xbx, [xax].FILEINFORMATION.pFileName
  invoke StrRScan, xbx, "."
  .if xax == NULL
    invoke StrEnd, xbx
  .endif
  FillString [xax], <.asm>

  OutputFileInfo LastWriteTimeAsm
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_09, HTML_FLS_09_SIZE, xdi, NULL

  ;Show lib file
  lea xbx, cHexAddr
  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_10, HTML_FLS_10_SIZE, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, xbx, 10, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_11, HTML_FLS_11_SIZE, xdi, NULL

  mov xcx, [xsi].pInfo
  mov xax, [xcx].OBJECTINFORMATION.pFileInfo
  lea xbx, cBuffer
  invoke StrCopy, xbx, [xax].FILEINFORMATION.pFileName
  invoke StrRScan, xbx, "."
  .if xax == NULL
    invoke StrEnd, xbx
  .endif
  FillString [xax], <.lib>
  OutputFileInfo LastWriteTimeLib, 1
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_12, HTML_FLS_12_SIZE, xdi, NULL

  ;Show method information
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_OMD_00, HTML_OMD_00_SIZE, xdi, NULL
  OCall [xsi].Methods::DataCollection.ForEach, offset ShowObjMtd, xsi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_OMD_12, HTML_OMD_12_SIZE, xdi, NULL

  ;Show variable information
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_VAR_00, HTML_VAR_00_SIZE, xdi, NULL
  OCall [xsi].Variables::DataCollection.ForEach, offset ShowObjVar, xsi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_VAR_07, HTML_VAR_07_SIZE, xdi, NULL

  ;End HTML document
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_DOC_99, HTML_DOC_99_SIZE, xdi, NULL
MethodEnd

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
    mov xcx, [xsi].pOwner                             ;ecx -> ClientWnd
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
  mov xcx, [xsi].pOwner                               ;xcx -> ClientWnd
  mov xdx, [xcx].$Obj(ClientWnd).pOwner         ;xax -> ObjectBrowser
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
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_ANF_00, HTML_ANF_00_SIZE, xdi, NULL
      invoke StrLength, xbx
      invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_ANF_01, HTML_ANF_01_SIZE, xdi, NULL
    .endif
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_04, HTML_INH_04_SIZE, xdi, NULL
  .endif

  mov xcx, pObjectInfo
  mov xbx, [xcx].OBJECTINFORMATION.pName
  .if dLink != FALSE
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_01, HTML_INH_01_SIZE, xdi, NULL
    invoke xword2hex, addr cHexBuffer, pObjectInfo
    invoke WriteFile, [xsi].hHtmlFile, addr cHexBuffer, 8, xdi, NULL  ;****************************************************
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_02, HTML_INH_02_SIZE, xdi, NULL
    invoke StrLength, xbx
    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_03, HTML_INH_03_SIZE, xdi, NULL

  .else
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_05, HTML_INH_05_SIZE, xdi, NULL
    invoke StrLength, xbx
    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_06, HTML_INH_06_SIZE, xdi, NULL
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
  m2m WC.lpfnWndProc, $MethodAddr(ObjPropWnd.WndProc), edx
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, edx
  mov WC.hbrBackground, 0
  mov WC.lpszMenuName, NULL
  m2m WC.lpszClassName, offset cObjPropClass, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_OBJ_STD"))
  mov WC.hIconSm, 0
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd

;##/

; ==================================================================================================
;    SetupDlg implementation
; ==================================================================================================

;##\

SetCtrlText macro ControlID, TextID
  lea edx, [ebx + TextID]
  invoke LoadString, hInstance, edx, xdi, lengthof(cBuffer) - 1
  invoke SetDlgItemText, [xsi].hWnd, ControlID, xdi
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SetupDlg.CtlsGet
; Purpose:    Reads the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method SetupDlg.CtlsGet, uses xbx xdi xsi
  local hWnd:HWND

  SetObject xsi
  mov xdi, [xsi].pOwner
  invoke StrDispose, [xdi].$Obj(ObjectBrowser).pViewerApp
  mov hWnd, $invoke(GetDlgItem, [xsi].hWnd, IDC_SETUP_VIEWER_EDIT)
  mov ebx, $32($invoke(GetWindowTextLength, xax))
  mov [xdi].$Obj(ObjectBrowser).pViewerApp, $invoke(StrAlloc, ebx)
  inc ebx
  invoke GetWindowText, hWnd, xax, ebx

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_SETUP_PROP_CHK_MTD
  mov [xdi].$Obj(ObjectBrowser).dShowRedefMtds, eax
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_SETUP_PROP_CHK_VAR
  mov [xdi].$Obj(ObjectBrowser).dShowRedefVars, eax

  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SetupDlg.CtlsSet
; Purpose:    Sets the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = TRUE to direct Windows to set the keyboard focus. Otherwise FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method SetupDlg.CtlsSet, uses xbx xdi xsi
  local cBuffer[1024]:CHR

  SetObject xsi

  ;Set caption and control strings
  mov xcx, [xsi].pOwner
  mov ebx, [xcx].$Obj(ObjectBrowser).dLanguage
  lea xdi, cBuffer

  lea edx, [ebx + IDS_SETUP_CAPTION]
  invoke LoadString, hInstance, edx, xdi, lengthof(cBuffer) - 1
  invoke SetWindowText, [xsi].hWnd, xdi
  SetCtrlText IDC_SETUP_VIEWER_GRP,   IDS_SETUP_VIEWER_GRP
  SetCtrlText IDC_SETUP_VIEWER_STC,   IDS_SETUP_VIEWER_APP
  SetCtrlText IDC_SETUP_VIEWER_TEXT,  IDS_SETUP_VIEWER_TEXT
  SetCtrlText IDC_SETUP_PROP_GRP,     IDS_SETUP_PROP_GRP
  SetCtrlText IDC_SETUP_PROP_CHK_MTD, IDS_SETUP_PROP_CHK_MTD
  SetCtrlText IDC_SETUP_PROP_CHK_VAR, IDS_SETUP_PROP_CHK_VAR
  SetCtrlText IDOK, IDS_SETUP_OK
  SetCtrlText IDCANCEL, IDS_SETUP_CANCEL

  ;Set control values
  mov xdi, [xsi].pOwner
  assume xdi:$ObjPtr(ObjectBrowser)
  invoke SetDlgItemText, [xsi].hWnd, IDC_SETUP_VIEWER_EDIT,  [xdi].pViewerApp
  invoke CheckDlgButton, [xsi].hWnd, IDC_SETUP_PROP_CHK_MTD, [xdi].dShowRedefMtds
  invoke CheckDlgButton, [xsi].hWnd, IDC_SETUP_PROP_CHK_VAR, [xdi].dShowRedefVars
  assume xdi:nothing

  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SetupDlg.Init
; Purpose:    Initialaizes a dialog.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window handle.
; Return:     Nothing.

Method SetupDlg.Init,, pOwner:POINTER, hParentWnd:HANDLE
  SetObject xcx
  ACall xcx.Init, pOwner, hParentWnd, IDD_SETUP_DLG
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SetupDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method SetupDlg.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local OpenFileName:OPENFILENAME, cInitDir[MAX_PATH]:CHR, cFileName[MAX_PATH]:CHR
  local cBuffer[1024]:CHR

  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDC_SETUP_VIEWER_BTN
    lea xdi, cInitDir
    invoke GetDlgItemText, [xsi].hWnd, IDC_SETUP_VIEWER_EDIT, xdi, lengthof(cInitDir) - 1

    mov OpenFileName.lStructSize, sizeof OPENFILENAME
    m2m OpenFileName.hwndOwner, [xsi].hWnd, xax
    m2m OpenFileName.hInstance, hInstance, xax
    mov OpenFileName.lpstrFilter, NULL
    mov OpenFileName.lpstrCustomFilter, NULL
    mov OpenFileName.nMaxCustFilter, 0
    mov OpenFileName.nFilterIndex, 0
    lea xax, cFileName
    mov CHR ptr [xax], 0
    mov OpenFileName.lpstrFile, xax
    mov OpenFileName.nMaxFile, lengthof(cFileName) - 1
    mov OpenFileName.lpstrFileTitle, NULL
    mov OpenFileName.nMaxFileTitle, 0
    lea xax, cInitDir
    mov OpenFileName.lpstrInitialDir, xax
    mov xax, [xsi].pOwner
    mov ecx, [xax].$Obj(ObjectBrowser).dLanguage
    lea edx, [ecx + IDS_SELECT]
    lea xax, cBuffer
    mov OpenFileName.lpstrTitle, xax
    invoke LoadString, hInstance, edx, xax, lengthof(cBuffer) - 1
    mov OpenFileName.lpstrDefExt, NULL
    mov OpenFileName.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES or OFN_HIDEREADONLY
    invoke GetOpenFileName, addr OpenFileName

    .if eax != 0
      invoke SetDlgItemText, [xsi].hWnd, IDC_SETUP_VIEWER_EDIT, addr cFileName
    .endif
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     SetupDlg.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method SetupDlg.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd


;##/

; ==================================================================================================
;    FindInfoDlg implementation
; ==================================================================================================

;##\

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindInfoDlg.CtlsSet
; Purpose:    Sets the controls of the dialog.
; Arguments:  None.
; Return:     eax = TRUE to direct Windows to set the keyboard focus. Otherwise FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method FindInfoDlg.CtlsSet, uses xbx xdi xsi
  local cBuffer[1024]:CHR

  SetObject xsi

  ;Set caption and control strings
  mov xcx, [xsi].pOwner
  mov ebx, [xcx].$Obj(ObjectBrowser).dLanguage
  lea xdi, cBuffer

  lea edx, [ebx + IDS_FIND_CAPTION]
  invoke LoadString, hInstance, edx, xdi, lengthof(cBuffer) - 1
  invoke SetWindowText, [xsi].hWnd, xdi

  invoke CheckRadioButton, [xsi].hWnd, IDC_FIND_RBN_OBJ, IDC_FIND_RBN_INT, IDC_FIND_RBN_OBJ

  SetCtrlText IDC_FIND_BTN_GO, IDS_FIND_GO
  SetCtrlText IDC_FIND_RBN_OBJ, IDS_FIND_OBJ
  SetCtrlText IDC_FIND_RBN_INT, IDS_FIND_INT

  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:   	FindInfoDlg.Init
; Purpose:  	Initializes a Dialog object.
; Arguments:	Arg1: -> Owner object.
;           	Arg2: Parent window handle.
; Return:   	Nothing.

Method FindInfoDlg.Init, uses xsi, pOwner:POINTER, hParent:HANDLE
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, IDD_FIND_DLG
  ;We create here the Modeless Dialog but without showing it. WS_VISIBLE must not be set!
  invoke CreateDialogParam, hInstance, [xsi].pTemplate, [xsi].hParent, \
                            $MethodAddr(FindInfoDlg.DlgProc), xsi   ;lParam passed WM_INITDIALOG
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindInfoDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method FindInfoDlg.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  .if ([xsi].StartPos.x != -1) || ([xsi].StartPos.y != -1)
    ;Check if the dialog will be fully visible
    invoke MoveWindowVisible, [xsi].hWnd, [xsi].StartPos.x, [xsi].StartPos.y
  .endif

  invoke SetFocus, $invoke(GetDlgItem, [xsi].hWnd, IDC_FIND_EDIT)
  OCall xsi.CtlsSet

  invoke SetForegroundWindow, [xsi].hWnd
  xor eax, eax                                 ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  InfoMatch
; Purpose:    Used to filter out not matching strings from the ListBox content.
; Arguments:  Arg1: -> INFORMATION.
;             Arg2: -> Filter string.
;             Arg3: ListBox handle.
; Return:     Nothing.

InfoMatch proc pItem:PINFORMATION, pFilter:PSTRING, hListBox:HANDLE
  mov xcx, pItem
  invoke StrIFilter, [xcx].INFORMATION.pName, pFilter
  .if eax != FALSE
    mov xax, pItem
    invoke SendMessage, hListBox, LB_ADDSTRING, 0, [xax].INFORMATION.pName
  .endif
  ret
InfoMatch endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindInfoDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FindInfoDlg.OnCommand, uses xdi xbx xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

  SetObject xsi
  mov xax, wParam
  .if (ax == IDC_FIND_BTN_GO) || (ax == IDOK) || \
      (ax == IDC_FIND_RBN_OBJ) || (ax == IDC_FIND_RBN_INT)
    lea xdi, cBuffer
    invoke GetDlgItem, [xsi].hWnd, IDC_FIND_EDIT
    invoke GetWindowText, xax, xdi, lengthof(cBuffer) - 1
    invoke StrLRTrim, xdi, xdi
    mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_FIND_LISTBOX)
    invoke LockWindowUpdate, xbx
    invoke SendMessage, xbx, LB_RESETCONTENT, 0, 0
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_FIND_RBN_OBJ
    mov xdx, [xsi].pOwner
    mov xcx, [xdx].$Obj(ObjectBrowser).pObjDB
    .if eax != FALSE
      OCall [xcx].$Obj(OA_ObjDB).ObjectColl::ObjInfoCollection.ForEach, offset InfoMatch, xdi, xbx
    .else
      OCall [xcx].$Obj(OA_ObjDB).InterfaceColl::IntInfoCollection.ForEach, offset InfoMatch, xdi, xbx
    .endif
    invoke LockWindowUpdate, 0
    xor eax, eax

  .elseif ax == IDCANCEL
    invoke ShowWindow, [xsi].hWnd, SW_HIDE
    xor eax, eax

  .elseif ax == IDC_FIND_RBN_OBJ

  .else
    shr eax, 16
    .if ax == LBN_DBLCLK
      mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_FIND_LISTBOX)
      invoke SendMessage, xbx, LB_GETCURSEL, 0, 0
      lea xdi, cBuffer
      invoke SendMessage, xbx, LB_GETTEXT, eax, xdi
      invoke IsDlgButtonChecked, [xsi].hWnd, IDC_FIND_RBN_OBJ
      .if eax != FALSE
        OCall [xsi].pOwner::ObjectBrowser.Navigate, xdi, INFO_TYPE_OBJECT
      .else
        OCall [xsi].pOwner::ObjectBrowser.Navigate, xdi, INFO_TYPE_INTERFACE
      .endif
      xor eax, eax
    .else
      xor eax, eax
      inc eax
    .endif

  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindInfoDlg.OnActivate
; Purpose:    Event procedure for WM_ACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method FindInfoDlg.OnActivate,, wParam:WPARAM, lParam:LPARAM
  xor eax, eax
MethodEnd

;##/

endif