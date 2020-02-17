/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** display_list.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

int max_nbrlen(content_t *content, int i)
{
    int max = 0;
    content_t *first;

    first = content;
    while (first != NULL) {
        if (first->file->name[0] != '.') {
            if (i == 1) {
                if (my_nbrlen(first->file->size) > max)
                    max = my_nbrlen(first->file->size);
            } else
                if (my_nbrlen(first->file->nb_link) > max)
                    max = my_nbrlen(first->file->nb_link);
        }
        first = first->next;
    }
    return max;
}

int count_nb_blocks(content_t *content, opt_t *opt)
{
    content_t *first;
    int nb_blocks = 0;
    char c = '.';

    if (opt->a == 1)
        c = ' ';
    first = content;
    while (first != NULL && first->file != NULL) {
        if (first->file->name[0] != c)
            nb_blocks += first->file->blocks;
        first = first->next;
    }
    return nb_blocks / 2;
}

void display_info(content_t *content, file_t *file)
{
    int i;
    int n = 0;

    n = max_nbrlen(content, 2);
    my_putstr(file->stat);
    my_putchar(' ');
    for (i = 0; i < n - my_nbrlen(file->nb_link); i++)
        my_putchar(' ');
    my_putnbr(file->nb_link);
    my_putchar(' ');
    my_putstr(file->user);
    my_putchar(' ');
    my_putstr(file->group);
    my_putchar(' ');
}

int display_link_reference(file_t *file)
{
    char *link;
    char *str;

    my_putstr(" -> ");
    link = malloc(file->size + 1);
    if (link == NULL)
        return 0;
    if (readlink(file->name, link, file->size + 1)) {
        str = my_strdup(link);
        my_putstr(str);
        free(str);
        free(link);
    }
    return 1;
}

void display_list(content_t *content, file_t *file, opt_t *opt)
{
    int i = -1;
    int length = 0;
    char *s = file->name;

    if (condition_opt(opt, s) == 1) {
        display_info(content, file);
        length = max_nbrlen(content, 1);
        while (++i < length - my_nbrlen(file->size))
            my_putchar(' ');
        my_putnbr(file->size);
        my_putstr(" ");
        display_time(file->time);
        my_putchar(' ');
        my_putstr(s);
        if (file->stat[0] == 'l')
            display_link_reference(file);
        my_putchar('\n');
    }
}
