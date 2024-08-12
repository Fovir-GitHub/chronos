#include"include/link_list.h"
#include<stdlib.h>

void initialize_link_list(LinkList * plist)
{
	plist->head = NULL;
	plist->tail = NULL;

	return;
}