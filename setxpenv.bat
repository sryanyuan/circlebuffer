@rem support xp
@set WindowsSdkDir_71A=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\
@set WindowsSDK_ExecutablePath_x86=C:\Program Files (x86)\Microsoft Kits\8.0\bin\x86;C:\Program Files (x86)\Mircorsoft SDKs\Windows\v8.0A\bin\NETFX 4.0 Tools
@set FrameworkSDKDir_71A=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\

@set PATH=%VCInstallDir%bin;%WindowsSdkDir_71A%bin;%WindowsSDK_ExecutablePath_x86%;%VSInstallDir%Common7\Tools\bin;$(VSInstallDir)Common7\tools;%VSInstallDir%Common7\ide;%ProgramFiles%\HTML Help Workshop;%MSBuildToolsPath32%;%VSInstallDir%;%SystemRoot%\SysWow64;%FxCopDir%;%PATH%;
@set INCLUDE=%VCInstallDir%include;%VCInstallDir%atlmfc\include;%WindowsSdkDir_71A%include;%FrameworkSDKDir_71A%include
@set LIB=%VCInstallDir%lib;%VCInstallDir%atlmfc\lib;%WindowsSdkDir_71A%lib