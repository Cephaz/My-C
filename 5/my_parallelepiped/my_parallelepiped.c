/*
** ETNA PROJECT, 04/10/2019 by zhou_p
** my_parallelepiped.c
** File description:
**      project_description
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_head(int x, int y, int z)
{
	while (--z > 0)
		my_putchar(' ');
	if (x >= 1 && y >= 1)
		my_putchar('*');
	while (x - 2 > 0) {
		my_putchar('-');
		--x;
	}
	if (x >= 2)
		my_putchar('*');
}

int my_body(int x, int y, int z, int cpt)
{
	while (--z > 0) {
		my_putchar(' ');
	}
	if (z == 0 && x >= 1)
		my_putchar('/');
	while (--x > 1)
		my_putchar(' ');
	if (x == 1)
		my_putchar('/');
	if (cpt > 0)
		my_putchar(' ');
	if (--y > 1)
		my_putchar('|');
	if (y >= 0)
		++cpt;
	if (--y == 0) {
		my_putchar(' ');
		my_putchar('*');
	}
	return (cpt);
}

void my_foot(int x, int y, int z)
{
	int affy = y / 2 + 1;
	int cpt = 0;
	int xx;
	int fixy = y;

	if (x > 1 && y > 1 && z > 1) {
		my_head(x, y, 0);
		if (y > 2) {
			while (--affy > 0)
				my_putchar(' ');
			if (affy == 0)
				my_putchar('/');
			my_putchar('\n');
		}
	}
	while (y > 2) {
		my_putchar('|');
		xx = x;
		while (--xx - 1 > 0)
			my_putchar(' ');
		my_putchar('|');
		affy = fixy / 2;
		while (--affy - cpt > 0)
			my_putchar(' ');
		if (affy <= 1 && y > 2)
			my_putchar('/');
		--y;
		++cpt;
		my_putchar('\n');
	}
	if (x >= 1 && y >= 1) {
		my_head(x, y, 0);
		my_putchar('\n');
	}
}

int my_parallelepiped(int x, int y, int z)
{
	int cpt = 0;
	int cpt2 = 0;
	int resety = y;
	int resetz = z;

	if (x == 0 || y == 0 || z == 0)
		return (-1);
	if (x >= 1) {
		my_head(x, y, z);
		my_putchar('\n');
	}
	while (--z > 1) {
		cpt = my_body(x, y, z, cpt);
		--y;
		cpt2 = cpt + 1;
		while (cpt2 > 0 && y <= 0 && --cpt2) {
			cpt2 = cpt2 / 3;
			my_putchar(' ');
		}
		if (y <= 0 && cpt2 <= 0)
			my_putchar('/');
		my_putchar('\n');
	}
	my_foot(x, resety, resetz);
	return (0);
}
