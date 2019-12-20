/*
** ETNA PROJECT, 01/10/2019 by zhou_p
** my_revstr.c
** File description:
**      Code is poetry..
*/

int my_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (*str != '\0') {
		++cpt;
		++str;
	}
	return (cpt);
}

char *my_revstr(char *str)
{
	int size;
	char sub;
	int min;

	min = 0;
	size = my_strlen(str) - 1;
	while (min < size)
	{
		sub = str[min];
		str[min] = str[size];
		str[size] = sub;
		--size;
		++min;
	}
	return (str);
}
