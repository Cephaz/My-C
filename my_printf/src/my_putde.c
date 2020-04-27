/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_putde.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

void my_putpointe(float nbr, unsigned int p, long lon, char carac)
{
	if (nbr > 0 && p >= 1) {
		while (p--) {
			nbr = nbr * 10;
			lon = (long)nbr;
			lon = lon % 10;
			nbr = nbr - lon;
            my_putchar(lon + 48);
		}
	}
	if (carac == 'e')
		my_putstr("e+");
	else
		my_putstr("E+");
}

unsigned int phqu(long att, unsigned int p)
{
    long nbr = att;
    long rest = 0;

    if (p != 0)
        my_putchar('.');
    while (p != 0 && att > 0) {
        nbr = att;
        while (nbr > 9) {
            rest++;
            nbr = nbr / 10;
        }
        my_putnbr(nbr);
        while (rest > 0) {
            nbr = nbr * 10;
            rest--;
        }
        att -= nbr;
        p--;
    }
    return (p);
}

void affzero(int cpt)
{
    if (cpt < 10)
		my_putnbr(0);
	my_putnbr(cpt);
}

void my_putde(float nbr, unsigned int p, char carac)
{
	long lon = (long) nbr;
	int att = 0;
	float r = 0.5;
	int cpt = 0;

	if ((foa(nbr - lon) >= r) && (p == 0))
		lon = ((lon > 0) ? lon + 1 : lon - 1);
	while (lon > 9) {
		att = (att * 10) + lon % 10;
		lon = lon / 10;
		cpt++;
	}
    if (p == 0)
        rondibien(nbr, lon);
    else
	    my_putnbr(lon);
	nbr = foa(nbr - lon);
    p = phqu(att, p);
	my_putpointe(nbr, p, lon, carac);
	affzero(cpt);
}