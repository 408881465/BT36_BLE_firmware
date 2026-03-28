/**
 * DX-BT36 自定义 BLE 服务
 *
 * 自定义 UUID:
 * - Service UUID:  0xFFE0 (可修改)
 * - TX Characteristic: 0xFFE1 (Notify)
 * - RX Characteristic: 0xFFE2 (Write)
 * - CMD Characteristic: 0xFFE3 (Write)
 */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "user_uart.h"

/* 自定义 Service UUID */
#define CUSTOM_SERVICE_UUID        0xFFE0
#define CUSTOM_CHAR_TX_UUID        0xFFE1
#define CUSTOM_CHAR_RX_UUID        0xFFE2
#define CUSTOM_CHAR_CMD_UUID       0xFFE3

/* BLE 收发缓冲区 */
static uint8_t ble_rx_buf[256];
static uint8_t ble_tx_buf[256];

/**
 * BLE 服务初始化
 */
void user_ble_service_init(void)
{
    // 创建自定义 GATT 服务
    // 设置 Service UUID: 0xFFE0
    // 添加 Characteristics:
    //   - TX (Notify): 0xFFE1
    //   - RX (Write): 0xFFE2
    //   - CMD (Write): 0xFFE3

    // 设置连接参数
    // - 连接间隔: 15ms (可调整)
    // - 从机延迟: 0
    // - 超时时间: 500ms

    // 启动广播
}

/**
 * 处理 BLE 接收数据 (从手机收到数据)
 */
void user_ble_service_on_rx(const uint8_t *data, uint16_t len)
{
    if (len == 0 || data == NULL) return;

    // 复制数据
    if (len < sizeof(ble_rx_buf)) {
        memcpy(ble_rx_buf, data, len);
    }

    // 判断数据类型: AT命令 or 透传数据
    if (len >= 2 && data[0] == 'A' && data[1] == 'T') {
        // AT 指令模式 - 通过 CMD 通道处理
        user_ble_service_handle_at_cmd(data, len);
    } else {
        // 透传数据 - 转发到 UART
        user_uart_send(data, len);
    }
}

/**
 * 处理 AT 命令 (通过 CMD 通道)
 */
void user_ble_service_handle_at_cmd(const uint8_t *cmd, uint16_t len)
{
    // 解析 AT 命令并响应
    // 响应格式: +CMD=<result>\r\nOK\r\n

    user_uart_print("\r\n");
    user_uart_send(cmd, len);
    user_uart_print("\r\nOK\r\n");
}

/**
 * BLE 数据处理 (发送数据到手机)
 */
void user_ble_service_process(void)
{
    // 检查是否有数据等待发送
}

/**
 * 发送数据到手机 (通过 Notify)
 */
void user_ble_service_send_to_phone(const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0) return;

    // 通过 0xFFE1 Notify 发送数据到手机
    // ble_gatt_notify(0xFFE1, data, len);
}

/**
 * 获取连接状态
 */
bool user_ble_service_is_connected(void)
{
    // 返回当前连接状态
    // return connection_status;
}
