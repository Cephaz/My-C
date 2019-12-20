/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_strncat.c
** File description:
**      Code is poetry..
*/

char *my_strncat(char *dest, const char *src, int nb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		++i;
	while (j < nb && src[j] != '\0') {
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
