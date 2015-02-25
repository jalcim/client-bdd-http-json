/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:02:48 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:25:16 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t compt;

	compt = 0;
	while (s1[compt] != '\0' && s1[compt] == s2[compt] && compt < (size - 1))
		compt++;
	return (s1[compt] - s2[compt]);
}
