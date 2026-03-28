/**
 * DX-BT36 蓝牙模块固件
 * 主程序入口
 *
 * 功能：
 * - 自定义 BLE GATT 服务
 * - UART 透传数据传输
 * - AT 指令保留
 */

#include "arch_system.h"
#include "user_ble_service.h"
#include "user_uart.h"
#include "user_adv.h"

/**
 * 应用初始化
 */
void app_init(void)
{
    // 初始化 UART
    user_uart_init();

    // 初始化 BLE 服务
    user_ble_service_init();

    // 配置自定义广播数据
    user_adv_init();

    // 输出启动信息
    user_uart_print("\r\nDX-BT36 Firmware V1.0\r\n");
    user_uart_print("BLE Custom Service Ready\r\n");
}

/**
 * 主循环
 */
void app_main_loop(void)
{
    // 处理 UART 数据转发到 BLE
    user_uart_process();

    // 处理 BLE 数据转发到 UART
    user_ble_service_process();
}

/**
 * 连接状态回调
 */
void on_ble_connect(void)
{
    user_uart_print("\r\n+CONNECTED\r\n");
}

/**
 * 断开连接回调
 */
void on_ble_disconnect(void)
{
    user_uart_print("\r\n+DISCONNECTED\r\n");
}
