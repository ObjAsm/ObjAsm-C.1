; ==================================================================================================
; Title:      LSLL.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of "Linear Simply Linked List" macros.
; Notes:      No sanity checks are performed by this set of macros!
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;This structure describes the members stored in the Simply Linked List.
;Each member contains a pointer to the next member.
;
;
;
;   FirstMember -> LSLL_ITEM_0
;                        |
;                        V
;                  LSLL_ITEM_1
;                        |
;
;                        .
;                        .
;                        .
;
;                        |
;                        V
;                  LSLL_ITEM_N
;                        |
;                        V
;                      (NULL)
;


; ==================================================================================================


PLSLL_ITEM typedef ptr LSLL_ITEM
LSLL_ITEM struc
  pLinkFwrd     PLSLL_ITEM    ?                         ;-> Next member
LSLL_ITEM ends

PLSLL_CONTROL typedef ptr LSLL_CONTROL
LSLL_CONTROL struc
  pFirstMember  PLSLL_ITEM    ?                         ;-> First member
LSLL_CONTROL ends

; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LSLL.InsertAfter
; Purpose:    Insert an object after another in the linked list.
; Arguments:  Arg1: -> Member to insert after.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register.

LSLL_InsertAfter macro RefReg:req, NewReg:req, AuxReg:=<>
  m2m [NewReg].LSLL_ITEM.pLinkFwrd, [RefReg].LSLL_ITEM.pLinkFwrd, AuxReg
  mov [RefReg].LSLL_ITEM.pLinkFwrd, NewReg
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LSLL_RemoveAfter
; Purpose:    Remove a member from the linked list.
; Arguments:  Arg1: -> Member to remove after.
;             Arg2: Auxiliar register, default is xcx.

LSLL_RemoveAfter macro RefReg:req, AuxReg:=<xcx>
  mov AuxReg, [RefReg].LSLL_ITEM.pLinkFwrd
  m2m [RefReg].LSLL_ITEM.pLinkFwrd, [AuxReg].LSLL_ITEM.pLinkFwrd, AuxReg
endm
