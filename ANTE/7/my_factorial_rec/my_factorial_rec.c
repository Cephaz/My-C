/*
** ETNA PROJECT, 07/10/2019 by zhou_p
** my_factorial_rec.c
** File description:
**      Code is poetry..
*/

int my_factorial_rec(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 0)
		return (nb * my_factorial_rec(nb - 1));
	return (1);
}
