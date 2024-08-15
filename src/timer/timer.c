#include<stdio.h>
#include<time.h>
#include"../main/include/json_operation.h"
#include"../main/include/link_list.h"
#include"../main/include/constant.h"
#include"include/time_function.h"

int main(void)
{
	LinkList event_data;

	initialize_link_list(&event_data);
	read_event_from_json_file(&event_data);	/* get json data */

	Node * scan = event_data;
	time_t now = get_current_time();
	while (scan)
	{
		if (scan->node_event.status == NOTSTART
			&& covert_schedule_to_time(scan->node_event.start_time) > now)
		{
			alarm_event(scan);
			before_quit(&event_data, get_json_file_path());
		}
		scan = scan->next;
	}

	return 0;
}