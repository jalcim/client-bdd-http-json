/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 08:54:52 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/25 09:00:20 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_rbzero(void *src, size_t size)
{
	char *tab;
	size_t compt;
	int size_str;

	compt = 0;
	size_str = ft_strlen(src);
	tab = (char *)src;
	while (compt < size)
	{
		tab[size_str] = 0;
		size_str--;
		compt++;
	}
}
