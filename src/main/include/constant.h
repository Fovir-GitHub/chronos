/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-11 21:04:56
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-15 15:33:44
 * @Description: The file include constants to be used in this project.
 */

#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#include<stdbool.h>

#define DEBUG printf("debug\n")

#define OPEARTION_NUMBER 4
#define TITLE_LENGTH 81
#define DETAIL_LENGTH 129
#define DATE_LENGTH 11
#define BIG_MONTHS_NUMBER 7
#define COMMAND_LENGTH 256
#define TIMER_NAME "chronos-timer"

 // JSON operation
#define FINISHED true
#define NOTSTART false

 // for compare_events function
#define FIRST_EARLIER_THAN_SECOND 1
#define SECOND_EARLIER_THAN_FIRST -1
#define FIRST_AND_SECOND_ARE_THE_SAME 0

#define ERROR -1

#define NO_TERMINAL_ARGUMENT -1
#define HAVE_TERMINAL_ARGUMENT -2

#define UID_MAX_NUMBER 512	/* UID record array size */
extern bool g_uid_record[UID_MAX_NUMBER];

enum Operations
{
	ADD, REMOVE, LIST, EDIT
};

extern const char * g_operations[OPEARTION_NUMBER];

#endif // !_CONSTANT_H_