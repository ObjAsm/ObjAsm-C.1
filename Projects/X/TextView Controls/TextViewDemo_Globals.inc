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
                        "[~]"
ExtendString            "[F'Wingdings 2']", \
                        "{#0020}{#0021}{#0022}{#0023}{#0024}{#0025}{#0026}{#0027}{#0028}{#0029}{#002A}{#002B}{#002C}{#002D}{#002E}{#002F}{B}", \
                        "{#0030}{#0031}{#0032}{#0033}{#0034}{#0035}{#0036}{#0037}{#0038}{#0039}{#003A}{#003B}{#003C}{#003D}{#003E}{#003F}{B}", \
                        "{#0040}{#0041}{#0042}{#0043}{#0044}{#0045}{#0046}{#0047}{#0048}{#0049}{#004A}{#004B}{#004C}{#004D}{#004E}{#004F}{B}", \
                        "{#0050}{#0051}{#0052}{#0053}{#0054}{#0055}{#0056}{#0057}{#0058}{#0059}{#005A}{#005B}{#005C}{#005D}{#005E}{#005F}{B}"
ExtendString            "{#0060}{#0061}{#0062}{#0063}{#0064}{#0065}{#0066}{#0067}{#0068}{#0069}{#006A}{#006B}{#006C}{#006D}{#006E}{#006F}{B}", \
                        "{#0070}{#0071}{#0072}{#0073}{#0074}{#0075}{#0076}{#0077}{#0078}{#0079}{#007A}{#007B}{#007C}{#007D}{#007E}{#007F}{B}", \
                        "{#0080}{#0081}{#0082}{#0083}{#0084}{#0085}{#0086}{#0087}{#0088}{#0089}{#008A}{#008B}{#008C}{#008D}{#008E}{#008F}{B}", \
                        "{#0090}{#0091}{#0092}{#0093}{#0094}{#0095}{#0096}{#0097}{#0098}{#0099}{#009A}{#009B}{#009C}{#009D}{#009E}{#009F}{B}", \
                        "{#00A0}{#00A1}{#00A2}{#00A3}{#00A4}{#00A5}{#00A6}{#00A7}{#00A8}{#00A9}{#00AA}{#00AB}{#00AC}{#00AD}{#00AE}{#00AF}{B}", \
                        "{#00B0}{#00B1}{#00B2}{#00B3}{#00B4}{#00B5}{#00B6}{#00B7}{#00B8}{#00B9}{#00BA}{#00BB}{#00BC}{#00BD}{#00BE}{#00BF}{B}", \
                        "{#00C0}{#00C1}{#00C2}{#00C3}{#00C4}{#00C5}{#00C6}{#00C7}{#00C8}{#00C9}{#00CA}{#00CB}{#00CC}{#00CD}{#00CE}{#00CF}{B}", \
                        "{#00D0}{#00D1}{#00D2}{#00D3}{#00D4}{#00D5}{#00D6}{#00D7}{#00D8}{#00D9}{#00DA}{#00DB}{#00DC}{#00DD}{#00DE}{#00DF}{B}"
ExtendString            "{#00E0}{#00E1}{#00E2}{#00E3}{#00E4}{#00E5}{#00E6}{#00E7}{#00E8}{#00E9}{#00EA}{#00EB}{#00EC}{#00ED}{#00EE}{#00EF}{B}", \
                        "{#00F0}{#00F1}{#00F2}{#00F3}{#00F4}{#00F5}{#00F6}{#00F7}{#00F8}{#00F9}{#00FA}{#00FB}{#00FC}{#00FD}{#00FE}{#00FF}{B}", \
                        "[~]", \
                        "-------------------------------------------------------------------------------------------------------------------------{B}"
ExtendString            "[F'Lucida Console']", \
                        "{#0020}{#0021}{#0022}{#0023}{#0024}{#0025}{#0026}{#0027}{#0028}{#0029}{#002A}{#002B}{#002C}{#002D}{#002E}{#002F}{B}", \
                        "{#0030}{#0031}{#0032}{#0033}{#0034}{#0035}{#0036}{#0037}{#0038}{#0039}{#003A}{#003B}{#003C}{#003D}{#003E}{#003F}{B}", \
                        "{#0040}{#0041}{#0042}{#0043}{#0044}{#0045}{#0046}{#0047}{#0048}{#0049}{#004A}{#004B}{#004C}{#004D}{#004E}{#004F}{B}", \
                        "{#0050}{#0051}{#0052}{#0053}{#0054}{#0055}{#0056}{#0057}{#0058}{#0059}{#005A}{#005B}{#005C}{#005D}{#005E}{#005F}{B}"
ExtendString            "{#0060}{#0061}{#0062}{#0063}{#0064}{#0065}{#0066}{#0067}{#0068}{#0069}{#006A}{#006B}{#006C}{#006D}{#006E}{#006F}{B}", \
                        "{#0070}{#0071}{#0072}{#0073}{#0074}{#0075}{#0076}{#0077}{#0078}{#0079}{#007A}{#007B}{#007C}{#007D}{#007E}{#007F}{B}", \
                        "{#0080}{#0081}{#0082}{#0083}{#0084}{#0085}{#0086}{#0087}{#0088}{#0089}{#008A}{#008B}{#008C}{#008D}{#008E}{#008F}{B}", \
                        "{#0090}{#0091}{#0092}{#0093}{#0094}{#0095}{#0096}{#0097}{#0098}{#0099}{#009A}{#009B}{#009C}{#009D}{#009E}{#009F}{B}", \
                        "{#00A0}{#00A1}{#00A2}{#00A3}{#00A4}{#00A5}{#00A6}{#00A7}{#00A8}{#00A9}{#00AA}{#00AB}{#00AC}{#00AD}{#00AE}{#00AF}{B}", \
                        "{#00B0}{#00B1}{#00B2}{#00B3}{#00B4}{#00B5}{#00B6}{#00B7}{#00B8}{#00B9}{#00BA}{#00BB}{#00BC}{#00BD}{#00BE}{#00BF}{B}", \
                        "{#00C0}{#00C1}{#00C2}{#00C3}{#00C4}{#00C5}{#00C6}{#00C7}{#00C8}{#00C9}{#00CA}{#00CB}{#00CC}{#00CD}{#00CE}{#00CF}{B}", \
                        "{#00D0}{#00D1}{#00D2}{#00D3}{#00D4}{#00D5}{#00D6}{#00D7}{#00D8}{#00D9}{#00DA}{#00DB}{#00DC}{#00DD}{#00DE}{#00DF}{B}"
ExtendString            "{#00E0}{#00E1}{#00E2}{#00E3}{#00E4}{#00E5}{#00E6}{#00E7}{#00E8}{#00E9}{#00EA}{#00EB}{#00EC}{#00ED}{#00EE}{#00EF}{B}", \
                        "{#00F0}{#00F1}{#00F2}{#00F3}{#00F4}{#00F5}{#00F6}{#00F7}{#00F8}{#00F9}{#00FA}{#00FB}{#00FC}{#00FD}{#00FE}{#00FF}{B}", \
                        "[~]", \
                      "[~]"

;String szMarkupText,  "{Padding 20, AutoLineBreak, Zoomable}", \
;                      "[H +3]", \
;                      "[H+2,Canvas#FFFFFF]", \
;                        "[H+1]Settings:[~]{P}", \
;                        "[FI20,HI20,C#0000F0]", \
;                          "[C#0000F0,App0][TXT0,F'Lucida Sans Unicode']?[~] Option 1[~]   [TIP0,F'Webdings',H-2]{#69}[~]{B}", \
;                          "[C#F00000,App1][TXT1,F'Lucida Sans Unicode']?[~] Option 2[~]{P}", \
;                          "[C#007000,App2][TXT2,F'Wingdings 2']?[~] Option 3[~]{B}", \
;                          "[C#000000,App3][TXT3,F'Wingdings 2']?[~] Option 4[~]{B}{B}", \
;                        "[~]", \
;                        "[APP 4, C #0066D5]Google[~] test{P}", \
;                        '[I, C #5C5C5C, BGCOLOR #D1D1D1, Align.Center, H +2, BOX #D1D1D1] "Man is still the most extraordinary computer of all." [~]{B}', \
;                        "- John F. Kennedy{B}", \
;                        "{LINE}", \
;                        "Click on this [APP 5, Color #0066D5]link[~] to show a message box{P}"
;ExtendString            "[Indent 10, Hanging 30]{TABL 30}", \
;                          "{#2981}{T}List 1 - [B]First Item[~] - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.{B}", \
;                          "{#2981}{T}List 1 - [B]Second Item[~]{P}", \
;                        "[~]", \
;                      "[~]"

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
