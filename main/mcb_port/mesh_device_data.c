#include "mesh_device_data.h"

#define STD_LOCAL_LOG_LEVEL STD_LOG_DEBUG
device_info_raw_t g_device_info_raw;

device_info_raw_t *get_device_raw()
{
    return &g_device_info_raw;
}

void format_device_info(char *json)
{
    int temp;
    
    temp = g_device_info_raw.device_info.device_bool.sw_1;
    json_pack_object(json, "SW_1", &temp);

    temp = g_device_info_raw.device_info.device_bool.sw_2;
    json_pack_object(json, "SW_2", &temp);

    temp = g_device_info_raw.device_info.device_bool.sw_3;
    json_pack_object(json, "SW_3", &temp);

    temp = g_device_info_raw.device_info.device_bool.sw_4;
    json_pack_object(json, "SW_4", &temp);

    json_pack_object(json, "ImgProgress", &g_device_info_raw.device_info.ImgProgress);
}

void device_data_init()
{
    memcpy(g_device_info_raw.mac, std_wifi_get_stamac(), 6);
    g_device_info_raw.raw_len = sizeof(device_info_t);
}