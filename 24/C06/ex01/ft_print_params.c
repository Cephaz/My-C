/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:13:39 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/17 10:32:21 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long		strlen(const char *aa)
{
	int i;

	i = 0;
	while (aa[i])
		i++;
	return (i);
}

int					main(int argc, char **argv)
{
	int i;

	i = 0;
	while (i++ < argc - 1)
	{
		write(1, argv[i], strlen(argv[i]));
		write(1, "\n", 1);
	}
	return (0);
}
