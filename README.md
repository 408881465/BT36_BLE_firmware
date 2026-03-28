# DX-BT36 BLE Module Firmware

基于 Dialog DA14535 芯片的 BLE 5.3 固件项目，支持云端编译。

## 功能特性

- **自定义 BLE GATT 服务**
  - Service UUID: 0xFFE0
  - TX Characteristic (Notify): 0xFFE1 - 模块→手机数据通道
  - RX Characteristic (Write): 0xFFE2 - 手机→模块数据通道
  - CMD Characteristic (Write): 0xFFE3 - AT指令通道

- **UART 透传模式**
- **AT 指令保留**
- **CMake + GCC 云端编译**

## 目录结构

```
BT36_firmware/
├── .github/workflows/
│   └── build.yml           # GitHub Actions 云端编译
├── SDK/                    # Dialog DA14535 SDK (需自行下载)
│   └── DA14535_SDK/
│       └── DA145xx_SDK/
│           └── 6.0.24.1464/
├── project/
│   ├── CMakeLists.txt      # CMake 构建配置
│   ├── build-windows.bat   # Windows 构建脚本
│   ├── build-linux.sh      # Linux 构建脚本
│   ├── gcc/                # GCC 工具链配置
│   │   ├── arm-none-eabi.cmake
│   │   └── dialog-sdk.cmake
│   ├── src/                # 源代码
│   │   ├── ble_handlers.c
│   │   ├── user_app.c
│   │   ├── user_custs1_def.c  # 自定义 GATT 服务
│   │   └── custom_profile/
│   ├── include/            # 头文件
│   └── components/config/  # 配置文件
└── README.md
```

## SDK 获取

1. 下载 **SDK6.0.24.1464 for DA1453x, DA14585/6**
   - 访问: https://www.renesas.com/us/en/products/wireless-connectivity/bluetooth-low-energy
   - 搜索: DA14535 或 SDK6

2. 解压 SDK 到 `SDK/DA14535_SDK/` 目录

## 本地编译

### Windows
```cmd
project\build-windows.bat C:\gcc-arm-none-eabi C:\path\to\SDK\DA145xx_SDK\6.0.24.1464
```

### Linux
```bash
./project/build-linux.sh ~/gcc-arm-none-eabi ~/path/to/SDK/DA145xx_SDK/6.0.24.1464
```

## 云端编译

推送到 GitHub 后，Actions 将自动编译，产出的固件可在 Artifacts 中下载：
- `DA14535_BLE.hex` - Intel HEX 格式
- `DA14535_BLE.bin` - 二进制格式

## BLE 服务定义

| Characteristic | UUID | 属性 | 用途 |
|---------------|------|------|------|
| TX | 0xFFE1 | Notify | 模块→手机 |
| RX | 0xFFE2 | Write | 手机→模块 |
| CMD | 0xFFE3 | Write | AT 指令 |

## 烧录

使用 CMSIS-DAP 或 J-Link 调试器连接模块 SWD 接口烧录固件。

## 参考

- 芯片: Dialog DA14535
- 蓝牙: BLE 5.3
- 文档: DX-BT36 蓝牙模块_UART_应用指导.pdf
