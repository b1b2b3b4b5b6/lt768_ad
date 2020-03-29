#ifndef UP_INTERFACE_H
#define UP_INTERFACE_H

#include "std_port_common.h"

typedef enum {
    UP_EVENT_CHECKBOX_1,//checkbox 1 event
    UP_EVENT_CHECKBOX_2,//checkbox 2 event
    UP_EVENT_CHECKBOX_3,//checkbox 3 event
    UP_EVENT_CHECKBOX_4,//checkbox 4 event
}up_event_type_t;

typedef struct up_event_t{
    int type; //event type
    void *value; //event value, need to convert,for checkbox, this value need to be convert to bool
}up_event_t;

void up_interface_init();

/**
 * @brief  wait up event
 * 
 * @param  time_ms time to wait until retrun
 * 
 * @return
 *     - not NULL up event memery
 *     - NULL time out
 */
up_event_t *wait_up_event(int time_ms);

/**
 * @brief  free up event memery
 * 
 * @param  event free target up event
 * 
 */
void free_up_event(up_event_t *event);

/**
 * @brief  print up event with type and value(pointer format)
 * 
 * @param  event free target up event
 * 
 */
void print_up_event(up_event_t *event);

void checkbox_cb_1(bool status);
void checkbox_cb_2(bool status);
void checkbox_cb_3(bool status);
void checkbox_cb_4(bool status);

#endif