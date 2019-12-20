/*
** ETNA PROJECT, 10/10/2019 by zhou_p
** my_concat_list.c
** File description:
**      Code is poetry..
*/

#include "../include/my_list.h"
#include <stdlib.h>

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
	linked_list_t *chaine = *begin1;

	while (chaine->next != NULL)
		chaine = chaine->next;
	if (chaine->next == NULL)
		chaine->next = begin2;
	chaine = *begin1;
}
