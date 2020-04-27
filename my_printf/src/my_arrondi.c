/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_arrondi.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

int intsize(int nbr)
{
    int cpt = 1;

    while (nbr > 9) {
        nbr = nbr / 10;
        cpt++;
    }
    return (cpt);
}

void rondibien(long nbr, long lon)
{
    int size = intsize(nbr);
    long nb = nbr;

    if (size == 1)
        my_putnbr(lon);
    else {
        while (size > 2) {
            nb = nb / 10;
            size--;
        }
        if (nb % 10 >= 5)
            lon++;
        my_putnbr(lon);
    }
}