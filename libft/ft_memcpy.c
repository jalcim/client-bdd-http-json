/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:20:49 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 19:32:46 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void * ft_memcpy (void *dest, const void *src, size_t n)
{
	size_t compt;
	compt = 0;

	char *s1 = (char *) dest;
	char *s2 = (char *) src;

	while (compt < n)
	{
		s1[compt] = s2[compt];
		compt++;
	}

	return (dest);
}
