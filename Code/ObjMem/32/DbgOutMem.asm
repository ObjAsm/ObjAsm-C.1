; ==================================================================================================
; Title:      DbgOutMem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMem.cop

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
; Procedure:  DbgOutMem
; Purpose:    Outputs the content of a memory block.
; Arguments:  Arg1: -> Memory block.
;             Arg2: Memory block size.
;             Arg3: Display mode.
;             Arg4: -> Destination Window name.
; Return:     Nothing.

align ALIGN_CODE
DbgOutMem proc uses ebx edi esi, pStart:POINTER, dSize:DWORD, dVCode:DWORD, pDest:POINTER
  local cBuffer[512]:CHRA, cBuff[128]:CHRA

  mov esi, pStart
  mov ebx, dSize
  .while ebx != 0
    lea edi, cBuffer
    invoke dword2hexA, edi, esi
    m2z BYTE ptr [edi + 8]
    invoke DbgOutTextA, edi, $RGB(100,100,200), DBG_EFFECT_BOLD, pDest
    mov WORD ptr [edi],  " :"
    inc edi
    inc edi
    push esi
    push ebx

    ;;Dump hex values:
    xor ecx, ecx
    .while ecx < 16
      .if ecx != 0
        .ifBitClr ecx, BIT01 or BIT00
          .if !ebx
            mov WORD ptr [edi], "  "
          .else
            mov WORD ptr [edi], " -"
          .endif
          add edi, 2
        .endif
      .endif

      .if !ebx
        mov DWORD ptr [edi], "    "
        add edi, 4
      .else
        dec ebx
        xor eax, eax
        mov al, [esi]
        inc esi
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
        mov WORD ptr [edi], ax
        mov WORD ptr [edi + 2], " h"
        add edi, 4
      .endif
      inc ecx
    .endw
    mov eax, ebx
    pop ebx
    pop esi

    m2z BYTE ptr [edi]
    invoke DbgOutTextA, addr cBuffer, $RGB(100,100,200), DBG_EFFECT_NORMAL, pDest
    lea edi, cBuffer

    .if dVCode == 100

      mov DWORD ptr [edi], "  | "
      add edi, 4

      ;;Dump text output:
      xor ecx, ecx
      .while ecx < 16
        mov al, [esi]
        .if !ebx
          mov al, " "
        .else
          dec ebx
          inc esi
          cmp al, 20h
          jae @F
          mov al, "."
@@:
        .endif
        mov [edi], al
        inc edi
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_UI8

      mov DWORD ptr [edi], "  U:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 16
        mov al, [esi]
        .if !ebx
          mov al, " "
          mov [edi], al
          inc edi
        .else
          dec ebx
          inc esi
          push ecx
          movzx ecx, al
          invoke wsprintfA, edi, offset dbfmt01, ecx
          pop ecx
          add edi, 4

          mov eax, ecx
          .if (eax == 3) || (eax == 7) || (eax == 11)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_UI16

      mov DWORD ptr [edi], "  U:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 8
        mov ax, [esi]

        .if ebx && (ebx < 2)
          add esi, ebx
          xor ebx, ebx
        .endif

        .if ebx >= 2
          sub ebx, 2
          add esi, 2

          push ecx
          movzx ecx, ax
          invoke wsprintfA, edi, offset dbfmt02, ecx
          pop ecx
          add edi, 6

          mov eax, ecx
          .if (eax == 1) || (eax == 3) || (eax == 5)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_UI32

      mov DWORD ptr [edi], "  U:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 4
        mov eax, [esi]

        .if ebx && (ebx < 4)
          add esi, ebx
          xor ebx, ebx
        .endif

        .if ebx >= 4
          sub ebx, 4
          add esi, 4

          push ecx
          mov ecx, eax
          invoke wsprintfA, edi, offset dbfmt03, ecx
          pop ecx
          add edi, 11

          mov eax, ecx
          .if (eax == 0) || (eax == 1) || (eax == 2)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_I8

      mov DWORD ptr [edi], "  D:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 16
        mov al, [esi]
        .if !ebx
          mov al, " "
          mov [edi], al
          inc edi
        .else
          dec ebx
          inc esi
          push ecx
          movsx ecx, al
          invoke wsprintfA, edi, offset dbfmt04, ecx
          pop ecx
          add edi, 5

          mov eax, ecx
          .if (eax == 3) || (eax == 7) || (eax == 11)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_I16

      mov DWORD ptr [edi], "  D:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 8
        mov ax, [esi]

        .if ebx && (ebx < 2)
          add esi, ebx
          xor ebx, ebx
        .endif

        .if ebx >= 2
          sub ebx, 2
          add esi, 2

          push ecx
          movsx ecx, ax
          invoke wsprintfA, edi, offset dbfmt05, ecx
          pop ecx
          add edi, 7

          mov eax, ecx
          .if (eax == 1) || (eax == 3) || (eax == 5)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_I32

      mov DWORD ptr [edi], "  D:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 4
        mov eax, [esi]

        .if ebx && (ebx < 4)
          add esi, ebx
          xor ebx, ebx
        .endif

        .if ebx >= 4
          sub ebx, 4
          add esi, 4

          push ecx
          mov ecx, eax
          invoke wsprintfA, edi, offset dbfmt06, ecx
          pop ecx
          add edi, 12

          mov eax, ecx
          .if (eax == 0) || (eax == 1) || (eax == 2)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw


    .elseif dVCode == DBG_MEM_R4

      mov DWORD ptr [edi], "  R:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 4
        mov eax, esi

        .if ebx && (ebx < 4)
          add esi, ebx
          xor ebx, ebx
        .endif

        .if ebx >= 4
          sub ebx, 4
          add esi, 4

          push ecx
          fld REAL4 ptr [eax]
          invoke St0ToStrA, addr cBuff, 0, 4, f_SCI
          fUnload
          invoke wsprintfA, edi, offset dbfmt07, addr cBuff
          pop ecx

          add edi, 15

          mov eax, ecx
          .if (eax == 0) || (eax == 1) || (eax == 2)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_R8

      mov DWORD ptr [edi], "  R:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 2
        mov eax, esi

        .if ebx && (ebx < 8)
          add esi, ebx
          xor ebx, ebx
        .endif

        .if ebx >= 8
          sub ebx, 8
          add esi, 8

          push ecx
          fld REAL8 ptr [eax]
          invoke St0ToStrA, addr cBuff, 0, 4, f_SCI
          fUnload
          invoke wsprintfA, edi, offset dbfmt07, addr cBuff
          pop ecx

          add edi, 15

          mov eax, ecx
          .if (eax == 0)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_H8

      mov DWORD ptr [edi], "  H:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 16
        mov al, [esi]
        .if !ebx
          mov al, " "
          mov [edi], al
          inc edi
        .else
          dec ebx
          inc esi
          push ecx
          movzx ecx, al
          invoke wsprintfA, edi, offset dbfmt08, ecx
          pop ecx
          add edi, 2

          mov eax, ecx
          .if (eax == 3) || (eax == 7) || (eax == 11)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_H16

      mov DWORD ptr [edi], "  H:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 8
        mov ax, [esi]

        .if ebx && (ebx < 2)
          add esi, ebx
          xor ebx, ebx
        .endif

        .if ebx >= 2
          sub ebx, 2
          add esi, 2

          push ecx
          movzx ecx, ax
          invoke wsprintfA, edi, offset dbfmt09, ecx
          pop ecx
          add edi, 4

          mov eax, ecx
          .if (eax == 1) || (eax == 3) || (eax == 5)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .elseif dVCode == DBG_MEM_H32

      mov DWORD ptr [edi], "  H:"
      add edi, 4

      xor ecx, ecx
      .while ecx < 4
        mov eax, [esi]

        .if ebx && (ebx < 4)
          add esi, ebx
          xor ebx, ebx
        .endif

        .if ebx >= 4
          sub ebx, 4
          add esi, 4

          push ecx
          mov ecx, eax
          invoke wsprintfA, edi, offset dbfmt10, ecx
          pop ecx
          add edi, 8

          mov eax, ecx
          .if (eax == 0) || (eax == 1) || (eax == 2)
            mov WORD ptr [edi], "  "
            add edi, 2
          .endif

        .endif
        inc ecx
      .endw

    .else
      mov ebx, eax
    .endif

    m2z BYTE ptr [edi]
    invoke DbgOutTextA, addr cBuffer, $RGB(100,00,00), DBG_EFFECT_NEWLINE, pDest
  .endw
  ret
DbgOutMem endp

end
