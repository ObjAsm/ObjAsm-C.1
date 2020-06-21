@echo off

call "%OBJASM_PATH%\Code\ObjMem\MakeObjMem32.cmd" NOPAUSE
call "%OBJASM_PATH%\Code\ObjMem\MakeObjMem64.cmd" NOPAUSE

echo Build complete^^!

if not [%1] == [NOPAUSE] (
  echo Press any key to close this window.
  pause > nul
)

