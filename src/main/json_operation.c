#include"include/json_operation.h"
#include"include/constant.h"
#include"include/schedule_event.h"
#include"include/global_function.h"
#include<cjson/cJSON.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<pwd.h>

char * get_json_file_path(void)
{
	struct passwd * pw = getpwuid(getuid());
	const char * home_dir = pw->pw_dir;

	char * file_path = malloc(strlen(home_dir) +
		strlen("/.config/chronos-data/data.json") + 1);

	if (!file_path)
	{
		perror("Can't allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	sprintf(file_path, "%s/.config/chronos-data/data.json", home_dir);
	return file_path;
}

char * read_json_file(const char * file_path)
{
	FILE * file;
	long length;

	file = fopen(file_path, "r");
	if (!file)
	{
		fprintf(stderr, "Can't open %s\n", file_path);
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
	char * json_string = read_json_file(get_json_file_path());
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

cJSON * make_json_from_event(const Event * event)
{
	cJSON * event_json = cJSON_CreateObject();
	if (!event_json)
	{
		fprintf(stderr, "Can't create cJSON object.\n");
		exit(EXIT_FAILURE);
	}

	cJSON_AddNumberToObject(event_json, "uid", event->uid);

	cJSON * start_date = cJSON_CreateObject();
	cJSON_AddNumberToObject(start_date, "year", event->start_time->year);
	cJSON_AddNumberToObject(start_date, "month", event->start_time->month);
	cJSON_AddNumberToObject(start_date, "day", event->start_time->day);
	cJSON_AddNumberToObject(start_date, "hour", event->start_time->hour);
	cJSON_AddNumberToObject(start_date, "minute", event->start_time->minute);
	cJSON_AddItemToObject(event_json, "start_date", start_date);

	cJSON * due_date = cJSON_CreateObject();
	cJSON_AddNumberToObject(due_date, "year", event->due_time->year);
	cJSON_AddNumberToObject(due_date, "month", event->due_time->month);
	cJSON_AddNumberToObject(due_date, "day", event->due_time->day);
	cJSON_AddNumberToObject(due_date, "hour", event->due_time->hour);
	cJSON_AddNumberToObject(due_date, "minute", event->due_time->minute);
	cJSON_AddItemToObject(event_json, "due_date", due_date);

	cJSON_AddStringToObject(event_json, "detail", event->detail);
	cJSON_AddNumberToObject(event_json, "status", event->status);

	return event_json;
}

void before_quit(LinkList * plist, const char * file_path)
{
	cJSON * json = cJSON_CreateObject();
	if (!json)
	{
		fprintf(stderr, "Can't create cJSON object.\n");
		exit(EXIT_FAILURE);
	}

	Node * current = *plist;

	while (current)
	{
		cJSON * event_json = make_json_from_event(&current->node_event);
		if (!event_json)
		{
			fprintf(stderr, "Can't create cJSON object.\n");
			exit(EXIT_FAILURE);
		}

		cJSON_AddItemToObject(json, current->node_event.title, event_json);
		current = current->next;
	}

	output_to_json_file(file_path, json);
	cJSON_Delete(json);

	return;
}

void output_to_json_file(const char * file_path, cJSON * json)
{
	char * json_string = cJSON_Print(json);
	if (!json_string)
	{
		fprintf(stderr, "Failed to print JSON.\n");
		exit(EXIT_FAILURE);
	}

	FILE * output = fopen(file_path, "w");
	if (!output)
	{
		fprintf(stderr, "Can't open file %s\n", file_path);
		free(json_string);
		exit(EXIT_FAILURE);
	}

	fprintf(output, "%s", json_string);
	fclose(output);
	free(json_string);

	return;
}