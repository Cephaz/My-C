/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriallot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:02:59 by jriallot          #+#    #+#             */
/*   Updated: 2019/06/13 05:12:13 by jriallot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_in_char(unsigned char *c, int a)
{
	if (a < 10)
		*c = '0' + a;
	else
		*c = 87 + a;
}

void	ft_print_hex(unsigned char *nb)
{
	int				a;
	int				b;
	unsigned char	c;
	unsigned char	d;

	a = *nb % 16;
	b = *nb / 16;
	ft_in_char(&c, b);
	ft_in_char(&d, a);
	write(1, &c, 1);
	write(1, &d, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '~' && str[i] >= ' ')
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			ft_print_hex((unsigned char *)&str[i]);
		}
		i++;
	}
}
