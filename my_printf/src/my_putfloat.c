/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_putfloat.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

float foa(float f)
{
	f = (f < 0 ? -f : f);
	return (f);
}

void my_putpointf(float nbr, unsigned int p, long lon)
{
	if (nbr > 0 && p != 0) {
		my_putchar('.');
		while (p--) {
			nbr = nbr * 10;
			lon = (long)nbr;
			lon = lon % 10;
			nbr = nbr - lon;
            my_putchar(lon + 48);
		}
	}
}

void my_putfloat(float nbr, unsigned int p)
{
	long lon = (long) nbr;
	float r = 0.5;

	if ((foa(nbr - lon) >= r) && (p == 0))
		lon = ((lon > 0) ? lon + 1 : lon - 1);
	my_putnbr(lon);
	nbr = foa(nbr - lon);
	my_putpointf(nbr, p, lon);
}
