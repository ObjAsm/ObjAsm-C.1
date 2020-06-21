@echo off
if exist "%OBJASM_PATH%\Code\ObjMem\ObjMem32.lib" copy "%OBJASM_PATH%\Code\ObjMem\ObjMem32.lib" "%OBJASM_PATH%\Code\Lib\32\ObjAsm\ObjMem32.lib" > nul
if exist "%OBJASM_PATH%\Code\ObjMem\ObjMem64.lib" copy "%OBJASM_PATH%\Code\ObjMem\ObjMem64.lib" "%OBJASM_PATH%\Code\Lib\64\ObjAsm\ObjMem64.lib" > nul
