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
		while (scan->next)
			scan = scan->next;
		scan->next = pnew;
	}

	return true;
}