#include "include/schedule_event.h"
#include"include/constant.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static void eat_line(void);
static int character2integer(char ch);

void make_time(ScheduleTime * st, int mininute, int hour, int day, int month, int year)
{
	st->mininute = mininute;
	st->hour = hour;
	st->day = day;
	st->month = month;
	st->year = year;

	return;
}

void get_time_from_user(ScheduleTime * st)
{
	char date[DATE_LENGTH];
	int st_length;
	st->day = st->hour = st->mininute = st->month = st->year = 0;

	puts("Please enter the date (YYYY-MM-DD or MM-DD):");
	scanf("%s", date);
	eat_line();
	st_length = strlen(date);

	if (st_length == 10)	/* YYYY-MM-DD format */
	{
		for (int i = 0; i < 4; i++)	/* read in year */
			st->year = st->year * 10 + character2integer(date[i]);
		for (int i = 5; i < 7; i++)
			st->month = st->month * 10 + character2integer(date[i]);
		for (int i = 8; i < 10; i++)
			st->day = st->day * 10 + character2integer(date[i]);
	}
}


void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

int character2integer(char ch)
{
	return (int) (ch - '0');
}
