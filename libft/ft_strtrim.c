/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 09:31:36 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:36:34 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_strlen (const char *src);
char *ft_strnew(size_t size);
char * ft_strcpy (char *dest, const char *src);

char * ft_strtrim(const char *s)
{
	int compt;
	int compt_2;
	char *s1;
	int size;

	size = ft_strlen(s);
	compt = 0;
	compt_2 = 0;
	if ((!(s1 = ft_strnew(size + 1))) || !s)
		return (NULL);

	while (compt < size)
	{if (s[compt] != ' ' && s[compt] != '\n' && s[compt] != '\t')
	{
		ft_strcpy(s1, s);
		return (s1);
	}
		compt = size;
	}
	compt = 0;
	while (compt <= size)
	{
		if (s[compt] == ' ' && s[compt] == '\n' && s[compt] == '\t')
		{
			return (s1 = ft_strcpy(s1, (char *)s));
		}
		compt += size;
	}
	compt = 0;

	while (s[compt_2] != '\0')
	{
		if (s[compt_2] != ' ' && s[compt_2] != '\n' && s[compt_2] != '\t')
		{
			s1[compt] = (char )s[compt_2];

			compt++;
		}
		compt_2++;
	}
	return (s1);
}
