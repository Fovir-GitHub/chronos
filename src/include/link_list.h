/*
 * @Author: Fovir
 * @Email: fovir@disroot.org
 * @Date: 2024-08-12 13:35:33
 * @Last Modified by:   Fovir
 * @Last Modified time: 2024-08-12 13:35:53
 * @Description: This file defines link list for event.
 */

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#include"schedule_event.h"

typedef struct node
{
	Event node_event;
	struct node * previous;
	struct node * next;
}Node;

typedef struct link_list
{
	Node * head;
	Node * tail;
}LinkList;

// LinkList operaitons:

/// @brief The function is used to initialize link list, which set head and tail to NULL.
void initialize_link_list(LinkList * plist);

#endif // !_LINK_LIST_H_