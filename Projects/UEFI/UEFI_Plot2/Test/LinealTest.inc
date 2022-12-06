; ==================================================================================================
; Title:   LinealTest.inc
; Author:  Héctor S. Enrique  @ March 2016
; Version: 1.0.0
; Purpose: Functional Continuos Simulation - IntegAsm32 Light
; ==================================================================================================

Object LinealTest,, SimpleTest

	RedefineMethod Init
	RedefineMethod Muestra
	
ObjectEnd

    
if IMPLEMENT

.data
    CStr nombreM, "modeloC"

.code

if @WordSize eq 8
; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

StdOut proc

  ; rcx = text address

    LOCAL bwrt  :QWORD
    LOCAL .r14  :QWORD
    LOCAL .r15  :QWORD

    mov .r14, r14                       ; preserve non-volatile registers
    mov .r15, r15

    mov r14, rcx                        ; store address in r14
    mov rax, r14
    sub rax, 1
  @@:
    add rax, 1
    cmp BYTE PTR [rax], 0               ; get the text length
    jne @B
    sub rax, r14                        ; sub original address from RAX
    mov r15, rax                        ; save string length into r15

    ; MakeEFI
    ;invoke GetStdHandle,STD_OUTPUT_HANDLE
    ;invoke WriteFile,rax,r14,r15w,ADDR bwrt,NULL

    mov r14, .r14                       ; restore non-volatile registers
    mov r15, .r15

    mov rax, bwrt                       ; return value is bytes written

    ret

StdOut endp
endif

unidadesactivas = -1

Method LinealTest.Init, uses xsi
    local last_unidad: xword
    local last_modelo: xword
    local last_etapa: xword
    
	;local fSlvTLS()
	
    CStr LinealTestInit$,"+LinealTest.Init",13,10
;    mov rcx,pConsole
;    invoke [rcx].ConOut.OutputString, pConsole, ADDR LinealTestInit$

	DbgText "+LinealTest.Init"
	
	SetObject xsi
    
	individuo modeloC
	nuevaetapa 1, 165.0, 10.0
	nuevaetapa 0, 0.0, 825.0
	;finalizaIndividuo
	DbgText "-LinealTest.Init"

MethodEnd

Method LinealTest.Muestra , uses xsi
	
	SetObject xsi

MethodEnd
endif