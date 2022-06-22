; ==================================================================================================
; Title:      MemAllocX_UEFI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include &ObjMemPath&ObjMemUEFI.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemAlloc_UEFI
; Purpose:    Allocate a memory block.
; Arguments:  Arg1: Memory block attributes [0, MEM_INIT_ZERO].
;             Arg2: Memory block size in BYTEs.
; Return:     xax -> Memory block or NULL if failed.

align ALIGN_CODE
MemAlloc_UEFI proc uses xbx dAttr:DWORD, dMemSize:DWORD
  local pMemBlock:POINTER
  
  mov xbx, pBootServices
  invoke [xbx].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_TYPE_EfiBootServicesData, \
                                               dMemSize, addr pMemBlock
  .ifBitSet xax, EFI_ERROR
    xor eax, eax
  .else
    .ifBitSet dAttr, MEM_INIT_ZERO
      invoke MemZero, pMemBlock, dMemSize
    .endif
    mov xax, pMemBlock
  .endif
  ret 
MemAlloc_UEFI endp