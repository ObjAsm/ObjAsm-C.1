; ==================================================================================================
; Title:      RadixSortPtrI32.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop
% include &ObjMemPath&32\RadixSort.inc                  ;Helper macros

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RadixSortPtrI32
; Purpose:    Ascending sort of an array of POINTERs to structures containing a SDWORD key using a
;             modified "4 passes radix sort" algorithm.
; Arguments:  Arg1: -> Array of POINTERs.
;             Arg2: Number of POINTERs contained in the array.
;             Arg3: offset of the SDWORD key within the hosting structure.
;             Arg4: -> Memory used for the sorting process or NULL. The buffer size must be at least
;                   the size of the input array. If NULL, a memory chunk is allocated automatically.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Notes:      - Original code from r22.
;               http://www.asmcommunity.net/board/index.php?topic=24563.0
;             - For short arrays, the shadow array can be placed onto the stack, saving the
;               expensive memory allocation/deallocation API calls. To achieve this, the proc
;               must be modified and stack probing must be included.
; Links:      - http://www.codercorner.com/RadixSortRevisited.htm
;             - http://en.wikipedia.org/wiki/Radix_sort
;
;
;                array                          structures
;
;           ———————————————
;          | addr Struc 1  | —————————————————————————————————————> ——————————————  ——
;          |———————————————|                                       |      ...     |   | Offset
;          | addr Struc 2  | —————————————————————> —————————————— |——————————————| <—
;          |———————————————|                       |      ...     || SDWORD Key 1 |
;          |    ...        |                       |——————————————||——————————————|
;          |———————————————|          ..           | SDWORD Key 2 ||      ...     |
;          |               |                       |——————————————| ——————————————
;          |———————————————|                       |      ...     |
;          | addr Struc N  | —————> ——————————————  ——————————————
;           ———————————————        |      ...     |
;                                  |——————————————|
;                                  | SDWORD Key N |
;                                  |——————————————|
;                                  |      ...     |
;                                   ——————————————
;

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
RadixSortPtrI32 proc pArray:POINTER, dCount:DWORD, dOffset:DWORD, pWorkArea:POINTER
  push ebx
  mov ebx, [esp + 12]                                   ;dCount
  shl ebx, 2                                            ;ebx = Array size in bytes
  .if ZERO?
    mov eax, TRUE
  .else
    mov eax, [esp + 20]
    .if eax == NULL
      invoke VirtualAlloc, NULL, ebx, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .endif
    .if eax != NULL
      push esi
      push edi
      push ebp
      mov esi, [esp + 20]                               ;esi -> Array
      mov edi, eax                                      ;edi -> Shadow array
      mov ebp, [esp + 28]                               ;ebp = offset
      sub esp, 256*4                                    ;Make room for the counter array

      RadixPassPtr 0, edi, esi                          ;LSB
      RadixPassPtr 1, esi, edi
      RadixPassPtr 2, edi, esi

      ;Modified RadixPassPtr 3                          :MSB
      ResetRadixCounters
      CountRadixPtr 3, edi
      GetRadixCountToIndexNegFirst
      SortRadixPtr 3, esi, edi

      add esp, 256*4                                    ;Release counter array
      .if POINTER ptr [esp + 32] == NULL
        invoke VirtualFree, edi, 0, MEM_RELEASE         ;Release shadow array, return value = TRUE
      .endif
      mov eax, TRUE
      pop ebp
      pop edi
      pop esi
    .endif
  .endif
  pop ebx
  ret 12
RadixSortPtrI32 endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
