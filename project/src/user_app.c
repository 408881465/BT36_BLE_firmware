#include <da1458x_config_basic.h>
#include <da1458x_config_advanced.h>
#include <user_config.h>
#include <rwip_config.h> // SW configuration

#include <user_app.h>
#include <custs1.h>
#include <custs1_task.h>
#include <gpio.h>
#include <user_custs1_def.h>
#include <user_periph_setup.h>
#include <ble_handlers.h>
#include <debug.h>

/*
This function is called as a callback by system arch, after peripheral init, and app init, but before giving away to the kernel and main loop
*/
void app_on_init(void)
{
    // To keep compatibility call default handler
    default_app_on_init();

    extern uint32_t __StackTop;
    extern uint32_t __HeapBase;
    extern uint32_t __HeapLimit;

    uint32_t initial_sp = (uint32_t)&__StackTop;
    uint32_t heap_base = (uint32_t)&__HeapBase;
    uint32_t heap_limit = (uint32_t)&__HeapLimit;

    printf("[DX-BT36] Firmware V1.0\r\n");
    printf("[DX-BT36] Compiled: %s %s\r\n", __DATE__, __TIME__);
    printf("[DX-BT36] Service UUID: 0xFFE0\r\n");
    printf("[DX-BT36] TX UUID: 0xFFE1 (Notify)\r\n");
    printf("[DX-BT36] RX UUID: 0xFFE2 (Write)\r\n");
    printf("[DX-BT36] CMD UUID: 0xFFE3 (Write)\r\n");
}

void app_resume_from_sleep(void)
{
}

arch_main_loop_callback_ret_t app_on_system_powered(void)
{
    wdg_reload(1);
    return KEEP_POWERED;
}

sleep_mode_t app_validate_sleep(sleep_mode_t sleep_mode)
{
    /* Block sleep. */
    return mode_active;
}

void app_going_to_sleep(sleep_mode_t sleep_mode)
{
}
