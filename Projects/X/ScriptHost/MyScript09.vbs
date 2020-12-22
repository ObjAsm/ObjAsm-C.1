
Output.Clear
strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colBIOS = objWMIService.ExecQuery _
    ("Select * from Win32_BIOS")

For each objBIOS in colBIOS
    Output.Write "Build Number: " & objBIOS.BuildNumber & vbCRLF
    Output.Write "Current Language: " & objBIOS.CurrentLanguage & vbCRLF
    Output.Write "Installable Languages: " & objBIOS.InstallableLanguages & vbCRLF
    Output.Write "Manufacturer: " & objBIOS.Manufacturer & vbCRLF
    Output.Write "Name: " & objBIOS.Name & vbCRLF
    Output.Write "Primary BIOS: " & objBIOS.PrimaryBIOS & vbCRLF
    Output.Write "Release Date: " & objBIOS.ReleaseDate & vbCRLF
    Output.Write "Serial Number: " & objBIOS.SerialNumber & vbCRLF
    Output.Write "SMBIOS Version: " & objBIOS.SMBIOSBIOSVersion & vbCRLF
    Output.Write "SMBIOS Major Version: " & objBIOS.SMBIOSMajorVersion & vbCRLF
    Output.Write "SMBIOS Minor Version: " & objBIOS.SMBIOSMinorVersion & vbCRLF
    Output.Write "SMBIOS Present: " & objBIOS.SMBIOSPresent & vbCRLF
    Output.Write "Status: " & objBIOS.Status & vbCRLF
    Output.Write "Version: " & objBIOS.Version & vbCRLF
    For i = 0 to Ubound(objBIOS.BiosCharacteristics)
        Output.Write "BIOS Characteristics: " & objBIOS.BiosCharacteristics(i) & vbCRLF
    Next
Next