/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:38:26 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/25 12:46:26 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		sp(char *str, char *charset, int i)
{
	int k;

	k = 0;
	while (charset[k] != '\0')
	{
		if (charset[k] == str[i])
			return (0);
		k++;
	}
	return (1);
}

int		gt(char *str, char *charset)
{
	int i;
	int etat;
	int cpt;

	i = 0;
	etat = 0;
	cpt = 0;
	if (str == 0)
		return (0);
	while (str[i] != 0)
	{
		while (str[i] != 0 && sp(str, charset, i) != 0)
		{
			i++;
			etat = 1;
		}
		if (str[i] == '\0' || sp(str, charset, i) == 0)
		{
			if (etat == 1)
				cpt++;
			etat = 0;
			i++;
		}
	}
	return (cpt);
}

int		pt(char *str, char *charset, int i)
{
	int cpt;

	cpt = 0;
	while (sp(str, charset, i) != 0 && str[i] != 0)
	{
		i++;
		cpt++;
	}
	return (cpt);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char*) * (gt(str, charset) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		while (sp(str, charset, i) == 0 && str[i])
			i++;
		if (str[i] != '\0')
		{
			k = 0;
			if (!(tab[j] = malloc(sizeof(char) * (pt(str, charset, i) + 1))))
				return (NULL);
			while (sp(str, charset, i) != 0 && str[i])
				tab[j][k++] = str[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}
