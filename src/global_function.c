#include"include/global_function.h"
#include"include/constant.h"
#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

void global_initialize(void)
{
	memset(g_uid_record, false, sizeof(g_uid_record));
	srand(time(NULL));

	return;
}

void add_operation(LinkList * plist)
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

void remove_operation(LinkList * plist)
{
	int uid;

	show_link_list(plist);
	putchar('\n');
	puts("Please enter the uid of the event that you want to remove:");

	while (scanf("%d", &uid) != 1 || uid < 0 || uid >= UID_MAX_NUMBER)
	{
		printf("Please enter the right uid again (0 - %d)\n",
			UID_MAX_NUMBER - 1);
		eat_line();
	}

	remove_event(plist, uid);

	return;
}

void edit_operation(LinkList * plist, const char * unique_id, int status)
{
	int uid = 0;

	if (status == HAVE_TERMINAL_ARGUMENT)
	{
		int length = strlen(unique_id);
		for (int i = 0; i < length; i++)
		{
			if (!isdigit(unique_id[i]))
			{
				fprintf(stderr, "Invalid UID");
				exit(EXIT_FAILURE);
			}
			uid = uid * 10 + character2integer(unique_id[i]);
		}
	}
	else
	{
		show_link_list(plist);
		putchar('\n');
		printf("Please select the event's UID: ");
		while (scanf("%d", &uid) != 1 || uid < 0 || uid >= UID_MAX_NUMBER - 1)
		{
			printf("Please enter the right uid again (0 - %d)\n",
				UID_MAX_NUMBER - 1);
			eat_line();
		}
	}

	Node * edit_node = find_uid(plist, uid);
	if (!edit_node)
	{
		fprintf(stderr, "Not found the uid: %d\n", uid);
		exit(EXIT_FAILURE);
	}

	if (status == NO_TERMINAL_ARGUMENT)
		eat_line();
	else
		show_node(edit_node);
	char choice;
	Event new_event = edit_node->node_event;
	bool edited = false;

	printf("Do you want to change the start time? [y/N]: ");
	scanf("%c", &choice);
	if (tolower(choice) == 'y')
	{
		edited = true;
		new_event.start_time = get_time_from_user();
	}

	printf("Do you want to change the end time? [y/N]: ");
	scanf("%c", &choice);
	if (tolower(choice) == 'y')
	{
		edited = true;
		new_event.due_time = get_time_from_user();
	}

	printf("Do you want to change the event's name? [y/N]: ");
	scanf("%c", &choice);
	if (tolower(choice) == 'y')
	{
		edited = true;
		puts("Please enter the new event's name:");
		eat_line();
		s_gets(new_event.title, TITLE_LENGTH);
	}

	printf("Do you want to change the event's details [y/N]: ");
	scanf("%c", &choice);
	if (tolower(choice) == 'y')
	{
		edited = true;
		puts("Please enter the new evnet's details:");
		eat_line();
		s_gets(new_event.detail, DETAIL_LENGTH);
	}

	printf("Do you want to upate the event's status? [y/N]: ");
	scanf("%c", &choice);
	if (tolower(choice) == 'y')
	{
		edited = true;
		new_event.status ^= true;
	}

	if (edited)
	{
		remove_event(plist, uid);
		add_new_event(plist, new_event);
	}

	return;
}

int character2integer(char ch)
{
	return (int) (ch - '0');
}

void eat_line(void)
{
	while (getchar() != '\n');
}