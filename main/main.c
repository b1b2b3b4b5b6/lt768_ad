#include "lt768ui.h"
#include "business.h"
#include "decode_image.h"
#include "operation.h"
#include "std_decode.h"
#include "mcb.h"

#define STD_LOCAL_LOG_LEVEL STD_LOG_DEBUG
#define COM_RESET 15

/**
 * @brief  common reset pin
 * 
 * @note use this function will reset all device, include tft, lt768, i2c device. define for temporary
 *
 */
void com_reset()
{
	gpio_set_direction(COM_RESET, GPIO_MODE_OUTPUT);
	gpio_set_level(COM_RESET, 0);
	vTaskDelay(100 / portTICK_PERIOD_MS);               
	gpio_set_level(COM_RESET, 1);
	vTaskDelay(100 / portTICK_PERIOD_MS);
}

void app_main()
{
    std_nvs_init();
    std_rdebug_init(false);
    std_reboot_init();
    std_ota_init(NULL, NULL);
    std_wifi_init();
    
    interface_config_t cfg;
    cfg.type = INTERFACE_TCP;
    std_nvs_save(INTERFACE_KEY, &cfg, sizeof(interface_config_t));

    network_info_t info;
    memset(&info, 0, sizeof(network_info_t));
    strcpy(info.ssid, "MESH_ROUTER");
    strcpy(info.passwd, "12345678");
    strcpy(info.mesh_id, "11:11:11:11:11:11");
    std_nvs_save(KEY_NETWORK, &info, sizeof(network_info_t));
    mcb_init(MESH_AUTO);

    com_reset();
	lt768ui_init(); // lt768 ui init, call before bussiness
	business_init();

    for(;;)
    {
        vTaskDelay(4000 / portTICK_PERIOD_MS);
        PORT_HEAP();
    }
}


