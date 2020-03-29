# lt768ui demo



| 依赖资源/组件 |
| ------------- |
| lt768ui     |
| ccom          |
| epcom         |
| mcb         |



| 配置              | 文件位置                       |
| ----------------- | ------------------------------ |
| lt768硬件资源配置 | /lt768ui_port/lt768ui_config.h |



### 示例

```c
#include "lt768ui.h"

/**
 * @brief  common reset pin
 * 
 * @note use this function will reset all device, include tft, lt768, i2c device. define for temporary
 *
 */
void com_reset()
{
	gpio_set_direction(15, GPIO_MODE_OUTPUT);
	gpio_set_level(15, 0);
	vTaskDelay(100 / portTICK_PERIOD_MS);
	gpio_set_level(15, 1);
	vTaskDelay(100 / portTICK_PERIOD_MS);
}

void app_main()
{
    esp_err_t ret;
    nvs_flash_init();

	com_reset();
	lt768ui_init(); // lt768 ui init, call before bussiness

	for(;;)
	{
		up_event_t *event = wait_up_event(4000);//recv up event
		if(event)
			print_up_event(event); //print up event for debug
		/*
		bussiness code
		*/

		free_up_event(event); // free event
		PORT_HEAP(); //print free heap for debug
	}
}

```



## 主要api

```c
/**
 * @brief  Initialization lt768 ui component
 * 
 */
void lt768ui_init();

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
 * @brief  print up event with type and value(pointer format) for dubug
 * 
 * @param  event free target up event
 * 
 */
void print_up_event(up_event_t *event);
```

