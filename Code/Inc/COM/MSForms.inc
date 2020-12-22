
;--- Generated .INC file by COMView
;--- typelib name=MSForms
;--- documentation=Microsoft Forms 2.0 Object Library
;--- GUID={0D452EE1-E08F-101A-852E-02608C4D0BB4}
;--- Version 2.0, LCID 0

;--- prototypes too complex for MASM may exist
;--- if such ones reside in a vtable they will be replaced by dummies
;--- search for occurances of ';+++' to have a closer look at these

sTLBID_MSForms textequ <GUID {00D452EE1h,0E08Fh,0101Ah,{085h,02Eh,002h,060h,08Ch,04Dh,00Bh,0B4h}}>
_MajorVer_MSForms equ 2
_MinorVer_MSForms equ 0

;--- fmDropEffect, Type=ENUM, GUID={10BB4720-F797-11CE-B9EC-00AA006B1A69}

fmDropEffect typedef SDWORD
fmDropEffectNone  EQU  0
fmDropEffectCopy  EQU  1
fmDropEffectMove  EQU  2
fmDropEffectCopyOrMove  EQU  3

;--- fmAction, Type=ENUM, GUID={570C03E0-F797-11CE-B9EC-00AA006B1A69}

fmAction typedef SDWORD
fmActionCut  EQU  0
fmActionCopy  EQU  1
fmActionPaste  EQU  2
fmActionDragDrop  EQU  3

;--- fmMode, Type=ENUM, GUID={C63BD250-BCAA-11CE-B64D-00AA004CD6D8}

fmMode typedef SDWORD
fmModeInherit  EQU  -2      ;=0FFFFFFFEh
fmModeOn  EQU  -1
fmModeOff  EQU  0

;--- fmMousePointer, Type=ENUM, GUID={593104F8-16BA-101B-989C-00006B82871A}

fmMousePointer typedef SDWORD
fmMousePointerDefault  EQU  0
fmMousePointerArrow  EQU  1
fmMousePointerCross  EQU  2
fmMousePointerIBeam  EQU  3
fmMousePointerSizeNESW  EQU  6
fmMousePointerSizeNS  EQU  7
fmMousePointerSizeNWSE  EQU  8
fmMousePointerSizeWE  EQU  9
fmMousePointerUpArrow  EQU  10
fmMousePointerHourGlass  EQU  11
fmMousePointerNoDrop  EQU  12
fmMousePointerAppStarting  EQU  13
fmMousePointerHelp  EQU  14
fmMousePointerSizeAll  EQU  15
fmMousePointerCustom  EQU  99      ;=063h

;--- fmScrollBars, Type=ENUM, GUID={5931055E-16BA-101B-989C-00006B82871A}

fmScrollBars typedef SDWORD
fmScrollBarsNone  EQU  0
fmScrollBarsHorizontal  EQU  1
fmScrollBarsVertical  EQU  2
fmScrollBarsBoth  EQU  3

;--- fmScrollAction, Type=ENUM, GUID={E0ABC3C0-D199-11CE-8CCE-00AA0044BB60}

fmScrollAction typedef SDWORD
fmScrollActionNoChange  EQU  0
fmScrollActionLineUp  EQU  1
fmScrollActionLineDown  EQU  2
fmScrollActionPageUp  EQU  3
fmScrollActionPageDown  EQU  4
fmScrollActionBegin  EQU  5
fmScrollActionEnd  EQU  6
_fmScrollActionAbsoluteChange  EQU  7
fmScrollActionPropertyChange  EQU  8
fmScrollActionControlRequest  EQU  9
fmScrollActionFocusRequest  EQU  10

;--- fmCycle, Type=ENUM, GUID={3DBDD630-DD73-11CE-8CD1-00AA0044BB60}

fmCycle typedef SDWORD
fmCycleAllForms  EQU  0
fmCycleCurrentForm  EQU  2

;--- fmZOrder, Type=ENUM, GUID={14C73C30-1612-11CE-9E98-00AA00574A4F}

fmZOrder typedef SDWORD
fmZOrderFront  EQU  0
fmZOrderBack  EQU  1

;--- fmBorderStyle, Type=ENUM, GUID={5931055C-16BA-101B-989C-00006B82871A}

fmBorderStyle typedef SDWORD
fmBorderStyleNone  EQU  0
fmBorderStyleSingle  EQU  1

;--- fmTextAlign, Type=ENUM, GUID={66BAAC90-7C2A-11CE-B783-00AA004BA6AE}

fmTextAlign typedef SDWORD
fmTextAlignLeft  EQU  1
fmTextAlignCenter  EQU  2
fmTextAlignRight  EQU  3

;--- fmAlignment, Type=ENUM, GUID={CD474E84-A35F-101A-BEB9-00006B827DA8}

fmAlignment typedef SDWORD
fmAlignmentLeft  EQU  0
fmAlignmentRight  EQU  1

;--- fmBorders, Type=ENUM, GUID={E1FC1640-70DF-101B-BC16-00AA003E3B29}

fmBorders typedef SDWORD
fmBordersNone  EQU  0
fmBordersBox  EQU  1
fmBordersLeft  EQU  2
fmBordersTop  EQU  3

;--- fmBackStyle, Type=ENUM, GUID={1AFB3130-C129-11CD-A777-00DD01143C57}

fmBackStyle typedef SDWORD
fmBackStyleTransparent  EQU  0
fmBackStyleOpaque  EQU  1

;--- fmButtonStyle, Type=ENUM, GUID={FDE774C0-9AA8-11CD-84DB-00006B82871A}

fmButtonStyle typedef SDWORD
fmButtonStylePushButton  EQU  0
fmButtonStyleToggleButton  EQU  1

;--- fmPicPosition, Type=ENUM, GUID={9011F7A0-C130-11CD-9BE1-00006B82871A}

fmPicPosition typedef SDWORD
fmPicPositionCenter  EQU  0
fmPicPositionTopLeft  EQU  1
fmPicPositionTopCenter  EQU  2
fmPicPositionTopRight  EQU  3
fmPicPositionCenterLeft  EQU  4
fmPicPositionCenterRight  EQU  5
fmPicPositionBottomLeft  EQU  6
fmPicPositionBottomCenter  EQU  7
fmPicPositionBottomRight  EQU  8

;--- fmVerticalScrollBarSide, Type=ENUM, GUID={D625CA10-CC59-11CE-B653-00AA004CD6D8}

fmVerticalScrollBarSide typedef SDWORD
fmVerticalScrollBarSideRight  EQU  0
fmVerticalScrollBarSideLeft  EQU  1

;--- fmLayoutEffect, Type=ENUM, GUID={02DFD4F0-EA2B-11CE-8043-00AA006009FA}

fmLayoutEffect typedef SDWORD
fmLayoutEffectNone  EQU  0
fmLayoutEffectInitiate  EQU  1
_fmLayoutEffectRespond  EQU  2

;--- fmSpecialEffect, Type=ENUM, GUID={A7946240-EA45-11CE-8043-00AA006009FA}

fmSpecialEffect typedef SDWORD
fmSpecialEffectFlat  EQU  0
fmSpecialEffectRaised  EQU  1
fmSpecialEffectSunken  EQU  2
fmSpecialEffectEtched  EQU  3
fmSpecialEffectBump  EQU  6

;--- fmDragState, Type=ENUM, GUID={82074C80-EA51-11CE-8043-00AA006009FA}

fmDragState typedef SDWORD
fmDragStateEnter  EQU  0
fmDragStateLeave  EQU  1
fmDragStateOver  EQU  2

;--- fmPictureSizeMode, Type=ENUM, GUID={53327010-E90B-11CE-9E0B-00AA006002F3}

fmPictureSizeMode typedef SDWORD
fmPictureSizeModeClip  EQU  0
fmPictureSizeModeStretch  EQU  1
fmPictureSizeModeZoom  EQU  3

;--- fmPictureAlignment, Type=ENUM, GUID={3574BBE0-F520-11CE-83F6-00AA00479846}

fmPictureAlignment typedef SDWORD
fmPictureAlignmentTopLeft  EQU  0
fmPictureAlignmentTopRight  EQU  1
fmPictureAlignmentCenter  EQU  2
fmPictureAlignmentBottomLeft  EQU  3
fmPictureAlignmentBottomRight  EQU  4

;--- fmButtonEffect, Type=ENUM, GUID={317A54C0-C7B1-11CE-9AFD-00AA00600AB8}

fmButtonEffect typedef SDWORD
fmButtonEffectFlat  EQU  0
fmButtonEffectSunken  EQU  2

;--- fmOrientation, Type=ENUM, GUID={16E571E0-040B-11CF-8283-00AA004BA6AE}

fmOrientation typedef SDWORD
fmOrientationAuto  EQU  -1
fmOrientationVertical  EQU  0
fmOrientationHorizontal  EQU  1

;--- fmSnapPoint, Type=ENUM, GUID={317A54C1-C7B1-11CE-9AFD-00AA00600AB8}

fmSnapPoint typedef SDWORD
fmSnapPointTopLeft  EQU  0
fmSnapPointTopCenter  EQU  1
fmSnapPointTopRight  EQU  2
fmSnapPointCenterLeft  EQU  3
fmSnapPointCenter  EQU  4
fmSnapPointCenterRight  EQU  5
fmSnapPointBottomLeft  EQU  6
fmSnapPointBottomCenter  EQU  7
fmSnapPointBottomRight  EQU  8

;--- fmPicturePosition, Type=ENUM, GUID={317A54C2-C7B1-11CE-9AFD-00AA00600AB8}

fmPicturePosition typedef SDWORD
fmPicturePositionLeftTop  EQU  0
fmPicturePositionLeftCenter  EQU  1
fmPicturePositionLeftBottom  EQU  2
fmPicturePositionRightTop  EQU  3
fmPicturePositionRightCenter  EQU  4
fmPicturePositionRightBottom  EQU  5
fmPicturePositionAboveLeft  EQU  6
fmPicturePositionAboveCenter  EQU  7
fmPicturePositionAboveRight  EQU  8
fmPicturePositionBelowLeft  EQU  9
fmPicturePositionBelowCenter  EQU  10
fmPicturePositionBelowRight  EQU  11
fmPicturePositionCenter  EQU  12

;--- fmDisplayStyle, Type=ENUM, GUID={A4069F25-4221-11CE-8EA0-00AA004BA6AE}

fmDisplayStyle typedef SDWORD
fmDisplayStyleText  EQU  1
fmDisplayStyleList  EQU  2
fmDisplayStyleCombo  EQU  3
fmDisplayStyleCheckBox  EQU  4
fmDisplayStyleOptionButton  EQU  5
fmDisplayStyleToggle  EQU  6
fmDisplayStyleDropList  EQU  7

;--- fmShowListWhen, Type=ENUM, GUID={A4069F24-4221-11CE-8EA0-00AA004BA6AE}

fmShowListWhen typedef SDWORD
fmShowListWhenNever  EQU  0
fmShowListWhenButton  EQU  1
fmShowListWhenFocus  EQU  2
fmShowListWhenAlways  EQU  3

;--- fmShowDropButtonWhen, Type=ENUM, GUID={C5D98C41-4EB2-11CE-8EA0-00AA004BA6AE}

fmShowDropButtonWhen typedef SDWORD
fmShowDropButtonWhenNever  EQU  0
fmShowDropButtonWhenFocus  EQU  1
fmShowDropButtonWhenAlways  EQU  2

;--- fmMultiSelect, Type=ENUM, GUID={F00164C0-B17B-11CE-A95D-00AA006CB389}

fmMultiSelect typedef SDWORD
fmMultiSelectSingle  EQU  0
fmMultiSelectMulti  EQU  1
fmMultiSelectExtended  EQU  2

;--- fmListStyle, Type=ENUM, GUID={F00164C1-B17B-11CE-A95D-00AA006CB389}

fmListStyle typedef SDWORD
fmListStylePlain  EQU  0
fmListStyleOption  EQU  1

;--- fmEnterFieldBehavior, Type=ENUM, GUID={6A7167F1-2432-11CF-956F-00AA004B9DFA}

fmEnterFieldBehavior typedef SDWORD
fmEnterFieldBehaviorSelectAll  EQU  0
fmEnterFieldBehaviorRecallSelection  EQU  1

;--- fmDragBehavior, Type=ENUM, GUID={E25EB550-24F6-11CF-A6E2-00AA00C0098D}

fmDragBehavior typedef SDWORD
fmDragBehaviorDisabled  EQU  0
fmDragBehaviorEnabled  EQU  1

;--- fmMatchEntry, Type=ENUM, GUID={8CCD0AC2-B1AD-11CE-8276-00AA004BA6AE}

fmMatchEntry typedef SDWORD
fmMatchEntryFirstLetter  EQU  0
fmMatchEntryComplete  EQU  1
fmMatchEntryNone  EQU  2

;--- fmDropButtonStyle, Type=ENUM, GUID={14D122B0-C6E7-11CE-827C-00AA004BA6AE}

fmDropButtonStyle typedef SDWORD
fmDropButtonStylePlain  EQU  0
fmDropButtonStyleArrow  EQU  1
fmDropButtonStyleEllipsis  EQU  2
fmDropButtonStyleReduce  EQU  3

;--- fmStyle, Type=ENUM, GUID={9C37F9D0-FDE5-11CE-9560-00AA004B9DFA}

fmStyle typedef SDWORD
fmStyleDropDownCombo  EQU  0
fmStyleDropDownList  EQU  2

;--- fmTabOrientation, Type=ENUM, GUID={EBC7FDE1-6899-11CE-80C0-00AA00611080}

fmTabOrientation typedef SDWORD
fmTabOrientationTop  EQU  0
fmTabOrientationBottom  EQU  1
fmTabOrientationLeft  EQU  2
fmTabOrientationRight  EQU  3

;--- fmTabStyle, Type=ENUM, GUID={EBC7FDE3-6899-11CE-80C0-00AA00611080}

fmTabStyle typedef SDWORD
fmTabStyleTabs  EQU  0
fmTabStyleButtons  EQU  1
fmTabStyleNone  EQU  2

;--- fmIMEMode, Type=ENUM, GUID={4D067CD0-0D74-11CF-B474-00AA006EB734}

fmIMEMode typedef SDWORD
fmIMEModeNoControl  EQU  0
fmIMEModeOn  EQU  1
fmIMEModeOff  EQU  2
fmIMEModeDisable  EQU  3
fmIMEModeHiragana  EQU  4
fmIMEModeKatakana  EQU  5
fmIMEModeKatakanaHalf  EQU  6
fmIMEModeAlphaFull  EQU  7
fmIMEModeAlpha  EQU  8
fmIMEModeHangulFull  EQU  9
fmIMEModeHangul  EQU  10
fmIMEModeHanziFull  EQU  11
fmIMEModeHanzi  EQU  12

;--- fmTransitionEffect, Type=ENUM, GUID={0EE49F40-E956-11CE-8141-00AA00611080}

fmTransitionEffect typedef SDWORD
fmTransitionEffectNone  EQU  0
fmTransitionEffectCoverUp  EQU  1
fmTransitionEffectCoverRightUp  EQU  2
fmTransitionEffectCoverRight  EQU  3
fmTransitionEffectCoverRightDown  EQU  4
fmTransitionEffectCoverDown  EQU  5
fmTransitionEffectCoverLeftDown  EQU  6
fmTransitionEffectCoverLeft  EQU  7
fmTransitionEffectCoverLeftUp  EQU  8
fmTransitionEffectPushUp  EQU  9
fmTransitionEffectPushRight  EQU  10
fmTransitionEffectPushDown  EQU  11
fmTransitionEffectPushLeft  EQU  12

;--- fmListBoxStyles, Type=ENUM, GUID={F00164C2-B17B-11CE-A95D-00AA006CB389}

fmListBoxStyles typedef SDWORD
_fmListBoxStylesNone  EQU  0
_fmListBoxStylesListBox  EQU  1
_fmListBoxStylesComboBox  EQU  2

;--- fmRepeatDirection, Type=ENUM, GUID={C3689F20-C231-11CE-A30C-00AA004A3D3C}

fmRepeatDirection typedef SDWORD
_fmRepeatDirectionHorizontal  EQU  0
_fmRepeatDirectionVertical  EQU  1

;--- fmEnAutoSize, Type=ENUM, GUID={C3689F20-C231-11CE-A30C-00AA004A3D3D}

fmEnAutoSize typedef SDWORD
_fmEnAutoSizeNone  EQU  0
_fmEnAutoSizeHorizontal  EQU  1
_fmEnAutoSizeVertical  EQU  2
_fmEnAutoSizeBoth  EQU  3

;--- OLE_OPTEXCLUSIVE, Type=ALIAS, GUID={6650430B-BE0F-101A-8BBB-00AA00300CAB}

OLE_OPTEXCLUSIVE typedef BOOL

;--- OLE_COLOR, Type=ALIAS, GUID={66504301-BE0F-101A-8BBB-00AA00300CAB}

OLE_COLOR typedef SDWORD

;--- OLE_HANDLE, Type=ALIAS, GUID={66504313-BE0F-101A-8BBB-00AA00300CAB}

OLE_HANDLE typedef SDWORD

;--- PIROWSET, Type=ALIAS, GUID={0C733A52-2A1C-11CE-ADE5-00AA0044773D}

PIROWSET typedef LPUNKNOWN

;--- IReturnSingle, Type=INTERFACE, GUID={8A683C90-BA84-11CF-8110-00A0C9030074}

ifndef IReturnSingleVtbl
COM_INTERFACE_BEG IReturnSingle, IDispatch
  COM_STD_METHOD  put_Value  , :REAL4
  COM_STD_METHOD  get_Value  , :ptr REAL4
COM_INTERFACE_END
endif

sIID_IReturnSingle textequ <IID {08A683C90h,0BA84h,011CFh,{081h,010h,000h,0A0h,0C9h,003h,000h,074h}}>

;--- IReturnEffect, Type=INTERFACE, GUID={8A683C91-BA84-11CF-8110-00A0C9030074}

ifndef IReturnEffectVtbl
COM_INTERFACE_BEG IReturnEffect, IDispatch
  COM_STD_METHOD  put_Value  , :fmDropEffect
  COM_STD_METHOD  get_Value  , :ptr fmDropEffect
COM_INTERFACE_END
endif

sIID_IReturnEffect textequ <IID {08A683C91h,0BA84h,011CFh,{081h,010h,000h,0A0h,0C9h,003h,000h,074h}}>

;--- IFont, Type=INTERFACE, GUID={BEF6E002-A874-101A-8BBA-00AA00300CAB}

ifndef IFontVtbl
COM_INTERFACE_BEG IFont, IUnknown
  COM_STD_METHOD  get_Name  , :ptr BSTR
  COM_STD_METHOD  put_Name  , :BSTR
  COM_STD_METHOD  get_Size  , :ptr CY
  COM_STD_METHOD  put_Size  , :CY
  COM_STD_METHOD  get_Bold  , :ptr BOOL
  COM_STD_METHOD  put_Bold  , :BOOL
  COM_STD_METHOD  get_Italic  , :ptr BOOL
  COM_STD_METHOD  put_Italic  , :BOOL
  COM_STD_METHOD  get_Underline  , :ptr BOOL
  COM_STD_METHOD  put_Underline  , :BOOL
  COM_STD_METHOD  get_Strikethrough  , :ptr BOOL
  COM_STD_METHOD  put_Strikethrough  , :BOOL
  COM_STD_METHOD  get_Weight  , :ptr SWORD
  COM_STD_METHOD  put_Weight  , :SWORD
  COM_STD_METHOD  get_Charset  , :ptr SWORD
  COM_STD_METHOD  put_Charset  , :SWORD
  COM_STD_METHOD  get_hFont  , :ptr OLE_HANDLE
  COM_STD_METHOD  Clone  , :ptr ptr IFont
  COM_STD_METHOD  IsEqual  , :ptr IFont
  COM_STD_METHOD  SetRatio  , :SDWORD,:SDWORD
  COM_STD_METHOD  AddRefHfont  , :OLE_HANDLE
  COM_STD_METHOD  ReleaseHfont  , :OLE_HANDLE
COM_INTERFACE_END
endif

sIID_IFont textequ <IID {0BEF6E002h,0A874h,0101Ah,{08Bh,0BAh,000h,0AAh,000h,030h,00Ch,0ABh}}>

;--- IDataAutoWrapper, Type=INTERFACE, GUID={EC72F590-F375-11CE-B9E8-00AA006B1A69}

ifndef IDataAutoWrapperVtbl
COM_INTERFACE_BEG IDataAutoWrapper, IDispatch
  COM_STD_METHOD  Clear  
  COM_STD_METHOD  GetFormat  , :VARIANT,:ptr BOOL
  COM_STD_METHOD  GetText  , :VARIANT,:ptr BSTR
  COM_STD_METHOD  SetText  , :BSTR,:VARIANT
  COM_STD_METHOD  PutInClipboard  
  COM_STD_METHOD  GetFromClipboard  
  COM_STD_METHOD  StartDrag  , :VARIANT,:ptr fmDropEffect
COM_INTERFACE_END
endif

sIID_IDataAutoWrapper textequ <IID {0EC72F590h,0F375h,011CEh,{0B9h,0E8h,000h,0AAh,000h,06Bh,01Ah,069h}}>

;--- IReturnInteger, Type=INTERFACE, GUID={82B02370-B5BC-11CF-810F-00A0C9030074}

ifndef IReturnIntegerVtbl
COM_INTERFACE_BEG IReturnInteger, IDispatch
  COM_STD_METHOD  put_Value  , :SDWORD
  COM_STD_METHOD  get_Value  , :ptr SDWORD
COM_INTERFACE_END
endif

sIID_IReturnInteger textequ <IID {082B02370h,0B5BCh,011CFh,{081h,00Fh,000h,0A0h,0C9h,003h,000h,074h}}>

;--- IReturnBoolean, Type=INTERFACE, GUID={82B02371-B5BC-11CF-810F-00A0C9030074}

ifndef IReturnBooleanVtbl
COM_INTERFACE_BEG IReturnBoolean, IDispatch
  COM_STD_METHOD  put_Value  , :BOOL
  COM_STD_METHOD  get_Value  , :ptr BOOL
COM_INTERFACE_END
endif

sIID_IReturnBoolean textequ <IID {082B02371h,0B5BCh,011CFh,{081h,00Fh,000h,0A0h,0C9h,003h,000h,074h}}>

;--- ILabelControl, Type=INTERFACE, GUID={04598FC1-866C-11CF-AB7C-00AA00C08FCF}

ifndef ILabelControlVtbl
COM_INTERFACE_BEG ILabelControl, IDispatch
  COM_STD_METHOD  put_AutoSize  , :BOOL
  COM_STD_METHOD  get_AutoSize  , :ptr BOOL
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BackStyle  , :fmBackStyle
  COM_STD_METHOD  get_BackStyle  , :ptr fmBackStyle
  COM_STD_METHOD  put_BorderColor  , :OLE_COLOR
  COM_STD_METHOD  get_BorderColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BorderStyle  , :fmBorderStyle
  COM_STD_METHOD  get_BorderStyle  , :ptr fmBorderStyle
  COM_STD_METHOD  put_Caption  , :BSTR
  COM_STD_METHOD  get_Caption  , :ptr BSTR
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_FontItalic  , :BOOL
  COM_STD_METHOD  get_FontItalic  , :ptr BOOL
  COM_STD_METHOD  put_FontBold  , :BOOL
  COM_STD_METHOD  get_FontBold  , :ptr BOOL
  COM_STD_METHOD  put_FontName  , :BSTR
  COM_STD_METHOD  get_FontName  , :ptr BSTR
  COM_STD_METHOD  put_FontSize  , :CY
  COM_STD_METHOD  get_FontSize  , :ptr CY
  COM_STD_METHOD  put_FontStrikethru  , :BOOL
  COM_STD_METHOD  get_FontStrikethru  , :ptr BOOL
  COM_STD_METHOD  put_FontUnderline  , :BOOL
  COM_STD_METHOD  get_FontUnderline  , :ptr BOOL
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_Picture  , :ptr Picture
  COM_STD_METHOD  putref_Picture  , :ptr Picture
  COM_STD_METHOD  get_Picture  , :ptr ptr Picture
  COM_STD_METHOD  put_PicturePosition  , :fmPicturePosition
  COM_STD_METHOD  get_PicturePosition  , :ptr fmPicturePosition
  COM_STD_METHOD  put_SpecialEffect  , :fmSpecialEffect
  COM_STD_METHOD  get_SpecialEffect  , :ptr fmSpecialEffect
  COM_STD_METHOD  put_TextAlign  , :fmTextAlign
  COM_STD_METHOD  get_TextAlign  , :ptr fmTextAlign
  COM_STD_METHOD  put_WordWrap  , :BOOL
  COM_STD_METHOD  get_WordWrap  , :ptr BOOL
  COM_STD_METHOD  put_Accelerator  , :BSTR
  COM_STD_METHOD  get_Accelerator  , :ptr BSTR
  COM_STD_METHOD  put_FontWeight  , :SWORD
  COM_STD_METHOD  get_FontWeight  , :ptr SWORD
  COM_STD_METHOD  put__Value  , :BSTR
  COM_STD_METHOD  get__Value  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_ILabelControl textequ <IID {004598FC1h,0866Ch,011CFh,{0ABh,07Ch,000h,0AAh,000h,0C0h,08Fh,0CFh}}>

;--- ICommandButton, Type=INTERFACE, GUID={04598FC4-866C-11CF-AB7C-00AA00C08FCF}

ifndef ICommandButtonVtbl
COM_INTERFACE_BEG ICommandButton, IDispatch
  COM_STD_METHOD  put_AutoSize  , :BOOL
  COM_STD_METHOD  get_AutoSize  , :ptr BOOL
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BackStyle  , :fmBackStyle
  COM_STD_METHOD  get_BackStyle  , :ptr fmBackStyle
  COM_STD_METHOD  put_Caption  , :BSTR
  COM_STD_METHOD  get_Caption  , :ptr BSTR
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_FontBold  , :BOOL
  COM_STD_METHOD  get_FontBold  , :ptr BOOL
  COM_STD_METHOD  put_FontItalic  , :BOOL
  COM_STD_METHOD  get_FontItalic  , :ptr BOOL
  COM_STD_METHOD  put_FontName  , :BSTR
  COM_STD_METHOD  get_FontName  , :ptr BSTR
  COM_STD_METHOD  put_FontSize  , :CY
  COM_STD_METHOD  get_FontSize  , :ptr CY
  COM_STD_METHOD  put_FontStrikethru  , :BOOL
  COM_STD_METHOD  get_FontStrikethru  , :ptr BOOL
  COM_STD_METHOD  put_FontUnderline  , :BOOL
  COM_STD_METHOD  get_FontUnderline  , :ptr BOOL
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_TakeFocusOnClick  , :BOOL
  COM_STD_METHOD  get_TakeFocusOnClick  , :ptr BOOL
  COM_STD_METHOD  put_Locked  , :BOOL
  COM_STD_METHOD  get_Locked  , :ptr BOOL
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_Picture  , :ptr Picture
  COM_STD_METHOD  putref_Picture  , :ptr Picture
  COM_STD_METHOD  get_Picture  , :ptr ptr Picture
  COM_STD_METHOD  put_PicturePosition  , :fmPicturePosition
  COM_STD_METHOD  get_PicturePosition  , :ptr fmPicturePosition
  COM_STD_METHOD  put_Accelerator  , :BSTR
  COM_STD_METHOD  get_Accelerator  , :ptr BSTR
  COM_STD_METHOD  put_WordWrap  , :BOOL
  COM_STD_METHOD  get_WordWrap  , :ptr BOOL
  COM_STD_METHOD  put_Value  , :BOOL
  COM_STD_METHOD  get_Value  , :ptr BOOL
  COM_STD_METHOD  put_FontWeight  , :SWORD
  COM_STD_METHOD  get_FontWeight  , :ptr SWORD
COM_INTERFACE_END
endif

sIID_ICommandButton textequ <IID {004598FC4h,0866Ch,011CFh,{0ABh,07Ch,000h,0AAh,000h,0C0h,08Fh,0CFh}}>

;--- IReturnString, Type=INTERFACE, GUID={82B02372-B5BC-11CF-810F-00A0C9030074}

ifndef IReturnStringVtbl
COM_INTERFACE_BEG IReturnString, IDispatch
  COM_STD_METHOD  put_Value  , :BSTR
  COM_STD_METHOD  get_Value  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IReturnString textequ <IID {082B02372h,0B5BCh,011CFh,{081h,00Fh,000h,0A0h,0C9h,003h,000h,074h}}>

;--- IMdcText, Type=INTERFACE, GUID={8BD21D13-EC42-11CE-9E0D-00AA006002F3}

ifndef IMdcTextVtbl
COM_INTERFACE_BEG IMdcText, IDispatch
  COM_STD_METHOD  put_AutoSize  , :BOOL
  COM_STD_METHOD  get_AutoSize  , :ptr BOOL
  COM_STD_METHOD  put_AutoTab  , :BOOL
  COM_STD_METHOD  get_AutoTab  , :ptr BOOL
  COM_STD_METHOD  put_AutoWordSelect  , :BOOL
  COM_STD_METHOD  get_AutoWordSelect  , :ptr BOOL
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BackStyle  , :fmBackStyle
  COM_STD_METHOD  get_BackStyle  , :ptr fmBackStyle
  COM_STD_METHOD  put_BorderColor  , :OLE_COLOR
  COM_STD_METHOD  get_BorderColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BorderStyle  , :fmBorderStyle
  COM_STD_METHOD  get_BorderStyle  , :ptr fmBorderStyle
  COM_STD_METHOD  put_BordersSuppress  , :BOOL
  COM_STD_METHOD  get_BordersSuppress  , :ptr BOOL
  COM_STD_METHOD  get_CanPaste  , :ptr BOOL
  COM_STD_METHOD  put_CurLine  , :SDWORD
  COM_STD_METHOD  get_CurLine  , :ptr SDWORD
  COM_STD_METHOD  get_CurTargetX  , :ptr SDWORD
  COM_STD_METHOD  get_CurTargetY  , :ptr SDWORD
  COM_STD_METHOD  put_CurX  , :SDWORD
  COM_STD_METHOD  get_CurX  , :ptr SDWORD
  COM_STD_METHOD  put_CurY  , :SDWORD
  COM_STD_METHOD  get_CurY  , :ptr SDWORD
  COM_STD_METHOD  put_DropButtonStyle  , :fmDropButtonStyle
  COM_STD_METHOD  get_DropButtonStyle  , :ptr fmDropButtonStyle
  COM_STD_METHOD  put_EnterKeyBehavior  , :BOOL
  COM_STD_METHOD  get_EnterKeyBehavior  , :ptr BOOL
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_FontBold  , :BOOL
  COM_STD_METHOD  get_FontBold  , :ptr BOOL
  COM_STD_METHOD  put_FontItalic  , :BOOL
  COM_STD_METHOD  get_FontItalic  , :ptr BOOL
  COM_STD_METHOD  put_FontName  , :BSTR
  COM_STD_METHOD  get_FontName  , :ptr BSTR
  COM_STD_METHOD  put_FontSize  , :CY
  COM_STD_METHOD  get_FontSize  , :ptr CY
  COM_STD_METHOD  put_FontStrikethru  , :BOOL
  COM_STD_METHOD  get_FontStrikethru  , :ptr BOOL
  COM_STD_METHOD  put_FontUnderline  , :BOOL
  COM_STD_METHOD  get_FontUnderline  , :ptr BOOL
  COM_STD_METHOD  put_FontWeight  , :SWORD
  COM_STD_METHOD  get_FontWeight  , :ptr SWORD
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_HideSelection  , :BOOL
  COM_STD_METHOD  get_HideSelection  , :ptr BOOL
  COM_STD_METHOD  put_IntegralHeight  , :BOOL
  COM_STD_METHOD  get_IntegralHeight  , :ptr BOOL
  COM_STD_METHOD  get_LineCount  , :ptr SDWORD
  COM_STD_METHOD  put_Locked  , :BOOL
  COM_STD_METHOD  get_Locked  , :ptr BOOL
  COM_STD_METHOD  put_MaxLength  , :SDWORD
  COM_STD_METHOD  get_MaxLength  , :ptr SDWORD
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_MultiLine  , :BOOL
  COM_STD_METHOD  get_MultiLine  , :ptr BOOL
  COM_STD_METHOD  put_PasswordChar  , :BSTR
  COM_STD_METHOD  get_PasswordChar  , :ptr BSTR
  COM_STD_METHOD  put_ScrollBars  , :fmScrollBars
  COM_STD_METHOD  get_ScrollBars  , :ptr fmScrollBars
  COM_STD_METHOD  put_SelectionMargin  , :BOOL
  COM_STD_METHOD  get_SelectionMargin  , :ptr BOOL
  COM_STD_METHOD  put_SelLength  , :SDWORD
  COM_STD_METHOD  get_SelLength  , :ptr SDWORD
  COM_STD_METHOD  put_SelStart  , :SDWORD
  COM_STD_METHOD  get_SelStart  , :ptr SDWORD
  COM_STD_METHOD  put_SelText  , :BSTR
  COM_STD_METHOD  get_SelText  , :ptr BSTR
  COM_STD_METHOD  put_ShowDropButtonWhen  , :fmShowDropButtonWhen
  COM_STD_METHOD  get_ShowDropButtonWhen  , :ptr fmShowDropButtonWhen
  COM_STD_METHOD  put_SpecialEffect  , :fmSpecialEffect
  COM_STD_METHOD  get_SpecialEffect  , :ptr fmSpecialEffect
  COM_STD_METHOD  put_TabKeyBehavior  , :BOOL
  COM_STD_METHOD  get_TabKeyBehavior  , :ptr BOOL
  COM_STD_METHOD  put_Text  , :BSTR
  COM_STD_METHOD  get_Text  , :ptr BSTR
  COM_STD_METHOD  put_TextAlign  , :fmTextAlign
  COM_STD_METHOD  get_TextAlign  , :ptr fmTextAlign
  COM_STD_METHOD  get_TextLength  , :ptr SDWORD
  COM_STD_METHOD  get_Valid  , :ptr BOOL
  COM_STD_METHOD  put_Value  , :ptr VARIANT
  COM_STD_METHOD  get_Value  , :ptr VARIANT
  COM_STD_METHOD  put_WordWrap  , :BOOL
  COM_STD_METHOD  get_WordWrap  , :ptr BOOL
  COM_STD_METHOD  Copy  
  COM_STD_METHOD  Cut  
  COM_STD_METHOD  Paste  
  COM_STD_METHOD  put_IMEMode  , :fmIMEMode
  COM_STD_METHOD  get_IMEMode  , :ptr fmIMEMode
  COM_STD_METHOD  put_EnterFieldBehavior  , :fmEnterFieldBehavior
  COM_STD_METHOD  get_EnterFieldBehavior  , :ptr fmEnterFieldBehavior
  COM_STD_METHOD  put_DragBehavior  , :fmDragBehavior
  COM_STD_METHOD  get_DragBehavior  , :ptr fmDragBehavior
  COM_STD_METHOD  get_DisplayStyle  , :ptr fmDisplayStyle
COM_INTERFACE_END
endif

sIID_IMdcText textequ <IID {08BD21D13h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- IMdcList, Type=INTERFACE, GUID={8BD21D23-EC42-11CE-9E0D-00AA006002F3}

ifndef IMdcListVtbl
COM_INTERFACE_BEG IMdcList, IDispatch
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BorderColor  , :OLE_COLOR
  COM_STD_METHOD  get_BorderColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BorderStyle  , :fmBorderStyle
  COM_STD_METHOD  get_BorderStyle  , :ptr fmBorderStyle
  COM_STD_METHOD  put_BordersSuppress  , :BOOL
  COM_STD_METHOD  get_BordersSuppress  , :ptr BOOL
  COM_STD_METHOD  put_BoundColumn  , :ptr VARIANT
  COM_STD_METHOD  get_BoundColumn  , :ptr VARIANT
  COM_STD_METHOD  put_ColumnCount  , :SDWORD
  COM_STD_METHOD  get_ColumnCount  , :ptr SDWORD
  COM_STD_METHOD  put_ColumnHeads  , :BOOL
  COM_STD_METHOD  get_ColumnHeads  , :ptr BOOL
  COM_STD_METHOD  put_ColumnWidths  , :BSTR
  COM_STD_METHOD  get_ColumnWidths  , :ptr BSTR
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_FontBold  , :BOOL
  COM_STD_METHOD  get_FontBold  , :ptr BOOL
  COM_STD_METHOD  put_FontItalic  , :BOOL
  COM_STD_METHOD  get_FontItalic  , :ptr BOOL
  COM_STD_METHOD  put_FontName  , :BSTR
  COM_STD_METHOD  get_FontName  , :ptr BSTR
  COM_STD_METHOD  put_FontSize  , :CY
  COM_STD_METHOD  get_FontSize  , :ptr CY
  COM_STD_METHOD  put_FontStrikethru  , :BOOL
  COM_STD_METHOD  get_FontStrikethru  , :ptr BOOL
  COM_STD_METHOD  put_FontUnderline  , :BOOL
  COM_STD_METHOD  get_FontUnderline  , :ptr BOOL
  COM_STD_METHOD  put_FontWeight  , :SWORD
  COM_STD_METHOD  get_FontWeight  , :ptr SWORD
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_IntegralHeight  , :BOOL
  COM_STD_METHOD  get_IntegralHeight  , :ptr BOOL
  COM_STD_METHOD  get_ListCount  , :ptr SDWORD
  COM_STD_METHOD  put_ListCursor  , :PIROWSET
  COM_STD_METHOD  get_ListCursor  , :ptr PIROWSET
  COM_STD_METHOD  put_ListIndex  , :ptr VARIANT
  COM_STD_METHOD  get_ListIndex  , :ptr VARIANT
  COM_STD_METHOD  put_ListStyle  , :fmListStyle
  COM_STD_METHOD  get_ListStyle  , :ptr fmListStyle
  COM_STD_METHOD  put_ListWidth  , :ptr VARIANT
  COM_STD_METHOD  get_ListWidth  , :ptr VARIANT
  COM_STD_METHOD  put_Locked  , :BOOL
  COM_STD_METHOD  get_Locked  , :ptr BOOL
  COM_STD_METHOD  put_MatchEntry  , :fmMatchEntry
  COM_STD_METHOD  get_MatchEntry  , :ptr fmMatchEntry
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_MultiSelect  , :fmMultiSelect
  COM_STD_METHOD  get_MultiSelect  , :ptr fmMultiSelect
  COM_STD_METHOD  put_SpecialEffect  , :fmSpecialEffect
  COM_STD_METHOD  get_SpecialEffect  , :ptr fmSpecialEffect
  COM_STD_METHOD  put_Text  , :BSTR
  COM_STD_METHOD  get_Text  , :ptr BSTR
  COM_STD_METHOD  put_TextColumn  , :ptr VARIANT
  COM_STD_METHOD  get_TextColumn  , :ptr VARIANT
  COM_STD_METHOD  put_TopIndex  , :ptr VARIANT
  COM_STD_METHOD  get_TopIndex  , :ptr VARIANT
  COM_STD_METHOD  get_Valid  , :ptr BOOL
  COM_STD_METHOD  put_Value  , :ptr VARIANT
  COM_STD_METHOD  get_Value  , :ptr VARIANT
  COM_STD_METHOD  get_Column  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  put_Column  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  get_List  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  put_List  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  get_Selected  , :ptr VARIANT,:ptr BOOL
  COM_STD_METHOD  put_Selected  , :ptr VARIANT,:BOOL
  COM_STD_METHOD  AddItem  , :ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  Clear  
  COM_STD_METHOD  RemoveItem  , :ptr VARIANT
  COM_STD_METHOD  put_IMEMode  , :fmIMEMode
  COM_STD_METHOD  get_IMEMode  , :ptr fmIMEMode
  COM_STD_METHOD  get_DisplayStyle  , :ptr fmDisplayStyle
  COM_STD_METHOD  put_TextAlign  , :fmTextAlign
  COM_STD_METHOD  get_TextAlign  , :ptr fmTextAlign
COM_INTERFACE_END
endif

sIID_IMdcList textequ <IID {08BD21D23h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- IMdcCombo, Type=INTERFACE, GUID={8BD21D33-EC42-11CE-9E0D-00AA006002F3}

ifndef IMdcComboVtbl
COM_INTERFACE_BEG IMdcCombo, IDispatch
  COM_STD_METHOD  put_AutoSize  , :BOOL
  COM_STD_METHOD  get_AutoSize  , :ptr BOOL
  COM_STD_METHOD  put_AutoTab  , :BOOL
  COM_STD_METHOD  get_AutoTab  , :ptr BOOL
  COM_STD_METHOD  put_AutoWordSelect  , :BOOL
  COM_STD_METHOD  get_AutoWordSelect  , :ptr BOOL
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BackStyle  , :fmBackStyle
  COM_STD_METHOD  get_BackStyle  , :ptr fmBackStyle
  COM_STD_METHOD  put_BorderColor  , :OLE_COLOR
  COM_STD_METHOD  get_BorderColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BorderStyle  , :fmBorderStyle
  COM_STD_METHOD  get_BorderStyle  , :ptr fmBorderStyle
  COM_STD_METHOD  put_BordersSuppress  , :BOOL
  COM_STD_METHOD  get_BordersSuppress  , :ptr BOOL
  COM_STD_METHOD  put_BoundColumn  , :ptr VARIANT
  COM_STD_METHOD  get_BoundColumn  , :ptr VARIANT
  COM_STD_METHOD  get_CanPaste  , :ptr BOOL
  COM_STD_METHOD  put_ColumnCount  , :SDWORD
  COM_STD_METHOD  get_ColumnCount  , :ptr SDWORD
  COM_STD_METHOD  put_ColumnHeads  , :BOOL
  COM_STD_METHOD  get_ColumnHeads  , :ptr BOOL
  COM_STD_METHOD  put_ColumnWidths  , :BSTR
  COM_STD_METHOD  get_ColumnWidths  , :ptr BSTR
  COM_STD_METHOD  get_CurTargetX  , :ptr SDWORD
  COM_STD_METHOD  get_CurTargetY  , :ptr SDWORD
  COM_STD_METHOD  put_CurX  , :SDWORD
  COM_STD_METHOD  get_CurX  , :ptr SDWORD
  COM_STD_METHOD  put_DropButtonStyle  , :fmDropButtonStyle
  COM_STD_METHOD  get_DropButtonStyle  , :ptr fmDropButtonStyle
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_FontBold  , :BOOL
  COM_STD_METHOD  get_FontBold  , :ptr BOOL
  COM_STD_METHOD  put_FontItalic  , :BOOL
  COM_STD_METHOD  get_FontItalic  , :ptr BOOL
  COM_STD_METHOD  put_FontName  , :BSTR
  COM_STD_METHOD  get_FontName  , :ptr BSTR
  COM_STD_METHOD  put_FontSize  , :CY
  COM_STD_METHOD  get_FontSize  , :ptr CY
  COM_STD_METHOD  put_FontStrikethru  , :BOOL
  COM_STD_METHOD  get_FontStrikethru  , :ptr BOOL
  COM_STD_METHOD  put_FontUnderline  , :BOOL
  COM_STD_METHOD  get_FontUnderline  , :ptr BOOL
  COM_STD_METHOD  put_FontWeight  , :SWORD
  COM_STD_METHOD  get_FontWeight  , :ptr SWORD
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_HideSelection  , :BOOL
  COM_STD_METHOD  get_HideSelection  , :ptr BOOL
  COM_STD_METHOD  get_LineCount  , :ptr SDWORD
  COM_STD_METHOD  get_ListCount  , :ptr SDWORD
  COM_STD_METHOD  put_ListCursor  , :PIROWSET
  COM_STD_METHOD  get_ListCursor  , :ptr PIROWSET
  COM_STD_METHOD  put_ListIndex  , :ptr VARIANT
  COM_STD_METHOD  get_ListIndex  , :ptr VARIANT
  COM_STD_METHOD  put_ListRows  , :SDWORD
  COM_STD_METHOD  get_ListRows  , :ptr SDWORD
  COM_STD_METHOD  put_ListStyle  , :fmListStyle
  COM_STD_METHOD  get_ListStyle  , :ptr fmListStyle
  COM_STD_METHOD  put_ListWidth  , :ptr VARIANT
  COM_STD_METHOD  get_ListWidth  , :ptr VARIANT
  COM_STD_METHOD  put_Locked  , :BOOL
  COM_STD_METHOD  get_Locked  , :ptr BOOL
  COM_STD_METHOD  put_MatchEntry  , :fmMatchEntry
  COM_STD_METHOD  get_MatchEntry  , :ptr fmMatchEntry
  COM_STD_METHOD  get_MatchFound  , :ptr BOOL
  COM_STD_METHOD  put_MatchRequired  , :BOOL
  COM_STD_METHOD  get_MatchRequired  , :ptr BOOL
  COM_STD_METHOD  put_MaxLength  , :SDWORD
  COM_STD_METHOD  get_MaxLength  , :ptr SDWORD
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_SelectionMargin  , :BOOL
  COM_STD_METHOD  get_SelectionMargin  , :ptr BOOL
  COM_STD_METHOD  put_SelLength  , :SDWORD
  COM_STD_METHOD  get_SelLength  , :ptr SDWORD
  COM_STD_METHOD  put_SelStart  , :SDWORD
  COM_STD_METHOD  get_SelStart  , :ptr SDWORD
  COM_STD_METHOD  put_SelText  , :BSTR
  COM_STD_METHOD  get_SelText  , :ptr BSTR
  COM_STD_METHOD  put_ShowDropButtonWhen  , :fmShowDropButtonWhen
  COM_STD_METHOD  get_ShowDropButtonWhen  , :ptr fmShowDropButtonWhen
  COM_STD_METHOD  put_SpecialEffect  , :fmSpecialEffect
  COM_STD_METHOD  get_SpecialEffect  , :ptr fmSpecialEffect
  COM_STD_METHOD  put_Style  , :fmStyle
  COM_STD_METHOD  get_Style  , :ptr fmStyle
  COM_STD_METHOD  put_Text  , :BSTR
  COM_STD_METHOD  get_Text  , :ptr BSTR
  COM_STD_METHOD  put_TextAlign  , :fmTextAlign
  COM_STD_METHOD  get_TextAlign  , :ptr fmTextAlign
  COM_STD_METHOD  put_TextColumn  , :ptr VARIANT
  COM_STD_METHOD  get_TextColumn  , :ptr VARIANT
  COM_STD_METHOD  get_TextLength  , :ptr SDWORD
  COM_STD_METHOD  put_TopIndex  , :ptr VARIANT
  COM_STD_METHOD  get_TopIndex  , :ptr VARIANT
  COM_STD_METHOD  get_Valid  , :ptr BOOL
  COM_STD_METHOD  put_Value  , :ptr VARIANT
  COM_STD_METHOD  get_Value  , :ptr VARIANT
  COM_STD_METHOD  get_Column  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  put_Column  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  get_List  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  put_List  , :ptr VARIANT,:ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  AddItem  , :ptr VARIANT,:ptr VARIANT
  COM_STD_METHOD  Clear  
  COM_STD_METHOD  DropDown  
  COM_STD_METHOD  RemoveItem  , :ptr VARIANT
  COM_STD_METHOD  Copy  
  COM_STD_METHOD  Cut  
  COM_STD_METHOD  Paste  
  COM_STD_METHOD  put_IMEMode  , :fmIMEMode
  COM_STD_METHOD  get_IMEMode  , :ptr fmIMEMode
  COM_STD_METHOD  put_EnterFieldBehavior  , :fmEnterFieldBehavior
  COM_STD_METHOD  get_EnterFieldBehavior  , :ptr fmEnterFieldBehavior
  COM_STD_METHOD  put_DragBehavior  , :fmDragBehavior
  COM_STD_METHOD  get_DragBehavior  , :ptr fmDragBehavior
  COM_STD_METHOD  get_DisplayStyle  , :ptr fmDisplayStyle
COM_INTERFACE_END
endif

sIID_IMdcCombo textequ <IID {08BD21D33h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- IMdcCheckBox, Type=INTERFACE, GUID={8BD21D43-EC42-11CE-9E0D-00AA006002F3}

ifndef IMdcCheckBoxVtbl
COM_INTERFACE_BEG IMdcCheckBox, IDispatch
  COM_STD_METHOD  put_Accelerator  , :BSTR
  COM_STD_METHOD  get_Accelerator  , :ptr BSTR
  COM_STD_METHOD  put_Alignment  , :fmAlignment
  COM_STD_METHOD  get_Alignment  , :ptr fmAlignment
  COM_STD_METHOD  put_AutoSize  , :BOOL
  COM_STD_METHOD  get_AutoSize  , :ptr BOOL
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BackStyle  , :fmBackStyle
  COM_STD_METHOD  get_BackStyle  , :ptr fmBackStyle
  COM_STD_METHOD  put_BordersSuppress  , :BOOL
  COM_STD_METHOD  get_BordersSuppress  , :ptr BOOL
  COM_STD_METHOD  put_Caption  , :BSTR
  COM_STD_METHOD  get_Caption  , :ptr BSTR
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_FontBold  , :BOOL
  COM_STD_METHOD  get_FontBold  , :ptr BOOL
  COM_STD_METHOD  put_FontItalic  , :BOOL
  COM_STD_METHOD  get_FontItalic  , :ptr BOOL
  COM_STD_METHOD  put_FontName  , :BSTR
  COM_STD_METHOD  get_FontName  , :ptr BSTR
  COM_STD_METHOD  put_FontSize  , :CY
  COM_STD_METHOD  get_FontSize  , :ptr CY
  COM_STD_METHOD  put_FontStrikethru  , :BOOL
  COM_STD_METHOD  get_FontStrikethru  , :ptr BOOL
  COM_STD_METHOD  put_FontUnderline  , :BOOL
  COM_STD_METHOD  get_FontUnderline  , :ptr BOOL
  COM_STD_METHOD  put_FontWeight  , :SWORD
  COM_STD_METHOD  get_FontWeight  , :ptr SWORD
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_Locked  , :BOOL
  COM_STD_METHOD  get_Locked  , :ptr BOOL
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_MultiSelect  , :fmMultiSelect
  COM_STD_METHOD  get_MultiSelect  , :ptr fmMultiSelect
  COM_STD_METHOD  put_Picture  , :ptr Picture
  COM_STD_METHOD  putref_Picture  , :ptr Picture
  COM_STD_METHOD  get_Picture  , :ptr ptr Picture
  COM_STD_METHOD  put_PicturePosition  , :fmPicturePosition
  COM_STD_METHOD  get_PicturePosition  , :ptr fmPicturePosition
  COM_STD_METHOD  put_SpecialEffect  , :fmButtonEffect
  COM_STD_METHOD  get_SpecialEffect  , :ptr fmButtonEffect
  COM_STD_METHOD  put_TripleState  , :BOOL
  COM_STD_METHOD  get_TripleState  , :ptr BOOL
  COM_STD_METHOD  get_Valid  , :ptr BOOL
  COM_STD_METHOD  put_Value  , :ptr VARIANT
  COM_STD_METHOD  get_Value  , :ptr VARIANT
  COM_STD_METHOD  put_WordWrap  , :BOOL
  COM_STD_METHOD  get_WordWrap  , :ptr BOOL
  COM_STD_METHOD  get_DisplayStyle  , :ptr fmDisplayStyle
  COM_STD_METHOD  put_GroupName  , :BSTR
  COM_STD_METHOD  get_GroupName  , :ptr BSTR
  COM_STD_METHOD  put_TextAlign  , :fmTextAlign
  COM_STD_METHOD  get_TextAlign  , :ptr fmTextAlign
COM_INTERFACE_END
endif

sIID_IMdcCheckBox textequ <IID {08BD21D43h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- IMdcOptionButton, Type=INTERFACE, GUID={8BD21D53-EC42-11CE-9E0D-00AA006002F3}

ifndef IMdcOptionButtonVtbl
COM_INTERFACE_BEG IMdcOptionButton, IMdcCheckBox
COM_INTERFACE_END
endif

sIID_IMdcOptionButton textequ <IID {08BD21D53h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- IMdcToggleButton, Type=INTERFACE, GUID={8BD21D63-EC42-11CE-9E0D-00AA006002F3}

ifndef IMdcToggleButtonVtbl
COM_INTERFACE_BEG IMdcToggleButton, IMdcCheckBox
COM_INTERFACE_END
endif

sIID_IMdcToggleButton textequ <IID {08BD21D63h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- IScrollbar, Type=INTERFACE, GUID={04598FC3-866C-11CF-AB7C-00AA00C08FCF}

ifndef IScrollbarVtbl
COM_INTERFACE_BEG IScrollbar, IDispatch
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_Value  , :SDWORD
  COM_STD_METHOD  get_Value  , :ptr SDWORD
  COM_STD_METHOD  put_Min  , :SDWORD
  COM_STD_METHOD  get_Min  , :ptr SDWORD
  COM_STD_METHOD  put_Max  , :SDWORD
  COM_STD_METHOD  get_Max  , :ptr SDWORD
  COM_STD_METHOD  put_SmallChange  , :SDWORD
  COM_STD_METHOD  get_SmallChange  , :ptr SDWORD
  COM_STD_METHOD  put_LargeChange  , :SDWORD
  COM_STD_METHOD  get_LargeChange  , :ptr SDWORD
  COM_STD_METHOD  put_ProportionalThumb  , :BOOL
  COM_STD_METHOD  get_ProportionalThumb  , :ptr BOOL
  COM_STD_METHOD  put_Orientation  , :fmOrientation
  COM_STD_METHOD  get_Orientation  , :ptr fmOrientation
  COM_STD_METHOD  put_Delay  , :SDWORD
  COM_STD_METHOD  get_Delay  , :ptr SDWORD
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
COM_INTERFACE_END
endif

sIID_IScrollbar textequ <IID {004598FC3h,0866Ch,011CFh,{0ABh,07Ch,000h,0AAh,000h,0C0h,08Fh,0CFh}}>

;--- Tab, Type=INTERFACE, GUID={A38BFFC3-A5A0-11CE-8107-00AA00611080}

ifndef TabVtbl
COM_INTERFACE_BEG Tab, IDispatch
  COM_STD_METHOD  put_Caption  , :BSTR
  COM_STD_METHOD  get_Caption  , :ptr BSTR
  COM_STD_METHOD  put_ControlTipText  , :BSTR
  COM_STD_METHOD  get_ControlTipText  , :ptr BSTR
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put_Index  , :SDWORD
  COM_STD_METHOD  get_Index  , :ptr SDWORD
  COM_STD_METHOD  put_Name  , :BSTR
  COM_STD_METHOD  get_Name  , :ptr BSTR
  COM_STD_METHOD  put_Tag  , :BSTR
  COM_STD_METHOD  get_Tag  , :ptr BSTR
  COM_STD_METHOD  put_Visible  , :BOOL
  COM_STD_METHOD  get_Visible  , :ptr BOOL
  COM_STD_METHOD  put_Accelerator  , :BSTR
  COM_STD_METHOD  get_Accelerator  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_Tab textequ <IID {0A38BFFC3h,0A5A0h,011CEh,{081h,007h,000h,0AAh,000h,061h,010h,080h}}>

;--- Tabs, Type=INTERFACE, GUID={944ACF93-A1E6-11CE-8104-00AA00611080}

ifndef TabsVtbl
COM_INTERFACE_BEG Tabs, IDispatch
  COM_STD_METHOD  get_Count  , :ptr SDWORD
  COM_STD_METHOD  get__NewEnum  , :ptr LPUNKNOWN
  COM_STD_METHOD  _GetItemByIndex  , :SDWORD,:ptr ptr Tab
  COM_STD_METHOD  _GetItemByName  , :BSTR,:ptr ptr Tab
  COM_STD_METHOD  Item  , :VARIANT,:ptr LPDISPATCH
  COM_STD_METHOD  Enum  , :ptr LPUNKNOWN
  COM_STD_METHOD  Add_  , :VARIANT,:VARIANT,:VARIANT,:ptr ptr Tab
  COM_STD_METHOD  _Add  , :BSTR,:BSTR,:ptr ptr Tab
  COM_STD_METHOD  _Insert  , :BSTR,:BSTR,:SDWORD,:ptr ptr Tab
  COM_STD_METHOD  Remove  , :VARIANT
  COM_STD_METHOD  Clear  
COM_INTERFACE_END
endif

sIID_Tabs textequ <IID {0944ACF93h,0A1E6h,011CEh,{081h,004h,000h,0AAh,000h,061h,010h,080h}}>

;--- ITabStrip, Type=INTERFACE, GUID={04598FC2-866C-11CF-AB7C-00AA00C08FCF}

ifndef ITabStripVtbl
COM_INTERFACE_BEG ITabStrip, IDispatch
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_FontName  , :BSTR
  COM_STD_METHOD  get_FontName  , :ptr BSTR
  COM_STD_METHOD  put_FontBold  , :BOOL
  COM_STD_METHOD  get_FontBold  , :ptr BOOL
  COM_STD_METHOD  put_FontItalic  , :BOOL
  COM_STD_METHOD  get_FontItalic  , :ptr BOOL
  COM_STD_METHOD  put_FontUnderline  , :BOOL
  COM_STD_METHOD  get_FontUnderline  , :ptr BOOL
  COM_STD_METHOD  put_FontStrikethru  , :BOOL
  COM_STD_METHOD  get_FontStrikethru  , :ptr BOOL
  COM_STD_METHOD  put_FontSize  , :CY
  COM_STD_METHOD  get_FontSize  , :ptr CY
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_MultiRow  , :BOOL
  COM_STD_METHOD  get_MultiRow  , :ptr BOOL
  COM_STD_METHOD  put_Style  , :fmTabStyle
  COM_STD_METHOD  get_Style  , :ptr fmTabStyle
  COM_STD_METHOD  put_TabOrientation  , :fmTabOrientation
  COM_STD_METHOD  get_TabOrientation  , :ptr fmTabOrientation
  COM_STD_METHOD  _SetTabFixedWidth  , :SDWORD
  COM_STD_METHOD  _GetTabFixedWidth  , :ptr SDWORD
  COM_STD_METHOD  _SetTabFixedHeight  , :SDWORD
  COM_STD_METHOD  _GetTabFixedHeight  , :ptr SDWORD
  COM_STD_METHOD  _GetClientTop  , :ptr SDWORD
  COM_STD_METHOD  get_ClientTop  , :ptr REAL4
  COM_STD_METHOD  _GetClientLeft  , :ptr SDWORD
  COM_STD_METHOD  get_ClientLeft  , :ptr REAL4
  COM_STD_METHOD  _GetClientWidth  , :ptr SDWORD
  COM_STD_METHOD  get_ClientWidth  , :ptr REAL4
  COM_STD_METHOD  _GetClientHeight  , :ptr SDWORD
  COM_STD_METHOD  get_ClientHeight  , :ptr REAL4
  COM_STD_METHOD  get_Tabs  , :ptr ptr Tabs
  COM_STD_METHOD  get_SelectedItem  , :ptr ptr Tab
  COM_STD_METHOD  put_Value  , :SDWORD
  COM_STD_METHOD  get_Value  , :ptr SDWORD
  COM_STD_METHOD  put_TabFixedWidth  , :REAL4
  COM_STD_METHOD  get_TabFixedWidth  , :ptr REAL4
  COM_STD_METHOD  put_TabFixedHeight  , :REAL4
  COM_STD_METHOD  get_TabFixedHeight  , :ptr REAL4
  COM_STD_METHOD  put_FontWeight  , :SWORD
  COM_STD_METHOD  get_FontWeight  , :ptr SWORD
COM_INTERFACE_END
endif

sIID_ITabStrip textequ <IID {004598FC2h,0866Ch,011CFh,{0ABh,07Ch,000h,0AAh,000h,0C0h,08Fh,0CFh}}>

;--- ISpinbutton, Type=INTERFACE, GUID={79176FB3-B7F2-11CE-97EF-00AA006D2776}

ifndef ISpinbuttonVtbl
COM_INTERFACE_BEG ISpinbutton, IDispatch
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_Value  , :SDWORD
  COM_STD_METHOD  get_Value  , :ptr SDWORD
  COM_STD_METHOD  put_Min  , :SDWORD
  COM_STD_METHOD  get_Min  , :ptr SDWORD
  COM_STD_METHOD  put_Max  , :SDWORD
  COM_STD_METHOD  get_Max  , :ptr SDWORD
  COM_STD_METHOD  put_SmallChange  , :SDWORD
  COM_STD_METHOD  get_SmallChange  , :ptr SDWORD
  COM_STD_METHOD  put_Orientation  , :fmOrientation
  COM_STD_METHOD  get_Orientation  , :ptr fmOrientation
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_Delay  , :SDWORD
  COM_STD_METHOD  get_Delay  , :ptr SDWORD
COM_INTERFACE_END
endif

sIID_ISpinbutton textequ <IID {079176FB3h,0B7F2h,011CEh,{097h,0EFh,000h,0AAh,000h,06Dh,027h,076h}}>

;--- IImage, Type=INTERFACE, GUID={4C599243-6926-101B-9992-00000B65C6F9}

ifndef IImageVtbl
COM_INTERFACE_BEG IImage, IDispatch
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_AutoSize  , :BOOL
  COM_STD_METHOD  get_AutoSize  , :ptr BOOL
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BackStyle  , :fmBackStyle
  COM_STD_METHOD  get_BackStyle  , :ptr fmBackStyle
  COM_STD_METHOD  put_BorderColor  , :OLE_COLOR
  COM_STD_METHOD  get_BorderColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BorderStyle  , :fmBorderStyle
  COM_STD_METHOD  get_BorderStyle  , :ptr fmBorderStyle
  COM_STD_METHOD  put_Picture  , :ptr Picture
  COM_STD_METHOD  putref_Picture  , :ptr Picture
  COM_STD_METHOD  get_Picture  , :ptr ptr Picture
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_PictureSizeMode  , :fmPictureSizeMode
  COM_STD_METHOD  get_PictureSizeMode  , :ptr fmPictureSizeMode
  COM_STD_METHOD  put_PictureAlignment  , :fmPictureAlignment
  COM_STD_METHOD  get_PictureAlignment  , :ptr fmPictureAlignment
  COM_STD_METHOD  put_PictureTiling  , :BOOL
  COM_STD_METHOD  get_PictureTiling  , :ptr BOOL
  COM_STD_METHOD  put_SpecialEffect  , :fmSpecialEffect
  COM_STD_METHOD  get_SpecialEffect  , :ptr fmSpecialEffect
COM_INTERFACE_END
endif

sIID_IImage textequ <IID {04C599243h,06926h,0101Bh,{099h,092h,000h,000h,00Bh,065h,0C6h,0F9h}}>

;--- IWHTMLSubmitButton, Type=INTERFACE, GUID={5512D111-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLSubmitButtonVtbl
COM_INTERFACE_BEG IWHTMLSubmitButton, IDispatch
  COM_STD_METHOD  put_Action  , :BSTR
  COM_STD_METHOD  get_Action  , :ptr BSTR
  COM_STD_METHOD  put_Caption  , :BSTR
  COM_STD_METHOD  get_Caption  , :ptr BSTR
  COM_STD_METHOD  put_Encoding  , :BSTR
  COM_STD_METHOD  get_Encoding  , :ptr BSTR
  COM_STD_METHOD  put_Method  , :BSTR
  COM_STD_METHOD  get_Method  , :ptr BSTR
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_HTMLType  , :BSTR
  COM_STD_METHOD  get_HTMLType  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IWHTMLSubmitButton textequ <IID {05512D111h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLImage, Type=INTERFACE, GUID={5512D113-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLImageVtbl
COM_INTERFACE_BEG IWHTMLImage, IDispatch
  COM_STD_METHOD  put_Action  , :BSTR
  COM_STD_METHOD  get_Action  , :ptr BSTR
  COM_STD_METHOD  put_Source  , :BSTR
  COM_STD_METHOD  get_Source  , :ptr BSTR
  COM_STD_METHOD  put_Encoding  , :BSTR
  COM_STD_METHOD  get_Encoding  , :ptr BSTR
  COM_STD_METHOD  put_Method  , :BSTR
  COM_STD_METHOD  get_Method  , :ptr BSTR
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_HTMLType  , :BSTR
  COM_STD_METHOD  get_HTMLType  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IWHTMLImage textequ <IID {05512D113h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLReset, Type=INTERFACE, GUID={5512D115-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLResetVtbl
COM_INTERFACE_BEG IWHTMLReset, IDispatch
  COM_STD_METHOD  put_Caption  , :BSTR
  COM_STD_METHOD  get_Caption  , :ptr BSTR
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_HTMLType  , :BSTR
  COM_STD_METHOD  get_HTMLType  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IWHTMLReset textequ <IID {05512D115h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLCheckbox, Type=INTERFACE, GUID={5512D117-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLCheckboxVtbl
COM_INTERFACE_BEG IWHTMLCheckbox, IDispatch
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_Value  , :BSTR
  COM_STD_METHOD  get_Value  , :ptr BSTR
  COM_STD_METHOD  put_Checked  , :BOOL
  COM_STD_METHOD  get_Checked  , :ptr BOOL
  COM_STD_METHOD  put_HTMLType  , :BSTR
  COM_STD_METHOD  get_HTMLType  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IWHTMLCheckbox textequ <IID {05512D117h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLOption, Type=INTERFACE, GUID={5512D119-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLOptionVtbl
COM_INTERFACE_BEG IWHTMLOption, IDispatch
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_Value  , :BSTR
  COM_STD_METHOD  get_Value  , :ptr BSTR
  COM_STD_METHOD  put_Checked  , :BOOL
  COM_STD_METHOD  get_Checked  , :ptr BOOL
  COM_STD_METHOD  put_HTMLType  , :BSTR
  COM_STD_METHOD  get_HTMLType  , :ptr BSTR
  COM_STD_METHOD  get_DisplayStyle  , :ptr fmDisplayStyle
COM_INTERFACE_END
endif

sIID_IWHTMLOption textequ <IID {05512D119h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLText, Type=INTERFACE, GUID={5512D11B-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLTextVtbl
COM_INTERFACE_BEG IWHTMLText, IDispatch
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_Value  , :BSTR
  COM_STD_METHOD  get_Value  , :ptr BSTR
  COM_STD_METHOD  put_MaxLength  , :SDWORD
  COM_STD_METHOD  get_MaxLength  , :ptr SDWORD
  COM_STD_METHOD  put_Width  , :SDWORD
  COM_STD_METHOD  get_Width  , :ptr SDWORD
  COM_STD_METHOD  put_HTMLType  , :BSTR
  COM_STD_METHOD  get_HTMLType  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IWHTMLText textequ <IID {05512D11Bh,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLHidden, Type=INTERFACE, GUID={5512D11D-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLHiddenVtbl
COM_INTERFACE_BEG IWHTMLHidden, IDispatch
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_Value  , :BSTR
  COM_STD_METHOD  get_Value  , :ptr BSTR
  COM_STD_METHOD  put_HTMLType  , :BSTR
  COM_STD_METHOD  get_HTMLType  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IWHTMLHidden textequ <IID {05512D11Dh,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLPassword, Type=INTERFACE, GUID={5512D11F-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLPasswordVtbl
COM_INTERFACE_BEG IWHTMLPassword, IDispatch
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_Value  , :BSTR
  COM_STD_METHOD  get_Value  , :ptr BSTR
  COM_STD_METHOD  put_MaxLength  , :SDWORD
  COM_STD_METHOD  get_MaxLength  , :ptr SDWORD
  COM_STD_METHOD  put_Width  , :SDWORD
  COM_STD_METHOD  get_Width  , :ptr SDWORD
  COM_STD_METHOD  put_HTMLType  , :BSTR
  COM_STD_METHOD  get_HTMLType  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IWHTMLPassword textequ <IID {05512D11Fh,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLSelect, Type=INTERFACE, GUID={5512D123-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLSelectVtbl
COM_INTERFACE_BEG IWHTMLSelect, IDispatch
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_Values  , :ptr VARIANT
  COM_STD_METHOD  get_Values  , :ptr VARIANT
  COM_STD_METHOD  put_DisplayValues  , :ptr VARIANT
  COM_STD_METHOD  get_DisplayValues  , :ptr VARIANT
  COM_STD_METHOD  put_Selected  , :BSTR
  COM_STD_METHOD  get_Selected  , :ptr BSTR
  COM_STD_METHOD  put_MultiSelect  , :BOOL
  COM_STD_METHOD  get_MultiSelect  , :ptr BOOL
  COM_STD_METHOD  put_Size  , :SDWORD
  COM_STD_METHOD  get_Size  , :ptr SDWORD
COM_INTERFACE_END
endif

sIID_IWHTMLSelect textequ <IID {05512D123h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IWHTMLTextArea, Type=INTERFACE, GUID={5512D125-5CC6-11CF-8D67-00AA00BDCE1D}

ifndef IWHTMLTextAreaVtbl
COM_INTERFACE_BEG IWHTMLTextArea, IDispatch
  COM_STD_METHOD  put_HTMLName  , :BSTR
  COM_STD_METHOD  get_HTMLName  , :ptr BSTR
  COM_STD_METHOD  put_Value  , :BSTR
  COM_STD_METHOD  get_Value  , :ptr BSTR
  COM_STD_METHOD  put_Rows  , :SDWORD
  COM_STD_METHOD  get_Rows  , :ptr SDWORD
  COM_STD_METHOD  put_Columns  , :SDWORD
  COM_STD_METHOD  get_Columns  , :ptr SDWORD
  COM_STD_METHOD  put_WordWrap  , :BSTR
  COM_STD_METHOD  get_WordWrap  , :ptr BSTR
COM_INTERFACE_END
endif

sIID_IWHTMLTextArea textequ <IID {05512D125h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- IControl, Type=INTERFACE, GUID={04598FC6-866C-11CF-AB7C-00AA00C08FCF}

ifndef IControlVtbl
COM_INTERFACE_BEG IControl, IDispatch
  COM_STD_METHOD  put_Cancel  , :BOOL
  COM_STD_METHOD  get_Cancel  , :ptr BOOL
  COM_STD_METHOD  put_ControlSource  , :BSTR
  COM_STD_METHOD  get_ControlSource  , :ptr BSTR
  COM_STD_METHOD  put_ControlTipText  , :BSTR
  COM_STD_METHOD  get_ControlTipText  , :ptr BSTR
  COM_STD_METHOD  put_Default  , :BOOL
  COM_STD_METHOD  get_Default  , :ptr BOOL
  COM_STD_METHOD  _SetHeight  , :SDWORD
  COM_STD_METHOD  _GetHeight  , :ptr SDWORD
  COM_STD_METHOD  put_Height  , :REAL4
  COM_STD_METHOD  get_Height  , :ptr REAL4
  COM_STD_METHOD  put_HelpContextID  , :SDWORD
  COM_STD_METHOD  get_HelpContextID  , :ptr SDWORD
  COM_STD_METHOD  put_InSelection  , :BOOL
  COM_STD_METHOD  get_InSelection  , :ptr BOOL
  COM_STD_METHOD  get_LayoutEffect  , :ptr fmLayoutEffect
  COM_STD_METHOD  _SetLeft  , :SDWORD
  COM_STD_METHOD  _GetLeft  , :ptr SDWORD
  COM_STD_METHOD  put_Left  , :REAL4
  COM_STD_METHOD  get_Left  , :ptr REAL4
  COM_STD_METHOD  put_Name  , :BSTR
  COM_STD_METHOD  get_Name  , :ptr BSTR
  COM_STD_METHOD  _GetOldHeight  , :ptr SDWORD
  COM_STD_METHOD  get_OldHeight  , :ptr REAL4
  COM_STD_METHOD  _GetOldLeft  , :ptr SDWORD
  COM_STD_METHOD  get_OldLeft  , :ptr REAL4
  COM_STD_METHOD  _GetOldTop  , :ptr SDWORD
  COM_STD_METHOD  get_OldTop  , :ptr REAL4
  COM_STD_METHOD  _GetOldWidth  , :ptr SDWORD
  COM_STD_METHOD  get_OldWidth  , :ptr REAL4
  COM_STD_METHOD  get_Object  , :ptr LPDISPATCH
  COM_STD_METHOD  get_Parent  , :ptr LPDISPATCH
  COM_STD_METHOD  put_RowSource  , :BSTR
  COM_STD_METHOD  get_RowSource  , :ptr BSTR
  COM_STD_METHOD  put_RowSourceType  , :SWORD
  COM_STD_METHOD  get_RowSourceType  , :ptr SWORD
  COM_STD_METHOD  put_TabIndex  , :SWORD
  COM_STD_METHOD  get_TabIndex  , :ptr SWORD
  COM_STD_METHOD  put_TabStop  , :BOOL
  COM_STD_METHOD  get_TabStop  , :ptr BOOL
  COM_STD_METHOD  put_Tag  , :BSTR
  COM_STD_METHOD  get_Tag  , :ptr BSTR
  COM_STD_METHOD  _SetTop  , :SDWORD
  COM_STD_METHOD  _GetTop  , :ptr SDWORD
  COM_STD_METHOD  put_Top  , :REAL4
  COM_STD_METHOD  get_Top  , :ptr REAL4
  COM_STD_METHOD  put_BoundValue  , :ptr VARIANT
  COM_STD_METHOD  get_BoundValue  , :ptr VARIANT
  COM_STD_METHOD  put_Visible  , :BOOL
  COM_STD_METHOD  get_Visible  , :ptr BOOL
  COM_STD_METHOD  _SetWidth  , :SDWORD
  COM_STD_METHOD  _GetWidth  , :ptr SDWORD
  COM_STD_METHOD  put_Width  , :REAL4
  COM_STD_METHOD  get_Width  , :ptr REAL4
  COM_STD_METHOD  Move  , :VARIANT,:VARIANT,:VARIANT,:VARIANT,:VARIANT
  COM_STD_METHOD  ZOrder  , :VARIANT
  COM_STD_METHOD  Select  , :BOOL
  COM_STD_METHOD  SetFocus  
  COM_STD_METHOD  _GethWnd  , :ptr SDWORD
  COM_STD_METHOD  _GetID  , :ptr SDWORD
  COM_STD_METHOD  _Move  , :SDWORD,:SDWORD,:SDWORD,:SDWORD
  COM_STD_METHOD  _ZOrder  , :fmZOrder
COM_INTERFACE_END
endif

sIID_IControl textequ <IID {004598FC6h,0866Ch,011CFh,{0ABh,07Ch,000h,0AAh,000h,0C0h,08Fh,0CFh}}>

;--- IPage, Type=INTERFACE, GUID={5CEF5613-713D-11CE-80C9-00AA00611080}

ifndef IPageVtbl
COM_INTERFACE_BEG IPage, IDispatch
  COM_STD_METHOD  get_Controls  , :ptr ptr Controls
  COM_STD_METHOD  get_Selected  , :ptr ptr Controls
  COM_STD_METHOD  get_ActiveControl  , :ptr ptr Control
  COM_STD_METHOD  get_CanPaste  , :ptr BOOL
  COM_STD_METHOD  get_CanRedo  , :ptr BOOL
  COM_STD_METHOD  get_CanUndo  , :ptr BOOL
  COM_STD_METHOD  put_Cycle  , :fmCycle
  COM_STD_METHOD  get_Cycle  , :ptr fmCycle
  COM_STD_METHOD  put_Caption  , :BSTR
  COM_STD_METHOD  get_Caption  , :ptr BSTR
  COM_STD_METHOD  put_ControlTipText  , :BSTR
  COM_STD_METHOD  get_ControlTipText  , :ptr BSTR
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put_Index  , :SDWORD
  COM_STD_METHOD  get_Index  , :ptr SDWORD
  COM_STD_METHOD  _GetInsideHeight  , :ptr SDWORD
  COM_STD_METHOD  get_InsideHeight  , :ptr REAL4
  COM_STD_METHOD  _GetInsideWidth  , :ptr SDWORD
  COM_STD_METHOD  get_InsideWidth  , :ptr REAL4
  COM_STD_METHOD  put_KeepScrollBarsVisible  , :fmScrollBars
  COM_STD_METHOD  get_KeepScrollBarsVisible  , :ptr fmScrollBars
  COM_STD_METHOD  put_Name  , :BSTR
  COM_STD_METHOD  get_Name  , :ptr BSTR
  COM_STD_METHOD  put_PictureAlignment  , :fmPictureAlignment
  COM_STD_METHOD  get_PictureAlignment  , :ptr fmPictureAlignment
  COM_STD_METHOD  put_Picture  , :ptr Picture
  COM_STD_METHOD  putref_Picture  , :ptr Picture
  COM_STD_METHOD  get_Picture  , :ptr ptr Picture
  COM_STD_METHOD  put_PictureSizeMode  , :fmPictureSizeMode
  COM_STD_METHOD  get_PictureSizeMode  , :ptr fmPictureSizeMode
  COM_STD_METHOD  put_PictureTiling  , :BOOL
  COM_STD_METHOD  get_PictureTiling  , :ptr BOOL
  COM_STD_METHOD  put_ScrollBars  , :fmScrollBars
  COM_STD_METHOD  get_ScrollBars  , :ptr fmScrollBars
  COM_STD_METHOD  _SetScrollHeight  , :SDWORD
  COM_STD_METHOD  _GetScrollHeight  , :ptr SDWORD
  COM_STD_METHOD  put_ScrollHeight  , :REAL4
  COM_STD_METHOD  get_ScrollHeight  , :ptr REAL4
  COM_STD_METHOD  _SetScrollLeft  , :SDWORD
  COM_STD_METHOD  _GetScrollLeft  , :ptr SDWORD
  COM_STD_METHOD  put_ScrollLeft  , :REAL4
  COM_STD_METHOD  get_ScrollLeft  , :ptr REAL4
  COM_STD_METHOD  _SetScrollTop  , :SDWORD
  COM_STD_METHOD  _GetScrollTop  , :ptr SDWORD
  COM_STD_METHOD  put_ScrollTop  , :REAL4
  COM_STD_METHOD  get_ScrollTop  , :ptr REAL4
  COM_STD_METHOD  _SetScrollWidth  , :SDWORD
  COM_STD_METHOD  _GetScrollWidth  , :ptr SDWORD
  COM_STD_METHOD  put_ScrollWidth  , :REAL4
  COM_STD_METHOD  get_ScrollWidth  , :ptr REAL4
  COM_STD_METHOD  put_Tag  , :BSTR
  COM_STD_METHOD  get_Tag  , :ptr BSTR
  COM_STD_METHOD  put_TransitionEffect  , :fmTransitionEffect
  COM_STD_METHOD  get_TransitionEffect  , :ptr fmTransitionEffect
  COM_STD_METHOD  put_TransitionPeriod  , :SDWORD
  COM_STD_METHOD  get_TransitionPeriod  , :ptr SDWORD
  COM_STD_METHOD  put_VerticalScrollBarSide  , :fmVerticalScrollBarSide
  COM_STD_METHOD  get_VerticalScrollBarSide  , :ptr fmVerticalScrollBarSide
  COM_STD_METHOD  put_Visible  , :BOOL
  COM_STD_METHOD  get_Visible  , :ptr BOOL
  COM_STD_METHOD  put_Zoom  , :SWORD
  COM_STD_METHOD  get_Zoom  , :ptr SWORD
  COM_STD_METHOD  put_DesignMode  , :fmMode
  COM_STD_METHOD  get_DesignMode  , :ptr fmMode
  COM_STD_METHOD  put_ShowToolbox  , :fmMode
  COM_STD_METHOD  get_ShowToolbox  , :ptr fmMode
  COM_STD_METHOD  put_ShowGridDots  , :fmMode
  COM_STD_METHOD  get_ShowGridDots  , :ptr fmMode
  COM_STD_METHOD  put_SnapToGrid  , :fmMode
  COM_STD_METHOD  get_SnapToGrid  , :ptr fmMode
  COM_STD_METHOD  put_GridX  , :REAL4
  COM_STD_METHOD  get_GridX  , :ptr REAL4
  COM_STD_METHOD  _SetGridX  , :SDWORD
  COM_STD_METHOD  _GetGridX  , :ptr SDWORD
  COM_STD_METHOD  put_GridY  , :REAL4
  COM_STD_METHOD  get_GridY  , :ptr REAL4
  COM_STD_METHOD  _SetGridY  , :SDWORD
  COM_STD_METHOD  _GetGridY  , :ptr SDWORD
  COM_STD_METHOD  Copy  
  COM_STD_METHOD  Cut  
  COM_STD_METHOD  Paste  
  COM_STD_METHOD  RedoAction  
  COM_STD_METHOD  Repaint  
  COM_STD_METHOD  Scroll  , :VARIANT,:VARIANT
  COM_STD_METHOD  SetDefaultTabOrder  
  COM_STD_METHOD  UndoAction  
  COM_STD_METHOD  put_Accelerator  , :BSTR
  COM_STD_METHOD  get_Accelerator  , :ptr BSTR
  COM_STD_METHOD  get_Parent  , :ptr LPDISPATCH
COM_INTERFACE_END
endif

sIID_IPage textequ <IID {05CEF5613h,0713Dh,011CEh,{080h,0C9h,000h,0AAh,000h,061h,010h,080h}}>

;--- Pages, Type=INTERFACE, GUID={92E11A03-7358-11CE-80CB-00AA00611080}

ifndef PagesVtbl
COM_INTERFACE_BEG Pages, IDispatch
  COM_STD_METHOD  get_Count  , :ptr SDWORD
  COM_STD_METHOD  get__NewEnum  , :ptr LPUNKNOWN
  COM_STD_METHOD  Item  , :VARIANT,:ptr LPDISPATCH
  COM_STD_METHOD  Enum  , :ptr LPUNKNOWN
  COM_STD_METHOD  Add_  , :VARIANT,:VARIANT,:VARIANT,:ptr ptr Page
  COM_STD_METHOD  _AddCtrl  , :ptr SDWORD,:BSTR,:BSTR,:ptr ptr Page
  COM_STD_METHOD  _InsertCtrl  , :ptr SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ptr Page
  COM_STD_METHOD  _GetItemByIndex  , :SDWORD,:ptr ptr Control
  COM_STD_METHOD  _GetItemByName  , :BSTR,:ptr ptr Control
  COM_STD_METHOD  Remove  , :VARIANT
  COM_STD_METHOD  Clear  
COM_INTERFACE_END
endif

sIID_Pages textequ <IID {092E11A03h,07358h,011CEh,{080h,0CBh,000h,0AAh,000h,061h,010h,080h}}>

;--- IMultiPage, Type=INTERFACE, GUID={04598FC9-866C-11CF-AB7C-00AA00C08FCF}

ifndef IMultiPageVtbl
COM_INTERFACE_BEG IMultiPage, IDispatch
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_FontName  , :BSTR
  COM_STD_METHOD  get_FontName  , :ptr BSTR
  COM_STD_METHOD  put_FontBold  , :BOOL
  COM_STD_METHOD  get_FontBold  , :ptr BOOL
  COM_STD_METHOD  put_FontItalic  , :BOOL
  COM_STD_METHOD  get_FontItalic  , :ptr BOOL
  COM_STD_METHOD  put_FontUnderline  , :BOOL
  COM_STD_METHOD  get_FontUnderline  , :ptr BOOL
  COM_STD_METHOD  put_FontStrikethru  , :BOOL
  COM_STD_METHOD  get_FontStrikethru  , :ptr BOOL
  COM_STD_METHOD  put_FontSize  , :CY
  COM_STD_METHOD  get_FontSize  , :ptr CY
  COM_STD_METHOD  put_MultiRow  , :BOOL
  COM_STD_METHOD  get_MultiRow  , :ptr BOOL
  COM_STD_METHOD  put_Style  , :fmTabStyle
  COM_STD_METHOD  get_Style  , :ptr fmTabStyle
  COM_STD_METHOD  put_TabOrientation  , :fmTabOrientation
  COM_STD_METHOD  get_TabOrientation  , :ptr fmTabOrientation
  COM_STD_METHOD  _SetTabFixedWidth  , :SDWORD
  COM_STD_METHOD  _GetTabFixedWidth  , :ptr SDWORD
  COM_STD_METHOD  _SetTabFixedHeight  , :SDWORD
  COM_STD_METHOD  _GetTabFixedHeight  , :ptr SDWORD
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  get_SelectedItem  , :ptr ptr Page
  COM_STD_METHOD  get_Pages  , :ptr ptr Pages
  COM_STD_METHOD  put_Value  , :SDWORD
  COM_STD_METHOD  get_Value  , :ptr SDWORD
  COM_STD_METHOD  put_TabFixedWidth  , :REAL4
  COM_STD_METHOD  get_TabFixedWidth  , :ptr REAL4
  COM_STD_METHOD  put_TabFixedHeight  , :REAL4
  COM_STD_METHOD  get_TabFixedHeight  , :ptr REAL4
  COM_STD_METHOD  put_FontWeight  , :SWORD
  COM_STD_METHOD  get_FontWeight  , :ptr SWORD
COM_INTERFACE_END
endif

sIID_IMultiPage textequ <IID {004598FC9h,0866Ch,011CFh,{0ABh,07Ch,000h,0AAh,000h,0C0h,08Fh,0CFh}}>

;--- Controls, Type=INTERFACE, GUID={04598FC7-866C-11CF-AB7C-00AA00C08FCF}

ifndef ControlsVtbl
COM_INTERFACE_BEG Controls, IDispatch
  COM_STD_METHOD  get_Count  , :ptr SDWORD
  COM_STD_METHOD  get__NewEnum  , :ptr LPUNKNOWN
  COM_STD_METHOD  Item  , :VARIANT,:ptr LPDISPATCH
  COM_STD_METHOD  Clear  
  COM_STD_METHOD  _Move  , :SDWORD,:SDWORD
  COM_STD_METHOD  SelectAll  
  COM_STD_METHOD  _AddByClass  , :ptr SDWORD,:ptr ptr Control
  COM_STD_METHOD  AlignToGrid  
  COM_STD_METHOD  BringForward  
  COM_STD_METHOD  BringToFront  
  COM_STD_METHOD  Copy  
  COM_STD_METHOD  Cut  
  COM_STD_METHOD  Enum  , :ptr LPUNKNOWN
  COM_STD_METHOD  _GetItemByIndex  , :SDWORD,:ptr ptr Control
  COM_STD_METHOD  _GetItemByName  , :BSTR,:ptr ptr Control
  COM_STD_METHOD  _GetItemByID  , :SDWORD,:ptr ptr Control
  COM_STD_METHOD  SendBackward  
  COM_STD_METHOD  SendToBack  
  COM_STD_METHOD  Move  , :REAL4,:REAL4
  COM_STD_METHOD  Add_  , :BSTR,:VARIANT,:VARIANT,:ptr ptr Control
  COM_STD_METHOD  Remove  , :VARIANT
COM_INTERFACE_END
endif

sIID_Controls textequ <IID {004598FC7h,0866Ch,011CFh,{0ABh,07Ch,000h,0AAh,000h,0C0h,08Fh,0CFh}}>

;--- IOptionFrame, Type=INTERFACE, GUID={29B86A70-F52E-11CE-9BCE-00AA00608E01}

ifndef IOptionFrameVtbl
COM_INTERFACE_BEG IOptionFrame, IDispatch
  COM_STD_METHOD  get_ActiveControl  , :ptr ptr Control
  COM_STD_METHOD  put_BackColor  , :OLE_COLOR
  COM_STD_METHOD  get_BackColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BorderColor  , :OLE_COLOR
  COM_STD_METHOD  get_BorderColor  , :ptr OLE_COLOR
  COM_STD_METHOD  put_BorderStyle  , :fmBorderStyle
  COM_STD_METHOD  get_BorderStyle  , :ptr fmBorderStyle
  COM_STD_METHOD  get_CanPaste  , :ptr BOOL
  COM_STD_METHOD  get_CanRedo  , :ptr BOOL
  COM_STD_METHOD  get_CanUndo  , :ptr BOOL
  COM_STD_METHOD  put_Caption  , :BSTR
  COM_STD_METHOD  get_Caption  , :ptr BSTR
  COM_STD_METHOD  get_Controls  , :ptr ptr Controls
  COM_STD_METHOD  put_Cycle  , :fmCycle
  COM_STD_METHOD  get_Cycle  , :ptr fmCycle
  COM_STD_METHOD  put_Enabled  , :BOOL
  COM_STD_METHOD  get_Enabled  , :ptr BOOL
  COM_STD_METHOD  put__Font_Reserved  , :ptr Font
  COM_STD_METHOD  putref_Font  , :ptr Font
  COM_STD_METHOD  get_Font  , :ptr ptr Font
  COM_STD_METHOD  put_ForeColor  , :OLE_COLOR
  COM_STD_METHOD  get_ForeColor  , :ptr OLE_COLOR
  COM_STD_METHOD  _GetInsideHeight  , :ptr SDWORD
  COM_STD_METHOD  get_InsideHeight  , :ptr REAL4
  COM_STD_METHOD  _GetInsideWidth  , :ptr SDWORD
  COM_STD_METHOD  get_InsideWidth  , :ptr REAL4
  COM_STD_METHOD  put_KeepScrollBarsVisible  , :fmScrollBars
  COM_STD_METHOD  get_KeepScrollBarsVisible  , :ptr fmScrollBars
  COM_STD_METHOD  put_MouseIcon  , :ptr Picture
  COM_STD_METHOD  putref_MouseIcon  , :ptr Picture
  COM_STD_METHOD  get_MouseIcon  , :ptr ptr Picture
  COM_STD_METHOD  put_MousePointer  , :fmMousePointer
  COM_STD_METHOD  get_MousePointer  , :ptr fmMousePointer
  COM_STD_METHOD  put_PictureAlignment  , :fmPictureAlignment
  COM_STD_METHOD  get_PictureAlignment  , :ptr fmPictureAlignment
  COM_STD_METHOD  put_Picture  , :ptr Picture
  COM_STD_METHOD  putref_Picture  , :ptr Picture
  COM_STD_METHOD  get_Picture  , :ptr ptr Picture
  COM_STD_METHOD  put_PictureSizeMode  , :fmPictureSizeMode
  COM_STD_METHOD  get_PictureSizeMode  , :ptr fmPictureSizeMode
  COM_STD_METHOD  put_PictureTiling  , :BOOL
  COM_STD_METHOD  get_PictureTiling  , :ptr BOOL
  COM_STD_METHOD  put_ScrollBars  , :fmScrollBars
  COM_STD_METHOD  get_ScrollBars  , :ptr fmScrollBars
  COM_STD_METHOD  _SetScrollHeight  , :SDWORD
  COM_STD_METHOD  _GetScrollHeight  , :ptr SDWORD
  COM_STD_METHOD  put_ScrollHeight  , :REAL4
  COM_STD_METHOD  get_ScrollHeight  , :ptr REAL4
  COM_STD_METHOD  _SetScrollLeft  , :SDWORD
  COM_STD_METHOD  _GetScrollLeft  , :ptr SDWORD
  COM_STD_METHOD  put_ScrollLeft  , :REAL4
  COM_STD_METHOD  get_ScrollLeft  , :ptr REAL4
  COM_STD_METHOD  _SetScrollTop  , :SDWORD
  COM_STD_METHOD  _GetScrollTop  , :ptr SDWORD
  COM_STD_METHOD  put_ScrollTop  , :REAL4
  COM_STD_METHOD  get_ScrollTop  , :ptr REAL4
  COM_STD_METHOD  _SetScrollWidth  , :SDWORD
  COM_STD_METHOD  _GetScrollWidth  , :ptr SDWORD
  COM_STD_METHOD  put_ScrollWidth  , :REAL4
  COM_STD_METHOD  get_ScrollWidth  , :ptr REAL4
  COM_STD_METHOD  get_Selected  , :ptr ptr Controls
  COM_STD_METHOD  put_SpecialEffect  , :fmSpecialEffect
  COM_STD_METHOD  get_SpecialEffect  , :ptr fmSpecialEffect
  COM_STD_METHOD  put_VerticalScrollBarSide  , :fmVerticalScrollBarSide
  COM_STD_METHOD  get_VerticalScrollBarSide  , :ptr fmVerticalScrollBarSide
  COM_STD_METHOD  put_Zoom  , :SWORD
  COM_STD_METHOD  get_Zoom  , :ptr SWORD
  COM_STD_METHOD  Copy  
  COM_STD_METHOD  Cut  
  COM_STD_METHOD  Paste  
  COM_STD_METHOD  RedoAction  
  COM_STD_METHOD  Repaint  
  COM_STD_METHOD  Scroll  , :VARIANT,:VARIANT
  COM_STD_METHOD  SetDefaultTabOrder  
  COM_STD_METHOD  UndoAction  
  COM_STD_METHOD  put_DesignMode  , :fmMode
  COM_STD_METHOD  get_DesignMode  , :ptr fmMode
  COM_STD_METHOD  put_ShowToolbox  , :fmMode
  COM_STD_METHOD  get_ShowToolbox  , :ptr fmMode
  COM_STD_METHOD  put_ShowGridDots  , :fmMode
  COM_STD_METHOD  get_ShowGridDots  , :ptr fmMode
  COM_STD_METHOD  put_SnapToGrid  , :fmMode
  COM_STD_METHOD  get_SnapToGrid  , :ptr fmMode
  COM_STD_METHOD  put_GridX  , :REAL4
  COM_STD_METHOD  get_GridX  , :ptr REAL4
  COM_STD_METHOD  _SetGridX  , :SDWORD
  COM_STD_METHOD  _GetGridX  , :ptr SDWORD
  COM_STD_METHOD  put_GridY  , :REAL4
  COM_STD_METHOD  get_GridY  , :ptr REAL4
  COM_STD_METHOD  _SetGridY  , :SDWORD
  COM_STD_METHOD  _GetGridY  , :ptr SDWORD
COM_INTERFACE_END
endif

sIID_IOptionFrame textequ <IID {029B86A70h,0F52Eh,011CEh,{09Bh,0CEh,000h,0AAh,000h,060h,08Eh,001h}}>

;--- _UserForm, Type=INTERFACE, GUID={04598FC8-866C-11CF-AB7C-00AA00C08FCF}

ifndef _UserFormVtbl
COM_INTERFACE_BEG _UserForm, IOptionFrame
  COM_STD_METHOD  put_DrawBuffer  , :SDWORD
  COM_STD_METHOD  get_DrawBuffer  , :ptr SDWORD
COM_INTERFACE_END
endif

sIID__UserForm textequ <IID {004598FC8h,0866Ch,011CFh,{0ABh,07Ch,000h,0AAh,000h,0C0h,08Fh,0CFh}}>

;--- MdcListEvents, Type=DISPATCH, GUID={8BD21D22-EC42-11CE-9E0D-00AA006002F3}

;--- dispinterface only
ifndef MdcListEventsVtbl
COM_INTERFACE_BEG MdcListEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_MdcListEvents textequ <IID {08BD21D22h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- MdcComboEvents, Type=DISPATCH, GUID={8BD21D32-EC42-11CE-9E0D-00AA006002F3}

;--- dispinterface only
ifndef MdcComboEventsVtbl
COM_INTERFACE_BEG MdcComboEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  DropButtonClick  
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_MdcComboEvents textequ <IID {08BD21D32h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- MdcCheckBoxEvents, Type=DISPATCH, GUID={8BD21D42-EC42-11CE-9E0D-00AA006002F3}

;--- dispinterface only
ifndef MdcCheckBoxEventsVtbl
COM_INTERFACE_BEG MdcCheckBoxEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_MdcCheckBoxEvents textequ <IID {08BD21D42h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- MdcOptionButtonEvents, Type=DISPATCH, GUID={8BD21D52-EC42-11CE-9E0D-00AA006002F3}

;--- dispinterface only
ifndef MdcOptionButtonEventsVtbl
COM_INTERFACE_BEG MdcOptionButtonEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_MdcOptionButtonEvents textequ <IID {08BD21D52h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- MdcToggleButtonEvents, Type=DISPATCH, GUID={8BD21D62-EC42-11CE-9E0D-00AA006002F3}

;--- dispinterface only
ifndef MdcToggleButtonEventsVtbl
COM_INTERFACE_BEG MdcToggleButtonEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_MdcToggleButtonEvents textequ <IID {08BD21D62h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- ScrollbarEvents, Type=DISPATCH, GUID={7B020EC2-AF6C-11CE-9F46-00AA00574A4F}

;--- dispinterface only
ifndef ScrollbarEventsVtbl
COM_INTERFACE_BEG ScrollbarEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  Scroll  
COM_INTERFACE_END
endif

sIID_ScrollbarEvents textequ <IID {07B020EC2h,0AF6Ch,011CEh,{09Fh,046h,000h,0AAh,000h,057h,04Ah,04Fh}}>

;--- TabStripEvents, Type=DISPATCH, GUID={7B020EC7-AF6C-11CE-9F46-00AA00574A4F}

;--- dispinterface only
ifndef TabStripEventsVtbl
COM_INTERFACE_BEG TabStripEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :SDWORD,:ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :SDWORD,:ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Click  , :SDWORD
  COM_DISP_METHOD  DblClick  , :SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  MouseDown  , :SDWORD,:SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SDWORD,:SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SDWORD,:SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_TabStripEvents textequ <IID {07B020EC7h,0AF6Ch,011CEh,{09Fh,046h,000h,0AAh,000h,057h,04Ah,04Fh}}>

;--- SpinbuttonEvents, Type=DISPATCH, GUID={79176FB2-B7F2-11CE-97EF-00AA006D2776}

;--- dispinterface only
ifndef SpinbuttonEventsVtbl
COM_INTERFACE_BEG SpinbuttonEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  SpinUp  
  COM_DISP_METHOD  SpinDown  
COM_INTERFACE_END
endif

sIID_SpinbuttonEvents textequ <IID {079176FB2h,0B7F2h,011CEh,{097h,0EFh,000h,0AAh,000h,06Dh,027h,076h}}>

;--- ImageEvents, Type=DISPATCH, GUID={4C5992A5-6926-101B-9992-00000B65C6F9}

;--- dispinterface only
ifndef ImageEventsVtbl
COM_INTERFACE_BEG ImageEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_ImageEvents textequ <IID {04C5992A5h,06926h,0101Bh,{099h,092h,000h,000h,00Bh,065h,0C6h,0F9h}}>

;--- WHTMLControlEvents, Type=DISPATCH, GUID={796ED650-5FE9-11CF-8D68-00AA00BDCE1D}

;--- dispinterface only
ifndef WHTMLControlEventsVtbl
COM_INTERFACE_BEG WHTMLControlEvents, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents textequ <IID {0796ED650h,05FE9h,011CFh,{08Dh,068h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- WHTMLControlEvents1, Type=DISPATCH, GUID={47FF8FE0-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents1Vtbl
COM_INTERFACE_BEG WHTMLControlEvents1, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents1 textequ <IID {047FF8FE0h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- WHTMLControlEvents2, Type=DISPATCH, GUID={47FF8FE1-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents2Vtbl
COM_INTERFACE_BEG WHTMLControlEvents2, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents2 textequ <IID {047FF8FE1h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- WHTMLControlEvents3, Type=DISPATCH, GUID={47FF8FE2-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents3Vtbl
COM_INTERFACE_BEG WHTMLControlEvents3, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents3 textequ <IID {047FF8FE2h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- WHTMLControlEvents4, Type=DISPATCH, GUID={47FF8FE3-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents4Vtbl
COM_INTERFACE_BEG WHTMLControlEvents4, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents4 textequ <IID {047FF8FE3h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- WHTMLControlEvents5, Type=DISPATCH, GUID={47FF8FE4-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents5Vtbl
COM_INTERFACE_BEG WHTMLControlEvents5, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents5 textequ <IID {047FF8FE4h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- WHTMLControlEvents6, Type=DISPATCH, GUID={47FF8FE5-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents6Vtbl
COM_INTERFACE_BEG WHTMLControlEvents6, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents6 textequ <IID {047FF8FE5h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- WHTMLControlEvents7, Type=DISPATCH, GUID={47FF8FE6-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents7Vtbl
COM_INTERFACE_BEG WHTMLControlEvents7, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents7 textequ <IID {047FF8FE6h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- WHTMLControlEvents9, Type=DISPATCH, GUID={47FF8FE8-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents9Vtbl
COM_INTERFACE_BEG WHTMLControlEvents9, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents9 textequ <IID {047FF8FE8h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- WHTMLControlEvents10, Type=DISPATCH, GUID={47FF8FE9-6198-11CF-8CE8-00AA006CB389}

;--- dispinterface only
ifndef WHTMLControlEvents10Vtbl
COM_INTERFACE_BEG WHTMLControlEvents10, IDispatch
  COM_DISP_METHOD  Click  
COM_INTERFACE_END
endif

sIID_WHTMLControlEvents10 textequ <IID {047FF8FE9h,06198h,011CFh,{08Ch,0E8h,000h,0AAh,000h,06Ch,0B3h,089h}}>

;--- FormEvents, Type=DISPATCH, GUID={5B9D8FC8-4A71-101B-97A6-00000B65C08B}

;--- dispinterface only
ifndef FormEventsVtbl
COM_INTERFACE_BEG FormEvents, IDispatch
  COM_DISP_METHOD  AddControl  , :ptr Control
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr Control,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:ptr Control,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  Layout  
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  RemoveControl  , :ptr Control
  COM_DISP_METHOD  Scroll  , :fmScrollAction,:fmScrollAction,:REAL4,:REAL4,:ptr ReturnSingle,:ptr ReturnSingle
  COM_DISP_METHOD  Zoom  , :ptr SWORD
COM_INTERFACE_END
endif

sIID_FormEvents textequ <IID {05B9D8FC8h,04A71h,0101Bh,{097h,0A6h,000h,000h,00Bh,065h,0C0h,08Bh}}>

;--- OptionFrameEvents, Type=DISPATCH, GUID={CF3F94A0-F546-11CE-9BCE-00AA00608E01}

;--- dispinterface only
ifndef OptionFrameEventsVtbl
COM_INTERFACE_BEG OptionFrameEvents, IDispatch
  COM_DISP_METHOD  AddControl  , :ptr Control
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr Control,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:ptr Control,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  Layout  
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  RemoveControl  , :ptr Control
  COM_DISP_METHOD  Scroll  , :fmScrollAction,:fmScrollAction,:REAL4,:REAL4,:ptr ReturnSingle,:ptr ReturnSingle
  COM_DISP_METHOD  Zoom  , :ptr SWORD
COM_INTERFACE_END
endif

sIID_OptionFrameEvents textequ <IID {0CF3F94A0h,0F546h,011CEh,{09Bh,0CEh,000h,0AAh,000h,060h,08Eh,001h}}>

;--- Font, Type=DISPATCH, GUID={BEF6E003-A874-101A-8BBA-00AA00300CAB}

;DISPID_Name  EQU  00h
;DISPID_Size  EQU  02h
;DISPID_Bold  EQU  03h
;DISPID_Italic  EQU  04h
;DISPID_Underline  EQU  05h
;DISPID_Strikethrough  EQU  06h
;DISPID_Weight  EQU  07h
;DISPID_Charset  EQU  08h

;--- dispinterface only
ifndef FontVtbl
COM_INTERFACE_BEG Font, IDispatch
COM_INTERFACE_END
endif

sIID_Font textequ <IID {0BEF6E003h,0A874h,0101Ah,{08Bh,0BAh,000h,0AAh,000h,030h,00Ch,0ABh}}>

;--- ControlEvents, Type=DISPATCH, GUID={9A4BBF53-4E46-101B-8BBD-00AA003E3B29}

;--- dispinterface only
ifndef ControlEventsVtbl
COM_INTERFACE_BEG ControlEvents, IDispatch
  COM_DISP_METHOD  Enter_  
  COM_DISP_METHOD  Exit  , :ptr ReturnBoolean
  COM_DISP_METHOD  BeforeUpdate  , :ptr ReturnBoolean
  COM_DISP_METHOD  AfterUpdate  
COM_INTERFACE_END
endif

sIID_ControlEvents textequ <IID {09A4BBF53h,04E46h,0101Bh,{08Bh,0BDh,000h,0AAh,000h,03Eh,03Bh,029h}}>

;--- MultiPageEvents, Type=DISPATCH, GUID={7B020EC8-AF6C-11CE-9F46-00AA00574A4F}

;--- dispinterface only
ifndef MultiPageEventsVtbl
COM_INTERFACE_BEG MultiPageEvents, IDispatch
  COM_DISP_METHOD  AddControl  , :SDWORD,:ptr Control
  COM_DISP_METHOD  BeforeDragOver  , :SDWORD,:ptr ReturnBoolean,:ptr Control,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :SDWORD,:ptr ReturnBoolean,:ptr Control,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  Click  , :SDWORD
  COM_DISP_METHOD  DblClick  , :SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SDWORD,:SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  Layout  , :SDWORD
  COM_DISP_METHOD  MouseDown  , :SDWORD,:SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SDWORD,:SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SDWORD,:SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  RemoveControl  , :SDWORD,:ptr Control
  COM_DISP_METHOD  Scroll  , :SDWORD,:fmScrollAction,:fmScrollAction,:REAL4,:REAL4,:ptr ReturnSingle,:ptr ReturnSingle
  COM_DISP_METHOD  Zoom  , :SDWORD,:ptr SWORD
COM_INTERFACE_END
endif

sIID_MultiPageEvents textequ <IID {07B020EC8h,0AF6Ch,011CEh,{09Fh,046h,000h,0AAh,000h,057h,04Ah,04Fh}}>

;--- LabelControlEvents, Type=DISPATCH, GUID={978C9E22-D4B0-11CE-BF2D-00AA003F40D0}

;--- dispinterface only
ifndef LabelControlEventsVtbl
COM_INTERFACE_BEG LabelControlEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_LabelControlEvents textequ <IID {0978C9E22h,0D4B0h,011CEh,{0BFh,02Dh,000h,0AAh,000h,03Fh,040h,0D0h}}>

;--- CommandButtonEvents, Type=DISPATCH, GUID={7B020EC1-AF6C-11CE-9F46-00AA00574A4F}

;--- dispinterface only
ifndef CommandButtonEventsVtbl
COM_INTERFACE_BEG CommandButtonEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Click  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_CommandButtonEvents textequ <IID {07B020EC1h,0AF6Ch,011CEh,{09Fh,046h,000h,0AAh,000h,057h,04Ah,04Fh}}>

;--- MdcTextEvents, Type=DISPATCH, GUID={8BD21D12-EC42-11CE-9E0D-00AA006002F3}

;--- dispinterface only
ifndef MdcTextEventsVtbl
COM_INTERFACE_BEG MdcTextEvents, IDispatch
  COM_DISP_METHOD  BeforeDragOver  , :ptr ReturnBoolean,:ptr DataObject,:REAL4,:REAL4,:fmDragState,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  BeforeDropOrPaste  , :ptr ReturnBoolean,:fmAction,:ptr DataObject,:REAL4,:REAL4,:ptr ReturnEffect,:SWORD
  COM_DISP_METHOD  Change  
  COM_DISP_METHOD  DblClick  , :ptr ReturnBoolean
  COM_DISP_METHOD  DropButtonClick  
  COM_DISP_METHOD  Error  , :SWORD,:ptr ReturnString,:SDWORD,:BSTR,:BSTR,:SDWORD,:ptr ReturnBoolean
  COM_DISP_METHOD  KeyDown  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  KeyPress  , :ptr ReturnInteger
  COM_DISP_METHOD  KeyUp  , :ptr ReturnInteger,:SWORD
  COM_DISP_METHOD  MouseDown  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseMove  , :SWORD,:SWORD,:REAL4,:REAL4
  COM_DISP_METHOD  MouseUp  , :SWORD,:SWORD,:REAL4,:REAL4
COM_INTERFACE_END
endif

sIID_MdcTextEvents textequ <IID {08BD21D12h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- Label, Type=COCLASS, GUID={978C9E23-D4B0-11CE-BF2D-00AA003F40D0}

sCLSID_Label_ textequ <GUID {0978C9E23h,0D4B0h,011CEh,{0BFh,02Dh,000h,0AAh,000h,03Fh,040h,0D0h}}>

;--- SpinButton, Type=COCLASS, GUID={79176FB0-B7F2-11CE-97EF-00AA006D2776}

sCLSID_SpinButton textequ <GUID {079176FB0h,0B7F2h,011CEh,{097h,0EFh,000h,0AAh,000h,06Dh,027h,076h}}>

;--- UserForm, Type=COCLASS, GUID={C62A69F0-16DC-11CE-9E98-00AA00574A4F}

sCLSID_UserForm textequ <GUID {0C62A69F0h,016DCh,011CEh,{09Eh,098h,000h,0AAh,000h,057h,04Ah,04Fh}}>

;--- Image, Type=COCLASS, GUID={4C599241-6926-101B-9992-00000B65C6F9}

sCLSID_Image textequ <GUID {04C599241h,06926h,0101Bh,{099h,092h,000h,000h,00Bh,065h,0C6h,0F9h}}>

;--- CommandButton, Type=COCLASS, GUID={D7053240-CE69-11CD-A777-00DD01143C57}

sCLSID_CommandButton textequ <GUID {0D7053240h,0CE69h,011CDh,{0A7h,077h,000h,0DDh,001h,014h,03Ch,057h}}>

;--- Frame, Type=COCLASS, GUID={6E182020-F460-11CE-9BCD-00AA00608E01}

sCLSID_Frame textequ <GUID {06E182020h,0F460h,011CEh,{09Bh,0CDh,000h,0AAh,000h,060h,08Eh,001h}}>

;--- TextBox, Type=COCLASS, GUID={8BD21D10-EC42-11CE-9E0D-00AA006002F3}

sCLSID_TextBox textequ <GUID {08BD21D10h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- ReturnString, Type=COCLASS, GUID={82B02375-B5BC-11CF-810F-00A0C9030074}

sCLSID_ReturnString textequ <GUID {082B02375h,0B5BCh,011CFh,{081h,00Fh,000h,0A0h,0C9h,003h,000h,074h}}>

;--- ListBox, Type=COCLASS, GUID={8BD21D20-EC42-11CE-9E0D-00AA006002F3}

sCLSID_ListBox textequ <GUID {08BD21D20h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- ReturnSingle, Type=COCLASS, GUID={8A683C92-BA84-11CF-8110-00A0C9030074}

sCLSID_ReturnSingle textequ <GUID {08A683C92h,0BA84h,011CFh,{081h,010h,000h,0A0h,0C9h,003h,000h,074h}}>

;--- ComboBox, Type=COCLASS, GUID={8BD21D30-EC42-11CE-9E0D-00AA006002F3}

sCLSID_ComboBox textequ <GUID {08BD21D30h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- ReturnEffect, Type=COCLASS, GUID={8A683C93-BA84-11CF-8110-00A0C9030074}

sCLSID_ReturnEffect textequ <GUID {08A683C93h,0BA84h,011CFh,{081h,010h,000h,0A0h,0C9h,003h,000h,074h}}>

;--- DataObject, Type=COCLASS, GUID={1C3B4210-F441-11CE-B9EA-00AA006B1A69}

sCLSID_DataObject textequ <GUID {01C3B4210h,0F441h,011CEh,{0B9h,0EAh,000h,0AAh,000h,06Bh,01Ah,069h}}>

;--- Control, Type=COCLASS, GUID={909E0AE0-16DC-11CE-9E98-00AA00574A4F}

sCLSID_Control textequ <GUID {0909E0AE0h,016DCh,011CEh,{09Eh,098h,000h,0AAh,000h,057h,04Ah,04Fh}}>

;--- HTMLSubmit, Type=COCLASS, GUID={5512D110-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLSubmit textequ <GUID {05512D110h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLImage, Type=COCLASS, GUID={5512D112-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLImage textequ <GUID {05512D112h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLReset, Type=COCLASS, GUID={5512D114-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLReset textequ <GUID {05512D114h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLCheckbox, Type=COCLASS, GUID={5512D116-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLCheckbox textequ <GUID {05512D116h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLOption, Type=COCLASS, GUID={5512D118-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLOption textequ <GUID {05512D118h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLText, Type=COCLASS, GUID={5512D11A-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLText textequ <GUID {05512D11Ah,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLHidden, Type=COCLASS, GUID={5512D11C-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLHidden textequ <GUID {05512D11Ch,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLPassword, Type=COCLASS, GUID={5512D11E-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLPassword textequ <GUID {05512D11Eh,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLSelect, Type=COCLASS, GUID={5512D122-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLSelect textequ <GUID {05512D122h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- HTMLTextArea, Type=COCLASS, GUID={5512D124-5CC6-11CF-8D67-00AA00BDCE1D}

sCLSID_HTMLTextArea textequ <GUID {05512D124h,05CC6h,011CFh,{08Dh,067h,000h,0AAh,000h,0BDh,0CEh,01Dh}}>

;--- CheckBox, Type=COCLASS, GUID={8BD21D40-EC42-11CE-9E0D-00AA006002F3}

sCLSID_CheckBox textequ <GUID {08BD21D40h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- OptionButton, Type=COCLASS, GUID={8BD21D50-EC42-11CE-9E0D-00AA006002F3}

sCLSID_OptionButton textequ <GUID {08BD21D50h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- ToggleButton, Type=COCLASS, GUID={8BD21D60-EC42-11CE-9E0D-00AA006002F3}

sCLSID_ToggleButton textequ <GUID {08BD21D60h,0EC42h,011CEh,{09Eh,00Dh,000h,0AAh,000h,060h,002h,0F3h}}>

;--- NewFont, Type=COCLASS, GUID={AFC20920-DA4E-11CE-B943-00AA006887B4}

sCLSID_NewFont textequ <GUID {0AFC20920h,0DA4Eh,011CEh,{0B9h,043h,000h,0AAh,000h,068h,087h,0B4h}}>

;--- ReturnInteger, Type=COCLASS, GUID={82B02373-B5BC-11CF-810F-00A0C9030074}

sCLSID_ReturnInteger textequ <GUID {082B02373h,0B5BCh,011CFh,{081h,00Fh,000h,0A0h,0C9h,003h,000h,074h}}>

;--- MultiPage, Type=COCLASS, GUID={46E31370-3F7A-11CE-BED6-00AA00611080}

sCLSID_MultiPage textequ <GUID {046E31370h,03F7Ah,011CEh,{0BEh,0D6h,000h,0AAh,000h,061h,010h,080h}}>

;--- Page, Type=COCLASS, GUID={5CEF5610-713D-11CE-80C9-00AA00611080}

sCLSID_Page textequ <GUID {05CEF5610h,0713Dh,011CEh,{080h,0C9h,000h,0AAh,000h,061h,010h,080h}}>

;--- ScrollBar, Type=COCLASS, GUID={DFD181E0-5E2F-11CE-A449-00AA004A803D}

sCLSID_ScrollBar textequ <GUID {0DFD181E0h,05E2Fh,011CEh,{0A4h,049h,000h,0AAh,000h,04Ah,080h,03Dh}}>

;--- ReturnBoolean, Type=COCLASS, GUID={82B02374-B5BC-11CF-810F-00A0C9030074}

sCLSID_ReturnBoolean textequ <GUID {082B02374h,0B5BCh,011CFh,{081h,00Fh,000h,0A0h,0C9h,003h,000h,074h}}>

;--- TabStrip, Type=COCLASS, GUID={EAE50EB0-4A62-11CE-BED6-00AA00611080}

sCLSID_TabStrip textequ <GUID {0EAE50EB0h,04A62h,011CEh,{0BEh,0D6h,000h,0AAh,000h,061h,010h,080h}}>

;--- end of type library ---
