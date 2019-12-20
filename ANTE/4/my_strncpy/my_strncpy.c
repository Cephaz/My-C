/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_strncpy.c
** File description:
**      Code is poetry..
*/

char *my_strncpy(char *dest, const char *src, int n)
{
	int i;

	i = -1;
	while (++i < n && src[i] != '\0')
		dest[i] = src[i];
	while (i < n) {
		dest[i] = '\0';
		++i;
	}
	return (dest);
}
