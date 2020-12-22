
;--- Generated .INC file by COMView
;--- typelib name=Word
;--- documentation=Microsoft Word 9.0 Object Library
;--- GUID={00020905-0000-0000-C000-000000000046}
;--- Version 8.1, LCID 0

;--- prototypes too complex for MASM may exist
;--- if such ones reside in a vtable they will be replaced by dummies
;--- search for occurances of ';+++' to have a closer look at these

sTLBID_Word textequ <GUID {000020905h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
_MajorVer_Word equ 8
_MinorVer_Word equ 1

;--- WdMailSystem, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailSystem typedef SDWORD
wdNoMailSystem  EQU  0
wdMAPI  EQU  1
wdPowerTalk  EQU  2
wdMAPIandPowerTalk  EQU  3

;--- WdTemplateType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTemplateType typedef SDWORD
wdNormalTemplate  EQU  0
wdGlobalTemplate  EQU  1
wdAttachedTemplate  EQU  2

;--- WdContinue, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdContinue typedef SDWORD
wdContinueDisabled  EQU  0
wdResetList  EQU  1
wdContinueList  EQU  2

;--- WdIMEMode, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdIMEMode typedef SDWORD
wdIMEModeNoControl  EQU  0
wdIMEModeOn  EQU  1
wdIMEModeOff  EQU  2
wdIMEModeHiragana  EQU  4
wdIMEModeKatakana  EQU  5
wdIMEModeKatakanaHalf  EQU  6
wdIMEModeAlphaFull  EQU  7
wdIMEModeAlpha  EQU  8
wdIMEModeHangulFull  EQU  9
wdIMEModeHangul  EQU  10

;--- WdBaselineAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBaselineAlignment typedef SDWORD
wdBaselineAlignTop  EQU  0
wdBaselineAlignCenter  EQU  1
wdBaselineAlignBaseline  EQU  2
wdBaselineAlignFarEast50  EQU  3
wdBaselineAlignAuto  EQU  4

;--- WdIndexFilter, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdIndexFilter typedef SDWORD
wdIndexFilterNone  EQU  0
wdIndexFilterAiueo  EQU  1
wdIndexFilterAkasatana  EQU  2
wdIndexFilterChosung  EQU  3
wdIndexFilterLow  EQU  4
wdIndexFilterMedium  EQU  5
wdIndexFilterFull  EQU  6

;--- WdIndexSortBy, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdIndexSortBy typedef SDWORD
wdIndexSortByStroke  EQU  0
wdIndexSortBySyllable  EQU  1

;--- WdJustificationMode, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdJustificationMode typedef SDWORD
wdJustificationModeExpand  EQU  0
wdJustificationModeCompress  EQU  1
wdJustificationModeCompressKana  EQU  2

;--- WdFarEastLineBreakLevel, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFarEastLineBreakLevel typedef SDWORD
wdFarEastLineBreakLevelNormal  EQU  0
wdFarEastLineBreakLevelStrict  EQU  1
wdFarEastLineBreakLevelCustom  EQU  2

;--- WdMultipleWordConversionsMode, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMultipleWordConversionsMode typedef SDWORD
wdHangulToHanja  EQU  0
wdHanjaToHangul  EQU  1

;--- WdColorIndex, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdColorIndex typedef SDWORD
wdAuto  EQU  0
wdBlack  EQU  1
wdBlue  EQU  2
wdTurquoise  EQU  3
wdBrightGreen  EQU  4
wdPink  EQU  5
wdRed  EQU  6
wdYellow  EQU  7
wdWhite  EQU  8
wdDarkBlue  EQU  9
wdTeal  EQU  10
wdGreen  EQU  11
wdViolet  EQU  12
wdDarkRed  EQU  13
wdDarkYellow  EQU  14
wdGray50  EQU  15
wdGray25  EQU  16      ;=010h
wdByAuthor  EQU  -1
wdNoHighlight  EQU  0

;--- WdTextureIndex, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTextureIndex typedef SDWORD
wdTextureNone  EQU  0
wdTexture2Pt5Percent  EQU  25      ;=019h
wdTexture5Percent  EQU  50      ;=032h
wdTexture7Pt5Percent  EQU  75      ;=04Bh
wdTexture10Percent  EQU  100      ;=064h
wdTexture12Pt5Percent  EQU  125      ;=07Dh
wdTexture15Percent  EQU  150      ;=096h
wdTexture17Pt5Percent  EQU  175      ;=0AFh
wdTexture20Percent  EQU  200      ;=0C8h
wdTexture22Pt5Percent  EQU  225      ;=0E1h
wdTexture25Percent  EQU  250      ;=0FAh
wdTexture27Pt5Percent  EQU  275      ;=0113h
wdTexture30Percent  EQU  300      ;=012Ch
wdTexture32Pt5Percent  EQU  325      ;=0145h
wdTexture35Percent  EQU  350      ;=015Eh
wdTexture37Pt5Percent  EQU  375      ;=0177h
wdTexture40Percent  EQU  400      ;=0190h
wdTexture42Pt5Percent  EQU  425      ;=01A9h
wdTexture45Percent  EQU  450      ;=01C2h
wdTexture47Pt5Percent  EQU  475      ;=01DBh
wdTexture50Percent  EQU  500      ;=01F4h
wdTexture52Pt5Percent  EQU  525      ;=020Dh
wdTexture55Percent  EQU  550      ;=0226h
wdTexture57Pt5Percent  EQU  575      ;=023Fh
wdTexture60Percent  EQU  600      ;=0258h
wdTexture62Pt5Percent  EQU  625      ;=0271h
wdTexture65Percent  EQU  650      ;=028Ah
wdTexture67Pt5Percent  EQU  675      ;=02A3h
wdTexture70Percent  EQU  700      ;=02BCh
wdTexture72Pt5Percent  EQU  725      ;=02D5h
wdTexture75Percent  EQU  750      ;=02EEh
wdTexture77Pt5Percent  EQU  775      ;=0307h
wdTexture80Percent  EQU  800      ;=0320h
wdTexture82Pt5Percent  EQU  825      ;=0339h
wdTexture85Percent  EQU  850      ;=0352h
wdTexture87Pt5Percent  EQU  875      ;=036Bh
wdTexture90Percent  EQU  900      ;=0384h
wdTexture92Pt5Percent  EQU  925      ;=039Dh
wdTexture95Percent  EQU  950      ;=03B6h
wdTexture97Pt5Percent  EQU  975      ;=03CFh
wdTextureSolid  EQU  1000      ;=03E8h
wdTextureDarkHorizontal  EQU  -1
wdTextureDarkVertical  EQU  -2      ;=0FFFFFFFEh
wdTextureDarkDiagonalDown  EQU  -3      ;=0FFFFFFFDh
wdTextureDarkDiagonalUp  EQU  -4      ;=0FFFFFFFCh
wdTextureDarkCross  EQU  -5      ;=0FFFFFFFBh
wdTextureDarkDiagonalCross  EQU  -6      ;=0FFFFFFFAh
wdTextureHorizontal  EQU  -7      ;=0FFFFFFF9h
wdTextureVertical  EQU  -8      ;=0FFFFFFF8h
wdTextureDiagonalDown  EQU  -9      ;=0FFFFFFF7h
wdTextureDiagonalUp  EQU  -10      ;=0FFFFFFF6h
wdTextureCross  EQU  -11      ;=0FFFFFFF5h
wdTextureDiagonalCross  EQU  -12      ;=0FFFFFFF4h

;--- WdUnderline, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdUnderline typedef SDWORD
wdUnderlineNone  EQU  0
wdUnderlineSingle  EQU  1
wdUnderlineWords  EQU  2
wdUnderlineDouble  EQU  3
wdUnderlineDotted  EQU  4
wdUnderlineThick  EQU  6
wdUnderlineDash  EQU  7
wdUnderlineDotDash  EQU  9
wdUnderlineDotDotDash  EQU  10
wdUnderlineWavy  EQU  11
wdUnderlineWavyHeavy  EQU  27      ;=01Bh
wdUnderlineDottedHeavy  EQU  20      ;=014h
wdUnderlineDashHeavy  EQU  23      ;=017h
wdUnderlineDotDashHeavy  EQU  25      ;=019h
wdUnderlineDotDotDashHeavy  EQU  26      ;=01Ah
wdUnderlineDashLong  EQU  39      ;=027h
wdUnderlineDashLongHeavy  EQU  55      ;=037h
wdUnderlineWavyDouble  EQU  43      ;=02Bh

;--- WdEmphasisMark, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdEmphasisMark typedef SDWORD
wdEmphasisMarkNone  EQU  0
wdEmphasisMarkOverSolidCircle  EQU  1
wdEmphasisMarkOverComma  EQU  2
wdEmphasisMarkOverWhiteCircle  EQU  3
wdEmphasisMarkUnderSolidCircle  EQU  4

;--- WdInternationalIndex, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdInternationalIndex typedef SDWORD
wdListSeparator  EQU  17      ;=011h
wdDecimalSeparator  EQU  18      ;=012h
wdThousandsSeparator  EQU  19      ;=013h
wdCurrencyCode  EQU  20      ;=014h
wd24HourClock  EQU  21      ;=015h
wdInternationalAM  EQU  22      ;=016h
wdInternationalPM  EQU  23      ;=017h
wdTimeSeparator  EQU  24      ;=018h
wdDateSeparator  EQU  25      ;=019h
wdProductLanguageID  EQU  26      ;=01Ah

;--- WdAutoMacros, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdAutoMacros typedef SDWORD
wdAutoExec  EQU  0
wdAutoNew  EQU  1
wdAutoOpen  EQU  2
wdAutoClose  EQU  3
wdAutoExit  EQU  4

;--- WdCaptionPosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCaptionPosition typedef SDWORD
wdCaptionPositionAbove  EQU  0
wdCaptionPositionBelow  EQU  1

;--- WdCountry, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCountry typedef SDWORD
wdUS  EQU  1
wdCanada  EQU  2
wdLatinAmerica  EQU  3
wdNetherlands  EQU  31      ;=01Fh
wdFrance  EQU  33      ;=021h
wdSpain  EQU  34      ;=022h
wdItaly  EQU  39      ;=027h
wdUK  EQU  44      ;=02Ch
wdDenmark  EQU  45      ;=02Dh
wdSweden  EQU  46      ;=02Eh
wdNorway  EQU  47      ;=02Fh
wdGermany  EQU  49      ;=031h
wdPeru  EQU  51      ;=033h
wdMexico  EQU  52      ;=034h
wdArgentina  EQU  54      ;=036h
wdBrazil  EQU  55      ;=037h
wdChile  EQU  56      ;=038h
wdVenezuela  EQU  58      ;=03Ah
wdJapan  EQU  81      ;=051h
wdTaiwan  EQU  886      ;=0376h
wdChina  EQU  86      ;=056h
wdKorea  EQU  82      ;=052h
wdFinland  EQU  358      ;=0166h
wdIceland  EQU  354      ;=0162h

;--- WdHeadingSeparator, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHeadingSeparator typedef SDWORD
wdHeadingSeparatorNone  EQU  0
wdHeadingSeparatorBlankLine  EQU  1
wdHeadingSeparatorLetter  EQU  2
wdHeadingSeparatorLetterLow  EQU  3
wdHeadingSeparatorLetterFull  EQU  4

;--- WdSeparatorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSeparatorType typedef SDWORD
wdSeparatorHyphen  EQU  0
wdSeparatorPeriod  EQU  1
wdSeparatorColon  EQU  2
wdSeparatorEmDash  EQU  3
wdSeparatorEnDash  EQU  4

;--- WdPageNumberAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPageNumberAlignment typedef SDWORD
wdAlignPageNumberLeft  EQU  0
wdAlignPageNumberCenter  EQU  1
wdAlignPageNumberRight  EQU  2
wdAlignPageNumberInside  EQU  3
wdAlignPageNumberOutside  EQU  4

;--- WdBorderType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBorderType typedef SDWORD
wdBorderTop  EQU  -1
wdBorderLeft  EQU  -2      ;=0FFFFFFFEh
wdBorderBottom  EQU  -3      ;=0FFFFFFFDh
wdBorderRight  EQU  -4      ;=0FFFFFFFCh
wdBorderHorizontal  EQU  -5      ;=0FFFFFFFBh
wdBorderVertical  EQU  -6      ;=0FFFFFFFAh
wdBorderDiagonalDown  EQU  -7      ;=0FFFFFFF9h
wdBorderDiagonalUp  EQU  -8      ;=0FFFFFFF8h

;--- WdBorderTypeHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBorderTypeHID typedef SDWORD
emptyenum  EQU  0

;--- WdFramePosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFramePosition typedef SDWORD
wdFrameTop  EQU  -999999      ;=0FFF0BDC1h
wdFrameLeft  EQU  -999998      ;=0FFF0BDC2h
wdFrameBottom  EQU  -999997      ;=0FFF0BDC3h
wdFrameRight  EQU  -999996      ;=0FFF0BDC4h
wdFrameCenter  EQU  -999995      ;=0FFF0BDC5h
wdFrameInside  EQU  -999994      ;=0FFF0BDC6h
wdFrameOutside  EQU  -999993      ;=0FFF0BDC7h

;--- WdAnimation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdAnimation typedef SDWORD
wdAnimationNone  EQU  0
wdAnimationLasVegasLights  EQU  1
wdAnimationBlinkingBackground  EQU  2
wdAnimationSparkleText  EQU  3
wdAnimationMarchingBlackAnts  EQU  4
wdAnimationMarchingRedAnts  EQU  5
wdAnimationShimmer  EQU  6

;--- WdCharacterCase, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCharacterCase typedef SDWORD
wdNextCase  EQU  -1
wdLowerCase  EQU  0
wdUpperCase  EQU  1
wdTitleWord  EQU  2
wdTitleSentence  EQU  4
wdToggleCase  EQU  5
wdHalfWidth  EQU  6
wdFullWidth  EQU  7
wdKatakana  EQU  8
wdHiragana  EQU  9

;--- WdCharacterCaseHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCharacterCaseHID typedef SDWORD
emptyenum  EQU  0

;--- WdSummaryMode, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSummaryMode typedef SDWORD
wdSummaryModeHighlight  EQU  0
wdSummaryModeHideAllButSummary  EQU  1
wdSummaryModeInsert  EQU  2
wdSummaryModeCreateNew  EQU  3

;--- WdSummaryLength, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSummaryLength typedef SDWORD
wd10Sentences  EQU  -2      ;=0FFFFFFFEh
wd20Sentences  EQU  -3      ;=0FFFFFFFDh
wd100Words  EQU  -4      ;=0FFFFFFFCh
wd500Words  EQU  -5      ;=0FFFFFFFBh
wd10Percent  EQU  -6      ;=0FFFFFFFAh
wd25Percent  EQU  -7      ;=0FFFFFFF9h
wd50Percent  EQU  -8      ;=0FFFFFFF8h
wd75Percent  EQU  -9      ;=0FFFFFFF7h

;--- WdStyleType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdStyleType typedef SDWORD
wdStyleTypeParagraph  EQU  1
wdStyleTypeCharacter  EQU  2

;--- WdUnits, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdUnits typedef SDWORD
wdCharacter  EQU  1
wdWord  EQU  2
wdSentence  EQU  3
wdParagraph  EQU  4
wdLine  EQU  5
wdStory  EQU  6
wdScreen  EQU  7
wdSection  EQU  8
wdColumn  EQU  9
wdRow  EQU  10
wdWindow  EQU  11
wdCell  EQU  12
wdCharacterFormatting  EQU  13
wdParagraphFormatting  EQU  14
wdTable  EQU  15
wdItem  EQU  16      ;=010h

;--- WdGoToItem, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdGoToItem typedef SDWORD
wdGoToBookmark  EQU  -1
wdGoToSection  EQU  0
wdGoToPage  EQU  1
wdGoToTable  EQU  2
wdGoToLine  EQU  3
wdGoToFootnote  EQU  4
wdGoToEndnote  EQU  5
wdGoToComment  EQU  6
wdGoToField  EQU  7
wdGoToGraphic  EQU  8
wdGoToObject  EQU  9
wdGoToEquation  EQU  10
wdGoToHeading  EQU  11
wdGoToPercent  EQU  12
wdGoToSpellingError  EQU  13
wdGoToGrammaticalError  EQU  14
wdGoToProofreadingError  EQU  15

;--- WdGoToDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdGoToDirection typedef SDWORD
wdGoToFirst  EQU  1
wdGoToLast  EQU  -1
wdGoToNext  EQU  2
wdGoToRelative  EQU  2
wdGoToPrevious  EQU  3
wdGoToAbsolute  EQU  1

;--- WdCollapseDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCollapseDirection typedef SDWORD
wdCollapseStart  EQU  1
wdCollapseEnd  EQU  0

;--- WdRowHeightRule, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRowHeightRule typedef SDWORD
wdRowHeightAuto  EQU  0
wdRowHeightAtLeast  EQU  1
wdRowHeightExactly  EQU  2

;--- WdFrameSizeRule, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFrameSizeRule typedef SDWORD
wdFrameAuto  EQU  0
wdFrameAtLeast  EQU  1
wdFrameExact  EQU  2

;--- WdInsertCells, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdInsertCells typedef SDWORD
wdInsertCellsShiftRight  EQU  0
wdInsertCellsShiftDown  EQU  1
wdInsertCellsEntireRow  EQU  2
wdInsertCellsEntireColumn  EQU  3

;--- WdDeleteCells, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDeleteCells typedef SDWORD
wdDeleteCellsShiftLeft  EQU  0
wdDeleteCellsShiftUp  EQU  1
wdDeleteCellsEntireRow  EQU  2
wdDeleteCellsEntireColumn  EQU  3

;--- WdListApplyTo, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdListApplyTo typedef SDWORD
wdListApplyToWholeList  EQU  0
wdListApplyToThisPointForward  EQU  1
wdListApplyToSelection  EQU  2

;--- WdAlertLevel, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdAlertLevel typedef SDWORD
wdAlertsNone  EQU  0
wdAlertsMessageBox  EQU  -2      ;=0FFFFFFFEh
wdAlertsAll  EQU  -1

;--- WdCursorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCursorType typedef SDWORD
wdCursorWait  EQU  0
wdCursorIBeam  EQU  1
wdCursorNormal  EQU  2
wdCursorNorthwestArrow  EQU  3

;--- WdEnableCancelKey, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdEnableCancelKey typedef SDWORD
wdCancelDisabled  EQU  0
wdCancelInterrupt  EQU  1

;--- WdRulerStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRulerStyle typedef SDWORD
wdAdjustNone  EQU  0
wdAdjustProportional  EQU  1
wdAdjustFirstColumn  EQU  2
wdAdjustSameWidth  EQU  3

;--- WdParagraphAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdParagraphAlignment typedef SDWORD
wdAlignParagraphLeft  EQU  0
wdAlignParagraphCenter  EQU  1
wdAlignParagraphRight  EQU  2
wdAlignParagraphJustify  EQU  3
wdAlignParagraphDistribute  EQU  4
wdAlignParagraphJustifyMed  EQU  5
wdAlignParagraphJustifyHi  EQU  7
wdAlignParagraphJustifyLow  EQU  8

;--- WdParagraphAlignmentHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdParagraphAlignmentHID typedef SDWORD
emptyenum  EQU  0

;--- WdListLevelAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdListLevelAlignment typedef SDWORD
wdListLevelAlignLeft  EQU  0
wdListLevelAlignCenter  EQU  1
wdListLevelAlignRight  EQU  2

;--- WdRowAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRowAlignment typedef SDWORD
wdAlignRowLeft  EQU  0
wdAlignRowCenter  EQU  1
wdAlignRowRight  EQU  2

;--- WdTabAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTabAlignment typedef SDWORD
wdAlignTabLeft  EQU  0
wdAlignTabCenter  EQU  1
wdAlignTabRight  EQU  2
wdAlignTabDecimal  EQU  3
wdAlignTabBar  EQU  4
wdAlignTabList  EQU  6

;--- WdVerticalAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdVerticalAlignment typedef SDWORD
wdAlignVerticalTop  EQU  0
wdAlignVerticalCenter  EQU  1
wdAlignVerticalJustify  EQU  2
wdAlignVerticalBottom  EQU  3

;--- WdCellVerticalAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCellVerticalAlignment typedef SDWORD
wdCellAlignVerticalTop  EQU  0
wdCellAlignVerticalCenter  EQU  1
wdCellAlignVerticalBottom  EQU  3

;--- WdTrailingCharacter, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTrailingCharacter typedef SDWORD
wdTrailingTab  EQU  0
wdTrailingSpace  EQU  1
wdTrailingNone  EQU  2

;--- WdListGalleryType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdListGalleryType typedef SDWORD
wdBulletGallery  EQU  1
wdNumberGallery  EQU  2
wdOutlineNumberGallery  EQU  3

;--- WdListNumberStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdListNumberStyle typedef SDWORD
wdListNumberStyleArabic  EQU  0
wdListNumberStyleUppercaseRoman  EQU  1
wdListNumberStyleLowercaseRoman  EQU  2
wdListNumberStyleUppercaseLetter  EQU  3
wdListNumberStyleLowercaseLetter  EQU  4
wdListNumberStyleOrdinal  EQU  5
wdListNumberStyleCardinalText  EQU  6
wdListNumberStyleOrdinalText  EQU  7
wdListNumberStyleKanji  EQU  10
wdListNumberStyleKanjiDigit  EQU  11
wdListNumberStyleAiueoHalfWidth  EQU  12
wdListNumberStyleIrohaHalfWidth  EQU  13
wdListNumberStyleArabicFullWidth  EQU  14
wdListNumberStyleKanjiTraditional  EQU  16      ;=010h
wdListNumberStyleKanjiTraditional2  EQU  17      ;=011h
wdListNumberStyleNumberInCircle  EQU  18      ;=012h
wdListNumberStyleAiueo  EQU  20      ;=014h
wdListNumberStyleIroha  EQU  21      ;=015h
wdListNumberStyleArabicLZ  EQU  22      ;=016h
wdListNumberStyleBullet  EQU  23      ;=017h
wdListNumberStyleGanada  EQU  24      ;=018h
wdListNumberStyleChosung  EQU  25      ;=019h
wdListNumberStyleGBNum1  EQU  26      ;=01Ah
wdListNumberStyleGBNum2  EQU  27      ;=01Bh
wdListNumberStyleGBNum3  EQU  28      ;=01Ch
wdListNumberStyleGBNum4  EQU  29      ;=01Dh
wdListNumberStyleZodiac1  EQU  30      ;=01Eh
wdListNumberStyleZodiac2  EQU  31      ;=01Fh
wdListNumberStyleZodiac3  EQU  32      ;=020h
wdListNumberStyleTradChinNum1  EQU  33      ;=021h
wdListNumberStyleTradChinNum2  EQU  34      ;=022h
wdListNumberStyleTradChinNum3  EQU  35      ;=023h
wdListNumberStyleTradChinNum4  EQU  36      ;=024h
wdListNumberStyleSimpChinNum1  EQU  37      ;=025h
wdListNumberStyleSimpChinNum2  EQU  38      ;=026h
wdListNumberStyleSimpChinNum3  EQU  39      ;=027h
wdListNumberStyleSimpChinNum4  EQU  40      ;=028h
wdListNumberStyleHanjaRead  EQU  41      ;=029h
wdListNumberStyleHanjaReadDigit  EQU  42      ;=02Ah
wdListNumberStyleHangul  EQU  43      ;=02Bh
wdListNumberStyleHanja  EQU  44      ;=02Ch
wdListNumberStyleHebrew1  EQU  45      ;=02Dh
wdListNumberStyleArabic1  EQU  46      ;=02Eh
wdListNumberStyleHebrew2  EQU  47      ;=02Fh
wdListNumberStyleArabic2  EQU  48      ;=030h
wdListNumberStyleLegal  EQU  253      ;=0FDh
wdListNumberStyleLegalLZ  EQU  254      ;=0FEh
wdListNumberStyleNone  EQU  255      ;=0FFh

;--- WdListNumberStyleHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdListNumberStyleHID typedef SDWORD
emptyenum  EQU  0

;--- WdNoteNumberStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdNoteNumberStyle typedef SDWORD
wdNoteNumberStyleArabic  EQU  0
wdNoteNumberStyleUppercaseRoman  EQU  1
wdNoteNumberStyleLowercaseRoman  EQU  2
wdNoteNumberStyleUppercaseLetter  EQU  3
wdNoteNumberStyleLowercaseLetter  EQU  4
wdNoteNumberStyleSymbol  EQU  9
wdNoteNumberStyleArabicFullWidth  EQU  14
wdNoteNumberStyleKanji  EQU  10
wdNoteNumberStyleKanjiDigit  EQU  11
wdNoteNumberStyleKanjiTraditional  EQU  16      ;=010h
wdNoteNumberStyleNumberInCircle  EQU  18      ;=012h
wdNoteNumberStyleHanjaRead  EQU  41      ;=029h
wdNoteNumberStyleHanjaReadDigit  EQU  42      ;=02Ah
wdNoteNumberStyleTradChinNum1  EQU  33      ;=021h
wdNoteNumberStyleTradChinNum2  EQU  34      ;=022h
wdNoteNumberStyleSimpChinNum1  EQU  37      ;=025h
wdNoteNumberStyleSimpChinNum2  EQU  38      ;=026h
wdNoteNumberStyleHebrewLetter1  EQU  45      ;=02Dh
wdNoteNumberStyleArabicLetter1  EQU  46      ;=02Eh
wdNoteNumberStyleHebrewLetter2  EQU  47      ;=02Fh
wdNoteNumberStyleArabicLetter2  EQU  48      ;=030h

;--- WdNoteNumberStyleHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdNoteNumberStyleHID typedef SDWORD
emptyenum  EQU  0

;--- WdCaptionNumberStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCaptionNumberStyle typedef SDWORD
wdCaptionNumberStyleArabic  EQU  0
wdCaptionNumberStyleUppercaseRoman  EQU  1
wdCaptionNumberStyleLowercaseRoman  EQU  2
wdCaptionNumberStyleUppercaseLetter  EQU  3
wdCaptionNumberStyleLowercaseLetter  EQU  4
wdCaptionNumberStyleArabicFullWidth  EQU  14
wdCaptionNumberStyleKanji  EQU  10
wdCaptionNumberStyleKanjiDigit  EQU  11
wdCaptionNumberStyleKanjiTraditional  EQU  16      ;=010h
wdCaptionNumberStyleNumberInCircle  EQU  18      ;=012h
wdCaptionNumberStyleGanada  EQU  24      ;=018h
wdCaptionNumberStyleChosung  EQU  25      ;=019h
wdCaptionNumberStyleZodiac1  EQU  30      ;=01Eh
wdCaptionNumberStyleZodiac2  EQU  31      ;=01Fh
wdCaptionNumberStyleHanjaRead  EQU  41      ;=029h
wdCaptionNumberStyleHanjaReadDigit  EQU  42      ;=02Ah
wdCaptionNumberStyleTradChinNum2  EQU  34      ;=022h
wdCaptionNumberStyleTradChinNum3  EQU  35      ;=023h
wdCaptionNumberStyleSimpChinNum2  EQU  38      ;=026h
wdCaptionNumberStyleSimpChinNum3  EQU  39      ;=027h
wdCaptionNumberStyleHebrewLetter1  EQU  45      ;=02Dh
wdCaptionNumberStyleArabicLetter1  EQU  46      ;=02Eh
wdCaptionNumberStyleHebrewLetter2  EQU  47      ;=02Fh
wdCaptionNumberStyleArabicLetter2  EQU  48      ;=030h

;--- WdCaptionNumberStyleHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCaptionNumberStyleHID typedef SDWORD
emptyenum  EQU  0

;--- WdPageNumberStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPageNumberStyle typedef SDWORD
wdPageNumberStyleArabic  EQU  0
wdPageNumberStyleUppercaseRoman  EQU  1
wdPageNumberStyleLowercaseRoman  EQU  2
wdPageNumberStyleUppercaseLetter  EQU  3
wdPageNumberStyleLowercaseLetter  EQU  4
wdPageNumberStyleArabicFullWidth  EQU  14
wdPageNumberStyleKanji  EQU  10
wdPageNumberStyleKanjiDigit  EQU  11
wdPageNumberStyleKanjiTraditional  EQU  16      ;=010h
wdPageNumberStyleNumberInCircle  EQU  18      ;=012h
wdPageNumberStyleHanjaRead  EQU  41      ;=029h
wdPageNumberStyleHanjaReadDigit  EQU  42      ;=02Ah
wdPageNumberStyleTradChinNum1  EQU  33      ;=021h
wdPageNumberStyleTradChinNum2  EQU  34      ;=022h
wdPageNumberStyleSimpChinNum1  EQU  37      ;=025h
wdPageNumberStyleSimpChinNum2  EQU  38      ;=026h
wdPageNumberStyleHebrewLetter1  EQU  45      ;=02Dh
wdPageNumberStyleArabicLetter1  EQU  46      ;=02Eh
wdPageNumberStyleHebrewLetter2  EQU  47      ;=02Fh
wdPageNumberStyleArabicLetter2  EQU  48      ;=030h

;--- WdPageNumberStyleHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPageNumberStyleHID typedef SDWORD
emptyenum  EQU  0

;--- WdStatistic, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdStatistic typedef SDWORD
wdStatisticWords  EQU  0
wdStatisticLines  EQU  1
wdStatisticPages  EQU  2
wdStatisticCharacters  EQU  3
wdStatisticParagraphs  EQU  4
wdStatisticCharactersWithSpaces  EQU  5
wdStatisticFarEastCharacters  EQU  6

;--- WdStatisticHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdStatisticHID typedef SDWORD
emptyenum  EQU  0

;--- WdBuiltInProperty, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBuiltInProperty typedef SDWORD
wdPropertyTitle  EQU  1
wdPropertySubject  EQU  2
wdPropertyAuthor  EQU  3
wdPropertyKeywords  EQU  4
wdPropertyComments  EQU  5
wdPropertyTemplate  EQU  6
wdPropertyLastAuthor  EQU  7
wdPropertyRevision  EQU  8
wdPropertyAppName  EQU  9
wdPropertyTimeLastPrinted  EQU  10
wdPropertyTimeCreated  EQU  11
wdPropertyTimeLastSaved  EQU  12
wdPropertyVBATotalEdit  EQU  13
wdPropertyPages  EQU  14
wdPropertyWords  EQU  15
wdPropertyCharacters  EQU  16      ;=010h
wdPropertySecurity  EQU  17      ;=011h
wdPropertyCategory  EQU  18      ;=012h
wdPropertyFormat  EQU  19      ;=013h
wdPropertyManager  EQU  20      ;=014h
wdPropertyCompany  EQU  21      ;=015h
wdPropertyBytes  EQU  22      ;=016h
wdPropertyLines  EQU  23      ;=017h
wdPropertyParas  EQU  24      ;=018h
wdPropertySlides  EQU  25      ;=019h
wdPropertyNotes  EQU  26      ;=01Ah
wdPropertyHiddenSlides  EQU  27      ;=01Bh
wdPropertyMMClips  EQU  28      ;=01Ch
wdPropertyHyperlinkBase  EQU  29      ;=01Dh
wdPropertyCharsWSpaces  EQU  30      ;=01Eh

;--- WdLineSpacing, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdLineSpacing typedef SDWORD
wdLineSpaceSingle  EQU  0
wdLineSpace1pt5  EQU  1
wdLineSpaceDouble  EQU  2
wdLineSpaceAtLeast  EQU  3
wdLineSpaceExactly  EQU  4
wdLineSpaceMultiple  EQU  5

;--- WdNumberType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdNumberType typedef SDWORD
wdNumberParagraph  EQU  1
wdNumberListNum  EQU  2
wdNumberAllNumbers  EQU  3

;--- WdListType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdListType typedef SDWORD
wdListNoNumbering  EQU  0
wdListListNumOnly  EQU  1
wdListBullet  EQU  2
wdListSimpleNumbering  EQU  3
wdListOutlineNumbering  EQU  4
wdListMixedNumbering  EQU  5

;--- WdStoryType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdStoryType typedef SDWORD
wdMainTextStory  EQU  1
wdFootnotesStory  EQU  2
wdEndnotesStory  EQU  3
wdCommentsStory  EQU  4
wdTextFrameStory  EQU  5
wdEvenPagesHeaderStory  EQU  6
wdPrimaryHeaderStory  EQU  7
wdEvenPagesFooterStory  EQU  8
wdPrimaryFooterStory  EQU  9
wdFirstPageHeaderStory  EQU  10
wdFirstPageFooterStory  EQU  11

;--- WdSaveFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSaveFormat typedef SDWORD
wdFormatDocument  EQU  0
wdFormatTemplate  EQU  1
wdFormatText  EQU  2
wdFormatTextLineBreaks  EQU  3
wdFormatDOSText  EQU  4
wdFormatDOSTextLineBreaks  EQU  5
wdFormatRTF  EQU  6
wdFormatUnicodeText  EQU  7
wdFormatEncodedText  EQU  7
wdFormatHTML  EQU  8

;--- WdOpenFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdOpenFormat typedef SDWORD
wdOpenFormatAuto  EQU  0
wdOpenFormatDocument  EQU  1
wdOpenFormatTemplate  EQU  2
wdOpenFormatRTF  EQU  3
wdOpenFormatText  EQU  4
wdOpenFormatUnicodeText  EQU  5
wdOpenFormatEncodedText  EQU  5
wdOpenFormatAllWord  EQU  6
wdOpenFormatWebPages  EQU  7

;--- WdHeaderFooterIndex, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHeaderFooterIndex typedef SDWORD
wdHeaderFooterPrimary  EQU  1
wdHeaderFooterFirstPage  EQU  2
wdHeaderFooterEvenPages  EQU  3

;--- WdTocFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTocFormat typedef SDWORD
wdTOCTemplate  EQU  0
wdTOCClassic  EQU  1
wdTOCDistinctive  EQU  2
wdTOCFancy  EQU  3
wdTOCModern  EQU  4
wdTOCFormal  EQU  5
wdTOCSimple  EQU  6

;--- WdTofFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTofFormat typedef SDWORD
wdTOFTemplate  EQU  0
wdTOFClassic  EQU  1
wdTOFDistinctive  EQU  2
wdTOFCentered  EQU  3
wdTOFFormal  EQU  4
wdTOFSimple  EQU  5

;--- WdToaFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdToaFormat typedef SDWORD
wdTOATemplate  EQU  0
wdTOAClassic  EQU  1
wdTOADistinctive  EQU  2
wdTOAFormal  EQU  3
wdTOASimple  EQU  4

;--- WdLineStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdLineStyle typedef SDWORD
wdLineStyleNone  EQU  0
wdLineStyleSingle  EQU  1
wdLineStyleDot  EQU  2
wdLineStyleDashSmallGap  EQU  3
wdLineStyleDashLargeGap  EQU  4
wdLineStyleDashDot  EQU  5
wdLineStyleDashDotDot  EQU  6
wdLineStyleDouble  EQU  7
wdLineStyleTriple  EQU  8
wdLineStyleThinThickSmallGap  EQU  9
wdLineStyleThickThinSmallGap  EQU  10
wdLineStyleThinThickThinSmallGap  EQU  11
wdLineStyleThinThickMedGap  EQU  12
wdLineStyleThickThinMedGap  EQU  13
wdLineStyleThinThickThinMedGap  EQU  14
wdLineStyleThinThickLargeGap  EQU  15
wdLineStyleThickThinLargeGap  EQU  16      ;=010h
wdLineStyleThinThickThinLargeGap  EQU  17      ;=011h
wdLineStyleSingleWavy  EQU  18      ;=012h
wdLineStyleDoubleWavy  EQU  19      ;=013h
wdLineStyleDashDotStroked  EQU  20      ;=014h
wdLineStyleEmboss3D  EQU  21      ;=015h
wdLineStyleEngrave3D  EQU  22      ;=016h
wdLineStyleOutset  EQU  23      ;=017h
wdLineStyleInset  EQU  24      ;=018h

;--- WdLineWidth, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdLineWidth typedef SDWORD
wdLineWidth025pt  EQU  2
wdLineWidth050pt  EQU  4
wdLineWidth075pt  EQU  6
wdLineWidth100pt  EQU  8
wdLineWidth150pt  EQU  12
wdLineWidth225pt  EQU  18      ;=012h
wdLineWidth300pt  EQU  24      ;=018h
wdLineWidth450pt  EQU  36      ;=024h
wdLineWidth600pt  EQU  48      ;=030h

;--- WdBreakType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBreakType typedef SDWORD
wdSectionBreakNextPage  EQU  2
wdSectionBreakContinuous  EQU  3
wdSectionBreakEvenPage  EQU  4
wdSectionBreakOddPage  EQU  5
wdLineBreak  EQU  6
wdPageBreak  EQU  7
wdColumnBreak  EQU  8
wdLineBreakClearLeft  EQU  9
wdLineBreakClearRight  EQU  10
wdTextWrappingBreak  EQU  11

;--- WdTabLeader, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTabLeader typedef SDWORD
wdTabLeaderSpaces  EQU  0
wdTabLeaderDots  EQU  1
wdTabLeaderDashes  EQU  2
wdTabLeaderLines  EQU  3
wdTabLeaderHeavy  EQU  4
wdTabLeaderMiddleDot  EQU  5

;--- WdTabLeaderHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTabLeaderHID typedef SDWORD
emptyenum  EQU  0

;--- WdMeasurementUnits, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMeasurementUnits typedef SDWORD
wdInches  EQU  0
wdCentimeters  EQU  1
wdMillimeters  EQU  2
wdPoints  EQU  3
wdPicas  EQU  4

;--- WdMeasurementUnitsHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMeasurementUnitsHID typedef SDWORD
emptyenum  EQU  0

;--- WdDropPosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDropPosition typedef SDWORD
wdDropNone  EQU  0
wdDropNormal  EQU  1
wdDropMargin  EQU  2

;--- WdNumberingRule, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdNumberingRule typedef SDWORD
wdRestartContinuous  EQU  0
wdRestartSection  EQU  1
wdRestartPage  EQU  2

;--- WdFootnoteLocation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFootnoteLocation typedef SDWORD
wdBottomOfPage  EQU  0
wdBeneathText  EQU  1

;--- WdEndnoteLocation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdEndnoteLocation typedef SDWORD
wdEndOfSection  EQU  0
wdEndOfDocument  EQU  1

;--- WdSortSeparator, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSortSeparator typedef SDWORD
wdSortSeparateByTabs  EQU  0
wdSortSeparateByCommas  EQU  1
wdSortSeparateByDefaultTableSeparator  EQU  2

;--- WdTableFieldSeparator, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTableFieldSeparator typedef SDWORD
wdSeparateByParagraphs  EQU  0
wdSeparateByTabs  EQU  1
wdSeparateByCommas  EQU  2
wdSeparateByDefaultListSeparator  EQU  3

;--- WdSortFieldType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSortFieldType typedef SDWORD
wdSortFieldAlphanumeric  EQU  0
wdSortFieldNumeric  EQU  1
wdSortFieldDate  EQU  2
wdSortFieldSyllable  EQU  3
wdSortFieldJapanJIS  EQU  4
wdSortFieldStroke  EQU  5
wdSortFieldKoreaKS  EQU  6

;--- WdSortFieldTypeHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSortFieldTypeHID typedef SDWORD
emptyenum  EQU  0

;--- WdSortOrder, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSortOrder typedef SDWORD
wdSortOrderAscending  EQU  0
wdSortOrderDescending  EQU  1

;--- WdTableFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTableFormat typedef SDWORD
wdTableFormatNone  EQU  0
wdTableFormatSimple1  EQU  1
wdTableFormatSimple2  EQU  2
wdTableFormatSimple3  EQU  3
wdTableFormatClassic1  EQU  4
wdTableFormatClassic2  EQU  5
wdTableFormatClassic3  EQU  6
wdTableFormatClassic4  EQU  7
wdTableFormatColorful1  EQU  8
wdTableFormatColorful2  EQU  9
wdTableFormatColorful3  EQU  10
wdTableFormatColumns1  EQU  11
wdTableFormatColumns2  EQU  12
wdTableFormatColumns3  EQU  13
wdTableFormatColumns4  EQU  14
wdTableFormatColumns5  EQU  15
wdTableFormatGrid1  EQU  16      ;=010h
wdTableFormatGrid2  EQU  17      ;=011h
wdTableFormatGrid3  EQU  18      ;=012h
wdTableFormatGrid4  EQU  19      ;=013h
wdTableFormatGrid5  EQU  20      ;=014h
wdTableFormatGrid6  EQU  21      ;=015h
wdTableFormatGrid7  EQU  22      ;=016h
wdTableFormatGrid8  EQU  23      ;=017h
wdTableFormatList1  EQU  24      ;=018h
wdTableFormatList2  EQU  25      ;=019h
wdTableFormatList3  EQU  26      ;=01Ah
wdTableFormatList4  EQU  27      ;=01Bh
wdTableFormatList5  EQU  28      ;=01Ch
wdTableFormatList6  EQU  29      ;=01Dh
wdTableFormatList7  EQU  30      ;=01Eh
wdTableFormatList8  EQU  31      ;=01Fh
wdTableFormat3DEffects1  EQU  32      ;=020h
wdTableFormat3DEffects2  EQU  33      ;=021h
wdTableFormat3DEffects3  EQU  34      ;=022h
wdTableFormatContemporary  EQU  35      ;=023h
wdTableFormatElegant  EQU  36      ;=024h
wdTableFormatProfessional  EQU  37      ;=025h
wdTableFormatSubtle1  EQU  38      ;=026h
wdTableFormatSubtle2  EQU  39      ;=027h
wdTableFormatWeb1  EQU  40      ;=028h
wdTableFormatWeb2  EQU  41      ;=029h
wdTableFormatWeb3  EQU  42      ;=02Ah

;--- WdTableFormatApply, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTableFormatApply typedef SDWORD
wdTableFormatApplyBorders  EQU  1
wdTableFormatApplyShading  EQU  2
wdTableFormatApplyFont  EQU  4
wdTableFormatApplyColor  EQU  8
wdTableFormatApplyAutoFit  EQU  16      ;=010h
wdTableFormatApplyHeadingRows  EQU  32      ;=020h
wdTableFormatApplyLastRow  EQU  64      ;=040h
wdTableFormatApplyFirstColumn  EQU  128      ;=080h
wdTableFormatApplyLastColumn  EQU  256      ;=0100h

;--- WdLanguageID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdLanguageID typedef SDWORD
wdLanguageNone  EQU  0
wdNoProofing  EQU  1024      ;=0400h
wdAfrikaans  EQU  1078      ;=0436h
wdAlbanian  EQU  1052      ;=041Ch
wdArabicAlgeria  EQU  5121      ;=01401h
wdArabicBahrain  EQU  15361      ;=03C01h
wdArabicEgypt  EQU  3073      ;=0C01h
wdArabicIraq  EQU  2049      ;=0801h
wdArabicJordan  EQU  11265      ;=02C01h
wdArabicKuwait  EQU  13313      ;=03401h
wdArabicLebanon  EQU  12289      ;=03001h
wdArabicLibya  EQU  4097      ;=01001h
wdArabicMorocco  EQU  6145      ;=01801h
wdArabicOman  EQU  8193      ;=02001h
wdArabicQatar  EQU  16385      ;=04001h
wdArabic  EQU  1025      ;=0401h
wdArabicSyria  EQU  10241      ;=02801h
wdArabicTunisia  EQU  7169      ;=01C01h
wdArabicUAE  EQU  14337      ;=03801h
wdArabicYemen  EQU  9217      ;=02401h
wdArmenian  EQU  1067      ;=042Bh
wdAssamese  EQU  1101      ;=044Dh
wdAzeriCyrillic  EQU  2092      ;=082Ch
wdAzeriLatin  EQU  1068      ;=042Ch
wdBasque  EQU  1069      ;=042Dh
wdByelorussian  EQU  1059      ;=0423h
wdBengali  EQU  1093      ;=0445h
wdBulgarian  EQU  1026      ;=0402h
wdBurmese  EQU  1109      ;=0455h
wdCatalan  EQU  1027      ;=0403h
wdChineseHongKong  EQU  3076      ;=0C04h
wdChineseMacao  EQU  5124      ;=01404h
wdSimplifiedChinese  EQU  2052      ;=0804h
wdChineseSingapore  EQU  4100      ;=01004h
wdTraditionalChinese  EQU  1028      ;=0404h
wdCroatian  EQU  1050      ;=041Ah
wdCzech  EQU  1029      ;=0405h
wdDanish  EQU  1030      ;=0406h
wdBelgianDutch  EQU  2067      ;=0813h
wdDutch  EQU  1043      ;=0413h
wdEnglishAUS  EQU  3081      ;=0C09h
wdEnglishBelize  EQU  10249      ;=02809h
wdEnglishCanadian  EQU  4105      ;=01009h
wdEnglishCaribbean  EQU  9225      ;=02409h
wdEnglishIreland  EQU  6153      ;=01809h
wdEnglishJamaica  EQU  8201      ;=02009h
wdEnglishNewZealand  EQU  5129      ;=01409h
wdEnglishPhilippines  EQU  13321      ;=03409h
wdEnglishSouthAfrica  EQU  7177      ;=01C09h
wdEnglishTrinidad  EQU  11273      ;=02C09h
wdEnglishUK  EQU  2057      ;=0809h
wdEnglishUS  EQU  1033      ;=0409h
wdEnglishZimbabwe  EQU  12297      ;=03009h
wdEstonian  EQU  1061      ;=0425h
wdFaeroese  EQU  1080      ;=0438h
wdFarsi  EQU  1065      ;=0429h
wdFinnish  EQU  1035      ;=040Bh
wdBelgianFrench  EQU  2060      ;=080Ch
wdFrenchCameroon  EQU  11276      ;=02C0Ch
wdFrenchCanadian  EQU  3084      ;=0C0Ch
wdFrenchCotedIvoire  EQU  12300      ;=0300Ch
wdFrench  EQU  1036      ;=040Ch
wdFrenchLuxembourg  EQU  5132      ;=0140Ch
wdFrenchMali  EQU  13324      ;=0340Ch
wdFrenchMonaco  EQU  6156      ;=0180Ch
wdFrenchReunion  EQU  8204      ;=0200Ch
wdFrenchSenegal  EQU  10252      ;=0280Ch
wdSwissFrench  EQU  4108      ;=0100Ch
wdFrenchWestIndies  EQU  7180      ;=01C0Ch
wdFrenchZaire  EQU  9228      ;=0240Ch
wdFrisianNetherlands  EQU  1122      ;=0462h
wdGaelicIreland  EQU  2108      ;=083Ch
wdGaelicScotland  EQU  1084      ;=043Ch
wdGalician  EQU  1110      ;=0456h
wdGeorgian  EQU  1079      ;=0437h
wdGermanAustria  EQU  3079      ;=0C07h
wdGerman  EQU  1031      ;=0407h
wdGermanLiechtenstein  EQU  5127      ;=01407h
wdGermanLuxembourg  EQU  4103      ;=01007h
wdSwissGerman  EQU  2055      ;=0807h
wdGreek  EQU  1032      ;=0408h
wdGujarati  EQU  1095      ;=0447h
wdHebrew  EQU  1037      ;=040Dh
wdHindi  EQU  1081      ;=0439h
wdHungarian  EQU  1038      ;=040Eh
wdIcelandic  EQU  1039      ;=040Fh
wdIndonesian  EQU  1057      ;=0421h
wdItalian  EQU  1040      ;=0410h
wdSwissItalian  EQU  2064      ;=0810h
wdJapanese  EQU  1041      ;=0411h
wdKannada  EQU  1099      ;=044Bh
wdKashmiri  EQU  1120      ;=0460h
wdKazakh  EQU  1087      ;=043Fh
wdKhmer  EQU  1107      ;=0453h
wdKirghiz  EQU  1088      ;=0440h
wdKonkani  EQU  1111      ;=0457h
wdKorean  EQU  1042      ;=0412h
wdLao  EQU  1108      ;=0454h
wdLatvian  EQU  1062      ;=0426h
wdLithuanian  EQU  1063      ;=0427h
wdMacedonian  EQU  1071      ;=042Fh
wdMalaysian  EQU  1086      ;=043Eh
wdMalayBruneiDarussalam  EQU  2110      ;=083Eh
wdMalayalam  EQU  1100      ;=044Ch
wdMaltese  EQU  1082      ;=043Ah
wdManipuri  EQU  1112      ;=0458h
wdMarathi  EQU  1102      ;=044Eh
wdMongolian  EQU  1104      ;=0450h
wdNepali  EQU  1121      ;=0461h
wdNorwegianBokmol  EQU  1044      ;=0414h
wdNorwegianNynorsk  EQU  2068      ;=0814h
wdOriya  EQU  1096      ;=0448h
wdPolish  EQU  1045      ;=0415h
wdBrazilianPortuguese  EQU  1046      ;=0416h
wdPortuguese  EQU  2070      ;=0816h
wdPunjabi  EQU  1094      ;=0446h
wdRhaetoRomanic  EQU  1047      ;=0417h
wdRomanianMoldova  EQU  2072      ;=0818h
wdRomanian  EQU  1048      ;=0418h
wdRussianMoldova  EQU  2073      ;=0819h
wdRussian  EQU  1049      ;=0419h
wdSamiLappish  EQU  1083      ;=043Bh
wdSanskrit  EQU  1103      ;=044Fh
wdSerbianCyrillic  EQU  3098      ;=0C1Ah
wdSerbianLatin  EQU  2074      ;=081Ah
wdSindhi  EQU  1113      ;=0459h
wdSlovak  EQU  1051      ;=041Bh
wdSlovenian  EQU  1060      ;=0424h
wdSorbian  EQU  1070      ;=042Eh
wdSpanishArgentina  EQU  11274      ;=02C0Ah
wdSpanishBolivia  EQU  16394      ;=0400Ah
wdSpanishChile  EQU  13322      ;=0340Ah
wdSpanishColombia  EQU  9226      ;=0240Ah
wdSpanishCostaRica  EQU  5130      ;=0140Ah
wdSpanishDominicanRepublic  EQU  7178      ;=01C0Ah
wdSpanishEcuador  EQU  12298      ;=0300Ah
wdSpanishElSalvador  EQU  17418      ;=0440Ah
wdSpanishGuatemala  EQU  4106      ;=0100Ah
wdSpanishHonduras  EQU  18442      ;=0480Ah
wdMexicanSpanish  EQU  2058      ;=080Ah
wdSpanishNicaragua  EQU  19466      ;=04C0Ah
wdSpanishPanama  EQU  6154      ;=0180Ah
wdSpanishParaguay  EQU  15370      ;=03C0Ah
wdSpanishPeru  EQU  10250      ;=0280Ah
wdSpanishPuertoRico  EQU  20490      ;=0500Ah
wdSpanishModernSort  EQU  3082      ;=0C0Ah
wdSpanish  EQU  1034      ;=040Ah
wdSpanishUruguay  EQU  14346      ;=0380Ah
wdSpanishVenezuela  EQU  8202      ;=0200Ah
wdSesotho  EQU  1072      ;=0430h
wdSutu  EQU  1072      ;=0430h
wdSwahili  EQU  1089      ;=0441h
wdSwedishFinland  EQU  2077      ;=081Dh
wdSwedish  EQU  1053      ;=041Dh
wdTajik  EQU  1064      ;=0428h
wdTamil  EQU  1097      ;=0449h
wdTatar  EQU  1092      ;=0444h
wdTelugu  EQU  1098      ;=044Ah
wdThai  EQU  1054      ;=041Eh
wdTibetan  EQU  1105      ;=0451h
wdTsonga  EQU  1073      ;=0431h
wdTswana  EQU  1074      ;=0432h
wdTurkish  EQU  1055      ;=041Fh
wdTurkmen  EQU  1090      ;=0442h
wdUkrainian  EQU  1058      ;=0422h
wdUrdu  EQU  1056      ;=0420h
wdUzbekCyrillic  EQU  2115      ;=0843h
wdUzbekLatin  EQU  1091      ;=0443h
wdVenda  EQU  1075      ;=0433h
wdVietnamese  EQU  1066      ;=042Ah
wdWelsh  EQU  1106      ;=0452h
wdXhosa  EQU  1076      ;=0434h
wdZulu  EQU  1077      ;=0435h

;--- WdFieldType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFieldType typedef SDWORD
wdFieldEmpty  EQU  -1
wdFieldRef  EQU  3
wdFieldIndexEntry  EQU  4
wdFieldFootnoteRef  EQU  5
wdFieldSet  EQU  6
wdFieldIf  EQU  7
wdFieldIndex  EQU  8
wdFieldTOCEntry  EQU  9
wdFieldStyleRef  EQU  10
wdFieldRefDoc  EQU  11
wdFieldSequence  EQU  12
wdFieldTOC  EQU  13
wdFieldInfo  EQU  14
wdFieldTitle  EQU  15
wdFieldSubject  EQU  16      ;=010h
wdFieldAuthor  EQU  17      ;=011h
wdFieldKeyWord  EQU  18      ;=012h
wdFieldComments  EQU  19      ;=013h
wdFieldLastSavedBy  EQU  20      ;=014h
wdFieldCreateDate  EQU  21      ;=015h
wdFieldSaveDate  EQU  22      ;=016h
wdFieldPrintDate  EQU  23      ;=017h
wdFieldRevisionNum  EQU  24      ;=018h
wdFieldEditTime  EQU  25      ;=019h
wdFieldNumPages  EQU  26      ;=01Ah
wdFieldNumWords  EQU  27      ;=01Bh
wdFieldNumChars  EQU  28      ;=01Ch
wdFieldFileName  EQU  29      ;=01Dh
wdFieldTemplate  EQU  30      ;=01Eh
wdFieldDate  EQU  31      ;=01Fh
wdFieldTime  EQU  32      ;=020h
wdFieldPage  EQU  33      ;=021h
wdFieldExpression  EQU  34      ;=022h
wdFieldQuote  EQU  35      ;=023h
wdFieldInclude  EQU  36      ;=024h
wdFieldPageRef  EQU  37      ;=025h
wdFieldAsk  EQU  38      ;=026h
wdFieldFillIn  EQU  39      ;=027h
wdFieldData  EQU  40      ;=028h
wdFieldNext  EQU  41      ;=029h
wdFieldNextIf  EQU  42      ;=02Ah
wdFieldSkipIf  EQU  43      ;=02Bh
wdFieldMergeRec  EQU  44      ;=02Ch
wdFieldDDE  EQU  45      ;=02Dh
wdFieldDDEAuto  EQU  46      ;=02Eh
wdFieldGlossary  EQU  47      ;=02Fh
wdFieldPrint  EQU  48      ;=030h
wdFieldFormula  EQU  49      ;=031h
wdFieldGoToButton  EQU  50      ;=032h
wdFieldMacroButton  EQU  51      ;=033h
wdFieldAutoNumOutline  EQU  52      ;=034h
wdFieldAutoNumLegal  EQU  53      ;=035h
wdFieldAutoNum  EQU  54      ;=036h
wdFieldImport  EQU  55      ;=037h
wdFieldLink  EQU  56      ;=038h
wdFieldSymbol  EQU  57      ;=039h
wdFieldEmbed  EQU  58      ;=03Ah
wdFieldMergeField  EQU  59      ;=03Bh
wdFieldUserName  EQU  60      ;=03Ch
wdFieldUserInitials  EQU  61      ;=03Dh
wdFieldUserAddress  EQU  62      ;=03Eh
wdFieldBarCode  EQU  63      ;=03Fh
wdFieldDocVariable  EQU  64      ;=040h
wdFieldSection  EQU  65      ;=041h
wdFieldSectionPages  EQU  66      ;=042h
wdFieldIncludePicture  EQU  67      ;=043h
wdFieldIncludeText  EQU  68      ;=044h
wdFieldFileSize  EQU  69      ;=045h
wdFieldFormTextInput  EQU  70      ;=046h
wdFieldFormCheckBox  EQU  71      ;=047h
wdFieldNoteRef  EQU  72      ;=048h
wdFieldTOA  EQU  73      ;=049h
wdFieldTOAEntry  EQU  74      ;=04Ah
wdFieldMergeSeq  EQU  75      ;=04Bh
wdFieldPrivate  EQU  77      ;=04Dh
wdFieldDatabase  EQU  78      ;=04Eh
wdFieldAutoText  EQU  79      ;=04Fh
wdFieldCompare  EQU  80      ;=050h
wdFieldAddin  EQU  81      ;=051h
wdFieldSubscriber  EQU  82      ;=052h
wdFieldFormDropDown  EQU  83      ;=053h
wdFieldAdvance  EQU  84      ;=054h
wdFieldDocProperty  EQU  85      ;=055h
wdFieldOCX  EQU  87      ;=057h
wdFieldHyperlink  EQU  88      ;=058h
wdFieldAutoTextList  EQU  89      ;=059h
wdFieldListNum  EQU  90      ;=05Ah
wdFieldHTMLActiveX  EQU  91      ;=05Bh

;--- WdBuiltinStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBuiltinStyle typedef SDWORD
wdStyleNormal  EQU  -1
wdStyleEnvelopeAddress  EQU  -37      ;=0FFFFFFDBh
wdStyleEnvelopeReturn  EQU  -38      ;=0FFFFFFDAh
wdStyleBodyText  EQU  -67      ;=0FFFFFFBDh
wdStyleHeading1  EQU  -2      ;=0FFFFFFFEh
wdStyleHeading2  EQU  -3      ;=0FFFFFFFDh
wdStyleHeading3  EQU  -4      ;=0FFFFFFFCh
wdStyleHeading4  EQU  -5      ;=0FFFFFFFBh
wdStyleHeading5  EQU  -6      ;=0FFFFFFFAh
wdStyleHeading6  EQU  -7      ;=0FFFFFFF9h
wdStyleHeading7  EQU  -8      ;=0FFFFFFF8h
wdStyleHeading8  EQU  -9      ;=0FFFFFFF7h
wdStyleHeading9  EQU  -10      ;=0FFFFFFF6h
wdStyleIndex1  EQU  -11      ;=0FFFFFFF5h
wdStyleIndex2  EQU  -12      ;=0FFFFFFF4h
wdStyleIndex3  EQU  -13      ;=0FFFFFFF3h
wdStyleIndex4  EQU  -14      ;=0FFFFFFF2h
wdStyleIndex5  EQU  -15      ;=0FFFFFFF1h
wdStyleIndex6  EQU  -16      ;=0FFFFFFF0h
wdStyleIndex7  EQU  -17      ;=0FFFFFFEFh
wdStyleIndex8  EQU  -18      ;=0FFFFFFEEh
wdStyleIndex9  EQU  -19      ;=0FFFFFFEDh
wdStyleTOC1  EQU  -20      ;=0FFFFFFECh
wdStyleTOC2  EQU  -21      ;=0FFFFFFEBh
wdStyleTOC3  EQU  -22      ;=0FFFFFFEAh
wdStyleTOC4  EQU  -23      ;=0FFFFFFE9h
wdStyleTOC5  EQU  -24      ;=0FFFFFFE8h
wdStyleTOC6  EQU  -25      ;=0FFFFFFE7h
wdStyleTOC7  EQU  -26      ;=0FFFFFFE6h
wdStyleTOC8  EQU  -27      ;=0FFFFFFE5h
wdStyleTOC9  EQU  -28      ;=0FFFFFFE4h
wdStyleNormalIndent  EQU  -29      ;=0FFFFFFE3h
wdStyleFootnoteText  EQU  -30      ;=0FFFFFFE2h
wdStyleCommentText  EQU  -31      ;=0FFFFFFE1h
wdStyleHeader  EQU  -32      ;=0FFFFFFE0h
wdStyleFooter  EQU  -33      ;=0FFFFFFDFh
wdStyleIndexHeading  EQU  -34      ;=0FFFFFFDEh
wdStyleCaption  EQU  -35      ;=0FFFFFFDDh
wdStyleTableOfFigures  EQU  -36      ;=0FFFFFFDCh
wdStyleFootnoteReference  EQU  -39      ;=0FFFFFFD9h
wdStyleCommentReference  EQU  -40      ;=0FFFFFFD8h
wdStyleLineNumber  EQU  -41      ;=0FFFFFFD7h
wdStylePageNumber  EQU  -42      ;=0FFFFFFD6h
wdStyleEndnoteReference  EQU  -43      ;=0FFFFFFD5h
wdStyleEndnoteText  EQU  -44      ;=0FFFFFFD4h
wdStyleTableOfAuthorities  EQU  -45      ;=0FFFFFFD3h
wdStyleMacroText  EQU  -46      ;=0FFFFFFD2h
wdStyleTOAHeading  EQU  -47      ;=0FFFFFFD1h
wdStyleList  EQU  -48      ;=0FFFFFFD0h
wdStyleListBullet  EQU  -49      ;=0FFFFFFCFh
wdStyleListNumber  EQU  -50      ;=0FFFFFFCEh
wdStyleList2  EQU  -51      ;=0FFFFFFCDh
wdStyleList3  EQU  -52      ;=0FFFFFFCCh
wdStyleList4  EQU  -53      ;=0FFFFFFCBh
wdStyleList5  EQU  -54      ;=0FFFFFFCAh
wdStyleListBullet2  EQU  -55      ;=0FFFFFFC9h
wdStyleListBullet3  EQU  -56      ;=0FFFFFFC8h
wdStyleListBullet4  EQU  -57      ;=0FFFFFFC7h
wdStyleListBullet5  EQU  -58      ;=0FFFFFFC6h
wdStyleListNumber2  EQU  -59      ;=0FFFFFFC5h
wdStyleListNumber3  EQU  -60      ;=0FFFFFFC4h
wdStyleListNumber4  EQU  -61      ;=0FFFFFFC3h
wdStyleListNumber5  EQU  -62      ;=0FFFFFFC2h
wdStyleTitle  EQU  -63      ;=0FFFFFFC1h
wdStyleClosing  EQU  -64      ;=0FFFFFFC0h
wdStyleSignature  EQU  -65      ;=0FFFFFFBFh
wdStyleDefaultParagraphFont  EQU  -66      ;=0FFFFFFBEh
wdStyleBodyTextIndent  EQU  -68      ;=0FFFFFFBCh
wdStyleListContinue  EQU  -69      ;=0FFFFFFBBh
wdStyleListContinue2  EQU  -70      ;=0FFFFFFBAh
wdStyleListContinue3  EQU  -71      ;=0FFFFFFB9h
wdStyleListContinue4  EQU  -72      ;=0FFFFFFB8h
wdStyleListContinue5  EQU  -73      ;=0FFFFFFB7h
wdStyleMessageHeader  EQU  -74      ;=0FFFFFFB6h
wdStyleSubtitle  EQU  -75      ;=0FFFFFFB5h
wdStyleSalutation  EQU  -76      ;=0FFFFFFB4h
wdStyleDate  EQU  -77      ;=0FFFFFFB3h
wdStyleBodyTextFirstIndent  EQU  -78      ;=0FFFFFFB2h
wdStyleBodyTextFirstIndent2  EQU  -79      ;=0FFFFFFB1h
wdStyleNoteHeading  EQU  -80      ;=0FFFFFFB0h
wdStyleBodyText2  EQU  -81      ;=0FFFFFFAFh
wdStyleBodyText3  EQU  -82      ;=0FFFFFFAEh
wdStyleBodyTextIndent2  EQU  -83      ;=0FFFFFFADh
wdStyleBodyTextIndent3  EQU  -84      ;=0FFFFFFACh
wdStyleBlockQuotation  EQU  -85      ;=0FFFFFFABh
wdStyleHyperlink  EQU  -86      ;=0FFFFFFAAh
wdStyleHyperlinkFollowed  EQU  -87      ;=0FFFFFFA9h
wdStyleStrong  EQU  -88      ;=0FFFFFFA8h
wdStyleEmphasis  EQU  -89      ;=0FFFFFFA7h
wdStyleNavPane  EQU  -90      ;=0FFFFFFA6h
wdStylePlainText  EQU  -91      ;=0FFFFFFA5h
wdStyleHtmlNormal  EQU  -95      ;=0FFFFFFA1h
wdStyleHtmlAcronym  EQU  -96      ;=0FFFFFFA0h
wdStyleHtmlAddress  EQU  -97      ;=0FFFFFF9Fh
wdStyleHtmlCite  EQU  -98      ;=0FFFFFF9Eh
wdStyleHtmlCode  EQU  -99      ;=0FFFFFF9Dh
wdStyleHtmlDfn  EQU  -100      ;=0FFFFFF9Ch
wdStyleHtmlKbd  EQU  -101      ;=0FFFFFF9Bh
wdStyleHtmlPre  EQU  -102      ;=0FFFFFF9Ah
wdStyleHtmlSamp  EQU  -103      ;=0FFFFFF99h
wdStyleHtmlTt  EQU  -104      ;=0FFFFFF98h
wdStyleHtmlVar  EQU  -105      ;=0FFFFFF97h

;--- WdWordDialogTab, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdWordDialogTab typedef SDWORD
wdDialogToolsOptionsTabView  EQU  204      ;=0CCh
wdDialogToolsOptionsTabGeneral  EQU  203      ;=0CBh
wdDialogToolsOptionsTabEdit  EQU  224      ;=0E0h
wdDialogToolsOptionsTabPrint  EQU  208      ;=0D0h
wdDialogToolsOptionsTabSave  EQU  209      ;=0D1h
wdDialogToolsOptionsTabProofread  EQU  211      ;=0D3h
wdDialogToolsOptionsTabTrackChanges  EQU  386      ;=0182h
wdDialogToolsOptionsTabUserInfo  EQU  213      ;=0D5h
wdDialogToolsOptionsTabCompatibility  EQU  525      ;=020Dh
wdDialogToolsOptionsTabTypography  EQU  739      ;=02E3h
wdDialogToolsOptionsTabFileLocations  EQU  225      ;=0E1h
wdDialogToolsOptionsTabFuzzy  EQU  790      ;=0316h
wdDialogToolsOptionsTabHangulHanjaConversion  EQU  786      ;=0312h
wdDialogToolsOptionsTabBidi  EQU  1029      ;=0405h
wdDialogFilePageSetupTabMargins  EQU  150000      ;=0249F0h
wdDialogFilePageSetupTabPaperSize  EQU  150001      ;=0249F1h
wdDialogFilePageSetupTabPaperSource  EQU  150002      ;=0249F2h
wdDialogFilePageSetupTabLayout  EQU  150003      ;=0249F3h
wdDialogFilePageSetupTabCharsLines  EQU  150004      ;=0249F4h
wdDialogInsertSymbolTabSymbols  EQU  200000      ;=030D40h
wdDialogInsertSymbolTabSpecialCharacters  EQU  200001      ;=030D41h
wdDialogNoteOptionsTabAllFootnotes  EQU  300000      ;=0493E0h
wdDialogNoteOptionsTabAllEndnotes  EQU  300001      ;=0493E1h
wdDialogInsertIndexAndTablesTabIndex  EQU  400000      ;=061A80h
wdDialogInsertIndexAndTablesTabTableOfContents  EQU  400001      ;=061A81h
wdDialogInsertIndexAndTablesTabTableOfFigures  EQU  400002      ;=061A82h
wdDialogInsertIndexAndTablesTabTableOfAuthorities  EQU  400003      ;=061A83h
wdDialogOrganizerTabStyles  EQU  500000      ;=07A120h
wdDialogOrganizerTabAutoText  EQU  500001      ;=07A121h
wdDialogOrganizerTabCommandBars  EQU  500002      ;=07A122h
wdDialogOrganizerTabMacros  EQU  500003      ;=07A123h
wdDialogFormatFontTabFont  EQU  600000      ;=0927C0h
wdDialogFormatFontTabCharacterSpacing  EQU  600001      ;=0927C1h
wdDialogFormatFontTabAnimation  EQU  600002      ;=0927C2h
wdDialogFormatBordersAndShadingTabBorders  EQU  700000      ;=0AAE60h
wdDialogFormatBordersAndShadingTabPageBorder  EQU  700001      ;=0AAE61h
wdDialogFormatBordersAndShadingTabShading  EQU  700002      ;=0AAE62h
wdDialogToolsEnvelopesAndLabelsTabEnvelopes  EQU  800000      ;=0C3500h
wdDialogToolsEnvelopesAndLabelsTabLabels  EQU  800001      ;=0C3501h
wdDialogFormatParagraphTabIndentsAndSpacing  EQU  1000000      ;=0F4240h
wdDialogFormatParagraphTabTextFlow  EQU  1000001      ;=0F4241h
wdDialogFormatParagraphTabTeisai  EQU  1000002      ;=0F4242h
wdDialogFormatDrawingObjectTabColorsAndLines  EQU  1200000      ;=0124F80h
wdDialogFormatDrawingObjectTabSize  EQU  1200001      ;=0124F81h
wdDialogFormatDrawingObjectTabPosition  EQU  1200002      ;=0124F82h
wdDialogFormatDrawingObjectTabWrapping  EQU  1200003      ;=0124F83h
wdDialogFormatDrawingObjectTabPicture  EQU  1200004      ;=0124F84h
wdDialogFormatDrawingObjectTabTextbox  EQU  1200005      ;=0124F85h
wdDialogFormatDrawingObjectTabWeb  EQU  1200006      ;=0124F86h
wdDialogFormatDrawingObjectTabHR  EQU  1200007      ;=0124F87h
wdDialogToolsAutoCorrectExceptionsTabFirstLetter  EQU  1400000      ;=0155CC0h
wdDialogToolsAutoCorrectExceptionsTabInitialCaps  EQU  1400001      ;=0155CC1h
wdDialogToolsAutoCorrectExceptionsTabHangulAndAlphabet  EQU  1400002      ;=0155CC2h
wdDialogToolsAutoCorrectExceptionsTabIac  EQU  1400003      ;=0155CC3h
wdDialogFormatBulletsAndNumberingTabBulleted  EQU  1500000      ;=016E360h
wdDialogFormatBulletsAndNumberingTabNumbered  EQU  1500001      ;=016E361h
wdDialogFormatBulletsAndNumberingTabOutlineNumbered  EQU  1500002      ;=016E362h
wdDialogLetterWizardTabLetterFormat  EQU  1600000      ;=0186A00h
wdDialogLetterWizardTabRecipientInfo  EQU  1600001      ;=0186A01h
wdDialogLetterWizardTabOtherElements  EQU  1600002      ;=0186A02h
wdDialogLetterWizardTabSenderInfo  EQU  1600003      ;=0186A03h
wdDialogToolsAutoManagerTabAutoCorrect  EQU  1700000      ;=019F0A0h
wdDialogToolsAutoManagerTabAutoFormatAsYouType  EQU  1700001      ;=019F0A1h
wdDialogToolsAutoManagerTabAutoText  EQU  1700002      ;=019F0A2h
wdDialogToolsAutoManagerTabAutoFormat  EQU  1700003      ;=019F0A3h
wdDialogEmailOptionsTabSignature  EQU  1900000      ;=01CFDE0h
wdDialogEmailOptionsTabStationary  EQU  1900001      ;=01CFDE1h
wdDialogEmailOptionsTabQuoting  EQU  1900002      ;=01CFDE2h
wdDialogWebOptionsGeneral  EQU  2000000      ;=01E8480h
wdDialogWebOptionsFiles  EQU  2000001      ;=01E8481h
wdDialogWebOptionsPictures  EQU  2000002      ;=01E8482h
wdDialogWebOptionsEncoding  EQU  2000003      ;=01E8483h
wdDialogWebOptionsFonts  EQU  2000004      ;=01E8484h

;--- WdWordDialogTabHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdWordDialogTabHID typedef SDWORD
emptyenum  EQU  0

;--- WdWordDialog, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdWordDialog typedef SDWORD
wdDialogHelpAbout  EQU  9
wdDialogHelpWordPerfectHelp  EQU  10
wdDialogHelpWordPerfectHelpOptions  EQU  511      ;=01FFh
wdDialogFormatChangeCase  EQU  322      ;=0142h
wdDialogToolsOptionsFuzzy  EQU  790      ;=0316h
wdDialogToolsWordCount  EQU  228      ;=0E4h
wdDialogDocumentStatistics  EQU  78      ;=04Eh
wdDialogFileNew  EQU  79      ;=04Fh
wdDialogFileOpen  EQU  80      ;=050h
wdDialogMailMergeOpenDataSource  EQU  81      ;=051h
wdDialogMailMergeOpenHeaderSource  EQU  82      ;=052h
wdDialogMailMergeUseAddressBook  EQU  779      ;=030Bh
wdDialogFileSaveAs  EQU  84      ;=054h
wdDialogFileSummaryInfo  EQU  86      ;=056h
wdDialogToolsTemplates  EQU  87      ;=057h
wdDialogOrganizer  EQU  222      ;=0DEh
wdDialogFilePrint  EQU  88      ;=058h
wdDialogMailMerge  EQU  676      ;=02A4h
wdDialogMailMergeCheck  EQU  677      ;=02A5h
wdDialogMailMergeQueryOptions  EQU  681      ;=02A9h
wdDialogMailMergeFindRecord  EQU  569      ;=0239h
wdDialogMailMergeInsertIf  EQU  4049      ;=0FD1h
wdDialogMailMergeInsertNextIf  EQU  4053      ;=0FD5h
wdDialogMailMergeInsertSkipIf  EQU  4055      ;=0FD7h
wdDialogMailMergeInsertFillIn  EQU  4048      ;=0FD0h
wdDialogMailMergeInsertAsk  EQU  4047      ;=0FCFh
wdDialogMailMergeInsertSet  EQU  4054      ;=0FD6h
wdDialogMailMergeHelper  EQU  680      ;=02A8h
wdDialogLetterWizard  EQU  821      ;=0335h
wdDialogFilePrintSetup  EQU  97      ;=061h
wdDialogFileFind  EQU  99      ;=063h
wdDialogMailMergeCreateDataSource  EQU  642      ;=0282h
wdDialogMailMergeCreateHeaderSource  EQU  643      ;=0283h
wdDialogEditPasteSpecial  EQU  111      ;=06Fh
wdDialogEditFind  EQU  112      ;=070h
wdDialogEditReplace  EQU  117      ;=075h
wdDialogEditGoToOld  EQU  811      ;=032Bh
wdDialogEditGoTo  EQU  896      ;=0380h
wdDialogCreateAutoText  EQU  872      ;=0368h
wdDialogEditAutoText  EQU  985      ;=03D9h
wdDialogEditLinks  EQU  124      ;=07Ch
wdDialogEditObject  EQU  125      ;=07Dh
wdDialogConvertObject  EQU  392      ;=0188h
wdDialogTableToText  EQU  128      ;=080h
wdDialogTextToTable  EQU  127      ;=07Fh
wdDialogTableInsertTable  EQU  129      ;=081h
wdDialogTableInsertCells  EQU  130      ;=082h
wdDialogTableInsertRow  EQU  131      ;=083h
wdDialogTableDeleteCells  EQU  133      ;=085h
wdDialogTableSplitCells  EQU  137      ;=089h
wdDialogTableFormula  EQU  348      ;=015Ch
wdDialogTableAutoFormat  EQU  563      ;=0233h
wdDialogTableFormatCell  EQU  612      ;=0264h
wdDialogViewZoom  EQU  577      ;=0241h
wdDialogNewToolbar  EQU  586      ;=024Ah
wdDialogInsertBreak  EQU  159      ;=09Fh
wdDialogInsertFootnote  EQU  370      ;=0172h
wdDialogInsertSymbol  EQU  162      ;=0A2h
wdDialogInsertPicture  EQU  163      ;=0A3h
wdDialogInsertFile  EQU  164      ;=0A4h
wdDialogInsertDateTime  EQU  165      ;=0A5h
wdDialogInsertNumber  EQU  812      ;=032Ch
wdDialogInsertField  EQU  166      ;=0A6h
wdDialogInsertDatabase  EQU  341      ;=0155h
wdDialogInsertMergeField  EQU  167      ;=0A7h
wdDialogInsertBookmark  EQU  168      ;=0A8h
wdDialogInsertHyperlink  EQU  925      ;=039Dh
wdDialogMarkIndexEntry  EQU  169      ;=0A9h
wdDialogMarkCitation  EQU  463      ;=01CFh
wdDialogEditTOACategory  EQU  625      ;=0271h
wdDialogInsertIndexAndTables  EQU  473      ;=01D9h
wdDialogInsertIndex  EQU  170      ;=0AAh
wdDialogInsertTableOfContents  EQU  171      ;=0ABh
wdDialogMarkTableOfContentsEntry  EQU  442      ;=01BAh
wdDialogInsertTableOfFigures  EQU  472      ;=01D8h
wdDialogInsertTableOfAuthorities  EQU  471      ;=01D7h
wdDialogInsertObject  EQU  172      ;=0ACh
wdDialogFormatCallout  EQU  610      ;=0262h
wdDialogDrawSnapToGrid  EQU  633      ;=0279h
wdDialogDrawAlign  EQU  634      ;=027Ah
wdDialogToolsEnvelopesAndLabels  EQU  607      ;=025Fh
wdDialogToolsCreateEnvelope  EQU  173      ;=0ADh
wdDialogToolsCreateLabels  EQU  489      ;=01E9h
wdDialogToolsProtectDocument  EQU  503      ;=01F7h
wdDialogToolsProtectSection  EQU  578      ;=0242h
wdDialogToolsUnprotectDocument  EQU  521      ;=0209h
wdDialogFormatFont  EQU  174      ;=0AEh
wdDialogFormatParagraph  EQU  175      ;=0AFh
wdDialogFormatSectionLayout  EQU  176      ;=0B0h
wdDialogFormatColumns  EQU  177      ;=0B1h
wdDialogFileDocumentLayout  EQU  178      ;=0B2h
wdDialogFileMacPageSetup  EQU  685      ;=02ADh
wdDialogFilePrintOneCopy  EQU  445      ;=01BDh
wdDialogFileMacPageSetupGX  EQU  444      ;=01BCh
wdDialogFileMacCustomPageSetupGX  EQU  737      ;=02E1h
wdDialogFilePageSetup  EQU  178      ;=0B2h
wdDialogFormatTabs  EQU  179      ;=0B3h
wdDialogFormatStyle  EQU  180      ;=0B4h
wdDialogFormatStyleGallery  EQU  505      ;=01F9h
wdDialogFormatDefineStyleFont  EQU  181      ;=0B5h
wdDialogFormatDefineStylePara  EQU  182      ;=0B6h
wdDialogFormatDefineStyleTabs  EQU  183      ;=0B7h
wdDialogFormatDefineStyleFrame  EQU  184      ;=0B8h
wdDialogFormatDefineStyleBorders  EQU  185      ;=0B9h
wdDialogFormatDefineStyleLang  EQU  186      ;=0BAh
wdDialogFormatPicture  EQU  187      ;=0BBh
wdDialogToolsLanguage  EQU  188      ;=0BCh
wdDialogFormatBordersAndShading  EQU  189      ;=0BDh
wdDialogFormatDrawingObject  EQU  960      ;=03C0h
wdDialogFormatFrame  EQU  190      ;=0BEh
wdDialogFormatDropCap  EQU  488      ;=01E8h
wdDialogFormatBulletsAndNumbering  EQU  824      ;=0338h
wdDialogToolsHyphenation  EQU  195      ;=0C3h
wdDialogToolsBulletsNumbers  EQU  196      ;=0C4h
wdDialogToolsHighlightChanges  EQU  197      ;=0C5h
wdDialogToolsAcceptRejectChanges  EQU  506      ;=01FAh
wdDialogToolsMergeDocuments  EQU  435      ;=01B3h
wdDialogToolsCompareDocuments  EQU  198      ;=0C6h
wdDialogTableSort  EQU  199      ;=0C7h
wdDialogToolsCustomizeMenuBar  EQU  615      ;=0267h
wdDialogToolsCustomize  EQU  152      ;=098h
wdDialogToolsCustomizeKeyboard  EQU  432      ;=01B0h
wdDialogToolsCustomizeMenus  EQU  433      ;=01B1h
wdDialogListCommands  EQU  723      ;=02D3h
wdDialogToolsOptions  EQU  974      ;=03CEh
wdDialogToolsOptionsGeneral  EQU  203      ;=0CBh
wdDialogToolsAdvancedSettings  EQU  206      ;=0CEh
wdDialogToolsOptionsCompatibility  EQU  525      ;=020Dh
wdDialogToolsOptionsPrint  EQU  208      ;=0D0h
wdDialogToolsOptionsSave  EQU  209      ;=0D1h
wdDialogToolsOptionsSpellingAndGrammar  EQU  211      ;=0D3h
wdDialogToolsSpellingAndGrammar  EQU  828      ;=033Ch
wdDialogToolsThesaurus  EQU  194      ;=0C2h
wdDialogToolsOptionsUserInfo  EQU  213      ;=0D5h
wdDialogToolsOptionsAutoFormat  EQU  959      ;=03BFh
wdDialogToolsOptionsTrackChanges  EQU  386      ;=0182h
wdDialogToolsOptionsEdit  EQU  224      ;=0E0h
wdDialogToolsMacro  EQU  215      ;=0D7h
wdDialogInsertPageNumbers  EQU  294      ;=0126h
wdDialogFormatPageNumber  EQU  298      ;=012Ah
wdDialogNoteOptions  EQU  373      ;=0175h
wdDialogCopyFile  EQU  300      ;=012Ch
wdDialogFormatAddrFonts  EQU  103      ;=067h
wdDialogFormatRetAddrFonts  EQU  221      ;=0DDh
wdDialogToolsOptionsFileLocations  EQU  225      ;=0E1h
wdDialogToolsCreateDirectory  EQU  833      ;=0341h
wdDialogUpdateTOC  EQU  331      ;=014Bh
wdDialogInsertFormField  EQU  483      ;=01E3h
wdDialogFormFieldOptions  EQU  353      ;=0161h
wdDialogInsertCaption  EQU  357      ;=0165h
wdDialogInsertAutoCaption  EQU  359      ;=0167h
wdDialogInsertAddCaption  EQU  402      ;=0192h
wdDialogInsertCaptionNumbering  EQU  358      ;=0166h
wdDialogInsertCrossReference  EQU  367      ;=016Fh
wdDialogToolsManageFields  EQU  631      ;=0277h
wdDialogToolsAutoManager  EQU  915      ;=0393h
wdDialogToolsAutoCorrect  EQU  378      ;=017Ah
wdDialogToolsAutoCorrectExceptions  EQU  762      ;=02FAh
wdDialogConnect  EQU  420      ;=01A4h
wdDialogToolsOptionsBidi  EQU  1029      ;=0405h
wdDialogToolsOptionsView  EQU  204      ;=0CCh
wdDialogInsertSubdocument  EQU  583      ;=0247h
wdDialogFileRoutingSlip  EQU  624      ;=0270h
wdDialogFontSubstitution  EQU  581      ;=0245h
wdDialogEditCreatePublisher  EQU  732      ;=02DCh
wdDialogEditSubscribeTo  EQU  733      ;=02DDh
wdDialogEditPublishOptions  EQU  735      ;=02DFh
wdDialogEditSubscribeOptions  EQU  736      ;=02E0h
wdDialogToolsOptionsTypography  EQU  739      ;=02E3h
wdDialogToolsOptionsAutoFormatAsYouType  EQU  778      ;=030Ah
wdDialogControlRun  EQU  235      ;=0EBh
wdDialogFileVersions  EQU  945      ;=03B1h
wdDialogToolsAutoSummarize  EQU  874      ;=036Ah
wdDialogFileSaveVersion  EQU  1007      ;=03EFh
wdDialogWindowActivate  EQU  220      ;=0DCh
wdDialogToolsMacroRecord  EQU  214      ;=0D6h
wdDialogToolsRevisions  EQU  197      ;=0C5h
wdDialogEmailOptions  EQU  863      ;=035Fh
wdDialogWebOptions  EQU  898      ;=0382h
wdDialogFitText  EQU  983      ;=03D7h
wdDialogPhoneticGuide  EQU  986      ;=03DAh
wdDialogHorizontalInVertical  EQU  1160      ;=0488h
wdDialogTwoLinesInOne  EQU  1161      ;=0489h
wdDialogFormatEncloseCharacters  EQU  1162      ;=048Ah
wdDialogFormatTheme  EQU  855      ;=0357h
wdDialogTCSCTranslator  EQU  1156      ;=0484h

;--- WdWordDialogHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdWordDialogHID typedef SDWORD
emptyenum  EQU  0

;--- WdFieldKind, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFieldKind typedef SDWORD
wdFieldKindNone  EQU  0
wdFieldKindHot  EQU  1
wdFieldKindWarm  EQU  2
wdFieldKindCold  EQU  3

;--- WdTextFormFieldType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTextFormFieldType typedef SDWORD
wdRegularText  EQU  0
wdNumberText  EQU  1
wdDateText  EQU  2
wdCurrentDateText  EQU  3
wdCurrentTimeText  EQU  4
wdCalculationText  EQU  5

;--- WdChevronConvertRule, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdChevronConvertRule typedef SDWORD
wdNeverConvert  EQU  0
wdAlwaysConvert  EQU  1
wdAskToNotConvert  EQU  2
wdAskToConvert  EQU  3

;--- WdMailMergeMainDocType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailMergeMainDocType typedef SDWORD
wdNotAMergeDocument  EQU  -1
wdFormLetters  EQU  0
wdMailingLabels  EQU  1
wdEnvelopes  EQU  2
wdCatalog  EQU  3

;--- WdMailMergeState, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailMergeState typedef SDWORD
wdNormalDocument  EQU  0
wdMainDocumentOnly  EQU  1
wdMainAndDataSource  EQU  2
wdMainAndHeader  EQU  3
wdMainAndSourceAndHeader  EQU  4
wdDataSource  EQU  5

;--- WdMailMergeDestination, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailMergeDestination typedef SDWORD
wdSendToNewDocument  EQU  0
wdSendToPrinter  EQU  1
wdSendToEmail  EQU  2
wdSendToFax  EQU  3

;--- WdMailMergeActiveRecord, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailMergeActiveRecord typedef SDWORD
wdNoActiveRecord  EQU  -1
wdNextRecord  EQU  -2      ;=0FFFFFFFEh
wdPreviousRecord  EQU  -3      ;=0FFFFFFFDh
wdFirstRecord  EQU  -4      ;=0FFFFFFFCh
wdLastRecord  EQU  -5      ;=0FFFFFFFBh

;--- WdMailMergeDefaultRecord, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailMergeDefaultRecord typedef SDWORD
wdDefaultFirstRecord  EQU  1
wdDefaultLastRecord  EQU  -16      ;=0FFFFFFF0h

;--- WdMailMergeDataSource, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailMergeDataSource typedef SDWORD
wdNoMergeInfo  EQU  -1
wdMergeInfoFromWord  EQU  0
wdMergeInfoFromAccessDDE  EQU  1
wdMergeInfoFromExcelDDE  EQU  2
wdMergeInfoFromMSQueryDDE  EQU  3
wdMergeInfoFromODBC  EQU  4

;--- WdMailMergeComparison, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailMergeComparison typedef SDWORD
wdMergeIfEqual  EQU  0
wdMergeIfNotEqual  EQU  1
wdMergeIfLessThan  EQU  2
wdMergeIfGreaterThan  EQU  3
wdMergeIfLessThanOrEqual  EQU  4
wdMergeIfGreaterThanOrEqual  EQU  5
wdMergeIfIsBlank  EQU  6
wdMergeIfIsNotBlank  EQU  7

;--- WdBookmarkSortBy, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBookmarkSortBy typedef SDWORD
wdSortByName  EQU  0
wdSortByLocation  EQU  1

;--- WdWindowState, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdWindowState typedef SDWORD
wdWindowStateNormal  EQU  0
wdWindowStateMaximize  EQU  1
wdWindowStateMinimize  EQU  2

;--- WdPictureLinkType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPictureLinkType typedef SDWORD
wdLinkNone  EQU  0
wdLinkDataInDoc  EQU  1
wdLinkDataOnDisk  EQU  2

;--- WdLinkType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdLinkType typedef SDWORD
wdLinkTypeOLE  EQU  0
wdLinkTypePicture  EQU  1
wdLinkTypeText  EQU  2
wdLinkTypeReference  EQU  3
wdLinkTypeInclude  EQU  4
wdLinkTypeImport  EQU  5
wdLinkTypeDDE  EQU  6
wdLinkTypeDDEAuto  EQU  7

;--- WdWindowType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdWindowType typedef SDWORD
wdWindowDocument  EQU  0
wdWindowTemplate  EQU  1

;--- WdViewType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdViewType typedef SDWORD
wdNormalView  EQU  1
wdOutlineView  EQU  2
wdPrintView  EQU  3
wdPrintPreview  EQU  4
wdMasterView  EQU  5
wdWebView  EQU  6

;--- WdSeekView, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSeekView typedef SDWORD
wdSeekMainDocument  EQU  0
wdSeekPrimaryHeader  EQU  1
wdSeekFirstPageHeader  EQU  2
wdSeekEvenPagesHeader  EQU  3
wdSeekPrimaryFooter  EQU  4
wdSeekFirstPageFooter  EQU  5
wdSeekEvenPagesFooter  EQU  6
wdSeekFootnotes  EQU  7
wdSeekEndnotes  EQU  8
wdSeekCurrentPageHeader  EQU  9
wdSeekCurrentPageFooter  EQU  10

;--- WdSpecialPane, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSpecialPane typedef SDWORD
wdPaneNone  EQU  0
wdPanePrimaryHeader  EQU  1
wdPaneFirstPageHeader  EQU  2
wdPaneEvenPagesHeader  EQU  3
wdPanePrimaryFooter  EQU  4
wdPaneFirstPageFooter  EQU  5
wdPaneEvenPagesFooter  EQU  6
wdPaneFootnotes  EQU  7
wdPaneEndnotes  EQU  8
wdPaneFootnoteContinuationNotice  EQU  9
wdPaneFootnoteContinuationSeparator  EQU  10
wdPaneFootnoteSeparator  EQU  11
wdPaneEndnoteContinuationNotice  EQU  12
wdPaneEndnoteContinuationSeparator  EQU  13
wdPaneEndnoteSeparator  EQU  14
wdPaneComments  EQU  15
wdPaneCurrentPageHeader  EQU  16      ;=010h
wdPaneCurrentPageFooter  EQU  17      ;=011h

;--- WdPageFit, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPageFit typedef SDWORD
wdPageFitNone  EQU  0
wdPageFitFullPage  EQU  1
wdPageFitBestFit  EQU  2
wdPageFitTextFit  EQU  3

;--- WdBrowseTarget, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBrowseTarget typedef SDWORD
wdBrowsePage  EQU  1
wdBrowseSection  EQU  2
wdBrowseComment  EQU  3
wdBrowseFootnote  EQU  4
wdBrowseEndnote  EQU  5
wdBrowseField  EQU  6
wdBrowseTable  EQU  7
wdBrowseGraphic  EQU  8
wdBrowseHeading  EQU  9
wdBrowseEdit  EQU  10
wdBrowseFind  EQU  11
wdBrowseGoTo  EQU  12

;--- WdPaperTray, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPaperTray typedef SDWORD
wdPrinterDefaultBin  EQU  0
wdPrinterUpperBin  EQU  1
wdPrinterOnlyBin  EQU  1
wdPrinterLowerBin  EQU  2
wdPrinterMiddleBin  EQU  3
wdPrinterManualFeed  EQU  4
wdPrinterEnvelopeFeed  EQU  5
wdPrinterManualEnvelopeFeed  EQU  6
wdPrinterAutomaticSheetFeed  EQU  7
wdPrinterTractorFeed  EQU  8
wdPrinterSmallFormatBin  EQU  9
wdPrinterLargeFormatBin  EQU  10
wdPrinterLargeCapacityBin  EQU  11
wdPrinterPaperCassette  EQU  14
wdPrinterFormSource  EQU  15

;--- WdOrientation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdOrientation typedef SDWORD
wdOrientPortrait  EQU  0
wdOrientLandscape  EQU  1

;--- WdSelectionType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSelectionType typedef SDWORD
wdNoSelection  EQU  0
wdSelectionIP  EQU  1
wdSelectionNormal  EQU  2
wdSelectionFrame  EQU  3
wdSelectionColumn  EQU  4
wdSelectionRow  EQU  5
wdSelectionBlock  EQU  6
wdSelectionInlineShape  EQU  7
wdSelectionShape  EQU  8

;--- WdCaptionLabelID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCaptionLabelID typedef SDWORD
wdCaptionFigure  EQU  -1
wdCaptionTable  EQU  -2      ;=0FFFFFFFEh
wdCaptionEquation  EQU  -3      ;=0FFFFFFFDh

;--- WdReferenceType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdReferenceType typedef SDWORD
wdRefTypeNumberedItem  EQU  0
wdRefTypeHeading  EQU  1
wdRefTypeBookmark  EQU  2
wdRefTypeFootnote  EQU  3
wdRefTypeEndnote  EQU  4

;--- WdReferenceKind, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdReferenceKind typedef SDWORD
wdContentText  EQU  -1
wdNumberRelativeContext  EQU  -2      ;=0FFFFFFFEh
wdNumberNoContext  EQU  -3      ;=0FFFFFFFDh
wdNumberFullContext  EQU  -4      ;=0FFFFFFFCh
wdEntireCaption  EQU  2
wdOnlyLabelAndNumber  EQU  3
wdOnlyCaptionText  EQU  4
wdFootnoteNumber  EQU  5
wdEndnoteNumber  EQU  6
wdPageNumber  EQU  7
wdPosition  EQU  15
wdFootnoteNumberFormatted  EQU  16      ;=010h
wdEndnoteNumberFormatted  EQU  17      ;=011h

;--- WdIndexFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdIndexFormat typedef SDWORD
wdIndexTemplate  EQU  0
wdIndexClassic  EQU  1
wdIndexFancy  EQU  2
wdIndexModern  EQU  3
wdIndexBulleted  EQU  4
wdIndexFormal  EQU  5
wdIndexSimple  EQU  6

;--- WdIndexType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdIndexType typedef SDWORD
wdIndexIndent  EQU  0
wdIndexRunin  EQU  1

;--- WdRevisionsWrap, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRevisionsWrap typedef SDWORD
wdWrapNever  EQU  0
wdWrapAlways  EQU  1
wdWrapAsk  EQU  2

;--- WdRevisionType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRevisionType typedef SDWORD
wdNoRevision  EQU  0
wdRevisionInsert  EQU  1
wdRevisionDelete  EQU  2
wdRevisionProperty  EQU  3
wdRevisionParagraphNumber  EQU  4
wdRevisionDisplayField  EQU  5
wdRevisionReconcile  EQU  6
wdRevisionConflict  EQU  7
wdRevisionStyle  EQU  8
wdRevisionReplace  EQU  9

;--- WdRoutingSlipDelivery, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRoutingSlipDelivery typedef SDWORD
wdOneAfterAnother  EQU  0
wdAllAtOnce  EQU  1

;--- WdRoutingSlipStatus, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRoutingSlipStatus typedef SDWORD
wdNotYetRouted  EQU  0
wdRouteInProgress  EQU  1
wdRouteComplete  EQU  2

;--- WdSectionStart, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSectionStart typedef SDWORD
wdSectionContinuous  EQU  0
wdSectionNewColumn  EQU  1
wdSectionNewPage  EQU  2
wdSectionEvenPage  EQU  3
wdSectionOddPage  EQU  4

;--- WdSaveOptions, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSaveOptions typedef SDWORD
wdDoNotSaveChanges  EQU  0
wdSaveChanges  EQU  -1
wdPromptToSaveChanges  EQU  -2      ;=0FFFFFFFEh

;--- WdDocumentKind, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDocumentKind typedef SDWORD
wdDocumentNotSpecified  EQU  0
wdDocumentLetter  EQU  1
wdDocumentEmail  EQU  2

;--- WdDocumentType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDocumentType typedef SDWORD
wdTypeDocument  EQU  0
wdTypeTemplate  EQU  1
wdTypeFrameset  EQU  2

;--- WdOriginalFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdOriginalFormat typedef SDWORD
wdWordDocument  EQU  0
wdOriginalDocumentFormat  EQU  1
wdPromptUser  EQU  2

;--- WdRelocate, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRelocate typedef SDWORD
wdRelocateUp  EQU  0
wdRelocateDown  EQU  1

;--- WdInsertedTextMark, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdInsertedTextMark typedef SDWORD
wdInsertedTextMarkNone  EQU  0
wdInsertedTextMarkBold  EQU  1
wdInsertedTextMarkItalic  EQU  2
wdInsertedTextMarkUnderline  EQU  3
wdInsertedTextMarkDoubleUnderline  EQU  4

;--- WdRevisedLinesMark, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRevisedLinesMark typedef SDWORD
wdRevisedLinesMarkNone  EQU  0
wdRevisedLinesMarkLeftBorder  EQU  1
wdRevisedLinesMarkRightBorder  EQU  2
wdRevisedLinesMarkOutsideBorder  EQU  3

;--- WdDeletedTextMark, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDeletedTextMark typedef SDWORD
wdDeletedTextMarkHidden  EQU  0
wdDeletedTextMarkStrikeThrough  EQU  1
wdDeletedTextMarkCaret  EQU  2
wdDeletedTextMarkPound  EQU  3

;--- WdRevisedPropertiesMark, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRevisedPropertiesMark typedef SDWORD
wdRevisedPropertiesMarkNone  EQU  0
wdRevisedPropertiesMarkBold  EQU  1
wdRevisedPropertiesMarkItalic  EQU  2
wdRevisedPropertiesMarkUnderline  EQU  3
wdRevisedPropertiesMarkDoubleUnderline  EQU  4

;--- WdFieldShading, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFieldShading typedef SDWORD
wdFieldShadingNever  EQU  0
wdFieldShadingAlways  EQU  1
wdFieldShadingWhenSelected  EQU  2

;--- WdDefaultFilePath, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDefaultFilePath typedef SDWORD
wdDocumentsPath  EQU  0
wdPicturesPath  EQU  1
wdUserTemplatesPath  EQU  2
wdWorkgroupTemplatesPath  EQU  3
wdUserOptionsPath  EQU  4
wdAutoRecoverPath  EQU  5
wdToolsPath  EQU  6
wdTutorialPath  EQU  7
wdStartupPath  EQU  8
wdProgramPath  EQU  9
wdGraphicsFiltersPath  EQU  10
wdTextConvertersPath  EQU  11
wdProofingToolsPath  EQU  12
wdTempFilePath  EQU  13
wdCurrentFolderPath  EQU  14
wdStyleGalleryPath  EQU  15
wdBorderArtPath  EQU  19      ;=013h

;--- WdCompatibility, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCompatibility typedef SDWORD
wdNoTabHangIndent  EQU  1
wdNoSpaceRaiseLower  EQU  2
wdPrintColBlack  EQU  3
wdWrapTrailSpaces  EQU  4
wdNoColumnBalance  EQU  5
wdConvMailMergeEsc  EQU  6
wdSuppressSpBfAfterPgBrk  EQU  7
wdSuppressTopSpacing  EQU  8
wdOrigWordTableRules  EQU  9
wdTransparentMetafiles  EQU  10
wdShowBreaksInFrames  EQU  11
wdSwapBordersFacingPages  EQU  12
wdLeaveBackslashAlone  EQU  13
wdExpandShiftReturn  EQU  14
wdDontULTrailSpace  EQU  15
wdDontBalanceSingleByteDoubleByteWidth  EQU  16      ;=010h
wdSuppressTopSpacingMac5  EQU  17      ;=011h
wdSpacingInWholePoints  EQU  18      ;=012h
wdPrintBodyTextBeforeHeader  EQU  19      ;=013h
wdNoLeading  EQU  20      ;=014h
wdNoSpaceForUL  EQU  21      ;=015h
wdMWSmallCaps  EQU  22      ;=016h
wdNoExtraLineSpacing  EQU  23      ;=017h
wdTruncateFontHeight  EQU  24      ;=018h
wdSubFontBySize  EQU  25      ;=019h
wdUsePrinterMetrics  EQU  26      ;=01Ah
wdWW6BorderRules  EQU  27      ;=01Bh
wdExactOnTop  EQU  28      ;=01Ch
wdSuppressBottomSpacing  EQU  29      ;=01Dh
wdWPSpaceWidth  EQU  30      ;=01Eh
wdWPJustification  EQU  31      ;=01Fh
wdLineWrapLikeWord6  EQU  32      ;=020h
wdShapeLayoutLikeWW8  EQU  33      ;=021h
wdFootnoteLayoutLikeWW8  EQU  34      ;=022h
wdDontUseHTMLParagraphAutoSpacing  EQU  35      ;=023h
wdDontAdjustLineHeightInTable  EQU  36      ;=024h
wdForgetLastTabAlignment  EQU  37      ;=025h
wdAutospaceLikeWW7  EQU  38      ;=026h
wdAlignTablesRowByRow  EQU  39      ;=027h
wdLayoutRawTableWidth  EQU  40      ;=028h
wdLayoutTableRowsApart  EQU  41      ;=029h
wdUseWord97LineBreakingRules  EQU  42      ;=02Ah

;--- WdPaperSize, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPaperSize typedef SDWORD
wdPaper10x14  EQU  0
wdPaper11x17  EQU  1
wdPaperLetter  EQU  2
wdPaperLetterSmall  EQU  3
wdPaperLegal  EQU  4
wdPaperExecutive  EQU  5
wdPaperA3  EQU  6
wdPaperA4  EQU  7
wdPaperA4Small  EQU  8
wdPaperA5  EQU  9
wdPaperB4  EQU  10
wdPaperB5  EQU  11
wdPaperCSheet  EQU  12
wdPaperDSheet  EQU  13
wdPaperESheet  EQU  14
wdPaperFanfoldLegalGerman  EQU  15
wdPaperFanfoldStdGerman  EQU  16      ;=010h
wdPaperFanfoldUS  EQU  17      ;=011h
wdPaperFolio  EQU  18      ;=012h
wdPaperLedger  EQU  19      ;=013h
wdPaperNote  EQU  20      ;=014h
wdPaperQuarto  EQU  21      ;=015h
wdPaperStatement  EQU  22      ;=016h
wdPaperTabloid  EQU  23      ;=017h
wdPaperEnvelope9  EQU  24      ;=018h
wdPaperEnvelope10  EQU  25      ;=019h
wdPaperEnvelope11  EQU  26      ;=01Ah
wdPaperEnvelope12  EQU  27      ;=01Bh
wdPaperEnvelope14  EQU  28      ;=01Ch
wdPaperEnvelopeB4  EQU  29      ;=01Dh
wdPaperEnvelopeB5  EQU  30      ;=01Eh
wdPaperEnvelopeB6  EQU  31      ;=01Fh
wdPaperEnvelopeC3  EQU  32      ;=020h
wdPaperEnvelopeC4  EQU  33      ;=021h
wdPaperEnvelopeC5  EQU  34      ;=022h
wdPaperEnvelopeC6  EQU  35      ;=023h
wdPaperEnvelopeC65  EQU  36      ;=024h
wdPaperEnvelopeDL  EQU  37      ;=025h
wdPaperEnvelopeItaly  EQU  38      ;=026h
wdPaperEnvelopeMonarch  EQU  39      ;=027h
wdPaperEnvelopePersonal  EQU  40      ;=028h
wdPaperCustom  EQU  41      ;=029h

;--- WdCustomLabelPageSize, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCustomLabelPageSize typedef SDWORD
wdCustomLabelLetter  EQU  0
wdCustomLabelLetterLS  EQU  1
wdCustomLabelA4  EQU  2
wdCustomLabelA4LS  EQU  3
wdCustomLabelA5  EQU  4
wdCustomLabelA5LS  EQU  5
wdCustomLabelB5  EQU  6
wdCustomLabelMini  EQU  7
wdCustomLabelFanfold  EQU  8
wdCustomLabelVertHalfSheet  EQU  9
wdCustomLabelVertHalfSheetLS  EQU  10
wdCustomLabelHigaki  EQU  11
wdCustomLabelHigakiLS  EQU  12
wdCustomLabelB4JIS  EQU  13

;--- WdProtectionType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdProtectionType typedef SDWORD
wdNoProtection  EQU  -1
wdAllowOnlyRevisions  EQU  0
wdAllowOnlyComments  EQU  1
wdAllowOnlyFormFields  EQU  2

;--- WdPartOfSpeech, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPartOfSpeech typedef SDWORD
wdAdjective  EQU  0
wdNoun  EQU  1
wdAdverb  EQU  2
wdVerb  EQU  3
wdPronoun  EQU  4
wdConjunction  EQU  5
wdPreposition  EQU  6
wdInterjection  EQU  7
wdIdiom  EQU  8
wdOther  EQU  9

;--- WdSubscriberFormats, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSubscriberFormats typedef SDWORD
wdSubscriberBestFormat  EQU  0
wdSubscriberRTF  EQU  1
wdSubscriberText  EQU  2
wdSubscriberPict  EQU  4

;--- WdEditionType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdEditionType typedef SDWORD
wdPublisher  EQU  0
wdSubscriber  EQU  1

;--- WdEditionOption, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdEditionOption typedef SDWORD
wdCancelPublisher  EQU  0
wdSendPublisher  EQU  1
wdSelectPublisher  EQU  2
wdAutomaticUpdate  EQU  3
wdManualUpdate  EQU  4
wdChangeAttributes  EQU  5
wdUpdateSubscriber  EQU  6
wdOpenSource  EQU  7

;--- WdRelativeHorizontalPosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRelativeHorizontalPosition typedef SDWORD
wdRelativeHorizontalPositionMargin  EQU  0
wdRelativeHorizontalPositionPage  EQU  1
wdRelativeHorizontalPositionColumn  EQU  2
wdRelativeHorizontalPositionCharacter  EQU  3

;--- WdRelativeVerticalPosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdRelativeVerticalPosition typedef SDWORD
wdRelativeVerticalPositionMargin  EQU  0
wdRelativeVerticalPositionPage  EQU  1
wdRelativeVerticalPositionParagraph  EQU  2
wdRelativeVerticalPositionLine  EQU  3

;--- WdHelpType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHelpType typedef SDWORD
wdHelp  EQU  0
wdHelpAbout  EQU  1
wdHelpActiveWindow  EQU  2
wdHelpContents  EQU  3
wdHelpExamplesAndDemos  EQU  4
wdHelpIndex  EQU  5
wdHelpKeyboard  EQU  6
wdHelpPSSHelp  EQU  7
wdHelpQuickPreview  EQU  8
wdHelpSearch  EQU  9
wdHelpUsingHelp  EQU  10
wdHelpIchitaro  EQU  11
wdHelpPE2  EQU  12
wdHelpHWP  EQU  13

;--- WdHelpTypeHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHelpTypeHID typedef SDWORD
emptyenum  EQU  0

;--- WdKeyCategory, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdKeyCategory typedef SDWORD
wdKeyCategoryNil  EQU  -1
wdKeyCategoryDisable  EQU  0
wdKeyCategoryCommand  EQU  1
wdKeyCategoryMacro  EQU  2
wdKeyCategoryFont  EQU  3
wdKeyCategoryAutoText  EQU  4
wdKeyCategoryStyle  EQU  5
wdKeyCategorySymbol  EQU  6
wdKeyCategoryPrefix  EQU  7

;--- WdKey, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdKey typedef SDWORD
wdNoKey  EQU  255      ;=0FFh
wdKeyShift  EQU  256      ;=0100h
wdKeyControl  EQU  512      ;=0200h
wdKeyCommand  EQU  512      ;=0200h
wdKeyAlt  EQU  1024      ;=0400h
wdKeyOption  EQU  1024      ;=0400h
wdKeyA  EQU  65      ;=041h
wdKeyB  EQU  66      ;=042h
wdKeyC  EQU  67      ;=043h
wdKeyD  EQU  68      ;=044h
wdKeyE  EQU  69      ;=045h
wdKeyF  EQU  70      ;=046h
wdKeyG  EQU  71      ;=047h
wdKeyH  EQU  72      ;=048h
wdKeyI  EQU  73      ;=049h
wdKeyJ  EQU  74      ;=04Ah
wdKeyK  EQU  75      ;=04Bh
wdKeyL  EQU  76      ;=04Ch
wdKeyM  EQU  77      ;=04Dh
wdKeyN  EQU  78      ;=04Eh
wdKeyO  EQU  79      ;=04Fh
wdKeyP  EQU  80      ;=050h
wdKeyQ  EQU  81      ;=051h
wdKeyR  EQU  82      ;=052h
wdKeyS  EQU  83      ;=053h
wdKeyT  EQU  84      ;=054h
wdKeyU  EQU  85      ;=055h
wdKeyV  EQU  86      ;=056h
wdKeyW  EQU  87      ;=057h
wdKeyX  EQU  88      ;=058h
wdKeyY  EQU  89      ;=059h
wdKeyZ  EQU  90      ;=05Ah
wdKey0  EQU  48      ;=030h
wdKey1  EQU  49      ;=031h
wdKey2  EQU  50      ;=032h
wdKey3  EQU  51      ;=033h
wdKey4  EQU  52      ;=034h
wdKey5  EQU  53      ;=035h
wdKey6  EQU  54      ;=036h
wdKey7  EQU  55      ;=037h
wdKey8  EQU  56      ;=038h
wdKey9  EQU  57      ;=039h
wdKeyBackspace  EQU  8
wdKeyTab  EQU  9
wdKeyNumeric5Special  EQU  12
wdKeyReturn  EQU  13
wdKeyPause  EQU  19      ;=013h
wdKeyEsc  EQU  27      ;=01Bh
wdKeySpacebar  EQU  32      ;=020h
wdKeyPageUp  EQU  33      ;=021h
wdKeyPageDown  EQU  34      ;=022h
wdKeyEnd  EQU  35      ;=023h
wdKeyHome  EQU  36      ;=024h
wdKeyInsert  EQU  45      ;=02Dh
wdKeyDelete  EQU  46      ;=02Eh
wdKeyNumeric0  EQU  96      ;=060h
wdKeyNumeric1  EQU  97      ;=061h
wdKeyNumeric2  EQU  98      ;=062h
wdKeyNumeric3  EQU  99      ;=063h
wdKeyNumeric4  EQU  100      ;=064h
wdKeyNumeric5  EQU  101      ;=065h
wdKeyNumeric6  EQU  102      ;=066h
wdKeyNumeric7  EQU  103      ;=067h
wdKeyNumeric8  EQU  104      ;=068h
wdKeyNumeric9  EQU  105      ;=069h
wdKeyNumericMultiply  EQU  106      ;=06Ah
wdKeyNumericAdd  EQU  107      ;=06Bh
wdKeyNumericSubtract  EQU  109      ;=06Dh
wdKeyNumericDecimal  EQU  110      ;=06Eh
wdKeyNumericDivide  EQU  111      ;=06Fh
wdKeyF1  EQU  112      ;=070h
wdKeyF2  EQU  113      ;=071h
wdKeyF3  EQU  114      ;=072h
wdKeyF4  EQU  115      ;=073h
wdKeyF5  EQU  116      ;=074h
wdKeyF6  EQU  117      ;=075h
wdKeyF7  EQU  118      ;=076h
wdKeyF8  EQU  119      ;=077h
wdKeyF9  EQU  120      ;=078h
wdKeyF10  EQU  121      ;=079h
wdKeyF11  EQU  122      ;=07Ah
wdKeyF12  EQU  123      ;=07Bh
wdKeyF13  EQU  124      ;=07Ch
wdKeyF14  EQU  125      ;=07Dh
wdKeyF15  EQU  126      ;=07Eh
wdKeyF16  EQU  127      ;=07Fh
wdKeyScrollLock  EQU  145      ;=091h
wdKeySemiColon  EQU  186      ;=0BAh
wdKeyEquals  EQU  187      ;=0BBh
wdKeyComma  EQU  188      ;=0BCh
wdKeyHyphen  EQU  189      ;=0BDh
wdKeyPeriod  EQU  190      ;=0BEh
wdKeySlash  EQU  191      ;=0BFh
wdKeyBackSingleQuote  EQU  192      ;=0C0h
wdKeyOpenSquareBrace  EQU  219      ;=0DBh
wdKeyBackSlash  EQU  220      ;=0DCh
wdKeyCloseSquareBrace  EQU  221      ;=0DDh
wdKeySingleQuote  EQU  222      ;=0DEh

;--- WdOLEType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdOLEType typedef SDWORD
wdOLELink  EQU  0
wdOLEEmbed  EQU  1
wdOLEControl  EQU  2

;--- WdOLEVerb, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdOLEVerb typedef SDWORD
wdOLEVerbPrimary  EQU  0
wdOLEVerbShow  EQU  -1
wdOLEVerbOpen  EQU  -2      ;=0FFFFFFFEh
wdOLEVerbHide  EQU  -3      ;=0FFFFFFFDh
wdOLEVerbUIActivate  EQU  -4      ;=0FFFFFFFCh
wdOLEVerbInPlaceActivate  EQU  -5      ;=0FFFFFFFBh
wdOLEVerbDiscardUndoState  EQU  -6      ;=0FFFFFFFAh

;--- WdOLEPlacement, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdOLEPlacement typedef SDWORD
wdInLine  EQU  0
wdFloatOverText  EQU  1

;--- WdEnvelopeOrientation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdEnvelopeOrientation typedef SDWORD
wdLeftPortrait  EQU  0
wdCenterPortrait  EQU  1
wdRightPortrait  EQU  2
wdLeftLandscape  EQU  3
wdCenterLandscape  EQU  4
wdRightLandscape  EQU  5
wdLeftClockwise  EQU  6
wdCenterClockwise  EQU  7
wdRightClockwise  EQU  8

;--- WdLetterStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdLetterStyle typedef SDWORD
wdFullBlock  EQU  0
wdModifiedBlock  EQU  1
wdSemiBlock  EQU  2

;--- WdLetterheadLocation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdLetterheadLocation typedef SDWORD
wdLetterTop  EQU  0
wdLetterBottom  EQU  1
wdLetterLeft  EQU  2
wdLetterRight  EQU  3

;--- WdSalutationType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSalutationType typedef SDWORD
wdSalutationInformal  EQU  0
wdSalutationFormal  EQU  1
wdSalutationBusiness  EQU  2
wdSalutationOther  EQU  3

;--- WdSalutationGender, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSalutationGender typedef SDWORD
wdGenderFemale  EQU  0
wdGenderMale  EQU  1
wdGenderNeutral  EQU  2
wdGenderUnknown  EQU  3

;--- WdMovementType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMovementType typedef SDWORD
wdMove  EQU  0
wdExtend  EQU  1

;--- WdConstants, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdConstants typedef SDWORD
wdUndefined  EQU  9999999      ;=098967Fh
wdToggle  EQU  9999998      ;=098967Eh
wdForward  EQU  1073741823      ;=03FFFFFFFh
wdBackward  EQU  -1073741823      ;=0C0000001h
wdAutoPosition  EQU  0
wdFirst  EQU  1
wdCreatorCode  EQU  1297307460      ;=04D535744h

;--- WdPasteDataType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPasteDataType typedef SDWORD
wdPasteOLEObject  EQU  0
wdPasteRTF  EQU  1
wdPasteText  EQU  2
wdPasteMetafilePicture  EQU  3
wdPasteBitmap  EQU  4
wdPasteDeviceIndependentBitmap  EQU  5
wdPasteHyperlink  EQU  7
wdPasteShape  EQU  8
wdPasteEnhancedMetafile  EQU  9
wdPasteHTML  EQU  10

;--- WdPrintOutItem, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPrintOutItem typedef SDWORD
wdPrintDocumentContent  EQU  0
wdPrintProperties  EQU  1
wdPrintComments  EQU  2
wdPrintStyles  EQU  3
wdPrintAutoTextEntries  EQU  4
wdPrintKeyAssignments  EQU  5
wdPrintEnvelope  EQU  6

;--- WdPrintOutPages, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPrintOutPages typedef SDWORD
wdPrintAllPages  EQU  0
wdPrintOddPagesOnly  EQU  1
wdPrintEvenPagesOnly  EQU  2

;--- WdPrintOutRange, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPrintOutRange typedef SDWORD
wdPrintAllDocument  EQU  0
wdPrintSelection  EQU  1
wdPrintCurrentPage  EQU  2
wdPrintFromTo  EQU  3
wdPrintRangeOfPages  EQU  4

;--- WdDictionaryType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDictionaryType typedef SDWORD
wdSpelling  EQU  0
wdGrammar  EQU  1
wdThesaurus  EQU  2
wdHyphenation  EQU  3
wdSpellingComplete  EQU  4
wdSpellingCustom  EQU  5
wdSpellingLegal  EQU  6
wdSpellingMedical  EQU  7
wdHangulHanjaConversion  EQU  8
wdHangulHanjaConversionCustom  EQU  9

;--- WdDictionaryTypeHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDictionaryTypeHID typedef SDWORD
emptyenum  EQU  0

;--- WdSpellingWordType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSpellingWordType typedef SDWORD
wdSpellword  EQU  0
wdWildcard  EQU  1
wdAnagram  EQU  2

;--- WdSpellingErrorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSpellingErrorType typedef SDWORD
wdSpellingCorrect  EQU  0
wdSpellingNotInDictionary  EQU  1
wdSpellingCapitalization  EQU  2

;--- WdProofreadingErrorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdProofreadingErrorType typedef SDWORD
wdSpellingError  EQU  0
wdGrammaticalError  EQU  1

;--- WdInlineShapeType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdInlineShapeType typedef SDWORD
wdInlineShapeEmbeddedOLEObject  EQU  1
wdInlineShapeLinkedOLEObject  EQU  2
wdInlineShapePicture  EQU  3
wdInlineShapeLinkedPicture  EQU  4
wdInlineShapeOLEControlObject  EQU  5
wdInlineShapeHorizontalLine  EQU  6
wdInlineShapePictureHorizontalLine  EQU  7
wdInlineShapeLinkedPictureHorizontalLine  EQU  8
wdInlineShapePictureBullet  EQU  9
wdInlineShapeScriptAnchor  EQU  10
wdInlineShapeOWSAnchor  EQU  11

;--- WdArrangeStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdArrangeStyle typedef SDWORD
wdTiled  EQU  0
wdIcons  EQU  1

;--- WdSelectionFlags, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSelectionFlags typedef SDWORD
wdSelStartActive  EQU  1
wdSelAtEOL  EQU  2
wdSelOvertype  EQU  4
wdSelActive  EQU  8
wdSelReplace  EQU  16      ;=010h

;--- WdAutoVersions, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdAutoVersions typedef SDWORD
wdAutoVersionOff  EQU  0
wdAutoVersionOnClose  EQU  1

;--- WdOrganizerObject, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdOrganizerObject typedef SDWORD
wdOrganizerObjectStyles  EQU  0
wdOrganizerObjectAutoText  EQU  1
wdOrganizerObjectCommandBars  EQU  2
wdOrganizerObjectProjectItems  EQU  3

;--- WdFindMatch, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFindMatch typedef SDWORD
wdMatchParagraphMark  EQU  65551      ;=01000Fh
wdMatchTabCharacter  EQU  9
wdMatchCommentMark  EQU  5
wdMatchAnyCharacter  EQU  65599      ;=01003Fh
wdMatchAnyDigit  EQU  65567      ;=01001Fh
wdMatchAnyLetter  EQU  65583      ;=01002Fh
wdMatchCaretCharacter  EQU  11
wdMatchColumnBreak  EQU  14
wdMatchEmDash  EQU  8212      ;=02014h
wdMatchEnDash  EQU  8211      ;=02013h
wdMatchEndnoteMark  EQU  65555      ;=010013h
wdMatchField  EQU  19      ;=013h
wdMatchFootnoteMark  EQU  65554      ;=010012h
wdMatchGraphic  EQU  1
wdMatchManualLineBreak  EQU  65551      ;=01000Fh
wdMatchManualPageBreak  EQU  65564      ;=01001Ch
wdMatchNonbreakingHyphen  EQU  30      ;=01Eh
wdMatchNonbreakingSpace  EQU  160      ;=0A0h
wdMatchOptionalHyphen  EQU  31      ;=01Fh
wdMatchSectionBreak  EQU  65580      ;=01002Ch
wdMatchWhiteSpace  EQU  65655      ;=010077h

;--- WdFindWrap, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFindWrap typedef SDWORD
wdFindStop  EQU  0
wdFindContinue  EQU  1
wdFindAsk  EQU  2

;--- WdInformation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdInformation typedef SDWORD
wdActiveEndAdjustedPageNumber  EQU  1
wdActiveEndSectionNumber  EQU  2
wdActiveEndPageNumber  EQU  3
wdNumberOfPagesInDocument  EQU  4
wdHorizontalPositionRelativeToPage  EQU  5
wdVerticalPositionRelativeToPage  EQU  6
wdHorizontalPositionRelativeToTextBoundary  EQU  7
wdVerticalPositionRelativeToTextBoundary  EQU  8
wdFirstCharacterColumnNumber  EQU  9
wdFirstCharacterLineNumber  EQU  10
wdFrameIsSelected  EQU  11
wdWithInTable  EQU  12
wdStartOfRangeRowNumber  EQU  13
wdEndOfRangeRowNumber  EQU  14
wdMaximumNumberOfRows  EQU  15
wdStartOfRangeColumnNumber  EQU  16      ;=010h
wdEndOfRangeColumnNumber  EQU  17      ;=011h
wdMaximumNumberOfColumns  EQU  18      ;=012h
wdZoomPercentage  EQU  19      ;=013h
wdSelectionMode  EQU  20      ;=014h
wdCapsLock  EQU  21      ;=015h
wdNumLock  EQU  22      ;=016h
wdOverType  EQU  23      ;=017h
wdRevisionMarking  EQU  24      ;=018h
wdInFootnoteEndnotePane  EQU  25      ;=019h
wdInCommentPane  EQU  26      ;=01Ah
wdInHeaderFooter  EQU  28      ;=01Ch
wdAtEndOfRowMarker  EQU  31      ;=01Fh
wdReferenceOfType  EQU  32      ;=020h
wdHeaderFooterType  EQU  33      ;=021h
wdInMasterDocument  EQU  34      ;=022h
wdInFootnote  EQU  35      ;=023h
wdInEndnote  EQU  36      ;=024h
wdInWordMail  EQU  37      ;=025h
wdInClipboard  EQU  38      ;=026h

;--- WdWrapType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdWrapType typedef SDWORD
wdWrapSquare  EQU  0
wdWrapTight  EQU  1
wdWrapThrough  EQU  2
wdWrapNone  EQU  3
wdWrapTopBottom  EQU  4

;--- WdWrapSideType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdWrapSideType typedef SDWORD
wdWrapBoth  EQU  0
wdWrapLeft  EQU  1
wdWrapRight  EQU  2
wdWrapLargest  EQU  3

;--- WdOutlineLevel, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdOutlineLevel typedef SDWORD
wdOutlineLevel1  EQU  1
wdOutlineLevel2  EQU  2
wdOutlineLevel3  EQU  3
wdOutlineLevel4  EQU  4
wdOutlineLevel5  EQU  5
wdOutlineLevel6  EQU  6
wdOutlineLevel7  EQU  7
wdOutlineLevel8  EQU  8
wdOutlineLevel9  EQU  9
wdOutlineLevelBodyText  EQU  10

;--- WdTextOrientation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTextOrientation typedef SDWORD
wdTextOrientationHorizontal  EQU  0
wdTextOrientationUpward  EQU  2
wdTextOrientationDownward  EQU  3
wdTextOrientationVerticalFarEast  EQU  1
wdTextOrientationHorizontalRotatedFarEast  EQU  4

;--- WdTextOrientationHID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTextOrientationHID typedef SDWORD
emptyenum  EQU  0

;--- WdPageBorderArt, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPageBorderArt typedef SDWORD
wdArtApples  EQU  1
wdArtMapleMuffins  EQU  2
wdArtCakeSlice  EQU  3
wdArtCandyCorn  EQU  4
wdArtIceCreamCones  EQU  5
wdArtChampagneBottle  EQU  6
wdArtPartyGlass  EQU  7
wdArtChristmasTree  EQU  8
wdArtTrees  EQU  9
wdArtPalmsColor  EQU  10
wdArtBalloons3Colors  EQU  11
wdArtBalloonsHotAir  EQU  12
wdArtPartyFavor  EQU  13
wdArtConfettiStreamers  EQU  14
wdArtHearts  EQU  15
wdArtHeartBalloon  EQU  16      ;=010h
wdArtStars3D  EQU  17      ;=011h
wdArtStarsShadowed  EQU  18      ;=012h
wdArtStars  EQU  19      ;=013h
wdArtSun  EQU  20      ;=014h
wdArtEarth2  EQU  21      ;=015h
wdArtEarth1  EQU  22      ;=016h
wdArtPeopleHats  EQU  23      ;=017h
wdArtSombrero  EQU  24      ;=018h
wdArtPencils  EQU  25      ;=019h
wdArtPackages  EQU  26      ;=01Ah
wdArtClocks  EQU  27      ;=01Bh
wdArtFirecrackers  EQU  28      ;=01Ch
wdArtRings  EQU  29      ;=01Dh
wdArtMapPins  EQU  30      ;=01Eh
wdArtConfetti  EQU  31      ;=01Fh
wdArtCreaturesButterfly  EQU  32      ;=020h
wdArtCreaturesLadyBug  EQU  33      ;=021h
wdArtCreaturesFish  EQU  34      ;=022h
wdArtBirdsFlight  EQU  35      ;=023h
wdArtScaredCat  EQU  36      ;=024h
wdArtBats  EQU  37      ;=025h
wdArtFlowersRoses  EQU  38      ;=026h
wdArtFlowersRedRose  EQU  39      ;=027h
wdArtPoinsettias  EQU  40      ;=028h
wdArtHolly  EQU  41      ;=029h
wdArtFlowersTiny  EQU  42      ;=02Ah
wdArtFlowersPansy  EQU  43      ;=02Bh
wdArtFlowersModern2  EQU  44      ;=02Ch
wdArtFlowersModern1  EQU  45      ;=02Dh
wdArtWhiteFlowers  EQU  46      ;=02Eh
wdArtVine  EQU  47      ;=02Fh
wdArtFlowersDaisies  EQU  48      ;=030h
wdArtFlowersBlockPrint  EQU  49      ;=031h
wdArtDecoArchColor  EQU  50      ;=032h
wdArtFans  EQU  51      ;=033h
wdArtFilm  EQU  52      ;=034h
wdArtLightning1  EQU  53      ;=035h
wdArtCompass  EQU  54      ;=036h
wdArtDoubleD  EQU  55      ;=037h
wdArtClassicalWave  EQU  56      ;=038h
wdArtShadowedSquares  EQU  57      ;=039h
wdArtTwistedLines1  EQU  58      ;=03Ah
wdArtWaveline  EQU  59      ;=03Bh
wdArtQuadrants  EQU  60      ;=03Ch
wdArtCheckedBarColor  EQU  61      ;=03Dh
wdArtSwirligig  EQU  62      ;=03Eh
wdArtPushPinNote1  EQU  63      ;=03Fh
wdArtPushPinNote2  EQU  64      ;=040h
wdArtPumpkin1  EQU  65      ;=041h
wdArtEggsBlack  EQU  66      ;=042h
wdArtCup  EQU  67      ;=043h
wdArtHeartGray  EQU  68      ;=044h
wdArtGingerbreadMan  EQU  69      ;=045h
wdArtBabyPacifier  EQU  70      ;=046h
wdArtBabyRattle  EQU  71      ;=047h
wdArtCabins  EQU  72      ;=048h
wdArtHouseFunky  EQU  73      ;=049h
wdArtStarsBlack  EQU  74      ;=04Ah
wdArtSnowflakes  EQU  75      ;=04Bh
wdArtSnowflakeFancy  EQU  76      ;=04Ch
wdArtSkyrocket  EQU  77      ;=04Dh
wdArtSeattle  EQU  78      ;=04Eh
wdArtMusicNotes  EQU  79      ;=04Fh
wdArtPalmsBlack  EQU  80      ;=050h
wdArtMapleLeaf  EQU  81      ;=051h
wdArtPaperClips  EQU  82      ;=052h
wdArtShorebirdTracks  EQU  83      ;=053h
wdArtPeople  EQU  84      ;=054h
wdArtPeopleWaving  EQU  85      ;=055h
wdArtEclipsingSquares2  EQU  86      ;=056h
wdArtHypnotic  EQU  87      ;=057h
wdArtDiamondsGray  EQU  88      ;=058h
wdArtDecoArch  EQU  89      ;=059h
wdArtDecoBlocks  EQU  90      ;=05Ah
wdArtCirclesLines  EQU  91      ;=05Bh
wdArtPapyrus  EQU  92      ;=05Ch
wdArtWoodwork  EQU  93      ;=05Dh
wdArtWeavingBraid  EQU  94      ;=05Eh
wdArtWeavingRibbon  EQU  95      ;=05Fh
wdArtWeavingAngles  EQU  96      ;=060h
wdArtArchedScallops  EQU  97      ;=061h
wdArtSafari  EQU  98      ;=062h
wdArtCelticKnotwork  EQU  99      ;=063h
wdArtCrazyMaze  EQU  100      ;=064h
wdArtEclipsingSquares1  EQU  101      ;=065h
wdArtBirds  EQU  102      ;=066h
wdArtFlowersTeacup  EQU  103      ;=067h
wdArtNorthwest  EQU  104      ;=068h
wdArtSouthwest  EQU  105      ;=069h
wdArtTribal6  EQU  106      ;=06Ah
wdArtTribal4  EQU  107      ;=06Bh
wdArtTribal3  EQU  108      ;=06Ch
wdArtTribal2  EQU  109      ;=06Dh
wdArtTribal5  EQU  110      ;=06Eh
wdArtXIllusions  EQU  111      ;=06Fh
wdArtZanyTriangles  EQU  112      ;=070h
wdArtPyramids  EQU  113      ;=071h
wdArtPyramidsAbove  EQU  114      ;=072h
wdArtConfettiGrays  EQU  115      ;=073h
wdArtConfettiOutline  EQU  116      ;=074h
wdArtConfettiWhite  EQU  117      ;=075h
wdArtMosaic  EQU  118      ;=076h
wdArtLightning2  EQU  119      ;=077h
wdArtHeebieJeebies  EQU  120      ;=078h
wdArtLightBulb  EQU  121      ;=079h
wdArtGradient  EQU  122      ;=07Ah
wdArtTriangleParty  EQU  123      ;=07Bh
wdArtTwistedLines2  EQU  124      ;=07Ch
wdArtMoons  EQU  125      ;=07Dh
wdArtOvals  EQU  126      ;=07Eh
wdArtDoubleDiamonds  EQU  127      ;=07Fh
wdArtChainLink  EQU  128      ;=080h
wdArtTriangles  EQU  129      ;=081h
wdArtTribal1  EQU  130      ;=082h
wdArtMarqueeToothed  EQU  131      ;=083h
wdArtSharksTeeth  EQU  132      ;=084h
wdArtSawtooth  EQU  133      ;=085h
wdArtSawtoothGray  EQU  134      ;=086h
wdArtPostageStamp  EQU  135      ;=087h
wdArtWeavingStrips  EQU  136      ;=088h
wdArtZigZag  EQU  137      ;=089h
wdArtCrossStitch  EQU  138      ;=08Ah
wdArtGems  EQU  139      ;=08Bh
wdArtCirclesRectangles  EQU  140      ;=08Ch
wdArtCornerTriangles  EQU  141      ;=08Dh
wdArtCreaturesInsects  EQU  142      ;=08Eh
wdArtZigZagStitch  EQU  143      ;=08Fh
wdArtCheckered  EQU  144      ;=090h
wdArtCheckedBarBlack  EQU  145      ;=091h
wdArtMarquee  EQU  146      ;=092h
wdArtBasicWhiteDots  EQU  147      ;=093h
wdArtBasicWideMidline  EQU  148      ;=094h
wdArtBasicWideOutline  EQU  149      ;=095h
wdArtBasicWideInline  EQU  150      ;=096h
wdArtBasicThinLines  EQU  151      ;=097h
wdArtBasicWhiteDashes  EQU  152      ;=098h
wdArtBasicWhiteSquares  EQU  153      ;=099h
wdArtBasicBlackSquares  EQU  154      ;=09Ah
wdArtBasicBlackDashes  EQU  155      ;=09Bh
wdArtBasicBlackDots  EQU  156      ;=09Ch
wdArtStarsTop  EQU  157      ;=09Dh
wdArtCertificateBanner  EQU  158      ;=09Eh
wdArtHandmade1  EQU  159      ;=09Fh
wdArtHandmade2  EQU  160      ;=0A0h
wdArtTornPaper  EQU  161      ;=0A1h
wdArtTornPaperBlack  EQU  162      ;=0A2h
wdArtCouponCutoutDashes  EQU  163      ;=0A3h
wdArtCouponCutoutDots  EQU  164      ;=0A4h

;--- WdBorderDistanceFrom, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBorderDistanceFrom typedef SDWORD
wdBorderDistanceFromText  EQU  0
wdBorderDistanceFromPageEdge  EQU  1

;--- WdReplace, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdReplace typedef SDWORD
wdReplaceNone  EQU  0
wdReplaceOne  EQU  1
wdReplaceAll  EQU  2

;--- WdFontBias, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFontBias typedef SDWORD
wdFontBiasDontCare  EQU  255      ;=0FFh
wdFontBiasDefault  EQU  0
wdFontBiasFareast  EQU  1

;--- WdBrowserLevel, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdBrowserLevel typedef SDWORD
wdBrowserLevelV4  EQU  0
wdBrowserLevelMicrosoftInternetExplorer5  EQU  1

;--- WdEnclosureType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdEnclosureType typedef SDWORD
wdEnclosureCircle  EQU  0
wdEnclosureSquare  EQU  1
wdEnclosureTriangle  EQU  2
wdEnclosureDiamond  EQU  3

;--- WdEncloseStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdEncloseStyle typedef SDWORD
wdEncloseStyleNone  EQU  0
wdEncloseStyleSmall  EQU  1
wdEncloseStyleLarge  EQU  2

;--- WdHighAnsiText, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHighAnsiText typedef SDWORD
wdHighAnsiIsFarEast  EQU  0
wdHighAnsiIsHighAnsi  EQU  1
wdAutoDetectHighAnsiFarEast  EQU  2

;--- WdLayoutMode, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdLayoutMode typedef SDWORD
wdLayoutModeDefault  EQU  0
wdLayoutModeGrid  EQU  1
wdLayoutModeLineGrid  EQU  2
wdLayoutModeGenko  EQU  3

;--- WdDocumentMedium, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDocumentMedium typedef SDWORD
wdEmailMessage  EQU  0
wdDocument  EQU  1
wdWebPage  EQU  2

;--- WdMailerPriority, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMailerPriority typedef SDWORD
wdPriorityNormal  EQU  1
wdPriorityLow  EQU  2
wdPriorityHigh  EQU  3

;--- WdDocumentViewDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDocumentViewDirection typedef SDWORD
wdDocumentViewRtl  EQU  0
wdDocumentViewLtr  EQU  1

;--- WdArabicNumeral, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdArabicNumeral typedef SDWORD
wdNumeralArabic  EQU  0
wdNumeralHindi  EQU  1
wdNumeralContext  EQU  2
wdNumeralSystem  EQU  3

;--- WdMonthNames, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdMonthNames typedef SDWORD
wdMonthNamesArabic  EQU  0
wdMonthNamesEnglish  EQU  1
wdMonthNamesFrench  EQU  2

;--- WdCursorMovement, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCursorMovement typedef SDWORD
wdCursorMovementLogical  EQU  0
wdCursorMovementVisual  EQU  1

;--- WdVisualSelection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdVisualSelection typedef SDWORD
wdVisualSelectionBlock  EQU  0
wdVisualSelectionContinuous  EQU  1

;--- WdTableDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTableDirection typedef SDWORD
wdTableDirectionRtl  EQU  0
wdTableDirectionLtr  EQU  1

;--- WdFlowDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFlowDirection typedef SDWORD
wdFlowLtr  EQU  0
wdFlowRtl  EQU  1

;--- WdDiacriticColor, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDiacriticColor typedef SDWORD
wdDiacriticColorBidi  EQU  0
wdDiacriticColorLatin  EQU  1

;--- WdGutterStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdGutterStyle typedef SDWORD
wdGutterPosLeft  EQU  0
wdGutterPosTop  EQU  1
wdGutterPosRight  EQU  2

;--- WdGutterStyleOld, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdGutterStyleOld typedef SDWORD
wdGutterStyleLatin  EQU  -10      ;=0FFFFFFF6h
wdGutterStyleBidi  EQU  2

;--- WdSectionDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdSectionDirection typedef SDWORD
wdSectionDirectionRtl  EQU  0
wdSectionDirectionLtr  EQU  1

;--- WdDateLanguage, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDateLanguage typedef SDWORD
wdDateLanguageBidi  EQU  10
wdDateLanguageLatin  EQU  1033      ;=0409h

;--- WdCalendarTypeBi, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCalendarTypeBi typedef SDWORD
wdCalendarTypeBidi  EQU  99      ;=063h
wdCalendarTypeGregorian  EQU  100      ;=064h

;--- WdCalendarType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCalendarType typedef SDWORD
wdCalendarWestern  EQU  0
wdCalendarArabic  EQU  1
wdCalendarHebrew  EQU  2
wdCalendarChina  EQU  3
wdCalendarJapan  EQU  4
wdCalendarThai  EQU  5
wdCalendarKorean  EQU  6

;--- WdReadingOrder, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdReadingOrder typedef SDWORD
wdReadingOrderRtl  EQU  0
wdReadingOrderLtr  EQU  1

;--- WdHebSpellStart, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHebSpellStart typedef SDWORD
wdFullScript  EQU  0
wdPartialScript  EQU  1
wdMixedScript  EQU  2
wdMixedAuthorizedScript  EQU  3

;--- WdAraSpeller, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdAraSpeller typedef SDWORD
wdNone  EQU  0
wdInitialAlef  EQU  1
wdFinalYaa  EQU  2
wdBoth  EQU  3

;--- WdColor, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdColor typedef SDWORD
wdColorAutomatic  EQU  -16777216      ;=0FF000000h
wdColorBlack  EQU  0
wdColorBlue  EQU  16711680      ;=0FF0000h
wdColorTurquoise  EQU  16776960      ;=0FFFF00h
wdColorBrightGreen  EQU  65280      ;=0FF00h
wdColorPink  EQU  16711935      ;=0FF00FFh
wdColorRed  EQU  255      ;=0FFh
wdColorYellow  EQU  65535      ;=0FFFFh
wdColorWhite  EQU  16777215      ;=0FFFFFFh
wdColorDarkBlue  EQU  8388608      ;=0800000h
wdColorTeal  EQU  8421376      ;=0808000h
wdColorGreen  EQU  32768      ;=08000h
wdColorViolet  EQU  8388736      ;=0800080h
wdColorDarkRed  EQU  128      ;=080h
wdColorDarkYellow  EQU  32896      ;=08080h
wdColorBrown  EQU  13209      ;=03399h
wdColorOliveGreen  EQU  13107      ;=03333h
wdColorDarkGreen  EQU  13056      ;=03300h
wdColorDarkTeal  EQU  6697728      ;=0663300h
wdColorIndigo  EQU  10040115      ;=0993333h
wdColorOrange  EQU  26367      ;=066FFh
wdColorBlueGray  EQU  10053222      ;=0996666h
wdColorLightOrange  EQU  39423      ;=099FFh
wdColorLime  EQU  52377      ;=0CC99h
wdColorSeaGreen  EQU  6723891      ;=0669933h
wdColorAqua  EQU  13421619      ;=0CCCC33h
wdColorLightBlue  EQU  16737843      ;=0FF6633h
wdColorGold  EQU  52479      ;=0CCFFh
wdColorSkyBlue  EQU  16763904      ;=0FFCC00h
wdColorPlum  EQU  6697881      ;=0663399h
wdColorRose  EQU  13408767      ;=0CC99FFh
wdColorTan  EQU  10079487      ;=099CCFFh
wdColorLightYellow  EQU  10092543      ;=099FFFFh
wdColorLightGreen  EQU  13434828      ;=0CCFFCCh
wdColorLightTurquoise  EQU  16777164      ;=0FFFFCCh
wdColorPaleBlue  EQU  16764057      ;=0FFCC99h
wdColorLavender  EQU  16751052      ;=0FF99CCh
wdColorGray05  EQU  15987699      ;=0F3F3F3h
wdColorGray10  EQU  15132390      ;=0E6E6E6h
wdColorGray125  EQU  14737632      ;=0E0E0E0h
wdColorGray15  EQU  14277081      ;=0D9D9D9h
wdColorGray20  EQU  13421772      ;=0CCCCCCh
wdColorGray25  EQU  12632256      ;=0C0C0C0h
wdColorGray30  EQU  11776947      ;=0B3B3B3h
wdColorGray35  EQU  10921638      ;=0A6A6A6h
wdColorGray375  EQU  10526880      ;=0A0A0A0h
wdColorGray40  EQU  10066329      ;=0999999h
wdColorGray45  EQU  9211020      ;=08C8C8Ch
wdColorGray50  EQU  8421504      ;=0808080h
wdColorGray55  EQU  7566195      ;=0737373h
wdColorGray60  EQU  6710886      ;=0666666h
wdColorGray625  EQU  6316128      ;=0606060h
wdColorGray65  EQU  5855577      ;=0595959h
wdColorGray70  EQU  5000268      ;=04C4C4Ch
wdColorGray75  EQU  4210752      ;=0404040h
wdColorGray80  EQU  3355443      ;=0333333h
wdColorGray85  EQU  2500134      ;=0262626h
wdColorGray875  EQU  2105376      ;=0202020h
wdColorGray90  EQU  1644825      ;=0191919h
wdColorGray95  EQU  789516      ;=0C0C0Ch

;--- WdShapePosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdShapePosition typedef SDWORD
wdShapeTop  EQU  -999999      ;=0FFF0BDC1h
wdShapeLeft  EQU  -999998      ;=0FFF0BDC2h
wdShapeBottom  EQU  -999997      ;=0FFF0BDC3h
wdShapeRight  EQU  -999996      ;=0FFF0BDC4h
wdShapeCenter  EQU  -999995      ;=0FFF0BDC5h
wdShapeInside  EQU  -999994      ;=0FFF0BDC6h
wdShapeOutside  EQU  -999993      ;=0FFF0BDC7h

;--- WdTablePosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTablePosition typedef SDWORD
wdTableTop  EQU  -999999      ;=0FFF0BDC1h
wdTableLeft  EQU  -999998      ;=0FFF0BDC2h
wdTableBottom  EQU  -999997      ;=0FFF0BDC3h
wdTableRight  EQU  -999996      ;=0FFF0BDC4h
wdTableCenter  EQU  -999995      ;=0FFF0BDC5h
wdTableInside  EQU  -999994      ;=0FFF0BDC6h
wdTableOutside  EQU  -999993      ;=0FFF0BDC7h

;--- WdDefaultListBehavior, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDefaultListBehavior typedef SDWORD
wdWord8ListBehavior  EQU  0
wdWord9ListBehavior  EQU  1

;--- WdDefaultTableBehavior, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdDefaultTableBehavior typedef SDWORD
wdWord8TableBehavior  EQU  0
wdWord9TableBehavior  EQU  1

;--- WdAutoFitBehavior, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdAutoFitBehavior typedef SDWORD
wdAutoFitFixed  EQU  0
wdAutoFitContent  EQU  1
wdAutoFitWindow  EQU  2

;--- WdPreferredWidthType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPreferredWidthType typedef SDWORD
wdPreferredWidthAuto  EQU  1
wdPreferredWidthPercent  EQU  2
wdPreferredWidthPoints  EQU  3

;--- WdFarEastLineBreakLanguageID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFarEastLineBreakLanguageID typedef SDWORD
wdLineBreakJapanese  EQU  1041      ;=0411h
wdLineBreakKorean  EQU  1042      ;=0412h
wdLineBreakSimplifiedChinese  EQU  2052      ;=0804h
wdLineBreakTraditionalChinese  EQU  1028      ;=0404h

;--- WdViewTypeOld, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdViewTypeOld typedef SDWORD
wdPageView  EQU  3
wdOnlineView  EQU  6

;--- WdFramesetType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFramesetType typedef SDWORD
wdFramesetTypeFrameset  EQU  0
wdFramesetTypeFrame  EQU  1

;--- WdFramesetSizeType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFramesetSizeType typedef SDWORD
wdFramesetSizeTypePercent  EQU  0
wdFramesetSizeTypeFixed  EQU  1
wdFramesetSizeTypeRelative  EQU  2

;--- WdFramesetNewFrameLocation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdFramesetNewFrameLocation typedef SDWORD
wdFramesetNewFrameAbove  EQU  0
wdFramesetNewFrameBelow  EQU  1
wdFramesetNewFrameRight  EQU  2
wdFramesetNewFrameLeft  EQU  3

;--- WdScrollbarType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdScrollbarType typedef SDWORD
wdScrollbarTypeAuto  EQU  0
wdScrollbarTypeYes  EQU  1
wdScrollbarTypeNo  EQU  2

;--- WdTwoLinesInOneType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTwoLinesInOneType typedef SDWORD
wdTwoLinesInOneNone  EQU  0
wdTwoLinesInOneNoBrackets  EQU  1
wdTwoLinesInOneParentheses  EQU  2
wdTwoLinesInOneSquareBrackets  EQU  3
wdTwoLinesInOneAngleBrackets  EQU  4
wdTwoLinesInOneCurlyBrackets  EQU  5

;--- WdHorizontalInVerticalType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHorizontalInVerticalType typedef SDWORD
wdHorizontalInVerticalNone  EQU  0
wdHorizontalInVerticalFitInLine  EQU  1
wdHorizontalInVerticalResizeLine  EQU  2

;--- WdHorizontalLineAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHorizontalLineAlignment typedef SDWORD
wdHorizontalLineAlignLeft  EQU  0
wdHorizontalLineAlignCenter  EQU  1
wdHorizontalLineAlignRight  EQU  2

;--- WdHorizontalLineWidthType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdHorizontalLineWidthType typedef SDWORD
wdHorizontalLinePercentWidth  EQU  -1
wdHorizontalLineFixedWidth  EQU  -2      ;=0FFFFFFFEh

;--- WdPhoneticGuideAlignmentType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdPhoneticGuideAlignmentType typedef SDWORD
wdPhoneticGuideAlignmentCenter  EQU  0
wdPhoneticGuideAlignmentZeroOneZero  EQU  1
wdPhoneticGuideAlignmentOneTwoOne  EQU  2
wdPhoneticGuideAlignmentLeft  EQU  3
wdPhoneticGuideAlignmentRight  EQU  4

;--- WdNewDocumentType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdNewDocumentType typedef SDWORD
wdNewBlankDocument  EQU  0
wdNewWebPage  EQU  1
wdNewEmailMessage  EQU  2
wdNewFrameset  EQU  3

;--- WdKana, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdKana typedef SDWORD
wdKanaKatakana  EQU  8
wdKanaHiragana  EQU  9

;--- WdCharacterWidth, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdCharacterWidth typedef SDWORD
wdWidthHalfWidth  EQU  6
wdWidthFullWidth  EQU  7

;--- WdNumberStyleWordBasicBiDi, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdNumberStyleWordBasicBiDi typedef SDWORD
wdListNumberStyleBidi1  EQU  49      ;=031h
wdListNumberStyleBidi2  EQU  50      ;=032h
wdCaptionNumberStyleBidiLetter1  EQU  49      ;=031h
wdCaptionNumberStyleBidiLetter2  EQU  50      ;=032h
wdNoteNumberStyleBidiLetter1  EQU  49      ;=031h
wdNoteNumberStyleBidiLetter2  EQU  50      ;=032h
wdPageNumberStyleBidiLetter1  EQU  49      ;=031h
wdPageNumberStyleBidiLetter2  EQU  50      ;=032h

;--- WdTCSCConverterDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}

WdTCSCConverterDirection typedef SDWORD
wdTCSCConverterDirectionSCTC  EQU  0
wdTCSCConverterDirectionTCSC  EQU  1
wdTCSCConverterDirectionAuto  EQU  2

;--- FirstLetterExceptions, Type=INTERFACE, GUID={00020946-0000-0000-C000-000000000046}
;
;ifndef FirstLetterExceptionsVtbl
;COM_INTERFACE_BEG FirstLetterExceptions, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr FirstLetterException
;  COM_MTD_STD  Add_  , :BSTR,:ptr ptr FirstLetterException
;COM_INTERFACE_END
;endif
;
;sIID_FirstLetterExceptions textequ <IID {000020946h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FirstLetterException, Type=INTERFACE, GUID={00020945-0000-0000-C000-000000000046}
;
;ifndef FirstLetterExceptionVtbl
;COM_INTERFACE_BEG FirstLetterException, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_FirstLetterException textequ <IID {000020945h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TwoInitialCapsExceptions, Type=INTERFACE, GUID={00020944-0000-0000-C000-000000000046}
;
;ifndef TwoInitialCapsExceptionsVtbl
;COM_INTERFACE_BEG TwoInitialCapsExceptions, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr TwoInitialCapsException
;  COM_MTD_STD  Add_  , :BSTR,:ptr ptr TwoInitialCapsException
;COM_INTERFACE_END
;endif
;
;sIID_TwoInitialCapsExceptions textequ <IID {000020944h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TwoInitialCapsException, Type=INTERFACE, GUID={00020943-0000-0000-C000-000000000046}
;
;ifndef TwoInitialCapsExceptionVtbl
;COM_INTERFACE_BEG TwoInitialCapsException, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_TwoInitialCapsException textequ <IID {000020943h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Footnotes, Type=INTERFACE, GUID={00020942-0000-0000-C000-000000000046}
;
;ifndef FootnotesVtbl
;COM_INTERFACE_BEG Footnotes, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Location  , :ptr WdFootnoteLocation
;  COM_MTD_STD  put_Location  , :WdFootnoteLocation
;  COM_MTD_STD  get_NumberStyle  , :ptr WdNoteNumberStyle
;  COM_MTD_STD  put_NumberStyle  , :WdNoteNumberStyle
;  COM_MTD_STD  get_StartingNumber  , :ptr SDWORD
;  COM_MTD_STD  put_StartingNumber  , :SDWORD
;  COM_MTD_STD  get_NumberingRule  , :ptr WdNumberingRule
;  COM_MTD_STD  put_NumberingRule  , :WdNumberingRule
;  COM_MTD_STD  get_Separator  , :ptr ptr Range
;  COM_MTD_STD  get_ContinuationSeparator  , :ptr ptr Range
;  COM_MTD_STD  get_ContinuationNotice  , :ptr ptr Range
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Footnote
;  COM_MTD_STD  Add_  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr ptr Footnote
;  COM_MTD_STD  Convert  
;  COM_MTD_STD  SwapWithEndnotes  
;  COM_MTD_STD  ResetSeparator  
;  COM_MTD_STD  ResetContinuationSeparator  
;  COM_MTD_STD  ResetContinuationNotice  
;COM_INTERFACE_END
;endif
;
;sIID_Footnotes textequ <IID {000020942h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Endnotes, Type=INTERFACE, GUID={00020941-0000-0000-C000-000000000046}
;
;ifndef EndnotesVtbl
;COM_INTERFACE_BEG Endnotes, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Location  , :ptr WdEndnoteLocation
;  COM_MTD_STD  put_Location  , :WdEndnoteLocation
;  COM_MTD_STD  get_NumberStyle  , :ptr WdNoteNumberStyle
;  COM_MTD_STD  put_NumberStyle  , :WdNoteNumberStyle
;  COM_MTD_STD  get_StartingNumber  , :ptr SDWORD
;  COM_MTD_STD  put_StartingNumber  , :SDWORD
;  COM_MTD_STD  get_NumberingRule  , :ptr WdNumberingRule
;  COM_MTD_STD  put_NumberingRule  , :WdNumberingRule
;  COM_MTD_STD  get_Separator  , :ptr ptr Range
;  COM_MTD_STD  get_ContinuationSeparator  , :ptr ptr Range
;  COM_MTD_STD  get_ContinuationNotice  , :ptr ptr Range
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Endnote
;  COM_MTD_STD  Add_  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr ptr Endnote
;  COM_MTD_STD  Convert  
;  COM_MTD_STD  SwapWithFootnotes  
;  COM_MTD_STD  ResetSeparator  
;  COM_MTD_STD  ResetContinuationSeparator  
;  COM_MTD_STD  ResetContinuationNotice  
;COM_INTERFACE_END
;endif
;
;sIID_Endnotes textequ <IID {000020941h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Comments, Type=INTERFACE, GUID={00020940-0000-0000-C000-000000000046}
;
;ifndef CommentsVtbl
;COM_INTERFACE_BEG Comments, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_ShowBy  , :ptr BSTR
;  COM_MTD_STD  put_ShowBy  , :BSTR
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Comment_
;  COM_MTD_STD  Add_  , :ptr Range,:ptr VARIANT,:ptr ptr Comment_
;COM_INTERFACE_END
;endif
;
;sIID_Comments textequ <IID {000020940h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Footnote, Type=INTERFACE, GUID={0002093F-0000-0000-C000-000000000046}
;
;ifndef FootnoteVtbl
;COM_INTERFACE_BEG Footnote, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_Reference  , :ptr ptr Range
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_Footnote textequ <IID {00002093Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Endnote, Type=INTERFACE, GUID={0002093E-0000-0000-C000-000000000046}
;
;ifndef EndnoteVtbl
;COM_INTERFACE_BEG Endnote, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_Reference  , :ptr ptr Range
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_Endnote textequ <IID {00002093Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Comment, Type=INTERFACE, GUID={0002093D-0000-0000-C000-000000000046}
;
;ifndef Comment_Vtbl
;COM_INTERFACE_BEG Comment_, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_Reference  , :ptr ptr Range
;  COM_MTD_STD  get_Scope  , :ptr ptr Range
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Author  , :ptr BSTR
;  COM_MTD_STD  put_Author  , :BSTR
;  COM_MTD_STD  get_Initial  , :ptr BSTR
;  COM_MTD_STD  put_Initial  , :BSTR
;  COM_MTD_STD  get_ShowTip  , :ptr BOOL
;  COM_MTD_STD  put_ShowTip  , :BOOL
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_Comment_ textequ <IID {00002093Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Borders, Type=INTERFACE, GUID={0002093C-0000-0000-C000-000000000046}
;
;ifndef BordersVtbl
;COM_INTERFACE_BEG Borders, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Enable  , :ptr SDWORD
;  COM_MTD_STD  put_Enable  , :SDWORD
;  COM_MTD_STD  get_DistanceFromTop  , :ptr SDWORD
;  COM_MTD_STD  put_DistanceFromTop  , :SDWORD
;  COM_MTD_STD  get_Shadow  , :ptr BOOL
;  COM_MTD_STD  put_Shadow  , :BOOL
;  COM_MTD_STD  get_InsideLineStyle  , :ptr WdLineStyle
;  COM_MTD_STD  put_InsideLineStyle  , :WdLineStyle
;  COM_MTD_STD  get_OutsideLineStyle  , :ptr WdLineStyle
;  COM_MTD_STD  put_OutsideLineStyle  , :WdLineStyle
;  COM_MTD_STD  get_InsideLineWidth  , :ptr WdLineWidth
;  COM_MTD_STD  put_InsideLineWidth  , :WdLineWidth
;  COM_MTD_STD  get_OutsideLineWidth  , :ptr WdLineWidth
;  COM_MTD_STD  put_OutsideLineWidth  , :WdLineWidth
;  COM_MTD_STD  get_InsideColorIndex  , :ptr WdColorIndex
;  COM_MTD_STD  put_InsideColorIndex  , :WdColorIndex
;  COM_MTD_STD  get_OutsideColorIndex  , :ptr WdColorIndex
;  COM_MTD_STD  put_OutsideColorIndex  , :WdColorIndex
;  COM_MTD_STD  get_DistanceFromLeft  , :ptr SDWORD
;  COM_MTD_STD  put_DistanceFromLeft  , :SDWORD
;  COM_MTD_STD  get_DistanceFromBottom  , :ptr SDWORD
;  COM_MTD_STD  put_DistanceFromBottom  , :SDWORD
;  COM_MTD_STD  get_DistanceFromRight  , :ptr SDWORD
;  COM_MTD_STD  put_DistanceFromRight  , :SDWORD
;  COM_MTD_STD  get_AlwaysInFront  , :ptr BOOL
;  COM_MTD_STD  put_AlwaysInFront  , :BOOL
;  COM_MTD_STD  get_SurroundHeader  , :ptr BOOL
;  COM_MTD_STD  put_SurroundHeader  , :BOOL
;  COM_MTD_STD  get_SurroundFooter  , :ptr BOOL
;  COM_MTD_STD  put_SurroundFooter  , :BOOL
;  COM_MTD_STD  get_JoinBorders  , :ptr BOOL
;  COM_MTD_STD  put_JoinBorders  , :BOOL
;  COM_MTD_STD  get_HasHorizontal  , :ptr BOOL
;  COM_MTD_STD  get_HasVertical  , :ptr BOOL
;  COM_MTD_STD  get_DistanceFrom  , :ptr WdBorderDistanceFrom
;  COM_MTD_STD  put_DistanceFrom  , :WdBorderDistanceFrom
;  COM_MTD_STD  get_EnableFirstPageInSection  , :ptr BOOL
;  COM_MTD_STD  put_EnableFirstPageInSection  , :BOOL
;  COM_MTD_STD  get_EnableOtherPagesInSection  , :ptr BOOL
;  COM_MTD_STD  put_EnableOtherPagesInSection  , :BOOL
;  COM_MTD_STD  Item  , :WdBorderType,:ptr ptr Border
;  COM_MTD_STD  ApplyPageBordersToAllSections  
;  COM_MTD_STD  get_InsideColor  , :ptr WdColor
;  COM_MTD_STD  put_InsideColor  , :WdColor
;  COM_MTD_STD  get_OutsideColor  , :ptr WdColor
;  COM_MTD_STD  put_OutsideColor  , :WdColor
;COM_INTERFACE_END
;endif
;
;sIID_Borders textequ <IID {00002093Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Border, Type=INTERFACE, GUID={0002093B-0000-0000-C000-000000000046}
;
;ifndef BorderVtbl
;COM_INTERFACE_BEG Border, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Visible  , :ptr BOOL
;  COM_MTD_STD  put_Visible  , :BOOL
;  COM_MTD_STD  get_ColorIndex  , :ptr WdColorIndex
;  COM_MTD_STD  put_ColorIndex  , :WdColorIndex
;  COM_MTD_STD  get_Inside  , :ptr BOOL
;  COM_MTD_STD  get_LineStyle  , :ptr WdLineStyle
;  COM_MTD_STD  put_LineStyle  , :WdLineStyle
;  COM_MTD_STD  get_LineWidth  , :ptr WdLineWidth
;  COM_MTD_STD  put_LineWidth  , :WdLineWidth
;  COM_MTD_STD  get_ArtStyle  , :ptr WdPageBorderArt
;  COM_MTD_STD  put_ArtStyle  , :WdPageBorderArt
;  COM_MTD_STD  get_ArtWidth  , :ptr SDWORD
;  COM_MTD_STD  put_ArtWidth  , :SDWORD
;  COM_MTD_STD  get_Color  , :ptr WdColor
;  COM_MTD_STD  put_Color  , :WdColor
;COM_INTERFACE_END
;endif
;
;sIID_Border textequ <IID {00002093Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Shading, Type=INTERFACE, GUID={0002093A-0000-0000-C000-000000000046}
;
;ifndef ShadingVtbl
;COM_INTERFACE_BEG Shading, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_ForegroundPatternColorIndex  , :ptr WdColorIndex
;  COM_MTD_STD  put_ForegroundPatternColorIndex  , :WdColorIndex
;  COM_MTD_STD  get_BackgroundPatternColorIndex  , :ptr WdColorIndex
;  COM_MTD_STD  put_BackgroundPatternColorIndex  , :WdColorIndex
;  COM_MTD_STD  get_Texture  , :ptr WdTextureIndex
;  COM_MTD_STD  put_Texture  , :WdTextureIndex
;  COM_MTD_STD  get_ForegroundPatternColor  , :ptr WdColor
;  COM_MTD_STD  put_ForegroundPatternColor  , :WdColor
;  COM_MTD_STD  get_BackgroundPatternColor  , :ptr WdColor
;  COM_MTD_STD  put_BackgroundPatternColor  , :WdColor
;COM_INTERFACE_END
;endif
;
;sIID_Shading textequ <IID {00002093Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TextRetrievalMode, Type=INTERFACE, GUID={00020939-0000-0000-C000-000000000046}
;
;ifndef TextRetrievalModeVtbl
;COM_INTERFACE_BEG TextRetrievalMode, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_ViewType  , :ptr WdViewType
;  COM_MTD_STD  put_ViewType  , :WdViewType
;  COM_MTD_STD  get_Duplicate  , :ptr ptr TextRetrievalMode
;  COM_MTD_STD  get_IncludeHiddenText  , :ptr BOOL
;  COM_MTD_STD  put_IncludeHiddenText  , :BOOL
;  COM_MTD_STD  get_IncludeFieldCodes  , :ptr BOOL
;  COM_MTD_STD  put_IncludeFieldCodes  , :BOOL
;COM_INTERFACE_END
;endif
;
;sIID_TextRetrievalMode textequ <IID {000020939h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- AutoTextEntries, Type=INTERFACE, GUID={00020937-0000-0000-C000-000000000046}
;
;ifndef AutoTextEntriesVtbl
;COM_INTERFACE_BEG AutoTextEntries, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr AutoTextEntry
;  COM_MTD_STD  Add_  , :BSTR,:ptr Range,:ptr ptr AutoTextEntry
;  COM_MTD_STD  AppendToSpike  , :ptr Range,:ptr ptr AutoTextEntry
;COM_INTERFACE_END
;endif
;
;sIID_AutoTextEntries textequ <IID {000020937h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- AutoTextEntry, Type=INTERFACE, GUID={00020936-0000-0000-C000-000000000046}
;
;ifndef AutoTextEntryVtbl
;COM_INTERFACE_BEG AutoTextEntry, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  get_StyleName  , :ptr BSTR
;  COM_MTD_STD  get_Value  , :ptr BSTR
;  COM_MTD_STD  put_Value  , :BSTR
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Insert  , :ptr Range,:ptr VARIANT,:ptr ptr Range
;COM_INTERFACE_END
;endif
;
;sIID_AutoTextEntry textequ <IID {000020936h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- System, Type=INTERFACE, GUID={00020935-0000-0000-C000-000000000046}
;
;ifndef SystemVtbl
;COM_INTERFACE_BEG System, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_OperatingSystem  , :ptr BSTR
;  COM_MTD_STD  get_ProcessorType  , :ptr BSTR
;  COM_MTD_STD  get_Version  , :ptr BSTR
;  COM_MTD_STD  get_FreeDiskSpace  , :ptr SDWORD
;  COM_MTD_STD  get_Country  , :ptr WdCountry
;  COM_MTD_STD  get_LanguageDesignation  , :ptr BSTR
;  COM_MTD_STD  get_HorizontalResolution  , :ptr SDWORD
;  COM_MTD_STD  get_VerticalResolution  , :ptr SDWORD
;  COM_MTD_STD  get_ProfileString  , :BSTR,:BSTR,:ptr BSTR
;  COM_MTD_STD  put_ProfileString  , :BSTR,:BSTR,:BSTR
;  COM_MTD_STD  get_PrivateProfileString  , :BSTR,:BSTR,:BSTR,:ptr BSTR
;  COM_MTD_STD  put_PrivateProfileString  , :BSTR,:BSTR,:BSTR,:BSTR
;  COM_MTD_STD  get_MathCoprocessorInstalled  , :ptr BOOL
;  COM_MTD_STD  get_ComputerType  , :ptr BSTR
;  COM_MTD_STD  get_MacintoshName  , :ptr BSTR
;  COM_MTD_STD  get_QuickDrawInstalled  , :ptr BOOL
;  COM_MTD_STD  get_Cursor  , :ptr WdCursorType
;  COM_MTD_STD  put_Cursor  , :WdCursorType
;  COM_MTD_STD  MSInfo  
;  COM_MTD_STD  Connect  , :BSTR,:ptr VARIANT,:ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_System textequ <IID {000020935h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- OLEFormat, Type=INTERFACE, GUID={00020933-0000-0000-C000-000000000046}
;
;ifndef OLEFormatVtbl
;COM_INTERFACE_BEG OLEFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_ClassType  , :ptr BSTR
;  COM_MTD_STD  put_ClassType  , :BSTR
;  COM_MTD_STD  get_DisplayAsIcon  , :ptr BOOL
;  COM_MTD_STD  put_DisplayAsIcon  , :BOOL
;  COM_MTD_STD  get_IconName  , :ptr BSTR
;  COM_MTD_STD  put_IconName  , :BSTR
;  COM_MTD_STD  get_IconPath  , :ptr BSTR
;  COM_MTD_STD  get_IconIndex  , :ptr SDWORD
;  COM_MTD_STD  put_IconIndex  , :SDWORD
;  COM_MTD_STD  get_IconLabel  , :ptr BSTR
;  COM_MTD_STD  put_IconLabel  , :BSTR
;  COM_MTD_STD  get_Label  , :ptr BSTR
;  COM_MTD_STD  get_Object  , :ptr LPDISPATCH
;  COM_MTD_STD  get_ProgID  , :ptr BSTR
;  COM_MTD_STD  Activate  
;  COM_MTD_STD  Edit  
;  COM_MTD_STD  Open  
;  COM_MTD_STD  DoVerb  , :ptr VARIANT
;  COM_MTD_STD  ConvertTo  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  ActivateAs  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID_OLEFormat textequ <IID {000020933h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- LinkFormat, Type=INTERFACE, GUID={00020931-0000-0000-C000-000000000046}
;
;ifndef LinkFormatVtbl
;COM_INTERFACE_BEG LinkFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_AutoUpdate  , :ptr BOOL
;  COM_MTD_STD  put_AutoUpdate  , :BOOL
;  COM_MTD_STD  get_SourceName  , :ptr BSTR
;  COM_MTD_STD  get_SourcePath  , :ptr BSTR
;  COM_MTD_STD  get_Locked  , :ptr BOOL
;  COM_MTD_STD  put_Locked  , :BOOL
;  COM_MTD_STD  get_Type  , :ptr WdLinkType
;  COM_MTD_STD  get_SourceFullName  , :ptr BSTR
;  COM_MTD_STD  put_SourceFullName  , :BSTR
;  COM_MTD_STD  get_SavePictureWithDocument  , :ptr BOOL
;  COM_MTD_STD  put_SavePictureWithDocument  , :BOOL
;  COM_MTD_STD  BreakLink  
;  COM_MTD_STD  Update  
;COM_INTERFACE_END
;endif
;
;sIID_LinkFormat textequ <IID {000020931h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _OLEControl, Type=INTERFACE, GUID={000209A4-0000-0000-C000-000000000046}
;
;ifndef _OLEControlVtbl
;COM_INTERFACE_BEG _OLEControl, IDispatch
;  COM_MTD_STD  get_Left  , :ptr REAL4
;  COM_MTD_STD  put_Left  , :REAL4
;  COM_MTD_STD  get_Top  , :ptr REAL4
;  COM_MTD_STD  put_Top  , :REAL4
;  COM_MTD_STD  get_Height  , :ptr REAL4
;  COM_MTD_STD  put_Height  , :REAL4
;  COM_MTD_STD  get_Width  , :ptr REAL4
;  COM_MTD_STD  put_Width  , :REAL4
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  get_Automation  , :ptr LPDISPATCH
;  COM_MTD_STD  Select  
;  COM_MTD_STD  Copy  
;  COM_MTD_STD  Cut  
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Activate  
;  COM_MTD_STD  get_AltHTML  , :ptr BSTR
;  COM_MTD_STD  put_AltHTML  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID__OLEControl textequ <IID {0000209A4h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Fields, Type=INTERFACE, GUID={00020930-0000-0000-C000-000000000046}
;
;ifndef FieldsVtbl
;COM_INTERFACE_BEG Fields, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Locked  , :ptr SDWORD
;  COM_MTD_STD  put_Locked  , :SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Field
;  COM_MTD_STD  ToggleShowCodes  
;  COM_MTD_STD  Update  , :ptr SDWORD
;  COM_MTD_STD  Unlink  
;  COM_MTD_STD  UpdateSource  
;  COM_MTD_STD  Add_  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Field
;COM_INTERFACE_END
;endif
;
;sIID_Fields textequ <IID {000020930h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Field, Type=INTERFACE, GUID={0002092F-0000-0000-C000-000000000046}
;
;ifndef FieldVtbl
;COM_INTERFACE_BEG Field, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Code  , :ptr ptr Range
;  COM_MTD_STD  put_Code  , :ptr Range
;  COM_MTD_STD  get_Type  , :ptr WdFieldType
;  COM_MTD_STD  get_Locked  , :ptr BOOL
;  COM_MTD_STD  put_Locked  , :BOOL
;  COM_MTD_STD  get_Kind  , :ptr WdFieldKind
;  COM_MTD_STD  get_Result  , :ptr ptr Range
;  COM_MTD_STD  put_Result  , :ptr Range
;  COM_MTD_STD  get_Data  , :ptr BSTR
;  COM_MTD_STD  put_Data  , :BSTR
;  COM_MTD_STD  get_Next  , :ptr ptr Field
;  COM_MTD_STD  get_Previous  , :ptr ptr Field
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_ShowCodes  , :ptr BOOL
;  COM_MTD_STD  put_ShowCodes  , :BOOL
;  COM_MTD_STD  get_LinkFormat  , :ptr ptr LinkFormat
;  COM_MTD_STD  get_OLEFormat  , :ptr ptr OLEFormat
;  COM_MTD_STD  get_InlineShape  , :ptr ptr InlineShape
;  COM_MTD_STD  Select  
;  COM_MTD_STD  Update  , :ptr BOOL
;  COM_MTD_STD  Unlink  
;  COM_MTD_STD  UpdateSource  
;  COM_MTD_STD  DoClick  
;  COM_MTD_STD  Copy  
;  COM_MTD_STD  Cut  
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_Field textequ <IID {00002092Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Browser, Type=INTERFACE, GUID={0002092E-0000-0000-C000-000000000046}
;
;ifndef BrowserVtbl
;COM_INTERFACE_BEG Browser, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Target  , :ptr WdBrowseTarget
;  COM_MTD_STD  put_Target  , :WdBrowseTarget
;  COM_MTD_STD  Next  
;  COM_MTD_STD  Previous  
;COM_INTERFACE_END
;endif
;
;sIID_Browser textequ <IID {00002092Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Styles, Type=INTERFACE, GUID={0002092D-0000-0000-C000-000000000046}
;
;ifndef StylesVtbl
;COM_INTERFACE_BEG Styles, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Style
;  COM_MTD_STD  Add_  , :BSTR,:ptr VARIANT,:ptr ptr Style
;COM_INTERFACE_END
;endif
;
;sIID_Styles textequ <IID {00002092Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Style, Type=INTERFACE, GUID={0002092C-0000-0000-C000-000000000046}
;
;ifndef StyleVtbl
;COM_INTERFACE_BEG Style, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_NameLocal  , :ptr BSTR
;  COM_MTD_STD  put_NameLocal  , :BSTR
;  COM_MTD_STD  get_BaseStyle  , :ptr VARIANT
;  COM_MTD_STD  put_BaseStyle  , :ptr VARIANT
;  COM_MTD_STD  get_Description  , :ptr BSTR
;  COM_MTD_STD  get_Type  , :ptr WdStyleType
;  COM_MTD_STD  get_BuiltIn  , :ptr BOOL
;  COM_MTD_STD  get_NextParagraphStyle  , :ptr VARIANT
;  COM_MTD_STD  put_NextParagraphStyle  , :ptr VARIANT
;  COM_MTD_STD  get_InUse  , :ptr BOOL
;  COM_MTD_STD  get_Shading  , :ptr ptr Shading
;  COM_MTD_STD  get_Borders  , :ptr ptr Borders
;  COM_MTD_STD  put_Borders  , :ptr Borders
;  COM_MTD_STD  get_ParagraphFormat  , :ptr ptr ParagraphFormat
;  COM_MTD_STD  put_ParagraphFormat  , :ptr ParagraphFormat
;  COM_MTD_STD  get_Font  , :ptr ptr Font
;  COM_MTD_STD  put_Font  , :ptr Font
;  COM_MTD_STD  get_Frame  , :ptr ptr Frame
;  COM_MTD_STD  get_LanguageID  , :ptr WdLanguageID
;  COM_MTD_STD  put_LanguageID  , :WdLanguageID
;  COM_MTD_STD  get_AutomaticallyUpdate  , :ptr BOOL
;  COM_MTD_STD  put_AutomaticallyUpdate  , :BOOL
;  COM_MTD_STD  get_ListTemplate  , :ptr ptr ListTemplate
;  COM_MTD_STD  get_ListLevelNumber  , :ptr SDWORD
;  COM_MTD_STD  get_LanguageIDFarEast  , :ptr WdLanguageID
;  COM_MTD_STD  put_LanguageIDFarEast  , :WdLanguageID
;  COM_MTD_STD  get_Hidden  , :ptr BOOL
;  COM_MTD_STD  put_Hidden  , :BOOL
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  LinkToListTemplate  , :ptr ListTemplate,:ptr VARIANT
;  COM_MTD_STD  get_NoProofing  , :ptr SDWORD
;  COM_MTD_STD  put_NoProofing  , :SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_Style textequ <IID {00002092Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Frames, Type=INTERFACE, GUID={0002092B-0000-0000-C000-000000000046}
;
;ifndef FramesVtbl
;COM_INTERFACE_BEG Frames, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Frame
;  COM_MTD_STD  Add_  , :ptr Range,:ptr ptr Frame
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_Frames textequ <IID {00002092Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Frame, Type=INTERFACE, GUID={0002092A-0000-0000-C000-000000000046}
;
;ifndef FrameVtbl
;COM_INTERFACE_BEG Frame, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_HeightRule  , :ptr WdFrameSizeRule
;  COM_MTD_STD  put_HeightRule  , :WdFrameSizeRule
;  COM_MTD_STD  get_WidthRule  , :ptr WdFrameSizeRule
;  COM_MTD_STD  put_WidthRule  , :WdFrameSizeRule
;  COM_MTD_STD  get_HorizontalDistanceFromText  , :ptr REAL4
;  COM_MTD_STD  put_HorizontalDistanceFromText  , :REAL4
;  COM_MTD_STD  get_Height  , :ptr REAL4
;  COM_MTD_STD  put_Height  , :REAL4
;  COM_MTD_STD  get_HorizontalPosition  , :ptr REAL4
;  COM_MTD_STD  put_HorizontalPosition  , :REAL4
;  COM_MTD_STD  get_LockAnchor  , :ptr BOOL
;  COM_MTD_STD  put_LockAnchor  , :BOOL
;  COM_MTD_STD  get_RelativeHorizontalPosition  , :ptr WdRelativeHorizontalPosition
;  COM_MTD_STD  put_RelativeHorizontalPosition  , :WdRelativeHorizontalPosition
;  COM_MTD_STD  get_RelativeVerticalPosition  , :ptr WdRelativeVerticalPosition
;  COM_MTD_STD  put_RelativeVerticalPosition  , :WdRelativeVerticalPosition
;  COM_MTD_STD  get_VerticalDistanceFromText  , :ptr REAL4
;  COM_MTD_STD  put_VerticalDistanceFromText  , :REAL4
;  COM_MTD_STD  get_VerticalPosition  , :ptr REAL4
;  COM_MTD_STD  put_VerticalPosition  , :REAL4
;  COM_MTD_STD  get_Width  , :ptr REAL4
;  COM_MTD_STD  put_Width  , :REAL4
;  COM_MTD_STD  get_TextWrap  , :ptr BOOL
;  COM_MTD_STD  put_TextWrap  , :BOOL
;  COM_MTD_STD  get_Shading  , :ptr ptr Shading
;  COM_MTD_STD  get_Borders  , :ptr ptr Borders
;  COM_MTD_STD  put_Borders  , :ptr Borders
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Select  
;  COM_MTD_STD  Copy  
;  COM_MTD_STD  Cut  
;COM_INTERFACE_END
;endif
;
;sIID_Frame textequ <IID {00002092Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FormFields, Type=INTERFACE, GUID={00020929-0000-0000-C000-000000000046}
;
;ifndef FormFieldsVtbl
;COM_INTERFACE_BEG FormFields, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Shaded  , :ptr BOOL
;  COM_MTD_STD  put_Shaded  , :BOOL
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr FormField
;  COM_MTD_STD  Add_  , :ptr Range,:WdFieldType,:ptr ptr FormField
;COM_INTERFACE_END
;endif
;
;sIID_FormFields textequ <IID {000020929h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FormField, Type=INTERFACE, GUID={00020928-0000-0000-C000-000000000046}
;
;ifndef FormFieldVtbl
;COM_INTERFACE_BEG FormField, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Type  , :ptr WdFieldType
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  get_EntryMacro  , :ptr BSTR
;  COM_MTD_STD  put_EntryMacro  , :BSTR
;  COM_MTD_STD  get_ExitMacro  , :ptr BSTR
;  COM_MTD_STD  put_ExitMacro  , :BSTR
;  COM_MTD_STD  get_OwnHelp  , :ptr BOOL
;  COM_MTD_STD  put_OwnHelp  , :BOOL
;  COM_MTD_STD  get_OwnStatus  , :ptr BOOL
;  COM_MTD_STD  put_OwnStatus  , :BOOL
;  COM_MTD_STD  get_HelpText  , :ptr BSTR
;  COM_MTD_STD  put_HelpText  , :BSTR
;  COM_MTD_STD  get_StatusText  , :ptr BSTR
;  COM_MTD_STD  put_StatusText  , :BSTR
;  COM_MTD_STD  get_Enabled  , :ptr BOOL
;  COM_MTD_STD  put_Enabled  , :BOOL
;  COM_MTD_STD  get_Result  , :ptr BSTR
;  COM_MTD_STD  put_Result  , :BSTR
;  COM_MTD_STD  get_TextInput  , :ptr ptr TextInput
;  COM_MTD_STD  get_CheckBox  , :ptr ptr CheckBox
;  COM_MTD_STD  get_DropDown  , :ptr ptr DropDown
;  COM_MTD_STD  get_Next  , :ptr ptr FormField
;  COM_MTD_STD  get_Previous  , :ptr ptr FormField
;  COM_MTD_STD  get_CalculateOnExit  , :ptr BOOL
;  COM_MTD_STD  put_CalculateOnExit  , :BOOL
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  Select  
;  COM_MTD_STD  Copy  
;  COM_MTD_STD  Cut  
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_FormField textequ <IID {000020928h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TextInput, Type=INTERFACE, GUID={00020927-0000-0000-C000-000000000046}
;
;ifndef TextInputVtbl
;COM_INTERFACE_BEG TextInput, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Valid  , :ptr BOOL
;  COM_MTD_STD  get_Default  , :ptr BSTR
;  COM_MTD_STD  put_Default  , :BSTR
;  COM_MTD_STD  get_Type  , :ptr WdTextFormFieldType
;  COM_MTD_STD  get_Format  , :ptr BSTR
;  COM_MTD_STD  get_Width  , :ptr SDWORD
;  COM_MTD_STD  put_Width  , :SDWORD
;  COM_MTD_STD  Clear  
;  COM_MTD_STD  EditType  , :WdTextFormFieldType,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_TextInput textequ <IID {000020927h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CheckBox, Type=INTERFACE, GUID={00020926-0000-0000-C000-000000000046}
;
;ifndef CheckBoxVtbl
;COM_INTERFACE_BEG CheckBox, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Valid  , :ptr BOOL
;  COM_MTD_STD  get_AutoSize  , :ptr BOOL
;  COM_MTD_STD  put_AutoSize  , :BOOL
;  COM_MTD_STD  get_Size  , :ptr REAL4
;  COM_MTD_STD  put_Size  , :REAL4
;  COM_MTD_STD  get_Default  , :ptr BOOL
;  COM_MTD_STD  put_Default  , :BOOL
;  COM_MTD_STD  get_Value  , :ptr BOOL
;  COM_MTD_STD  put_Value  , :BOOL
;COM_INTERFACE_END
;endif
;
;sIID_CheckBox textequ <IID {000020926h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- DropDown, Type=INTERFACE, GUID={00020925-0000-0000-C000-000000000046}
;
;ifndef DropDownVtbl
;COM_INTERFACE_BEG DropDown, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Valid  , :ptr BOOL
;  COM_MTD_STD  get_Default  , :ptr SDWORD
;  COM_MTD_STD  put_Default  , :SDWORD
;  COM_MTD_STD  get_Value  , :ptr SDWORD
;  COM_MTD_STD  put_Value  , :SDWORD
;  COM_MTD_STD  get_ListEntries  , :ptr ptr ListEntries
;COM_INTERFACE_END
;endif
;
;sIID_DropDown textequ <IID {000020925h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListEntries, Type=INTERFACE, GUID={00020924-0000-0000-C000-000000000046}
;
;ifndef ListEntriesVtbl
;COM_INTERFACE_BEG ListEntries, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr ListEntry
;  COM_MTD_STD  Add_  , :BSTR,:ptr VARIANT,:ptr ptr ListEntry
;  COM_MTD_STD  Clear  
;COM_INTERFACE_END
;endif
;
;sIID_ListEntries textequ <IID {000020924h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListEntry, Type=INTERFACE, GUID={00020923-0000-0000-C000-000000000046}
;
;ifndef ListEntryVtbl
;COM_INTERFACE_BEG ListEntry, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_ListEntry textequ <IID {000020923h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TablesOfFigures, Type=INTERFACE, GUID={00020922-0000-0000-C000-000000000046}
;
;ifndef TablesOfFiguresVtbl
;COM_INTERFACE_BEG TablesOfFigures, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Format  , :ptr WdTofFormat
;  COM_MTD_STD  put_Format  , :WdTofFormat
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr TableOfFigures
;  COM_MTD_STD  AddOld  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr TableOfFigures
;  COM_MTD_STD  MarkEntry  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Field
;  COM_MTD_STD  Add_  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr TableOfFigures
;COM_INTERFACE_END
;endif
;
;sIID_TablesOfFigures textequ <IID {000020922h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TableOfFigures, Type=INTERFACE, GUID={00020921-0000-0000-C000-000000000046}
;
;ifndef TableOfFiguresVtbl
;COM_INTERFACE_BEG TableOfFigures, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Caption  , :ptr BSTR
;  COM_MTD_STD  put_Caption  , :BSTR
;  COM_MTD_STD  get_IncludeLabel  , :ptr BOOL
;  COM_MTD_STD  put_IncludeLabel  , :BOOL
;  COM_MTD_STD  get_RightAlignPageNumbers  , :ptr BOOL
;  COM_MTD_STD  put_RightAlignPageNumbers  , :BOOL
;  COM_MTD_STD  get_UseHeadingStyles  , :ptr BOOL
;  COM_MTD_STD  put_UseHeadingStyles  , :BOOL
;  COM_MTD_STD  get_LowerHeadingLevel  , :ptr SDWORD
;  COM_MTD_STD  put_LowerHeadingLevel  , :SDWORD
;  COM_MTD_STD  get_UpperHeadingLevel  , :ptr SDWORD
;  COM_MTD_STD  put_UpperHeadingLevel  , :SDWORD
;  COM_MTD_STD  get_IncludePageNumbers  , :ptr BOOL
;  COM_MTD_STD  put_IncludePageNumbers  , :BOOL
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_UseFields  , :ptr BOOL
;  COM_MTD_STD  put_UseFields  , :BOOL
;  COM_MTD_STD  get_TableID  , :ptr BSTR
;  COM_MTD_STD  put_TableID  , :BSTR
;  COM_MTD_STD  get_HeadingStyles  , :ptr ptr HeadingStyles
;  COM_MTD_STD  get_TabLeader  , :ptr WdTabLeader
;  COM_MTD_STD  put_TabLeader  , :WdTabLeader
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  UpdatePageNumbers  
;  COM_MTD_STD  Update  
;  COM_MTD_STD  get_UseHyperlinks  , :ptr BOOL
;  COM_MTD_STD  put_UseHyperlinks  , :BOOL
;  COM_MTD_STD  get_HidePageNumbersInWeb  , :ptr BOOL
;  COM_MTD_STD  put_HidePageNumbersInWeb  , :BOOL
;COM_INTERFACE_END
;endif
;
;sIID_TableOfFigures textequ <IID {000020921h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMerge, Type=INTERFACE, GUID={00020920-0000-0000-C000-000000000046}
;
;ifndef MailMergeVtbl
;COM_INTERFACE_BEG MailMerge, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_MainDocumentType  , :ptr WdMailMergeMainDocType
;  COM_MTD_STD  put_MainDocumentType  , :WdMailMergeMainDocType
;  COM_MTD_STD  get_State  , :ptr WdMailMergeState
;  COM_MTD_STD  get_Destination  , :ptr WdMailMergeDestination
;  COM_MTD_STD  put_Destination  , :WdMailMergeDestination
;  COM_MTD_STD  get_DataSource  , :ptr ptr MailMergeDataSource
;  COM_MTD_STD  get_Fields  , :ptr ptr MailMergeFields
;  COM_MTD_STD  get_ViewMailMergeFieldCodes  , :ptr SDWORD
;  COM_MTD_STD  put_ViewMailMergeFieldCodes  , :SDWORD
;  COM_MTD_STD  get_SuppressBlankLines  , :ptr BOOL
;  COM_MTD_STD  put_SuppressBlankLines  , :BOOL
;  COM_MTD_STD  get_MailAsAttachment  , :ptr BOOL
;  COM_MTD_STD  put_MailAsAttachment  , :BOOL
;  COM_MTD_STD  get_MailAddressFieldName  , :ptr BSTR
;  COM_MTD_STD  put_MailAddressFieldName  , :BSTR
;  COM_MTD_STD  get_MailSubject  , :ptr BSTR
;  COM_MTD_STD  put_MailSubject  , :BSTR
;  COM_MTD_STD  CreateDataSource  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  CreateHeaderSource  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  OpenDataSource  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  OpenHeaderSource  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  Execute  , :ptr VARIANT
;  COM_MTD_STD  Check  
;  COM_MTD_STD  EditDataSource  
;  COM_MTD_STD  EditHeaderSource  
;  COM_MTD_STD  EditMainDocument  
;  COM_MTD_STD  UseAddressBook  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID_MailMerge textequ <IID {000020920h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMergeFields, Type=INTERFACE, GUID={0002091F-0000-0000-C000-000000000046}
;
;ifndef MailMergeFieldsVtbl
;COM_INTERFACE_BEG MailMergeFields, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr MailMergeField
;  COM_MTD_STD  Add_  , :ptr Range,:BSTR,:ptr ptr MailMergeField
;  COM_MTD_STD  AddAsk  , :ptr Range,:BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr MailMergeField
;  COM_MTD_STD  AddFillIn  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr MailMergeField
;  COM_MTD_STD  AddIf  , :ptr Range,:BSTR,:WdMailMergeComparison,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr MailMergeField
;  COM_MTD_STD  AddMergeRec  , :ptr Range,:ptr ptr MailMergeField
;  COM_MTD_STD  AddMergeSeq  , :ptr Range,:ptr ptr MailMergeField
;  COM_MTD_STD  AddNext  , :ptr Range,:ptr ptr MailMergeField
;  COM_MTD_STD  AddNextIf  , :ptr Range,:BSTR,:WdMailMergeComparison,:ptr VARIANT,:ptr ptr MailMergeField
;  COM_MTD_STD  AddSet  , :ptr Range,:BSTR,:ptr VARIANT,:ptr VARIANT,:ptr ptr MailMergeField
;  COM_MTD_STD  AddSkipIf  , :ptr Range,:BSTR,:WdMailMergeComparison,:ptr VARIANT,:ptr ptr MailMergeField
;COM_INTERFACE_END
;endif
;
;sIID_MailMergeFields textequ <IID {00002091Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMergeField, Type=INTERFACE, GUID={0002091E-0000-0000-C000-000000000046}
;
;ifndef MailMergeFieldVtbl
;COM_INTERFACE_BEG MailMergeField, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Type  , :ptr WdFieldType
;  COM_MTD_STD  get_Locked  , :ptr BOOL
;  COM_MTD_STD  put_Locked  , :BOOL
;  COM_MTD_STD  get_Code  , :ptr ptr Range
;  COM_MTD_STD  put_Code  , :ptr Range
;  COM_MTD_STD  get_Next  , :ptr ptr MailMergeField
;  COM_MTD_STD  get_Previous  , :ptr ptr MailMergeField
;  COM_MTD_STD  Select  
;  COM_MTD_STD  Copy  
;  COM_MTD_STD  Cut  
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_MailMergeField textequ <IID {00002091Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMergeDataSource, Type=INTERFACE, GUID={0002091D-0000-0000-C000-000000000046}
;
;ifndef MailMergeDataSourceVtbl
;COM_INTERFACE_BEG MailMergeDataSource, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_HeaderSourceName  , :ptr BSTR
;  COM_MTD_STD  get_Type  , :ptr WdMailMergeDataSource
;  COM_MTD_STD  get_HeaderSourceType  , :ptr WdMailMergeDataSource
;  COM_MTD_STD  get_ConnectString  , :ptr BSTR
;  COM_MTD_STD  get_QueryString  , :ptr BSTR
;  COM_MTD_STD  put_QueryString  , :BSTR
;  COM_MTD_STD  get_ActiveRecord  , :ptr WdMailMergeActiveRecord
;  COM_MTD_STD  put_ActiveRecord  , :WdMailMergeActiveRecord
;  COM_MTD_STD  get_FirstRecord  , :ptr SDWORD
;  COM_MTD_STD  put_FirstRecord  , :SDWORD
;  COM_MTD_STD  get_LastRecord  , :ptr SDWORD
;  COM_MTD_STD  put_LastRecord  , :SDWORD
;  COM_MTD_STD  get_FieldNames  , :ptr ptr MailMergeFieldNames
;  COM_MTD_STD  get_DataFields  , :ptr ptr MailMergeDataFields
;  COM_MTD_STD  FindRecord  , :BSTR,:BSTR,:ptr BOOL
;COM_INTERFACE_END
;endif
;
;sIID_MailMergeDataSource textequ <IID {00002091Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMergeFieldNames, Type=INTERFACE, GUID={0002091C-0000-0000-C000-000000000046}
;
;ifndef MailMergeFieldNamesVtbl
;COM_INTERFACE_BEG MailMergeFieldNames, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr MailMergeFieldName
;COM_INTERFACE_END
;endif
;
;sIID_MailMergeFieldNames textequ <IID {00002091Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMergeFieldName, Type=INTERFACE, GUID={0002091B-0000-0000-C000-000000000046}
;
;ifndef MailMergeFieldNameVtbl
;COM_INTERFACE_BEG MailMergeFieldName, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_MailMergeFieldName textequ <IID {00002091Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMergeDataFields, Type=INTERFACE, GUID={0002091A-0000-0000-C000-000000000046}
;
;ifndef MailMergeDataFieldsVtbl
;COM_INTERFACE_BEG MailMergeDataFields, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr MailMergeDataField
;COM_INTERFACE_END
;endif
;
;sIID_MailMergeDataFields textequ <IID {00002091Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMergeDataField, Type=INTERFACE, GUID={00020919-0000-0000-C000-000000000046}
;
;ifndef MailMergeDataFieldVtbl
;COM_INTERFACE_BEG MailMergeDataField, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Value  , :ptr BSTR
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_MailMergeDataField textequ <IID {000020919h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Envelope, Type=INTERFACE, GUID={00020918-0000-0000-C000-000000000046}
;
;ifndef EnvelopeVtbl
;COM_INTERFACE_BEG Envelope, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Address  , :ptr ptr Range
;  COM_MTD_STD  get_ReturnAddress  , :ptr ptr Range
;  COM_MTD_STD  get_DefaultPrintBarCode  , :ptr BOOL
;  COM_MTD_STD  put_DefaultPrintBarCode  , :BOOL
;  COM_MTD_STD  get_DefaultPrintFIMA  , :ptr BOOL
;  COM_MTD_STD  put_DefaultPrintFIMA  , :BOOL
;  COM_MTD_STD  get_DefaultHeight  , :ptr REAL4
;  COM_MTD_STD  put_DefaultHeight  , :REAL4
;  COM_MTD_STD  get_DefaultWidth  , :ptr REAL4
;  COM_MTD_STD  put_DefaultWidth  , :REAL4
;  COM_MTD_STD  get_DefaultSize  , :ptr BSTR
;  COM_MTD_STD  put_DefaultSize  , :BSTR
;  COM_MTD_STD  get_DefaultOmitReturnAddress  , :ptr BOOL
;  COM_MTD_STD  put_DefaultOmitReturnAddress  , :BOOL
;  COM_MTD_STD  get_FeedSource  , :ptr WdPaperTray
;  COM_MTD_STD  put_FeedSource  , :WdPaperTray
;  COM_MTD_STD  get_AddressFromLeft  , :ptr REAL4
;  COM_MTD_STD  put_AddressFromLeft  , :REAL4
;  COM_MTD_STD  get_AddressFromTop  , :ptr REAL4
;  COM_MTD_STD  put_AddressFromTop  , :REAL4
;  COM_MTD_STD  get_ReturnAddressFromLeft  , :ptr REAL4
;  COM_MTD_STD  put_ReturnAddressFromLeft  , :REAL4
;  COM_MTD_STD  get_ReturnAddressFromTop  , :ptr REAL4
;  COM_MTD_STD  put_ReturnAddressFromTop  , :REAL4
;  COM_MTD_STD  get_AddressStyle  , :ptr ptr Style
;  COM_MTD_STD  get_ReturnAddressStyle  , :ptr ptr Style
;  COM_MTD_STD  get_DefaultOrientation  , :ptr WdEnvelopeOrientation
;  COM_MTD_STD  put_DefaultOrientation  , :WdEnvelopeOrientation
;  COM_MTD_STD  get_DefaultFaceUp  , :ptr BOOL
;  COM_MTD_STD  put_DefaultFaceUp  , :BOOL
;  COM_MTD_STD  Insert  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  PrintOut  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  UpdateDocument  
;COM_INTERFACE_END
;endif
;
;sIID_Envelope textequ <IID {000020918h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailingLabel, Type=INTERFACE, GUID={00020917-0000-0000-C000-000000000046}
;
;ifndef MailingLabelVtbl
;COM_INTERFACE_BEG MailingLabel, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_DefaultPrintBarCode  , :ptr BOOL
;  COM_MTD_STD  put_DefaultPrintBarCode  , :BOOL
;  COM_MTD_STD  get_DefaultLaserTray  , :ptr WdPaperTray
;  COM_MTD_STD  put_DefaultLaserTray  , :WdPaperTray
;  COM_MTD_STD  get_CustomLabels  , :ptr ptr CustomLabels
;  COM_MTD_STD  get_DefaultLabelName  , :ptr BSTR
;  COM_MTD_STD  put_DefaultLabelName  , :BSTR
;  COM_MTD_STD  CreateNewDocument  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Document
;  COM_MTD_STD  PrintOut  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_MailingLabel textequ <IID {000020917h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CustomLabels, Type=INTERFACE, GUID={00020916-0000-0000-C000-000000000046}
;
;ifndef CustomLabelsVtbl
;COM_INTERFACE_BEG CustomLabels, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr CustomLabel
;  COM_MTD_STD  Add_  , :BSTR,:ptr VARIANT,:ptr ptr CustomLabel
;COM_INTERFACE_END
;endif
;
;sIID_CustomLabels textequ <IID {000020916h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CustomLabel, Type=INTERFACE, GUID={00020915-0000-0000-C000-000000000046}
;
;ifndef CustomLabelVtbl
;COM_INTERFACE_BEG CustomLabel, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  get_TopMargin  , :ptr REAL4
;  COM_MTD_STD  put_TopMargin  , :REAL4
;  COM_MTD_STD  get_SideMargin  , :ptr REAL4
;  COM_MTD_STD  put_SideMargin  , :REAL4
;  COM_MTD_STD  get_Height  , :ptr REAL4
;  COM_MTD_STD  put_Height  , :REAL4
;  COM_MTD_STD  get_Width  , :ptr REAL4
;  COM_MTD_STD  put_Width  , :REAL4
;  COM_MTD_STD  get_VerticalPitch  , :ptr REAL4
;  COM_MTD_STD  put_VerticalPitch  , :REAL4
;  COM_MTD_STD  get_HorizontalPitch  , :ptr REAL4
;  COM_MTD_STD  put_HorizontalPitch  , :REAL4
;  COM_MTD_STD  get_NumberAcross  , :ptr SDWORD
;  COM_MTD_STD  put_NumberAcross  , :SDWORD
;  COM_MTD_STD  get_NumberDown  , :ptr SDWORD
;  COM_MTD_STD  put_NumberDown  , :SDWORD
;  COM_MTD_STD  get_DotMatrix  , :ptr BOOL
;  COM_MTD_STD  get_PageSize  , :ptr WdCustomLabelPageSize
;  COM_MTD_STD  put_PageSize  , :WdCustomLabelPageSize
;  COM_MTD_STD  get_Valid  , :ptr BOOL
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_CustomLabel textequ <IID {000020915h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TablesOfContents, Type=INTERFACE, GUID={00020914-0000-0000-C000-000000000046}
;
;ifndef TablesOfContentsVtbl
;COM_INTERFACE_BEG TablesOfContents, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Format  , :ptr WdTocFormat
;  COM_MTD_STD  put_Format  , :WdTocFormat
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr TableOfContents
;  COM_MTD_STD  AddOld  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr TableOfContents
;  COM_MTD_STD  MarkEntry  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Field
;  COM_MTD_STD  Add_  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr TableOfContents
;COM_INTERFACE_END
;endif
;
;sIID_TablesOfContents textequ <IID {000020914h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TableOfContents, Type=INTERFACE, GUID={00020913-0000-0000-C000-000000000046}
;
;ifndef TableOfContentsVtbl
;COM_INTERFACE_BEG TableOfContents, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_UseHeadingStyles  , :ptr BOOL
;  COM_MTD_STD  put_UseHeadingStyles  , :BOOL
;  COM_MTD_STD  get_UseFields  , :ptr BOOL
;  COM_MTD_STD  put_UseFields  , :BOOL
;  COM_MTD_STD  get_UpperHeadingLevel  , :ptr SDWORD
;  COM_MTD_STD  put_UpperHeadingLevel  , :SDWORD
;  COM_MTD_STD  get_LowerHeadingLevel  , :ptr SDWORD
;  COM_MTD_STD  put_LowerHeadingLevel  , :SDWORD
;  COM_MTD_STD  get_TableID  , :ptr BSTR
;  COM_MTD_STD  put_TableID  , :BSTR
;  COM_MTD_STD  get_HeadingStyles  , :ptr ptr HeadingStyles
;  COM_MTD_STD  get_RightAlignPageNumbers  , :ptr BOOL
;  COM_MTD_STD  put_RightAlignPageNumbers  , :BOOL
;  COM_MTD_STD  get_IncludePageNumbers  , :ptr BOOL
;  COM_MTD_STD  put_IncludePageNumbers  , :BOOL
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_TabLeader  , :ptr WdTabLeader
;  COM_MTD_STD  put_TabLeader  , :WdTabLeader
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  UpdatePageNumbers  
;  COM_MTD_STD  Update  
;  COM_MTD_STD  get_UseHyperlinks  , :ptr BOOL
;  COM_MTD_STD  put_UseHyperlinks  , :BOOL
;  COM_MTD_STD  get_HidePageNumbersInWeb  , :ptr BOOL
;  COM_MTD_STD  put_HidePageNumbersInWeb  , :BOOL
;COM_INTERFACE_END
;endif
;
;sIID_TableOfContents textequ <IID {000020913h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TablesOfAuthorities, Type=INTERFACE, GUID={00020912-0000-0000-C000-000000000046}
;
;ifndef TablesOfAuthoritiesVtbl
;COM_INTERFACE_BEG TablesOfAuthorities, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Format  , :ptr WdToaFormat
;  COM_MTD_STD  put_Format  , :WdToaFormat
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr TableOfAuthorities
;  COM_MTD_STD  Add_  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr TableOfAuthorities
;  COM_MTD_STD  NextCitation  , :BSTR
;  COM_MTD_STD  MarkCitation  , :ptr Range,:BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Field
;  COM_MTD_STD  MarkAllCitations  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_TablesOfAuthorities textequ <IID {000020912h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TableOfAuthorities, Type=INTERFACE, GUID={00020911-0000-0000-C000-000000000046}
;
;ifndef TableOfAuthoritiesVtbl
;COM_INTERFACE_BEG TableOfAuthorities, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Passim  , :ptr BOOL
;  COM_MTD_STD  put_Passim  , :BOOL
;  COM_MTD_STD  get_KeepEntryFormatting  , :ptr BOOL
;  COM_MTD_STD  put_KeepEntryFormatting  , :BOOL
;  COM_MTD_STD  get_Category  , :ptr SDWORD
;  COM_MTD_STD  put_Category  , :SDWORD
;  COM_MTD_STD  get_Bookmark  , :ptr BSTR
;  COM_MTD_STD  put_Bookmark  , :BSTR
;  COM_MTD_STD  get_Separator  , :ptr BSTR
;  COM_MTD_STD  put_Separator  , :BSTR
;  COM_MTD_STD  get_IncludeSequenceName  , :ptr BSTR
;  COM_MTD_STD  put_IncludeSequenceName  , :BSTR
;  COM_MTD_STD  get_EntrySeparator  , :ptr BSTR
;  COM_MTD_STD  put_EntrySeparator  , :BSTR
;  COM_MTD_STD  get_PageRangeSeparator  , :ptr BSTR
;  COM_MTD_STD  put_PageRangeSeparator  , :BSTR
;  COM_MTD_STD  get_IncludeCategoryHeader  , :ptr BOOL
;  COM_MTD_STD  put_IncludeCategoryHeader  , :BOOL
;  COM_MTD_STD  get_PageNumberSeparator  , :ptr BSTR
;  COM_MTD_STD  put_PageNumberSeparator  , :BSTR
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_TabLeader  , :ptr WdTabLeader
;  COM_MTD_STD  put_TabLeader  , :WdTabLeader
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Update  
;COM_INTERFACE_END
;endif
;
;sIID_TableOfAuthorities textequ <IID {000020911h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Dialogs, Type=INTERFACE, GUID={00020910-0000-0000-C000-000000000046}
;
;ifndef DialogsVtbl
;COM_INTERFACE_BEG Dialogs, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :WdWordDialog,:ptr ptr Dialog
;COM_INTERFACE_END
;endif
;
;sIID_Dialogs textequ <IID {000020910h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Dialog, Type=INTERFACE, GUID={000209B8-0000-0000-C000-000000000046}
;
;ifndef DialogVtbl
;COM_INTERFACE_BEG Dialog, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_DefaultTab  , :ptr WdWordDialogTab
;  COM_MTD_STD  put_DefaultTab  , :WdWordDialogTab
;  COM_MTD_STD  get_Type  , :ptr WdWordDialog
;  COM_MTD_STD  Show  , :ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  Display  , :ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  Execute  
;  COM_MTD_STD  Update  
;  COM_MTD_STD  get_CommandName  , :ptr BSTR
;COM_INTERFACE_END
;endif
;
;sIID_Dialog textequ <IID {0000209B8h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- PageSetup, Type=INTERFACE, GUID={00020971-0000-0000-C000-000000000046}
;
;ifndef PageSetupVtbl
;COM_INTERFACE_BEG PageSetup, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_TopMargin  , :ptr REAL4
;  COM_MTD_STD  put_TopMargin  , :REAL4
;  COM_MTD_STD  get_BottomMargin  , :ptr REAL4
;  COM_MTD_STD  put_BottomMargin  , :REAL4
;  COM_MTD_STD  get_LeftMargin  , :ptr REAL4
;  COM_MTD_STD  put_LeftMargin  , :REAL4
;  COM_MTD_STD  get_RightMargin  , :ptr REAL4
;  COM_MTD_STD  put_RightMargin  , :REAL4
;  COM_MTD_STD  get_Gutter  , :ptr REAL4
;  COM_MTD_STD  put_Gutter  , :REAL4
;  COM_MTD_STD  get_PageWidth  , :ptr REAL4
;  COM_MTD_STD  put_PageWidth  , :REAL4
;  COM_MTD_STD  get_PageHeight  , :ptr REAL4
;  COM_MTD_STD  put_PageHeight  , :REAL4
;  COM_MTD_STD  get_Orientation  , :ptr WdOrientation
;  COM_MTD_STD  put_Orientation  , :WdOrientation
;  COM_MTD_STD  get_FirstPageTray  , :ptr WdPaperTray
;  COM_MTD_STD  put_FirstPageTray  , :WdPaperTray
;  COM_MTD_STD  get_OtherPagesTray  , :ptr WdPaperTray
;  COM_MTD_STD  put_OtherPagesTray  , :WdPaperTray
;  COM_MTD_STD  get_VerticalAlignment  , :ptr WdVerticalAlignment
;  COM_MTD_STD  put_VerticalAlignment  , :WdVerticalAlignment
;  COM_MTD_STD  get_MirrorMargins  , :ptr SDWORD
;  COM_MTD_STD  put_MirrorMargins  , :SDWORD
;  COM_MTD_STD  get_HeaderDistance  , :ptr REAL4
;  COM_MTD_STD  put_HeaderDistance  , :REAL4
;  COM_MTD_STD  get_FooterDistance  , :ptr REAL4
;  COM_MTD_STD  put_FooterDistance  , :REAL4
;  COM_MTD_STD  get_SectionStart  , :ptr WdSectionStart
;  COM_MTD_STD  put_SectionStart  , :WdSectionStart
;  COM_MTD_STD  get_OddAndEvenPagesHeaderFooter  , :ptr SDWORD
;  COM_MTD_STD  put_OddAndEvenPagesHeaderFooter  , :SDWORD
;  COM_MTD_STD  get_DifferentFirstPageHeaderFooter  , :ptr SDWORD
;  COM_MTD_STD  put_DifferentFirstPageHeaderFooter  , :SDWORD
;  COM_MTD_STD  get_SuppressEndnotes  , :ptr SDWORD
;  COM_MTD_STD  put_SuppressEndnotes  , :SDWORD
;  COM_MTD_STD  get_LineNumbering  , :ptr ptr LineNumbering
;  COM_MTD_STD  put_LineNumbering  , :ptr LineNumbering
;  COM_MTD_STD  get_TextColumns  , :ptr ptr TextColumns
;  COM_MTD_STD  put_TextColumns  , :ptr TextColumns
;  COM_MTD_STD  get_PaperSize  , :ptr WdPaperSize
;  COM_MTD_STD  put_PaperSize  , :WdPaperSize
;  COM_MTD_STD  get_TwoPagesOnOne  , :ptr BOOL
;  COM_MTD_STD  put_TwoPagesOnOne  , :BOOL
;  COM_MTD_STD  get_GutterOnTop  , :ptr BOOL
;  COM_MTD_STD  put_GutterOnTop  , :BOOL
;  COM_MTD_STD  get_CharsLine  , :ptr REAL4
;  COM_MTD_STD  put_CharsLine  , :REAL4
;  COM_MTD_STD  get_LinesPage  , :ptr REAL4
;  COM_MTD_STD  put_LinesPage  , :REAL4
;  COM_MTD_STD  get_ShowGrid  , :ptr BOOL
;  COM_MTD_STD  put_ShowGrid  , :BOOL
;  COM_MTD_STD  TogglePortrait  
;  COM_MTD_STD  SetAsTemplateDefault  
;  COM_MTD_STD  get_GutterStyle  , :ptr WdGutterStyleOld
;  COM_MTD_STD  put_GutterStyle  , :WdGutterStyleOld
;  COM_MTD_STD  get_SectionDirection  , :ptr WdSectionDirection
;  COM_MTD_STD  put_SectionDirection  , :WdSectionDirection
;  COM_MTD_STD  get_LayoutMode  , :ptr WdLayoutMode
;  COM_MTD_STD  put_LayoutMode  , :WdLayoutMode
;  COM_MTD_STD  get_GutterPos  , :ptr WdGutterStyle
;  COM_MTD_STD  put_GutterPos  , :WdGutterStyle
;COM_INTERFACE_END
;endif
;
;sIID_PageSetup textequ <IID {000020971h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- LineNumbering, Type=INTERFACE, GUID={00020972-0000-0000-C000-000000000046}
;
;ifndef LineNumberingVtbl
;COM_INTERFACE_BEG LineNumbering, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_RestartMode  , :ptr WdNumberingRule
;  COM_MTD_STD  put_RestartMode  , :WdNumberingRule
;  COM_MTD_STD  get_StartingNumber  , :ptr SDWORD
;  COM_MTD_STD  put_StartingNumber  , :SDWORD
;  COM_MTD_STD  get_DistanceFromText  , :ptr REAL4
;  COM_MTD_STD  put_DistanceFromText  , :REAL4
;  COM_MTD_STD  get_CountBy  , :ptr SDWORD
;  COM_MTD_STD  put_CountBy  , :SDWORD
;  COM_MTD_STD  get_Active  , :ptr SDWORD
;  COM_MTD_STD  put_Active  , :SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_LineNumbering textequ <IID {000020972h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TextColumns, Type=INTERFACE, GUID={00020973-0000-0000-C000-000000000046}
;
;ifndef TextColumnsVtbl
;COM_INTERFACE_BEG TextColumns, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_EvenlySpaced  , :ptr SDWORD
;  COM_MTD_STD  put_EvenlySpaced  , :SDWORD
;  COM_MTD_STD  get_LineBetween  , :ptr SDWORD
;  COM_MTD_STD  put_LineBetween  , :SDWORD
;  COM_MTD_STD  get_Width  , :ptr REAL4
;  COM_MTD_STD  put_Width  , :REAL4
;  COM_MTD_STD  get_Spacing  , :ptr REAL4
;  COM_MTD_STD  put_Spacing  , :REAL4
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr TextColumn
;  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr TextColumn
;  COM_MTD_STD  SetCount  , :SDWORD
;  COM_MTD_STD  get_FlowDirection  , :ptr WdFlowDirection
;  COM_MTD_STD  put_FlowDirection  , :WdFlowDirection
;COM_INTERFACE_END
;endif
;
;sIID_TextColumns textequ <IID {000020973h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TextColumn, Type=INTERFACE, GUID={00020974-0000-0000-C000-000000000046}
;
;ifndef TextColumnVtbl
;COM_INTERFACE_BEG TextColumn, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Width  , :ptr REAL4
;  COM_MTD_STD  put_Width  , :REAL4
;  COM_MTD_STD  get_SpaceAfter  , :ptr REAL4
;  COM_MTD_STD  put_SpaceAfter  , :REAL4
;COM_INTERFACE_END
;endif
;
;sIID_TextColumn textequ <IID {000020974h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Selection, Type=INTERFACE, GUID={00020975-0000-0000-C000-000000000046}
;
;ifndef SelectionVtbl
;COM_INTERFACE_BEG Selection, IDispatch
;  COM_MTD_STD  get_Text  , :ptr BSTR
;  COM_MTD_STD  put_Text  , :BSTR
;  COM_MTD_STD  get_FormattedText  , :ptr ptr Range
;  COM_MTD_STD  put_FormattedText  , :ptr Range
;  COM_MTD_STD  get_Start  , :ptr SDWORD
;  COM_MTD_STD  put_Start  , :SDWORD
;  COM_MTD_STD  get_End  , :ptr SDWORD
;  COM_MTD_STD  put_End  , :SDWORD
;  COM_MTD_STD  get_Font  , :ptr ptr Font
;  COM_MTD_STD  put_Font  , :ptr Font
;  COM_MTD_STD  get_Type  , :ptr WdSelectionType
;  COM_MTD_STD  get_StoryType  , :ptr WdStoryType
;  COM_MTD_STD  get_Style  , :ptr VARIANT
;  COM_MTD_STD  put_Style  , :ptr VARIANT
;  COM_MTD_STD  get_Tables  , :ptr ptr Tables
;  COM_MTD_STD  get_Words  , :ptr ptr Words
;  COM_MTD_STD  get_Sentences  , :ptr ptr Sentences
;  COM_MTD_STD  get_Characters  , :ptr ptr Characters
;  COM_MTD_STD  get_Footnotes  , :ptr ptr Footnotes
;  COM_MTD_STD  get_Endnotes  , :ptr ptr Endnotes
;  COM_MTD_STD  get_Comments  , :ptr ptr Comments
;  COM_MTD_STD  get_Cells  , :ptr ptr Cells
;  COM_MTD_STD  get_Sections  , :ptr ptr Sections
;  COM_MTD_STD  get_Paragraphs  , :ptr ptr Paragraphs
;  COM_MTD_STD  get_Borders  , :ptr ptr Borders
;  COM_MTD_STD  put_Borders  , :ptr Borders
;  COM_MTD_STD  get_Shading  , :ptr ptr Shading
;  COM_MTD_STD  get_Fields  , :ptr ptr Fields
;  COM_MTD_STD  get_FormFields  , :ptr ptr FormFields
;  COM_MTD_STD  get_Frames  , :ptr ptr Frames
;  COM_MTD_STD  get_ParagraphFormat  , :ptr ptr ParagraphFormat
;  COM_MTD_STD  put_ParagraphFormat  , :ptr ParagraphFormat
;  COM_MTD_STD  get_PageSetup  , :ptr ptr PageSetup
;  COM_MTD_STD  put_PageSetup  , :ptr PageSetup
;  COM_MTD_STD  get_Bookmarks  , :ptr ptr Bookmarks
;  COM_MTD_STD  get_StoryLength  , :ptr SDWORD
;  COM_MTD_STD  get_LanguageID  , :ptr WdLanguageID
;  COM_MTD_STD  put_LanguageID  , :WdLanguageID
;  COM_MTD_STD  get_LanguageIDFarEast  , :ptr WdLanguageID
;  COM_MTD_STD  put_LanguageIDFarEast  , :WdLanguageID
;  COM_MTD_STD  get_LanguageIDOther  , :ptr WdLanguageID
;  COM_MTD_STD  put_LanguageIDOther  , :WdLanguageID
;  COM_MTD_STD  get_Hyperlinks  , :ptr ptr Hyperlinks
;  COM_MTD_STD  get_Columns  , :ptr ptr Columns
;  COM_MTD_STD  get_Rows  , :ptr ptr Rows
;  COM_MTD_STD  get_HeaderFooter  , :ptr ptr HeaderFooter
;  COM_MTD_STD  get_IsEndOfRowMark  , :ptr BOOL
;  COM_MTD_STD  get_BookmarkID  , :ptr SDWORD
;  COM_MTD_STD  get_PreviousBookmarkID  , :ptr SDWORD
;  COM_MTD_STD  get_Find  , :ptr ptr Find
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_Information  , :WdInformation,:ptr VARIANT
;  COM_MTD_STD  get_Flags  , :ptr WdSelectionFlags
;  COM_MTD_STD  put_Flags  , :WdSelectionFlags
;  COM_MTD_STD  get_Active  , :ptr BOOL
;  COM_MTD_STD  get_StartIsActive  , :ptr BOOL
;  COM_MTD_STD  put_StartIsActive  , :BOOL
;  COM_MTD_STD  get_IPAtEndOfLine  , :ptr BOOL
;  COM_MTD_STD  get_ExtendMode  , :ptr BOOL
;  COM_MTD_STD  put_ExtendMode  , :BOOL
;  COM_MTD_STD  get_ColumnSelectMode  , :ptr BOOL
;  COM_MTD_STD  put_ColumnSelectMode  , :BOOL
;  COM_MTD_STD  get_Orientation  , :ptr WdTextOrientation
;  COM_MTD_STD  put_Orientation  , :WdTextOrientation
;  COM_MTD_STD  get_InlineShapes  , :ptr ptr InlineShapes
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Document  , :ptr ptr Document
;  COM_MTD_STD  get_ShapeRange  , :ptr ptr ShapeRange
;  COM_MTD_STD  Select  
;  COM_MTD_STD  SetRange  , :SDWORD,:SDWORD
;  COM_MTD_STD  Collapse  , :ptr VARIANT
;  COM_MTD_STD  InsertBefore  , :BSTR
;  COM_MTD_STD  InsertAfter  , :BSTR
;  COM_MTD_STD  Next  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Range
;  COM_MTD_STD  Previous  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Range
;  COM_MTD_STD  StartOf  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  EndOf  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  Move  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveStart  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveEnd  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveWhile  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveStartWhile  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveEndWhile  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveUntil  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveStartUntil  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveEndUntil  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  Cut  
;  COM_MTD_STD  Copy  
;  COM_MTD_STD  Paste  
;  COM_MTD_STD  InsertBreak  , :ptr VARIANT
;  COM_MTD_STD  InsertFile  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  InStory  , :ptr Range,:ptr BOOL
;  COM_MTD_STD  InRange  , :ptr Range,:ptr BOOL
;  COM_MTD_STD  Delete  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  Expand  , :ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  InsertParagraph  
;  COM_MTD_STD  InsertParagraphAfter  
;  COM_MTD_STD  ConvertToTableOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Table
;  COM_MTD_STD  InsertDateTimeOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  InsertSymbol  , :SDWORD,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  InsertCrossReference  , :ptr VARIANT,:WdReferenceKind,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  InsertCaption  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  CopyAsPicture  
;  COM_MTD_STD  SortOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  SortAscending  
;  COM_MTD_STD  SortDescending  
;  COM_MTD_STD  IsEqual  , :ptr Range,:ptr BOOL
;  COM_MTD_STD  Calculate  , :ptr REAL4
;  COM_MTD_STD  GoTo_  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Range
;  COM_MTD_STD  GoToNext  , :WdGoToItem,:ptr ptr Range
;  COM_MTD_STD  GoToPrevious  , :WdGoToItem,:ptr ptr Range
;  COM_MTD_STD  PasteSpecial  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  PreviousField  , :ptr ptr Field
;  COM_MTD_STD  NextField  , :ptr ptr Field
;  COM_MTD_STD  InsertParagraphBefore  
;  COM_MTD_STD  InsertCells  , :ptr VARIANT
;  COM_MTD_STD  Extend  , :ptr VARIANT
;  COM_MTD_STD  Shrink  
;  COM_MTD_STD  MoveLeft  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveRight  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveUp  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  MoveDown  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  HomeKey  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  EndKey  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  EscapeKey  
;  COM_MTD_STD  TypeText  , :BSTR
;  COM_MTD_STD  CopyFormat  
;  COM_MTD_STD  PasteFormat  
;  COM_MTD_STD  TypeParagraph  
;  COM_MTD_STD  TypeBackspace  
;  COM_MTD_STD  NextSubdocument  
;  COM_MTD_STD  PreviousSubdocument  
;  COM_MTD_STD  SelectColumn  
;  COM_MTD_STD  SelectCurrentFont  
;  COM_MTD_STD  SelectCurrentAlignment  
;  COM_MTD_STD  SelectCurrentSpacing  
;  COM_MTD_STD  SelectCurrentIndent  
;  COM_MTD_STD  SelectCurrentTabs  
;  COM_MTD_STD  SelectCurrentColor  
;  COM_MTD_STD  CreateTextbox  
;  COM_MTD_STD  WholeStory  
;  COM_MTD_STD  SelectRow  
;  COM_MTD_STD  SplitTable  
;  COM_MTD_STD  InsertRows  , :ptr VARIANT
;  COM_MTD_STD  InsertColumns  
;  COM_MTD_STD  InsertFormula  , :ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  NextRevision  , :ptr VARIANT,:ptr ptr Revision
;  COM_MTD_STD  PreviousRevision  , :ptr VARIANT,:ptr ptr Revision
;  COM_MTD_STD  PasteAsNestedTable  
;  COM_MTD_STD  CreateAutoTextEntry  , :BSTR,:BSTR,:ptr ptr AutoTextEntry
;  COM_MTD_STD  DetectLanguage  
;  COM_MTD_STD  SelectCell  
;  COM_MTD_STD  InsertRowsBelow  , :ptr VARIANT
;  COM_MTD_STD  InsertColumnsRight  
;  COM_MTD_STD  InsertRowsAbove  , :ptr VARIANT
;  COM_MTD_STD  RtlRun  
;  COM_MTD_STD  LtrRun  
;  COM_MTD_STD  BoldRun  
;  COM_MTD_STD  ItalicRun  
;  COM_MTD_STD  RtlPara  
;  COM_MTD_STD  LtrPara  
;  COM_MTD_STD  InsertDateTime  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  Sort  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  ConvertToTable  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Table
;  COM_MTD_STD  get_NoProofing  , :ptr SDWORD
;  COM_MTD_STD  put_NoProofing  , :SDWORD
;  COM_MTD_STD  get_TopLevelTables  , :ptr ptr Tables
;  COM_MTD_STD  get_LanguageDetected  , :ptr BOOL
;  COM_MTD_STD  put_LanguageDetected  , :BOOL
;  COM_MTD_STD  get_FitTextWidth  , :ptr REAL4
;  COM_MTD_STD  put_FitTextWidth  , :REAL4
;COM_INTERFACE_END
;endif
;
;sIID_Selection textequ <IID {000020975h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TablesOfAuthoritiesCategories, Type=INTERFACE, GUID={00020976-0000-0000-C000-000000000046}
;
;ifndef TablesOfAuthoritiesCategoriesVtbl
;COM_INTERFACE_BEG TablesOfAuthoritiesCategories, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr TableOfAuthoritiesCategory
;COM_INTERFACE_END
;endif
;
;sIID_TablesOfAuthoritiesCategories textequ <IID {000020976h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TableOfAuthoritiesCategory, Type=INTERFACE, GUID={00020977-0000-0000-C000-000000000046}
;
;ifndef TableOfAuthoritiesCategoryVtbl
;COM_INTERFACE_BEG TableOfAuthoritiesCategory, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_TableOfAuthoritiesCategory textequ <IID {000020977h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CaptionLabels, Type=INTERFACE, GUID={00020978-0000-0000-C000-000000000046}
;
;ifndef CaptionLabelsVtbl
;COM_INTERFACE_BEG CaptionLabels, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr CaptionLabel
;  COM_MTD_STD  Add_  , :BSTR,:ptr ptr CaptionLabel
;COM_INTERFACE_END
;endif
;
;sIID_CaptionLabels textequ <IID {000020978h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CaptionLabel, Type=INTERFACE, GUID={00020979-0000-0000-C000-000000000046}
;
;ifndef CaptionLabelVtbl
;COM_INTERFACE_BEG CaptionLabel, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_BuiltIn  , :ptr BOOL
;  COM_MTD_STD  get_ID  , :ptr WdCaptionLabelID
;  COM_MTD_STD  get_IncludeChapterNumber  , :ptr BOOL
;  COM_MTD_STD  put_IncludeChapterNumber  , :BOOL
;  COM_MTD_STD  get_NumberStyle  , :ptr WdCaptionNumberStyle
;  COM_MTD_STD  put_NumberStyle  , :WdCaptionNumberStyle
;  COM_MTD_STD  get_ChapterStyleLevel  , :ptr SDWORD
;  COM_MTD_STD  put_ChapterStyleLevel  , :SDWORD
;  COM_MTD_STD  get_Separator  , :ptr WdSeparatorType
;  COM_MTD_STD  put_Separator  , :WdSeparatorType
;  COM_MTD_STD  get_Position  , :ptr WdCaptionPosition
;  COM_MTD_STD  put_Position  , :WdCaptionPosition
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_CaptionLabel textequ <IID {000020979h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- AutoCaptions, Type=INTERFACE, GUID={0002097A-0000-0000-C000-000000000046}
;
;ifndef AutoCaptionsVtbl
;COM_INTERFACE_BEG AutoCaptions, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr AutoCaption
;  COM_MTD_STD  CancelAutoInsert  
;COM_INTERFACE_END
;endif
;
;sIID_AutoCaptions textequ <IID {00002097Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- AutoCaption, Type=INTERFACE, GUID={0002097B-0000-0000-C000-000000000046}
;
;ifndef AutoCaptionVtbl
;COM_INTERFACE_BEG AutoCaption, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_AutoInsert  , :ptr BOOL
;  COM_MTD_STD  put_AutoInsert  , :BOOL
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_CaptionLabel  , :ptr VARIANT
;  COM_MTD_STD  put_CaptionLabel  , :ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_AutoCaption textequ <IID {00002097Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Indexes, Type=INTERFACE, GUID={0002097C-0000-0000-C000-000000000046}
;
;ifndef IndexesVtbl
;COM_INTERFACE_BEG Indexes, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Format  , :ptr WdIndexFormat
;  COM_MTD_STD  put_Format  , :WdIndexFormat
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Index
;  COM_MTD_STD  AddOld  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Index
;  COM_MTD_STD  MarkEntry  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Field
;  COM_MTD_STD  MarkAllEntries  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  AutoMarkEntries  , :BSTR
;  COM_MTD_STD  Add_  , :ptr Range,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Index
;COM_INTERFACE_END
;endif
;
;sIID_Indexes textequ <IID {00002097Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Index, Type=INTERFACE, GUID={0002097D-0000-0000-C000-000000000046}
;
;ifndef IndexVtbl
;COM_INTERFACE_BEG Index, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_HeadingSeparator  , :ptr WdHeadingSeparator
;  COM_MTD_STD  put_HeadingSeparator  , :WdHeadingSeparator
;  COM_MTD_STD  get_RightAlignPageNumbers  , :ptr BOOL
;  COM_MTD_STD  put_RightAlignPageNumbers  , :BOOL
;  COM_MTD_STD  get_Type  , :ptr WdIndexType
;  COM_MTD_STD  put_Type  , :WdIndexType
;  COM_MTD_STD  get_NumberOfColumns  , :ptr SDWORD
;  COM_MTD_STD  put_NumberOfColumns  , :SDWORD
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_TabLeader  , :ptr WdTabLeader
;  COM_MTD_STD  put_TabLeader  , :WdTabLeader
;  COM_MTD_STD  get_AccentedLetters  , :ptr BOOL
;  COM_MTD_STD  put_AccentedLetters  , :BOOL
;  COM_MTD_STD  get_SortBy  , :ptr WdIndexSortBy
;  COM_MTD_STD  put_SortBy  , :WdIndexSortBy
;  COM_MTD_STD  get_Filter  , :ptr WdIndexFilter
;  COM_MTD_STD  put_Filter  , :WdIndexFilter
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Update  
;  COM_MTD_STD  get_IndexLanguage  , :ptr WdLanguageID
;  COM_MTD_STD  put_IndexLanguage  , :WdLanguageID
;COM_INTERFACE_END
;endif
;
;sIID_Index textequ <IID {00002097Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- AddIn, Type=INTERFACE, GUID={0002097E-0000-0000-C000-000000000046}
;
;ifndef AddInVtbl
;COM_INTERFACE_BEG AddIn, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Path  , :ptr BSTR
;  COM_MTD_STD  get_Installed  , :ptr BOOL
;  COM_MTD_STD  put_Installed  , :BOOL
;  COM_MTD_STD  get_Compiled  , :ptr BOOL
;  COM_MTD_STD  get_Autoload  , :ptr BOOL
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_AddIn textequ <IID {00002097Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- AddIns, Type=INTERFACE, GUID={0002097F-0000-0000-C000-000000000046}
;
;ifndef AddInsVtbl
;COM_INTERFACE_BEG AddIns, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr AddIn
;  COM_MTD_STD  Add_  , :BSTR,:ptr VARIANT,:ptr ptr AddIn
;  COM_MTD_STD  Unload  , :BOOL
;COM_INTERFACE_END
;endif
;
;sIID_AddIns textequ <IID {00002097Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Revisions, Type=INTERFACE, GUID={00020980-0000-0000-C000-000000000046}
;
;ifndef RevisionsVtbl
;COM_INTERFACE_BEG Revisions, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Revision
;  COM_MTD_STD  AcceptAll  
;  COM_MTD_STD  RejectAll  
;COM_INTERFACE_END
;endif
;
;sIID_Revisions textequ <IID {000020980h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Revision, Type=INTERFACE, GUID={00020981-0000-0000-C000-000000000046}
;
;ifndef RevisionVtbl
;COM_INTERFACE_BEG Revision, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Author  , :ptr BSTR
;  COM_MTD_STD  get_Date  , :ptr DATE
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_Type  , :ptr WdRevisionType
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  Accept  
;  COM_MTD_STD  Reject  
;COM_INTERFACE_END
;endif
;
;sIID_Revision textequ <IID {000020981h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Task, Type=INTERFACE, GUID={00020982-0000-0000-C000-000000000046}
;
;ifndef TaskVtbl
;COM_INTERFACE_BEG Task, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Left  , :ptr SDWORD
;  COM_MTD_STD  put_Left  , :SDWORD
;  COM_MTD_STD  get_Top  , :ptr SDWORD
;  COM_MTD_STD  put_Top  , :SDWORD
;  COM_MTD_STD  get_Width  , :ptr SDWORD
;  COM_MTD_STD  put_Width  , :SDWORD
;  COM_MTD_STD  get_Height  , :ptr SDWORD
;  COM_MTD_STD  put_Height  , :SDWORD
;  COM_MTD_STD  get_WindowState  , :ptr WdWindowState
;  COM_MTD_STD  put_WindowState  , :WdWindowState
;  COM_MTD_STD  get_Visible  , :ptr BOOL
;  COM_MTD_STD  put_Visible  , :BOOL
;  COM_MTD_STD  Activate  , :ptr VARIANT
;  COM_MTD_STD  Close  
;  COM_MTD_STD  Move  , :SDWORD,:SDWORD
;  COM_MTD_STD  Resize  , :SDWORD,:SDWORD
;  COM_MTD_STD  SendWindowMessage  , :SDWORD,:SDWORD,:SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_Task textequ <IID {000020982h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Tasks, Type=INTERFACE, GUID={00020983-0000-0000-C000-000000000046}
;
;ifndef TasksVtbl
;COM_INTERFACE_BEG Tasks, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Task
;  COM_MTD_STD  Exists  , :BSTR,:ptr BOOL
;  COM_MTD_STD  ExitWindows  
;COM_INTERFACE_END
;endif
;
;sIID_Tasks textequ <IID {000020983h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HeadersFooters, Type=INTERFACE, GUID={00020984-0000-0000-C000-000000000046}
;
;ifndef HeadersFootersVtbl
;COM_INTERFACE_BEG HeadersFooters, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :WdHeaderFooterIndex,:ptr ptr HeaderFooter
;COM_INTERFACE_END
;endif
;
;sIID_HeadersFooters textequ <IID {000020984h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HeaderFooter, Type=INTERFACE, GUID={00020985-0000-0000-C000-000000000046}
;
;ifndef HeaderFooterVtbl
;COM_INTERFACE_BEG HeaderFooter, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_Index  , :ptr WdHeaderFooterIndex
;  COM_MTD_STD  get_IsHeader  , :ptr BOOL
;  COM_MTD_STD  get_Exists  , :ptr BOOL
;  COM_MTD_STD  put_Exists  , :BOOL
;  COM_MTD_STD  get_PageNumbers  , :ptr ptr PageNumbers
;  COM_MTD_STD  get_LinkToPrevious  , :ptr BOOL
;  COM_MTD_STD  put_LinkToPrevious  , :BOOL
;  COM_MTD_STD  get_Shapes  , :ptr ptr Shapes
;COM_INTERFACE_END
;endif
;
;sIID_HeaderFooter textequ <IID {000020985h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- PageNumbers, Type=INTERFACE, GUID={00020986-0000-0000-C000-000000000046}
;
;ifndef PageNumbersVtbl
;COM_INTERFACE_BEG PageNumbers, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_NumberStyle  , :ptr WdPageNumberStyle
;  COM_MTD_STD  put_NumberStyle  , :WdPageNumberStyle
;  COM_MTD_STD  get_IncludeChapterNumber  , :ptr BOOL
;  COM_MTD_STD  put_IncludeChapterNumber  , :BOOL
;  COM_MTD_STD  get_HeadingLevelForChapter  , :ptr SDWORD
;  COM_MTD_STD  put_HeadingLevelForChapter  , :SDWORD
;  COM_MTD_STD  get_ChapterPageSeparator  , :ptr WdSeparatorType
;  COM_MTD_STD  put_ChapterPageSeparator  , :WdSeparatorType
;  COM_MTD_STD  get_RestartNumberingAtSection  , :ptr BOOL
;  COM_MTD_STD  put_RestartNumberingAtSection  , :BOOL
;  COM_MTD_STD  get_StartingNumber  , :ptr SDWORD
;  COM_MTD_STD  put_StartingNumber  , :SDWORD
;  COM_MTD_STD  get_ShowFirstPageNumber  , :ptr BOOL
;  COM_MTD_STD  put_ShowFirstPageNumber  , :BOOL
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr PageNumber
;  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr VARIANT,:ptr ptr PageNumber
;  COM_MTD_STD  get_DoubleQuote  , :ptr BOOL
;  COM_MTD_STD  put_DoubleQuote  , :BOOL
;COM_INTERFACE_END
;endif
;
;sIID_PageNumbers textequ <IID {000020986h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- PageNumber, Type=INTERFACE, GUID={00020987-0000-0000-C000-000000000046}
;
;ifndef PageNumberVtbl
;COM_INTERFACE_BEG PageNumber, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Alignment  , :ptr WdPageNumberAlignment
;  COM_MTD_STD  put_Alignment  , :WdPageNumberAlignment
;  COM_MTD_STD  Select  
;  COM_MTD_STD  Copy  
;  COM_MTD_STD  Cut  
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_PageNumber textequ <IID {000020987h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Subdocuments, Type=INTERFACE, GUID={00020988-0000-0000-C000-000000000046}
;
;ifndef SubdocumentsVtbl
;COM_INTERFACE_BEG Subdocuments, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Expanded  , :ptr BOOL
;  COM_MTD_STD  put_Expanded  , :BOOL
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Subdocument
;  COM_MTD_STD  AddFromFile  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Subdocument
;  COM_MTD_STD  AddFromRange  , :ptr Range,:ptr ptr Subdocument
;  COM_MTD_STD  Merge  , :ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Select  
;COM_INTERFACE_END
;endif
;
;sIID_Subdocuments textequ <IID {000020988h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Subdocument, Type=INTERFACE, GUID={00020989-0000-0000-C000-000000000046}
;
;ifndef SubdocumentVtbl
;COM_INTERFACE_BEG Subdocument, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Locked  , :ptr BOOL
;  COM_MTD_STD  put_Locked  , :BOOL
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Path  , :ptr BSTR
;  COM_MTD_STD  get_HasFile  , :ptr BOOL
;  COM_MTD_STD  get_Level  , :ptr SDWORD
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Split  , :ptr Range
;  COM_MTD_STD  Open  , :ptr ptr Document
;COM_INTERFACE_END
;endif
;
;sIID_Subdocument textequ <IID {000020989h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HeadingStyles, Type=INTERFACE, GUID={0002098A-0000-0000-C000-000000000046}
;
;ifndef HeadingStylesVtbl
;COM_INTERFACE_BEG HeadingStyles, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr HeadingStyle
;  COM_MTD_STD  Add_  , :ptr VARIANT,:SWORD,:ptr ptr HeadingStyle
;COM_INTERFACE_END
;endif
;
;sIID_HeadingStyles textequ <IID {00002098Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HeadingStyle, Type=INTERFACE, GUID={0002098B-0000-0000-C000-000000000046}
;
;ifndef HeadingStyleVtbl
;COM_INTERFACE_BEG HeadingStyle, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Style  , :ptr VARIANT
;  COM_MTD_STD  put_Style  , :ptr VARIANT
;  COM_MTD_STD  get_Level  , :ptr SWORD
;  COM_MTD_STD  put_Level  , :SWORD
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_HeadingStyle textequ <IID {00002098Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- StoryRanges, Type=INTERFACE, GUID={0002098C-0000-0000-C000-000000000046}
;
;ifndef StoryRangesVtbl
;COM_INTERFACE_BEG StoryRanges, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :WdStoryType,:ptr ptr Range
;COM_INTERFACE_END
;endif
;
;sIID_StoryRanges textequ <IID {00002098Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListLevel, Type=INTERFACE, GUID={0002098D-0000-0000-C000-000000000046}
;
;ifndef ListLevelVtbl
;COM_INTERFACE_BEG ListLevel, IDispatch
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_NumberFormat  , :ptr BSTR
;  COM_MTD_STD  put_NumberFormat  , :BSTR
;  COM_MTD_STD  get_TrailingCharacter  , :ptr WdTrailingCharacter
;  COM_MTD_STD  put_TrailingCharacter  , :WdTrailingCharacter
;  COM_MTD_STD  get_NumberStyle  , :ptr WdListNumberStyle
;  COM_MTD_STD  put_NumberStyle  , :WdListNumberStyle
;  COM_MTD_STD  get_NumberPosition  , :ptr REAL4
;  COM_MTD_STD  put_NumberPosition  , :REAL4
;  COM_MTD_STD  get_Alignment  , :ptr WdListLevelAlignment
;  COM_MTD_STD  put_Alignment  , :WdListLevelAlignment
;  COM_MTD_STD  get_TextPosition  , :ptr REAL4
;  COM_MTD_STD  put_TextPosition  , :REAL4
;  COM_MTD_STD  get_TabPosition  , :ptr REAL4
;  COM_MTD_STD  put_TabPosition  , :REAL4
;  COM_MTD_STD  get_ResetOnHigherOld  , :ptr BOOL
;  COM_MTD_STD  put_ResetOnHigherOld  , :BOOL
;  COM_MTD_STD  get_StartAt  , :ptr SDWORD
;  COM_MTD_STD  put_StartAt  , :SDWORD
;  COM_MTD_STD  get_LinkedStyle  , :ptr BSTR
;  COM_MTD_STD  put_LinkedStyle  , :BSTR
;  COM_MTD_STD  get_Font  , :ptr ptr Font
;  COM_MTD_STD  put_Font  , :ptr Font
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_ResetOnHigher  , :ptr SDWORD
;  COM_MTD_STD  put_ResetOnHigher  , :SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_ListLevel textequ <IID {00002098Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListLevels, Type=INTERFACE, GUID={0002098E-0000-0000-C000-000000000046}
;
;ifndef ListLevelsVtbl
;COM_INTERFACE_BEG ListLevels, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr ListLevel
;COM_INTERFACE_END
;endif
;
;sIID_ListLevels textequ <IID {00002098Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListTemplate, Type=INTERFACE, GUID={0002098F-0000-0000-C000-000000000046}
;
;ifndef ListTemplateVtbl
;COM_INTERFACE_BEG ListTemplate, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_OutlineNumbered  , :ptr BOOL
;  COM_MTD_STD  put_OutlineNumbered  , :BOOL
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  get_ListLevels  , :ptr ptr ListLevels
;  COM_MTD_STD  Convert  , :ptr VARIANT,:ptr ptr ListTemplate
;COM_INTERFACE_END
;endif
;
;sIID_ListTemplate textequ <IID {00002098Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListTemplates, Type=INTERFACE, GUID={00020990-0000-0000-C000-000000000046}
;
;ifndef ListTemplatesVtbl
;COM_INTERFACE_BEG ListTemplates, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr ListTemplate
;  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr VARIANT,:ptr ptr ListTemplate
;COM_INTERFACE_END
;endif
;
;sIID_ListTemplates textequ <IID {000020990h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListParagraphs, Type=INTERFACE, GUID={00020991-0000-0000-C000-000000000046}
;
;ifndef ListParagraphsVtbl
;COM_INTERFACE_BEG ListParagraphs, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Paragraph
;COM_INTERFACE_END
;endif
;
;sIID_ListParagraphs textequ <IID {000020991h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- List, Type=INTERFACE, GUID={00020992-0000-0000-C000-000000000046}
;
;ifndef ListVtbl
;COM_INTERFACE_BEG List, IDispatch
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_ListParagraphs  , :ptr ptr ListParagraphs
;  COM_MTD_STD  get_SingleListTemplate  , :ptr BOOL
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  ConvertNumbersToText  , :ptr VARIANT
;  COM_MTD_STD  RemoveNumbers  , :ptr VARIANT
;  COM_MTD_STD  CountNumberedItems  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  ApplyListTemplateOld  , :ptr ListTemplate,:ptr VARIANT
;  COM_MTD_STD  CanContinuePreviousList  , :ptr ListTemplate,:ptr WdContinue
;  COM_MTD_STD  ApplyListTemplate  , :ptr ListTemplate,:ptr VARIANT,:ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_List textequ <IID {000020992h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Lists, Type=INTERFACE, GUID={00020993-0000-0000-C000-000000000046}
;
;ifndef ListsVtbl
;COM_INTERFACE_BEG Lists, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr List
;COM_INTERFACE_END
;endif
;
;sIID_Lists textequ <IID {000020993h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListGallery, Type=INTERFACE, GUID={00020994-0000-0000-C000-000000000046}
;
;ifndef ListGalleryVtbl
;COM_INTERFACE_BEG ListGallery, IDispatch
;  COM_MTD_STD  get_ListTemplates  , :ptr ptr ListTemplates
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Modified  , :SDWORD,:ptr BOOL
;  COM_MTD_STD  Reset  , :SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_ListGallery textequ <IID {000020994h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ListGalleries, Type=INTERFACE, GUID={00020995-0000-0000-C000-000000000046}
;
;ifndef ListGalleriesVtbl
;COM_INTERFACE_BEG ListGalleries, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :WdListGalleryType,:ptr ptr ListGallery
;COM_INTERFACE_END
;endif
;
;sIID_ListGalleries textequ <IID {000020995h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- KeyBindings, Type=INTERFACE, GUID={00020996-0000-0000-C000-000000000046}
;
;ifndef KeyBindingsVtbl
;COM_INTERFACE_BEG KeyBindings, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Context  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr KeyBinding
;  COM_MTD_STD  Add_  , :WdKeyCategory,:BSTR,:SDWORD,:ptr VARIANT,:ptr VARIANT,:ptr ptr KeyBinding
;  COM_MTD_STD  ClearAll  
;  COM_MTD_STD  Key  , :SDWORD,:ptr VARIANT,:ptr ptr KeyBinding
;COM_INTERFACE_END
;endif
;
;sIID_KeyBindings textequ <IID {000020996h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- KeysBoundTo, Type=INTERFACE, GUID={00020997-0000-0000-C000-000000000046}
;
;ifndef KeysBoundToVtbl
;COM_INTERFACE_BEG KeysBoundTo, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_KeyCategory  , :ptr WdKeyCategory
;  COM_MTD_STD  get_Command  , :ptr BSTR
;  COM_MTD_STD  get_CommandParameter  , :ptr BSTR
;  COM_MTD_STD  get_Context  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr KeyBinding
;  COM_MTD_STD  Key  , :SDWORD,:ptr VARIANT,:ptr ptr KeyBinding
;COM_INTERFACE_END
;endif
;
;sIID_KeysBoundTo textequ <IID {000020997h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- KeyBinding, Type=INTERFACE, GUID={00020998-0000-0000-C000-000000000046}
;
;ifndef KeyBindingVtbl
;COM_INTERFACE_BEG KeyBinding, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Command  , :ptr BSTR
;  COM_MTD_STD  get_KeyString  , :ptr BSTR
;  COM_MTD_STD  get_Protected  , :ptr BOOL
;  COM_MTD_STD  get_KeyCategory  , :ptr WdKeyCategory
;  COM_MTD_STD  get_KeyCode  , :ptr SDWORD
;  COM_MTD_STD  get_KeyCode2  , :ptr SDWORD
;  COM_MTD_STD  get_CommandParameter  , :ptr BSTR
;  COM_MTD_STD  get_Context  , :ptr LPDISPATCH
;  COM_MTD_STD  Clear  
;  COM_MTD_STD  Disable  
;  COM_MTD_STD  Execute  
;  COM_MTD_STD  Rebind  , :WdKeyCategory,:BSTR,:ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_KeyBinding textequ <IID {000020998h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FileConverter, Type=INTERFACE, GUID={00020999-0000-0000-C000-000000000046}
;
;ifndef FileConverterVtbl
;COM_INTERFACE_BEG FileConverter, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_FormatName  , :ptr BSTR
;  COM_MTD_STD  get_ClassName  , :ptr BSTR
;  COM_MTD_STD  get_SaveFormat  , :ptr SDWORD
;  COM_MTD_STD  get_OpenFormat  , :ptr SDWORD
;  COM_MTD_STD  get_CanSave  , :ptr BOOL
;  COM_MTD_STD  get_CanOpen  , :ptr BOOL
;  COM_MTD_STD  get_Path  , :ptr BSTR
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Extensions  , :ptr BSTR
;COM_INTERFACE_END
;endif
;
;sIID_FileConverter textequ <IID {000020999h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FileConverters, Type=INTERFACE, GUID={0002099A-0000-0000-C000-000000000046}
;
;ifndef FileConvertersVtbl
;COM_INTERFACE_BEG FileConverters, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_ConvertMacWordChevrons  , :ptr WdChevronConvertRule
;  COM_MTD_STD  put_ConvertMacWordChevrons  , :WdChevronConvertRule
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr FileConverter
;COM_INTERFACE_END
;endif
;
;sIID_FileConverters textequ <IID {00002099Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- SynonymInfo, Type=INTERFACE, GUID={0002099B-0000-0000-C000-000000000046}
;
;ifndef SynonymInfoVtbl
;COM_INTERFACE_BEG SynonymInfo, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Word  , :ptr BSTR
;  COM_MTD_STD  get_Found  , :ptr BOOL
;  COM_MTD_STD  get_MeaningCount  , :ptr SDWORD
;  COM_MTD_STD  get_MeaningList  , :ptr VARIANT
;  COM_MTD_STD  get_PartOfSpeechList  , :ptr VARIANT
;  COM_MTD_STD  get_SynonymList  , :ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  get_AntonymList  , :ptr VARIANT
;  COM_MTD_STD  get_RelatedExpressionList  , :ptr VARIANT
;  COM_MTD_STD  get_RelatedWordList  , :ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_SynonymInfo textequ <IID {00002099Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Hyperlinks, Type=INTERFACE, GUID={0002099C-0000-0000-C000-000000000046}
;
;ifndef HyperlinksVtbl
;COM_INTERFACE_BEG Hyperlinks, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Hyperlink
;  COM_MTD_STD  _Add  , :LPDISPATCH,:ptr VARIANT,:ptr VARIANT,:ptr ptr Hyperlink
;  COM_MTD_STD  Add_  , :LPDISPATCH,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Hyperlink
;COM_INTERFACE_END
;endif
;
;sIID_Hyperlinks textequ <IID {00002099Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Hyperlink, Type=INTERFACE, GUID={0002099D-0000-0000-C000-000000000046}
;
;ifndef HyperlinkVtbl
;COM_INTERFACE_BEG Hyperlink, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_AddressOld  , :ptr BSTR
;  COM_MTD_STD  get_Type  , :ptr MsoHyperlinkType
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_Shape  , :ptr ptr Shape
;  COM_MTD_STD  get_SubAddressOld  , :ptr BSTR
;  COM_MTD_STD  get_ExtraInfoRequired  , :ptr BOOL
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Follow  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  AddToFavorites  
;  COM_MTD_STD  CreateNewDocument  , :BSTR,:BOOL,:BOOL
;  COM_MTD_STD  get_Address  , :ptr BSTR
;  COM_MTD_STD  put_Address  , :BSTR
;  COM_MTD_STD  get_SubAddress  , :ptr BSTR
;  COM_MTD_STD  put_SubAddress  , :BSTR
;  COM_MTD_STD  get_EmailSubject  , :ptr BSTR
;  COM_MTD_STD  put_EmailSubject  , :BSTR
;  COM_MTD_STD  get_ScreenTip  , :ptr BSTR
;  COM_MTD_STD  put_ScreenTip  , :BSTR
;  COM_MTD_STD  get_TextToDisplay  , :ptr BSTR
;  COM_MTD_STD  put_TextToDisplay  , :BSTR
;  COM_MTD_STD  get_Target  , :ptr BSTR
;  COM_MTD_STD  put_Target  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID_Hyperlink textequ <IID {00002099Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Shapes, Type=INTERFACE, GUID={0002099F-0000-0000-C000-000000000046}
;
;ifndef ShapesVtbl
;COM_INTERFACE_BEG Shapes, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddCallout  , :MsoCalloutType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddConnector  , :MsoConnectorType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  COM_MTD_STD  AddCurve  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddLabel  , :MsoTextOrientation,:REAL4,:REAL4,:REAL4,:REAL4,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddLine  , :REAL4,:REAL4,:REAL4,:REAL4,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddPicture  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddPolyline  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddShape  , :SDWORD,:REAL4,:REAL4,:REAL4,:REAL4,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddTextEffect  , :MsoPresetTextEffect,:BSTR,:BSTR,:REAL4,:MsoTriState,:MsoTriState,:REAL4,:REAL4,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddTextbox  , :MsoTextOrientation,:REAL4,:REAL4,:REAL4,:REAL4,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  BuildFreeform  , :MsoEditingType,:REAL4,:REAL4,:ptr ptr FreeformBuilder
;  COM_MTD_STD  Range  , :ptr VARIANT,:ptr ptr ShapeRange
;  COM_MTD_STD  SelectAll  
;  COM_MTD_STD  AddOLEObject  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  AddOLEControl  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Shape
;COM_INTERFACE_END
;endif
;
;sIID_Shapes textequ <IID {00002099Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ShapeRange, Type=INTERFACE, GUID={000209B5-0000-0000-C000-000000000046}
;
;ifndef ShapeRangeVtbl
;COM_INTERFACE_BEG ShapeRange, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Adjustments  , :ptr ptr Adjustments
;  COM_MTD_STD  get_AutoShapeType  , :ptr MsoAutoShapeType
;  COM_MTD_STD  put_AutoShapeType  , :MsoAutoShapeType
;  COM_MTD_STD  get_Callout  , :ptr ptr CalloutFormat
;  COM_MTD_STD  get_ConnectionSiteCount  , :ptr SDWORD
;  COM_MTD_STD  get_Connector  , :ptr MsoTriState
;  COM_MTD_STD  get_ConnectorFormat  , :ptr ptr ConnectorFormat
;  COM_MTD_STD  get_Fill  , :ptr ptr FillFormat
;  COM_MTD_STD  get_GroupItems  , :ptr ptr GroupShapes
;  COM_MTD_STD  get_Height  , :ptr REAL4
;  COM_MTD_STD  put_Height  , :REAL4
;  COM_MTD_STD  get_HorizontalFlip  , :ptr MsoTriState
;  COM_MTD_STD  get_Left  , :ptr REAL4
;  COM_MTD_STD  put_Left  , :REAL4
;  COM_MTD_STD  get_Line  , :ptr ptr LineFormat
;  COM_MTD_STD  get_LockAspectRatio  , :ptr MsoTriState
;  COM_MTD_STD  put_LockAspectRatio  , :MsoTriState
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  get_Nodes  , :ptr ptr ShapeNodes
;  COM_MTD_STD  get_Rotation  , :ptr REAL4
;  COM_MTD_STD  put_Rotation  , :REAL4
;  COM_MTD_STD  get_PictureFormat  , :ptr ptr PictureFormat
;  COM_MTD_STD  get_Shadow  , :ptr ptr ShadowFormat
;  COM_MTD_STD  get_TextEffect  , :ptr ptr TextEffectFormat
;  COM_MTD_STD  get_TextFrame  , :ptr ptr TextFrame
;  COM_MTD_STD  get_ThreeD  , :ptr ptr ThreeDFormat
;  COM_MTD_STD  get_Top  , :ptr REAL4
;  COM_MTD_STD  put_Top  , :REAL4
;  COM_MTD_STD  get_Type  , :ptr MsoShapeType
;  COM_MTD_STD  get_VerticalFlip  , :ptr MsoTriState
;  COM_MTD_STD  get_Vertices  , :ptr VARIANT
;  COM_MTD_STD  get_Visible  , :ptr MsoTriState
;  COM_MTD_STD  put_Visible  , :MsoTriState
;  COM_MTD_STD  get_Width  , :ptr REAL4
;  COM_MTD_STD  put_Width  , :REAL4
;  COM_MTD_STD  get_ZOrderPosition  , :ptr SDWORD
;  COM_MTD_STD  get_Hyperlink  , :ptr ptr Hyperlink
;  COM_MTD_STD  get_RelativeHorizontalPosition  , :ptr WdRelativeHorizontalPosition
;  COM_MTD_STD  put_RelativeHorizontalPosition  , :WdRelativeHorizontalPosition
;  COM_MTD_STD  get_RelativeVerticalPosition  , :ptr WdRelativeVerticalPosition
;  COM_MTD_STD  put_RelativeVerticalPosition  , :WdRelativeVerticalPosition
;  COM_MTD_STD  get_LockAnchor  , :ptr SDWORD
;  COM_MTD_STD  put_LockAnchor  , :SDWORD
;  COM_MTD_STD  get_WrapFormat  , :ptr ptr WrapFormat
;  COM_MTD_STD  get_Anchor  , :ptr ptr Range
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Shape
;  COM_MTD_STD  Align_  , :MsoAlignCmd,:SDWORD
;  COM_MTD_STD  Apply  
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Distribute  , :MsoDistributeCmd,:SDWORD
;  COM_MTD_STD  Duplicate  , :ptr ptr ShapeRange
;  COM_MTD_STD  Flip  , :MsoFlipCmd
;  COM_MTD_STD  IncrementLeft  , :REAL4
;  COM_MTD_STD  IncrementRotation  , :REAL4
;  COM_MTD_STD  IncrementTop  , :REAL4
;  COM_MTD_STD  Group_  , :ptr ptr Shape
;  COM_MTD_STD  PickUp  
;  COM_MTD_STD  Regroup  , :ptr ptr Shape
;  COM_MTD_STD  RerouteConnections  
;  COM_MTD_STD  ScaleHeight  , :REAL4,:MsoTriState,:MsoScaleFrom
;  COM_MTD_STD  ScaleWidth  , :REAL4,:MsoTriState,:MsoScaleFrom
;  COM_MTD_STD  Select  , :ptr VARIANT
;  COM_MTD_STD  SetShapesDefaultProperties  
;  COM_MTD_STD  Ungroup  , :ptr ptr ShapeRange
;  COM_MTD_STD  ZOrder  , :MsoZOrderCmd
;  COM_MTD_STD  ConvertToFrame  , :ptr ptr Frame
;  COM_MTD_STD  ConvertToInlineShape  , :ptr ptr InlineShape
;  COM_MTD_STD  Activate  
;  COM_MTD_STD  get_AlternativeText  , :ptr BSTR
;  COM_MTD_STD  put_AlternativeText  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID_ShapeRange textequ <IID {0000209B5h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- GroupShapes, Type=INTERFACE, GUID={000209B6-0000-0000-C000-000000000046}
;
;ifndef GroupShapesVtbl
;COM_INTERFACE_BEG GroupShapes, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Shape
;COM_INTERFACE_END
;endif
;
;sIID_GroupShapes textequ <IID {0000209B6h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Shape, Type=INTERFACE, GUID={000209A0-0000-0000-C000-000000000046}
;
;ifndef ShapeVtbl
;COM_INTERFACE_BEG Shape, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Adjustments  , :ptr ptr Adjustments
;  COM_MTD_STD  get_AutoShapeType  , :ptr MsoAutoShapeType
;  COM_MTD_STD  put_AutoShapeType  , :MsoAutoShapeType
;  COM_MTD_STD  get_Callout  , :ptr ptr CalloutFormat
;  COM_MTD_STD  get_ConnectionSiteCount  , :ptr SDWORD
;  COM_MTD_STD  get_Connector  , :ptr MsoTriState
;  COM_MTD_STD  get_ConnectorFormat  , :ptr ptr ConnectorFormat
;  COM_MTD_STD  get_Fill  , :ptr ptr FillFormat
;  COM_MTD_STD  get_GroupItems  , :ptr ptr GroupShapes
;  COM_MTD_STD  get_Height  , :ptr REAL4
;  COM_MTD_STD  put_Height  , :REAL4
;  COM_MTD_STD  get_HorizontalFlip  , :ptr MsoTriState
;  COM_MTD_STD  get_Left  , :ptr REAL4
;  COM_MTD_STD  put_Left  , :REAL4
;  COM_MTD_STD  get_Line  , :ptr ptr LineFormat
;  COM_MTD_STD  get_LockAspectRatio  , :ptr MsoTriState
;  COM_MTD_STD  put_LockAspectRatio  , :MsoTriState
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  put_Name  , :BSTR
;  COM_MTD_STD  get_Nodes  , :ptr ptr ShapeNodes
;  COM_MTD_STD  get_Rotation  , :ptr REAL4
;  COM_MTD_STD  put_Rotation  , :REAL4
;  COM_MTD_STD  get_PictureFormat  , :ptr ptr PictureFormat
;  COM_MTD_STD  get_Shadow  , :ptr ptr ShadowFormat
;  COM_MTD_STD  get_TextEffect  , :ptr ptr TextEffectFormat
;  COM_MTD_STD  get_TextFrame  , :ptr ptr TextFrame
;  COM_MTD_STD  get_ThreeD  , :ptr ptr ThreeDFormat
;  COM_MTD_STD  get_Top  , :ptr REAL4
;  COM_MTD_STD  put_Top  , :REAL4
;  COM_MTD_STD  get_Type  , :ptr MsoShapeType
;  COM_MTD_STD  get_VerticalFlip  , :ptr MsoTriState
;  COM_MTD_STD  get_Vertices  , :ptr VARIANT
;  COM_MTD_STD  get_Visible  , :ptr MsoTriState
;  COM_MTD_STD  put_Visible  , :MsoTriState
;  COM_MTD_STD  get_Width  , :ptr REAL4
;  COM_MTD_STD  put_Width  , :REAL4
;  COM_MTD_STD  get_ZOrderPosition  , :ptr SDWORD
;  COM_MTD_STD  get_Hyperlink  , :ptr ptr Hyperlink
;  COM_MTD_STD  get_RelativeHorizontalPosition  , :ptr WdRelativeHorizontalPosition
;  COM_MTD_STD  put_RelativeHorizontalPosition  , :WdRelativeHorizontalPosition
;  COM_MTD_STD  get_RelativeVerticalPosition  , :ptr WdRelativeVerticalPosition
;  COM_MTD_STD  put_RelativeVerticalPosition  , :WdRelativeVerticalPosition
;  COM_MTD_STD  get_LockAnchor  , :ptr SDWORD
;  COM_MTD_STD  put_LockAnchor  , :SDWORD
;  COM_MTD_STD  get_WrapFormat  , :ptr ptr WrapFormat
;  COM_MTD_STD  get_OLEFormat  , :ptr ptr OLEFormat
;  COM_MTD_STD  get_Anchor  , :ptr ptr Range
;  COM_MTD_STD  get_LinkFormat  , :ptr ptr LinkFormat
;  COM_MTD_STD  Apply  
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Duplicate  , :ptr ptr Shape
;  COM_MTD_STD  Flip  , :MsoFlipCmd
;  COM_MTD_STD  IncrementLeft  , :REAL4
;  COM_MTD_STD  IncrementRotation  , :REAL4
;  COM_MTD_STD  IncrementTop  , :REAL4
;  COM_MTD_STD  PickUp  
;  COM_MTD_STD  RerouteConnections  
;  COM_MTD_STD  ScaleHeight  , :REAL4,:MsoTriState,:MsoScaleFrom
;  COM_MTD_STD  ScaleWidth  , :REAL4,:MsoTriState,:MsoScaleFrom
;  COM_MTD_STD  Select  , :ptr VARIANT
;  COM_MTD_STD  SetShapesDefaultProperties  
;  COM_MTD_STD  Ungroup  , :ptr ptr ShapeRange
;  COM_MTD_STD  ZOrder  , :MsoZOrderCmd
;  COM_MTD_STD  ConvertToInlineShape  , :ptr ptr InlineShape
;  COM_MTD_STD  ConvertToFrame  , :ptr ptr Frame
;  COM_MTD_STD  Activate  
;  COM_MTD_STD  get_AlternativeText  , :ptr BSTR
;  COM_MTD_STD  put_AlternativeText  , :BSTR
;  COM_MTD_STD  get_Script  , :ptr ptr Script
;COM_INTERFACE_END
;endif
;
;sIID_Shape textequ <IID {0000209A0h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TextFrame, Type=INTERFACE, GUID={000209B2-0000-0000-C000-000000000046}
;
;ifndef TextFrameVtbl
;COM_INTERFACE_BEG TextFrame, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr ptr Shape
;  COM_MTD_STD  get_MarginBottom  , :ptr REAL4
;  COM_MTD_STD  put_MarginBottom  , :REAL4
;  COM_MTD_STD  get_MarginLeft  , :ptr REAL4
;  COM_MTD_STD  put_MarginLeft  , :REAL4
;  COM_MTD_STD  get_MarginRight  , :ptr REAL4
;  COM_MTD_STD  put_MarginRight  , :REAL4
;  COM_MTD_STD  get_MarginTop  , :ptr REAL4
;  COM_MTD_STD  put_MarginTop  , :REAL4
;  COM_MTD_STD  get_Orientation  , :ptr MsoTextOrientation
;  COM_MTD_STD  put_Orientation  , :MsoTextOrientation
;  COM_MTD_STD  get_TextRange  , :ptr ptr Range
;  COM_MTD_STD  get_ContainingRange  , :ptr ptr Range
;  COM_MTD_STD  get_Next  , :ptr ptr TextFrame
;  COM_MTD_STD  put_Next  , :ptr TextFrame
;  COM_MTD_STD  get_Previous  , :ptr ptr TextFrame
;  COM_MTD_STD  put_Previous  , :ptr TextFrame
;  COM_MTD_STD  get_Overflowing  , :ptr BOOL
;  COM_MTD_STD  get_HasText  , :ptr SDWORD
;  COM_MTD_STD  BreakForwardLink  
;  COM_MTD_STD  ValidLinkTarget  , :ptr TextFrame,:ptr BOOL
;COM_INTERFACE_END
;endif
;
;sIID_TextFrame textequ <IID {0000209B2h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _LetterContent, Type=INTERFACE, GUID={000209A1-0000-0000-C000-000000000046}
;
;ifndef _LetterContentVtbl
;COM_INTERFACE_BEG _LetterContent, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Duplicate  , :ptr ptr LetterContent
;  COM_MTD_STD  get_DateFormat  , :ptr BSTR
;  COM_MTD_STD  put_DateFormat  , :BSTR
;  COM_MTD_STD  get_IncludeHeaderFooter  , :ptr BOOL
;  COM_MTD_STD  put_IncludeHeaderFooter  , :BOOL
;  COM_MTD_STD  get_PageDesign  , :ptr BSTR
;  COM_MTD_STD  put_PageDesign  , :BSTR
;  COM_MTD_STD  get_LetterStyle  , :ptr WdLetterStyle
;  COM_MTD_STD  put_LetterStyle  , :WdLetterStyle
;  COM_MTD_STD  get_Letterhead  , :ptr BOOL
;  COM_MTD_STD  put_Letterhead  , :BOOL
;  COM_MTD_STD  get_LetterheadLocation  , :ptr WdLetterheadLocation
;  COM_MTD_STD  put_LetterheadLocation  , :WdLetterheadLocation
;  COM_MTD_STD  get_LetterheadSize  , :ptr REAL4
;  COM_MTD_STD  put_LetterheadSize  , :REAL4
;  COM_MTD_STD  get_RecipientName  , :ptr BSTR
;  COM_MTD_STD  put_RecipientName  , :BSTR
;  COM_MTD_STD  get_RecipientAddress  , :ptr BSTR
;  COM_MTD_STD  put_RecipientAddress  , :BSTR
;  COM_MTD_STD  get_Salutation  , :ptr BSTR
;  COM_MTD_STD  put_Salutation  , :BSTR
;  COM_MTD_STD  get_SalutationType  , :ptr WdSalutationType
;  COM_MTD_STD  put_SalutationType  , :WdSalutationType
;  COM_MTD_STD  get_RecipientReference  , :ptr BSTR
;  COM_MTD_STD  put_RecipientReference  , :BSTR
;  COM_MTD_STD  get_MailingInstructions  , :ptr BSTR
;  COM_MTD_STD  put_MailingInstructions  , :BSTR
;  COM_MTD_STD  get_AttentionLine  , :ptr BSTR
;  COM_MTD_STD  put_AttentionLine  , :BSTR
;  COM_MTD_STD  get_Subject  , :ptr BSTR
;  COM_MTD_STD  put_Subject  , :BSTR
;  COM_MTD_STD  get_EnclosureNumber  , :ptr SDWORD
;  COM_MTD_STD  put_EnclosureNumber  , :SDWORD
;  COM_MTD_STD  get_CCList  , :ptr BSTR
;  COM_MTD_STD  put_CCList  , :BSTR
;  COM_MTD_STD  get_ReturnAddress  , :ptr BSTR
;  COM_MTD_STD  put_ReturnAddress  , :BSTR
;  COM_MTD_STD  get_SenderName  , :ptr BSTR
;  COM_MTD_STD  put_SenderName  , :BSTR
;  COM_MTD_STD  get_Closing  , :ptr BSTR
;  COM_MTD_STD  put_Closing  , :BSTR
;  COM_MTD_STD  get_SenderCompany  , :ptr BSTR
;  COM_MTD_STD  put_SenderCompany  , :BSTR
;  COM_MTD_STD  get_SenderJobTitle  , :ptr BSTR
;  COM_MTD_STD  put_SenderJobTitle  , :BSTR
;  COM_MTD_STD  get_SenderInitials  , :ptr BSTR
;  COM_MTD_STD  put_SenderInitials  , :BSTR
;  COM_MTD_STD  get_InfoBlock  , :ptr BOOL
;  COM_MTD_STD  put_InfoBlock  , :BOOL
;  COM_MTD_STD  get_RecipientCode  , :ptr BSTR
;  COM_MTD_STD  put_RecipientCode  , :BSTR
;  COM_MTD_STD  get_RecipientGender  , :ptr WdSalutationGender
;  COM_MTD_STD  put_RecipientGender  , :WdSalutationGender
;  COM_MTD_STD  get_ReturnAddressShortForm  , :ptr BSTR
;  COM_MTD_STD  put_ReturnAddressShortForm  , :BSTR
;  COM_MTD_STD  get_SenderCity  , :ptr BSTR
;  COM_MTD_STD  put_SenderCity  , :BSTR
;  COM_MTD_STD  get_SenderCode  , :ptr BSTR
;  COM_MTD_STD  put_SenderCode  , :BSTR
;  COM_MTD_STD  get_SenderGender  , :ptr WdSalutationGender
;  COM_MTD_STD  put_SenderGender  , :WdSalutationGender
;  COM_MTD_STD  get_SenderReference  , :ptr BSTR
;  COM_MTD_STD  put_SenderReference  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID__LetterContent textequ <IID {0000209A1h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- View, Type=INTERFACE, GUID={000209A5-0000-0000-C000-000000000046}
;
;ifndef ViewVtbl
;COM_INTERFACE_BEG View, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Type  , :ptr WdViewType
;  COM_MTD_STD  put_Type  , :WdViewType
;  COM_MTD_STD  get_FullScreen  , :ptr BOOL
;  COM_MTD_STD  put_FullScreen  , :BOOL
;  COM_MTD_STD  get_Draft  , :ptr BOOL
;  COM_MTD_STD  put_Draft  , :BOOL
;  COM_MTD_STD  get_ShowAll  , :ptr BOOL
;  COM_MTD_STD  put_ShowAll  , :BOOL
;  COM_MTD_STD  get_ShowFieldCodes  , :ptr BOOL
;  COM_MTD_STD  put_ShowFieldCodes  , :BOOL
;  COM_MTD_STD  get_MailMergeDataView  , :ptr BOOL
;  COM_MTD_STD  put_MailMergeDataView  , :BOOL
;  COM_MTD_STD  get_Magnifier  , :ptr BOOL
;  COM_MTD_STD  put_Magnifier  , :BOOL
;  COM_MTD_STD  get_ShowFirstLineOnly  , :ptr BOOL
;  COM_MTD_STD  put_ShowFirstLineOnly  , :BOOL
;  COM_MTD_STD  get_ShowFormat  , :ptr BOOL
;  COM_MTD_STD  put_ShowFormat  , :BOOL
;  COM_MTD_STD  get_Zoom  , :ptr ptr Zoom
;  COM_MTD_STD  get_ShowObjectAnchors  , :ptr BOOL
;  COM_MTD_STD  put_ShowObjectAnchors  , :BOOL
;  COM_MTD_STD  get_ShowTextBoundaries  , :ptr BOOL
;  COM_MTD_STD  put_ShowTextBoundaries  , :BOOL
;  COM_MTD_STD  get_ShowHighlight  , :ptr BOOL
;  COM_MTD_STD  put_ShowHighlight  , :BOOL
;  COM_MTD_STD  get_ShowDrawings  , :ptr BOOL
;  COM_MTD_STD  put_ShowDrawings  , :BOOL
;  COM_MTD_STD  get_ShowTabs  , :ptr BOOL
;  COM_MTD_STD  put_ShowTabs  , :BOOL
;  COM_MTD_STD  get_ShowSpaces  , :ptr BOOL
;  COM_MTD_STD  put_ShowSpaces  , :BOOL
;  COM_MTD_STD  get_ShowParagraphs  , :ptr BOOL
;  COM_MTD_STD  put_ShowParagraphs  , :BOOL
;  COM_MTD_STD  get_ShowHyphens  , :ptr BOOL
;  COM_MTD_STD  put_ShowHyphens  , :BOOL
;  COM_MTD_STD  get_ShowHiddenText  , :ptr BOOL
;  COM_MTD_STD  put_ShowHiddenText  , :BOOL
;  COM_MTD_STD  get_WrapToWindow  , :ptr BOOL
;  COM_MTD_STD  put_WrapToWindow  , :BOOL
;  COM_MTD_STD  get_ShowPicturePlaceHolders  , :ptr BOOL
;  COM_MTD_STD  put_ShowPicturePlaceHolders  , :BOOL
;  COM_MTD_STD  get_ShowBookmarks  , :ptr BOOL
;  COM_MTD_STD  put_ShowBookmarks  , :BOOL
;  COM_MTD_STD  get_FieldShading  , :ptr WdFieldShading
;  COM_MTD_STD  put_FieldShading  , :WdFieldShading
;  COM_MTD_STD  get_ShowAnimation  , :ptr BOOL
;  COM_MTD_STD  put_ShowAnimation  , :BOOL
;  COM_MTD_STD  get_TableGridlines  , :ptr BOOL
;  COM_MTD_STD  put_TableGridlines  , :BOOL
;  COM_MTD_STD  get_EnlargeFontsLessThan  , :ptr SDWORD
;  COM_MTD_STD  put_EnlargeFontsLessThan  , :SDWORD
;  COM_MTD_STD  get_ShowMainTextLayer  , :ptr BOOL
;  COM_MTD_STD  put_ShowMainTextLayer  , :BOOL
;  COM_MTD_STD  get_SeekView  , :ptr WdSeekView
;  COM_MTD_STD  put_SeekView  , :WdSeekView
;  COM_MTD_STD  get_SplitSpecial  , :ptr WdSpecialPane
;  COM_MTD_STD  put_SplitSpecial  , :WdSpecialPane
;  COM_MTD_STD  get_BrowseToWindow  , :ptr SDWORD
;  COM_MTD_STD  put_BrowseToWindow  , :SDWORD
;  COM_MTD_STD  get_ShowOptionalBreaks  , :ptr BOOL
;  COM_MTD_STD  put_ShowOptionalBreaks  , :BOOL
;  COM_MTD_STD  CollapseOutline  , :ptr VARIANT
;  COM_MTD_STD  ExpandOutline  , :ptr VARIANT
;  COM_MTD_STD  ShowAllHeadings  
;  COM_MTD_STD  ShowHeading  , :SDWORD
;  COM_MTD_STD  PreviousHeaderFooter  
;  COM_MTD_STD  NextHeaderFooter  
;COM_INTERFACE_END
;endif
;
;sIID_View textequ <IID {0000209A5h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Zoom, Type=INTERFACE, GUID={000209A6-0000-0000-C000-000000000046}
;
;ifndef ZoomVtbl
;COM_INTERFACE_BEG Zoom, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Percentage  , :ptr SDWORD
;  COM_MTD_STD  put_Percentage  , :SDWORD
;  COM_MTD_STD  get_PageFit  , :ptr WdPageFit
;  COM_MTD_STD  put_PageFit  , :WdPageFit
;  COM_MTD_STD  get_PageRows  , :ptr SDWORD
;  COM_MTD_STD  put_PageRows  , :SDWORD
;  COM_MTD_STD  get_PageColumns  , :ptr SDWORD
;  COM_MTD_STD  put_PageColumns  , :SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_Zoom textequ <IID {0000209A6h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Zooms, Type=INTERFACE, GUID={000209A7-0000-0000-C000-000000000046}
;
;ifndef ZoomsVtbl
;COM_INTERFACE_BEG Zooms, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :WdViewType,:ptr ptr Zoom
;COM_INTERFACE_END
;endif
;
;sIID_Zooms textequ <IID {0000209A7h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- InlineShape, Type=INTERFACE, GUID={000209A8-0000-0000-C000-000000000046}
;
;ifndef InlineShapeVtbl
;COM_INTERFACE_BEG InlineShape, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Borders  , :ptr ptr Borders
;  COM_MTD_STD  put_Borders  , :ptr Borders
;  COM_MTD_STD  get_Range  , :ptr ptr Range
;  COM_MTD_STD  get_LinkFormat  , :ptr ptr LinkFormat
;  COM_MTD_STD  get_Field  , :ptr ptr Field
;  COM_MTD_STD  get_OLEFormat  , :ptr ptr OLEFormat
;  COM_MTD_STD  get_Type  , :ptr WdInlineShapeType
;  COM_MTD_STD  get_Hyperlink  , :ptr ptr Hyperlink
;  COM_MTD_STD  get_Height  , :ptr REAL4
;  COM_MTD_STD  put_Height  , :REAL4
;  COM_MTD_STD  get_Width  , :ptr REAL4
;  COM_MTD_STD  put_Width  , :REAL4
;  COM_MTD_STD  get_ScaleHeight  , :ptr REAL4
;  COM_MTD_STD  put_ScaleHeight  , :REAL4
;  COM_MTD_STD  get_ScaleWidth  , :ptr REAL4
;  COM_MTD_STD  put_ScaleWidth  , :REAL4
;  COM_MTD_STD  get_LockAspectRatio  , :ptr MsoTriState
;  COM_MTD_STD  put_LockAspectRatio  , :MsoTriState
;  COM_MTD_STD  get_Line  , :ptr ptr LineFormat
;  COM_MTD_STD  get_Fill  , :ptr ptr FillFormat
;  COM_MTD_STD  get_PictureFormat  , :ptr ptr PictureFormat
;  COM_MTD_STD  put_PictureFormat  , :ptr PictureFormat
;  COM_MTD_STD  Activate  
;  COM_MTD_STD  Reset  
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Select  
;  COM_MTD_STD  ConvertToShape  , :ptr ptr Shape
;  COM_MTD_STD  get_HorizontalLineFormat  , :ptr ptr HorizontalLineFormat
;  COM_MTD_STD  get_Script  , :ptr ptr Script
;  COM_MTD_STD  get_OWSAnchor  , :ptr SDWORD
;  COM_MTD_STD  get_TextEffect  , :ptr ptr TextEffectFormat
;  COM_MTD_STD  put_TextEffect  , :ptr TextEffectFormat
;  COM_MTD_STD  get_AlternativeText  , :ptr BSTR
;  COM_MTD_STD  put_AlternativeText  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID_InlineShape textequ <IID {0000209A8h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- InlineShapes, Type=INTERFACE, GUID={000209A9-0000-0000-C000-000000000046}
;
;ifndef InlineShapesVtbl
;COM_INTERFACE_BEG InlineShapes, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr InlineShape
;  COM_MTD_STD  AddPicture  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr InlineShape
;  COM_MTD_STD  AddOLEObject  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr InlineShape
;  COM_MTD_STD  AddOLEControl  , :ptr VARIANT,:ptr VARIANT,:ptr ptr InlineShape
;  COM_MTD_STD  New  , :ptr Range,:ptr ptr InlineShape
;  COM_MTD_STD  AddHorizontalLine  , :BSTR,:ptr VARIANT,:ptr ptr InlineShape
;  COM_MTD_STD  AddHorizontalLineStandard  , :ptr VARIANT,:ptr ptr InlineShape
;  COM_MTD_STD  AddPictureBullet  , :BSTR,:ptr VARIANT,:ptr ptr InlineShape
;COM_INTERFACE_END
;endif
;
;sIID_InlineShapes textequ <IID {0000209A9h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- SpellingSuggestions, Type=INTERFACE, GUID={000209AA-0000-0000-C000-000000000046}
;
;ifndef SpellingSuggestionsVtbl
;COM_INTERFACE_BEG SpellingSuggestions, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_SpellingErrorType  , :ptr WdSpellingErrorType
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr SpellingSuggestion
;COM_INTERFACE_END
;endif
;
;sIID_SpellingSuggestions textequ <IID {0000209AAh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- SpellingSuggestion, Type=INTERFACE, GUID={000209AB-0000-0000-C000-000000000046}
;
;ifndef SpellingSuggestionVtbl
;COM_INTERFACE_BEG SpellingSuggestion, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;COM_INTERFACE_END
;endif
;
;sIID_SpellingSuggestion textequ <IID {0000209ABh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Dictionaries, Type=INTERFACE, GUID={000209AC-0000-0000-C000-000000000046}
;
;ifndef DictionariesVtbl
;COM_INTERFACE_BEG Dictionaries, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Maximum  , :ptr SDWORD
;  COM_MTD_STD  get_ActiveCustomDictionary  , :ptr ptr Dictionary
;  COM_MTD_STD  put_ActiveCustomDictionary  , :ptr Dictionary
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Dictionary
;  COM_MTD_STD  Add_  , :BSTR,:ptr ptr Dictionary
;  COM_MTD_STD  ClearAll  
;COM_INTERFACE_END
;endif
;
;sIID_Dictionaries textequ <IID {0000209ACh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HangulHanjaConversionDictionaries, Type=INTERFACE, GUID={000209E0-0000-0000-C000-000000000046}
;
;ifndef HangulHanjaConversionDictionariesVtbl
;COM_INTERFACE_BEG HangulHanjaConversionDictionaries, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Maximum  , :ptr SDWORD
;  COM_MTD_STD  get_ActiveCustomDictionary  , :ptr ptr Dictionary
;  COM_MTD_STD  put_ActiveCustomDictionary  , :ptr Dictionary
;  COM_MTD_STD  get_BuiltinDictionary  , :ptr ptr Dictionary
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Dictionary
;  COM_MTD_STD  Add_  , :BSTR,:ptr ptr Dictionary
;  COM_MTD_STD  ClearAll  
;COM_INTERFACE_END
;endif
;
;sIID_HangulHanjaConversionDictionaries textequ <IID {0000209E0h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Dictionary, Type=INTERFACE, GUID={000209AD-0000-0000-C000-000000000046}
;
;ifndef DictionaryVtbl
;COM_INTERFACE_BEG Dictionary, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Path  , :ptr BSTR
;  COM_MTD_STD  get_LanguageID  , :ptr WdLanguageID
;  COM_MTD_STD  put_LanguageID  , :WdLanguageID
;  COM_MTD_STD  get_ReadOnly  , :ptr BOOL
;  COM_MTD_STD  get_Type  , :ptr WdDictionaryType
;  COM_MTD_STD  get_LanguageSpecific  , :ptr BOOL
;  COM_MTD_STD  put_LanguageSpecific  , :BOOL
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_Dictionary textequ <IID {0000209ADh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ReadabilityStatistics, Type=INTERFACE, GUID={000209AE-0000-0000-C000-000000000046}
;
;ifndef ReadabilityStatisticsVtbl
;COM_INTERFACE_BEG ReadabilityStatistics, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr ReadabilityStatistic
;COM_INTERFACE_END
;endif
;
;sIID_ReadabilityStatistics textequ <IID {0000209AEh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ReadabilityStatistic, Type=INTERFACE, GUID={000209AF-0000-0000-C000-000000000046}
;
;ifndef ReadabilityStatisticVtbl
;COM_INTERFACE_BEG ReadabilityStatistic, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Value  , :ptr REAL4
;COM_INTERFACE_END
;endif
;
;sIID_ReadabilityStatistic textequ <IID {0000209AFh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Versions, Type=INTERFACE, GUID={000209B3-0000-0000-C000-000000000046}
;
;ifndef VersionsVtbl
;COM_INTERFACE_BEG Versions, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_AutoVersion  , :ptr WdAutoVersions
;  COM_MTD_STD  put_AutoVersion  , :WdAutoVersions
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Version
;  COM_MTD_STD  Save  , :ptr VARIANT
;COM_INTERFACE_END
;endif
;
;sIID_Versions textequ <IID {0000209B3h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Version, Type=INTERFACE, GUID={000209B4-0000-0000-C000-000000000046}
;
;ifndef VersionVtbl
;COM_INTERFACE_BEG Version, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_SavedBy  , :ptr BSTR
;  COM_MTD_STD  get_Comment  , :ptr BSTR
;  COM_MTD_STD  get_Date  , :ptr DATE
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  OpenOld  
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  Open  , :ptr ptr Document
;COM_INTERFACE_END
;endif
;
;sIID_Version textequ <IID {0000209B4h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Options, Type=INTERFACE, GUID={000209B7-0000-0000-C000-000000000046}
;
;ifndef OptionsVtbl
;COM_INTERFACE_BEG Options, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_AllowAccentedUppercase  , :ptr BOOL
;  COM_MTD_STD  put_AllowAccentedUppercase  , :BOOL
;  COM_MTD_STD  get_WPHelp  , :ptr BOOL
;  COM_MTD_STD  put_WPHelp  , :BOOL
;  COM_MTD_STD  get_WPDocNavKeys  , :ptr BOOL
;  COM_MTD_STD  put_WPDocNavKeys  , :BOOL
;  COM_MTD_STD  get_Pagination  , :ptr BOOL
;  COM_MTD_STD  put_Pagination  , :BOOL
;  COM_MTD_STD  get_BlueScreen  , :ptr BOOL
;  COM_MTD_STD  put_BlueScreen  , :BOOL
;  COM_MTD_STD  get_EnableSound  , :ptr BOOL
;  COM_MTD_STD  put_EnableSound  , :BOOL
;  COM_MTD_STD  get_ConfirmConversions  , :ptr BOOL
;  COM_MTD_STD  put_ConfirmConversions  , :BOOL
;  COM_MTD_STD  get_UpdateLinksAtOpen  , :ptr BOOL
;  COM_MTD_STD  put_UpdateLinksAtOpen  , :BOOL
;  COM_MTD_STD  get_SendMailAttach  , :ptr BOOL
;  COM_MTD_STD  put_SendMailAttach  , :BOOL
;  COM_MTD_STD  get_MeasurementUnit  , :ptr WdMeasurementUnits
;  COM_MTD_STD  put_MeasurementUnit  , :WdMeasurementUnits
;  COM_MTD_STD  get_ButtonFieldClicks  , :ptr SDWORD
;  COM_MTD_STD  put_ButtonFieldClicks  , :SDWORD
;  COM_MTD_STD  get_ShortMenuNames  , :ptr BOOL
;  COM_MTD_STD  put_ShortMenuNames  , :BOOL
;  COM_MTD_STD  get_RTFInClipboard  , :ptr BOOL
;  COM_MTD_STD  put_RTFInClipboard  , :BOOL
;  COM_MTD_STD  get_UpdateFieldsAtPrint  , :ptr BOOL
;  COM_MTD_STD  put_UpdateFieldsAtPrint  , :BOOL
;  COM_MTD_STD  get_PrintProperties  , :ptr BOOL
;  COM_MTD_STD  put_PrintProperties  , :BOOL
;  COM_MTD_STD  get_PrintFieldCodes  , :ptr BOOL
;  COM_MTD_STD  put_PrintFieldCodes  , :BOOL
;  COM_MTD_STD  get_PrintComments  , :ptr BOOL
;  COM_MTD_STD  put_PrintComments  , :BOOL
;  COM_MTD_STD  get_PrintHiddenText  , :ptr BOOL
;  COM_MTD_STD  put_PrintHiddenText  , :BOOL
;  COM_MTD_STD  get_EnvelopeFeederInstalled  , :ptr BOOL
;  COM_MTD_STD  get_UpdateLinksAtPrint  , :ptr BOOL
;  COM_MTD_STD  put_UpdateLinksAtPrint  , :BOOL
;  COM_MTD_STD  get_PrintBackground  , :ptr BOOL
;  COM_MTD_STD  put_PrintBackground  , :BOOL
;  COM_MTD_STD  get_PrintDrawingObjects  , :ptr BOOL
;  COM_MTD_STD  put_PrintDrawingObjects  , :BOOL
;  COM_MTD_STD  get_DefaultTray  , :ptr BSTR
;  COM_MTD_STD  put_DefaultTray  , :BSTR
;  COM_MTD_STD  get_DefaultTrayID  , :ptr SDWORD
;  COM_MTD_STD  put_DefaultTrayID  , :SDWORD
;  COM_MTD_STD  get_CreateBackup  , :ptr BOOL
;  COM_MTD_STD  put_CreateBackup  , :BOOL
;  COM_MTD_STD  get_AllowFastSave  , :ptr BOOL
;  COM_MTD_STD  put_AllowFastSave  , :BOOL
;  COM_MTD_STD  get_SavePropertiesPrompt  , :ptr BOOL
;  COM_MTD_STD  put_SavePropertiesPrompt  , :BOOL
;  COM_MTD_STD  get_SaveNormalPrompt  , :ptr BOOL
;  COM_MTD_STD  put_SaveNormalPrompt  , :BOOL
;  COM_MTD_STD  get_SaveInterval  , :ptr SDWORD
;  COM_MTD_STD  put_SaveInterval  , :SDWORD
;  COM_MTD_STD  get_BackgroundSave  , :ptr BOOL
;  COM_MTD_STD  put_BackgroundSave  , :BOOL
;  COM_MTD_STD  get_InsertedTextMark  , :ptr WdInsertedTextMark
;  COM_MTD_STD  put_InsertedTextMark  , :WdInsertedTextMark
;  COM_MTD_STD  get_DeletedTextMark  , :ptr WdDeletedTextMark
;  COM_MTD_STD  put_DeletedTextMark  , :WdDeletedTextMark
;  COM_MTD_STD  get_RevisedLinesMark  , :ptr WdRevisedLinesMark
;  COM_MTD_STD  put_RevisedLinesMark  , :WdRevisedLinesMark
;  COM_MTD_STD  get_InsertedTextColor  , :ptr WdColorIndex
;  COM_MTD_STD  put_InsertedTextColor  , :WdColorIndex
;  COM_MTD_STD  get_DeletedTextColor  , :ptr WdColorIndex
;  COM_MTD_STD  put_DeletedTextColor  , :WdColorIndex
;  COM_MTD_STD  get_RevisedLinesColor  , :ptr WdColorIndex
;  COM_MTD_STD  put_RevisedLinesColor  , :WdColorIndex
;  COM_MTD_STD  get_DefaultFilePath  , :WdDefaultFilePath,:ptr BSTR
;  COM_MTD_STD  put_DefaultFilePath  , :WdDefaultFilePath,:BSTR
;  COM_MTD_STD  get_Overtype  , :ptr BOOL
;  COM_MTD_STD  put_Overtype  , :BOOL
;  COM_MTD_STD  get_ReplaceSelection  , :ptr BOOL
;  COM_MTD_STD  put_ReplaceSelection  , :BOOL
;  COM_MTD_STD  get_AllowDragAndDrop  , :ptr BOOL
;  COM_MTD_STD  put_AllowDragAndDrop  , :BOOL
;  COM_MTD_STD  get_AutoWordSelection  , :ptr BOOL
;  COM_MTD_STD  put_AutoWordSelection  , :BOOL
;  COM_MTD_STD  get_INSKeyForPaste  , :ptr BOOL
;  COM_MTD_STD  put_INSKeyForPaste  , :BOOL
;  COM_MTD_STD  get_SmartCutPaste  , :ptr BOOL
;  COM_MTD_STD  put_SmartCutPaste  , :BOOL
;  COM_MTD_STD  get_TabIndentKey  , :ptr BOOL
;  COM_MTD_STD  put_TabIndentKey  , :BOOL
;  COM_MTD_STD  get_PictureEditor  , :ptr BSTR
;  COM_MTD_STD  put_PictureEditor  , :BSTR
;  COM_MTD_STD  get_AnimateScreenMovements  , :ptr BOOL
;  COM_MTD_STD  put_AnimateScreenMovements  , :BOOL
;  COM_MTD_STD  get_VirusProtection  , :ptr BOOL
;  COM_MTD_STD  put_VirusProtection  , :BOOL
;  COM_MTD_STD  get_RevisedPropertiesMark  , :ptr WdRevisedPropertiesMark
;  COM_MTD_STD  put_RevisedPropertiesMark  , :WdRevisedPropertiesMark
;  COM_MTD_STD  get_RevisedPropertiesColor  , :ptr WdColorIndex
;  COM_MTD_STD  put_RevisedPropertiesColor  , :WdColorIndex
;  COM_MTD_STD  get_SnapToGrid  , :ptr BOOL
;  COM_MTD_STD  put_SnapToGrid  , :BOOL
;  COM_MTD_STD  get_SnapToShapes  , :ptr BOOL
;  COM_MTD_STD  put_SnapToShapes  , :BOOL
;  COM_MTD_STD  get_GridDistanceHorizontal  , :ptr REAL4
;  COM_MTD_STD  put_GridDistanceHorizontal  , :REAL4
;  COM_MTD_STD  get_GridDistanceVertical  , :ptr REAL4
;  COM_MTD_STD  put_GridDistanceVertical  , :REAL4
;  COM_MTD_STD  get_GridOriginHorizontal  , :ptr REAL4
;  COM_MTD_STD  put_GridOriginHorizontal  , :REAL4
;  COM_MTD_STD  get_GridOriginVertical  , :ptr REAL4
;  COM_MTD_STD  put_GridOriginVertical  , :REAL4
;  COM_MTD_STD  get_InlineConversion  , :ptr BOOL
;  COM_MTD_STD  put_InlineConversion  , :BOOL
;  COM_MTD_STD  get_IMEAutomaticControl  , :ptr BOOL
;  COM_MTD_STD  put_IMEAutomaticControl  , :BOOL
;  COM_MTD_STD  get_AutoFormatApplyHeadings  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatApplyHeadings  , :BOOL
;  COM_MTD_STD  get_AutoFormatApplyLists  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatApplyLists  , :BOOL
;  COM_MTD_STD  get_AutoFormatApplyBulletedLists  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatApplyBulletedLists  , :BOOL
;  COM_MTD_STD  get_AutoFormatApplyOtherParas  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatApplyOtherParas  , :BOOL
;  COM_MTD_STD  get_AutoFormatReplaceQuotes  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatReplaceQuotes  , :BOOL
;  COM_MTD_STD  get_AutoFormatReplaceSymbols  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatReplaceSymbols  , :BOOL
;  COM_MTD_STD  get_AutoFormatReplaceOrdinals  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatReplaceOrdinals  , :BOOL
;  COM_MTD_STD  get_AutoFormatReplaceFractions  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatReplaceFractions  , :BOOL
;  COM_MTD_STD  get_AutoFormatReplacePlainTextEmphasis  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatReplacePlainTextEmphasis  , :BOOL
;  COM_MTD_STD  get_AutoFormatPreserveStyles  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatPreserveStyles  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeApplyHeadings  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeApplyHeadings  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeApplyBorders  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeApplyBorders  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeApplyBulletedLists  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeApplyBulletedLists  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeApplyNumberedLists  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeApplyNumberedLists  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeReplaceQuotes  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeReplaceQuotes  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeReplaceSymbols  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeReplaceSymbols  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeReplaceOrdinals  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeReplaceOrdinals  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeReplaceFractions  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeReplaceFractions  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeReplacePlainTextEmphasis  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeReplacePlainTextEmphasis  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeFormatListItemBeginning  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeFormatListItemBeginning  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeDefineStyles  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeDefineStyles  , :BOOL
;  COM_MTD_STD  get_AutoFormatPlainTextWordMail  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatPlainTextWordMail  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeReplaceHyperlinks  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeReplaceHyperlinks  , :BOOL
;  COM_MTD_STD  get_AutoFormatReplaceHyperlinks  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatReplaceHyperlinks  , :BOOL
;  COM_MTD_STD  get_DefaultHighlightColorIndex  , :ptr WdColorIndex
;  COM_MTD_STD  put_DefaultHighlightColorIndex  , :WdColorIndex
;  COM_MTD_STD  get_DefaultBorderLineStyle  , :ptr WdLineStyle
;  COM_MTD_STD  put_DefaultBorderLineStyle  , :WdLineStyle
;  COM_MTD_STD  get_CheckSpellingAsYouType  , :ptr BOOL
;  COM_MTD_STD  put_CheckSpellingAsYouType  , :BOOL
;  COM_MTD_STD  get_CheckGrammarAsYouType  , :ptr BOOL
;  COM_MTD_STD  put_CheckGrammarAsYouType  , :BOOL
;  COM_MTD_STD  get_IgnoreInternetAndFileAddresses  , :ptr BOOL
;  COM_MTD_STD  put_IgnoreInternetAndFileAddresses  , :BOOL
;  COM_MTD_STD  get_ShowReadabilityStatistics  , :ptr BOOL
;  COM_MTD_STD  put_ShowReadabilityStatistics  , :BOOL
;  COM_MTD_STD  get_IgnoreUppercase  , :ptr BOOL
;  COM_MTD_STD  put_IgnoreUppercase  , :BOOL
;  COM_MTD_STD  get_IgnoreMixedDigits  , :ptr BOOL
;  COM_MTD_STD  put_IgnoreMixedDigits  , :BOOL
;  COM_MTD_STD  get_SuggestFromMainDictionaryOnly  , :ptr BOOL
;  COM_MTD_STD  put_SuggestFromMainDictionaryOnly  , :BOOL
;  COM_MTD_STD  get_SuggestSpellingCorrections  , :ptr BOOL
;  COM_MTD_STD  put_SuggestSpellingCorrections  , :BOOL
;  COM_MTD_STD  get_DefaultBorderLineWidth  , :ptr WdLineWidth
;  COM_MTD_STD  put_DefaultBorderLineWidth  , :WdLineWidth
;  COM_MTD_STD  get_CheckGrammarWithSpelling  , :ptr BOOL
;  COM_MTD_STD  put_CheckGrammarWithSpelling  , :BOOL
;  COM_MTD_STD  get_DefaultOpenFormat  , :ptr WdOpenFormat
;  COM_MTD_STD  put_DefaultOpenFormat  , :WdOpenFormat
;  COM_MTD_STD  get_PrintDraft  , :ptr BOOL
;  COM_MTD_STD  put_PrintDraft  , :BOOL
;  COM_MTD_STD  get_PrintReverse  , :ptr BOOL
;  COM_MTD_STD  put_PrintReverse  , :BOOL
;  COM_MTD_STD  get_MapPaperSize  , :ptr BOOL
;  COM_MTD_STD  put_MapPaperSize  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeApplyTables  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeApplyTables  , :BOOL
;  COM_MTD_STD  get_AutoFormatApplyFirstIndents  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatApplyFirstIndents  , :BOOL
;  COM_MTD_STD  get_AutoFormatMatchParentheses  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatMatchParentheses  , :BOOL
;  COM_MTD_STD  get_AutoFormatReplaceFarEastDashes  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatReplaceFarEastDashes  , :BOOL
;  COM_MTD_STD  get_AutoFormatDeleteAutoSpaces  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatDeleteAutoSpaces  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeApplyFirstIndents  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeApplyFirstIndents  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeApplyDates  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeApplyDates  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeApplyClosings  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeApplyClosings  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeMatchParentheses  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeMatchParentheses  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeReplaceFarEastDashes  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeReplaceFarEastDashes  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeDeleteAutoSpaces  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeDeleteAutoSpaces  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeInsertClosings  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeInsertClosings  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeAutoLetterWizard  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeAutoLetterWizard  , :BOOL
;  COM_MTD_STD  get_AutoFormatAsYouTypeInsertOvers  , :ptr BOOL
;  COM_MTD_STD  put_AutoFormatAsYouTypeInsertOvers  , :BOOL
;  COM_MTD_STD  get_DisplayGridLines  , :ptr BOOL
;  COM_MTD_STD  put_DisplayGridLines  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyCase  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyCase  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyByte  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyByte  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyHiragana  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyHiragana  , :BOOL
;  COM_MTD_STD  get_MatchFuzzySmallKana  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzySmallKana  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyDash  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyDash  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyIterationMark  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyIterationMark  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyKanji  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyKanji  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyOldKana  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyOldKana  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyProlongedSoundMark  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyProlongedSoundMark  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyDZ  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyDZ  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyBV  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyBV  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyTC  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyTC  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyHF  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyHF  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyZJ  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyZJ  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyAY  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyAY  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyKiKu  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyKiKu  , :BOOL
;  COM_MTD_STD  get_MatchFuzzyPunctuation  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzyPunctuation  , :BOOL
;  COM_MTD_STD  get_MatchFuzzySpace  , :ptr BOOL
;  COM_MTD_STD  put_MatchFuzzySpace  , :BOOL
;  COM_MTD_STD  get_ApplyFarEastFontsToAscii  , :ptr BOOL
;  COM_MTD_STD  put_ApplyFarEastFontsToAscii  , :BOOL
;  COM_MTD_STD  get_ConvertHighAnsiToFarEast  , :ptr BOOL
;  COM_MTD_STD  put_ConvertHighAnsiToFarEast  , :BOOL
;  COM_MTD_STD  get_PrintOddPagesInAscendingOrder  , :ptr BOOL
;  COM_MTD_STD  put_PrintOddPagesInAscendingOrder  , :BOOL
;  COM_MTD_STD  get_PrintEvenPagesInAscendingOrder  , :ptr BOOL
;  COM_MTD_STD  put_PrintEvenPagesInAscendingOrder  , :BOOL
;  COM_MTD_STD  get_DefaultBorderColorIndex  , :ptr WdColorIndex
;  COM_MTD_STD  put_DefaultBorderColorIndex  , :WdColorIndex
;  COM_MTD_STD  get_EnableMisusedWordsDictionary  , :ptr BOOL
;  COM_MTD_STD  put_EnableMisusedWordsDictionary  , :BOOL
;  COM_MTD_STD  get_AllowCombinedAuxiliaryForms  , :ptr BOOL
;  COM_MTD_STD  put_AllowCombinedAuxiliaryForms  , :BOOL
;  COM_MTD_STD  get_HangulHanjaFastConversion  , :ptr BOOL
;  COM_MTD_STD  put_HangulHanjaFastConversion  , :BOOL
;  COM_MTD_STD  get_CheckHangulEndings  , :ptr BOOL
;  COM_MTD_STD  put_CheckHangulEndings  , :BOOL
;  COM_MTD_STD  get_EnableHangulHanjaRecentOrdering  , :ptr BOOL
;  COM_MTD_STD  put_EnableHangulHanjaRecentOrdering  , :BOOL
;  COM_MTD_STD  get_MultipleWordConversionsMode  , :ptr WdMultipleWordConversionsMode
;  COM_MTD_STD  put_MultipleWordConversionsMode  , :WdMultipleWordConversionsMode
;  COM_MTD_STD  SetWPHelpOptions  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  get_DefaultBorderColor  , :ptr WdColor
;  COM_MTD_STD  put_DefaultBorderColor  , :WdColor
;  COM_MTD_STD  get_AllowPixelUnits  , :ptr BOOL
;  COM_MTD_STD  put_AllowPixelUnits  , :BOOL
;  COM_MTD_STD  get_UseCharacterUnit  , :ptr BOOL
;  COM_MTD_STD  put_UseCharacterUnit  , :BOOL
;  COM_MTD_STD  get_AllowCompoundNounProcessing  , :ptr BOOL
;  COM_MTD_STD  put_AllowCompoundNounProcessing  , :BOOL
;  COM_MTD_STD  get_AutoKeyboardSwitching  , :ptr BOOL
;  COM_MTD_STD  put_AutoKeyboardSwitching  , :BOOL
;  COM_MTD_STD  get_DocumentViewDirection  , :ptr WdDocumentViewDirection
;  COM_MTD_STD  put_DocumentViewDirection  , :WdDocumentViewDirection
;  COM_MTD_STD  get_ArabicNumeral  , :ptr WdArabicNumeral
;  COM_MTD_STD  put_ArabicNumeral  , :WdArabicNumeral
;  COM_MTD_STD  get_MonthNames  , :ptr WdMonthNames
;  COM_MTD_STD  put_MonthNames  , :WdMonthNames
;  COM_MTD_STD  get_CursorMovement  , :ptr WdCursorMovement
;  COM_MTD_STD  put_CursorMovement  , :WdCursorMovement
;  COM_MTD_STD  get_VisualSelection  , :ptr WdVisualSelection
;  COM_MTD_STD  put_VisualSelection  , :WdVisualSelection
;  COM_MTD_STD  get_ShowDiacritics  , :ptr BOOL
;  COM_MTD_STD  put_ShowDiacritics  , :BOOL
;  COM_MTD_STD  get_ShowControlCharacters  , :ptr BOOL
;  COM_MTD_STD  put_ShowControlCharacters  , :BOOL
;  COM_MTD_STD  get_AddControlCharacters  , :ptr BOOL
;  COM_MTD_STD  put_AddControlCharacters  , :BOOL
;  COM_MTD_STD  get_AddBiDirectionalMarksWhenSavingTextFile  , :ptr BOOL
;  COM_MTD_STD  put_AddBiDirectionalMarksWhenSavingTextFile  , :BOOL
;  COM_MTD_STD  get_StrictInitialAlefHamza  , :ptr BOOL
;  COM_MTD_STD  put_StrictInitialAlefHamza  , :BOOL
;  COM_MTD_STD  get_StrictFinalYaa  , :ptr BOOL
;  COM_MTD_STD  put_StrictFinalYaa  , :BOOL
;  COM_MTD_STD  get_HebrewMode  , :ptr WdHebSpellStart
;  COM_MTD_STD  put_HebrewMode  , :WdHebSpellStart
;  COM_MTD_STD  get_ArabicMode  , :ptr WdAraSpeller
;  COM_MTD_STD  put_ArabicMode  , :WdAraSpeller
;  COM_MTD_STD  get_AllowClickAndTypeMouse  , :ptr BOOL
;  COM_MTD_STD  put_AllowClickAndTypeMouse  , :BOOL
;  COM_MTD_STD  get_UseGermanSpellingReform  , :ptr BOOL
;  COM_MTD_STD  put_UseGermanSpellingReform  , :BOOL
;  COM_MTD_STD  get_InterpretHighAnsi  , :ptr WdHighAnsiText
;  COM_MTD_STD  put_InterpretHighAnsi  , :WdHighAnsiText
;  COM_MTD_STD  get_AddHebDoubleQuote  , :ptr BOOL
;  COM_MTD_STD  put_AddHebDoubleQuote  , :BOOL
;  COM_MTD_STD  get_UseDiffDiacColor  , :ptr BOOL
;  COM_MTD_STD  put_UseDiffDiacColor  , :BOOL
;  COM_MTD_STD  get_DiacriticColorVal  , :ptr WdColor
;  COM_MTD_STD  put_DiacriticColorVal  , :WdColor
;  COM_MTD_STD  get_OptimizeForWord97byDefault  , :ptr BOOL
;  COM_MTD_STD  put_OptimizeForWord97byDefault  , :BOOL
;COM_INTERFACE_END
;endif
;
;sIID_Options textequ <IID {0000209B7h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MailMessage, Type=INTERFACE, GUID={000209BA-0000-0000-C000-000000000046}
;
;ifndef MailMessageVtbl
;COM_INTERFACE_BEG MailMessage, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  CheckName  
;  COM_MTD_STD  Delete  
;  COM_MTD_STD  DisplayMoveDialog  
;  COM_MTD_STD  DisplayProperties  
;  COM_MTD_STD  DisplaySelectNamesDialog  
;  COM_MTD_STD  Forward  
;  COM_MTD_STD  GoToNext  
;  COM_MTD_STD  GoToPrevious  
;  COM_MTD_STD  Reply  
;  COM_MTD_STD  ReplyAll  
;  COM_MTD_STD  ToggleHeader  
;COM_INTERFACE_END
;endif
;
;sIID_MailMessage textequ <IID {0000209BAh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ProofreadingErrors, Type=INTERFACE, GUID={000209BB-0000-0000-C000-000000000046}
;
;ifndef ProofreadingErrorsVtbl
;COM_INTERFACE_BEG ProofreadingErrors, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Type  , :ptr WdProofreadingErrorType
;  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Range
;COM_INTERFACE_END
;endif
;
;sIID_ProofreadingErrors textequ <IID {0000209BBh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Mailer, Type=INTERFACE, GUID={000209BD-0000-0000-C000-000000000046}
;
;ifndef MailerVtbl
;COM_INTERFACE_BEG Mailer, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_BCCRecipients  , :ptr VARIANT
;  COM_MTD_STD  put_BCCRecipients  , :ptr VARIANT
;  COM_MTD_STD  get_CCRecipients  , :ptr VARIANT
;  COM_MTD_STD  put_CCRecipients  , :ptr VARIANT
;  COM_MTD_STD  get_Recipients  , :ptr VARIANT
;  COM_MTD_STD  put_Recipients  , :ptr VARIANT
;  COM_MTD_STD  get_Enclosures  , :ptr VARIANT
;  COM_MTD_STD  put_Enclosures  , :ptr VARIANT
;  COM_MTD_STD  get_Sender  , :ptr BSTR
;  COM_MTD_STD  get_SendDateTime  , :ptr DATE
;  COM_MTD_STD  get_Received  , :ptr BOOL
;  COM_MTD_STD  get_Subject  , :ptr BSTR
;  COM_MTD_STD  put_Subject  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID_Mailer textequ <IID {0000209BDh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- WrapFormat, Type=INTERFACE, GUID={000209C3-0000-0000-C000-000000000046}
;
;ifndef WrapFormatVtbl
;COM_INTERFACE_BEG WrapFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Type  , :ptr WdWrapType
;  COM_MTD_STD  put_Type  , :WdWrapType
;  COM_MTD_STD  get_Side  , :ptr WdWrapSideType
;  COM_MTD_STD  put_Side  , :WdWrapSideType
;  COM_MTD_STD  get_DistanceTop  , :ptr REAL4
;  COM_MTD_STD  put_DistanceTop  , :REAL4
;  COM_MTD_STD  get_DistanceBottom  , :ptr REAL4
;  COM_MTD_STD  put_DistanceBottom  , :REAL4
;  COM_MTD_STD  get_DistanceLeft  , :ptr REAL4
;  COM_MTD_STD  put_DistanceLeft  , :REAL4
;  COM_MTD_STD  get_DistanceRight  , :ptr REAL4
;  COM_MTD_STD  put_DistanceRight  , :REAL4
;  COM_MTD_STD  get_AllowOverlap  , :ptr SDWORD
;  COM_MTD_STD  put_AllowOverlap  , :SDWORD
;COM_INTERFACE_END
;endif
;
;sIID_WrapFormat textequ <IID {0000209C3h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HangulAndAlphabetExceptions, Type=INTERFACE, GUID={000209D1-0000-0000-C000-000000000046}
;
;ifndef HangulAndAlphabetExceptionsVtbl
;COM_INTERFACE_BEG HangulAndAlphabetExceptions, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr HangulAndAlphabetException
;  COM_MTD_STD  Add_  , :BSTR,:ptr ptr HangulAndAlphabetException
;COM_INTERFACE_END
;endif
;
;sIID_HangulAndAlphabetExceptions textequ <IID {0000209D1h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HangulAndAlphabetException, Type=INTERFACE, GUID={000209D2-0000-0000-C000-000000000046}
;
;ifndef HangulAndAlphabetExceptionVtbl
;COM_INTERFACE_BEG HangulAndAlphabetException, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Index  , :ptr SDWORD
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  Delete  
;COM_INTERFACE_END
;endif
;
;sIID_HangulAndAlphabetException textequ <IID {0000209D2h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Adjustments, Type=INTERFACE, GUID={000209C4-0000-0000-C000-000000000046}
;
;ifndef AdjustmentsVtbl
;COM_INTERFACE_BEG Adjustments, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Item  , :SDWORD,:ptr REAL4
;  COM_MTD_STD  put_Item  , :SDWORD,:REAL4
;COM_INTERFACE_END
;endif
;
;sIID_Adjustments textequ <IID {0000209C4h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CalloutFormat, Type=INTERFACE, GUID={000209C5-0000-0000-C000-000000000046}
;
;ifndef CalloutFormatVtbl
;COM_INTERFACE_BEG CalloutFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Accent  , :ptr MsoTriState
;  COM_MTD_STD  put_Accent  , :MsoTriState
;  COM_MTD_STD  get_Angle  , :ptr MsoCalloutAngleType
;  COM_MTD_STD  put_Angle  , :MsoCalloutAngleType
;  COM_MTD_STD  get_AutoAttach  , :ptr MsoTriState
;  COM_MTD_STD  put_AutoAttach  , :MsoTriState
;  COM_MTD_STD  get_AutoLength  , :ptr MsoTriState
;  COM_MTD_STD  get_Border  , :ptr MsoTriState
;  COM_MTD_STD  put_Border  , :MsoTriState
;  COM_MTD_STD  get_Drop  , :ptr REAL4
;  COM_MTD_STD  get_DropType  , :ptr MsoCalloutDropType
;  COM_MTD_STD  get_Gap  , :ptr REAL4
;  COM_MTD_STD  put_Gap  , :REAL4
;  COM_MTD_STD  get_Length  , :ptr REAL4
;  COM_MTD_STD  get_Type  , :ptr MsoCalloutType
;  COM_MTD_STD  put_Type  , :MsoCalloutType
;  COM_MTD_STD  AutomaticLength  
;  COM_MTD_STD  CustomDrop  , :REAL4
;  COM_MTD_STD  CustomLength  , :REAL4
;  COM_MTD_STD  PresetDrop  , :MsoCalloutDropType
;COM_INTERFACE_END
;endif
;
;sIID_CalloutFormat textequ <IID {0000209C5h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ColorFormat, Type=INTERFACE, GUID={000209C6-0000-0000-C000-000000000046}
;
;ifndef ColorFormatVtbl
;COM_INTERFACE_BEG ColorFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_RGB  , :ptr SDWORD
;  COM_MTD_STD  put_RGB  , :SDWORD
;  COM_MTD_STD  get_SchemeColor  , :ptr SDWORD
;  COM_MTD_STD  put_SchemeColor  , :SDWORD
;  COM_MTD_STD  get_Type  , :ptr MsoColorType
;COM_INTERFACE_END
;endif
;
;sIID_ColorFormat textequ <IID {0000209C6h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ConnectorFormat, Type=INTERFACE, GUID={000209C7-0000-0000-C000-000000000046}
;
;ifndef ConnectorFormatVtbl
;COM_INTERFACE_BEG ConnectorFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_BeginConnected  , :ptr MsoTriState
;  COM_MTD_STD  get_BeginConnectedShape  , :ptr ptr Shape
;  COM_MTD_STD  get_BeginConnectionSite  , :ptr SDWORD
;  COM_MTD_STD  get_EndConnected  , :ptr MsoTriState
;  COM_MTD_STD  get_EndConnectedShape  , :ptr ptr Shape
;  COM_MTD_STD  get_EndConnectionSite  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Type  , :ptr MsoConnectorType
;  COM_MTD_STD  put_Type  , :MsoConnectorType
;  COM_MTD_STD  BeginConnect  , :ptr ptr Shape,:SDWORD
;  COM_MTD_STD  BeginDisconnect  
;  COM_MTD_STD  EndConnect  , :ptr ptr Shape,:SDWORD
;  COM_MTD_STD  EndDisconnect  
;COM_INTERFACE_END
;endif
;
;sIID_ConnectorFormat textequ <IID {0000209C7h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FillFormat, Type=INTERFACE, GUID={000209C8-0000-0000-C000-000000000046}
;
;ifndef FillFormatVtbl
;COM_INTERFACE_BEG FillFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_BackColor  , :ptr ptr ColorFormat
;  COM_MTD_STD  get_ForeColor  , :ptr ptr ColorFormat
;  COM_MTD_STD  get_GradientColorType  , :ptr MsoGradientColorType
;  COM_MTD_STD  get_GradientDegree  , :ptr REAL4
;  COM_MTD_STD  get_GradientStyle  , :ptr MsoGradientStyle
;  COM_MTD_STD  get_GradientVariant  , :ptr SDWORD
;  COM_MTD_STD  get_Pattern  , :ptr MsoPatternType
;  COM_MTD_STD  get_PresetGradientType  , :ptr MsoPresetGradientType
;  COM_MTD_STD  get_PresetTexture  , :ptr MsoPresetTexture
;  COM_MTD_STD  get_TextureName  , :ptr BSTR
;  COM_MTD_STD  get_TextureType  , :ptr MsoTextureType
;  COM_MTD_STD  get_Transparency  , :ptr REAL4
;  COM_MTD_STD  put_Transparency  , :REAL4
;  COM_MTD_STD  get_Type  , :ptr MsoFillType
;  COM_MTD_STD  get_Visible  , :ptr MsoTriState
;  COM_MTD_STD  put_Visible  , :MsoTriState
;  COM_MTD_STD  Background  
;  COM_MTD_STD  OneColorGradient  , :MsoGradientStyle,:SDWORD,:REAL4
;  COM_MTD_STD  Patterned  , :MsoPatternType
;  COM_MTD_STD  PresetGradient  , :MsoGradientStyle,:SDWORD,:MsoPresetGradientType
;  COM_MTD_STD  PresetTextured  , :MsoPresetTexture
;  COM_MTD_STD  Solid  
;  COM_MTD_STD  TwoColorGradient  , :MsoGradientStyle,:SDWORD
;  COM_MTD_STD  UserPicture  , :BSTR
;  COM_MTD_STD  UserTextured  , :BSTR
;COM_INTERFACE_END
;endif
;
;sIID_FillFormat textequ <IID {0000209C8h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FreeformBuilder, Type=INTERFACE, GUID={000209C9-0000-0000-C000-000000000046}
;
;ifndef FreeformBuilderVtbl
;COM_INTERFACE_BEG FreeformBuilder, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  AddNodes  , :MsoSegmentType,:MsoEditingType,:REAL4,:REAL4,:REAL4,:REAL4,:REAL4,:REAL4
;  COM_MTD_STD  ConvertToShape  , :ptr VARIANT,:ptr ptr Shape
;COM_INTERFACE_END
;endif
;
;sIID_FreeformBuilder textequ <IID {0000209C9h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- LineFormat, Type=INTERFACE, GUID={000209CA-0000-0000-C000-000000000046}
;
;ifndef LineFormatVtbl
;COM_INTERFACE_BEG LineFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_BackColor  , :ptr ptr ColorFormat
;  COM_MTD_STD  get_BeginArrowheadLength  , :ptr MsoArrowheadLength
;  COM_MTD_STD  put_BeginArrowheadLength  , :MsoArrowheadLength
;  COM_MTD_STD  get_BeginArrowheadStyle  , :ptr MsoArrowheadStyle
;  COM_MTD_STD  put_BeginArrowheadStyle  , :MsoArrowheadStyle
;  COM_MTD_STD  get_BeginArrowheadWidth  , :ptr MsoArrowheadWidth
;  COM_MTD_STD  put_BeginArrowheadWidth  , :MsoArrowheadWidth
;  COM_MTD_STD  get_DashStyle  , :ptr MsoLineDashStyle
;  COM_MTD_STD  put_DashStyle  , :MsoLineDashStyle
;  COM_MTD_STD  get_EndArrowheadLength  , :ptr MsoArrowheadLength
;  COM_MTD_STD  put_EndArrowheadLength  , :MsoArrowheadLength
;  COM_MTD_STD  get_EndArrowheadStyle  , :ptr MsoArrowheadStyle
;  COM_MTD_STD  put_EndArrowheadStyle  , :MsoArrowheadStyle
;  COM_MTD_STD  get_EndArrowheadWidth  , :ptr MsoArrowheadWidth
;  COM_MTD_STD  put_EndArrowheadWidth  , :MsoArrowheadWidth
;  COM_MTD_STD  get_ForeColor  , :ptr ptr ColorFormat
;  COM_MTD_STD  get_Pattern  , :ptr MsoPatternType
;  COM_MTD_STD  put_Pattern  , :MsoPatternType
;  COM_MTD_STD  get_Style  , :ptr MsoLineStyle
;  COM_MTD_STD  put_Style  , :MsoLineStyle
;  COM_MTD_STD  get_Transparency  , :ptr REAL4
;  COM_MTD_STD  put_Transparency  , :REAL4
;  COM_MTD_STD  get_Visible  , :ptr MsoTriState
;  COM_MTD_STD  put_Visible  , :MsoTriState
;  COM_MTD_STD  get_Weight  , :ptr REAL4
;  COM_MTD_STD  put_Weight  , :REAL4
;COM_INTERFACE_END
;endif
;
;sIID_LineFormat textequ <IID {0000209CAh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- PictureFormat, Type=INTERFACE, GUID={000209CB-0000-0000-C000-000000000046}
;
;ifndef PictureFormatVtbl
;COM_INTERFACE_BEG PictureFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Brightness  , :ptr REAL4
;  COM_MTD_STD  put_Brightness  , :REAL4
;  COM_MTD_STD  get_ColorType  , :ptr MsoPictureColorType
;  COM_MTD_STD  put_ColorType  , :MsoPictureColorType
;  COM_MTD_STD  get_Contrast  , :ptr REAL4
;  COM_MTD_STD  put_Contrast  , :REAL4
;  COM_MTD_STD  get_CropBottom  , :ptr REAL4
;  COM_MTD_STD  put_CropBottom  , :REAL4
;  COM_MTD_STD  get_CropLeft  , :ptr REAL4
;  COM_MTD_STD  put_CropLeft  , :REAL4
;  COM_MTD_STD  get_CropRight  , :ptr REAL4
;  COM_MTD_STD  put_CropRight  , :REAL4
;  COM_MTD_STD  get_CropTop  , :ptr REAL4
;  COM_MTD_STD  put_CropTop  , :REAL4
;  COM_MTD_STD  get_TransparencyColor  , :ptr SDWORD
;  COM_MTD_STD  put_TransparencyColor  , :SDWORD
;  COM_MTD_STD  get_TransparentBackground  , :ptr MsoTriState
;  COM_MTD_STD  put_TransparentBackground  , :MsoTriState
;  COM_MTD_STD  IncrementBrightness  , :REAL4
;  COM_MTD_STD  IncrementContrast  , :REAL4
;COM_INTERFACE_END
;endif
;
;sIID_PictureFormat textequ <IID {0000209CBh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ShadowFormat, Type=INTERFACE, GUID={000209CC-0000-0000-C000-000000000046}
;
;ifndef ShadowFormatVtbl
;COM_INTERFACE_BEG ShadowFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_ForeColor  , :ptr ptr ColorFormat
;  COM_MTD_STD  get_Obscured  , :ptr MsoTriState
;  COM_MTD_STD  put_Obscured  , :MsoTriState
;  COM_MTD_STD  get_OffsetX  , :ptr REAL4
;  COM_MTD_STD  put_OffsetX  , :REAL4
;  COM_MTD_STD  get_OffsetY  , :ptr REAL4
;  COM_MTD_STD  put_OffsetY  , :REAL4
;  COM_MTD_STD  get_Transparency  , :ptr REAL4
;  COM_MTD_STD  put_Transparency  , :REAL4
;  COM_MTD_STD  get_Type  , :ptr MsoShadowType
;  COM_MTD_STD  put_Type  , :MsoShadowType
;  COM_MTD_STD  get_Visible  , :ptr MsoTriState
;  COM_MTD_STD  put_Visible  , :MsoTriState
;  COM_MTD_STD  IncrementOffsetX  , :REAL4
;  COM_MTD_STD  IncrementOffsetY  , :REAL4
;COM_INTERFACE_END
;endif
;
;sIID_ShadowFormat textequ <IID {0000209CCh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ShapeNode, Type=INTERFACE, GUID={000209CD-0000-0000-C000-000000000046}
;
;ifndef ShapeNodeVtbl
;COM_INTERFACE_BEG ShapeNode, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_EditingType  , :ptr MsoEditingType
;  COM_MTD_STD  get_Points  , :ptr VARIANT
;  COM_MTD_STD  get_SegmentType  , :ptr MsoSegmentType
;COM_INTERFACE_END
;endif
;
;sIID_ShapeNode textequ <IID {0000209CDh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ShapeNodes, Type=INTERFACE, GUID={000209CE-0000-0000-C000-000000000046}
;
;ifndef ShapeNodesVtbl
;COM_INTERFACE_BEG ShapeNodes, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  Delete  , :SDWORD
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr ShapeNode
;  COM_MTD_STD  SetEditingType  , :SDWORD,:MsoEditingType
;  COM_MTD_STD  SetPosition  , :SDWORD,:REAL4,:REAL4
;  COM_MTD_STD  SetSegmentType  , :SDWORD,:MsoSegmentType
;  COM_MTD_STD  Insert  , :SDWORD,:MsoSegmentType,:MsoEditingType,:REAL4,:REAL4,:REAL4,:REAL4,:REAL4,:REAL4
;COM_INTERFACE_END
;endif
;
;sIID_ShapeNodes textequ <IID {0000209CEh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TextEffectFormat, Type=INTERFACE, GUID={000209CF-0000-0000-C000-000000000046}
;
;ifndef TextEffectFormatVtbl
;COM_INTERFACE_BEG TextEffectFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Alignment  , :ptr MsoTextEffectAlignment
;  COM_MTD_STD  put_Alignment  , :MsoTextEffectAlignment
;  COM_MTD_STD  get_FontBold  , :ptr MsoTriState
;  COM_MTD_STD  put_FontBold  , :MsoTriState
;  COM_MTD_STD  get_FontItalic  , :ptr MsoTriState
;  COM_MTD_STD  put_FontItalic  , :MsoTriState
;  COM_MTD_STD  get_FontName  , :ptr BSTR
;  COM_MTD_STD  put_FontName  , :BSTR
;  COM_MTD_STD  get_FontSize  , :ptr REAL4
;  COM_MTD_STD  put_FontSize  , :REAL4
;  COM_MTD_STD  get_KernedPairs  , :ptr MsoTriState
;  COM_MTD_STD  put_KernedPairs  , :MsoTriState
;  COM_MTD_STD  get_NormalizedHeight  , :ptr MsoTriState
;  COM_MTD_STD  put_NormalizedHeight  , :MsoTriState
;  COM_MTD_STD  get_PresetShape  , :ptr MsoPresetTextEffectShape
;  COM_MTD_STD  put_PresetShape  , :MsoPresetTextEffectShape
;  COM_MTD_STD  get_PresetTextEffect  , :ptr MsoPresetTextEffect
;  COM_MTD_STD  put_PresetTextEffect  , :MsoPresetTextEffect
;  COM_MTD_STD  get_RotatedChars  , :ptr MsoTriState
;  COM_MTD_STD  put_RotatedChars  , :MsoTriState
;  COM_MTD_STD  get_Text  , :ptr BSTR
;  COM_MTD_STD  put_Text  , :BSTR
;  COM_MTD_STD  get_Tracking  , :ptr REAL4
;  COM_MTD_STD  put_Tracking  , :REAL4
;  COM_MTD_STD  ToggleVerticalText  
;COM_INTERFACE_END
;endif
;
;sIID_TextEffectFormat textequ <IID {0000209CFh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ThreeDFormat, Type=INTERFACE, GUID={000209D0-0000-0000-C000-000000000046}
;
;ifndef ThreeDFormatVtbl
;COM_INTERFACE_BEG ThreeDFormat, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Depth  , :ptr REAL4
;  COM_MTD_STD  put_Depth  , :REAL4
;  COM_MTD_STD  get_ExtrusionColor  , :ptr ptr ColorFormat
;  COM_MTD_STD  get_ExtrusionColorType  , :ptr MsoExtrusionColorType
;  COM_MTD_STD  put_ExtrusionColorType  , :MsoExtrusionColorType
;  COM_MTD_STD  get_Perspective  , :ptr MsoTriState
;  COM_MTD_STD  put_Perspective  , :MsoTriState
;  COM_MTD_STD  get_PresetExtrusionDirection  , :ptr MsoPresetExtrusionDirection
;  COM_MTD_STD  get_PresetLightingDirection  , :ptr MsoPresetLightingDirection
;  COM_MTD_STD  put_PresetLightingDirection  , :MsoPresetLightingDirection
;  COM_MTD_STD  get_PresetLightingSoftness  , :ptr MsoPresetLightingSoftness
;  COM_MTD_STD  put_PresetLightingSoftness  , :MsoPresetLightingSoftness
;  COM_MTD_STD  get_PresetMaterial  , :ptr MsoPresetMaterial
;  COM_MTD_STD  put_PresetMaterial  , :MsoPresetMaterial
;  COM_MTD_STD  get_PresetThreeDFormat  , :ptr MsoPresetThreeDFormat
;  COM_MTD_STD  get_RotationX  , :ptr REAL4
;  COM_MTD_STD  put_RotationX  , :REAL4
;  COM_MTD_STD  get_RotationY  , :ptr REAL4
;  COM_MTD_STD  put_RotationY  , :REAL4
;  COM_MTD_STD  get_Visible  , :ptr MsoTriState
;  COM_MTD_STD  put_Visible  , :MsoTriState
;  COM_MTD_STD  IncrementRotationX  , :REAL4
;  COM_MTD_STD  IncrementRotationY  , :REAL4
;  COM_MTD_STD  ResetRotation  
;  COM_MTD_STD  SetExtrusionDirection  , :MsoPresetExtrusionDirection
;  COM_MTD_STD  SetThreeDFormat  , :MsoPresetThreeDFormat
;COM_INTERFACE_END
;endif
;
;sIID_ThreeDFormat textequ <IID {0000209D0h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- IApplicationEvents, Type=INTERFACE, GUID={000209F7-0001-0000-C000-000000000046}
;
;ifndef IApplicationEventsVtbl
;COM_INTERFACE_BEG IApplicationEvents, IDispatch
;  COM_MTD_STD  Startup  
;  COM_MTD_STD  Quit  
;  COM_MTD_STD  DocumentChange  
;COM_INTERFACE_END
;endif
;
;sIID_IApplicationEvents textequ <IID {0000209F7h,00001h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- IApplicationEvents2, Type=INTERFACE, GUID={000209FE-0001-0000-C000-000000000046}
;
;ifndef IApplicationEvents2Vtbl
;COM_INTERFACE_BEG IApplicationEvents2, IDispatch
;  COM_MTD_STD  Startup  
;  COM_MTD_STD  Quit  
;  COM_MTD_STD  DocumentChange  
;  COM_MTD_STD  DocumentOpen  , :ptr Document
;  COM_MTD_STD  DocumentBeforeClose  , :ptr Document,:ptr BOOL
;  COM_MTD_STD  DocumentBeforePrint  , :ptr Document,:ptr BOOL
;  COM_MTD_STD  DocumentBeforeSave  , :ptr Document,:ptr BOOL,:ptr BOOL
;  COM_MTD_STD  NewDocument  , :ptr Document
;  COM_MTD_STD  WindowActivate  , :ptr Document,:ptr Window
;  COM_MTD_STD  WindowDeactivate  , :ptr Document,:ptr Window
;  COM_MTD_STD  WindowSelectionChange  , :ptr Selection
;  COM_MTD_STD  WindowBeforeRightClick  , :ptr Selection,:ptr BOOL
;  COM_MTD_STD  WindowBeforeDoubleClick  , :ptr Selection,:ptr BOOL
;COM_INTERFACE_END
;endif
;
;sIID_IApplicationEvents2 textequ <IID {0000209FEh,00001h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;--- _Application, Type=INTERFACE, GUID={00020970-0000-0000-C000-000000000046}

ifndef _ApplicationVtbl
COM_INTERFACE_BEG _Application, IDispatch, 00020970-0000-0000-C000-000000000046
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  get_Documents  , :ptr ptr Documents
  COM_MTD_STD  get_Windows  , :ptr ptr Windows
  COM_MTD_STD  get_ActiveDocument  , :ptr ptr Document
  COM_MTD_STD  get_ActiveWindow  , :ptr ptr Window
  COM_MTD_STD  get_Selection  , :ptr ptr Selection
  COM_MTD_STD  get_WordBasic  , :ptr LPDISPATCH
  COM_MTD_STD  get_RecentFiles  , :ptr ptr RecentFiles
  COM_MTD_STD  get_NormalTemplate  , :ptr ptr Template
  COM_MTD_STD  get_System  , :ptr ptr System
  COM_MTD_STD  get_AutoCorrect  , :ptr ptr AutoCorrect
  COM_MTD_STD  get_FontNames  , :ptr ptr FontNames
  COM_MTD_STD  get_LandscapeFontNames  , :ptr ptr FontNames
  COM_MTD_STD  get_PortraitFontNames  , :ptr ptr FontNames
  COM_MTD_STD  get_Languages  , :ptr ptr Languages
  COM_MTD_STD  get_Assistant  , :ptr ptr Assistant
  COM_MTD_STD  get_Browser  , :ptr ptr Browser
  COM_MTD_STD  get_FileConverters  , :ptr ptr FileConverters
  COM_MTD_STD  get_MailingLabel  , :ptr ptr MailingLabel
  COM_MTD_STD  get_Dialogs  , :ptr ptr Dialogs
  COM_MTD_STD  get_CaptionLabels  , :ptr ptr CaptionLabels
  COM_MTD_STD  get_AutoCaptions  , :ptr ptr AutoCaptions
  COM_MTD_STD  get_AddIns  , :ptr ptr AddIns
  COM_MTD_STD  get_Visible  , :ptr BOOL
  COM_MTD_STD  put_Visible  , :BOOL
  COM_MTD_STD  get_Version  , :ptr BSTR
  COM_MTD_STD  get_ScreenUpdating  , :ptr BOOL
  COM_MTD_STD  put_ScreenUpdating  , :BOOL
  COM_MTD_STD  get_PrintPreview  , :ptr BOOL
  COM_MTD_STD  put_PrintPreview  , :BOOL
  COM_MTD_STD  get_Tasks  , :ptr ptr Tasks
  COM_MTD_STD  get_DisplayStatusBar  , :ptr BOOL
  COM_MTD_STD  put_DisplayStatusBar  , :BOOL
  COM_MTD_STD  get_SpecialMode  , :ptr BOOL
  COM_MTD_STD  get_UsableWidth  , :ptr SDWORD
  COM_MTD_STD  get_UsableHeight  , :ptr SDWORD
  COM_MTD_STD  get_MathCoprocessorAvailable  , :ptr BOOL
  COM_MTD_STD  get_MouseAvailable  , :ptr BOOL
  COM_MTD_STD  get_International  , :WdInternationalIndex,:ptr VARIANT
  COM_MTD_STD  get_Build  , :ptr BSTR
  COM_MTD_STD  get_CapsLock  , :ptr BOOL
  COM_MTD_STD  get_NumLock  , :ptr BOOL
  COM_MTD_STD  get_UserName  , :ptr BSTR
  COM_MTD_STD  put_UserName  , :BSTR
  COM_MTD_STD  get_UserInitials  , :ptr BSTR
  COM_MTD_STD  put_UserInitials  , :BSTR
  COM_MTD_STD  get_UserAddress  , :ptr BSTR
  COM_MTD_STD  put_UserAddress  , :BSTR
  COM_MTD_STD  get_MacroContainer  , :ptr LPDISPATCH
  COM_MTD_STD  get_DisplayRecentFiles  , :ptr BOOL
  COM_MTD_STD  put_DisplayRecentFiles  , :BOOL
  COM_MTD_STD  get_CommandBars  , :ptr ptr CommandBars
  COM_MTD_STD  get_SynonymInfo  , :BSTR,:ptr VARIANT,:ptr ptr SynonymInfo
  COM_MTD_STD  get_VBE  , :ptr ptr VBE
  COM_MTD_STD  get_DefaultSaveFormat  , :ptr BSTR
  COM_MTD_STD  put_DefaultSaveFormat  , :BSTR
  COM_MTD_STD  get_ListGalleries  , :ptr ptr ListGalleries
  COM_MTD_STD  get_ActivePrinter  , :ptr BSTR
  COM_MTD_STD  put_ActivePrinter  , :BSTR
  COM_MTD_STD  get_Templates  , :ptr ptr Templates
  COM_MTD_STD  get_CustomizationContext  , :ptr LPDISPATCH
  COM_MTD_STD  put_CustomizationContext  , :LPDISPATCH
  COM_MTD_STD  get_KeyBindings  , :ptr ptr KeyBindings
  COM_MTD_STD  get_KeysBoundTo  , :WdKeyCategory,:BSTR,:ptr VARIANT,:ptr ptr KeysBoundTo
  COM_MTD_STD  get_FindKey  , :SDWORD,:ptr VARIANT,:ptr ptr KeyBinding
  COM_MTD_STD  get_Caption  , :ptr BSTR
  COM_MTD_STD  put_Caption  , :BSTR
  COM_MTD_STD  get_Path  , :ptr BSTR
  COM_MTD_STD  get_DisplayScrollBars  , :ptr BOOL
  COM_MTD_STD  put_DisplayScrollBars  , :BOOL
  COM_MTD_STD  get_StartupPath  , :ptr BSTR
  COM_MTD_STD  put_StartupPath  , :BSTR
  COM_MTD_STD  get_BackgroundSavingStatus  , :ptr SDWORD
  COM_MTD_STD  get_BackgroundPrintingStatus  , :ptr SDWORD
  COM_MTD_STD  get_Left  , :ptr SDWORD
  COM_MTD_STD  put_Left  , :SDWORD
  COM_MTD_STD  get_Top  , :ptr SDWORD
  COM_MTD_STD  put_Top  , :SDWORD
  COM_MTD_STD  get_Width  , :ptr SDWORD
  COM_MTD_STD  put_Width  , :SDWORD
  COM_MTD_STD  get_Height  , :ptr SDWORD
  COM_MTD_STD  put_Height  , :SDWORD
  COM_MTD_STD  get_WindowState  , :ptr WdWindowState
  COM_MTD_STD  put_WindowState  , :WdWindowState
  COM_MTD_STD  get_DisplayAutoCompleteTips  , :ptr BOOL
  COM_MTD_STD  put_DisplayAutoCompleteTips  , :BOOL
  COM_MTD_STD  get_Options  , :ptr ptr Options
  COM_MTD_STD  get_DisplayAlerts  , :ptr WdAlertLevel
  COM_MTD_STD  put_DisplayAlerts  , :WdAlertLevel
  COM_MTD_STD  get_CustomDictionaries  , :ptr ptr Dictionaries
  COM_MTD_STD  get_PathSeparator  , :ptr BSTR
  COM_MTD_STD  put_StatusBar  , :BSTR
  COM_MTD_STD  get_MAPIAvailable  , :ptr BOOL
  COM_MTD_STD  get_DisplayScreenTips  , :ptr BOOL
  COM_MTD_STD  put_DisplayScreenTips  , :BOOL
  COM_MTD_STD  get_EnableCancelKey  , :ptr WdEnableCancelKey
  COM_MTD_STD  put_EnableCancelKey  , :WdEnableCancelKey
  COM_MTD_STD  get_UserControl  , :ptr BOOL
  COM_MTD_STD  get_FileSearch  , :ptr ptr FileSearch
  COM_MTD_STD  get_MailSystem  , :ptr WdMailSystem
  COM_MTD_STD  get_DefaultTableSeparator  , :ptr BSTR
  COM_MTD_STD  put_DefaultTableSeparator  , :BSTR
  COM_MTD_STD  get_ShowVisualBasicEditor  , :ptr BOOL
  COM_MTD_STD  put_ShowVisualBasicEditor  , :BOOL
  COM_MTD_STD  get_BrowseExtraFileTypes  , :ptr BSTR
  COM_MTD_STD  put_BrowseExtraFileTypes  , :BSTR
  COM_MTD_STD  get_IsObjectValid  , :LPDISPATCH,:ptr BOOL
  COM_MTD_STD  get_HangulHanjaDictionaries  , :ptr ptr HangulHanjaConversionDictionaries
  COM_MTD_STD  get_MailMessage  , :ptr ptr MailMessage
  COM_MTD_STD  get_FocusInMailHeader  , :ptr BOOL
  COM_MTD_STD  Quit  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  ScreenRefresh  
  COM_MTD_STD  PrintOutOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  LookupNameProperties  , :BSTR
  COM_MTD_STD  SubstituteFont  , :BSTR,:BSTR
  COM_MTD_STD  Repeat_  , :ptr VARIANT,:ptr BOOL
  COM_MTD_STD  DDEExecute  , :SDWORD,:BSTR
  COM_MTD_STD  DDEInitiate  , :BSTR,:BSTR,:ptr SDWORD
  COM_MTD_STD  DDEPoke  , :SDWORD,:BSTR,:BSTR
  COM_MTD_STD  DDERequest  , :SDWORD,:BSTR,:ptr BSTR
  COM_MTD_STD  DDETerminate  , :SDWORD
  COM_MTD_STD  DDETerminateAll  
  COM_MTD_STD  BuildKeyCode  , :WdKey,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  KeyString  , :SDWORD,:ptr VARIANT,:ptr BSTR
  COM_MTD_STD  OrganizerCopy  , :BSTR,:BSTR,:BSTR,:WdOrganizerObject
  COM_MTD_STD  OrganizerDelete  , :BSTR,:BSTR,:WdOrganizerObject
  COM_MTD_STD  OrganizerRename  , :BSTR,:BSTR,:BSTR,:WdOrganizerObject
  COM_MTD_STD  AddAddress  , :ptr SAFEARRAY,:ptr SAFEARRAY
  COM_MTD_STD  GetAddress  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr BSTR
  COM_MTD_STD  CheckGrammar  , :BSTR,:ptr BOOL
  COM_MTD_STD  CheckSpelling  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr BOOL
  COM_MTD_STD  ResetIgnoreAll  
;  COM_MTD_STD  GetSpellingSuggestions  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr SpellingSuggestions
  COM_MTD_STD  GoBack  
  COM_MTD_STD  Help  , :ptr VARIANT
  COM_MTD_STD  AutomaticChange  
  COM_MTD_STD  ShowMe  
  COM_MTD_STD  HelpTool  
  COM_MTD_STD  NewWindow  , :ptr ptr Window
  COM_MTD_STD  ListCommands  , :BOOL
  COM_MTD_STD  ShowClipboard  
  COM_MTD_STD  OnTime  , :ptr VARIANT,:BSTR,:ptr VARIANT
  COM_MTD_STD  NextLetter  
  COM_MTD_STD  MountVolume  , :BSTR,:BSTR,:BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr SWORD
  COM_MTD_STD  CleanString  , :BSTR,:ptr BSTR
  COM_MTD_STD  SendFax  
  COM_MTD_STD  ChangeFileOpenDirectory  , :BSTR
  COM_MTD_STD  RunOld  , :BSTR
  COM_MTD_STD  GoForward  
  COM_MTD_STD  Move  , :SDWORD,:SDWORD
  COM_MTD_STD  Resize  , :SDWORD,:SDWORD
  COM_MTD_STD  InchesToPoints  , :REAL4,:ptr REAL4
  COM_MTD_STD  CentimetersToPoints  , :REAL4,:ptr REAL4
  COM_MTD_STD  MillimetersToPoints  , :REAL4,:ptr REAL4
  COM_MTD_STD  PicasToPoints  , :REAL4,:ptr REAL4
  COM_MTD_STD  LinesToPoints  , :REAL4,:ptr REAL4
  COM_MTD_STD  PointsToInches  , :REAL4,:ptr REAL4
  COM_MTD_STD  PointsToCentimeters  , :REAL4,:ptr REAL4
  COM_MTD_STD  PointsToMillimeters  , :REAL4,:ptr REAL4
  COM_MTD_STD  PointsToPicas  , :REAL4,:ptr REAL4
  COM_MTD_STD  PointsToLines  , :REAL4,:ptr REAL4
  COM_MTD_STD  Activate  
  COM_MTD_STD  PointsToPixels  , :REAL4,:ptr VARIANT,:ptr REAL4
  COM_MTD_STD  PixelsToPoints  , :REAL4,:ptr VARIANT,:ptr REAL4
  COM_MTD_STD  KeyboardLatin  
  COM_MTD_STD  KeyboardBidi  
  COM_MTD_STD  ToggleKeyboard  
  COM_MTD_STD  Keyboard  , :SDWORD,:ptr SDWORD
  COM_MTD_STD  ProductCode  , :ptr BSTR
  COM_MTD_STD  DefaultWebOptions  , :ptr ptr DefaultWebOptions
  COM_MTD_STD  DiscussionSupport  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SetDefaultTheme  , :BSTR,:WdDocumentMedium
  COM_MTD_STD  GetDefaultTheme  , :WdDocumentMedium,:ptr BSTR
  COM_MTD_STD  get_EmailOptions  , :ptr ptr EmailOptions
  COM_MTD_STD  get_Language  , :ptr MsoLanguageID
  COM_MTD_STD  get_COMAddIns  , :ptr ptr COMAddIns
  COM_MTD_STD  get_CheckLanguage  , :ptr BOOL
  COM_MTD_STD  put_CheckLanguage  , :BOOL
  COM_MTD_STD  get_LanguageSettings  , :ptr ptr LanguageSettings
  COM_MTD_STD  get_Dummy1  , :ptr BOOL
  COM_MTD_STD  get_AnswerWizard  , :ptr ptr AnswerWizard
  COM_MTD_STD  get_FeatureInstall  , :ptr MsoFeatureInstall
  COM_MTD_STD  put_FeatureInstall  , :MsoFeatureInstall
;  COM_MTD_STD  PrintOut  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;+++   COM_MTD_STD  Run  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  Run  , :DWORD
COM_INTERFACE_END
endif

sIID__Application textequ <IID {000020970h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _Global, Type=INTERFACE, GUID={000209B9-0000-0000-C000-000000000046}
;
;ifndef _GlobalVtbl
;COM_INTERFACE_BEG _Global, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_Documents  , :ptr ptr Documents
;  COM_MTD_STD  get_Windows  , :ptr ptr Windows
;  COM_MTD_STD  get_ActiveDocument  , :ptr ptr Document
;  COM_MTD_STD  get_ActiveWindow  , :ptr ptr Window
;  COM_MTD_STD  get_Selection  , :ptr ptr Selection
;  COM_MTD_STD  get_WordBasic  , :ptr LPDISPATCH
;  COM_MTD_STD  get_PrintPreview  , :ptr BOOL
;  COM_MTD_STD  put_PrintPreview  , :BOOL
;  COM_MTD_STD  get_RecentFiles  , :ptr ptr RecentFiles
;  COM_MTD_STD  get_NormalTemplate  , :ptr ptr Template
;  COM_MTD_STD  get_System  , :ptr ptr System
;  COM_MTD_STD  get_AutoCorrect  , :ptr ptr AutoCorrect
;  COM_MTD_STD  get_FontNames  , :ptr ptr FontNames
;  COM_MTD_STD  get_LandscapeFontNames  , :ptr ptr FontNames
;  COM_MTD_STD  get_PortraitFontNames  , :ptr ptr FontNames
;  COM_MTD_STD  get_Languages  , :ptr ptr Languages
;  COM_MTD_STD  get_Assistant  , :ptr ptr Assistant
;  COM_MTD_STD  get_FileConverters  , :ptr ptr FileConverters
;  COM_MTD_STD  get_Dialogs  , :ptr ptr Dialogs
;  COM_MTD_STD  get_CaptionLabels  , :ptr ptr CaptionLabels
;  COM_MTD_STD  get_AutoCaptions  , :ptr ptr AutoCaptions
;  COM_MTD_STD  get_AddIns  , :ptr ptr AddIns
;  COM_MTD_STD  get_Tasks  , :ptr ptr Tasks
;  COM_MTD_STD  get_MacroContainer  , :ptr LPDISPATCH
;  COM_MTD_STD  get_CommandBars  , :ptr ptr CommandBars
;  COM_MTD_STD  get_SynonymInfo  , :BSTR,:ptr VARIANT,:ptr ptr SynonymInfo
;  COM_MTD_STD  get_VBE  , :ptr ptr VBE
;  COM_MTD_STD  get_ListGalleries  , :ptr ptr ListGalleries
;  COM_MTD_STD  get_ActivePrinter  , :ptr BSTR
;  COM_MTD_STD  put_ActivePrinter  , :BSTR
;  COM_MTD_STD  get_Templates  , :ptr ptr Templates
;  COM_MTD_STD  get_CustomizationContext  , :ptr LPDISPATCH
;  COM_MTD_STD  put_CustomizationContext  , :LPDISPATCH
;  COM_MTD_STD  get_KeyBindings  , :ptr ptr KeyBindings
;  COM_MTD_STD  get_KeysBoundTo  , :WdKeyCategory,:BSTR,:ptr VARIANT,:ptr ptr KeysBoundTo
;  COM_MTD_STD  get_FindKey  , :SDWORD,:ptr VARIANT,:ptr ptr KeyBinding
;  COM_MTD_STD  get_Options  , :ptr ptr Options
;  COM_MTD_STD  get_CustomDictionaries  , :ptr ptr Dictionaries
;  COM_MTD_STD  put_StatusBar  , :BSTR
;  COM_MTD_STD  get_ShowVisualBasicEditor  , :ptr BOOL
;  COM_MTD_STD  put_ShowVisualBasicEditor  , :BOOL
;  COM_MTD_STD  get_IsObjectValid  , :LPDISPATCH,:ptr BOOL
;  COM_MTD_STD  get_HangulHanjaDictionaries  , :ptr ptr HangulHanjaConversionDictionaries
;  COM_MTD_STD  Repeat_  , :ptr VARIANT,:ptr BOOL
;  COM_MTD_STD  DDEExecute  , :SDWORD,:BSTR
;  COM_MTD_STD  DDEInitiate  , :BSTR,:BSTR,:ptr SDWORD
;  COM_MTD_STD  DDEPoke  , :SDWORD,:BSTR,:BSTR
;  COM_MTD_STD  DDERequest  , :SDWORD,:BSTR,:ptr BSTR
;  COM_MTD_STD  DDETerminate  , :SDWORD
;  COM_MTD_STD  DDETerminateAll  
;  COM_MTD_STD  BuildKeyCode  , :WdKey,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr SDWORD
;  COM_MTD_STD  KeyString  , :SDWORD,:ptr VARIANT,:ptr BSTR
;  COM_MTD_STD  CheckSpelling  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr BOOL
;  COM_MTD_STD  GetSpellingSuggestions  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr SpellingSuggestions
;  COM_MTD_STD  Help  , :ptr VARIANT
;  COM_MTD_STD  NewWindow  , :ptr ptr Window
;  COM_MTD_STD  CleanString  , :BSTR,:ptr BSTR
;  COM_MTD_STD  ChangeFileOpenDirectory  , :BSTR
;  COM_MTD_STD  InchesToPoints  , :REAL4,:ptr REAL4
;  COM_MTD_STD  CentimetersToPoints  , :REAL4,:ptr REAL4
;  COM_MTD_STD  MillimetersToPoints  , :REAL4,:ptr REAL4
;  COM_MTD_STD  PicasToPoints  , :REAL4,:ptr REAL4
;  COM_MTD_STD  LinesToPoints  , :REAL4,:ptr REAL4
;  COM_MTD_STD  PointsToInches  , :REAL4,:ptr REAL4
;  COM_MTD_STD  PointsToCentimeters  , :REAL4,:ptr REAL4
;  COM_MTD_STD  PointsToMillimeters  , :REAL4,:ptr REAL4
;  COM_MTD_STD  PointsToPicas  , :REAL4,:ptr REAL4
;  COM_MTD_STD  PointsToLines  , :REAL4,:ptr REAL4
;  COM_MTD_STD  PointsToPixels  , :REAL4,:ptr VARIANT,:ptr REAL4
;  COM_MTD_STD  PixelsToPoints  , :REAL4,:ptr VARIANT,:ptr REAL4
;  COM_MTD_STD  get_LanguageSettings  , :ptr ptr LanguageSettings
;  COM_MTD_STD  get_AnswerWizard  , :ptr ptr AnswerWizard
;COM_INTERFACE_END
;endif
;
;sIID__Global textequ <IID {0000209B9h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FontNames, Type=INTERFACE, GUID={0002096F-0000-0000-C000-000000000046}
;
;ifndef FontNamesVtbl
;COM_INTERFACE_BEG FontNames, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :SDWORD,:ptr BSTR
;COM_INTERFACE_END
;endif
;
;sIID_FontNames textequ <IID {00002096Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Languages, Type=INTERFACE, GUID={0002096E-0000-0000-C000-000000000046}
;
;ifndef LanguagesVtbl
;COM_INTERFACE_BEG Languages, IDispatch
;  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
;  COM_MTD_STD  get_Count  , :ptr SDWORD
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Language
;COM_INTERFACE_END
;endif
;
;sIID_Languages textequ <IID {00002096Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Language, Type=INTERFACE, GUID={0002096D-0000-0000-C000-000000000046}
;
;ifndef LanguageVtbl
;COM_INTERFACE_BEG Language, IDispatch
;  COM_MTD_STD  get_Application  , :ptr ptr Application
;  COM_MTD_STD  get_Creator  , :ptr SDWORD
;  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
;  COM_MTD_STD  get_ID  , :ptr WdLanguageID
;  COM_MTD_STD  get_NameLocal  , :ptr BSTR
;  COM_MTD_STD  get_Name  , :ptr BSTR
;  COM_MTD_STD  get_ActiveGrammarDictionary  , :ptr ptr Dictionary
;  COM_MTD_STD  get_ActiveHyphenationDictionary  , :ptr ptr Dictionary
;  COM_MTD_STD  get_ActiveSpellingDictionary  , :ptr ptr Dictionary
;  COM_MTD_STD  get_ActiveThesaurusDictionary  , :ptr ptr Dictionary
;  COM_MTD_STD  get_DefaultWritingStyle  , :ptr BSTR
;  COM_MTD_STD  put_DefaultWritingStyle  , :BSTR
;  COM_MTD_STD  get_WritingStyleList  , :ptr VARIANT
;  COM_MTD_STD  get_SpellingDictionaryType  , :ptr WdDictionaryType
;  COM_MTD_STD  put_SpellingDictionaryType  , :WdDictionaryType
;COM_INTERFACE_END
;endif
;
;sIID_Language textequ <IID {00002096Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Documents, Type=INTERFACE, GUID={0002096C-0000-0000-C000-000000000046}

ifndef DocumentsVtbl
COM_INTERFACE_BEG Documents, IDispatch, 0002096C-0000-0000-C000-000000000046
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Document
  COM_MTD_STD  Close  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  AddOld  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Document
  COM_MTD_STD  OpenOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Document
  COM_MTD_STD  Save  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Document
  COM_MTD_STD  Open  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Document
COM_INTERFACE_END
endif

sIID_Documents textequ <IID {00002096Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- _Document, Type=INTERFACE, GUID={0002096B-0000-0000-C000-000000000046}

ifndef _DocumentVtbl
COM_INTERFACE_BEG _Document, IDispatch, 0002096B-0000-0000-C000-000000000046
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_BuiltInDocumentProperties  , :ptr LPDISPATCH
  COM_MTD_STD  get_CustomDocumentProperties  , :ptr LPDISPATCH
  COM_MTD_STD  get_Path  , :ptr BSTR
  COM_MTD_STD  get_Bookmarks  , :ptr ptr Bookmarks
  COM_MTD_STD  get_Tables  , :ptr ptr Tables
  COM_MTD_STD  get_Footnotes  , :ptr ptr Footnotes
  COM_MTD_STD  get_Endnotes  , :ptr ptr Endnotes
  COM_MTD_STD  get_Comments  , :ptr ptr Comments
  COM_MTD_STD  get_Type  , :ptr WdDocumentType
  COM_MTD_STD  get_AutoHyphenation  , :ptr BOOL
  COM_MTD_STD  put_AutoHyphenation  , :BOOL
  COM_MTD_STD  get_HyphenateCaps  , :ptr BOOL
  COM_MTD_STD  put_HyphenateCaps  , :BOOL
  COM_MTD_STD  get_HyphenationZone  , :ptr SDWORD
  COM_MTD_STD  put_HyphenationZone  , :SDWORD
  COM_MTD_STD  get_ConsecutiveHyphensLimit  , :ptr SDWORD
  COM_MTD_STD  put_ConsecutiveHyphensLimit  , :SDWORD
  COM_MTD_STD  get_Sections  , :ptr ptr Sections
  COM_MTD_STD  get_Paragraphs  , :ptr ptr Paragraphs
  COM_MTD_STD  get_Words  , :ptr ptr Words
  COM_MTD_STD  get_Sentences  , :ptr ptr Sentences
  COM_MTD_STD  get_Characters  , :ptr ptr Characters
  COM_MTD_STD  get_Fields  , :ptr ptr Fields
  COM_MTD_STD  get_FormFields  , :ptr ptr FormFields
  COM_MTD_STD  get_Styles  , :ptr ptr Styles
  COM_MTD_STD  get_Frames  , :ptr ptr Frames
  COM_MTD_STD  get_TablesOfFigures  , :ptr ptr TablesOfFigures
  COM_MTD_STD  get_Variables  , :ptr ptr Variables
  COM_MTD_STD  get_MailMerge  , :ptr ptr MailMerge
  COM_MTD_STD  get_Envelope  , :ptr ptr Envelope
  COM_MTD_STD  get_FullName  , :ptr BSTR
  COM_MTD_STD  get_Revisions  , :ptr ptr Revisions
  COM_MTD_STD  get_TablesOfContents  , :ptr ptr TablesOfContents
  COM_MTD_STD  get_TablesOfAuthorities  , :ptr ptr TablesOfAuthorities
  COM_MTD_STD  get_PageSetup  , :ptr ptr PageSetup
  COM_MTD_STD  put_PageSetup  , :ptr PageSetup
  COM_MTD_STD  get_Windows  , :ptr ptr Windows
  COM_MTD_STD  get_HasRoutingSlip  , :ptr BOOL
  COM_MTD_STD  put_HasRoutingSlip  , :BOOL
  COM_MTD_STD  get_RoutingSlip  , :ptr ptr RoutingSlip
  COM_MTD_STD  get_Routed  , :ptr BOOL
  COM_MTD_STD  get_TablesOfAuthoritiesCategories  , :ptr ptr TablesOfAuthoritiesCategories
  COM_MTD_STD  get_Indexes  , :ptr ptr Indexes
  COM_MTD_STD  get_Saved  , :ptr BOOL
  COM_MTD_STD  put_Saved  , :BOOL
  COM_MTD_STD  get_Content  , :ptr ptr Range
  COM_MTD_STD  get_ActiveWindow  , :ptr ptr Window
  COM_MTD_STD  get_Kind  , :ptr WdDocumentKind
  COM_MTD_STD  put_Kind  , :WdDocumentKind
  COM_MTD_STD  get_ReadOnly  , :ptr BOOL
  COM_MTD_STD  get_Subdocuments  , :ptr ptr Subdocuments
  COM_MTD_STD  get_IsMasterDocument  , :ptr BOOL
  COM_MTD_STD  get_DefaultTabStop  , :ptr REAL4
  COM_MTD_STD  put_DefaultTabStop  , :REAL4
  COM_MTD_STD  get_EmbedTrueTypeFonts  , :ptr BOOL
  COM_MTD_STD  put_EmbedTrueTypeFonts  , :BOOL
  COM_MTD_STD  get_SaveFormsData  , :ptr BOOL
  COM_MTD_STD  put_SaveFormsData  , :BOOL
  COM_MTD_STD  get_ReadOnlyRecommended  , :ptr BOOL
  COM_MTD_STD  put_ReadOnlyRecommended  , :BOOL
  COM_MTD_STD  get_SaveSubsetFonts  , :ptr BOOL
  COM_MTD_STD  put_SaveSubsetFonts  , :BOOL
  COM_MTD_STD  get_Compatibility  , :WdCompatibility,:ptr BOOL
  COM_MTD_STD  put_Compatibility  , :WdCompatibility,:BOOL
  COM_MTD_STD  get_StoryRanges  , :ptr ptr StoryRanges
  COM_MTD_STD  get_CommandBars  , :ptr ptr CommandBars
  COM_MTD_STD  get_IsSubdocument  , :ptr BOOL
  COM_MTD_STD  get_SaveFormat  , :ptr SDWORD
  COM_MTD_STD  get_ProtectionType  , :ptr WdProtectionType
  COM_MTD_STD  get_Hyperlinks  , :ptr ptr Hyperlinks
  COM_MTD_STD  get_Shapes  , :ptr ptr Shapes
  COM_MTD_STD  get_ListTemplates  , :ptr ptr ListTemplates
  COM_MTD_STD  get_Lists  , :ptr ptr Lists
  COM_MTD_STD  get_UpdateStylesOnOpen  , :ptr BOOL
  COM_MTD_STD  put_UpdateStylesOnOpen  , :BOOL
  COM_MTD_STD  get_AttachedTemplate  , :ptr VARIANT
  COM_MTD_STD  put_AttachedTemplate  , :ptr VARIANT
  COM_MTD_STD  get_InlineShapes  , :ptr ptr InlineShapes
  COM_MTD_STD  get_Background  , :ptr ptr Shape
  COM_MTD_STD  put_Background  , :ptr Shape
  COM_MTD_STD  get_GrammarChecked  , :ptr BOOL
  COM_MTD_STD  put_GrammarChecked  , :BOOL
  COM_MTD_STD  get_SpellingChecked  , :ptr BOOL
  COM_MTD_STD  put_SpellingChecked  , :BOOL
  COM_MTD_STD  get_ShowGrammaticalErrors  , :ptr BOOL
  COM_MTD_STD  put_ShowGrammaticalErrors  , :BOOL
  COM_MTD_STD  get_ShowSpellingErrors  , :ptr BOOL
  COM_MTD_STD  put_ShowSpellingErrors  , :BOOL
  COM_MTD_STD  get_Versions  , :ptr ptr Versions
  COM_MTD_STD  get_ShowSummary  , :ptr BOOL
  COM_MTD_STD  put_ShowSummary  , :BOOL
  COM_MTD_STD  get_SummaryViewMode  , :ptr WdSummaryMode
  COM_MTD_STD  put_SummaryViewMode  , :WdSummaryMode
  COM_MTD_STD  get_SummaryLength  , :ptr SDWORD
  COM_MTD_STD  put_SummaryLength  , :SDWORD
  COM_MTD_STD  get_PrintFractionalWidths  , :ptr BOOL
  COM_MTD_STD  put_PrintFractionalWidths  , :BOOL
  COM_MTD_STD  get_PrintPostScriptOverText  , :ptr BOOL
  COM_MTD_STD  put_PrintPostScriptOverText  , :BOOL
  COM_MTD_STD  get_Container  , :ptr LPDISPATCH
  COM_MTD_STD  get_PrintFormsData  , :ptr BOOL
  COM_MTD_STD  put_PrintFormsData  , :BOOL
  COM_MTD_STD  get_ListParagraphs  , :ptr ptr ListParagraphs
  COM_MTD_STD  put_Password  , :BSTR
  COM_MTD_STD  put_WritePassword  , :BSTR
  COM_MTD_STD  get_HasPassword  , :ptr BOOL
  COM_MTD_STD  get_WriteReserved  , :ptr BOOL
  COM_MTD_STD  get_ActiveWritingStyle  , :ptr VARIANT,:ptr BSTR
  COM_MTD_STD  put_ActiveWritingStyle  , :ptr VARIANT,:BSTR
  COM_MTD_STD  get_UserControl  , :ptr BOOL
  COM_MTD_STD  put_UserControl  , :BOOL
  COM_MTD_STD  get_HasMailer  , :ptr BOOL
  COM_MTD_STD  put_HasMailer  , :BOOL
  COM_MTD_STD  get_Mailer  , :ptr ptr Mailer
  COM_MTD_STD  get_ReadabilityStatistics  , :ptr ptr ReadabilityStatistics
  COM_MTD_STD  get_GrammaticalErrors  , :ptr ptr ProofreadingErrors
  COM_MTD_STD  get_SpellingErrors  , :ptr ptr ProofreadingErrors
  COM_MTD_STD  get_VBProject  , :ptr ptr VBProject
  COM_MTD_STD  get_FormsDesign  , :ptr BOOL
  COM_MTD_STD  get__CodeName  , :ptr BSTR
  COM_MTD_STD  put__CodeName  , :BSTR
  COM_MTD_STD  get_CodeName  , :ptr BSTR
  COM_MTD_STD  get_SnapToGrid  , :ptr BOOL
  COM_MTD_STD  put_SnapToGrid  , :BOOL
  COM_MTD_STD  get_SnapToShapes  , :ptr BOOL
  COM_MTD_STD  put_SnapToShapes  , :BOOL
  COM_MTD_STD  get_GridDistanceHorizontal  , :ptr REAL4
  COM_MTD_STD  put_GridDistanceHorizontal  , :REAL4
  COM_MTD_STD  get_GridDistanceVertical  , :ptr REAL4
  COM_MTD_STD  put_GridDistanceVertical  , :REAL4
  COM_MTD_STD  get_GridOriginHorizontal  , :ptr REAL4
  COM_MTD_STD  put_GridOriginHorizontal  , :REAL4
  COM_MTD_STD  get_GridOriginVertical  , :ptr REAL4
  COM_MTD_STD  put_GridOriginVertical  , :REAL4
  COM_MTD_STD  get_GridSpaceBetweenHorizontalLines  , :ptr SDWORD
  COM_MTD_STD  put_GridSpaceBetweenHorizontalLines  , :SDWORD
  COM_MTD_STD  get_GridSpaceBetweenVerticalLines  , :ptr SDWORD
  COM_MTD_STD  put_GridSpaceBetweenVerticalLines  , :SDWORD
  COM_MTD_STD  get_GridOriginFromMargin  , :ptr BOOL
  COM_MTD_STD  put_GridOriginFromMargin  , :BOOL
  COM_MTD_STD  get_KerningByAlgorithm  , :ptr BOOL
  COM_MTD_STD  put_KerningByAlgorithm  , :BOOL
  COM_MTD_STD  get_JustificationMode  , :ptr WdJustificationMode
  COM_MTD_STD  put_JustificationMode  , :WdJustificationMode
  COM_MTD_STD  get_FarEastLineBreakLevel  , :ptr WdFarEastLineBreakLevel
  COM_MTD_STD  put_FarEastLineBreakLevel  , :WdFarEastLineBreakLevel
  COM_MTD_STD  get_NoLineBreakBefore  , :ptr BSTR
  COM_MTD_STD  put_NoLineBreakBefore  , :BSTR
  COM_MTD_STD  get_NoLineBreakAfter  , :ptr BSTR
  COM_MTD_STD  put_NoLineBreakAfter  , :BSTR
  COM_MTD_STD  get_TrackRevisions  , :ptr BOOL
  COM_MTD_STD  put_TrackRevisions  , :BOOL
  COM_MTD_STD  get_PrintRevisions  , :ptr BOOL
  COM_MTD_STD  put_PrintRevisions  , :BOOL
  COM_MTD_STD  get_ShowRevisions  , :ptr BOOL
  COM_MTD_STD  put_ShowRevisions  , :BOOL
  COM_MTD_STD  Close  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SaveAs  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  Repaginate  
  COM_MTD_STD  FitToPages  
  COM_MTD_STD  ManualHyphenation  
  COM_MTD_STD  Select  
  COM_MTD_STD  DataForm  
  COM_MTD_STD  Route  
  COM_MTD_STD  Save  
  COM_MTD_STD  PrintOutOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SendMail  
  COM_MTD_STD  Range  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  RunAutoMacro  , :WdAutoMacros
  COM_MTD_STD  Activate  
  COM_MTD_STD  PrintPreview  
  COM_MTD_STD  GoTo_  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  Undo  , :ptr VARIANT,:ptr BOOL
  COM_MTD_STD  Redo  , :ptr VARIANT,:ptr BOOL
  COM_MTD_STD  ComputeStatistics  , :WdStatistic,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MakeCompatibilityDefault  
  COM_MTD_STD  Protect  , :WdProtectionType,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  Unprotect  , :ptr VARIANT
  COM_MTD_STD  EditionOptions  , :WdEditionType,:WdEditionOption,:BSTR,:ptr VARIANT
  COM_MTD_STD  RunLetterWizard  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  GetLetterContent  , :ptr ptr LetterContent
  COM_MTD_STD  SetLetterContent  , :ptr VARIANT
  COM_MTD_STD  CopyStylesFromTemplate  , :BSTR
  COM_MTD_STD  UpdateStyles  
  COM_MTD_STD  CheckGrammar  
  COM_MTD_STD  CheckSpelling  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  FollowHyperlink  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  AddToFavorites  
  COM_MTD_STD  Reload  
  COM_MTD_STD  AutoSummarize  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  RemoveNumbers  , :ptr VARIANT
  COM_MTD_STD  ConvertNumbersToText  , :ptr VARIANT
  COM_MTD_STD  CountNumberedItems  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  Post  
  COM_MTD_STD  ToggleFormsDesign  
  COM_MTD_STD  Compare  , :BSTR
  COM_MTD_STD  UpdateSummaryProperties  
  COM_MTD_STD  GetCrossReferenceItems  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  AutoFormat  
  COM_MTD_STD  ViewCode  
  COM_MTD_STD  ViewPropertyBrowser  
  COM_MTD_STD  ForwardMailer  
  COM_MTD_STD  Reply  
  COM_MTD_STD  ReplyAll  
  COM_MTD_STD  SendMailer  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  UndoClear  
  COM_MTD_STD  PresentIt  
  COM_MTD_STD  SendFax  , :BSTR,:ptr VARIANT
  COM_MTD_STD  Merge  , :BSTR
  COM_MTD_STD  ClosePrintPreview  
  COM_MTD_STD  CheckConsistency  
;+++   COM_MTD_STD  CreateLetterContent  , :BSTR,:BOOL,:BSTR,:WdLetterStyle,:BOOL,:WdLetterheadLocation,:REAL4,:BSTR,:BSTR,:BSTR,:WdSalutationType,:BSTR,:BSTR,:BSTR,:BSTR,:BSTR,:BSTR,:BSTR,:BSTR,:BSTR,:BSTR,:BSTR,:SDWORD,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr LetterContent
  COM_MTD_STD  CreateLetterContent  , :DWORD
  COM_MTD_STD  AcceptAllRevisions  
  COM_MTD_STD  RejectAllRevisions  
  COM_MTD_STD  DetectLanguage  
  COM_MTD_STD  ApplyTheme  , :BSTR
  COM_MTD_STD  RemoveTheme  
  COM_MTD_STD  WebPagePreview  
  COM_MTD_STD  ReloadAs, :SDWORD;MsoEncoding
  COM_MTD_STD  get_ActiveTheme  , :ptr BSTR
  COM_MTD_STD  get_ActiveThemeDisplayName  , :ptr BSTR
  COM_MTD_STD  get_Email  , :ptr ptr Email
  COM_MTD_STD  get_Scripts  , :ptr ptr Scripts
  COM_MTD_STD  get_LanguageDetected  , :ptr BOOL
  COM_MTD_STD  put_LanguageDetected  , :BOOL
  COM_MTD_STD  get_FarEastLineBreakLanguage  , :ptr WdFarEastLineBreakLanguageID
  COM_MTD_STD  put_FarEastLineBreakLanguage  , :WdFarEastLineBreakLanguageID
  COM_MTD_STD  get_Frameset  , :ptr ptr Frameset
  COM_MTD_STD  get_ClickAndTypeParagraphStyle  , :ptr VARIANT
  COM_MTD_STD  put_ClickAndTypeParagraphStyle  , :ptr VARIANT
  COM_MTD_STD  get_HTMLProject  , :ptr ptr HTMLProject
  COM_MTD_STD  get_WebOptions  , :ptr ptr WebOptions
  COM_MTD_STD  get_OpenEncoding  , :ptr MsoEncoding
  COM_MTD_STD  get_SaveEncoding  , :ptr MsoEncoding
  COM_MTD_STD  put_SaveEncoding  , :MsoEncoding
  COM_MTD_STD  get_OptimizeForWord97  , :ptr BOOL
  COM_MTD_STD  put_OptimizeForWord97  , :BOOL
  COM_MTD_STD  get_VBASigned  , :ptr BOOL
;  COM_MTD_STD  PrintOut  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  sblt  , :BSTR
COM_INTERFACE_END
endif

sIID__Document textequ <IID {00002096Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Template, Type=INTERFACE, GUID={0002096A-0000-0000-C000-000000000046}

ifndef TemplateVtbl
COM_INTERFACE_BEG Template, IDispatch
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Path  , :ptr BSTR
  COM_MTD_STD  get_AutoTextEntries  , :ptr ptr AutoTextEntries
  COM_MTD_STD  get_LanguageID  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageID  , :WdLanguageID
  COM_MTD_STD  get_Saved  , :ptr BOOL
  COM_MTD_STD  put_Saved  , :BOOL
  COM_MTD_STD  get_Type  , :ptr WdTemplateType
  COM_MTD_STD  get_FullName  , :ptr BSTR
  COM_MTD_STD  get_BuiltInDocumentProperties  , :ptr LPDISPATCH
  COM_MTD_STD  get_CustomDocumentProperties  , :ptr LPDISPATCH
  COM_MTD_STD  get_ListTemplates  , :ptr ptr ListTemplates
  COM_MTD_STD  get_LanguageIDFarEast  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageIDFarEast  , :WdLanguageID
  COM_MTD_STD  get_VBProject  , :ptr ptr VBProject
  COM_MTD_STD  get_KerningByAlgorithm  , :ptr BOOL
  COM_MTD_STD  put_KerningByAlgorithm  , :BOOL
  COM_MTD_STD  get_JustificationMode  , :ptr WdJustificationMode
  COM_MTD_STD  put_JustificationMode  , :WdJustificationMode
  COM_MTD_STD  get_FarEastLineBreakLevel  , :ptr WdFarEastLineBreakLevel
  COM_MTD_STD  put_FarEastLineBreakLevel  , :WdFarEastLineBreakLevel
  COM_MTD_STD  get_NoLineBreakBefore  , :ptr BSTR
  COM_MTD_STD  put_NoLineBreakBefore  , :BSTR
  COM_MTD_STD  get_NoLineBreakAfter  , :ptr BSTR
  COM_MTD_STD  put_NoLineBreakAfter  , :BSTR
  COM_MTD_STD  OpenAsDocument  , :ptr ptr Document
  COM_MTD_STD  Save  
  COM_MTD_STD  get_NoProofing  , :ptr SDWORD
  COM_MTD_STD  put_NoProofing  , :SDWORD
  COM_MTD_STD  get_FarEastLineBreakLanguage  , :ptr WdFarEastLineBreakLanguageID
  COM_MTD_STD  put_FarEastLineBreakLanguage  , :WdFarEastLineBreakLanguageID
COM_INTERFACE_END
endif

sIID_Template textequ <IID {00002096Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Templates, Type=INTERFACE, GUID={000209A2-0000-0000-C000-000000000046}

ifndef TemplatesVtbl
COM_INTERFACE_BEG Templates, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Template
COM_INTERFACE_END
endif

sIID_Templates textequ <IID {0000209A2h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- RoutingSlip, Type=INTERFACE, GUID={00020969-0000-0000-C000-000000000046}

ifndef RoutingSlipVtbl
COM_INTERFACE_BEG RoutingSlip, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Subject  , :ptr BSTR
  COM_MTD_STD  put_Subject  , :BSTR
  COM_MTD_STD  get_Message  , :ptr BSTR
  COM_MTD_STD  put_Message  , :BSTR
  COM_MTD_STD  get_Delivery  , :ptr WdRoutingSlipDelivery
  COM_MTD_STD  put_Delivery  , :WdRoutingSlipDelivery
  COM_MTD_STD  get_TrackStatus  , :ptr BOOL
  COM_MTD_STD  put_TrackStatus  , :BOOL
  COM_MTD_STD  get_Protect  , :ptr WdProtectionType
  COM_MTD_STD  put_Protect  , :WdProtectionType
  COM_MTD_STD  get_ReturnWhenDone  , :ptr BOOL
  COM_MTD_STD  put_ReturnWhenDone  , :BOOL
  COM_MTD_STD  get_Status  , :ptr WdRoutingSlipStatus
  COM_MTD_STD  get_Recipients  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  Reset  
  COM_MTD_STD  AddRecipient  , :BSTR
COM_INTERFACE_END
endif

sIID_RoutingSlip textequ <IID {000020969h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Bookmark, Type=INTERFACE, GUID={00020968-0000-0000-C000-000000000046}

ifndef BookmarkVtbl
COM_INTERFACE_BEG Bookmark, IDispatch
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  get_Range  , :ptr ptr Range
  COM_MTD_STD  get_Empty  , :ptr BOOL
  COM_MTD_STD  get_Start  , :ptr SDWORD
  COM_MTD_STD  put_Start  , :SDWORD
  COM_MTD_STD  get_End  , :ptr SDWORD
  COM_MTD_STD  put_End  , :SDWORD
  COM_MTD_STD  get_Column  , :ptr BOOL
  COM_MTD_STD  get_StoryType  , :ptr WdStoryType
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Select  
  COM_MTD_STD  Delete  
  COM_MTD_STD  Copy  , :BSTR,:ptr ptr Bookmark
COM_INTERFACE_END
endif

sIID_Bookmark textequ <IID {000020968h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Bookmarks, Type=INTERFACE, GUID={00020967-0000-0000-C000-000000000046}

ifndef BookmarksVtbl
COM_INTERFACE_BEG Bookmarks, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_DefaultSorting  , :ptr WdBookmarkSortBy
  COM_MTD_STD  put_DefaultSorting  , :WdBookmarkSortBy
  COM_MTD_STD  get_ShowHidden  , :ptr BOOL
  COM_MTD_STD  put_ShowHidden  , :BOOL
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Bookmark
  COM_MTD_STD  Add_  , :BSTR,:ptr VARIANT,:ptr ptr Bookmark
  COM_MTD_STD  Exists  , :BSTR,:ptr BOOL
COM_INTERFACE_END
endif

sIID_Bookmarks textequ <IID {000020967h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Variable, Type=INTERFACE, GUID={00020966-0000-0000-C000-000000000046}

ifndef VariableVtbl
COM_INTERFACE_BEG Variable, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  get_Value  , :ptr BSTR
  COM_MTD_STD  put_Value  , :BSTR
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  Delete  
COM_INTERFACE_END
endif

sIID_Variable textequ <IID {000020966h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Variables, Type=INTERFACE, GUID={00020965-0000-0000-C000-000000000046}

ifndef VariablesVtbl
COM_INTERFACE_BEG Variables, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Variable
  COM_MTD_STD  Add_  , :BSTR,:ptr VARIANT,:ptr ptr Variable
COM_INTERFACE_END
endif

sIID_Variables textequ <IID {000020965h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- RecentFile, Type=INTERFACE, GUID={00020964-0000-0000-C000-000000000046}

ifndef RecentFileVtbl
COM_INTERFACE_BEG RecentFile, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  get_ReadOnly  , :ptr BOOL
  COM_MTD_STD  put_ReadOnly  , :BOOL
  COM_MTD_STD  get_Path  , :ptr BSTR
  COM_MTD_STD  Open  , :ptr ptr Document
  COM_MTD_STD  Delete  
COM_INTERFACE_END
endif

sIID_RecentFile textequ <IID {000020964h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- RecentFiles, Type=INTERFACE, GUID={00020963-0000-0000-C000-000000000046}

ifndef RecentFilesVtbl
COM_INTERFACE_BEG RecentFiles, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Maximum  , :ptr SDWORD
  COM_MTD_STD  put_Maximum  , :SDWORD
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr RecentFile
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr VARIANT,:ptr ptr RecentFile
COM_INTERFACE_END
endif

sIID_RecentFiles textequ <IID {000020963h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Window, Type=INTERFACE, GUID={00020962-0000-0000-C000-000000000046}

ifndef WindowVtbl
COM_INTERFACE_BEG Window, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_ActivePane  , :ptr ptr Pane
  COM_MTD_STD  get_Document  , :ptr ptr Document
  COM_MTD_STD  get_Panes  , :ptr ptr Panes
  COM_MTD_STD  get_Selection  , :ptr ptr Selection
  COM_MTD_STD  get_Left  , :ptr SDWORD
  COM_MTD_STD  put_Left  , :SDWORD
  COM_MTD_STD  get_Top  , :ptr SDWORD
  COM_MTD_STD  put_Top  , :SDWORD
  COM_MTD_STD  get_Width  , :ptr SDWORD
  COM_MTD_STD  put_Width  , :SDWORD
  COM_MTD_STD  get_Height  , :ptr SDWORD
  COM_MTD_STD  put_Height  , :SDWORD
  COM_MTD_STD  get_Split  , :ptr BOOL
  COM_MTD_STD  put_Split  , :BOOL
  COM_MTD_STD  get_SplitVertical  , :ptr SDWORD
  COM_MTD_STD  put_SplitVertical  , :SDWORD
  COM_MTD_STD  get_Caption  , :ptr BSTR
  COM_MTD_STD  put_Caption  , :BSTR
  COM_MTD_STD  get_WindowState  , :ptr WdWindowState
  COM_MTD_STD  put_WindowState  , :WdWindowState
  COM_MTD_STD  get_DisplayRulers  , :ptr BOOL
  COM_MTD_STD  put_DisplayRulers  , :BOOL
  COM_MTD_STD  get_DisplayVerticalRuler  , :ptr BOOL
  COM_MTD_STD  put_DisplayVerticalRuler  , :BOOL
  COM_MTD_STD  get_View  , :ptr ptr View
  COM_MTD_STD  get_Type  , :ptr WdWindowType
  COM_MTD_STD  get_Next  , :ptr ptr Window
  COM_MTD_STD  get_Previous  , :ptr ptr Window
  COM_MTD_STD  get_WindowNumber  , :ptr SDWORD
  COM_MTD_STD  get_DisplayVerticalScrollBar  , :ptr BOOL
  COM_MTD_STD  put_DisplayVerticalScrollBar  , :BOOL
  COM_MTD_STD  get_DisplayHorizontalScrollBar  , :ptr BOOL
  COM_MTD_STD  put_DisplayHorizontalScrollBar  , :BOOL
  COM_MTD_STD  get_StyleAreaWidth  , :ptr REAL4
  COM_MTD_STD  put_StyleAreaWidth  , :REAL4
  COM_MTD_STD  get_DisplayScreenTips  , :ptr BOOL
  COM_MTD_STD  put_DisplayScreenTips  , :BOOL
  COM_MTD_STD  get_HorizontalPercentScrolled  , :ptr SDWORD
  COM_MTD_STD  put_HorizontalPercentScrolled  , :SDWORD
  COM_MTD_STD  get_VerticalPercentScrolled  , :ptr SDWORD
  COM_MTD_STD  put_VerticalPercentScrolled  , :SDWORD
  COM_MTD_STD  get_DocumentMap  , :ptr BOOL
  COM_MTD_STD  put_DocumentMap  , :BOOL
  COM_MTD_STD  get_Active  , :ptr BOOL
  COM_MTD_STD  get_DocumentMapPercentWidth  , :ptr SDWORD
  COM_MTD_STD  put_DocumentMapPercentWidth  , :SDWORD
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  get_IMEMode  , :ptr WdIMEMode
  COM_MTD_STD  put_IMEMode  , :WdIMEMode
  COM_MTD_STD  Activate  
  COM_MTD_STD  Close  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  LargeScroll  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SmallScroll  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  NewWindow  , :ptr ptr Window
  COM_MTD_STD  PrintOutOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  PageScroll  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SetFocus  
  COM_MTD_STD  RangeFromPoint  , :SDWORD,:SDWORD,:ptr LPDISPATCH
  COM_MTD_STD  ScrollIntoView  , :LPDISPATCH,:ptr VARIANT
  COM_MTD_STD  GetPoint  , :ptr SDWORD,:ptr SDWORD,:ptr SDWORD,:ptr SDWORD,:LPDISPATCH
;  COM_MTD_STD  PrintOut  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  get_UsableWidth  , :ptr SDWORD
  COM_MTD_STD  get_UsableHeight  , :ptr SDWORD
  COM_MTD_STD  get_EnvelopeVisible  , :ptr BOOL
  COM_MTD_STD  put_EnvelopeVisible  , :BOOL
  COM_MTD_STD  get_DisplayRightRuler  , :ptr BOOL
  COM_MTD_STD  put_DisplayRightRuler  , :BOOL
  COM_MTD_STD  get_DisplayLeftScrollBar  , :ptr BOOL
  COM_MTD_STD  put_DisplayLeftScrollBar  , :BOOL
  COM_MTD_STD  get_Visible  , :ptr BOOL
  COM_MTD_STD  put_Visible  , :BOOL
COM_INTERFACE_END
endif

sIID_Window textequ <IID {000020962h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Windows, Type=INTERFACE, GUID={00020961-0000-0000-C000-000000000046}

ifndef WindowsVtbl
COM_INTERFACE_BEG Windows, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr Window
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr ptr Window
  COM_MTD_STD  Arrange  , :ptr VARIANT
COM_INTERFACE_END
endif

sIID_Windows textequ <IID {000020961h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Pane, Type=INTERFACE, GUID={00020960-0000-0000-C000-000000000046}

ifndef PaneVtbl
COM_INTERFACE_BEG Pane, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Document  , :ptr ptr Document
  COM_MTD_STD  get_Selection  , :ptr ptr Selection
  COM_MTD_STD  get_DisplayRulers  , :ptr BOOL
  COM_MTD_STD  put_DisplayRulers  , :BOOL
  COM_MTD_STD  get_DisplayVerticalRuler  , :ptr BOOL
  COM_MTD_STD  put_DisplayVerticalRuler  , :BOOL
  COM_MTD_STD  get_Zooms  , :ptr ptr Zooms
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  get_View  , :ptr ptr View
  COM_MTD_STD  get_Next  , :ptr ptr Pane
  COM_MTD_STD  get_Previous  , :ptr ptr Pane
  COM_MTD_STD  get_HorizontalPercentScrolled  , :ptr SDWORD
  COM_MTD_STD  put_HorizontalPercentScrolled  , :SDWORD
  COM_MTD_STD  get_VerticalPercentScrolled  , :ptr SDWORD
  COM_MTD_STD  put_VerticalPercentScrolled  , :SDWORD
  COM_MTD_STD  get_MinimumFontSize  , :ptr SDWORD
  COM_MTD_STD  put_MinimumFontSize  , :SDWORD
  COM_MTD_STD  get_BrowseToWindow  , :ptr BOOL
  COM_MTD_STD  put_BrowseToWindow  , :BOOL
  COM_MTD_STD  get_BrowseWidth  , :ptr SDWORD
  COM_MTD_STD  Activate  
  COM_MTD_STD  Close  
  COM_MTD_STD  LargeScroll  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SmallScroll  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  AutoScroll  , :SDWORD
  COM_MTD_STD  PageScroll  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  NewFrameset  
  COM_MTD_STD  TOCInFrameset  
  COM_MTD_STD  get_Frameset  , :ptr ptr Frameset
COM_INTERFACE_END
endif

sIID_Pane textequ <IID {000020960h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Panes, Type=INTERFACE, GUID={0002095F-0000-0000-C000-000000000046}

ifndef PanesVtbl
COM_INTERFACE_BEG Panes, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Pane
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr ptr Pane
COM_INTERFACE_END
endif

sIID_Panes textequ <IID {00002095Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Range, Type=INTERFACE, GUID={0002095E-0000-0000-C000-000000000046}

ifndef RangeVtbl
COM_INTERFACE_BEG Range, IDispatch
  COM_MTD_STD  get_Text  , :ptr BSTR
  COM_MTD_STD  put_Text  , :BSTR
  COM_MTD_STD  get_FormattedText  , :ptr ptr Range
  COM_MTD_STD  put_FormattedText  , :ptr Range
  COM_MTD_STD  get_Start  , :ptr SDWORD
  COM_MTD_STD  put_Start  , :SDWORD
  COM_MTD_STD  get_End  , :ptr SDWORD
  COM_MTD_STD  put_End  , :SDWORD
  COM_MTD_STD  get_Font  , :ptr ptr Font
  COM_MTD_STD  put_Font  , :ptr Font
  COM_MTD_STD  get_Duplicate  , :ptr ptr Range
  COM_MTD_STD  get_StoryType  , :ptr WdStoryType
  COM_MTD_STD  get_Tables  , :ptr ptr Tables
  COM_MTD_STD  get_Words  , :ptr ptr Words
  COM_MTD_STD  get_Sentences  , :ptr ptr Sentences
  COM_MTD_STD  get_Characters  , :ptr ptr Characters
  COM_MTD_STD  get_Footnotes  , :ptr ptr Footnotes
  COM_MTD_STD  get_Endnotes  , :ptr ptr Endnotes
  COM_MTD_STD  get_Comments  , :ptr ptr Comments
  COM_MTD_STD  get_Cells  , :ptr ptr Cells
  COM_MTD_STD  get_Sections  , :ptr ptr Sections
  COM_MTD_STD  get_Paragraphs  , :ptr ptr Paragraphs
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_TextRetrievalMode  , :ptr ptr TextRetrievalMode
  COM_MTD_STD  put_TextRetrievalMode  , :ptr TextRetrievalMode
  COM_MTD_STD  get_Fields  , :ptr ptr Fields
  COM_MTD_STD  get_FormFields  , :ptr ptr FormFields
  COM_MTD_STD  get_Frames  , :ptr ptr Frames
  COM_MTD_STD  get_ParagraphFormat  , :ptr ptr ParagraphFormat
  COM_MTD_STD  put_ParagraphFormat  , :ptr ParagraphFormat
  COM_MTD_STD  get_ListFormat  , :ptr ptr ListFormat
  COM_MTD_STD  get_Bookmarks  , :ptr ptr Bookmarks
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Bold  , :ptr SDWORD
  COM_MTD_STD  put_Bold  , :SDWORD
  COM_MTD_STD  get_Italic  , :ptr SDWORD
  COM_MTD_STD  put_Italic  , :SDWORD
  COM_MTD_STD  get_Underline  , :ptr WdUnderline
  COM_MTD_STD  put_Underline  , :WdUnderline
  COM_MTD_STD  get_EmphasisMark  , :ptr WdEmphasisMark
  COM_MTD_STD  put_EmphasisMark  , :WdEmphasisMark
  COM_MTD_STD  get_DisableCharacterSpaceGrid  , :ptr BOOL
  COM_MTD_STD  put_DisableCharacterSpaceGrid  , :BOOL
  COM_MTD_STD  get_Revisions  , :ptr ptr Revisions
  COM_MTD_STD  get_Style  , :ptr VARIANT
  COM_MTD_STD  put_Style  , :ptr VARIANT
  COM_MTD_STD  get_StoryLength  , :ptr SDWORD
  COM_MTD_STD  get_LanguageID  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageID  , :WdLanguageID
  COM_MTD_STD  get_SynonymInfo  , :ptr ptr SynonymInfo
  COM_MTD_STD  get_Hyperlinks  , :ptr ptr Hyperlinks
  COM_MTD_STD  get_ListParagraphs  , :ptr ptr ListParagraphs
  COM_MTD_STD  get_Subdocuments  , :ptr ptr Subdocuments
  COM_MTD_STD  get_GrammarChecked  , :ptr BOOL
  COM_MTD_STD  put_GrammarChecked  , :BOOL
  COM_MTD_STD  get_SpellingChecked  , :ptr BOOL
  COM_MTD_STD  put_SpellingChecked  , :BOOL
  COM_MTD_STD  get_HighlightColorIndex  , :ptr WdColorIndex
  COM_MTD_STD  put_HighlightColorIndex  , :WdColorIndex
  COM_MTD_STD  get_Columns  , :ptr ptr Columns
  COM_MTD_STD  get_Rows  , :ptr ptr Rows
  COM_MTD_STD  get_CanEdit  , :ptr SDWORD
  COM_MTD_STD  get_CanPaste  , :ptr SDWORD
  COM_MTD_STD  get_IsEndOfRowMark  , :ptr BOOL
  COM_MTD_STD  get_BookmarkID  , :ptr SDWORD
  COM_MTD_STD  get_PreviousBookmarkID  , :ptr SDWORD
  COM_MTD_STD  get_Find  , :ptr ptr Find
  COM_MTD_STD  get_PageSetup  , :ptr ptr PageSetup
  COM_MTD_STD  put_PageSetup  , :ptr PageSetup
  COM_MTD_STD  get_ShapeRange  , :ptr ptr ShapeRange
  COM_MTD_STD  get_Case  , :ptr WdCharacterCase
  COM_MTD_STD  put_Case  , :WdCharacterCase
  COM_MTD_STD  get_Information  , :WdInformation,:ptr VARIANT
  COM_MTD_STD  get_ReadabilityStatistics  , :ptr ptr ReadabilityStatistics
  COM_MTD_STD  get_GrammaticalErrors  , :ptr ptr ProofreadingErrors
  COM_MTD_STD  get_SpellingErrors  , :ptr ptr ProofreadingErrors
  COM_MTD_STD  get_Orientation  , :ptr WdTextOrientation
  COM_MTD_STD  put_Orientation  , :WdTextOrientation
  COM_MTD_STD  get_InlineShapes  , :ptr ptr InlineShapes
  COM_MTD_STD  get_NextStoryRange  , :ptr ptr Range
  COM_MTD_STD  get_LanguageIDFarEast  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageIDFarEast  , :WdLanguageID
  COM_MTD_STD  get_LanguageIDOther  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageIDOther  , :WdLanguageID
  COM_MTD_STD  Select  
  COM_MTD_STD  SetRange  , :SDWORD,:SDWORD
  COM_MTD_STD  Collapse  , :ptr VARIANT
  COM_MTD_STD  InsertBefore  , :BSTR
  COM_MTD_STD  InsertAfter  , :BSTR
  COM_MTD_STD  Next  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  Previous  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  StartOf  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  EndOf  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  Move  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MoveStart  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MoveEnd  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MoveWhile  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MoveStartWhile  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MoveEndWhile  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MoveUntil  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MoveStartUntil  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  MoveEndUntil  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  Cut  
  COM_MTD_STD  Copy  
  COM_MTD_STD  Paste  
  COM_MTD_STD  InsertBreak  , :ptr VARIANT
  COM_MTD_STD  InsertFile  , :BSTR,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  InStory  , :ptr Range,:ptr BOOL
  COM_MTD_STD  InRange  , :ptr Range,:ptr BOOL
  COM_MTD_STD  Delete  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  WholeStory  
  COM_MTD_STD  Expand  , :ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  InsertParagraph  
  COM_MTD_STD  InsertParagraphAfter  
  COM_MTD_STD  ConvertToTableOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Table
  COM_MTD_STD  InsertDateTimeOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  InsertSymbol  , :SDWORD,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  InsertCrossReference  , :ptr VARIANT,:WdReferenceKind,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  InsertCaption  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  CopyAsPicture  
  COM_MTD_STD  SortOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SortAscending  
  COM_MTD_STD  SortDescending  
  COM_MTD_STD  IsEqual  , :ptr Range,:ptr BOOL
  COM_MTD_STD  Calculate  , :ptr REAL4
  COM_MTD_STD  GoTo_  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  GoToNext  , :WdGoToItem,:ptr ptr Range
  COM_MTD_STD  GoToPrevious  , :WdGoToItem,:ptr ptr Range
  COM_MTD_STD  PasteSpecial  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  LookupNameProperties  
  COM_MTD_STD  ComputeStatistics  , :WdStatistic,:ptr SDWORD
  COM_MTD_STD  Relocate  , :SDWORD
  COM_MTD_STD  CheckSynonyms  
  COM_MTD_STD  SubscribeTo  , :BSTR,:ptr VARIANT
  COM_MTD_STD  CreatePublisher  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  InsertAutoText  
  COM_MTD_STD  InsertDatabase  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  AutoFormat  
  COM_MTD_STD  CheckGrammar  
  COM_MTD_STD  CheckSpelling  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  GetSpellingSuggestions  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr SpellingSuggestions
  COM_MTD_STD  InsertParagraphBefore  
  COM_MTD_STD  NextSubdocument  
  COM_MTD_STD  PreviousSubdocument  
  COM_MTD_STD  ConvertHangulAndHanja  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  PasteAsNestedTable  
  COM_MTD_STD  ModifyEnclosure  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  PhoneticGuide  , :BSTR,:WdPhoneticGuideAlignmentType,:SDWORD,:SDWORD,:BSTR
  COM_MTD_STD  InsertDateTime  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
;  COM_MTD_STD  Sort  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  DetectLanguage  
;  COM_MTD_STD  ConvertToTable  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr ptr Table
  COM_MTD_STD  TCSCConverter  , :WdTCSCConverterDirection,:BOOL,:BOOL
  COM_MTD_STD  get_LanguageDetected  , :ptr BOOL
  COM_MTD_STD  put_LanguageDetected  , :BOOL
  COM_MTD_STD  get_FitTextWidth  , :ptr REAL4
  COM_MTD_STD  put_FitTextWidth  , :REAL4
  COM_MTD_STD  get_HorizontalInVertical  , :ptr WdHorizontalInVerticalType
  COM_MTD_STD  put_HorizontalInVertical  , :WdHorizontalInVerticalType
  COM_MTD_STD  get_TwoLinesInOne  , :ptr WdTwoLinesInOneType
  COM_MTD_STD  put_TwoLinesInOne  , :WdTwoLinesInOneType
  COM_MTD_STD  get_CombineCharacters  , :ptr BOOL
  COM_MTD_STD  put_CombineCharacters  , :BOOL
  COM_MTD_STD  get_NoProofing  , :ptr SDWORD
  COM_MTD_STD  put_NoProofing  , :SDWORD
  COM_MTD_STD  get_TopLevelTables  , :ptr ptr Tables
  COM_MTD_STD  get_Scripts  , :ptr ptr Scripts
  COM_MTD_STD  get_CharacterWidth  , :ptr WdCharacterWidth
  COM_MTD_STD  put_CharacterWidth  , :WdCharacterWidth
  COM_MTD_STD  get_Kana  , :ptr WdKana
  COM_MTD_STD  put_Kana  , :WdKana
  COM_MTD_STD  get_BoldBi  , :ptr SDWORD
  COM_MTD_STD  put_BoldBi  , :SDWORD
  COM_MTD_STD  get_ItalicBi  , :ptr SDWORD
  COM_MTD_STD  put_ItalicBi  , :SDWORD
  COM_MTD_STD  get_ID  , :ptr BSTR
  COM_MTD_STD  put_ID  , :BSTR
COM_INTERFACE_END
endif

sIID_Range textequ <IID {00002095Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- ListFormat, Type=INTERFACE, GUID={000209C0-0000-0000-C000-000000000046}

ifndef ListFormatVtbl
COM_INTERFACE_BEG ListFormat, IDispatch
  COM_MTD_STD  get_ListLevelNumber  , :ptr SDWORD
  COM_MTD_STD  put_ListLevelNumber  , :SDWORD
  COM_MTD_STD  get_List  , :ptr ptr List
  COM_MTD_STD  get_ListTemplate  , :ptr ptr ListTemplate
  COM_MTD_STD  get_ListValue  , :ptr SDWORD
  COM_MTD_STD  get_SingleList  , :ptr BOOL
  COM_MTD_STD  get_SingleListTemplate  , :ptr BOOL
  COM_MTD_STD  get_ListType  , :ptr WdListType
  COM_MTD_STD  get_ListString  , :ptr BSTR
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  CanContinuePreviousList  , :ptr ListTemplate,:ptr WdContinue
  COM_MTD_STD  RemoveNumbers  , :ptr VARIANT
  COM_MTD_STD  ConvertNumbersToText  , :ptr VARIANT
  COM_MTD_STD  CountNumberedItems  , :ptr VARIANT,:ptr VARIANT,:ptr SDWORD
  COM_MTD_STD  ApplyBulletDefaultOld  
  COM_MTD_STD  ApplyNumberDefaultOld  
  COM_MTD_STD  ApplyOutlineNumberDefaultOld  
  COM_MTD_STD  ApplyListTemplateOld  , :ptr ListTemplate,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  ListOutdent  
  COM_MTD_STD  ListIndent  
  COM_MTD_STD  ApplyBulletDefault  , :ptr VARIANT
  COM_MTD_STD  ApplyNumberDefault  , :ptr VARIANT
  COM_MTD_STD  ApplyOutlineNumberDefault  , :ptr VARIANT
  COM_MTD_STD  ApplyListTemplate  , :ptr ListTemplate,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
COM_INTERFACE_END
endif

sIID_ListFormat textequ <IID {0000209C0h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Find, Type=INTERFACE, GUID={000209B0-0000-0000-C000-000000000046}

ifndef FindVtbl
COM_INTERFACE_BEG Find, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Forward  , :ptr BOOL
  COM_MTD_STD  put_Forward  , :BOOL
  COM_MTD_STD  get_Font  , :ptr ptr Font
  COM_MTD_STD  put_Font  , :ptr Font
  COM_MTD_STD  get_Found  , :ptr BOOL
  COM_MTD_STD  get_MatchAllWordForms  , :ptr BOOL
  COM_MTD_STD  put_MatchAllWordForms  , :BOOL
  COM_MTD_STD  get_MatchCase  , :ptr BOOL
  COM_MTD_STD  put_MatchCase  , :BOOL
  COM_MTD_STD  get_MatchWildcards  , :ptr BOOL
  COM_MTD_STD  put_MatchWildcards  , :BOOL
  COM_MTD_STD  get_MatchSoundsLike  , :ptr BOOL
  COM_MTD_STD  put_MatchSoundsLike  , :BOOL
  COM_MTD_STD  get_MatchWholeWord  , :ptr BOOL
  COM_MTD_STD  put_MatchWholeWord  , :BOOL
  COM_MTD_STD  get_MatchFuzzy  , :ptr BOOL
  COM_MTD_STD  put_MatchFuzzy  , :BOOL
  COM_MTD_STD  get_MatchByte  , :ptr BOOL
  COM_MTD_STD  put_MatchByte  , :BOOL
  COM_MTD_STD  get_ParagraphFormat  , :ptr ptr ParagraphFormat
  COM_MTD_STD  put_ParagraphFormat  , :ptr ParagraphFormat
  COM_MTD_STD  get_Style  , :ptr VARIANT
  COM_MTD_STD  put_Style  , :ptr VARIANT
  COM_MTD_STD  get_Text  , :ptr BSTR
  COM_MTD_STD  put_Text  , :BSTR
  COM_MTD_STD  get_LanguageID  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageID  , :WdLanguageID
  COM_MTD_STD  get_Highlight  , :ptr SDWORD
  COM_MTD_STD  put_Highlight  , :SDWORD
  COM_MTD_STD  get_Replacement  , :ptr ptr Replacement
  COM_MTD_STD  get_Frame, :POINTER;ptr ptr Frame
  COM_MTD_STD  get_Wrap  , :ptr WdFindWrap
  COM_MTD_STD  put_Wrap  , :WdFindWrap
  COM_MTD_STD  get_Format  , :ptr BOOL
  COM_MTD_STD  put_Format  , :BOOL
  COM_MTD_STD  get_LanguageIDFarEast  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageIDFarEast  , :WdLanguageID
  COM_MTD_STD  get_LanguageIDOther  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageIDOther  , :WdLanguageID
  COM_MTD_STD  get_CorrectHangulEndings  , :ptr BOOL
  COM_MTD_STD  put_CorrectHangulEndings  , :BOOL
  COM_MTD_STD  ExecuteOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr BOOL
  COM_MTD_STD  ClearFormatting  
  COM_MTD_STD  SetAllFuzzyOptions  
  COM_MTD_STD  ClearAllFuzzyOptions  
  COM_MTD_STD  Execute  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr BOOL
  COM_MTD_STD  get_NoProofing  , :ptr SDWORD
  COM_MTD_STD  put_NoProofing  , :SDWORD
  COM_MTD_STD  get_MatchKashida  , :ptr BOOL
  COM_MTD_STD  put_MatchKashida  , :BOOL
  COM_MTD_STD  get_MatchDiacritics  , :ptr BOOL
  COM_MTD_STD  put_MatchDiacritics  , :BOOL
  COM_MTD_STD  get_MatchAlefHamza  , :ptr BOOL
  COM_MTD_STD  put_MatchAlefHamza  , :BOOL
  COM_MTD_STD  get_MatchControl  , :ptr BOOL
  COM_MTD_STD  put_MatchControl  , :BOOL
COM_INTERFACE_END
endif

sIID_Find textequ <IID {0000209B0h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Replacement, Type=INTERFACE, GUID={000209B1-0000-0000-C000-000000000046}

ifndef ReplacementVtbl
COM_INTERFACE_BEG Replacement, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Font  , :ptr ptr Font
  COM_MTD_STD  put_Font  , :ptr Font
  COM_MTD_STD  get_ParagraphFormat  , :ptr ptr ParagraphFormat
  COM_MTD_STD  put_ParagraphFormat  , :ptr ParagraphFormat
  COM_MTD_STD  get_Style  , :ptr VARIANT
  COM_MTD_STD  put_Style  , :ptr VARIANT
  COM_MTD_STD  get_Text  , :ptr BSTR
  COM_MTD_STD  put_Text  , :BSTR
  COM_MTD_STD  get_LanguageID  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageID  , :WdLanguageID
  COM_MTD_STD  get_Highlight  , :ptr SDWORD
  COM_MTD_STD  put_Highlight  , :SDWORD
  COM_MTD_STD  get_Frame  , :POINTER;ptr ptr Frame
  COM_MTD_STD  get_LanguageIDFarEast  , :ptr WdLanguageID
  COM_MTD_STD  put_LanguageIDFarEast  , :WdLanguageID
  COM_MTD_STD  ClearFormatting  
  COM_MTD_STD  get_NoProofing  , :ptr SDWORD
  COM_MTD_STD  put_NoProofing  , :SDWORD
COM_INTERFACE_END
endif

sIID_Replacement textequ <IID {0000209B1h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Characters, Type=INTERFACE, GUID={0002095D-0000-0000-C000-000000000046}

ifndef CharactersVtbl
COM_INTERFACE_BEG Characters, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_First  , :ptr ptr Range
  COM_MTD_STD  get_Last  , :ptr ptr Range
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Range
COM_INTERFACE_END
endif

sIID_Characters textequ <IID {00002095Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Words, Type=INTERFACE, GUID={0002095C-0000-0000-C000-000000000046}

ifndef WordsVtbl
COM_INTERFACE_BEG Words, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_First  , :ptr ptr Range
  COM_MTD_STD  get_Last  , :ptr ptr Range
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Range
COM_INTERFACE_END
endif

sIID_Words textequ <IID {00002095Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Sentences, Type=INTERFACE, GUID={0002095B-0000-0000-C000-000000000046}

ifndef SentencesVtbl
COM_INTERFACE_BEG Sentences, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_First  , :ptr ptr Range
  COM_MTD_STD  get_Last  , :ptr ptr Range
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Range
COM_INTERFACE_END
endif

sIID_Sentences textequ <IID {00002095Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Sections, Type=INTERFACE, GUID={0002095A-0000-0000-C000-000000000046}

ifndef SectionsVtbl
COM_INTERFACE_BEG Sections, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_First  , :ptr ptr Section
  COM_MTD_STD  get_Last  , :ptr ptr Section
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_PageSetup  , :ptr ptr PageSetup
  COM_MTD_STD  put_PageSetup  , :ptr PageSetup
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Section
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Section
COM_INTERFACE_END
endif

sIID_Sections textequ <IID {00002095Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Section, Type=INTERFACE, GUID={00020959-0000-0000-C000-000000000046}

ifndef SectionVtbl
COM_INTERFACE_BEG Section, IDispatch
  COM_MTD_STD  get_Range  , :ptr ptr Range
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_PageSetup  , :ptr ptr PageSetup
  COM_MTD_STD  put_PageSetup  , :ptr PageSetup
  COM_MTD_STD  get_Headers  , :ptr ptr HeadersFooters
  COM_MTD_STD  get_Footers  , :ptr ptr HeadersFooters
  COM_MTD_STD  get_ProtectedForForms  , :ptr BOOL
  COM_MTD_STD  put_ProtectedForForms  , :BOOL
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
COM_INTERFACE_END
endif

sIID_Section textequ <IID {000020959h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Paragraphs, Type=INTERFACE, GUID={00020958-0000-0000-C000-000000000046}

ifndef ParagraphsVtbl
COM_INTERFACE_BEG Paragraphs, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_First  , :ptr ptr Paragraph
  COM_MTD_STD  get_Last  , :ptr ptr Paragraph
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Format  , :ptr ptr ParagraphFormat
  COM_MTD_STD  put_Format  , :ptr ParagraphFormat
  COM_MTD_STD  get_TabStops  , :ptr ptr TabStops
  COM_MTD_STD  put_TabStops  , :ptr TabStops
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Style  , :ptr VARIANT
  COM_MTD_STD  put_Style  , :ptr VARIANT
  COM_MTD_STD  get_Alignment  , :ptr WdParagraphAlignment
  COM_MTD_STD  put_Alignment  , :WdParagraphAlignment
  COM_MTD_STD  get_KeepTogether  , :ptr SDWORD
  COM_MTD_STD  put_KeepTogether  , :SDWORD
  COM_MTD_STD  get_KeepWithNext  , :ptr SDWORD
  COM_MTD_STD  put_KeepWithNext  , :SDWORD
  COM_MTD_STD  get_PageBreakBefore  , :ptr SDWORD
  COM_MTD_STD  put_PageBreakBefore  , :SDWORD
  COM_MTD_STD  get_NoLineNumber  , :ptr SDWORD
  COM_MTD_STD  put_NoLineNumber  , :SDWORD
  COM_MTD_STD  get_RightIndent  , :ptr REAL4
  COM_MTD_STD  put_RightIndent  , :REAL4
  COM_MTD_STD  get_LeftIndent  , :ptr REAL4
  COM_MTD_STD  put_LeftIndent  , :REAL4
  COM_MTD_STD  get_FirstLineIndent  , :ptr REAL4
  COM_MTD_STD  put_FirstLineIndent  , :REAL4
  COM_MTD_STD  get_LineSpacing  , :ptr REAL4
  COM_MTD_STD  put_LineSpacing  , :REAL4
  COM_MTD_STD  get_LineSpacingRule  , :ptr WdLineSpacing
  COM_MTD_STD  put_LineSpacingRule  , :WdLineSpacing
  COM_MTD_STD  get_SpaceBefore  , :ptr REAL4
  COM_MTD_STD  put_SpaceBefore  , :REAL4
  COM_MTD_STD  get_SpaceAfter  , :ptr REAL4
  COM_MTD_STD  put_SpaceAfter  , :REAL4
  COM_MTD_STD  get_Hyphenation  , :ptr SDWORD
  COM_MTD_STD  put_Hyphenation  , :SDWORD
  COM_MTD_STD  get_WidowControl  , :ptr SDWORD
  COM_MTD_STD  put_WidowControl  , :SDWORD
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_FarEastLineBreakControl  , :ptr SDWORD
  COM_MTD_STD  put_FarEastLineBreakControl  , :SDWORD
  COM_MTD_STD  get_WordWrap  , :ptr SDWORD
  COM_MTD_STD  put_WordWrap  , :SDWORD
  COM_MTD_STD  get_HangingPunctuation  , :ptr SDWORD
  COM_MTD_STD  put_HangingPunctuation  , :SDWORD
  COM_MTD_STD  get_HalfWidthPunctuationOnTopOfLine  , :ptr SDWORD
  COM_MTD_STD  put_HalfWidthPunctuationOnTopOfLine  , :SDWORD
  COM_MTD_STD  get_AddSpaceBetweenFarEastAndAlpha  , :ptr SDWORD
  COM_MTD_STD  put_AddSpaceBetweenFarEastAndAlpha  , :SDWORD
  COM_MTD_STD  get_AddSpaceBetweenFarEastAndDigit  , :ptr SDWORD
  COM_MTD_STD  put_AddSpaceBetweenFarEastAndDigit  , :SDWORD
  COM_MTD_STD  get_BaseLineAlignment  , :ptr WdBaselineAlignment
  COM_MTD_STD  put_BaseLineAlignment  , :WdBaselineAlignment
  COM_MTD_STD  get_AutoAdjustRightIndent  , :ptr SDWORD
  COM_MTD_STD  put_AutoAdjustRightIndent  , :SDWORD
  COM_MTD_STD  get_DisableLineHeightGrid  , :ptr SDWORD
  COM_MTD_STD  put_DisableLineHeightGrid  , :SDWORD
  COM_MTD_STD  get_OutlineLevel  , :ptr WdOutlineLevel
  COM_MTD_STD  put_OutlineLevel  , :WdOutlineLevel
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Paragraph
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr ptr Paragraph
  COM_MTD_STD  CloseUp  
  COM_MTD_STD  OpenUp  
  COM_MTD_STD  OpenOrCloseUp  
  COM_MTD_STD  TabHangingIndent  , :SWORD
  COM_MTD_STD  TabIndent  , :SWORD
  COM_MTD_STD  Reset  
  COM_MTD_STD  Space1  
  COM_MTD_STD  Space15  
  COM_MTD_STD  Space2  
  COM_MTD_STD  IndentCharWidth  , :SWORD
  COM_MTD_STD  IndentFirstLineCharWidth  , :SWORD
  COM_MTD_STD  OutlinePromote  
  COM_MTD_STD  OutlineDemote  
  COM_MTD_STD  OutlineDemoteToBody  
  COM_MTD_STD  Indent  
  COM_MTD_STD  Outdent  
  COM_MTD_STD  get_CharacterUnitRightIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitRightIndent  , :REAL4
  COM_MTD_STD  get_CharacterUnitLeftIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitLeftIndent  , :REAL4
  COM_MTD_STD  get_CharacterUnitFirstLineIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitFirstLineIndent  , :REAL4
  COM_MTD_STD  get_LineUnitBefore  , :ptr REAL4
  COM_MTD_STD  put_LineUnitBefore  , :REAL4
  COM_MTD_STD  get_LineUnitAfter  , :ptr REAL4
  COM_MTD_STD  put_LineUnitAfter  , :REAL4
  COM_MTD_STD  get_ReadingOrder  , :ptr WdReadingOrder
  COM_MTD_STD  put_ReadingOrder  , :WdReadingOrder
  COM_MTD_STD  get_SpaceBeforeAuto  , :ptr SDWORD
  COM_MTD_STD  put_SpaceBeforeAuto  , :SDWORD
  COM_MTD_STD  get_SpaceAfterAuto  , :ptr SDWORD
  COM_MTD_STD  put_SpaceAfterAuto  , :SDWORD
COM_INTERFACE_END
endif

sIID_Paragraphs textequ <IID {000020958h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Paragraph, Type=INTERFACE, GUID={00020957-0000-0000-C000-000000000046}

ifndef ParagraphVtbl
COM_INTERFACE_BEG Paragraph, IDispatch
  COM_MTD_STD  get_Range  , :ptr ptr Range
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Format  , :ptr ptr ParagraphFormat
  COM_MTD_STD  put_Format  , :ptr ParagraphFormat
  COM_MTD_STD  get_TabStops  , :ptr ptr TabStops
  COM_MTD_STD  put_TabStops  , :ptr TabStops
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_DropCap  , :ptr ptr DropCap
  COM_MTD_STD  get_Style  , :ptr VARIANT
  COM_MTD_STD  put_Style  , :ptr VARIANT
  COM_MTD_STD  get_Alignment  , :ptr WdParagraphAlignment
  COM_MTD_STD  put_Alignment  , :WdParagraphAlignment
  COM_MTD_STD  get_KeepTogether  , :ptr SDWORD
  COM_MTD_STD  put_KeepTogether  , :SDWORD
  COM_MTD_STD  get_KeepWithNext  , :ptr SDWORD
  COM_MTD_STD  put_KeepWithNext  , :SDWORD
  COM_MTD_STD  get_PageBreakBefore  , :ptr SDWORD
  COM_MTD_STD  put_PageBreakBefore  , :SDWORD
  COM_MTD_STD  get_NoLineNumber  , :ptr SDWORD
  COM_MTD_STD  put_NoLineNumber  , :SDWORD
  COM_MTD_STD  get_RightIndent  , :ptr REAL4
  COM_MTD_STD  put_RightIndent  , :REAL4
  COM_MTD_STD  get_LeftIndent  , :ptr REAL4
  COM_MTD_STD  put_LeftIndent  , :REAL4
  COM_MTD_STD  get_FirstLineIndent  , :ptr REAL4
  COM_MTD_STD  put_FirstLineIndent  , :REAL4
  COM_MTD_STD  get_LineSpacing  , :ptr REAL4
  COM_MTD_STD  put_LineSpacing  , :REAL4
  COM_MTD_STD  get_LineSpacingRule  , :ptr WdLineSpacing
  COM_MTD_STD  put_LineSpacingRule  , :WdLineSpacing
  COM_MTD_STD  get_SpaceBefore  , :ptr REAL4
  COM_MTD_STD  put_SpaceBefore  , :REAL4
  COM_MTD_STD  get_SpaceAfter  , :ptr REAL4
  COM_MTD_STD  put_SpaceAfter  , :REAL4
  COM_MTD_STD  get_Hyphenation  , :ptr SDWORD
  COM_MTD_STD  put_Hyphenation  , :SDWORD
  COM_MTD_STD  get_WidowControl  , :ptr SDWORD
  COM_MTD_STD  put_WidowControl  , :SDWORD
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_FarEastLineBreakControl  , :ptr SDWORD
  COM_MTD_STD  put_FarEastLineBreakControl  , :SDWORD
  COM_MTD_STD  get_WordWrap  , :ptr SDWORD
  COM_MTD_STD  put_WordWrap  , :SDWORD
  COM_MTD_STD  get_HangingPunctuation  , :ptr SDWORD
  COM_MTD_STD  put_HangingPunctuation  , :SDWORD
  COM_MTD_STD  get_HalfWidthPunctuationOnTopOfLine  , :ptr SDWORD
  COM_MTD_STD  put_HalfWidthPunctuationOnTopOfLine  , :SDWORD
  COM_MTD_STD  get_AddSpaceBetweenFarEastAndAlpha  , :ptr SDWORD
  COM_MTD_STD  put_AddSpaceBetweenFarEastAndAlpha  , :SDWORD
  COM_MTD_STD  get_AddSpaceBetweenFarEastAndDigit  , :ptr SDWORD
  COM_MTD_STD  put_AddSpaceBetweenFarEastAndDigit  , :SDWORD
  COM_MTD_STD  get_BaseLineAlignment  , :ptr WdBaselineAlignment
  COM_MTD_STD  put_BaseLineAlignment  , :WdBaselineAlignment
  COM_MTD_STD  get_AutoAdjustRightIndent  , :ptr SDWORD
  COM_MTD_STD  put_AutoAdjustRightIndent  , :SDWORD
  COM_MTD_STD  get_DisableLineHeightGrid  , :ptr SDWORD
  COM_MTD_STD  put_DisableLineHeightGrid  , :SDWORD
  COM_MTD_STD  get_OutlineLevel  , :ptr WdOutlineLevel
  COM_MTD_STD  put_OutlineLevel  , :WdOutlineLevel
  COM_MTD_STD  CloseUp  
  COM_MTD_STD  OpenUp  
  COM_MTD_STD  OpenOrCloseUp  
  COM_MTD_STD  TabHangingIndent  , :SWORD
  COM_MTD_STD  TabIndent  , :SWORD
  COM_MTD_STD  Reset  
  COM_MTD_STD  Space1  
  COM_MTD_STD  Space15  
  COM_MTD_STD  Space2  
  COM_MTD_STD  IndentCharWidth  , :SWORD
  COM_MTD_STD  IndentFirstLineCharWidth  , :SWORD
  COM_MTD_STD  Next  , :ptr VARIANT,:ptr ptr Paragraph
  COM_MTD_STD  Previous  , :ptr VARIANT,:ptr ptr Paragraph
  COM_MTD_STD  OutlinePromote  
  COM_MTD_STD  OutlineDemote  
  COM_MTD_STD  OutlineDemoteToBody  
  COM_MTD_STD  Indent  
  COM_MTD_STD  Outdent  
  COM_MTD_STD  get_CharacterUnitRightIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitRightIndent  , :REAL4
  COM_MTD_STD  get_CharacterUnitLeftIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitLeftIndent  , :REAL4
  COM_MTD_STD  get_CharacterUnitFirstLineIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitFirstLineIndent  , :REAL4
  COM_MTD_STD  get_LineUnitBefore  , :ptr REAL4
  COM_MTD_STD  put_LineUnitBefore  , :REAL4
  COM_MTD_STD  get_LineUnitAfter  , :ptr REAL4
  COM_MTD_STD  put_LineUnitAfter  , :REAL4
  COM_MTD_STD  get_ReadingOrder  , :ptr WdReadingOrder
  COM_MTD_STD  put_ReadingOrder  , :WdReadingOrder
  COM_MTD_STD  get_ID  , :ptr BSTR
  COM_MTD_STD  put_ID  , :BSTR
  COM_MTD_STD  get_SpaceBeforeAuto  , :ptr SDWORD
  COM_MTD_STD  put_SpaceBeforeAuto  , :SDWORD
  COM_MTD_STD  get_SpaceAfterAuto  , :ptr SDWORD
  COM_MTD_STD  put_SpaceAfterAuto  , :SDWORD
COM_INTERFACE_END
endif

sIID_Paragraph textequ <IID {000020957h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- DropCap, Type=INTERFACE, GUID={00020956-0000-0000-C000-000000000046}

ifndef DropCapVtbl
COM_INTERFACE_BEG DropCap, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Position  , :ptr WdDropPosition
  COM_MTD_STD  put_Position  , :WdDropPosition
  COM_MTD_STD  get_FontName  , :ptr BSTR
  COM_MTD_STD  put_FontName  , :BSTR
  COM_MTD_STD  get_LinesToDrop  , :ptr SDWORD
  COM_MTD_STD  put_LinesToDrop  , :SDWORD
  COM_MTD_STD  get_DistanceFromText  , :ptr REAL4
  COM_MTD_STD  put_DistanceFromText  , :REAL4
  COM_MTD_STD  Clear  
  COM_MTD_STD  Enable  
COM_INTERFACE_END
endif

sIID_DropCap textequ <IID {000020956h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- TabStops, Type=INTERFACE, GUID={00020955-0000-0000-C000-000000000046}

ifndef TabStopsVtbl
COM_INTERFACE_BEG TabStops, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr TabStop
  COM_MTD_STD  Add_  , :REAL4,:ptr VARIANT,:ptr VARIANT,:ptr ptr TabStop
  COM_MTD_STD  ClearAll  
  COM_MTD_STD  Before  , :REAL4,:ptr ptr TabStop
  COM_MTD_STD  After  , :REAL4,:ptr ptr TabStop
COM_INTERFACE_END
endif

sIID_TabStops textequ <IID {000020955h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- TabStop, Type=INTERFACE, GUID={00020954-0000-0000-C000-000000000046}

ifndef TabStopVtbl
COM_INTERFACE_BEG TabStop, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Alignment  , :ptr WdTabAlignment
  COM_MTD_STD  put_Alignment  , :WdTabAlignment
  COM_MTD_STD  get_Leader  , :ptr WdTabLeader
  COM_MTD_STD  put_Leader  , :WdTabLeader
  COM_MTD_STD  get_Position  , :ptr REAL4
  COM_MTD_STD  put_Position  , :REAL4
  COM_MTD_STD  get_CustomTab  , :ptr BOOL
  COM_MTD_STD  get_Next  , :ptr ptr TabStop
  COM_MTD_STD  get_Previous  , :ptr ptr TabStop
  COM_MTD_STD  Clear  
COM_INTERFACE_END
endif

sIID_TabStop textequ <IID {000020954h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- _ParagraphFormat, Type=INTERFACE, GUID={00020953-0000-0000-C000-000000000046}

ifndef _ParagraphFormatVtbl
COM_INTERFACE_BEG _ParagraphFormat, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Duplicate  , :ptr ptr ParagraphFormat
  COM_MTD_STD  get_Style  , :ptr VARIANT
  COM_MTD_STD  put_Style  , :ptr VARIANT
  COM_MTD_STD  get_Alignment  , :ptr WdParagraphAlignment
  COM_MTD_STD  put_Alignment  , :WdParagraphAlignment
  COM_MTD_STD  get_KeepTogether  , :ptr SDWORD
  COM_MTD_STD  put_KeepTogether  , :SDWORD
  COM_MTD_STD  get_KeepWithNext  , :ptr SDWORD
  COM_MTD_STD  put_KeepWithNext  , :SDWORD
  COM_MTD_STD  get_PageBreakBefore  , :ptr SDWORD
  COM_MTD_STD  put_PageBreakBefore  , :SDWORD
  COM_MTD_STD  get_NoLineNumber  , :ptr SDWORD
  COM_MTD_STD  put_NoLineNumber  , :SDWORD
  COM_MTD_STD  get_RightIndent  , :ptr REAL4
  COM_MTD_STD  put_RightIndent  , :REAL4
  COM_MTD_STD  get_LeftIndent  , :ptr REAL4
  COM_MTD_STD  put_LeftIndent  , :REAL4
  COM_MTD_STD  get_FirstLineIndent  , :ptr REAL4
  COM_MTD_STD  put_FirstLineIndent  , :REAL4
  COM_MTD_STD  get_LineSpacing  , :ptr REAL4
  COM_MTD_STD  put_LineSpacing  , :REAL4
  COM_MTD_STD  get_LineSpacingRule  , :ptr WdLineSpacing
  COM_MTD_STD  put_LineSpacingRule  , :WdLineSpacing
  COM_MTD_STD  get_SpaceBefore  , :ptr REAL4
  COM_MTD_STD  put_SpaceBefore  , :REAL4
  COM_MTD_STD  get_SpaceAfter  , :ptr REAL4
  COM_MTD_STD  put_SpaceAfter  , :REAL4
  COM_MTD_STD  get_Hyphenation  , :ptr SDWORD
  COM_MTD_STD  put_Hyphenation  , :SDWORD
  COM_MTD_STD  get_WidowControl  , :ptr SDWORD
  COM_MTD_STD  put_WidowControl  , :SDWORD
  COM_MTD_STD  get_FarEastLineBreakControl  , :ptr SDWORD
  COM_MTD_STD  put_FarEastLineBreakControl  , :SDWORD
  COM_MTD_STD  get_WordWrap  , :ptr SDWORD
  COM_MTD_STD  put_WordWrap  , :SDWORD
  COM_MTD_STD  get_HangingPunctuation  , :ptr SDWORD
  COM_MTD_STD  put_HangingPunctuation  , :SDWORD
  COM_MTD_STD  get_HalfWidthPunctuationOnTopOfLine  , :ptr SDWORD
  COM_MTD_STD  put_HalfWidthPunctuationOnTopOfLine  , :SDWORD
  COM_MTD_STD  get_AddSpaceBetweenFarEastAndAlpha  , :ptr SDWORD
  COM_MTD_STD  put_AddSpaceBetweenFarEastAndAlpha  , :SDWORD
  COM_MTD_STD  get_AddSpaceBetweenFarEastAndDigit  , :ptr SDWORD
  COM_MTD_STD  put_AddSpaceBetweenFarEastAndDigit  , :SDWORD
  COM_MTD_STD  get_BaseLineAlignment  , :ptr WdBaselineAlignment
  COM_MTD_STD  put_BaseLineAlignment  , :WdBaselineAlignment
  COM_MTD_STD  get_AutoAdjustRightIndent  , :ptr SDWORD
  COM_MTD_STD  put_AutoAdjustRightIndent  , :SDWORD
  COM_MTD_STD  get_DisableLineHeightGrid  , :ptr SDWORD
  COM_MTD_STD  put_DisableLineHeightGrid  , :SDWORD
  COM_MTD_STD  get_TabStops  , :ptr ptr TabStops
  COM_MTD_STD  put_TabStops  , :ptr TabStops
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_OutlineLevel  , :ptr WdOutlineLevel
  COM_MTD_STD  put_OutlineLevel  , :WdOutlineLevel
  COM_MTD_STD  CloseUp  
  COM_MTD_STD  OpenUp  
  COM_MTD_STD  OpenOrCloseUp  
  COM_MTD_STD  TabHangingIndent  , :SWORD
  COM_MTD_STD  TabIndent  , :SWORD
  COM_MTD_STD  Reset  
  COM_MTD_STD  Space1  
  COM_MTD_STD  Space15  
  COM_MTD_STD  Space2  
  COM_MTD_STD  IndentCharWidth  , :SWORD
  COM_MTD_STD  IndentFirstLineCharWidth  , :SWORD
  COM_MTD_STD  get_CharacterUnitRightIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitRightIndent  , :REAL4
  COM_MTD_STD  get_CharacterUnitLeftIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitLeftIndent  , :REAL4
  COM_MTD_STD  get_CharacterUnitFirstLineIndent  , :ptr REAL4
  COM_MTD_STD  put_CharacterUnitFirstLineIndent  , :REAL4
  COM_MTD_STD  get_LineUnitBefore  , :ptr REAL4
  COM_MTD_STD  put_LineUnitBefore  , :REAL4
  COM_MTD_STD  get_LineUnitAfter  , :ptr REAL4
  COM_MTD_STD  put_LineUnitAfter  , :REAL4
  COM_MTD_STD  get_ReadingOrder  , :ptr WdReadingOrder
  COM_MTD_STD  put_ReadingOrder  , :WdReadingOrder
  COM_MTD_STD  get_SpaceBeforeAuto  , :ptr SDWORD
  COM_MTD_STD  put_SpaceBeforeAuto  , :SDWORD
  COM_MTD_STD  get_SpaceAfterAuto  , :ptr SDWORD
  COM_MTD_STD  put_SpaceAfterAuto  , :SDWORD
COM_INTERFACE_END
endif

sIID__ParagraphFormat textequ <IID {000020953h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- _Font, Type=INTERFACE, GUID={00020952-0000-0000-C000-000000000046}

ifndef _FontVtbl
COM_INTERFACE_BEG _Font, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Duplicate  , :ptr ptr Font
  COM_MTD_STD  get_Bold  , :ptr SDWORD
  COM_MTD_STD  put_Bold  , :SDWORD
  COM_MTD_STD  get_Italic  , :ptr SDWORD
  COM_MTD_STD  put_Italic  , :SDWORD
  COM_MTD_STD  get_Hidden  , :ptr SDWORD
  COM_MTD_STD  put_Hidden  , :SDWORD
  COM_MTD_STD  get_SmallCaps  , :ptr SDWORD
  COM_MTD_STD  put_SmallCaps  , :SDWORD
  COM_MTD_STD  get_AllCaps  , :ptr SDWORD
  COM_MTD_STD  put_AllCaps  , :SDWORD
  COM_MTD_STD  get_StrikeThrough  , :ptr SDWORD
  COM_MTD_STD  put_StrikeThrough  , :SDWORD
  COM_MTD_STD  get_DoubleStrikeThrough  , :ptr SDWORD
  COM_MTD_STD  put_DoubleStrikeThrough  , :SDWORD
  COM_MTD_STD  get_ColorIndex  , :ptr WdColorIndex
  COM_MTD_STD  put_ColorIndex  , :WdColorIndex
  COM_MTD_STD  get_Subscript  , :ptr SDWORD
  COM_MTD_STD  put_Subscript  , :SDWORD
  COM_MTD_STD  get_Superscript  , :ptr SDWORD
  COM_MTD_STD  put_Superscript  , :SDWORD
  COM_MTD_STD  get_Underline  , :ptr WdUnderline
  COM_MTD_STD  put_Underline  , :WdUnderline
  COM_MTD_STD  get_Size  , :ptr REAL4
  COM_MTD_STD  put_Size  , :REAL4
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  put_Name  , :BSTR
  COM_MTD_STD  get_Position  , :ptr SDWORD
  COM_MTD_STD  put_Position  , :SDWORD
  COM_MTD_STD  get_Spacing  , :ptr REAL4
  COM_MTD_STD  put_Spacing  , :REAL4
  COM_MTD_STD  get_Scaling  , :ptr SDWORD
  COM_MTD_STD  put_Scaling  , :SDWORD
  COM_MTD_STD  get_Shadow  , :ptr SDWORD
  COM_MTD_STD  put_Shadow  , :SDWORD
  COM_MTD_STD  get_Outline  , :ptr SDWORD
  COM_MTD_STD  put_Outline  , :SDWORD
  COM_MTD_STD  get_Emboss  , :ptr SDWORD
  COM_MTD_STD  put_Emboss  , :SDWORD
  COM_MTD_STD  get_Kerning  , :ptr REAL4
  COM_MTD_STD  put_Kerning  , :REAL4
  COM_MTD_STD  get_Engrave  , :ptr SDWORD
  COM_MTD_STD  put_Engrave  , :SDWORD
  COM_MTD_STD  get_Animation  , :ptr WdAnimation
  COM_MTD_STD  put_Animation  , :WdAnimation
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_EmphasisMark  , :ptr WdEmphasisMark
  COM_MTD_STD  put_EmphasisMark  , :WdEmphasisMark
  COM_MTD_STD  get_DisableCharacterSpaceGrid  , :ptr BOOL
  COM_MTD_STD  put_DisableCharacterSpaceGrid  , :BOOL
  COM_MTD_STD  get_NameFarEast  , :ptr BSTR
  COM_MTD_STD  put_NameFarEast  , :BSTR
  COM_MTD_STD  get_NameAscii  , :ptr BSTR
  COM_MTD_STD  put_NameAscii  , :BSTR
  COM_MTD_STD  get_NameOther  , :ptr BSTR
  COM_MTD_STD  put_NameOther  , :BSTR
  COM_MTD_STD  Grow  
  COM_MTD_STD  Shrink  
  COM_MTD_STD  Reset  
  COM_MTD_STD  SetAsTemplateDefault  
  COM_MTD_STD  get_Color  , :ptr WdColor
  COM_MTD_STD  put_Color  , :WdColor
  COM_MTD_STD  get_BoldBi  , :ptr SDWORD
  COM_MTD_STD  put_BoldBi  , :SDWORD
  COM_MTD_STD  get_ItalicBi  , :ptr SDWORD
  COM_MTD_STD  put_ItalicBi  , :SDWORD
  COM_MTD_STD  get_SizeBi  , :ptr REAL4
  COM_MTD_STD  put_SizeBi  , :REAL4
  COM_MTD_STD  get_NameBi  , :ptr BSTR
  COM_MTD_STD  put_NameBi  , :BSTR
  COM_MTD_STD  get_ColorIndexBi  , :ptr WdColorIndex
  COM_MTD_STD  put_ColorIndexBi  , :WdColorIndex
  COM_MTD_STD  get_DiacriticColor  , :ptr WdColor
  COM_MTD_STD  put_DiacriticColor  , :WdColor
  COM_MTD_STD  get_UnderlineColor  , :ptr WdColor
  COM_MTD_STD  put_UnderlineColor  , :WdColor
COM_INTERFACE_END
endif

sIID__Font textequ <IID {000020952h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Table, Type=INTERFACE, GUID={00020951-0000-0000-C000-000000000046}

ifndef TableVtbl
COM_INTERFACE_BEG Table, IDispatch
  COM_MTD_STD  get_Range  , :ptr ptr Range
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Columns  , :ptr ptr Columns
  COM_MTD_STD  get_Rows  , :ptr ptr Rows
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_Uniform  , :ptr BOOL
  COM_MTD_STD  get_AutoFormatType  , :ptr SDWORD
  COM_MTD_STD  Select  
  COM_MTD_STD  Delete  
  COM_MTD_STD  SortOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SortAscending  
  COM_MTD_STD  SortDescending  
  COM_MTD_STD  AutoFormat  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  UpdateAutoFormat  
  COM_MTD_STD  ConvertToTextOld  , :ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  Cell  , :SDWORD,:SDWORD,:ptr ptr Cell
  COM_MTD_STD  Split  , :ptr VARIANT,:ptr ptr Table
  COM_MTD_STD  ConvertToText  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  AutoFitBehavior  , :WdAutoFitBehavior
;  COM_MTD_STD  Sort  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  get_Tables  , :ptr ptr Tables
  COM_MTD_STD  get_NestingLevel  , :ptr SDWORD
  COM_MTD_STD  get_AllowPageBreaks  , :ptr BOOL
  COM_MTD_STD  put_AllowPageBreaks  , :BOOL
  COM_MTD_STD  get_AllowAutoFit  , :ptr BOOL
  COM_MTD_STD  put_AllowAutoFit  , :BOOL
  COM_MTD_STD  get_PreferredWidth  , :ptr REAL4
  COM_MTD_STD  put_PreferredWidth  , :REAL4
  COM_MTD_STD  get_PreferredWidthType  , :ptr WdPreferredWidthType
  COM_MTD_STD  put_PreferredWidthType  , :WdPreferredWidthType
  COM_MTD_STD  get_TopPadding  , :ptr REAL4
  COM_MTD_STD  put_TopPadding  , :REAL4
  COM_MTD_STD  get_BottomPadding  , :ptr REAL4
  COM_MTD_STD  put_BottomPadding  , :REAL4
  COM_MTD_STD  get_LeftPadding  , :ptr REAL4
  COM_MTD_STD  put_LeftPadding  , :REAL4
  COM_MTD_STD  get_RightPadding  , :ptr REAL4
  COM_MTD_STD  put_RightPadding  , :REAL4
  COM_MTD_STD  get_Spacing  , :ptr REAL4
  COM_MTD_STD  put_Spacing  , :REAL4
  COM_MTD_STD  get_TableDirection  , :ptr WdTableDirection
  COM_MTD_STD  put_TableDirection  , :WdTableDirection
  COM_MTD_STD  get_ID  , :ptr BSTR
  COM_MTD_STD  put_ID  , :BSTR
COM_INTERFACE_END
endif

sIID_Table textequ <IID {000020951h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Row, Type=INTERFACE, GUID={00020950-0000-0000-C000-000000000046}

ifndef RowVtbl
COM_INTERFACE_BEG Row, IDispatch
  COM_MTD_STD  get_Range  , :ptr ptr Range
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_AllowBreakAcrossPages  , :ptr SDWORD
  COM_MTD_STD  put_AllowBreakAcrossPages  , :SDWORD
  COM_MTD_STD  get_Alignment  , :ptr WdRowAlignment
  COM_MTD_STD  put_Alignment  , :WdRowAlignment
  COM_MTD_STD  get_HeadingFormat  , :ptr SDWORD
  COM_MTD_STD  put_HeadingFormat  , :SDWORD
  COM_MTD_STD  get_SpaceBetweenColumns  , :ptr REAL4
  COM_MTD_STD  put_SpaceBetweenColumns  , :REAL4
  COM_MTD_STD  get_Height  , :ptr REAL4
  COM_MTD_STD  put_Height  , :REAL4
  COM_MTD_STD  get_HeightRule  , :ptr WdRowHeightRule
  COM_MTD_STD  put_HeightRule  , :WdRowHeightRule
  COM_MTD_STD  get_LeftIndent  , :ptr REAL4
  COM_MTD_STD  put_LeftIndent  , :REAL4
  COM_MTD_STD  get_IsLast  , :ptr BOOL
  COM_MTD_STD  get_IsFirst  , :ptr BOOL
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  get_Cells  , :ptr ptr Cells
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_Next  , :ptr ptr Row
  COM_MTD_STD  get_Previous  , :ptr ptr Row
  COM_MTD_STD  Select  
  COM_MTD_STD  Delete  
  COM_MTD_STD  SetLeftIndent  , :REAL4,:WdRulerStyle
  COM_MTD_STD  SetHeight  , :REAL4,:WdRowHeightRule
  COM_MTD_STD  ConvertToTextOld  , :ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  ConvertToText  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  get_NestingLevel  , :ptr SDWORD
  COM_MTD_STD  get_ID  , :ptr BSTR
  COM_MTD_STD  put_ID  , :BSTR
COM_INTERFACE_END
endif

sIID_Row textequ <IID {000020950h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Column, Type=INTERFACE, GUID={0002094F-0000-0000-C000-000000000046}

ifndef ColumnVtbl
COM_INTERFACE_BEG Column, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Width  , :ptr REAL4
  COM_MTD_STD  put_Width  , :REAL4
  COM_MTD_STD  get_IsFirst  , :ptr BOOL
  COM_MTD_STD  get_IsLast  , :ptr BOOL
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  get_Cells  , :ptr ptr Cells
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_Next  , :ptr ptr Column
  COM_MTD_STD  get_Previous  , :ptr ptr Column
  COM_MTD_STD  Select  
  COM_MTD_STD  Delete  
  COM_MTD_STD  SetWidth  , :REAL4,:WdRulerStyle
  COM_MTD_STD  AutoFit  
  COM_MTD_STD  SortOld  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  Sort  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  get_NestingLevel  , :ptr SDWORD
  COM_MTD_STD  get_PreferredWidth  , :ptr REAL4
  COM_MTD_STD  put_PreferredWidth  , :REAL4
  COM_MTD_STD  get_PreferredWidthType  , :ptr WdPreferredWidthType
  COM_MTD_STD  put_PreferredWidthType  , :WdPreferredWidthType
COM_INTERFACE_END
endif

sIID_Column textequ <IID {00002094Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Cell, Type=INTERFACE, GUID={0002094E-0000-0000-C000-000000000046}

ifndef CellVtbl
COM_INTERFACE_BEG Cell, IDispatch
  COM_MTD_STD  get_Range  , :ptr ptr Range
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_RowIndex  , :ptr SDWORD
  COM_MTD_STD  get_ColumnIndex  , :ptr SDWORD
  COM_MTD_STD  get_Width  , :ptr REAL4
  COM_MTD_STD  put_Width  , :REAL4
  COM_MTD_STD  get_Height  , :ptr REAL4
  COM_MTD_STD  put_Height  , :REAL4
  COM_MTD_STD  get_HeightRule  , :ptr WdRowHeightRule
  COM_MTD_STD  put_HeightRule  , :WdRowHeightRule
  COM_MTD_STD  get_VerticalAlignment  , :ptr WdCellVerticalAlignment
  COM_MTD_STD  put_VerticalAlignment  , :WdCellVerticalAlignment
  COM_MTD_STD  get_Column  , :ptr ptr Column
  COM_MTD_STD  get_Row  , :ptr ptr Row
  COM_MTD_STD  get_Next  , :ptr ptr Cell
  COM_MTD_STD  get_Previous  , :ptr ptr Cell
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  Select  
  COM_MTD_STD  Delete  , :ptr VARIANT
  COM_MTD_STD  Formula  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  SetWidth  , :REAL4,:WdRulerStyle
  COM_MTD_STD  SetHeight  , :ptr VARIANT,:WdRowHeightRule
  COM_MTD_STD  Merge  , :ptr Cell
  COM_MTD_STD  Split  , :ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  AutoSum  
  COM_MTD_STD  get_Tables  , :ptr ptr Tables
  COM_MTD_STD  get_NestingLevel  , :ptr SDWORD
  COM_MTD_STD  get_WordWrap  , :ptr BOOL
  COM_MTD_STD  put_WordWrap  , :BOOL
  COM_MTD_STD  get_PreferredWidth  , :ptr REAL4
  COM_MTD_STD  put_PreferredWidth  , :REAL4
  COM_MTD_STD  get_FitText  , :ptr BOOL
  COM_MTD_STD  put_FitText  , :BOOL
  COM_MTD_STD  get_TopPadding  , :ptr REAL4
  COM_MTD_STD  put_TopPadding  , :REAL4
  COM_MTD_STD  get_BottomPadding  , :ptr REAL4
  COM_MTD_STD  put_BottomPadding  , :REAL4
  COM_MTD_STD  get_LeftPadding  , :ptr REAL4
  COM_MTD_STD  put_LeftPadding  , :REAL4
  COM_MTD_STD  get_RightPadding  , :ptr REAL4
  COM_MTD_STD  put_RightPadding  , :REAL4
  COM_MTD_STD  get_ID  , :ptr BSTR
  COM_MTD_STD  put_ID  , :BSTR
  COM_MTD_STD  get_PreferredWidthType  , :ptr WdPreferredWidthType
  COM_MTD_STD  put_PreferredWidthType  , :WdPreferredWidthType
COM_INTERFACE_END
endif

sIID_Cell textequ <IID {00002094Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Tables, Type=INTERFACE, GUID={0002094D-0000-0000-C000-000000000046}

ifndef TablesVtbl
COM_INTERFACE_BEG Tables, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Table
  COM_MTD_STD  AddOld  , :ptr Range,:SDWORD,:SDWORD,:ptr ptr Table
  COM_MTD_STD  Add_  , :ptr Range,:SDWORD,:SDWORD,:ptr VARIANT,:ptr VARIANT,:ptr ptr Table
  COM_MTD_STD  get_NestingLevel  , :ptr SDWORD
COM_INTERFACE_END
endif

sIID_Tables textequ <IID {00002094Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Rows, Type=INTERFACE, GUID={0002094C-0000-0000-C000-000000000046}

ifndef RowsVtbl
COM_INTERFACE_BEG Rows, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_AllowBreakAcrossPages  , :ptr SDWORD
  COM_MTD_STD  put_AllowBreakAcrossPages  , :SDWORD
  COM_MTD_STD  get_Alignment  , :ptr WdRowAlignment
  COM_MTD_STD  put_Alignment  , :WdRowAlignment
  COM_MTD_STD  get_HeadingFormat  , :ptr SDWORD
  COM_MTD_STD  put_HeadingFormat  , :SDWORD
  COM_MTD_STD  get_SpaceBetweenColumns  , :ptr REAL4
  COM_MTD_STD  put_SpaceBetweenColumns  , :REAL4
  COM_MTD_STD  get_Height  , :ptr REAL4
  COM_MTD_STD  put_Height  , :REAL4
  COM_MTD_STD  get_HeightRule  , :ptr WdRowHeightRule
  COM_MTD_STD  put_HeightRule  , :WdRowHeightRule
  COM_MTD_STD  get_LeftIndent  , :ptr REAL4
  COM_MTD_STD  put_LeftIndent  , :REAL4
  COM_MTD_STD  get_First  , :ptr ptr Row
  COM_MTD_STD  get_Last  , :ptr ptr Row
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Row
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr ptr Row
  COM_MTD_STD  Select  
  COM_MTD_STD  Delete  
  COM_MTD_STD  SetLeftIndent  , :REAL4,:WdRulerStyle
  COM_MTD_STD  SetHeight  , :REAL4,:WdRowHeightRule
  COM_MTD_STD  ConvertToTextOld  , :ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  DistributeHeight  
  COM_MTD_STD  ConvertToText  , :ptr VARIANT,:ptr VARIANT,:ptr ptr Range
  COM_MTD_STD  get_WrapAroundText  , :ptr SDWORD
  COM_MTD_STD  put_WrapAroundText  , :SDWORD
  COM_MTD_STD  get_DistanceTop  , :ptr REAL4
  COM_MTD_STD  put_DistanceTop  , :REAL4
  COM_MTD_STD  get_DistanceBottom  , :ptr REAL4
  COM_MTD_STD  put_DistanceBottom  , :REAL4
  COM_MTD_STD  get_DistanceLeft  , :ptr REAL4
  COM_MTD_STD  put_DistanceLeft  , :REAL4
  COM_MTD_STD  get_DistanceRight  , :ptr REAL4
  COM_MTD_STD  put_DistanceRight  , :REAL4
  COM_MTD_STD  get_HorizontalPosition  , :ptr REAL4
  COM_MTD_STD  put_HorizontalPosition  , :REAL4
  COM_MTD_STD  get_VerticalPosition  , :ptr REAL4
  COM_MTD_STD  put_VerticalPosition  , :REAL4
  COM_MTD_STD  get_RelativeHorizontalPosition  , :ptr WdRelativeHorizontalPosition
  COM_MTD_STD  put_RelativeHorizontalPosition  , :WdRelativeHorizontalPosition
  COM_MTD_STD  get_RelativeVerticalPosition  , :ptr WdRelativeVerticalPosition
  COM_MTD_STD  put_RelativeVerticalPosition  , :WdRelativeVerticalPosition
  COM_MTD_STD  get_AllowOverlap  , :ptr SDWORD
  COM_MTD_STD  put_AllowOverlap  , :SDWORD
  COM_MTD_STD  get_NestingLevel  , :ptr SDWORD
  COM_MTD_STD  get_TableDirection  , :ptr WdTableDirection
  COM_MTD_STD  put_TableDirection  , :WdTableDirection
COM_INTERFACE_END
endif

sIID_Rows textequ <IID {00002094Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Columns, Type=INTERFACE, GUID={0002094B-0000-0000-C000-000000000046}

ifndef ColumnsVtbl
COM_INTERFACE_BEG Columns, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_First  , :ptr ptr Column
  COM_MTD_STD  get_Last  , :ptr ptr Column
  COM_MTD_STD  get_Width  , :ptr REAL4
  COM_MTD_STD  put_Width  , :REAL4
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Column
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr ptr Column
  COM_MTD_STD  Select  
  COM_MTD_STD  Delete  
  COM_MTD_STD  SetWidth  , :REAL4,:WdRulerStyle
  COM_MTD_STD  AutoFit  
  COM_MTD_STD  DistributeWidth  
  COM_MTD_STD  get_NestingLevel  , :ptr SDWORD
  COM_MTD_STD  get_PreferredWidth  , :ptr REAL4
  COM_MTD_STD  put_PreferredWidth  , :REAL4
  COM_MTD_STD  get_PreferredWidthType  , :ptr WdPreferredWidthType
  COM_MTD_STD  put_PreferredWidthType  , :WdPreferredWidthType
COM_INTERFACE_END
endif

sIID_Columns textequ <IID {00002094Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Cells, Type=INTERFACE, GUID={0002094A-0000-0000-C000-000000000046}

ifndef CellsVtbl
COM_INTERFACE_BEG Cells, IDispatch
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Width  , :ptr REAL4
  COM_MTD_STD  put_Width  , :REAL4
  COM_MTD_STD  get_Height  , :ptr REAL4
  COM_MTD_STD  put_Height  , :REAL4
  COM_MTD_STD  get_HeightRule  , :ptr WdRowHeightRule
  COM_MTD_STD  put_HeightRule  , :WdRowHeightRule
  COM_MTD_STD  get_VerticalAlignment  , :ptr WdCellVerticalAlignment
  COM_MTD_STD  put_VerticalAlignment  , :WdCellVerticalAlignment
  COM_MTD_STD  get_Borders  , :ptr ptr Borders
  COM_MTD_STD  put_Borders  , :ptr Borders
  COM_MTD_STD  get_Shading  , :ptr ptr Shading
  COM_MTD_STD  Item  , :SDWORD,:ptr ptr Cell
  COM_MTD_STD  Add_  , :ptr VARIANT,:ptr ptr Cell
  COM_MTD_STD  Delete  , :ptr VARIANT
  COM_MTD_STD  SetWidth  , :REAL4,:WdRulerStyle
  COM_MTD_STD  SetHeight  , :ptr VARIANT,:WdRowHeightRule
  COM_MTD_STD  Merge  
  COM_MTD_STD  Split  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_MTD_STD  DistributeHeight  
  COM_MTD_STD  DistributeWidth  
  COM_MTD_STD  AutoFit  
  COM_MTD_STD  get_NestingLevel  , :ptr SDWORD
  COM_MTD_STD  get_PreferredWidth  , :ptr REAL4
  COM_MTD_STD  put_PreferredWidth  , :REAL4
  COM_MTD_STD  get_PreferredWidthType  , :ptr WdPreferredWidthType
  COM_MTD_STD  put_PreferredWidthType  , :WdPreferredWidthType
COM_INTERFACE_END
endif

sIID_Cells textequ <IID {00002094Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- AutoCorrect, Type=INTERFACE, GUID={00020949-0000-0000-C000-000000000046}

ifndef AutoCorrectVtbl
COM_INTERFACE_BEG AutoCorrect, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_CorrectDays  , :ptr BOOL
  COM_MTD_STD  put_CorrectDays  , :BOOL
  COM_MTD_STD  get_CorrectInitialCaps  , :ptr BOOL
  COM_MTD_STD  put_CorrectInitialCaps  , :BOOL
  COM_MTD_STD  get_CorrectSentenceCaps  , :ptr BOOL
  COM_MTD_STD  put_CorrectSentenceCaps  , :BOOL
  COM_MTD_STD  get_ReplaceText  , :ptr BOOL
  COM_MTD_STD  put_ReplaceText  , :BOOL
  COM_MTD_STD  get_Entries  , :ptr ptr AutoCorrectEntries
  COM_MTD_STD  get_FirstLetterExceptions  , :ptr ptr FirstLetterExceptions
  COM_MTD_STD  get_FirstLetterAutoAdd  , :ptr BOOL
  COM_MTD_STD  put_FirstLetterAutoAdd  , :BOOL
  COM_MTD_STD  get_TwoInitialCapsExceptions  , :ptr ptr TwoInitialCapsExceptions
  COM_MTD_STD  get_TwoInitialCapsAutoAdd  , :ptr BOOL
  COM_MTD_STD  put_TwoInitialCapsAutoAdd  , :BOOL
  COM_MTD_STD  get_CorrectCapsLock  , :ptr BOOL
  COM_MTD_STD  put_CorrectCapsLock  , :BOOL
  COM_MTD_STD  get_CorrectHangulAndAlphabet  , :ptr BOOL
  COM_MTD_STD  put_CorrectHangulAndAlphabet  , :BOOL
  COM_MTD_STD  get_HangulAndAlphabetExceptions  , :ptr ptr HangulAndAlphabetExceptions
  COM_MTD_STD  get_HangulAndAlphabetAutoAdd  , :ptr BOOL
  COM_MTD_STD  put_HangulAndAlphabetAutoAdd  , :BOOL
  COM_MTD_STD  get_ReplaceTextFromSpellingChecker  , :ptr BOOL
  COM_MTD_STD  put_ReplaceTextFromSpellingChecker  , :BOOL
  COM_MTD_STD  get_OtherCorrectionsAutoAdd  , :ptr BOOL
  COM_MTD_STD  put_OtherCorrectionsAutoAdd  , :BOOL
  COM_MTD_STD  get_OtherCorrectionsExceptions  , :ptr ptr OtherCorrectionsExceptions
  COM_MTD_STD  get_CorrectKeyboardSetting  , :ptr BOOL
  COM_MTD_STD  put_CorrectKeyboardSetting  , :BOOL
COM_INTERFACE_END
endif

sIID_AutoCorrect textequ <IID {000020949h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- AutoCorrectEntries, Type=INTERFACE, GUID={00020948-0000-0000-C000-000000000046}

ifndef AutoCorrectEntriesVtbl
COM_INTERFACE_BEG AutoCorrectEntries, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr AutoCorrectEntry
  COM_MTD_STD  Add_  , :BSTR,:BSTR,:ptr ptr AutoCorrectEntry
  COM_MTD_STD  AddRichText  , :BSTR,:ptr Range,:ptr ptr AutoCorrectEntry
COM_INTERFACE_END
endif

sIID_AutoCorrectEntries textequ <IID {000020948h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- AutoCorrectEntry, Type=INTERFACE, GUID={00020947-0000-0000-C000-000000000046}

ifndef AutoCorrectEntryVtbl
COM_INTERFACE_BEG AutoCorrectEntry, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  put_Name  , :BSTR
  COM_MTD_STD  get_Value  , :ptr BSTR
  COM_MTD_STD  put_Value  , :BSTR
  COM_MTD_STD  get_RichText  , :ptr BOOL
  COM_MTD_STD  Delete  
  COM_MTD_STD  Apply  , :ptr Range
COM_INTERFACE_END
endif

sIID_AutoCorrectEntry textequ <IID {000020947h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- EmailAuthor, Type=INTERFACE, GUID={000209D7-0000-0000-C000-000000000046}

ifndef EmailAuthorVtbl
COM_INTERFACE_BEG EmailAuthor, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Style  , :ptr ptr Style
COM_INTERFACE_END
endif

sIID_EmailAuthor textequ <IID {0000209D7h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- EmailOptions, Type=INTERFACE, GUID={000209DB-0000-0000-C000-000000000046}

ifndef EmailOptionsVtbl
COM_INTERFACE_BEG EmailOptions, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_UseThemeStyle  , :ptr BOOL
  COM_MTD_STD  put_UseThemeStyle  , :BOOL
  COM_MTD_STD  get_MarkCommentsWith  , :ptr BSTR
  COM_MTD_STD  put_MarkCommentsWith  , :BSTR
  COM_MTD_STD  get_MarkComments  , :ptr BOOL
  COM_MTD_STD  put_MarkComments  , :BOOL
  COM_MTD_STD  get_EmailSignature  , :ptr ptr EmailSignature
  COM_MTD_STD  get_ComposeStyle  , :ptr ptr Style
  COM_MTD_STD  get_ReplyStyle  , :ptr ptr Style
  COM_MTD_STD  get_ThemeName  , :ptr BSTR
  COM_MTD_STD  put_ThemeName  , :BSTR
COM_INTERFACE_END
endif

sIID_EmailOptions textequ <IID {0000209DBh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- EmailSignature, Type=INTERFACE, GUID={000209DC-0000-0000-C000-000000000046}

ifndef EmailSignatureVtbl
COM_INTERFACE_BEG EmailSignature, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_NewMessageSignature  , :ptr BSTR
  COM_MTD_STD  put_NewMessageSignature  , :BSTR
  COM_MTD_STD  get_ReplyMessageSignature  , :ptr BSTR
  COM_MTD_STD  put_ReplyMessageSignature  , :BSTR
COM_INTERFACE_END
endif

sIID_EmailSignature textequ <IID {0000209DCh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Email, Type=INTERFACE, GUID={000209DD-0000-0000-C000-000000000046}

ifndef EmailVtbl
COM_INTERFACE_BEG Email, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_CurrentEmailAuthor  , :ptr ptr EmailAuthor
COM_INTERFACE_END
endif

sIID_Email textequ <IID {0000209DDh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- HorizontalLineFormat, Type=INTERFACE, GUID={000209DE-0000-0000-C000-000000000046}

ifndef HorizontalLineFormatVtbl
COM_INTERFACE_BEG HorizontalLineFormat, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_PercentWidth  , :ptr REAL4
  COM_MTD_STD  put_PercentWidth  , :REAL4
  COM_MTD_STD  get_NoShade  , :ptr BOOL
  COM_MTD_STD  put_NoShade  , :BOOL
  COM_MTD_STD  get_Alignment  , :ptr WdHorizontalLineAlignment
  COM_MTD_STD  put_Alignment  , :WdHorizontalLineAlignment
  COM_MTD_STD  get_WidthType  , :ptr WdHorizontalLineWidthType
  COM_MTD_STD  put_WidthType  , :WdHorizontalLineWidthType
COM_INTERFACE_END
endif

sIID_HorizontalLineFormat textequ <IID {0000209DEh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Frameset, Type=INTERFACE, GUID={000209E2-0000-0000-C000-000000000046}

ifndef FramesetVtbl
COM_INTERFACE_BEG Frameset, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_ParentFrameset  , :ptr ptr Frameset
  COM_MTD_STD  get_Type  , :ptr WdFramesetType
  COM_MTD_STD  get_WidthType  , :ptr WdFramesetSizeType
  COM_MTD_STD  put_WidthType  , :WdFramesetSizeType
  COM_MTD_STD  get_HeightType  , :ptr WdFramesetSizeType
  COM_MTD_STD  put_HeightType  , :WdFramesetSizeType
  COM_MTD_STD  get_Width  , :ptr SDWORD
  COM_MTD_STD  put_Width  , :SDWORD
  COM_MTD_STD  get_Height  , :ptr SDWORD
  COM_MTD_STD  put_Height  , :SDWORD
  COM_MTD_STD  get_ChildFramesetCount  , :ptr SDWORD
  COM_MTD_STD  get_ChildFramesetItem  , :SDWORD,:ptr ptr Frameset
  COM_MTD_STD  get_FramesetBorderWidth  , :ptr REAL4
  COM_MTD_STD  put_FramesetBorderWidth  , :REAL4
  COM_MTD_STD  get_FramesetBorderColor  , :ptr WdColor
  COM_MTD_STD  put_FramesetBorderColor  , :WdColor
  COM_MTD_STD  get_FrameScrollbarType  , :ptr WdScrollbarType
  COM_MTD_STD  put_FrameScrollbarType  , :WdScrollbarType
  COM_MTD_STD  get_FrameResizable  , :ptr BOOL
  COM_MTD_STD  put_FrameResizable  , :BOOL
  COM_MTD_STD  get_FrameName  , :ptr BSTR
  COM_MTD_STD  put_FrameName  , :BSTR
  COM_MTD_STD  get_FrameDisplayBorders  , :ptr BOOL
  COM_MTD_STD  put_FrameDisplayBorders  , :BOOL
  COM_MTD_STD  get_FrameDefaultURL  , :ptr BSTR
  COM_MTD_STD  put_FrameDefaultURL  , :BSTR
  COM_MTD_STD  get_FrameLinkToFile  , :ptr BOOL
  COM_MTD_STD  put_FrameLinkToFile  , :BOOL
  COM_MTD_STD  AddNewFrame  , :WdFramesetNewFrameLocation,:ptr ptr Frameset
  COM_MTD_STD  Delete  
COM_INTERFACE_END
endif

sIID_Frameset textequ <IID {0000209E2h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- DefaultWebOptions, Type=INTERFACE, GUID={000209E3-0000-0000-C000-000000000046}

ifndef DefaultWebOptionsVtbl
COM_INTERFACE_BEG DefaultWebOptions, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_OptimizeForBrowser  , :ptr BOOL
  COM_MTD_STD  put_OptimizeForBrowser  , :BOOL
  COM_MTD_STD  get_BrowserLevel  , :ptr WdBrowserLevel
  COM_MTD_STD  put_BrowserLevel  , :WdBrowserLevel
  COM_MTD_STD  get_RelyOnCSS  , :ptr BOOL
  COM_MTD_STD  put_RelyOnCSS  , :BOOL
  COM_MTD_STD  get_OrganizeInFolder  , :ptr BOOL
  COM_MTD_STD  put_OrganizeInFolder  , :BOOL
  COM_MTD_STD  get_UpdateLinksOnSave  , :ptr BOOL
  COM_MTD_STD  put_UpdateLinksOnSave  , :BOOL
  COM_MTD_STD  get_UseLongFileNames  , :ptr BOOL
  COM_MTD_STD  put_UseLongFileNames  , :BOOL
  COM_MTD_STD  get_CheckIfOfficeIsHTMLEditor  , :ptr BOOL
  COM_MTD_STD  put_CheckIfOfficeIsHTMLEditor  , :BOOL
  COM_MTD_STD  get_CheckIfWordIsDefaultHTMLEditor  , :ptr BOOL
  COM_MTD_STD  put_CheckIfWordIsDefaultHTMLEditor  , :BOOL
  COM_MTD_STD  get_RelyOnVML  , :ptr BOOL
  COM_MTD_STD  put_RelyOnVML  , :BOOL
  COM_MTD_STD  get_AllowPNG  , :ptr BOOL
  COM_MTD_STD  put_AllowPNG  , :BOOL
  COM_MTD_STD  get_ScreenSize  , :ptr MsoScreenSize
  COM_MTD_STD  put_ScreenSize  , :MsoScreenSize
  COM_MTD_STD  get_PixelsPerInch  , :ptr SDWORD
  COM_MTD_STD  put_PixelsPerInch  , :SDWORD
  COM_MTD_STD  get_Encoding  , :ptr MsoEncoding
  COM_MTD_STD  put_Encoding  , :MsoEncoding
  COM_MTD_STD  get_AlwaysSaveInDefaultEncoding  , :ptr BOOL
  COM_MTD_STD  put_AlwaysSaveInDefaultEncoding  , :BOOL
  COM_MTD_STD  get_Fonts  , :ptr ptr WebPageFonts
  COM_MTD_STD  get_FolderSuffix  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_DefaultWebOptions textequ <IID {0000209E3h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- WebOptions, Type=INTERFACE, GUID={000209E4-0000-0000-C000-000000000046}

ifndef WebOptionsVtbl
COM_INTERFACE_BEG WebOptions, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_OptimizeForBrowser  , :ptr BOOL
  COM_MTD_STD  put_OptimizeForBrowser  , :BOOL
  COM_MTD_STD  get_BrowserLevel  , :ptr WdBrowserLevel
  COM_MTD_STD  put_BrowserLevel  , :WdBrowserLevel
  COM_MTD_STD  get_RelyOnCSS  , :ptr BOOL
  COM_MTD_STD  put_RelyOnCSS  , :BOOL
  COM_MTD_STD  get_OrganizeInFolder  , :ptr BOOL
  COM_MTD_STD  put_OrganizeInFolder  , :BOOL
  COM_MTD_STD  get_UseLongFileNames  , :ptr BOOL
  COM_MTD_STD  put_UseLongFileNames  , :BOOL
  COM_MTD_STD  get_RelyOnVML  , :ptr BOOL
  COM_MTD_STD  put_RelyOnVML  , :BOOL
  COM_MTD_STD  get_AllowPNG  , :ptr BOOL
  COM_MTD_STD  put_AllowPNG  , :BOOL
  COM_MTD_STD  get_ScreenSize  , :ptr MsoScreenSize
  COM_MTD_STD  put_ScreenSize  , :MsoScreenSize
  COM_MTD_STD  get_PixelsPerInch  , :ptr SDWORD
  COM_MTD_STD  put_PixelsPerInch  , :SDWORD
  COM_MTD_STD  get_Encoding  , :ptr MsoEncoding
  COM_MTD_STD  put_Encoding  , :MsoEncoding
  COM_MTD_STD  get_FolderSuffix  , :ptr BSTR
  COM_MTD_STD  UseDefaultFolderSuffix  
COM_INTERFACE_END
endif

sIID_WebOptions textequ <IID {0000209E4h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- OtherCorrectionsExceptions, Type=INTERFACE, GUID={000209DF-0000-0000-C000-000000000046}

ifndef OtherCorrectionsExceptionsVtbl
COM_INTERFACE_BEG OtherCorrectionsExceptions, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get__NewEnum  , :ptr LPUNKNOWN
  COM_MTD_STD  get_Count  , :ptr SDWORD
  COM_MTD_STD  Item  , :ptr VARIANT,:ptr ptr OtherCorrectionsException
  COM_MTD_STD  Add_  , :BSTR,:ptr ptr OtherCorrectionsException
COM_INTERFACE_END
endif

sIID_OtherCorrectionsExceptions textequ <IID {0000209DFh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- OtherCorrectionsException, Type=INTERFACE, GUID={000209E1-0000-0000-C000-000000000046}

ifndef OtherCorrectionsExceptionVtbl
COM_INTERFACE_BEG OtherCorrectionsException, IDispatch
  COM_MTD_STD  get_Application  , :ptr ptr Application
  COM_MTD_STD  get_Creator  , :ptr SDWORD
  COM_MTD_STD  get_Parent  , :ptr LPDISPATCH
  COM_MTD_STD  get_Index  , :ptr SDWORD
  COM_MTD_STD  get_Name  , :ptr BSTR
  COM_MTD_STD  Delete  
COM_INTERFACE_END
endif

sIID_OtherCorrectionsException textequ <IID {0000209E1h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- ApplicationEvents, Type=DISPATCH, GUID={000209F7-0000-0000-C000-000000000046}

;--- dispinterface only
ifndef ApplicationEventsVtbl
COM_INTERFACE_BEG ApplicationEvents, IDispatch
COM_INTERFACE_END
endif

sIID_ApplicationEvents textequ <IID {0000209F7h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- DocumentEvents, Type=DISPATCH, GUID={000209F6-0000-0000-C000-000000000046}

;--- dispinterface only
ifndef DocumentEventsVtbl
COM_INTERFACE_BEG DocumentEvents, IDispatch
  COM_MTD_DSP  New  
  COM_MTD_DSP  Open  
  COM_MTD_DSP  Close  
COM_INTERFACE_END
endif

sIID_DocumentEvents textequ <IID {0000209F6h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- ApplicationEvents2, Type=DISPATCH, GUID={000209FE-0000-0000-C000-000000000046}

;--- dispinterface only
ifndef ApplicationEvents2Vtbl
COM_INTERFACE_BEG ApplicationEvents2, IDispatch
  COM_MTD_DSP  Startup  
  COM_MTD_DSP  Quit  
  COM_MTD_DSP  DocumentChange  
  COM_MTD_DSP  DocumentOpen  , :ptr Document
  COM_MTD_DSP  DocumentBeforeClose  , :ptr Document,:ptr BOOL
  COM_MTD_DSP  DocumentBeforePrint  , :ptr Document,:ptr BOOL
  COM_MTD_DSP  DocumentBeforeSave  , :ptr Document,:ptr BOOL,:ptr BOOL
  COM_MTD_DSP  NewDocument  , :ptr Document
  COM_MTD_DSP  WindowActivate  , :ptr Document,:ptr Window
  COM_MTD_DSP  WindowDeactivate  , :ptr Document,:ptr Window
  COM_MTD_DSP  WindowSelectionChange  , :ptr Selection
  COM_MTD_DSP  WindowBeforeRightClick  , :ptr Selection,:ptr BOOL
  COM_MTD_DSP  WindowBeforeDoubleClick  , :ptr Selection,:ptr BOOL
COM_INTERFACE_END
endif

sIID_ApplicationEvents2 textequ <IID {0000209FEh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- OCXEvents, Type=DISPATCH, GUID={000209F3-0000-0000-C000-000000000046}

;--- dispinterface only
ifndef OCXEventsVtbl
COM_INTERFACE_BEG OCXEvents, IDispatch
  COM_MTD_DSP  GotFocus  
  COM_MTD_DSP  LostFocus  
COM_INTERFACE_END
endif

sIID_OCXEvents textequ <IID {0000209F3h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Application, Type=COCLASS, GUID={000209FF-0000-0000-C000-000000000046}

sCLSID_Application textequ <GUID {0000209FFh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- OLEControl, Type=COCLASS, GUID={000209F2-0000-0000-C000-000000000046}

sCLSID_OLEControl textequ <GUID {0000209F2h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- LetterContent, Type=COCLASS, GUID={000209F1-0000-0000-C000-000000000046}

sCLSID_LetterContent textequ <GUID {0000209F1h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Global, Type=COCLASS, GUID={000209F0-0000-0000-C000-000000000046}

sCLSID_Global textequ <GUID {0000209F0h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Document, Type=COCLASS, GUID={00020906-0000-0000-C000-000000000046}

sCLSID_Document textequ <GUID {000020906h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- Font, Type=COCLASS, GUID={000209F5-0000-0000-C000-000000000046}

sCLSID_Font textequ <GUID {0000209F5h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- ParagraphFormat, Type=COCLASS, GUID={000209F4-0000-0000-C000-000000000046}

sCLSID_ParagraphFormat textequ <GUID {0000209F4h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>

;--- end of type library ---