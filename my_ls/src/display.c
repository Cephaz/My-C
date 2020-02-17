/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** display.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void display_name(file_t *file, opt_t *opt)
{
    if (file != NULL)
        my_putstr(file->name);
    if (opt->neg == 1)
        my_putstr("\n");
    else
        my_putstr("\n");
}

char *get_path(char *str)
{
    char current_path[256];
    char *path;

    getcwd(current_path, sizeof(current_path));
    path = my_strdup(current_path);
    path = my_strcat(current_path, "/");
    path = my_strdup(str);
    return path;
}

void displaynopt(path_t *path, opt_t *opt)
{
    if (path != NULL){
        verif_sort(opt, path);
        while (path->content != NULL) {
            display_condition(path, opt, 1);
            path->content = path->content->next;
        }
    }
}

void displayfollow(path_t *path, opt_t *opt, int pass)
{
    if ((opt->L == 1) && pass == 0 && (pass = 1))
        displaynopt(path, opt);
    if (((opt->a == 1) || (opt->t == 1) || (opt->r == 1)) &&
        pass == 0 && (pass = 1))
        displaya(path, opt);
    if ((opt->A == 1) && pass == 0 && (pass = 1)) {
        opt->a = 1;
        displaya(path, opt);
    }
    if ((opt->neg == 1) && pass == 0 && (pass = 1))
        displayneg(path, opt);
    if (opt->R == 1 && pass == 0 && (pass = 1))
        //read_recursive(ac, av);
    free_content(path->content);
    free(path);
}

void display(path_t *path, opt_t *opt)
{
    int pass = 0;

    if (nopt(opt) == 0)
        displaynopt(path, opt);
    else {
        if (opt->d == 1) {
            pass = 1;
            condition_optd(opt, path);
        }
        if (opt->l == 1) {
            my_putstr("total ");
            my_putnbr(count_nb_blocks(path->content, opt));
            my_putchar('\n');
            displayl(path, opt);
            pass = 1;
        }
        displayfollow(path, opt, pass);
    }
}