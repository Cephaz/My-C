/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_strcmp.c
** File description:
**      Code is poetry..
*/

int my_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i])) {
		++i;
	}
	if (s1[i] != s2[i]) {
		return (s1[i] - s2[i]);
	}
	return (0);
}
