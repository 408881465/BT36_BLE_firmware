/**
 * DX-BT36 自定义广播数据
 *
 * 可自定义:
 * - 设备名称
 * - 厂商 ID
 * - 广播间隔
 */

#include "da1458c_modules.h"

/* 自定义厂商 ID (可修改) */
#define CUSTOM_COMPANY_ID      0xFFFF

/* 自定义广播数据 */
static const uint8_t custom_adv_data[] = {
    0x02, 0x01, 0x06,         // 通用发现标志
    0x03, 0xFF, 0x00, 0xFF,   // 厂商数据 (ID: 0xFF00)
    0x0B, 0x09, 'D', 'X', '-', 'B', 'T', '3', '6', '_', 'V', '1'  // 设备名称
};

/* 自定义扫描响应数据 */
static const uint8_t custom_scan_resp[] = {
    0x03, 0xFF, 0x00, 0xFF    // 扩展厂商数据
};

/* 设备名称 */
static char device_name[32] = "DX-BT36_V1";

/**
 * 初始化广播参数
 */
void user_adv_init(void)
{
    // 设置广播间隔: 546ms (默认)
    // 可调整为: 100ms~1024ms
    // uint16_t adv_interval = 546;

    // 设置发射功率: +4dB (默认)
    // 可调整: -19dB ~ +4dB

    // 配置广播数据
    // adv_data_set(custom_adv_data, sizeof(custom_adv_data));
    // scan_resp_set(custom_scan_resp, sizeof(custom_scan_resp));
}

/**
 * 设置设备名称
 */
void user_adv_set_device_name(const char *name)
{
    if (name == NULL) return;

    strncpy(device_name, name, sizeof(device_name) - 1);
    device_name[sizeof(device_name) - 1] = '\0';

    // 重新设置广播数据中的设备名称
    // 需要更新广播数据包
}

/**
 * 获取设备名称
 */
const char* user_adv_get_device_name(void)
{
    return device_name;
}

/**
 * 设置自定义厂商数据
 */
void user_adv_set_company_data(uint16_t company_id, const uint8_t *data, uint8_t len)
{
    // 更新广播数据中的厂商信息
    // 格式: 0x03, 0xFF, <company_id_low>, <company_id_high>, <data...>
}
