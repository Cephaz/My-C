/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** displayoptions.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void display_condition(path_t *path, opt_t *opt, int x)
{
    char c = (opt->a == 1) ? ' ' : '.';
    int verif = 1;

    if (opt->A == 1) {
        c = ' ';
        verif = condition_opt(opt, path->content->file->name);
    }
    if (path->content->file != NULL) {
        if (path->content->file->name != NULL) {
            if (path->content->file->name[0] != c && x == 1 && verif == 1)
                display_name(path->content->file, opt);
            if (path->content->file->name[0] != c && x == 2 && verif == 1)
                display_list(path->content, path->content->file, opt);
        }
    } else {
        my_putstr(get_path(path->name));
        my_putstr("\n");
    }
}

void displayneg(path_t *path, opt_t *opt)
{
    if (path != NULL){
        verif_sort(opt, path);
        while (path->content != NULL) {
            display_condition(path, opt, 1);
            path->content = path->content->next;
        }
        if (path->next != NULL)
            display_name(NULL, opt);
    }
}

void displayl(path_t *path, opt_t *opt)
{
    if (path != NULL){
        verif_sort(opt, path);
        while (path->content != NULL) {
            display_condition(path, opt, 2);
            path->content = path->content->next;
        }
        if (path->next != NULL)
            display_name(NULL, opt);
    }
}

void displaya(path_t *path, opt_t *opt)
{
    if (path != NULL){
        verif_sort(opt, path);
        while (path->content != NULL) {
            display_condition(path, opt, 1);
            path->content = path->content->next;
        }
    }
}