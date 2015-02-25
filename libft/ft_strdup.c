/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:27:32 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:15:10 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen (const char *src);

char * ft_strdup (const char *str)
{
	int compt;
	compt = 0;

	char *dest;
	dest = NULL;
	if ((dest = (char *) malloc (ft_strlen (str) * sizeof(char))) == NULL)
		return (NULL);

	while (str[compt] != '\0')
	{
		dest[compt] = str[compt];
		compt++;
	}
	dest[compt] = '\0';

	return (dest);
}
