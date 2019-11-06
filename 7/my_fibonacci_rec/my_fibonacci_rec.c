/*
** ETNA PROJECT, 07/10/2019 by zhou_p
** my_fibonacci_rec.c
** File description:
**      Code is poetry..
*/

int my_fibonacci_rec(int nb)
{
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (nb);
	else
		return (my_fibonacci_rec(nb - 1) + my_fibonacci_rec(nb - 2));
}
