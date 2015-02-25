/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:02:09 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:35:33 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strsub(const char *s1, unsigned int start, size_t len)
{
	size_t compt;
	char *s2;

	compt = 0;
	if (!(s2 = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);

	while (compt < len)
	{
		s2[compt] = s1[start];

		start++;
		compt++;
	}
	s2[compt] = '\0';

	return (s2);
}
