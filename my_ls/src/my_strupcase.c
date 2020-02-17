/*
** ETNA PROJECT, 10/02/2020 by zhou_p
** my_strupcase.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return (str);
}
