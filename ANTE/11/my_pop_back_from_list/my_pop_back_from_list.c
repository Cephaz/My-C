/*
** ETNA PROJECT, 10/10/2019 by zhou_p
** my_pop_back_from_list.c
** File description:
**      Code is poetry..
*/

#include <stdlib.h>
#include "../include/my_list.h"

linked_list_t *my_pop_back_from_list(linked_list_t *list)
{
	linked_list_t *sub = list;
	linked_list_t *sup = list;
	int i = 0;

	if (list->next != NULL) {
		while (sub->next != NULL) {
			++i;
			sub = sub->next;
		}
		while (i > 1) {
			sup = sup->next;
			--i;
		}
		sup->next = NULL;
	} else
		return (NULL);
	free(sub);
	sup = list;
	return (list);
}
