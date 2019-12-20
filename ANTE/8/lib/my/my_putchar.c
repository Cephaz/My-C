/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_putchar.c
** File description:
**      Code is poetry..
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
