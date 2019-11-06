/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_find_node.c
** File description:
**      Code is poetry..
*/

#include <stdlib.h>
#include "../include/my_list.h"

linked_list_t *my_find_node(linked_list_t *list, const int data_ref)
{
	while (list != 0) {
		if (list->data == data_ref)
			return (list);
		list = list->next;
	}
	return (NULL);
}
