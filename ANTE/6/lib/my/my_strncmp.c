/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_strncmp.c
** File description:
**      Code is poetry..
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
	int i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n) {
		if (s1[i] != s2[i]) {
			return (s1[i] - s2[i]);
		}
		++i;
	}
	return (0);
}
