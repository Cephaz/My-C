/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:57:57 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/18 09:20:47 by pzhou            ###   ########.fr       */
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
	argc = 0;
	write(1, argv[0], strlen(*argv));
	write(1, "\n", 1);
	return (0);
}
