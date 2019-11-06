/*
** ETNA PROJECT, 30/09/2019 by zhou_p
** my_print_digits.c
** File description:
** 		vide
*/

void my_putchar(char c);

void my_print_digits(void)
{
	int compteur;

	for (compteur = 0; compteur < 10; ++compteur) {
		my_putchar(48 + compteur);
	}
}
