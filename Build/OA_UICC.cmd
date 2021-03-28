if exist !ProjectName!.xml (
  echo Compiling UI resources ...
  echo Compiling UI resources ...>> !LogFile!

  !UICCompiler! !ProjectName!.xml /header:!ProjectName!.h /res:!ProjectName!.rib>> !LogFile!

  echo.>> !LogFile!
)

