; ==================================================================================================
; Title:      MdiApp.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of memory streaming objects.
; Notes:      Version C.1.2, december 2020
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  MemoryStream
; Purpose: Implements an "in memory" stream.

Object MemoryStream, MemoryStreamID, Stream
  RedefineMethod    BinRead,      POINTER, DWORD      ;-> Buffer, Count
  RedefineMethod    BinWrite,     POINTER, DWORD      ;-> Buffer, Count
  VirtualMethod     BufferLoad,   POINTER, DWORD      ;-> Buffer, Size
  VirtualMethod     BufferSave,   POINTER             ;-> Buffer
  RedefineMethod    Done
  VirtualMethod     FileLoad,     PSTRING             ;-> FileName
  VirtualMethod     FileSave,     PSTRING             ;-> FileName
  RedefineMethod    GetPos                            ;Returns QWORD edx::eax
  RedefineMethod    GetSize                           ;Returns QWORD edx::eax
  RedefineMethod    Init,         POINTER, DWORD, DWORD, DWORD  ;-> Owner, Capacity, Increment, Max.
  RedefineMethod    Seek,         QWORD               ;Position
  StaticMethod      SetCapacity,  DWORD
  RedefineMethod    Truncate

  DefineVariable    pBuffer,      POINTER,      NULL  ;-> Storage buffer
  DefineVariable    dCurrSize,    DWORD,        0     ;Storage fill
  DefineVariable    dPosition,    DWORD,        0     ;Current position into storage
  DefineVariable    dLimit,       DWORD,        0     ;Current storage capacity
  DefineVariable    dDelta,       DWORD,        0     ;Storage capacity increment
  DefineVariable    dMaxSize,     DWORD,        0     ;Maximal storage capacity
  DefineVariable    ObjLock,      OBJECT_LOCK,  {}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.BinRead
; Purpose:    Reads a number of bytes from stream at the current position to a buffer.
; Arguments:  Arg1: -> Buffer.
;             Arg2: Number of bytes to read.
; Return:     eax = Bytes read.

Method MemoryStream.BinRead, uses xsi, pBuffer:POINTER, dCount:DWORD
  SetObject xsi
  .if [xsi].dErrorCode != OBJ_OK
    xor eax, eax
  .else
    mov eax, [xsi].dPosition
    mov ecx, [xsi].dCurrSize
    sub ecx, eax
    .if ecx < dCount
      OCall xsi.ErrorReport, NULL, STM_READ_ERROR
      xor eax, eax
    .else
      add xax, [xsi].pBuffer
      invoke MemClone, pBuffer, xax, dCount
      mov eax, dCount                               ;Set return value
      add [xsi].dPosition, eax
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.BinWrite
; Purpose:    Write should write Count bytes from Buffer onto the stream and advance the
;             current position of the stream by Count bytes.
; Arguments:  Arg1: -> Buffer.
;             Arg2: Number of bytes to write.
; Return:     eax = Bytes written.

Method MemoryStream.BinWrite, uses xsi, pBuffer:POINTER, dCount:DWORD
  SetObject xsi
  .if [xsi].dErrorCode != OBJ_OK
    xor eax, eax
  .else
    mov ecx, [xsi].dPosition
    add ecx, dCount
    mov eax, [xsi].dLimit
    .if eax < ecx
      align ALIGN_CODE
      .repeat
        add eax, [xsi].dDelta
      .until eax >= ecx
      .if eax <= [xsi].dMaxSize
        OCall xsi.SetCapacity, eax
        ExitMethod .if [xsi].dErrorCode !!= OBJ_OK
      .else
        OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
      .endif
    .endif
    mov eax, [xsi].dPosition
    add xax, [xsi].pBuffer
    invoke MemClone, xax, pBuffer, dCount
    mov eax, dCount                               ;Set return value
    add [xsi].dPosition, eax
    mov edx, [xsi].dPosition
    cmp edx, [xsi].dCurrSize
    jbe @@EOM
    mov [xsi].dCurrSize, edx                      ;Adjust dCurrSize
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.BufferLoad
; Purpose:    Loads the stream content from a buffer.
; Arguments:  Arg1: -> Buffer.
;             Arg2: Buffer size in bytes.
; Return:     Nothing.

Method MemoryStream.BufferLoad, uses xsi, pBuffer:POINTER, dSize:DWORD
  SetObject xsi
  mov eax, [xsi].dLimit
  .if eax < dSize
    align ALIGN_CODE
    .repeat
      add eax, [xsi].dDelta
    .until eax >= dSize
    .if eax > [xsi].dMaxSize
      OCall xsi.ErrorReport, NULL, STM_OVERFLOW
      ExitMethod
    .else
      and [xsi].dCurrSize, 0                      ;Forget old content!
      OCall xsi.SetCapacity, eax
      ExitMethod .if [xsi].dErrorCode !!= OBJ_OK
    .endif
  .endif
  invoke MemClone, [xsi].pBuffer, pBuffer, dSize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.BufferSave
; Purpose:    Saves the stream content to a buffer.
; Arguments:  Arg1: -> Buffer.
; Return:     Nothing.

Method MemoryStream.BufferSave,, pBuffer:POINTER
  SetObject xax
  invoke MemClone, pBuffer, [xax].pBuffer, [xax].dCurrSize
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.Done
; Purpose:    Finalizes the object.
; Arguments:  None.
; Return:     Nothing.

Method MemoryStream.Done, uses xsi
  SetObject xsi
  .if [xsi].pBuffer != NULL
    MemFree [xsi].pBuffer
  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.FileLoad
; Purpose:    Recovers the stream object from file.
; Arguments:  Arg1: -> ANSI string containing the file name.
; Return:     Nothing.

Method MemoryStream.FileLoad, uses xsi, pFileName:PSTRING
  local hFile:HANDLE, dBytesRead:DWORD, dNewLimit:DWORD

  SetObject xsi
  invoke CreateFile, pFileName, GENERIC_READ, 0, NULL, \
                     OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
  .if xax == INVALID_HANDLE_VALUE
    OCall xsi.ErrorReport, NULL, STM_FILE_NOT_FOUND
    ExitMethod
  .endif
  mov hFile, xax
  invoke ReadFile, hFile, addr [xsi].dErrorCode, sizeof $Obj(MemoryStream).dErrorCode, \
                   addr dBytesRead, NULL
  or eax, eax
  je @@Error
  invoke ReadFile, hFile, addr dNewLimit, sizeof $Obj(MemoryStream).dLimit, addr dBytesRead, NULL
  or eax, eax
  je @@Error
  mov eax, dNewLimit
  .if eax > [xsi].dMaxSize
    OCall xsi.ErrorReport, NULL, STM_OVERFLOW
    jmp @@Exit
  .endif
  and [xsi].dCurrSize, 0                          ;Forget old content!
  OCall xsi.SetCapacity, eax
  cmp [xsi].dErrorCode, OBJ_OK
  jne @@Error
  invoke ReadFile, hFile, addr [xsi].dCurrSize, sizeof $Obj(MemoryStream).dCurrSize, \
         addr dBytesRead, NULL
  or eax, eax
  je @@Error
  invoke ReadFile, hFile, addr [xsi].dPosition, sizeof $Obj(MemoryStream).dPosition, \
         addr dBytesRead, NULL
  or eax, eax
  je @@Error
  invoke ReadFile, hFile, [xsi].pBuffer, [xsi].dCurrSize, addr dBytesRead, NULL
  or eax, eax
  jne @@Exit
@@Error:
  OCall xsi.ErrorReport, NULL, STM_READ_ERROR
@@Exit:
  invoke CloseHandle, hFile
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.FileSave
; Purpose:    Stores the stream object to file.
; Arguments:  Arg1: -> ANSI string containing the file name.
; Return:     Nothing.

Method MemoryStream.FileSave, uses xsi, pFileName:PSTRING
  local hFile:HANDLE, dBytesWritten:DWORD

  SetObject xsi
  invoke CreateFile, pFileName, GENERIC_WRITE, 0, NULL, \
                     CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
  mov hFile, xax
  invoke WriteFile, hFile, addr [xsi].dErrorCode, sizeof $Obj(MemoryStream).dErrorCode, \
                           addr dBytesWritten, NULL
  or eax, eax
  je @@Error
  invoke WriteFile, hFile, addr [xsi].dLimit, sizeof $Obj(MemoryStream).dLimit, \
                    addr dBytesWritten, NULL
  or eax, eax
  je @@Error
  invoke WriteFile, hFile, addr [xsi].dCurrSize, sizeof $Obj(MemoryStream).dCurrSize, \
                    addr dBytesWritten, NULL
  or eax, eax
  je @@Error
  invoke WriteFile, hFile, addr [xsi].dPosition, sizeof $Obj(MemoryStream).dPosition, \
                    addr dBytesWritten, NULL
  or eax, eax
  je @@Error
  invoke WriteFile, hFile, [xsi].pBuffer, [xsi].dCurrSize, addr dBytesWritten, NULL
  or eax, eax
  jne @@Exit
@@Error:
  OCall xsi.ErrorReport, NULL, STM_WRITE_ERROR
@@Exit:
  invoke CloseHandle, hFile
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.GetPos
; Purpose:    Returns the current position into the memory stream.
; Arguments:  None.
; Return:     edx::eax = Current position into stream.

Method MemoryStream.GetPos
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    mov eax, [xcx].dPosition
    xor edx, edx
  .else
    mov eax, -1
    mov edx, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.GetSize
; Purpose:    Returns the current file size of the stream.
; Arguments:  None.
; Return:     edx::eax = Size of Stream.

Method MemoryStream.GetSize
  SetObject xcx
  xor edx, edx
  .if [xcx].dErrorCode == OBJ_OK
    mov eax, [xcx].dCurrSize
  .else
    mov eax, -1
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.Init
; Purpose:    Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Buffer capacity in bytes.
;             Arg3: Buffer increment in bytes.
;             Arg4: Buffer maximal size in bytes.
; Return:     Nothing.

Method MemoryStream.Init, uses xsi, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, dMaxSize:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].dDelta, dDelta, edx
  m2m [xsi].dMaxSize, dMaxSize, edx
  mov eax, dLimit
  .if eax <= dMaxSize
    OCall xsi.SetCapacity, eax
  .else
    OCall xsi.ErrorReport, NULL, STM_SETUP_ERROR
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.Seek
; Purpose:    Seek sets the current position to NewPosition bytes from the start of the calling
;             stream. The start of a stream is position 0. HiPart of qNewPosition is ignored!
; Arguments:  Arg1: New position.
; Return:     Nothing.

Method MemoryStream.Seek,, qNewPosition:QWORD
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    mov eax, (QUADWORD ptr qNewPosition).LoDWord
    .if eax > [xcx].dCurrSize
      OCall xcx.ErrorReport, NULL, STM_SEEK_ERROR
    .else
      mov [xcx].dPosition, eax
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.SetCapacity
; Purpose:    Creates a new buffer with a size of NewCapacity bytes on the heap and copies the
;             old Buffer content to the new one.
; Arguments:  Arg1: New storage dLimit in bytes.
; Return:     eax = if succeeded, allocated dLimit, otherwise 0.

Method MemoryStream.SetCapacity, uses xbx xsi, dNewLimit:DWORD
  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    MemAlloc dNewLimit
    .if xax == NULL
      OCall xsi.ErrorReport, NULL, STM_OUT_OF_MEMORY
      xor eax, eax
    .else
      mov xbx, [xsi].pBuffer
      mov [xsi].pBuffer, xax
      .if xbx != NULL
        invoke MemClone, xax, xbx, [xsi].dCurrSize
        MemFree xbx
      .endif
      m2m [xsi].dLimit, dNewLimit, eax                ;Set return value
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     MemoryStream.Truncate
; Purpose:    Deletes all data on the calling stream from the current position to the end.
; Arguments:  None.
; Return:     Nothing.

Method MemoryStream.Truncate
  SetObject xcx
  .if [xcx].dErrorCode == OBJ_OK
    m2m [xcx].dCurrSize, [xcx].dPosition, edx
  .endif
MethodEnd

endif