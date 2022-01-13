; ==================================================================================================
; Title:      Demo01A.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Dictionary demonstration application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, NUI64, WIDE_STRING, DEBUG(WND)

MakeObjects Primer, Stream, HashTable, Collection


Args struct
  Arg1  DWORD   ?
  Arg2  POINTER ?
Args ends


$StrucPtr macro StrucName, Args:vararg
  echo Args
  for Arg, <Args>
    echo Arg
    @CatStr(<mov >, StrucName, <.>, Arg)
  endm
  lea xax, StrucName
  exitm <xax>
endm


.code

CallBack proc Arg1:DWORD, Arg2:DWORD
  ret
CallBack endp

start proc
  local MyColl:$Obj(Collection), MyArgs:Args
  
  SysInit
  DbgClearAll
  New MyColl::Collection
  OCall MyColl::Collection.Init, NULL, 10, 10, 1000
  int 3
  OCall MyColl::Collection.ForEach, offset CallBack, $StrucPtr(MyArgs, <<<Arg1, eax>>>, <<<Arg2, 1235>>>), 0
  OCall MyColl::Collection.Done
  SysDone

  invoke ExitProcess, 0
start endp

end