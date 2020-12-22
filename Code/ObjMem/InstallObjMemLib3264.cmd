@echo off
echo Installing 32 bit ObjMem library...
call %OBJASM_PATH%\Code\ObjMem\InstallObjMemLib32.cmd

echo Installing 64 bit ObjMem library...
call %OBJASM_PATH%\Code\ObjMem\InstallObjMemLib64.cmd

pause
