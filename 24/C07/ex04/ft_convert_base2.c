/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 21:53:20 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/26 10:40:34 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	strlen(const char *base);
int				ft_atoi_base(char *str, char *base);
int				labase(char *base);

long int		ft_ifelse(long int nb)
{
	long int nomb;

	if (nb < 0)
	{
		nomb = nb * -1;
		return (nomb);
	}
	else
	{
		nomb = nb;
		return (nomb);
	}
}

char			*ft_putnbropti(long int nb, int lenbase_to, char *base_to)
{
	long int	nomb;
	int			i;
	char		*tab;

	i = 0;
	if (nb < 0 && i++ != -1)
		nomb = nb * -1;
	else
		nomb = nb;
	while (nomb > 0 && i++ != -1)
	{
		nomb = nomb / lenbase_to;
	}
	if ((tab = malloc(sizeof(char) * i + 1)) == NULL)
		return (0);
	if (nb < 0)
		tab[0] = '-';
	tab[i] = '\0';
	nomb = ft_ifelse(nb);
	while (nomb > 0 && --i != -2)
	{
		tab[i] = base_to[nomb % lenbase_to];
		nomb = nomb / lenbase_to;
	}
	return (tab);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int		nb;
	int				len;
	char			*tab;

	if (labase(base_to) == 0 || labase(base_from) == 0)
		return (NULL);
	if (labase(base_to) == 1 && labase(base_from) == 1
		&& ft_atoi_base(nbr, base_from) == 0)
	{
		if (!(tab = malloc(sizeof(char) * 2)))
			return (0);
		tab[0] = base_to[0];
		tab[1] = '\0';
		return (tab);
	}
	nb = ft_atoi_base(nbr, base_from);
	len = strlen(base_to);
	return (ft_putnbropti(nb, len, base_to));
}
