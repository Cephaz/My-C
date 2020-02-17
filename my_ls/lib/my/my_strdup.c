/*
** ETNA PROJECT, 03/10/2019 by zhou_p
** my_strdup.c
** File description:
**      project_description
*/

#include <stdlib.h>

int my_strlennnn(const char *str)
{
	int cpt;

	cpt = 0;
	while (*str != '\0') {
		++cpt;
		++str;
	}
	return (cpt);
}

char *my_strdup(char *str)
{
    int i = 0;
    char *copy;
    int size = 0;

    size = my_strlennnn(str);
    copy = (char*)malloc(sizeof(*copy) * (size + 1));
    if (copy == NULL)
        return NULL;
    while (str[i] != '\0') {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}