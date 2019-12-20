/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_strcapitalize.c
** File description:
**      Code is poetry..
*/

char    *my_strlowcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i = i + 1;
	}
	return (str);
}

char    *my_strcapitalize(char *str)
{
	int i = 0;
	int cpt = 1;

	str = my_strlowcase(str);
	while (str[i]) {
		if (str[i] > 96 && str[i] < 123) {
			if (cpt == 1)
				str[i] = str[i] - 32;
			cpt = 0;
		}
		else if (str[i] > 47 && str[i] < 58)
			cpt = 0;
		else if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
			cpt = 1;
		else
		    cpt = 0;
		++i;
	}
	return (str);
}
