/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-12 12:39:16
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-12 12:46:16
 * @Description: This file stroes event operations.
 */

#ifndef _SCHEDULE_EVENT_H_
#define _SCHEDULE_EVENT_H_

#include<time.h>

 /// @brief This structure is used to store time.
typedef struct schedule_time
{
	int mininute;
	int hour;
	int day;
	int month;
	int year;
}ScheduleTime;

typedef struct event
{
	ScheduleTime start_time;
	ScheduleTime due_time;
	char * title;
	char * detail;
}Event;

typedef struct node
{
	Event node_event;
	struct node * previous;
	struct node * next;
}Node;

typedef struct link_list
{
	Node * head;
	Node * tail;
}LinkList;


/// @brief This function is used to make up a schedule time.
/// @param time_struct the structure to be defined
void make_time(ScheduleTime * st, int mininute,
	int hour, int day, int month, int year);

#endif // !_SCHEDULE_EVENT_H_