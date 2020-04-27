/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_putstr.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

void my_putstr(char *str)
{
	while (*str) {
		my_putchar(*str);
		++str;
	}
}
