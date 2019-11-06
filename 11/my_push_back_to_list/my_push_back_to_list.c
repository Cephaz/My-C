/*
** ETNA PROJECT, 10/10/2019 by zhou_p
** my_push_back_to_list.c
** File description:
**      Code is poetry..
*/

#include <stdlib.h>
#include "../include/my_list.h"

linked_list_t *my_push_back_to_list(int value, linked_list_t *list)
{
	linked_list_t *node;
	linked_list_t *pos1 = list;

	node = malloc(sizeof(*node));
	while (pos1->next != NULL)
		pos1 = pos1->next;
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	pos1->next = node;
	node->data = value;
	return (list);
}
