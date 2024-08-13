#include<stdio.h>
#include"include/choose_operation.h"
#include"include/schedule_event.h"
#include"include/link_list.h"
#include"include/json_operation.h"

int main(int argc, char * argv[])
{
	LinkList schedule;
	initialize_link_list(&schedule);
	read_event_from_json_file(&schedule);

	show_link_list(&schedule);

	return 0;
}