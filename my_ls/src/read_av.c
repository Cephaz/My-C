/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** read_av.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void init_allpath(path_t *path, opt_t *opt, char **av)
{
    if (opt->d == 1) {
        opt->a = 1;
        existing_file(".", opt, path);
    } else {
        while (path != NULL) {
            if (existing_file(path->name, opt, path) == 1)
                ;
            else if (existing_file(path->name, opt, path) == 0)
                print_errors(av, path->name);
            else
                my_putstr("Cannot open file with stat\n");
            path = path->next;
        }
    } 
}

int cptpath(path_t *path)
{
    int cptpath = 0;

    while (path != NULL) {
        cptpath += 1;
        path = path->next;
    }
    return (cptpath);
}

char *get_cpath(char *str)
{
    char current_path[256];
    char *path;

    getcwd(current_path, sizeof(current_path));
    path = my_strdup(current_path);
    path = my_strcat(current_path, "/");
    path = my_strcat(path, str);
    return path;
}

void generate_allpath(path_t *path, opt_t *opt)
{
    while (path != NULL) {
        my_putstr(get_cpath(path->name));
        my_putstr(":\n");
        display(path, opt);
        path = path->next;
        if (path != NULL)
            my_putstr("\n");
    }
}

void read_av(int ac, char **av)
{
    opt_t *opt = verif_options(ac, av);
    path_t *path = verif_path(ac, av);
    int nbrpath = cptpath(path);

    if (nbrpath > 1) {
        init_allpath(path, opt, av);
        generate_allpath(path, opt);
    } else {
        init_allpath(path, opt, av);
        display(path, opt);
    }
}