/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:54:49 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/23 14:54:56 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int cpt;

	cpt = 0;
	while (*str != '\0')
	{
		cpt++;
		str++;
	}
	return (cpt);
}
