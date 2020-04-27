/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_check.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

int cpti(int i, const char *entrer)
{
    if (entrer[i] == '.') {
        i++;
        while (entrer[i] >= '0' && entrer[i] <= '9')
            i++;
    }
    return (i);
}

int checknbr(const char *entrer, int i)
{
    int nbr = 0;

    if (!(entrer[i] >= '0' && entrer[i] <= '9'))
        return (-1);
    while (i != -1) {
        if (entrer[i] >= '0' && entrer[i] <= '9')
            nbr = nbr * 10 + entrer[i] - 48;
        else
            i = -2;
        i++;
    }
    return (nbr);
}

int checki(const char *entrer, int i)
{
    int cpt = 0;

    while (entrer[i] >= '0' && entrer[i] <= '9') {
        cpt++;
        i++;
    }
    return (cpt);
}
