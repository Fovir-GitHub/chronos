#include "include/schedule_event.h"


void make_time(ScheduleTime * st, int mininute, int hour, int day, int month, int year)
{
	st->mininute = mininute;
	st->hour = hour;
	st->day = day;
	st->month = month;
	st->year = year;

	return;
}