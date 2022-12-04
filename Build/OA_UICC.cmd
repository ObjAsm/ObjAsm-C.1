if exist !ProjectName!.xml (
  echo Compiling UI resources ...
  echo Compiling UI resources ...>> !LogFile!

  if exist !UICCompiler! (
    !UICCompiler! !ProjectName!.xml /header:!ProjectName!.h /res:!ProjectName!.rib>> !LogFile!
    echo.>> !LogFile!
  ) else (
    echo ERROR: UIC Compiler not found>> !LogFile!
    echo.>> !LogFile!
    exit /b 1
  )
)
