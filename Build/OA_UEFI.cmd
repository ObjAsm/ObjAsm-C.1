if exist !ProjectName!.dll (
  echo Converting DLL to EFI image...
  echo Converting DLL to EFI image...>> !LogFile!

  if exist !EfiImageConverter! (
    !EfiImageConverter! app !ProjectName!.dll !ProjectName!.efi>> !LogFile!
    echo.>> !LogFile!
  ) else (
    echo ERROR: EFI Image Converter not found>> !LogFile!
    echo.>> !LogFile!
    exit /b 1
  )
)
