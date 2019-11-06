/*
** ETNA PROJECT, 30/09/2019 by zhou_p
** iseven.c
** File description:
** 		E O O E
*/

void my_putchar(char c);

void my_iseven(int n)
{
	if (n % 2 == 0) {
		my_putchar('E');
	} else {
		my_putchar('O');
	}
}
