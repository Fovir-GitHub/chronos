#include"include/choose_operation.h"
#include"include/constant.h"
#include<string.h>
#include<ctype.h>

static void string_to_lower(char * str);

int get_operation(char * operation)
{
	string_to_lower(operation);

	for (int i = 0; i < OPEARTION_NUMBER; i++)
		if (strcmp(operation, g_operations[i]) == 0)
			return i;

	return ERROR;
}

static void string_to_lower(char * str)
{
	int length = strlen(str);

	for (int i = 0; i < length; i++)
		str[i] = tolower(str[i]);

	return;
}
