#ifndef OPERATION_H
#define OPERATION_H

#include "std_common.h"

void set_inroom_temp(int num_1, int num_2);
void set_time(int time1, int time2, int time3, int time4);
void set_set_temp(int a, int b);
void set_ad_num(int num);

extern int first_num, second_num;
extern int time_1, time_2, time_3, time_4;
extern int set_temp_1, set_temp_2;
extern int set_ad;
#endif