/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 08:41:53 by pzhou             #+#    #+#             */
/*   Updated: 2019/06/11 15:28:07 by pzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *str2;

	str2 = str;
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
		{
			*str = *str + 'a' - 'A';
		}
		str++;
	}
	return (str2);
}
