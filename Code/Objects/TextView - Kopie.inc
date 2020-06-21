; ==================================================================================================
; Title:      TextView.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of TextView objects.
;             It displays formatted text using styles like font, color, background, etc. and
;             control commands using a MASM friendly markup string.
; Notes:      Version C.1.1, April 2020
;               - First release.
; Links:      https://docs.microsoft.com/en-us/windows/win32/gdi/string-widths-and-heights
;             https://codepundit.wordpress.com/2012/04/14/text-metrics-wow/
;             https://docs.microsoft.com/de-ch/windows/win32/gdi/drawing-text-from-different-fonts-on-the-same-line
; ==================================================================================================


; Markup specification:
;
; Styles: a series of markup identifiers enclosed in square brackets [] and separated by commas.
;         A value can follow each identifier. For some identifiers, the value is a decimal number
;         or a hex value. Hex values are specified prepending a # character.
;         If an identifier expects a value but it is missing, the control's default is used instead.
;         Each defined style is pushed onto a stack and popped using [~].
;         Markup identifiers are not case sensitive.
;
;     Style identifier: (00 stands for a number)
;         Verbose           Short   Description
;         ALIGN XXX           A     Left, Center, Right
;         APP 00                    Active area: notifies the control parent on mouse events.
;         BGCOLOR #000000     G     Text background color as a RGB hex value.
;         BOLD                B     Bold style.
;         BOX #000000         X     Box with background color as RGB hex value.
;         COLOR #000000       C     Text foreground color as a RGB hex value.
;         FONT 'Font Name'    F     Font face.
;         HANGING 000         HI    Set hanging text indentation.
;         HEIGHT 00           H     Font size in logical units. If + or - is prepended, then the
;                                   value is relative to the previous setting.
;         INDENT 000          FI    Set first text indentation.
;         INFO 000                  Request text information from
;         ITALIC              I     Italic style.
;         STRIKEOUT           O     Strike out style.
;         SUB                       Subscript.
;         SUP                       Superscript.
;         UNDERLINE           U     Underlined.
;
;
;     Example: [FONT 'Segoe UI', SIZE 12, COLOR #7F7F7F, BGCOLOR #000000]
;
;
; Commands: a single markup identifier enclosed in curly brackets {}.
;           Command markup identifiers are not case sensitive.
;
;     Command identifier:
;         Verbose           Short   Description
;         #00                       Insert a (unicode) character in hex. E.g.: {#5B} displays a [.
;         BREAK               B     Line break.
;         COVER               C     Perfom an action by the parent at the end of the rendering process.
;         DRAW                D     Perfom an action by the parent window.
;         PADDING 000        P.A    Set all padding values
;         PADDING.BOTTOM 000 P.B    Set bottom marign
;         PADDING.LEFT 000   P.L    Set left margin
;         PADDING.RIGHT 000  P.R    Set right margin
;         PADDING.TOP 000    P.T    Set top margin
;         PARA                P     Paragraph.
;         TAB                 T     Perform a tab.
;         TABL 00            T.L    Set a left tabstop.
;         TABC 00            T.C    Set a center tabstop.
;         TABR 00            T.R    Set a right tabstop.
;         TABCLR                    Reset all tabstops.
;         SIZE.X 000         S.X    Set MemBitmap width.
;         SIZE.Y 000         S.Y    Set MemBitmap heigth.
;
;     Example: {BREAK}
;
;
;
; Supported styles:
; TV_WORDBREAK:      Breaks words. Lines are automatically broken between words if a word would
;                    extend past the edge of the rectangle specified by the lpRect parameter.
;
; ****************** NOT IMPLEMENTED YET *******************
; TV_RTLREADING:     Not implemented.
; TV_SINGLELINE:     Displays text on a single line only. Carriage returns and line feeds do not
;                    break the line.
; TV_PATH_ELLIPSIS:  Replaces characters in the middle of the string with ellipses so that the
;                    result fits in the specified rectangle. If the string contains backslash (\)
;                    characters, TV_PATH_ELLIPSIS preserves as much as possible of the text after
;                    the last backslash.
; TV_WORD_ELLIPSIS:  If the end of a string does not fit in the rectangle, it is truncated and
;                    ellipses are added.
;
; Design notes:
;  - Tab characters are different from {TAB} commands. Tab characters (ASCII 9) are expanded to
;    spaces using the dTab2Spaces (usually = 8) value.
;  - The APP style sends a notification to the parent window to perform an action, like an
;    hyperlink or any another task.
;  - The INFO style sends a notification to the parent window to get information that can be
;    displayed using a Tooltip.
;  - The DRAW command sends a notification to the parent window to perform a drawing operation
;    once all other text related drawing tasks are finished. This ensures that the control
;    background is completely drawn before the drawing operation is started.

externdef TVCH_SIZE_X:NEAR
externdef TVCH_SIZE_Y:NEAR

DEF_TEXTVIEW struc
  xCtlID            XWORD       ?         ;Contol ID
  dStyle            DWORD       ?         ;Style
  dExStyle          DWORD       ?         ;Extended style
  pText             PSTRING     ?         ;-> Window text passed as the window caption
  sdPosX            SDWORD      ?         ;X position
  sdPosY            SDWORD      ?         ;Y position
  dWidth            DWORD       ?         ;Width
  dHeight           DWORD       ?         ;Height
DEF_TEXTVIEW ends
PDEF_TEXTVIEW typedef ptr DEF_TEXTVIEW

TV_WORDBREAK    equ   BIT00

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     TextView
; Purpose:    Provide a control that displays formatted text using styles like font, color,
;             background, etc. and control commands using a MASM friendly markup string.

Object TextView, TextViewID, Window
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PDEF_TEXTVIEW
  StaticMethod      GetActiveArea,      POINTS
  DynamicMethod     GetExtent
  StaticMethod      GetNextTabStop,     DWORD
  StaticMethod      GetNextTextOrTab,   DWORD
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      Parse
  StaticMethod      Render
  StaticMethod      Reset
  StaticMethod      Show
  StaticMethod      Startup
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnButtonDown,       WM_LBUTTONDOWN, WM_MBUTTONDOWN, WM_RBUTTONDOWN
  VirtualEvent      OnButtonUp,         WM_LBUTTONUP, WM_MBUTTONUP, WM_RBUTTONUP
  VirtualEvent      OnCommand,          WM_COMMAND, WM_NOTIFY  ;Parent forwarded
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnCtlColorStatic,   WM_CTLCOLORSTATIC
  VirtualEvent      OnGetFont,          WM_GETFONT
  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE
  VirtualEvent      OnPaint,            WM_PAINT
  VirtualEvent      OnSetFont,          WM_SETFONT
  VirtualEvent      OnSetText,          WM_SETTEXT
  VirtualEvent      OnHScroll,          WM_HSCROLL 
  VirtualEvent      OnVScroll,          WM_VSCROLL


  DefineVariable    pMarkupText,        PSTRING,    NULL
  DefineVariable    dFlags,             DWORD,      0     ;Ressource creation?
  DefineVariable    hParent,            HWND,       0
  DefineVariable    hMemDC,             HDC,        0     ;Memory DC
  DefineVariable    hMemBmp,            HBITMAP,    0     ;Memory DC bitmap
  DefineVariable    hPrvBmp,            HBITMAP,    0     ;Previous hMemDC bitmap
  DefineVariable    hPrvBrush,          HBRUSH,     0     ;Previous hMemDC brush
  DefineVariable    hPrvFont,           HFONT,      0     ;Previous hMemDC font
  DefineVariable    Extent,             POINT,      {}    ;Size of the complete drawing area
  DefineVariable    Origin,             POINT,      {}    ;Coordinates of the left/top visible corner
  DefineVariable    Padding,            RECT,       {}    ;None drawable borders
  DefineVariable    dFormatFlags,       DWORD,      0     ;See "Supported styles" above
  DefineVariable    dLogPixY,           DWORD,      0

  DefineVariable    DefaultTextColor,   RGBQUAD,    {}    ;B,G,R,0
  DefineVariable    DefaultBackColor,   RGBQUAD,    {}    ;B,G,R,0
  DefineVariable    pDefaultFontFace,   PSTRING,    NULL
  DefineVariable    dDefaultFontSize,   DWORD,      10
  DefineVariable    dTab2Spaces,        DWORD,      8     ;Default value
  DefineVariable    hToolTip,           HWND,       0

  Embed    Entries,       DataCollection
  Embed    ActiveAreas,   DataCollection
  Embed    Styles,        DataCollection
  Embed    StyleStack,    XWCollection
  Embed    TabStops,      SortedDataCollection
  Embed    GdiObjects,    XWCollection
  Embed    CoverTasks,    DataCollection

ObjectEnd


; ==================================================================================================

TVSTYLE struc
  dFlags        DWORD       ?             ;Style flags TVSF_xxx
  TextColor     RGBQUAD     {}
  BackColor     RGBQUAD     {}
  BoxColor      RGBQUAD     {}
  dAlignment    DWORD       ?             ;TVALIGN_xxx
  dIndent       DWORD       ?             ;First text indent
  dHanging      DWORD       ?             ;Hanging text indent
  dFontSize     DWORD       ?             ;Font size in logical units
  hFont         HFONT       ?             ;Font HANDLE
  LogFont       LOGFONT     {}
  TextMetric    TEXTMETRIC  {}
  hBackBrush    HBRUSH      ?             ;Background brush HANDLE
  dID           DWORD       ?             ;APP/INFO/DRAW ID
TVSTYLE ends
PTVSTYLE typedef ptr TVSTYLE

TVENTRY struc
  dType         DWORD       ?             ;TVET_xxx
  Area          RECT        {}            ;Position on the client area
  Extent        RECT        {}            ;Size of the area, left and top members are always zero
  pStyle        PTVSTYLE    ?             ;-> TVSTYLE
  dCharCount    DWORD       ?             ;# of characters in pText. Needed to convert tabs to " "
  pText         PSTRING     ?             ;-> zero terminated string
  pHandler      POINTER     ?             ;Command proc, executed before drawing
  dValue        DWORD       ?             ;Command parameter
TVENTRY ends
PTVENTRY typedef ptr TVENTRY


if IMPLEMENT

%CStr cTextViewClass&TARGET_STR_AFFIX, "TextView"

TVStyleHandler typedef proto :POINTER
PTVStyleHandler typedef ptr TVStyleHandler

;TextView Window Flag
TVWF_AUTO       equ   BIT00

TVTAG_STYLE_OPEN    equ   "["               ;{#5B}
TVTAG_STYLE_CLOSE   equ   "]"
TVTAG_CMD_OPEN      equ   "{"               ;{#7B}
TVTAG_CMD_CLOSE     equ   "}"

;TVENTRY type
TVET_TEXT           equ   1
TVET_BLANK          equ   2
TVET_CMD            equ   3

;TVSTYLE flags
TVSF_SUP            equ   BIT00
TVSF_SUB            equ   BIT01
TVSF_ACTIVE         equ   BIT02
TVSF_INFO           equ   BIT03
TVSF_INCR           equ   BIT04             ;"+" sign detected
TVSF_DECR           equ   BIT05             ;"-" sign detected
TVSF_BOX            equ   BIT06

;TVSTYLE change flag
TVSC_NOTHING        equ   0
TVSC_FONT           equ   BIT00
TVSC_BACKCOLOR      equ   BIT01

;TextView Alignment
TVALIGN_LEFT        equ   0
TVALIGN_CENTER      equ   1
TVALIGN_RIGHT       equ   2

;TABSTOP types
TVTAB_TYPE_LEFT     equ   0
TVTAB_TYPE_CENTER   equ   1
TVTAB_TYPE_RIGHT    equ   2

;TVNM_XX.NMHDR.code values
TVNMC_APP_MOUSEOVER equ   1
TVNMC_APP_MOUSEDOWN equ   2
TVNMC_APP_MOUSEUP   equ   3
TVNMC_INFO          equ   4
TVNMC_DRAW          equ   5

TVNM_APP struc
  Header        NMHDR     <>
  dID           DWORD     ?
  dButton       DWORD     ?
TVNM_APP ends

TVNM_INFO struc
  Header        NMHDR     <>
  dID           DWORD     ?
  pText         PSTRING   ?
TVNM_INFO ends

TVNM_DRAW struc
  Header        NMHDR     <>
  dID           DWORD     ?
  hDC           HDC       ?
  Position      POINT     <>
  dLineHeight   DWORD     ?
  Extent        POINT     <>
  Padding       RECT      <>
  pStyle        PTVSTYLE  ?
TVNM_DRAW ends

TVTABSTOP struc
  dPosition     DWORD     ?
  bType         BYTE      ?
TVTABSTOP ends
PVTABSTOP typedef ptr TVTABSTOP

TVTAG struc
  dLength       DWORD     ?               ;Mnemonic length
  pMnemonic     PSTRING   ?               ;-> Mnemonic string (without brackets etc.)
  pHandler      POINTER   ?
TVTAG ends
PTVTAG typedef ptr TVTAG


;Note: keep the TVTGAs ordered by ascending length order and then in ascending Mnemonic order!
;      Otherwise the Mnemonics could not be found.

.const
TVTAG_STYLES label TVTAG
  TVTAG <01, $OfsTStr("A"),               TVSH_ALIGN      >   ;Align
  TVTAG <01, $OfsTStr("B"),               TVSH_BOLD       >   ;Bold
  TVTAG <01, $OfsTStr("C"),               TVSH_COLOR      >   ;Text color
  TVTAG <01, $OfsTStr("F"),               TVSH_FONT       >   ;Font
  TVTAG <01, $OfsTStr("G"),               TVSH_BGCOLOR    >   ;Background color
  TVTAG <01, $OfsTStr("H"),               TVSH_HEIGHT     >   ;Font height
  TVTAG <01, $OfsTStr("I"),               TVSH_ITALIC     >   ;Italic
  TVTAG <01, $OfsTStr("O"),               TVSH_STRIKEOUT  >   ;Strikeout
  TVTAG <01, $OfsTStr("U"),               TVSH_UNDERLINE  >   ;Underline
  TVTAG <01, $OfsTStr("X"),               TVSH_BOX        >   ;Boxed
  TVTAG <02, $OfsTStr("FI"),              TVSH_INDENT     >   ;First indent
  TVTAG <02, $OfsTStr("HI"),              TVSH_HANGING    >   ;Hanging indent
  TVTAG <03, $OfsTStr("APP"),             TVSH_APP        >   ;Application notification
  TVTAG <03, $OfsTStr("BOX"),             TVSH_BOX        >   ;Boxed
  TVTAG <03, $OfsTStr("SUB"),             TVSH_SUB        >   ;Subscript
  TVTAG <03, $OfsTStr("SUP"),             TVSH_SUP        >   ;Superscript
  TVTAG <04, $OfsTStr("BOLD"),            TVSH_BOLD       >   ;Bold
  TVTAG <04, $OfsTStr("FONT"),            TVSH_FONT       >   ;Font
  TVTAG <04, $OfsTStr("INFO"),            TVSH_INFO       >   ;Information callback
  TVTAG <05, $OfsTStr("ALIGN"),           TVSH_ALIGN      >   ;Align
  TVTAG <05, $OfsTStr("COLOR"),           TVSH_COLOR      >   ;Text color
  TVTAG <06, $OfsTStr("HEIGHT"),          TVSH_HEIGHT     >   ;Font height
  TVTAG <06, $OfsTStr("INDENT"),          TVSH_INDENT     >   ;First indent
  TVTAG <06, $OfsTStr("ITALIC"),          TVSH_ITALIC     >   ;Italic
  TVTAG <07, $OfsTStr("BGCOLOR"),         TVSH_BGCOLOR    >   ;Background color
  TVTAG <07, $OfsTStr("HANGING"),         TVSH_HANGING    >   ;Hanging indent
  TVTAG <09, $OfsTStr("STRIKEOUT"),       TVSH_STRIKEOUT  >   ;Strikeout
  TVTAG <09, $OfsTStr("UNDERLINE"),       TVSH_UNDERLINE  >   ;Underline
  TVTAG <>                                                    ;Last TVTAG

TVTAG_CMDS label TVTAG
  TVTAG <01, $OfsTStr("B"),               TVCH_BREAK      >   ;Line Break (soft break)
  TVTAG <01, $OfsTStr("C"),               TVCH_COVER      >   ;Draw the foreground
  TVTAG <01, $OfsTStr("D"),               TVCH_DRAW       >   ;Draw the background
  TVTAG <01, $OfsTStr("P"),               TVCH_PARA       >   ;Paragraph
  TVTAG <01, $OfsTStr("T"),               TVCH_TAB        >   ;Perform a Tabstop
  TVTAG <03, $OfsTStr("P.A"),             TVCH_PADDING    >   ;Set all paddings
  TVTAG <03, $OfsTStr("P.B"),             TVCH_PADDINGBOT >   ;Set bottom padding
  TVTAG <03, $OfsTStr("P.L"),             TVCH_PADDINGLFT >   ;Set left padding
  TVTAG <03, $OfsTStr("P.R"),             TVCH_PADDINGRGT >   ;Set right padding
  TVTAG <03, $OfsTStr("P.T"),             TVCH_PADDINGTOP >   ;Set top padding
  TVTAG <03, $OfsTStr("S.X"),             TVCH_SIZE_X     >   ;Set draw area width
  TVTAG <03, $OfsTStr("S.Y"),             TVCH_SIZE_Y     >   ;Set draw area height
  TVTAG <03, $OfsTStr("T.C"),             TVCH_TABC       >   ;Set center Tabstop
  TVTAG <03, $OfsTStr("T.L"),             TVCH_TABL       >   ;Set left Tabstop
  TVTAG <03, $OfsTStr("T.R"),             TVCH_TABR       >   ;Set right Tabstop
  TVTAG <03, $OfsTStr("TAB"),             TVCH_TAB        >   ;Perform a Tabstop
  TVTAG <04, $OfsTStr("DRAW"),            TVCH_DRAW       >   ;Regular draw
  TVTAG <04, $OfsTStr("LINE"),            TVCH_LINE       >   ;Horizontal line
  TVTAG <04, $OfsTStr("PARA"),            TVCH_PARA       >   ;Paragraph
  TVTAG <04, $OfsTStr("TABC"),            TVCH_TABC       >   ;Set center Tabstop
  TVTAG <04, $OfsTStr("TABL"),            TVCH_TABL       >   ;Set left Tabstop
  TVTAG <04, $OfsTStr("TABR"),            TVCH_TABR       >   ;Set right Tabstop
  TVTAG <05, $OfsTStr("BREAK"),           TVCH_BREAK      >   ;Line break (soft break)
  TVTAG <05, $OfsTStr("COVER"),           TVCH_COVER      >   ;Cover drawing
  TVTAG <06, $OfsTStr("SIZE.X"),          TVCH_SIZE_X     >   ;Set draw area width
  TVTAG <06, $OfsTStr("SIZE.Y"),          TVCH_SIZE_Y     >   ;Set draw area height
  TVTAG <06, $OfsTStr("TABCLR"),          TVCH_TABCLR     >   ;Reset all tabstops
  TVTAG <07, $OfsTStr("PADDING"),         TVCH_PADDING    >   ;Set all paddings
  TVTAG <11, $OfsTStr("PADDING.TOP"),     TVCH_PADDINGTOP >   ;Set top padding
  TVTAG <12, $OfsTStr("PADDING.LEFT"),    TVCH_PADDINGLFT >   ;Set left padding
  TVTAG <13, $OfsTStr("PADDING.RIGHT"),   TVCH_PADDINGRGT >   ;Set right padding
  TVTAG <14, $OfsTStr("PADDING.BOTTOM"),  TVCH_PADDINGBOT >   ;Set bottom padding
  TVTAG <>                                                    ;Last TVTAG

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     GdiObjects.DestroyItem
; Purpose:    Auxiliar function to release a GDI Object from the collection.
; Arguments:  Arg1: Object HANDLE.
; Return:     Nothing.

Method GdiObjects.DestroyItem,, hObject:HANDLE
  .if hObject != 0
    invoke DeleteObject, hObject
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Entries.DestroyItem
; Purpose:    Auxiliar function to release the string from the collection.
; Arguments:  Arg1: -> hFont.
; Return:     Nothing.

Method Entries.DestroyItem,, pItem:POINTER
  .if pItem != NULL
    mov xcx, pItem
    invoke StrDispose, [xcx].TVENTRY.pText             ;Safe if pString = NULL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TabStops.Compare
; Purpose:    Comparison of VTABSTOPs.
; Arguments:  Arg1: -> TVTABSTOP 1
;             Arg2: -> TVTABSTOP 2
; Return:     eax: Comparison result.

Method TabStops.Compare,, pItem1:PVTABSTOP, pItem2:PVTABSTOP
  ?mov xdx, pItem1
  mov xcx, pItem2
  mov eax, [xdx].TVTABSTOP.dPosition
  sub eax, [xcx].TVTABSTOP.dPosition
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method TextView.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Done
; Purpose:    Finalize the Button object.
; Arguments:  None.
; Return:     Nothing.

Method TextView.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pMarkupText

  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvBmp
  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvBrush
  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvFont
  invoke DeleteDC, [xsi].hMemDC

  OCall [xsi].CoverTasks::DataCollection.Done
  OCall [xsi].GdiObjects::XWCollection.Done
  OCall [xsi].TabStops::DataCollection.Done
  OCall [xsi].ActiveAreas::DataCollection.Done
  OCall [xsi].StyleStack::XWCollection.Done
  OCall [xsi].Styles::DataCollection.Done
  OCall [xsi].Entries::DataCollection.Done

  invoke DestroyWindow, [xsi].hToolTip

  invoke SetWindowLong, [xsi].hWnd, GWL_USERDATA, NULL

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.GetActiveArea
; Purpose:    Return the active ViewArea under the mouse pointer.
; Arguments:  Arg1: -> POINT (mouse coordinates in client space).
; Return:     xax -> ViewArea or NULL.

Method TextView.GetActiveArea, uses xbx xdi xsi, Point:POINTS
  local MouseClientPos:POINT

  SetObject xsi
  xor ebx, ebx
  PntS2Pnt MouseClientPos, Point                        ;Uses eax
  xor eax, eax
  .while ebx != [xsi].ActiveAreas.dCount
    mov xdi, $OCall([xsi].ActiveAreas::DataCollection.ItemAt, ebx)
    invoke PtInRect, addr [xax].TVENTRY.Area, MouseClientPos
    .if eax != FALSE
      mov xax, xdi
      .break
    .endif
    add ebx, 1
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.GetExtent
; Purpose:    Return the Extent after evaluation of SIZE commands.
; Arguments:  None.
; Return:     eax = TRUE if the extent has changed, otherwise FALSE.

Method TextView.GetExtent, uses xbx xdi xsi
  local NewExtent:POINT, dHasChanged:DWORD

  SetObject xsi
  mov dHasChanged, FALSE
  s2s NewExtent, [xsi].Extent, xax, xcx, xmm0, xmm1, xmm2
  .for (ebx = 0 : ebx != [xsi].Entries.dCount: ebx++)
    mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, ebx)
    mov xax, [xdi].TVENTRY.pHandler
    mov xcx, offset(TVCH_SIZE_X)
    .if xax == xcx
      m2m NewExtent.x, [xdi].TVENTRY.dValue, ecx
      mov dHasChanged, TRUE
    .else
      mov xcx, offset(TVCH_SIZE_Y)
      .if xax == xcx
        m2m NewExtent.y, [xdi].TVENTRY.dValue, ecx
        mov dHasChanged, TRUE
      .endif
    .endif
  .endfor

  xor eax, eax
  .if dHasChanged != FALSE
    mov ecx, NewExtent.x
    mov edx, NewExtent.y
    .if ecx != [xsi].Extent.x
      mov [xsi].Extent.x, ecx
      mov eax, TRUE
    .endif
    .if edx != [xsi].Extent.y
      mov [xsi].Extent.y, edx
      mov eax, TRUE
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.GetNextTabStop
; Purpose:    Return the next TVTABSTOP after a given x position.
; Arguments:  Arg1: x position
; Return:     xax -> TVTABSTOP or NULL.

Method TextView.GetNextTabStop, uses xsi, dPosX:DWORD
  local TVTabStop:TVTABSTOP

  SetObject xsi
  m2m TVTabStop.dPosition, dPosX, eax
  OCall [xsi].TabStops::SortedDataCollection.Search, addr TVTabStop
  .if ecx != [xsi].TabStops.dCount
    mov edx, ecx
    OCall [xsi].TabStops::SortedDataCollection.ItemAt, edx
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.GetNextTextOrTab
; Purpose:    Return the next TVENTRY of type TVET_TEXT or TAB command.
; Arguments:  Arg1: Current TVENTRY index.
; Return:     xax -> TVENTRY or NULL.

Method TextView.GetNextTextOrTab, uses xbx xsi, dCurEntryIndex:DWORD
  SetObject xsi
  mov ebx, dCurEntryIndex
  inc ebx
  xor eax, eax
  .while ebx < [xsi].Entries.dCount
    OCall [xsi].Entries::DataCollection.ItemAt, ebx
    mov edx, [xax].TVENTRY.dType
    .break .if edx == TVET_TEXT
    mov xcx, TVCH_TAB
    .break .if edx == TVET_CMD && [xax].TVENTRY.pHandler == xcx
    xor eax, eax
    inc ebx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Init
; Purpose:    Initialize the TextView object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Definition structure.
; Return:     Nothing.

Method TextView.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_TEXTVIEW
;  DbgText "TextView.Init"
  SetObject xsi
  m2m [xsi].hParent, hParent, xax
  mov xbx, pDefStruc
  assume xbx:PDEF_TEXTVIEW
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE
  %invoke CreateWindowEx, [xbx].dExStyle, offset cTextViewClass&TARGET_STR_AFFIX, [xbx].pText, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnButtonDown
; Purpose:    Event procedure for WM_XBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  local AppNotification:TVNM_APP, xCtrlID:XWORD

;  DbgText "TextView.OnButtonDown"
  SetObject xsi
  mov xax, lParam
  OCall xsi.GetActiveArea, eax
  .if xax != NULL
;    DbgDec [xax].TVENTRY.dValue, "Mouse button down over active area"
    m2m AppNotification.dID, [xax].TVENTRY.dValue, ecx
    mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)
    m2m AppNotification.Header.hwndFrom, [xsi].hWnd, xax
    m2m AppNotification.Header.idFrom, xCtrlID, xax
    mov AppNotification.Header.code, TVNMC_APP_MOUSEDOWN
    mov xax, wParam
    mov AppNotification.dButton, eax
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotification
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnButtonUp
; Purpose:    Event procedure for WM_XBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  local AppNotification:TVNM_APP, xCtrlID:XWORD

;  DbgText "TextView.OnButtonUp"
  SetObject xsi
  mov xax, lParam
  OCall xsi.GetActiveArea, eax
  .if xax != NULL
;    DbgDec [xax].TVENTRY.dValue, "Mouse button up over active area"
    m2m AppNotification.dID, [xax].TVENTRY.dValue, ecx
    mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)
    m2m AppNotification.Header.hwndFrom, [xsi].hWnd, xax
    m2m AppNotification.Header.idFrom, xCtrlID, xax
    mov AppNotification.Header.code, TVNMC_APP_MOUSEUP
    mov xax, wParam
    mov AppNotification.dButton, eax
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotification
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ;If we recieve WM_COMMANDs from a child window, replay them to the parent.
  ;eax = message ID
;  DbgHex eax, "MsgID", "Messages"
;  .if eax == WM_COMMAND
;    mov xdx, wParam
;    DbgHex dx
;    shr edx, 16
;    DbgHex dx
;    DbgHex lParam
;  .endif
  invoke SendMessage, [xsi].hParent, eax, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, CRect:RECT, dStrSize:DWORD

;  DbgText "TextView.OnCreate"

  SetObject xsi
  ;Get the markuptext
  invoke GetWindowTextLength, [xsi].hWnd                ;Does not include the ZTC
  add eax, 1                                            ;Include ZTC
  mov dStrSize, eax
  mov [xsi].pMarkupText, $invoke(StrAlloc, eax)
  invoke GetWindowText, [xsi].hWnd, xax, dStrSize       ;dStrSize must include the ZTC

  ;Initialize and customize collections
  OCall [xsi].Entries::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].Styles::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].StyleStack::XWCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].ActiveAreas::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].TabStops::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].GdiObjects::XWCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].CoverTasks::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  Override [xsi].GdiObjects::XWCollection.DestroyItem, GdiObjects.DestroyItem
  Override [xsi].Entries::DataCollection.DestroyItem, Entries.DestroyItem
  Override [xsi].TabStops::SortedDataCollection.Compare, TabStops.Compare

  ;Setup internal variables
  invoke GetClientRect, [xsi].hWnd, addr CRect
  m2m [xsi].Extent.x, CRect.right, xax
  m2m [xsi].Extent.y, CRect.bottom, xax
  m2m [xsi].pDefaultFontFace, $OfsCStr("Segoe UI"), xax

  ;Create memory resources
  mov hDC, $invoke(GetDC, [xsi].hParent)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke CreateCompatibleBitmap, hDC, [xsi].Extent.x, [xsi].Extent.y
  mov [xsi].hMemBmp, xax
  invoke ReleaseDC, [xsi].hParent, hDC
  mov [xsi].hPrvBmp, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBmp)
  mov [xsi].hPrvFont, $invoke(GetCurrentObject, [xsi].hMemDC, OBJ_FONT)
  mov [xsi].dLogPixY, $32($invoke(GetDeviceCaps, [xsi].hMemDC, LOGPIXELSY))

  ;Create a ToolTip window to display popup information when hoovering over an INFO area
  invoke CreateWindowEx, WS_EX_TOPMOST, $OfsCStr("tooltips_class32"), NULL, \
                         WS_POPUP or TTS_NOPREFIX or TTS_ALWAYSTIP, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xsi].hWnd, NULL, hInstance, NULL
  mov [xsi].hToolTip, xax
  invoke SetWindowPos, [xsi].hToolTip, HWND_TOPMOST, 0, 0, 0, 0, \
                       SWP_NOMOVE or SWP_NOSIZE or SWP_NOACTIVATE
  invoke SendMessage, [xsi].hToolTip, TTM_SETMAXTIPWIDTH, 0, 1000
  
  xor eax, eax                                          ;Return zero to continue window creation
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Brush HANDLE used to paint the background of the static control.

Method TextView.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnCtlColorStatic"
  SetObject xsi
  invoke SetTextColor, wParam, [xsi].DefaultTextColor
  invoke SetBkColor, wParam, [xsi].DefaultBackColor
  ;After a Render call, this collection item holds the background brush
  OCall [xsi].GdiObjects::XWCollection.ItemAt, 1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnGetFont
; Purpose:    Event procedure for WM_GETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Font handle or zero.

Method TextView.OnGetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "TextView.OnGetFont"
  SetObject xsi
  xor eax, eax
  .if [xsi].GdiObjects.dCount != 0
    OCall [xsi].GdiObjects::XWCollection.ItemAt, 0
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local AppNotification:TVNM_APP, xCtrlID:XWORD

;  DbgText "TextView.OnMouseMove"
  SetObject xsi
  mov xax, lParam
  OCall xsi.GetActiveArea, eax
  .if xax != NULL
;    DbgDec [xax].TVENTRY.dValue, "Mouse over active area"
    m2m AppNotification.dID, [xax].TVENTRY.dValue, ecx
    mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)
    m2m AppNotification.Header.hwndFrom, [xsi].hWnd, xax
    m2m AppNotification.Header.idFrom, xCtrlID, xax
    mov AppNotification.Header.code, TVNMC_APP_MOUSEOVER
    mov xax, wParam
    mov AppNotification.dButton, eax
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotification
    invoke SetCursor, $invoke(LoadCursor, 0, IDC_HAND)
  .else
    invoke SetCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, CRect:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)
  invoke GetClientRect, [xsi].hWnd, addr CRect

  uMin [xsi].Extent.x, CRect.right, eax
  uMin [xsi].Extent.y, CRect.bottom, ebx
;  sub eax, [xsi].Origin.x
;  sub ebx, [xsi].Origin.y
  invoke BitBlt, hDC, 0, 0, eax, ebx, [xsi].hMemDC, [xsi].Origin.x, [xsi].Origin.y, SRCCOPY

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnSetFont
; Purpose:    Event procedure for WM_SETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method TextView.OnSetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
  local LogFont:LOGFONT

  DbgText "TextView.OnSetFont"
  SetObject xsi
  invoke GetObject, wParam, sizeof(LogFont), addr LogFont
  .if eax != 0
    invoke StrDispose, [xsi].pDefaultFontFace
    mov [xsi].pDefaultFontFace, $invoke(StrNew, addr LogFont.lfFaceName)
    OCall xsi.Reset
    OCall xsi.Parse
    .if lParam != FALSE
      OCall xsi.Render
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnSetText
; Purpose:    Event procedure for WM_SETTEXT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method TextView.OnSetText, uses xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "TextView.OnSetText"
  SetObject xsi
  invoke DefWindowProc, [xsi].hWnd, WM_SETTEXT, wParam, lParam
  invoke StrDispose, [xsi].pMarkupText
  mov [xsi].pMarkupText, $invoke(StrNew, lParam)
  OCall xsi.Reset
  OCall xsi.Parse
  OCall xsi.Render
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local WRect:RECT, WndSize:POINT, ScrollInfo:SCROLLINFO

  SetObject xsi
  .if wParam != SIZE_MINIMIZED
    invoke GetWindowRect, [xsi].hWnd, addr WRect

    mov ecx, WRect.right
    sub ecx, WRect.left
    mov WndSize.x, ecx
    .if ecx < [xsi].Extent.x
      invoke SetScrollRange, [xsi].hWnd, SB_HORZ, 0, [xsi].Extent.x, TRUE
      invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, TRUE

      mov ScrollInfo.cbSize, sizeof SCROLLINFO
      mov ScrollInfo.fMask, SIF_POS or SIF_PAGE
      mov eax, [xsi].Origin.x
      mov ScrollInfo.nPos, eax
      mov eax, WndSize.x
      mov ScrollInfo.nPage, eax
      invoke SetScrollInfo, [xsi].hWnd, SB_HORZ, addr ScrollInfo, TRUE

    .else
      mov [xsi].Origin.x, 0
      invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, FALSE
    .endif

    mov ecx, WRect.bottom
    sub ecx, WRect.top
    mov WndSize.y, ecx
    .if ecx < [xsi].Extent.y
      invoke SetScrollRange, [xsi].hWnd, SB_VERT, 0, [xsi].Extent.y, TRUE
      invoke ShowScrollBar, [xsi].hWnd, SB_VERT, TRUE

      mov ScrollInfo.cbSize, sizeof SCROLLINFO
      mov ScrollInfo.fMask, SIF_POS or SIF_PAGE
      mov eax, [xsi].Origin.y
      mov ScrollInfo.nPos, eax
      mov eax, WndSize.y
      mov ScrollInfo.nPage, eax
      invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, TRUE

    .else
      mov [xsi].Origin.y, 0
      invoke ShowScrollBar, [xsi].hWnd, SB_VERT, FALSE
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnHScroll
; Purpose:    Event procedure for WM_HSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnHScroll, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

  SetObject xsi
  mov xax, wParam
  .if ax == SB_THUMBPOSITION || ax == SB_THUMBTRACK
    shr eax, 16
    mov [xsi].Origin.x, eax

  .elseif ax == SB_LINELEFT
    sub [xsi].Origin.x, 1
    .if SIGN?
      m2z [xsi].Origin.x
    .endif

  .else
    mov ScrollInfo.cbSize, sizeof(ScrollInfo)
    mov ScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_HORZ, addr ScrollInfo

    mov xax, wParam
    .if ax == SB_LINERIGHT
      mov eax, [xsi].Origin.x
      add eax, 1
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      add edx, 1
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].Origin.x, eax

    .elseif ax == SB_PAGERIGHT
      mov eax, [xsi].Origin.x
      add eax, ScrollInfo.nPage
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      inc edx
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].Origin.x, eax

    .elseif ax == SB_PAGELEFT
      mov eax, ScrollInfo.nPage
      sub [xsi].Origin.x, eax
      .if SIGN?
        m2z [xsi].Origin.x
      .endif

    .endif
  .endif

  invoke SetScrollPos, [xsi].hWnd, SB_HORZ, [xsi].Origin.x, TRUE 
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_FRAME
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnVScroll
; Purpose:    Event procedure for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnVScroll, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

  SetObject xsi
  mov xax, wParam
  .if ax == SB_THUMBPOSITION || ax == SB_THUMBTRACK
    shr eax, 16
    mov [xsi].Origin.y, eax

  .elseif ax == SB_LINELEFT
    sub [xsi].Origin.y, 1
    .if SIGN?
      m2z [xsi].Origin.y
    .endif

  .else
    mov ScrollInfo.cbSize, sizeof(ScrollInfo)
    mov ScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo

    mov xax, wParam
    .if ax == SB_LINERIGHT
      mov eax, [xsi].Origin.y
      add eax, 1
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      add edx, 1
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].Origin.y, eax

    .elseif ax == SB_PAGERIGHT
      mov eax, [xsi].Origin.y
      add eax, ScrollInfo.nPage
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      inc edx
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].Origin.y, eax

    .elseif ax == SB_PAGELEFT
      mov eax, ScrollInfo.nPage
      sub [xsi].Origin.y, eax
      .if SIGN?
        m2z [xsi].Origin.y
      .endif

    .endif
  .endif

  invoke SetScrollPos, [xsi].hWnd, SB_VERT, [xsi].Origin.y, TRUE 
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE or RDW_FRAME
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Parse
; Purpose:    Parse input markup text string using a state machine.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

;Styles:    [FONT "ARIAL", HEIGHT 10, ...]Some Text.[~]
;Command:     {TABC 120}{BR}

;States:
;  [  Markup  Numeric  ,  Markup  'String'  ]TEXT[ ~  ~ ~  ]
; 04  5     6 #RRGGBB  4  5     6 A       9 01     C        1
;             7      9            B       9  Space
;             Decimal                        2    1
;             8      9                       Tab
;             +                              3    1
;             -

;Transitions:
;From  To   Condition        Description
; 00  04    == "["           Markup start
; 00  02    == " "           White mode
; 00  03    == Tab           Check ExpandTab
; 00  01    else             Text

; 01  04    == "["           Markup start
; 01  02    == " "           White mode
; 01  03    == Tab           Check ExpandTab

; 02  03    == Tab
; 02  01    <> " "
;
; 03  01    TabExpand == 1   Expand to dTab2Spaces spaces
; 03  01    == Tab           Create Command
;
; 04  12    == "~"           Markup pop
; 04  05    == "A...Z"       Markup name
; 04  00    <> White

; 05  06    == White
; 05  01    == "]"           Markup close
; 05  00    <> "A..Z"

; 06  07    == "#"           Markup hex value
; 06  08    == "0..9"        Markup decimal value
; 06  10    == "'"           Markup single quoted string value
; 06  11    == '"'           Markup double quoted string value
; 06  01    == "]"           Markup close

; 07  09    == " "
; 07  04    == ,             Next Markup
; 07  01    == "]"           Evaluate hex value & Markup push
; 07  00    <> "A..F"

; 08  09    == " "
; 08  04    == ,             Next Markup, evaluate decimal value
; 08  01    == "]"           Markup close, evaluate decimal value
; 08  00    <> "0..9"

; 09  04    == ","
; 09  01    == "]"
; 09  00    == <> White

; 10  09    == "'"

; 11  09    == '"'

; 12  01    == "]"
; 12  00    <> "~", " ", Tab

; ...

GetHandler proc uses xdi xbx pTable:POINTER, pBeg:POINTER, pEnd:POINTER
  mov xbx, pTable
  xor eax, eax
  mov xdi, pEnd
  sub xdi, pBeg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shr edi, 1
  endif
  .while [xbx].TVTAG.pMnemonic != NULL
    mov ecx, [xbx].TVTAG.dLength
    .break .if ecx > edi
    .if ZERO?
      invoke StrCIComp, pBeg, [xbx].TVTAG.pMnemonic, edi
      .if SDWORD ptr eax < 0
        xor eax, eax
        .break
      .endif
      .if ZERO?
        mov xax, xbx
        .break
      .endif
      xor eax, eax
    .endif
    add xbx, sizeof(TVTAG)
  .endw

  .if xax != NULL
    mov xax, [xbx].TVTAG.pHandler
  .endif

  ret
GetHandler endp

$NewTVENTRY macro pCurStyle
  MemAlloc sizeof(TVENTRY), MEM_INIT_ZERO
;  DbgHex xax, "New TVENTRY"
  OCall [xsi].Entries::DataCollection.Insert, xax
  ifnb <pCurStyle>
    m2m [xax].TVENTRY.pStyle, pCurStyle, xdx
  endif
  exitm <xax>
endm

DupTVStyle macro
  mov dStyleChange, TVSC_NOTHING
  MemAlloc sizeof(TVSTYLE)
;  DbgHex xax, "New TVSTYLE"
  OCall [xsi].Styles::DataCollection.Insert, xax
  OCall [xsi].StyleStack::DataCollection.Insert, xax
  .if xdi == NULL
    m2m [xax].TVSTYLE.TextColor, [xsi].DefaultTextColor, ecx
    m2m [xax].TVSTYLE.BackColor, [xsi].DefaultBackColor, ecx
    mov [xax].TVSTYLE.dAlignment, TVALIGN_LEFT
    m2z [xax].TVSTYLE.dIndent
    m2z [xax].TVSTYLE.dHanging
    m2m [xax].TVSTYLE.dFontSize, [xsi].dDefaultFontSize, ecx
    m2z [xax].TVSTYLE.hFont
    m2z [xax].TVSTYLE.hBackBrush
    m2z [xax].TVSTYLE.dFlags
    m2z [xax].TVSTYLE.dID
  .else
    s2s TVSTYLE ptr [xax], TVSTYLE ptr [xdi], xcx, xdx, xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7
  .endif
  mov xdi, xax
endm

CreateTVStyleFont macro
;  DbgDec [xdi].TVSTYLE.dFontSize, "Creating Font"
  invoke MulDiv, [xdi].TVSTYLE.dFontSize, [xsi].dLogPixY, -72
  mov [xdi].TVSTYLE.LogFont.lfHeight, eax
  mov [xdi].TVSTYLE.hFont, $invoke(CreateFontIndirect, addr [xdi].TVSTYLE.LogFont)
  OCall [xsi].GdiObjects::DataCollection.Insert, xax
  invoke SelectObject, [xsi].hMemDC, [xdi].TVSTYLE.hFont
  invoke GetTextMetrics, [xsi].hMemDC, addr [xdi].TVSTYLE.TextMetric
endm

CreateTVSytleResources macro
  .ifBitSet dStyleChange, TVSC_FONT
    CreateTVStyleFont
  .endif
  .ifBitSet dStyleChange, TVSC_BACKCOLOR
    mov [xdi].TVSTYLE.hBackBrush, $invoke(CreateSolidBrush, [xdi].TVSTYLE.BackColor)
    OCall [xsi].GdiObjects::DataCollection.Insert, xax
    invoke SelectObject, [xsi].hMemDC, xax
  .endif
endm

GetSingleTVStyleName macro HasBlanks:req
  m2z CHR ptr cBuffer                                   ;Clear buffer
  invoke GetHandler, offset TVTAG_STYLES, pBlockBeg, pBlockEnd  ;xax -> Handler
  .if xax != NULL
    .if cCurChr == TVTAG_STYLE_CLOSE
      invoke TVStyleHandler ptr xax, NULL
      or dStyleChange, eax
      CreateTVSytleResources
      mov dTVStateID, TVSID_INIT
  if HasBlanks eq TRUE
    .elseif cCurChr == ","
      invoke TVStyleHandler ptr xax, NULL
      or dStyleChange, eax
      mov dTVStateID, TVSID_STYLE
    .else
      mov pTVStyleHandler, xax
      mov dTVStateID, TVSID_STYLE_NAME_END              ;Blank
    .endif
  else
    .else
      invoke TVStyleHandler ptr xax, NULL
      or dStyleChange, eax
    .endif
  endif

  .else                                                 ;ecx == VMT_NONE
    mov dTVStateID, TVSID_ERROR
    DbgWarning "Parsing error: Style identifier not found"
  .endif
  add pBlockEnd, sizeof(CHR)
endm

GetSingleTVCmdName macro HasBlanks:req
  m2z CHR ptr cBuffer                                   ;Clear buffer
  mov pEntry, $NewTVENTRY(xdi)
  invoke GetHandler, offset TVTAG_CMDS, pBlockBeg, pBlockEnd  ;xax -> Handler
  .if xax != NULL
    mov xdx, pEntry
    .if [xdx].TVENTRY.pHandler == NULL
      mov [xdx].TVENTRY.pHandler, xax
      m2z [xdx].TVENTRY.dValue

      .if cCurChr == TVTAG_CMD_CLOSE
        mov dTVStateID, TVSID_INIT
  if HasBlanks eq TRUE
      .elseif cCurChr == " "
        mov dTVStateID, TVSID_CMD_NAME_END
  endif
      .else
        mov dTVStateID, TVSID_ERROR
      .endif
    .else
      mov dTVStateID, TVSID_ERROR
    .endif
  .else                                                 ;ecx == VMT_NONE
    mov dTVStateID, TVSID_ERROR
    DbgWarning "Parsing error: Command identifier not found"
    DbgStr pBlockBeg

  .endif
  add pBlockEnd, sizeof(CHR)
endm

DefineTextViewState macro StateName:req
  TVSID_&StateName equ TVStateID
  TVStateID = TVStateID + 1
  POINTER offset VSTAGE_&StateName
endm

IsStyleNameChar textequ <((cCurChr !>= "A" && cCurChr !<= "Z") || \
                          (cCurChr !>= "a" && cCurChr !<= "z") || \
                           cCurChr == ".")>
IsCmdNameChar   textequ IsStyleNameChar
IsHexChar       textequ <((cCurChr !>= "A" && cCurChr !<= "F") || \
                          (cCurChr !>= "a" && cCurChr !<= "f") || \
                          (cCurChr !>= "0" && cCurChr !<= "9"))>
IsDecChar       textequ <(cCurChr !>= "0" && cCurChr !<= "9")>
IsBlankChar     textequ <(cCurChr == " " || cCurChr == 9)>

Method TextView.Parse, uses xdi xsi
  local cCurChr:CHR, dTVStateID:DWORD, pBlockBeg:POINTER, pBlockEnd:POINTER
  local pEntry:PTVENTRY, dStyleChange:DWORD
  local pTVStyleHandler:PTVStyleHandler, dValue:DWORD, cBuffer[1024]:CHR

  ;xsi -> TextView
  ;xdi -> current TVSTYLE

  .const
  TVStateID = 0                                         ;Set first TVStateID = 0
  ViewStates label POINTER                              ;Build jump table and define EQUs
  DefineTextViewState ERROR                             ;TVStateID = 00
  DefineTextViewState INIT                              ;TVStateID = 01
  DefineTextViewState TEXT                              ;TVStateID = 02
  DefineTextViewState BLANK                             ;TVStateID = 03
  DefineTextViewState STYLE                             ;TVStateID = 04
  DefineTextViewState STYLE_NAME                        ;TVStateID = 05
  DefineTextViewState STYLE_NAME_END                    ;TVStateID = 06
  DefineTextViewState STYLE_HEX                         ;TVStateID = 07
  DefineTextViewState STYLE_DEC                         ;TVStateID = 08
  DefineTextViewState STYLE_VAL_END                     ;TVStateID = 09
  DefineTextViewState STYLE_STR1                        ;TVStateID = 10
  DefineTextViewState STYLE_STR2                        ;TVStateID = 11
  DefineTextViewState STYLE_POP                         ;TVStateID = 12
  DefineTextViewState CMD                               ;TVStateID = 13
  DefineTextViewState CMD_NAME                          ;TVStateID = 14
  DefineTextViewState CMD_NAME_END                      ;TVStateID = 15
  DefineTextViewState CMD_DEC                           ;TVStateID = 16
  DefineTextViewState CMD_DEC_END                       ;TVStateID = 17
  DefineTextViewState CMD_CHR                           ;TVStateID = 18
  DefineTextViewState CMD_CHR_END                       ;TVStateID = 19

  .code
;  DbgText "TextView.ParseText"

  SetObject xsi

  ;Get default colors
  invoke SendMessage, [xsi].hParent, WM_CTLCOLORSTATIC, [xsi].hMemDC, [xsi].hWnd
  mov [xsi].DefaultTextColor, $32($invoke(GetTextColor, [xsi].hMemDC))
  mov [xsi].DefaultBackColor, $32($invoke(GetBkColor, [xsi].hMemDC))

  mov xdx, [xsi].pMarkupText
  mov pBlockBeg, xdx
  mov pBlockEnd, xdx

  ;Create initial TVSTYLE and store original values from MemDC
  mov dStyleChange, TVSC_NOTHING
  MemAlloc sizeof(TVSTYLE)
  OCall [xsi].Styles::DataCollection.Insert, xax
  OCall [xsi].StyleStack::DataCollection.Insert, xax
  mov xdi, xax

  mov [xdi].TVSTYLE.dAlignment, TVALIGN_LEFT
  m2z [xdi].TVSTYLE.dIndent
  m2z [xax].TVSTYLE.dHanging
  m2z [xdi].TVSTYLE.dFlags
  m2z [xax].TVSTYLE.dID

  m2m [xdi].TVSTYLE.dFontSize, [xsi].dDefaultFontSize, eax

  invoke StrCCopy, addr [xdi].TVSTYLE.LogFont.lfFaceName, [xsi].pDefaultFontFace, 32
  m2z [xdi].TVSTYLE.LogFont.lfWidth
  m2z [xdi].TVSTYLE.LogFont.lfEscapement
  m2z [xdi].TVSTYLE.LogFont.lfOrientation
  mov [xdi].TVSTYLE.LogFont.lfCharSet, DEFAULT_CHARSET
  mov [xdi].TVSTYLE.LogFont.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov [xdi].TVSTYLE.LogFont.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov [xdi].TVSTYLE.LogFont.lfQuality, CLEARTYPE_QUALITY
  mov [xdi].TVSTYLE.LogFont.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov [xdi].TVSTYLE.LogFont.lfWeight, FW_NORMAL
  m2z [xdi].TVSTYLE.LogFont.lfItalic
  m2z [xdi].TVSTYLE.LogFont.lfUnderline
  m2z [xdi].TVSTYLE.LogFont.lfStrikeOut
  CreateTVStyleFont                                     ;Resource #0

  m2m [xdi].TVSTYLE.TextColor, [xsi].DefaultTextColor, eax
  m2m [xdi].TVSTYLE.BackColor, [xsi].DefaultBackColor, eax
  mov [xdi].TVSTYLE.hBackBrush, $invoke(CreateSolidBrush, [xdi].TVSTYLE.BackColor)

  OCall [xsi].GdiObjects::DataCollection.Insert, xax    ;Resource #1
  mov [xsi].hPrvBrush, $invoke(SelectObject, [xsi].hMemDC, xax)

  mov dTVStateID, TVSID_INIT                            ;Set initial state

  .while TRUE
    mov xdx, pBlockEnd
    mrm cCurChr, [xdx], ecx
    .if cCurChr == 0
      .if dTVStateID == TVSID_TEXT
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          shr eax, 1
        endif
        invoke StrCNew, pBlockBeg, eax
        mov xcx, pEntry
        mov [xcx].TVENTRY.pText, xax
      .endif
      .break
    .endif

    mov xdx, offset ViewStates
    mov ecx, dTVStateID
    jmp POINTER ptr [xdx + sizeof(POINTER)*xcx]

    VSTAGE_INIT:
      mov pEntry, NULL
      .if cCurChr == TVTAG_STYLE_OPEN
        DupTVStyle
        add pBlockEnd, sizeof(CHR)
        mov dTVStateID, TVSID_STYLE

      .else
        mov pEntry, $NewTVENTRY(xdi)
        .if cCurChr == TVTAG_CMD_OPEN
          mov [xax].TVENTRY.dType, TVET_CMD
          add pBlockEnd, sizeof(CHR)
          mov dTVStateID, TVSID_CMD

        .elseif cCurChr == " "
          mov [xax].TVENTRY.dType, TVET_BLANK
          mov [xax].TVENTRY.dCharCount, 1
          add pBlockEnd, sizeof(CHR)
          mov dTVStateID, TVSID_BLANK
        .else
          .if cCurChr == 9
            ;Handle it as regular blanks
            mov [xax].TVENTRY.dType, TVET_BLANK
            m2m [xax].TVENTRY.dCharCount, [xsi].dTab2Spaces, ecx
            add pBlockEnd, sizeof(CHR)
            mov dTVStateID, TVSID_TEXT
          .else
            mov [xax].TVENTRY.dType, TVET_TEXT
            mov [xax].TVENTRY.dCharCount, 1
            mrm pBlockBeg, pBlockEnd, xcx
            add xcx, sizeof(CHR)
            mov pBlockEnd, xcx
            mov dTVStateID, TVSID_TEXT
          .endif
        .endif
      .endif
      .continue

    VSTAGE_TEXT:
      .if cCurChr == TVTAG_STYLE_OPEN || cCurChr == TVTAG_CMD_OPEN || IsBlankChar
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          shr eax, 1
        endif
        invoke StrCNew, pBlockBeg, eax
        mov xcx, pEntry
        mov [xcx].TVENTRY.pText, xax
        .if cCurChr == TVTAG_STYLE_OPEN
          DupTVStyle
          mov dTVStateID, TVSID_STYLE

        .elseif cCurChr == TVTAG_CMD_OPEN
          mov pEntry, $NewTVENTRY(xdi)
          mov dTVStateID, TVSID_CMD

        .elseif cCurChr == " "
          mov pEntry, $NewTVENTRY(xdi)
          mov [xax].TVENTRY.dType, TVET_BLANK
          mov [xax].TVENTRY.dCharCount, 1
          mov dTVStateID, TVSID_BLANK

        .elseif cCurChr == 9
          mov pEntry, $NewTVENTRY(xdi)
          ;Handle it as a regular character
          mov [xax].TVENTRY.dType, TVET_BLANK
          mov ecx, [xsi].dTab2Spaces
          add [xax].TVENTRY.dCharCount, ecx
          mov dTVStateID, TVSID_BLANK
        .endif

      .else
        mov xax, pEntry
        add [xax].TVENTRY.dCharCount, 1
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_BLANK:
      .if cCurChr == 9
        ;Handle it as a regular character
        mov xax, pEntry
        add [xax].TVENTRY.dCharCount, ecx
        mov ecx, [xsi].dTab2Spaces

      .elseif cCurChr == " "
        mov xax, pEntry
        add [xax].TVENTRY.dCharCount, 1

      .elseif cCurChr == TVTAG_STYLE_OPEN
        mov xax, pEntry
        invoke StrRepChr, " ", [xax].TVENTRY.dCharCount
        mov xcx, pEntry
        mov [xcx].TVENTRY.pText, xax
        DupTVStyle
        mov dTVStateID, TVSID_STYLE

      .elseif cCurChr == TVTAG_CMD_OPEN
        mov xax, pEntry
        invoke StrRepChr, " ", [xax].TVENTRY.dCharCount
        mov xcx, pEntry
        mov [xcx].TVENTRY.pText, xax
        mov pEntry, $NewTVENTRY(xdi)
        mov dTVStateID, TVSID_CMD

      .else
        mov xax, pEntry
        invoke StrRepChr, " ", [xax].TVENTRY.dCharCount
        mov xcx, pEntry
        mov [xcx].TVENTRY.pText, xax
        mov pEntry, $NewTVENTRY(xdi)
        mov [xax].TVENTRY.dCharCount, 1
        m2m pBlockBeg, pBlockEnd, xcx
        mov dTVStateID, TVSID_TEXT
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    ;Styles -------------------------------------------------------------------

    VSTAGE_STYLE:
      .if IsBlankChar
        add pBlockEnd, sizeof(CHR)                      ;Skip blanks

      .elseif IsStyleNameChar
        m2m pBlockBeg, pBlockEnd, xcx                   ;Remember beginning
        add xcx, sizeof(CHR)
        mov pBlockEnd, xcx
        mov dTVStateID, TVSID_STYLE_NAME

      .elseif cCurChr == "~"
        mov dValue, 1                                   ;Initialize to 1
        mov dTVStateID, TVSID_STYLE_POP
        add pBlockEnd, sizeof(CHR)

      .else
        add pBlockEnd, sizeof(CHR)                      ;Bad character
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_STYLE"
      .endif
      .continue

    VSTAGE_STYLE_NAME:
      .if IsBlankChar || cCurChr == TVTAG_STYLE_CLOSE || cCurChr == ","
        GetSingleTVStyleName TRUE
      .else
        .if !IsStyleNameChar                            ;Bad character
          mov dTVStateID, TVSID_ERROR
          DbgWarning "Parsing error in VSTAGE_STYLE_NAME"
        .endif
        add pBlockEnd, sizeof(CHR)
      .endif
      .continue

    VSTAGE_STYLE_NAME_END:
      .if cCurChr == TVTAG_STYLE_CLOSE || cCurChr == ","
        GetSingleTVStyleName FALSE

      .elseif cCurChr == "#"
        mov dTVStateID, TVSID_STYLE_HEX
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx

      .elseif IsDecChar
        mov dTVStateID, TVSID_STYLE_DEC
        mrm pBlockBeg, pBlockEnd, xcx
        add xcx, sizeof(CHR)
        mov pBlockEnd, xcx

      .elseif cCurChr == "+"
        mov dTVStateID, TVSID_STYLE_DEC
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx
        BitSet [xdi].TVSTYLE.dFlags, TVSF_INCR

      .elseif cCurChr == "-"
        mov dTVStateID, TVSID_STYLE_DEC
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx
        BitSet [xdi].TVSTYLE.dFlags, TVSF_DECR

      .elseif cCurChr == "'"
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx                              ;Remember beginning
        mov pBlockEnd, xcx
        mov dTVStateID, TVSID_STYLE_STR1

      .elseif cCurChr == '"'
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx                              ;Remember beginning
        mov pBlockEnd, xcx
        mov dTVStateID, TVSID_STYLE_STR2

      .elseif IsBlankChar
        add pBlockEnd, sizeof(CHR)                      ;Skip blanks

      .else
        add pBlockEnd, sizeof(CHR)                      ;Bad character
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_STYLE_NAME_END"
      .endif
      .continue

    VSTAGE_STYLE_HEX:
      .if IsBlankChar || cCurChr == "," || cCurChr == TVTAG_STYLE_CLOSE
        FillString cBuffer, <00000000>                  ;Complete with zeros
        mov edx, 8*sizeof(CHR)
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        .if eax > 0 && eax <= 6*sizeof(CHR)             ;0 < # of digits <= 6 (RGB)
          sub xdx, xax
          invoke MemClone, addr [cBuffer + xdx], pBlockBeg, eax
        .endif
        mov DWORD ptr cBuffer, $32($invoke(hex2dword, addr cBuffer))
        m2z CHR ptr [cBuffer + sizeof(DWORD)]           ;Just in case
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax

        .if IsBlankChar
          mov dTVStateID, TVSID_STYLE_VAL_END
        .elseif cCurChr == ","
          mov dTVStateID, TVSID_STYLE
        .else                                           ;"]"
          CreateTVSytleResources
          mov dTVStateID, TVSID_INIT
        .endif

      .elseif !IsHexChar
        mov dTVStateID, TVSID_ERROR                     ;Bad character
        DbgWarning "Parsing error in VSTAGE_STYLE_HEX"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_STYLE_DEC:
      .if IsBlankChar || cCurChr == "," || cCurChr == TVTAG_STYLE_CLOSE
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, cBuffer
        m2z CHR ptr [xcx + xax]                         ;ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        mov DWORD ptr cBuffer, $32($invoke(dec2dword, addr cBuffer))
        m2z CHR ptr [cBuffer + sizeof(DWORD)]           ;Just in case
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax

        .if IsBlankChar
          mov dTVStateID, TVSID_STYLE_VAL_END
        .elseif cCurChr == ","
          mov dTVStateID, TVSID_STYLE
        .else                                           ;"]"
          CreateTVSytleResources
          mov dTVStateID, TVSID_INIT
        .endif

      .elseif !IsDecChar                                ;Bad characters
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_STYLE_DEC"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_STYLE_VAL_END:
      .if cCurChr == ","
        add pBlockEnd, sizeof(CHR)
        mov dTVStateID, TVSID_STYLE

      .elseif cCurChr == TVTAG_STYLE_CLOSE
        CreateTVSytleResources
        mov dTVStateID, TVSID_INIT
        add pBlockEnd, sizeof(CHR)

      .elseif IsBlankChar
        add pBlockEnd, sizeof(CHR)

      .else
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_STYLE_VAL_END"
      .endif
      .continue

    VSTAGE_STYLE_STR1:
      .if cCurChr == "'"
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, [cBuffer]
        m2z CHR ptr [xcx + xax]                         ;Set ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax
        mov dTVStateID, TVSID_STYLE_VAL_END
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_STYLE_STR2:
      .if cCurChr == '"'
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, [cBuffer]
        m2z CHR ptr [xcx + xax]                         ;Set ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax
        mov dTVStateID, TVSID_STYLE_VAL_END
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_STYLE_POP:
      .if cCurChr == "~"                                ;For each "~" pop a TVSTYLE from stack
        add dValue, 1

      .elseif cCurChr == TVTAG_STYLE_CLOSE
        add dValue, 1                                   ;Delete itself
        mov eax, [xsi].StyleStack.dCount
        sub eax, dValue
        .if SDWORD ptr eax < 1                          ;Leave the first
          mov eax, 1
        .endif

        mov [xsi].StyleStack.dCount, eax
        sub eax, 1
        mov xdi, $OCall([xsi].StyleStack::DataCollection.ItemAt, eax)
        mov dTVStateID, TVSID_INIT

      .elseif !IsBlankChar
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_STYLE_POP"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    ;Commands -----------------------------------------------------------------

    VSTAGE_CMD:
      .if IsBlankChar
        add pBlockEnd, sizeof(CHR)                      ;Skip blanks

      .elseif cCurChr == "#"
        mov xcx, pBlockEnd                              ;Remember beginning
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx
        mov xdx, pEntry
        m2m [xdx].TVENTRY.pHandler, TVCH_CHR, xax
        mov dTVStateID, TVSID_CMD_CHR

      .elseif IsCmdNameChar
        m2m pBlockBeg, pBlockEnd, xcx                   ;Remember beginning
        add xcx, sizeof(CHR)
        mov pBlockEnd, xcx
        mov dTVStateID, TVSID_CMD_NAME

      .else
        add pBlockEnd, sizeof(CHR)                      ;Bad character
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_CMD"
      .endif
      .continue

    VSTAGE_CMD_NAME:
      .if IsBlankChar || cCurChr == TVTAG_CMD_CLOSE
        GetSingleTVCmdName TRUE
      .else
        .if !IsCmdNameChar
          mov dTVStateID, TVSID_ERROR                   ;Bad character
          DbgWarning "Parsing error in VSTAGE_CMD_NAME"
        .endif
        add pBlockEnd, sizeof(CHR)
      .endif
      .continue

    VSTAGE_CMD_NAME_END:
      .if cCurChr == TVTAG_CMD_CLOSE
        GetSingleTVCmdName FALSE

      .elseif IsDecChar
        mov dTVStateID, TVSID_CMD_DEC
        mrm pBlockBeg, pBlockEnd, xcx
        add xcx, sizeof(CHR)
        mov pBlockEnd, xcx

      .elseif IsBlankChar
        add pBlockEnd, sizeof(CHR)                      ;Skip blanks

      .else
        add pBlockEnd, sizeof(CHR)                      ;Bad character
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_CMD_NAME_END"
      .endif
      .continue

    VSTAGE_CMD_DEC:
      .if IsBlankChar || cCurChr == TVTAG_CMD_CLOSE
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, cBuffer
        m2z CHR ptr [xcx + xax]                         ;ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        invoke dec2dword, addr cBuffer
        mov xdx, pEntry
        mov [xdx].TVENTRY.dValue, eax

        .if IsBlankChar
          mov dTVStateID, TVSID_CMD_DEC_END
        .else                                           ;"}"
          CreateTVSytleResources
          mov dTVStateID, TVSID_INIT
        .endif

      .elseif !IsDecChar                                ;Bad characters
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_CMD_DEC"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_CMD_DEC_END:
      .if cCurChr == TVTAG_CMD_CLOSE
        mov dTVStateID, TVSID_INIT

      .elseif !IsBlankChar
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_CMD_DEC_END"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_CMD_CHR:
      .if IsBlankChar || cCurChr == TVTAG_CMD_CLOSE
        FillString cBuffer, <00000000>                  ;Complete with zeros
        mov edx, 8*sizeof(CHR)
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        .if eax > 0 && eax <= 6*sizeof(CHR)             ;0 < # of digits <= 6 (RGB)
          sub xdx, xax
          invoke MemClone, addr [cBuffer + xdx], pBlockBeg, eax
        .endif
        invoke hex2dword, addr cBuffer
        mov xcx, pEntry
        mov [xcx].TVENTRY.dValue, eax

        .if IsBlankChar
          mov dTVStateID, TVSID_CMD_CHR_END
        .else                                           ;"]"
          mov dTVStateID, TVSID_INIT
        .endif

      .elseif !IsHexChar
        mov dTVStateID, TVSID_ERROR                     ;Bad character
        DbgWarning "Parsing error in VSTAGE_CMD_CHR"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_CMD_CHR_END:
      .if cCurChr == TVTAG_CMD_CLOSE
        mov dTVStateID, TVSID_INIT

      .elseif !IsBlankChar
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in VSTAGE_CMD_CHR_END"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    VSTAGE_ERROR:
      add pBlockEnd, sizeof(CHR)
      .break

  .endw
  mov eax, TRUE

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Render
; Purpose:    Renders the parsed text onto the MemDC.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method TextView.Render, uses xbx xdi xsi
  local xCtrlID:XWORD, dLineLength:DWORD, dLineAlignment:DWORD
  local dHanging:DWORD, dLineIndent:DWORD, dAdjacentTextItems:DWORD
  local dBoxed:DWORD, BoxRect:RECT, BoxColor:RGBQUAD
  local CurLinePos:POINT, NewLinePos:POINT, DrawExtent:POINT, DrawRect:RECT, OutRect:RECT
  local dMaxAscent:DWORD, dMaxDescent:DWORD, dMaxHeight:DWORD, dMaxExtLeading:DWORD
  local dLastAscent:DWORD, dLastDescent:DWORD
  local dCurEntryIndex:DWORD, dLineFirstEntryIndex:DWORD, dLineLastEntryIndex:DWORD
  local cChars[10]:CHR, hBrush:HBRUSH, ToolInfo:TOOLINFO
  local InfoNotification:TVNM_INFO, DrawNotification:TVNM_DRAW

  SetObject xsi

  mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)
  OCall [xsi].ActiveAreas::DataCollection.DeleteAll
  OCall [xsi].CoverTasks::DataCollection.DisposeAll
  OCall [xsi].TabStops::SortedDataCollection.DisposeAll

  OCall xsi.GetExtent
  .if eax != FALSE
   invoke CreateCompatibleBitmap, [xsi].hMemDC, [xsi].Extent.x, [xsi].Extent.y
    mov [xsi].hMemBmp, xax
    invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, xax)
  .endif

  mov eax, [xsi].Extent.x
  sub eax, [xsi].Padding.left
  sub eax, [xsi].Padding.right
  mov DrawExtent.x, eax
  mov eax, [xsi].Extent.y
  sub eax, [xsi].Padding.top
  sub eax, [xsi].Padding.bottom
  mov DrawExtent.y, eax

  mov eax, [xsi].Padding.left
  mov DrawRect.left, eax
  add eax, DrawExtent.x
  mov DrawRect.right, eax
  mov eax, [xsi].Padding.top
  mov DrawRect.top, eax
  add eax, DrawExtent.y
  mov DrawRect.bottom, eax

  s2s CurLinePos, POINT ptr [xsi].Padding, xax, xcx, xdx, xmm0  ;Copy only left & right

;  DbgDec [xsi].Entries.dCount
;  DbgDec [xsi].Styles.dCount
;  DbgDec [xsi].GdiObjects.dCount

  mov hBrush, $OCall([xsi].GdiObjects::XWCollection.ItemAt, 1)  ;Fill using the default BG color
                                                                ;Resource #1
  invoke SetBkMode, [xsi].hMemDC, TRANSPARENT
  invoke FillRect, [xsi].hMemDC, addr [xsi].Extent, hBrush      ;Fill the complete background

  ;Evaluate the width of all text and blank areas
  .for (ebx = 0 : ebx != [xsi].Entries.dCount: ebx++)
    mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, ebx)
    .if [xdi].TVENTRY.pText != NULL
      mov xax, [xdi].TVENTRY.pStyle
      invoke SelectObject, [xsi].hMemDC,  [xax].TVSTYLE.hFont
      invoke DrawText, [xsi].hMemDC, [xdi].TVENTRY.pText, -1, addr [xdi].TVENTRY.Extent, DT_CALCRECT
      mov xax, [xdi].TVENTRY.pStyle
      mov ecx, [xax].TVSTYLE.TextMetric.tmOverhang
      sub [xdi].TVENTRY.Extent.right, ecx
    .endif
  .endfor

;  DbgClearTxt
  ;Master loop ===============================================================================
  m2z dCurEntryIndex
  m2z dHanging
  .while TRUE
    mov edx, dCurEntryIndex
    .break .if edx >= [xsi].Entries.dCount

    ;Start a new line
    m2z dBoxed
    m2z dLineLength
    m2z dMaxAscent
    m2z dLastAscent
    m2z dMaxDescent
    m2z dMaxExtLeading
    m2z dLineIndent
    m2m CurLinePos.x, [xsi].Padding.left, eax

    ;Get the metric of the current line ———————————————————————————————————————
    m2z dAdjacentTextItems
    mov dLineFirstEntryIndex, edx
    .while TRUE
      mov edx, dCurEntryIndex
      .break .if edx >= [xsi].Entries.dCount

      mov dLineLastEntryIndex, edx
      mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, edx)
      mov xax, [xdi].TVENTRY.pHandler
      test xax, xax
      jz @@EndHandler
      jmp xax

      ; —————————————————————————————————————————————————————————————
      ; Routines:   TVCH_xxx
      ; Purpose:    Handler for TextView Commands.
      ; Arguments:  xsi -> TextView
      ;             xdi -> ViewArea
      ; Note:       ebx can be used in the command routines.
      ;##\
    TVCH_CHR::
;      DbgText "CHR"
      mov eax, [xdi].TVENTRY.dValue
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        .if eax > 0FFh
          mov eax, "?"
        .endif
        mov CHR ptr cChars[0], al
        m2z CHR ptr cChars[1]
        mov [xdi].TVENTRY.dCharCount, 1
      else
        .if eax > 0FFFFh                                ;Character > BMP
          mov edx, eax
          mov cx, ax
          shr edx, 6
          shr cx, 18
          mov dh, al
          and cx, 00000111y
          shr eax, 12
          and edx, 0011111100111111y
          add cx, 11110000y
          add edx, 1000000010000000y
          and eax, 00111111y
          shl edx, 16
          mov dl, cl
          add al, 10000000y
          mov dh, al
          mov DWORD ptr cChars, edx
          m2z CHR ptr cChars[4]                         ;mov edx, 0D834DD1Eh  mov DCHR ptr cChars[0], edx
          mov [xdi].TVENTRY.dCharCount, 2                ;m2z CHR ptr cChars[4]
        .else
          mov CHR ptr cChars[0], ax
          m2z CHR ptr cChars[2]
          mov [xdi].TVENTRY.dCharCount, 1
        .endif
      endif
      mov [xdi].TVENTRY.pText, $invoke(StrNew, addr cChars)
      mov xax, [xdi].TVENTRY.pStyle
      invoke SelectObject, [xsi].hMemDC,  [xax].TVSTYLE.hFont
      invoke DrawText, [xsi].hMemDC, [xdi].TVENTRY.pText, -1, addr [xdi].TVENTRY.Extent, DT_CALCRECT
      mov xax, [xdi].TVENTRY.pStyle
      mov ecx, [xax].TVSTYLE.TextMetric.tmOverhang
      sub [xdi].TVENTRY.Extent.right, ecx
      mov [xdi].TVENTRY.dType, TVET_TEXT                 ;Mutate from TVET_CMD to TVET_TEXT
      mov [xdi].TVENTRY.pHandler, NULL
      jmp @@EndHandler

    TVCH_TAB::
;      DbgText "TAB"
      mov edx, dLineLength
      add edx, dLineIndent
      OCall xsi.GetNextTabStop, edx
      .if xax != NULL
        .if [xax].TVTABSTOP.bType == TVTAB_TYPE_LEFT
          mov ecx, [xax].TVTABSTOP.dPosition
          sub ecx, dLineLength
          sub ecx, dLineIndent
        .else
          mov xbx, xax
          OCall xsi.GetNextTextOrTab, dCurEntryIndex
          .if xax != NULL
            .if [xbx].TVTABSTOP.bType == TVTAB_TYPE_CENTER
              mov ecx, [xbx].TVTABSTOP.dPosition
              mov edx, [xax].TVENTRY.Extent.right
              shr edx, 1
              sub ecx, edx
              sub ecx, dLineIndent
              sub ecx, dLineLength
            .elseif [xbx].TVTABSTOP.bType == TVTAB_TYPE_RIGHT
              mov ecx, [xbx].TVTABSTOP.dPosition
              mov edx, [xax].TVENTRY.Extent.right
              sub ecx, edx
              sub ecx, dLineLength
              sub ecx, dLineIndent
            .endif
          .else
            xor ecx, ecx
          .endif
        .endif
      .else
        ;Get the size of dTab2Spaces spaces
        mov xax, [xdi].TVENTRY.pStyle
        invoke SelectObject, [xsi].hMemDC,  [xax].TVSTYLE.hFont
        invoke DrawText, [xsi].hMemDC, $OfsCStr(" "), -1, addr [xdi].TVENTRY.Extent, DT_CALCRECT
        mov xax, [xdi].TVENTRY.pStyle
        mov ecx, [xdi].TVENTRY.Extent.right
        sub ecx, [xax].TVSTYLE.TextMetric.tmOverhang
        imul ecx, [xsi].dTab2Spaces
      .endif
      mov [xdi].TVENTRY.Extent.right, ecx
      jmp @@EndHandler


    TVCH_DRAW::
;      DbgText "BACKDRAW"
      mov DrawNotification.Header.code, TVNMC_DRAW
      m2m DrawNotification.Header.hwndFrom, [xsi].hWnd, xcx
      mov DrawNotification.Header.idFrom, xdx
      m2m DrawNotification.dID, [xdi].TVENTRY.dValue, edx
      m2m DrawNotification.hDC, [xsi].hMemDC, xcx
      s2s DrawNotification.Position, CurLinePos, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      m2m DrawNotification.dLineHeight, dMaxHeight, xdx
      s2s DrawNotification.Extent, [xsi].Extent, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      s2s DrawNotification.Padding, [xsi].Padding, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      m2m DrawNotification.pStyle, [xdi].TVENTRY.pStyle, xcx
      invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr DrawNotification
      jmp @@EndHandler

    TVCH_LINE::
;      DbgText "LINE"
      mov xax, [xdi].TVENTRY.pStyle
      mov ecx, [xax].TVSTYLE.TextMetric.tmHeight
      mov ebx, ecx
      shr ebx, 1
      add ebx, CurLinePos.y
      add ecx, [xax].TVSTYLE.TextMetric.tmExternalLeading
      add CurLinePos.y, ecx

      mov eax, [xsi].Extent.y
      sub eax, [xsi].Padding.bottom
      .if eax > ebx
        mov edx, [xsi].Padding.left
        add edx, dLineIndent
        invoke MoveToEx, [xsi].hMemDC, edx, ebx, NULL
        mov edx, [xsi].Padding.left
        add edx, DrawExtent.x
        invoke LineTo, [xsi].hMemDC, edx, ebx
      .endif
      jmp @@EndHandler

    TVCH_COVER::
;      DbgText "FOREDRAW"
      MemAlloc TVNM_DRAW
      mov [xax].TVNM_DRAW.Header.code, TVNMC_DRAW
      m2m [xax].TVNM_DRAW.Header.hwndFrom, [xsi].hWnd, xcx
      mov [xax].TVNM_DRAW.Header.idFrom, xdx
      m2m [xax].TVNM_DRAW.dID, [xdi].TVENTRY.dValue, edx
      m2m [xax].TVNM_DRAW.hDC, [xsi].hMemDC, xcx
      s2s [xax].TVNM_DRAW.Position, CurLinePos, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      m2m [xax].TVNM_DRAW.dLineHeight, dMaxHeight, xdx
      s2s [xax].TVNM_DRAW.Extent, [xsi].Extent, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      s2s [xax].TVNM_DRAW.Padding, [xsi].Padding, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      m2m [xax].TVNM_DRAW.pStyle, [xdi].TVENTRY.pStyle, xcx
      OCall [xsi].CoverTasks::DataCollection.Insert, xax
      jmp @@EndHandler

    TVCH_PARA::
;      DbgText "PARA"
      add dCurEntryIndex, 1
      m2z dHanging
      .break

    TVCH_TABL::
;      DbgText "TABL"
      MemAlloc sizeof(TVTABSTOP)
      m2m [xax].TVTABSTOP.dPosition, [xdi].TVENTRY.dValue, ecx
      mov [xax].TVTABSTOP.bType, TVTAB_TYPE_LEFT
      OCall [xsi].$Obj(TextView).TabStops::DataCollection.Insert, xax
      jmp @@EndHandler

    TVCH_TABC::
;      DbgText "TABC"
      MemAlloc sizeof(TVTABSTOP)
      m2m [xax].TVTABSTOP.dPosition, [xdi].TVENTRY.dValue, ecx
      mov [xax].TVTABSTOP.bType, TVTAB_TYPE_CENTER
      OCall [xsi].$Obj(TextView).TabStops::DataCollection.Insert, xax
      jmp @@EndHandler

    TVCH_TABR::
;      DbgText "TABR"
      MemAlloc sizeof(TVTABSTOP)
      m2m [xax].TVTABSTOP.dPosition, [xdi].TVENTRY.dValue, ecx
      mov [xax].TVTABSTOP.bType, TVTAB_TYPE_RIGHT
      OCall [xsi].TabStops::DataCollection.Insert, xax
      jmp @@EndHandler


    TVCH_BREAK::
;      DbgText "BREAK"
      add dCurEntryIndex, 1
      m2z dHanging
      .break


    TVCH_SIZE_X::                                       ;Evaluated in GetExtent method
;      DbgText "TVCH_SIZE.X"
      jmp @@EndHandler

    TVCH_SIZE_Y::
;      DbgText "TVCH_SIZE.Y"                            ;Evaluated in GetExtent method
      jmp @@EndHandler

    TVCH_TABCLR::
;      DbgText "TABCLR"
      OCall [xsi].TabStops::DataCollection.DisposeAll
      jmp @@EndHandler


    TVCH_PADDING::
;      DbgText "PADDING"
      mov ecx, [xdi].TVENTRY.dValue
      mov [xsi].Padding.left, ecx
      mov [xsi].Padding.top, ecx
      mov [xsi].Padding.right, ecx
      mov [xsi].Padding.bottom, ecx
      shl ecx, 1
      mov eax, [xsi].Extent.x
      sub eax, ecx
      mov DrawExtent.x, eax
      mov eax, [xsi].Extent.y
      sub eax, ecx
      mov DrawExtent.y, eax
      s2s CurLinePos, POINT ptr [xsi].Padding, xax, xcx, xdx, xmm0
      jmp @@EndHandler


    TVCH_PADDINGBOT::
;      DbgText "PADDING.BOTTOM"
      m2m [xsi].Padding.bottom, [xdi].TVENTRY.dValue, ecx
      mov eax, [xsi].Extent.y
      sub eax, ecx
      sub eax, [xsi].Padding.top
      mov DrawExtent.y, eax
      m2m CurLinePos.y, [xsi].Padding.top, ecx
      jmp @@EndHandler

    TVCH_PADDINGLFT::
;      DbgText "PADDING.LEFT"
      m2m [xsi].Padding.left, [xdi].TVENTRY.dValue, ecx
      mov eax, [xsi].Extent.x
      sub eax, ecx
      sub eax, [xsi].Padding.right
      mov DrawExtent.x, eax
      mov CurLinePos.x, ecx
      jmp @@EndHandler

    TVCH_PADDINGRGT::
;      DbgText "PADDING.RIGHT"
      m2m [xsi].Padding.right, [xdi].TVENTRY.dValue, ecx
      mov eax, [xsi].Extent.x
      sub eax, ecx
      sub eax, [xsi].Padding.left
      mov DrawExtent.x, eax
      m2m CurLinePos.x, [xsi].Padding.left, ecx
      jmp @@EndHandler

    TVCH_PADDINGTOP::
;      DbgText "PADDING.TOP"
      m2m [xsi].Padding.top, [xdi].TVENTRY.dValue, ecx
      mov eax, [xsi].Extent.y
      sub eax, ecx
      sub eax, [xsi].Padding.bottom
      mov DrawExtent.y, eax
      m2m CurLinePos.y, [xsi].Padding.top, ecx

      ;##/
      ; —————————————————————————————————————————————————————————————
@@EndHandler:

      .if [xdi].TVENTRY.dType == TVET_TEXT
        add dAdjacentTextItems, 1
      .endif

      mov xcx, [xdi].TVENTRY.pStyle

      .ifBitSet [xcx].TVSTYLE.dFlags, TVSF_BOX
        add dBoxed, 1
        m2m BoxColor, [xcx].TVSTYLE.BoxColor, edx
      .endif

      .if [xdi].TVENTRY.dType != TVET_CMD
        mov dMaxAscent, $uMax(dMaxAscent, [xcx].TVSTYLE.TextMetric.tmAscent, eax)
        mov dMaxDescent, $uMax(dMaxDescent, [xcx].TVSTYLE.TextMetric.tmDescent, eax)
        mov dMaxExtLeading, $uMax(dMaxExtLeading, [xcx].TVSTYLE.TextMetric.tmExternalLeading, eax)
        m2m dLineAlignment, [xcx].TVSTYLE.dAlignment, eax
      .endif

      .if dHanging
        mov edx, [xcx].TVSTYLE.dHanging
      .else
        mov edx, [xcx].TVSTYLE.dIndent
      .endif
      mov dLineIndent, $uMax(dLineIndent, edx)
      mov ecx, [xcx].TVSTYLE.TextMetric.tmOverhang      ;Overhang of the last TVArea
      mov eax, [xdi].TVENTRY.Extent.right
      mov edx, dLineLength
      add edx, dLineIndent
      add edx, ecx
      add edx, eax

      .if [xdi].TVENTRY.dType == TVET_BLANK
        .ifBitSet [xsi].dFormatFlags, TV_WORDBREAK
          .if edx > DrawExtent.x && dLineLength > 0       ;We have at least one visible area drawn
            .if [xdi].TVENTRY.dType != TVET_CMD
              add dHanging, 1
              mov ecx, dAdjacentTextItems
              sub dLineLastEntryIndex, ecx
              .break
            .endif
          .endif
        .endif
      .endif

      .if [xdi].TVENTRY.dType == TVET_BLANK
        mov dAdjacentTextItems, 0
      .endif

      add dLineLength, eax
      add dCurEntryIndex, 1
    .endw                                               ;End line metric analysis

    ;——————————————————————————————————————————————————————————————————————————

    ;Calculate dMaxHeight for the current line
    mov eax, dMaxAscent
    add eax, dMaxDescent
    mov dMaxHeight, eax

    ;Calculate alignment and fill the gap on the front, including the indent
    .if dLineAlignment == TVALIGN_RIGHT
      mov eax, DrawExtent.x
      sub eax, dLineIndent
      sub eax, dLineLength
    .elseif dLineAlignment == TVALIGN_CENTER
      mov eax, DrawExtent.x
      sub eax, dLineIndent
      sub eax, dLineLength
      sar eax, 1
    .else
      xor eax, eax
    .endif

    add eax, dLineIndent
    .if SDWORD ptr eax > 0
      add CurLinePos.x, eax
    .endif

    ;——————————————————————————————————————————————————————————————————————————

    .if dBoxed
      mov eax, [xsi].Padding.left
      mov edx, dLineIndent
      add edx, eax
      mov BoxRect.left, edx
      mov edx, DrawExtent.x
      add edx, eax
      mov BoxRect.right, edx

      mrm BoxRect.top, CurLinePos.y, edx
      add edx, dMaxHeight
      mov BoxRect.bottom, edx
      invoke IntersectRect, addr OutRect, addr DrawRect, addr BoxRect
      mov hBrush, $invoke(CreateSolidBrush, BoxColor)
      invoke FillRect, [xsi].hMemDC, addr OutRect, xax
      invoke DeleteObject, hBrush
    .endif

    ;Draw all Entries of the current line
    .while TRUE
      mov edx, dLineFirstEntryIndex
      .break .if edx > dLineLastEntryIndex

      mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, edx)

      mov xbx, [xdi].TVENTRY.pStyle                    ;xbx -> TVSTYLE
      .if [xdi].TVENTRY.pText != NULL
        mrm [xdi].TVENTRY.Area.left, CurLinePos.x, edx
        add edx, [xdi].TVENTRY.Extent.right
        mov ecx, DrawExtent.x
        add ecx, [xsi].Padding.left
        .if edx > ecx
          mov edx, ecx
        .endif
        mov [xdi].TVENTRY.Area.right, edx
        mov NewLinePos.x, edx

        .ifBitSet [xbx].TVSTYLE.dFlags, TVSF_SUP
          ;[SUP] text
          mov edx, CurLinePos.y
          add edx, dMaxAscent
          sub edx, dLastAscent
          mov [xdi].TVENTRY.Area.top, edx
          add edx, [xbx].TVSTYLE.TextMetric.tmHeight
          mov [xdi].TVENTRY.Area.bottom, edx
        .elseIfBitSet [xbx].TVSTYLE.dFlags, TVSF_SUB
          ;[SUB] text
          mov edx, CurLinePos.y
          add edx, dMaxAscent
          add edx, dLastDescent
          mov [xdi].TVENTRY.Area.bottom, edx
          sub edx, [xbx].TVSTYLE.TextMetric.tmHeight
          mov [xdi].TVENTRY.Area.top, edx
        .else
          ;Regular text
          mov eax, dMaxAscent
          mrm dLastAscent, [xbx].TVSTYLE.TextMetric.tmAscent, ecx   ;Remember this value
          sub eax, ecx                                  ;Y offset
          mrm dLastDescent, [xbx].TVSTYLE.TextMetric.tmDescent, ecx ;Remember this value
          mov edx, CurLinePos.y
          add edx, eax
          mov [xdi].TVENTRY.Area.top, edx
          add edx, [xbx].TVSTYLE.TextMetric.tmHeight
          mov [xdi].TVENTRY.Area.bottom, edx
        .endif
        invoke SetTextColor, [xsi].hMemDC, [xbx].TVSTYLE.TextColor
        invoke SelectObject, [xsi].hMemDC,  [xbx].TVSTYLE.hFont

        ;If the style background color is not the default color, then draw a new background
        invoke IntersectRect, addr OutRect, addr DrawRect, addr [xdi].TVENTRY.Area
        mov ecx, [xbx].TVSTYLE.BackColor
        .if ecx != [xsi].DefaultBackColor
          invoke FillRect, [xsi].hMemDC, addr OutRect, [xbx].TVSTYLE.hBackBrush
        .endif
        invoke DrawText, [xsi].hMemDC, [xdi].TVENTRY.pText, -1, addr OutRect, 0; or DT_NOCLIP

        .ifBitSet [xbx].TVSTYLE.dFlags, TVSF_ACTIVE
          OCall [xsi].ActiveAreas::DataCollection.Insert, xdi
          m2m [xdi].TVENTRY.dValue, [xbx].TVSTYLE.dID, eax
        .endif

        .ifBitSet [xbx].TVSTYLE.dFlags, TVSF_INFO
          ;Set up "tool" information
          mov ToolInfo.cbSize, sizeof(TOOLINFO)
          s2s ToolInfo.rect, [xdi].TVENTRY.Area, xax, xcx, xmm0, xmm1, xmm2, xmm3
          mov ToolInfo.uFlags, TTF_SUBCLASS
          m2m ToolInfo.hwnd, [xsi].hWnd, xax
          m2m ToolInfo.hinst, hInstance, xcx
          mov eax, [xbx].TVSTYLE.dID
          mov ToolInfo.uId, xax

          mov InfoNotification.dID, eax
          mov InfoNotification.Header.code, TVNMC_INFO
          m2m InfoNotification.Header.hwndFrom, [xsi].hWnd, xcx
          mov InfoNotification.Header.idFrom, xax
          mov InfoNotification.pText, NULL
          invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr InfoNotification

          m2m ToolInfo.lpszText, InfoNotification.pText, xcx
          invoke SendMessage, [xsi].hToolTip, TTM_ADDTOOL, 0, addr ToolInfo ;Associate the tooltip
        .endif

        m2m CurLinePos.x, NewLinePos.x, ecx
      .else
        mov ecx, [xdi].TVENTRY.Extent.right
        .if ecx != 0
          ;{TAB}
          mov edx, [xdi].TVENTRY.Extent.right
          add CurLinePos.x, edx
        .endif
      .endif
      add dLineFirstEntryIndex, 1
    .endw

    mov edx, dMaxHeight
    add edx, dMaxExtLeading
    add CurLinePos.y, edx
    m2m CurLinePos.x, [xsi].Padding.left, eax

    mov xcx, offset TVCH_PARA
    .if [xdi].TVENTRY.pHandler == xcx
      mov edx, dMaxHeight
      mov ecx, CurLinePos.y
      shr edx, 1
      add ecx, edx
      mov CurLinePos.y, ecx
    .endif
  .endw

  ;Final step: call all parent foreground drawing tasks on the just drawn TextView background
  .for (ebx = 0 : ebx != [xsi].CoverTasks.dCount : ebx++)
    OCall [xsi].CoverTasks::DataCollection.ItemAt, ebx
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, xax
  .endfor

  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Reset
; Purpose:    Reset all collections, freeing associated resources.
; Arguments:  None.
; Return:     Nothing.

Method TextView.Reset, uses xsi
  SetObject xsi
  OCall [xsi].Entries::DataCollection.DisposeAll
  OCall [xsi].ActiveAreas::DataCollection.DeleteAll
  OCall [xsi].Styles::DataCollection.DisposeAll
  OCall [xsi].StyleStack::XWCollection.DeleteAll
  OCall [xsi].TabStops::SortedDataCollection.DisposeAll
  OCall [xsi].GdiObjects::XWCollection.DisposeAll
  OCall [xsi].CoverTasks::DataCollection.DisposeAll
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Show
; Purpose:    Present the processed markup string.
; Arguments:  None.
; Return:     Nothing.

Method TextView.Show, uses xsi
;  DbgText "TextView.Show"
  SetObject xsi
  OCall xsi.Reset
  OCall xsi.Parse
  OCall xsi.Render
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Startup
; Purpose:    Register the TextView window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method TextView.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(TextView.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, 0;COLOR_WINDOW + 1
  m2z WC.lpszMenuName
  %mov xax, offset cTextViewClass&TARGET_STR_AFFIX
  mov WC.lpszClassName, xax
  m2z WC.hIcon
  m2z WC.hCursor
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method TextView.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg, "TextView.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(TextView)
      invoke GetParent, pSelf
      mov [xsi].$Obj(TextView).hParent, xax
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      ACall xsi::TextView.Init, xax, pSelf
      BitSet [xsi].$Obj(TextView).dFlags, TVWF_AUTO
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      mrm [xsi].$Obj(TextView).hWnd, pSelf, xax
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::TextView.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::TextView.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(TextView).dFlags, TVWF_AUTO
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedures: TVSH_xxx
; Purpose:    Handler for TextView TVSTYLE changes.
; Arguments:  Arg1: xsi -> TextView object.
;             Arg2: xdi -> TVSTYLE.
;             Arg3: -> Buffer.
; Return:     eax = Indicates what was changed and needs to be updated.

;##\
TVSH_APP proc pBuffer:POINTER
;  DbgText "APP"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, -1
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dID, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_ACTIVE
  mov eax, TVSC_NOTHING
  ret
TVSH_APP endp

TVSH_BOX proc pBuffer:POINTER
;  DbgText "BOX"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).DefaultBackColor
  .else
    mov eax, [xcx]
    BGR2RGB eax                                         ;Swap Red <-> Blue
  .endif
  mov [xdi].TVSTYLE.BoxColor, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_BOX
  mov eax, TVSC_NOTHING
  ret
TVSH_BOX endp

TVSH_SUB proc pBuffer:POINTER
;  DbgText "SUB"
  mov eax, [xdi].TVSTYLE.dFontSize
  shl eax, 1
  cdiv 3
  mov [xdi].TVSTYLE.dFontSize, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_SUB
  mov eax, TVSC_FONT
  ret
TVSH_SUB endp

TVSH_SUP proc pBuffer:POINTER
;  DbgText "SUP"
  mov eax, [xdi].TVSTYLE.dFontSize
  shl eax, 1
  cdiv 3
  mov [xdi].TVSTYLE.dFontSize, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_SUP
  mov eax, TVSC_FONT
  ret
TVSH_SUP endp


TVSH_BOLD proc pBuffer:POINTER
;  DbgText "BOLD"
  mov [xdi].TVSTYLE.LogFont.lfWeight, FW_BOLD
  mov eax, TVSC_FONT
  ret
TVSH_BOLD endp

TVSH_FONT proc pBuffer:POINTER
;  DbgText "FONT"
  lea xcx, [xdi].TVSTYLE.LogFont.lfFaceName
  mov xdx, pBuffer
  .if xdx == NULL
    mov xdx, [xsi].$Obj(TextView).pDefaultFontFace
  .endif
  invoke StrCopy, xcx, xdx
  mov eax, TVSC_FONT
  ret
TVSH_FONT endp

TVSH_INFO proc pBuffer:POINTER
;  DbgText "INFO"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, -1
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dID, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_INFO
  mov eax, TVSC_NOTHING
  ret
TVSH_INFO endp


TVSH_ALIGN proc pBuffer:POINTER
;  DbgText "ALIGN"
  .if pBuffer == NULL
    mov [xdi].TVSTYLE.dAlignment, TVALIGN_LEFT
  .else
    invoke StrIComp, pBuffer, $OfsCStr("RIGHT")
    .if eax == 0
      mov [xdi].TVSTYLE.dAlignment, TVALIGN_RIGHT
    .else
      invoke StrIComp, pBuffer, $OfsCStr("CENTER")
      .if eax == 0
        mov [xdi].TVSTYLE.dAlignment, TVALIGN_CENTER
      .else
        mov [xdi].TVSTYLE.dAlignment, TVALIGN_LEFT
      .endif
    .endif
  .endif
  mov xcx, pBuffer

  mov eax, TVSC_NOTHING
  ret
TVSH_ALIGN endp

TVSH_COLOR proc pBuffer:POINTER
;  DbgText "COLOR"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).DefaultTextColor
  .else
    mov eax, [xcx]
    BGR2RGB eax                                         ;Swap Red <-> Blue
  .endif
  mov [xdi].TVSTYLE.TextColor, eax
  mov eax, TVSC_NOTHING
  ret
TVSH_COLOR endp


TVSH_HEIGHT proc pBuffer:POINTER
;  DbgText "HEIGHT"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).dDefaultFontSize
  .else
    .ifBitSet [xdi].TVSTYLE.dFlags, TVSF_INCR
      mov eax, [xdi].TVSTYLE.dFontSize
      add eax, [xcx]
    .elseIfBitSet [xdi].TVSTYLE.dFlags, TVSF_DECR
      mov eax, [xdi].TVSTYLE.dFontSize
      sub eax, [xcx]
      .if SIGN?
        xor eax, eax
      .endif
    .else
      mov eax, [xcx]
    .endif
    BitClr [xdi].TVSTYLE.dFlags, TVSF_INCR or TVSF_DECR
  .endif
  mov [xdi].TVSTYLE.dFontSize, eax
  mov eax, TVSC_FONT
  ret
TVSH_HEIGHT endp

TVSH_INDENT proc pBuffer:POINTER
;  DbgText "INDENT"
  ?mov xcx, pBuffer
  .if xcx == NULL
    xor eax, eax
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dIndent, eax
  mov eax, TVSC_NOTHING
  ret
TVSH_INDENT endp

TVSH_ITALIC proc pBuffer:POINTER
;  DbgText "ITALIC"
  mov [xdi].TVSTYLE.LogFont.lfItalic, TRUE
  mov eax, TVSC_FONT
  ret
TVSH_ITALIC endp


TVSH_BGCOLOR proc pBuffer:POINTER
;  DbgText "BGCOLOR"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).DefaultBackColor
  .else
    mov eax, [xcx]
    BGR2RGB eax                                         ;Swap Red <-> Blue
  .endif
  mov [xdi].TVSTYLE.BackColor, eax
  mov eax, TVSC_BACKCOLOR
  ret
TVSH_BGCOLOR endp

TVSH_HANGING proc pBuffer:POINTER
;  DbgText "HANGING"
  ?mov xcx, pBuffer
  .if xcx == NULL
    xor eax, eax
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dHanging, eax
  mov eax, TVSC_NOTHING
  ret
TVSH_HANGING endp


TVSH_STRIKEOUT proc pBuffer:POINTER
;  DbgText "STRIKEOUT"
  mov [xdi].TVSTYLE.LogFont.lfStrikeOut, TRUE
  mov eax, TVSC_FONT
  ret
TVSH_STRIKEOUT endp

TVSH_UNDERLINE proc pBuffer:POINTER
;  DbgText "UNDERLINE"
  mov [xdi].TVSTYLE.LogFont.lfUnderline, TRUE
  mov eax, TVSC_FONT
  ret
TVSH_UNDERLINE endp
;##/

endif
