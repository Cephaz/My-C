/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_strstr.c
** File description:
**      Code is poetry..
*/

char *my_strstr(char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[i] != '\0') {
		while (str[i] != '\0') {
			j = 0;
			while (to_find[j] == str[i + j]) {
				if (to_find[j + 1] == '\0') {
					return (&str[i]);
				}
				++j;
			}
			++i;
		}
		return (0);
	}
	return (str);
}
