/*
** ETNA PROJECT, 09/10/2019 by zhou_p
** my_putstr.c
** File description:
**      Code is poetry..
*/

void my_putchar(char c);

void my_putstr(const char *str)
{
	while (*str) {
		my_putchar(*str);
		++str;
	}
}
