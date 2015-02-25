/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 07:35:37 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:25:56 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t compt;
	compt = 0;

	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && compt < n)
	{
		s1++;
		s2++;
		compt++;
	}

	s1 -= compt;
	s2 -= compt;

	if (compt != n)
		return (0);

	return (1);
}
