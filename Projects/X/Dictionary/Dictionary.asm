; ==================================================================================================
; Title:      Dictionary.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Dictionary demonstration application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, NUI64, WIDE_STRING, DEBUG(WND)

% include &MacPath&fMath.inc

MakeObjects Primer, Stream, HashTable, Dictionary, Collection
MakeObjects StopWatch


MY_DIC_ITEM struc
  HTL_ITEM            {}
  pKey      PSTRING   ?           ;Key, usually a POINTER to data/String
MY_DIC_ITEM ends

include WordList.inc

.code
start proc uses xbx xdi xsi
  local Dict:$Obj(Dictionary)
  local SW:$Obj(StopWatch), cBuffer[100]:CHR

  SysInit
  DbgClearAll

  New SW::StopWatch
  OCall SW::StopWatch.Init, NULL

  New Dict::Dictionary
  OCall Dict::Dictionary.Init, NULL, 1024


  mov xdi, offset MY_DIC_ITEMS
  OCall SW::StopWatch.Start
  xor ebx, ebx
  .while ebx < MY_DIC_ITEM_COUNT
    invoke StrComp, [xdi].MY_DIC_ITEM.pKey, $OfsCStr("do")
    .if eax == 0
      int 3
    .endif
    OCall Dict::Dictionary.Insert, xdi
    add xdi, sizeof(MY_DIC_ITEM)
    inc ebx
  .endw
  OCall SW::StopWatch.Stop
  OCall SW::StopWatch.%GetTimeStr, addr cBuffer
  DbgStr cBuffer, "µS"
  DbgDec Dict.dCollisionCount
  DbgText "All items inserted"
  DbgLine

  mov xdi, offset MY_DIC_ITEMS
  OCall SW::StopWatch.Reset
  OCall SW::StopWatch.Start
  xor ebx, ebx
  .while ebx < MY_DIC_ITEM_COUNT
    OCall Dict::Dictionary.Search, [xdi].MY_DIC_ITEM.pKey
    add xdi, sizeof(MY_DIC_ITEM)
    inc ebx
  .endw

  OCall SW::StopWatch.Stop
  OCall SW::StopWatch.%GetTimeStr, addr cBuffer
  DbgStr cBuffer, "µS"
  DbgText "All items found"
  DbgLine

  mov xdi, offset MY_DIC_ITEMS
  OCall SW::StopWatch.Reset
  OCall SW::StopWatch.Start
  xor ebx, ebx
  .while ebx < MY_DIC_ITEM_COUNT
    invoke StrComp, [xdi].MY_DIC_ITEM.pKey, $OfsCStr("do")
    .if eax == 0
      int 3
    .endif
    OCall Dict::Dictionary.Delete, [xdi].MY_DIC_ITEM.pKey
    add xdi, sizeof(MY_DIC_ITEM)
    inc ebx
  .endw

  OCall SW::StopWatch.Stop
  OCall SW::StopWatch.%GetTimeStr, addr cBuffer
  DbgStr cBuffer, "µS"
  DbgText "All items deleted"
  DbgLine

  OCall Dict::Dictionary.Done
  OCall SW::StopWatch.Done

  DbgText "Ready"
  SysDone

  invoke ExitProcess, 0
start endp

end
