/**
 * DX-BT36 自定义 GATT Profile
 *
 * 基于 Dialog DA14535 SDK 定义的 GATT 服务结构
 */

/* 标准 Bluetooth UUIDs */
#include "BLE_types.h"

/* 自定义 Service UUID */
#define CUSTOM_SERVICE_UUID           {0xE0, 0xFF}

/* 自定义 Characteristic UUIDs */
#define CUSTOM_CHAR_TX_UUID          {0xE1, 0xFF}   /* Notify */
#define CUSTOM_CHAR_RX_UUID          {0xE2, 0xFF}   /* Write */
#define CUSTOM_CHAR_CMD_UUID         {0xE3, 0xFF}   /* Write */

/**
 * GATT Service 定义
 */
static const gatt_service_t custom_service = {
    .uuid = CUSTOM_SERVICE_UUID,
    .num_attributes = 7,  /* 1 service + 3 characteristics * 2 (decl + value) */
    .attributes = {
        /* Characteristic TX (Notify) */
        {
            .uuid = CUSTOM_CHAR_TX_UUID,
            .properties = GATT_PROP_NOTIFY,
            .permissions = GATT_PERM_NONE,
            .max_size = 244
        },
        /* Characteristic RX (Write) */
        {
            .uuid = CUSTOM_CHAR_RX_UUID,
            .properties = GATT_PROP_WRITE,
            .permissions = GATT_PERM_WRITE,
            .max_size = 244
        },
        /* Characteristic CMD (Write) */
        {
            .uuid = CUSTOM_CHAR_CMD_UUID,
            .properties = GATT_PROP_WRITE,
            .permissions = GATT_PERM_WRITE,
            .max_size = 64
        }
    }
};

/**
 * 注册自定义服务到 GATT 数据库
 */
void custom_profile_register(void)
{
    // gatt_db_add_service(&custom_service);
}
