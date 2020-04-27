/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_putnbrbase.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

void my_putnbrbase(int nb, char *base)
{
    int cpt = 1;
    int res;
    int size = my_strlen(base);

    if (nb < 0)
        nb = -nb;
    while ((nb / cpt) >= size)
        cpt *= size;
    while (cpt > 0) {
        res = (nb / cpt) % size;
        my_putchar(base[res]);
        cpt /= size;
    }
}