#include"include/time_function.h"
#include"../main/include/constant.h"
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

time_t get_current_time(void)
{
	return time(NULL);
}

time_t covert_schedule_to_time(ScheduleTime * st)
{
	struct tm ret_val;

	memset(&ret_val, 0, sizeof(struct tm));

	ret_val.tm_year = st->year - 1900;
	ret_val.tm_mon = st->month - 1;
	ret_val.tm_mday = st->day;
	ret_val.tm_hour = st->hour;
	ret_val.tm_min = st->minute;

	return mktime(&ret_val);
}

void alarm_event(Node * event)
{
	const static char * programm_name = "Chronos";

	time_t now = get_current_time();
	time_t target_time = covert_schedule_to_time(event->node_event.start_time);

	sleep(difftime(target_time, now));

	play_sound();

	char command[COMMAND_LENGTH];
	sprintf(command, "notify-send \"%s\" \"It's time to do %s\"",
		programm_name, event->node_event.title);
	system(command);

	now = get_current_time();
	target_time = covert_schedule_to_time(event->node_event.due_time);

	sleep(difftime(target_time, now));

	play_sound();
	sprintf(command, "notify-send \"%s\" \"%s is end.\"",
		programm_name, event->node_event.title);
	system(command);
	event->node_event.status = FINISHED;

	return;
}

void play_sound(void)
{
	putchar('\a');
}