#!/bin/bash

set -e

GCC_TOOLCHAIN_PATH=$1
DIALOG_SDK_PATH=$2

if [ -z "$GCC_TOOLCHAIN_PATH" ] || [ -z "$DIALOG_SDK_PATH" ]; then
    echo "Usage: build-linux.sh <gcc_path> <sdk_path>"
    echo "Example: build-linux.sh ~/gcc-arm-none-eabi ~/dialog-sdk"
    exit 1
fi

echo "Building DA14535 firmware..."
echo "GCC: $GCC_TOOLCHAIN_PATH"
echo "SDK: $DIALOG_SDK_PATH"

mkdir -p build
cd build

cmake -DCMAKE_TOOLCHAIN_FILE=../gcc/arm-none-eabi.cmake \
      -DGCC_TOOLCHAIN_PATH=$GCC_TOOLCHAIN_PATH \
      -DDIALOG_SDK_PATH=$DIALOG_SDK_PATH \
      ..

cmake --build . -j$(nproc)

echo ""
echo "Build completed successfully!"
echo "Firmware files:"
[ -f DA14535_BLE.hex ] && echo "  - DA14535_BLE.hex"
[ -f DA14535_BLE.bin ] && echo "  - DA14535_BLE.bin"

cd ..
