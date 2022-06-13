; ==================================================================================================
; Title:      Paoloni2010.inc
; Author:     Héctor S. Enrique
; Version:    1.0.0
; Purpose:    Include file for UEFI Benchmark Application.
; Version:    Version 1.0.0, May 2022
;             - First release.
;
; Note:       Gabriele Paoloni. 2010. How to Benchmark Code Execution Times on Intel IA-32 and IA-64
;             Instruction Set Architectures. Retrieved May 26, 2022, from 
;             http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-32-ia-64-benchmark-code-execution-paper.pdf
; ==================================================================================================


var_calc2 proc inputs:POINTER, .size:QWORD
  local i:QWORD, i_t:QWORD
  local acc:REAL8, previous:REAL8, temp_var:REAL8
  local salto:QWORD
  local .r9:QWORD

  fSlv8 acc = 0
  fSlv8 previous = 0
  
  ForLp_df i, 0, .size
    .if fLT(acc, previous)
      mov salto, 0
      jmp overflow
    .endif
    fSlv8 previous = acc;
    mov r9, i
    shl r9, 3
    add r9, inputs
    mov rax, QWORD ptr [r9]
    mov .r9, rax
    fild QWORD ptr [r9]
    fadd acc
    fstp acc
  Next i

  fSlv acc = acc * acc
  .if fLT(acc, previous)
    mov salto, 1
    jmp overflow
  .endif

  fSlv8 temp_var = 0
  fSlv8 previous = 0

  ForLp_df i, 0, .size
    .if fLT(temp_var, previous)
      mov salto, 2
      jmp overflow
    .endif
    fSlv8 previous = temp_var
    mov r9, i
    shl r9, 3
    add r9, inputs
    fild QWORD ptr [r9]
    fld st
    fmul
    fadd temp_var
    fstp temp_var
  Next i
  fSlvW temp_var *= .size;
  
  .if fLT(temp_var, previous)
    mov salto, 3
    jmp overflow
  .endif    
  fSlv8 = (temp_var - acc) / .size ^ 2
  ret
overflow:
  PrintC "%E \n\n  CRITICAL OVERFLOW ERROR IN var_calc %d \n\n ", salto
  fSlv = r8NaN
  ret
var_calc2 endp

fvar_calc proc inputs: POINTER, .size:QWORD
  local i:QWORD, i_t:QWORD
  local acc:REAL8, previous:REAL8, temp_var:REAL8
  local salto:QWORD
  local variance:REAL8
  
  fSlv8 acc = 0
  fSlv8 previous = 0
  
  ForLp_df i, 0, .size
    .if fLT(acc, previous)
      mov salto, 0
      jmp overflow
    .endif
    fSlv8 previous = acc;
    mov r9, i
    shl r9, 3
    add r9, inputs
    ;add r9, QWORD ptr[r8]
    fld QWORD ptr [r9]
    fadd acc
    fstp acc
  Next i

  fSlv acc = acc * acc
  .if fLT(acc, previous)
    mov salto, 1
    jmp overflow
  .endif

  fSlv8 temp_var = 0
  fSlv8 previous = 0

  ForLp_df i, 0, .size
    .if fLT(temp_var, previous)
      mov salto, 2
      jmp overflow
    .endif
    fSlv8 previous = temp_var
    mov r9, i
    shl r9, 3
    add r9, inputs
    fld REAL8 ptr [r9]
    fld st
    fmul
    fadd temp_var
    fstp temp_var
  Next i
  fSlvW temp_var *= .size;
  
  .if fLT(temp_var, previous)
    mov salto, 3
    jmp overflow
  .endif    
  fSlv8 = (temp_var - acc) / .size ^ 2
  ret

overflow:
  PrintC "%E \n\n  CRITICAL OVERFLOW ERROR IN var_calc %d \n\n ", salto
  fSlv = r8NaN
  ret
fvar_calc endp

var_calc proc inputs: POINTER, .size:QWORD
  local i:QWORD, i_t:QWORD
  local acc:REAL8, previous:REAL8, temp_var:REAL8
  local salto:QWORD
  
  fSlv8 acc = 0
  fSlv8 previous = 0
  
  ForLp_df i, 0, .size
    .if fLT(acc, previous)
      mov salto, 0
      jmp overflow
    .endif
    fSlv8 previous = acc;
    mov r9, i
    shl r9, 3
    mov r8, inputs
    add r9, QWORD ptr[r8]
    fild QWORD ptr [r9]
    fadd acc
    fstp acc
  Next i

  fSlv acc = acc * acc
  .if fLT(acc, previous)
    mov salto, 1
    jmp overflow
  .endif

  fSlv8 temp_var = 0
  fSlv8 previous = 0

  ForLp_df i, 0, .size
    .if fLT(temp_var, previous)
      mov salto, 2
      jmp overflow
    .endif
    fSlv8 previous = temp_var
    mov r9, i
    shl r9, 3
    mov r8, inputs
    add r9, QWORD ptr[r8]
    mov r8, QWORD ptr [r9]
    fSlvW temp_var += r8 ^ 2
  Next i

  fSlvW temp_var *= .size;
  
  .if fLT(temp_var, previous)
    mov salto, 3
    jmp overflow
  .endif    
  fSlv8 = (temp_var - acc) / .size ^ 2
  ret

overflow:
  PrintC "%E \n\n  CRITICAL OVERFLOW ERROR IN var_calc %d \n\n ", salto
  fSlv = r8NaN
  ret
var_calc endp

;----------------------------------------------------------------------------------------------

BM_start proc
  local i:QWORD, i_t:QWORD, j:QWORD, j_t:QWORD
  local spurious:QWORD, k:QWORD, k_t:QWORD
  local times:POINTER
  local variances:POINTER, variance:REAL8

  local min_values:POINTER
  local max_dev:REAL8, min_time:QWORD, max_time:QWORD, prev_min:QWORD
  local tot_var:REAL8, max_dev_all:REAL8, var_of_vars:REAL8, var_of_mins:REAL8

  local .r8:QWORD, .rax:QWORD
  local tempR:REAL8

  local measure:REAL8, overhead:REAL8
  
  PrintC "%H Loading hello module..."

  mov r10, pBootServices
  invoke [r10].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP * 8, addr times
  .if !times
    PrintC  "%E unable to allocate memory for times\n"
    mov rax, EFI_ABORTED
  .endif
  ForLp_df j, 0, BOUND_OF_LOOP
    mov r8, times
    shl rax, 3
    add r8, rax
    mov .r8, r8
    mov r10, pBootServices
    invoke [r10].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, SIZE_OF_STAT * 8, r8
    mov r8, .r8
    mov r9, QWORD ptr [r8]
    .if !r9
      PrintC "%E unable to allocate memory for times[%d]\n", j
      ForLp_df k, 0, j
        mov rcx, times
        shl rax, 3
        add rcx, rax
        invoke [rax].EFI_BOOT_SERVICES.FreePool, rcx 
      Next k
      mov rax, 0;
    .endif
  Next j

  mov r10, pBootServices
  invoke [r10].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP * 8, ADDR variances

  .if !variances
    PrintC "%E unable to allocate memory for variances\n"
    mov rax, 0;
  .endif

  mov r10, pBootServices
  invoke [r10].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP * 8, ADDR min_values

  .if !min_values
    PrintC "%E unable to allocate memory for min_values\n"
    mov rax, 0
  .endif

  invoke Filltimes, times

  ForLp_df j, 0, BOUND_OF_LOOP

    mov min_time , 0
    mov max_time , 0

    ForLp_df i, 0, SIZE_OF_STAT
      mov r8, times
      mov r9, j
      shl r9, 3
      add r9, r8
      mov r8, QWORD ptr [r9]
      mov r9, i
      shl r9, 3
      add r8, r9
      mov r10, QWORD ptr [r8]
      mov .r8, r10 
      .if ((min_time == 0) || (min_time > r10))
        mov min_time, r10
      .endif
      mov r10, .r8    
      .if (max_time < r10)
        mov max_time, r10
      .endif    
    Next i
    mov rax, max_time
    sub rax, min_time
    fSlv8 max_dev = max_time - min_time

    mov r8, min_values
    mov rax, j
    shl rax, 3
    add r8, rax
    mov rax, min_time
    mov QWORD ptr [r8], rax

    .if ((prev_min != 0) && (prev_min > rax))
       inc spurious
    .endif
    .if fGT(max_dev, max_dev_all)
      fSlv8 max_dev_all = max_dev
    .endif
    
    mov rcx, times
    mov rax, j
    shl rax, 3
    add rcx, rax
    invoke var_calc, rcx, SIZE_OF_STAT
    mov rdx, variances
    mov rax, j
    shl rax, 3
    add rdx, rax
    fst REAL8 ptr [rdx]
    fst variance 
    fadd tot_var
    fstp tot_var
    PrintC "loop_size:%d $$$$ variance(cycles): %f ; max_deviation: %f ;min time: %d ", j, variance, max_dev, min_time
    m2m prev_min, min_time, rax
  Next j

  invoke fvar_calc, variances, BOUND_OF_LOOP
  fstp var_of_vars 
  invoke var_calc2, min_values, BOUND_OF_LOOP
  fstp var_of_mins 

  mov r8, BOUND_OF_LOOP    
  %fSlv8 tempR = tot_var / r8
  PrintC "  total number of spurious min values = %d ", spurious
  PrintC "  total variance             = %f ", tempR
  PrintC "  absolute max deviation     = %f ", max_dev_all
  PrintC "  variance of variances      = %f ", var_of_vars
  PrintC "  variance of minimum values = %f ", var_of_mins

  invoke lineal, min_values, BOUND_OF_LOOP
  fstp measure
  fstp overhead
  PrintC "%H     overhead = %f        measure = %f ", overhead, measure    

  ForLp_df j, 0, BOUND_OF_LOOP
    mov rdx, times
    shl rax, 3
    add rdx, rax
    mov rcx, QWORD ptr [rdx]
    mov r10, pBootServices
    invoke [r10].EFI_BOOT_SERVICES.FreePool, rcx 
  Next j

  mov r10, pBootServices
  invoke [r10].EFI_BOOT_SERVICES.FreePool, times 
  mov r10, pBootServices
  invoke [r10].EFI_BOOT_SERVICES.FreePool, variances
  mov r10, pBootServices
  invoke [r10].EFI_BOOT_SERVICES.FreePool, min_values 
  mov rax, EFI_SUCCESS
BM_start endp

