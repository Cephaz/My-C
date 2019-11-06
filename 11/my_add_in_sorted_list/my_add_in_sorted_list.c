/*
** ETNA PROJECT, 10/10/2019 by zhou_p
** my_add_in_sorted_list.c
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

linked_list_t *my_push_front(int value, linked_list_t *list)
{
    linked_list_t *node;

    node = malloc(sizeof(*node));
    if (node == 0)
        return (0);
    node->next = list;
    node->data = value;
    return (node);
}

void my_add_in_sorted_list(linked_list_t **begin, int data)
{
	*begin = my_push_front(data, *begin);
	my_sort_list(begin);
}
