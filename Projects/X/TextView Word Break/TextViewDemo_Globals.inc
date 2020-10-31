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
                    

APP_VISIT     equ   0
APP_CHECK     equ   1
APP_EMAIL     equ   2
INFO_BUILD    equ   0
INFO_UPDATE   equ   1


;https://books.google.ch/books?id=O9k_CgAAQBAJ&pg=PA144&lpg=PA144&dq=26AB+2022+bullet&source=bl&ots=tp_qp6lS7Q&sig=ACfU3U0hEvNwRGIhvLnMLl5ypy3eF82Quw&hl=de&sa=X&ved=2ahUKEwi-gKjwguHpAhVCzqQKHem3AQsQ6AEwAHoECAoQAQ#v=onepage&q=26AB%202022%20bullet&f=false

if 1
.const
String szMarkupText,"{Padding 20}", \
                    "[H +3]", \
                      "Beauty, success, truth ...{B}", \
                      "[I]He is blessed who has two.[~]{B}", \
                      "[C #C00000, B]Your program has none.[~]{P}", \
                      "[I]Ken Carpenter[~]{B}", \
                      "[FONT 'Lucida Console', H -1, C #5C5C5C, BOX #CEDBE5]This example{TAB}uses the following tags: {#7B}TAB} {#5B}BOX #CEDBE5], {#7B}BREAK}, {#5B}color=#5C5C5C]{B}", \
                      "And the following end tags: {#5B}~][~]{B}", \
                      "[App 0, C #0066D5]Google[~] test{P}", \
                      '[I, C #5C5C5C, BGCOLOR #D1D1D1, Align "CENTER", H +2, BOX #D1D1D1] "Man is still the most extraordinary computer of all." [~]{B}', \
                      "- John F. Kennedy{B}", \
                      "{LINE}", \
                      "Click on this [App 1, Color #0066D5]link[~] to show a message box{P}"
ExtendString          "[Indent 10, Hanging 30]{TABL 30}", \
                        "{#2981}{T}List 1 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                        "{#2981}{T}List 1 - [B]Second Item[~]{P}", \
                        "[B]1.[~]{T}List 2 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                        "[B]2.[~]{T}List 2 - [B]Second Item[~]{P}"
ExtendString            "{#2981}{T}List 3 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                        "{#2981}{T}List 3 - [B]Second Item[~]{B}", \
                        "[Indent 30, Hanging 50]{TABL 50}", \
                          "{#2022}{T}List 3 - Lvl 2 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
                          "{#2022}{T}List 3 - Lvl 2 - [B]Second Item[~]{B}", \
                        "[~]", \
                        "{#2981}{T}List 3 - [B]Third Item[~]{B}", \
                      "[~]", \
                    "[~]"

else

.const
String szMarkupText,  "{Padding 20}", \
                      "[Height 11]", \
                        "{COVER 0}", \
                        "[Indent 150, Align 'LEFT']", \
                          "[Height +3, Bold]&ABOUT_TEXT{B}[~]", \
                          "[Italic]Version &VER_PRODUCTVERSION_STR{P}[~]", \
                          "[Color #3F3F3F]", \
                            "Designed with ObjAsm{B}", \
                            "© &COPYRIGHT{P}", \
                            "[Color #5F4FFF]", \
                              @CatStr(<!">, %BUILD_DATE_STR, \
                                      <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                                      %TARGET_MODE_STR, <->, %TARGET_BITNESS, <    !">), \
                              "[Info ", @CatStr(<!">, %INFO_BUILD, <!">), ", Font 'Webdings', Height +1]{#69}[~]", \
                            "[~]{B}{B}", \
                          "[~]", \
                        "[~]"
ExtendString            "[Indent 0, Align 'CENTER']", \
                          "[Font 'Webdings', Color #FF5F5F, Height +7]{#7E}[~]", \
                          "  Visit us at  ", \
                          "[App ", @CatStr(<!">, %APP_VISIT, <!">), ", Color #0000FF, U]www.objasm.x10host.com[~]{B}", \
                          "[Font 'Wingdings', Color #408090, Height +1]{#2A}[~]", \
                          "   Email us to  ", \
                          "[App ", @CatStr(<!">, %APP_EMAIL, <!">), ", Color #0000FF, U]objasm@gmx.net[~]{P}", \
                          "[App ", @CatStr(<!">, %APP_CHECK, <!">), ", Color #0000FF, U]Check for updates[~]", \
                          "[Info ", @CatStr(<!">, %INFO_UPDATE, <!">), ", Font 'Webdings', H +1, Color #5F5FFF]  {#69}[~]", \
                        "[~]", \
                      "[~]"

endif

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
