@echo off
REM Usage: 
REM   1. copy this file to the destination folder.
REM   2. execute it to to start the build process.

set LogFile=Make.log
if exist "%OBJASM_PATH%1" (
  call "%OBJASM_PATH%\Build\OA_BUILD.cmd" %*
  ) else (
    echo Incorrect Path to ObjAsm
    if not [!LogFile!] == [] (
      echo Incorrect Path to ObjAsm> !LogFile!
    )
    exit /b 1
  )
)

