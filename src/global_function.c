#include"include/global_function.h"
#include"include/constant.h"
#include<string.h>
#include<stdbool.h>

void global_initialize(void)
{
	memset(g_uid_record, false, sizeof(g_uid_record));
}