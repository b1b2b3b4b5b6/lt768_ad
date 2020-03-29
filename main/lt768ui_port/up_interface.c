#include "up_interface.h"

#define STD_LOCAL_LOG_LEVEL STD_LOG_INFO
#define QUEUE_SIZE 5
static xQueueHandle g_queue;

void up_interface_init()
{
    g_queue = xQueueCreate(5, sizeof(up_event_t *));
}

up_event_t *wait_up_event(int time_ms)
{
    up_event_t *p = NULL;
    xQueueReceive(g_queue, &p, time_ms / portTICK_PERIOD_MS);
    return p;
}

void free_up_event(up_event_t *event)
{
    if(event == NULL)
        return;

    STD_FREE(event);
}

void print_up_event(up_event_t *event)
{
    printf("************up_event**************\r\n");
    printf("type[%d] value[%p]\r\n", event->type, event->value);
}
void checkbox_cb_1(bool status)
{
    STD_LOGD("checkbos_cb_1 trigger[%d]", status);
    up_event_t *p = STD_CALLOC(1, sizeof(up_event_t));
    p->type = UP_EVENT_CHECKBOX_1;
    p->value = (void *)status;
    STD_ASSERT(xQueueSend(g_queue, &p, portMAX_DELAY) == pdTRUE);
}

void checkbox_cb_2(bool status)
{
    STD_LOGD("checkbos_cb_2 trigger[%d]", status);
    up_event_t *p = STD_CALLOC(1, sizeof(up_event_t));
    p->type = UP_EVENT_CHECKBOX_2;
    p->value = (void *)status;
    STD_ASSERT(xQueueSend(g_queue, &p, portMAX_DELAY) == pdTRUE);
}

void checkbox_cb_3(bool status)
{
    STD_LOGD("checkbos_cb_3 trigger[%d]", status);
    up_event_t *p = STD_CALLOC(1, sizeof(up_event_t));
    p->type = UP_EVENT_CHECKBOX_3;
    p->value = (void *)status;
    STD_ASSERT(xQueueSend(g_queue, &p, portMAX_DELAY) == pdTRUE);
}

void checkbox_cb_4(bool status)
{
    STD_LOGD("checkbos_cb_4 trigger[%d]", status);
    up_event_t *p = STD_CALLOC(1, sizeof(up_event_t));
    p->type = UP_EVENT_CHECKBOX_4;
    p->value = (void *)status;
    STD_ASSERT(xQueueSend(g_queue, &p, portMAX_DELAY) == pdTRUE);
}

