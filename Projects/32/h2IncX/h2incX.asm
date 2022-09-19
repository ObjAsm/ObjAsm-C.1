; ==================================================================================================
; Title:    h2incX.asm
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  Creates MASM .inc files from C .h files.
; Links:    http://masm32.com/board/index.php?topic=7006.msg75149#msg75149
;           C++ reference: https://en.cppreference.com/w/cpp
;           Std C: http://www.open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf
; Notes:    This is the continuation & further development of Japheth's open source h2incX project.
;           Version B.01.00, June 2018
;             - First release.
;           Version C.01.00, September 2018
;             - Improvements:
;               - Output syntax & and spacing management intoduced.
;               - Removal of unnecessary output: ";{", ";}", error & warning count, "#undef", etc.
;               - Strategy change of @DefProto for x64.
;               - Ini-File completion.
;               - TypeC detection introduced.
;               - Switches on WinAsm.inc set correctly.
;               - Conditional sentence evaluation to skip code that can't be translated properly.
;               - Ini-File completed.
;
; ==================================================================================================


;todo: EncryptionState[15][16] is not translated correctly: SHORT Weights[2][32][3][2] ==> Weights WORD 2*32*3*2 dup(?)
;todo: numerical constants beginning with 0 (not 0x) are octals! Not used yet on the header set.
;todo: Comment list: AddComment adds a string to the stack, while PrintComment writes all strings to
;      the output stream
;todo: better COM support for OA32/OA64. ObjExplorer doesn't detect COM interfaces
;todo: renamed reserved words used as structure named must be added to the known structure names, like SIZE_.
;todo: check for reserved words in STD_METHOD names, like Kill.
;idea: replace ... equ <ptr ... by ... typedef ptr ... were possible
;idea: dont include non .h files like "include DirectXMathConvert.inl"
;todo: check alignment
;todo: correct bit fields (ASm != C++)



; EDITSTREAM struct 4                 Must be 4 aligned   --> #pragma pack 4
;pshpack1.inc pshpack2.inc pshpack4.inc pshpack8.inc and poppack.inc should implement a stack of structure alignment 



;    DECLARE_INTERFACE_ IImgCtx, IUnknown
;      ifndef NO_BASEINTERFACE_FUNCS
;        STD_METHOD QueryInterface, :THIS_, :ptr LPVOID
;        STD_METHOD AddRef, :THIS_
;        STD_METHOD Release, :THIS_
;      endif
;      STD_METHOD Load, :THIS_, :LPCWSTR, :DWORD   <<<<<<<<< LPCWSTR missing          

;
;prsht.inc missing
;
; DECLARE_INTERFACE_IID_ IPrintDialogCallback, IUnknown, "5852A2C3-6530-11D1-B6A3-0000F8757BF9"     replace "" with <>

; The IniFileReader stops reading after an ";"

;if (_WIN32_WINNT ge _WIN32_WINNT_WINXP)                    in wingdi.inc
;  HGDI_ERROR equ (LongToHandle(0FFFFFFFFh))  <= LongToHandle
;else
;  HGDI_ERROR equ (- 1)   <= ()
;endif

;    ifndef IN                in minwindef
;      ;IN equ <>
;    endif
;    ifndef OUT
;      ;OUT equ <>
;    endif

;    PROPSHEETPAGEA_V1_FIELDS macro
;      dwSize    DWORD     ?
;      dwFlags   DWORD     ?
;      hInstance HINSTANCE ? 
;      union
;        pszTemplate   LPCSTR                  ?
;        pResource     PROPSHEETPAGE_RESOURCE  ? 
;      ends
;      union
;        hIcon   HICON     ?  
;        pszIcon LPCSTR    ? 
;      ends
;      pszTitle  LPCSTR    ? 
;      pfnDlgProc DLGPROC  ? 
;      lParam    LPARAM    ? 
;      pfnCallback LPFNPSPCALLBACKA  ? 
;      pcRefParent PUINT   ? 
;    endm
;
;    PROPSHEETPAGEW_V1_FIELDS macro
;      dwSize    DWORD     ?
;      dwFlags   DWORD     ?
;      hInstance HINSTANCE ? 
;      union
;        pszTemplate   LPCWSTR                 ?
;        pResource     PROPSHEETPAGE_RESOURCE  ? 
;      ends
;      union
;        hIcon   HICON     ?  
;        pszIcon LPCWSTR   ? 
;      ends
;      pszTitle  LPCWSTR   ? 
;      pfnDlgProc DLGPROC  ? 
;      lParam    LPARAM    ? 
;      pfnCallback LPFNPSPCALLBACKA  ? 
;      pcRefParent PUINT   ? 
;    endm

;    ifndef IN        in minwindef.h
;      ;IN equ <>
;    endif


;BUG:
;
;        EXCEPINFO struct
;          wCode WORD ?
;          wReserved WORD ?
;          bstrSource BSTR ?
;          bstrDescription BSTR ?
;          bstrHelpFile BSTR ?
;          dwHelpContext DWORD ?
;          pvReserved PVOID ?
;          TYPE_pfnDeferredFillIn typedef proto WIN_STD_CALL_CONV :ptr tagEXCEPINFO
;          pfnDeferredFillIn typedef ptr TYPE_pfnDeferredFillIn   <------------------------------- should be  pfnDeferredFillIn TYPE_pfnDeferredFillIn  ?

;          scode SCODE ?
;        EXCEPINFO ends
;

%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc
SysSetup OOP, NUI32, ANSI_STRING, DEBUG(WND);, STKGUARD);, RESGUARD)

include CRTDLL.inc
includelib CRTDLL.lib

include h2incX_BStrA.inc
include h2incX_Globals.inc
% include &MacPath&LDLL.inc
% include &MacPath&LSLL.inc

MakeObjects Primer, Stream, Collection, SortedCollection, SortedStrCollectionA
MakeObjects .\h2incX_MemPool
MakeObjects .\h2incX_List
MakeObjects .\h2incX_IniFileReader
MakeObjects .\h2incX_IncFile                            ;Evaluator is here

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: GetOption
; Purpose:   Scan command line for options.
; Arguments: Arg1: -> Arguments from commandline.
; Return:    eax: TRUE if succeeded, FALSE on error.

GetOption proc uses edi esi pArgument:PSTRINGA
    mov esi, pArgument
    mov al, [esi]
    .if al == "/" || al == "-"
      mov ax, [esi + 1]
      .if ah != 0
        .if al == "W"
          sub ah, "0"
          jc @Error
          cmp ah, MAX_WARNING_LEVEL
          ja @Error
          mov g_bWarningLevel, ah

        .elseif al == "d"
          sub ah, "0"
          jc @Error
          .if ah == 0
            ;Default
          .elseif ah == 1
            mov g_bAssumeDllImport, TRUE
          .elseif ah == 2
            mov g_bIgnoreDllImport, TRUE
          .elseif ah == 3
            mov g_bUse@DefProto, TRUE
          .else
            jmp @Error
          .endif
          jmp @Exit
        .else
          jmp @Error
        .endif
      .endif

      mov edi, offset CmdLineSwitchTab
      .while [edi].CMDLINE_SWITCH_ENTRY.bSwitch != 0     ;End marker
        .if al == [edi].CMDLINE_SWITCH_ENTRY.bSwitch
          .if [edi].CMDLINE_SWITCH_ENTRY.bType == CLS_IS_BOOL
            mov ecx, [edi].CMDLINE_SWITCH_ENTRY.pVariable
            mov BYTE ptr [ecx], TRUE
          .endif
          jmp @Exit
        .endif
        add edi, sizeof CMDLINE_SWITCH_ENTRY
      .endw
      jmp @Error

    .else
      .if g_bOutDirExpected != FALSE
        mov g_pOutDir, esi
        mov g_bOutDirExpected, FALSE

      .elseif g_bSelExpected != FALSE
        mov g_bConstants, FALSE
        mov g_bTypedefs, FALSE
        mov g_bPrototypes, FALSE
        mov g_bExternals, FALSE
        .while TRUE
          lodsb
          .break .if al == 0
          or al, 20h
          .if al == "c"
            mov g_bConstants, TRUE
          .elseif al == "e"
            mov g_bExternals, TRUE
          .elseif al == "p"
            mov g_bPrototypes, TRUE
          .elseif al == "t"
            mov g_bTypedefs, TRUE
          .else
            jmp @Error
          .endif
        .endw
        mov g_bSelExpected, FALSE

      .elseif g_bCallConvExpected != FALSE
        mov ax, [esi]
        .if ah != 0
          jmp @Error
        .endif
        or al, 20h
        .if al == "c"
          or g_dDefCallConv, PTQ_CDECL
        .elseif al == "s"
          or g_dDefCallConv, PTQ_STDCALL
        .elseif al == "p"
          or g_dDefCallConv, PTQ_PASCAL
        .elseif al == "y"
          or g_dDefCallConv, PTQ_SYSCALL
        .elseif al == "f"
          or g_dDefCallConv, PTQ_FASTCALL
        .elseif al == "v"
          or g_dDefCallConv, PTQ_VECTORCALL
        .else
          jmp @Error
        .endif
        mov g_bCallConvExpected, FALSE

      .elseif g_bIncDirExpected != FALSE
        mov g_pIncDir, esi
        mov g_bIncDirExpected, FALSE

      .else
        xchg esi, g_pFilespec
        test esi, esi
        jnz @Error
      .endif
    .endif

@Exit:
    mov eax, TRUE
    ret

@Error:
    DbgErrorF <"%s(%u): ParseEqu - error">, [ebx].$Obj(IncFile).pFileName, [ebx].$Obj(IncFile).dLineNbr
    DbgErrorF <"%u: GetOption - error">, [ebx].$Obj(IncFile).dLineNbr
    mov eax, FALSE
    ret
GetOption endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: CheckIncFile
; Purpose:   Check if output file would be overwritten. If yes, optionally ask user how to proceed.
; Arguments: Arg1: -> OutputName.
;            Arg2: -> FileName.
;            Arg3: -> Parent IncFile.
; Return:    eax: 1 => proceed, 0 => skip processing.

CheckIncFile proc uses ebx pOutName:PSTRINGA, pFileName:PSTRINGA, pParent:$ObjPtr(IncFile)
    local szPrefix[MAX_PATH + 32]:CHRA

    .if g_bOverwrite == FALSE
      invoke FileExistA, pOutName
      .if eax != FALSE
        .if g_bBatchmode != FALSE
          .if g_bWarningLevel >= MAX_WARNING_LEVEL || pParent == NULL
            .if pParent != NULL
              mov ecx, pParent
              invoke sprintf, addr szPrefix, $OfsCStrA("%s(%u): "), [ecx].$Obj(IncFile).pFileName,
                              [ecx].$Obj(IncFile).dLineNbr
            .else
              mov szPrefix, 0
            .endif
            invoke printf, $OfsCStrA("%s%s exists, file %s not processed"),
                           addr szPrefix, pOutName, pFileName
          .endif
          xor eax, eax        ;FALSE
          jmp @Exit
        .else
          invoke printf, $OfsCStrA("%s exists, overwrite (y/n)?"), pOutName
          .while TRUE
            invoke _getch
            .if al >= "A"
              or al, 20h
            .endif
            .break .if al == "y"
            .break .if al == "n"
            .break .if al == 3
          .endw
          push eax
          invoke printf, $OfsCStr(LF)
          pop eax
          .if al == 3
            mov g_bTerminate, TRUE
            invoke printf, $OfsCStrA("^C")
            xor eax, eax      ;FALSE
            jmp @Exit
          .elseif al == "n"
            invoke printf, $OfsCStrA("%s not processed", LF), pFileName
            xor eax, eax
            jmp @Exit
          .endif
        .endif
      .endif
    .endif
    mov eax, TRUE
@Exit:
    ret
CheckIncFile endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ProcessFile
; Purpose:   Process a single .h file
; Arguments: Arg1: -> FileName.
;            Arg2: -> Parent IncFile that calls ProcessFile due to an "include" PP command.
; Return:    eax = TRUE if succeded, otherwise FALSE.

ProcessFile proc uses ebx esi pFileName:PSTRINGA, pParent:ptr IncFile
    local pIncFile:$ObjPtr(IncFile), pFilePart:PSTRINGA
    local szFileName[MAX_PATH]:CHRA, szFileNameLC[MAX_PATH]:CHRA
    local szOutName[MAX_PATH]:CHRA, szName[256]:CHRA, szMsg[1024]:CHRA

    if DEBUGGING
      DbgSaveContext
      DbgSetDestWnd "Include Tree"
      mov ecx, g_dIncLevel
      lea edi, szMsg
      mov byte ptr [edi], 0
      .if SDWORD ptr ecx < 0                        ;Just in case something goes wrong
        mov g_dIncLevel, 0
      .else
        shl ecx, 1
        mov al, " "
        rep stosb                                   ;Indentation
      .endif
      invoke StrECopy, edi, pFileName
      invoke StrCopy, eax, $OfsCStrA(" [")
      invoke DbgOutTextA, addr szMsg, DbgColorForeground, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
      DbgLoadContext
      inc g_dIncLevel
    endif

    invoke GetFullPathName, pFileName, MAX_PATH, addr szFileName, addr pFilePart
    invoke StrCopyA, addr szFileNameLC, addr szFileName
    invoke StrLowerA, addr szFileNameLC

    ;-- Don't process files more than once --
    OCall g_pInpFiles::List.Search, addr szFileNameLC
    .if eax == FALSE
      OCall g_pMemPool::MemPool.AddStr, addr szFileNameLC
      OCall g_pInpFiles::List.Insert, eax

      .if g_bVerbose != FALSE
        .if pParent != NULL
          mov ecx, pParent
          invoke printf, $OfsCStrA("%s(%u): "), [ecx].$Obj(IncFile).pFileName, [ecx].$Obj(IncFile).dLineNbr
        .endif
        invoke printf, $OfsCStrA("file '%s'", LF), pFileName
      .endif
      invoke _splitpath, addr szFileName, NULL, NULL, addr szName, NULL
      invoke _makepath, addr szOutName, NULL, g_pOutDir, addr szName, $OfsCStrA(".inc")
      ;--- check if output file exists
      invoke CheckIncFile, addr szOutName, pFileName, pParent
      .if eax != FALSE
        ;--- create the IncFile object instance
        New IncFile
        .if eax != NULL
          mov pIncFile, eax
          OCall pIncFile::IncFile.Init, NULL, addr szFileName, pParent
          .if eax != FALSE
            if DEBUGGING
              DbgSaveContext
              DbgSetDestWnd "Include Tree"
              invoke DbgOutTextA, $OfsCStrA("processed]"), DbgColorForeground, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
              DbgLoadContext
            endif
            OCall pIncFile::IncFile.ParseHeaderFile
            OCall pIncFile::IncFile.Analyse                 ;Reset volatile lists
            OCall pIncFile::IncFile.Save, addr szOutName
            push eax
            OCall pIncFile::IncFile.CreateDefFile, addr szOutName
          .else
            push eax
            if DEBUGGING
              DbgSaveContext
              DbgSetDestWnd "Include Tree"
              invoke DbgOutTextA, $OfsCStrA("failed"), DbgColorError, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
              invoke DbgOutTextA, $OfsCStrA("]"), DbgColorForeground, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
              DbgLoadContext
            endif
          .endif
          Destroy pIncFile
          pop eax
        .else
          mov g_bTerminate, TRUE
        .endif
      .endif
    if DEBUGGING
    .else
      DbgSaveContext
      DbgSetDestWnd "Include Tree"
      invoke DbgOutTextA, $OfsCStrA("skipped"), DbgColorBlue, DbgColorBackground, DBG_EFFECT_NORMAL, ??DbgDstWnd
      invoke DbgOutTextA, $OfsCStrA("]"), DbgColorForeground, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
      DbgLoadContext
    endif
    .endif
@Exit:
    if DEBUGGING
      dec g_dIncLevel
    endif
    ret
ProcessFile endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ProcessFiles
; Purpose:   Process all .h files in the current path.
; Arguments: Arg1: -> FileNme filter.
; Return:    Nothing.

ProcessFiles proc pFileSpec:PSTRINGA
    local hFFHandle:DWORD, pFilePart:PSTRINGA
    local szCurDir[MAX_PATH]:CHRA, szInpDir[MAX_PATH]:CHRA, szFileSpec[MAX_PATH]:CHRA
    local szDrive[4]:CHRA, szDir[256]:CHRA, szName[256]:CHRA, szExt[256]:CHRA
    local FindData:WIN32_FIND_DATA

    invoke GetCurrentDirectory, MAX_PATH, addr szCurDir      ;Save current directory

    invoke GetFullPathName, pFileSpec, MAX_PATH, addr szFileSpec, addr pFilePart
    invoke _splitpath, addr szFileSpec, addr szDrive, addr szDir, addr szName, addr szExt
    invoke _makepath, addr szInpDir, addr szDrive, addr szDir, NULL, NULL
    DbgPrintF $RGB(0,0,0), <"ProcessFiles - input directory = '%s'">, addr szInpDir

    invoke SetCurrentDirectory, addr szInpDir
    lea ecx, szInpDir
    DbgPrintF $RGB(0,0,0), <"ProcessFiles - SetCurrentDirectory() = %X to '%s'">, eax, ecx

    invoke StrECopyA, addr szFileSpec, addr szName
    lea ecx, szExt
    invoke StrCopyA, eax, ecx

    DbgPrintF $RGB(0,0,0), <"ProcessFiles - FileSpec = '%s'">, addr szFileSpec

    invoke FindFirstFile, addr szFileSpec, addr FindData
    .if eax == INVALID_HANDLE_VALUE
      invoke printf, $OfsCStrA("No matching files found", LF)
    .else
      mov hFFHandle, eax
      .repeat
        .if FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY
          .if DCHRA ptr FindData.cFileName == "."
            jmp @SkipItem
          .elseif DCHRA ptr FindData.cFileName == ".." && CHRA ptr FindData.cFileName[2] == 0
            jmp @SkipItem
          .endif
          .if g_bBatchmode == FALSE
            invoke printf, $OfsCStrA("%s is a directory, process all files inside (y/n)?"),
                           addr FindData.cFileName
            .while TRUE
              invoke _getch
              .if al >= "A"
                or al, 20h
              .endif
              .break .if al == "y"
              .break .if al == "n"
              .break .if al == 3
            .endw
          .else
            mov al, "y"
          .endif
          push eax
          invoke printf, $OfsCStr(LF)
          pop eax
          .break .if al == 3
          .if al == "y"
            invoke StrECopyA, addr szFileSpec, addr FindData.cFileName
            invoke StrCopyA, eax, $OfsCStrA("\*.h")
            invoke ProcessFiles, addr szFileSpec
          .endif
          jmp @SkipItem
        .endif
        invoke ProcessFile, addr FindData.cFileName, NULL
        mov g_dResult, eax
;        invoke PrintSummary, addr FindData.cFileName
@SkipItem:
        .break .if g_bTerminate != FALSE
        invoke FindNextFile, hFFHandle, addr FindData
      .until eax == 0

      invoke FindClose, hFFHandle
@Exit:
      invoke SetCurrentDirectory, addr szCurDir      ;Restore directory
    .endif
    ret
ProcessFiles endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: start
; Purpose:   Start console procedure.
;             - reads profile file
;             - reads command line
;             - loops thru all header files calling ProcessFile
; Arguments: None.
; Return:    Nothing.

start proc uses ebx edi esi
    local dSize:DWORD, pIniFile:POINTER, pFilePart:PSTRINGA
    local szOutDir[MAX_PATH]:CHRA, LocTime:SYSTEMTIME
    local argc:DWORD, argv:POINTER, envp:POINTER
    local ArgA:POINTER, Arg9:POINTER, Arg8:POINTER, Arg7:POINTER, Arg6:POINTER
    local Arg5:POINTER, Arg4:POINTER, Arg3:POINTER, Arg2:POINTER, Arg1:POINTER

    SysInit
    DbgClearAll

;    mov argc, 9
;    lea eax, Arg1
;    mov argv, eax
;    mov Arg1, $OfsCStrA("h2incX.exe")
;    mov Arg2, $OfsCStrA("-b")            ;Batch mode, no user interaction
;    mov Arg3, $OfsCStrA("-y")            ;Overwrite existing .inc files without confirmation
;    mov Arg4, $OfsCStrA("-d3")           ;If possible use @DefProto macro to define prototypes
;    mov Arg5, $OfsCStrA("-i")            ;Process #include lines
;    mov Arg6, $OfsCStrA("-S")            ;Print summary (structures, macros)
;    mov Arg7, $OfsCStrA("-o")            ;Set output directory
;  if 1
;    mov Arg8, $OfsCStrA("\ObjAsm\Projects\32\h2IncX\Inc")
;    mov Arg9, $OfsCStrA("\ObjAsm\Projects\32\h2IncX\Header_10.0.17763.0\h2incX_MasterInclude.h")   ;Convert all files at a time
;    ;h2incX_MasterInclude
;  else
;    mov Arg8, $OfsCStrA("\ObjAsm\Projects\32\h2IncX\Inc\SFML")
;    mov Arg9, $OfsCStrA("D:\ObjAsm\Projects\32\h2IncX\SFML\SFML_Master.h")
;;  else
;;    mov Arg8, $OfsCStrA("\ObjAsm\Projects\32\h2IncX\CUDA_10.1\Inc")
;;    mov Arg9, $OfsCStrA("\ObjAsm\Projects\32\h2IncX\CUDA_10.1\Include\CudaMaster.h")   ;Convert all files at a time
;  endif

    mov g_dResult, 1
    mov g_pMemPool, $New(MemPool)
    OCall eax::MemPool.Init, NULL, 1000000h, 100000h    ;Grab 10MB
    .if g_pMemPool == NULL
      invoke printf, $OfsCStrA("Fatal error: out of memory.", LF)
    .else
;      invoke __GetMainArgs, addr argc, addr argv, addr envp, 0
      mov edi, 1
      mov ebx, argv
      .while edi < argc
        invoke GetOption, POINTER ptr [ebx + sizeof(POINTER)*edi]
        .if eax == FALSE
          sub edi, 2
          invoke printf, $OfsCStrA("Fatal error: error on parameter %u.", LF, LF), edi
          mov g_bShowUsage, TRUE
          mov g_bTerminate, TRUE
          .break
        .endif
        inc edi
      .endw
      .if g_pFilespec == NULL
        invoke printf, $OfsCStrA("Fatal error: invalid filespec.", LF, LF)
        mov g_bShowUsage, TRUE
        mov g_bTerminate, TRUE
      .endif

      .if g_bShowUsage == TRUE
        invoke printf, offset szUsage
      .endif

      .if g_bTerminate == FALSE && edi == argc
        mov g_pIF_Reader, $New(IniFileReader)
        OCall eax::IniFileReader.Init, NULL
        mov ebx, offset g_PersistConvTable
        .while POINTER ptr [ebx] != NULL
          mov [ebx].CONV_TAB_ENTRY.pList, $New(List)
          OCall eax::List.Init, NULL, [ebx].CONV_TAB_ENTRY.dAlloc, \
                                      [ebx].CONV_TAB_ENTRY.dIncr, [ebx].CONV_TAB_ENTRY.dFlags
          .ifBitSet [ebx].CONV_TAB_ENTRY.dFlags, CF_INIF
            OCall g_pIF_Reader::IniFileReader.LoadList, ebx
            .if eax == FALSE
              invoke printf, $OfsCStrA("Fatal error: reading ini file.", LF)
              .break
            .endif
          .endif
          add ebx, sizeof CONV_TAB_ENTRY
        .endw
        Destroy g_pIF_Reader

;        OCall g_pSimpleTypes::List.LoadFromFile,     $OfsCStrA("H2I_TypeNames.lst")
;        OCall g_pKnownQualifiers::List.LoadFromFile, $OfsCStrA("H2I_KnwMacros.lst")
;        OCall g_pKnownStructs::List.LoadFromFile,    $OfsCStrA("H2I_KnwStruct.lst")
;        OCall g_pKnownQualifiers::List.LoadFromFile, $OfsCStrA("H2I_KnwQualif.lst")
;        OCall g_pReservedWords::List.LoadFromFile,   $OfsCStrA("H2I_ResvWords.lst")
;        OCall g_pConvertTypeQual::List.LoadFromFile, $OfsCStrA("H2I_QualifCnv.lst")
;        OCall g_pConvertTypes1::List.LoadFromFile,   $OfsCStrA("H2I_TypeConv1.lst")
;        OCall g_pConvertTypes2::List.LoadFromFile,   $OfsCStrA("H2I_TypeConv2.lst")
;        OCall g_pConvertTypes3::List.LoadFromFile,   $OfsCStrA("H2I_TypeConv3.lst")
;        OCall g_pConvertTokens::List.LoadFromFile,   $OfsCStrA("H2I_TokenConv.lst")
;        OCall g_pAlignments::List.LoadFromFile,      $OfsCStrA("H2I_Alignment.lst")
;        OCall g_pTypeSize::List.LoadFromFile,        $OfsCStrA("H2I_TypeSizes.lst")
;        OCall g_pAnnotations::List.LoadFromFile,     $OfsCStrA("H2I_KnwAnnots.lst")
;        OCall g_pMacros::List.LoadFromFile,          $OfsCStrA("H2I_NewMacros.lst")
;        OCall g_pStructs::List.LoadFromFile,         $OfsCStrA("H2I_NewStruct.lst")
;        OCall g_pQualifiers::List.LoadFromFile,      $OfsCStrA("H2I_NewQualif.lst")
;        OCall g_pPrototypes::List.LoadFromFile,      $OfsCStrA("H2I_NewProtos.lst")
;        OCall g_pTypedefs::List.LoadFromFile,        $OfsCStrA("H2I_NewTypdef.lst")


        .if POINTER ptr [ebx] != NULL
          invoke printf, $OfsCStrA("Fatal error: initialization failed.", LF)
        .else
          invoke GetFullPathName, g_pOutDir, MAX_PATH, addr szOutDir, addr pFilePart
          lea eax, szOutDir
          mov g_pOutDir, eax
          invoke GetLocalTime, addr LocTime             ;Get conversion time for all files
          invoke sprintf, offset g_szCreation, $OfsCStrA(", %02u/%02u/%02u %02u:%02u"), \
                    LocTime.wDay, LocTime.wMonth, LocTime.wYear, LocTime.wHour, LocTime.wMinute

          invoke ProcessFiles, g_pFilespec              ;<= analysis start here
        .endif

        mov ebx, offset g_PersistConvTable
        .while POINTER ptr [ebx] != NULL
          .if [ebx].CONV_TAB_ENTRY.pFileName != NULL
            OCall [ebx].CONV_TAB_ENTRY.pList::List.SaveToFile, [ebx].CONV_TAB_ENTRY.pFileName
          .endif
          Destroy [ebx].CONV_TAB_ENTRY.pList::List.Done
          add ebx, sizeof CONV_TAB_ENTRY
        .endw

      .endif
      Destroy g_pMemPool
    .endif

    DbgText "--- End of Program ---", "Output"
    SysDone
    invoke ExitProcess, g_dResult
start endp

end
