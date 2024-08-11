/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-11 21:04:56
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-11 21:42:32
 * @Description: The file include constants to be used in this project.
 */

#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#define OPEARTION_NUMBER 4

enum Operations
{
	ADD, REMOVE, LIST, RESET, ERROR
};

const char * OPERATIONS[OPEARTION_NUMBER] =
{
	"add","remove","list","reset"
};

#endif // !_CONSTANT_H_