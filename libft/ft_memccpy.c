/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:02:43 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 20:57:59 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void * ft_memccpy (void *dest, const void *src, int c, size_t size)
{
	size_t compt;
	compt = 0;

	if (dest && src && c && size)
	{
		char *s1;
		s1 = dest;
		const char *s2;
		s2 = src;

		while (compt < size)
		{
			s1[compt] = s2[compt];
			compt++;
			if (s2[compt - 1] == c)
				return ((s1 + compt));
		}
	}
	return (NULL);
}
