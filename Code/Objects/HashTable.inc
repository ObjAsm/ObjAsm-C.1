; ==================================================================================================
; Title:      HashTable.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of HashTable objects.
; Notes:      Version C.1.0, January 2022
;             - First release.
; Links:      - http://libhashish.sourceforge.net/
;             - http://isthe.com/chongo/tech/comp/fnv/       in particular the FNV-1a algorithm
; ==================================================================================================


HTL_BUCKET_EMPTY    equ   NULL

HTL_ITEM struc
  xHash   XWORD     ?           ;Hash value, always the first member!
HTL_ITEM ends
PHTL_ITEM typedef ptr HTL_ITEM

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     HashTable
; Purpose:    Base object for HashTable descendants.
;             This object implements an Unordered Associative Container.
; Note;       The first member of the Item structure must be an XWORD to thold the Hash.
;             The items are only accessed via the key values.
;
;
;                            Buckets                                Items
;                           (POINTER)
;                           —————————                —————————————————————————————————————
;             pBuckets --> |         | -----------> | xHash | Key | Value1 | Value2 | ... |
;                          |—————————|              |———————|—————|————————|————————|—————|
;                          |  EMPTY  |    --------> | xHash | Key | Value1 | Value2 | ... |
;                          |—————————|   |          |———————|—————|————————|————————|—————|
;                          |  EMPTY  |   |   -----> | xHash | Key | Value1 | Value2 | ... |
;                          |—————————|   |  |       |———————|—————|————————|————————|—————|
;                          |         | --   |   --> | xHash | Key | Value1 | Value2 | ... |
;                          |—————————|      |  |     —————————————————————————————————————
;                          |  EMPTY  |      |  |
;                          |—————————|      |  |
;                          |         | -----   |
;                          |—————————|         |
;                          |         | --------
;                          |—————————|
;                          |  EMPTY  |
;                           —————————
;

Object HashTable, HashTableID, Streamable
  VirtualAbstract   Delete,           POINTER
  VirtualMethod     DeleteAll
  DynamicMethod     DestroyItem,      PHTL_ITEM
  VirtualMethod     Dispose,          POINTER
  VirtualMethod     DisposeAll
  RedefineMethod    Done
  VirtualAbstract   GetItemKey,       PHTL_ITEM
  VirtualAbstract   Hash,             POINTER
  RedefineMethod    Init,             POINTER, DWORD
  VirtualMethod     Insert,           PHTL_ITEM
  VirtualAbstract   OnCollision,      XWORD
  VirtualMethod     Resize,           DWORD                 ;Resize to new limit
  VirtualAbstract   Search,           POINTER

  DefineVariable    dBucketMaxCount,  DWORD,        0FFFFFFFFh/sizeof(POINTER)
  DefineVariable    dBucketCount,     DWORD,        0
  DefineVariable    dBucketsUsed,     DWORD,        0
  DefineVariable    dMask,            DWORD,        0
  DefineVariable    pBuckets,         POINTER,      NULL

  DefineVariable    dCollisionCount,  DWORD,        0       ;Hash performance indicator
  DefineVariable    ObjLock,          OBJECT_LOCK,  {}      ;Locking struc for multithreaded access

ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HashTable.DeleteAll
; Purpose:    Remove all item POINTERs, setting all Buckets to HTL_BUCKET_EMPTY.
;             No memory is freed!
; Arguments:  None.
; Return:     Nothing.

Method HashTable.DeleteAll
  SetObject xcx
  mov eax, [xcx].dBucketCount
  mov xdx, [xcx].pBuckets
  test eax, eax
  .while !ZERO?
    mov POINTER ptr [xdx], HTL_BUCKET_EMPTY
    add xdx, sizeof(POINTER)
    dec eax
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    HashTable.DestroyItem
; Purpose:   Auxiliary procedure to dispose a item in the collection. Don't call directly!
; Arguments: Arg1: -> Item.
; Return:    Nothing.

Method HashTable.DestroyItem,, pItem:PHTL_ITEM
  .if pItem != NULL
    MemFree pItem                                       ;Frees the Item from process heap
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HashTable.Dispose
; Purpose:    Dispose an item.
; Arguments:  Arg1: -> Key. This argument should never be NULL.
; Return:     Nothing.

Method HashTable.Dispose, uses xsi, pKey:POINTER
  ArgReg pKey:rdx

  SetObject xsi
  OCall xsi.Delete, $ArgReg(pKey)
  .if xax != NULL
    OCall xsi.DestroyItem, xax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HashTable.DisposeAll
; Purpose:    Dispose of all items in the collection.
; Arguments:  None.
; Return:     Nothing.

Method HashTable.DisposeAll, uses xbx xdi xsi
  SetObject xsi
  mov ebx, [xsi].dBucketCount
  mov xdi, [xsi].pBuckets
  test ebx, ebx
  .while !ZERO?
    mov xdx, POINTER ptr [xdi]
    .if xdx != NULL
      OCall xsi.DestroyItem, xdx
      mov POINTER ptr [xdi], HTL_BUCKET_EMPTY
    .endif
    add xdi, sizeof(POINTER)
    dec ebx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HashTable.Done
; Purpose:    Destructor method.
; Arguments:  Nothing.
; Return:     None.

Method HashTable.Done, uses xsi
  SetObject xsi
  mov xax, [xsi].pBuckets
  .if xax != NULL
    MemFree xax
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HashTable.Init
; Purpose:    Initialize the HashTable object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial Bucket count.
; Return:     eax = Error code.

Method HashTable.Init, uses xsi, pOwner:POINTER, dBucketCount:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  mov eax, dBucketCount
  .if eax != 0
    mov [xsi].dBucketCount, eax
    shl eax, $Log2(sizeof(POINTER))                       ;eax = Entries * sizeof(POINTER)
    MemAlloc eax, MEM_INIT_ZERO
    .if xax != NULL
      mov [xsi].pBuckets, xax
      mov ecx, [xsi].dBucketCount
      dec ecx
      mov [xsi].dMask, ecx
      xor eax, eax
    .else
      OCall xsi.ErrorReport, NULL, HTL_OUT_OF_MEMORY
    .endif
  .else
    OCall xsi.ErrorReport, NULL, HTL_INVALID_ARGUMENT
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HashTable.Insert
; Purpose:    Insert a new Item.
; Arguments:  Arg1: -> Item.
; Return:     xax = Hash or 0 if failed.

Method HashTable.Insert, uses xsi, pItem:PHTL_ITEM
  local xHash:XWORD

;  DbgText "Dictionary.Insert"
  SetObject xsi
  OCall xsi.GetItemKey, pItem
  OCall xsi.Hash, xax
  mov xHash, xax
  mov ecx, [xsi].dMask
  and xcx, xax                                          ;ecx is used as index into the bucket array
;  DbgDec ecx, "Index"

  mov xdx, [xsi].pBuckets
  lea xdx, [xdx + sizeof(POINTER)*xcx]
  .if POINTER ptr [xdx] == NULL
    m2m POINTER ptr [xdx], pItem, xcx
    mov XWORD ptr [xcx], xax                            ;Save hash value
  .else
    inc [xsi].dCollisionCount
    OCall xsi.OnCollision, xHash                        ;eax = new index
    .if eax == -1
      OCall xsi.ErrorReport, NULL, HTL_TABLE_FULL
      xor eax, eax
    .else
;      DbgDec eax, "Inserted at"
      mov xdx, [xsi].pBuckets
      mrm POINTER ptr [xdx + sizeof(POINTER)*xax], pItem, xcx     ;Insert
      m2m XWORD ptr [xcx], xHash, xax
      inc [xsi].dBucketsUsed
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     HashTable.Resize
; Purpose:    Resize the HashTable, allocating the necessary memory on the heap to hold
;             the Buckets table.
; Arguments:  Arg1: New size (Bucket Count). It must be a power of 2.
; Return:     eax = Error code.

Method HashTable.Resize, uses xbx xdi xsi, dNewSize:DWORD
  ArgReg dNewSize:edx

  SetObject xsi
  mov ebx, $ArgReg(dNewSize)
  mov eax, [xsi].dBucketCount
  cmp eax, ebx                                          ;dNewSize
  ja @@1                                                ;NewSize can not be less than dBucketCount!
  mov eax, [xsi].dBucketMaxCount
  cmp eax, ebx                                          ;NewSize can not be > than dBucketMaxCount!
  jae @@2
@@1:
  mov ebx, eax                                          ;Limit the new collection size
@@2:
  mov ecx, [xsi].dBucketCount
  cmp ecx, ebx
  jne @@3
  xor eax, eax                                          ;eax = OBJ_OK
  ret

@@3:
  test ebx, ebx                                         ;dNewSize = 0 ?
  jne @@4
  MemFree [xsi].pBuckets, MEM_SAFE_FREE
  xor eax, eax                                          ;eax = OBJ_OK
  mov [xsi].pBuckets, xax                               ;NULL
  mov [xsi].dBucketCount, eax                           ;0
  mov [xsi].dMask, eax
  ret

@@4:
  mov edi, ebx
  shl edi, $Log2(sizeof(POINTER))                       ;xdx*sizeof(POINTER)
  mov xax, [xsi].pBuckets
  test xax, xax
  jne @@5
  MemAlloc edi
  test xax, xax                                         ;Function failed?
  jz @@Error
  mov [xsi].pBuckets, xax
  mov [xsi].dBucketCount, ebx                           ;dNewSize
  dec ebx
  mov [xsi].dMask, ebx
  xor eax, eax                                          ;eax = OBJ_OK (return value)
  ret

@@5:
  MemReAlloc xax, edi
  test xax, xax                                         ;Function failed?
  jz @@Error
  mov [xsi].pBuckets, xax
  mov [xsi].dBucketCount, ebx                           ;dNewSize
  dec ebx
  mov [xsi].dMask, ebx
  xor eax, eax                                          ;eax = OBJ_OK (return value)
  ret

@@Error:
  mov eax, COL_OUT_OF_MEMORY                            ;Return value
MethodEnd

endif
