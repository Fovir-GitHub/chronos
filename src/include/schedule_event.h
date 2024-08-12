/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-12 12:39:16
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-12 17:54:20
 * @Description: This file stroes event operations.
 */

#ifndef _SCHEDULE_EVENT_H_
#define _SCHEDULE_EVENT_H_

#include<time.h>
#include<stdbool.h>
#include"constant.h"

 /// @brief This structure is used to store time.
typedef struct schedule_time
{
	int minute;
	int hour;
	int day;
	int month;
	int year;
}ScheduleTime;

typedef struct event
{
	ScheduleTime start_time;
	ScheduleTime due_time;
	bool status;
	char * title;
	char * detail;
}Event;

// ScheduleTime operations:

/// @brief This function is used to make up a schedule time.
/// @param time_struct the structure to be defined
void make_time(ScheduleTime * st, int minute,
	int hour, int day, int month, int year);

bool get_time_from_user(ScheduleTime * st);

void get_time_from_json();

#endif // !_SCHEDULE_EVENT_H_