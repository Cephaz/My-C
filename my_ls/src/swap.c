/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** swap.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void swap(content_t *a, content_t *b)
{
    void *tmp = a->file;
    a->file = b->file;
    b->file = tmp;
}
