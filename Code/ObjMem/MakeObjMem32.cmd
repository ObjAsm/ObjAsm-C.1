@echo off
set TARGET_BITNESS=32
set TARGET_MODE=RLS

call "%OBJASM_PATH%\Code\ObjMem\BuildObjMem.cmd" %*
