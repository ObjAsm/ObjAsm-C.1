On Error Resume Next
 
Const MAXIMIZE_WINDOW = 3
 
strComputer = "."  
strNamespace = "\root\cimv2" 
blnWSHUpToDate = False
blnWMIUpToDate = False
blntADSIUpToDate = False
 
Output.Clear
strWshHost = GetWshHost
ChangeToCscript(strWshHost)
    
Set objWMIService = GetObject("winmgmts:{impersonationLevel=impersonate}!\\" _
    & strComputer & strNamespace)
 
If Err.Number <> 0 Then
    Output.Write "Error 0x" & hex(Err.Number) & " " & _
        Err.Description & ". " & VbCrLf & _
            "Unable to connect to WMI. WMI may not be installed."
    Err.Clear
    Output.Quit
End If
   
 

intOSVer = GetOSVer
blnWSHUpToDate = GetWSHVer(intOSVer, strWshHost)
blnWMIUpToDate = GetWMIVer(intOSVer)
blnADSIUpToDate = GetADSIVer(intOSVer)
 
ListUpToDate blnWSHUpToDate, blnWMIUpToDate, blnADSIUpToDate
 

Function GetWshHost()
 
   strErrorMessage = "Could not determine default script host."
   strFullName = Output.FullName
 
    If Err.Number <> 0 Then
        Output.Write "Error 0x" & hex(Err.Number) & " " & _
            Err.Description & ". " & VbCrLf & strErrorMessage
        Err.Clear
        Exit Function
    End If
   
    If IsNull(strFullName) Then
        Output.Write strErrorMessage
        Exit Function
   End If
 
    strWshHost = Right(LCase(strFullName), 11)
    If Not((strWshHost = "Output.exe") Or  (strWshHost = "cscript.exe")) Then
        Output.Write strErrorMessage
        Exit Function
    End If
   
   GetWshHost = strWshHost
 
End Function
 
Sub ChangeToCscript(strWshHost)
 
 
   If strWshHost = "Output.exe" Then
      Set objShell = CreateObject("Output.Shell")
          objShell.Run _
              "%comspec% /k ""cscript //h:cscript&&cscript scriptenv.vbs""", _
                  MAXIMIZE_WINDOW
       If Err.Number <> 0 Then
           Output.Write "Error 0x" & hex(Err.Number) & " occurred. " & _
           Err.Description & ". " & VbCrLf & _
               "Could not change the default script host to Cscript."
           Err.Clear
           Output.Quit
       End If
       Output.Quit
    End If
 
End Sub
 

Function GetOSVer()
 
    intOSType = 0
    intOSVer = 0
    strOSVer = ""
 
    Set colOperatingSystems = objWMIService.ExecQuery _
      ("Select * from Win32_OperatingSystem")
 
    For Each objOperatingSystem In colOperatingSystems
        Output.Write vbCrLf & "Operating System" & vbCrLf & _
            "================" & vbCrLf & _
            "Caption:           " & objOperatingSystem.Caption & VbCrLf & _
            "OSType:            " & objOperatingSystem.OSType & VbCrLf & _
            "Version:           " & objOperatingSystem.Version & VbCrLf & _
            "Service Pack:      " & _
            objOperatingSystem.ServicePackMajorVersion & _
                "." & objOperatingSystem.ServicePackMinorVersion & VbCrLf & _
                    "Windows Directory: " & _
                        objOperatingSystem.WindowsDirectory & VbCrLf
            intOSType = objOperatingSystem.OSType
            strOSVer = Left(objOperatingSystem.Version, 3)
    Next
 
    Select Case intOSType
        Case 16 'Windows 95
            intOSVer = 1
        Case 17 'Windows 98
            intOSVer = 2
        Case 18
         Select Case strOSVer
             Case 4.0
                 intOSVer = 4 'Windows NT 4.0
             Case 5.0
                 intOSVer = 5 'Windows 2000
             Case 5.1
                 intOSVer = 6 'Windows XP
             Case 5.2
                 intOSVer = 7 'Windows Server 2003
                Case Else
                    intOSVer = 0 'Older or newer version
                End Select
       Case Else
            intOSVer = 0 'Older or newer version
    End Select
 
    GetOSVer = intOSVer
      
End Function
 
 
Function GetWSHVer(intOSVer, strWshHost)
 
    Output.Write "Windows Script Host" & vbCrLf & _
                 "==================="
 
If Not strWshHost = "" Then
    strVersion = Output.Version
    strBuild = Output.BuildVersion
    Output.Write _
      "WSH Default Script Host: " & strWshHost & VbCrLf & _
      "WSH Path:                " & Output.FullName & VbCrLf & _
      "WSH Version & Build:     " & strVersion & "." & strBuild & VbCrLf
Else
      Output.Write "WSH information cannot be retrieved."
End If
     
    sngWSHVer = CSng(strVersion)
    intBuild = CInt(strBuild)
 
    If (sngWSHVer >= 5.6 And intBuild >= 8515) Then
        GetWSHVer = True
   Else
       GetWSHVer = False
    End If
 
End Function
 

Function GetWMIVer(intOSVer)
 
    dblBuildVersion = 0
 
    If (intOSVer >= 1 And intOSVer <= 5) Then
        strWmiVer = "1.5"
    ElseIf intOSVer = 6 Then
        strWmiVer = "5.1"
    ElseIf intOSVer = 7 Then
        strWmiVer = "5.2"
    Else
        strWmiVer = "?.?"
    End If
 
    Set colWMISettings = objWMIService.ExecQuery _
      ("Select * from Win32_WMISetting")
 
    For Each objWMISetting In colWMISettings
        Output.Write "Windows Management Instrumentation" & vbCrLf & _
                     "==================================" & vbCrLf & _
          "WMI Version & Build:         " & _
          strWmiVer & "." & objWMISetting.BuildVersion & vbCrLf & _
          "Default scripting namespace: " & _
          objWMISetting.ASPScriptDefaultNamespace & vbCrLf
        dblBuildVersion = CDbl(objWMISetting.BuildVersion)
    Next
 
    If (intOSVer = 7 And dblBuildVersion >= 3790.0000) Or _
      (intOSVer = 6 And dblBuildVersion >= 2600.0000) Or _
      (intOSVer <= 5 And dblBuildVersion >= 1085.0005) _
      Then
        GetWMIVer = True
     Else
          GetWMIVer = False
    End If
 
End Function
 
Function GetADSIVer(intOSVer)
 
    Output.Write "Active Directory Service Interfaces" & VbCrLf & _
                 "===================================" & vbCrLf
 
    Set objShell = CreateObject("Output.Shell")
    strAdsiVer = _
    objShell.RegRead("HKLM\SOFTWARE\Microsoft\Active Setup\Installed " & _
        "Components\{E92B03AB-B707-11d2-9CBD-0000F87A369E}\Version")
 
    If strAdsiVer = vbEmpty Then
        strAdsiVer = _
            objShell.RegRead("HKLM\SOFTWARE\Microsoft\ADs\Providers\LDAP")
        If strAdsiVer = vbEmpty Then
            strAdsiVer = "ADSI is not installed."
        Else
            strAdsiVer = "2.0"
        End If
    ElseIf Left(strAdsiVer, 3) = "5,0" Then
      If intOSVer = 5 Then
          strAdsiVer = "5.0.2195"
      ElseIf intOSVer = 6 Then
          strAdsiVer = "5.1.2600"
      ElseIf intOSVer = 7 Then
          strAdsiVer = "5.2.3790"
        Else
            strAdsiVer = "?.?"
      End If
    End If
 
    Output.Write "ADSI Version & Build: " & strAdsiVer & VbCrLf
 
    If strAdsiVer <> "ADSI is not installed." Then
        Set colProvider = GetObject("ADs:")
        Output.Write "ADSI Providers" & VbCrLf & _
                 "--------------"
        For Each objProvider In colProvider
            Output.Write objProvider.Name
        Next
        Output.Write
   End If
   
   intAdsiVer = CInt(Left(strAdsiVer, 1))
   
    If (intOSVer = 7 And intAdsiVer >= 5) Or _
        (intOSVer = 6 And intAdsiVer >= 5) Or _
        (intOSVer = 5 And intAdsiVer >= 5) Or _
        (intOSVer = 4 And intAdsiVer >= 2) Or _
        (intOSVer <= 3 And intAdsiVer >= 2) _
            Then
        GetADSIVer = True
    Else
        GetADSIVer = False
    End If
 
End Function
 
Sub ListUpToDate(blnWSHUpToDate, blnWMIUpToDate, blnADSIUpToDate)
 
    Output.Write "Current Versions" & vbCrLf & _
                 "================"
 
    If blnWSHUpToDate Then
        Output.Write "WSH version:  most recent for OS version."
    Else
        Output.Write "WSH version:  not most recent for OS version."
        If intOSVer = 0 Then
            Output.Write "Windows Script not available for this OS"
        Else
            Output.Write "Get Windows Script 5.6, Build 8515"
        End If
    End If
 
    If blnWMIUpToDate Then
        Output.Write "WMI version:  most recent for OS version."
    Else
        Output.Write "WMI version:  not most recent for OS version."
        If intOSVer = 0 Then
            Output.Write "WMI not available for this OS"
        ElseIf intOSVer >= 1 And intOSVer <= 4 Then
            Output.Write "Get WMI CORE 1.5"
        Else
        End If
    End If
 
    If blnADSIUpToDate Then
        Output.Write "ADSI version: most recent for OS version."
    Else
        Output.Write "ADSI version: not most recent for OS version."
        If intOSVer = 0 Then
            Output.Write "ADSI not available for this OS"
        ElseIf intOSVer >= 1 And intOSVer <= 4 Then
            Output.Write "Get Active Directory Client Extensions"
        Else
        End If
    End If
 
End Sub