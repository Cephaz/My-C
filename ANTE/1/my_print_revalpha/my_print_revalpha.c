/*
** ETNA PROJECT, 30/09/2019 zhou_p
** my_print_revalpha
** File description:
** 		revalpha
*/

void my_putchar(char c);

void my_print_revalpha(void)
{
	int compteur;

	for (compteur = 0; compteur < 26; ++compteur) {
		my_putchar('z' - compteur);
	}
}
