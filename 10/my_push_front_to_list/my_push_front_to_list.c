/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_push_front_to_list.c
** File description:
**      Code is poetry..
*/

#include <stdlib.h>
#include "../include/my_list.h"

linked_list_t *my_push_front_to_list(int value, linked_list_t *list)
{
	linked_list_t *node;

	node = malloc(sizeof(*node));
	if (node == 0)
		return (0);
	node->next = list;
	node->data = value;
	return (node);
}
