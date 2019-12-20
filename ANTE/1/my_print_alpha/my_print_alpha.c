/*
** ETNA PROJECT, 30/09/2019 zhou_p
** my_print_alpha.c
** File description:
** 		printalphabet
*/

void my_putchar(char c);

void my_print_alpha(void)
{
	int compteur;

	for (compteur = 0; compteur < 26; ++compteur) {
		my_putchar('a' + compteur);
	}
	my_putchar('\n');
}
