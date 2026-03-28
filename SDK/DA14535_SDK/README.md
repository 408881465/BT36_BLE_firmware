# Dialog DA14535 SDK

此目录需要放置 Dialog DA14535 SDK。

## 获取方式

Dialog DA14535 SDK 是 **专有软件**，需要从 Renesas 官网获取：

1. 访问: https://www.renesas.com/us/en/products/wireless-connectivity/fi/ble-bluetooth-low-energy
2. 注册账户
3. 下载 **SmartSnippets SDK** 或 **SDK6** (针对 DA14535/DA14531)
4. 解压到本目录

## 目录结构

解压后应包含:
```
DA14535_SDK/
├── include/          # 头文件
├── sdk/             # SDK 核心
│   ├── modules/     # 外设驱动
│   └── stack/       # BLE 协议栈
├── libs/            # 库文件
└── tools/           # 工具链
```

## 注意

- SDK 需要授权协议
- 部分组件可能需要单独下载
- 确保下载与 DA14535 芯片对应的 SDK 版本
