/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-11 21:04:56
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-12 17:56:50
 * @Description: The file include constants to be used in this project.
 */

#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#define OPEARTION_NUMBER 4
#define TITLE_LENGTH 81
#define DETAIL_LENGTH 129
#define DATE_LENGTH 11
#define BIG_MONTHS_NUMBER 7

#define FINISHED true
#define NOTSTART false

#define ERROR -1

enum Operations
{
	ADD, REMOVE, LIST, EDIT
};

extern const char * g_operations[OPEARTION_NUMBER];

#endif // !_CONSTANT_H_