/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 06:07:54 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:22:35 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_strlen (const char *src);

size_t ft_strlcat (char *dest, const char *src, size_t size)
{
	char *d;
	char *s;
	size_t tmp;
	size_t len;
	tmp = size;
	d = dest;
	s = (char *) src;
	while (*d != '\0' && tmp-- != 0)
		d++;
	len = d - dest;
    tmp = size - len;
	if (tmp == 0)
		return (len + ft_strlen(s));
	while (*s != '\0')
	{
		if (tmp != 1)
		{
			*d++ = *s;
			tmp--;
		}
		s++;
	}
	*d = '\0';
	return (len + (s - src));
}
