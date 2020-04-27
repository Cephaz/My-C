/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_putnbrunsigned.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

int my_putnbrunsigned(long unsigned int nb, char *base)
{
    int size = my_strlen(base);
    int i = nb % size;
    int res = 0;

    nb /= size;
    if (nb > 0)
        res += my_putnbrunsigned(nb, base);
    my_putchar(base[i]);
    res++;
    return (res);
}