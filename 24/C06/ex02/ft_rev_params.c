/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:18:16 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/17 10:32:40 by pzhou            ###   ########.fr       */
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
	while (i + 1 < argc)
	{
		write(1, argv[argc - 1], strlen(argv[argc - 1]));
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
