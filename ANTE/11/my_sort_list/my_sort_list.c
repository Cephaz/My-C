/*
** ETNA PROJECT, 10/10/2019 by zhou_p
** my_sort_list.c
** File description:
**      Code is poetry..
*/

#include <stdlib.h>
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

void my_sort_list(linked_list_t **begin)
{
	linked_list_t *par;
	int total = my_list_size(*begin);
	int i = 0;
	int syb = 0;

	while (i < total) {
		par = *begin;
		while (par->next != NULL) {
			if (par->data > (par->next)->data) {
				syb = par->data;
				par->data = (par->next)->data;
				(par->next)->data = syb;
			}
			par = par->next;
		}
		++i;
	}
}
