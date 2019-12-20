/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 16:49:23 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/27 10:28:12 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display(char *fic)
{
	int		cpt;
	char	carac;

	cpt = open(fic, O_RDONLY);
	if (cpt < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	while (read(cpt, &carac, 1))
		write(1, &carac, 1);
	close(cpt);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display(av[1]);
	return (0);
}
