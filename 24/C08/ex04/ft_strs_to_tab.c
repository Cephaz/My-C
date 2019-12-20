/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:17:48 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/22 14:47:12 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

unsigned long			strlen(const char *base)
{
	int cpt;

	cpt = 0;
	while (base[cpt])
		cpt++;
	return (cpt);
}

char					*ft_strdup(char *src)
{
	char	*nsrc;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if ((nsrc = (char *)malloc(sizeof(*src) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		nsrc[i] = src[i];
		i++;
	}
	nsrc[i] = '\0';
	return (nsrc);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;

	if ((tab = (struct s_stock_str*)malloc(sizeof(*tab) * (ac + 1))) == NULL)
		return (0);
	i = 0;
	while (i < ac)
	{
		tab[i].size = strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
