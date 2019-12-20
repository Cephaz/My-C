/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:33:11 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/18 09:29:46 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long	strlen(const char *aa)
{
	int i;

	i = 0;
	while (aa[i])
		i++;
	return (i);
}

void			ft_affiche(char **tab, int argc)
{
	int i;

	i = 0;
	while (i++ < argc - 1)
	{
		write(1, tab[i], strlen(tab[i]));
		write(1, "\n", 1);
	}
}

void			ft_sort_params(char **tab, int argc)
{
	int		i;
	int		j;
	char	*tmp;
	int		k;

	k = 0;
	while (k++ < argc - 2)
	{
		i = 0;
		while (i++ < argc - 2)
		{
			j = 0;
			while (tab[i][j] == tab[i + 1][j])
				j++;
			if (tab[i][j] > tab[i + 1][j] || tab[i + 1][j] == '\0')
			{
				tmp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = tmp;
			}
		}
	}
	ft_affiche(tab, argc);
}

int				main(int argc, char **argv)
{
	int i;

	i = 1;
	if (i <= argc - 1)
		ft_sort_params(argv, argc);
	return (0);
}
