/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-12 12:39:16
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-13 15:40:15
 * @Description: This file stroes event operations.
 */

#ifndef _SCHEDULE_EVENT_H_
#define _SCHEDULE_EVENT_H_

#include<time.h>
#include<stdbool.h>
#include<cjson/cJSON.h>
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

/// @brief This structure is used to store event
typedef struct event
{
	ScheduleTime * start_time;
	ScheduleTime * due_time;
	bool status;
	char * title;
	char * detail;
	int uid;	/* unique id */
}Event;

// ScheduleTime operations:

/// @brief This function is used to make up a schedule time.
/// @param time_struct the structure to be defined
ScheduleTime * make_time(int year, int month,
	int day, int hour, int minute);

/// @brief This function make up a schedule time from a cJSON object.
/// @return a pointer to ScheduleTime
ScheduleTime * make_time_from_json_object(cJSON * date);

/// @brief Get schedule time from user's input.
/// @param st the operation object
/// @return If get time successfully, it will return true.
///	Otherwise, it will return false.
ScheduleTime * get_time_from_user(void);

/// @brief This function is used to check the order of events.
/// @param first the first event
/// @param second the second event
/// @return If event fist is earlier than the second, it will return 1. If they are the same, it will return 0.
/// Otherwise, it will return -1.
int compare_events(Event * first, Event * second);

/// @brief This function creates new event object.
/// @param title event title
/// @param detail event detail
/// @param uid event unique id
/// @param start_time the start time of the event
/// @param due_time the end time of the event
/// @param status whether the event is finished
/// @return a pointer to a Event object
Event * make_event(char * title, char * detail,
	int uid, ScheduleTime * start_time,
	ScheduleTime * due_time, bool status);

#endif // !_SCHEDULE_EVENT_H_