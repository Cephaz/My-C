/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jriallot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:36:35 by jriallot          #+#    #+#             */
/*   Updated: 2019/06/11 21:36:39 by jriallot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex_2(char nb, int iteration)
{
	char	c;
	int		reminder;

	if (nb != 0)
	{
		reminder = nb % 16;
		if (reminder < 10)
			c = 48 + reminder;
		else
			c = 87 + reminder;
		if (iteration < 1)
			ft_print_hex_2(nb /= 16, iteration + 1);
		write(1, &c, 1);
	}
	else
	{
		c = '0';
		write(1, &c, 1);
		if (iteration < 1)
			ft_print_hex_2(nb /= 16, iteration + 1);
	}
}

void	ft_print_hex_adress(unsigned long nb)
{
	char	c;
	int		reminder;

	if (nb < 10)
		write(1, "0", 1);
	if (nb != 0)
	{
		reminder = nb % 16;
		if (reminder < 10)
			c = 48 + reminder;
		else
			c = 87 + reminder;
		ft_print_hex_adress(nb /= 16);
		write(1, &c, 1);
	}
}

void	ft_print_hex_values(unsigned long *addr, int nb_to_print)
{
	int				i;

	i = 0;
	while (i < nb_to_print)
	{
		ft_print_hex_2((char)(((char *)(addr))[i]), 0);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (i < 16)
	{
		while (i < 16)
		{
			if (i % 2 == 1)
				write(1, "   ", 3);
			else
				write(1, "  ", 2);
			i++;
		}
	}
}

void	ft_print_str(unsigned char *addr, int nb_to_print)
{
	int		i;
	char	c;

	i = 0;
	while (i < nb_to_print)
	{
		c = addr[i];
		if (!(c <= '~' && c >= ' '))
			c = 0 + '.';
		write(1, &c, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	nb_to_print;

	while (size > 0)
	{
		ft_print_hex_adress((unsigned long)addr);
		write(1, ": ", 2);
		if (size > 15)
		{
			size = size - 16;
			nb_to_print = 16;
		}
		else
		{
			nb_to_print = size;
			size = 0;
		}
		ft_print_hex_values((unsigned long *)addr, nb_to_print);
		ft_print_str((unsigned char *)addr, nb_to_print);
		addr += 16;
		write(1, "\n", 2);
	}
	return (addr);
}
