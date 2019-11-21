echo "Set environment"
set EXT_DIR=%cd%
set BUILD_DIR=%EXT_DIR%\build-windows
set VCVARSALL="C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat"

if not exist "%BUILD_DIR%" (
	mkdir "%BUILD_DIR%"
)

cd %BUILD_DIR%

if "%VSCMD_VER%"=="" (
	set MAKE=
	set CC=
	set CXX=
	call %VCVARSALL% x86 8.1
)

:: Getting sourcemod

echo "Download sourcemod"
if not exist "sourcemod-%BRANCH%" (
	git clone https://github.com/alliedmodders/sourcemod --recursive --branch %BRANCH% --single-branch sourcemod-%BRANCH%
)

cd sourcemod-%BRANCH%
set SOURCEMOD=%cd%

echo "Download metamod"
if not exist "metamod-source-master" (
	git clone https://github.com/alliedmodders/metamod-source.git --recursive --branch master --single-branch metamod-source-master
)

cd metamod-source-master
set METAMOD=%cd%

echo "Download hl2sdk-csgo"
if not exist "hl2sdk-csgo" (
	git clone https://github.com/alliedmodders/hl2sdk.git --recursive  --branch csgo --single-branch hl2sdk-csgo
)

cd hl2sdk-csgo
set HL2SDK-CSGO=%cd%


cd %BUILD_DIR%

:: Start build

echo "Build"
cd %EXT_DIR%
msbuild msvc15/ArmsFix.sln /p:Platform="win32"