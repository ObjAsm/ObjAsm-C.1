Const HKLM = &H80000002 'HKEY_LOCAL_MACHINE
Output.Clear
strComputer = "."
strKey = "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\"
strEntry1a = "DisplayName"
strEntry1b = "QuietDisplayName"
strEntry2 = "InstallDate"
strEntry3 = "VersionMajor"
strEntry4 = "VersionMinor"
strEntry5 = "EstimatedSize"

Set objReg = GetObject("winmgmts://" & strComputer & "/root/default:StdRegProv")
objReg.EnumKey HKLM, strKey, arrSubkeys
Output.Write "Installed Applications" & VbCrLf
For Each strSubkey In arrSubkeys
  intRet1 = objReg.GetStringValue(HKLM, strKey & strSubkey, strEntry1a, strValue1)
  If intRet1 <> 0 Then
    objReg.GetStringValue HKLM, strKey & strSubkey, strEntry1b, strValue1
  End If
  If strValue1 <> "" Then
    Output.Write VbCrLf & "Display Name: " & strValue1
  End If
  objReg.GetStringValue HKLM, strKey & strSubkey, strEntry2, strValue2
  If strValue2 <> "" Then
    Output.Write " Install Date: " & strValue2
  End If
  objReg.GetDWORDValue HKLM, strKey & strSubkey, strEntry3, intValue3
  objReg.GetDWORDValue HKLM, strKey & strSubkey, strEntry4, intValue4
  If intValue3 <> "" Then
     Output.Write " Version: " & intValue3 & "." & intValue4
  End If
  objReg.GetDWORDValue HKLM, strKey & strSubkey, strEntry5, intValue5
  If intValue5 <> "" Then
    Output.Write " Estimated Size: " & Round(intValue5/1024, 3) & " megabytes"
  End If
Next