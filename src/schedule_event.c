#include "include/schedule_event.h"
#include"include/constant.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

static void eat_line(void);
static int character2integer(char ch);

void make_time(ScheduleTime * st, int minute, int hour, int day, int month, int year)
{
	st->minute = minute;
	st->hour = hour;
	st->day = day;
	st->month = month;
	st->year = year;

	return;
}

bool get_time_from_user(ScheduleTime * st)
{
	char date[DATE_LENGTH];
	int st_length;
	static int big_months[BIG_MONTHS_NUMBER] = { 1,3,5,7,8,10,12 };

	memset(st, 0, sizeof(*st));

	// get date
	puts("Please enter the date (YYYY-MM-DD or MM-DD):");
	scanf("%s", date);
	eat_line();
	st_length = strlen(date);

	if (st_length == 10)	/* YYYY-MM-DD format */
	{
		// check non-digit
		for (int i = 0; i < st_length; i++)
		{
			if (!isdigit(date[i]) && !(i == 4 || i == 7))
			{
				fprintf(stderr, "Invalid format.\n");
				memset(st, 0, sizeof(*st));
				return false;
			}
		}
		for (int i = 0; i < 4; i++)	/* get year */
			st->year = st->year * 10 + character2integer(date[i]);
		for (int i = 5; i < 7; i++)	/* get month */
			st->month = st->month * 10 + character2integer(date[i]);
		for (int i = 8; i < st_length; i++)	/* get day */
			st->day = st->day * 10 + character2integer(date[i]);
	}
	else if (st_length == 5)
	{
		for (int i = 0; i < st_length; i++)
		{
			if (i == 2)
				continue;
			if (!isdigit(date[i]))
			{
				fprintf(stderr, "Invalid format.\n");
				memset(st, 0, sizeof(*st));
				return false;
			}
		}

		for (int i = 0; i < 2; i++)	/* get month */
			st->month = st->month * 10 + character2integer(date[i]);
		for (int i = 3; i < st_length; i++)	/* get day */
			st->day = st->day * 10 + character2integer(date[i]);

		// set year to this year
		time_t current_time = time(NULL);
		struct tm * local_time = localtime(&current_time);
		st->year = local_time->tm_year + 1900;
	}
	else
	{
		fprintf(stderr, "Invalide format.\n");
		memset(st, 0, sizeof(*st));
		return false;
	}

	// if the month is big
	for (int i = 0; i < BIG_MONTHS_NUMBER; i++)
		if (st->month == big_months[i])
		{
			if (st->day > 31)
			{
				fprintf(stderr, "Error date.\n");
				memset(st, 0, sizeof(*st));
				return false;
			}
		}
	// Specially, Feburary
	if (st->month == 2)
	{
		if (st->year % 4 == 0 && st->day > 29)
		{
			fprintf(stderr, "Error date.\n");
			memset(st, 0, sizeof(*st));
			return false;
		}
		else if (st->year % 4 != 0 && st->day > 28)
		{
			fprintf(stderr, "Error date.\n");
			memset(st, 0, sizeof(*st));
			return false;
		}
	}
	else
		if (st->day > 30)
		{
			fprintf(stderr, "Error date.\n");
			memset(st, 0, sizeof(*st));
			return false;
		}

	// get time
	puts("Please enter the time (hh:ss):");
	scanf("%s", date);
	if (strlen(date) != 5)
	{
		fprintf(stderr, "Invalid format.\n");
		memset(st, 0, sizeof(*st));
		return false;
	}

	for (int i = 0; i < strlen(date); i++)
		if (i != 2 && !isdigit(date[i]))
		{
			fprintf(stderr, "Invalid format.\n");
			memset(st, 0, sizeof(*st));
			return false;
		}

	// get hour
	for (int i = 0; i < 2; i++)
		st->hour = st->hour * 10 + character2integer(date[i]);
	for (int i = 3; i < strlen(date); i++)
		st->minute = st->minute * 10 + character2integer(date[i]);

	if (st->hour > 23 || st->minute > 59)
	{
		fprintf(stderr, "Error time.\n");
		memset(st, 0, sizeof(*st));
		return false;
	}

	return true;
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
