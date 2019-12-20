/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_strupcase.c
** File description:
**      Code is poetry..
*/

char *my_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 97 && str[i] <= 122) {
			str[i] = str[i] - 32;
		}
		++i;
	}
	return (str);
}
