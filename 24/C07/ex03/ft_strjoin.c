/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:52:26 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/27 10:01:36 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	colleplus(int size, char **strs, char *tab, char *sep)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i != size)
	{
		k = 0;
		while (strs[i][k] != '\0')
			tab[j++] = strs[i][k++];
		k = 0;
		while (sep[k] != '\0' && i < (size - 1))
			tab[j++] = sep[k++];
		i++;
	}
	tab[j] = '\0';
}

int		taille(char **strs, int size, char *sep)
{
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	while (++i < size && (j = -1) != -2)
		while (strs[i][++j] != '\0')
			k++;
	i = 0;
	while (sep[i])
		i++;
	k = k + (size - 1) * i;
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;

	if (size == 0)
	{
		if (!(tab = malloc(sizeof(*tab) * 1)))
			return (NULL);
		tab[0] = '\0';
	}
	else
	{
		if (!(tab = malloc(sizeof(*tab) * (taille(strs, size, sep) + 1))))
			return (NULL);
		colleplus(size, strs, tab, sep);
	}
	return (tab);
}
