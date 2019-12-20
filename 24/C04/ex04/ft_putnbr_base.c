/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 10:09:28 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/19 17:22:11 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void					ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned long			strlen(const char *base)
{
	int cpt;

	cpt = 0;
	while (base[cpt])
		cpt++;
	return (cpt);
}

int						labase(char *base)
{
	int i;
	int j;

	i = 0;
	j = strlen(base);
	if (j <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void					ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	int			len;

	nb = nbr;
	len = strlen(base);
	if (labase(base))
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-');
		}
		if (nb > len)
			ft_putnbr_base((nb / len), base);
		ft_putchar(base[nb % len]);
	}
}
