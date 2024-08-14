/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-13 20:03:57
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-13 20:11:42
 * @Description: This file stores some global functions.
 */

#ifndef _GLOBAL_FUNCTION_H_
#define _GLOBAL_FUNCTION_H_

#include"link_list.h"

 /// @brief This function should run in the beginning of the program.
void global_initialize(void);

/// @brief When user choose "add" operation, this function will run.
/// @param plist the link list which will be added new event
void add_operation(LinkList * plist);

/// @brief When user choose "remove" operation, this function will run.
/// @param plist the target link list
void remove_operation(LinkList * plist);

/// @brief This function is used to get a string whose max length is n.
/// This reading includes space.
/// @param str the source string
/// @param n the length of the string
/// @return the string read in
char * s_gets(char * str, int n);

char * copy_string(const char * original);

int character2integer(char ch);

void eat_line(void);

#endif // !_GLOBAL_FUNCTION_H_