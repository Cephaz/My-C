/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:45:20 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/10 00:05:00 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int c;
	int i;
	int moitier;

	i = 0;
	size--;
	moitier = size / 2;
	while (size > moitier)
	{
		c = tab[i];
		tab[i] = tab[size];
		tab[size] = c;
		size--;
		i++;
	}
}
