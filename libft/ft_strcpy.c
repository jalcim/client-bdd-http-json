/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:54:00 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 18:57:52 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char * ft_strcpy (char *dest, const char *src)
{
	int compt;
	compt = 0;

	while (src[compt] != '\0')
	{
		dest[compt] = src[compt];
		compt++;
	}
	dest[compt] = '\0';
	return (dest);
}
