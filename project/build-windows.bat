@echo off
setlocal

set GCC_TOOLCHAIN_PATH=%1
set DIALOG_SDK_PATH=%2

if "%GCC_TOOLCHAIN_PATH%"=="" (
    echo Usage: build-windows.bat ^<gcc_path^> ^<sdk_path^>
    echo Example: build-windows.bat C:\gcc-arm-none-eabi C:\dialog-sdk
    exit /b 1
)

if "%DIALOG_SDK_PATH%"=="" (
    echo Error: DIALOG_SDK_PATH not set
    exit /b 1
)

echo Building DA14535 firmware...
echo GCC: %GCC_TOOLCHAIN_PATH%
echo SDK: %DIALOG_SDK_PATH%

mkdir build 2>nul

cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../gcc/arm-none-eabi.cmake -DGCC_TOOLCHAIN_PATH=%GCC_TOOLCHAIN_PATH% -DDIALOG_SDK_PATH=%DIALOG_SDK_PATH% -G "MinGW Makefiles" ..
if errorlevel 1 (
    echo CMake configuration failed!
    exit /b 1
)

cmake --build . -- -j4
if errorlevel 1 (
    echo Build failed!
    exit /b 1
)

echo.
echo Build completed successfully!
echo Firmware files:
if exist DA14535_BLE.hex echo   - DA14535_BLE.hex
if exist DA14535_BLE.bin echo   - DA14535_BLE.bin

cd ..
