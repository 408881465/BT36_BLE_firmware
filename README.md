# DX-BT36 蓝牙模块固件项目

基于 Dialog DA14535 芯片的 BLE 5.3 固件，支持自定义 UUID、广播包和 UART 透传。

## 获取 SDK

**重要**：Dialog DA14535 SDK 是专有软件，需要从 Renesas 官网获取。

### 获取步骤：

1. 访问 [Renesas Dialog 官网](https://www.renesas.com/us/en/products/wireless-connectivity/fi/ble-bluetooth-low-energy)
2. 注册账户
3. 下载 **SmartSnippets SDK** 或 **SDK6**
4. 将 SDK 放入 `SDK/DA14535_SDK/` 目录

### SDK 目录结构要求：

```
SDK/
└── DA14535_SDK/
    └── (解压后的 SDK 内容)
```

## 项目结构

```
BT36_firmware/
├── .github/workflows/build.yml    # GitHub Actions 编译
├── SDK/                          # Dialog SDK (需自行下载)
├── project/
│   ├── user_app/
│   │   ├── main.c                # 主程序入口
│   │   ├── user_ble_service.c   # 自定义 BLE 服务
│   │   ├── user_adv.c           # 自定义广播数据
│   │   └── user_uart.c          # UART 数据转发
│   ├── custom_profile.c         # GATT Profile 定义
│   └── Makefile                 # 编译配置
└── README.md
```

## 编译

推送代码到 GitHub 后，Actions 将自动编译，产出的 `.hex` 和 `.bin` 文件可在 Artifacts 中下载。

本地编译：

```bash
cd project
make clean
make
```

## 烧录

使用 CMSIS-DAP 或 J-Link 调试器连接模块 SWD 接口烧录。

## BLE 服务定义

| Characteristic | UUID | 属性 | 用途 |
|---------------|------|------|------|
| TX | 0xFFE1 | Notify | 模块→手机 |
| RX | 0xFFE2 | Write | 手机→模块 |
| CMD | 0xFFE3 | Write | AT 指令通道 |

## 联系方式

深圳大夏龙雀科技有限公司
- 邮箱：sales@szdx-smart.com
- 电话：0755-2997 8125
