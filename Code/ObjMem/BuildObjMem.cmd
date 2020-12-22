@echo off

setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

call "%OBJASM_PATH%\Code\ObjMem\InstallObjMemInc.cmd"

echo Building ObjMem!TARGET_BITNESS! library ...
echo.

if [!TARGET_BITNESS!] == [] (
  echo Missing targets...
  call %OBJASM_PATH%\Build\OA_ERROR.cmd
) else (
  pushd
  cd %OBJASM_PATH%\Code\ObjMem\!TARGET_BITNESS!
  
  REM delete all leftover .obj, .lib & .err files that can disturb the build process
  if exist *.err del *.err
  if exist *.obj del *.obj
  if exist *.lib del *.lib
  
  REM Start assembling all files in current directory
  @echo Assembling files ...
  call %OBJASM_PATH%\Build\OA_SET.cmd
  call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_LIB_!TARGET_BITNESS!.txt" *.asm
  if exist *.err (
    echo -- Error compiling source files -- Press any key to close this window
    pause > nul
  ) else (
    REM Create the .lib file
    @echo Building library file ...
    call !LibraryCompiler! @"%OBJASM_PATH%\Build\Options\OPT_LIB_!TARGET_MODE!_!TARGET_BITNESS!.txt" *.obj /OUT:"%OBJASM_PATH%\Code\ObjMem\ObjMem!TARGET_BITNESS!.lib"
    if not exist "%OBJASM_PATH%\Code\ObjMem\ObjMem!TARGET_BITNESS!.lib" (
      echo -- Error building the lib file -- Press any key to close this window
      pause > nul
    ) else (
      if exist *.obj del *.obj
      REM Install library
      cd..
      call "%OBJASM_PATH%\Code\ObjMem\InstallObjMemLib!TARGET_BITNESS!.cmd"
      echo Installation ready^^!
      echo.
    )
  )
  if not [%1] == [NOPAUSE] (
    echo Press any key to close this window.
    pause > nul
  )
  popd
)
