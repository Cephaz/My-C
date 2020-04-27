/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_putchar.c
** File description:
**      Code is poetry..
*/

#include "../include/my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
