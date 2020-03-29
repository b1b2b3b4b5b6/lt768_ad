#include "up_service.h"

#define STD_LOCAL_LOG_LEVEL STD_LOG_DEBUG

#define TASK_SIZE 2048
#define TASK_PRI ESP_TASK_MAIN_PRIO

static void loop_task(void *argc)
{
	STD_LOGD("up service task create");
	device_info_raw_t *raw = get_device_raw();
	for(;;)
	{
		up_event_t *event = wait_up_event(3000);//recv up event
		if(event == NULL)
			continue;
		print_up_event(event); //print up event for debug
		switch(event->type)
		{
			case UP_EVENT_CHECKBOX_1:
				raw->device_info.device_bool.sw_1 = (int)event->value;
				break;

			case UP_EVENT_CHECKBOX_2:
				raw->device_info.device_bool.sw_2 = (int)event->value;
				break;

			case UP_EVENT_CHECKBOX_3:
				raw->device_info.device_bool.sw_3 = (int)event->value;
				break;

			case UP_EVENT_CHECKBOX_4:
				raw->device_info.device_bool.sw_4 = (int)event->value;
				break;
			default:
				STD_LOGE("undefine event type[%d]", event->type);
				STD_ASSERT(-1);
				break;
		}
		
		free_up_event(event); // free event
		mesh_report_brust();
	}
}

void up_service_init()
{
    xTaskCreate(loop_task, "up service task", TASK_SIZE, NULL, TASK_PRI, NULL);
	STD_LOGI("up service init success");
}
