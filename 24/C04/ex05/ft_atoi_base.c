/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:55:39 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/20 19:06:30 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int						affiche(char nbr, char *base)
{
	int len;
	int j;
	int entier;

	entier = -1;
	j = 0;
	len = strlen(base);
	while (base[j] && nbr != base[j])
		j++;
	if (nbr == base[j])
		return (j);
	return (entier);
}

int						ft_atoi_base(char *str, char *base)
{
	int i;
	int symbole;
	int len;
	int numero;

	numero = 0;
	len = strlen(base);
	symbole = 1;
	i = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\r')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			symbole *= -1;
	while (labase(base) && str[i] && affiche(str[i], base) != -1)
		numero = (numero * len) + affiche(str[i++], base);
	return (symbole * numero);
}
#include <stdio.h>

int main()
{
	printf("%d",ft_atoi_base("wqwqwq","qw"));
	return 0;
}
