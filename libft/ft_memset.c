/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:03:03 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 19:23:32 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void * ft_memset (void *source, int rempl, size_t size)
{
	size_t compt;
	compt = 0;

	char *s1;
	s1 = (char *) source;

	while (compt < size)
	{
		s1[compt] = rempl;
		compt++;
	}

	return (source);
}
