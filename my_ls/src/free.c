/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** free.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void free_content(content_t *content)
{
    content_t *tmp;

    tmp = content;
    while (content->next != NULL) {
        tmp = content;
        content = content->next;
        free(tmp->file->name);
        free(tmp->file->surname);
        free(tmp->file->time);
        free(tmp->file);
        free(tmp);
    }
}
