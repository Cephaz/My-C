/*
** ETNA PROJECT, 10/10/2019 by zhou_p
** my_merge.c
** File description:
**      Code is poetry..
*/

#include "../include/my_list.h"
#include <stdlib.h>

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

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
        linked_list_t *chaine = *begin1;

        while (chaine->next != NULL)
                chaine = chaine->next;
        if (chaine->next == NULL)
                chaine->next = begin2;
        chaine = *begin1;
}

void my_merge(linked_list_t **begin1, linked_list_t *begin2)
{
	my_concat_list(begin1, begin2);
	my_sort_list(begin1);
}
