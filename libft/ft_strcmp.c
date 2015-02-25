/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:02:48 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 18:57:28 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp(const char *s1, const char *s2)
{
	int compt;
	compt = 0;

	while (s1[compt] != '\0' && s1[compt] == s2[compt])
		compt++;
	return (s1[compt] - s2[compt]);
}
