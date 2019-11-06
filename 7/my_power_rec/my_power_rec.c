/*
** ETNA PROJECT, 07/10/2019 by zhou_p
** my_power_rec.c
** File description:
**      Code is poetry..
*/

int my_power_rec(int nb, int p)
{
	if (p >= 0) {
		if (p == 0)
			return (1);
		if (p > 0)
			return (nb * my_power_rec(nb, p - 1));
	}
	return (0);
}
