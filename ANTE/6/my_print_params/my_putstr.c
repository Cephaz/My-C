/*
** ETNA PROJECT, 01/10/2019 by zhou_p
** my_putstr.c
** File description:
**      Code is poetry..
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(const char *str)
{
	while (*str) {
		my_putchar(*str);
		++str;
	}
}
