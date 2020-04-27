/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_base.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

void base_i(void *aff, int nbr)
{
    int nb = (intptr_t)aff;

    nbr = nbr - intsize(nb);
    affichagespace(nbr);
    my_putnbr((intptr_t)aff);
}

void base_char(void *aff, int nbr)
{
    int nb = (intptr_t)aff;

    nbr = nbr - intsize(nb);
    affichagespace(nbr);
    my_putchar((intptr_t)aff);
}

void base_charetoile(void *aff, int nbr)
{
    int nb = strlen((char *)aff);

    nbr = nbr - nb;
    affichagespace(nbr);
    my_putstr((char *)aff);
}

void base_octal(void *aff, int nbr)
{
    char* base = "01234567";
    int nb = (intptr_t)aff;

    nbr = nbr - intsize(nb);
    affichagespace(nbr);
    my_putnbrbase((intptr_t)aff, base);
}

void base_ten(void *aff, int nbr)
{
    char* base = "0123456789";
    int nb = (intptr_t)aff;

    nbr = nbr - intsize(nb);
    affichagespace(nbr);
    my_putnbrunsigned((long unsigned int)aff, base);
}
