/*
** ETNA PROJECT, 10/02/2020 by zhou_p
** sort_content.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void sort_content(content_t **begin, int (*cmp)())
{
    int sorted = 0;
    content_t *ct = NULL;

    while (!sorted) {
        ct = *begin;
        sorted = 1;
        while (ct->next != NULL) {
            if ((*cmp)(ct->file->surname, ct->next->file->surname) > 0) {
                swap(ct, ct->next);
                sorted = 0;
            }
            ct = ct->next;
        }
    }
}

void sort_content_time(content_t **begin)
{
    int sorted = 0;
    content_t *content = NULL;

    while (!sorted) {
        content = *begin;
        sorted = 1;
        while (content->next != NULL) {
            if ((content->file->mtime) < (content->next->file->mtime)) {
                swap(content, content->next);
                sorted = 0;
            }
            content = content->next;
        }
    }
}

void verif_sort(opt_t *opt, path_t *path)
{
    sort_content_time(&path->content);
    if (opt->t != 1)
        sort_content(&path->content, &my_strcmp);
    if (opt->r == 1)
        reverse_content(&path->content);
}