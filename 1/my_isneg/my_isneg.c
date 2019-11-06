/*
** ETNA PROJECT, 30/09/2019 zhou_p
** my_isneg
** File description:
** 		my_isneg
*/

void my_putchar(char c);

void my_isneg(int n)
{
	if (n >= 0) {
		my_putchar('P');
	} else {
		my_putchar('N');
	}
}
