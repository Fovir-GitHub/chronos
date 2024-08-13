#include"include/json_operation.h"
#include"include/constant.h"
#include"include/schedule_event.h"
#include<cjson/cJSON.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

static char * copy_string(const char * original);

char * read_json_file(const char * file_path)
{
	FILE * file;
	long length;

	file = fopen(file_path, "r");
	if (!file)
	{
		perror("Can't open the file");
		exit(EXIT_FAILURE);
	}

	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);

	char * content = (char *) malloc(length + 1);
	if (!content)
	{
		perror("Can't allocate memory.");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	fread(content, 1, length, file);
	content[length] = '\0';

	fclose(file);

	return content;
}

void read_event_from_json_file(LinkList * plist)
{
	char * json_string = read_json_file(JSON_FILE_PATH);
	if (!json_string)
	{
		perror("Can't read in JSON file.");
		exit(EXIT_FAILURE);
	}

	cJSON * json = cJSON_Parse(json_string);
	free(json_string);

	if (!json)
	{
		perror("Can't parse JSON file.");
		exit(EXIT_FAILURE);
	}

	cJSON * item = NULL;
	cJSON * value = NULL;
	cJSON * current_key = NULL;

	cJSON_ArrayForEach(current_key, json)
	{
		if (cJSON_IsObject(current_key))
		{
			value = cJSON_GetObjectItem(json, current_key->string);	/* title */
			if (cJSON_IsObject(value))
			{
				cJSON * uid = cJSON_GetObjectItemCaseSensitive(value, "uid");
				cJSON * detail = cJSON_GetObjectItemCaseSensitive(value, "detail");
				cJSON * status = cJSON_GetObjectItemCaseSensitive(value, "status");
				cJSON * start_date =
					cJSON_GetObjectItemCaseSensitive(value, "start_date");
				cJSON * due_date =
					cJSON_GetObjectItemCaseSensitive(value, "due_date");

				ScheduleTime * start_time =
					make_time_from_json_object(start_date);
				ScheduleTime * due_time =
					make_time_from_json_object(due_date);

				// prevent cJSON_Delete()
				char * copy_title = copy_string(current_key->string);
				char * copy_detail = copy_string(detail->valuestring);

				Event * new_event = make_event(copy_title,
					copy_detail, uid->valueint,
					start_time, due_time, status->valueint);

				add_new_event(plist, *new_event);
				free(new_event);
			}
		}
	}
	cJSON_Delete(json);

	return;
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
