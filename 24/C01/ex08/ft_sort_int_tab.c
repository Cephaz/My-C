/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:07:06 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/09 20:31:40 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int imin;
	int j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		imin = i;
		j = i;
		while (j < size)
		{
			if (tab[j] < tab[imin])
			{
				imin = j;
			}
			j++;
		}
		tmp = tab[imin];
		tab[imin] = tab[i];
		tab[i] = tmp;
		i++;
	}
}
