#include<stdio.h>
#include"include/choose_operation.h"
#include"include/schedule_event.h"
#include"include/link_list.h"
#include"include/json_operation.h"
#include"include/global_function.h"

int main(int argc, char * argv[])
{
	global_initialize();

	LinkList schedule;
	initialize_link_list(&schedule);
	read_event_from_json_file(&schedule);

	int choice = get_operation(argv[1]);
	if (choice == ADD)
		add_event_from_user_input(&schedule);

	show_link_list(&schedule);

	return 0;
}