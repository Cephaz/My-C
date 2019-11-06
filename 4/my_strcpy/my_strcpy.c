/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_strcpy.c
** File description:
**      Code is poetry..
*/

char *my_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
