if exist !ProjectName!.dll (
  echo Converting DLL to EFI image...
  echo Converting DLL to EFI image...>> !LogFile!

  !EfiImageConverter! app !ProjectName!.dll !ProjectName!.efi >> !LogFile!

  echo.>> !LogFile!
)
