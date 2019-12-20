/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:45:22 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/17 21:44:51 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	while (min + i < max)
	{
		range[0][i] = min + i;
		printf("%d",range[0][i]);
		i++;
	}
	return (i);
}
int main()
{
	int i;
	int *tab=NULL;
	i = -1;
	printf("%d", ft_ultimate_range(&tab, 10, 10));
	return 0;
}
