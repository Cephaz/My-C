/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 20:52:26 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/26 10:39:34 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*colleplus(char *strs, char *tab, char *sep)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (strs[j])
		tab[i++] = strs[j++];
	j = 0;
	while (sep[j])
		tab[i++] = sep[j++];
	tab[i] = '\0';
	return (tab);
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
	int		i;

	if (size == 0)
	{
		if (!(tab = malloc(sizeof(*tab) * 1)))
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	if (!(tab = malloc(sizeof(*tab) * taille(strs, size, sep))))
		return (NULL);
	i = 0;
	while (i < size - 1)
		tab = colleplus(strs[i++], tab, sep);
	tab = colleplus(strs[i], tab, "");
	return (tab);
}
