/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 02:46:26 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 19:21:33 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void * ft_memchr(const void *src, int c, size_t size)
{
	char *s1;
	s1 = (char *)src;
	while (*s1 && size)
	{
		if (*s1 == c)
			return (s1);
		s1++;
		size--;
	}
	return (NULL);
}
