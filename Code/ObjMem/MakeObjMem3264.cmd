@echo off
start "Building 32 bit ObjMem library" "%OBJASM_PATH%\Code\ObjMem\MakeObjMem32.cmd" NOPAUSE
start "Building 64 bit ObjMem library" "%OBJASM_PATH%\Code\ObjMem\MakeObjMem64.cmd" NOPAUSE
