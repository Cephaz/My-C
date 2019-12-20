/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:08:15 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/27 10:23:44 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_cat(int ac, char **av)
{
	char	*buff;
	int		fd;
	int		i;

	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd >= 0)
			while (read(fd, &buff, 1) != 0)
				write(1, &buff, 1);
		else
		{
			putstr("cat: ");
			putstr(av[i]);
			putstr(": No such file or directory\n");
		}
		close(fd);
	}
}

int		main(int ac, char **av)
{
	ft_cat(ac, av);
	return (0);
}
