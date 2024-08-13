/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-12 13:35:33
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-13 16:44:38
 * @Description: This file defines link list for event.
 */

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include"schedule_event.h"
#include<stdbool.h>

typedef struct node
{
	Event node_event;
	struct node * next;
}Node;

typedef Node * LinkList;

// LinkList operaitons:

/// @brief The function is used to initialize link list, which set head and tail to NULL.
void initialize_link_list(LinkList * plist);

/// @brief The function is used to add new event to the link list. In time order.
/// @param plist the pointer of the target link list.
/// @param new_event the event to be added.
/// @return If the function added successfully, it will return true. Otherwise, it returns false.
bool add_new_event(LinkList * plist, Event new_event);

/// @brief The function is used to show link list's content.
void show_link_list(const LinkList * plist);

#endif // !_LINK_LIST_H_