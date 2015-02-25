/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 07:59:25 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/25 08:03:41 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strrcpy (char *dest, const char *src)
{
	int size;
	int size2;

	size = ft_strlen(dest) + 1;
	size2 = ft_strlen(src) + 1;
	dest[size] = '\0';
	while (--size && --size2)
		dest[size] = src[size2];

	return (dest);
}
