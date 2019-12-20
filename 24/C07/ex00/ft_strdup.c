/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:31:12 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/17 21:12:02 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char		*ft_strdup(char *src)
{
	char *nsrc;
	int i;

	i = 0;
	while (src[i])
		i++;
	nsrc = (char *)malloc(sizeof(*src) * (i + 1));
	i = 0;
	while (src[i])
	{
		nsrc[i] = src[i];
		i++;
	}
	nsrc[i] = '\0';
	return (nsrc);
}

int main()
{
	printf("%s\n",ft_strdup("123456"));
	printf("%s", strdup("123456"));
	return (0);
}
