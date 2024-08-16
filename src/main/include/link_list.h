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

/// @brief This function is used to remove event in a link list.
/// @param plist the link list
/// @param unique_id the event's uid
void remove_event(LinkList * plist, int unique_id);

/// @brief This function tells whether the uid exist in the link list.
/// @param plist the link list storing data
/// @param uid the uid user want to search
/// @return If the uid is found, it will return the pointer.
/// Otherwise, it return NULL.
Node * find_uid(LinkList * plist, int uid);

/// @brief This function is used to copy a node to another.
/// @param original the original node
/// @return the new node
Node * copy_node(Node * original);

/// @brief This function shows one specific node.
/// @param node pointer of the node to be shown
void show_node(Node * node);

void free_link_list(LinkList * plist);

#endif // !_LINK_LIST_H_