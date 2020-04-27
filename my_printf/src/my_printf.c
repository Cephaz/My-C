/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_printf.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

const a_base tbase [8] = {
    {'c', &base_char},
    {'s', &base_charetoile},
    {'o', &base_octal},
    {'x', &base_hexM},
    {'X', &base_hexm},
    {'i', &base_i},
    {'d', &base_i},
    {'u', &base_ten},
};

int searchopt(char c)
{
    int cpt = 0;

    if (c == '.' || c == 'f' || c == 'F' || c == 'e' || c == 'E')
        return (1);
    if (c == 'c' || c == 's' || c == 'o' || c == 'x' ||  c == 'X'
        || c == 'i' || c == 'd' || c == 'u') {
        while (c != tbase[cpt].key)
            cpt++;
        return (cpt);
    }
    return (-1);
}

void va(int i, va_list agptr, const char *entrer, int nbr)
{
    void* typ;
    float typf;
    int boucle = 6;

    if (entrer[i + 1] == '.') {
        i++;
        boucle = 0;
        while (entrer[i + 1] >= '0' && entrer[i + 1] <= '9') {
            boucle = boucle * 10 + entrer[i + 1] - 48;
            i++;
        }
    }
    if (entrer[i + 1] == 'f' || entrer[i + 1] == 'e'
        || entrer[i + 1] == 'F' || entrer[i + 1] == 'E') {
        typf = (float) va_arg(agptr, typeof(double));
        base_f(typf, boucle, entrer[i + 1]);
    } else {
        typ = va_arg(agptr, typeof(typ));
        tbase[searchopt(entrer[i + 1])].pf(typ, nbr);
    }  
}

int my_printf(const char *entrer, ...)
{
    int i;
    int nbr = 0;
    va_list agptr;
    va_start (agptr, entrer);

    for (i = 0; entrer[i] != '\0'; i++) {
        if (entrer[i] == '%') {
            if ((nbr = checknbr(entrer, i + 1)) != -1)
                i += checki(entrer, i + 1);
            if ((entrer[i + 1]) == '%') {
                my_putchar('%');
                i++;
            }
            if (searchopt(entrer[i + 1]) != -1)
                va(i++, agptr, entrer, nbr);
            i = cpti(i, entrer);
        }
        else
            my_putchar(entrer[i]);
    }
    va_end(agptr);
    return (0);
}
