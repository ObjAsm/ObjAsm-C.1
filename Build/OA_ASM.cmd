if exist !ProjectName!.asm (
  echo Assembling !ProjectName!.asm project ...
  if [!LogFile!] == [] (
    if exist !Assembler! (
      call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.asm
    ) else (
      echo ERROR: Assembler not found
      exit /b 1
    )
  ) else (
    if exist !Assembler! (
      echo Assembling !ProjectName!.asm project ...>> !LogFile!
      call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.asm >> !LogFile!
      echo.>> !LogFile!
    ) else (
      echo ERROR: Assembler not found>> !LogFile!
      exit /b 1
    )
  )
)
