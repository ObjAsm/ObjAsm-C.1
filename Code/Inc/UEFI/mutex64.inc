linear macro reg, trg, _seg:=<0>
  xor reg,reg
  mov reg,_seg
  ;shl reg, 4
  add reg,trg
endm

qlock64 macro trg, position:=<0>
  push rcx
  lea rax, trg
  linear rcx, rax, position
  dec byte ptr [rcx]
  pop rcx
  endm

qunlock64 macro trg, position:=<0>
  
  local @@unlk
  
  push rcx
  lea rax, trg
  linear rcx, rax, position
  cmp byte ptr [rcx], 0FFh
  jz @@unlk
  inc byte ptr [rcx]
  @@unlk:
  pop rcx
  endm
.data
    mut_core db 0FFh, 0FFh
  mut_cpu db 0FFh, 0FFh, 0FFh, 0FFh,0FFh, 0FFh, 0FFh, 0FFh
  mut_eve db 0FFh, 0FFh, 0FFh, 0FFh,0FFh, 0FFh, 0FFh, 0FFh,0FFh, 0FFh, 0FFh, 0FFh

.code
qwait64:
  ; ax = target mutex in data16
  push rcx
  linear rcx, rax, r10

  @@Loop1a:    
  CMP byte ptr [rcx], 0ffh
  JZ @@OutLoop1a
  pause 
  JMP @@Loop1a
  @@OutLoop1a:
  
  pop rcx
ret


qwaitlock64:
  ; rax = target mutex in data16
  push rbx
  push rcx
  linear rcx,rax

  @@Loop1:    
  mov al,[rcx]
  CMP al,0ffh
  JZ @@OutLoop1
  pause 
  JMP @@Loop1
  @@OutLoop1:
  
  ; Lock is free, can we grab it?
  mov bl,0feh
  MOV AL,0ffh
  LOCK CMPXCHG [rcx],bl
  JNZ @@Loop1 ; Write failed

  @@OutLoop2: ; Lock Acquired

  pop rcx
  pop rbx
ret

lockwait64 MACRO mut_var, position
    qlock64 &mut_var, &position
    lea rax, &mut_var
    mov r10, &position
    call qwait64
endm

UseConsole macro texto1:VARARG
    lea rax, mut_eve
    mov r10, 4
    call qwait64
    qlock64 mut_eve, 4
    mov rcx, pConsole
    invoke [rcx].ConOut.OutputString, rcx, $OfsCStr(<texto1>,13,10)
    qunlock64 mut_eve, 4
endm

UseConsoleAddr macro texto1
    lea rax, mut_eve
    mov r10, 4
    call qwait64
    qlock64 mut_eve, 4
    mov rcx, pConsole
    invoke [rcx].ConOut.OutputString, rcx, addr &texto1
    qunlock64 mut_eve, 4
endm

UseConsoleC macro color1, texto1:VARARG
    ifnb color1
        mov rcx, pConsole                                     ;Colors change
        invoke [rcx].ConOut.SetAttribute, rcx, <color1>
    endif
    lea rax, mut_eve
    mov r10, 4
    call qwait64
    qlock64 mut_eve, 4
    mov rcx, pConsole
    invoke [rcx].ConOut.OutputString, rcx, $OfsCStr(<texto1>,13,10)
    qunlock64 mut_eve, 4
endm
