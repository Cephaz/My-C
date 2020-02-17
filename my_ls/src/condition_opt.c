/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** condition_opt.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

int condition_opta(opt_t *opt, char *s)
{
    int a = (opt->A == 1) ? 1 : 0;

    if (a == 1) {
        if (my_strcmp(s, ".") != 0 && my_strcmp(s, "..") != 0)
            return (1);
    }
    return (0);
}

int condition_opt(opt_t *opt, char *s)
{
    char c = (opt->a == 1) ? ' ': '.';
    int true = 1;

    if (opt->A == 1) {
        c = ' ';
        true = condition_opta(opt, s);
    }
    if (s[0] != c && true == 1) {
        return (1);
    }
    return (0);
}

void condition_optd(opt_t *opt, path_t *path)
{
    while (path->content != NULL) {
        if (opt->d == 1)
            if (my_strcmp(path->content->file->name, ".") == 0) {
                display_name(path->content->file, opt);
                my_putstr("\n");
            }
        path->content = path->content->next;
    }
}