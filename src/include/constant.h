/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-11 21:04:56
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-12 12:41:04
 * @Description: The file include constants to be used in this project.
 */

#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#define OPEARTION_NUMBER 4
#define TITLE_LENGTH 81
#define DETAIL_LENGTH 129

enum Operations
{
	ADD, REMOVE, LIST, RESET, ERROR
};

const char * g_operations[OPEARTION_NUMBER] =
{
	"add","remove","list","reset"
};

#endif // !_CONSTANT_H_