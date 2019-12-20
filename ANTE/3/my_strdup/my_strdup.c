/*
** ETNA PROJECT, 03/10/2019 by zhou_p
** my_strdup.c
** File description:
**      project_description
*/

#include <stdlib.h>

char *my_strdup(const char *src)
{
	char *nsrc;
	int i = 0;

	while (src[i])
		++i;
	nsrc = (char *)malloc(sizeof(*src) + (i + 1));
	i = -1;
	while (src[++i])
		nsrc[i] = src[i];
	nsrc[i] = '\0';
	return (nsrc);
}
