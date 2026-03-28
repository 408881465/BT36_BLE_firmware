/**
 * DX-BT36 UART 数据转发
 *
 * 功能:
 * - 串口参数: 9600bps/8/n/1 (默认, 可配置)
 * - AT 指令模式: 未连接时响应 AT 命令
 * - 透传模式: 连接后数据直接转发
 */

#include "da1458c_modules.h"
#include "user_ble_service.h"

/* UART 缓冲区 */
static uint8_t uart_rx_buf[256];
static uint8_t uart_tx_buf[256];
static volatile uint16_t uart_rx_len = 0;

/* UART 配置 */
#define DEFAULT_BAUDRATE   9600

/* AT 命令检测 */
static const char *at_commands[] = {
    "AT",
    "AT+NAME",
    "AT+BAUD",
    "AT+VERSION",
    "AT+LADDR",
    "AT+UUID",
    "AT+CHAR",
    "AT+RESET",
    "AT+DISC",
    "AT+DEFAULT"
};

/**
 * UART 初始化
 */
void user_uart_init(void)
{
    // 配置 UART 引脚
    // UART_TX: P0.00 (或根据实际电路)
    // UART_RX: P0.01

    // 配置 UART 参数:
    // - 波特率: 9600 (默认)
    // - 数据位: 8
    // - 停止位: 1
    // - 校验位: 无

    // 开启 UART 中断
}

/**
 * 发送数据到 UART
 */
void user_uart_send(const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0) return;

    for (uint16_t i = 0; i < len; i++) {
        // uart_putchar(data[i]);
    }
}

/**
 * 打印字符串到 UART
 */
void user_uart_print(const char *str)
{
    if (str == NULL) return;

    while (*str) {
        // uart_putchar(*str++);
    }
}

/**
 * UART 接收中断处理
 */
void user_uart_rx_handler(uint8_t byte)
{
    if (uart_rx_len < sizeof(uart_rx_buf)) {
        uart_rx_buf[uart_rx_len++] = byte;
    }
}

/**
 * 处理 UART 数据
 *
 * 未连接时: 解析 AT 命令
 * 已连接时: 透传到 BLE
 */
void user_uart_process(void)
{
    if (uart_rx_len == 0) return;

    // 检查连接状态
    if (user_ble_service_is_connected()) {
        // 连接状态: 透传数据到 BLE
        user_ble_service_send_to_phone(uart_rx_buf, uart_rx_len);
    } else {
        // 未连接: 解析 AT 命令
        user_uart_process_at_cmd(uart_rx_buf, uart_rx_len);
    }

    // 清空缓冲区
    uart_rx_len = 0;
}

/**
 * 处理 AT 命令
 */
void user_uart_process_at_cmd(const uint8_t *cmd, uint16_t len)
{
    // 查找匹配的 AT 命令
    for (int i = 0; i < sizeof(at_commands)/sizeof(at_commands[0]); i++) {
        uint8_t cmd_len = strlen(at_commands[i]);
        if (len >= cmd_len && memcmp(cmd, at_commands[i], cmd_len) == 0) {
            // 找到匹配的命令
            user_uart_execute_at_cmd(cmd, len);
            return;
        }
    }

    // 未识别的命令
    user_uart_print("\r\nERROR=1\r\n");
}

/**
 * 执行 AT 命令
 */
void user_uart_execute_at_cmd(const uint8_t *cmd, uint16_t len)
{
    // 复制命令到字符串
    char cmd_str[64] = {0};
    if (len < sizeof(cmd_str)) {
        memcpy(cmd_str, cmd, len);
    }

    // 简单命令解析
    if (memcmp(cmd, "AT", 2) == 0) {
        if (len == 2) {
            user_uart_print("\r\nOK\r\n");
            return;
        }
    }

    if (memcmp(cmd, "AT+VERSION", 10) == 0) {
        user_uart_print("\r\n+VERSION=1.0.0\r\nOK\r\n");
        return;
    }

    if (memcmp(cmd, "AT+LADDR", 8) == 0) {
        user_uart_print("\r\n+LADDR=AABBCC112233\r\nOK\r\n");
        return;
    }

    // 未知命令
    user_uart_print("\r\nERROR=1\r\n");
}

/**
 * 获取 UART 波特率
 */
uint32_t user_uart_get_baudrate(void)
{
    return DEFAULT_BAUDRATE;
}
