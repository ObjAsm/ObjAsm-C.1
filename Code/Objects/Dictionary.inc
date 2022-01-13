; ==================================================================================================
; Title:      Dictionary.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Dictionary objects.
; Notes:      Version C.1.0, January 2022
;             - First release.
; ==================================================================================================


DIC_PERTURB_SHIFT     equ 5

DIC_ITEM struc
  HTL_ITEM            {}
  pKey      PSTRING   ?           ;Key, usually a POINTER to data/String
  dValue    DWORD     ?           ;Payload
DIC_ITEM ends
PDIC_ITEM typedef ptr DIC_ITEM


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Dictionary
; Purpose:    HashTable derived object. Ti resolve collisions, we use open addressing.
;             dBucketCount is always a power of 2.
; Links:      https://www.data-structures-in-practice.com/hash-tables/

Object Dictionary, DictionaryID, HashTable
  RedefineMethod    Delete,           PSTRING
  RedefineMethod    GetItemKey,       PDIC_ITEM
  RedefineMethod    Hash,             PSTRING
  RedefineMethod    OnCollision,      XWORD
  RedefineMethod    Search,           PSTRING
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Dictionary.Delete
; Purpose:    Delete an item from the Dictionary using a Key.
; Arguments:  Arg1: -> Key. This argument should never be NULL.
; Return:     xax -> Item or NULL if the item is not in the Dictionary.

Method Dictionary.Delete, uses xbx xdi xsi, pKey:PSTRING
  local dDelIndex:DWORD, dLastIndex:DWORD, xHash:XWORD

;  DbgText "Dictionary.Delete"
  SetObject xsi
  OCall xsi.Hash, pKey
;  DbgHex xax
  mov xHash, xax
  mov xdi, xax                                            ;Remember the hash
  mov ebx, [xsi].dMask
  and xbx, xax                                            ;ebx is used as index into a pointer array

  ;Search for the correct item where the hash and the Key match
  .while TRUE
    mov xdx, [xsi].pBuckets
    mov xax, POINTER ptr [xdx + sizeof(POINTER)*xbx]
    .if xax == HTL_BUCKET_EMPTY
      DbgText "Not found"
      ExitMethod
    .endif
    invoke StrComp, pKey, [xax].DIC_ITEM.pKey
    .break .if eax == 0                                   ;Found => exit loop
    shr xdi, DIC_PERTURB_SHIFT                            ;edi = Perturbation
    lea ebx, [4*ebx + ebx + 1]
    add ebx, edi
    and ebx, [xsi].dMask
  .endw
;  DbgDec ebx
  mov dDelIndex, ebx

  ;Search the last alternate bucket
  .while TRUE
    mov dLastIndex, ebx                                   ;Save last index where we have a hash match
    @@:
    shr xdi, DIC_PERTURB_SHIFT                            ;edi = Perturbation
    lea ebx, [4*ebx + ebx + 1]
    add ebx, edi
    and ebx, [xsi].dMask
    cmp ebx, dDelIndex
    jz @B                                                 ;Skip if the alt. index = DelIndex
    mov xdx, [xsi].pBuckets
    mov xax, POINTER ptr [xdx + sizeof(POINTER)*xbx]
    .break .if  xax == HTL_BUCKET_EMPTY
    mov xdx, xHash
    sub xdx, [xax].DIC_ITEM.xHash
    jnz @B
  .endw
;  DbgDec dLastIndex

  mov ecx, dDelIndex
  mov eax, dLastIndex
  mov xdx, [xsi].pBuckets
  dec [xsi].dBucketsUsed
  ReleaseObject
  .if eax == ecx                                          ;The actual index is the last one
    mov POINTER ptr [xdx + sizeof(POINTER)*xcx], HTL_BUCKET_EMPTY
  .else
    lea xbx, [xdx + sizeof(POINTER)*xax]
    mov xsi, POINTER ptr [xbx]
    mov POINTER ptr [xbx], HTL_BUCKET_EMPTY
    mov POINTER ptr [xdx + sizeof(POINTER)*xcx], xsi
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Dictionary.GetItemKey
; Purpose:    Return the pointer to the item key.
; Arguments:  Arg1: -> Item. This argument should never be NULL.
; Return:     xax -> Key.

Method Dictionary.GetItemKey,, pItem:PDIC_ITEM
;  DbgText "Dictionary.GetItemKey"
  ?mov edx, pItem
  mov xax, [xdx].DIC_ITEM.pKey
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Dictionary.Hash
; Purpose:    Computs the hash value based on the item input data.
;             This is the "Fowler/Noll/Vo" or FNV hash.
; Arguments:  Arg1: -> Key.
; Return:     xax = Hash.
; Link:       https://create.stephan-brumme.com/fnv-hash/
;             http://www.isthe.com/chongo/tech/comp/fnv/#FNV-1
;             CPython uses SipHash
;
; FNV-1a      hash = offset_basis
;             for each octet_of_data to be hashed
;               hash = hash xor octet_of_data
;               hash = hash * FNV_prime
;             return hash

Method Dictionary.Hash, uses xbx xdi, pKey:PSTRING
  mov xcx, pKey                                           ;Use xcx as pointer since xdx is destroyed
  if TARGET_BITNESS eq 32                                 ;by the multiplication
    mov eax, 0811C9DC5h                                   ;Offset Basis 32
    mov edi, 001000193h                                   ;FNV-1a Prime 32 (224 + 28 + 0x93)
  else
    mov rax, 000000100000001b3h                           ;Offset Basis 64
    mov rdi, 0cbf29ce484222325h                           ;FNV-1a Prime 64 (240 + 28 + 0xb3)
  endif
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    .while TRUE
      movzx ebx, BYTE ptr [xcx]
      test ebx, ebx
      .break .if ZERO?
      xor xax, xbx
      mul xdi
      inc xcx                                             ;Move to next BYTE
    .endw
  else
    .while TRUE
      movzx ebx, WORD ptr [xcx]
      test ebx, ebx
      .break .if ZERO?
      and xbx, 0FFh
      xor xax, xbx
      mul xdi
      inc xcx                                             ;Move to next BYTE
      movzx ebx, BYTE ptr [xcx]
      xor xax, xbx
      mul xdi
      inc xcx                                             ;Move to next BYTE
    .endw
  endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Dictionary.OnCollision
; Purpose:    Internal collision handler. Since we are using open addressing, we will start probing
;             with a perturbation we get from the upper bits of the hash.
; Arguments:  Arg1: Hash value.
; Return:     eax = new alternate insertion index.

Method Dictionary.OnCollision, uses xbx xsi, xHash:XWORD
;  DbgText "Dictionary.OnCollision"
;  DbgHex xHash
  SetObject xsi
  mov xcx, xHash
  mov ebx, [xsi].dBucketCount
  dec ebx                                                 ;ebx = Mask
  mov xax, xcx
  and xax, xbx                                            ;eax = index
  mov xdx, [xsi].pBuckets
  ReleaseObject

  .repeat
    shr xcx, DIC_PERTURB_SHIFT                            ;eax = Perturbation
    lea eax, [4*eax + eax + 1]
    add eax, ecx
    and eax, ebx
;    DbgDec eax, "test alternate index"
  .until POINTER ptr [xdx + sizeof(POINTER)*xax] == HTL_BUCKET_EMPTY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Dictionary.Search
; Purpose:    Search in the Dictionary for a given Key.
; Arguments:  Arg1: -> Key
; Return:     xax -> Item or NULL if not found.

Method Dictionary.Search, uses xbx xdi xsi, pKey:PSTRING
;  DbgText "Dictionary.Search"
  SetObject xsi
  OCall xsi.Hash, pKey
  mov xdi, xax                                            ;Remember the hash
  mov ebx, [xsi].dMask
  and xbx, xax                                            ;ebx is used as index into a pointer array

  ;Search for the correct item where the hash and the Key match
  .while TRUE
    mov xdx, [xsi].pBuckets
    mov xax, POINTER ptr [xdx + sizeof(POINTER)*xbx]
    .if xax == HTL_BUCKET_EMPTY
      DbgText "Not found"
      ExitMethod
    .endif
    invoke StrComp, pKey, [xax].DIC_ITEM.pKey
    .break .if eax == 0                                   ;Found => exit loop
    shr xdi, DIC_PERTURB_SHIFT                            ;edi = Perturbation
    lea ebx, [4*ebx + ebx + 1]
    add ebx, edi
    and ebx, [xsi].dMask
  .endw
  mov xdx, [xsi].pBuckets
  mov xax, POINTER ptr [xdx + sizeof(POINTER)*xbx]
MethodEnd

endif
