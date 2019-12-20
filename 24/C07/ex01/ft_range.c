/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:50:44 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/17 21:11:58 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max)
{
	int	*tab;
	int i;

	i = -1;
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (min >= max)
		return (0);
	while (min + i++ < max)
		tab[i] = min + i;
	return (tab);
}

int	main()
{
	int i;
	i = -1;
	int *tab = ft_range(1,9);
	while (i++ < 7)
		printf("%d",tab[i]);
	return 0;
}
