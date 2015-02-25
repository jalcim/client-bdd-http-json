/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 04:15:08 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 19:20:52 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
int ft_strlen (const char *src);

char * ft_strncat (char * dest, const char *src, size_t size)
{
	size_t compt;
	compt = 0;

	int size_d;
	size_d = ft_strlen(dest);

	while (src[compt] != '\0' && compt < size)
	{
		dest[size_d + compt] = src[compt];
		compt++;
	}
	dest[size_d + compt] = '\0';

	return (dest);
}
