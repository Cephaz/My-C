/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_delete_nodes.c
** File description:
**      Code is poetry..
*/

#include <stdlib.h>
#include "../include/my_list.h"

void my_delete_nodes(linked_list_t **list, const int data_ref)
{
	linked_list_t *par = *list;
	linked_list_t *cur = *list;
	int pre = 0;

	if (par->data == data_ref)
		pre = 1;
	while (par->next != NULL) {
		cur = par->next;
		if ((par->next)->data == data_ref)
			par->next = cur->next;
		else
			par = par->next;
	}
	if (pre == 1) {
		par = *list;
		*list = (*list)->next;
	} else
		par = *list;
}
