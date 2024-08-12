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
	Node * scan_next = scan->next;

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
		while (scan_next->next
			&& compare_events(&scan_next->node_event,
				&pnew->node_event) == FIRST_EARLIER_THAN_SECOND)
		{
			scan = scan->next;
			scan_next = scan_next->next;
		}

		// time conflict
		if (compare_events(&scan_next->node_event,
			&pnew->node_event) == FIRST_AND_SECOND_ARE_THE_SAME)
		{
			fprintf(stderr, "The time has been occupied by event: %s\n",
				scan_next->node_event.title);
			free(pnew);	/* delete the item */

			return false;
		}
		/*
		now the link list looks like:
		scan	pnew	scan_next
		*/

		scan->next = pnew;
		pnew->next = scan_next;
	}

	return true;
}