@echo off
REM Start build process

setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

if exist *.asm (
  REM Set ProjectName to the name of the .asm file on the current directory
  for %%* in (*.asm) do set ProjectName=%%~n*
  set LogFile=Make.log

  REM Dispaly some information
  echo Building !ProjectName! project ...
  echo Building !ProjectName! project ...> !LogFile!
  echo.
  echo.>> !LogFile!

  REM Set build targets.
  call "%OBJASM_PATH%\Build\OA_TARGET.cmd" %*
  if errorlevel 1 goto Error

  REM Display targets on screen
  echo Platform:       !TARGET_PLATFORM!
  echo User Interface: !TARGET_USER_INTERFACE!
  echo Binary Format:  !TARGET_BIN_FORMAT!
  echo Bitness:        !TARGET_BITNESS!
  echo OOP support:    !TARGET_SUPPORT_OOP!
  echo String Type:    !TARGET_STRING_TYPE!
  echo Mode:           !TARGET_MODE_STR!
  echo.

  REM Set known tools.
  call "%OBJASM_PATH%\Build\OA_SET.cmd" %*
  if errorlevel 1 goto Error

  REM Prepare for build
  call "%OBJASM_PATH%\Build\OA_PRE.cmd" %*
  if errorlevel 1 goto Error

  REM Compile type libraries
  call "%OBJASM_PATH%\Build\OA_MIDL.cmd" %*
  if errorlevel 1 goto Error

  REM Compile resources
  call "%OBJASM_PATH%\Build\OA_RES.cmd" %*
  if errorlevel 1 goto Error

  REM Assemble project
  call "%OBJASM_PATH%\Build\OA_ASM.cmd" %*
  if errorlevel 1 goto Error

  REM Link project
  call "%OBJASM_PATH%\Build\OA_LINK.cmd" %*
  if errorlevel 1 goto Error

  if !TARGET_PLATFORM! == UEFI (
    REM Convert PE/DLL to efi image
    call "%OBJASM_PATH%\Build\OA_UEFI.cmd" %*
    if errorlevel 1 goto Error
  )

  REM Housekeeping
  call "%OBJASM_PATH%\Build\OA_POS.cmd" %*
  goto :EOF

  :Error
  call "%OBJASM_PATH%\Build\OA_ERROR.cmd" %*
  goto :EOF

) else (
  echo No project file found^^!
  if not [!LogFile!] == [] (
    echo No project file found^^!> !LogFile!
  )
  call "%OBJASM_PATH%\Build\OA_ERROR.cmd" %*
)
