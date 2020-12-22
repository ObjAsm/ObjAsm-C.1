if exist !ProjectName!.asm (
  echo Assembling !ProjectName!.asm project ...
  if [!LogFile!] == [] (
    call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.asm
  ) else (
    echo Assembling !ProjectName!.asm project ...>> !LogFile!
    call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.asm >> !LogFile!
    echo.>> !LogFile!
  )
)
