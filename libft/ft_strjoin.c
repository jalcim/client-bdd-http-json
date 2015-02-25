/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 09:16:40 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:18:52 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void ft_bzero (void *src, size_t size);
char * ft_strcat (char * dest, const char *src);
int ft_strlen (const char *src);
char *ft_strnew(size_t size);

char * ft_strjoin(char const *s1, char const *s2)
{
	char *s3;
	int size;
	size = ((ft_strlen(s1) + ft_strlen(s2)) + 1);

	if (!s1 || !s2)
		return (NULL);

	if (!(s3 = ft_strnew(size)))
		return (NULL);

	ft_bzero(s3, size);
	ft_strcat(s3, s1);
	ft_strcat(s3, s2);

	return (s3);
}
