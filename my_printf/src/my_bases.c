/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_bases.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

void affichagespace(int nbr)
{
    while (nbr-- > 0)
        my_putchar(' ');
}

void base_hexm(void* aff, int nbr)
{
    char* base = "0123456789ABCDEF";
    int nb = (intptr_t)aff;

    nbr = nbr - intsize(nb);
    affichagespace(nbr);
    my_putnbrbase((intptr_t)aff, base);
}

void base_hexM(void* aff, int nbr)
{
    char* base = "0123456789abcdef";
    int nb = (intptr_t)aff;

    nbr = nbr - intsize(nb);
    affichagespace(nbr);
    my_putnbrbase((intptr_t)aff, base);
}

void base_f(float aff, int boucle, char carac)
{
    if (carac == 'f' || carac == 'F')
        my_putfloat(aff, boucle);
    if (carac == 'e' || carac == 'E')
        my_putde(aff, boucle, carac);
}