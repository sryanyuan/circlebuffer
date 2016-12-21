@rem Script to build LuaJIT with MSVC.
@rem Copyright (C) 2005-2015 Mike Pall. See Copyright Notice in luajit.h
@rem
@rem Either open a "Visual Studio .NET Command Prompt"
@rem (Note that the Express Edition does not contain an x64 compiler)
@rem -or-
@rem Open a "Windows SDK Command Shell" and set the compiler environment:
@rem     setenv /release /x86
@rem   -or-
@rem     setenv /release /x64
@rem
@rem Then cd to this directory and run this script.

@if not defined INCLUDE goto :FAIL

@rem support xp
@set WindowsSdkDir_71A=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\
@set WindowsSDK_ExecutablePath_x86=C:\Program Files (x86)\Microsoft Kits\8.0\bin\x86;C:\Program Files (x86)\Mircorsoft SDKs\Windows\v8.0A\bin\NETFX 4.0 Tools
@set FrameworkSDKDir_71A=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\

@set PATH=%VCInstallDir%bin;%WindowsSdkDir_71A%bin;%WindowsSDK_ExecutablePath_x86%;%VSInstallDir%Common7\Tools\bin;$(VSInstallDir)Common7\tools;%VSInstallDir%Common7\ide;%ProgramFiles%\HTML Help Workshop;%MSBuildToolsPath32%;%VSInstallDir%;%SystemRoot%\SysWow64;%FxCopDir%;%PATH%;
@set INCLUDE=%VCInstallDir%include;%VCInstallDir%atlmfc\include;%WindowsSdkDir_71A%include;%FrameworkSDKDir_71A%include
@set LIB=%VCInstallDir%lib;%VCInstallDir%atlmfc\lib;%WindowsSdkDir_71A%lib

@setlocal
@set LJCOMPILE=cl /nologo /c /Od /W3 /D_CRT_SECURE_NO_DEPRECATE /D_USING_V110_SDK71_
@set LJLINK=link /nologo
@set LJMT=mt /nologo
@set LJLIB=lib /nologo /nodefaultlib
@set DASMDIR=..\dynasm
@set DASM=%DASMDIR%\dynasm.lua
@set LJDLLNAME=lua51.dll
@set LJLIBNAME=lua51.lib
@set ALL_LIB=lib_base.c lib_math.c lib_bit.c lib_string.c lib_table.c lib_io.c lib_os.c lib_package.c lib_debug.c lib_jit.c lib_ffi.c

%LJCOMPILE% host\minilua.c
@if errorlevel 1 goto :BAD
%LJLINK% /out:minilua.exe minilua.obj
@if errorlevel 1 goto :BAD
if exist minilua.exe.manifest^
  %LJMT% -manifest minilua.exe.manifest -outputresource:minilua.exe

@set DASMFLAGS=-D WIN -D JIT -D FFI -D P64
@set LJARCH=x64
@minilua
@if errorlevel 8 goto :X64
@set DASMFLAGS=-D WIN -D JIT -D FFI
@set LJARCH=x86
:X64
minilua %DASM% -LN %DASMFLAGS% -o host\buildvm_arch.h vm_x86.dasc
@if errorlevel 1 goto :BAD

%LJCOMPILE% /I "." /I %DASMDIR% host\buildvm*.c
@if errorlevel 1 goto :BAD
%LJLINK% /out:buildvm.exe buildvm*.obj
@if errorlevel 1 goto :BAD
if exist buildvm.exe.manifest^
  %LJMT% -manifest buildvm.exe.manifest -outputresource:buildvm.exe

buildvm -m peobj -o lj_vm.obj
@if errorlevel 1 goto :BAD
buildvm -m bcdef -o lj_bcdef.h %ALL_LIB%
@if errorlevel 1 goto :BAD
buildvm -m ffdef -o lj_ffdef.h %ALL_LIB%
@if errorlevel 1 goto :BAD
buildvm -m libdef -o lj_libdef.h %ALL_LIB%
@if errorlevel 1 goto :BAD
buildvm -m recdef -o lj_recdef.h %ALL_LIB%
@if errorlevel 1 goto :BAD
buildvm -m vmdef -o jit\vmdef.lua %ALL_LIB%
@if errorlevel 1 goto :BAD
buildvm -m folddef -o lj_folddef.h lj_opt_fold.c
@if errorlevel 1 goto :BAD

@set LJCOMPILE=%LJCOMPILE% /Zi
@set LJLINK=%LJLINK% /debug
@set LJDLLNAME=lua51vc12_d.dll
@set LJLIBNAME=lua51d.lib

%LJCOMPILE% /MDd /DLUA_BUILD_AS_DLL lj_*.c lib_*.c
@if errorlevel 1 goto :BAD
%LJLINK% /DLL /out:%LJDLLNAME% lj_*.obj lib_*.obj
@if errorlevel 1 goto :BAD
@rename lua51vc12_d.lib %LJLIBNAME%
@goto :MTDLL
:MTDLL
if exist %LJDLLNAME%.manifest^
  %LJMT% -manifest %LJDLLNAME%.manifest -outputresource:%LJDLLNAME%;2

%LJCOMPILE% luajit.c
@if errorlevel 1 goto :BAD
%LJLINK% /out:luajit.exe luajit.obj %LJLIBNAME%
@if errorlevel 1 goto :BAD
if exist luajit.exe.manifest^
  %LJMT% -manifest luajit.exe.manifest -outputresource:luajit.exe

@del *.obj *.manifest minilua.exe buildvm.exe
@echo.
@echo === Successfully built LuaJIT for Windows/%LJARCH% ===

@goto :END
:BAD
@echo.
@echo *******************************************************
@echo *** Build FAILED -- Please check the error messages ***
@echo *******************************************************
@goto :END
:FAIL
@echo You must open a "Visual Studio .NET Command Prompt" to run this script
:END
