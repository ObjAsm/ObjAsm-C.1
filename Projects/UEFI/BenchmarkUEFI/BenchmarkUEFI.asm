; ==================================================================================================
; Title:   BenchmarkUEFI.asm
; Author:  Héctor S. Enrique
; Version: 1.0.0
; Purpose: ObjAsm compilation file for Benchmark UEFI Application.
; Version: Version 1.0.0, December 2022
;            - First release.
;
; Gabriele Paoloni. 2010. How to Benchmark Code Execution Times on Intel IA-32 and IA-64 Instruction
; Set Architectures. Retrieved May 26, 2022, from http://www.intel.com/content/dam/www/public/
; us/en/documents/white-papers/ia-32-ia-64-benchmark-code-execution-paper.pdf
; ==================================================================================================

return macro valor1
  mov rax, &valor1
  ret
endm

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIDE_STRING, UEFI64                        ;Load OOP files and basic OS support

.data
  MpProto POINTER NULL

  align @WordSize
  buffer CHR 32 dup (0)
  CStr crlf$,13,10

  ; for glass
  numerator REAL8 100000.0        ; values for measured
  denominator REAL8 10.0          ; FPU sequence
  result dq 0

  NaN REAL8  7FF8000000000000r
  fpu QWORD 0
.code

include \masm32\macros\SmplMath\math.inc
fSlvSelectBackEnd FPU

SIZE_OF_STAT equ 10000
BOUND_OF_LOOP equ 1000

UINT64_MAX equ 7ffffffffffffffh
function_under_glass0 macro
  mov rax, 1
endm

function_under_glass1 macro
  fld  QWORD ptr [numerator]
  fdiv QWORD ptr [denominator]
  fdiv QWORD ptr [denominator]
  fdiv QWORD ptr [denominator]
  fdiv QWORD ptr [denominator]
  fstp QWORD ptr [result]
endm

function_under_glass2 macro
  fsave fpu
  frstor fpu
endm

measured_loop proc loops:QWORD
  local i:QWORD

  ForLp i, 0, loops
    function_under_glass1
  Next i
  ret
measured_loop endp

Filltimes proc times:POINTER
  local flags:QWORD
  local i:QWORD, i_t:QWORD, j:QWORD, j_t:QWORD
  local .start:QWORD, .end:QWORD
  local cycles_low:QWORD, cycles_high:QWORD
  local cycles_low1:QWORD, cycles_high1:QWORD
  local variable:QWORD
  local .dur:QWORD
  local .r8:QWORD, .rdx:QWORD
  local Old_TPL:QWORD

  finit
  repeat 3
    CPUID
    RDTSC
    mov cycles_high , rdx
    mov cycles_low  , rax
    RDTSCP
    mov cycles_high1 , rdx
    mov cycles_low1  , rax
    CPUID
  endm

  ForLp_df j, 0, BOUND_OF_LOOP
    ForLp_df i, 0, SIZE_OF_STAT
      mov r10, pBootServices
      invoke [r10].EFI_BOOT_SERVICES.RaiseTPL,TPL_HIGH_LEVEL
      mov Old_TPL, rax
      CPUID
      RDTSC
      mov cycles_high, rdx
      mov cycles_low, rax

      invoke measured_loop, j

      RDTSCP
      mov cycles_high1, rdx
      mov cycles_low1, rax
      CPUID

      mov r10, pBootServices
      invoke [r10].EFI_BOOT_SERVICES.RestoreTPL, Old_TPL

      mov rdx, cycles_high
      shl rdx, 32
      mov rax, cycles_low
      or  rdx, rax
      mov .start, rdx

      mov rdx, cycles_high1
      shl rdx, 32
      mov rax, cycles_low1
      or  rdx, rax
      mov .end , rdx

      sub rdx, .start
      mov .rdx, rdx
      .if rdx  < 0
        PrintC "%E \n $$$$$$$ CRITICAL ERROR IN TAKING THE TIME \n loop(%d) stat(%d) start = %d , end = %d , variable = %f \n ", j, i, .start, .end, variable
        mov r8, times
        mov r9, j
        shl r9, 3
        add r9, r8
        mov r8, QWORD ptr [r9]
        mov r9, i
        shl r9, 3
        add r8, r9
        mov QWORD ptr [r8], 0
      .else
        mov r8, times
        mov r9, j
        shl r9, 3
        add r9, r8
        mov r8, QWORD ptr [r9]
        mov r9, i
        shl r9, 3
        add r8, r9

        mov rdx, .rdx
        mov QWORD ptr [r8], rdx
      .endif
      mov rdx, QWORD ptr [r8]
      mov .dur, rdx
    Next i
  Next j
  ret
Filltimes endp

include lineal.inc
include Paoloni2010.inc

Main PROC imageHandle:EFI_HANDLE, SystemTable:PTR_EFI_SYSTEM_TABLE
                                                        ;Runtime model initialization
    mov Handle, rcx
    mov SystemTablePtr,rdx

    SysInit

    mov rax, SystemTablePtr
    mov rsi, [rax].EFI_SYSTEM_TABLE.RuntimeServices
    mov pRuntimeServices, rsi
    mov rsi, [rax].EFI_SYSTEM_TABLE.BootServices
    mov pBootServices, rsi

    mov rcx,SystemTablePtr
    mov rax,[rcx].EFI_SYSTEM_TABLE.ConIn
    mov pConsoleIn,rax
    mov rax,[rcx].EFI_SYSTEM_TABLE.ConOut
    mov pConsole,rax
    invoke [rax].ConOut.ClearScreen, pConsole

    mov rax, pConsole                                     ;Colors change
    invoke [rax].ConOut.SetAttribute, pConsole, 0Eh

    CStr HelloMsg,"Benchmark with UEFI",13,10,13,10
    mov rcx, pConsole
    invoke [rcx].ConOut.OutputString, rcx, ADDR HelloMsg

    mov rax, pConsole                                     ;Colors change
    invoke [rax].ConOut.SetAttribute, pConsole, 07h

    mov r10, pBootServices
    invoke [r10].EFI_BOOT_SERVICES.SetWatchdogTimer, 0, 0, 0, NULL


    ;------------------------------------

    call BM_start

    ;------------------------------------

    Println "vuelve a Main"
    call WaitforKey

    mov rax, pConsole
    invoke [rax].ConOut.SetAttribute, pConsole, 0Fh     ;Color change

    CStr msg_bye, 13, 10,"bye bye...", 13, 10
    mov rcx, pConsole
    invoke [rcx].ConOut.OutputString, rcx, ADDR msg_bye

    SysDone

    CStr complete, "Complete",13,10
    mov rax, pBootServices
    invoke [rax].EFI_BOOT_SERVICES.Exit, Handle, EFI_SUCCESS, 10, addr complete

Main endp

end Main