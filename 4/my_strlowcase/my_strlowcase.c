/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_strlowcase.c
** File description:
**      project_description
*/

char *my_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
		}
		++i;
	}
	return (str);
}
