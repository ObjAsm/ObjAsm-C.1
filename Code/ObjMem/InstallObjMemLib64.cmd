@echo off
if exist "%OBJASM_PATH%\Code\ObjMem\ObjMem64.lib" copy /y "%OBJASM_PATH%\Code\ObjMem\ObjMem64.lib" "%OBJASM_PATH%\Code\Lib\64\ObjAsm\ObjMem64.lib" > nul
