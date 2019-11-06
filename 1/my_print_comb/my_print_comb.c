/*
** ETNA PROJECT, 30/09/2019 by zhou_p
** blabla
** File description:
**              ok
*/

void my_putchar(char c);

void my_syntax(char a, char b, char c)
{
	my_putchar('0' + a);
	my_putchar('0' + b);
	my_putchar('0' + c);
	if (a != 7) {
		my_putchar(',');
		my_putchar(' ');
	}
}

void my_print_comb(void)
{
	char a;
	char b;
	char c;

	for (a = 0; a < 10; ++a) {
		for (b = a + 1; b < 10; ++b) {
			for (c = b + 1; c < 10; ++c) {
				my_syntax(a, b, c);
			}
		}
	}
}
