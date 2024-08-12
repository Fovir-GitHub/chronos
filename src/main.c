#include<stdio.h>
#include"include/choose_operation.h"
#include"include/schedule_event.h"

int main(int argc, char * argv[])
{
	ScheduleTime st;
	get_time_from_user(&st);

	printf("%d %d %d\n%d %d", st.year, st.month, st.day, st.hour, st.mininute);

	return 0;
}