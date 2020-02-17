/*
** ETNA PROJECT, 10/02/2020 by zhou_p
** error.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void print_errors(char **av, char *str)
{
    my_putstr(av[0]);
    my_putstr(": cannot access '");
    my_putstr(str);
    my_putstr("': No such file or directory\n");
    exit(0);
}

void no_found_errors(char **av, char *str)
{
    if (str[0] != '-') {
        my_putstr(av[0]);
        my_putstr(": cannot access '");
        my_putstr(str);
        my_putstr("': No such file or directory\n");
    }
}

void print_option_errors(char c)
{
    if ((c == '1') || (c == 'l') || (c == 'R') || (c == 'r') ||
        (c == 'd') || (c == 't') || (c == 'a') || (c == 'A') ||
        (c == 'L'))
        ;
    else {
        my_putstr("./my_ls: invalid option -- '");
        my_putchar(c);
        my_putstr("'\nTry 'ls -- help' for more information.\n");
        exit(0);
    }
}
