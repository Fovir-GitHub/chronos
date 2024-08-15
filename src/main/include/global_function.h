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

/// @brief When user choose "edit" operation, this function will run.
/// @param plist the link list storing data
/// @param unique_id the unique_id entered in terminal
/// @param status whether has the terminal's uid, possible value: 
/// NO_TERMINAL_ARGUMENT or HAVE_TERMINAL_ARGUMENT (from constant.h )
void edit_operation(LinkList * plist, const char * unique_id, int status);

/// @brief This function is used to get a string whose max length is n.
/// This reading includes space.
/// @param str the source string
/// @param n the length of the string
/// @return the string read in
char * s_gets(char * str, int n);

/// @brief Copy a string to another string with malloc function.
/// @param original the original string
/// @return the new string
char * copy_string(const char * original);

/// @brief Covert character '0' to '9' to integer 0 to 9.
/// @param ch the character
/// @return the integer
int character2integer(char ch);

/// @brief Refresh the buffer.
void eat_line(void);

void restart_timer(void);

#endif // !_GLOBAL_FUNCTION_H_