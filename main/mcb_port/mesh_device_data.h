#ifndef MESH_DEVICE_DATA_H
#define MESH_DEVICE_DATA_H

#include "std_port_common.h"
#include "std_wifi.h"

typedef struct device_bool_t{
    uint8_t sw_1:1;
    uint8_t sw_2:1;
    uint8_t sw_3:1;
    uint8_t sw_4:1;
}__attribute__((__packed__)) device_bool_t;

typedef struct device_info_t{
    uint8_t ImgProgress;
    device_bool_t device_bool;
}__attribute__((__packed__)) device_info_t;

typedef struct device_info_raw_t{
    uint8_t mac[6];
    uint8_t raw_len;
    device_info_t device_info;
}__attribute__((__packed__)) device_info_raw_t;

device_info_raw_t *get_device_raw();
void device_data_init();
void format_device_info(char *json);
#endif