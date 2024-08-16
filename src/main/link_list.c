#include"include/link_list.h"
#include<stdlib.h>
#include<stdio.h>

void initialize_link_list(LinkList * plist)
{
	*plist = NULL;

	return;
}

bool add_new_event(LinkList * plist, Event new_event)
{
	Node * pnew = (Node *) malloc(sizeof(Node));
	Node * scan = *plist;

	if (!pnew)
	{
		fprintf(stderr, "Can't allocate space.\n");
		return false;
	}

	pnew->node_event = new_event;
	pnew->next = NULL;

	if (scan == NULL)	/* the link list is empty */
		*plist = pnew;
	// the link list is not empty, and the new node is earlier than the head
	else if (compare_events(&(*plist)->node_event, &pnew->node_event)
		== SECOND_EARLIER_THAN_FIRST)
	{
		pnew->next = *plist;
		*plist = pnew;
		return true;
	}
	else
	{
		Node * previous = NULL;
		while (scan != NULL
			&& compare_events(&scan->node_event,
				&pnew->node_event) == FIRST_EARLIER_THAN_SECOND)
		{
			previous = scan;
			scan = scan->next;
		}

		// time conflict
		if (compare_events(&previous->node_event,
			&pnew->node_event) == FIRST_AND_SECOND_ARE_THE_SAME)
		{
			fprintf(stderr, "The time has been occupied by event: %s\n",
				scan->node_event.title);
			free(pnew);	/* delete the item */

			return false;
		}

		// insert to the head
		if (!previous)
		{
			pnew->next = *plist;
			*plist = pnew;
		}
		else
		{
			previous->next = pnew;
			pnew->next = scan;
		}
	}

	return true;
}

void show_link_list(const LinkList * plist)
{
	Node * scan = *plist;

	while (scan)
	{
		show_node(scan);
		scan = scan->next;
	}

	return;
}

void show_node(Node * node)
{
	printf("%s\n", node->node_event.title);
	printf("    From %d-%02d-%02d %02d:%02d to %d-%02d-%02d %02d:%02d\n",
		node->node_event.start_time->year,
		node->node_event.start_time->month,
		node->node_event.start_time->day,
		node->node_event.start_time->hour,
		node->node_event.start_time->minute,
		node->node_event.due_time->year,
		node->node_event.due_time->month,
		node->node_event.due_time->day,
		node->node_event.due_time->hour,
		node->node_event.due_time->minute);
	printf("    UID = %3d, Status: %s\n", node->node_event.uid,
		(node->node_event.status ? "Finished" : "Wait to finish"));
	printf("    Details: %s\n", node->node_event.detail);

	return;
}

void remove_event(LinkList * plist, int unique_id)
{
	if (!(*plist))	/* the link list is empty */
	{
		fprintf(stderr, "Nothing to remove.");
		exit(EXIT_FAILURE);
	}

	Node * current = *plist;
	Node * previous = NULL;

	if (current->next == NULL)	/* there is only one item in link list */
	{
		if (current->node_event.uid == unique_id)
			current = NULL;
		else
			fprintf(stderr, "Not found event: %d", unique_id);
		return;
	}

	while (current)
	{
		if (current->node_event.uid == unique_id)
		{
			if (previous == NULL)
			{
				*plist = current->next;
				free(current);
			}
			else
			{
				previous->next = current->next;
				free(current);
			}
			g_uid_record[unique_id] = false;	/* mark as no used uid */
			return;
		}
		previous = current;
		current = current->next;
	}

	fprintf(stderr, "Not found event: %d", unique_id);
	exit(EXIT_FAILURE);
}

Node * find_uid(LinkList * plist, int uid)
{
	Node * scan = *plist;

	while (scan)
	{
		if (scan->node_event.uid == uid)
			return scan;
		scan = scan->next;
	}

	return NULL;
}

Node * copy_node(Node * original)
{
	Node * new_node = (Node *) malloc(sizeof(Node));
	if (!new_node)
	{
		perror("Can't copy node.");
		exit(EXIT_FAILURE);
	}

	new_node->node_event = original->node_event;
	new_node->next = original->next;

	return new_node;
}

void free_link_list(LinkList * plist)
{
	Node * backup;
	while (*plist)
	{
		backup = (*plist)->next;
		free(*plist);
		*plist = backup;
	}

	return;
}