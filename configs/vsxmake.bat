@echo off
setlocal

IF NOT EXIST "xmake.lua" (
    cd ..
)

xmake project -k vsxmake -y

SET "ProcessName=devenv.exe"

tasklist /FI "IMAGENAME eq %ProcessName%" | find /I "%ProcessName%" >nul

IF %ERRORLEVEL%==0 (
    echo Visual Studio is running. Please close and reopen it to reload the project.
) ELSE (
    echo Visual Studio is closed. Starting solution...
    start vsxmake2022/Szar.sln
)

endlocal
