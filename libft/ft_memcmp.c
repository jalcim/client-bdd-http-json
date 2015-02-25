/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 03:20:38 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 19:20:28 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_memcmp (const void *dest, const void *src, size_t size)
{
	int compt;
	char *s1;
	char *s2;

	if (dest && src && size)
	{
		compt = -1;
		s1 = (char *) dest;
		s2 = (char *) src;
		while ((--size) + 1)
		{
			compt++;
			if (s1[compt] != s2[compt])
				return ((int)(s1[compt] - s2[compt]));
		}
	}
	return (0);
}

