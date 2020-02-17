/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** my_nbrlen.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

int my_nbrlen(int n)
{
    int count = 0;

    if (n <= 0) {
        count++;
        n *= -1;
    }
    while (n > 0) {
        count++;
        n /= 10;
    }
    return (count);
}

void display_time(char *str)
{
    int i = 4;

    while (i < 16) {
        my_putchar(str[i]);
        i++;
    }
}