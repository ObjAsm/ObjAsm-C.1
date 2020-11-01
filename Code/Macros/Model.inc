; ==================================================================================================
; Title:      Model.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm supporting macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================

; Notes about ObjAsm:
; ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
;  1. Naming rules
;     a. Constants, structures, unions and native types are written in capitals and words are
;        separated with an underscore, e.g. MAX_SIZE.
;     b. Variables follows the "medial capitals" style (CamelCase), e.g. dSelection.
;  2. Prefixes:
;     a. Hidden Symbols prepended with "??" are "cross macro" symbols. Do not alter them with other
;        macros.
;     b. Local macro variables are reused as much as possible to minimize symbol table growth.
;        They are prepended with "$$".
;     c. Variable types are denoted using the following prefixes:
;        - x: XWORD (X is also used as suffix for proc naming)
;        - b: BYTE or BOOL
;        - w: WORD
;        - d: DWORD
;        - q: QWORD
;        - o: OWORD
;        - sb: SBYTE
;        - sw: SWORD
;        - sd: SDWORD
;        - sq: SQWORD
;        - so: SOWORD
;        - t: TBYTE
;        - c: CHR (CHRA, CHRW, CHRU)
;        - sz: zero terminated string (ANSI or WIDE)
;        - h: HANDLE
;        - p: POINTER
;        - pp: POINTER to a POINTER
;        - pv: POINTER to a vector
;        - v: Vector, e.g. VEC3 or VEC4
;        - m: matrix, e.g. MAT33 or MAT44
;        - sz: Zero terminated string of CHR characters, usually defined as CONST
;        - r4: REAL4
;        - r8: REAL8
;        - r10: REAL10
;        - P_: ptr type, e.g. ptr RECT = P_RECT
;        - POB_: ptr Object type
;        - TPL_: Object template
;        - $: macro that returns a text or a number
;        - s: user symbols (sIID_xxx)
;        - $$: hidden symbols, but reused by macros to save space on the symbol table
;        - ??: hidden symbols, but shared between macros

;  3. Macro parameters are usually InsName, ObjName, MtdMame, VarName, IfcName, Args, ...
;  4. Stucture alingnement are usually 1.
;  5. Object is a synonym for class.
;  6. The following prefixes are used:
;       TPL_ : object template from which an instance is created.
;       POB_ : object POINTER type. Used to type cast e.g. variables, paramters, etc.
;  7. Each macro, procedure or method has a standard header, that can be parsed into a help system.
;     The header should include the following items in this format (descs should start at pos. 15):
;        ; Macro:      ... /Procedure/Method
;        ; Purpose:    ...
;        ; Arguments:  Arg1: ...
;        ;             Arg2: ...
;        ; Return:     ...
;  8. ObjAsm uses a dual method table (DMT) that fuses a virtual method table (VMT) with an interface
;     method table (IMT). The layout of the VMT is designed with negative offsets from the table
;     entry point. To have a quick access to a event translation table (ETT), a POINTER is inserted
;     in between the VMT and the IMT, shifting the VMT one entry back.
;  9. The event translation table (ETT) is used to dispatch Windows messages, COM and other events.
; 10. Information about objects are hold in a metadata chained list, that starts with p1stOMD.
; 11. Each object/instance can be identifed at runtime by its ID, declared with the "Object" macro.
;     If this ID is not declared, ObjAsm doesn't emmit an error. The ID is assumed as "0" and the
;     object/instance can not be identifed at runtime anymore.
; 12. Object definition and implementation are hold together in one single file (ObjName.inc).
;     To separate them, a conditional compilation switch called IMPLEMENT is used to encapsulate
;     the implementation. This switch is handled automatically.
; 13. Object implementation can be precompiled to a library file (ObjName.lib) using an auxiliary
;     assembly file (ObjName.asm) located in most cases in the same communal directory (ObjPath).
; 14. Communal paths and other basic definitions are defined in one file called OA_Setup64.inc
; 15. Including objects are done using the MakeObjects or LoadObjects macro. The first builds
;     the object source while the second loads the precompiled library file. Descendant objects
;     must be loaded in inheritance order. Included or loaded Objects have to be included or
;     loaded again. If no path is prepended to the object name, the ObjPath communal directory
;     is assumed.
; 16. An object may have virtual methods, that are invoked using the VMT and the OCall macro.
;     Interface methods use the IMT and may use ICall or OCall for their invoketion.
; 17. Static methods use a direct call to the method implementation without any indirection.
; 18. Dynamic methods are like virtual or interface methods, but the indirection is done using
;     a method address stored in the object instance. This way, subclassing of an object instance
;     can be done.
; 19. Superclassing can be done redefining the adresses stored in the DMT. For this purpose use the
;     RedefineMethod macro.
; 20. In this implementation, the VMT & IMT are per object, not per instance. To implement instance
;     dependant methods use "Dynamic Methods".
; 21. Object errors are written in the ObjErr.inc file. User defined errors should be kept in a
;     separate file.
; 22. Object IDs are written in the ObjIDs.inc file. User defined IDs should be kept in a separate
;     file.
; 23. WIDE string support is enabled adding the WIDE_STRING keyword to the SysSetup macro at the
;     beginning of the sorece. ANSI_STRING switches the ANSI string support on.
; 24. The "CHR", "PCHR" and "PSTRING" types change their meaning according the string compilation
;     target (ANSI_STRING or WIDE_STRING).
; 25. Debugging macros are enabled when DEBUG() is added to the SysSetuo macro. The destination
;     of the debug information is directed using the Debug auguments WND, CON, LOG or PRN.
; 26. If a string procedure name contain one of the following characters, it behave as follows:
;       - A: ANSI procedure
;       - W: WIDE procedure
;       - C: character count limited
;       - E: returns the address of the ZTC
;       - I: case insensitive
;       - L: operation starts from left
;       - R: operation starts from right

; ——————————————————————————————————————————————————————————————————————————————————————————————————

ifdef __UASM__
  ASSEMBLER CatStr <U>, %__UASM__
elseifdef __JWASM__
  ASSEMBLER CatStr <J>, %__JWASM__                      ;Legacy
elseifdef __ASMC__
  ASSEMBLER CatStr <A>, %__ASMC__
else
  ASSEMBLER CatStr <M>, @Version
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SysSetup
; Purpose:    Load and configure standard modules.
; Arguments:  Support level: OOP, WIN, LIB
;             Debug Switches : SHOWINFO, TRACE, RESGUARD, STKGUARD
;             Source identif.: SRC="..."
;             Default string : ANSI_STRING or WIDE_STRING
; Return:     Nothing.

DEBUG macro DbgArgs:vararg
  ifndef ISABLE_DEBUG                                   ;;Use assembler option /D<ISABLE_DEBUG>
    $$DbgArgs equ DbgArgs                               ;;   to disable application debugging
    exitm <DEBUG_TRUE>
  else
    $$DbgArgs equ <>
    exitm <DEBUG_FALSE>
  endif
endm

RESGUARD_LOADED         =         0                     ;Set these flags
STKGUARDING             =         0
TRACING                 =         0
DEBUGGING               =         0

STR_TYPE_ANSI           equ       1
STR_TYPE_WIDE           equ       2
TARGET_STR_TYPE         =         STR_TYPE_WIDE         ;Default WIDE strings
TARGET_STR_AFFIX        textequ   <W>

OOP_DISABLED            equ       1                     ;OOP support disabled.
OOP_ENABLED             equ       2                     ;OOP support enabled.
TARGET_OOP              =         OOP_DISABLED

BIN_FORMAT_EXE          equ       1
BIN_FORMAT_DLL          equ       2
BIN_FORMAT_LIB          equ       3
TARGET_BIN_FORMAT       =         BIN_FORMAT_EXE

USER_INTERFACE_NONE     equ       1                     ;No user interface
USER_INTERFACE_WIN      equ       2                     ;Window user interface
TARGET_USER_INTERFACE   =         USER_INTERFACE_WIN    ;Default: Window

TARGET_BITNESS          =         32                    ;Default 32-bit

MODE_RLS                equ       1
MODE_DBG                equ       2
TARGET_MODE             =         MODE_RLS
TARGET_MODE_STR         textequ   <R>

DEBUGGING               =         0

??ObjectContext         textequ   <>


SysSetup macro Arguments:vararg
  for Argument, <Arguments>
    ifidni  <Argument>, <WIDE_STRING>                   ;;WIDE string support
      TARGET_STR_TYPE = STR_TYPE_WIDE
      TARGET_STR_AFFIX textequ <W>
      UNICODE equ 1
    elseifidni  <Argument>, <ANSI_STRING>               ;;ANSI string support
      TARGET_STR_TYPE = STR_TYPE_ANSI
      TARGET_STR_AFFIX textequ <A>

    elseifidni <Argument>, <DEBUG_TRUE>
      DEBUGGING = 1
      TARGET_MODE = MODE_DBG
      TARGET_MODE_STR textequ <D>

    elseifidni <Argument>, <DEBUG_FALSE>
      DEBUGGING = 0
      TARGET_MODE = MODE_RLS
      TARGET_MODE_STR textequ <R>

    elseifidni <Argument>, <OOP>
      TARGET_OOP = OOP_ENABLED

    elseifidni  <Argument>, <NUI32>
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <NUI64>
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 64

    elseifidni  <Argument>, <WINDOWS>
      echo WARNING: Legacy SysSetup argument - WINDOWS - using WIN32
      TARGET_USER_INTERFACE = USER_INTERFACE_WIN
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <WIN32>
      TARGET_USER_INTERFACE = USER_INTERFACE_WIN
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <WIN64>
      TARGET_USER_INTERFACE = USER_INTERFACE_WIN
      TARGET_BITNESS = 64

    elseifidni  <Argument>, <CON32>
      TARGET_USER_INTERFACE = USER_INTERFACE_CON
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <CON64>
      TARGET_USER_INTERFACE = USER_INTERFACE_CON
      TARGET_BITNESS = 64

    elseifidni  <Argument>, <LIBRARY>
      echo WARNING: Legacy SysSetup argument - LIBRARY - falling back to LIB32
      TARGET_BIN_FORMAT = BIN_FORMAT_LIB
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <LIB32>
      TARGET_BIN_FORMAT = BIN_FORMAT_LIB
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <LIB64>
      TARGET_BIN_FORMAT = LIB
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 64

    elseifidni  <Argument>, <DLL32>
      TARGET_BIN_FORMAT = BIN_FORMAT_DLL
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 32
    elseifidni  <Argument>, <DLL64>
      TARGET_BIN_FORMAT = BIN_FORMAT_DLL
      TARGET_USER_INTERFACE = USER_INTERFACE_NONE
      TARGET_BITNESS = 64

    else
      echo SysSetup - Invalid argument
      echo
    endif
  endm

  if TARGET_BITNESS eq 32
    % include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
  else
    % include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
  endif

  .nolist
  .nocref

  % include &IncPath&Windows\\Windows.inc
  % include &MacPath&System.inc
  % include &MacPath&Memory.inc
  % include &MacPath&Strings.inc
  % include &MacPath&WinHelpers.inc
  % include &MacPath&ConstDiv.inc
  % include &IncPath&ObjAsm\\ObjMem.inc
  
  % includelib &LibPath&Windows\\GDI32.lib
  % includelib &LibPath&Windows\\Kernel32.lib
  % includelib &LibPath&Windows\\User32.lib
  % includelib &LibPath&Windows\\Advapi32.lib

  if TARGET_BITNESS eq 32
    % includelib &LibPath&ObjAsm\\ObjMem32.lib
  else
    % includelib &LibPath&ObjAsm\\ObjMem64.lib
  endif

  .list
  .cref

  externdef hInstance:HINSTANCE                         ;;Export hInstance symbol
  externdef hProcessHeap:HANDLE                         ;;Export hProcessHeap symbol
  externdef p1stOMD:POINTER                             ;;Export p1stOMD symbol

  ;;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  if TARGET_USER_INTERFACE eq USER_INTERFACE_NONE
    echo User Interface: NONE
  elseif TARGET_USER_INTERFACE eq USER_INTERFACE_WIN
    echo User Interface: WINDOW
  endif

  if TARGET_BIN_FORMAT eq BIN_FORMAT_EXE
    echo Binary Format:  EXE
  elseif TARGET_BIN_FORMAT eq BIN_FORMAT_DLL
    echo Binary Format:  DLL
  elseif TARGET_BIN_FORMAT eq BIN_FORMAT_LIB
    echo Binary Format:  LIB
    IMPLEMENT         = FALSE                           ;;Don't implement unless MakeObject is used
    MAKETEMPL         = FALSE                           ;;Don't create any object template
    SHOWINHERITANCE   = FALSE                           ;;Don't output the inheritance path
  endif

  if TARGET_BITNESS eq 32
    echo Bitness:        32
  else
    echo Bitness:        64
  endif

  if TARGET_OOP eq OOP_ENABLED
    echo OOP Support:    ENABLED
    % include &MacPath&Objects.inc                      ;;Here is our OOP support! => ObjAsm

    if DEBUGGING
      S_OBJID segment                                   ;;Define a new segment
        ??ObjIDTableStart equ $                         
      S_OBJID ends                                      ;;Switch back to previous segment
      ??ObjIDTableCount = 0                             
                                                        
      S_OBJERR segment                                  ;;Define a new segment
        ??ObjErrTableStart equ $                        
      S_OBJERR ends                                     ;;Switch back to previous segment
      ??ObjErrTableCount = 0

    endif
    % include &ObjPath&ObjIDs.inc                       ;;These include files must follow the
    % include &ObjPath&ObjErrs.inc                      ;;  previous segment definitions

  else
    echo OOP Support:    DISABLED
    IMPLEMENT         = FALSE                           ;;Don't implement unless MakeObject is used
    MAKETEMPL         = FALSE                           ;;Don't create any object template
    SHOWINHERITANCE   = FALSE                           ;;Don't output the inheritance path
  endif

  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    echo String Type:    ANSI
  elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
    echo String Type:    WIDE (UNICODE)
  endif

  ;;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  if DEBUGGING
    if TARGET_BITNESS eq 64
      ??StackBase equ <rbp>                             ;;Set default
      option stackbase:??StackBase                      ;;use rbp as stackbase for easier debugging
    endif

    % include &MacPath&DebugShare.inc

    DBG_SAVE_CPU_CONTEXT = TRUE                         ;;Debug macros preserve the CPU context
    DBG_SAVE_XMM_CONTEXT = TRUE                         ;;Debug macros preserve the XMM context
    DBG_SAVE_FPU_CONTEXT = TRUE                         ;;Debug macros preserve the FPU context

    DBG_DEVICE textequ <WND>                            ;;Default debug device
    DBG_TRACE = FALSE
    DBG_INFO  = FALSE
    DBG_SHOW_TIME_STAMP = FALSE
    $$sz1 textequ <>

    %for $$Arg, <$$DbgArgs>
      ifidni <$$Arg>, <RESGUARD>
        IncludeAPIs ResGuard                            ;;Load ResGuard.dll
        RESGUARD_LOADED = TRUE
      elseifidni <$$Arg>, <STKGUARD>
        STKGUARDING = TRUE
      elseifidni <$$Arg>, <WND>
        DBG_DEVICE textequ <WND>
      elseifidni <$$Arg>, <CON>
        DBG_DEVICE textequ <CON>
      elseifidni <$$Arg>, <LOG>
        DBG_DEVICE textequ <LOG>
      elseifidni <$$Arg>, <INFO>
        DBG_INFO = TRUE
      elseifidni <$$Arg>, <TRACE>
        DBG_TRACE = TRUE
      elseifidni <$$Arg>, <TIME>
        DBG_SHOW_TIME_STAMP = TRUE
      else
        if @InStr(1, $$Arg, <!">) eq 1
          $$sz1 textequ <$$Arg>
        endif
      endif
    endm

    ifb $$sz1
      CStrW szDbgSrc, @CatStr(<!">, %@FileName, <!">) ;;Use the Project File Name
    else
      CStrW szDbgSrc, $$sz1                           ;;Use the specified name
    endif

    externdef dDbgDev:DWORD                           ;;Export dDbgDev symbol
    externdef dDbgOpt:DWORD                           ;;Export dDbgOpt symbol
    externdef DbgCritSect:CRITICAL_SECTION            ;;Export DbgCritSect symbol

    if TARGET_BIN_FORMAT eq BIN_FORMAT_LIB
      ;;Debug support symbols
      ??ObjIDTableCount = 0
      ??ObjErrTableCount = 0
      externdef szDbgSrc:CHRW
      externdef szDbgInvalid:CHRA
      externdef szDbgErr:CHRW
      externdef szDbgObjErr:CHRW
      externdef szDbgFPU1:CHRA
      externdef szDbgFPU2:CHRA
      externdef szDbgFPU3:CHRA
      externdef szDbgFPU4:CHRA
      externdef szDbgFPU5:CHRA
      externdef szDbgFPU6:CHRA
      externdef szDbgFPU7:CHRA
      externdef szDbgMemFmt:CHRA
      externdef szDbgElipsis:CHRA
      externdef szDbgInvalid:CHRA
      externdef szDbgPoint2:CHRA
      externdef szDbgComma:CHRA
      externdef szDbgCtrCls:CHRW
      externdef hDbgDev:HANDLE
      externdef pObjIDTableStart:POINTER
      externdef dObjIDTableCount:DWORD
      externdef pObjErrTableStart:POINTER
      externdef dObjErrTableCount:DWORD

    else
      .data
      align ALIGN_DATA
      %ifidn <DBG_DEVICE>, <WND>
        dDbgDev   DWORD   DBG_DEV_WND
      %elseifidn <DBG_DEVICE>, <CON>
        dDbgDev   DWORD   DBG_DEV_CON
      %elseifidn <DBG_DEVICE>, <LOG>
        dDbgDev   DWORD   DBG_DEV_LOG
      endif

      ifdef DBG_INFO
        dDbgOpt   DWORD   DBG_OPT_SHOWINFO
      else
        dDbgOpt   DWORD   0
      endif

      DbgCritSect  CRITICAL_SECTION  {}

      if DBG_TRACE
        TRACING = TRUE

        S_PROF segment
          ??pDbgTraceInstance  POINTER  NULL
        S_PROF ends
      else
        TRACING = FALSE
      endif

      if STKGUARDING ne FALSE
        if TARGET_BITNESS eq 32
          xStkGrdCookie  DWORD  0                       ;;Create Cookie variable
        else
          xStkGrdCookie  QWORD  0                       ;;Create Cookie variable
        endif
      endif

    endif

    if TARGET_BITNESS eq 32
      %echo Mode:           DEBUG
    else
      %echo Mode:           DEBUG => DBG_DEVICE, using &??StackBase as stackframe pointer
    endif

    if STKGUARDING ne FALSE
      echo STACKGUARD:     ACTIVE
    endif

    if RESGUARD_LOADED ne FALSE
      echo RESGUARD:       ACTIVE
    endif

  else
    if TARGET_BITNESS eq 32
      %echo Mode:           RELEASE
    else
      %echo Mode:           RELEASE => using &??StackBase as stackframe pointer
    endif
  endif
  % include &MacPath&Debug.inc
  
  TARGET_SUFFIX CatStr $ToStr(%TARGET_BITNESS), TARGET_STR_AFFIX
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SysInit
; Purpose:    Initialize the model and internal variables.
; Arguments:  Arg1: Instance HANDLE. If not specified, the Module HANDLE is loaded into hInstance.

SysInit macro hInst
.data
  align ALIGN_DATA
  hInstance     HINSTANCE   0                           ;;Module instance
  hProcessHeap  HANDLE      0                           ;;Process Heap HANDLE
  if TARGET_OOP eq OOP_ENABLED
    p1stOMD     POINTER     ??1stOMD                    ;;-> 1st item in object metadata chain
  endif

.code
  ifnb <hInst>                                          ;;Used for DLLs
    mrm hInstance, hInst, xax
  else
    mov hInstance, $invoke(GetModuleHandle, NULL)       ;;Retrieves module instance HANDLE
  endif

  mov hProcessHeap, $invoke(GetProcessHeap)             ;;Get and save the process heap HANDLE

  if DEBUGGING
    invoke InitializeCriticalSection, addr DbgCritSect
    m2m pObjErrTableStart, ??ObjErrTableStart, xax
    mov dObjErrTableCount, ??ObjErrTableCount
    m2m pObjIDTableStart, ??ObjIDTableStart, xax
    mov dObjIDTableCount, ??ObjIDTableCount
  endif

  if STKGUARDING ne FALSE
    rdtsc                                               ;;Generate a run-time random QWORD cookie
    xor xax, xdx
    mov xStkGrdCookie, xax
  endif

  if TARGET_OOP eq OOP_ENABLED
    ObjectsInit
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SysDone
; Purpose:    Finalize the model.
; Arguments:  None.

SysDone macro
  if TARGET_OOP eq OOP_ENABLED
    ObjectsDone
  endif

  if DEBUGGING
    invoke DeleteCriticalSection, addr DbgCritSect
  endif
endm
