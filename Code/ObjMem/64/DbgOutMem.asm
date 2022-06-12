; ==================================================================================================
; Title:      DbgOutMem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

CStrA dbfmt01, "%03u "
CStrA dbfmt02, "%05u "
CStrA dbfmt03, "%010u "
CStrA dbfmt04, "%04d "
CStrA dbfmt05, "%06d "
CStrA dbfmt06, "%011d "
CStrA dbfmt07, "%-14s "
CStrA dbfmt08, "%02X"
CStrA dbfmt09, "%04X"
CStrA dbfmt10, "%08X"

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Outputs the content of a memory block.
; Arguments:  Arg1: -> Memory block.
;             Arg2: Memory block size.
;             Arg3: Display mode.
;             Arg4: -> Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutMem proc uses rbx rdi rsi, pStart:POINTER, dSize:DWORD, dVCode:DWORD, pDest:POINTER
  local cBuffer[512]:CHRA, cBuff[128]:CHRA, qRSI:QWORD, qRBX:QWORD, qRCX:QWORD

  mov rsi, pStart
  mov ebx, dSize
  .while SQWORD ptr rbx > 0
    lea rdi, cBuffer
    invoke qword2hexA, rdi, esi
    invoke DbgOutTextA, rdi, $RGB(100,100,200), DBG_EFFECT_BOLD, pDest
    mov WORD ptr [rdi],  " :"
    inc rdi
    inc rdi
    mov qRSI, rsi
    mov qRBX, rbx

    ;;Dump hex values:
    xor ecx, ecx
    .while SQWORD ptr rcx < 16
      .if rcx != 0
        .ifBitClr rcx, BIT01 or BIT00
          .if !rbx
            mov WORD ptr [rdi], "  "
          .else
            mov WORD ptr [rdi], " -"
          .endif
          add rdi, 2
        .endif
      .endif

      .if !rbx
        mov DWORD ptr [rdi], "    "
        add rdi, 4
      .else
        dec rbx
        xor eax, eax
        mov al, [rsi]
        inc rsi
        ror ax, 4
        shr ah, 4
        add ax, 3030h
        cmp ah, 39h
        jbe @F
        add ah, "A" - 3Ah
@@:
        cmp al, 39h
        jbe @F
        add al, "A" - 3Ah
@@:
        mov WORD ptr [rdi], ax
        mov WORD ptr [rdi + 2], " h"
        add rdi, 4
      .endif
      inc rcx
    .endw
    mov rax, rbx
    mov rbx, qRBX
    mov rsi, qRSI

    m2z BYTE ptr [rdi]
    invoke DbgOutTextA, addr cBuffer, $RGB(100,100,200), DBG_EFFECT_NORMAL, pDest
    lea rdi, cBuffer

    .if dVCode == DBG_MEM_STRA
      mov DWORD ptr [rdi], "  | "
      add rdi, 4

      ;;Dump text output:
      xor ecx, ecx
      .while SQWORD ptr rcx < 16
        mov al, [rsi]
        .if !rbx
          mov al, " "
        .else
          dec rbx
          inc rsi
          .if al < " "                                  ;Not printable
            mov al, "."
          .endif
        .endif
        mov [rdi], al
        inc rdi
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_STRW
      mov DWORD ptr [rdi], "  | "
      add rdi, 4

      ;;Dump text output:
      xor ecx, ecx
      .while SQWORD ptr rcx < 16
        mov ax, [rsi]
        .if !rbx
          mov ax, " "
        .else
          dec rbx
          add rsi, 2
          .if ax < " " || ax > 255                      ;Not printable
            mov ax, "."
          .endif
        .endif
        mov [rdi], al
        inc rdi
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_UI8
      mov DWORD ptr [rdi], "  U:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 16
        mov al, [rsi]
        .if !rbx
          mov al, " "
          mov [rdi], al
          inc rdi
        .else
          dec rbx
          inc rsi
          mov qRCX, rcx
          movzx rcx, al
          invoke wsprintfA, rdi, offset dbfmt01, rcx
          mov rcx, qRCX
          add rdi, 4

          mov rax, rcx
          .if (rax == 3) || (rax == 7) || (rax == 11)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_UI16
      mov DWORD ptr [rdi], "  U:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 8
        mov ax, [rsi]

        .if rbx && (rbx < 2)
          add rsi, rbx
          xor ebx, ebx
        .endif

        .if rbx >= 2
          sub rbx, 2
          add rsi, 2

          mov qRCX, rcx
          movzx rcx, ax
          invoke wsprintfA, rdi, offset dbfmt02, rcx
          mov rcx, qRCX
          add rdi, 6

          mov rax, rcx
          .if (rax == 1) || (rax == 3) || (rax == 5)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_UI32
      mov DWORD ptr [rdi], "  U:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 4
        mov rax, [rsi]

        .if rbx && (rbx < 4)
          add rsi, rbx
          xor ebx, ebx
        .endif

        .if rbx >= 4
          sub rbx, 4
          add rsi, 4

          mov qRCX, rcx
          mov rcx, rax
          invoke wsprintfA, rdi, offset dbfmt03, rcx
          mov rcx, qRCX
          add rdi, 11

          mov rax, rcx
          .if (rax == 0) || (rax == 1) || (rax == 2)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_I8
      mov DWORD ptr [rdi], "  S:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 16
        mov al, [rsi]
        .if !rbx
          mov al, " "
          mov [rdi], al
          inc rdi
        .else
          dec rbx
          inc rsi
          mov qRCX, rcx
          movsx rcx, al
          invoke wsprintfA, rdi, offset dbfmt04, rcx
          mov rcx, qRCX
          add rdi, 5

          mov rax, rcx
          .if (rax == 3) || (rax == 7) || (rax == 11)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_I16
      mov DWORD ptr [rdi], "  S:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 8
        mov ax, [rsi]

        .if rbx && (rbx < 2)
          add rsi, rbx
          xor ebx, ebx
        .endif

        .if rbx >= 2
          sub rbx, 2
          add rsi, 2

          mov qRCX, rcx
          movsx rcx, ax
          invoke wsprintfA, rdi, offset dbfmt05, rcx
          mov rcx, qRCX
          add rdi, 7

          mov rax, rcx
          .if (rax == 1) || (rax == 3) || (rax == 5)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_I32
      mov DWORD ptr [rdi], "  S:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 4
        mov rax, [rsi]

        .if rbx && (rbx < 4)
          add rsi, rbx
          xor ebx, ebx
        .endif

        .if rbx >= 4
          sub rbx, 4
          add rsi, 4

          mov qRCX, rcx
          mov rcx, rax
          invoke wsprintfA, rdi, offset dbfmt06, rcx
          mov rcx, qRCX
          add rdi, 12

          mov rax, rcx
          .if (rax == 0) || (rax == 1) || (rax == 2)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_R4
      mov DWORD ptr [rdi], "  R:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 4
        mov rax, rsi

        .if rbx && (rbx < 4)
          add rsi, rbx
          xor ebx, ebx
        .endif

        .if rbx >= 4
          sub rbx, 4
          add rsi, 4

          mov qRCX, rcx
          fld REAL4 ptr [rax]
          invoke St0ToStrA, addr cBuff, 0, 4, f_SCI
          fUnload
          invoke wsprintfA, rdi, offset dbfmt07, addr cBuff
          mov rcx, qRCX

          add rdi, 15

          mov rax, rcx
          .if (rax == 0) || (rax == 1) || (rax == 2)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_R8
      mov DWORD ptr [rdi], "  R:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 2
        mov rax, rsi

        .if rbx && (rbx < 8)
          add rsi, rbx
          xor ebx, ebx
        .endif

        .if rbx >= 8
          sub rbx, 8
          add rsi, 8

          mov qRCX, rcx
          fld REAL8 ptr [rax]
          invoke St0ToStrA, addr cBuff, 0, 4, f_SCI
          fUnload
          invoke wsprintfA, rdi, offset dbfmt07, addr cBuff
          mov rcx, qRCX

          add rdi, 15

          mov rax, rcx
          .if (rax == 0)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_H8
      mov DWORD ptr [rdi], "  H:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 16
        mov al, [rsi]
        .if !rbx
          mov al, " "
          mov [rdi], al
          inc rdi
        .else
          dec rbx
          inc rsi
          mov qRCX, rcx
          movzx rcx, al
          invoke wsprintfA, rdi, offset dbfmt08, rcx
          mov rcx, qRCX
          add rdi, 2

          mov rax, rcx
          .if (rax == 3) || (rax == 7) || (rax == 11)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_H16
      mov DWORD ptr [rdi], "  H:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 8
        mov ax, [rsi]

        .if rbx && (rbx < 2)
          add rsi, rbx
          xor ebx, ebx
        .endif

        .if rbx >= 2
          sub rbx, 2
          add rsi, 2

          mov qRCX, rcx
          movzx rcx, ax
          invoke wsprintfA, rdi, offset dbfmt09, rcx
          mov rcx, qRCX
          add rdi, 4

          mov rax, rcx
          .if (rax == 1) || (rax == 3) || (rax == 5)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .elseif dVCode == DBG_MEM_H32
      mov DWORD ptr [rdi], "  H:"
      add rdi, 4

      xor ecx, ecx
      .while SQWORD ptr rcx < 4
        mov rax, [rsi]

        .if rbx && (rbx < 4)
          add rsi, rbx
          xor ebx, ebx
        .endif

        .if rbx >= 4
          sub rbx, 4
          add rsi, 4

          mov qRCX, rcx
          mov rcx, rax
          invoke wsprintfA, rdi, offset dbfmt10, rcx
          mov rcx, qRCX
          add rdi, 8

          mov rax, rcx
          .if (rax == 0) || (rax == 1) || (rax == 2)
            mov WORD ptr [rdi], "  "
            add rdi, 2
          .endif

        .endif
        inc rcx
      .endw

    .else
      mov rbx, rax
    .endif

    m2z BYTE ptr [rdi]
    invoke DbgOutTextA, addr cBuffer, $RGB(100,00,00), DBG_EFFECT_NEWLINE, pDest
  .endw
  ret
DbgOutMem endp

end
