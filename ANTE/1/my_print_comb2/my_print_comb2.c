/*
** ETNA PROJECT, 30/09/2019 by zhou_p
** comicomobo
** File description:
**              vide
*/

void my_putchar(char c);

void my_syntax(int a, int b)
{
	my_putchar(a / 10 + 48);
	my_putchar(a % 10 + 48);
	my_putchar(' ');
	my_putchar(b / 10 + 48);
	my_putchar(b % 10 + 48);
	if (a != 98) {
		my_putchar(',');
		my_putchar(' ');
	}
}

void my_print_comb2(void)
{
	int b;
	int a;

	for (a = 0; a < 100; ++a) {
		for (b = a + 1; b < 100; ++b) {
			my_syntax(a, b);
		}
	}
}
