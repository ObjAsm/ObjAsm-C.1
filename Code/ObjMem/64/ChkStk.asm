;*******************************************************************************
;
;       Copyright (c) Microsoft Corporation. All rights reserved.
;
; Purpose:
;       Provides support for automatic stack checking in C procedures
;       when stack checking is enabled.
;
; __chkstk - check stack upon procedure entry
;
; Purpose:
;       Provide stack checking on procedure entry. Method is to simply probe
;       each page of memory required for the stack in descending order. This
;       causes the necessary pages of memory to be allocated via the guard
;       page scheme, if possible. In the event of failure, the OS raises the
;       _XCPT_UNABLE_TO_GROW_STACK exception.
;
;       NOTE:  Currently, the (EAX < PAGESIZE) code path falls through
;       to the "lastpage" label of the (EAX >= PAGESIZE) code path.  This
;       is small; a minor speed optimization would be to special case
;       this up top.  This would avoid the painful save/restore of
;       ecx and would shorten the code path by 4-6 instructions.
;
; Entry:
;       EAX = size of local frame
;
; Exit:
;       ESP = new stackframe, if successful
;
; Uses:
;       EAX
;
; Exceptions:
;       _XCPT_GUARD_PAGE_VIOLATION - May be raised on a page probe. NEVER TRAP
;                                    THIS!!!! It is used by the OS to grow the
;                                    stack on demand.
;       _XCPT_UNABLE_TO_GROW_STACK - The stack cannot be grown. More precisely,
;                                    the attempt by the OS memory manager to
;                                    allocate another guard page in response
;                                    to a _XCPT_GUARD_PAGE_VIOLATION has
;                                    failed.
;
;*******************************************************************************

% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
align ALIGN_CODE
_chkstk proc c
  ret
_chkstk endp

end
