/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_strcat.c
** File description:
**      Code is poetry..
*/

char *my_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0') {
		++i;
	}
	while (src[j] != '\0') {
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
