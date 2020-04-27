/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_strlen.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (*(str + i) != '\0')
        ++i;
    return (i);
}
