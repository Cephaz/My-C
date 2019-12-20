/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriallot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 05:11:57 by jriallot          #+#    #+#             */
/*   Updated: 2019/06/10 01:32:51 by jriallot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_ls(int *li, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = '0' + li[i];
		write(1, &c, 1);
		i++;
	}
}

void	ft_init(int *li, int n)
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		*li = i;
		li++;
		i++;
	}
}

void	recurs(int *li, int n, int rang, int *no_write)
{
	int i;

	i = li[0] + rang;
	if (rang != 0)
		li[rang] = li[rang - 1] + 1;
	while (li[rang] < 11 - (n - rang))
	{
		if (rang != n - 1)
		{
			recurs(li, n, rang + 1, no_write);
		}
		else
		{
			if (*no_write)
				*no_write = 0;
			else
				write(1, ", ", 2);
			print_ls(li, n);
		}
		li[rang] += 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int li[n];
	int no_write;

	if (n == 1)
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
	else
	{	
		no_write = 1;
		ft_init(li, n);
		recurs(li, n, 0, &no_write);
	}
}
