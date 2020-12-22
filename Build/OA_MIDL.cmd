if exist !ProjectName!.idl (
  echo Compiling Type Library ...

  if exist !ProjectName!.tlb del !ProjectName!.tlb
  if [!LogFile!] == [] (
    call !MidlCompiler! /I %OBJASM_PATH%\Code\Inc\COM\IDL @"%OBJASM_PATH%\Build\Options\OPT_MIDL_!TARGET_BITNESS!.txt" !ProjectName!.idl
  ) else (
    echo Compiling Type Library ...>> !LogFile!
    call !MidlCompiler! /I %OBJASM_PATH%\Code\Inc\COM\IDL @"%OBJASM_PATH%\Build\Options\OPT_MIDL_!TARGET_BITNESS!.txt" !ProjectName!.idl>> !LogFile!
    echo.>> !LogFile!
  )
)
