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
		printf("%s\n", scan->node_event.title);
		printf("    From %d-%02d-%02d %02d:%02d to %d-%02d-%02d %02d:%02d\n",
			scan->node_event.start_time->year,
			scan->node_event.start_time->month,
			scan->node_event.start_time->day,
			scan->node_event.start_time->hour,
			scan->node_event.start_time->minute,
			scan->node_event.due_time->year,
			scan->node_event.due_time->month,
			scan->node_event.due_time->day,
			scan->node_event.due_time->hour,
			scan->node_event.due_time->minute);
		printf("    UID = %3d, Status: %s\n", scan->node_event.uid,
			(scan->node_event.status ? "Finished" : "Wait to finish"));
		printf("    Details: %s\n", scan->node_event.detail);

		scan = scan->next;
	}

	return;
}