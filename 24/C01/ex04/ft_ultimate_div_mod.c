/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:55:55 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/09 23:43:03 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int temps_div;
	int temps_mod;

	temps_div = *a / *b;
	temps_mod = *a % *b;
	*a = temps_div;
	*b = temps_mod;
}
