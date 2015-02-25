/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:05:17 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/26 09:15:14 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strstr (const char *s1, const char *s2)
{
	int compt_s1;
	int compt_s2;
	int size_s2;

	size_s2 = ft_strlen(s2);
	compt_s1 = 0;
	compt_s2 = 0;

	while (s1[compt_s1])
	{
		if (!s1[compt_s1] || !s2[compt_s2])
            return (NULL);

		else if (s1[compt_s1] == s2[compt_s2])
		{
			if ((compt_s2 + 1) == size_s2)
				return ((char *)(s1 + (compt_s1 - compt_s2)));
			compt_s2++;
		}

		else
			compt_s2 = 0;
		compt_s1++;
	}
	return (NULL);
}
