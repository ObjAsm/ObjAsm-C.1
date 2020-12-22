
;--- Generated .INC file by COMView
;--- typelib name=Office
;--- documentation=Microsoft Office 10.0 Object Library
;--- GUID={2DF8D04C-5BFA-101B-BDE5-00AA0044DE52}
;--- Version 2.2, LCID 0

;--- prototypes too complex for MASM may exist
;--- if such ones reside in a vtable they will be replaced by dummies
;--- search for occurances of ';+++' to have a closer look at these

;sTLBID_Office textequ <GUID {02DF8D04Ch,05BFAh,0101Bh,{0BDh,0E5h,000h,0AAh,000h,044h,0DEh,052h}}>
;_MajorVer_Office equ 2
;_MinorVer_Office equ 2
;
;;--- MsoLineDashStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoLineDashStyle typedef SDWORD
;msoLineDashStyleMixed  EQU  -2      ;=0FFFFFFFEh
;msoLineSolid  EQU  1
;msoLineSquareDot  EQU  2
;msoLineRoundDot  EQU  3
;msoLineDash  EQU  4
;msoLineDashDot  EQU  5
;msoLineDashDotDot  EQU  6
;msoLineLongDash  EQU  7
;msoLineLongDashDot  EQU  8
;
;;--- MsoLineStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoLineStyle typedef SDWORD
;msoLineStyleMixed  EQU  -2      ;=0FFFFFFFEh
;msoLineSingle  EQU  1
;msoLineThinThin  EQU  2
;msoLineThinThick  EQU  3
;msoLineThickThin  EQU  4
;msoLineThickBetweenThin  EQU  5
;
;;--- MsoArrowheadStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoArrowheadStyle typedef SDWORD
;msoArrowheadStyleMixed  EQU  -2      ;=0FFFFFFFEh
;msoArrowheadNone  EQU  1
;msoArrowheadTriangle  EQU  2
;msoArrowheadOpen  EQU  3
;msoArrowheadStealth  EQU  4
;msoArrowheadDiamond  EQU  5
;msoArrowheadOval  EQU  6
;
;;--- MsoArrowheadWidth, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoArrowheadWidth typedef SDWORD
;msoArrowheadWidthMixed  EQU  -2      ;=0FFFFFFFEh
;msoArrowheadNarrow  EQU  1
;msoArrowheadWidthMedium  EQU  2
;msoArrowheadWide  EQU  3
;
;;--- MsoArrowheadLength, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoArrowheadLength typedef SDWORD
;msoArrowheadLengthMixed  EQU  -2      ;=0FFFFFFFEh
;msoArrowheadShort  EQU  1
;msoArrowheadLengthMedium  EQU  2
;msoArrowheadLong  EQU  3
;
;;--- MsoFillType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFillType typedef SDWORD
;msoFillMixed  EQU  -2      ;=0FFFFFFFEh
;msoFillSolid  EQU  1
;msoFillPatterned  EQU  2
;msoFillGradient  EQU  3
;msoFillTextured  EQU  4
;msoFillBackground  EQU  5
;msoFillPicture  EQU  6
;
;;--- MsoGradientStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoGradientStyle typedef SDWORD
;msoGradientMixed  EQU  -2      ;=0FFFFFFFEh
;msoGradientHorizontal  EQU  1
;msoGradientVertical  EQU  2
;msoGradientDiagonalUp  EQU  3
;msoGradientDiagonalDown  EQU  4
;msoGradientFromCorner  EQU  5
;msoGradientFromTitle  EQU  6
;msoGradientFromCenter  EQU  7
;
;;--- MsoGradientColorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoGradientColorType typedef SDWORD
;msoGradientColorMixed  EQU  -2      ;=0FFFFFFFEh
;msoGradientOneColor  EQU  1
;msoGradientTwoColors  EQU  2
;msoGradientPresetColors  EQU  3
;
;;--- MsoTextureType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoTextureType typedef SDWORD
;msoTextureTypeMixed  EQU  -2      ;=0FFFFFFFEh
;msoTexturePreset  EQU  1
;msoTextureUserDefined  EQU  2
;
;;--- MsoPresetTexture, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetTexture typedef SDWORD
;msoPresetTextureMixed  EQU  -2      ;=0FFFFFFFEh
;msoTexturePapyrus  EQU  1
;msoTextureCanvas  EQU  2
;msoTextureDenim  EQU  3
;msoTextureWovenMat  EQU  4
;msoTextureWaterDroplets  EQU  5
;msoTexturePaperBag  EQU  6
;msoTextureFishFossil  EQU  7
;msoTextureSand  EQU  8
;msoTextureGreenMarble  EQU  9
;msoTextureWhiteMarble  EQU  10
;msoTextureBrownMarble  EQU  11
;msoTextureGranite  EQU  12
;msoTextureNewsprint  EQU  13
;msoTextureRecycledPaper  EQU  14
;msoTextureParchment  EQU  15
;msoTextureStationery  EQU  16      ;=010h
;msoTextureBlueTissuePaper  EQU  17      ;=011h
;msoTexturePinkTissuePaper  EQU  18      ;=012h
;msoTexturePurpleMesh  EQU  19      ;=013h
;msoTextureBouquet  EQU  20      ;=014h
;msoTextureCork  EQU  21      ;=015h
;msoTextureWalnut  EQU  22      ;=016h
;msoTextureOak  EQU  23      ;=017h
;msoTextureMediumWood  EQU  24      ;=018h
;
;;--- MsoPatternType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPatternType typedef SDWORD
;msoPatternMixed  EQU  -2      ;=0FFFFFFFEh
;msoPattern5Percent  EQU  1
;msoPattern10Percent  EQU  2
;msoPattern20Percent  EQU  3
;msoPattern25Percent  EQU  4
;msoPattern30Percent  EQU  5
;msoPattern40Percent  EQU  6
;msoPattern50Percent  EQU  7
;msoPattern60Percent  EQU  8
;msoPattern70Percent  EQU  9
;msoPattern75Percent  EQU  10
;msoPattern80Percent  EQU  11
;msoPattern90Percent  EQU  12
;msoPatternDarkHorizontal  EQU  13
;msoPatternDarkVertical  EQU  14
;msoPatternDarkDownwardDiagonal  EQU  15
;msoPatternDarkUpwardDiagonal  EQU  16      ;=010h
;msoPatternSmallCheckerBoard  EQU  17      ;=011h
;msoPatternTrellis  EQU  18      ;=012h
;msoPatternLightHorizontal  EQU  19      ;=013h
;msoPatternLightVertical  EQU  20      ;=014h
;msoPatternLightDownwardDiagonal  EQU  21      ;=015h
;msoPatternLightUpwardDiagonal  EQU  22      ;=016h
;msoPatternSmallGrid  EQU  23      ;=017h
;msoPatternDottedDiamond  EQU  24      ;=018h
;msoPatternWideDownwardDiagonal  EQU  25      ;=019h
;msoPatternWideUpwardDiagonal  EQU  26      ;=01Ah
;msoPatternDashedUpwardDiagonal  EQU  27      ;=01Bh
;msoPatternDashedDownwardDiagonal  EQU  28      ;=01Ch
;msoPatternNarrowVertical  EQU  29      ;=01Dh
;msoPatternNarrowHorizontal  EQU  30      ;=01Eh
;msoPatternDashedVertical  EQU  31      ;=01Fh
;msoPatternDashedHorizontal  EQU  32      ;=020h
;msoPatternLargeConfetti  EQU  33      ;=021h
;msoPatternLargeGrid  EQU  34      ;=022h
;msoPatternHorizontalBrick  EQU  35      ;=023h
;msoPatternLargeCheckerBoard  EQU  36      ;=024h
;msoPatternSmallConfetti  EQU  37      ;=025h
;msoPatternZigZag  EQU  38      ;=026h
;msoPatternSolidDiamond  EQU  39      ;=027h
;msoPatternDiagonalBrick  EQU  40      ;=028h
;msoPatternOutlinedDiamond  EQU  41      ;=029h
;msoPatternPlaid  EQU  42      ;=02Ah
;msoPatternSphere  EQU  43      ;=02Bh
;msoPatternWeave  EQU  44      ;=02Ch
;msoPatternDottedGrid  EQU  45      ;=02Dh
;msoPatternDivot  EQU  46      ;=02Eh
;msoPatternShingle  EQU  47      ;=02Fh
;msoPatternWave  EQU  48      ;=030h
;
;;--- MsoPresetGradientType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetGradientType typedef SDWORD
;msoPresetGradientMixed  EQU  -2      ;=0FFFFFFFEh
;msoGradientEarlySunset  EQU  1
;msoGradientLateSunset  EQU  2
;msoGradientNightfall  EQU  3
;msoGradientDaybreak  EQU  4
;msoGradientHorizon  EQU  5
;msoGradientDesert  EQU  6
;msoGradientOcean  EQU  7
;msoGradientCalmWater  EQU  8
;msoGradientFire  EQU  9
;msoGradientFog  EQU  10
;msoGradientMoss  EQU  11
;msoGradientPeacock  EQU  12
;msoGradientWheat  EQU  13
;msoGradientParchment  EQU  14
;msoGradientMahogany  EQU  15
;msoGradientRainbow  EQU  16      ;=010h
;msoGradientRainbowII  EQU  17      ;=011h
;msoGradientGold  EQU  18      ;=012h
;msoGradientGoldII  EQU  19      ;=013h
;msoGradientBrass  EQU  20      ;=014h
;msoGradientChrome  EQU  21      ;=015h
;msoGradientChromeII  EQU  22      ;=016h
;msoGradientSilver  EQU  23      ;=017h
;msoGradientSapphire  EQU  24      ;=018h
;
;;--- MsoShadowType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoShadowType typedef SDWORD
;msoShadowMixed  EQU  -2      ;=0FFFFFFFEh
;msoShadow1  EQU  1
;msoShadow2  EQU  2
;msoShadow3  EQU  3
;msoShadow4  EQU  4
;msoShadow5  EQU  5
;msoShadow6  EQU  6
;msoShadow7  EQU  7
;msoShadow8  EQU  8
;msoShadow9  EQU  9
;msoShadow10  EQU  10
;msoShadow11  EQU  11
;msoShadow12  EQU  12
;msoShadow13  EQU  13
;msoShadow14  EQU  14
;msoShadow15  EQU  15
;msoShadow16  EQU  16      ;=010h
;msoShadow17  EQU  17      ;=011h
;msoShadow18  EQU  18      ;=012h
;msoShadow19  EQU  19      ;=013h
;msoShadow20  EQU  20      ;=014h
;
;;--- MsoPresetTextEffect, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetTextEffect typedef SDWORD
;msoTextEffectMixed  EQU  -2      ;=0FFFFFFFEh
;msoTextEffect1  EQU  0
;msoTextEffect2  EQU  1
;msoTextEffect3  EQU  2
;msoTextEffect4  EQU  3
;msoTextEffect5  EQU  4
;msoTextEffect6  EQU  5
;msoTextEffect7  EQU  6
;msoTextEffect8  EQU  7
;msoTextEffect9  EQU  8
;msoTextEffect10  EQU  9
;msoTextEffect11  EQU  10
;msoTextEffect12  EQU  11
;msoTextEffect13  EQU  12
;msoTextEffect14  EQU  13
;msoTextEffect15  EQU  14
;msoTextEffect16  EQU  15
;msoTextEffect17  EQU  16      ;=010h
;msoTextEffect18  EQU  17      ;=011h
;msoTextEffect19  EQU  18      ;=012h
;msoTextEffect20  EQU  19      ;=013h
;msoTextEffect21  EQU  20      ;=014h
;msoTextEffect22  EQU  21      ;=015h
;msoTextEffect23  EQU  22      ;=016h
;msoTextEffect24  EQU  23      ;=017h
;msoTextEffect25  EQU  24      ;=018h
;msoTextEffect26  EQU  25      ;=019h
;msoTextEffect27  EQU  26      ;=01Ah
;msoTextEffect28  EQU  27      ;=01Bh
;msoTextEffect29  EQU  28      ;=01Ch
;msoTextEffect30  EQU  29      ;=01Dh
;
;;--- MsoPresetTextEffectShape, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetTextEffectShape typedef SDWORD
;msoTextEffectShapeMixed  EQU  -2      ;=0FFFFFFFEh
;msoTextEffectShapePlainText  EQU  1
;msoTextEffectShapeStop  EQU  2
;msoTextEffectShapeTriangleUp  EQU  3
;msoTextEffectShapeTriangleDown  EQU  4
;msoTextEffectShapeChevronUp  EQU  5
;msoTextEffectShapeChevronDown  EQU  6
;msoTextEffectShapeRingInside  EQU  7
;msoTextEffectShapeRingOutside  EQU  8
;msoTextEffectShapeArchUpCurve  EQU  9
;msoTextEffectShapeArchDownCurve  EQU  10
;msoTextEffectShapeCircleCurve  EQU  11
;msoTextEffectShapeButtonCurve  EQU  12
;msoTextEffectShapeArchUpPour  EQU  13
;msoTextEffectShapeArchDownPour  EQU  14
;msoTextEffectShapeCirclePour  EQU  15
;msoTextEffectShapeButtonPour  EQU  16      ;=010h
;msoTextEffectShapeCurveUp  EQU  17      ;=011h
;msoTextEffectShapeCurveDown  EQU  18      ;=012h
;msoTextEffectShapeCanUp  EQU  19      ;=013h
;msoTextEffectShapeCanDown  EQU  20      ;=014h
;msoTextEffectShapeWave1  EQU  21      ;=015h
;msoTextEffectShapeWave2  EQU  22      ;=016h
;msoTextEffectShapeDoubleWave1  EQU  23      ;=017h
;msoTextEffectShapeDoubleWave2  EQU  24      ;=018h
;msoTextEffectShapeInflate  EQU  25      ;=019h
;msoTextEffectShapeDeflate  EQU  26      ;=01Ah
;msoTextEffectShapeInflateBottom  EQU  27      ;=01Bh
;msoTextEffectShapeDeflateBottom  EQU  28      ;=01Ch
;msoTextEffectShapeInflateTop  EQU  29      ;=01Dh
;msoTextEffectShapeDeflateTop  EQU  30      ;=01Eh
;msoTextEffectShapeDeflateInflate  EQU  31      ;=01Fh
;msoTextEffectShapeDeflateInflateDeflate  EQU  32      ;=020h
;msoTextEffectShapeFadeRight  EQU  33      ;=021h
;msoTextEffectShapeFadeLeft  EQU  34      ;=022h
;msoTextEffectShapeFadeUp  EQU  35      ;=023h
;msoTextEffectShapeFadeDown  EQU  36      ;=024h
;msoTextEffectShapeSlantUp  EQU  37      ;=025h
;msoTextEffectShapeSlantDown  EQU  38      ;=026h
;msoTextEffectShapeCascadeUp  EQU  39      ;=027h
;msoTextEffectShapeCascadeDown  EQU  40      ;=028h
;
;;--- MsoTextEffectAlignment, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoTextEffectAlignment typedef SDWORD
;msoTextEffectAlignmentMixed  EQU  -2      ;=0FFFFFFFEh
;msoTextEffectAlignmentLeft  EQU  1
;msoTextEffectAlignmentCentered  EQU  2
;msoTextEffectAlignmentRight  EQU  3
;msoTextEffectAlignmentLetterJustify  EQU  4
;msoTextEffectAlignmentWordJustify  EQU  5
;msoTextEffectAlignmentStretchJustify  EQU  6
;
;;--- MsoPresetLightingDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetLightingDirection typedef SDWORD
;msoPresetLightingDirectionMixed  EQU  -2      ;=0FFFFFFFEh
;msoLightingTopLeft  EQU  1
;msoLightingTop  EQU  2
;msoLightingTopRight  EQU  3
;msoLightingLeft  EQU  4
;msoLightingNone  EQU  5
;msoLightingRight  EQU  6
;msoLightingBottomLeft  EQU  7
;msoLightingBottom  EQU  8
;msoLightingBottomRight  EQU  9
;
;;--- MsoPresetLightingSoftness, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetLightingSoftness typedef SDWORD
;msoPresetLightingSoftnessMixed  EQU  -2      ;=0FFFFFFFEh
;msoLightingDim  EQU  1
;msoLightingNormal  EQU  2
;msoLightingBright  EQU  3
;
;;--- MsoPresetMaterial, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetMaterial typedef SDWORD
;msoPresetMaterialMixed  EQU  -2      ;=0FFFFFFFEh
;msoMaterialMatte  EQU  1
;msoMaterialPlastic  EQU  2
;msoMaterialMetal  EQU  3
;msoMaterialWireFrame  EQU  4
;
;;--- MsoPresetExtrusionDirection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetExtrusionDirection typedef SDWORD
;msoPresetExtrusionDirectionMixed  EQU  -2      ;=0FFFFFFFEh
;msoExtrusionBottomRight  EQU  1
;msoExtrusionBottom  EQU  2
;msoExtrusionBottomLeft  EQU  3
;msoExtrusionRight  EQU  4
;msoExtrusionNone  EQU  5
;msoExtrusionLeft  EQU  6
;msoExtrusionTopRight  EQU  7
;msoExtrusionTop  EQU  8
;msoExtrusionTopLeft  EQU  9
;
;;--- MsoPresetThreeDFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPresetThreeDFormat typedef SDWORD
;msoPresetThreeDFormatMixed  EQU  -2      ;=0FFFFFFFEh
;msoThreeD1  EQU  1
;msoThreeD2  EQU  2
;msoThreeD3  EQU  3
;msoThreeD4  EQU  4
;msoThreeD5  EQU  5
;msoThreeD6  EQU  6
;msoThreeD7  EQU  7
;msoThreeD8  EQU  8
;msoThreeD9  EQU  9
;msoThreeD10  EQU  10
;msoThreeD11  EQU  11
;msoThreeD12  EQU  12
;msoThreeD13  EQU  13
;msoThreeD14  EQU  14
;msoThreeD15  EQU  15
;msoThreeD16  EQU  16      ;=010h
;msoThreeD17  EQU  17      ;=011h
;msoThreeD18  EQU  18      ;=012h
;msoThreeD19  EQU  19      ;=013h
;msoThreeD20  EQU  20      ;=014h
;
;;--- MsoExtrusionColorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoExtrusionColorType typedef SDWORD
;msoExtrusionColorTypeMixed  EQU  -2      ;=0FFFFFFFEh
;msoExtrusionColorAutomatic  EQU  1
;msoExtrusionColorCustom  EQU  2
;
;;--- MsoAlignCmd, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoAlignCmd typedef SDWORD
;msoAlignLefts  EQU  0
;msoAlignCenters  EQU  1
;msoAlignRights  EQU  2
;msoAlignTops  EQU  3
;msoAlignMiddles  EQU  4
;msoAlignBottoms  EQU  5
;
;;--- MsoDistributeCmd, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoDistributeCmd typedef SDWORD
;msoDistributeHorizontally  EQU  0
;msoDistributeVertically  EQU  1
;
;;--- MsoConnectorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoConnectorType typedef SDWORD
;msoConnectorTypeMixed  EQU  -2      ;=0FFFFFFFEh
;msoConnectorStraight  EQU  1
;msoConnectorElbow  EQU  2
;msoConnectorCurve  EQU  3
;
;;--- MsoHorizontalAnchor, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoHorizontalAnchor typedef SDWORD
;msoHorizontalAnchorMixed  EQU  -2      ;=0FFFFFFFEh
;msoAnchorNone  EQU  1
;msoAnchorCenter  EQU  2
;
;;--- MsoVerticalAnchor, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoVerticalAnchor typedef SDWORD
;msoVerticalAnchorMixed  EQU  -2      ;=0FFFFFFFEh
;msoAnchorTop  EQU  1
;msoAnchorTopBaseline  EQU  2
;msoAnchorMiddle  EQU  3
;msoAnchorBottom  EQU  4
;msoAnchorBottomBaseLine  EQU  5
;
;;--- MsoOrientation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoOrientation typedef SDWORD
;msoOrientationMixed  EQU  -2      ;=0FFFFFFFEh
;msoOrientationHorizontal  EQU  1
;msoOrientationVertical  EQU  2
;
;;--- MsoZOrderCmd, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoZOrderCmd typedef SDWORD
;msoBringToFront  EQU  0
;msoSendToBack  EQU  1
;msoBringForward  EQU  2
;msoSendBackward  EQU  3
;msoBringInFrontOfText  EQU  4
;msoSendBehindText  EQU  5
;
;;--- MsoSegmentType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoSegmentType typedef SDWORD
;msoSegmentLine  EQU  0
;msoSegmentCurve  EQU  1
;
;;--- MsoEditingType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoEditingType typedef SDWORD
;msoEditingAuto  EQU  0
;msoEditingCorner  EQU  1
;msoEditingSmooth  EQU  2
;msoEditingSymmetric  EQU  3
;
;;--- MsoAutoShapeType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoAutoShapeType typedef SDWORD
;msoShapeMixed  EQU  -2      ;=0FFFFFFFEh
;msoShapeRectangle  EQU  1
;msoShapeParallelogram  EQU  2
;msoShapeTrapezoid  EQU  3
;msoShapeDiamond  EQU  4
;msoShapeRoundedRectangle  EQU  5
;msoShapeOctagon  EQU  6
;msoShapeIsoscelesTriangle  EQU  7
;msoShapeRightTriangle  EQU  8
;msoShapeOval  EQU  9
;msoShapeHexagon  EQU  10
;msoShapeCross  EQU  11
;msoShapeRegularPentagon  EQU  12
;msoShapeCan  EQU  13
;msoShapeCube  EQU  14
;msoShapeBevel  EQU  15
;msoShapeFoldedCorner  EQU  16      ;=010h
;msoShapeSmileyFace  EQU  17      ;=011h
;msoShapeDonut  EQU  18      ;=012h
;msoShapeNoSymbol  EQU  19      ;=013h
;msoShapeBlockArc  EQU  20      ;=014h
;msoShapeHeart  EQU  21      ;=015h
;msoShapeLightningBolt  EQU  22      ;=016h
;msoShapeSun  EQU  23      ;=017h
;msoShapeMoon  EQU  24      ;=018h
;msoShapeArc  EQU  25      ;=019h
;msoShapeDoubleBracket  EQU  26      ;=01Ah
;msoShapeDoubleBrace  EQU  27      ;=01Bh
;msoShapePlaque  EQU  28      ;=01Ch
;msoShapeLeftBracket  EQU  29      ;=01Dh
;msoShapeRightBracket  EQU  30      ;=01Eh
;msoShapeLeftBrace  EQU  31      ;=01Fh
;msoShapeRightBrace  EQU  32      ;=020h
;msoShapeRightArrow  EQU  33      ;=021h
;msoShapeLeftArrow  EQU  34      ;=022h
;msoShapeUpArrow  EQU  35      ;=023h
;msoShapeDownArrow  EQU  36      ;=024h
;msoShapeLeftRightArrow  EQU  37      ;=025h
;msoShapeUpDownArrow  EQU  38      ;=026h
;msoShapeQuadArrow  EQU  39      ;=027h
;msoShapeLeftRightUpArrow  EQU  40      ;=028h
;msoShapeBentArrow  EQU  41      ;=029h
;msoShapeUTurnArrow  EQU  42      ;=02Ah
;msoShapeLeftUpArrow  EQU  43      ;=02Bh
;msoShapeBentUpArrow  EQU  44      ;=02Ch
;msoShapeCurvedRightArrow  EQU  45      ;=02Dh
;msoShapeCurvedLeftArrow  EQU  46      ;=02Eh
;msoShapeCurvedUpArrow  EQU  47      ;=02Fh
;msoShapeCurvedDownArrow  EQU  48      ;=030h
;msoShapeStripedRightArrow  EQU  49      ;=031h
;msoShapeNotchedRightArrow  EQU  50      ;=032h
;msoShapePentagon  EQU  51      ;=033h
;msoShapeChevron  EQU  52      ;=034h
;msoShapeRightArrowCallout  EQU  53      ;=035h
;msoShapeLeftArrowCallout  EQU  54      ;=036h
;msoShapeUpArrowCallout  EQU  55      ;=037h
;msoShapeDownArrowCallout  EQU  56      ;=038h
;msoShapeLeftRightArrowCallout  EQU  57      ;=039h
;msoShapeUpDownArrowCallout  EQU  58      ;=03Ah
;msoShapeQuadArrowCallout  EQU  59      ;=03Bh
;msoShapeCircularArrow  EQU  60      ;=03Ch
;msoShapeFlowchartProcess  EQU  61      ;=03Dh
;msoShapeFlowchartAlternateProcess  EQU  62      ;=03Eh
;msoShapeFlowchartDecision  EQU  63      ;=03Fh
;msoShapeFlowchartData  EQU  64      ;=040h
;msoShapeFlowchartPredefinedProcess  EQU  65      ;=041h
;msoShapeFlowchartInternalStorage  EQU  66      ;=042h
;msoShapeFlowchartDocument  EQU  67      ;=043h
;msoShapeFlowchartMultidocument  EQU  68      ;=044h
;msoShapeFlowchartTerminator  EQU  69      ;=045h
;msoShapeFlowchartPreparation  EQU  70      ;=046h
;msoShapeFlowchartManualInput  EQU  71      ;=047h
;msoShapeFlowchartManualOperation  EQU  72      ;=048h
;msoShapeFlowchartConnector  EQU  73      ;=049h
;msoShapeFlowchartOffpageConnector  EQU  74      ;=04Ah
;msoShapeFlowchartCard  EQU  75      ;=04Bh
;msoShapeFlowchartPunchedTape  EQU  76      ;=04Ch
;msoShapeFlowchartSummingJunction  EQU  77      ;=04Dh
;msoShapeFlowchartOr  EQU  78      ;=04Eh
;msoShapeFlowchartCollate  EQU  79      ;=04Fh
;msoShapeFlowchartSort  EQU  80      ;=050h
;msoShapeFlowchartExtract  EQU  81      ;=051h
;msoShapeFlowchartMerge  EQU  82      ;=052h
;msoShapeFlowchartStoredData  EQU  83      ;=053h
;msoShapeFlowchartDelay  EQU  84      ;=054h
;msoShapeFlowchartSequentialAccessStorage  EQU  85      ;=055h
;msoShapeFlowchartMagneticDisk  EQU  86      ;=056h
;msoShapeFlowchartDirectAccessStorage  EQU  87      ;=057h
;msoShapeFlowchartDisplay  EQU  88      ;=058h
;msoShapeExplosion1  EQU  89      ;=059h
;msoShapeExplosion2  EQU  90      ;=05Ah
;msoShape4pointStar  EQU  91      ;=05Bh
;msoShape5pointStar  EQU  92      ;=05Ch
;msoShape8pointStar  EQU  93      ;=05Dh
;msoShape16pointStar  EQU  94      ;=05Eh
;msoShape24pointStar  EQU  95      ;=05Fh
;msoShape32pointStar  EQU  96      ;=060h
;msoShapeUpRibbon  EQU  97      ;=061h
;msoShapeDownRibbon  EQU  98      ;=062h
;msoShapeCurvedUpRibbon  EQU  99      ;=063h
;msoShapeCurvedDownRibbon  EQU  100      ;=064h
;msoShapeVerticalScroll  EQU  101      ;=065h
;msoShapeHorizontalScroll  EQU  102      ;=066h
;msoShapeWave  EQU  103      ;=067h
;msoShapeDoubleWave  EQU  104      ;=068h
;msoShapeRectangularCallout  EQU  105      ;=069h
;msoShapeRoundedRectangularCallout  EQU  106      ;=06Ah
;msoShapeOvalCallout  EQU  107      ;=06Bh
;msoShapeCloudCallout  EQU  108      ;=06Ch
;msoShapeLineCallout1  EQU  109      ;=06Dh
;msoShapeLineCallout2  EQU  110      ;=06Eh
;msoShapeLineCallout3  EQU  111      ;=06Fh
;msoShapeLineCallout4  EQU  112      ;=070h
;msoShapeLineCallout1AccentBar  EQU  113      ;=071h
;msoShapeLineCallout2AccentBar  EQU  114      ;=072h
;msoShapeLineCallout3AccentBar  EQU  115      ;=073h
;msoShapeLineCallout4AccentBar  EQU  116      ;=074h
;msoShapeLineCallout1NoBorder  EQU  117      ;=075h
;msoShapeLineCallout2NoBorder  EQU  118      ;=076h
;msoShapeLineCallout3NoBorder  EQU  119      ;=077h
;msoShapeLineCallout4NoBorder  EQU  120      ;=078h
;msoShapeLineCallout1BorderandAccentBar  EQU  121      ;=079h
;msoShapeLineCallout2BorderandAccentBar  EQU  122      ;=07Ah
;msoShapeLineCallout3BorderandAccentBar  EQU  123      ;=07Bh
;msoShapeLineCallout4BorderandAccentBar  EQU  124      ;=07Ch
;msoShapeActionButtonCustom  EQU  125      ;=07Dh
;msoShapeActionButtonHome  EQU  126      ;=07Eh
;msoShapeActionButtonHelp  EQU  127      ;=07Fh
;msoShapeActionButtonInformation  EQU  128      ;=080h
;msoShapeActionButtonBackorPrevious  EQU  129      ;=081h
;msoShapeActionButtonForwardorNext  EQU  130      ;=082h
;msoShapeActionButtonBeginning  EQU  131      ;=083h
;msoShapeActionButtonEnd  EQU  132      ;=084h
;msoShapeActionButtonReturn  EQU  133      ;=085h
;msoShapeActionButtonDocument  EQU  134      ;=086h
;msoShapeActionButtonSound  EQU  135      ;=087h
;msoShapeActionButtonMovie  EQU  136      ;=088h
;msoShapeBalloon  EQU  137      ;=089h
;msoShapeNotPrimitive  EQU  138      ;=08Ah
;
;;--- MsoShapeType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoShapeType typedef SDWORD
;msoShapeTypeMixed  EQU  -2      ;=0FFFFFFFEh
;msoAutoShape  EQU  1
;msoCallout  EQU  2
;msoChart  EQU  3
;msoComment  EQU  4
;msoFreeform  EQU  5
;msoGroup  EQU  6
;msoEmbeddedOLEObject  EQU  7
;msoFormControl  EQU  8
;msoLine  EQU  9
;msoLinkedOLEObject  EQU  10
;msoLinkedPicture  EQU  11
;msoOLEControlObject  EQU  12
;msoPicture  EQU  13
;msoPlaceholder  EQU  14
;msoTextEffect  EQU  15
;msoMedia  EQU  16      ;=010h
;msoTextBox  EQU  17      ;=011h
;msoScriptAnchor  EQU  18      ;=012h
;msoTable  EQU  19      ;=013h
;msoCanvas  EQU  20      ;=014h
;msoDiagram  EQU  21      ;=015h
;
;;--- MsoFlipCmd, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFlipCmd typedef SDWORD
;msoFlipHorizontal  EQU  0
;msoFlipVertical  EQU  1
;
;;--- MsoTriState, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoTriState typedef SDWORD
;msoTrue  EQU  -1
;msoFalse  EQU  0
;msoCTrue  EQU  1
;msoTriStateToggle  EQU  -3      ;=0FFFFFFFDh
;msoTriStateMixed  EQU  -2      ;=0FFFFFFFEh
;
;;--- MsoColorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoColorType typedef SDWORD
;msoColorTypeMixed  EQU  -2      ;=0FFFFFFFEh
;msoColorTypeRGB  EQU  1
;msoColorTypeScheme  EQU  2
;msoColorTypeCMYK  EQU  3
;msoColorTypeCMS  EQU  4
;msoColorTypeInk  EQU  5
;
;;--- MsoPictureColorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoPictureColorType typedef SDWORD
;msoPictureMixed  EQU  -2      ;=0FFFFFFFEh
;msoPictureAutomatic  EQU  1
;msoPictureGrayscale  EQU  2
;msoPictureBlackAndWhite  EQU  3
;msoPictureWatermark  EQU  4
;
;;--- MsoCalloutAngleType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoCalloutAngleType typedef SDWORD
;msoCalloutAngleMixed  EQU  -2      ;=0FFFFFFFEh
;msoCalloutAngleAutomatic  EQU  1
;msoCalloutAngle30  EQU  2
;msoCalloutAngle45  EQU  3
;msoCalloutAngle60  EQU  4
;msoCalloutAngle90  EQU  5
;
;;--- MsoCalloutDropType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoCalloutDropType typedef SDWORD
;msoCalloutDropMixed  EQU  -2      ;=0FFFFFFFEh
;msoCalloutDropCustom  EQU  1
;msoCalloutDropTop  EQU  2
;msoCalloutDropCenter  EQU  3
;msoCalloutDropBottom  EQU  4
;
;;--- MsoCalloutType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoCalloutType typedef SDWORD
;msoCalloutMixed  EQU  -2      ;=0FFFFFFFEh
;msoCalloutOne  EQU  1
;msoCalloutTwo  EQU  2
;msoCalloutThree  EQU  3
;msoCalloutFour  EQU  4
;
;;--- MsoBlackWhiteMode, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoBlackWhiteMode typedef SDWORD
;msoBlackWhiteMixed  EQU  -2      ;=0FFFFFFFEh
;msoBlackWhiteAutomatic  EQU  1
;msoBlackWhiteGrayScale  EQU  2
;msoBlackWhiteLightGrayScale  EQU  3
;msoBlackWhiteInverseGrayScale  EQU  4
;msoBlackWhiteGrayOutline  EQU  5
;msoBlackWhiteBlackTextAndLine  EQU  6
;msoBlackWhiteHighContrast  EQU  7
;msoBlackWhiteBlack  EQU  8
;msoBlackWhiteWhite  EQU  9
;msoBlackWhiteDontShow  EQU  10
;
;;--- MsoMixedType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoMixedType typedef SDWORD
;msoIntegerMixed  EQU  32768      ;=08000h
;msoSingleMixed  EQU  -2147483648      ;=080000000h
;
;;--- MsoTextOrientation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoTextOrientation typedef SDWORD
;msoTextOrientationMixed  EQU  -2      ;=0FFFFFFFEh
;msoTextOrientationHorizontal  EQU  1
;msoTextOrientationUpward  EQU  2
;msoTextOrientationDownward  EQU  3
;msoTextOrientationVerticalFarEast  EQU  4
;msoTextOrientationVertical  EQU  5
;msoTextOrientationHorizontalRotatedFarEast  EQU  6
;
;;--- MsoScaleFrom, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoScaleFrom typedef SDWORD
;msoScaleFromTopLeft  EQU  0
;msoScaleFromMiddle  EQU  1
;msoScaleFromBottomRight  EQU  2
;
;;--- MsoBarPosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoBarPosition typedef SDWORD
;msoBarLeft  EQU  0
;msoBarTop  EQU  1
;msoBarRight  EQU  2
;msoBarBottom  EQU  3
;msoBarFloating  EQU  4
;msoBarPopup  EQU  5
;msoBarMenuBar  EQU  6
;
;;--- MsoBarProtection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoBarProtection typedef SDWORD
;msoBarNoProtection  EQU  0
;msoBarNoCustomize  EQU  1
;msoBarNoResize  EQU  2
;msoBarNoMove  EQU  4
;msoBarNoChangeVisible  EQU  8
;msoBarNoChangeDock  EQU  16      ;=010h
;msoBarNoVerticalDock  EQU  32      ;=020h
;msoBarNoHorizontalDock  EQU  64      ;=040h
;
;;--- MsoBarType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoBarType typedef SDWORD
;msoBarTypeNormal  EQU  0
;msoBarTypeMenuBar  EQU  1
;msoBarTypePopup  EQU  2
;
;;--- MsoControlType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoControlType typedef SDWORD
;msoControlCustom  EQU  0
;msoControlButton  EQU  1
;msoControlEdit  EQU  2
;msoControlDropdown  EQU  3
;msoControlComboBox  EQU  4
;msoControlButtonDropdown  EQU  5
;msoControlSplitDropdown  EQU  6
;msoControlOCXDropdown  EQU  7
;msoControlGenericDropdown  EQU  8
;msoControlGraphicDropdown  EQU  9
;msoControlPopup  EQU  10
;msoControlGraphicPopup  EQU  11
;msoControlButtonPopup  EQU  12
;msoControlSplitButtonPopup  EQU  13
;msoControlSplitButtonMRUPopup  EQU  14
;msoControlLabel  EQU  15
;msoControlExpandingGrid  EQU  16      ;=010h
;msoControlSplitExpandingGrid  EQU  17      ;=011h
;msoControlGrid  EQU  18      ;=012h
;msoControlGauge  EQU  19      ;=013h
;msoControlGraphicCombo  EQU  20      ;=014h
;msoControlPane  EQU  21      ;=015h
;msoControlActiveX  EQU  22      ;=016h
;msoControlSpinner  EQU  23      ;=017h
;msoControlLabelEx  EQU  24      ;=018h
;msoControlWorkPane  EQU  25      ;=019h
;msoControlAutoCompleteCombo  EQU  26      ;=01Ah
;
;;--- MsoButtonState, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoButtonState typedef SDWORD
;msoButtonUp  EQU  0
;msoButtonDown  EQU  -1
;msoButtonMixed  EQU  2
;
;;--- MsoControlOLEUsage, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoControlOLEUsage typedef SDWORD
;msoControlOLEUsageNeither  EQU  0
;msoControlOLEUsageServer  EQU  1
;msoControlOLEUsageClient  EQU  2
;msoControlOLEUsageBoth  EQU  3
;
;;--- MsoButtonStyleHidden, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoButtonStyleHidden typedef SDWORD
;msoButtonWrapText  EQU  4
;msoButtonTextBelow  EQU  8
;
;;--- MsoButtonStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoButtonStyle typedef SDWORD
;msoButtonAutomatic  EQU  0
;msoButtonIcon  EQU  1
;msoButtonCaption  EQU  2
;msoButtonIconAndCaption  EQU  3
;msoButtonIconAndWrapCaption  EQU  7
;msoButtonIconAndCaptionBelow  EQU  11
;msoButtonWrapCaption  EQU  14
;msoButtonIconAndWrapCaptionBelow  EQU  15
;
;;--- MsoComboStyle, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoComboStyle typedef SDWORD
;msoComboNormal  EQU  0
;msoComboLabel  EQU  1
;
;;--- MsoOLEMenuGroup, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoOLEMenuGroup typedef SDWORD
;msoOLEMenuGroupNone  EQU  -1
;msoOLEMenuGroupFile  EQU  0
;msoOLEMenuGroupEdit  EQU  1
;msoOLEMenuGroupContainer  EQU  2
;msoOLEMenuGroupObject  EQU  3
;msoOLEMenuGroupWindow  EQU  4
;msoOLEMenuGroupHelp  EQU  5
;
;;--- MsoMenuAnimation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoMenuAnimation typedef SDWORD
;msoMenuAnimationNone  EQU  0
;msoMenuAnimationRandom  EQU  1
;msoMenuAnimationUnfold  EQU  2
;msoMenuAnimationSlide  EQU  3
;
;;--- MsoBarRow, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoBarRow typedef SDWORD
;msoBarRowFirst  EQU  0
;msoBarRowLast  EQU  -1
;
;;--- MsoCommandBarButtonHyperlinkType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoCommandBarButtonHyperlinkType typedef SDWORD
;msoCommandBarButtonHyperlinkNone  EQU  0
;msoCommandBarButtonHyperlinkOpen  EQU  1
;msoCommandBarButtonHyperlinkInsertPicture  EQU  2
;
;;--- MsoHyperlinkType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoHyperlinkType typedef SDWORD
;msoHyperlinkRange  EQU  0
;msoHyperlinkShape  EQU  1
;msoHyperlinkInlineShape  EQU  2
;
;;--- MsoExtraInfoMethod, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoExtraInfoMethod typedef SDWORD
;msoMethodGet  EQU  0
;msoMethodPost  EQU  1
;
;;--- MsoAnimationType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoAnimationType typedef SDWORD
;msoAnimationIdle  EQU  1
;msoAnimationGreeting  EQU  2
;msoAnimationGoodbye  EQU  3
;msoAnimationBeginSpeaking  EQU  4
;msoAnimationRestPose  EQU  5
;msoAnimationCharacterSuccessMajor  EQU  6
;msoAnimationGetAttentionMajor  EQU  11
;msoAnimationGetAttentionMinor  EQU  12
;msoAnimationSearching  EQU  13
;msoAnimationPrinting  EQU  18      ;=012h
;msoAnimationGestureRight  EQU  19      ;=013h
;msoAnimationWritingNotingSomething  EQU  22      ;=016h
;msoAnimationWorkingAtSomething  EQU  23      ;=017h
;msoAnimationThinking  EQU  24      ;=018h
;msoAnimationSendingMail  EQU  25      ;=019h
;msoAnimationListensToComputer  EQU  26      ;=01Ah
;msoAnimationDisappear  EQU  31      ;=01Fh
;msoAnimationAppear  EQU  32      ;=020h
;msoAnimationGetArtsy  EQU  100      ;=064h
;msoAnimationGetTechy  EQU  101      ;=065h
;msoAnimationGetWizardy  EQU  102      ;=066h
;msoAnimationCheckingSomething  EQU  103      ;=067h
;msoAnimationLookDown  EQU  104      ;=068h
;msoAnimationLookDownLeft  EQU  105      ;=069h
;msoAnimationLookDownRight  EQU  106      ;=06Ah
;msoAnimationLookLeft  EQU  107      ;=06Bh
;msoAnimationLookRight  EQU  108      ;=06Ch
;msoAnimationLookUp  EQU  109      ;=06Dh
;msoAnimationLookUpLeft  EQU  110      ;=06Eh
;msoAnimationLookUpRight  EQU  111      ;=06Fh
;msoAnimationSaving  EQU  112      ;=070h
;msoAnimationGestureDown  EQU  113      ;=071h
;msoAnimationGestureLeft  EQU  114      ;=072h
;msoAnimationGestureUp  EQU  115      ;=073h
;msoAnimationEmptyTrash  EQU  116      ;=074h
;
;;--- MsoButtonSetType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoButtonSetType typedef SDWORD
;msoButtonSetNone  EQU  0
;msoButtonSetOK  EQU  1
;msoButtonSetCancel  EQU  2
;msoButtonSetOkCancel  EQU  3
;msoButtonSetYesNo  EQU  4
;msoButtonSetYesNoCancel  EQU  5
;msoButtonSetBackClose  EQU  6
;msoButtonSetNextClose  EQU  7
;msoButtonSetBackNextClose  EQU  8
;msoButtonSetRetryCancel  EQU  9
;msoButtonSetAbortRetryIgnore  EQU  10
;msoButtonSetSearchClose  EQU  11
;msoButtonSetBackNextSnooze  EQU  12
;msoButtonSetTipsOptionsClose  EQU  13
;msoButtonSetYesAllNoCancel  EQU  14
;
;;--- MsoIconType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoIconType typedef SDWORD
;msoIconNone  EQU  0
;msoIconAlert  EQU  2
;msoIconTip  EQU  3
;msoIconAlertInfo  EQU  4
;msoIconAlertWarning  EQU  5
;msoIconAlertQuery  EQU  6
;msoIconAlertCritical  EQU  7
;
;;--- MsoBalloonType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoBalloonType typedef SDWORD
;msoBalloonTypeButtons  EQU  0
;msoBalloonTypeBullets  EQU  1
;msoBalloonTypeNumbers  EQU  2
;
;;--- MsoModeType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoModeType typedef SDWORD
;msoModeModal  EQU  0
;msoModeAutoDown  EQU  1
;msoModeModeless  EQU  2
;
;;--- MsoBalloonErrorType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoBalloonErrorType typedef SDWORD
;msoBalloonErrorNone  EQU  0
;msoBalloonErrorOther  EQU  1
;msoBalloonErrorTooBig  EQU  2
;msoBalloonErrorOutOfMemory  EQU  3
;msoBalloonErrorBadPictureRef  EQU  4
;msoBalloonErrorBadReference  EQU  5
;msoBalloonErrorButtonlessModal  EQU  6
;msoBalloonErrorButtonModeless  EQU  7
;msoBalloonErrorBadCharacter  EQU  8
;msoBalloonErrorCOMFailure  EQU  9
;msoBalloonErrorCharNotTopmostForModal  EQU  10
;msoBalloonErrorTooManyControls  EQU  11
;
;;--- MsoWizardActType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoWizardActType typedef SDWORD
;msoWizardActInactive  EQU  0
;msoWizardActActive  EQU  1
;msoWizardActSuspend  EQU  2
;msoWizardActResume  EQU  3
;
;;--- MsoWizardMsgType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoWizardMsgType typedef SDWORD
;msoWizardMsgLocalStateOn  EQU  1
;msoWizardMsgLocalStateOff  EQU  2
;msoWizardMsgShowHelp  EQU  3
;msoWizardMsgSuspending  EQU  4
;msoWizardMsgResuming  EQU  5
;
;;--- MsoBalloonButtonType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoBalloonButtonType typedef SDWORD
;msoBalloonButtonYesToAll  EQU  -15      ;=0FFFFFFF1h
;msoBalloonButtonOptions  EQU  -14      ;=0FFFFFFF2h
;msoBalloonButtonTips  EQU  -13      ;=0FFFFFFF3h
;msoBalloonButtonClose  EQU  -12      ;=0FFFFFFF4h
;msoBalloonButtonSnooze  EQU  -11      ;=0FFFFFFF5h
;msoBalloonButtonSearch  EQU  -10      ;=0FFFFFFF6h
;msoBalloonButtonIgnore  EQU  -9      ;=0FFFFFFF7h
;msoBalloonButtonAbort  EQU  -8      ;=0FFFFFFF8h
;msoBalloonButtonRetry  EQU  -7      ;=0FFFFFFF9h
;msoBalloonButtonNext  EQU  -6      ;=0FFFFFFFAh
;msoBalloonButtonBack  EQU  -5      ;=0FFFFFFFBh
;msoBalloonButtonNo  EQU  -4      ;=0FFFFFFFCh
;msoBalloonButtonYes  EQU  -3      ;=0FFFFFFFDh
;msoBalloonButtonCancel  EQU  -2      ;=0FFFFFFFEh
;msoBalloonButtonOK  EQU  -1
;msoBalloonButtonNull  EQU  0
;
;;--- DocProperties, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;DocProperties typedef SDWORD
;offPropertyTypeNumber  EQU  1
;offPropertyTypeBoolean  EQU  2
;offPropertyTypeDate  EQU  3
;offPropertyTypeString  EQU  4
;offPropertyTypeFloat  EQU  5
;
;;--- MsoDocProperties, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoDocProperties typedef SDWORD
;msoPropertyTypeNumber  EQU  1
;msoPropertyTypeBoolean  EQU  2
;msoPropertyTypeDate  EQU  3
;msoPropertyTypeString  EQU  4
;msoPropertyTypeFloat  EQU  5
;
;;--- MsoAppLanguageID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoAppLanguageID typedef SDWORD
;msoLanguageIDInstall  EQU  1
;msoLanguageIDUI  EQU  2
;msoLanguageIDHelp  EQU  3
;msoLanguageIDExeMode  EQU  4
;msoLanguageIDUIPrevious  EQU  5
;
;;--- MsoFarEastLineBreakLanguageID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFarEastLineBreakLanguageID typedef SDWORD
;MsoFarEastLineBreakLanguageJapanese  EQU  1041      ;=0411h
;MsoFarEastLineBreakLanguageKorean  EQU  1042      ;=0412h
;MsoFarEastLineBreakLanguageSimplifiedChinese  EQU  2052      ;=0804h
;MsoFarEastLineBreakLanguageTraditionalChinese  EQU  1028      ;=0404h
;
;;--- MsoFeatureInstall, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
MsoFeatureInstall typedef SDWORD
;msoFeatureInstallNone  EQU  0
;msoFeatureInstallOnDemand  EQU  1
;msoFeatureInstallOnDemandWithUI  EQU  2
;
;;--- MsoScriptLanguage, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoScriptLanguage typedef SDWORD
;msoScriptLanguageJava  EQU  1
;msoScriptLanguageVisualBasic  EQU  2
;msoScriptLanguageASP  EQU  3
;msoScriptLanguageOther  EQU  4
;
;;--- MsoScriptLocation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoScriptLocation typedef SDWORD
;msoScriptLocationInHead  EQU  1
;msoScriptLocationInBody  EQU  2
;
;;--- MsoFileFindOptions, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileFindOptions typedef SDWORD
;msoOptionsNew  EQU  1
;msoOptionsAdd  EQU  2
;msoOptionsWithin  EQU  3
;
;;--- MsoFileFindView, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileFindView typedef SDWORD
;msoViewFileInfo  EQU  1
;msoViewPreview  EQU  2
;msoViewSummaryInfo  EQU  3
;
;;--- MsoFileFindSortBy, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileFindSortBy typedef SDWORD
;msoFileFindSortbyAuthor  EQU  1
;msoFileFindSortbyDateCreated  EQU  2
;msoFileFindSortbyLastSavedBy  EQU  3
;msoFileFindSortbyDateSaved  EQU  4
;msoFileFindSortbyFileName  EQU  5
;msoFileFindSortbySize  EQU  6
;msoFileFindSortbyTitle  EQU  7
;
;;--- MsoFileFindListBy, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileFindListBy typedef SDWORD
;msoListbyName  EQU  1
;msoListbyTitle  EQU  2
;
;;--- MsoLastModified, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoLastModified typedef SDWORD
;msoLastModifiedYesterday  EQU  1
;msoLastModifiedToday  EQU  2
;msoLastModifiedLastWeek  EQU  3
;msoLastModifiedThisWeek  EQU  4
;msoLastModifiedLastMonth  EQU  5
;msoLastModifiedThisMonth  EQU  6
;msoLastModifiedAnyTime  EQU  7
;
;;--- MsoSortBy, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoSortBy typedef SDWORD
;msoSortByFileName  EQU  1
;msoSortBySize  EQU  2
;msoSortByFileType  EQU  3
;msoSortByLastModified  EQU  4
;msoSortByNone  EQU  5
;
;;--- MsoSortOrder, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoSortOrder typedef SDWORD
;msoSortOrderAscending  EQU  1
;msoSortOrderDescending  EQU  2
;
;;--- MsoConnector, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoConnector typedef SDWORD
;msoConnectorAnd  EQU  1
;msoConnectorOr  EQU  2
;
;;--- MsoCondition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoCondition typedef SDWORD
;msoConditionFileTypeAllFiles  EQU  1
;msoConditionFileTypeOfficeFiles  EQU  2
;msoConditionFileTypeWordDocuments  EQU  3
;msoConditionFileTypeExcelWorkbooks  EQU  4
;msoConditionFileTypePowerPointPresentations  EQU  5
;msoConditionFileTypeBinders  EQU  6
;msoConditionFileTypeDatabases  EQU  7
;msoConditionFileTypeTemplates  EQU  8
;msoConditionIncludes  EQU  9
;msoConditionIncludesPhrase  EQU  10
;msoConditionBeginsWith  EQU  11
;msoConditionEndsWith  EQU  12
;msoConditionIncludesNearEachOther  EQU  13
;msoConditionIsExactly  EQU  14
;msoConditionIsNot  EQU  15
;msoConditionYesterday  EQU  16      ;=010h
;msoConditionToday  EQU  17      ;=011h
;msoConditionTomorrow  EQU  18      ;=012h
;msoConditionLastWeek  EQU  19      ;=013h
;msoConditionThisWeek  EQU  20      ;=014h
;msoConditionNextWeek  EQU  21      ;=015h
;msoConditionLastMonth  EQU  22      ;=016h
;msoConditionThisMonth  EQU  23      ;=017h
;msoConditionNextMonth  EQU  24      ;=018h
;msoConditionAnytime  EQU  25      ;=019h
;msoConditionAnytimeBetween  EQU  26      ;=01Ah
;msoConditionOn  EQU  27      ;=01Bh
;msoConditionOnOrAfter  EQU  28      ;=01Ch
;msoConditionOnOrBefore  EQU  29      ;=01Dh
;msoConditionInTheNext  EQU  30      ;=01Eh
;msoConditionInTheLast  EQU  31      ;=01Fh
;msoConditionEquals  EQU  32      ;=020h
;msoConditionDoesNotEqual  EQU  33      ;=021h
;msoConditionAnyNumberBetween  EQU  34      ;=022h
;msoConditionAtMost  EQU  35      ;=023h
;msoConditionAtLeast  EQU  36      ;=024h
;msoConditionMoreThan  EQU  37      ;=025h
;msoConditionLessThan  EQU  38      ;=026h
;msoConditionIsYes  EQU  39      ;=027h
;msoConditionIsNo  EQU  40      ;=028h
;msoConditionIncludesFormsOf  EQU  41      ;=029h
;msoConditionFreeText  EQU  42      ;=02Ah
;msoConditionFileTypeOutlookItems  EQU  43      ;=02Bh
;msoConditionFileTypeMailItem  EQU  44      ;=02Ch
;msoConditionFileTypeCalendarItem  EQU  45      ;=02Dh
;msoConditionFileTypeContactItem  EQU  46      ;=02Eh
;msoConditionFileTypeNoteItem  EQU  47      ;=02Fh
;msoConditionFileTypeJournalItem  EQU  48      ;=030h
;msoConditionFileTypeTaskItem  EQU  49      ;=031h
;msoConditionFileTypePhotoDrawFiles  EQU  50      ;=032h
;msoConditionFileTypeDataConnectionFiles  EQU  51      ;=033h
;msoConditionFileTypePublisherFiles  EQU  52      ;=034h
;msoConditionFileTypeProjectFiles  EQU  53      ;=035h
;msoConditionFileTypeDocumentImagingFiles  EQU  54      ;=036h
;msoConditionFileTypeVisioFiles  EQU  55      ;=037h
;msoConditionFileTypeDesignerFiles  EQU  56      ;=038h
;msoConditionFileTypeWebPages  EQU  57      ;=039h
;msoConditionEqualsLow  EQU  58      ;=03Ah
;msoConditionEqualsNormal  EQU  59      ;=03Bh
;msoConditionEqualsHigh  EQU  60      ;=03Ch
;msoConditionNotEqualToLow  EQU  61      ;=03Dh
;msoConditionNotEqualToNormal  EQU  62      ;=03Eh
;msoConditionNotEqualToHigh  EQU  63      ;=03Fh
;msoConditionEqualsNotStarted  EQU  64      ;=040h
;msoConditionEqualsInProgress  EQU  65      ;=041h
;msoConditionEqualsCompleted  EQU  66      ;=042h
;msoConditionEqualsWaitingForSomeoneElse  EQU  67      ;=043h
;msoConditionEqualsDeferred  EQU  68      ;=044h
;msoConditionNotEqualToNotStarted  EQU  69      ;=045h
;msoConditionNotEqualToInProgress  EQU  70      ;=046h
;msoConditionNotEqualToCompleted  EQU  71      ;=047h
;msoConditionNotEqualToWaitingForSomeoneElse  EQU  72      ;=048h
;msoConditionNotEqualToDeferred  EQU  73      ;=049h
;
;;--- MsoFileType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileType typedef SDWORD
;msoFileTypeAllFiles  EQU  1
;msoFileTypeOfficeFiles  EQU  2
;msoFileTypeWordDocuments  EQU  3
;msoFileTypeExcelWorkbooks  EQU  4
;msoFileTypePowerPointPresentations  EQU  5
;msoFileTypeBinders  EQU  6
;msoFileTypeDatabases  EQU  7
;msoFileTypeTemplates  EQU  8
;msoFileTypeOutlookItems  EQU  9
;msoFileTypeMailItem  EQU  10
;msoFileTypeCalendarItem  EQU  11
;msoFileTypeContactItem  EQU  12
;msoFileTypeNoteItem  EQU  13
;msoFileTypeJournalItem  EQU  14
;msoFileTypeTaskItem  EQU  15
;msoFileTypePhotoDrawFiles  EQU  16      ;=010h
;msoFileTypeDataConnectionFiles  EQU  17      ;=011h
;msoFileTypePublisherFiles  EQU  18      ;=012h
;msoFileTypeProjectFiles  EQU  19      ;=013h
;msoFileTypeDocumentImagingFiles  EQU  20      ;=014h
;msoFileTypeVisioFiles  EQU  21      ;=015h
;msoFileTypeDesignerFiles  EQU  22      ;=016h
;msoFileTypeWebPages  EQU  23      ;=017h
;
;;--- MsoLanguageID, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoLanguageID typedef SDWORD
;msoLanguageIDMixed  EQU  -2      ;=0FFFFFFFEh
;msoLanguageIDNone  EQU  0
;msoLanguageIDNoProofing  EQU  1024      ;=0400h
;msoLanguageIDAfrikaans  EQU  1078      ;=0436h
;msoLanguageIDAlbanian  EQU  1052      ;=041Ch
;msoLanguageIDAmharic  EQU  1118      ;=045Eh
;msoLanguageIDArabicAlgeria  EQU  5121      ;=01401h
;msoLanguageIDArabicBahrain  EQU  15361      ;=03C01h
;msoLanguageIDArabicEgypt  EQU  3073      ;=0C01h
;msoLanguageIDArabicIraq  EQU  2049      ;=0801h
;msoLanguageIDArabicJordan  EQU  11265      ;=02C01h
;msoLanguageIDArabicKuwait  EQU  13313      ;=03401h
;msoLanguageIDArabicLebanon  EQU  12289      ;=03001h
;msoLanguageIDArabicLibya  EQU  4097      ;=01001h
;msoLanguageIDArabicMorocco  EQU  6145      ;=01801h
;msoLanguageIDArabicOman  EQU  8193      ;=02001h
;msoLanguageIDArabicQatar  EQU  16385      ;=04001h
;msoLanguageIDArabic  EQU  1025      ;=0401h
;msoLanguageIDArabicSyria  EQU  10241      ;=02801h
;msoLanguageIDArabicTunisia  EQU  7169      ;=01C01h
;msoLanguageIDArabicUAE  EQU  14337      ;=03801h
;msoLanguageIDArabicYemen  EQU  9217      ;=02401h
;msoLanguageIDArmenian  EQU  1067      ;=042Bh
;msoLanguageIDAssamese  EQU  1101      ;=044Dh
;msoLanguageIDAzeriCyrillic  EQU  2092      ;=082Ch
;msoLanguageIDAzeriLatin  EQU  1068      ;=042Ch
;msoLanguageIDBasque  EQU  1069      ;=042Dh
;msoLanguageIDByelorussian  EQU  1059      ;=0423h
;msoLanguageIDBengali  EQU  1093      ;=0445h
;msoLanguageIDBulgarian  EQU  1026      ;=0402h
;msoLanguageIDBurmese  EQU  1109      ;=0455h
;msoLanguageIDCatalan  EQU  1027      ;=0403h
;msoLanguageIDChineseHongKongSAR  EQU  3076      ;=0C04h
;msoLanguageIDChineseMacaoSAR  EQU  5124      ;=01404h
;msoLanguageIDSimplifiedChinese  EQU  2052      ;=0804h
;msoLanguageIDChineseSingapore  EQU  4100      ;=01004h
;msoLanguageIDTraditionalChinese  EQU  1028      ;=0404h
;msoLanguageIDCherokee  EQU  1116      ;=045Ch
;msoLanguageIDCroatian  EQU  1050      ;=041Ah
;msoLanguageIDCzech  EQU  1029      ;=0405h
;msoLanguageIDDanish  EQU  1030      ;=0406h
;msoLanguageIDDivehi  EQU  1125      ;=0465h
;msoLanguageIDBelgianDutch  EQU  2067      ;=0813h
;msoLanguageIDDutch  EQU  1043      ;=0413h
;msoLanguageIDDzongkhaBhutan  EQU  2129      ;=0851h
;msoLanguageIDEdo  EQU  1126      ;=0466h
;msoLanguageIDEnglishAUS  EQU  3081      ;=0C09h
;msoLanguageIDEnglishBelize  EQU  10249      ;=02809h
;msoLanguageIDEnglishCanadian  EQU  4105      ;=01009h
;msoLanguageIDEnglishCaribbean  EQU  9225      ;=02409h
;msoLanguageIDEnglishIndonesia  EQU  14345      ;=03809h
;msoLanguageIDEnglishIreland  EQU  6153      ;=01809h
;msoLanguageIDEnglishJamaica  EQU  8201      ;=02009h
;msoLanguageIDEnglishNewZealand  EQU  5129      ;=01409h
;msoLanguageIDEnglishPhilippines  EQU  13321      ;=03409h
;msoLanguageIDEnglishSouthAfrica  EQU  7177      ;=01C09h
;msoLanguageIDEnglishTrinidadTobago  EQU  11273      ;=02C09h
;msoLanguageIDEnglishUK  EQU  2057      ;=0809h
;msoLanguageIDEnglishUS  EQU  1033      ;=0409h
;msoLanguageIDEnglishZimbabwe  EQU  12297      ;=03009h
;msoLanguageIDEstonian  EQU  1061      ;=0425h
;msoLanguageIDFaeroese  EQU  1080      ;=0438h
;msoLanguageIDFarsi  EQU  1065      ;=0429h
;msoLanguageIDFilipino  EQU  1124      ;=0464h
;msoLanguageIDFinnish  EQU  1035      ;=040Bh
;msoLanguageIDBelgianFrench  EQU  2060      ;=080Ch
;msoLanguageIDFrenchCameroon  EQU  11276      ;=02C0Ch
;msoLanguageIDFrenchCanadian  EQU  3084      ;=0C0Ch
;msoLanguageIDFrenchCotedIvoire  EQU  12300      ;=0300Ch
;msoLanguageIDFrench  EQU  1036      ;=040Ch
;msoLanguageIDFrenchHaiti  EQU  15372      ;=03C0Ch
;msoLanguageIDFrenchLuxembourg  EQU  5132      ;=0140Ch
;msoLanguageIDFrenchMali  EQU  13324      ;=0340Ch
;msoLanguageIDFrenchMonaco  EQU  6156      ;=0180Ch
;msoLanguageIDFrenchMorocco  EQU  14348      ;=0380Ch
;msoLanguageIDFrenchReunion  EQU  8204      ;=0200Ch
;msoLanguageIDFrenchSenegal  EQU  10252      ;=0280Ch
;msoLanguageIDSwissFrench  EQU  4108      ;=0100Ch
;msoLanguageIDFrenchWestIndies  EQU  7180      ;=01C0Ch
;msoLanguageIDFrenchZaire  EQU  9228      ;=0240Ch
;msoLanguageIDFrisianNetherlands  EQU  1122      ;=0462h
;msoLanguageIDFulfulde  EQU  1127      ;=0467h
;msoLanguageIDGaelicIreland  EQU  2108      ;=083Ch
;msoLanguageIDGaelicScotland  EQU  1084      ;=043Ch
;msoLanguageIDGalician  EQU  1110      ;=0456h
;msoLanguageIDGeorgian  EQU  1079      ;=0437h
;msoLanguageIDGermanAustria  EQU  3079      ;=0C07h
;msoLanguageIDGerman  EQU  1031      ;=0407h
;msoLanguageIDGermanLiechtenstein  EQU  5127      ;=01407h
;msoLanguageIDGermanLuxembourg  EQU  4103      ;=01007h
;msoLanguageIDSwissGerman  EQU  2055      ;=0807h
;msoLanguageIDGreek  EQU  1032      ;=0408h
;msoLanguageIDGuarani  EQU  1140      ;=0474h
;msoLanguageIDGujarati  EQU  1095      ;=0447h
;msoLanguageIDHausa  EQU  1128      ;=0468h
;msoLanguageIDHawaiian  EQU  1141      ;=0475h
;msoLanguageIDHebrew  EQU  1037      ;=040Dh
;msoLanguageIDHindi  EQU  1081      ;=0439h
;msoLanguageIDHungarian  EQU  1038      ;=040Eh
;msoLanguageIDIbibio  EQU  1129      ;=0469h
;msoLanguageIDIcelandic  EQU  1039      ;=040Fh
;msoLanguageIDIgbo  EQU  1136      ;=0470h
;msoLanguageIDIndonesian  EQU  1057      ;=0421h
;msoLanguageIDInuktitut  EQU  1117      ;=045Dh
;msoLanguageIDItalian  EQU  1040      ;=0410h
;msoLanguageIDSwissItalian  EQU  2064      ;=0810h
;msoLanguageIDJapanese  EQU  1041      ;=0411h
;msoLanguageIDKannada  EQU  1099      ;=044Bh
;msoLanguageIDKanuri  EQU  1137      ;=0471h
;msoLanguageIDKashmiri  EQU  1120      ;=0460h
;msoLanguageIDKashmiriDevanagari  EQU  2144      ;=0860h
;msoLanguageIDKazakh  EQU  1087      ;=043Fh
;msoLanguageIDKhmer  EQU  1107      ;=0453h
;msoLanguageIDKirghiz  EQU  1088      ;=0440h
;msoLanguageIDKonkani  EQU  1111      ;=0457h
;msoLanguageIDKorean  EQU  1042      ;=0412h
;msoLanguageIDKyrgyz  EQU  1088      ;=0440h
;msoLanguageIDLatin  EQU  1142      ;=0476h
;msoLanguageIDLao  EQU  1108      ;=0454h
;msoLanguageIDLatvian  EQU  1062      ;=0426h
;msoLanguageIDLithuanian  EQU  1063      ;=0427h
;msoLanguageIDMacedonian  EQU  1071      ;=042Fh
;msoLanguageIDMalaysian  EQU  1086      ;=043Eh
;msoLanguageIDMalayBruneiDarussalam  EQU  2110      ;=083Eh
;msoLanguageIDMalayalam  EQU  1100      ;=044Ch
;msoLanguageIDMaltese  EQU  1082      ;=043Ah
;msoLanguageIDManipuri  EQU  1112      ;=0458h
;msoLanguageIDMarathi  EQU  1102      ;=044Eh
;msoLanguageIDMongolian  EQU  1104      ;=0450h
;msoLanguageIDNepali  EQU  1121      ;=0461h
;msoLanguageIDNorwegianBokmol  EQU  1044      ;=0414h
;msoLanguageIDNorwegianNynorsk  EQU  2068      ;=0814h
;msoLanguageIDOriya  EQU  1096      ;=0448h
;msoLanguageIDOromo  EQU  1138      ;=0472h
;msoLanguageIDPashto  EQU  1123      ;=0463h
;msoLanguageIDPolish  EQU  1045      ;=0415h
;msoLanguageIDBrazilianPortuguese  EQU  1046      ;=0416h
;msoLanguageIDPortuguese  EQU  2070      ;=0816h
;msoLanguageIDPunjabi  EQU  1094      ;=0446h
;msoLanguageIDRhaetoRomanic  EQU  1047      ;=0417h
;msoLanguageIDRomanianMoldova  EQU  2072      ;=0818h
;msoLanguageIDRomanian  EQU  1048      ;=0418h
;msoLanguageIDRussianMoldova  EQU  2073      ;=0819h
;msoLanguageIDRussian  EQU  1049      ;=0419h
;msoLanguageIDSamiLappish  EQU  1083      ;=043Bh
;msoLanguageIDSanskrit  EQU  1103      ;=044Fh
;msoLanguageIDSerbianCyrillic  EQU  3098      ;=0C1Ah
;msoLanguageIDSerbianLatin  EQU  2074      ;=081Ah
;msoLanguageIDSesotho  EQU  1072      ;=0430h
;msoLanguageIDSindhi  EQU  1113      ;=0459h
;msoLanguageIDSindhiPakistan  EQU  2137      ;=0859h
;msoLanguageIDSinhalese  EQU  1115      ;=045Bh
;msoLanguageIDSlovak  EQU  1051      ;=041Bh
;msoLanguageIDSlovenian  EQU  1060      ;=0424h
;msoLanguageIDSomali  EQU  1143      ;=0477h
;msoLanguageIDSorbian  EQU  1070      ;=042Eh
;msoLanguageIDSpanishArgentina  EQU  11274      ;=02C0Ah
;msoLanguageIDSpanishBolivia  EQU  16394      ;=0400Ah
;msoLanguageIDSpanishChile  EQU  13322      ;=0340Ah
;msoLanguageIDSpanishColombia  EQU  9226      ;=0240Ah
;msoLanguageIDSpanishCostaRica  EQU  5130      ;=0140Ah
;msoLanguageIDSpanishDominicanRepublic  EQU  7178      ;=01C0Ah
;msoLanguageIDSpanishEcuador  EQU  12298      ;=0300Ah
;msoLanguageIDSpanishElSalvador  EQU  17418      ;=0440Ah
;msoLanguageIDSpanishGuatemala  EQU  4106      ;=0100Ah
;msoLanguageIDSpanishHonduras  EQU  18442      ;=0480Ah
;msoLanguageIDMexicanSpanish  EQU  2058      ;=080Ah
;msoLanguageIDSpanishNicaragua  EQU  19466      ;=04C0Ah
;msoLanguageIDSpanishPanama  EQU  6154      ;=0180Ah
;msoLanguageIDSpanishParaguay  EQU  15370      ;=03C0Ah
;msoLanguageIDSpanishPeru  EQU  10250      ;=0280Ah
;msoLanguageIDSpanishPuertoRico  EQU  20490      ;=0500Ah
;msoLanguageIDSpanishModernSort  EQU  3082      ;=0C0Ah
;msoLanguageIDSpanish  EQU  1034      ;=040Ah
;msoLanguageIDSpanishUruguay  EQU  14346      ;=0380Ah
;msoLanguageIDSpanishVenezuela  EQU  8202      ;=0200Ah
;msoLanguageIDSutu  EQU  1072      ;=0430h
;msoLanguageIDSwahili  EQU  1089      ;=0441h
;msoLanguageIDSwedishFinland  EQU  2077      ;=081Dh
;msoLanguageIDSwedish  EQU  1053      ;=041Dh
;msoLanguageIDSyriac  EQU  1114      ;=045Ah
;msoLanguageIDTajik  EQU  1064      ;=0428h
;msoLanguageIDTamil  EQU  1097      ;=0449h
;msoLanguageIDTamazight  EQU  1119      ;=045Fh
;msoLanguageIDTamazightLatin  EQU  2143      ;=085Fh
;msoLanguageIDTatar  EQU  1092      ;=0444h
;msoLanguageIDTelugu  EQU  1098      ;=044Ah
;msoLanguageIDThai  EQU  1054      ;=041Eh
;msoLanguageIDTibetan  EQU  1105      ;=0451h
;msoLanguageIDTigrignaEthiopic  EQU  1139      ;=0473h
;msoLanguageIDTigrignaEritrea  EQU  2163      ;=0873h
;msoLanguageIDTsonga  EQU  1073      ;=0431h
;msoLanguageIDTswana  EQU  1074      ;=0432h
;msoLanguageIDTurkish  EQU  1055      ;=041Fh
;msoLanguageIDTurkmen  EQU  1090      ;=0442h
;msoLanguageIDUkrainian  EQU  1058      ;=0422h
;msoLanguageIDUrdu  EQU  1056      ;=0420h
;msoLanguageIDUzbekCyrillic  EQU  2115      ;=0843h
;msoLanguageIDUzbekLatin  EQU  1091      ;=0443h
;msoLanguageIDVenda  EQU  1075      ;=0433h
;msoLanguageIDVietnamese  EQU  1066      ;=042Ah
;msoLanguageIDWelsh  EQU  1106      ;=0452h
;msoLanguageIDXhosa  EQU  1076      ;=0434h
;msoLanguageIDYi  EQU  1144      ;=0478h
;msoLanguageIDYiddish  EQU  1085      ;=043Dh
;msoLanguageIDYoruba  EQU  1130      ;=046Ah
;msoLanguageIDZulu  EQU  1077      ;=0435h
;
;;--- MsoScreenSize, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoScreenSize typedef SDWORD
;msoScreenSize544x376  EQU  0
;msoScreenSize640x480  EQU  1
;msoScreenSize720x512  EQU  2
;msoScreenSize800x600  EQU  3
;msoScreenSize1024x768  EQU  4
;msoScreenSize1152x882  EQU  5
;msoScreenSize1152x900  EQU  6
;msoScreenSize1280x1024  EQU  7
;msoScreenSize1600x1200  EQU  8
;msoScreenSize1800x1440  EQU  9
;msoScreenSize1920x1200  EQU  10
;
;;--- MsoCharacterSet, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoCharacterSet typedef SDWORD
;msoCharacterSetArabic  EQU  1
;msoCharacterSetCyrillic  EQU  2
;msoCharacterSetEnglishWesternEuropeanOtherLatinScript  EQU  3
;msoCharacterSetGreek  EQU  4
;msoCharacterSetHebrew  EQU  5
;msoCharacterSetJapanese  EQU  6
;msoCharacterSetKorean  EQU  7
;msoCharacterSetMultilingualUnicode  EQU  8
;msoCharacterSetSimplifiedChinese  EQU  9
;msoCharacterSetThai  EQU  10
;msoCharacterSetTraditionalChinese  EQU  11
;msoCharacterSetVietnamese  EQU  12
;
;;--- MsoEncoding, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoEncoding typedef SDWORD
;msoEncodingThai  EQU  874      ;=036Ah
;msoEncodingJapaneseShiftJIS  EQU  932      ;=03A4h
;msoEncodingSimplifiedChineseGBK  EQU  936      ;=03A8h
;msoEncodingKorean  EQU  949      ;=03B5h
;msoEncodingTraditionalChineseBig5  EQU  950      ;=03B6h
;msoEncodingUnicodeLittleEndian  EQU  1200      ;=04B0h
;msoEncodingUnicodeBigEndian  EQU  1201      ;=04B1h
;msoEncodingCentralEuropean  EQU  1250      ;=04E2h
;msoEncodingCyrillic  EQU  1251      ;=04E3h
;msoEncodingWestern  EQU  1252      ;=04E4h
;msoEncodingGreek  EQU  1253      ;=04E5h
;msoEncodingTurkish  EQU  1254      ;=04E6h
;msoEncodingHebrew  EQU  1255      ;=04E7h
;msoEncodingArabic  EQU  1256      ;=04E8h
;msoEncodingBaltic  EQU  1257      ;=04E9h
;msoEncodingVietnamese  EQU  1258      ;=04EAh
;msoEncodingAutoDetect  EQU  50001      ;=0C351h
;msoEncodingJapaneseAutoDetect  EQU  50932      ;=0C6F4h
;msoEncodingSimplifiedChineseAutoDetect  EQU  50936      ;=0C6F8h
;msoEncodingKoreanAutoDetect  EQU  50949      ;=0C705h
;msoEncodingTraditionalChineseAutoDetect  EQU  50950      ;=0C706h
;msoEncodingCyrillicAutoDetect  EQU  51251      ;=0C833h
;msoEncodingGreekAutoDetect  EQU  51253      ;=0C835h
;msoEncodingArabicAutoDetect  EQU  51256      ;=0C838h
;msoEncodingISO88591Latin1  EQU  28591      ;=06FAFh
;msoEncodingISO88592CentralEurope  EQU  28592      ;=06FB0h
;msoEncodingISO88593Latin3  EQU  28593      ;=06FB1h
;msoEncodingISO88594Baltic  EQU  28594      ;=06FB2h
;msoEncodingISO88595Cyrillic  EQU  28595      ;=06FB3h
;msoEncodingISO88596Arabic  EQU  28596      ;=06FB4h
;msoEncodingISO88597Greek  EQU  28597      ;=06FB5h
;msoEncodingISO88598Hebrew  EQU  28598      ;=06FB6h
;msoEncodingISO88599Turkish  EQU  28599      ;=06FB7h
;msoEncodingISO885915Latin9  EQU  28605      ;=06FBDh
;msoEncodingISO2022JPNoHalfwidthKatakana  EQU  50220      ;=0C42Ch
;msoEncodingISO2022JPJISX02021984  EQU  50221      ;=0C42Dh
;msoEncodingISO2022JPJISX02011989  EQU  50222      ;=0C42Eh
;msoEncodingISO2022KR  EQU  50225      ;=0C431h
;msoEncodingISO2022CNTraditionalChinese  EQU  50227      ;=0C433h
;msoEncodingISO2022CNSimplifiedChinese  EQU  50229      ;=0C435h
;msoEncodingMacRoman  EQU  10000      ;=02710h
;msoEncodingMacJapanese  EQU  10001      ;=02711h
;msoEncodingMacTraditionalChineseBig5  EQU  10002      ;=02712h
;msoEncodingMacKorean  EQU  10003      ;=02713h
;msoEncodingMacArabic  EQU  10004      ;=02714h
;msoEncodingMacHebrew  EQU  10005      ;=02715h
;msoEncodingMacGreek1  EQU  10006      ;=02716h
;msoEncodingMacCyrillic  EQU  10007      ;=02717h
;msoEncodingMacSimplifiedChineseGB2312  EQU  10008      ;=02718h
;msoEncodingMacRomania  EQU  10010      ;=0271Ah
;msoEncodingMacUkraine  EQU  10017      ;=02721h
;msoEncodingMacLatin2  EQU  10029      ;=0272Dh
;msoEncodingMacIcelandic  EQU  10079      ;=0275Fh
;msoEncodingMacTurkish  EQU  10081      ;=02761h
;msoEncodingMacCroatia  EQU  10082      ;=02762h
;msoEncodingEBCDICUSCanada  EQU  37      ;=025h
;msoEncodingEBCDICInternational  EQU  500      ;=01F4h
;msoEncodingEBCDICMultilingualROECELatin2  EQU  870      ;=0366h
;msoEncodingEBCDICGreekModern  EQU  875      ;=036Bh
;msoEncodingEBCDICTurkishLatin5  EQU  1026      ;=0402h
;msoEncodingEBCDICGermany  EQU  20273      ;=04F31h
;msoEncodingEBCDICDenmarkNorway  EQU  20277      ;=04F35h
;msoEncodingEBCDICFinlandSweden  EQU  20278      ;=04F36h
;msoEncodingEBCDICItaly  EQU  20280      ;=04F38h
;msoEncodingEBCDICLatinAmericaSpain  EQU  20284      ;=04F3Ch
;msoEncodingEBCDICUnitedKingdom  EQU  20285      ;=04F3Dh
;msoEncodingEBCDICJapaneseKatakanaExtended  EQU  20290      ;=04F42h
;msoEncodingEBCDICFrance  EQU  20297      ;=04F49h
;msoEncodingEBCDICArabic  EQU  20420      ;=04FC4h
;msoEncodingEBCDICGreek  EQU  20423      ;=04FC7h
;msoEncodingEBCDICHebrew  EQU  20424      ;=04FC8h
;msoEncodingEBCDICKoreanExtended  EQU  20833      ;=05161h
;msoEncodingEBCDICThai  EQU  20838      ;=05166h
;msoEncodingEBCDICIcelandic  EQU  20871      ;=05187h
;msoEncodingEBCDICTurkish  EQU  20905      ;=051A9h
;msoEncodingEBCDICRussian  EQU  20880      ;=05190h
;msoEncodingEBCDICSerbianBulgarian  EQU  21025      ;=05221h
;msoEncodingEBCDICJapaneseKatakanaExtendedAndJapanese  EQU  50930      ;=0C6F2h
;msoEncodingEBCDICUSCanadaAndJapanese  EQU  50931      ;=0C6F3h
;msoEncodingEBCDICKoreanExtendedAndKorean  EQU  50933      ;=0C6F5h
;msoEncodingEBCDICSimplifiedChineseExtendedAndSimplifiedChinese  EQU  50935      ;=0C6F7h
;msoEncodingEBCDICUSCanadaAndTraditionalChinese  EQU  50937      ;=0C6F9h
;msoEncodingEBCDICJapaneseLatinExtendedAndJapanese  EQU  50939      ;=0C6FBh
;msoEncodingOEMUnitedStates  EQU  437      ;=01B5h
;msoEncodingOEMGreek437G  EQU  737      ;=02E1h
;msoEncodingOEMBaltic  EQU  775      ;=0307h
;msoEncodingOEMMultilingualLatinI  EQU  850      ;=0352h
;msoEncodingOEMMultilingualLatinII  EQU  852      ;=0354h
;msoEncodingOEMCyrillic  EQU  855      ;=0357h
;msoEncodingOEMTurkish  EQU  857      ;=0359h
;msoEncodingOEMPortuguese  EQU  860      ;=035Ch
;msoEncodingOEMIcelandic  EQU  861      ;=035Dh
;msoEncodingOEMHebrew  EQU  862      ;=035Eh
;msoEncodingOEMCanadianFrench  EQU  863      ;=035Fh
;msoEncodingOEMArabic  EQU  864      ;=0360h
;msoEncodingOEMNordic  EQU  865      ;=0361h
;msoEncodingOEMCyrillicII  EQU  866      ;=0362h
;msoEncodingOEMModernGreek  EQU  869      ;=0365h
;msoEncodingEUCJapanese  EQU  51932      ;=0CADCh
;msoEncodingEUCChineseSimplifiedChinese  EQU  51936      ;=0CAE0h
;msoEncodingEUCKorean  EQU  51949      ;=0CAEDh
;msoEncodingEUCTaiwaneseTraditionalChinese  EQU  51950      ;=0CAEEh
;msoEncodingISCIIDevanagari  EQU  57002      ;=0DEAAh
;msoEncodingISCIIBengali  EQU  57003      ;=0DEABh
;msoEncodingISCIITamil  EQU  57004      ;=0DEACh
;msoEncodingISCIITelugu  EQU  57005      ;=0DEADh
;msoEncodingISCIIAssamese  EQU  57006      ;=0DEAEh
;msoEncodingISCIIOriya  EQU  57007      ;=0DEAFh
;msoEncodingISCIIKannada  EQU  57008      ;=0DEB0h
;msoEncodingISCIIMalayalam  EQU  57009      ;=0DEB1h
;msoEncodingISCIIGujarati  EQU  57010      ;=0DEB2h
;msoEncodingISCIIPunjabi  EQU  57011      ;=0DEB3h
;msoEncodingArabicASMO  EQU  708      ;=02C4h
;msoEncodingArabicTransparentASMO  EQU  720      ;=02D0h
;msoEncodingKoreanJohab  EQU  1361      ;=0551h
;msoEncodingTaiwanCNS  EQU  20000      ;=04E20h
;msoEncodingTaiwanTCA  EQU  20001      ;=04E21h
;msoEncodingTaiwanEten  EQU  20002      ;=04E22h
;msoEncodingTaiwanIBM5550  EQU  20003      ;=04E23h
;msoEncodingTaiwanTeleText  EQU  20004      ;=04E24h
;msoEncodingTaiwanWang  EQU  20005      ;=04E25h
;msoEncodingIA5IRV  EQU  20105      ;=04E89h
;msoEncodingIA5German  EQU  20106      ;=04E8Ah
;msoEncodingIA5Swedish  EQU  20107      ;=04E8Bh
;msoEncodingIA5Norwegian  EQU  20108      ;=04E8Ch
;msoEncodingUSASCII  EQU  20127      ;=04E9Fh
;msoEncodingT61  EQU  20261      ;=04F25h
;msoEncodingISO6937NonSpacingAccent  EQU  20269      ;=04F2Dh
;msoEncodingKOI8R  EQU  20866      ;=05182h
;msoEncodingExtAlphaLowercase  EQU  21027      ;=05223h
;msoEncodingKOI8U  EQU  21866      ;=0556Ah
;msoEncodingEuropa3  EQU  29001      ;=07149h
;msoEncodingHZGBSimplifiedChinese  EQU  52936      ;=0CEC8h
;msoEncodingUTF7  EQU  65000      ;=0FDE8h
;msoEncodingUTF8  EQU  65001      ;=0FDE9h
;
;;--- MsoHTMLProjectOpen, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoHTMLProjectOpen typedef SDWORD
;msoHTMLProjectOpenSourceView  EQU  1
;msoHTMLProjectOpenTextView  EQU  2
;
;;--- MsoHTMLProjectState, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoHTMLProjectState typedef SDWORD
;msoHTMLProjectStateDocumentLocked  EQU  1
;msoHTMLProjectStateProjectLocked  EQU  2
;msoHTMLProjectStateDocumentProjectUnlocked  EQU  3
;
;;--- MsoFileDialogType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileDialogType typedef SDWORD
;msoFileDialogOpen  EQU  1
;msoFileDialogSaveAs  EQU  2
;msoFileDialogFilePicker  EQU  3
;msoFileDialogFolderPicker  EQU  4
;
;;--- MsoFileDialogView, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileDialogView typedef SDWORD
;msoFileDialogViewList  EQU  1
;msoFileDialogViewDetails  EQU  2
;msoFileDialogViewProperties  EQU  3
;msoFileDialogViewPreview  EQU  4
;msoFileDialogViewThumbnail  EQU  5
;msoFileDialogViewLargeIcons  EQU  6
;msoFileDialogViewSmallIcons  EQU  7
;msoFileDialogViewWebView  EQU  8
;
;;--- MsoAutomationSecurity, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
MsoAutomationSecurity typedef SDWORD
;msoAutomationSecurityLow  EQU  1
;msoAutomationSecurityByUI  EQU  2
;msoAutomationSecurityForceDisable  EQU  3
;
;;--- MailFormat, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MailFormat typedef SDWORD
;mfPlainText  EQU  1
;mfHTML  EQU  2
;mfRTF  EQU  3
;
;;--- MsoAlertButtonType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoAlertButtonType typedef SDWORD
;msoAlertButtonOK  EQU  0
;msoAlertButtonOKCancel  EQU  1
;msoAlertButtonAbortRetryIgnore  EQU  2
;msoAlertButtonYesNoCancel  EQU  3
;msoAlertButtonYesNo  EQU  4
;msoAlertButtonRetryCancel  EQU  5
;msoAlertButtonYesAllNoCancel  EQU  6
;
;;--- MsoAlertIconType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoAlertIconType typedef SDWORD
;msoAlertIconNoIcon  EQU  0
;msoAlertIconCritical  EQU  1
;msoAlertIconQuery  EQU  2
;msoAlertIconWarning  EQU  3
;msoAlertIconInfo  EQU  4
;
;;--- MsoAlertDefaultType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoAlertDefaultType typedef SDWORD
;msoAlertDefaultFirst  EQU  0
;msoAlertDefaultSecond  EQU  1
;msoAlertDefaultThird  EQU  2
;msoAlertDefaultFourth  EQU  3
;msoAlertDefaultFifth  EQU  4
;
;;--- MsoAlertCancelType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoAlertCancelType typedef SDWORD
;msoAlertCancelDefault  EQU  -1
;msoAlertCancelFirst  EQU  0
;msoAlertCancelSecond  EQU  1
;msoAlertCancelThird  EQU  2
;msoAlertCancelFourth  EQU  3
;msoAlertCancelFifth  EQU  4
;
;;--- MsoSearchIn, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoSearchIn typedef SDWORD
;msoSearchInMyComputer  EQU  0
;msoSearchInOutlook  EQU  1
;msoSearchInMyNetworkPlaces  EQU  2
;msoSearchInCustom  EQU  3
;
;;--- MsoTargetBrowser, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoTargetBrowser typedef SDWORD
;msoTargetBrowserV3  EQU  0
;msoTargetBrowserV4  EQU  1
;msoTargetBrowserIE4  EQU  2
;msoTargetBrowserIE5  EQU  3
;msoTargetBrowserIE6  EQU  4
;
;;--- MsoOrgChartOrientation, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoOrgChartOrientation typedef SDWORD
;msoOrgChartOrientationMixed  EQU  -2      ;=0FFFFFFFEh
;msoOrgChartOrientationVertical  EQU  1
;
;;--- MsoOrgChartLayoutType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoOrgChartLayoutType typedef SDWORD
;msoOrgChartLayoutMixed  EQU  -2      ;=0FFFFFFFEh
;msoOrgChartLayoutStandard  EQU  1
;msoOrgChartLayoutBothHanging  EQU  2
;msoOrgChartLayoutLeftHanging  EQU  3
;msoOrgChartLayoutRightHanging  EQU  4
;
;;--- MsoRelativeNodePosition, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoRelativeNodePosition typedef SDWORD
;msoBeforeNode  EQU  1
;msoAfterNode  EQU  2
;msoBeforeFirstSibling  EQU  3
;msoAfterLastSibling  EQU  4
;
;;--- MsoDiagramType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoDiagramType typedef SDWORD
;msoDiagramMixed  EQU  -2      ;=0FFFFFFFEh
;msoDiagramOrgChart  EQU  1
;msoDiagramCycle  EQU  2
;msoDiagramRadial  EQU  3
;msoDiagramPyramid  EQU  4
;msoDiagramVenn  EQU  5
;msoDiagramTarget  EQU  6
;
;;--- MsoDiagramNodeType, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoDiagramNodeType typedef SDWORD
;msoDiagramNode  EQU  1
;msoDiagramAssistant  EQU  2
;
;;--- MsoMoveRow, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoMoveRow typedef SDWORD
;msoMoveRowFirst  EQU  -4      ;=0FFFFFFFCh
;msoMoveRowPrev  EQU  -3      ;=0FFFFFFFDh
;msoMoveRowNext  EQU  -2      ;=0FFFFFFFEh
;msoMoveRowNbr  EQU  -1
;
;;--- MsoFilterComparison, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFilterComparison typedef SDWORD
;msoFilterComparisonEqual  EQU  0
;msoFilterComparisonNotEqual  EQU  1
;msoFilterComparisonLessThan  EQU  2
;msoFilterComparisonGreaterThan  EQU  3
;msoFilterComparisonLessThanEqual  EQU  4
;msoFilterComparisonGreaterThanEqual  EQU  5
;msoFilterComparisonIsBlank  EQU  6
;msoFilterComparisonIsNotBlank  EQU  7
;msoFilterComparisonContains  EQU  8
;msoFilterComparisonNotContains  EQU  9
;
;;--- MsoFilterConjunction, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFilterConjunction typedef SDWORD
;msoFilterConjunctionAnd  EQU  0
;msoFilterConjunctionOr  EQU  1
;
;;--- MsoFileNewSection, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileNewSection typedef SDWORD
;msoOpenDocument  EQU  0
;msoNew  EQU  1
;msoNewfromExistingFile  EQU  2
;msoNewfromTemplate  EQU  3
;msoBottomSection  EQU  4
;
;;--- MsoFileNewAction, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoFileNewAction typedef SDWORD
;msoEditFile  EQU  0
;msoCreateNewFile  EQU  1
;msoOpenFile  EQU  2
;
;;--- MsoLanguageIDHidden, Type=ENUM, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoLanguageIDHidden typedef SDWORD
;msoLanguageIDChineseHongKong  EQU  3076      ;=0C04h
;msoLanguageIDChineseMacao  EQU  5124      ;=01404h
;msoLanguageIDEnglishTrinidad  EQU  11273      ;=02C09h
;
;;--- MsoRGBType, Type=ALIAS, GUID={00000000-0000-0000-0000-000000000000}
;
;MsoRGBType typedef SDWORD
;
;;--- _IMsoDispObj, Type=INTERFACE, GUID={000C0300-0000-0000-C000-000000000046}
;
;ifndef _IMsoDispObjVtbl
;BEGIN_INTERFACE _IMsoDispObj, IDispatch
;  STDMETHOD  get_Application  , :ptr LPDISPATCH
;  STDMETHOD  get_Creator  , :ptr SDWORD
;END_INTERFACE
;endif
;
;sIID__IMsoDispObj textequ <IID {0000C0300h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- AnswerWizard, Type=INTERFACE, GUID={000C0360-0000-0000-C000-000000000046}
;
;ifndef AnswerWizardVtbl
;BEGIN_INTERFACE AnswerWizard, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Files  , :ptr ptr AnswerWizardFiles
;  STDMETHOD  ClearFileList
;  STDMETHOD  ResetFileList
;END_INTERFACE
;endif
;
;sIID_AnswerWizard textequ <IID {0000C0360h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Assistant, Type=INTERFACE, GUID={000C0322-0000-0000-C000-000000000046}
;
;ifndef AssistantVtbl
;BEGIN_INTERFACE Assistant, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  Move  , :SDWORD,:SDWORD
;  STDMETHOD  put_Top  , :SDWORD
;  STDMETHOD  get_Top  , :ptr SDWORD
;  STDMETHOD  put_Left  , :SDWORD
;  STDMETHOD  get_Left  , :ptr SDWORD
;  STDMETHOD  Help
;  STDMETHOD  StartWizard  , :BOOL,:BSTR,:SDWORD,:VARIANT,:VARIANT,:VARIANT,:VARIANT,:VARIANT,:VARIANT,:ptr SDWORD
;  STDMETHOD  EndWizard  , :SDWORD,:BOOL,:VARIANT
;  STDMETHOD  ActivateWizard  , :SDWORD,:MsoWizardActType,:VARIANT
;  STDMETHOD  ResetTips
;  STDMETHOD  get_NewBalloon  , :ptr ptr Balloon
;  STDMETHOD  get_BalloonError  , :ptr MsoBalloonErrorType
;  STDMETHOD  get_Visible  , :ptr BOOL
;  STDMETHOD  put_Visible  , :BOOL
;  STDMETHOD  get_Animation  , :ptr MsoAnimationType
;  STDMETHOD  put_Animation  , :MsoAnimationType
;  STDMETHOD  get_Reduced  , :ptr BOOL
;  STDMETHOD  put_Reduced  , :BOOL
;  STDMETHOD  put_AssistWithHelp  , :BOOL
;  STDMETHOD  get_AssistWithHelp  , :ptr BOOL
;  STDMETHOD  put_AssistWithWizards  , :BOOL
;  STDMETHOD  get_AssistWithWizards  , :ptr BOOL
;  STDMETHOD  put_AssistWithAlerts  , :BOOL
;  STDMETHOD  get_AssistWithAlerts  , :ptr BOOL
;  STDMETHOD  put_MoveWhenInTheWay  , :BOOL
;  STDMETHOD  get_MoveWhenInTheWay  , :ptr BOOL
;  STDMETHOD  put_Sounds  , :BOOL
;  STDMETHOD  get_Sounds  , :ptr BOOL
;  STDMETHOD  put_FeatureTips  , :BOOL
;  STDMETHOD  get_FeatureTips  , :ptr BOOL
;  STDMETHOD  put_MouseTips  , :BOOL
;  STDMETHOD  get_MouseTips  , :ptr BOOL
;  STDMETHOD  put_KeyboardShortcutTips  , :BOOL
;  STDMETHOD  get_KeyboardShortcutTips  , :ptr BOOL
;  STDMETHOD  put_HighPriorityTips  , :BOOL
;  STDMETHOD  get_HighPriorityTips  , :ptr BOOL
;  STDMETHOD  put_TipOfDay  , :BOOL
;  STDMETHOD  get_TipOfDay  , :ptr BOOL
;  STDMETHOD  put_GuessHelp  , :BOOL
;  STDMETHOD  get_GuessHelp  , :ptr BOOL
;  STDMETHOD  put_SearchWhenProgramming  , :BOOL
;  STDMETHOD  get_SearchWhenProgramming  , :ptr BOOL
;  STDMETHOD  get_Item  , :ptr BSTR
;  STDMETHOD  get_FileName  , :ptr BSTR
;  STDMETHOD  put_FileName  , :BSTR
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_On  , :ptr BOOL
;  STDMETHOD  put_On  , :BOOL
;  STDMETHOD  DoAlert  , :BSTR,:BSTR,:MsoAlertButtonType,:MsoAlertIconType,:MsoAlertDefaultType,:MsoAlertCancelType,:BOOL,:ptr SDWORD
;END_INTERFACE
;endif
;
;sIID_Assistant textequ <IID {0000C0322h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- DocumentProperty, Type=INTERFACE, GUID={2DF8D04E-5BFA-101B-BDE5-00AA0044DE52}
;
;ifndef DocumentPropertyVtbl
;BEGIN_INTERFACE DocumentProperty, IDispatch
;  STDMETHOD  get_Parent
;  STDMETHOD  Delete
;  STDMETHOD  get_Name  , :SDWORD,:ptr BSTR
;  STDMETHOD  put_Name  , :SDWORD,:BSTR
;  STDMETHOD  get_Value  , :SDWORD,:ptr VARIANT
;  STDMETHOD  put_Value  , :SDWORD,:VARIANT
;  STDMETHOD  get_Type  , :SDWORD,:ptr MsoDocProperties
;  STDMETHOD  put_Type  , :SDWORD,:MsoDocProperties
;  STDMETHOD  get_LinkToContent  , :ptr BOOL
;  STDMETHOD  put_LinkToContent  , :BOOL
;  STDMETHOD  get_LinkSource  , :ptr BSTR
;  STDMETHOD  put_LinkSource  , :BSTR
;  STDMETHOD  get_Application  , :ptr LPDISPATCH
;  STDMETHOD  get_Creator  , :ptr SDWORD
;END_INTERFACE
;endif
;
;sIID_DocumentProperty textequ <IID {02DF8D04Eh,05BFAh,0101Bh,{0BDh,0E5h,000h,0AAh,000h,044h,0DEh,052h}}>
;
;;--- DocumentProperties, Type=INTERFACE, GUID={2DF8D04D-5BFA-101B-BDE5-00AA0044DE52}
;
;ifndef DocumentPropertiesVtbl
;BEGIN_INTERFACE DocumentProperties, IDispatch
;  STDMETHOD  get_Parent
;  STDMETHOD  get_Item  , :VARIANT,:SDWORD,:ptr ptr DocumentProperty
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Add_  , :BSTR,:BOOL,:VARIANT,:VARIANT,:VARIANT,:SDWORD,:ptr ptr DocumentProperty
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  get_Application  , :ptr LPDISPATCH
;  STDMETHOD  get_Creator  , :ptr SDWORD
;END_INTERFACE
;endif
;
;sIID_DocumentProperties textequ <IID {02DF8D04Dh,05BFAh,0101Bh,{0BDh,0E5h,000h,0AAh,000h,044h,0DEh,052h}}>
;
;;--- IAccessible, Type=INTERFACE, GUID={618736E0-3C3D-11CF-810C-00AA00389B71}
;
;ifndef IAccessibleVtbl
;BEGIN_INTERFACE IAccessible, IDispatch
;  STDMETHOD  get_accParent  , :ptr LPDISPATCH
;  STDMETHOD  get_accChildCount  , :ptr SDWORD
;  STDMETHOD  get_accChild  , :VARIANT,:ptr LPDISPATCH
;  STDMETHOD  get_accName  , :VARIANT,:ptr BSTR
;  STDMETHOD  get_accValue  , :VARIANT,:ptr BSTR
;  STDMETHOD  get_accDescription  , :VARIANT,:ptr BSTR
;  STDMETHOD  get_accRole  , :VARIANT,:ptr VARIANT
;  STDMETHOD  get_accState  , :VARIANT,:ptr VARIANT
;  STDMETHOD  get_accHelp  , :VARIANT,:ptr BSTR
;  STDMETHOD  get_accHelpTopic  , :ptr BSTR,:VARIANT,:ptr SDWORD
;  STDMETHOD  get_accKeyboardShortcut  , :VARIANT,:ptr BSTR
;  STDMETHOD  get_accFocus  , :ptr VARIANT
;  STDMETHOD  get_accSelection  , :ptr VARIANT
;  STDMETHOD  get_accDefaultAction  , :VARIANT,:ptr BSTR
;  STDMETHOD  accSelect  , :SDWORD,:VARIANT
;  STDMETHOD  accLocation  , :ptr SDWORD,:ptr SDWORD,:ptr SDWORD,:ptr SDWORD,:VARIANT
;  STDMETHOD  accNavigate  , :SDWORD,:VARIANT,:ptr VARIANT
;  STDMETHOD  accHitTest  , :SDWORD,:SDWORD,:ptr VARIANT
;  STDMETHOD  accDoDefaultAction  , :VARIANT
;  STDMETHOD  put_accName  , :VARIANT,:BSTR
;  STDMETHOD  put_accValue  , :VARIANT,:BSTR
;END_INTERFACE
;endif
;
;sIID_IAccessible textequ <IID {0618736E0h,03C3Dh,011CFh,{081h,00Ch,000h,0AAh,000h,038h,09Bh,071h}}>
;
;;--- CommandBarControls, Type=INTERFACE, GUID={000C0306-0000-0000-C000-000000000046}
;
;ifndef CommandBarControlsVtbl
;BEGIN_INTERFACE CommandBarControls, _IMsoDispObj
;  STDMETHOD  Add_  , :VARIANT,:VARIANT,:VARIANT,:VARIANT,:VARIANT,:ptr ptr CommandBarControl
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get_Item  , :VARIANT,:ptr ptr CommandBarControl
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  get_Parent  , :ptr ptr CommandBar
;END_INTERFACE
;endif
;
;sIID_CommandBarControls textequ <IID {0000C0306h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _IMsoOleAccDispObj, Type=INTERFACE, GUID={000C0301-0000-0000-C000-000000000046}
;
;ifndef _IMsoOleAccDispObjVtbl
;BEGIN_INTERFACE _IMsoOleAccDispObj, IAccessible
;  STDMETHOD  get_Application  , :ptr LPDISPATCH
;  STDMETHOD  get_Creator  , :ptr SDWORD
;END_INTERFACE
;endif
;
;sIID__IMsoOleAccDispObj textequ <IID {0000C0301h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Adjustments, Type=INTERFACE, GUID={000C0310-0000-0000-C000-000000000046}
;
;ifndef AdjustmentsVtbl
;BEGIN_INTERFACE Adjustments, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get_Item  , :SDWORD,:ptr REAL4
;  STDMETHOD  put_Item  , :SDWORD,:REAL4
;END_INTERFACE
;endif
;
;sIID_Adjustments textequ <IID {0000C0310h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- IFoundFiles, Type=INTERFACE, GUID={000C0338-0000-0000-C000-000000000046}
;
;ifndef IFoundFilesVtbl
;BEGIN_INTERFACE IFoundFiles, IDispatch
;  STDMETHOD  get_Item  , :SDWORD,:ptr BSTR
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_IFoundFiles textequ <IID {0000C0338h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- IFind, Type=INTERFACE, GUID={000C0337-0000-0000-C000-000000000046}
;
;ifndef IFindVtbl
;BEGIN_INTERFACE IFind, IDispatch
;  STDMETHOD  get_SearchPath  , :ptr BSTR
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_SubDir  , :ptr BOOL
;  STDMETHOD  get_Title  , :ptr BSTR
;  STDMETHOD  get_Author  , :ptr BSTR
;  STDMETHOD  get_Keywords  , :ptr BSTR
;  STDMETHOD  get_Subject  , :ptr BSTR
;  STDMETHOD  get_Options  , :ptr MsoFileFindOptions
;  STDMETHOD  get_MatchCase  , :ptr BOOL
;  STDMETHOD  get_Text  , :ptr BSTR
;  STDMETHOD  get_PatternMatch  , :ptr BOOL
;  STDMETHOD  get_DateSavedFrom  , :ptr VARIANT
;  STDMETHOD  get_DateSavedTo  , :ptr VARIANT
;  STDMETHOD  get_SavedBy  , :ptr BSTR
;  STDMETHOD  get_DateCreatedFrom  , :ptr VARIANT
;  STDMETHOD  get_DateCreatedTo  , :ptr VARIANT
;  STDMETHOD  get_View  , :ptr MsoFileFindView
;  STDMETHOD  get_SortBy  , :ptr MsoFileFindSortBy
;  STDMETHOD  get_ListBy  , :ptr MsoFileFindListBy
;  STDMETHOD  get_SelectedFile  , :ptr SDWORD
;  STDMETHOD  get_Results  , :ptr ptr IFoundFiles
;  STDMETHOD  Show  , :ptr SDWORD
;  STDMETHOD  put_SearchPath  , :BSTR
;  STDMETHOD  put_Name  , :BSTR
;  STDMETHOD  put_SubDir  , :BOOL
;  STDMETHOD  put_Title  , :BSTR
;  STDMETHOD  put_Author  , :BSTR
;  STDMETHOD  put_Keywords  , :BSTR
;  STDMETHOD  put_Subject  , :BSTR
;  STDMETHOD  put_Options  , :MsoFileFindOptions
;  STDMETHOD  put_MatchCase  , :BOOL
;  STDMETHOD  put_Text  , :BSTR
;  STDMETHOD  put_PatternMatch  , :BOOL
;  STDMETHOD  put_DateSavedFrom  , :VARIANT
;  STDMETHOD  put_DateSavedTo  , :VARIANT
;  STDMETHOD  put_SavedBy  , :BSTR
;  STDMETHOD  put_DateCreatedFrom  , :VARIANT
;  STDMETHOD  put_DateCreatedTo  , :VARIANT
;  STDMETHOD  put_View  , :MsoFileFindView
;  STDMETHOD  put_SortBy  , :MsoFileFindSortBy
;  STDMETHOD  put_ListBy  , :MsoFileFindListBy
;  STDMETHOD  put_SelectedFile  , :SDWORD
;  STDMETHOD  Execute
;  STDMETHOD  Load  , :BSTR
;  STDMETHOD  Save  , :BSTR
;  STDMETHOD  Delete  , :BSTR
;  STDMETHOD  get_FileType  , :ptr SDWORD
;  STDMETHOD  put_FileType  , :SDWORD
;END_INTERFACE
;endif
;
;sIID_IFind textequ <IID {0000C0337h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CommandBarControl, Type=INTERFACE, GUID={000C0308-0000-0000-C000-000000000046}
;
;ifndef CommandBarControlVtbl
;BEGIN_INTERFACE CommandBarControl, _IMsoOleAccDispObj
;  STDMETHOD  get_BeginGroup  , :ptr BOOL
;  STDMETHOD  put_BeginGroup  , :BOOL
;  STDMETHOD  get_BuiltIn  , :ptr BOOL
;  STDMETHOD  get_Caption  , :ptr BSTR
;  STDMETHOD  put_Caption  , :BSTR
;  STDMETHOD  get_Control  , :ptr LPDISPATCH
;  STDMETHOD  Copy  , :VARIANT,:VARIANT,:ptr ptr CommandBarControl
;  STDMETHOD  Delete  , :VARIANT
;  STDMETHOD  get_DescriptionText  , :ptr BSTR
;  STDMETHOD  put_DescriptionText  , :BSTR
;  STDMETHOD  get_Enabled  , :ptr BOOL
;  STDMETHOD  put_Enabled  , :BOOL
;  STDMETHOD  Execute
;  STDMETHOD  get_Height  , :ptr SDWORD
;  STDMETHOD  put_Height  , :SDWORD
;  STDMETHOD  get_HelpContextId  , :ptr SDWORD
;  STDMETHOD  put_HelpContextId  , :SDWORD
;  STDMETHOD  get_HelpFile  , :ptr BSTR
;  STDMETHOD  put_HelpFile  , :BSTR
;  STDMETHOD  get_Id  , :ptr SDWORD
;  STDMETHOD  get_Index  , :ptr SDWORD
;  STDMETHOD  get_InstanceId  , :ptr SDWORD
;  STDMETHOD  Move  , :VARIANT,:VARIANT,:ptr ptr CommandBarControl
;  STDMETHOD  get_Left  , :ptr SDWORD
;  STDMETHOD  get_OLEUsage  , :ptr MsoControlOLEUsage
;  STDMETHOD  put_OLEUsage  , :MsoControlOLEUsage
;  STDMETHOD  get_OnAction  , :ptr BSTR
;  STDMETHOD  put_OnAction  , :BSTR
;  STDMETHOD  get_Parent  , :ptr ptr CommandBar
;  STDMETHOD  get_Parameter  , :ptr BSTR
;  STDMETHOD  put_Parameter  , :BSTR
;  STDMETHOD  get_Priority  , :ptr SDWORD
;  STDMETHOD  put_Priority  , :SDWORD
;  STDMETHOD  Reset
;  STDMETHOD  SetFocus
;  STDMETHOD  get_Tag  , :ptr BSTR
;  STDMETHOD  put_Tag  , :BSTR
;  STDMETHOD  get_TooltipText  , :ptr BSTR
;  STDMETHOD  put_TooltipText  , :BSTR
;  STDMETHOD  get_Top  , :ptr SDWORD
;  STDMETHOD  get_Type  , :ptr MsoControlType
;  STDMETHOD  get_Visible  , :ptr BOOL
;  STDMETHOD  put_Visible  , :BOOL
;  STDMETHOD  get_Width  , :ptr SDWORD
;  STDMETHOD  put_Width  , :SDWORD
;  STDMETHOD  get_IsPriorityDropped  , :ptr BOOL
;  STDMETHOD  Reserved1
;  STDMETHOD  Reserved2
;  STDMETHOD  Reserved3
;  STDMETHOD  Reserved4
;  STDMETHOD  Reserved5
;  STDMETHOD  Reserved6
;  STDMETHOD  Reserved7
;END_INTERFACE
;endif
;
;sIID_CommandBarControl textequ <IID {0000C0308h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _CommandBarActiveX, Type=INTERFACE, GUID={000C030D-0000-0000-C000-000000000046}
;
;ifndef _CommandBarActiveXVtbl
;BEGIN_INTERFACE _CommandBarActiveX, CommandBarControl
;  STDMETHOD  get_ControlCLSID  , :ptr BSTR
;  STDMETHOD  put_ControlCLSID  , :BSTR
;  STDMETHOD  get_QueryControlInterface  , :BSTR,:ptr LPUNKNOWN
;  STDMETHOD  SetInnerObjectFactory  , :LPUNKNOWN
;  STDMETHOD  EnsureControl
;  STDMETHOD  put_InitWith  , :LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID__CommandBarActiveX textequ <IID {0000C030Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _CommandBarButton, Type=INTERFACE, GUID={000C030E-0000-0000-C000-000000000046}
;
;ifndef _CommandBarButtonVtbl
;BEGIN_INTERFACE _CommandBarButton, CommandBarControl
;  STDMETHOD  get_BuiltInFace  , :ptr BOOL
;  STDMETHOD  put_BuiltInFace  , :BOOL
;  STDMETHOD  CopyFace
;  STDMETHOD  get_FaceId  , :ptr SDWORD
;  STDMETHOD  put_FaceId  , :SDWORD
;  STDMETHOD  PasteFace
;  STDMETHOD  get_ShortcutText  , :ptr BSTR
;  STDMETHOD  put_ShortcutText  , :BSTR
;  STDMETHOD  get_State  , :ptr MsoButtonState
;  STDMETHOD  put_State  , :MsoButtonState
;  STDMETHOD  get_Style  , :ptr MsoButtonStyle
;  STDMETHOD  put_Style  , :MsoButtonStyle
;  STDMETHOD  get_HyperlinkType  , :ptr MsoCommandBarButtonHyperlinkType
;  STDMETHOD  put_HyperlinkType  , :MsoCommandBarButtonHyperlinkType
;  STDMETHOD  get_Picture  , :ptr ptr IPictureDisp
;  STDMETHOD  put_Picture  , :ptr IPictureDisp
;  STDMETHOD  get_Mask  , :ptr ptr IPictureDisp
;  STDMETHOD  put_Mask  , :ptr IPictureDisp
;END_INTERFACE
;endif
;
;sIID__CommandBarButton textequ <IID {0000C030Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CommandBar, Type=INTERFACE, GUID={000C0304-0000-0000-C000-000000000046}
;
;ifndef CommandBarVtbl
;BEGIN_INTERFACE CommandBar, _IMsoOleAccDispObj
;  STDMETHOD  get_BuiltIn  , :ptr BOOL
;  STDMETHOD  get_Context  , :ptr BSTR
;  STDMETHOD  put_Context  , :BSTR
;  STDMETHOD  get_Controls  , :ptr ptr CommandBarControls
;  STDMETHOD  Delete
;  STDMETHOD  get_Enabled  , :ptr BOOL
;  STDMETHOD  put_Enabled  , :BOOL
;  STDMETHOD  FindControl  , :VARIANT,:VARIANT,:VARIANT,:VARIANT,:VARIANT,:ptr ptr CommandBarControl
;  STDMETHOD  get_Height  , :ptr SDWORD
;  STDMETHOD  put_Height  , :SDWORD
;  STDMETHOD  get_Index  , :ptr SDWORD
;  STDMETHOD  get_InstanceId  , :ptr SDWORD
;  STDMETHOD  get_Left  , :ptr SDWORD
;  STDMETHOD  put_Left  , :SDWORD
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  put_Name  , :BSTR
;  STDMETHOD  get_NameLocal  , :ptr BSTR
;  STDMETHOD  put_NameLocal  , :BSTR
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Position  , :ptr MsoBarPosition
;  STDMETHOD  put_Position  , :MsoBarPosition
;  STDMETHOD  get_RowIndex  , :ptr SDWORD
;  STDMETHOD  put_RowIndex  , :SDWORD
;  STDMETHOD  get_Protection  , :ptr MsoBarProtection
;  STDMETHOD  put_Protection  , :MsoBarProtection
;  STDMETHOD  Reset
;  STDMETHOD  ShowPopup  , :VARIANT,:VARIANT
;  STDMETHOD  get_Top  , :ptr SDWORD
;  STDMETHOD  put_Top  , :SDWORD
;  STDMETHOD  get_Type  , :ptr MsoBarType
;  STDMETHOD  get_Visible  , :ptr BOOL
;  STDMETHOD  put_Visible  , :BOOL
;  STDMETHOD  get_Width  , :ptr SDWORD
;  STDMETHOD  put_Width  , :SDWORD
;  STDMETHOD  get_AdaptiveMenu  , :ptr BOOL
;  STDMETHOD  put_AdaptiveMenu  , :BOOL
;  STDMETHOD  get_Id  , :ptr SDWORD
;END_INTERFACE
;endif
;
;sIID_CommandBar textequ <IID {0000C0304h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CommandBarPopup, Type=INTERFACE, GUID={000C030A-0000-0000-C000-000000000046}
;
;ifndef CommandBarPopupVtbl
;BEGIN_INTERFACE CommandBarPopup, CommandBarControl
;  STDMETHOD  get_CommandBar  , :ptr ptr CommandBar
;  STDMETHOD  get_Controls  , :ptr ptr CommandBarControls
;  STDMETHOD  get_OLEMenuGroup  , :ptr MsoOLEMenuGroup
;  STDMETHOD  put_OLEMenuGroup  , :MsoOLEMenuGroup
;END_INTERFACE
;endif
;
;sIID_CommandBarPopup textequ <IID {0000C030Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CalloutFormat, Type=INTERFACE, GUID={000C0311-0000-0000-C000-000000000046}
;
;ifndef CalloutFormatVtbl
;BEGIN_INTERFACE CalloutFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  AutomaticLength
;  STDMETHOD  CustomDrop  , :REAL4
;  STDMETHOD  CustomLength  , :REAL4
;  STDMETHOD  PresetDrop  , :MsoCalloutDropType
;  STDMETHOD  get_Accent  , :ptr MsoTriState
;  STDMETHOD  put_Accent  , :MsoTriState
;  STDMETHOD  get_Angle  , :ptr MsoCalloutAngleType
;  STDMETHOD  put_Angle  , :MsoCalloutAngleType
;  STDMETHOD  get_AutoAttach  , :ptr MsoTriState
;  STDMETHOD  put_AutoAttach  , :MsoTriState
;  STDMETHOD  get_AutoLength  , :ptr MsoTriState
;  STDMETHOD  get_Border  , :ptr MsoTriState
;  STDMETHOD  put_Border  , :MsoTriState
;  STDMETHOD  get_Drop  , :ptr REAL4
;  STDMETHOD  get_DropType  , :ptr MsoCalloutDropType
;  STDMETHOD  get_Gap  , :ptr REAL4
;  STDMETHOD  put_Gap  , :REAL4
;  STDMETHOD  get_Length  , :ptr REAL4
;  STDMETHOD  get_Type  , :ptr MsoCalloutType
;  STDMETHOD  put_Type  , :MsoCalloutType
;END_INTERFACE
;endif
;
;sIID_CalloutFormat textequ <IID {0000C0311h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FoundFiles, Type=INTERFACE, GUID={000C0331-0000-0000-C000-000000000046}
;
;ifndef FoundFilesVtbl
;BEGIN_INTERFACE FoundFiles, _IMsoDispObj
;  STDMETHOD  get_Item  , :SDWORD,:SDWORD,:ptr BSTR
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_FoundFiles textequ <IID {0000C0331h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- PropertyTest, Type=INTERFACE, GUID={000C0333-0000-0000-C000-000000000046}
;
;ifndef PropertyTestVtbl
;BEGIN_INTERFACE PropertyTest, _IMsoDispObj
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_Condition  , :ptr MsoCondition
;  STDMETHOD  get_Value  , :ptr VARIANT
;  STDMETHOD  get_SecondValue  , :ptr VARIANT
;  STDMETHOD  get_Connector  , :ptr MsoConnector
;END_INTERFACE
;endif
;
;sIID_PropertyTest textequ <IID {0000C0333h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- PropertyTests, Type=INTERFACE, GUID={000C0334-0000-0000-C000-000000000046}
;
;ifndef PropertyTestsVtbl
;BEGIN_INTERFACE PropertyTests, _IMsoDispObj
;  STDMETHOD  get_Item  , :SDWORD,:SDWORD,:ptr ptr PropertyTest
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Add_  , :BSTR,:MsoCondition,:VARIANT,:VARIANT,:MsoConnector
;  STDMETHOD  Remove  , :SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_PropertyTests textequ <IID {0000C0334h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FileSearch, Type=INTERFACE, GUID={000C0332-0000-0000-C000-000000000046}
;
;ifndef FileSearchVtbl
;BEGIN_INTERFACE FileSearch, _IMsoDispObj
;  STDMETHOD  get_SearchSubFolders  , :ptr BOOL
;  STDMETHOD  put_SearchSubFolders  , :BOOL
;  STDMETHOD  get_MatchTextExactly  , :ptr BOOL
;  STDMETHOD  put_MatchTextExactly  , :BOOL
;  STDMETHOD  get_MatchAllWordForms  , :ptr BOOL
;  STDMETHOD  put_MatchAllWordForms  , :BOOL
;  STDMETHOD  get_FileName  , :ptr BSTR
;  STDMETHOD  put_FileName  , :BSTR
;  STDMETHOD  get_FileType  , :ptr MsoFileType
;  STDMETHOD  put_FileType  , :MsoFileType
;  STDMETHOD  get_LastModified  , :ptr MsoLastModified
;  STDMETHOD  put_LastModified  , :MsoLastModified
;  STDMETHOD  get_TextOrProperty  , :ptr BSTR
;  STDMETHOD  put_TextOrProperty  , :BSTR
;  STDMETHOD  get_LookIn  , :ptr BSTR
;  STDMETHOD  put_LookIn  , :BSTR
;  STDMETHOD  Execute  , :MsoSortBy,:MsoSortOrder,:BOOL,:ptr SDWORD
;  STDMETHOD  NewSearch
;  STDMETHOD  get_FoundFiles  , :ptr ptr FoundFiles
;  STDMETHOD  get_PropertyTests  , :ptr ptr PropertyTests
;  STDMETHOD  get_SearchScopes  , :ptr ptr SearchScopes
;  STDMETHOD  get_SearchFolders  , :ptr ptr SearchFolders
;  STDMETHOD  get_FileTypes  , :ptr ptr FileTypes
;  STDMETHOD  RefreshScopes
;END_INTERFACE
;endif
;
;sIID_FileSearch textequ <IID {0000C0332h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- COMAddIn, Type=INTERFACE, GUID={000C033A-0000-0000-C000-000000000046}
;
;ifndef COMAddInVtbl
;BEGIN_INTERFACE COMAddIn, _IMsoDispObj
;  STDMETHOD  get_Description  , :ptr BSTR
;  STDMETHOD  put_Description  , :BSTR
;  STDMETHOD  get_ProgId  , :ptr BSTR
;  STDMETHOD  get_Guid  , :ptr BSTR
;  STDMETHOD  get_Connect  , :ptr BOOL
;  STDMETHOD  put_Connect  , :BOOL
;  STDMETHOD  get_Object  , :ptr LPDISPATCH
;  STDMETHOD  put_Object  , :LPDISPATCH
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;END_INTERFACE
;endif
;
;sIID_COMAddIn textequ <IID {0000C033Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- COMAddIns, Type=INTERFACE, GUID={000C0339-0000-0000-C000-000000000046}
;
;ifndef COMAddInsVtbl
;BEGIN_INTERFACE COMAddIns, _IMsoDispObj
;  STDMETHOD  Item  , :ptr VARIANT,:ptr ptr COMAddIn
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  Update
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  SetAppModal  , :BOOL
;END_INTERFACE
;endif
;
;sIID_COMAddIns textequ <IID {0000C0339h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ColorFormat, Type=INTERFACE, GUID={000C0312-0000-0000-C000-000000000046}
;
;ifndef ColorFormatVtbl
;BEGIN_INTERFACE ColorFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_RGB  , :ptr MsoRGBType
;  STDMETHOD  put_RGB  , :MsoRGBType
;  STDMETHOD  get_SchemeColor  , :ptr SDWORD
;  STDMETHOD  put_SchemeColor  , :SDWORD
;  STDMETHOD  get_Type  , :ptr MsoColorType
;  STDMETHOD  get_TintAndShade  , :ptr REAL4
;  STDMETHOD  put_TintAndShade  , :REAL4
;END_INTERFACE
;endif
;
;sIID_ColorFormat textequ <IID {0000C0312h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- LanguageSettings, Type=INTERFACE, GUID={000C0353-0000-0000-C000-000000000046}
;
;ifndef LanguageSettingsVtbl
;BEGIN_INTERFACE LanguageSettings, _IMsoDispObj
;  STDMETHOD  get_LanguageID  , :MsoAppLanguageID,:ptr SDWORD
;  STDMETHOD  get_LanguagePreferredForEditing  , :MsoLanguageID,:ptr BOOL
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;END_INTERFACE
;endif
;
;sIID_LanguageSettings textequ <IID {0000C0353h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ICommandBarsEvents, Type=INTERFACE, GUID={55F88892-7708-11D1-ACEB-006008961DA5}
;
;ifndef ICommandBarsEventsVtbl
;BEGIN_INTERFACE ICommandBarsEvents, IDispatch
;  STDMETHOD  OnUpdate
;END_INTERFACE
;endif
;
;sIID_ICommandBarsEvents textequ <IID {055F88892h,07708h,011D1h,{0ACh,0EBh,000h,060h,008h,096h,01Dh,0A5h}}>
;
;;--- ICommandBarComboBoxEvents, Type=INTERFACE, GUID={55F88896-7708-11D1-ACEB-006008961DA5}
;
;ifndef ICommandBarComboBoxEventsVtbl
;BEGIN_INTERFACE ICommandBarComboBoxEvents, IDispatch
;  STDMETHOD  Change  , :ptr CommandBarComboBox
;END_INTERFACE
;endif
;
;sIID_ICommandBarComboBoxEvents textequ <IID {055F88896h,07708h,011D1h,{0ACh,0EBh,000h,060h,008h,096h,01Dh,0A5h}}>
;
;;--- ICommandBarButtonEvents, Type=INTERFACE, GUID={55F88890-7708-11D1-ACEB-006008961DA5}
;
;ifndef ICommandBarButtonEventsVtbl
;BEGIN_INTERFACE ICommandBarButtonEvents, IDispatch
;  STDMETHOD  Click  , :ptr CommandBarButton,:ptr BOOL
;END_INTERFACE
;endif
;
;sIID_ICommandBarButtonEvents textequ <IID {055F88890h,07708h,011D1h,{0ACh,0EBh,000h,060h,008h,096h,01Dh,0A5h}}>
;
;;--- ConnectorFormat, Type=INTERFACE, GUID={000C0313-0000-0000-C000-000000000046}
;
;ifndef ConnectorFormatVtbl
;BEGIN_INTERFACE ConnectorFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  BeginConnect  , :ptr Shape,:SDWORD
;  STDMETHOD  BeginDisconnect
;  STDMETHOD  EndConnect  , :ptr Shape,:SDWORD
;  STDMETHOD  EndDisconnect
;  STDMETHOD  get_BeginConnected  , :ptr MsoTriState
;  STDMETHOD  get_BeginConnectedShape  , :ptr ptr Shape
;  STDMETHOD  get_BeginConnectionSite  , :ptr SDWORD
;  STDMETHOD  get_EndConnected  , :ptr MsoTriState
;  STDMETHOD  get_EndConnectedShape  , :ptr ptr Shape
;  STDMETHOD  get_EndConnectionSite  , :ptr SDWORD
;  STDMETHOD  get_Type  , :ptr MsoConnectorType
;  STDMETHOD  put_Type  , :MsoConnectorType
;END_INTERFACE
;endif
;
;sIID_ConnectorFormat textequ <IID {0000C0313h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FillFormat, Type=INTERFACE, GUID={000C0314-0000-0000-C000-000000000046}
;
;ifndef FillFormatVtbl
;BEGIN_INTERFACE FillFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  Background
;  STDMETHOD  OneColorGradient  , :MsoGradientStyle,:SDWORD,:REAL4
;  STDMETHOD  Patterned  , :MsoPatternType
;  STDMETHOD  PresetGradient  , :MsoGradientStyle,:SDWORD,:MsoPresetGradientType
;  STDMETHOD  PresetTextured  , :MsoPresetTexture
;  STDMETHOD  Solid
;  STDMETHOD  TwoColorGradient  , :MsoGradientStyle,:SDWORD
;  STDMETHOD  UserPicture  , :BSTR
;  STDMETHOD  UserTextured  , :BSTR
;  STDMETHOD  get_BackColor  , :ptr ptr ColorFormat
;  STDMETHOD  put_BackColor  , :ptr ColorFormat
;  STDMETHOD  get_ForeColor  , :ptr ptr ColorFormat
;  STDMETHOD  put_ForeColor  , :ptr ColorFormat
;  STDMETHOD  get_GradientColorType  , :ptr MsoGradientColorType
;  STDMETHOD  get_GradientDegree  , :ptr REAL4
;  STDMETHOD  get_GradientStyle  , :ptr MsoGradientStyle
;  STDMETHOD  get_GradientVariant  , :ptr SDWORD
;  STDMETHOD  get_Pattern  , :ptr MsoPatternType
;  STDMETHOD  get_PresetGradientType  , :ptr MsoPresetGradientType
;  STDMETHOD  get_PresetTexture  , :ptr MsoPresetTexture
;  STDMETHOD  get_TextureName  , :ptr BSTR
;  STDMETHOD  get_TextureType  , :ptr MsoTextureType
;  STDMETHOD  get_Transparency  , :ptr REAL4
;  STDMETHOD  put_Transparency  , :REAL4
;  STDMETHOD  get_Type  , :ptr MsoFillType
;  STDMETHOD  get_Visible  , :ptr MsoTriState
;  STDMETHOD  put_Visible  , :MsoTriState
;END_INTERFACE
;endif
;
;sIID_FillFormat textequ <IID {0000C0314h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FreeformBuilder, Type=INTERFACE, GUID={000C0315-0000-0000-C000-000000000046}
;
;ifndef FreeformBuilderVtbl
;BEGIN_INTERFACE FreeformBuilder, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  AddNodes  , :MsoSegmentType,:MsoEditingType,:REAL4,:REAL4,:REAL4,:REAL4,:REAL4,:REAL4
;  STDMETHOD  ConvertToShape  , :ptr ptr Shape
;END_INTERFACE
;endif
;
;sIID_FreeformBuilder textequ <IID {0000C0315h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- WebPageFont, Type=INTERFACE, GUID={000C0913-0000-0000-C000-000000000046}
;
;ifndef WebPageFontVtbl
;BEGIN_INTERFACE WebPageFont, _IMsoDispObj
;  STDMETHOD  get_ProportionalFont  , :ptr BSTR
;  STDMETHOD  put_ProportionalFont  , :BSTR
;  STDMETHOD  get_ProportionalFontSize  , :ptr REAL4
;  STDMETHOD  put_ProportionalFontSize  , :REAL4
;  STDMETHOD  get_FixedWidthFont  , :ptr BSTR
;  STDMETHOD  put_FixedWidthFont  , :BSTR
;  STDMETHOD  get_FixedWidthFontSize  , :ptr REAL4
;  STDMETHOD  put_FixedWidthFontSize  , :REAL4
;END_INTERFACE
;endif
;
;sIID_WebPageFont textequ <IID {0000C0913h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- WebPageFonts, Type=INTERFACE, GUID={000C0914-0000-0000-C000-000000000046}
;
;ifndef WebPageFontsVtbl
;BEGIN_INTERFACE WebPageFonts, _IMsoDispObj
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get_Item  , :MsoCharacterSet,:ptr ptr WebPageFont
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_WebPageFonts textequ <IID {0000C0914h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- GroupShapes, Type=INTERFACE, GUID={000C0316-0000-0000-C000-000000000046}
;
;ifndef GroupShapesVtbl
;BEGIN_INTERFACE GroupShapes, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Item  , :VARIANT,:ptr ptr Shape
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  Range  , :VARIANT,:ptr ptr ShapeRange
;END_INTERFACE
;endif
;
;sIID_GroupShapes textequ <IID {0000C0316h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- LineFormat, Type=INTERFACE, GUID={000C0317-0000-0000-C000-000000000046}
;
;ifndef LineFormatVtbl
;BEGIN_INTERFACE LineFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_BackColor  , :ptr ptr ColorFormat
;  STDMETHOD  put_BackColor  , :ptr ColorFormat
;  STDMETHOD  get_BeginArrowheadLength  , :ptr MsoArrowheadLength
;  STDMETHOD  put_BeginArrowheadLength  , :MsoArrowheadLength
;  STDMETHOD  get_BeginArrowheadStyle  , :ptr MsoArrowheadStyle
;  STDMETHOD  put_BeginArrowheadStyle  , :MsoArrowheadStyle
;  STDMETHOD  get_BeginArrowheadWidth  , :ptr MsoArrowheadWidth
;  STDMETHOD  put_BeginArrowheadWidth  , :MsoArrowheadWidth
;  STDMETHOD  get_DashStyle  , :ptr MsoLineDashStyle
;  STDMETHOD  put_DashStyle  , :MsoLineDashStyle
;  STDMETHOD  get_EndArrowheadLength  , :ptr MsoArrowheadLength
;  STDMETHOD  put_EndArrowheadLength  , :MsoArrowheadLength
;  STDMETHOD  get_EndArrowheadStyle  , :ptr MsoArrowheadStyle
;  STDMETHOD  put_EndArrowheadStyle  , :MsoArrowheadStyle
;  STDMETHOD  get_EndArrowheadWidth  , :ptr MsoArrowheadWidth
;  STDMETHOD  put_EndArrowheadWidth  , :MsoArrowheadWidth
;  STDMETHOD  get_ForeColor  , :ptr ptr ColorFormat
;  STDMETHOD  put_ForeColor  , :ptr ColorFormat
;  STDMETHOD  get_Pattern  , :ptr MsoPatternType
;  STDMETHOD  put_Pattern  , :MsoPatternType
;  STDMETHOD  get_Style  , :ptr MsoLineStyle
;  STDMETHOD  put_Style  , :MsoLineStyle
;  STDMETHOD  get_Transparency  , :ptr REAL4
;  STDMETHOD  put_Transparency  , :REAL4
;  STDMETHOD  get_Visible  , :ptr MsoTriState
;  STDMETHOD  put_Visible  , :MsoTriState
;  STDMETHOD  get_Weight  , :ptr REAL4
;  STDMETHOD  put_Weight  , :REAL4
;  STDMETHOD  get_InsetPen  , :ptr MsoTriState
;  STDMETHOD  put_InsetPen  , :MsoTriState
;END_INTERFACE
;endif
;
;sIID_LineFormat textequ <IID {0000C0317h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HTMLProjectItem, Type=INTERFACE, GUID={000C0358-0000-0000-C000-000000000046}
;
;ifndef HTMLProjectItemVtbl
;BEGIN_INTERFACE HTMLProjectItem, _IMsoDispObj
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_IsOpen  , :ptr BOOL
;  STDMETHOD  LoadFromFile  , :BSTR
;  STDMETHOD  Open  , :MsoHTMLProjectOpen
;  STDMETHOD  SaveCopyAs  , :BSTR
;  STDMETHOD  get_Text  , :ptr BSTR
;  STDMETHOD  put_Text  , :BSTR
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;END_INTERFACE
;endif
;
;sIID_HTMLProjectItem textequ <IID {0000C0358h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HTMLProjectItems, Type=INTERFACE, GUID={000C0357-0000-0000-C000-000000000046}
;
;ifndef HTMLProjectItemsVtbl
;BEGIN_INTERFACE HTMLProjectItems, _IMsoDispObj
;  STDMETHOD  Item  , :ptr VARIANT,:ptr ptr HTMLProjectItem
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;END_INTERFACE
;endif
;
;sIID_HTMLProjectItems textequ <IID {0000C0357h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- HTMLProject, Type=INTERFACE, GUID={000C0356-0000-0000-C000-000000000046}
;
;ifndef HTMLProjectVtbl
;BEGIN_INTERFACE HTMLProject, _IMsoDispObj
;  STDMETHOD  get_State  , :ptr MsoHTMLProjectState
;  STDMETHOD  RefreshProject  , :BOOL
;  STDMETHOD  RefreshDocument  , :BOOL
;  STDMETHOD  get_HTMLProjectItems  , :ptr ptr HTMLProjectItems
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  Open  , :MsoHTMLProjectOpen
;END_INTERFACE
;endif
;
;sIID_HTMLProject textequ <IID {0000C0356h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- MsoDebugOptions, Type=INTERFACE, GUID={000C035A-0000-0000-C000-000000000046}
;
;ifndef MsoDebugOptionsVtbl
;BEGIN_INTERFACE MsoDebugOptions, _IMsoDispObj
;  STDMETHOD  get_FeatureReports  , :ptr SDWORD
;  STDMETHOD  put_FeatureReports  , :SDWORD
;  STDMETHOD  get_OutputToDebugger  , :ptr BOOL
;  STDMETHOD  put_OutputToDebugger  , :BOOL
;  STDMETHOD  get_OutputToFile  , :ptr BOOL
;  STDMETHOD  put_OutputToFile  , :BOOL
;  STDMETHOD  get_OutputToMessageBox  , :ptr BOOL
;  STDMETHOD  put_OutputToMessageBox  , :BOOL
;END_INTERFACE
;endif
;
;sIID_MsoDebugOptions textequ <IID {0000C035Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ShapeNode, Type=INTERFACE, GUID={000C0318-0000-0000-C000-000000000046}
;
;ifndef ShapeNodeVtbl
;BEGIN_INTERFACE ShapeNode, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_EditingType  , :ptr MsoEditingType
;  STDMETHOD  get_Points  , :ptr VARIANT
;  STDMETHOD  get_SegmentType  , :ptr MsoSegmentType
;END_INTERFACE
;endif
;
;sIID_ShapeNode textequ <IID {0000C0318h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ShapeNodes, Type=INTERFACE, GUID={000C0319-0000-0000-C000-000000000046}
;
;ifndef ShapeNodesVtbl
;BEGIN_INTERFACE ShapeNodes, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Item  , :VARIANT,:ptr ptr ShapeNode
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  Delete  , :SDWORD
;  STDMETHOD  Insert  , :SDWORD,:MsoSegmentType,:MsoEditingType,:REAL4,:REAL4,:REAL4,:REAL4,:REAL4,:REAL4
;  STDMETHOD  SetEditingType  , :SDWORD,:MsoEditingType
;  STDMETHOD  SetPosition  , :SDWORD,:REAL4,:REAL4
;  STDMETHOD  SetSegmentType  , :SDWORD,:MsoSegmentType
;END_INTERFACE
;endif
;
;sIID_ShapeNodes textequ <IID {0000C0319h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FileDialogSelectedItems, Type=INTERFACE, GUID={000C0363-0000-0000-C000-000000000046}
;
;ifndef FileDialogSelectedItemsVtbl
;BEGIN_INTERFACE FileDialogSelectedItems, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Item  , :SDWORD,:ptr BSTR
;END_INTERFACE
;endif
;
;sIID_FileDialogSelectedItems textequ <IID {0000C0363h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FileDialogFilter, Type=INTERFACE, GUID={000C0364-0000-0000-C000-000000000046}
;
;ifndef FileDialogFilterVtbl
;BEGIN_INTERFACE FileDialogFilter, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Extensions  , :ptr BSTR
;  STDMETHOD  get_Description  , :ptr BSTR
;END_INTERFACE
;endif
;
;sIID_FileDialogFilter textequ <IID {0000C0364h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FileDialogFilters, Type=INTERFACE, GUID={000C0365-0000-0000-C000-000000000046}
;
;ifndef FileDialogFiltersVtbl
;BEGIN_INTERFACE FileDialogFilters, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Item  , :SDWORD,:ptr ptr FileDialogFilter
;  STDMETHOD  Delete  , :VARIANT
;  STDMETHOD  Clear
;  STDMETHOD  Add_  , :BSTR,:BSTR,:VARIANT,:ptr ptr FileDialogFilter
;END_INTERFACE
;endif
;
;sIID_FileDialogFilters textequ <IID {0000C0365h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FileDialog, Type=INTERFACE, GUID={000C0362-0000-0000-C000-000000000046}
;
;ifndef FileDialogVtbl
;BEGIN_INTERFACE FileDialog, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Filters  , :ptr ptr FileDialogFilters
;  STDMETHOD  get_FilterIndex  , :ptr SDWORD
;  STDMETHOD  put_FilterIndex  , :SDWORD
;  STDMETHOD  get_Title  , :ptr BSTR
;  STDMETHOD  put_Title  , :BSTR
;  STDMETHOD  get_ButtonName  , :ptr BSTR
;  STDMETHOD  put_ButtonName  , :BSTR
;  STDMETHOD  get_AllowMultiSelect  , :ptr BOOL
;  STDMETHOD  put_AllowMultiSelect  , :BOOL
;  STDMETHOD  get_InitialView  , :ptr MsoFileDialogView
;  STDMETHOD  put_InitialView  , :MsoFileDialogView
;  STDMETHOD  get_InitialFileName  , :ptr BSTR
;  STDMETHOD  put_InitialFileName  , :BSTR
;  STDMETHOD  get_SelectedItems  , :ptr ptr FileDialogSelectedItems
;  STDMETHOD  get_DialogType  , :ptr MsoFileDialogType
;  STDMETHOD  get_Item  , :ptr BSTR
;  STDMETHOD  Show  , :ptr SDWORD
;  STDMETHOD  Execute
;END_INTERFACE
;endif
;
;sIID_FileDialog textequ <IID {0000C0362h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- PictureFormat, Type=INTERFACE, GUID={000C031A-0000-0000-C000-000000000046}
;
;ifndef PictureFormatVtbl
;BEGIN_INTERFACE PictureFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  IncrementBrightness  , :REAL4
;  STDMETHOD  IncrementContrast  , :REAL4
;  STDMETHOD  get_Brightness  , :ptr REAL4
;  STDMETHOD  put_Brightness  , :REAL4
;  STDMETHOD  get_ColorType  , :ptr MsoPictureColorType
;  STDMETHOD  put_ColorType  , :MsoPictureColorType
;  STDMETHOD  get_Contrast  , :ptr REAL4
;  STDMETHOD  put_Contrast  , :REAL4
;  STDMETHOD  get_CropBottom  , :ptr REAL4
;  STDMETHOD  put_CropBottom  , :REAL4
;  STDMETHOD  get_CropLeft  , :ptr REAL4
;  STDMETHOD  put_CropLeft  , :REAL4
;  STDMETHOD  get_CropRight  , :ptr REAL4
;  STDMETHOD  put_CropRight  , :REAL4
;  STDMETHOD  get_CropTop  , :ptr REAL4
;  STDMETHOD  put_CropTop  , :REAL4
;  STDMETHOD  get_TransparencyColor  , :ptr MsoRGBType
;  STDMETHOD  put_TransparencyColor  , :MsoRGBType
;  STDMETHOD  get_TransparentBackground  , :ptr MsoTriState
;  STDMETHOD  put_TransparentBackground  , :MsoTriState
;END_INTERFACE
;endif
;
;sIID_PictureFormat textequ <IID {0000C031Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- SignatureSet, Type=INTERFACE, GUID={000C0410-0000-0000-C000-000000000046}
;
;ifndef SignatureSetVtbl
;BEGIN_INTERFACE SignatureSet, _IMsoDispObj
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get_Item  , :SDWORD,:ptr ptr Signature
;  STDMETHOD  Add_  , :ptr ptr Signature
;  STDMETHOD  Commit
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;END_INTERFACE
;endif
;
;sIID_SignatureSet textequ <IID {0000C0410h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Signature, Type=INTERFACE, GUID={000C0411-0000-0000-C000-000000000046}
;
;ifndef SignatureVtbl
;BEGIN_INTERFACE Signature, _IMsoDispObj
;  STDMETHOD  get_Signer  , :ptr BSTR
;  STDMETHOD  get_Issuer  , :ptr BSTR
;  STDMETHOD  get_ExpireDate  , :ptr VARIANT
;  STDMETHOD  get_IsValid  , :ptr BOOL
;  STDMETHOD  get_AttachCertificate  , :ptr BOOL
;  STDMETHOD  put_AttachCertificate  , :BOOL
;  STDMETHOD  Delete
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_IsCertificateExpired  , :ptr BOOL
;  STDMETHOD  get_IsCertificateRevoked  , :ptr BOOL
;  STDMETHOD  get_SignDate  , :ptr VARIANT
;END_INTERFACE
;endif
;
;sIID_Signature textequ <IID {0000C0411h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ShadowFormat, Type=INTERFACE, GUID={000C031B-0000-0000-C000-000000000046}
;
;ifndef ShadowFormatVtbl
;BEGIN_INTERFACE ShadowFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  IncrementOffsetX  , :REAL4
;  STDMETHOD  IncrementOffsetY  , :REAL4
;  STDMETHOD  get_ForeColor  , :ptr ptr ColorFormat
;  STDMETHOD  put_ForeColor  , :ptr ColorFormat
;  STDMETHOD  get_Obscured  , :ptr MsoTriState
;  STDMETHOD  put_Obscured  , :MsoTriState
;  STDMETHOD  get_OffsetX  , :ptr REAL4
;  STDMETHOD  put_OffsetX  , :REAL4
;  STDMETHOD  get_OffsetY  , :ptr REAL4
;  STDMETHOD  put_OffsetY  , :REAL4
;  STDMETHOD  get_Transparency  , :ptr REAL4
;  STDMETHOD  put_Transparency  , :REAL4
;  STDMETHOD  get_Type  , :ptr MsoShadowType
;  STDMETHOD  put_Type  , :MsoShadowType
;  STDMETHOD  get_Visible  , :ptr MsoTriState
;  STDMETHOD  put_Visible  , :MsoTriState
;END_INTERFACE
;endif
;
;sIID_ShadowFormat textequ <IID {0000C031Bh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- IMsoEnvelopeVB, Type=INTERFACE, GUID={000672AC-0000-0000-C000-000000000046}
;
;ifndef IMsoEnvelopeVBVtbl
;BEGIN_INTERFACE IMsoEnvelopeVB, IDispatch
;  STDMETHOD  get_Introduction  , :ptr BSTR
;  STDMETHOD  put_Introduction  , :BSTR
;  STDMETHOD  get_Item  , :ptr LPDISPATCH
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_CommandBars  , :ptr LPDISPATCH
;END_INTERFACE
;endif
;
;sIID_IMsoEnvelopeVB textequ <IID {0000672ACh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _CommandBars, Type=INTERFACE, GUID={000C0302-0000-0000-C000-000000000046}
;
;ifndef _CommandBarsVtbl
;BEGIN_INTERFACE _CommandBars, _IMsoDispObj
;  STDMETHOD  get_ActionControl  , :ptr ptr CommandBarControl
;  STDMETHOD  get_ActiveMenuBar  , :ptr ptr CommandBar
;  STDMETHOD  Add_  , :VARIANT,:VARIANT,:VARIANT,:VARIANT,:ptr ptr CommandBar
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get_DisplayTooltips  , :ptr BOOL
;  STDMETHOD  put_DisplayTooltips  , :BOOL
;  STDMETHOD  get_DisplayKeysInTooltips  , :ptr BOOL
;  STDMETHOD  put_DisplayKeysInTooltips  , :BOOL
;  STDMETHOD  FindControl  , :VARIANT,:VARIANT,:VARIANT,:VARIANT,:ptr ptr CommandBarControl
;  STDMETHOD  get_Item  , :VARIANT,:ptr ptr CommandBar
;  STDMETHOD  get_LargeButtons  , :ptr BOOL
;  STDMETHOD  put_LargeButtons  , :BOOL
;  STDMETHOD  get_MenuAnimationStyle  , :ptr MsoMenuAnimation
;  STDMETHOD  put_MenuAnimationStyle  , :MsoMenuAnimation
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  ReleaseFocus
;  STDMETHOD  get_IdsString  , :SDWORD,:ptr BSTR,:ptr SDWORD
;  STDMETHOD  get_TmcGetName  , :SDWORD,:ptr BSTR,:ptr SDWORD
;  STDMETHOD  get_AdaptiveMenus  , :ptr BOOL
;  STDMETHOD  put_AdaptiveMenus  , :BOOL
;  STDMETHOD  FindControls  , :VARIANT,:VARIANT,:VARIANT,:VARIANT,:ptr ptr CommandBarControls
;  STDMETHOD  AddEx  , :VARIANT,:VARIANT,:VARIANT,:VARIANT,:VARIANT,:ptr ptr CommandBar
;  STDMETHOD  get_DisplayFonts  , :ptr BOOL
;  STDMETHOD  put_DisplayFonts  , :BOOL
;  STDMETHOD  get_DisableCustomize  , :ptr BOOL
;  STDMETHOD  put_DisableCustomize  , :BOOL
;  STDMETHOD  get_DisableAskAQuestionDropdown  , :ptr BOOL
;  STDMETHOD  put_DisableAskAQuestionDropdown  , :BOOL
;END_INTERFACE
;endif
;
;sIID__CommandBars textequ <IID {0000C0302h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _CommandBarComboBox, Type=INTERFACE, GUID={000C030C-0000-0000-C000-000000000046}
;
;ifndef _CommandBarComboBoxVtbl
;BEGIN_INTERFACE _CommandBarComboBox, CommandBarControl
;  STDMETHOD  AddItem  , :BSTR,:VARIANT
;  STDMETHOD  Clear
;  STDMETHOD  get_DropDownLines  , :ptr SDWORD
;  STDMETHOD  put_DropDownLines  , :SDWORD
;  STDMETHOD  get_DropDownWidth  , :ptr SDWORD
;  STDMETHOD  put_DropDownWidth  , :SDWORD
;  STDMETHOD  get_List  , :SDWORD,:ptr BSTR
;  STDMETHOD  put_List  , :SDWORD,:BSTR
;  STDMETHOD  get_ListCount  , :ptr SDWORD
;  STDMETHOD  get_ListHeaderCount  , :ptr SDWORD
;  STDMETHOD  put_ListHeaderCount  , :SDWORD
;  STDMETHOD  get_ListIndex  , :ptr SDWORD
;  STDMETHOD  put_ListIndex  , :SDWORD
;  STDMETHOD  RemoveItem  , :SDWORD
;  STDMETHOD  get_Style  , :ptr MsoComboStyle
;  STDMETHOD  put_Style  , :MsoComboStyle
;  STDMETHOD  get_Text  , :ptr BSTR
;  STDMETHOD  put_Text  , :BSTR
;END_INTERFACE
;endif
;
;sIID__CommandBarComboBox textequ <IID {0000C030Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Script, Type=INTERFACE, GUID={000C0341-0000-0000-C000-000000000046}
;
;ifndef ScriptVtbl
;BEGIN_INTERFACE Script, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Extended  , :ptr BSTR
;  STDMETHOD  put_Extended  , :BSTR
;  STDMETHOD  get_Id  , :ptr BSTR
;  STDMETHOD  put_Id  , :BSTR
;  STDMETHOD  get_Language  , :ptr MsoScriptLanguage
;  STDMETHOD  put_Language  , :MsoScriptLanguage
;  STDMETHOD  get_Location  , :ptr MsoScriptLocation
;  STDMETHOD  Delete
;  STDMETHOD  get_Shape  , :ptr LPDISPATCH
;  STDMETHOD  get_ScriptText  , :ptr BSTR
;  STDMETHOD  put_ScriptText  , :BSTR
;END_INTERFACE
;endif
;
;sIID_Script textequ <IID {0000C0341h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Scripts, Type=INTERFACE, GUID={000C0340-0000-0000-C000-000000000046}
;
;ifndef ScriptsVtbl
;BEGIN_INTERFACE Scripts, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  Item  , :VARIANT,:ptr ptr Script
;  STDMETHOD  Add_  , :LPDISPATCH,:MsoScriptLocation,:MsoScriptLanguage,:BSTR,:BSTR,:BSTR,:ptr ptr Script
;  STDMETHOD  Delete
;END_INTERFACE
;endif
;
;sIID_Scripts textequ <IID {0000C0340h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Shape, Type=INTERFACE, GUID={000C031C-0000-0000-C000-000000000046}
;
;ifndef ShapeVtbl
;BEGIN_INTERFACE Shape, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  Apply
;  STDMETHOD  Delete
;  STDMETHOD  Duplicate  , :ptr ptr Shape
;  STDMETHOD  Flip  , :MsoFlipCmd
;  STDMETHOD  IncrementLeft  , :REAL4
;  STDMETHOD  IncrementRotation  , :REAL4
;  STDMETHOD  IncrementTop  , :REAL4
;  STDMETHOD  PickUp
;  STDMETHOD  RerouteConnections
;  STDMETHOD  ScaleHeight  , :REAL4,:MsoTriState,:MsoScaleFrom
;  STDMETHOD  ScaleWidth  , :REAL4,:MsoTriState,:MsoScaleFrom
;  STDMETHOD  Select  , :VARIANT
;  STDMETHOD  SetShapesDefaultProperties
;  STDMETHOD  Ungroup  , :ptr ptr ShapeRange
;  STDMETHOD  ZOrder  , :MsoZOrderCmd
;  STDMETHOD  get_Adjustments  , :ptr ptr Adjustments
;  STDMETHOD  get_AutoShapeType  , :ptr MsoAutoShapeType
;  STDMETHOD  put_AutoShapeType  , :MsoAutoShapeType
;  STDMETHOD  get_BlackWhiteMode  , :ptr MsoBlackWhiteMode
;  STDMETHOD  put_BlackWhiteMode  , :MsoBlackWhiteMode
;  STDMETHOD  get_Callout  , :ptr ptr CalloutFormat
;  STDMETHOD  get_ConnectionSiteCount  , :ptr SDWORD
;  STDMETHOD  get_Connector  , :ptr MsoTriState
;  STDMETHOD  get_ConnectorFormat  , :ptr ptr ConnectorFormat
;  STDMETHOD  get_Fill  , :ptr ptr FillFormat
;  STDMETHOD  get_GroupItems  , :ptr ptr GroupShapes
;  STDMETHOD  get_Height  , :ptr REAL4
;  STDMETHOD  put_Height  , :REAL4
;  STDMETHOD  get_HorizontalFlip  , :ptr MsoTriState
;  STDMETHOD  get_Left  , :ptr REAL4
;  STDMETHOD  put_Left  , :REAL4
;  STDMETHOD  get_Line  , :ptr ptr LineFormat
;  STDMETHOD  get_LockAspectRatio  , :ptr MsoTriState
;  STDMETHOD  put_LockAspectRatio  , :MsoTriState
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  put_Name  , :BSTR
;  STDMETHOD  get_Nodes  , :ptr ptr ShapeNodes
;  STDMETHOD  get_Rotation  , :ptr REAL4
;  STDMETHOD  put_Rotation  , :REAL4
;  STDMETHOD  get_PictureFormat  , :ptr ptr PictureFormat
;  STDMETHOD  get_Shadow  , :ptr ptr ShadowFormat
;  STDMETHOD  get_TextEffect  , :ptr ptr TextEffectFormat
;  STDMETHOD  get_TextFrame  , :ptr ptr TextFrame
;  STDMETHOD  get_ThreeD  , :ptr ptr ThreeDFormat
;  STDMETHOD  get_Top  , :ptr REAL4
;  STDMETHOD  put_Top  , :REAL4
;  STDMETHOD  get_Type  , :ptr MsoShapeType
;  STDMETHOD  get_VerticalFlip  , :ptr MsoTriState
;  STDMETHOD  get_Vertices  , :ptr VARIANT
;  STDMETHOD  get_Visible  , :ptr MsoTriState
;  STDMETHOD  put_Visible  , :MsoTriState
;  STDMETHOD  get_Width  , :ptr REAL4
;  STDMETHOD  put_Width  , :REAL4
;  STDMETHOD  get_ZOrderPosition  , :ptr SDWORD
;  STDMETHOD  get_Script  , :ptr ptr Script
;  STDMETHOD  get_AlternativeText  , :ptr BSTR
;  STDMETHOD  put_AlternativeText  , :BSTR
;  STDMETHOD  get_HasDiagram  , :ptr MsoTriState
;  STDMETHOD  get_Diagram  , :ptr ptr IMsoDiagram
;  STDMETHOD  get_HasDiagramNode  , :ptr MsoTriState
;  STDMETHOD  get_DiagramNode  , :ptr ptr DiagramNode
;  STDMETHOD  get_Child  , :ptr MsoTriState
;  STDMETHOD  get_ParentGroup  , :ptr ptr Shape
;  STDMETHOD  get_CanvasItems  , :ptr ptr CanvasShapes
;  STDMETHOD  get_Id  , :ptr SDWORD
;  STDMETHOD  CanvasCropLeft  , :REAL4
;  STDMETHOD  CanvasCropTop  , :REAL4
;  STDMETHOD  CanvasCropRight  , :REAL4
;  STDMETHOD  CanvasCropBottom  , :REAL4
;  STDMETHOD  put_RTF  , :BSTR
;END_INTERFACE
;endif
;
;sIID_Shape textequ <IID {0000C031Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ShapeRange, Type=INTERFACE, GUID={000C031D-0000-0000-C000-000000000046}
;
;ifndef ShapeRangeVtbl
;BEGIN_INTERFACE ShapeRange, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Item  , :VARIANT,:ptr ptr Shape
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  Align_  , :MsoAlignCmd,:MsoTriState
;  STDMETHOD  Apply
;  STDMETHOD  Delete
;  STDMETHOD  Distribute  , :MsoDistributeCmd,:MsoTriState
;  STDMETHOD  Duplicate  , :ptr ptr ShapeRange
;  STDMETHOD  Flip  , :MsoFlipCmd
;  STDMETHOD  IncrementLeft  , :REAL4
;  STDMETHOD  IncrementRotation  , :REAL4
;  STDMETHOD  IncrementTop  , :REAL4
;  STDMETHOD  Group_  , :ptr ptr Shape
;  STDMETHOD  PickUp
;  STDMETHOD  Regroup  , :ptr ptr Shape
;  STDMETHOD  RerouteConnections
;  STDMETHOD  ScaleHeight  , :REAL4,:MsoTriState,:MsoScaleFrom
;  STDMETHOD  ScaleWidth  , :REAL4,:MsoTriState,:MsoScaleFrom
;  STDMETHOD  Select  , :VARIANT
;  STDMETHOD  SetShapesDefaultProperties
;  STDMETHOD  Ungroup  , :ptr ptr ShapeRange
;  STDMETHOD  ZOrder  , :MsoZOrderCmd
;  STDMETHOD  get_Adjustments  , :ptr ptr Adjustments
;  STDMETHOD  get_AutoShapeType  , :ptr MsoAutoShapeType
;  STDMETHOD  put_AutoShapeType  , :MsoAutoShapeType
;  STDMETHOD  get_BlackWhiteMode  , :ptr MsoBlackWhiteMode
;  STDMETHOD  put_BlackWhiteMode  , :MsoBlackWhiteMode
;  STDMETHOD  get_Callout  , :ptr ptr CalloutFormat
;  STDMETHOD  get_ConnectionSiteCount  , :ptr SDWORD
;  STDMETHOD  get_Connector  , :ptr MsoTriState
;  STDMETHOD  get_ConnectorFormat  , :ptr ptr ConnectorFormat
;  STDMETHOD  get_Fill  , :ptr ptr FillFormat
;  STDMETHOD  get_GroupItems  , :ptr ptr GroupShapes
;  STDMETHOD  get_Height  , :ptr REAL4
;  STDMETHOD  put_Height  , :REAL4
;  STDMETHOD  get_HorizontalFlip  , :ptr MsoTriState
;  STDMETHOD  get_Left  , :ptr REAL4
;  STDMETHOD  put_Left  , :REAL4
;  STDMETHOD  get_Line  , :ptr ptr LineFormat
;  STDMETHOD  get_LockAspectRatio  , :ptr MsoTriState
;  STDMETHOD  put_LockAspectRatio  , :MsoTriState
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  put_Name  , :BSTR
;  STDMETHOD  get_Nodes  , :ptr ptr ShapeNodes
;  STDMETHOD  get_Rotation  , :ptr REAL4
;  STDMETHOD  put_Rotation  , :REAL4
;  STDMETHOD  get_PictureFormat  , :ptr ptr PictureFormat
;  STDMETHOD  get_Shadow  , :ptr ptr ShadowFormat
;  STDMETHOD  get_TextEffect  , :ptr ptr TextEffectFormat
;  STDMETHOD  get_TextFrame  , :ptr ptr TextFrame
;  STDMETHOD  get_ThreeD  , :ptr ptr ThreeDFormat
;  STDMETHOD  get_Top  , :ptr REAL4
;  STDMETHOD  put_Top  , :REAL4
;  STDMETHOD  get_Type  , :ptr MsoShapeType
;  STDMETHOD  get_VerticalFlip  , :ptr MsoTriState
;  STDMETHOD  get_Vertices  , :ptr VARIANT
;  STDMETHOD  get_Visible  , :ptr MsoTriState
;  STDMETHOD  put_Visible  , :MsoTriState
;  STDMETHOD  get_Width  , :ptr REAL4
;  STDMETHOD  put_Width  , :REAL4
;  STDMETHOD  get_ZOrderPosition  , :ptr SDWORD
;  STDMETHOD  get_Script  , :ptr ptr Script
;  STDMETHOD  get_AlternativeText  , :ptr BSTR
;  STDMETHOD  put_AlternativeText  , :BSTR
;  STDMETHOD  get_HasDiagram  , :ptr MsoTriState
;  STDMETHOD  get_Diagram  , :ptr ptr IMsoDiagram
;  STDMETHOD  get_HasDiagramNode  , :ptr MsoTriState
;  STDMETHOD  get_DiagramNode  , :ptr ptr DiagramNode
;  STDMETHOD  get_Child  , :ptr MsoTriState
;  STDMETHOD  get_ParentGroup  , :ptr ptr Shape
;  STDMETHOD  get_CanvasItems  , :ptr ptr CanvasShapes
;  STDMETHOD  get_Id  , :ptr SDWORD
;  STDMETHOD  CanvasCropLeft  , :REAL4
;  STDMETHOD  CanvasCropTop  , :REAL4
;  STDMETHOD  CanvasCropRight  , :REAL4
;  STDMETHOD  CanvasCropBottom  , :REAL4
;  STDMETHOD  put_RTF  , :BSTR
;END_INTERFACE
;endif
;
;sIID_ShapeRange textequ <IID {0000C031Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- FileTypes, Type=INTERFACE, GUID={000C036C-0000-0000-C000-000000000046}
;
;ifndef FileTypesVtbl
;BEGIN_INTERFACE FileTypes, _IMsoDispObj
;  STDMETHOD  get_Item  , :SDWORD,:ptr MsoFileType
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Add_  , :MsoFileType
;  STDMETHOD  Remove  , :SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_FileTypes textequ <IID {0000C036Ch,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- SearchFolders, Type=INTERFACE, GUID={000C036A-0000-0000-C000-000000000046}
;
;ifndef SearchFoldersVtbl
;BEGIN_INTERFACE SearchFolders, _IMsoDispObj
;  STDMETHOD  get_Item  , :SDWORD,:ptr ptr ScopeFolder
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Add_  , :ptr ScopeFolder
;  STDMETHOD  Remove  , :SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_SearchFolders textequ <IID {0000C036Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ScopeFolders, Type=INTERFACE, GUID={000C0369-0000-0000-C000-000000000046}
;
;ifndef ScopeFoldersVtbl
;BEGIN_INTERFACE ScopeFolders, _IMsoDispObj
;  STDMETHOD  get_Item  , :SDWORD,:ptr ptr ScopeFolder
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_ScopeFolders textequ <IID {0000C0369h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ScopeFolder, Type=INTERFACE, GUID={000C0368-0000-0000-C000-000000000046}
;
;ifndef ScopeFolderVtbl
;BEGIN_INTERFACE ScopeFolder, _IMsoDispObj
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_Path  , :ptr BSTR
;  STDMETHOD  get_ScopeFolders  , :ptr ptr ScopeFolders
;  STDMETHOD  AddToSearchFolders
;END_INTERFACE
;endif
;
;sIID_ScopeFolder textequ <IID {0000C0368h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- SearchScope, Type=INTERFACE, GUID={000C0367-0000-0000-C000-000000000046}
;
;ifndef SearchScopeVtbl
;BEGIN_INTERFACE SearchScope, _IMsoDispObj
;  STDMETHOD  get_Type  , :ptr MsoSearchIn
;  STDMETHOD  get_ScopeFolder  , :ptr ptr ScopeFolder
;END_INTERFACE
;endif
;
;sIID_SearchScope textequ <IID {0000C0367h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- SearchScopes, Type=INTERFACE, GUID={000C0366-0000-0000-C000-000000000046}
;
;ifndef SearchScopesVtbl
;BEGIN_INTERFACE SearchScopes, _IMsoDispObj
;  STDMETHOD  get_Item  , :SDWORD,:ptr ptr SearchScope
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_SearchScopes textequ <IID {0000C0366h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Shapes, Type=INTERFACE, GUID={000C031E-0000-0000-C000-000000000046}
;
;ifndef ShapesVtbl
;BEGIN_INTERFACE Shapes, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Item  , :VARIANT,:ptr ptr Shape
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  AddCallout  , :MsoCalloutType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddConnector  , :MsoConnectorType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddCurve  , :VARIANT,:ptr ptr Shape
;  STDMETHOD  AddLabel  , :MsoTextOrientation,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddLine  , :REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddPicture  , :BSTR,:MsoTriState,:MsoTriState,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddPolyline  , :VARIANT,:ptr ptr Shape
;  STDMETHOD  AddShape  , :MsoAutoShapeType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddTextEffect  , :MsoPresetTextEffect,:BSTR,:BSTR,:REAL4,:MsoTriState,:MsoTriState,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddTextbox  , :MsoTextOrientation,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  BuildFreeform  , :MsoEditingType,:REAL4,:REAL4,:ptr ptr FreeformBuilder
;  STDMETHOD  Range  , :VARIANT,:ptr ptr ShapeRange
;  STDMETHOD  SelectAll
;  STDMETHOD  get_Background  , :ptr ptr Shape
;  STDMETHOD  get_Default  , :ptr ptr Shape
;  STDMETHOD  AddDiagram  , :MsoDiagramType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddCanvas  , :REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;END_INTERFACE
;endif
;
;sIID_Shapes textequ <IID {0000C031Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TextEffectFormat, Type=INTERFACE, GUID={000C031F-0000-0000-C000-000000000046}
;
;ifndef TextEffectFormatVtbl
;BEGIN_INTERFACE TextEffectFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  ToggleVerticalText
;  STDMETHOD  get_Alignment  , :ptr MsoTextEffectAlignment
;  STDMETHOD  put_Alignment  , :MsoTextEffectAlignment
;  STDMETHOD  get_FontBold  , :ptr MsoTriState
;  STDMETHOD  put_FontBold  , :MsoTriState
;  STDMETHOD  get_FontItalic  , :ptr MsoTriState
;  STDMETHOD  put_FontItalic  , :MsoTriState
;  STDMETHOD  get_FontName  , :ptr BSTR
;  STDMETHOD  put_FontName  , :BSTR
;  STDMETHOD  get_FontSize  , :ptr REAL4
;  STDMETHOD  put_FontSize  , :REAL4
;  STDMETHOD  get_KernedPairs  , :ptr MsoTriState
;  STDMETHOD  put_KernedPairs  , :MsoTriState
;  STDMETHOD  get_NormalizedHeight  , :ptr MsoTriState
;  STDMETHOD  put_NormalizedHeight  , :MsoTriState
;  STDMETHOD  get_PresetShape  , :ptr MsoPresetTextEffectShape
;  STDMETHOD  put_PresetShape  , :MsoPresetTextEffectShape
;  STDMETHOD  get_PresetTextEffect  , :ptr MsoPresetTextEffect
;  STDMETHOD  put_PresetTextEffect  , :MsoPresetTextEffect
;  STDMETHOD  get_RotatedChars  , :ptr MsoTriState
;  STDMETHOD  put_RotatedChars  , :MsoTriState
;  STDMETHOD  get_Text  , :ptr BSTR
;  STDMETHOD  put_Text  , :BSTR
;  STDMETHOD  get_Tracking  , :ptr REAL4
;  STDMETHOD  put_Tracking  , :REAL4
;END_INTERFACE
;endif
;
;sIID_TextEffectFormat textequ <IID {0000C031Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- TextFrame, Type=INTERFACE, GUID={000C0320-0000-0000-C000-000000000046}
;
;ifndef TextFrameVtbl
;BEGIN_INTERFACE TextFrame, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_MarginBottom  , :ptr REAL4
;  STDMETHOD  put_MarginBottom  , :REAL4
;  STDMETHOD  get_MarginLeft  , :ptr REAL4
;  STDMETHOD  put_MarginLeft  , :REAL4
;  STDMETHOD  get_MarginRight  , :ptr REAL4
;  STDMETHOD  put_MarginRight  , :REAL4
;  STDMETHOD  get_MarginTop  , :ptr REAL4
;  STDMETHOD  put_MarginTop  , :REAL4
;  STDMETHOD  get_Orientation  , :ptr MsoTextOrientation
;  STDMETHOD  put_Orientation  , :MsoTextOrientation
;END_INTERFACE
;endif
;
;sIID_TextFrame textequ <IID {0000C0320h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ThreeDFormat, Type=INTERFACE, GUID={000C0321-0000-0000-C000-000000000046}
;
;ifndef ThreeDFormatVtbl
;BEGIN_INTERFACE ThreeDFormat, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  IncrementRotationX  , :REAL4
;  STDMETHOD  IncrementRotationY  , :REAL4
;  STDMETHOD  ResetRotation
;  STDMETHOD  SetThreeDFormat  , :MsoPresetThreeDFormat
;  STDMETHOD  SetExtrusionDirection  , :MsoPresetExtrusionDirection
;  STDMETHOD  get_Depth  , :ptr REAL4
;  STDMETHOD  put_Depth  , :REAL4
;  STDMETHOD  get_ExtrusionColor  , :ptr ptr ColorFormat
;  STDMETHOD  get_ExtrusionColorType  , :ptr MsoExtrusionColorType
;  STDMETHOD  put_ExtrusionColorType  , :MsoExtrusionColorType
;  STDMETHOD  get_Perspective  , :ptr MsoTriState
;  STDMETHOD  put_Perspective  , :MsoTriState
;  STDMETHOD  get_PresetExtrusionDirection  , :ptr MsoPresetExtrusionDirection
;  STDMETHOD  get_PresetLightingDirection  , :ptr MsoPresetLightingDirection
;  STDMETHOD  put_PresetLightingDirection  , :MsoPresetLightingDirection
;  STDMETHOD  get_PresetLightingSoftness  , :ptr MsoPresetLightingSoftness
;  STDMETHOD  put_PresetLightingSoftness  , :MsoPresetLightingSoftness
;  STDMETHOD  get_PresetMaterial  , :ptr MsoPresetMaterial
;  STDMETHOD  put_PresetMaterial  , :MsoPresetMaterial
;  STDMETHOD  get_PresetThreeDFormat  , :ptr MsoPresetThreeDFormat
;  STDMETHOD  get_RotationX  , :ptr REAL4
;  STDMETHOD  put_RotationX  , :REAL4
;  STDMETHOD  get_RotationY  , :ptr REAL4
;  STDMETHOD  put_RotationY  , :REAL4
;  STDMETHOD  get_Visible  , :ptr MsoTriState
;  STDMETHOD  put_Visible  , :MsoTriState
;END_INTERFACE
;endif
;
;sIID_ThreeDFormat textequ <IID {0000C0321h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- Balloon, Type=INTERFACE, GUID={000C0324-0000-0000-C000-000000000046}
;
;ifndef BalloonVtbl
;BEGIN_INTERFACE Balloon, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Checkboxes  , :ptr LPDISPATCH
;  STDMETHOD  get_Labels  , :ptr LPDISPATCH
;  STDMETHOD  put_BalloonType  , :MsoBalloonType
;  STDMETHOD  get_BalloonType  , :ptr MsoBalloonType
;  STDMETHOD  put_Icon  , :MsoIconType
;  STDMETHOD  get_Icon  , :ptr MsoIconType
;  STDMETHOD  put_Heading  , :BSTR
;  STDMETHOD  get_Heading  , :ptr BSTR
;  STDMETHOD  put_Text  , :BSTR
;  STDMETHOD  get_Text  , :ptr BSTR
;  STDMETHOD  put_Mode  , :MsoModeType
;  STDMETHOD  get_Mode  , :ptr MsoModeType
;  STDMETHOD  put_Animation  , :MsoAnimationType
;  STDMETHOD  get_Animation  , :ptr MsoAnimationType
;  STDMETHOD  put_Button  , :MsoButtonSetType
;  STDMETHOD  get_Button  , :ptr MsoButtonSetType
;  STDMETHOD  put_Callback  , :BSTR
;  STDMETHOD  get_Callback  , :ptr BSTR
;  STDMETHOD  put_Private  , :SDWORD
;  STDMETHOD  get_Private  , :ptr SDWORD
;  STDMETHOD  SetAvoidRectangle  , :SDWORD,:SDWORD,:SDWORD,:SDWORD
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  Show  , :ptr MsoBalloonButtonType
;  STDMETHOD  Close
;END_INTERFACE
;endif
;
;sIID_Balloon textequ <IID {0000C0324h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- IMsoDiagram, Type=INTERFACE, GUID={000C036D-0000-0000-C000-000000000046}
;
;ifndef IMsoDiagramVtbl
;BEGIN_INTERFACE IMsoDiagram, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Nodes  , :ptr ptr DiagramNodes
;  STDMETHOD  get_Type  , :ptr MsoDiagramType
;  STDMETHOD  get_AutoLayout  , :ptr MsoTriState
;  STDMETHOD  put_AutoLayout  , :MsoTriState
;  STDMETHOD  get_Reverse  , :ptr MsoTriState
;  STDMETHOD  put_Reverse  , :MsoTriState
;  STDMETHOD  get_AutoFormat  , :ptr MsoTriState
;  STDMETHOD  put_AutoFormat  , :MsoTriState
;  STDMETHOD  Convert  , :MsoDiagramType
;END_INTERFACE
;endif
;
;sIID_IMsoDiagram textequ <IID {0000C036Dh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- DiagramNodes, Type=INTERFACE, GUID={000C036E-0000-0000-C000-000000000046}
;
;ifndef DiagramNodesVtbl
;BEGIN_INTERFACE DiagramNodes, _IMsoDispObj
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  Item  , :VARIANT,:ptr ptr DiagramNode
;  STDMETHOD  SelectAll
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;END_INTERFACE
;endif
;
;sIID_DiagramNodes textequ <IID {0000C036Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- DiagramNodeChildren, Type=INTERFACE, GUID={000C036F-0000-0000-C000-000000000046}
;
;ifndef DiagramNodeChildrenVtbl
;BEGIN_INTERFACE DiagramNodeChildren, _IMsoDispObj
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  Item  , :VARIANT,:ptr ptr DiagramNode
;  STDMETHOD  AddNode  , :VARIANT,:MsoDiagramNodeType,:ptr ptr DiagramNode
;  STDMETHOD  SelectAll
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get_FirstChild  , :ptr ptr DiagramNode
;  STDMETHOD  get_LastChild  , :ptr ptr DiagramNode
;END_INTERFACE
;endif
;
;sIID_DiagramNodeChildren textequ <IID {0000C036Fh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- DiagramNode, Type=INTERFACE, GUID={000C0370-0000-0000-C000-000000000046}
;
;ifndef DiagramNodeVtbl
;BEGIN_INTERFACE DiagramNode, _IMsoDispObj
;  STDMETHOD  AddNode  , :MsoRelativeNodePosition,:MsoDiagramNodeType,:ptr ptr DiagramNode
;  STDMETHOD  Delete
;  STDMETHOD  MoveNode  , :ptr DiagramNode,:MsoRelativeNodePosition
;  STDMETHOD  ReplaceNode  , :ptr DiagramNode
;  STDMETHOD  SwapNode  , :ptr DiagramNode,:BOOL
;  STDMETHOD  CloneNode  , :BOOL,:ptr DiagramNode,:MsoRelativeNodePosition,:ptr ptr DiagramNode
;  STDMETHOD  TransferChildren  , :ptr DiagramNode
;  STDMETHOD  NextNode  , :ptr ptr DiagramNode
;  STDMETHOD  PrevNode  , :ptr ptr DiagramNode
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Children  , :ptr ptr DiagramNodeChildren
;  STDMETHOD  get_Shape  , :ptr ptr Shape
;  STDMETHOD  get_Root  , :ptr ptr DiagramNode
;  STDMETHOD  get_Diagram  , :ptr ptr IMsoDiagram
;  STDMETHOD  get_Layout  , :ptr MsoOrgChartLayoutType
;  STDMETHOD  put_Layout  , :MsoOrgChartLayoutType
;  STDMETHOD  get_TextShape  , :ptr ptr Shape
;END_INTERFACE
;endif
;
;sIID_DiagramNode textequ <IID {0000C0370h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CanvasShapes, Type=INTERFACE, GUID={000C0371-0000-0000-C000-000000000046}
;
;ifndef CanvasShapesVtbl
;BEGIN_INTERFACE CanvasShapes, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Item  , :VARIANT,:ptr ptr Shape
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;  STDMETHOD  AddCallout  , :MsoCalloutType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddConnector  , :MsoConnectorType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddCurve  , :VARIANT,:ptr ptr Shape
;  STDMETHOD  AddLabel  , :MsoTextOrientation,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddLine  , :REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddPicture  , :BSTR,:MsoTriState,:MsoTriState,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddPolyline  , :VARIANT,:ptr ptr Shape
;  STDMETHOD  AddShape  , :MsoAutoShapeType,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddTextEffect  , :MsoPresetTextEffect,:BSTR,:BSTR,:REAL4,:MsoTriState,:MsoTriState,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  AddTextbox  , :MsoTextOrientation,:REAL4,:REAL4,:REAL4,:REAL4,:ptr ptr Shape
;  STDMETHOD  BuildFreeform  , :MsoEditingType,:REAL4,:REAL4,:ptr ptr FreeformBuilder
;  STDMETHOD  Range  , :VARIANT,:ptr ptr ShapeRange
;  STDMETHOD  SelectAll
;  STDMETHOD  get_Background  , :ptr ptr Shape
;END_INTERFACE
;endif
;
;sIID_CanvasShapes textequ <IID {0000C0371h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- IMsoDispCagNotifySink, Type=INTERFACE, GUID={000C0359-0000-0000-C000-000000000046}
;
;ifndef IMsoDispCagNotifySinkVtbl
;BEGIN_INTERFACE IMsoDispCagNotifySink, IDispatch
;  STDMETHOD  InsertClip  , :LPUNKNOWN,:LPUNKNOWN
;  STDMETHOD  WindowIsClosing
;END_INTERFACE
;endif
;
;sIID_IMsoDispCagNotifySink textequ <IID {0000C0359h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- OfficeDataSourceObject, Type=INTERFACE, GUID={000C1530-0000-0000-C000-000000000046}
;
;ifndef OfficeDataSourceObjectVtbl
;BEGIN_INTERFACE OfficeDataSourceObject, IDispatch
;  STDMETHOD  get_ConnectString  , :ptr BSTR
;  STDMETHOD  put_ConnectString  , :BSTR
;  STDMETHOD  get_Table  , :ptr BSTR
;  STDMETHOD  put_Table  , :BSTR
;  STDMETHOD  get_DataSource  , :ptr BSTR
;  STDMETHOD  put_DataSource  , :BSTR
;  STDMETHOD  get_Columns  , :ptr LPDISPATCH
;  STDMETHOD  get_RowCount  , :ptr SDWORD
;  STDMETHOD  get_Filters  , :ptr LPDISPATCH
;  STDMETHOD  Move  , :MsoMoveRow,:SDWORD,:ptr SDWORD
;  STDMETHOD  Open  , :BSTR,:BSTR,:BSTR,:SDWORD,:SDWORD
;  STDMETHOD  SetSortOrder  , :BSTR,:BOOL,:BSTR,:BOOL,:BSTR,:BOOL
;  STDMETHOD  ApplyFilter
;END_INTERFACE
;endif
;
;sIID_OfficeDataSourceObject textequ <IID {0000C1530h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ODSOColumn, Type=INTERFACE, GUID={000C1531-0000-0000-C000-000000000046}
;
;ifndef ODSOColumnVtbl
;BEGIN_INTERFACE ODSOColumn, _IMsoDispObj
;  STDMETHOD  get_Index  , :ptr SDWORD
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Value  , :ptr BSTR
;END_INTERFACE
;endif
;
;sIID_ODSOColumn textequ <IID {0000C1531h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ODSOColumns, Type=INTERFACE, GUID={000C1532-0000-0000-C000-000000000046}
;
;ifndef ODSOColumnsVtbl
;BEGIN_INTERFACE ODSOColumns, _IMsoDispObj
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  Item  , :VARIANT,:ptr LPDISPATCH
;END_INTERFACE
;endif
;
;sIID_ODSOColumns textequ <IID {0000C1532h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- BalloonCheckboxes, Type=INTERFACE, GUID={000C0326-0000-0000-C000-000000000046}
;
;ifndef BalloonCheckboxesVtbl
;BEGIN_INTERFACE BalloonCheckboxes, _IMsoDispObj
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Item  , :SDWORD,:ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  put_Count  , :SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_BalloonCheckboxes textequ <IID {0000C0326h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- BalloonCheckbox, Type=INTERFACE, GUID={000C0328-0000-0000-C000-000000000046}
;
;ifndef BalloonCheckboxVtbl
;BEGIN_INTERFACE BalloonCheckbox, _IMsoDispObj
;  STDMETHOD  get_Item  , :ptr BSTR
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  put_Checked  , :BOOL
;  STDMETHOD  get_Checked  , :ptr BOOL
;  STDMETHOD  put_Text  , :BSTR
;  STDMETHOD  get_Text  , :ptr BSTR
;END_INTERFACE
;endif
;
;sIID_BalloonCheckbox textequ <IID {0000C0328h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ODSOFilter, Type=INTERFACE, GUID={000C1533-0000-0000-C000-000000000046}
;
;ifndef ODSOFilterVtbl
;BEGIN_INTERFACE ODSOFilter, _IMsoDispObj
;  STDMETHOD  get_Index  , :ptr SDWORD
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Column  , :ptr BSTR
;  STDMETHOD  put_Column  , :BSTR
;  STDMETHOD  get_Comparison  , :ptr MsoFilterComparison
;  STDMETHOD  put_Comparison  , :MsoFilterComparison
;  STDMETHOD  get_CompareTo  , :ptr BSTR
;  STDMETHOD  put_CompareTo  , :BSTR
;  STDMETHOD  get_Conjunction  , :ptr MsoFilterConjunction
;  STDMETHOD  put_Conjunction  , :MsoFilterConjunction
;END_INTERFACE
;endif
;
;sIID_ODSOFilter textequ <IID {0000C1533h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ODSOFilters, Type=INTERFACE, GUID={000C1534-0000-0000-C000-000000000046}
;
;ifndef ODSOFiltersVtbl
;BEGIN_INTERFACE ODSOFilters, _IMsoDispObj
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  Item  , :SDWORD,:ptr LPDISPATCH
;  STDMETHOD  Add_  , :BSTR,:MsoFilterComparison,:MsoFilterConjunction,:BSTR,:BOOL
;  STDMETHOD  Delete  , :SDWORD,:BOOL
;END_INTERFACE
;endif
;
;sIID_ODSOFilters textequ <IID {0000C1534h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- BalloonLabels, Type=INTERFACE, GUID={000C032E-0000-0000-C000-000000000046}
;
;ifndef BalloonLabelsVtbl
;BEGIN_INTERFACE BalloonLabels, _IMsoDispObj
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Item  , :SDWORD,:ptr LPDISPATCH
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  put_Count  , :SDWORD
;  STDMETHOD  get__NewEnum  , :ptr LPUNKNOWN
;END_INTERFACE
;endif
;
;sIID_BalloonLabels textequ <IID {0000C032Eh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- BalloonLabel, Type=INTERFACE, GUID={000C0330-0000-0000-C000-000000000046}
;
;ifndef BalloonLabelVtbl
;BEGIN_INTERFACE BalloonLabel, _IMsoDispObj
;  STDMETHOD  get_Item  , :ptr BSTR
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  put_Text  , :BSTR
;  STDMETHOD  get_Text  , :ptr BSTR
;END_INTERFACE
;endif
;
;sIID_BalloonLabel textequ <IID {0000C0330h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- NewFile, Type=INTERFACE, GUID={000C0936-0000-0000-C000-000000000046}
;
;ifndef NewFileVtbl
;BEGIN_INTERFACE NewFile, _IMsoDispObj
;  STDMETHOD  Add_  , :BSTR,:VARIANT,:VARIANT,:VARIANT,:ptr BOOL
;  STDMETHOD  Remove  , :BSTR,:VARIANT,:VARIANT,:VARIANT,:ptr BOOL
;END_INTERFACE
;endif
;
;sIID_NewFile textequ <IID {0000C0936h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- WebComponent, Type=INTERFACE, GUID={000CD100-0000-0000-C000-000000000046}
;
;ifndef WebComponentVtbl
;BEGIN_INTERFACE WebComponent, IDispatch
;  STDMETHOD  get_Shape  , :ptr LPDISPATCH
;  STDMETHOD  get_URL  , :ptr BSTR
;  STDMETHOD  put_URL  , :BSTR
;  STDMETHOD  get_HTML  , :ptr BSTR
;  STDMETHOD  put_HTML  , :BSTR
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  put_Name  , :BSTR
;  STDMETHOD  get_Width  , :ptr SDWORD
;  STDMETHOD  put_Width  , :SDWORD
;  STDMETHOD  get_Height  , :ptr SDWORD
;  STDMETHOD  put_Height  , :SDWORD
;  STDMETHOD  SetPlaceHolderGraphic  , :BSTR
;  STDMETHOD  Commit
;  STDMETHOD  Revert
;END_INTERFACE
;endif
;
;sIID_WebComponent textequ <IID {0000CD100h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- WebComponentWindowExternal, Type=INTERFACE, GUID={000CD101-0000-0000-C000-000000000046}
;
;ifndef WebComponentWindowExternalVtbl
;BEGIN_INTERFACE WebComponentWindowExternal, IDispatch
;  STDMETHOD  get_InterfaceVersion  , :ptr SDWORD
;  STDMETHOD  get_ApplicationName  , :ptr BSTR
;  STDMETHOD  get_ApplicationVersion  , :ptr SDWORD
;  STDMETHOD  get_Application  , :ptr LPDISPATCH
;  STDMETHOD  CloseWindow
;  STDMETHOD  get_WebComponent  , :ptr ptr WebComponent
;END_INTERFACE
;endif
;
;sIID_WebComponentWindowExternal textequ <IID {0000CD101h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- WebComponentFormat, Type=INTERFACE, GUID={000CD102-0000-0000-C000-000000000046}
;
;ifndef WebComponentFormatVtbl
;BEGIN_INTERFACE WebComponentFormat, IDispatch
;  STDMETHOD  get_Application  , :ptr LPDISPATCH
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_URL  , :ptr BSTR
;  STDMETHOD  put_URL  , :BSTR
;  STDMETHOD  get_HTML  , :ptr BSTR
;  STDMETHOD  put_HTML  , :BSTR
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  put_Name  , :BSTR
;  STDMETHOD  get_Width  , :ptr SDWORD
;  STDMETHOD  put_Width  , :SDWORD
;  STDMETHOD  get_Height  , :ptr SDWORD
;  STDMETHOD  put_Height  , :SDWORD
;  STDMETHOD  get_PreviewGraphic  , :ptr BSTR
;  STDMETHOD  put_PreviewGraphic  , :BSTR
;  STDMETHOD  LaunchPropertiesWindow
;END_INTERFACE
;endif
;
;sIID_WebComponentFormat textequ <IID {0000CD102h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- AnswerWizardFiles, Type=INTERFACE, GUID={000C0361-0000-0000-C000-000000000046}
;
;ifndef AnswerWizardFilesVtbl
;BEGIN_INTERFACE AnswerWizardFiles, _IMsoDispObj
;  STDMETHOD  get_Parent  , :ptr LPDISPATCH
;  STDMETHOD  get_Item  , :SDWORD,:ptr BSTR
;  STDMETHOD  get_Count  , :ptr SDWORD
;  STDMETHOD  Add_  , :BSTR
;  STDMETHOD  Delete  , :BSTR
;END_INTERFACE
;endif
;
;sIID_AnswerWizardFiles textequ <IID {0000C0361h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- ILicWizExternal, Type=INTERFACE, GUID={4CAC6328-B9B0-11D3-8D59-0050048384E3}
;
;ifndef ILicWizExternalVtbl
;BEGIN_INTERFACE ILicWizExternal, IDispatch
;  STDMETHOD  PrintHtmlDocument  , :LPUNKNOWN
;  STDMETHOD  InvokeDateTimeApplet
;  STDMETHOD  FormatDate  , :Date,:BSTR,:ptr BSTR
;  STDMETHOD  ShowHelp  , :ptr VARIANT
;  STDMETHOD  Terminate
;  STDMETHOD  DisableVORWReminder  , :SDWORD
;  STDMETHOD  SaveReceipt  , :BSTR,:ptr BSTR
;  STDMETHOD  OpenInDefaultBrowser  , :BSTR
;  STDMETHOD  MsoAlert  , :BSTR,:BSTR,:BSTR,:ptr SDWORD
;  STDMETHOD  DepositPidKey  , :BSTR,:SDWORD,:ptr SDWORD
;  STDMETHOD  WriteLog  , :BSTR
;  STDMETHOD  ResignDpc  , :BSTR
;  STDMETHOD  ResetPID
;  STDMETHOD  SetDialogSize  , :SDWORD,:SDWORD
;  STDMETHOD  VerifyClock  , :SDWORD,:ptr SDWORD
;  STDMETHOD  SortSelectOptions  , :LPDISPATCH
;  STDMETHOD  InternetDisconnect
;  STDMETHOD  GetConnectedState  , :ptr SDWORD
;  STDMETHOD  get_Context  , :ptr SDWORD
;  STDMETHOD  get_Validator  , :ptr LPDISPATCH
;  STDMETHOD  get_LicAgent  , :ptr LPDISPATCH
;  STDMETHOD  get_CountryInfo  , :ptr BSTR
;  STDMETHOD  put_WizardVisible  , :SDWORD
;  STDMETHOD  put_WizardTitle  , :BSTR
;  STDMETHOD  get_AnimationEnabled  , :ptr SDWORD
;  STDMETHOD  put_CurrentHelpId  , :SDWORD
;  STDMETHOD  get_OfficeOnTheWebUrl  , :ptr BSTR
;END_INTERFACE
;endif
;
;sIID_ILicWizExternal textequ <IID {04CAC6328h,0B9B0h,011D3h,{08Dh,059h,000h,050h,004h,083h,084h,0E3h}}>
;
;;--- ILicValidator, Type=INTERFACE, GUID={919AA22C-B9AD-11D3-8D59-0050048384E3}
;
;ifndef ILicValidatorVtbl
;BEGIN_INTERFACE ILicValidator, IDispatch
;  STDMETHOD  get_Products  , :ptr VARIANT
;  STDMETHOD  get_Selection  , :ptr SDWORD
;  STDMETHOD  put_Selection  , :SDWORD
;END_INTERFACE
;endif
;
;sIID_ILicValidator textequ <IID {0919AA22Ch,0B9ADh,011D3h,{08Dh,059h,000h,050h,004h,083h,084h,0E3h}}>
;
;;--- ILicAgent, Type=INTERFACE, GUID={00194002-D9C3-11D3-8D59-0050048384E3}
;
;ifndef ILicAgentVtbl
;BEGIN_INTERFACE ILicAgent, IDispatch
;  STDMETHOD  Initialize  , :DWORD,:DWORD,:BSTR,:ptr DWORD
;  STDMETHOD  GetFirstName  , :ptr BSTR
;  STDMETHOD  SetFirstName  , :BSTR
;  STDMETHOD  GetLastName  , :ptr BSTR
;  STDMETHOD  SetLastName  , :BSTR
;  STDMETHOD  GetOrgName  , :ptr BSTR
;  STDMETHOD  SetOrgName  , :BSTR
;  STDMETHOD  GetEmail  , :ptr BSTR
;  STDMETHOD  SetEmail  , :BSTR
;  STDMETHOD  GetPhone  , :ptr BSTR
;  STDMETHOD  SetPhone  , :BSTR
;  STDMETHOD  GetAddress1  , :ptr BSTR
;  STDMETHOD  SetAddress1  , :BSTR
;  STDMETHOD  GetCity  , :ptr BSTR
;  STDMETHOD  SetCity  , :BSTR
;  STDMETHOD  GetState  , :ptr BSTR
;  STDMETHOD  SetState  , :BSTR
;  STDMETHOD  GetCountryCode  , :ptr BSTR
;  STDMETHOD  SetCountryCode  , :BSTR
;  STDMETHOD  GetCountryDesc  , :ptr BSTR
;  STDMETHOD  SetCountryDesc  , :BSTR
;  STDMETHOD  GetZip  , :ptr BSTR
;  STDMETHOD  SetZip  , :BSTR
;  STDMETHOD  GetIsoLanguage  , :ptr DWORD
;  STDMETHOD  SetIsoLanguage  , :DWORD
;  STDMETHOD  GetMSUpdate  , :ptr BSTR
;  STDMETHOD  SetMSUpdate  , :BSTR
;  STDMETHOD  GetMSOffer  , :ptr BSTR
;  STDMETHOD  SetMSOffer  , :BSTR
;  STDMETHOD  GetOtherOffer  , :ptr BSTR
;  STDMETHOD  SetOtherOffer  , :BSTR
;  STDMETHOD  GetAddress2  , :ptr BSTR
;  STDMETHOD  SetAddress2  , :BSTR
;  STDMETHOD  CheckSystemClock  , :ptr DWORD
;  STDMETHOD  GetExistingExpiryDate  , :ptr Date
;  STDMETHOD  GetNewExpiryDate  , :ptr Date
;  STDMETHOD  GetBillingFirstName  , :ptr BSTR
;  STDMETHOD  SetBillingFirstName  , :BSTR
;  STDMETHOD  GetBillingLastName  , :ptr BSTR
;  STDMETHOD  SetBillingLastName  , :BSTR
;  STDMETHOD  GetBillingPhone  , :ptr BSTR
;  STDMETHOD  SetBillingPhone  , :BSTR
;  STDMETHOD  GetBillingAddress1  , :ptr BSTR
;  STDMETHOD  SetBillingAddress1  , :BSTR
;  STDMETHOD  GetBillingAddress2  , :ptr BSTR
;  STDMETHOD  SetBillingAddress2  , :BSTR
;  STDMETHOD  GetBillingCity  , :ptr BSTR
;  STDMETHOD  SetBillingCity  , :BSTR
;  STDMETHOD  GetBillingState  , :ptr BSTR
;  STDMETHOD  SetBillingState  , :BSTR
;  STDMETHOD  GetBillingCountryCode  , :ptr BSTR
;  STDMETHOD  SetBillingCountryCode  , :BSTR
;  STDMETHOD  GetBillingZip  , :ptr BSTR
;  STDMETHOD  SetBillingZip  , :BSTR
;  STDMETHOD  SaveBillingInfo  , :SDWORD,:ptr DWORD
;  STDMETHOD  IsCCRenewalCountry  , :BSTR,:ptr SDWORD
;  STDMETHOD  GetVATLabel  , :BSTR,:ptr BSTR
;  STDMETHOD  GetCCRenewalExpiryDate  , :ptr Date
;  STDMETHOD  SetVATNumber  , :BSTR
;  STDMETHOD  SetCreditCardType  , :BSTR
;  STDMETHOD  SetCreditCardNumber  , :BSTR
;  STDMETHOD  SetCreditCardExpiryYear  , :DWORD
;  STDMETHOD  SetCreditCardExpiryMonth  , :DWORD
;  STDMETHOD  GetCreditCardCount  , :ptr DWORD
;  STDMETHOD  GetCreditCardCode  , :DWORD,:ptr BSTR
;  STDMETHOD  GetCreditCardName  , :DWORD,:ptr BSTR
;  STDMETHOD  GetVATNumber  , :ptr BSTR
;  STDMETHOD  GetCreditCardType  , :ptr BSTR
;  STDMETHOD  GetCreditCardNumber  , :ptr BSTR
;  STDMETHOD  GetCreditCardExpiryYear  , :ptr DWORD
;  STDMETHOD  GetCreditCardExpiryMonth  , :ptr DWORD
;  STDMETHOD  GetDisconnectOption  , :ptr SDWORD
;  STDMETHOD  SetDisconnectOption  , :SDWORD
;  STDMETHOD  AsyncProcessHandshakeRequest  , :SDWORD
;  STDMETHOD  AsyncProcessNewLicenseRequest
;  STDMETHOD  AsyncProcessReissueLicenseRequest
;  STDMETHOD  AsyncProcessRetailRenewalLicenseRequest
;  STDMETHOD  AsyncProcessReviseCustInfoRequest
;  STDMETHOD  AsyncProcessCCRenewalPriceRequest
;  STDMETHOD  AsyncProcessCCRenewalLicenseRequest
;  STDMETHOD  GetAsyncProcessReturnCode  , :ptr DWORD
;  STDMETHOD  IsUpgradeAvailable  , :ptr SDWORD
;  STDMETHOD  WantUpgrade  , :SDWORD
;  STDMETHOD  AsyncProcessDroppedLicenseRequest
;  STDMETHOD  GenerateInstallationId  , :ptr BSTR
;  STDMETHOD  DepositConfirmationId  , :BSTR,:ptr DWORD
;  STDMETHOD  VerifyCheckDigits  , :BSTR,:ptr SDWORD
;  STDMETHOD  GetCurrentExpiryDate  , :ptr Date
;  STDMETHOD  CancelAsyncProcessRequest  , :SDWORD
;  STDMETHOD  GetCurrencyDescription  , :DWORD,:ptr BSTR
;  STDMETHOD  GetPriceItemCount  , :ptr DWORD
;  STDMETHOD  GetPriceItemLabel  , :DWORD,:ptr BSTR
;  STDMETHOD  GetPriceItemValue  , :DWORD,:DWORD,:ptr BSTR
;  STDMETHOD  GetInvoiceText  , :ptr BSTR
;  STDMETHOD  GetBackendErrorMsg  , :ptr BSTR
;  STDMETHOD  GetCurrencyOption  , :ptr DWORD
;  STDMETHOD  SetCurrencyOption  , :DWORD
;  STDMETHOD  GetEndOfLifeHtmlText  , :ptr BSTR
;  STDMETHOD  DisplaySSLCert  , :ptr DWORD
;END_INTERFACE
;endif
;
;sIID_ILicAgent textequ <IID {000194002h,0D9C3h,011D3h,{08Dh,059h,000h,050h,004h,083h,084h,0E3h}}>
;
;;--- IMsoEServicesDialog, Type=INTERFACE, GUID={000C0372-0000-0000-C000-000000000046}
;
;ifndef IMsoEServicesDialogVtbl
;BEGIN_INTERFACE IMsoEServicesDialog, IDispatch
;  STDMETHOD  Close  , :BOOL
;  STDMETHOD  AddTrustedDomain  , :BSTR
;  STDMETHOD  get_ApplicationName  , :ptr BSTR
;  STDMETHOD  get_Application  , :ptr LPDISPATCH
;  STDMETHOD  get_WebComponent  , :ptr LPDISPATCH
;  STDMETHOD  get_ClipArt  , :ptr LPDISPATCH
;END_INTERFACE
;endif
;
;sIID_IMsoEServicesDialog textequ <IID {0000C0372h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- WebComponentProperties, Type=INTERFACE, GUID={000C0373-0000-0000-C000-000000000046}
;
;ifndef WebComponentPropertiesVtbl
;BEGIN_INTERFACE WebComponentProperties, IDispatch
;  STDMETHOD  get_Shape  , :ptr LPDISPATCH
;  STDMETHOD  get_Name  , :ptr BSTR
;  STDMETHOD  put_Name  , :BSTR
;  STDMETHOD  get_URL  , :ptr BSTR
;  STDMETHOD  put_URL  , :BSTR
;  STDMETHOD  get_HTML  , :ptr BSTR
;  STDMETHOD  put_HTML  , :BSTR
;  STDMETHOD  get_PreviewGraphic  , :ptr BSTR
;  STDMETHOD  put_PreviewGraphic  , :BSTR
;  STDMETHOD  get_PreviewHTML  , :ptr BSTR
;  STDMETHOD  put_PreviewHTML  , :BSTR
;  STDMETHOD  get_Width  , :ptr SDWORD
;  STDMETHOD  put_Width  , :SDWORD
;  STDMETHOD  get_Height  , :ptr SDWORD
;  STDMETHOD  put_Height  , :SDWORD
;  STDMETHOD  get_Tag  , :ptr BSTR
;  STDMETHOD  put_Tag  , :BSTR
;END_INTERFACE
;endif
;
;sIID_WebComponentProperties textequ <IID {0000C0373h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _CommandBarComboBoxEvents, Type=DISPATCH, GUID={000C0354-0000-0000-C000-000000000046}
;
;;--- dispinterface only
;ifndef _CommandBarComboBoxEventsVtbl
;BEGIN_INTERFACE _CommandBarComboBoxEvents, IDispatch
;  DISPMETHOD  Change  , :ptr CommandBarComboBox
;END_INTERFACE
;endif
;
;sIID__CommandBarComboBoxEvents textequ <IID {0000C0354h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- IMsoEnvelopeVBEvents, Type=DISPATCH, GUID={000672AD-0000-0000-C000-000000000046}
;
;;--- dispinterface only
;ifndef IMsoEnvelopeVBEventsVtbl
;BEGIN_INTERFACE IMsoEnvelopeVBEvents, IDispatch
;  DISPMETHOD  EnvelopeShow
;  DISPMETHOD  EnvelopeHide
;END_INTERFACE
;endif
;
;sIID_IMsoEnvelopeVBEvents textequ <IID {0000672ADh,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _CommandBarsEvents, Type=DISPATCH, GUID={000C0352-0000-0000-C000-000000000046}
;
;;--- dispinterface only
;ifndef _CommandBarsEventsVtbl
;BEGIN_INTERFACE _CommandBarsEvents, IDispatch
;  DISPMETHOD  OnUpdate
;END_INTERFACE
;endif
;
;sIID__CommandBarsEvents textequ <IID {0000C0352h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- _CommandBarButtonEvents, Type=DISPATCH, GUID={000C0351-0000-0000-C000-000000000046}
;
;;--- dispinterface only
;ifndef _CommandBarButtonEventsVtbl
;BEGIN_INTERFACE _CommandBarButtonEvents, IDispatch
;  DISPMETHOD  Click  , :ptr CommandBarButton,:ptr BOOL
;END_INTERFACE
;endif
;
;sIID__CommandBarButtonEvents textequ <IID {0000C0351h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CommandBarComboBox, Type=COCLASS, GUID={55F88897-7708-11D1-ACEB-006008961DA5}
;
;sCLSID_CommandBarComboBox textequ <GUID {055F88897h,07708h,011D1h,{0ACh,0EBh,000h,060h,008h,096h,01Dh,0A5h}}>
;
;;--- MsoEnvelope, Type=COCLASS, GUID={0006F01A-0000-0000-C000-000000000046}
;
;sCLSID_MsoEnvelope textequ <GUID {00006F01Ah,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}>
;
;;--- CommandBarButton, Type=COCLASS, GUID={55F88891-7708-11D1-ACEB-006008961DA5}
;
;sCLSID_CommandBarButton textequ <GUID {055F88891h,07708h,011D1h,{0ACh,0EBh,000h,060h,008h,096h,01Dh,0A5h}}>
;
;;--- CommandBars, Type=COCLASS, GUID={55F88893-7708-11D1-ACEB-006008961DA5}
;
;sCLSID_CommandBars textequ <GUID {055F88893h,07708h,011D1h,{0ACh,0EBh,000h,060h,008h,096h,01Dh,0A5h}}>
;
;;--- end of type library ---