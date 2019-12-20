/*
** ETNA PROJECT, 05/10/2019 by zhou_p
** my_copy.c
** File description:
**      project_description
*/
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

char *my_copy(char *dest, char *src)
{
	int i = -1;

	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char *my_copyinfirst(char *src)
{
	return (&src[2]);
}
