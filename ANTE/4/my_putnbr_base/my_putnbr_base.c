/*
** ETNA PROJECT, 02/10/2019 by zhou_p
** my_putnbr_base.c
** File description:
**      Code is poetry..
*/

void my_putchar(char c);

int lalen(const char *base)
{
	int cpt;

	cpt = 0;
	while (base[cpt])
		++cpt;
	return (cpt);
}

int veribase(const char *base)
{
	int i;
	int j;

	i = 0;
	j = lalen(base);
	if (j <= 1)
		return (0);
	while (base[i] != '\0') {
		if(base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i;
		while (base[++j] != '\0')
			if (base[i] == base[j])
				return (0);
		++i;
	}
	return (1);
}

void my_putnbr_base(int nbr, const char *base)
{
	long int nb = nbr;
	int leng = lalen(base);

	if (veribase(base) == 1) {
		if (nb < 0) {
			nb = -nb;
			my_putchar('-');
		}
		if (nb >= leng)
			my_putnbr_base((nb/leng), base);
		my_putchar(base[nb % leng]);
	}
}
