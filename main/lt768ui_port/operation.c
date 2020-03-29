#include "operation.h"

#define STD_LOCAL_LOG_LEVEL STD_LOG_DEBUG

int first_num, second_num;
void set_inroom_temp(int num_1, int num_2)
{
	first_num = num_1;
	second_num = num_2;
}

int time_1, time_2, time_3, time_4;

void set_time(int time1, int time2, int time3, int time4)
{
	time_1 = time1;
	time_2 = time2;
	time_3 = time3;
	time_4 = time4;
}

int set_temp_1, set_temp_2;

void set_set_temp(int a, int b)
{
	set_temp_1 = a;
	set_temp_2 = b;
}

int set_ad = 0;
void set_ad_num(int num)
{
	STD_ASSERT(num < 9);
	set_ad = num;
}
			