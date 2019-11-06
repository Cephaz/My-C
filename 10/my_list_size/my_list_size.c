/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_list_size.c
** File description:
**      Code is poetry..
*/

#include "../include/my_list.h"

int my_list_size(const linked_list_t *list)
{
	int cpt = 0;

	while (list != 0) {
		++cpt;
		list = list->next;
	}
	return (cpt);
}
