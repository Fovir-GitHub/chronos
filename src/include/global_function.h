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

void global_initialize(void);

void add_event_from_user_input(LinkList * plist);

char * s_gets(char * str, int n);
char * copy_string(const char * original);

#endif // !_GLOBAL_FUNCTION_H_