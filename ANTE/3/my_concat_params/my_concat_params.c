/*
** ETNA PROJECT, 03/10/2019 by zhou_p
** my_concat_params.c
** File description:
**      project_description
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char *src, int cpt, int argc)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		++i;
	while (src[j]) {
		dest[i] = src[j];
		++j;
		++i;
	}
	if (cpt < argc - 1)
		dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

int my_strlen(char *av)
{
	int cpt = 0;

	while (av[cpt])
		++cpt;
	return (cpt);
}

char *my_concat_params(int argc, char **argv)
{
	int i = 0;
	int size = 0;
	char *dest;
	int cpt = 0;

	while (i < argc) {
		size = size + my_strlen(argv[i]) + 1;
		++i;
	}
	if ((dest = (char *)malloc(sizeof(*argv) + (size + 1))) == NULL)
		return (0);
	i = 0;
	while (i < argc) {
		my_strcpy(dest, argv[i], cpt, argc);
		++cpt;
		++i;
	}
	dest[size + 1] = '\0';
	return (dest);
}
