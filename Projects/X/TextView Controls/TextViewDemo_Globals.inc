; ==================================================================================================
; Title:      TextViewDemo_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm TextView demonstration program.
; Notes:      Version C.1.1, April 2020
;               - First release.
; ==================================================================================================


include TextViewDemo_Shared.inc

CStr szIcoName,     "ICON_APP"
%CStr szAppTitle,   "&APP_TITLE"
%CStr szAboutText,  "&ABOUT_TEXT", 13, 10, \
                    "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                    "Designed with ObjAsm", 13, 10, \
                    "© &COPYRIGHT", 13, 10, 13, 10, \
                    @CatStr(<!">, %BUILD_DATE_STR, \
                            <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                            %TARGET_MODE_STR, <->, %TARGET_BITNESS, <!">)
                    

APP_VISIT     equ   4
APP_CHECK     equ   5

;https://books.google.ch/books?id=O9k_CgAAQBAJ&pg=PA144&lpg=PA144&dq=26AB+2022+bullet&source=bl&ots=tp_qp6lS7Q&sig=ACfU3U0hEvNwRGIhvLnMLl5ypy3eF82Quw&hl=de&sa=X&ved=2ahUKEwi-gKjwguHpAhVCzqQKHem3AQsQ6AEwAHoECAoQAQ#v=onepage&q=26AB%202022%20bullet&f=false

String szMarkupText,  "{Padding 20, AutoLineBreak, Zoomable}", \
                      "[H +3]", \
                      "[H+2,Canvas#FFFFFF]", \
                        "[H+1]Settings:[~]{P}", \
                        "[FI20,HI20,C#0000F0]", \
                          "[C#0000F0,App0][TXT0,F'Lucida Sans Unicode']?[~] Option 1[~]   [TIP0,F'Webdings',H-2]{#69}[~]{B}", \
                          "[C#F00000,App1][TXT1,F'Lucida Sans Unicode']?[~] Option 2[~]{P}", \
                          "[C#007000,App2][TXT2,F'Wingdings 2']?[~] Option 3[~]{B}", \
                          "[C#000000,App3][TXT3,F'Wingdings 2']?[~] Option 4[~]{B}{B}", \
                        "[~]", \
                        "[APP 4, C #0066D5]Google[~] test{P}", \
                        '[I, C #5C5C5C, BGCOLOR #D1D1D1, Align.Center, H +2, BOX #D1D1D1] "Man is still the most extraordinary computer of all." [~]{B}', \
                        "- John F. Kennedy{B}", \
                        "{LINE}", \
                        "Click on this [APP 5, Color #0066D5]link[~] to show a message box{P}"
ExtendString            "[Indent 10, Hanging 30]{TABL 30}", \
                          "{#2981}{T}List 1 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                          "{#2981}{T}List 1 - [B]Second Item[~]{P}", \
                        "[~]", \
                      "[~]"

ifdef __UASM__
  ANAME     textequ <UASM>
  AVERSION  equ __UASM__
elseifdef __JWASM__
  ANAME     textequ <JWASM>
  AVERSION  equ __JWASM__
elseifdef __ASMC__
  ANAME     textequ <ASMC>
  AVERSION  equ __ASMC__
else
  ANAME     textequ <MASM>
  AVERSION  equ  @Version
endif

if TARGET_MODE eq MODE_RLS
  DNAME     textequ <RELEASE>
else
  DNAME     textequ <DEBUG>
endif

CStr szUpdateInfo,  "Verifies the availability of a new software update."
                    
%CStr szBuildInfo,  "Build number:", 9, @CatStr(<!">, %BUILD_NUMBER, <!">), 13, \
                    "Assembler:   ", 9, @CatStr(<!">, %ANAME, <!">), 13, \
                    "Version:     ", 9, @CatStr(<!">, %AVERSION, <!">), 13, \
                    "Distribution:", 9, @CatStr(<!">, %DNAME, <!">), 13, \
                    "Bitness:     ", 9, @CatStr(<!">, %TARGET_BITNESS, <!">)
