/*
** ETNA PROJECT, 01/10/2019 by zhou_p
** my_strlen.c
** File description:
**      Code is poetry..
*/

int my_strlen(const char *str)
{
	int cpt;

	cpt = 0;
	while (*str != '\0') {
		++cpt;
		++str;
	}
	return (cpt);
}
