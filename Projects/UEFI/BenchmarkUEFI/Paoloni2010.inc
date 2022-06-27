; ==================================================================================================
; Title:      Paoloni2010.inc
; Author:     Héctor S. Enrique
; Version:    1.0.0
; Purpose:    Include file for UEFI Benchmark Application.
; Version:    Version 1.0.0, May 2022
;             - First release.
;
; Note:       Gabriele Paoloni, 2010. How to Benchmark Code Execution Times on Intel IA-32 and IA-64
;             Instruction Set Architectures. Retrieved May 26, 2022, from
;             http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-32-ia-64-benchmark-code-execution-paper.pdf
;
;             https://www.mun.ca/biology/scarr/Simplified_calculation_of_variance.html#:~:text=A%20more%20straightforward%20calculation%20recognizes,i2%20)%20%2F%20n%20%2D%202
;             https://www.mun.ca/biology/scarr/Mean_&_Variance.html#:~:text=easily%20calculated%20as
; ==================================================================================================


CalcQwVariance proc pQwValues:POINTER, qCount:QWORD
  local qStep:QWORD

  mov rcx, pQwValues
  xor eax, eax
  fldz
  .while rax < qCount
    fild QWORD ptr [rcx]            ;Load time value
    fld st(0)                       ;Duplicate
    fmulp st(1), st(0)              ;Square
    faddp st(1), st(0)              ;Cummulate
    add rcx, sizeof(QWORD)          ;Goto next value
    inc rax                         ;Increment counter
  .endw
  fild qCount
  fmulp                             ;st(0) = Count*Sum(Value^2)
  ;Check overflow
  fstsw ax
  .ifBitSet ax, MASK fOverflow
    fUnload
    mov qStep, 0
    jmp Overflow
  .endif

  mov rcx, pQwValues
  xor eax, eax
  fldz
  .while rax < qCount
    fadd QWORD ptr[rcx]             ;Cummulate
    add rcx, sizeof(QWORD)          ;Goto next value
    inc rax                         ;Increment counter
  .endw                             ;st(0) = Sum(Value)
  ;Check overflow
  fstsw ax
  .ifBitSet ax, MASK fOverflow
    fUnload 2
    mov qStep, 1
    jmp Overflow
  .endif

  fld st(0)                         ;Duplictae
  fmulp st(1), st(0)                ;Square; st(0) = [Sum(Value)]^2
  ;Check overflow
  fstsw ax
  .ifBitSet ax, MASK fOverflow
    fUnload 2
    mov qStep, 2
    jmp Overflow
  .endif

  fsubp st(1), st(0)                ;st(0) = Count*Sum(Value^2) - [Sum(Value)]^2 
  fild qCount
  fld st(0)                         ;Dulicate
  fmulp st(1), st(0)                ;Square
  fdivp st(1), st(0)                ;st(0) = {Count*Sum(Value^2) - [Sum(Value)]^2}/Count^2 
  ret

Overflow:
  fclex
  fld r8NaN
  PrintC "%E CRITICAL OVERFLOW ERROR IN CalcQwVariance %d", qStep
  ret
CalcQwVariance endp

CalcR8Variance proc pR8Values:POINTER, qCount:QWORD
  local qStep:QWORD

  mov rcx, pR8Values
  xor eax, eax
  fldz
  .while rax < qCount
    fild REAL8 ptr [rcx]            ;Load time value
    fld st(0)                       ;Duplicate
    fmulp st(1), st(0)              ;Square
    faddp st(1), st(0)              ;Cummulate
    add rcx, sizeof(REAL8)          ;Goto next value
    inc rax                         ;Increment counter
  .endw
  fild qCount
  fmulp                             ;st(0) = Count*Sum(Value^2)
  ;Check overflow
  fstsw ax
  .ifBitSet ax, MASK fOverflow
    fUnload
    mov qStep, 0
    jmp Overflow
  .endif

  mov rcx, pR8Values
  xor eax, eax
  fldz
  .while rax < qCount
    fadd REAL8 ptr[rcx]             ;Cummulate
    add rcx, sizeof(REAL8)          ;Goto next value
    inc rax                         ;Increment counter
  .endw                             ;st(0) = Sum(Value)
  ;Check overflow
  fstsw ax
  .ifBitSet ax, MASK fOverflow
    fUnload 2
    mov qStep, 1
    jmp Overflow
  .endif

  fld st(0)                         ;Duplictae
  fmulp st(1), st(0)                ;Square; st(0) = [Sum(Value)]^2
  ;Check overflow
  fstsw ax
  .ifBitSet ax, MASK fOverflow
    fUnload 2
    mov qStep, 2
    jmp Overflow
  .endif

  fsubp st(1), st(0)                ;st(0) = Count*Sum(Value^2) - [Sum(Value)]^2 
  fild qCount
  fld st(0)                         ;Dulicate
  fmulp st(1), st(0)                ;Square
  fdivp st(1), st(0)                ;st(0) = {Count*Sum(Value^2) - [Sum(Value)]^2}/Count^2 
  ret

Overflow:
  fclex
  fld r8NaN
  PrintC "%E CRITICAL OVERFLOW ERROR IN CalcR8Variance %d", qStep
  ret
CalcR8Variance endp

;----------------------------------------------------------------------------------------------

Benchmark proc uses rbx rdi rsi
  local pTimes:POINTER, pVariances:POINTER, r8Variance:REAL8, qSpurious:QWORD, pMinValues:POINTER
  local qMaxDiff:QWORD, qMaxTime:QWORD, qMinTime:QWORD, qPrevMinTime:QWORD
  local r8AccVariance:REAL8, qMaxMaxDiff:QWORD, r8VarOfVars:REAL8, r8VarOfMins:REAL8, r8Temp:REAL8
  local r8Measure:REAL8, r8Overhead:REAL8

  mov rsi, pBootServices
  invoke [rsi].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP*sizeof(REAL8), addr pVariances
  .if pVariances == NULL
    PrintC "%EUnable to allocate memory for pVariances"
    mov rax, EFI_ABORTED
  .else
    invoke [rsi].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP*sizeof(QWORD), addr pMinValues
    .if pMinValues == NULL
      PrintC "%EUnable to allocate memory for pMinValues"
      invoke [rsi].EFI_BOOT_SERVICES.FreePool, pVariances
    .else
      invoke [rsi].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP*sizeof(POINTER), addr pTimes
      .if pTimes == NULL
        PrintC "%EUnable to allocate memory for pTimes"
        invoke [rsi].EFI_BOOT_SERVICES.FreePool, pMinValues
        invoke [rsi].EFI_BOOT_SERVICES.FreePool, pVariances
        mov rax, EFI_ABORTED
      .else
        xor ebx, ebx
        .while rbx < BOUND_OF_LOOP
          mov rax, pTimes
          invoke [rsi].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, SIZE_OF_STAT*sizeof(REAL8), addr [rax + sizeof(POINTER)*rbx]
          .break .if rax != EFI_SUCCESS
          inc rbx
        .endw
        .if rbx != BOUND_OF_LOOP
          PrintC "%EUnable to allocate memory for Time[%d]", rbx
          .while rbx != 0
            dec rbx
            mov rdx, pTimes
            invoke [rsi].EFI_BOOT_SERVICES.FreePool, addr [rdx + sizeof(POINTER)*rbx]
            dec rbx
          .endw
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pTimes
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pMinValues
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pVariances
          mov rax, EFI_ABORTED
        .else
          invoke FillTimes, pTimes

          xor ebx, ebx
          mov qSpurious, rbx
          mov qMaxMaxDiff, rbx
          .while rbx < BOUND_OF_LOOP
            mov qMinTime, -1
            mov qMaxTime, 0

            xor edi, edi
            mov rax, pTimes
            mov rcx, POINTER ptr [rax + sizeof(POINTER)*rbx]
            .while rdi < SIZE_OF_STAT
              mov rdx, QWORD ptr [rcx + sizeof(QWORD)*rdi]
              .if qMinTime > rdx
                mov qMinTime, rdx
              .endif
              .if qMaxTime < rdx
                mov qMaxTime, rdx
              .endif
              inc edi
            .endw
            mov rax, qMaxTime
            sub rax, qMinTime
            mov qMaxDiff, rax
            .if rax > qMaxMaxDiff
              mov qMaxMaxDiff, rax
            .endif

            mov rcx, pMinValues
            mov rax, qMinTime
            mov QWORD ptr [rcx + sizeof(QWORD)*rbx], rax

            mov rcx, qPrevMinTime
            .if (rcx != 0) && (rcx > rax)
              inc qSpurious
            .endif
            mov qPrevMinTime, rax

            mov rdi, pTimes
            invoke CalcQwVariance, POINTER ptr [rdi + sizeof(POINTER)*rbx], SIZE_OF_STAT
            mov rdx, pVariances
            fst REAL8 ptr [rdx + sizeof(REAL8)*rbx]
            fst r8Variance
            fadd r8AccVariance
            fstp r8AccVariance
            ;PrintLn "Loop size: %d; Variance: %f; max. Deviation: %d; min. Time: %d", rbx, r8Variance, qMaxDiff, qMinTime
            inc rbx
          .endw

          invoke CalcR8Variance, pVariances, BOUND_OF_LOOP
          fstp r8VarOfVars
          invoke CalcQwVariance, pMinValues, BOUND_OF_LOOP
          fstp r8VarOfMins

          mov rax, BOUND_OF_LOOP
          %fSlv8 r8Temp = r8AccVariance / rax

          PrintLn "Spurious min. values    = %d", qSpurious
          PrintLn "Max. difference         = %d cycles", qMaxMaxDiff
          PrintLn "Variance of min. values =%f cycles", r8VarOfMins
          PrintLn "Total variance          =%f cycles^2", r8Temp
          PrintLn "Variance of variances   =%f cycles^4", r8VarOfVars
          
          invoke LinearRegression, pMinValues, BOUND_OF_LOOP
          fstp r8Measure
          fstp r8Overhead
          PrintLn "Overhead =%f cycles, Code Execution Time =%f cycles", r8Overhead, r8Measure

          ;Release allocated memory
          mov rsi, pBootServices
          mov rbx, BOUND_OF_LOOP
          mov rdi, pTimes
          .repeat
            invoke [rsi].EFI_BOOT_SERVICES.FreePool, addr [rdi]
            add rdi, sizeof(POINTER)
            dec rbx
          .until ZERO?

          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pMinValues
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pVariances
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pTimes
          mov rax, EFI_SUCCESS
        .endif
      .endif
    .endif
  .endif
  ret
Benchmark endp

