/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:21:10 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:30:29 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char * ft_strrchr (const char *src, int c)
{
	int compt;
	int compt2;
	compt = 0;
	compt2 = -1;

	while (src[compt])
		if (src[compt++] == (char )c)
			compt2 = compt - 1;
	if (src[compt] == (char) c)
		return ((char *) &src[compt]);
	if (compt2 >= 0)
		return ((char *) &src[compt2]);
	else
		return (NULL);
}
