#define FriendlyName "PdbReader"
#define VERSION_STRING "1.0.0.0"
#define MS_DIA_DLL_NAME "msdia100.dll"


[Setup]
AppName={#FriendlyName}
AppVersion={#VERSION_STRING}
AppCopyright="Copyleft kbridge@github 2015"
VersionInfoVersion={#VERSION_STRING}
DefaultDirName={pf}\{#FriendlyName}
DefaultGroupName={#FriendlyName}
UninstallDisplayIcon={app}\{#FriendlyName}.exe
Compression=lzma2
SolidCompression=yes
OutputDir=..\largelyignored\
OutputBaseFilename={#FriendlyName}-{#VERSION_STRING}-Setup
ChangesEnvironment=true


[Files]
Source: ".\bin\Release\{#FriendlyName}.exe"; DestDir: "{app}"; Flags: ReplaceSameVersion
Source: ".\{#MS_DIA_DLL_NAME}"; DestDir: "{app}"; Flags: ReplaceSameVersion


[Run]
Filename: "regsvr32"; Parameters: """{app}\{#MS_DIA_DLL_NAME}"""; StatusMsg: "Registering msdia..."; Tasks: RegisterMsDia


[Tasks]
Name: AddToPATH; Description: "Add to PATH"
Name: RegisterMsDia; Description: "Register bundled {#MS_DIA_DLL_NAME}"


[Code]
const
	ModPathName = 'AddToPATH';
	ModPathType = 'user';

function ModPathDir(): TArrayOfString;
begin
	setArrayLength(Result, 1)
	Result[0] := ExpandConstant('{app}\');
end;
#include "innosetup\modpath.iss"