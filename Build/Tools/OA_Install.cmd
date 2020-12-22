@echo off
@echo ObjAsm Installation
@echo.
set /p OA_PATH="Enter ObjAsm installation path: "
if not "%OA_PATH%" == "" setx OBJASM_PATH %OA_PATH%

set /p RA_PATH="Enter RadAsm installation path: "
if not "%RA_PATH%" == "" setx RADASM_PATH %RA_PATH%