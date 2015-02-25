/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 01:23:10 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:02:06 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void * ft_memcpy (void *dest, const void *src, size_t n);
void * ft_memmove (void *dest, const void *src, size_t size)
{
	char *s1;
	char *s2;
	char *s3;

	s1 = (char *) dest;
	s2 = (char *) src;
	s3 = (char *) malloc (size * sizeof (char));

	ft_memcpy(s3, s2, size);
	ft_memcpy(s1, s3, size);

	return (dest);
}
