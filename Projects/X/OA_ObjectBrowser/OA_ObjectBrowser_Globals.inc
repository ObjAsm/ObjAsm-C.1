; ==================================================================================================
; Title:      OA_ObjectBrowser_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Object Browser globals.
; Notes:      Version C.1.0, December 2020
;               - First release.
; ==================================================================================================


include OA_ObjectBrowser_Shared.inc

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


;String szMarkupText,"{Padding 20}{AutoLineBreak}", \
;                    "[H +3, CANVAS #FFFFFF]", \
;                      "{LINE}", \
;                    "[~]"


APP_VISIT     equ   0
APP_EMAIL     equ   1
APP_CHECK     equ   2

INFO_BUILD    equ   0
INFO_UPDATE   equ   1

String szMarkupText,  "{PA20,Z}", \
                      "[H+2,Canvas#FFFFFF]", \
                        "[H+1]Settings:[~]{P}", \
                        "[FI20,HI20,C#0000F0]", \
                          "[C#0000F0,App0][TXT0,F'Lucida Sans Unicode']?[~] Option 1[~]   [TIP", @CatStr(<!">, %INFO_UPDATE, <!">), ",F'Webdings',H-2]{#69}[~]{B}", \
                          "[C#F00000,App1][TXT1,F'Lucida Sans Unicode']?[~] Option 2[~]{P}", \
                          "[C#007000,App2][TXT2,F'Wingdings 2']?[~] Option 3[~]{B}", \
                          "[C#000000,App3][TXT3,F'Wingdings 2']?[~] Option 4[~]{B}{B}", \
                        "[~]", \
                        "[I]Ken Carpenter[~]{B}", \
                        "[F'Lucida Console',H-1,C#5C5C5C,BOX#CEDBE5]This example{TAB}uses the following tags: {#7B}TAB} {#5B}BOX #CEDBE5], {#7B}BREAK}, {#5B}color=#5C5C5C]{B}", \
                        "And the following end tags: {#5B}~][~]{B}", \
                        "[App0,C#0066D5]Google[~] test{P}", \
                        '[I,C#5C5C5C,G#D1D1D1,AC,H+2,BOX#D1D1D1] "Man is still the most extraordinary computer of all." [~]{B}', \
                        "- John F. Kennedy{B}", \
                        "{LINE}", \
                        "Click on this [App1,C#0066D5]link[~] to show a message box{P}"
ExtendString            "[FI10,HI30]{TL30}", \
                          "{#2981,T}List 1 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                          "{#2981,T}List 1 - [B]Second Item[~]{P}", \
                          "[B]1.[~]{T}List 2 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                          "[B]2.[~]{T}List 2 - [B]Second Item[~]{P}"
ExtendString              "{#2981,T}List 3 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                          "{#2981,T}List 3 - [B]Second Item[~]{B}", \
                          "[FI30,HI50]{TL50}", \
                            "{#2022,T}List 3 - Lvl 2 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                            "{#2022,T}List 3 - Lvl 2 - [B]Second Item[~]{B}", \
                          "[~]", \
                          "{#2981,T}List 3 - [B]Third Item[~]{B}", \
                          "[TIP", @CatStr(<!">, %INFO_UPDATE, <!">), ",F'Webdings',H+1]{#69}[~]", \
                        "[~]", \
                      "[~]"

;String szMarkupText,  "{PA20,ALB,Z}", \
;                      "[H+1]", \
;                        "{C0}", \
;                        "[FI150,HI150,AL]", \
;                          "[H+3,B]&ABOUT_TEXT{B}[~]", \
;                          "[I]Version &VER_PRODUCTVERSION_STR{P}[~]", \
;                          "[C#3F3F3F]", \
;                            "Designed with ObjAsm{B}", \
;                            "© &COPYRIGHT{P}", \
;                            "[C#5F4FFF]", \
;                              @CatStr(<!">, %BUILD_DATE_STR, \
;                                      <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
;                                      %TARGET_MODE_STR, <->, %TARGET_BITNESS, <    !">), \
;                              "[TIP", @CatStr(<!">, %INFO_BUILD, <!">), ",F'Webdings',H+1]{#69}[~]", \
;                            "[~]{B}{B}", \
;                          "[~]", \
;                        "[~]"
;ExtendString            "[FI0,HI0,AC]", \
;                          "[F'Webdings',C#FF5F5F,H+7]{#7E}[~]", \
;                          "  Visit us at  ", \
;                          "[APP", @CatStr(<!">, %APP_VISIT, <!">),",C#0000FF,U]www.objasm.x10host.com[~]{B}", \
;                          "[F'Wingdings',C#408090,H+1]{#2A}[~]", \
;                          "   Email us to  ", \
;                          "[APP", @CatStr(<!">, %APP_EMAIL, <!">),",C#0000FF,U]objasm@gmx.net[~]{P}", \
;                          "[APP", @CatStr(<!">, %APP_CHECK, <!">),",C#0000FF,U]Check for updates[~]", \
;                          "[TIP", @CatStr(<!">, %INFO_UPDATE, <!">), ",F'Webdings',H+1,C#5F5FFF]  {#69}[~]", \
;                        "[~]", \
;                      "[~]"

;String szMarkupText,  "{PA20,Z}", \
;                      "[H+3,Canvas#FFFFFF]", \
;                        "Beauty, success, truth ...{B}", \
;                        "[I]He is blessed who has two.[~]{B}", \
;                        "[C#C00000,B]Your program has none.[~]{P}", \
;                        "[I]Ken Carpenter[~]{B}", \
;                        "[F'Lucida Console',H-1,C#5C5C5C,BOX#CEDBE5]This example{TAB}uses the following tags: {#7B}TAB} {#5B}BOX #CEDBE5], {#7B}BREAK}, {#5B}color=#5C5C5C]{B}", \
;                        "And the following end tags: {#5B}~][~]{B}", \
;                        "[App0,C#0066D5]Google[~] test{P}", \
;                        '[I,C#5C5C5C,G#D1D1D1,AC,H+2,BOX#D1D1D1] "Man is still the most extraordinary computer of all." [~]{B}', \
;                        "- John F. Kennedy{B}", \
;                        "{LINE}", \
;                        "Click on this [App1,C#0066D5]link[~] to show a message box{P}"
;ExtendString            "[FI10,HI30]{TL30}", \
;                          "{#2981,T}List 1 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
;                          "{#2981,T}List 1 - [B]Second Item[~]{P}", \
;                          "[B]1.[~]{T}List 2 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
;                          "[B]2.[~]{T}List 2 - [B]Second Item[~]{P}"
;ExtendString              "{#2981,T}List 3 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
;                          "{#2981,T}List 3 - [B]Second Item[~]{B}", \
;                          "[FI30,HI50]{TL50}", \
;                            "{#2022,T}List 3 - Lvl 2 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
;                            "{#2022,T}List 3 - Lvl 2 - [B]Second Item[~]{B}", \
;                          "[~]", \
;                          "{#2981,T}List 3 - [B]Third Item[~]{B}", \
;                          "[TIP", @CatStr(<!">, %INFO_UPDATE, <!">), ",F'Webdings',H+1]{#69}[~]", \
;                        "[~]", \
;                      "[~]"
                      
;CStr szMarkupText,    "{PA20,Z}", \
;                      "{TC140}{TR220}", \
;                      "[H+2,B,U]", \
;                        "Description{T}Qty{T}Price{P}", \
;                      "[~]", \
;                      "[FI25,C#4F4FFF,H+2,I]", \
;                          "{#2022} Item[SUB]1[~]{T}2{T}2.35[SUP]*[~]{B}", \
;                          "{#2022} Item[SUB]2[~]{T}200.0{T}20.00[SUP]**[~]{B}", \
;                          "{#2022} Item[SUB]3[~]{T}0.1{T}0.23{B}{P}", \
;                      "[~]", \
;                      "{TABCLR}{TC80}{TL95}", \
;                      "[FI30,C#4F4F4F]", \
;                        "Note:{T}*{T}Volume discount{B}", \
;                        "{T}**{T}Regular discount{B}", \
;                      "[~]", \
;                      "{1}"
                    
;CStr szMarkupText,    "{Padding 20}", \
;                      "{TABC 140}{TABR 220}", \
;                      "[Indent 10, H +2, Bold, Underline]", \
;                        "Description{TAB}Qty{TAB}Price{P}", \
;                      "[~]", \
;                      "[Indent 25, Color #4F4FFF, H +2, Italic]", \
;                          "{#2022} Item[SUB]1[~]{TAB}2{TAB}2.35[SUP]*[~]{B}", \
;                          "{#2022} Item[SUB]2[~]{TAB}200.0{TAB}20.00[SUP]**[~]{B}", \
;                          "{#2022} Item[SUB]3[~]{TAB}0.1{TAB}0.23{B}{P}", \
;                      "[~]", \
;                      "{TABCLR}{TABC 80}{TABL 95}", \
;                      "[Indent 30, Color #4F4F4F]", \
;                        "Note:{TAB}*{TAB}Volume discount{B}", \
;                        "{TAB}**{TAB}Regular discount", \
;                      "[~]", \
;                      "{C1}"

CStr szIcoName,       "ICON_APP"

;Setup strings
CStr  cViewer,        "Viewer"
CStr  cDefViewer,     "Notepad.exe"           ;Default string
CStr  cLanguage,      "Language"
CStr  cShowRedefMtds, "ShowRedefinedMethods"
CStr  cShowRedefVars, "ShowRedefinedVariables"

CStr  cCodePath,      "\Code\"
CStr  cShow,          "show"
CStr  cViewerError,   "Can't start the specified viewer.", 13, 10, "Please check the application setup.", 13, 10
CStr  cPNG,           "PNG"
CStr  cOpen,          "open"

INFO_TYPE_OBJECT      equ   0                 ;Link type encoded in the char color
INFO_TYPE_INTERFACE   equ   1


HTML_VAROBJ           CHRA  'VarObj'          ;Object
HTML_VARDAT           CHRA  'VarDat'          ;Regular data
HTML_VARRDT           CHRA  'VarRDt'          ;Redefined data
HTML_INTMTD           CHRA  'IntMtd'
HTML_INTDSP           CHRA  'IntDsp'
HTML_SHOW             CHRA  'Show'
HTML_HIDE             CHRA  'Hide'
HTML_EDIT             CHRA  'Edit'
HTML_OPEN_HREF        CHRA  '<a href="'
HTML_CLOSE_HREF       CHRA  '</a>'
HTML_CLOSE_TAG        CHRA  '">'
HTML_OPEN_BOLD        CHRA  '<b>'
HTML_CLOSE_BOLD       CHRA  '</b>'
HTML_OPEN_ITALIC      CHRA  '<i>'
HTML_CLOSE_ITALIC     CHRA  '</i>'
HTML_COLOR_BLACK      CHRA  'color="#000000">'
HTML_COLOR_GRAY       CHRA  'color="#8F8F8F">'
HTML_COLOR_RED        CHRA  'color="#FF0000">'
HTML_BREAK            CHRA  '<br />'
HTML_SPACE            CHRA  '&nbsp;'
HTML_SEPARATOR        CHRA  '&nbsp;'
HTML_REGULAR          CHRA  '&ndash;&ndash;'
HTML_OK               CHRA  'OK'
HTML_UNKNOWN          CHRA  '[unknown]'
HTML_OUTDATED         CHRA  '[Outdated]'
HTML_ABSTRACT         CHRA  'Abstract'
HTML_TPL_DEFAULTS     CHRA  '[Template defaults]'



;HTML Document
HTML_DOC_00           CHRA  '<html>', 13, 10
                      CHRA  '  <head>', 13, 10
                      CHRA  '    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />', 13, 10
                      CHRA  '    <title>ObjAsm Properties of '
HTML_DOC_00_SIZE      equ $ - HTML_DOC_00

HTML_DOC_01           CHRA  '</title>', 13, 10
                      CHRA  '  </head>', 13, 10
                      CHRA  '  <script language="JavaScript">', 13, 10
                      CHRA  '    function OnClick(Type, ID)', 13, 10
                      CHRA  '    {y=window.external.OnClick(Type, ID);}', 13, 10
                      CHRA  '  </script>', 13, 10
                      CHRA  13, 10
                      CHRA  '  <body>', 13, 10
                      CHRA  '    <form>', 13, 10
HTML_DOC_01_SIZE      equ $ - HTML_DOC_01

HTML_DOC_99           CHRA  '    </form>', 13, 10
                      CHRA  '  </body>', 13, 10
                      CHRA  '</html>', 13, 10
HTML_DOC_99_SIZE      equ $ - HTML_DOC_99


;Object / Interface desciption
HTML_DSC_00           CHRA  '    <font size="2" face="Tahoma" color="#000000"><b><u>Name</u>:</b></font>', 13, 10
                      CHRA  '    <font size="2" face="Tahoma" color="#000000"> '
HTML_DSC_00_SIZE      equ $ - HTML_DSC_00

HTML_DSC_01           CHRA  '</font><br />', 13, 10
                      CHRA  '    <font size="1"><br /></font>', 13, 10
HTML_DSC_01_SIZE      equ $ - HTML_DSC_01

HTML_DSC_02           CHRA  '    <table cellspacing="0" cellpadding="0">', 13, 10
                      CHRA  '      <tr>', 13, 10
                      CHRA  '        <td width="40"></td>', 13, 10
                      CHRA  '        <td>', 13, 10
                      CHRA  '          <table border="1" cellpadding="8" cellspacing="0" bordercolor="#40EF40">', 13, 10
                      CHRA  '            <tr>', 13, 10
                      CHRA  '              <td nowrap bgcolor="#80FF80">', 13, 10
                      CHRA  '                <font face="Lucida Console" size="2" color="#000000">', 13, 10
HTML_DSC_02_SIZE      equ $ - HTML_DSC_02

HTML_DSC_03           CHRA  '                </font>', 13, 10
                      CHRA  '              </td>', 13, 10
                      CHRA  '            </tr>', 13, 10
                      CHRA  '          </table>', 13, 10
                      CHRA  '        </td>', 13, 10
                      CHRA  '      </tr>', 13, 10
                      CHRA  '    </table>', 13, 10
                      CHRA  '    <br />', 13, 10
HTML_DSC_03_SIZE      equ $ - HTML_DSC_03

;Object / Interface inheritance path
HTML_INH_00           CHRA  '    <br />', 13, 10
                      CHRA  '    <b><font size="2" face="Tahoma" color="#000000"><b><u>Inheritance Path</u>:</b></font></b><br />', 13, 10
	                    CHRA  '    <font size="1"><br /></font>&nbsp&nbsp&nbsp&nbsp', 13, 10
HTML_INH_00_SIZE      equ $ - HTML_INH_00

HTML_INH_01           CHRA  '    <font face="Arial" size="2" color="#000000"><a href="'
HTML_INH_01_SIZE      equ $ - HTML_INH_01

HTML_INH_02           CHRA  '">'
HTML_INH_02_SIZE      equ $ - HTML_INH_02

HTML_INH_03           CHRA  '</a></font>', 13, 10
HTML_INH_03_SIZE      equ $ - HTML_INH_03

HTML_INH_04           CHRA  '    <b><font face="Symbol" size="2" color="#000000">&#x00AE;&nbsp;</font></b>', 13, 10
HTML_INH_04_SIZE      equ $ - HTML_INH_04

HTML_INH_05           CHRA  '    <font face="Arial" size="2" color="#000000">'
HTML_INH_05_SIZE      equ $ - HTML_INH_05

HTML_INH_06           CHRA  '</font>', 13, 10
HTML_INH_06_SIZE      equ $ - HTML_INH_06

HTML_INH_07           CHRA  '    <br /><br /><br />', 13, 10
HTML_INH_07_SIZE      equ $ - HTML_INH_07

;Object / Interface files
HTML_FLS_00           CHRA  '    <font face="Tahoma" size="2" color="#000000"><b><u>Files</u>:</b></font><br />', 13, 10
                      CHRA  '    <font size="1"><br /></font>', 13, 10
                      CHRA  '    <table cellspacing="1" cellpadding="0">', 13, 10
                      CHRA  '      <tr height="24" align="left" bgcolor="#CFCFCF">', 13, 10
                      CHRA  '        <th width="70px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Action&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="90px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Function&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Path&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="150px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Last Update&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="120px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Status&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '      </tr>', 13, 10
HTML_FLS_00_SIZE      equ $ - HTML_FLS_00

HTML_FLS_01           CHRA  '      <tr>', 13, 10
                      CHRA  '        <td align="center">', 13, 10
                      CHRA  '          <input title="Edit source" onClick="OnClick(02, '
HTML_FLS_01_SIZE      equ $ - HTML_FLS_01

HTML_FLS_02           CHRA  ')" type="image" ID="BTN_DEF_EDIT" src="Edit.png">&nbsp;', 13, 10
                      CHRA  '          <input title="Explore" onClick="OnClick(01, '
HTML_FLS_02_SIZE      equ $ - HTML_FLS_02

HTML_FLS_03           CHRA  ')" type="image" ID="BTN_DEF_EXPLORE" src="Open.png">', 13, 10
                      CHRA  '        </td>', 13, 10
                      CHRA  '        <td align="center"><font face="Tahoma" size="2" color="#000000">&nbsp;&nbsp;Definition&nbsp;&nbsp;</font></td>', 13, 10
                      CHRA  '        <td><font face="Tahoma" size="2" color="#000000">'
HTML_FLS_03_SIZE      equ $ - HTML_FLS_03

HTML_FLS_04           CHRA  '</font></td>', 13, 10
                      CHRA  '        <td align="center"><font size="2" face="Tahoma" color="#000000">&nbsp;&nbsp;['
HTML_FLS_04_SIZE      equ $ - HTML_FLS_04

HTML_FLS_05           CHRA  ']&nbsp;&nbsp;</font></td>', 13, 10
                      CHRA  '        <td align="center"><font face="Tahoma" size="2" '
HTML_FLS_05_SIZE      equ $ - HTML_FLS_05

HTML_FLS_06           CHRA  '</font></td>', 13, 10
                      CHRA  '      </tr>', 13, 10
                      CHRA  '      <tr>', 13, 10
                      CHRA  '        <td align="center">', 13, 10
                      CHRA  '          <input title="Edit source" onClick="OnClick(04, '
HTML_FLS_06_SIZE      equ $ - HTML_FLS_06

HTML_FLS_07           CHRA  ')" type="image" src="Edit.png">&nbsp;', 13, 10
                      CHRA  '          <input title="Explore" onClick="OnClick(03, '
HTML_FLS_07_SIZE      equ $ - HTML_FLS_07

HTML_FLS_08           CHRA  ')" type="image" src="Open.png">', 13, 10
                      CHRA  '        </td>', 13, 10
                      CHRA  '        <td align="center"><font face="Tahoma" size="2" color="#000000">&nbsp;&nbsp;Assembly&nbsp;&nbsp;</font></td>', 13, 10
                      CHRA  '        <td><font face="Tahoma" size="2" color="#000000">'
HTML_FLS_08_SIZE      equ $ - HTML_FLS_08

HTML_FLS_09           CHRA  '</font></td>', 13, 10
                      CHRA  '      </tr>', 13, 10
                      CHRA  '      <tr>', 13, 10
                      CHRA  '        <td align="center">', 13, 10
                      CHRA  '          <input title="Compile" onClick="OnClick(06, '
HTML_FLS_09_SIZE      equ $ - HTML_FLS_09

HTML_FLS_10           CHRA  ')" type="image" src="Compile.png">&nbsp;', 13, 10
                      CHRA  '          <input title="Explore" onClick="OnClick(05, '
HTML_FLS_10_SIZE      equ $ - HTML_FLS_10

HTML_FLS_11           CHRA  ')" type="image" src="Open.png">', 13, 10
                      CHRA  '        </td>', 13, 10
                      CHRA  '        <td align="center"><font face="Tahoma" size="2" color="#000000">&nbsp;&nbsp;Library&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td>', 13, 10
                      CHRA  '        <td><font face="Tahoma" size="2" color="#000000">'
HTML_FLS_11_SIZE      equ $ - HTML_FLS_11

HTML_FLS_12           CHRA  '</font></td>', 13, 10
                      CHRA  '      </tr>', 13, 10
                      CHRA  '    </table>', 13, 10
                      CHRA  '    <br /><br />', 13, 10, 13, 10
HTML_FLS_12_SIZE      equ $ - HTML_FLS_12

;Object methods
HTML_OMD_00           CHRA  '    <font face="Tahoma" size="2" color="#000000">', 13, 10
                      CHRA  '      <input title="Show redefined methods" onClick="OnClick(20, 1)" type="image" src="Plus.png"><input title="Hide redefined methods" onClick="OnClick(20, 0)" type="image" src="Minus.png">', 13, 10
                      CHRA  '      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b><u>Methods</u>:</b>&nbsp;&nbsp;&nbsp;&nbsp;', 13, 10
                      CHRA  '    </font>', 13, 10
                      CHRA  '    <br />', 13, 10
                      CHRA  '    <font size="1"><br /></font>', 13, 10
                      CHRA  '    <table cellspacing="1" cellpadding="0">', 13, 10
                      CHRA  '      <tr height="24" align="left" bgcolor="#CFCFCF">', 13, 10
                      CHRA  '        <th width="70px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Action&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Name&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="100px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Type&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="100px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Implementation&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="100px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Status&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '      </tr>', 13, 10
HTML_OMD_00_SIZE      equ $ - HTML_OMD_00

HTML_OMD_01           CHRA  '      <tr>', 13, 10
                      CHRA  '        <td align="center">', 13, 10
HTML_OMD_01_SIZE      equ $ - HTML_OMD_01

HTML_OMD_02           CHRA  '          <input title="Show or hide method help" onClick="OnClick(08, '
HTML_OMD_02_SIZE      equ $ - HTML_OMD_02

;HTML_OMD_01           CHRA  '      <tr>', 13, 10
;                      CHRA  '        <td align="center">', 13, 10
;                      CHRA  '          <input title="Edit source" onClick="OnClick(07, '
;HTML_OMD_01_SIZE      equ $ - HTML_OMD_01
;
;HTML_OMD_02           CHRA  ')" type="image" src="Edit.png">&nbsp;', 13, 10
;                      CHRA  '          <input title="Show or hide method help" onClick="OnClick(08, '
;HTML_OMD_02_SIZE      equ $ - HTML_OMD_02

HTML_OMD_03           CHRA  ')" type="image" src="';Show/Hide
HTML_OMD_03_SIZE      equ $ - HTML_OMD_03

HTML_OMD_04           CHRA  '.png">', 13, 10
                      CHRA  '        </td>', 13, 10
HTML_OMD_04_SIZE      equ $ - HTML_OMD_04

HTML_OMD_05           CHRA  '        <td><font face="Tahoma" size="2" '
HTML_OMD_05_SIZE      equ $ - HTML_OMD_05

HTML_OMD_06           CHRA  '.'
HTML_OMD_06_SIZE      equ $ - HTML_OMD_06

HTML_OMD_07           CHRA  '</font></td>', 13, 10
HTML_OMD_07_SIZE      equ $ - HTML_OMD_07

HTML_OMD_08           CHRA  '        <td align="center"><font face="Tahoma" size="2" '
HTML_OMD_08_SIZE      equ $ - HTML_OMD_08

HTML_OMD_10           CHRA  '</font></td>', 13, 10
HTML_OMD_10_SIZE      equ $ - HTML_OMD_10

HTML_OMD_11           CHRA  '      </tr>', 13, 10
HTML_OMD_11_SIZE      equ $ - HTML_OMD_11

HTML_OMD_12           CHRA  '    </table>', 13, 10
                      CHRA  '    <br /><br />', 13, 10
                      CHRA  13, 10
HTML_OMD_12_SIZE      equ $ - HTML_OMD_12

;Object method comment
HTML_OMC_00           CHRA  '      <tr>', 13, 10
                      CHRA  '        <td></td>', 13, 10
                      CHRA  '          <td colspan="4">', 13, 10
                      CHRA  '            <table border="1" cellpadding="4" cellspacing="0" bordercolor="#40EF40">', 13, 10
                      CHRA  '              <tr>', 13, 10
                      CHRA  '                <td nowrap bgcolor="#80FF80">', 13, 10
                      CHRA  '                  <font face="Lucida Console" size="2" '
HTML_OMC_00_SIZE      equ $ - HTML_OMC_00

HTML_OMC_01           CHRA  '                  </font>', 13, 10
                      CHRA  '                 </td>', 13, 10
                      CHRA  '              </tr>', 13, 10
                      CHRA  '            </table>', 13, 10
                      CHRA  '        </td>', 13, 10
                      CHRA  '      </tr>', 13, 10
HTML_OMC_01_SIZE      equ $ - HTML_OMC_01

;Interface method
HTML_IMD_00           CHRA  '    <font face="Tahoma" size="3" color="#000000"><u>Methods</u>:</font><br />', 13, 10
                      CHRA  '    <font size="1"><br /></font>', 13, 10
                      CHRA  '    <table cellspacing="1" cellpadding="0">', 13, 10
                      CHRA  '      <tr height="24" align="left" bgcolor="#CFCFCF">', 13, 10
                      CHRA  '        <th width="50px"></td>', 13, 10
                      CHRA  '        <th align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Name&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="100px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Type&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '      </tr>', 13, 10
HTML_IMD_00_SIZE      equ $ - HTML_IMD_00

HTML_IMD_01           CHRA  '        <tr>', 13, 10
                      CHRA  '          <td align="center"><img src="'
HTML_IMD_01_SIZE      equ $ - HTML_IMD_01

HTML_IMD_02           CHRA  '.png" /></td>', 13, 10
                      CHRA  '          <td><font face="Tahoma" size="2" '
HTML_IMD_02_SIZE      equ $ - HTML_IMD_02

;Object variable
HTML_VAR_00           CHRA  '    <font face="Tahoma" size="2" color="#000000">', 13, 10
                      CHRA  '      <input title="Show redefined variables" onClick="OnClick(21, 1)" type="image" src="Plus.png"><input title="Hide redefined variables" onClick="OnClick(21, 0)" type="image" src="Minus.png">', 13, 10
                      CHRA  '      <b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<u>Variables</u>:</b>', 13, 10
                      CHRA  '    </font>', 13, 10
                      CHRA  '    <br />', 13, 10
                      CHRA  '    <font size="1"><br /></font>', 13, 10
                      CHRA  '    <table cellspacing="1" cellpadding="0">', 13, 10
                      CHRA  '      <tr height="24" align="left" bgcolor="#CFCFCF">', 13, 10
                      CHRA  '        <th width="50px"></td>', 13, 10
                      CHRA  '        <th align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Name&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="100px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Type&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="70px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Value&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '        <th width="100px" align="center"><font face="Tahoma" size="2" color="#000000"><b>&nbsp;&nbsp;Status&nbsp;&nbsp;</b></font></th>', 13, 10
                      CHRA  '      </tr>', 13, 10
HTML_VAR_00_SIZE      equ $ - HTML_VAR_00

HTML_VAR_01           CHRA  '        <tr>', 13, 10
                      CHRA  '          <td align="center"><img src="'
HTML_VAR_01_SIZE      equ $ - HTML_VAR_01

HTML_VAR_02           CHRA  '.png" /></td>', 13, 10
                      CHRA  '          <td><font face="Tahoma" size="2" '
HTML_VAR_02_SIZE      equ $ - HTML_VAR_02

HTML_VAR_03           CHRA  '.<b>'
HTML_VAR_03_SIZE      equ $ - HTML_VAR_03

HTML_VAR_04           CHRA  '</b></font></td>', 13, 10
                      CHRA  '          <td align="center"><font face="Tahoma" size="2" '
HTML_VAR_04_SIZE      equ $ - HTML_VAR_04

HTML_VAR_05           CHRA  '</font></td>', 13, 10
                      CHRA  '          <td align="center"><font face="Tahoma" size="2" '
HTML_VAR_05_SIZE      equ $ - HTML_VAR_05

HTML_VAR_06           CHRA  '</font></td>', 13, 10
                      CHRA  '        </tr>', 13, 10
HTML_VAR_06_SIZE      equ $ - HTML_VAR_06

HTML_VAR_07           CHRA  '      </table>', 13, 10
HTML_VAR_07_SIZE      equ $ - HTML_VAR_07

;Ancestor not found
HTML_ANF_00           CHRA  '          <font face="Arial" size="2" color="#8F8F8F">'
HTML_ANF_00_SIZE      equ $ - HTML_ANF_00
HTML_ANF_01           CHRA  '</font><font face="Arial" size="2" color="#FF0000">&nbsp;[unknown]&nbsp;</font>', 13, 10
HTML_ANF_01_SIZE      equ $ - HTML_ANF_01
HTML_FNF_00           CHRA  '[file not found]'
HTML_FNF_00_SIZE      equ $ - HTML_FNF_00
HTML_FNF_01           CHRA  '&ndash;&ndash;/&ndash;&ndash;/&ndash;&ndash;&ndash;&ndash; &ndash;&ndash;:&ndash;&ndash;:&ndash;&ndash;'
HTML_FNF_01_SIZE      equ $ - HTML_FNF_01

;File missing
HTML_MIS_00           CHRA  '        <tr>', 13, 10
                      CHRA  '          <td></td>', 13, 10
                      CHRA  '          <td><font face="Tahoma" size="2" color="#8F8F8F"">'
HTML_MIS_00_SIZE      equ $ - HTML_MIS_00

HTML_MIS_01           CHRA  '</font><font face="Arial" size="2" color="#FF0000">&nbsp;[unknown]'
HTML_MIS_01_SIZE      equ $ - HTML_MIS_01

HTML_MIS_02           CHRA  '</font></td>', 13, 10
                      CHRA  '        </tr>', 13, 10
HTML_MIS_02_SIZE      equ $ - HTML_MIS_02

;No info
HTML_NO_INFO          CHRA  'No information available', 13, 10
HTML_NO_INFO_SIZE     equ $ - HTML_NO_INFO
