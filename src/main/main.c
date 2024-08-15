#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"include/choose_operation.h"
#include"include/schedule_event.h"
#include"include/link_list.h"
#include"include/json_operation.h"
#include"include/global_function.h"
#include"include/constant.h"

int main(int argc, char * argv[])
{
	global_initialize();

	LinkList schedule;
	initialize_link_list(&schedule);
	read_event_from_json_file(&schedule);

	int choice = get_operation(argv[1]);

	switch (choice)
	{
	case ADD:
		add_operation(&schedule);
		break;
	case LIST:
		show_link_list(&schedule);
		break;
	case REMOVE:
		if (argc == 3)	/* input: chronos remove uid */
		{
			int unique_id = 0;
			int length = strlen(argv[2]);
			for (int i = 0; i < length; i++)
			{
				if (!isdigit(argv[2][i]))	/* there is non-digit */
				{
					fprintf(stderr, "Please enter right uid.");
					exit(EXIT_FAILURE);
				}
				unique_id = unique_id * 10 + character2integer(argv[2][i]);
			}

			if (unique_id < 0 || unique_id >= UID_MAX_NUMBER)
			{
				fprintf(stderr, "The uid ranging from 0 - %d",
					UID_MAX_NUMBER - 1);
				exit(EXIT_FAILURE);
			}

			remove_event(&schedule, unique_id);
		}
		else
			remove_operation(&schedule);
		break;
	case EDIT:
		if (argc == 2)
			edit_operation(&schedule, NULL, NO_TERMINAL_ARGUMENT);
		else
			edit_operation(&schedule, argv[2], HAVE_TERMINAL_ARGUMENT);
		break;
	}

	show_link_list(&schedule);

	before_quit(&schedule, get_json_file_path());

	return 0;
}