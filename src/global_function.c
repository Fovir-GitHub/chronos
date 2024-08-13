#include"include/global_function.h"
#include"include/constant.h"
#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void global_initialize(void)
{
	memset(g_uid_record, false, sizeof(g_uid_record));
	srand(time(NULL));

	return;
}

void add_event_from_user_input(LinkList * plist)
{
	// check whether the event is full.
	bool uid_is_full = true;
	for (int i = 0; i < UID_MAX_NUMBER; i++)
		if (!g_uid_record[i])
		{
			uid_is_full = false;
			break;
		}
	if (uid_is_full)
	{
		fprintf(stderr, "The events is full.\n");
		exit(EXIT_FAILURE);
	}

	static char s_title[TITLE_LENGTH];
	static char s_detail[DETAIL_LENGTH];
	char * title, * detail;
	ScheduleTime * start_time, * due_time;
	int uid;

	puts("Please enter the event's name:");
	// avoid blank input
	while (true)
	{
		s_gets(s_title, TITLE_LENGTH);

		bool all_blank = true;
		int str_length = strlen(s_title);

		for (int i = 0; i < str_length; i++)
			if (s_title[i] != ' ')
			{
				all_blank = false;
				break;
			}
		if (all_blank)
			puts("The name can't be empty, enter again:");
		else
			break;
	}
	title = copy_string(s_title);

	puts("Please enter details (black is OK):");
	s_gets(s_detail, DETAIL_LENGTH);
	if (strlen(s_detail) == 0)
		detail = copy_string(" ");
	else
		detail = copy_string(s_detail);

	puts("Now enter the start time:");
	start_time = get_time_from_user();
	puts("Now enter the end time:");
	due_time = get_time_from_user();

	// generate uid
	while (g_uid_record[(uid = rand() % UID_MAX_NUMBER)]);
	g_uid_record[uid] = true;

	Event * new_event = make_event(title, detail, uid,
		start_time, due_time, false);

	add_new_event(plist, *new_event);

	return;
}

char * s_gets(char * str, int n)
{
	char * ret_val = fgets(str, n, stdin);

	if (ret_val)
	{
		char * find = strchr(ret_val, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

char * copy_string(const char * original)
{
	size_t length = strlen(original) + 1;
	char * copy = (char *) malloc(length);

	if (!copy)
	{
		perror("Can't allocate memory.");
		exit(EXIT_FAILURE);
	}

	strcpy(copy, original);

	return copy;
}
