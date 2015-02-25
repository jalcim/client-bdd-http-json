/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 08:05:37 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/25 08:52:56 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strrncpy (char *dest, const char *src, size_t size)
{
    int size1;
    int size2;

	size += 2;
    size1 = ft_strlen(dest) + 2;
    size2 = ft_strlen(src) + 2;
    dest[size1] = '\0';
	while (--size && --size1 && --size2)
		dest[size1 - 1] = src[size2 - 1];

    return (dest);
}
