; ==================================================================================================
; Title:      BenchmarkUEFI.asm
; Author:     Héctor S. Enrique
; Version:    1.0.0
; Purpose:    ObjAsm compilation file for Benchmark UEFI Application.
; Version:    Version 1.0.0, Héctor S. Enrique
;             - First release.
; Note:       Gabriele Paoloni. 2010. How to Benchmark Code Execution Times on Intel IA-32 and IA-64
;             Instruction Set Architectures. Retrieved May 26, 2022, from
;             http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/
;             ia-32-ia-64-benchmark-code-execution-paper.pdf
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIDE_STRING, UEFI64, DEBUG(CON)           ;Load OOP files and basic OS support

% include &MacPath&fMath.inc
include \MASM32\SmplMath\macros\SmplMath\math.inc
;include C:\_MySoftware_\SmplMath\SmplMath\math.inc
fSlvSelectBackEnd FPU

;                 pTimes           1        2     ... SIZE_OF_STAT
;                ————————      ————————————————————————————————E;      1        | Ptr(0) | -> | Loop(0), Loop(0), ... , Loop(0) |
;      2        | Ptr(1) | -> | Loop(1), Loop(1), ... , Loop(1) |
;      .        |   .    |    |    .        .               .   |
;      .        |   .    |    |    .        .               .   |
;      .        |   .    |    |    .        .               .   |
; BOUND_OF_LOOP | Ptr(N) | -> | Loop(N), Loop(N), ... , Loop(N) |
;                ————————      ————————————————————————————————E
SIZE_OF_STAT  equ 10000
BOUND_OF_LOOP equ 100

.const
  r8NaN         REAL8   07FF8000000000000h    ;R8_NAN

  ;Values for performance test
  r8Numerator   REAL8   100000.0
  r8Denominator REAL8   10.0
.data
  r8Result      REAL8   0.0

  FpuEnv        BYTE    108 dup(0)            ;FPU environment 

.code

function_under_glass0 macro
  mov rax, 1
endm

function_under_glass1 macro
  fld  REAL8 ptr [r8Numerator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fstp REAL8 ptr [r8Result]
endm

function_under_glass2 macro
  fsave FpuEnv
  frstor FpuEnv
endm

FillTimes proc uses rbx rdi rsi r12 r13 r14 pTimes:POINTER
  local qStart:QWORD, qStop:QWORD, qPrevTPL:QWORD       ;Previous Task Priority Level

  finit
  repeat 3                                              ;Warm up instruction cache
    CPUID
    RDTSC
    mov DWORD ptr [qStart], eax
    mov DWORD ptr [qStart + sizeof(DWORD)], edx
    RDTSCP
    mov DWORD ptr [qStop], eax
    mov DWORD ptr [qStop + sizeof(DWORD)], edx
    CPUID
  endm

  xor rsi, rsi
  mov r14, pTimes
  .while esi < BOUND_OF_LOOP
    mov r12, POINTER ptr [r14 + sizeof(POINTER)*rsi]
    mov r13, pBootServices
    xor edi, edi
    .while edi < SIZE_OF_STAT
      invoke [r13].EFI_BOOT_SERVICES.RaiseTPL, TPL_HIGH_LEVEL
      mov qPrevTPL, rax
      CPUID                                             ;Serialize, uses eax ebx ecx edx!
      RDTSC                                             ;Clock reading
      mov DWORD ptr [qStart], eax                       ;Store time reading as edx::eax QWORD
      mov DWORD ptr [qStart + sizeof(DWORD)], edx

      mov ebx, esi
      test ebx, ebx
      .while !ZERO?
        function_under_glass1
        dec ebx
      .endw

      RDTSCP                                            ;Execute all up to this instruction
      mov DWORD ptr [qStop], eax                        ;Store time reading as edx::eax QWORD
      mov DWORD ptr [qStop + sizeof(DWORD)], edx
      CPUID                                             ;Serialize, uses eax ebx ecx edx!
      invoke [r13].EFI_BOOT_SERVICES.RestoreTPL, qPrevTPL

      mov rax, qStop
      mov rdx, qStart
      .if rax < rdx
        PrintC "%E CRITICAL ERROR IN TAKING THE TIME"
        PrintC "%E Loop(%d), Stat(%d): Start = %d, Stop = %d", rsi, rdi, qStart, qStop
        xor eax, eax
      .else
        sub rax, rdx
      .endif
      mov QWORD ptr [r12 + sizeof(QWORD)*rdi], rax      ;Store elapsed time
      inc edi
    .endw
    inc esi
  .endw
  ret
FillTimes endp

include Lineal.inc
include Paoloni2010.inc

start proc uses rbx ImageHandle:EFI_HANDLE, pSysTable:PTR_EFI_SYSTEM_TABLE
  ;Runtime model initialization
  SysInit ImageHandle, pSysTable

  mov rbx, pConsoleOut
  assume rbx:ptr ConOut
  ;invoke [xbx].ClearScreen, rbx
  ;Color change: Bits 0..3 are the foreground color, and bits 4..6 are the background color
  invoke [rbx].SetAttribute, rbx, EFI_YELLOW or EFI_BACKGROUND_BLACK
  invoke [rbx].ConOut.OutputString, rbx, $OfsCStr("Code Benchmark using UEFI", 13, 10)
  invoke [rbx].SetAttribute, rbx, EFI_WHITE or EFI_BACKGROUND_BLACK
  assume rbx:nothing

  mov r10, pBootServices
  invoke [r10].EFI_BOOT_SERVICES.SetWatchdogTimer, 0, 0, 0, NULL

  call Benchmark

  SysDone

  mov rbx, pBootServices
  invoke [rbx].EFI_BOOT_SERVICES.Exit, ImageHandle, EFI_SUCCESS, 0, NULL
start endp

end start