/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:05:17 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:26:57 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_strlen (const char *src);

char * ft_strnstr (const char *s1, const char *s2, size_t size)
{
	size_t compt_s1;
	size_t compt_s2;
	size_t size_s2;

    size_s2 = ft_strlen(s2);
	compt_s1 = 0;
	compt_s2 = 0;

	while (s1[compt_s1] && compt_s1 < size)
	{
		if (!s1[0] || !s2[0])
        {
            return ((char *)s1);
        }

		else if (s1[compt_s1] == s2[compt_s2])
		{
			if (((compt_s2 + 1) == size_s2))
				return ((char *)(s1 + (compt_s1 - compt_s2)));
			compt_s2++;
		}

		else
			compt_s2 = 0;
		compt_s1++;
	}
	return (NULL);
}
