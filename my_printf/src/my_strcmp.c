/*
** ETNA PROJECT, 16/03/2020 by zhou_p
** my_strcmp.c
** File description:
**      Code is poetry..
*/

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		++i;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
