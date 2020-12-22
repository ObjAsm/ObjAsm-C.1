if exist !ProjectName!.rc (
  echo Compiling !ProjectName!.rc resources ...

  if [!LogFile!] == [] (
    call !ResourceCompiler! /nologo /v /r /x /w /i"%OBJASM_PATH%\Resources" !ProjectName!.rc
  ) else (
    echo Compiling !ProjectName!.rc resources ...>> !LogFile!
    call !ResourceCompiler! /nologo /v /r /x /w /i"%OBJASM_PATH%\Resources" !ProjectName!.rc >> !LogFile!
    echo.>> !LogFile!
  )
)
