@echo off
REM Usage: 
REM   1. copy this file to the destination folder.
REM   2. execute it to to start the build process.

call "%OBJASM_PATH%\Build\OA_BUILD.cmd" %*
REM copy PlotUEFI.efi Y:\app.efi
REM "C:\Program Files\Virtual Machine USB Boot\Virtual Machine USB Boot.x64.exe"

