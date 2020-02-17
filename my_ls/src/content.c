/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** content.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void reverse_content(content_t **begin)
{
    content_t *first = NULL;
    content_t *elem = NULL;
    content_t *last = NULL;

    first = *begin;
    while (first != NULL) {
        elem = first->next;
        first->next = last;
        last = first;
        first = elem;
    }
    *begin = last;
}

content_t *new_content()
{
    content_t *content = NULL;

    content = malloc(sizeof(*content));
    if (content == NULL)
        return NULL;
    content->file = NULL;
    content->next = NULL;
    return content;
}

void add_to_content(content_t *content, file_t *file)
{
    content_t *first;
    content_t *elem;

    if (content->file == NULL) {
        content->file = file;
        content->next = NULL;
        
    } else {
        first = content;
        elem = malloc(sizeof(*elem));
        elem->file = file;
        elem->next = NULL;
        while (first->next != NULL)
            first = first->next;
        first->next = elem;
    }
}
