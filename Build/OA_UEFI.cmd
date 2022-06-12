if exist !ProjectName!.dll (
  echo Converting DLL to EFI ...
  echo Converting DLL to EFI ...>> !LogFile!

  !EfiImageConverter! app !ProjectName!.dll !ProjectName!.efi >> !LogFile!

  echo.>> !LogFile!
)
