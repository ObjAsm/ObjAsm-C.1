; ==================================================================================================
; Title:      ChartFlatTabScale.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartFlatTabScale objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartFlatTabScale implementation
; ==================================================================================================


IDD_CHT_SCL_TAB                 equ   5200
IDC_CHT_SCL_AUTO_STC            equ   5201

IDC_CHT_SCL_MINVAL_CHK          equ   5202
IDC_CHT_SCL_MAXVAL_CHK          equ   5203
IDC_CHT_SCL_MJRDIV_CHK          equ   5204
IDC_CHT_SCL_MNRDIV_CHK          equ   5205

IDC_CHT_SCL_MINVAL_EDT          equ   5206
IDC_CHT_SCL_MAXVAL_EDT          equ   5207
IDC_CHT_SCL_MJRDIV_EDT          equ   5208
IDC_CHT_SCL_MNRDIV_EDT          equ   5209

IDC_CHT_SCL_SHOW_VAL_CHK        equ   5210
IDC_CHT_SCL_SHOW_DATE_CHK       equ   5211
IDC_CHT_SCL_SHOW_DATEDIFF_CHK   equ   5212
IDC_CHT_SCL_SHOW_TIME_CHK       equ   5213
IDC_CHT_SCL_MJRDIV_UDN          equ   5214
IDC_CHT_SCL_MNRDIV_UDN          equ   5215

IDC_CHT_SCL_MJRGRD_SHOW_CHK     equ   5220
IDC_CHT_SCL_MNRGRD_SHOW_CHK     equ   5221

IDC_CHT_SCL_DESC_STC            equ   5230
IDC_CHT_SCL_DESC_EDT            equ   5231
IDC_CHT_SCL_UNIT_STC            equ   5232
IDC_CHT_SCL_UNIT_EDT            equ   5233

SCL_MJRDIV_MIN    equ   0
SCL_MJRDIV_MAX    equ   20
SCL_MNRDIV_MIN    equ   0
SCL_MNRDIV_MAX    equ   10

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatTabScale.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatTabScale.CtlsGet, uses xbx xdi xsi
  local cBuffer[1024]:CHR, dFailure:DWORD

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pScaleData
  assume xdi:PCHT_SCALE_DATA

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_MINVAL_CHK
  .if eax != FALSE
    BitSet [xdi].dFlags, CHT_SCALE_AUTO_MIN
  .else
    BitClr [xdi].dFlags, CHT_SCALE_AUTO_MIN
  .endif
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SCL_MINVAL_EDT, xbx, lengthof cBuffer
  fldStr xbx
  fstp [xdi].fSetupMin

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_MAXVAL_CHK
  .if eax != FALSE
    BitSet [xdi].dFlags, CHT_SCALE_AUTO_MAX
  .else
    BitClr [xdi].dFlags, CHT_SCALE_AUTO_MAX
  .endif
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SCL_MAXVAL_EDT, xbx, lengthof cBuffer
  fldStr xbx
  fstp [xdi].fSetupMax

  .if [xdi].dID == CHT_ID_SCALEX
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_SHOW_DATE_CHK
    .if eax == BST_CHECKED
      BitSet [xdi].dFlags, CHT_SCALE_SHOW_AS_DATE
    .else
      BitClr [xdi].dFlags, CHT_SCALE_SHOW_AS_DATE
      invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_SHOW_DATEDIFF_CHK
      .if eax == BST_CHECKED
        BitSet [xdi].dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
      .else
        BitClr [xdi].dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
      .endif
    .endif

    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_SHOW_TIME_CHK
    .if eax == BST_CHECKED
      BitSet [xdi].dFlags, CHT_SCALE_SHOW_AS_TIME
    .else
      BitClr [xdi].dFlags, CHT_SCALE_SHOW_AS_TIME
    .endif

  .endif

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_CHK
  .if eax != FALSE
    BitSet [xdi].dFlags, CHT_SCALE_AUTO_MJR_DIV
  .else
    BitClr [xdi].dFlags, CHT_SCALE_AUTO_MJR_DIV
  .endif
  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_EDT, addr dFailure, FALSE
  .if dFailure != FALSE
    .if (eax >= SCL_MJRDIV_MIN) && (eax <= SCL_MJRDIV_MAX)
      mov [xdi].dSetupMjrDiv, eax
    .endif
  .endif

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_CHK
  .if eax != FALSE
    BitSet [xdi].dFlags, CHT_SCALE_AUTO_MNR_DIV
  .else
    BitClr [xdi].dFlags, CHT_SCALE_AUTO_MNR_DIV
  .endif

  invoke GetDlgItemInt, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_EDT, addr dFailure, FALSE
  .if dFailure != FALSE
    .if (eax >= SCL_MNRDIV_MIN) && (eax <= SCL_MNRDIV_MAX)
      mov [xdi].dSetupMnrDiv, eax
    .endif
  .endif

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_MJRGRD_SHOW_CHK
  .if eax != FALSE
    BitSet [xdi].dFlags, CHT_SCALE_SHOW_MJR_GRID
  .else
    BitClr [xdi].dFlags, CHT_SCALE_SHOW_MJR_GRID
  .endif

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHT_SCL_MNRGRD_SHOW_CHK
  .if eax != FALSE
    BitSet [xdi].dFlags, CHT_SCALE_SHOW_MNR_GRID
  .else
    BitClr [xdi].dFlags, CHT_SCALE_SHOW_MNR_GRID
  .endif

  invoke StrDispose, [xdi].pDescription
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SCL_DESC_EDT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pDescription, xax

  invoke StrDispose, [xdi].pUnit
  invoke GetDlgItemText, [xsi].hWnd, IDC_CHT_SCL_UNIT_EDT, xbx, lengthof cBuffer
  .if eax == 0
    xor eax, eax
  .else
    invoke StrNew, xbx
  .endif
  mov [xdi].pUnit, xax

  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatTabScale.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatTabScale.CtlsSet, uses xbx xdi xsi
  local cBuffer[256]:CHR

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pScaleData
  assume xdi:PCHT_SCALE_DATA

  .ifBitSet [xdi].dFlags, CHT_SCALE_AUTO_MIN
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MINVAL_EDT), FALSE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MINVAL_CHK, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MINVAL_EDT), TRUE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MINVAL_CHK, BST_UNCHECKED
  .endif
  fld [xdi].fSetupMin
  invoke St0ToStr, xbx, 0, -1, f_NOR or f_TRIM
  fUnload
  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SCL_MINVAL_EDT, xbx

  .ifBitSet [xdi].dFlags, CHT_SCALE_AUTO_MAX
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MAXVAL_EDT), FALSE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MAXVAL_CHK, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MAXVAL_EDT), TRUE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MAXVAL_CHK, BST_UNCHECKED
  .endif
  fld [xdi].fSetupMax
  invoke St0ToStr, xbx, 0, -1, f_NOR or f_TRIM
  fUnload
  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SCL_MAXVAL_EDT, xbx

  .if [xdi].dID == CHT_ID_SCALEX
    .ifBitSet [xdi].dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
      invoke CheckRadioButton, [xsi].hWnd, IDC_CHT_SCL_SHOW_VAL_CHK, IDC_CHT_SCL_SHOW_DATEDIFF_CHK, IDC_CHT_SCL_SHOW_DATEDIFF_CHK
    .elseIfBitSet [xdi].dFlags, CHT_SCALE_SHOW_AS_DATE
      invoke CheckRadioButton, [xsi].hWnd, IDC_CHT_SCL_SHOW_VAL_CHK, IDC_CHT_SCL_SHOW_DATEDIFF_CHK, IDC_CHT_SCL_SHOW_DATE_CHK
    .else
      invoke CheckRadioButton, [xsi].hWnd, IDC_CHT_SCL_SHOW_VAL_CHK, IDC_CHT_SCL_SHOW_DATEDIFF_CHK, IDC_CHT_SCL_SHOW_VAL_CHK
    .endif

    .ifBitSet [xdi].dFlags, CHT_SCALE_SHOW_AS_TIME
      invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_SHOW_TIME_CHK, BST_CHECKED
    .else
      invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_SHOW_TIME_CHK, BST_UNCHECKED
    .endif
  .endif

  .ifBitSet [xdi].dFlags, CHT_SCALE_AUTO_MJR_DIV
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_EDT), FALSE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_CHK, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_EDT), TRUE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_CHK, BST_UNCHECKED
  .endif
  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_EDT, [xdi].dSetupMjrDiv, FALSE

  .ifBitSet [xdi].dFlags, CHT_SCALE_AUTO_MNR_DIV
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_EDT), FALSE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_CHK, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_EDT), TRUE
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_CHK, BST_UNCHECKED
  .endif
  invoke SetDlgItemInt, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_EDT, [xdi].dSetupMjrDiv, FALSE

  .ifBitSet [xdi].dFlags, CHT_SCALE_SHOW_MJR_GRID
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MJRGRD_SHOW_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MJRGRD_SHOW_CHK, BST_UNCHECKED
  .endif

  .ifBitSet [xdi].dFlags, CHT_SCALE_SHOW_MNR_GRID
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MNRGRD_SHOW_CHK, BST_CHECKED
  .else
    invoke CheckDlgButton, [xsi].hWnd, IDC_CHT_SCL_MNRGRD_SHOW_CHK, BST_UNCHECKED
  .endif

  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SCL_DESC_EDT, [xdi].pDescription

  invoke SetDlgItemText, [xsi].hWnd, IDC_CHT_SCL_UNIT_EDT, [xdi].pUnit

  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatTabScale.Done
; Purpose:    Finalize the ChartFlatTabSeries object.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatTabScale.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pLocalDescription
  invoke StrDispose, [xsi].pLocalUnit
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatTabScale.Init
; Purpose:    Initialize the ChartFlatTabScale object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> CHT_SCALE_DATA.
; Return:     Nothing.

Method ChartFlatTabScale.Init, uses xbx xsi, pOwner:POINTER, pScaleData:PCHT_SCALE_DATA
  SetObject xsi
  mov xbx, pOwner
  ACall xsi.Init, xbx, [xbx].$Obj(TabCtrl).hWnd, IDD_CHT_SCL_TAB, \
                  offset $ObjTmpl(Application).hActiveMlsDlg
  mrm [xsi].pScaleData, pScaleData, xbx

  ;Create local copies
  assume xbx:PCHT_SCALE_DATA
  invoke MemClone, addr [xsi].LocalScaleData, xbx, \
                   sizeof(CHT_SCALE_BASIC_DATA) - sizeof(CHT_SCALE_STRINGS)
  mov [xsi].pLocalDescription, $invoke(StrNew, [xbx].pDescription)
  mov [xsi].pLocalUnit, $invoke(StrNew, [xbx].pUnit)
  assume xbx:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatTabScale.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartFlatTabScale.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  movZX edi, WORD ptr wParam                            ;Get Low WORD in edi
  .if (edi >= IDC_CHT_SCL_MINVAL_CHK) && (edi <= IDC_CHT_SCL_MNRDIV_CHK)
    .if WORD ptr [wParam + sizeof(WORD)] == BN_CLICKED  ;Test High WORD
      invoke GetDlgItem, [xsi].hWnd, addr [edi + IDC_CHT_SCL_MINVAL_EDT - IDC_CHT_SCL_MINVAL_CHK]
      mov xbx, xax
      invoke IsDlgButtonChecked, [xsi].hWnd, edi
      .if eax == BST_CHECKED
        invoke EnableWindow, xbx, FALSE
      .else
        invoke EnableWindow, xbx, TRUE
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatTabScale.OnCtlColorDlg
; Purpose:    Event procedure for WM_CTLCOLORDLG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Brush to paint the background.

Method ChartFlatTabScale.OnCtlColorDlg,, wParam:WPARAM, lParam:LPARAM
  invoke GetStockObject, WHITE_BRUSH
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatTabScale.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

Method ChartFlatTabScale.OnInitDialog, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  ;Hide radiobuttons if the sacale is nit ScaleX
  mov xcx, [xsi].pScaleData
  .if [xcx].CHT_SCALE_DATA.dID != CHT_ID_SCALEX
    invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_SHOW_VAL_CHK
    invoke ShowWindow, xax, SW_HIDE
    invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_SHOW_DATE_CHK
    invoke ShowWindow, xax, SW_HIDE
    invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_SHOW_DATEDIFF_CHK
    invoke ShowWindow, xax, SW_HIDE
    invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_SHOW_TIME_CHK
    invoke ShowWindow, xax, SW_HIDE
  .endif

  ;Associate UDN-Controls
  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_UDN)
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MJRDIV_EDT
  invoke SendMessage, xbx, UDM_SETBUDDY, xax, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, SCL_MJRDIV_MIN, SCL_MJRDIV_MAX

  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_UDN)
  invoke GetDlgItem, [xsi].hWnd, IDC_CHT_SCL_MNRDIV_EDT
  invoke SendMessage, xbx, UDM_SETBUDDY, xax, 0
  invoke SendMessage, xbx, UDM_SETRANGE32, SCL_MNRDIV_MIN, SCL_MNRDIV_MAX

  ACall xsi.OnInitDialog, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartFlatTabScale.Restore
; Purpose:    Restore original values.
; Arguments:  None.
; Return:     Nothing.

Method ChartFlatTabScale.Restore, uses xbx xsi
  SetObject xsi

  ;Restore from local copies
  mov xbx, [xsi].pScaleData
  assume xbx:PCHT_SCALE_BASIC_DATA
  invoke MemClone, xbx, addr [xsi].LocalScaleData, \
                   sizeof(CHT_SCALE_BASIC_DATA) - sizeof(CHT_SCALE_STRINGS)
  invoke StrDispose, [xbx].pDescription
  mov [xbx].pDescription, $invoke(StrNew, [xsi].pLocalDescription)
  invoke StrDispose, [xbx].pUnit
  mov [xbx].pUnit, $invoke(StrNew, [xsi].pLocalUnit)
  assume xbx:NOTHING
MethodEnd
