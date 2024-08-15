/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-15 14:38:39
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-15 15:27:33
 * @Description: This file stores functions that operate time.
 */

#ifndef _TIME_FUNCTION_H_
#define _TIME_FUNCTION_H_

#include<time.h>
#include"../../main/include/schedule_event.h"
#include"../../main/include/link_list.h"

time_t get_current_time(void);

time_t covert_schedule_to_time(ScheduleTime * st);

void alarm_event(Node * event);

void play_sound(void);

#endif // !_TIME_FUNCTION_H_